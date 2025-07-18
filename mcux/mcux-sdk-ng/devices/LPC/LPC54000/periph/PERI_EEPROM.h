/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EEPROM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EEPROM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EEPROM
 *
 * CMSIS Peripheral Access Layer for EEPROM
 */

#if !defined(PERI_EEPROM_H_)
#define PERI_EEPROM_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
   -- EEPROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EEPROM_Peripheral_Access_Layer EEPROM Peripheral Access Layer
 * @{
 */

/** EEPROM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CMD;                               /**< EEPROM command register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t RWSTATE;                           /**< EEPROM read wait state register, offset: 0x8 */
  __IO uint32_t AUTOPROG;                          /**< EEPROM auto programming register, offset: 0xC */
  __IO uint32_t WSTATE;                            /**< EEPROM wait state register, offset: 0x10 */
  __IO uint32_t CLKDIV;                            /**< EEPROM clock divider register, offset: 0x14 */
  __IO uint32_t PWRDWN;                            /**< EEPROM power-down register, offset: 0x18 */
       uint8_t RESERVED_1[4028];
  __O  uint32_t INTENCLR;                          /**< EEPROM interrupt enable clear, offset: 0xFD8 */
  __O  uint32_t INTENSET;                          /**< EEPROM interrupt enable set, offset: 0xFDC */
  __I  uint32_t INTSTAT;                           /**< EEPROM interrupt status, offset: 0xFE0 */
  __I  uint32_t INTEN;                             /**< EEPROM interrupt enable, offset: 0xFE4 */
  __O  uint32_t INTSTATCLR;                        /**< EEPROM interrupt status clear, offset: 0xFE8 */
  __O  uint32_t INTSTATSET;                        /**< EEPROM interrupt status set, offset: 0xFEC */
} EEPROM_Type;

/* ----------------------------------------------------------------------------
   -- EEPROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EEPROM_Register_Masks EEPROM Register Masks
 * @{
 */

/*! @name CMD - EEPROM command register */
/*! @{ */

#define EEPROM_CMD_CMD_MASK                      (0x7U)
#define EEPROM_CMD_CMD_SHIFT                     (0U)
/*! CMD - Command. */
#define EEPROM_CMD_CMD(x)                        (((uint32_t)(((uint32_t)(x)) << EEPROM_CMD_CMD_SHIFT)) & EEPROM_CMD_CMD_MASK)
/*! @} */

/*! @name RWSTATE - EEPROM read wait state register */
/*! @{ */

#define EEPROM_RWSTATE_RPHASE2_MASK              (0xFFU)
#define EEPROM_RWSTATE_RPHASE2_SHIFT             (0U)
/*! RPHASE2 - Wait states 2 (minus 1 encoded). */
#define EEPROM_RWSTATE_RPHASE2(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_RWSTATE_RPHASE2_SHIFT)) & EEPROM_RWSTATE_RPHASE2_MASK)

#define EEPROM_RWSTATE_RPHASE1_MASK              (0xFF00U)
#define EEPROM_RWSTATE_RPHASE1_SHIFT             (8U)
/*! RPHASE1 - Wait states 1 (minus 1 encoded). */
#define EEPROM_RWSTATE_RPHASE1(x)                (((uint32_t)(((uint32_t)(x)) << EEPROM_RWSTATE_RPHASE1_SHIFT)) & EEPROM_RWSTATE_RPHASE1_MASK)
/*! @} */

/*! @name AUTOPROG - EEPROM auto programming register */
/*! @{ */

#define EEPROM_AUTOPROG_AUTOPROG_MASK            (0x3U)
#define EEPROM_AUTOPROG_AUTOPROG_SHIFT           (0U)
/*! AUTOPROG - Auto programming mode: 00 = auto programming off 01 = erase/program cycle is
 *    triggered after 1 word is written 10 = erase/program cycle is triggered after a write to AHB address
 *    ending with .
 */
#define EEPROM_AUTOPROG_AUTOPROG(x)              (((uint32_t)(((uint32_t)(x)) << EEPROM_AUTOPROG_AUTOPROG_SHIFT)) & EEPROM_AUTOPROG_AUTOPROG_MASK)
/*! @} */

/*! @name WSTATE - EEPROM wait state register */
/*! @{ */

#define EEPROM_WSTATE_PHASE3_MASK                (0xFFU)
#define EEPROM_WSTATE_PHASE3_SHIFT               (0U)
/*! PHASE3 - Wait states for phase 3 (minus 1 encoded). */
#define EEPROM_WSTATE_PHASE3(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_PHASE3_SHIFT)) & EEPROM_WSTATE_PHASE3_MASK)

#define EEPROM_WSTATE_PHASE2_MASK                (0xFF00U)
#define EEPROM_WSTATE_PHASE2_SHIFT               (8U)
/*! PHASE2 - Wait states for phase 2 (minus 1 encoded). */
#define EEPROM_WSTATE_PHASE2(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_PHASE2_SHIFT)) & EEPROM_WSTATE_PHASE2_MASK)

#define EEPROM_WSTATE_PHASE1_MASK                (0xFF0000U)
#define EEPROM_WSTATE_PHASE1_SHIFT               (16U)
/*! PHASE1 - Wait states for phase 1 (minus 1 encoded). */
#define EEPROM_WSTATE_PHASE1(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_PHASE1_SHIFT)) & EEPROM_WSTATE_PHASE1_MASK)

#define EEPROM_WSTATE_LCK_PARWEP_MASK            (0x80000000U)
#define EEPROM_WSTATE_LCK_PARWEP_SHIFT           (31U)
/*! LCK_PARWEP - Lock timing parameters for write, erase and program operation 0 = WSTATE and CLKDIV
 *    registers have R/W access 1 = WSTATE and CLKDIV registers have R only access.
 */
