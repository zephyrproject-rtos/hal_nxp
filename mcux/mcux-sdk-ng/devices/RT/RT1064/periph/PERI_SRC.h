/*
** ###################################################################
**     Processors:          MIMXRT1064CVJ5A
**                          MIMXRT1064CVJ5B
**                          MIMXRT1064CVL5A
**                          MIMXRT1064CVL5B
**                          MIMXRT1064DVJ6A
**                          MIMXRT1064DVJ6B
**                          MIMXRT1064DVL6A
**                          MIMXRT1064DVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-06-22)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1064RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1064RM Rev.0.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1064RM Rev.2.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SRC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC
 *
 * CMSIS Peripheral Access Layer for SRC
 */

#if !defined(PERI_SRC_H_)
#define PERI_SRC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1064CVJ5A) || defined(CPU_MIMXRT1064CVJ5B) || defined(CPU_MIMXRT1064CVL5A) || defined(CPU_MIMXRT1064CVL5B) || defined(CPU_MIMXRT1064DVJ6A) || defined(CPU_MIMXRT1064DVJ6B) || defined(CPU_MIMXRT1064DVL6A) || defined(CPU_MIMXRT1064DVL6B))
#include "MIMXRT1064_COMMON.h"
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
   -- SRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Peripheral_Access_Layer SRC Peripheral Access Layer
 * @{
 */

/** SRC - Size of Registers Arrays */
#define SRC_GPR_COUNT                             10u

/** SRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< SRC Control Register, offset: 0x0 */
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x4 */
  __IO uint32_t SRSR;                              /**< SRC Reset Status Register, offset: 0x8 */
       uint8_t RESERVED_0[16];
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x1C */
  __IO uint32_t GPR[SRC_GPR_COUNT];                /**< SRC General Purpose Register 1..SRC General Purpose Register 10, array offset: 0x20, array step: 0x4 */
} SRC_Type;

/* ----------------------------------------------------------------------------
   -- SRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Register_Masks SRC Register Masks
 * @{
 */

/*! @name SCR - SRC Control Register */
/*! @{ */

#define SRC_SCR_MASK_WDOG_RST_MASK               (0x780U)
#define SRC_SCR_MASK_WDOG_RST_SHIFT              (7U)
/*! mask_wdog_rst
 *  0b0101..wdog_rst_b is masked
 *  0b1010..wdog_rst_b is not masked (default)
 */
#define SRC_SCR_MASK_WDOG_RST(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_SCR_MASK_WDOG_RST_SHIFT)) & SRC_SCR_MASK_WDOG_RST_MASK)

#define SRC_SCR_CORE0_RST_MASK                   (0x2000U)
#define SRC_SCR_CORE0_RST_SHIFT                  (13U)
/*! core0_rst
 *  0b0..do not assert core0 reset
 *  0b1..assert core0 reset
 */
#define SRC_SCR_CORE0_RST(x)                     (((uint32_t)(((uint32_t)(x)) << SRC_SCR_CORE0_RST_SHIFT)) & SRC_SCR_CORE0_RST_MASK)

#define SRC_SCR_CORE0_DBG_RST_MASK               (0x20000U)
#define SRC_SCR_CORE0_DBG_RST_SHIFT              (17U)
/*! core0_dbg_rst
 *  0b0..do not assert core0 debug reset
 *  0b1..assert core0 debug reset
 */
#define SRC_SCR_CORE0_DBG_RST(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_SCR_CORE0_DBG_RST_SHIFT)) & SRC_SCR_CORE0_DBG_RST_MASK)

#define SRC_SCR_DBG_RST_MSK_PG_MASK              (0x2000000U)
#define SRC_SCR_DBG_RST_MSK_PG_SHIFT             (25U)
/*! dbg_rst_msk_pg
 *  0b0..do not mask core debug resets (debug resets will be asserted after power gating event)
 *  0b1..mask core debug resets (debug resets won't be asserted after power gating event)
 */
#define SRC_SCR_DBG_RST_MSK_PG(x)                (((uint32_t)(((uint32_t)(x)) << SRC_SCR_DBG_RST_MSK_PG_SHIFT)) & SRC_SCR_DBG_RST_MSK_PG_MASK)

