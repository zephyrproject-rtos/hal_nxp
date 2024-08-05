/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ATP.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ATP
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_ATP_H_)  /* Check if memory map has not been already included */
#define S32Z2_ATP_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ATP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ATP_Peripheral_Access_Layer ATP Peripheral Access Layer
 * @{
 */

/** ATP - Register Layout Typedef */
typedef struct {
  __IO uint32_t PLLC;                              /**< PLL Control, offset: 0x0 */
  __IO uint32_t PLLS;                              /**< PLL Status, offset: 0x4 */
  __IO uint32_t PLLDIV;                            /**< PLL Divider, offset: 0x8 */
  uint8_t RESERVED_0[12];
  __IO uint32_t PLLCAL_2;                          /**< PLL Calibration 2, offset: 0x18 */
  uint8_t RESERVED_1[4];
  __IO uint32_t PLLCKMUX;                          /**< PLL Clock MUX, offset: 0x20 */
  uint8_t RESERVED_2[732];
  __I  uint32_t ALS;                               /**< AL Status, offset: 0x300 */
  uint8_t RESERVED_3[4];
  __IO uint32_t ALGC;                              /**< AL General Control, offset: 0x308 */
  __IO uint32_t ALTC;                              /**< AL Training Control, offset: 0x30C */
  uint8_t RESERVED_4[304];
  __IO uint32_t LVDSTX;                            /**< LVDS TX IO Configuration, offset: 0x440 */
  __IO uint32_t LVDSRX;                            /**< LVDS RX IO Configuration, offset: 0x444 */
  __IO uint32_t LVDSTXOBE;                         /**< LVDS TX OBE Configuration, offset: 0x448 */
  uint8_t RESERVED_5[52];
  __IO uint32_t CIAC;                              /**< CIA Control, offset: 0x480 */
  uint8_t RESERVED_6[4];
  __IO uint32_t ATPE;                              /**< Aurora Trace Port Enable, offset: 0x488 */
  uint8_t RESERVED_7[2676];
  __I  uint32_t ITCTRL;                            /**< Integration Mode Control, offset: 0xF00 */
  uint8_t RESERVED_8[156];
  __I  uint32_t CLAIMSET;                          /**< Claim Tag Set, offset: 0xFA0 */
  __I  uint32_t CLAIMCLR;                          /**< Claim Tag Clear, offset: 0xFA4 */
  __I  uint32_t DEVAFF0;                           /**< Device Affinity 0, offset: 0xFA8 */
  __I  uint32_t DEVAFF1;                           /**< Device Affinity 1, offset: 0xFAC */
  __O  uint32_t LAR;                               /**< Lock Access Register, offset: 0xFB0 */
  __I  uint32_t LSR;                               /**< Lock Status Register, offset: 0xFB4 */
  __I  uint32_t AUTHSTATUS;                        /**< Authentication Status, offset: 0xFB8 */
  __I  uint32_t DEVARCH;                           /**< Device Architecture, offset: 0xFBC */
  __I  uint32_t DEVID2;                            /**< Device Configuration 2, offset: 0xFC0 */
  __I  uint32_t DEVID1;                            /**< Device Configuration 1, offset: 0xFC4 */
  __I  uint32_t DEVID;                             /**< Device Configuration, offset: 0xFC8 */
  __I  uint32_t DEVTYPE;                           /**< Device Type Identifier, offset: 0xFCC */
  __I  uint32_t PIDR4;                             /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint8_t RESERVED_9[12];
  __I  uint32_t PIDR0;                             /**< Peripheral Identification Register 0, offset: 0xFE0 */
  __I  uint32_t PIDR1;                             /**< Peripheral Identification Register 1, offset: 0xFE4 */
  __I  uint32_t PIDR2;                             /**< Peripheral Identification Register 2, offset: 0xFE8 */
  __I  uint32_t PIDR3;                             /**< Peripheral Identification Register 3, offset: 0xFEC */
  __I  uint32_t CIDR0;                             /**< Component Identification Register 0, offset: 0xFF0 */
  __I  uint32_t CIDR1;                             /**< Component Identification Register 1, offset: 0xFF4 */
  __I  uint32_t CIDR2;                             /**< Component Identification Register 2, offset: 0xFF8 */
  __I  uint32_t CIDR3;                             /**< Component Identification Register 3, offset: 0xFFC */
} ATP_Type, *ATP_MemMapPtr;

/** Number of instances of the ATP module. */
#define ATP_INSTANCE_COUNT                       (1u)

/* ATP - Peripheral instance base addresses */
/** Peripheral ATP base address */
#define IP_ATP_BASE                              (0x4D190000u)
/** Peripheral ATP base pointer */
#define IP_ATP                                   ((ATP_Type *)IP_ATP_BASE)
/** Array initializer of ATP peripheral base addresses */
#define IP_ATP_BASE_ADDRS                        { IP_ATP_BASE }
/** Array initializer of ATP peripheral base pointers */
#define IP_ATP_BASE_PTRS                         { IP_ATP }

/* ----------------------------------------------------------------------------
   -- ATP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ATP_Register_Masks ATP Register Masks
 * @{
 */

/*! @name PLLC - PLL Control */
/*! @{ */

#define ATP_PLLC_PLLPD_MASK                      (0x80000000U)
#define ATP_PLLC_PLLPD_SHIFT                     (31U)
#define ATP_PLLC_PLLPD_WIDTH                     (1U)
#define ATP_PLLC_PLLPD(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_PLLC_PLLPD_SHIFT)) & ATP_PLLC_PLLPD_MASK)
/*! @} */

/*! @name PLLS - PLL Status */
/*! @{ */

#define ATP_PLLS_LOCK_MASK                       (0x4U)
#define ATP_PLLS_LOCK_SHIFT                      (2U)
#define ATP_PLLS_LOCK_WIDTH                      (1U)
#define ATP_PLLS_LOCK(x)                         (((uint32_t)(((uint32_t)(x)) << ATP_PLLS_LOCK_SHIFT)) & ATP_PLLS_LOCK_MASK)

#define ATP_PLLS_LOL_MASK                        (0x8U)
#define ATP_PLLS_LOL_SHIFT                       (3U)
#define ATP_PLLS_LOL_WIDTH                       (1U)
#define ATP_PLLS_LOL(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_PLLS_LOL_SHIFT)) & ATP_PLLS_LOL_MASK)
/*! @} */

/*! @name PLLDIV - PLL Divider */
/*! @{ */

#define ATP_PLLDIV_MFID_MASK                     (0xFFU)
#define ATP_PLLDIV_MFID_SHIFT                    (0U)
#define ATP_PLLDIV_MFID_WIDTH                    (8U)
#define ATP_PLLDIV_MFID(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_PLLDIV_MFID_SHIFT)) & ATP_PLLDIV_MFID_MASK)

#define ATP_PLLDIV_RDIV_MASK                     (0x7000U)
#define ATP_PLLDIV_RDIV_SHIFT                    (12U)
#define ATP_PLLDIV_RDIV_WIDTH                    (3U)
#define ATP_PLLDIV_RDIV(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_PLLDIV_RDIV_SHIFT)) & ATP_PLLDIV_RDIV_MASK)

#define ATP_PLLDIV_ODIV1_MASK                    (0x3F0000U)
#define ATP_PLLDIV_ODIV1_SHIFT                   (16U)
#define ATP_PLLDIV_ODIV1_WIDTH                   (6U)
#define ATP_PLLDIV_ODIV1(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_PLLDIV_ODIV1_SHIFT)) & ATP_PLLDIV_ODIV1_MASK)
/*! @} */

/*! @name PLLCAL_2 - PLL Calibration 2 */
/*! @{ */

#define ATP_PLLCAL_2_CALDPER_MASK                (0x60000U)
#define ATP_PLLCAL_2_CALDPER_SHIFT               (17U)
#define ATP_PLLCAL_2_CALDPER_WIDTH               (2U)
#define ATP_PLLCAL_2_CALDPER(x)                  (((uint32_t)(((uint32_t)(x)) << ATP_PLLCAL_2_CALDPER_SHIFT)) & ATP_PLLCAL_2_CALDPER_MASK)
/*! @} */

/*! @name PLLCKMUX - PLL Clock MUX */
/*! @{ */

#define ATP_PLLCKMUX_REFCLKSEL_MASK              (0x3U)
#define ATP_PLLCKMUX_REFCLKSEL_SHIFT             (0U)
#define ATP_PLLCKMUX_REFCLKSEL_WIDTH             (2U)
#define ATP_PLLCKMUX_REFCLKSEL(x)                (((uint32_t)(((uint32_t)(x)) << ATP_PLLCKMUX_REFCLKSEL_SHIFT)) & ATP_PLLCKMUX_REFCLKSEL_MASK)
/*! @} */

/*! @name ALS - AL Status */
/*! @{ */

#define ATP_ALS_AS_MASK                          (0x1U)
#define ATP_ALS_AS_SHIFT                         (0U)
#define ATP_ALS_AS_WIDTH                         (1U)
#define ATP_ALS_AS(x)                            (((uint32_t)(((uint32_t)(x)) << ATP_ALS_AS_SHIFT)) & ATP_ALS_AS_MASK)

#define ATP_ALS_CS_MASK                          (0x2U)
#define ATP_ALS_CS_SHIFT                         (1U)
#define ATP_ALS_CS_WIDTH                         (1U)
#define ATP_ALS_CS(x)                            (((uint32_t)(((uint32_t)(x)) << ATP_ALS_CS_SHIFT)) & ATP_ALS_CS_MASK)

#define ATP_ALS_TS_MASK                          (0xCU)
#define ATP_ALS_TS_SHIFT                         (2U)
#define ATP_ALS_TS_WIDTH                         (2U)
#define ATP_ALS_TS(x)                            (((uint32_t)(((uint32_t)(x)) << ATP_ALS_TS_SHIFT)) & ATP_ALS_TS_MASK)

#define ATP_ALS_PRST_MASK                        (0x200U)
#define ATP_ALS_PRST_SHIFT                       (9U)
#define ATP_ALS_PRST_WIDTH                       (1U)
#define ATP_ALS_PRST(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALS_PRST_SHIFT)) & ATP_ALS_PRST_MASK)

#define ATP_ALS_TXCFG_MASK                       (0x1C00U)
#define ATP_ALS_TXCFG_SHIFT                      (10U)
#define ATP_ALS_TXCFG_WIDTH                      (3U)
#define ATP_ALS_TXCFG(x)                         (((uint32_t)(((uint32_t)(x)) << ATP_ALS_TXCFG_SHIFT)) & ATP_ALS_TXCFG_MASK)
/*! @} */

/*! @name ALGC - AL General Control */
/*! @{ */

#define ATP_ALGC_CCOEN_MASK                      (0x4U)
#define ATP_ALGC_CCOEN_SHIFT                     (2U)
#define ATP_ALGC_CCOEN_WIDTH                     (1U)
#define ATP_ALGC_CCOEN(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_ALGC_CCOEN_SHIFT)) & ATP_ALGC_CCOEN_MASK)

#define ATP_ALGC_CRCEN_MASK                      (0x8U)
#define ATP_ALGC_CRCEN_SHIFT                     (3U)
#define ATP_ALGC_CRCEN_WIDTH                     (1U)
#define ATP_ALGC_CRCEN(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_ALGC_CRCEN_SHIFT)) & ATP_ALGC_CRCEN_MASK)

#define ATP_ALGC_PCRST_MASK                      (0x4000U)
#define ATP_ALGC_PCRST_SHIFT                     (14U)
#define ATP_ALGC_PCRST_WIDTH                     (1U)
#define ATP_ALGC_PCRST(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_ALGC_PCRST_SHIFT)) & ATP_ALGC_PCRST_MASK)

#define ATP_ALGC_RST_MASK                        (0x80000000U)
#define ATP_ALGC_RST_SHIFT                       (31U)
#define ATP_ALGC_RST_WIDTH                       (1U)
#define ATP_ALGC_RST(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALGC_RST_SHIFT)) & ATP_ALGC_RST_MASK)
/*! @} */

/*! @name ALTC - AL Training Control */
/*! @{ */

#define ATP_ALTC_VTC_MASK                        (0xFU)
#define ATP_ALTC_VTC_SHIFT                       (0U)
#define ATP_ALTC_VTC_WIDTH                       (4U)
#define ATP_ALTC_VTC(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_VTC_SHIFT)) & ATP_ALTC_VTC_MASK)

#define ATP_ALTC_BTC_MASK                        (0x3C00U)
#define ATP_ALTC_BTC_SHIFT                       (10U)
#define ATP_ALTC_BTC_WIDTH                       (4U)
#define ATP_ALTC_BTC(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_BTC_SHIFT)) & ATP_ALTC_BTC_MASK)

#define ATP_ALTC_ATC_MASK                        (0x780000U)
#define ATP_ALTC_ATC_SHIFT                       (19U)
#define ATP_ALTC_ATC_WIDTH                       (4U)
#define ATP_ALTC_ATC(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_ATC_SHIFT)) & ATP_ALTC_ATC_MASK)

#define ATP_ALTC_VHD_MASK                        (0x10000000U)
#define ATP_ALTC_VHD_SHIFT                       (28U)
#define ATP_ALTC_VHD_WIDTH                       (1U)
#define ATP_ALTC_VHD(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_VHD_SHIFT)) & ATP_ALTC_VHD_MASK)

#define ATP_ALTC_BHD_MASK                        (0x20000000U)
#define ATP_ALTC_BHD_SHIFT                       (29U)
#define ATP_ALTC_BHD_WIDTH                       (1U)
#define ATP_ALTC_BHD(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_BHD_SHIFT)) & ATP_ALTC_BHD_MASK)

#define ATP_ALTC_AHD_MASK                        (0x40000000U)
#define ATP_ALTC_AHD_SHIFT                       (30U)
#define ATP_ALTC_AHD_WIDTH                       (1U)
#define ATP_ALTC_AHD(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_AHD_SHIFT)) & ATP_ALTC_AHD_MASK)

#define ATP_ALTC_STE_MASK                        (0x80000000U)
#define ATP_ALTC_STE_SHIFT                       (31U)
#define ATP_ALTC_STE_WIDTH                       (1U)
#define ATP_ALTC_STE(x)                          (((uint32_t)(((uint32_t)(x)) << ATP_ALTC_STE_SHIFT)) & ATP_ALTC_STE_MASK)
/*! @} */

/*! @name LVDSTX - LVDS TX IO Configuration */
/*! @{ */

#define ATP_LVDSTX_TXAMODE_MASK                  (0x1U)
#define ATP_LVDSTX_TXAMODE_SHIFT                 (0U)
#define ATP_LVDSTX_TXAMODE_WIDTH                 (1U)
#define ATP_LVDSTX_TXAMODE(x)                    (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTX_TXAMODE_SHIFT)) & ATP_LVDSTX_TXAMODE_MASK)

#define ATP_LVDSTX_CREF_EN_MASK                  (0x2U)
#define ATP_LVDSTX_CREF_EN_SHIFT                 (1U)
#define ATP_LVDSTX_CREF_EN_WIDTH                 (1U)
#define ATP_LVDSTX_CREF_EN(x)                    (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTX_CREF_EN_SHIFT)) & ATP_LVDSTX_CREF_EN_MASK)

#define ATP_LVDSTX_TX_TREF_EN_MASK               (0x4U)
#define ATP_LVDSTX_TX_TREF_EN_SHIFT              (2U)
#define ATP_LVDSTX_TX_TREF_EN_WIDTH              (1U)
#define ATP_LVDSTX_TX_TREF_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTX_TX_TREF_EN_SHIFT)) & ATP_LVDSTX_TX_TREF_EN_MASK)

#define ATP_LVDSTX_PREMPH_MASK                   (0x60U)
#define ATP_LVDSTX_PREMPH_SHIFT                  (5U)
#define ATP_LVDSTX_PREMPH_WIDTH                  (2U)
#define ATP_LVDSTX_PREMPH(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTX_PREMPH_SHIFT)) & ATP_LVDSTX_PREMPH_MASK)

#define ATP_LVDSTX_TX_CONF_MASK                  (0xF000U)
#define ATP_LVDSTX_TX_CONF_SHIFT                 (12U)
#define ATP_LVDSTX_TX_CONF_WIDTH                 (4U)
#define ATP_LVDSTX_TX_CONF(x)                    (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTX_TX_CONF_SHIFT)) & ATP_LVDSTX_TX_CONF_MASK)

#define ATP_LVDSTX_PADS_TX_CONF_EN_MASK          (0x10000U)
#define ATP_LVDSTX_PADS_TX_CONF_EN_SHIFT         (16U)
#define ATP_LVDSTX_PADS_TX_CONF_EN_WIDTH         (1U)
#define ATP_LVDSTX_PADS_TX_CONF_EN(x)            (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTX_PADS_TX_CONF_EN_SHIFT)) & ATP_LVDSTX_PADS_TX_CONF_EN_MASK)
/*! @} */

/*! @name LVDSRX - LVDS RX IO Configuration */
/*! @{ */

#define ATP_LVDSRX_RXICE_MASK                    (0x2U)
#define ATP_LVDSRX_RXICE_SHIFT                   (1U)
#define ATP_LVDSRX_RXICE_WIDTH                   (1U)
#define ATP_LVDSRX_RXICE(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_LVDSRX_RXICE_SHIFT)) & ATP_LVDSRX_RXICE_MASK)

#define ATP_LVDSRX_RXCB_MASK                     (0x8U)
#define ATP_LVDSRX_RXCB_SHIFT                    (3U)
#define ATP_LVDSRX_RXCB_WIDTH                    (1U)
#define ATP_LVDSRX_RXCB(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_LVDSRX_RXCB_SHIFT)) & ATP_LVDSRX_RXCB_MASK)

#define ATP_LVDSRX_RX_TREF_EN_MASK               (0x10000U)
#define ATP_LVDSRX_RX_TREF_EN_SHIFT              (16U)
#define ATP_LVDSRX_RX_TREF_EN_WIDTH              (1U)
#define ATP_LVDSRX_RX_TREF_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ATP_LVDSRX_RX_TREF_EN_SHIFT)) & ATP_LVDSRX_RX_TREF_EN_MASK)
/*! @} */

/*! @name LVDSTXOBE - LVDS TX OBE Configuration */
/*! @{ */

#define ATP_LVDSTXOBE_OBETX0_MASK                (0x1U)
#define ATP_LVDSTXOBE_OBETX0_SHIFT               (0U)
#define ATP_LVDSTXOBE_OBETX0_WIDTH               (1U)
#define ATP_LVDSTXOBE_OBETX0(x)                  (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTXOBE_OBETX0_SHIFT)) & ATP_LVDSTXOBE_OBETX0_MASK)

#define ATP_LVDSTXOBE_OBETX1_MASK                (0x2U)
#define ATP_LVDSTXOBE_OBETX1_SHIFT               (1U)
#define ATP_LVDSTXOBE_OBETX1_WIDTH               (1U)
#define ATP_LVDSTXOBE_OBETX1(x)                  (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTXOBE_OBETX1_SHIFT)) & ATP_LVDSTXOBE_OBETX1_MASK)

#define ATP_LVDSTXOBE_OBETX2_MASK                (0x4U)
#define ATP_LVDSTXOBE_OBETX2_SHIFT               (2U)
#define ATP_LVDSTXOBE_OBETX2_WIDTH               (1U)
#define ATP_LVDSTXOBE_OBETX2(x)                  (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTXOBE_OBETX2_SHIFT)) & ATP_LVDSTXOBE_OBETX2_MASK)

#define ATP_LVDSTXOBE_OBETX3_MASK                (0x8U)
#define ATP_LVDSTXOBE_OBETX3_SHIFT               (3U)
#define ATP_LVDSTXOBE_OBETX3_WIDTH               (1U)
#define ATP_LVDSTXOBE_OBETX3(x)                  (((uint32_t)(((uint32_t)(x)) << ATP_LVDSTXOBE_OBETX3_SHIFT)) & ATP_LVDSTXOBE_OBETX3_MASK)
/*! @} */

/*! @name CIAC - CIA Control */
/*! @{ */

#define ATP_CIAC_NUM_LANE_MASK                   (0xFU)
#define ATP_CIAC_NUM_LANE_SHIFT                  (0U)
#define ATP_CIAC_NUM_LANE_WIDTH                  (4U)
#define ATP_CIAC_NUM_LANE(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_CIAC_NUM_LANE_SHIFT)) & ATP_CIAC_NUM_LANE_MASK)

#define ATP_CIAC_TPIUCM_MASK                     (0x70U)
#define ATP_CIAC_TPIUCM_SHIFT                    (4U)
#define ATP_CIAC_TPIUCM_WIDTH                    (3U)
#define ATP_CIAC_TPIUCM(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_CIAC_TPIUCM_SHIFT)) & ATP_CIAC_TPIUCM_MASK)

#define ATP_CIAC_DBITR_MASK                      (0x100U)
#define ATP_CIAC_DBITR_SHIFT                     (8U)
#define ATP_CIAC_DBITR_WIDTH                     (1U)
#define ATP_CIAC_DBITR(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_CIAC_DBITR_SHIFT)) & ATP_CIAC_DBITR_MASK)

#define ATP_CIAC_DBYTER_MASK                     (0x200U)
#define ATP_CIAC_DBYTER_SHIFT                    (9U)
#define ATP_CIAC_DBYTER_WIDTH                    (1U)
#define ATP_CIAC_DBYTER(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_CIAC_DBYTER_SHIFT)) & ATP_CIAC_DBYTER_MASK)

#define ATP_CIAC_TPIU_CLK_SEL_MASK               (0x10000000U)
#define ATP_CIAC_TPIU_CLK_SEL_SHIFT              (28U)
#define ATP_CIAC_TPIU_CLK_SEL_WIDTH              (1U)
#define ATP_CIAC_TPIU_CLK_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << ATP_CIAC_TPIU_CLK_SEL_SHIFT)) & ATP_CIAC_TPIU_CLK_SEL_MASK)

#define ATP_CIAC_TPIU_CLK_DISABLE_MASK           (0x20000000U)
#define ATP_CIAC_TPIU_CLK_DISABLE_SHIFT          (29U)
#define ATP_CIAC_TPIU_CLK_DISABLE_WIDTH          (1U)
#define ATP_CIAC_TPIU_CLK_DISABLE(x)             (((uint32_t)(((uint32_t)(x)) << ATP_CIAC_TPIU_CLK_DISABLE_SHIFT)) & ATP_CIAC_TPIU_CLK_DISABLE_MASK)
/*! @} */

/*! @name ATPE - Aurora Trace Port Enable */
/*! @{ */

#define ATP_ATPE_ATPEN_MASK                      (0x1U)
#define ATP_ATPE_ATPEN_SHIFT                     (0U)
#define ATP_ATPE_ATPEN_WIDTH                     (1U)
#define ATP_ATPE_ATPEN(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_ATPE_ATPEN_SHIFT)) & ATP_ATPE_ATPEN_MASK)

#define ATP_ATPE_APHYEN_MASK                     (0x2U)
#define ATP_ATPE_APHYEN_SHIFT                    (1U)
#define ATP_ATPE_APHYEN_WIDTH                    (1U)
#define ATP_ATPE_APHYEN(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_ATPE_APHYEN_SHIFT)) & ATP_ATPE_APHYEN_MASK)
/*! @} */

/*! @name ITCTRL - Integration Mode Control */
/*! @{ */

#define ATP_ITCTRL_IME_MASK                      (0x1U)
#define ATP_ITCTRL_IME_SHIFT                     (0U)
#define ATP_ITCTRL_IME_WIDTH                     (1U)
#define ATP_ITCTRL_IME(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_ITCTRL_IME_SHIFT)) & ATP_ITCTRL_IME_MASK)
/*! @} */

/*! @name CLAIMSET - Claim Tag Set */
/*! @{ */

#define ATP_CLAIMSET_SET_MASK                    (0xFFFFFFFFU)
#define ATP_CLAIMSET_SET_SHIFT                   (0U)
#define ATP_CLAIMSET_SET_WIDTH                   (32U)
#define ATP_CLAIMSET_SET(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_CLAIMSET_SET_SHIFT)) & ATP_CLAIMSET_SET_MASK)
/*! @} */

/*! @name CLAIMCLR - Claim Tag Clear */
/*! @{ */

#define ATP_CLAIMCLR_CLR_MASK                    (0xFFFFFFFFU)
#define ATP_CLAIMCLR_CLR_SHIFT                   (0U)
#define ATP_CLAIMCLR_CLR_WIDTH                   (32U)
#define ATP_CLAIMCLR_CLR(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_CLAIMCLR_CLR_SHIFT)) & ATP_CLAIMCLR_CLR_MASK)
/*! @} */

/*! @name DEVAFF0 - Device Affinity 0 */
/*! @{ */

#define ATP_DEVAFF0_DEVAFF0_MASK                 (0xFFFFFFFFU)
#define ATP_DEVAFF0_DEVAFF0_SHIFT                (0U)
#define ATP_DEVAFF0_DEVAFF0_WIDTH                (32U)
#define ATP_DEVAFF0_DEVAFF0(x)                   (((uint32_t)(((uint32_t)(x)) << ATP_DEVAFF0_DEVAFF0_SHIFT)) & ATP_DEVAFF0_DEVAFF0_MASK)
/*! @} */

/*! @name DEVAFF1 - Device Affinity 1 */
/*! @{ */

#define ATP_DEVAFF1_DEVAFF1_MASK                 (0xFFFFFFFFU)
#define ATP_DEVAFF1_DEVAFF1_SHIFT                (0U)
#define ATP_DEVAFF1_DEVAFF1_WIDTH                (32U)
#define ATP_DEVAFF1_DEVAFF1(x)                   (((uint32_t)(((uint32_t)(x)) << ATP_DEVAFF1_DEVAFF1_SHIFT)) & ATP_DEVAFF1_DEVAFF1_MASK)
/*! @} */

/*! @name LAR - Lock Access Register */
/*! @{ */

#define ATP_LAR_KEY_MASK                         (0xFFFFFFFFU)
#define ATP_LAR_KEY_SHIFT                        (0U)
#define ATP_LAR_KEY_WIDTH                        (32U)
#define ATP_LAR_KEY(x)                           (((uint32_t)(((uint32_t)(x)) << ATP_LAR_KEY_SHIFT)) & ATP_LAR_KEY_MASK)
/*! @} */

/*! @name LSR - Lock Status Register */
/*! @{ */

#define ATP_LSR_SLI_MASK                         (0x1U)
#define ATP_LSR_SLI_SHIFT                        (0U)
#define ATP_LSR_SLI_WIDTH                        (1U)
#define ATP_LSR_SLI(x)                           (((uint32_t)(((uint32_t)(x)) << ATP_LSR_SLI_SHIFT)) & ATP_LSR_SLI_MASK)

#define ATP_LSR_SLK_MASK                         (0x2U)
#define ATP_LSR_SLK_SHIFT                        (1U)
#define ATP_LSR_SLK_WIDTH                        (1U)
#define ATP_LSR_SLK(x)                           (((uint32_t)(((uint32_t)(x)) << ATP_LSR_SLK_SHIFT)) & ATP_LSR_SLK_MASK)

#define ATP_LSR_nTT_MASK                         (0x4U)
#define ATP_LSR_nTT_SHIFT                        (2U)
#define ATP_LSR_nTT_WIDTH                        (1U)
#define ATP_LSR_nTT(x)                           (((uint32_t)(((uint32_t)(x)) << ATP_LSR_nTT_SHIFT)) & ATP_LSR_nTT_MASK)
/*! @} */

/*! @name AUTHSTATUS - Authentication Status */
/*! @{ */

#define ATP_AUTHSTATUS_AUTHSTATUS_MASK           (0xFFU)
#define ATP_AUTHSTATUS_AUTHSTATUS_SHIFT          (0U)
#define ATP_AUTHSTATUS_AUTHSTATUS_WIDTH          (8U)
#define ATP_AUTHSTATUS_AUTHSTATUS(x)             (((uint32_t)(((uint32_t)(x)) << ATP_AUTHSTATUS_AUTHSTATUS_SHIFT)) & ATP_AUTHSTATUS_AUTHSTATUS_MASK)
/*! @} */

/*! @name DEVARCH - Device Architecture */
/*! @{ */

#define ATP_DEVARCH_ARCHID_MASK                  (0xFFFFU)
#define ATP_DEVARCH_ARCHID_SHIFT                 (0U)
#define ATP_DEVARCH_ARCHID_WIDTH                 (16U)
#define ATP_DEVARCH_ARCHID(x)                    (((uint32_t)(((uint32_t)(x)) << ATP_DEVARCH_ARCHID_SHIFT)) & ATP_DEVARCH_ARCHID_MASK)

#define ATP_DEVARCH_REVISION_MASK                (0xF0000U)
#define ATP_DEVARCH_REVISION_SHIFT               (16U)
#define ATP_DEVARCH_REVISION_WIDTH               (4U)
#define ATP_DEVARCH_REVISION(x)                  (((uint32_t)(((uint32_t)(x)) << ATP_DEVARCH_REVISION_SHIFT)) & ATP_DEVARCH_REVISION_MASK)

#define ATP_DEVARCH_PRESENT_MASK                 (0x100000U)
#define ATP_DEVARCH_PRESENT_SHIFT                (20U)
#define ATP_DEVARCH_PRESENT_WIDTH                (1U)
#define ATP_DEVARCH_PRESENT(x)                   (((uint32_t)(((uint32_t)(x)) << ATP_DEVARCH_PRESENT_SHIFT)) & ATP_DEVARCH_PRESENT_MASK)

#define ATP_DEVARCH_ARCHITECT_MASK               (0xFFE00000U)
#define ATP_DEVARCH_ARCHITECT_SHIFT              (21U)
#define ATP_DEVARCH_ARCHITECT_WIDTH              (11U)
#define ATP_DEVARCH_ARCHITECT(x)                 (((uint32_t)(((uint32_t)(x)) << ATP_DEVARCH_ARCHITECT_SHIFT)) & ATP_DEVARCH_ARCHITECT_MASK)
/*! @} */

/*! @name DEVID2 - Device Configuration 2 */
/*! @{ */

#define ATP_DEVID2_DEVID2_MASK                   (0xFFFFFFFFU)
#define ATP_DEVID2_DEVID2_SHIFT                  (0U)
#define ATP_DEVID2_DEVID2_WIDTH                  (32U)
#define ATP_DEVID2_DEVID2(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_DEVID2_DEVID2_SHIFT)) & ATP_DEVID2_DEVID2_MASK)
/*! @} */

/*! @name DEVID1 - Device Configuration 1 */
/*! @{ */

#define ATP_DEVID1_DEVID1_MASK                   (0xFFFFFFFFU)
#define ATP_DEVID1_DEVID1_SHIFT                  (0U)
#define ATP_DEVID1_DEVID1_WIDTH                  (32U)
#define ATP_DEVID1_DEVID1(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_DEVID1_DEVID1_SHIFT)) & ATP_DEVID1_DEVID1_MASK)
/*! @} */

/*! @name DEVID - Device Configuration */
/*! @{ */

#define ATP_DEVID_DEVID_MASK                     (0xFFFFFFFFU)
#define ATP_DEVID_DEVID_SHIFT                    (0U)
#define ATP_DEVID_DEVID_WIDTH                    (32U)
#define ATP_DEVID_DEVID(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_DEVID_DEVID_SHIFT)) & ATP_DEVID_DEVID_MASK)
/*! @} */

/*! @name DEVTYPE - Device Type Identifier */
/*! @{ */

#define ATP_DEVTYPE_MAJOR_MASK                   (0xFU)
#define ATP_DEVTYPE_MAJOR_SHIFT                  (0U)
#define ATP_DEVTYPE_MAJOR_WIDTH                  (4U)
#define ATP_DEVTYPE_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_DEVTYPE_MAJOR_SHIFT)) & ATP_DEVTYPE_MAJOR_MASK)

#define ATP_DEVTYPE_SUB_MASK                     (0xF0U)
#define ATP_DEVTYPE_SUB_SHIFT                    (4U)
#define ATP_DEVTYPE_SUB_WIDTH                    (4U)
#define ATP_DEVTYPE_SUB(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_DEVTYPE_SUB_SHIFT)) & ATP_DEVTYPE_SUB_MASK)
/*! @} */

/*! @name PIDR4 - Peripheral Identification Register 4 */
/*! @{ */

#define ATP_PIDR4_DES_2_MASK                     (0xFU)
#define ATP_PIDR4_DES_2_SHIFT                    (0U)
#define ATP_PIDR4_DES_2_WIDTH                    (4U)
#define ATP_PIDR4_DES_2(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_PIDR4_DES_2_SHIFT)) & ATP_PIDR4_DES_2_MASK)

#define ATP_PIDR4_SIZE_MASK                      (0xF0U)
#define ATP_PIDR4_SIZE_SHIFT                     (4U)
#define ATP_PIDR4_SIZE_WIDTH                     (4U)
#define ATP_PIDR4_SIZE(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_PIDR4_SIZE_SHIFT)) & ATP_PIDR4_SIZE_MASK)
/*! @} */

/*! @name PIDR0 - Peripheral Identification Register 0 */
/*! @{ */

#define ATP_PIDR0_PART_0_MASK                    (0xFFU)
#define ATP_PIDR0_PART_0_SHIFT                   (0U)
#define ATP_PIDR0_PART_0_WIDTH                   (8U)
#define ATP_PIDR0_PART_0(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_PIDR0_PART_0_SHIFT)) & ATP_PIDR0_PART_0_MASK)
/*! @} */

/*! @name PIDR1 - Peripheral Identification Register 1 */
/*! @{ */

#define ATP_PIDR1_PART_1_MASK                    (0xFU)
#define ATP_PIDR1_PART_1_SHIFT                   (0U)
#define ATP_PIDR1_PART_1_WIDTH                   (4U)
#define ATP_PIDR1_PART_1(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_PIDR1_PART_1_SHIFT)) & ATP_PIDR1_PART_1_MASK)

#define ATP_PIDR1_DES_0_MASK                     (0xF0U)
#define ATP_PIDR1_DES_0_SHIFT                    (4U)
#define ATP_PIDR1_DES_0_WIDTH                    (4U)
#define ATP_PIDR1_DES_0(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_PIDR1_DES_0_SHIFT)) & ATP_PIDR1_DES_0_MASK)
/*! @} */

/*! @name PIDR2 - Peripheral Identification Register 2 */
/*! @{ */

#define ATP_PIDR2_DES_1_MASK                     (0x7U)
#define ATP_PIDR2_DES_1_SHIFT                    (0U)
#define ATP_PIDR2_DES_1_WIDTH                    (3U)
#define ATP_PIDR2_DES_1(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_PIDR2_DES_1_SHIFT)) & ATP_PIDR2_DES_1_MASK)

#define ATP_PIDR2_JEDEC_MASK                     (0x8U)
#define ATP_PIDR2_JEDEC_SHIFT                    (3U)
#define ATP_PIDR2_JEDEC_WIDTH                    (1U)
#define ATP_PIDR2_JEDEC(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_PIDR2_JEDEC_SHIFT)) & ATP_PIDR2_JEDEC_MASK)

#define ATP_PIDR2_REVISION_MASK                  (0xF0U)
#define ATP_PIDR2_REVISION_SHIFT                 (4U)
#define ATP_PIDR2_REVISION_WIDTH                 (4U)
#define ATP_PIDR2_REVISION(x)                    (((uint32_t)(((uint32_t)(x)) << ATP_PIDR2_REVISION_SHIFT)) & ATP_PIDR2_REVISION_MASK)
/*! @} */

/*! @name PIDR3 - Peripheral Identification Register 3 */
/*! @{ */

#define ATP_PIDR3_REVAND_MASK                    (0xFU)
#define ATP_PIDR3_REVAND_SHIFT                   (0U)
#define ATP_PIDR3_REVAND_WIDTH                   (4U)
#define ATP_PIDR3_REVAND(x)                      (((uint32_t)(((uint32_t)(x)) << ATP_PIDR3_REVAND_SHIFT)) & ATP_PIDR3_REVAND_MASK)

#define ATP_PIDR3_CMOD_MASK                      (0xF0U)
#define ATP_PIDR3_CMOD_SHIFT                     (4U)
#define ATP_PIDR3_CMOD_WIDTH                     (4U)
#define ATP_PIDR3_CMOD(x)                        (((uint32_t)(((uint32_t)(x)) << ATP_PIDR3_CMOD_SHIFT)) & ATP_PIDR3_CMOD_MASK)
/*! @} */

/*! @name CIDR0 - Component Identification Register 0 */
/*! @{ */

#define ATP_CIDR0_PRMBL_0_MASK                   (0xFFU)
#define ATP_CIDR0_PRMBL_0_SHIFT                  (0U)
#define ATP_CIDR0_PRMBL_0_WIDTH                  (8U)
#define ATP_CIDR0_PRMBL_0(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_CIDR0_PRMBL_0_SHIFT)) & ATP_CIDR0_PRMBL_0_MASK)
/*! @} */

/*! @name CIDR1 - Component Identification Register 1 */
/*! @{ */

#define ATP_CIDR1_PRMBL_1_MASK                   (0xFU)
#define ATP_CIDR1_PRMBL_1_SHIFT                  (0U)
#define ATP_CIDR1_PRMBL_1_WIDTH                  (4U)
#define ATP_CIDR1_PRMBL_1(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_CIDR1_PRMBL_1_SHIFT)) & ATP_CIDR1_PRMBL_1_MASK)

#define ATP_CIDR1_CLASS_MASK                     (0xF0U)
#define ATP_CIDR1_CLASS_SHIFT                    (4U)
#define ATP_CIDR1_CLASS_WIDTH                    (4U)
#define ATP_CIDR1_CLASS(x)                       (((uint32_t)(((uint32_t)(x)) << ATP_CIDR1_CLASS_SHIFT)) & ATP_CIDR1_CLASS_MASK)
/*! @} */

/*! @name CIDR2 - Component Identification Register 2 */
/*! @{ */

#define ATP_CIDR2_PRMBL_2_MASK                   (0xFFU)
#define ATP_CIDR2_PRMBL_2_SHIFT                  (0U)
#define ATP_CIDR2_PRMBL_2_WIDTH                  (8U)
#define ATP_CIDR2_PRMBL_2(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_CIDR2_PRMBL_2_SHIFT)) & ATP_CIDR2_PRMBL_2_MASK)
/*! @} */

/*! @name CIDR3 - Component Identification Register 3 */
/*! @{ */

#define ATP_CIDR3_PRMBL_3_MASK                   (0xFFU)
#define ATP_CIDR3_PRMBL_3_SHIFT                  (0U)
#define ATP_CIDR3_PRMBL_3_WIDTH                  (8U)
#define ATP_CIDR3_PRMBL_3(x)                     (((uint32_t)(((uint32_t)(x)) << ATP_CIDR3_PRMBL_3_SHIFT)) & ATP_CIDR3_PRMBL_3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ATP_Register_Masks */

/*!
 * @}
 */ /* end of group ATP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ATP_H_) */
