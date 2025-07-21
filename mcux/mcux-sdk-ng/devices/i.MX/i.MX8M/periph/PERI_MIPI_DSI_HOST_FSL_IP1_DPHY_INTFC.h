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
**         CMSIS Peripheral Access Layer for MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC
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
 * @file PERI_MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC
 */

#if !defined(PERI_MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_H_)
#define PERI_MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_H_ /**< Symbol preventing repeated inclusion */

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
   -- MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Peripheral_Access_Layer MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC Peripheral Access Layer
 * @{
 */

/** MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DPHY_PD_DPHY;                      /**< offset: 0x0 */
  __IO uint32_t DPHY_M_PRG_HS_PREPARE;             /**< offset: 0x4 */
  __IO uint32_t DPHY_MC_PRG_HS_PREPARE;            /**< offset: 0x8 */
  __IO uint32_t DPHY_M_PRG_HS_ZERO;                /**< offset: 0xC */
  __IO uint32_t DPHY_MC_PRG_HS_ZERO;               /**< offset: 0x10 */
  __IO uint32_t DPHY_M_PRG_HS_TRAIL;               /**< offset: 0x14 */
  __IO uint32_t DPHY_MC_PRG_HS_TRAIL;              /**< offset: 0x18 */
  __IO uint32_t DPHY_PD_PLL;                       /**< offset: 0x1C */
  __IO uint32_t DPHY_TST;                          /**< offset: 0x20 */
  __IO uint32_t DPHY_CN;                           /**< offset: 0x24 */
  __IO uint32_t DPHY_CM;                           /**< offset: 0x28 */
  __IO uint32_t DPHY_CO;                           /**< offset: 0x2C */
  __I  uint32_t DPHY_LOCK;                         /**< offset: 0x30 */
  __IO uint32_t DPHY_LOCK_BYP;                     /**< offset: 0x34 */
  __IO uint32_t DPHY_RTERM_SEL;                    /**< offset: 0x38 */
  __IO uint32_t DPHY_AUTO_PD_EN;                   /**< offset: 0x3C */
  __IO uint32_t DPHY_RXLPRP;                       /**< offset: 0x40 */
  __IO uint32_t DPHY_RXCDRP;                       /**< offset: 0x44 */
} MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Register_Masks MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC Register Masks
 * @{
 */

/*! @name DPHY_PD_DPHY -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_DPHY_dphy_pd_dphy_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_DPHY_dphy_pd_dphy_SHIFT (0U)
/*! dphy_pd_dphy - DPHY PD_DPHY input control. Detailed information about this parameter programming
 *    is available in the MIPI-DSI DPHY section.
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_DPHY_dphy_pd_dphy(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_DPHY_dphy_pd_dphy_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_DPHY_dphy_pd_dphy_MASK)
/*! @} */

/*! @name DPHY_M_PRG_HS_PREPARE -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_PREPARE_dphy_m_prg_hs_prepare_MASK (0x3U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_PREPARE_dphy_m_prg_hs_prepare_SHIFT (0U)
/*! dphy_m_prg_hs_prepare - DPHY m_PRG_HS_PREPARE input. Detailed information about this parameter
 *    programming is available in the MIPI-DSI DPHY section.
 *  0b00..1
 *  0b01..1.5
 *  0b10..2
 *  0b11..2.5
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_PREPARE_dphy_m_prg_hs_prepare(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_PREPARE_dphy_m_prg_hs_prepare_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_PREPARE_dphy_m_prg_hs_prepare_MASK)
/*! @} */

/*! @name DPHY_MC_PRG_HS_PREPARE -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_PREPARE_dphy_mc_prg_hs_prepare_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_PREPARE_dphy_mc_prg_hs_prepare_SHIFT (0U)
/*! dphy_mc_prg_hs_prepare - DPHY mc_PRG_HS_PREPARE input. Detailed information about this parameter
 *    programming is available in the MIPI-DSI DPHY section.
 *  0b0..1
 *  0b1..1.5
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_PREPARE_dphy_mc_prg_hs_prepare(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_PREPARE_dphy_mc_prg_hs_prepare_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_PREPARE_dphy_mc_prg_hs_prepare_MASK)
/*! @} */

/*! @name DPHY_M_PRG_HS_ZERO -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_ZERO_dphy_m_prg_hs_zero_MASK (0x1FU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_ZERO_dphy_m_prg_hs_zero_SHIFT (0U)
/*! dphy_m_prg_hs_zero - DPHY m_PRG_HS_ZERO input. Detailed information about this parameter
 *    programming is available in the MIPI-DSI DPHY section.
 *  0b00000..0
 *  0b00001..1
 *  0b00010..2
 *  0b00011..3
 *  0b00100..4
 *  0b00101..5
 *  0b00110..6
 *  0b00111..7
 *  0b01000..8
 *  0b01001..9
 *  0b01010..10
 *  0b01011..11
 *  0b01100..12
 *  0b01101..13
 *  0b01110..14
 *  0b01111..15
 *  0b10000..16
 *  0b10001..17
 *  0b10010..18
 *  0b10011..19
 *  0b10100..20
 *  0b10101..21
 *  0b10110..22
 *  0b10111..23
 *  0b11000..24
 *  0b11001..25
 *  0b11010..26
 *  0b11011..27
 *  0b11100..28
 *  0b11101..29
 *  0b11110..30
 *  0b11111..31
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_ZERO_dphy_m_prg_hs_zero(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_ZERO_dphy_m_prg_hs_zero_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_ZERO_dphy_m_prg_hs_zero_MASK)
/*! @} */

/*! @name DPHY_MC_PRG_HS_ZERO -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_ZERO_dphy_mc_prg_hs_zero_MASK (0x3FU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_ZERO_dphy_mc_prg_hs_zero_SHIFT (0U)
/*! dphy_mc_prg_hs_zero - DPHY mc_PRG_HS_ZERO input. Detailed information about this parameter
 *    programming is available in the MIPI-DSI DPHY section.
 *  0b100000..32
 *  0b100001..33
 *  0b100010..34
 *  0b100011..35
 *  0b100100..36
 *  0b100101..37
 *  0b100110..38
 *  0b100111..39
 *  0b101000..40
 *  0b101001..41
 *  0b101010..42
 *  0b101011..43
 *  0b101100..44
 *  0b101101..45
 *  0b101110..46
 *  0b101111..47
 *  0b110000..48
 *  0b110001..49
 *  0b110010..50
 *  0b110011..51
 *  0b110100..52
 *  0b110101..53
 *  0b110110..54
 *  0b110111..55
 *  0b111000..56
 *  0b111001..57
 *  0b111010..58
 *  0b111011..59
 *  0b111100..60
 *  0b111101..61
 *  0b111110..62
 *  0b111111..63
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_ZERO_dphy_mc_prg_hs_zero(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_ZERO_dphy_mc_prg_hs_zero_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_ZERO_dphy_mc_prg_hs_zero_MASK)
/*! @} */

/*! @name DPHY_M_PRG_HS_TRAIL -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_TRAIL_dphy_m_prg_hs_trail_MASK (0xFU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_TRAIL_dphy_m_prg_hs_trail_SHIFT (0U)
/*! dphy_m_prg_hs_trail - DPHY m_PRG_HS_TRAIL input. Detailed information about this parameter
 *    programming is available in the MIPI-DSI DPHY section.
 *  0b0000..0
 *  0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 *  0b1001..9
 *  0b1010..10
 *  0b1011..11
 *  0b1100..12
 *  0b1101..13
 *  0b1110..14
 *  0b1111..15
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_TRAIL_dphy_m_prg_hs_trail(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_TRAIL_dphy_m_prg_hs_trail_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_M_PRG_HS_TRAIL_dphy_m_prg_hs_trail_MASK)
/*! @} */

/*! @name DPHY_MC_PRG_HS_TRAIL -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_TRAIL_dphy_mc_prg_hs_trail_MASK (0xFU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_TRAIL_dphy_mc_prg_hs_trail_SHIFT (0U)
/*! dphy_mc_prg_hs_trail - DPHY mc_PRG_HS_TRAIL input. Detailed information about this parameter
 *    programming is available in the MIPI-DSI DPHY section.
 *  0b0000..0
 *  0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 *  0b1001..9
 *  0b1010..10
 *  0b1011..11
 *  0b1100..12
 *  0b1101..13
 *  0b1110..14
 *  0b1111..15
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_TRAIL_dphy_mc_prg_hs_trail(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_TRAIL_dphy_mc_prg_hs_trail_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_MC_PRG_HS_TRAIL_dphy_mc_prg_hs_trail_MASK)
/*! @} */

/*! @name DPHY_PD_PLL -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_PLL_PD_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_PLL_PD_SHIFT (0U)
/*! PD - DPHY PD_PLL input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_PLL_PD(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_PLL_PD_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_PD_PLL_PD_MASK)
/*! @} */

/*! @name DPHY_TST -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_TST_TST_MASK (0x3FU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_TST_TST_SHIFT (0U)
/*! TST - DPHY TST input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_TST_TST(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_TST_TST_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_TST_TST_MASK)
/*! @} */

/*! @name DPHY_CN -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CN_CN_MASK (0x1FU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CN_CN_SHIFT (0U)
/*! CN
 *  0b00000..Divide by 2
 *  0b00001..Divide by 32
 *  0b00010..Divide by 11
 *  0b00011..Divide by 31
 *  0b00100..Divide by 10
 *  0b00101..Divide by 26
 *  0b00110..Divide by 30
 *  0b00111..Divide by 7
 *  0b01000..Divide by 13
 *  0b01001..Divide by 9
 *  0b01010..Divide by 15
 *  0b01011..Divide by 25
 *  0b01100..Divide by 29
 *  0b01101..Divide by 23
 *  0b01110..Divide by 6
 *  0b01111..Divide by 20
 *  0b10000..Divide by 3
 *  0b10001..Divide by 12
 *  0b10010..Divide by 27
 *  0b10011..Divide by 8
 *  0b10100..Divide by 14
 *  0b10101..Divide by 16
 *  0b10110..Divide by 24
 *  0b10111..Divide by 21
 *  0b11000..Divide by 4
 *  0b11001..Divide by 28
 *  0b11010..Divide by 17
 *  0b11011..Divide by 22
 *  0b11100..Divide by 5
 *  0b11101..Divide by 18
 *  0b11110..Divide by 19
 *  0b11111..Divide by 1
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CN_CN(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CN_CN_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CN_CN_MASK)
/*! @} */

/*! @name DPHY_CM -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CM_CM_MASK (0xFFU)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CM_CM_SHIFT (0U)
/*! CM
 *  0b00000000..Divide by 128
 *  0b01111111..Divide by 255
 *  0b10000000..Divide by 64
 *  0b10111111..Divide by 127
 *  0b11000000..Divide by 32
 *  0b11011111..Divide by 63
 *  0b111x0000..Divide by 16
 *  0b111x1111..Divide by 31
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CM_CM(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CM_CM_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CM_CM_MASK)
/*! @} */

/*! @name DPHY_CO -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CO_CO_MASK (0x3U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CO_CO_SHIFT (0U)
/*! CO
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 4
 *  0b11..Divide by 8
 */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CO_CO(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CO_CO_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_CO_CO_MASK)
/*! @} */

/*! @name DPHY_LOCK -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_LOCK_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_LOCK_SHIFT (0U)
/*! LOCK - DPHY PLL LOCK output. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_LOCK(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_LOCK_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_LOCK_MASK)
/*! @} */

/*! @name DPHY_LOCK_BYP -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_BYP_dphy_lock_byp_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_BYP_dphy_lock_byp_SHIFT (0U)
/*! dphy_lock_byp - DPHY LOCK_BYP input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_BYP_dphy_lock_byp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_BYP_dphy_lock_byp_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_LOCK_BYP_dphy_lock_byp_MASK)
/*! @} */

/*! @name DPHY_RTERM_SEL -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RTERM_SEL_dphy_rterm_sel_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RTERM_SEL_dphy_rterm_sel_SHIFT (0U)
/*! dphy_rterm_sel - DPHY RTERM_SEL input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RTERM_SEL_dphy_rterm_sel(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RTERM_SEL_dphy_rterm_sel_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RTERM_SEL_dphy_rterm_sel_MASK)
/*! @} */

/*! @name DPHY_AUTO_PD_EN -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_AUTO_PD_EN_dphy_auto_pd_en_MASK (0x1U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_AUTO_PD_EN_dphy_auto_pd_en_SHIFT (0U)
/*! dphy_auto_pd_en - DPHY AUTO_PD_EN input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_AUTO_PD_EN_dphy_auto_pd_en(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_AUTO_PD_EN_dphy_auto_pd_en_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_AUTO_PD_EN_dphy_auto_pd_en_MASK)
/*! @} */

/*! @name DPHY_RXLPRP -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXLPRP_dphy_rxlprp_MASK (0x3U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXLPRP_dphy_rxlprp_SHIFT (0U)
/*! dphy_rxlprp - DPHY RXLPRP input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXLPRP_dphy_rxlprp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXLPRP_dphy_rxlprp_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXLPRP_dphy_rxlprp_MASK)
/*! @} */

/*! @name DPHY_RXCDRP -  */
/*! @{ */

#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXCDRP_dphy_rxcdrp_MASK (0x3U)
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXCDRP_dphy_rxcdrp_SHIFT (0U)
/*! dphy_rxcdrp - DPHY RXCDRP input. Detailed information about this parameter programming is available in the MIPI-DSI DPHY section. */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXCDRP_dphy_rxcdrp(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXCDRP_dphy_rxcdrp_SHIFT)) & MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_DPHY_RXCDRP_dphy_rxcdrp_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_H_ */

