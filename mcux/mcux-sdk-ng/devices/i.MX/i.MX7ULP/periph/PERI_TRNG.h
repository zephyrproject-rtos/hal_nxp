/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TRNG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRNG.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRNG
 *
 * CMSIS Peripheral Access Layer for TRNG
 */

#if !defined(PERI_TRNG_H_)
#define PERI_TRNG_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- TRNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Peripheral_Access_Layer TRNG Peripheral Access Layer
 * @{
 */

/** TRNG - Size of Registers Arrays */
#define TRNG_ENTA_COUNT                           16u

/** TRNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCTL;                              /**< Miscellaneous Control Register, offset: 0x0 */
  __IO uint32_t SCMISC;                            /**< Statistical Check Miscellaneous Register, offset: 0x4 */
  __IO uint32_t PKRRNG;                            /**< Poker Range Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    __IO uint32_t PKRMAX;                            /**< Poker Maximum Limit Register, offset: 0xC */
    __I  uint32_t PKRSQ;                             /**< Poker Square Calculation Result Register, offset: 0xC */
  };
  __IO uint32_t SDCTL;                             /**< Seed Control Register, offset: 0x10 */
  union {                                          /* offset: 0x14 */
    __IO uint32_t SBLIM;                             /**< Sparse Bit Limit Register, offset: 0x14 */
    __I  uint32_t TOTSAM;                            /**< Total Samples Register, offset: 0x14 */
  };
  __IO uint32_t FRQMIN;                            /**< Frequency Count Minimum Limit Register, offset: 0x18 */
  union {                                          /* offset: 0x1C */
    __I  uint32_t FRQCNT;                            /**< Frequency Count Register, offset: 0x1C */
    __IO uint32_t FRQMAX;                            /**< Frequency Count Maximum Limit Register, offset: 0x1C */
  };
  union {                                          /* offset: 0x20 */
    __I  uint32_t SCMC;                              /**< Statistical Check Monobit Count Register, offset: 0x20 */
    __IO uint32_t SCML;                              /**< Statistical Check Monobit Limit Register, offset: 0x20 */
  };
  union {                                          /* offset: 0x24 */
    __I  uint32_t SCR1C;                             /**< Statistical Check Run Length 1 Count Register, offset: 0x24 */
    __IO uint32_t SCR1L;                             /**< Statistical Check Run Length 1 Limit Register, offset: 0x24 */
  };
  union {                                          /* offset: 0x28 */
    __I  uint32_t SCR2C;                             /**< Statistical Check Run Length 2 Count Register, offset: 0x28 */
    __IO uint32_t SCR2L;                             /**< Statistical Check Run Length 2 Limit Register, offset: 0x28 */
  };
  union {                                          /* offset: 0x2C */
    __I  uint32_t SCR3C;                             /**< Statistical Check Run Length 3 Count Register, offset: 0x2C */
    __IO uint32_t SCR3L;                             /**< Statistical Check Run Length 3 Limit Register, offset: 0x2C */
  };
  union {                                          /* offset: 0x30 */
    __I  uint32_t SCR4C;                             /**< Statistical Check Run Length 4 Count Register, offset: 0x30 */
    __IO uint32_t SCR4L;                             /**< Statistical Check Run Length 4 Limit Register, offset: 0x30 */
  };
  union {                                          /* offset: 0x34 */
    __I  uint32_t SCR5C;                             /**< Statistical Check Run Length 5 Count Register, offset: 0x34 */
    __IO uint32_t SCR5L;                             /**< Statistical Check Run Length 5 Limit Register, offset: 0x34 */
  };
  union {                                          /* offset: 0x38 */
    __I  uint32_t SCR6PC;                            /**< Statistical Check Run Length 6+ Count Register, offset: 0x38 */
    __IO uint32_t SCR6PL;                            /**< Statistical Check Run Length 6+ Limit Register, offset: 0x38 */
  };
  __I  uint32_t STATUS;                            /**< Status Register, offset: 0x3C */
  __I  uint32_t ENT[TRNG_ENTA_COUNT];              /**< Entropy Read Register, array offset: 0x40, array step: 0x4 */
  __I  uint32_t PKRCNT10;                          /**< Statistical Check Poker Count 1 and 0 Register, offset: 0x80 */
  __I  uint32_t PKRCNT32;                          /**< Statistical Check Poker Count 3 and 2 Register, offset: 0x84 */
  __I  uint32_t PKRCNT54;                          /**< Statistical Check Poker Count 5 and 4 Register, offset: 0x88 */
  __I  uint32_t PKRCNT76;                          /**< Statistical Check Poker Count 7 and 6 Register, offset: 0x8C */
  __I  uint32_t PKRCNT98;                          /**< Statistical Check Poker Count 9 and 8 Register, offset: 0x90 */
  __I  uint32_t PKRCNTBA;                          /**< Statistical Check Poker Count B and A Register, offset: 0x94 */
  __I  uint32_t PKRCNTDC;                          /**< Statistical Check Poker Count D and C Register, offset: 0x98 */
  __I  uint32_t PKRCNTFE;                          /**< Statistical Check Poker Count F and E Register, offset: 0x9C */
  __IO uint32_t SEC_CFG;                           /**< Security Configuration Register, offset: 0xA0 */
  __IO uint32_t INT_CTRL;                          /**< Interrupt Control Register, offset: 0xA4 */
  __IO uint32_t INT_MASK;                          /**< Mask Register, offset: 0xA8 */
  __I  uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0xAC */
       uint8_t RESERVED_0[64];
  __I  uint32_t VID1;                              /**< Version ID Register (MS), offset: 0xF0 */
  __I  uint32_t VID2;                              /**< Version ID Register (LS), offset: 0xF4 */
} TRNG_Type;

/* ----------------------------------------------------------------------------
   -- TRNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRNG_Register_Masks TRNG Register Masks
 * @{
 */

/*! @name MCTL - Miscellaneous Control Register */
/*! @{ */