#define EEPROM_WSTATE_LCK_PARWEP(x)              (((uint32_t)(((uint32_t)(x)) << EEPROM_WSTATE_LCK_PARWEP_SHIFT)) & EEPROM_WSTATE_LCK_PARWEP_MASK)
/*! @} */

/*! @name CLKDIV - EEPROM clock divider register */
/*! @{ */

#define EEPROM_CLKDIV_CLKDIV_MASK                (0xFFFFU)
#define EEPROM_CLKDIV_CLKDIV_SHIFT               (0U)
/*! CLKDIV - Division factor (minus 1 encoded). */
#define EEPROM_CLKDIV_CLKDIV(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_CLKDIV_CLKDIV_SHIFT)) & EEPROM_CLKDIV_CLKDIV_MASK)
/*! @} */

/*! @name PWRDWN - EEPROM power-down register */
/*! @{ */

#define EEPROM_PWRDWN_PWRDWN_MASK                (0x1U)
#define EEPROM_PWRDWN_PWRDWN_SHIFT               (0U)
/*! PWRDWN - Power down mode bit. */
#define EEPROM_PWRDWN_PWRDWN(x)                  (((uint32_t)(((uint32_t)(x)) << EEPROM_PWRDWN_PWRDWN_SHIFT)) & EEPROM_PWRDWN_PWRDWN_MASK)
/*! @} */

/*! @name INTENCLR - EEPROM interrupt enable clear */
/*! @{ */

#define EEPROM_INTENCLR_PROG_CLR_EN_MASK         (0x4U)
#define EEPROM_INTENCLR_PROG_CLR_EN_SHIFT        (2U)
/*! PROG_CLR_EN - Clear program operation finished interrupt enable bit for EEPROM. */
#define EEPROM_INTENCLR_PROG_CLR_EN(x)           (((uint32_t)(((uint32_t)(x)) << EEPROM_INTENCLR_PROG_CLR_EN_SHIFT)) & EEPROM_INTENCLR_PROG_CLR_EN_MASK)
/*! @} */

/*! @name INTENSET - EEPROM interrupt enable set */
/*! @{ */

#define EEPROM_INTENSET_PROG_SET_EN_MASK         (0x4U)
#define EEPROM_INTENSET_PROG_SET_EN_SHIFT        (2U)
/*! PROG_SET_EN - Set program operation finished interrupt enable bit for EEPROM device 1. */
#define EEPROM_INTENSET_PROG_SET_EN(x)           (((uint32_t)(((uint32_t)(x)) << EEPROM_INTENSET_PROG_SET_EN_SHIFT)) & EEPROM_INTENSET_PROG_SET_EN_MASK)
/*! @} */

/*! @name INTSTAT - EEPROM interrupt status */
/*! @{ */

#define EEPROM_INTSTAT_END_OF_PROG_MASK          (0x4U)
#define EEPROM_INTSTAT_END_OF_PROG_SHIFT         (2U)
/*! END_OF_PROG - EEPROM program operation finished interrupt status bit. */
#define EEPROM_INTSTAT_END_OF_PROG(x)            (((uint32_t)(((uint32_t)(x)) << EEPROM_INTSTAT_END_OF_PROG_SHIFT)) & EEPROM_INTSTAT_END_OF_PROG_MASK)
/*! @} */

/*! @name INTEN - EEPROM interrupt enable */
/*! @{ */

#define EEPROM_INTEN_EE_PROG_DONE_MASK           (0x4U)
#define EEPROM_INTEN_EE_PROG_DONE_SHIFT          (2U)
/*! EE_PROG_DONE - EEPROM program operation finished interrupt enable bit. */
#define EEPROM_INTEN_EE_PROG_DONE(x)             (((uint32_t)(((uint32_t)(x)) << EEPROM_INTEN_EE_PROG_DONE_SHIFT)) & EEPROM_INTEN_EE_PROG_DONE_MASK)
/*! @} */

/*! @name INTSTATCLR - EEPROM interrupt status clear */
/*! @{ */

#define EEPROM_INTSTATCLR_PROG_CLR_ST_MASK       (0x4U)
#define EEPROM_INTSTATCLR_PROG_CLR_ST_SHIFT      (2U)
/*! PROG_CLR_ST - Clear program operation finished interrupt status bit for EEPROM device. */
#define EEPROM_INTSTATCLR_PROG_CLR_ST(x)         (((uint32_t)(((uint32_t)(x)) << EEPROM_INTSTATCLR_PROG_CLR_ST_SHIFT)) & EEPROM_INTSTATCLR_PROG_CLR_ST_MASK)
/*! @} */

/*! @name INTSTATSET - EEPROM interrupt status set */
/*! @{ */

#define EEPROM_INTSTATSET_PROG_SET_ST_MASK       (0x4U)
#define EEPROM_INTSTATSET_PROG_SET_ST_SHIFT      (2U)
/*! PROG_SET_ST - Set program operation finished interrupt status bit for EEPROM device. */
#define EEPROM_INTSTATSET_PROG_SET_ST(x)         (((uint32_t)(((uint32_t)(x)) << EEPROM_INTSTATSET_PROG_SET_ST_SHIFT)) & EEPROM_INTSTATSET_PROG_SET_ST_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EEPROM_Register_Masks */


/*!
 * @}
 */ /* end of group EEPROM_Peripheral_Access_Layer */


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


#endif  /* PERI_EEPROM_H_ */

