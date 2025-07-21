/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTL.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTL
 *
 * CMSIS Peripheral Access Layer for BLK_CTL
 */

#if !defined(PERI_BLK_CTL_H_)
#define PERI_BLK_CTL_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- BLK_CTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTL_Peripheral_Access_Layer BLK_CTL Peripheral Access Layer
 * @{
 */

/** BLK_CTL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Reset Control, offset: 0x0 */
    __IO uint32_t SET;                               /**< Reset Control, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Reset Control, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Reset Control, offset: 0xC */
  } RESET_CTRL;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Control, offset: 0x10 */
    __IO uint32_t SET;                               /**< Control, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Control, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Control, offset: 0x1C */
  } CONTROL0;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< Spare Control0, offset: 0x20 */
    __IO uint32_t SET;                               /**< Spare Control0, offset: 0x24 */
    __IO uint32_t CLR;                               /**< Spare Control0, offset: 0x28 */
    __IO uint32_t TOG;                               /**< Spare Control0, offset: 0x2C */
  } SPARE_CTRL0;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Spare Control1, offset: 0x30 */
    __IO uint32_t SET;                               /**< Spare Control1, offset: 0x34 */
    __IO uint32_t CLR;                               /**< Spare Control1, offset: 0x38 */
    __IO uint32_t TOG;                               /**< Spare Control1, offset: 0x3C */
  } SPARE_CTRL1;
  struct {                                         /* offset: 0x40 */
    __I  uint32_t RW;                                /**< Spare Status0, offset: 0x40 */
    __I  uint32_t SET;                               /**< Spare Status0, offset: 0x44 */
    __I  uint32_t CLR;                               /**< Spare Status0, offset: 0x48 */
    __I  uint32_t TOG;                               /**< Spare Status0, offset: 0x4C */
  } SPARE_STATUS0;
} BLK_CTL_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTL_Register_Masks BLK_CTL Register Masks
 * @{
 */

/*! @name RESET_CTRL - Reset Control */
/*! @{ */

#define BLK_CTL_RESET_CTRL_B_CLK_RESETN_MASK     (0x1U)
#define BLK_CTL_RESET_CTRL_B_CLK_RESETN_SHIFT    (0U)
/*! B_CLK_RESETN - b_clk domain modules resetn */
#define BLK_CTL_RESET_CTRL_B_CLK_RESETN(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTL_RESET_CTRL_B_CLK_RESETN_SHIFT)) & BLK_CTL_RESET_CTRL_B_CLK_RESETN_MASK)

#define BLK_CTL_RESET_CTRL_APB_CLK_RESETN_MASK   (0x2U)
#define BLK_CTL_RESET_CTRL_APB_CLK_RESETN_SHIFT  (1U)
/*! APB_CLK_RESETN - apb_clk domain modules resetn */
#define BLK_CTL_RESET_CTRL_APB_CLK_RESETN(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTL_RESET_CTRL_APB_CLK_RESETN_SHIFT)) & BLK_CTL_RESET_CTRL_APB_CLK_RESETN_MASK)

#define BLK_CTL_RESET_CTRL_P_CLK_RESETN_MASK     (0x4U)
#define BLK_CTL_RESET_CTRL_P_CLK_RESETN_SHIFT    (2U)
/*! P_CLK_RESETN - p_clk domain modules resetn */
#define BLK_CTL_RESET_CTRL_P_CLK_RESETN(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTL_RESET_CTRL_P_CLK_RESETN_SHIFT)) & BLK_CTL_RESET_CTRL_P_CLK_RESETN_MASK)

#define BLK_CTL_RESET_CTRL_RTR_CLK_RESETN_MASK   (0x8U)
#define BLK_CTL_RESET_CTRL_RTR_CLK_RESETN_SHIFT  (3U)
/*! RTR_CLK_RESETN - rtr_clk domain modules resetn */
#define BLK_CTL_RESET_CTRL_RTR_CLK_RESETN(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTL_RESET_CTRL_RTR_CLK_RESETN_SHIFT)) & BLK_CTL_RESET_CTRL_RTR_CLK_RESETN_MASK)

#define BLK_CTL_RESET_CTRL_SPARE_CLK_RESETN_MASK (0xFF0000U)
#define BLK_CTL_RESET_CTRL_SPARE_CLK_RESETN_SHIFT (16U)
/*! SPARE_CLK_RESETN - spare clk domain resetn */
#define BLK_CTL_RESET_CTRL_SPARE_CLK_RESETN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTL_RESET_CTRL_SPARE_CLK_RESETN_SHIFT)) & BLK_CTL_RESET_CTRL_SPARE_CLK_RESETN_MASK)
/*! @} */

/*! @name CONTROL0 - Control */
/*! @{ */

#define BLK_CTL_CONTROL0_DISPMIX_REFCLK_SEL_MASK (0x30U)
#define BLK_CTL_CONTROL0_DISPMIX_REFCLK_SEL_SHIFT (4U)
/*! DISPMIX_REFCLK_SEL - Display Subsystem Reference Clock Select */
#define BLK_CTL_CONTROL0_DISPMIX_REFCLK_SEL(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTL_CONTROL0_DISPMIX_REFCLK_SEL_SHIFT)) & BLK_CTL_CONTROL0_DISPMIX_REFCLK_SEL_MASK)

#define BLK_CTL_CONTROL0_DISPMIX_PIXCLK_SEL_MASK (0x100U)
#define BLK_CTL_CONTROL0_DISPMIX_PIXCLK_SEL_SHIFT (8U)
/*! DISPMIX_PIXCLK_SEL - Display Subsystem Pixel Clock Select */
#define BLK_CTL_CONTROL0_DISPMIX_PIXCLK_SEL(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTL_CONTROL0_DISPMIX_PIXCLK_SEL_SHIFT)) & BLK_CTL_CONTROL0_DISPMIX_PIXCLK_SEL_MASK)
/*! @} */

/*! @name SPARE_CTRL0 - Spare Control0 */
/*! @{ */

#define BLK_CTL_SPARE_CTRL0_SPARE_CTRL_MASK      (0xFFFFFFFFU)
#define BLK_CTL_SPARE_CTRL0_SPARE_CTRL_SHIFT     (0U)
/*! SPARE_CTRL - SPARE Control */
#define BLK_CTL_SPARE_CTRL0_SPARE_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTL_SPARE_CTRL0_SPARE_CTRL_SHIFT)) & BLK_CTL_SPARE_CTRL0_SPARE_CTRL_MASK)
/*! @} */

/*! @name SPARE_CTRL1 - Spare Control1 */
/*! @{ */

#define BLK_CTL_SPARE_CTRL1_SPARE_CTRL_MASK      (0xFFFFFFFFU)
#define BLK_CTL_SPARE_CTRL1_SPARE_CTRL_SHIFT     (0U)
/*! SPARE_CTRL - SPARE Control */
#define BLK_CTL_SPARE_CTRL1_SPARE_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTL_SPARE_CTRL1_SPARE_CTRL_SHIFT)) & BLK_CTL_SPARE_CTRL1_SPARE_CTRL_MASK)
/*! @} */

/*! @name SPARE_STATUS0 - Spare Status0 */
/*! @{ */

#define BLK_CTL_SPARE_STATUS0_SPARE_STATUS_MASK  (0xFFFFFFFFU)
#define BLK_CTL_SPARE_STATUS0_SPARE_STATUS_SHIFT (0U)
/*! SPARE_STATUS - SPARE Control */
#define BLK_CTL_SPARE_STATUS0_SPARE_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTL_SPARE_STATUS0_SPARE_STATUS_SHIFT)) & BLK_CTL_SPARE_STATUS0_SPARE_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTL_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTL_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTL_H_ */