#define TRNG_MCTL_SAMP_MODE_MASK                 (0x3U)
#define TRNG_MCTL_SAMP_MODE_SHIFT                (0U)
/*! SAMP_MODE
 *  0b00..use Von Neumann data into both Entropy shifter and Statistical Checker
 *  0b01..use raw data into both Entropy shifter and Statistical Checker
 *  0b10..use Von Neumann data into Entropy shifter. Use raw data into Statistical Checker
 *  0b11..undefined/reserved.
 */
#define TRNG_MCTL_SAMP_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_SAMP_MODE_SHIFT)) & TRNG_MCTL_SAMP_MODE_MASK)

#define TRNG_MCTL_OSC_DIV_MASK                   (0xCU)
#define TRNG_MCTL_OSC_DIV_SHIFT                  (2U)
/*! OSC_DIV
 *  0b00..use ring oscillator with no divide
 *  0b01..use ring oscillator divided-by-2
 *  0b10..use ring oscillator divided-by-4
 *  0b11..use ring oscillator divided-by-8
 */
#define TRNG_MCTL_OSC_DIV(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_OSC_DIV_SHIFT)) & TRNG_MCTL_OSC_DIV_MASK)

#define TRNG_MCTL_UNUSED4_MASK                   (0x10U)
#define TRNG_MCTL_UNUSED4_SHIFT                  (4U)
#define TRNG_MCTL_UNUSED4(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_UNUSED4_SHIFT)) & TRNG_MCTL_UNUSED4_MASK)

#define TRNG_MCTL_TRNG_ACC_MASK                  (0x20U)
#define TRNG_MCTL_TRNG_ACC_SHIFT                 (5U)
#define TRNG_MCTL_TRNG_ACC(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_TRNG_ACC_SHIFT)) & TRNG_MCTL_TRNG_ACC_MASK)

#define TRNG_MCTL_RST_DEF_MASK                   (0x40U)
#define TRNG_MCTL_RST_DEF_SHIFT                  (6U)
#define TRNG_MCTL_RST_DEF(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_RST_DEF_SHIFT)) & TRNG_MCTL_RST_DEF_MASK)

#define TRNG_MCTL_FOR_SCLK_MASK                  (0x80U)
#define TRNG_MCTL_FOR_SCLK_SHIFT                 (7U)
#define TRNG_MCTL_FOR_SCLK(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_FOR_SCLK_SHIFT)) & TRNG_MCTL_FOR_SCLK_MASK)

#define TRNG_MCTL_FCT_FAIL_MASK                  (0x100U)
#define TRNG_MCTL_FCT_FAIL_SHIFT                 (8U)
#define TRNG_MCTL_FCT_FAIL(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_FCT_FAIL_SHIFT)) & TRNG_MCTL_FCT_FAIL_MASK)

#define TRNG_MCTL_FCT_VAL_MASK                   (0x200U)
#define TRNG_MCTL_FCT_VAL_SHIFT                  (9U)
#define TRNG_MCTL_FCT_VAL(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_FCT_VAL_SHIFT)) & TRNG_MCTL_FCT_VAL_MASK)

#define TRNG_MCTL_ENT_VAL_MASK                   (0x400U)
#define TRNG_MCTL_ENT_VAL_SHIFT                  (10U)
#define TRNG_MCTL_ENT_VAL(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_ENT_VAL_SHIFT)) & TRNG_MCTL_ENT_VAL_MASK)

#define TRNG_MCTL_TST_OUT_MASK                   (0x800U)
#define TRNG_MCTL_TST_OUT_SHIFT                  (11U)
#define TRNG_MCTL_TST_OUT(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_TST_OUT_SHIFT)) & TRNG_MCTL_TST_OUT_MASK)

#define TRNG_MCTL_ERR_MASK                       (0x1000U)
#define TRNG_MCTL_ERR_SHIFT                      (12U)
#define TRNG_MCTL_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_ERR_SHIFT)) & TRNG_MCTL_ERR_MASK)

#define TRNG_MCTL_TSTOP_OK_MASK                  (0x2000U)
#define TRNG_MCTL_TSTOP_OK_SHIFT                 (13U)
#define TRNG_MCTL_TSTOP_OK(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_TSTOP_OK_SHIFT)) & TRNG_MCTL_TSTOP_OK_MASK)

#define TRNG_MCTL_PRGM_MASK                      (0x10000U)
#define TRNG_MCTL_PRGM_SHIFT                     (16U)
#define TRNG_MCTL_PRGM(x)                        (((uint32_t)(((uint32_t)(x)) << TRNG_MCTL_PRGM_SHIFT)) & TRNG_MCTL_PRGM_MASK)
/*! @} */

/*! @name SCMISC - Statistical Check Miscellaneous Register */
/*! @{ */

#define TRNG_SCMISC_LRUN_MAX_MASK                (0xFFU)
#define TRNG_SCMISC_LRUN_MAX_SHIFT               (0U)
#define TRNG_SCMISC_LRUN_MAX(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_SCMISC_LRUN_MAX_SHIFT)) & TRNG_SCMISC_LRUN_MAX_MASK)

#define TRNG_SCMISC_RTY_CT_MASK                  (0xF0000U)
#define TRNG_SCMISC_RTY_CT_SHIFT                 (16U)
#define TRNG_SCMISC_RTY_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCMISC_RTY_CT_SHIFT)) & TRNG_SCMISC_RTY_CT_MASK)
/*! @} */

/*! @name PKRRNG - Poker Range Register */
/*! @{ */

#define TRNG_PKRRNG_PKR_RNG_MASK                 (0xFFFFU)
#define TRNG_PKRRNG_PKR_RNG_SHIFT                (0U)
#define TRNG_PKRRNG_PKR_RNG(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_PKRRNG_PKR_RNG_SHIFT)) & TRNG_PKRRNG_PKR_RNG_MASK)
/*! @} */

/*! @name PKRMAX - Poker Maximum Limit Register */
/*! @{ */

#define TRNG_PKRMAX_PKR_MAX_MASK                 (0xFFFFFFU)
#define TRNG_PKRMAX_PKR_MAX_SHIFT                (0U)
/*! PKR_MAX - Poker Maximum Limit. */
#define TRNG_PKRMAX_PKR_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_PKRMAX_PKR_MAX_SHIFT)) & TRNG_PKRMAX_PKR_MAX_MASK)
/*! @} */