#define SRC_SCR_MASK_WDOG3_RST_MASK              (0xF0000000U)
#define SRC_SCR_MASK_WDOG3_RST_SHIFT             (28U)
/*! mask_wdog3_rst
 *  0b0101..wdog3_rst_b is masked
 *  0b1010..wdog3_rst_b is not masked
 */
#define SRC_SCR_MASK_WDOG3_RST(x)                (((uint32_t)(((uint32_t)(x)) << SRC_SCR_MASK_WDOG3_RST_SHIFT)) & SRC_SCR_MASK_WDOG3_RST_MASK)
/*! @} */

/*! @name SBMR1 - SRC Boot Mode Register 1 */
/*! @{ */

#define SRC_SBMR1_BOOT_CFG1_MASK                 (0xFFU)
#define SRC_SBMR1_BOOT_CFG1_SHIFT                (0U)
#define SRC_SBMR1_BOOT_CFG1(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SBMR1_BOOT_CFG1_SHIFT)) & SRC_SBMR1_BOOT_CFG1_MASK)

#define SRC_SBMR1_BOOT_CFG2_MASK                 (0xFF00U)
#define SRC_SBMR1_BOOT_CFG2_SHIFT                (8U)
#define SRC_SBMR1_BOOT_CFG2(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SBMR1_BOOT_CFG2_SHIFT)) & SRC_SBMR1_BOOT_CFG2_MASK)

#define SRC_SBMR1_BOOT_CFG3_MASK                 (0xFF0000U)
#define SRC_SBMR1_BOOT_CFG3_SHIFT                (16U)
#define SRC_SBMR1_BOOT_CFG3(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SBMR1_BOOT_CFG3_SHIFT)) & SRC_SBMR1_BOOT_CFG3_MASK)

#define SRC_SBMR1_BOOT_CFG4_MASK                 (0xFF000000U)
#define SRC_SBMR1_BOOT_CFG4_SHIFT                (24U)
#define SRC_SBMR1_BOOT_CFG4(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SBMR1_BOOT_CFG4_SHIFT)) & SRC_SBMR1_BOOT_CFG4_MASK)
/*! @} */

/*! @name SRSR - SRC Reset Status Register */
/*! @{ */

#define SRC_SRSR_IPP_RESET_B_MASK                (0x1U)
#define SRC_SRSR_IPP_RESET_B_SHIFT               (0U)
/*! ipp_reset_b
 *  0b0..Reset is not a result of ipp_reset_b pin.
 *  0b1..Reset is a result of ipp_reset_b pin.
 */
#define SRC_SRSR_IPP_RESET_B(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_IPP_RESET_B_SHIFT)) & SRC_SRSR_IPP_RESET_B_MASK)

#define SRC_SRSR_LOCKUP_SYSRESETREQ_MASK         (0x2U)
#define SRC_SRSR_LOCKUP_SYSRESETREQ_SHIFT        (1U)
/*! lockup_sysresetreq
 *  0b0..Reset is not a result of the mentioned case.
 *  0b1..Reset is a result of the mentioned case.
 */
#define SRC_SRSR_LOCKUP_SYSRESETREQ(x)           (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_LOCKUP_SYSRESETREQ_SHIFT)) & SRC_SRSR_LOCKUP_SYSRESETREQ_MASK)

#define SRC_SRSR_CSU_RESET_B_MASK                (0x4U)
#define SRC_SRSR_CSU_RESET_B_SHIFT               (2U)
/*! csu_reset_b
 *  0b0..Reset is not a result of the csu_reset_b event.
 *  0b1..Reset is a result of the csu_reset_b event.
 */
#define SRC_SRSR_CSU_RESET_B(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_CSU_RESET_B_SHIFT)) & SRC_SRSR_CSU_RESET_B_MASK)

#define SRC_SRSR_IPP_USER_RESET_B_MASK           (0x8U)
#define SRC_SRSR_IPP_USER_RESET_B_SHIFT          (3U)
/*! ipp_user_reset_b
 *  0b0..Reset is not a result of the ipp_user_reset_b qualified as COLD reset event.
 *  0b1..Reset is a result of the ipp_user_reset_b qualified as COLD reset event.
 */