/*! @name PKRSQ - Poker Square Calculation Result Register */
/*! @{ */

#define TRNG_PKRSQ_PKR_SQ_MASK                   (0xFFFFFFU)
#define TRNG_PKRSQ_PKR_SQ_SHIFT                  (0U)
/*! PKR_SQ - Poker Square Calculation Result. */
#define TRNG_PKRSQ_PKR_SQ(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_PKRSQ_PKR_SQ_SHIFT)) & TRNG_PKRSQ_PKR_SQ_MASK)
/*! @} */

/*! @name SDCTL - Seed Control Register */
/*! @{ */

#define TRNG_SDCTL_SAMP_SIZE_MASK                (0xFFFFU)
#define TRNG_SDCTL_SAMP_SIZE_SHIFT               (0U)
#define TRNG_SDCTL_SAMP_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_SDCTL_SAMP_SIZE_SHIFT)) & TRNG_SDCTL_SAMP_SIZE_MASK)

#define TRNG_SDCTL_ENT_DLY_MASK                  (0xFFFF0000U)
#define TRNG_SDCTL_ENT_DLY_SHIFT                 (16U)
#define TRNG_SDCTL_ENT_DLY(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SDCTL_ENT_DLY_SHIFT)) & TRNG_SDCTL_ENT_DLY_MASK)
/*! @} */

/*! @name SBLIM - Sparse Bit Limit Register */
/*! @{ */

#define TRNG_SBLIM_SB_LIM_MASK                   (0x3FFU)
#define TRNG_SBLIM_SB_LIM_SHIFT                  (0U)
#define TRNG_SBLIM_SB_LIM(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_SBLIM_SB_LIM_SHIFT)) & TRNG_SBLIM_SB_LIM_MASK)
/*! @} */

/*! @name TOTSAM - Total Samples Register */
/*! @{ */

#define TRNG_TOTSAM_TOT_SAM_MASK                 (0xFFFFFU)
#define TRNG_TOTSAM_TOT_SAM_SHIFT                (0U)
#define TRNG_TOTSAM_TOT_SAM(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_TOTSAM_TOT_SAM_SHIFT)) & TRNG_TOTSAM_TOT_SAM_MASK)
/*! @} */

/*! @name FRQMIN - Frequency Count Minimum Limit Register */
/*! @{ */

#define TRNG_FRQMIN_FRQ_MIN_MASK                 (0x3FFFFFU)
#define TRNG_FRQMIN_FRQ_MIN_SHIFT                (0U)
#define TRNG_FRQMIN_FRQ_MIN(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_FRQMIN_FRQ_MIN_SHIFT)) & TRNG_FRQMIN_FRQ_MIN_MASK)
/*! @} */

/*! @name FRQCNT - Frequency Count Register */
/*! @{ */

#define TRNG_FRQCNT_FRQ_CT_MASK                  (0x3FFFFFU)
#define TRNG_FRQCNT_FRQ_CT_SHIFT                 (0U)
#define TRNG_FRQCNT_FRQ_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_FRQCNT_FRQ_CT_SHIFT)) & TRNG_FRQCNT_FRQ_CT_MASK)
/*! @} */

/*! @name FRQMAX - Frequency Count Maximum Limit Register */
/*! @{ */

#define TRNG_FRQMAX_FRQ_MAX_MASK                 (0x3FFFFFU)
#define TRNG_FRQMAX_FRQ_MAX_SHIFT                (0U)
#define TRNG_FRQMAX_FRQ_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_FRQMAX_FRQ_MAX_SHIFT)) & TRNG_FRQMAX_FRQ_MAX_MASK)
/*! @} */

/*! @name SCMC - Statistical Check Monobit Count Register */
/*! @{ */

#define TRNG_SCMC_MONO_CT_MASK                   (0xFFFFU)
#define TRNG_SCMC_MONO_CT_SHIFT                  (0U)
#define TRNG_SCMC_MONO_CT(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_SCMC_MONO_CT_SHIFT)) & TRNG_SCMC_MONO_CT_MASK)
/*! @} */

/*! @name SCML - Statistical Check Monobit Limit Register */
/*! @{ */

#define TRNG_SCML_MONO_MAX_MASK                  (0xFFFFU)
#define TRNG_SCML_MONO_MAX_SHIFT                 (0U)
#define TRNG_SCML_MONO_MAX(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCML_MONO_MAX_SHIFT)) & TRNG_SCML_MONO_MAX_MASK)

#define TRNG_SCML_MONO_RNG_MASK                  (0xFFFF0000U)
#define TRNG_SCML_MONO_RNG_SHIFT                 (16U)
#define TRNG_SCML_MONO_RNG(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCML_MONO_RNG_SHIFT)) & TRNG_SCML_MONO_RNG_MASK)
/*! @} */

/*! @name SCR1C - Statistical Check Run Length 1 Count Register */
/*! @{ */

#define TRNG_SCR1C_R1_0_CT_MASK                  (0x7FFFU)
#define TRNG_SCR1C_R1_0_CT_SHIFT                 (0U)
#define TRNG_SCR1C_R1_0_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR1C_R1_0_CT_SHIFT)) & TRNG_SCR1C_R1_0_CT_MASK)

#define TRNG_SCR1C_R1_1_CT_MASK                  (0x7FFF0000U)
#define TRNG_SCR1C_R1_1_CT_SHIFT                 (16U)
#define TRNG_SCR1C_R1_1_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR1C_R1_1_CT_SHIFT)) & TRNG_SCR1C_R1_1_CT_MASK)
/*! @} */

/*! @name SCR1L - Statistical Check Run Length 1 Limit Register */
/*! @{ */

#define TRNG_SCR1L_RUN1_MAX_MASK                 (0x7FFFU)
#define TRNG_SCR1L_RUN1_MAX_SHIFT                (0U)
#define TRNG_SCR1L_RUN1_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR1L_RUN1_MAX_SHIFT)) & TRNG_SCR1L_RUN1_MAX_MASK)

#define TRNG_SCR1L_RUN1_RNG_MASK                 (0x7FFF0000U)
#define TRNG_SCR1L_RUN1_RNG_SHIFT                (16U)
#define TRNG_SCR1L_RUN1_RNG(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR1L_RUN1_RNG_SHIFT)) & TRNG_SCR1L_RUN1_RNG_MASK)
/*! @} */

/*! @name SCR2C - Statistical Check Run Length 2 Count Register */
/*! @{ */

#define TRNG_SCR2C_R2_0_CT_MASK                  (0x3FFFU)
#define TRNG_SCR2C_R2_0_CT_SHIFT                 (0U)
#define TRNG_SCR2C_R2_0_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR2C_R2_0_CT_SHIFT)) & TRNG_SCR2C_R2_0_CT_MASK)

#define TRNG_SCR2C_R2_1_CT_MASK                  (0x3FFF0000U)
#define TRNG_SCR2C_R2_1_CT_SHIFT                 (16U)
#define TRNG_SCR2C_R2_1_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR2C_R2_1_CT_SHIFT)) & TRNG_SCR2C_R2_1_CT_MASK)
/*! @} */

/*! @name SCR2L - Statistical Check Run Length 2 Limit Register */
/*! @{ */

#define TRNG_SCR2L_RUN2_MAX_MASK                 (0x3FFFU)
#define TRNG_SCR2L_RUN2_MAX_SHIFT                (0U)
#define TRNG_SCR2L_RUN2_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR2L_RUN2_MAX_SHIFT)) & TRNG_SCR2L_RUN2_MAX_MASK)

#define TRNG_SCR2L_RUN2_RNG_MASK                 (0x3FFF0000U)
#define TRNG_SCR2L_RUN2_RNG_SHIFT                (16U)
#define TRNG_SCR2L_RUN2_RNG(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR2L_RUN2_RNG_SHIFT)) & TRNG_SCR2L_RUN2_RNG_MASK)
/*! @} */

/*! @name SCR3C - Statistical Check Run Length 3 Count Register */
/*! @{ */

#define TRNG_SCR3C_R3_0_CT_MASK                  (0x1FFFU)
#define TRNG_SCR3C_R3_0_CT_SHIFT                 (0U)
#define TRNG_SCR3C_R3_0_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR3C_R3_0_CT_SHIFT)) & TRNG_SCR3C_R3_0_CT_MASK)

#define TRNG_SCR3C_R3_1_CT_MASK                  (0x1FFF0000U)
#define TRNG_SCR3C_R3_1_CT_SHIFT                 (16U)
#define TRNG_SCR3C_R3_1_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR3C_R3_1_CT_SHIFT)) & TRNG_SCR3C_R3_1_CT_MASK)
/*! @} */

/*! @name SCR3L - Statistical Check Run Length 3 Limit Register */
/*! @{ */

#define TRNG_SCR3L_RUN3_MAX_MASK                 (0x1FFFU)
#define TRNG_SCR3L_RUN3_MAX_SHIFT                (0U)
#define TRNG_SCR3L_RUN3_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR3L_RUN3_MAX_SHIFT)) & TRNG_SCR3L_RUN3_MAX_MASK)

#define TRNG_SCR3L_RUN3_RNG_MASK                 (0x1FFF0000U)
#define TRNG_SCR3L_RUN3_RNG_SHIFT                (16U)
#define TRNG_SCR3L_RUN3_RNG(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR3L_RUN3_RNG_SHIFT)) & TRNG_SCR3L_RUN3_RNG_MASK)
/*! @} */

/*! @name SCR4C - Statistical Check Run Length 4 Count Register */
/*! @{ */

#define TRNG_SCR4C_R4_0_CT_MASK                  (0xFFFU)
#define TRNG_SCR4C_R4_0_CT_SHIFT                 (0U)
#define TRNG_SCR4C_R4_0_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR4C_R4_0_CT_SHIFT)) & TRNG_SCR4C_R4_0_CT_MASK)

#define TRNG_SCR4C_R4_1_CT_MASK                  (0xFFF0000U)
#define TRNG_SCR4C_R4_1_CT_SHIFT                 (16U)
#define TRNG_SCR4C_R4_1_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR4C_R4_1_CT_SHIFT)) & TRNG_SCR4C_R4_1_CT_MASK)
/*! @} */

/*! @name SCR4L - Statistical Check Run Length 4 Limit Register */
/*! @{ */

#define TRNG_SCR4L_RUN4_MAX_MASK                 (0xFFFU)
#define TRNG_SCR4L_RUN4_MAX_SHIFT                (0U)
#define TRNG_SCR4L_RUN4_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR4L_RUN4_MAX_SHIFT)) & TRNG_SCR4L_RUN4_MAX_MASK)

#define TRNG_SCR4L_RUN4_RNG_MASK                 (0xFFF0000U)
#define TRNG_SCR4L_RUN4_RNG_SHIFT                (16U)
#define TRNG_SCR4L_RUN4_RNG(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR4L_RUN4_RNG_SHIFT)) & TRNG_SCR4L_RUN4_RNG_MASK)
/*! @} */

/*! @name SCR5C - Statistical Check Run Length 5 Count Register */
/*! @{ */

#define TRNG_SCR5C_R5_0_CT_MASK                  (0x7FFU)
#define TRNG_SCR5C_R5_0_CT_SHIFT                 (0U)
#define TRNG_SCR5C_R5_0_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR5C_R5_0_CT_SHIFT)) & TRNG_SCR5C_R5_0_CT_MASK)

#define TRNG_SCR5C_R5_1_CT_MASK                  (0x7FF0000U)
#define TRNG_SCR5C_R5_1_CT_SHIFT                 (16U)
#define TRNG_SCR5C_R5_1_CT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_SCR5C_R5_1_CT_SHIFT)) & TRNG_SCR5C_R5_1_CT_MASK)
/*! @} */

/*! @name SCR5L - Statistical Check Run Length 5 Limit Register */
/*! @{ */