#define SRC_SRSR_IPP_USER_RESET_B(x)             (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_IPP_USER_RESET_B_SHIFT)) & SRC_SRSR_IPP_USER_RESET_B_MASK)

#define SRC_SRSR_WDOG_RST_B_MASK                 (0x10U)
#define SRC_SRSR_WDOG_RST_B_SHIFT                (4U)
/*! wdog_rst_b
 *  0b0..Reset is not a result of the watchdog time-out event.
 *  0b1..Reset is a result of the watchdog time-out event.
 */
#define SRC_SRSR_WDOG_RST_B(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_WDOG_RST_B_SHIFT)) & SRC_SRSR_WDOG_RST_B_MASK)

#define SRC_SRSR_JTAG_RST_B_MASK                 (0x20U)
#define SRC_SRSR_JTAG_RST_B_SHIFT                (5U)
/*! jtag_rst_b
 *  0b0..Reset is not a result of HIGH-Z reset from JTAG.
 *  0b1..Reset is a result of HIGH-Z reset from JTAG.
 */
#define SRC_SRSR_JTAG_RST_B(x)                   (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_JTAG_RST_B_SHIFT)) & SRC_SRSR_JTAG_RST_B_MASK)

#define SRC_SRSR_JTAG_SW_RST_MASK                (0x40U)
#define SRC_SRSR_JTAG_SW_RST_SHIFT               (6U)
/*! jtag_sw_rst
 *  0b0..Reset is not a result of the mentioned case.
 *  0b1..Reset is a result of the mentioned case.
 */
#define SRC_SRSR_JTAG_SW_RST(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_JTAG_SW_RST_SHIFT)) & SRC_SRSR_JTAG_SW_RST_MASK)

#define SRC_SRSR_WDOG3_RST_B_MASK                (0x80U)
#define SRC_SRSR_WDOG3_RST_B_SHIFT               (7U)
/*! wdog3_rst_b
 *  0b0..Reset is not a result of the watchdog3 time-out event.
 *  0b1..Reset is a result of the watchdog3 time-out event.
 */
#define SRC_SRSR_WDOG3_RST_B(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_WDOG3_RST_B_SHIFT)) & SRC_SRSR_WDOG3_RST_B_MASK)

#define SRC_SRSR_TEMPSENSE_RST_B_MASK            (0x100U)
#define SRC_SRSR_TEMPSENSE_RST_B_SHIFT           (8U)
/*! tempsense_rst_b
 *  0b0..Reset is not a result of software reset from Temperature Sensor.
 *  0b1..Reset is a result of software reset from Temperature Sensor.
 */
#define SRC_SRSR_TEMPSENSE_RST_B(x)              (((uint32_t)(((uint32_t)(x)) << SRC_SRSR_TEMPSENSE_RST_B_SHIFT)) & SRC_SRSR_TEMPSENSE_RST_B_MASK)
/*! @} */

/*! @name SBMR2 - SRC Boot Mode Register 2 */
/*! @{ */

#define SRC_SBMR2_SEC_CONFIG_MASK                (0x3U)
#define SRC_SBMR2_SEC_CONFIG_SHIFT               (0U)
#define SRC_SBMR2_SEC_CONFIG(x)                  (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_SEC_CONFIG_SHIFT)) & SRC_SBMR2_SEC_CONFIG_MASK)

#define SRC_SBMR2_BT_FUSE_SEL_MASK               (0x10U)
#define SRC_SBMR2_BT_FUSE_SEL_SHIFT              (4U)
#define SRC_SBMR2_BT_FUSE_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_BT_FUSE_SEL_SHIFT)) & SRC_SBMR2_BT_FUSE_SEL_MASK)

#define SRC_SBMR2_BMOD_MASK                      (0x3000000U)
#define SRC_SBMR2_BMOD_SHIFT                     (24U)
#define SRC_SBMR2_BMOD(x)                        (((uint32_t)(((uint32_t)(x)) << SRC_SBMR2_BMOD_SHIFT)) & SRC_SBMR2_BMOD_MASK)
/*! @} */

/*! @name GPR - SRC General Purpose Register 1..SRC General Purpose Register 10 */
/*! @{ */