#define TRNG_SCR5L_RUN5_MAX_MASK                 (0x7FFU)
#define TRNG_SCR5L_RUN5_MAX_SHIFT                (0U)
#define TRNG_SCR5L_RUN5_MAX(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR5L_RUN5_MAX_SHIFT)) & TRNG_SCR5L_RUN5_MAX_MASK)

#define TRNG_SCR5L_RUN5_RNG_MASK                 (0x7FF0000U)
#define TRNG_SCR5L_RUN5_RNG_SHIFT                (16U)
#define TRNG_SCR5L_RUN5_RNG(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SCR5L_RUN5_RNG_SHIFT)) & TRNG_SCR5L_RUN5_RNG_MASK)
/*! @} */

/*! @name SCR6PC - Statistical Check Run Length 6+ Count Register */
/*! @{ */

#define TRNG_SCR6PC_R6P_0_CT_MASK                (0x7FFU)
#define TRNG_SCR6PC_R6P_0_CT_SHIFT               (0U)
#define TRNG_SCR6PC_R6P_0_CT(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_SCR6PC_R6P_0_CT_SHIFT)) & TRNG_SCR6PC_R6P_0_CT_MASK)

#define TRNG_SCR6PC_R6P_1_CT_MASK                (0x7FF0000U)
#define TRNG_SCR6PC_R6P_1_CT_SHIFT               (16U)
#define TRNG_SCR6PC_R6P_1_CT(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_SCR6PC_R6P_1_CT_SHIFT)) & TRNG_SCR6PC_R6P_1_CT_MASK)
/*! @} */

/*! @name SCR6PL - Statistical Check Run Length 6+ Limit Register */
/*! @{ */

#define TRNG_SCR6PL_RUN6P_MAX_MASK               (0x7FFU)
#define TRNG_SCR6PL_RUN6P_MAX_SHIFT              (0U)
#define TRNG_SCR6PL_RUN6P_MAX(x)                 (((uint32_t)(((uint32_t)(x)) << TRNG_SCR6PL_RUN6P_MAX_SHIFT)) & TRNG_SCR6PL_RUN6P_MAX_MASK)

#define TRNG_SCR6PL_RUN6P_RNG_MASK               (0x7FF0000U)
#define TRNG_SCR6PL_RUN6P_RNG_SHIFT              (16U)
#define TRNG_SCR6PL_RUN6P_RNG(x)                 (((uint32_t)(((uint32_t)(x)) << TRNG_SCR6PL_RUN6P_RNG_SHIFT)) & TRNG_SCR6PL_RUN6P_RNG_MASK)
/*! @} */

/*! @name STATUS - Status Register */
/*! @{ */

#define TRNG_STATUS_TF1BR0_MASK                  (0x1U)
#define TRNG_STATUS_TF1BR0_SHIFT                 (0U)
#define TRNG_STATUS_TF1BR0(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF1BR0_SHIFT)) & TRNG_STATUS_TF1BR0_MASK)

#define TRNG_STATUS_TF1BR1_MASK                  (0x2U)
#define TRNG_STATUS_TF1BR1_SHIFT                 (1U)
#define TRNG_STATUS_TF1BR1(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF1BR1_SHIFT)) & TRNG_STATUS_TF1BR1_MASK)

#define TRNG_STATUS_TF2BR0_MASK                  (0x4U)
#define TRNG_STATUS_TF2BR0_SHIFT                 (2U)
#define TRNG_STATUS_TF2BR0(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF2BR0_SHIFT)) & TRNG_STATUS_TF2BR0_MASK)

#define TRNG_STATUS_TF2BR1_MASK                  (0x8U)
#define TRNG_STATUS_TF2BR1_SHIFT                 (3U)
#define TRNG_STATUS_TF2BR1(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF2BR1_SHIFT)) & TRNG_STATUS_TF2BR1_MASK)

#define TRNG_STATUS_TF3BR0_MASK                  (0x10U)
#define TRNG_STATUS_TF3BR0_SHIFT                 (4U)
#define TRNG_STATUS_TF3BR0(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF3BR0_SHIFT)) & TRNG_STATUS_TF3BR0_MASK)

#define TRNG_STATUS_TF3BR1_MASK                  (0x20U)
#define TRNG_STATUS_TF3BR1_SHIFT                 (5U)
#define TRNG_STATUS_TF3BR1(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF3BR1_SHIFT)) & TRNG_STATUS_TF3BR1_MASK)

#define TRNG_STATUS_TF4BR0_MASK                  (0x40U)
#define TRNG_STATUS_TF4BR0_SHIFT                 (6U)
#define TRNG_STATUS_TF4BR0(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF4BR0_SHIFT)) & TRNG_STATUS_TF4BR0_MASK)

#define TRNG_STATUS_TF4BR1_MASK                  (0x80U)
#define TRNG_STATUS_TF4BR1_SHIFT                 (7U)
#define TRNG_STATUS_TF4BR1(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF4BR1_SHIFT)) & TRNG_STATUS_TF4BR1_MASK)

#define TRNG_STATUS_TF5BR0_MASK                  (0x100U)
#define TRNG_STATUS_TF5BR0_SHIFT                 (8U)
#define TRNG_STATUS_TF5BR0(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF5BR0_SHIFT)) & TRNG_STATUS_TF5BR0_MASK)

#define TRNG_STATUS_TF5BR1_MASK                  (0x200U)
#define TRNG_STATUS_TF5BR1_SHIFT                 (9U)
#define TRNG_STATUS_TF5BR1(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF5BR1_SHIFT)) & TRNG_STATUS_TF5BR1_MASK)

#define TRNG_STATUS_TF6PBR0_MASK                 (0x400U)
#define TRNG_STATUS_TF6PBR0_SHIFT                (10U)
#define TRNG_STATUS_TF6PBR0(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF6PBR0_SHIFT)) & TRNG_STATUS_TF6PBR0_MASK)

#define TRNG_STATUS_TF6PBR1_MASK                 (0x800U)
#define TRNG_STATUS_TF6PBR1_SHIFT                (11U)
#define TRNG_STATUS_TF6PBR1(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TF6PBR1_SHIFT)) & TRNG_STATUS_TF6PBR1_MASK)

#define TRNG_STATUS_TFSB_MASK                    (0x1000U)
#define TRNG_STATUS_TFSB_SHIFT                   (12U)
#define TRNG_STATUS_TFSB(x)                      (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TFSB_SHIFT)) & TRNG_STATUS_TFSB_MASK)

#define TRNG_STATUS_TFLR_MASK                    (0x2000U)
#define TRNG_STATUS_TFLR_SHIFT                   (13U)
#define TRNG_STATUS_TFLR(x)                      (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TFLR_SHIFT)) & TRNG_STATUS_TFLR_MASK)

#define TRNG_STATUS_TFP_MASK                     (0x4000U)
#define TRNG_STATUS_TFP_SHIFT                    (14U)
#define TRNG_STATUS_TFP(x)                       (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TFP_SHIFT)) & TRNG_STATUS_TFP_MASK)

#define TRNG_STATUS_TFMB_MASK                    (0x8000U)
#define TRNG_STATUS_TFMB_SHIFT                   (15U)
#define TRNG_STATUS_TFMB(x)                      (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_TFMB_SHIFT)) & TRNG_STATUS_TFMB_MASK)

#define TRNG_STATUS_RETRY_CT_MASK                (0xF0000U)
#define TRNG_STATUS_RETRY_CT_SHIFT               (16U)
#define TRNG_STATUS_RETRY_CT(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_STATUS_RETRY_CT_SHIFT)) & TRNG_STATUS_RETRY_CT_MASK)
/*! @} */

/*! @name ENT - Entropy Read Register */
/*! @{ */

#define TRNG_ENT_ENT_MASK                        (0xFFFFFFFFU)
#define TRNG_ENT_ENT_SHIFT                       (0U)
#define TRNG_ENT_ENT(x)                          (((uint32_t)(((uint32_t)(x)) << TRNG_ENT_ENT_SHIFT)) & TRNG_ENT_ENT_MASK)
/*! @} */

/* The count of TRNG_ENT */
#define TRNG_ENT_COUNT                           (16U)

/*! @name PKRCNT10 - Statistical Check Poker Count 1 and 0 Register */
/*! @{ */

#define TRNG_PKRCNT10_PKR_0_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNT10_PKR_0_CT_SHIFT             (0U)
#define TRNG_PKRCNT10_PKR_0_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT10_PKR_0_CT_SHIFT)) & TRNG_PKRCNT10_PKR_0_CT_MASK)

#define TRNG_PKRCNT10_PKR_1_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNT10_PKR_1_CT_SHIFT             (16U)
#define TRNG_PKRCNT10_PKR_1_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT10_PKR_1_CT_SHIFT)) & TRNG_PKRCNT10_PKR_1_CT_MASK)
/*! @} */

/*! @name PKRCNT32 - Statistical Check Poker Count 3 and 2 Register */
/*! @{ */

#define TRNG_PKRCNT32_PKR_2_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNT32_PKR_2_CT_SHIFT             (0U)
#define TRNG_PKRCNT32_PKR_2_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT32_PKR_2_CT_SHIFT)) & TRNG_PKRCNT32_PKR_2_CT_MASK)

#define TRNG_PKRCNT32_PKR_3_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNT32_PKR_3_CT_SHIFT             (16U)
#define TRNG_PKRCNT32_PKR_3_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT32_PKR_3_CT_SHIFT)) & TRNG_PKRCNT32_PKR_3_CT_MASK)
/*! @} */

/*! @name PKRCNT54 - Statistical Check Poker Count 5 and 4 Register */
/*! @{ */

#define TRNG_PKRCNT54_PKR_4_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNT54_PKR_4_CT_SHIFT             (0U)
#define TRNG_PKRCNT54_PKR_4_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT54_PKR_4_CT_SHIFT)) & TRNG_PKRCNT54_PKR_4_CT_MASK)

#define TRNG_PKRCNT54_PKR_5_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNT54_PKR_5_CT_SHIFT             (16U)
#define TRNG_PKRCNT54_PKR_5_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT54_PKR_5_CT_SHIFT)) & TRNG_PKRCNT54_PKR_5_CT_MASK)
/*! @} */

/*! @name PKRCNT76 - Statistical Check Poker Count 7 and 6 Register */
/*! @{ */

#define TRNG_PKRCNT76_PKR_6_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNT76_PKR_6_CT_SHIFT             (0U)
#define TRNG_PKRCNT76_PKR_6_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT76_PKR_6_CT_SHIFT)) & TRNG_PKRCNT76_PKR_6_CT_MASK)

#define TRNG_PKRCNT76_PKR_7_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNT76_PKR_7_CT_SHIFT             (16U)
#define TRNG_PKRCNT76_PKR_7_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT76_PKR_7_CT_SHIFT)) & TRNG_PKRCNT76_PKR_7_CT_MASK)
/*! @} */

/*! @name PKRCNT98 - Statistical Check Poker Count 9 and 8 Register */
/*! @{ */

#define TRNG_PKRCNT98_PKR_8_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNT98_PKR_8_CT_SHIFT             (0U)
#define TRNG_PKRCNT98_PKR_8_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT98_PKR_8_CT_SHIFT)) & TRNG_PKRCNT98_PKR_8_CT_MASK)

#define TRNG_PKRCNT98_PKR_9_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNT98_PKR_9_CT_SHIFT             (16U)
#define TRNG_PKRCNT98_PKR_9_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNT98_PKR_9_CT_SHIFT)) & TRNG_PKRCNT98_PKR_9_CT_MASK)
/*! @} */

/*! @name PKRCNTBA - Statistical Check Poker Count B and A Register */
/*! @{ */

#define TRNG_PKRCNTBA_PKR_A_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNTBA_PKR_A_CT_SHIFT             (0U)
#define TRNG_PKRCNTBA_PKR_A_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNTBA_PKR_A_CT_SHIFT)) & TRNG_PKRCNTBA_PKR_A_CT_MASK)

#define TRNG_PKRCNTBA_PKR_B_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNTBA_PKR_B_CT_SHIFT             (16U)
#define TRNG_PKRCNTBA_PKR_B_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNTBA_PKR_B_CT_SHIFT)) & TRNG_PKRCNTBA_PKR_B_CT_MASK)
/*! @} */