#define SRC_GPR_PERSISTENT_ARG0_MASK             (0xFFFFFFFFU)
#define SRC_GPR_PERSISTENT_ARG0_SHIFT            (0U)
#define SRC_GPR_PERSISTENT_ARG0(x)               (((uint32_t)(((uint32_t)(x)) << SRC_GPR_PERSISTENT_ARG0_SHIFT)) & SRC_GPR_PERSISTENT_ARG0_MASK)

#define SRC_GPR_PERSISTENT_ENTRY0_MASK           (0xFFFFFFFFU)
#define SRC_GPR_PERSISTENT_ENTRY0_SHIFT          (0U)
#define SRC_GPR_PERSISTENT_ENTRY0(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GPR_PERSISTENT_ENTRY0_SHIFT)) & SRC_GPR_PERSISTENT_ENTRY0_MASK)

#define SRC_GPR_PERSIST_REDUNDANT_BOOT_MASK      (0xC000000U)
#define SRC_GPR_PERSIST_REDUNDANT_BOOT_SHIFT     (26U)
#define SRC_GPR_PERSIST_REDUNDANT_BOOT(x)        (((uint32_t)(((uint32_t)(x)) << SRC_GPR_PERSIST_REDUNDANT_BOOT_SHIFT)) & SRC_GPR_PERSIST_REDUNDANT_BOOT_MASK)

#define SRC_GPR_PERSIST_SECONDARY_BOOT_MASK      (0x40000000U)
#define SRC_GPR_PERSIST_SECONDARY_BOOT_SHIFT     (30U)
#define SRC_GPR_PERSIST_SECONDARY_BOOT(x)        (((uint32_t)(((uint32_t)(x)) << SRC_GPR_PERSIST_SECONDARY_BOOT_SHIFT)) & SRC_GPR_PERSIST_SECONDARY_BOOT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_Register_Masks */

/* Backward compatibility */
#define SRC_SCR_MWDR_MASK                      SRC_SCR_MASK_WDOG_RST_MASK
#define SRC_SCR_MWDR_SHIFT                     SRC_SCR_MASK_WDOG_RST_SHIFT
#define SRC_SCR_MWDR(x)                        SRC_SCR_MASK_WDOG_RST(x)
#define SRC_SRSR_WDOG_MASK                     SRC_SRSR_WDOG_RST_B_MASK
#define SRC_SRSR_WDOG_SHIFT                    SRC_SRSR_WDOG_RST_B_SHIFT
#define SRC_SRSR_WDOG(x)                       SRC_SRSR_WDOG_RST_B(x)
#define SRC_SRSR_JTAG_MASK                     SRC_SRSR_JTAG_RST_B_MASK
#define SRC_SRSR_JTAG_SHIFT                    SRC_SRSR_JTAG_RST_B_SHIFT
#define SRC_SRSR_JTAG(x)                       SRC_SRSR_JTAG_RST_B(x)
#define SRC_SRSR_SJC_MASK                      SRC_SRSR_JTAG_SW_RST_MASK
#define SRC_SRSR_SJC_SHIFT                     SRC_SRSR_JTAG_SW_RST_SHIFT
#define SRC_SRSR_SJC(x)                        SRC_SRSR_JTAG_SW_RST(x)
#define SRC_SRSR_TSR_MASK                      SRC_SRSR_TEMPSENSE_RST_B_MASK
#define SRC_SRSR_TSR_SHIFT                     SRC_SRSR_TEMPSENSE_RST_B_SHIFT
#define SRC_SRSR_TSR(x)                        SRC_SRSR_TEMPSENSE_RST_B(x)
/* Extra definition */
#define SRC_SRSR_W1C_BITS_MASK  ( SRC_SRSR_WDOG3_RST_B_MASK \
                                | SRC_SRSR_JTAG_SW_RST_MASK \
                                | SRC_SRSR_JTAG_RST_B_MASK \
                                | SRC_SRSR_WDOG_RST_B_MASK \
                                | SRC_SRSR_IPP_USER_RESET_B_MASK \
                                | SRC_SRSR_CSU_RESET_B_MASK \
                                | SRC_SRSR_LOCKUP_SYSRESETREQ_MASK \
                                | SRC_SRSR_IPP_RESET_B_MASK)


/*!
 * @}
 */ /* end of group SRC_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_H_ */