/*! @name PKRCNTDC - Statistical Check Poker Count D and C Register */
/*! @{ */

#define TRNG_PKRCNTDC_PKR_C_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNTDC_PKR_C_CT_SHIFT             (0U)
#define TRNG_PKRCNTDC_PKR_C_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNTDC_PKR_C_CT_SHIFT)) & TRNG_PKRCNTDC_PKR_C_CT_MASK)

#define TRNG_PKRCNTDC_PKR_D_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNTDC_PKR_D_CT_SHIFT             (16U)
#define TRNG_PKRCNTDC_PKR_D_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNTDC_PKR_D_CT_SHIFT)) & TRNG_PKRCNTDC_PKR_D_CT_MASK)
/*! @} */

/*! @name PKRCNTFE - Statistical Check Poker Count F and E Register */
/*! @{ */

#define TRNG_PKRCNTFE_PKR_E_CT_MASK              (0xFFFFU)
#define TRNG_PKRCNTFE_PKR_E_CT_SHIFT             (0U)
#define TRNG_PKRCNTFE_PKR_E_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNTFE_PKR_E_CT_SHIFT)) & TRNG_PKRCNTFE_PKR_E_CT_MASK)

#define TRNG_PKRCNTFE_PKR_F_CT_MASK              (0xFFFF0000U)
#define TRNG_PKRCNTFE_PKR_F_CT_SHIFT             (16U)
#define TRNG_PKRCNTFE_PKR_F_CT(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_PKRCNTFE_PKR_F_CT_SHIFT)) & TRNG_PKRCNTFE_PKR_F_CT_MASK)
/*! @} */

/*! @name SEC_CFG - Security Configuration Register */
/*! @{ */

#define TRNG_SEC_CFG_SH0_MASK                    (0x1U)
#define TRNG_SEC_CFG_SH0_SHIFT                   (0U)
/*! SH0
 *  0b0..See DRNG version.
 *  0b1..See DRNG version.
 */
#define TRNG_SEC_CFG_SH0(x)                      (((uint32_t)(((uint32_t)(x)) << TRNG_SEC_CFG_SH0_SHIFT)) & TRNG_SEC_CFG_SH0_MASK)

#define TRNG_SEC_CFG_NO_PRGM_MASK                (0x2U)
#define TRNG_SEC_CFG_NO_PRGM_SHIFT               (1U)
/*! NO_PRGM
 *  0b0..Programability of registers controlled only by the Miscellaneous Control Register's access mode bit.
 *  0b1..Overides Miscellaneous Control Register access mode and prevents TRNG register programming.
 */
#define TRNG_SEC_CFG_NO_PRGM(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_SEC_CFG_NO_PRGM_SHIFT)) & TRNG_SEC_CFG_NO_PRGM_MASK)

#define TRNG_SEC_CFG_SK_VAL_MASK                 (0x4U)
#define TRNG_SEC_CFG_SK_VAL_SHIFT                (2U)
/*! SK_VAL
 *  0b0..See DRNG version.
 *  0b1..See DRNG version.
 */
#define TRNG_SEC_CFG_SK_VAL(x)                   (((uint32_t)(((uint32_t)(x)) << TRNG_SEC_CFG_SK_VAL_SHIFT)) & TRNG_SEC_CFG_SK_VAL_MASK)
/*! @} */

/*! @name INT_CTRL - Interrupt Control Register */
/*! @{ */

#define TRNG_INT_CTRL_HW_ERR_MASK                (0x1U)
#define TRNG_INT_CTRL_HW_ERR_SHIFT               (0U)
/*! HW_ERR
 *  0b0..Corresponding bit of INT_STATUS cleared.
 *  0b1..Corresponding bit of INT_STATUS active.
 */
#define TRNG_INT_CTRL_HW_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_INT_CTRL_HW_ERR_SHIFT)) & TRNG_INT_CTRL_HW_ERR_MASK)

#define TRNG_INT_CTRL_ENT_VAL_MASK               (0x2U)
#define TRNG_INT_CTRL_ENT_VAL_SHIFT              (1U)
/*! ENT_VAL
 *  0b0..Same behavior as bit 0 above.
 *  0b1..Same behavior as bit 0 above.
 */
#define TRNG_INT_CTRL_ENT_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << TRNG_INT_CTRL_ENT_VAL_SHIFT)) & TRNG_INT_CTRL_ENT_VAL_MASK)

#define TRNG_INT_CTRL_FRQ_CT_FAIL_MASK           (0x4U)
#define TRNG_INT_CTRL_FRQ_CT_FAIL_SHIFT          (2U)
/*! FRQ_CT_FAIL
 *  0b0..Same behavior as bit 0 above.
 *  0b1..Same behavior as bit 0 above.
 */
#define TRNG_INT_CTRL_FRQ_CT_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << TRNG_INT_CTRL_FRQ_CT_FAIL_SHIFT)) & TRNG_INT_CTRL_FRQ_CT_FAIL_MASK)

#define TRNG_INT_CTRL_UNUSED_MASK                (0xFFFFFFF8U)
#define TRNG_INT_CTRL_UNUSED_SHIFT               (3U)
#define TRNG_INT_CTRL_UNUSED(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_INT_CTRL_UNUSED_SHIFT)) & TRNG_INT_CTRL_UNUSED_MASK)
/*! @} */

/*! @name INT_MASK - Mask Register */
/*! @{ */

#define TRNG_INT_MASK_HW_ERR_MASK                (0x1U)
#define TRNG_INT_MASK_HW_ERR_SHIFT               (0U)
/*! HW_ERR
 *  0b0..Corresponding interrupt of INT_STATUS is masked.
 *  0b1..Corresponding bit of INT_STATUS is active.
 */
#define TRNG_INT_MASK_HW_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_INT_MASK_HW_ERR_SHIFT)) & TRNG_INT_MASK_HW_ERR_MASK)

#define TRNG_INT_MASK_ENT_VAL_MASK               (0x2U)
#define TRNG_INT_MASK_ENT_VAL_SHIFT              (1U)
/*! ENT_VAL
 *  0b0..Same behavior as bit 0 above.
 *  0b1..Same behavior as bit 0 above.
 */
#define TRNG_INT_MASK_ENT_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << TRNG_INT_MASK_ENT_VAL_SHIFT)) & TRNG_INT_MASK_ENT_VAL_MASK)

#define TRNG_INT_MASK_FRQ_CT_FAIL_MASK           (0x4U)
#define TRNG_INT_MASK_FRQ_CT_FAIL_SHIFT          (2U)
/*! FRQ_CT_FAIL
 *  0b0..Same behavior as bit 0 above.
 *  0b1..Same behavior as bit 0 above.
 */
#define TRNG_INT_MASK_FRQ_CT_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << TRNG_INT_MASK_FRQ_CT_FAIL_SHIFT)) & TRNG_INT_MASK_FRQ_CT_FAIL_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define TRNG_INT_STATUS_HW_ERR_MASK              (0x1U)
#define TRNG_INT_STATUS_HW_ERR_SHIFT             (0U)
/*! HW_ERR
 *  0b0..no error
 *  0b1..error detected.
 */
#define TRNG_INT_STATUS_HW_ERR(x)                (((uint32_t)(((uint32_t)(x)) << TRNG_INT_STATUS_HW_ERR_SHIFT)) & TRNG_INT_STATUS_HW_ERR_MASK)

#define TRNG_INT_STATUS_ENT_VAL_MASK             (0x2U)
#define TRNG_INT_STATUS_ENT_VAL_SHIFT            (1U)
/*! ENT_VAL
 *  0b0..Busy generation entropy. Any value read is invalid.
 *  0b1..TRNG can be stopped and entropy is valid if read.
 */
#define TRNG_INT_STATUS_ENT_VAL(x)               (((uint32_t)(((uint32_t)(x)) << TRNG_INT_STATUS_ENT_VAL_SHIFT)) & TRNG_INT_STATUS_ENT_VAL_MASK)

#define TRNG_INT_STATUS_FRQ_CT_FAIL_MASK         (0x4U)
#define TRNG_INT_STATUS_FRQ_CT_FAIL_SHIFT        (2U)
/*! FRQ_CT_FAIL
 *  0b0..No hardware nor self test frequency errors.
 *  0b1..The frequency counter has detected a failure.
 */
#define TRNG_INT_STATUS_FRQ_CT_FAIL(x)           (((uint32_t)(((uint32_t)(x)) << TRNG_INT_STATUS_FRQ_CT_FAIL_SHIFT)) & TRNG_INT_STATUS_FRQ_CT_FAIL_MASK)
/*! @} */

/*! @name VID1 - Version ID Register (MS) */
/*! @{ */

#define TRNG_VID1_MIN_REV_MASK                   (0xFFU)
#define TRNG_VID1_MIN_REV_SHIFT                  (0U)
/*! MIN_REV
 *  0b00000000..Minor revision number for TRNG.
 */
#define TRNG_VID1_MIN_REV(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_VID1_MIN_REV_SHIFT)) & TRNG_VID1_MIN_REV_MASK)

#define TRNG_VID1_MAJ_REV_MASK                   (0xFF00U)
#define TRNG_VID1_MAJ_REV_SHIFT                  (8U)
/*! MAJ_REV
 *  0b00000001..Major revision number for TRNG.
 */
#define TRNG_VID1_MAJ_REV(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_VID1_MAJ_REV_SHIFT)) & TRNG_VID1_MAJ_REV_MASK)

#define TRNG_VID1_IP_ID_MASK                     (0xFFFF0000U)
#define TRNG_VID1_IP_ID_SHIFT                    (16U)
/*! IP_ID
 *  0b0000000000110000..ID for TRNG.
 */
#define TRNG_VID1_IP_ID(x)                       (((uint32_t)(((uint32_t)(x)) << TRNG_VID1_IP_ID_SHIFT)) & TRNG_VID1_IP_ID_MASK)
/*! @} */

/*! @name VID2 - Version ID Register (LS) */
/*! @{ */

#define TRNG_VID2_CONFIG_OPT_MASK                (0xFFU)
#define TRNG_VID2_CONFIG_OPT_SHIFT               (0U)
/*! CONFIG_OPT
 *  0b00000000..TRNG_CONFIG_OPT for TRNG.
 */
#define TRNG_VID2_CONFIG_OPT(x)                  (((uint32_t)(((uint32_t)(x)) << TRNG_VID2_CONFIG_OPT_SHIFT)) & TRNG_VID2_CONFIG_OPT_MASK)

#define TRNG_VID2_ECO_REV_MASK                   (0xFF00U)
#define TRNG_VID2_ECO_REV_SHIFT                  (8U)
/*! ECO_REV
 *  0b00000000..TRNG_ECO_REV for TRNG.
 */
#define TRNG_VID2_ECO_REV(x)                     (((uint32_t)(((uint32_t)(x)) << TRNG_VID2_ECO_REV_SHIFT)) & TRNG_VID2_ECO_REV_MASK)

#define TRNG_VID2_INTG_OPT_MASK                  (0xFF0000U)
#define TRNG_VID2_INTG_OPT_SHIFT                 (16U)
/*! INTG_OPT
 *  0b00000000..INTG_OPT for TRNG.
 */
#define TRNG_VID2_INTG_OPT(x)                    (((uint32_t)(((uint32_t)(x)) << TRNG_VID2_INTG_OPT_SHIFT)) & TRNG_VID2_INTG_OPT_MASK)

#define TRNG_VID2_ERA_MASK                       (0xFF000000U)
#define TRNG_VID2_ERA_SHIFT                      (24U)
/*! ERA
 *  0b00000000..COMPILE_OPT for TRNG.
 */
#define TRNG_VID2_ERA(x)                         (((uint32_t)(((uint32_t)(x)) << TRNG_VID2_ERA_SHIFT)) & TRNG_VID2_ERA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRNG_Register_Masks */



/*!
 * @}
 */ /* end of group TRNG_Peripheral_Access_Layer */


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


#endif  /* PERI_TRNG_H_ */

