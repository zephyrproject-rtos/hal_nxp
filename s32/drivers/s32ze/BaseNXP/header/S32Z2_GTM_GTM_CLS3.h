/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_GTM_gtm_cls3.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_GTM_gtm_cls3
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
#if !defined(S32Z2_GTM_gtm_cls3_H_)  /* Check if memory map has not been already included */
#define S32Z2_GTM_gtm_cls3_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GTM_gtm_cls3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GTM_gtm_cls3_Peripheral_Access_Layer GTM_gtm_cls3 Peripheral Access Layer
 * @{
 */

/** GTM_gtm_cls3 - Size of Registers Arrays */
#define GTM_gtm_cls3_CDTM3_DTM4_CH4_DTV_COUNT     4u
#define GTM_gtm_cls3_CDTM3_DTM5_CH4_DTV_COUNT     4u
#define GTM_gtm_cls3_MCS3_MEM_COUNT               3072u

/** GTM_gtm_cls3 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[6144];
  __IO uint32_t ATOM3_CH0_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1800 */
  __IO uint32_t ATOM3_CH0_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1804 */
  __IO uint32_t ATOM3_CH0_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1808 */
  __IO uint32_t ATOM3_CH0_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x180C */
  __IO uint32_t ATOM3_CH0_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1810 */
  __IO uint32_t ATOM3_CH0_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1814 */
  __IO uint32_t ATOM3_CH0_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1818 */
  __IO uint32_t ATOM3_CH0_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x181C */
  __IO uint32_t ATOM3_CH0_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x1820 */
  __IO uint32_t ATOM3_CH0_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x1824 */
  __IO uint32_t ATOM3_CH0_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x1828 */
  __IO uint32_t ATOM3_CH0_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x182C */
  uint8_t RESERVED_1[4];
  __IO uint32_t ATOM3_CH0_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x1834 */
  uint8_t RESERVED_2[72];
  __IO uint32_t ATOM3_CH1_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1880 */
  __IO uint32_t ATOM3_CH1_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1884 */
  __IO uint32_t ATOM3_CH1_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1888 */
  __IO uint32_t ATOM3_CH1_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x188C */
  __IO uint32_t ATOM3_CH1_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1890 */
  __IO uint32_t ATOM3_CH1_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1894 */
  __IO uint32_t ATOM3_CH1_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1898 */
  __IO uint32_t ATOM3_CH1_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x189C */
  __IO uint32_t ATOM3_CH1_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x18A0 */
  __IO uint32_t ATOM3_CH1_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x18A4 */
  __IO uint32_t ATOM3_CH1_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x18A8 */
  __IO uint32_t ATOM3_CH1_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x18AC */
  uint8_t RESERVED_3[4];
  __IO uint32_t ATOM3_CH1_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x18B4 */
  uint8_t RESERVED_4[72];
  __IO uint32_t ATOM3_CH2_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1900 */
  __IO uint32_t ATOM3_CH2_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1904 */
  __IO uint32_t ATOM3_CH2_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1908 */
  __IO uint32_t ATOM3_CH2_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x190C */
  __IO uint32_t ATOM3_CH2_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1910 */
  __IO uint32_t ATOM3_CH2_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1914 */
  __IO uint32_t ATOM3_CH2_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1918 */
  __IO uint32_t ATOM3_CH2_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x191C */
  __IO uint32_t ATOM3_CH2_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x1920 */
  __IO uint32_t ATOM3_CH2_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x1924 */
  __IO uint32_t ATOM3_CH2_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x1928 */
  __IO uint32_t ATOM3_CH2_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x192C */
  uint8_t RESERVED_5[4];
  __IO uint32_t ATOM3_CH2_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x1934 */
  uint8_t RESERVED_6[72];
  __IO uint32_t ATOM3_CH3_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1980 */
  __IO uint32_t ATOM3_CH3_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1984 */
  __IO uint32_t ATOM3_CH3_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1988 */
  __IO uint32_t ATOM3_CH3_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x198C */
  __IO uint32_t ATOM3_CH3_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1990 */
  __IO uint32_t ATOM3_CH3_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1994 */
  __IO uint32_t ATOM3_CH3_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1998 */
  __IO uint32_t ATOM3_CH3_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x199C */
  __IO uint32_t ATOM3_CH3_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x19A0 */
  __IO uint32_t ATOM3_CH3_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x19A4 */
  __IO uint32_t ATOM3_CH3_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x19A8 */
  __IO uint32_t ATOM3_CH3_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x19AC */
  uint8_t RESERVED_7[4];
  __IO uint32_t ATOM3_CH3_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x19B4 */
  uint8_t RESERVED_8[72];
  __IO uint32_t ATOM3_CH4_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1A00 */
  __IO uint32_t ATOM3_CH4_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1A04 */
  __IO uint32_t ATOM3_CH4_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1A08 */
  __IO uint32_t ATOM3_CH4_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1A0C */
  __IO uint32_t ATOM3_CH4_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1A10 */
  __IO uint32_t ATOM3_CH4_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1A14 */
  __IO uint32_t ATOM3_CH4_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1A18 */
  __IO uint32_t ATOM3_CH4_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x1A1C */
  __IO uint32_t ATOM3_CH4_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x1A20 */
  __IO uint32_t ATOM3_CH4_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x1A24 */
  __IO uint32_t ATOM3_CH4_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x1A28 */
  __IO uint32_t ATOM3_CH4_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x1A2C */
  uint8_t RESERVED_9[4];
  __IO uint32_t ATOM3_CH4_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x1A34 */
  uint8_t RESERVED_10[72];
  __IO uint32_t ATOM3_CH5_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1A80 */
  __IO uint32_t ATOM3_CH5_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1A84 */
  __IO uint32_t ATOM3_CH5_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1A88 */
  __IO uint32_t ATOM3_CH5_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1A8C */
  __IO uint32_t ATOM3_CH5_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1A90 */
  __IO uint32_t ATOM3_CH5_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1A94 */
  __IO uint32_t ATOM3_CH5_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1A98 */
  __IO uint32_t ATOM3_CH5_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x1A9C */
  __IO uint32_t ATOM3_CH5_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x1AA0 */
  __IO uint32_t ATOM3_CH5_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x1AA4 */
  __IO uint32_t ATOM3_CH5_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x1AA8 */
  __IO uint32_t ATOM3_CH5_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x1AAC */
  uint8_t RESERVED_11[4];
  __IO uint32_t ATOM3_CH5_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x1AB4 */
  uint8_t RESERVED_12[72];
  __IO uint32_t ATOM3_CH6_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1B00 */
  __IO uint32_t ATOM3_CH6_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1B04 */
  __IO uint32_t ATOM3_CH6_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1B08 */
  __IO uint32_t ATOM3_CH6_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1B0C */
  __IO uint32_t ATOM3_CH6_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1B10 */
  __IO uint32_t ATOM3_CH6_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1B14 */
  __IO uint32_t ATOM3_CH6_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1B18 */
  __IO uint32_t ATOM3_CH6_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x1B1C */
  __IO uint32_t ATOM3_CH6_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x1B20 */
  __IO uint32_t ATOM3_CH6_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x1B24 */
  __IO uint32_t ATOM3_CH6_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x1B28 */
  __IO uint32_t ATOM3_CH6_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x1B2C */
  uint8_t RESERVED_13[4];
  __IO uint32_t ATOM3_CH6_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x1B34 */
  uint8_t RESERVED_14[72];
  __IO uint32_t ATOM3_CH7_RDADDR;                  /**< ATOM[i] channel[x] ARU read address register, offset: 0x1B80 */
  __IO uint32_t ATOM3_CH7_CTRL;                    /**< ATOM[i] channel [x] control register, offset: 0x1B84 */
  __IO uint32_t ATOM3_CH7_SR0;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1B88 */
  __IO uint32_t ATOM3_CH7_SR1;                     /**< ATOM[i] channel [x] CCU0 compare shadow register, offset: 0x1B8C */
  __IO uint32_t ATOM3_CH7_CM0;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1B90 */
  __IO uint32_t ATOM3_CH7_CM1;                     /**< ATOM[i] channel [x] CCU0 compare register, offset: 0x1B94 */
  __IO uint32_t ATOM3_CH7_CN0;                     /**< ATOM[i] channel [x] CCU0 counter register, offset: 0x1B98 */
  __IO uint32_t ATOM3_CH7_STAT;                    /**< ATOM[i] channel [x] status register, offset: 0x1B9C */
  __IO uint32_t ATOM3_CH7_IRQ_NOTIFY;              /**< ATOM[i] channel [x] interrupt notification register, offset: 0x1BA0 */
  __IO uint32_t ATOM3_CH7_IRQ_EN;                  /**< ATOM[i] channel [x] interrupt enable register, offset: 0x1BA4 */
  __IO uint32_t ATOM3_CH7_IRQ_FORCINT;             /**< ATOM[i] channel [x] software interrupt generation, offset: 0x1BA8 */
  __IO uint32_t ATOM3_CH7_IRQ_MODE;                /**< ATOM[i] channel [x] interrupt mode configuration register, offset: 0x1BAC */
  uint8_t RESERVED_15[4];
  __IO uint32_t ATOM3_CH7_CTRL_SR;                 /**< ATOM[i] channel [x] control shadow register, offset: 0x1BB4 */
  uint8_t RESERVED_16[136];
  __IO uint32_t ATOM3_AGC_GLB_CTRL;                /**< ATOM[i] AGC global control register, offset: 0x1C40 */
  __IO uint32_t ATOM3_AGC_ENDIS_CTRL;              /**< ATOM[i] AGC enable/disable control register, offset: 0x1C44 */
  __IO uint32_t ATOM3_AGC_ENDIS_STAT;              /**< ATOM[i] AGC enable/disable status register, offset: 0x1C48 */
  __IO uint32_t ATOM3_AGC_ACT_TB;                  /**< ATOM[i] AGC action time base register, offset: 0x1C4C */
  __IO uint32_t ATOM3_AGC_OUTEN_CTRL;              /**< ATOM[i] AGC output enable control register, offset: 0x1C50 */
  __IO uint32_t ATOM3_AGC_OUTEN_STAT;              /**< ATOM[i] AGC output enable status register, offset: 0x1C54 */
  __IO uint32_t ATOM3_AGC_FUPD_CTRL;               /**< ATOM[i] AGC force update control register, offset: 0x1C58 */
  __IO uint32_t ATOM3_AGC_INT_TRIG;                /**< ATOM[i] AGC internal trigger control register, offset: 0x1C5C */
  uint8_t RESERVED_17[928];
  __IO uint32_t MCS3_CH0_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2000 */
  __IO uint32_t MCS3_CH0_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2004 */
  __IO uint32_t MCS3_CH0_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2008 */
  __IO uint32_t MCS3_CH0_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x200C */
  __IO uint32_t MCS3_CH0_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2010 */
  __IO uint32_t MCS3_CH0_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2014 */
  __IO uint32_t MCS3_CH0_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2018 */
  __IO uint32_t MCS3_CH0_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x201C */
  __IO uint32_t MCS3_CH0_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2020 */
  __I  uint32_t MCS3_CH0_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2024 */
  uint8_t RESERVED_18[20];
  __I  uint32_t MCS3_CH0_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x203C */
  uint8_t RESERVED_19[160];
  __IO uint32_t MCS3_CH0_PC;                       /**< MCS[i] channel x program counter register, offset: 0x20E0 */
  __IO uint32_t MCS3_CH0_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x20E4 */
  __IO uint32_t MCS3_CH0_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x20E8 */
  __IO uint32_t MCS3_CH0_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x20EC */
  __IO uint32_t MCS3_CH0_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x20F0 */
  __IO uint32_t MCS3_CH0_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x20F4 */
  uint8_t RESERVED_20[8];
  __IO uint32_t MCS3_CH1_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2100 */
  __IO uint32_t MCS3_CH1_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2104 */
  __IO uint32_t MCS3_CH1_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2108 */
  __IO uint32_t MCS3_CH1_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x210C */
  __IO uint32_t MCS3_CH1_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2110 */
  __IO uint32_t MCS3_CH1_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2114 */
  __IO uint32_t MCS3_CH1_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2118 */
  __IO uint32_t MCS3_CH1_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x211C */
  __IO uint32_t MCS3_CH1_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2120 */
  __I  uint32_t MCS3_CH1_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2124 */
  uint8_t RESERVED_21[20];
  __I  uint32_t MCS3_CH1_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x213C */
  uint8_t RESERVED_22[160];
  __IO uint32_t MCS3_CH1_PC;                       /**< MCS[i] channel x program counter register, offset: 0x21E0 */
  __IO uint32_t MCS3_CH1_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x21E4 */
  __IO uint32_t MCS3_CH1_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x21E8 */
  __IO uint32_t MCS3_CH1_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x21EC */
  __IO uint32_t MCS3_CH1_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x21F0 */
  __IO uint32_t MCS3_CH1_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x21F4 */
  uint8_t RESERVED_23[8];
  __IO uint32_t MCS3_CH2_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2200 */
  __IO uint32_t MCS3_CH2_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2204 */
  __IO uint32_t MCS3_CH2_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2208 */
  __IO uint32_t MCS3_CH2_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x220C */
  __IO uint32_t MCS3_CH2_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2210 */
  __IO uint32_t MCS3_CH2_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2214 */
  __IO uint32_t MCS3_CH2_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2218 */
  __IO uint32_t MCS3_CH2_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x221C */
  __IO uint32_t MCS3_CH2_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2220 */
  __I  uint32_t MCS3_CH2_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2224 */
  uint8_t RESERVED_24[20];
  __I  uint32_t MCS3_CH2_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x223C */
  uint8_t RESERVED_25[160];
  __IO uint32_t MCS3_CH2_PC;                       /**< MCS[i] channel x program counter register, offset: 0x22E0 */
  __IO uint32_t MCS3_CH2_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x22E4 */
  __IO uint32_t MCS3_CH2_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x22E8 */
  __IO uint32_t MCS3_CH2_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x22EC */
  __IO uint32_t MCS3_CH2_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x22F0 */
  __IO uint32_t MCS3_CH2_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x22F4 */
  uint8_t RESERVED_26[8];
  __IO uint32_t MCS3_CH3_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2300 */
  __IO uint32_t MCS3_CH3_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2304 */
  __IO uint32_t MCS3_CH3_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2308 */
  __IO uint32_t MCS3_CH3_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x230C */
  __IO uint32_t MCS3_CH3_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2310 */
  __IO uint32_t MCS3_CH3_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2314 */
  __IO uint32_t MCS3_CH3_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2318 */
  __IO uint32_t MCS3_CH3_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x231C */
  __IO uint32_t MCS3_CH3_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2320 */
  __I  uint32_t MCS3_CH3_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2324 */
  uint8_t RESERVED_27[20];
  __I  uint32_t MCS3_CH3_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x233C */
  uint8_t RESERVED_28[160];
  __IO uint32_t MCS3_CH3_PC;                       /**< MCS[i] channel x program counter register, offset: 0x23E0 */
  __IO uint32_t MCS3_CH3_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x23E4 */
  __IO uint32_t MCS3_CH3_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x23E8 */
  __IO uint32_t MCS3_CH3_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x23EC */
  __IO uint32_t MCS3_CH3_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x23F0 */
  __IO uint32_t MCS3_CH3_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x23F4 */
  uint8_t RESERVED_29[8];
  __IO uint32_t MCS3_CH4_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2400 */
  __IO uint32_t MCS3_CH4_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2404 */
  __IO uint32_t MCS3_CH4_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2408 */
  __IO uint32_t MCS3_CH4_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x240C */
  __IO uint32_t MCS3_CH4_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2410 */
  __IO uint32_t MCS3_CH4_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2414 */
  __IO uint32_t MCS3_CH4_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2418 */
  __IO uint32_t MCS3_CH4_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x241C */
  __IO uint32_t MCS3_CH4_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2420 */
  __I  uint32_t MCS3_CH4_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2424 */
  uint8_t RESERVED_30[20];
  __I  uint32_t MCS3_CH4_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x243C */
  uint8_t RESERVED_31[160];
  __IO uint32_t MCS3_CH4_PC;                       /**< MCS[i] channel x program counter register, offset: 0x24E0 */
  __IO uint32_t MCS3_CH4_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x24E4 */
  __IO uint32_t MCS3_CH4_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x24E8 */
  __IO uint32_t MCS3_CH4_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x24EC */
  __IO uint32_t MCS3_CH4_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x24F0 */
  __IO uint32_t MCS3_CH4_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x24F4 */
  uint8_t RESERVED_32[8];
  __IO uint32_t MCS3_CH5_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2500 */
  __IO uint32_t MCS3_CH5_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2504 */
  __IO uint32_t MCS3_CH5_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2508 */
  __IO uint32_t MCS3_CH5_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x250C */
  __IO uint32_t MCS3_CH5_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2510 */
  __IO uint32_t MCS3_CH5_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2514 */
  __IO uint32_t MCS3_CH5_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2518 */
  __IO uint32_t MCS3_CH5_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x251C */
  __IO uint32_t MCS3_CH5_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2520 */
  __I  uint32_t MCS3_CH5_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2524 */
  uint8_t RESERVED_33[20];
  __I  uint32_t MCS3_CH5_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x253C */
  uint8_t RESERVED_34[160];
  __IO uint32_t MCS3_CH5_PC;                       /**< MCS[i] channel x program counter register, offset: 0x25E0 */
  __IO uint32_t MCS3_CH5_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x25E4 */
  __IO uint32_t MCS3_CH5_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x25E8 */
  __IO uint32_t MCS3_CH5_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x25EC */
  __IO uint32_t MCS3_CH5_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x25F0 */
  __IO uint32_t MCS3_CH5_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x25F4 */
  uint8_t RESERVED_35[8];
  __IO uint32_t MCS3_CH6_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2600 */
  __IO uint32_t MCS3_CH6_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2604 */
  __IO uint32_t MCS3_CH6_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2608 */
  __IO uint32_t MCS3_CH6_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x260C */
  __IO uint32_t MCS3_CH6_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2610 */
  __IO uint32_t MCS3_CH6_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2614 */
  __IO uint32_t MCS3_CH6_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2618 */
  __IO uint32_t MCS3_CH6_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x261C */
  __IO uint32_t MCS3_CH6_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2620 */
  __I  uint32_t MCS3_CH6_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2624 */
  uint8_t RESERVED_36[20];
  __I  uint32_t MCS3_CH6_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x263C */
  uint8_t RESERVED_37[160];
  __IO uint32_t MCS3_CH6_PC;                       /**< MCS[i] channel x program counter register, offset: 0x26E0 */
  __IO uint32_t MCS3_CH6_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x26E4 */
  __IO uint32_t MCS3_CH6_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x26E8 */
  __IO uint32_t MCS3_CH6_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x26EC */
  __IO uint32_t MCS3_CH6_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x26F0 */
  __IO uint32_t MCS3_CH6_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x26F4 */
  uint8_t RESERVED_38[8];
  __IO uint32_t MCS3_CH7_R0;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2700 */
  __IO uint32_t MCS3_CH7_R1;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2704 */
  __IO uint32_t MCS3_CH7_R2;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2708 */
  __IO uint32_t MCS3_CH7_R3;                       /**< MCS[i] channel x general purpose register [y], offset: 0x270C */
  __IO uint32_t MCS3_CH7_R4;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2710 */
  __IO uint32_t MCS3_CH7_R5;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2714 */
  __IO uint32_t MCS3_CH7_R6;                       /**< MCS[i] channel x general purpose register [y], offset: 0x2718 */
  __IO uint32_t MCS3_CH7_R7;                       /**< MCS[i] channel x general purpose register [y], offset: 0x271C */
  __IO uint32_t MCS3_CH7_CTRL;                     /**< MCS[i] channel x control register, offset: 0x2720 */
  __I  uint32_t MCS3_CH7_ACB;                      /**< MCS[i] channel x ARU control Bit register, offset: 0x2724 */
  uint8_t RESERVED_39[20];
  __I  uint32_t MCS3_CH7_MHB;                      /**< MCS[i] channel x memory high byte register, offset: 0x273C */
  uint8_t RESERVED_40[160];
  __IO uint32_t MCS3_CH7_PC;                       /**< MCS[i] channel x program counter register, offset: 0x27E0 */
  __IO uint32_t MCS3_CH7_IRQ_NOTIFY;               /**< MCS[i] channel x interrupt notification register, offset: 0x27E4 */
  __IO uint32_t MCS3_CH7_IRQ_EN;                   /**< MCS[i] channel x interrupt enable register, offset: 0x27E8 */
  __IO uint32_t MCS3_CH7_IRQ_FORCINT;              /**< MCS[i] channel x force interrupt register, offset: 0x27EC */
  __IO uint32_t MCS3_CH7_IRQ_MODE;                 /**< MCS[i] channel x IRQ mode configuration register, offset: 0x27F0 */
  __IO uint32_t MCS3_CH7_EIRQ_EN;                  /**< MCS[i] channel x error interrupt enable register, offset: 0x27F4 */
  uint8_t RESERVED_41[1584];
  __IO uint32_t MCS3_CTRG;                         /**< MCS[i] clear trigger control register, offset: 0x2E28 */
  __IO uint32_t MCS3_STRG;                         /**< MCS[i] set trigger control register, offset: 0x2E2C */
  uint8_t RESERVED_42[208];
  __IO uint32_t MCS3_CTRL_STAT;                    /**< MCS[i] control and status register, offset: 0x2F00 */
  __IO uint32_t MCS3_RESET;                        /**< MCS[i] reset register, offset: 0x2F04 */
  __IO uint32_t MCS3_CAT;                          /**< MCS[i] cancel ARU transfer instruction, offset: 0x2F08 */
  __IO uint32_t MCS3_CWT;                          /**< MCS[i] cancel waiting instruction, offset: 0x2F0C */
  __IO uint32_t MCS3_ERR;                          /**< MCS[i] error register, offset: 0x2F10 */
  uint8_t RESERVED_43[8];
  __IO uint32_t MCS3_REG_PROT;                     /**< MCS[i] write protection register, offset: 0x2F1C */
  __IO uint32_t MCS3_SINT_IRQ_NOTIFY;              /**< MCS[i] shared interrupt notification register, offset: 0x2F20 */
  __IO uint32_t MCS3_SINT_IRQ_EN;                  /**< MCS[i] shared interrupt enable register, offset: 0x2F24 */
  __IO uint32_t MCS3_SINT_IRQ_FORCINT;             /**< MCS[i] force shared interrupt register, offset: 0x2F28 */
  __IO uint32_t MCS3_SINT_IRQ_MODE;                /**< MCS[i] shared interrupt mode configuration register, offset: 0x2F2C */
  uint8_t RESERVED_44[16];
  __IO uint32_t MCS3_HBP0_CTRL;                    /**< MCS[i] hardware break point h control register, offset: 0x2F40 */
  __IO uint32_t MCS3_HBP0_PATTERN;                 /**< MCS[i] hardware break point pattern register, offset: 0x2F44 */
  __IO uint32_t MCS3_HBP0_STATUS;                  /**< MCS[i] hardware break point status register, offset: 0x2F48 */
  __IO uint32_t MCS3_HBP0_IRQ_NOTIFY;              /**< MCS[i] hardware break point interrupt notification register, offset: 0x2F4C */
  __IO uint32_t MCS3_HBP0_IRQ_EN;                  /**< MCS[i] hardware break point interrupt enable register, offset: 0x2F50 */
  __IO uint32_t MCS3_HBP0_IRQ_FORCINT;             /**< MCS[i] force hardware break point interrupt register, offset: 0x2F54 */
  __IO uint32_t MCS3_HBP0_IRQ_MODE;                /**< MCS[i] break point h interrupt mode configuration register, offset: 0x2F58 */
  uint8_t RESERVED_45[4];
  __IO uint32_t MCS3_HBP1_CTRL;                    /**< MCS[i] hardware break point h control register, offset: 0x2F60 */
  __IO uint32_t MCS3_HBP1_PATTERN;                 /**< MCS[i] hardware break point pattern register, offset: 0x2F64 */
  __IO uint32_t MCS3_HBP1_STATUS;                  /**< MCS[i] hardware break point status register, offset: 0x2F68 */
  __IO uint32_t MCS3_HBP1_IRQ_NOTIFY;              /**< MCS[i] hardware break point interrupt notification register, offset: 0x2F6C */
  __IO uint32_t MCS3_HBP1_IRQ_EN;                  /**< MCS[i] hardware break point interrupt enable register, offset: 0x2F70 */
  __IO uint32_t MCS3_HBP1_IRQ_FORCINT;             /**< MCS[i] force hardware break point interrupt register, offset: 0x2F74 */
  __IO uint32_t MCS3_HBP1_IRQ_MODE;                /**< MCS[i] break point h interrupt mode configuration register, offset: 0x2F78 */
  uint8_t RESERVED_46[132];
  __IO uint32_t TIO3_G0_CH0_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x3000 */
  __IO uint32_t TIO3_G0_CH0_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x3004 */
  __IO uint32_t TIO3_G0_CH0_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x3008 */
  __IO uint32_t TIO3_G0_CH0_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x300C */
  __IO uint32_t TIO3_G0_CH0_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x3010 */
  __IO uint32_t TIO3_G0_CH0_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x3014 */
  uint8_t RESERVED_47[8];
  __IO uint32_t TIO3_G0_CH0_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3020 */
  __IO uint32_t TIO3_G0_CH0_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3024 */
  __IO uint32_t TIO3_G0_CH0_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x3028 */
  uint8_t RESERVED_48[4];
  __IO uint32_t TIO3_G0_CH0_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x3030 */
  __IO uint32_t TIO3_G0_CH0_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x3034 */
  __IO uint32_t TIO3_G0_CH0_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x3038 */
  __I  uint32_t TIO3_G0_CH0_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x303C */
  __IO uint32_t TIO3_G0_CH1_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x3040 */
  __IO uint32_t TIO3_G0_CH1_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x3044 */
  __IO uint32_t TIO3_G0_CH1_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x3048 */
  __IO uint32_t TIO3_G0_CH1_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x304C */
  __IO uint32_t TIO3_G0_CH1_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x3050 */
  __IO uint32_t TIO3_G0_CH1_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x3054 */
  uint8_t RESERVED_49[8];
  __IO uint32_t TIO3_G0_CH1_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3060 */
  __IO uint32_t TIO3_G0_CH1_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3064 */
  __IO uint32_t TIO3_G0_CH1_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x3068 */
  uint8_t RESERVED_50[4];
  __IO uint32_t TIO3_G0_CH1_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x3070 */
  __IO uint32_t TIO3_G0_CH1_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x3074 */
  __IO uint32_t TIO3_G0_CH1_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x3078 */
  __I  uint32_t TIO3_G0_CH1_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x307C */
  __IO uint32_t TIO3_G0_CH2_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x3080 */
  __IO uint32_t TIO3_G0_CH2_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x3084 */
  __IO uint32_t TIO3_G0_CH2_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x3088 */
  __IO uint32_t TIO3_G0_CH2_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x308C */
  __IO uint32_t TIO3_G0_CH2_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x3090 */
  __IO uint32_t TIO3_G0_CH2_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x3094 */
  uint8_t RESERVED_51[8];
  __IO uint32_t TIO3_G0_CH2_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x30A0 */
  __IO uint32_t TIO3_G0_CH2_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x30A4 */
  __IO uint32_t TIO3_G0_CH2_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x30A8 */
  uint8_t RESERVED_52[4];
  __IO uint32_t TIO3_G0_CH2_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x30B0 */
  __IO uint32_t TIO3_G0_CH2_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x30B4 */
  __IO uint32_t TIO3_G0_CH2_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x30B8 */
  __I  uint32_t TIO3_G0_CH2_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x30BC */
  __IO uint32_t TIO3_G0_CH3_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x30C0 */
  __IO uint32_t TIO3_G0_CH3_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x30C4 */
  __IO uint32_t TIO3_G0_CH3_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x30C8 */
  __IO uint32_t TIO3_G0_CH3_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x30CC */
  __IO uint32_t TIO3_G0_CH3_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x30D0 */
  __IO uint32_t TIO3_G0_CH3_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x30D4 */
  uint8_t RESERVED_53[8];
  __IO uint32_t TIO3_G0_CH3_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x30E0 */
  __IO uint32_t TIO3_G0_CH3_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x30E4 */
  __IO uint32_t TIO3_G0_CH3_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x30E8 */
  uint8_t RESERVED_54[4];
  __IO uint32_t TIO3_G0_CH3_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x30F0 */
  __IO uint32_t TIO3_G0_CH3_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x30F4 */
  __IO uint32_t TIO3_G0_CH3_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x30F8 */
  __I  uint32_t TIO3_G0_CH3_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x30FC */
  __IO uint32_t TIO3_G0_CH4_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x3100 */
  __IO uint32_t TIO3_G0_CH4_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x3104 */
  __IO uint32_t TIO3_G0_CH4_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x3108 */
  __IO uint32_t TIO3_G0_CH4_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x310C */
  __IO uint32_t TIO3_G0_CH4_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x3110 */
  __IO uint32_t TIO3_G0_CH4_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x3114 */
  uint8_t RESERVED_55[8];
  __IO uint32_t TIO3_G0_CH4_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3120 */
  __IO uint32_t TIO3_G0_CH4_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3124 */
  __IO uint32_t TIO3_G0_CH4_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x3128 */
  uint8_t RESERVED_56[4];
  __IO uint32_t TIO3_G0_CH4_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x3130 */
  __IO uint32_t TIO3_G0_CH4_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x3134 */
  __IO uint32_t TIO3_G0_CH4_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x3138 */
  __I  uint32_t TIO3_G0_CH4_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x313C */
  __IO uint32_t TIO3_G0_CH5_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x3140 */
  __IO uint32_t TIO3_G0_CH5_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x3144 */
  __IO uint32_t TIO3_G0_CH5_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x3148 */
  __IO uint32_t TIO3_G0_CH5_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x314C */
  __IO uint32_t TIO3_G0_CH5_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x3150 */
  __IO uint32_t TIO3_G0_CH5_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x3154 */
  uint8_t RESERVED_57[8];
  __IO uint32_t TIO3_G0_CH5_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3160 */
  __IO uint32_t TIO3_G0_CH5_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x3164 */
  __IO uint32_t TIO3_G0_CH5_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x3168 */
  uint8_t RESERVED_58[4];
  __IO uint32_t TIO3_G0_CH5_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x3170 */
  __IO uint32_t TIO3_G0_CH5_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x3174 */
  __IO uint32_t TIO3_G0_CH5_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x3178 */
  __I  uint32_t TIO3_G0_CH5_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x317C */
  __IO uint32_t TIO3_G0_CH6_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x3180 */
  __IO uint32_t TIO3_G0_CH6_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x3184 */
  __IO uint32_t TIO3_G0_CH6_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x3188 */
  __IO uint32_t TIO3_G0_CH6_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x318C */
  __IO uint32_t TIO3_G0_CH6_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x3190 */
  __IO uint32_t TIO3_G0_CH6_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x3194 */
  uint8_t RESERVED_59[8];
  __IO uint32_t TIO3_G0_CH6_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x31A0 */
  __IO uint32_t TIO3_G0_CH6_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x31A4 */
  __IO uint32_t TIO3_G0_CH6_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x31A8 */
  uint8_t RESERVED_60[4];
  __IO uint32_t TIO3_G0_CH6_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x31B0 */
  __IO uint32_t TIO3_G0_CH6_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x31B4 */
  __IO uint32_t TIO3_G0_CH6_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x31B8 */
  __I  uint32_t TIO3_G0_CH6_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x31BC */
  __IO uint32_t TIO3_G0_CH7_CTRL;                  /**< TIO[i] group [g] channel [c] control register, offset: 0x31C0 */
  __IO uint32_t TIO3_G0_CH7_IRQ_NOTIFY;            /**< TIO[i] channel [c] interrupt notification register, offset: 0x31C4 */
  __IO uint32_t TIO3_G0_CH7_IRQ_EN;                /**< TIO[i] channel [c] interrupt enable register, offset: 0x31C8 */
  __IO uint32_t TIO3_G0_CH7_IRQ_FORCINT;           /**< TIO[i] channel [c] force interrupt register, offset: 0x31CC */
  __IO uint32_t TIO3_G0_CH7_IRQ_MODE;              /**< TIO[i] channel [c] IRQ mode configuration register, offset: 0x31D0 */
  __IO uint32_t TIO3_G0_CH7_CTRL2;                 /**< TIO[i] group [g] channel [c] control register, offset: 0x31D4 */
  uint8_t RESERVED_61[8];
  __IO uint32_t TIO3_G0_CH7_SINST;                 /**< TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x31E0 */
  __IO uint32_t TIO3_G0_CH7_SCMD;                  /**< TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0-, offset: 0x31E4 */
  __IO uint32_t TIO3_G0_CH7_SOP;                   /**< TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ), offset: 0x31E8 */
  uint8_t RESERVED_62[4];
  __IO uint32_t TIO3_G0_CH7_OINST;                 /**< TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00-, offset: 0x31F0 */
  __IO uint32_t TIO3_G0_CH7_OCMD;                  /**< TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00-, offset: 0x31F4 */
  __IO uint32_t TIO3_G0_CH7_OOP;                   /**< TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-), offset: 0x31F8 */
  __I  uint32_t TIO3_G0_CH7_SHIFTCNT;              /**< TIO[i] channel [c] resource shift count register, offset: 0x31FC */
  __IO uint32_t TIO3_G0_ISEL0_CTRL1;               /**< TIO[i] input selection register 1, offset: 0x3200 */
  __IO uint32_t TIO3_G0_ISEL0_CTRL2;               /**< TIO[i] input selection register 2, offset: 0x3204 */
  uint8_t RESERVED_63[24];
  __IO uint32_t TIO3_G0_ISEL1_CTRL1;               /**< TIO[i] input selection register 1, offset: 0x3220 */
  __IO uint32_t TIO3_G0_ISEL1_CTRL2;               /**< TIO[i] input selection register 2, offset: 0x3224 */
  uint8_t RESERVED_64[24];
  __IO uint32_t TIO3_G0_OP_USAGE;                  /**< TIO[i] operand usage selection register, offset: 0x3240 */
  uint8_t RESERVED_65[2492];
  __IO uint32_t TIO3_S;                            /**< TIO[i] signal sampling register, offset: 0x3C00 */
  __IO uint32_t TIO3_O;                            /**< TIO[i] output register, offset: 0x3C04 */
  __IO uint32_t TIO3_ENDIS;                        /**< TIO[i] enable/disable register, offset: 0x3C08 */
  __IO uint32_t TIO3_INVERT;                       /**< TIO[i] signal invert register, offset: 0x3C0C */
  __IO uint32_t TIO3_INPUT_MODE;                   /**< TIO[i] input mode register, offset: 0x3C10 */
  __IO uint32_t TIO3_CYCLIC_MODE;                  /**< TIO[i] cyclic mode register, offset: 0x3C14 */
  __IO uint32_t TIO3_TRIG_OUT_GATE_EN;             /**< TIO[i] enable Trigger Output, output gating register, offset: 0x3C18 */
  __IO uint32_t TIO3_PLTRIG_OUT_GATE_EN;           /**< TIO[i] enable PL_TRIG_OUT output gating register, offset: 0x3C1C */
  uint8_t RESERVED_66[32];
  __IO uint32_t TIO3_CS;                           /**< TIO[i] clear signal sampling register, offset: 0x3C40 */
  __IO uint32_t TIO3_CO;                           /**< TIO[i] clear output register, offset: 0x3C44 */
  __IO uint32_t TIO3_CENDIS;                       /**< TIO[i] disable register, offset: 0x3C48 */
  __IO uint32_t TIO3_CINVERT;                      /**< TIO[i] clear signal invert register, offset: 0x3C4C */
  __IO uint32_t TIO3_CINPUT_MODE;                  /**< TIO[i] disable input mode register, offset: 0x3C50 */
  __IO uint32_t TIO3_CCYCLIC_MODE;                 /**< TIO[i] disable cyclic mode register, offset: 0x3C54 */
  __IO uint32_t TIO3_CTRIG_OUT_GATE_EN;            /**< TIO[i] clear Trigger Output, output gating register, offset: 0x3C58 */
  __IO uint32_t TIO3_CPLTRIG_OUT_GATE_EN;          /**< TIO[i] clear PL_TRIG_OUT output gating register, offset: 0x3C5C */
  uint8_t RESERVED_67[32];
  __IO uint32_t TIO3_SS;                           /**< TIO[i] set signal sampling register, offset: 0x3C80 */
  __IO uint32_t TIO3_SO;                           /**< TIO[i] set output register, offset: 0x3C84 */
  __IO uint32_t TIO3_SENDIS;                       /**< TIO[i] enable register, offset: 0x3C88 */
  __IO uint32_t TIO3_SINVERT;                      /**< TIO[i] set signal invert register, offset: 0x3C8C */
  __IO uint32_t TIO3_SINPUT_MODE;                  /**< TIO[i] enable input mode register, offset: 0x3C90 */
  __IO uint32_t TIO3_SCYCLIC_MODE;                 /**< TIO[i] enable cyclic mode register, offset: 0x3C94 */
  __IO uint32_t TIO3_STRIG_OUT_GATE_EN;            /**< TIO[i] set Trigger Output, output gating register, offset: 0x3C98 */
  __IO uint32_t TIO3_SPLTRIG_OUT_GATE_EN;          /**< TIO[i] set PL_TRIG_OUT output gating register, offset: 0x3C9C */
  uint8_t RESERVED_68[32];
  __IO uint32_t TIO3_IS;                           /**< TIO[i] invert signal sampling register, offset: 0x3CC0 */
  __IO uint32_t TIO3_IO;                           /**< TIO[i] invert output register, offset: 0x3CC4 */
  __IO uint32_t TIO3_IENDIS;                       /**< TIO[i] toggle enable/disable register, offset: 0x3CC8 */
  __IO uint32_t TIO3_IINVERT;                      /**< TIO[i] toggle signal invert register, offset: 0x3CCC */
  __IO uint32_t TIO3_IINPUT_MODE;                  /**< TIO[i] enable input mode register, offset: 0x3CD0 */
  __IO uint32_t TIO3_ICYCLIC_MODE;                 /**< TIO[i] enable cyclic mode register, offset: 0x3CD4 */
  uint8_t RESERVED_69[40];
  __IO uint32_t TIO3_FUPD;                         /**< TIO[i] force update register, offset: 0x3D00 */
  __I  uint32_t TIO3_HW_CONF;                      /**< TIO[i] configuration register, offset: 0x3D04 */
  __IO uint32_t TIO3_RSEL_CTRL1;                   /**< TIO[i] resource selection control register 1, offset: 0x3D08 */
  __IO uint32_t TIO3_RSEL_CTRL2;                   /**< TIO[i] resource selection control register 2, offset: 0x3D0C */
  __IO uint32_t TIO3_PL_SWRST;                     /**< TIO[i] software reset for TIO Plus functionality, offset: 0x3D10 */
  uint8_t RESERVED_70[748];
  __IO uint32_t CCM3_ARP0_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4000 */
  __IO uint32_t CCM3_ARP0_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x4004 */
  __IO uint32_t CCM3_ARP1_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4008 */
  __IO uint32_t CCM3_ARP1_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x400C */
  __IO uint32_t CCM3_ARP2_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4010 */
  __IO uint32_t CCM3_ARP2_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x4014 */
  __IO uint32_t CCM3_ARP3_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4018 */
  __IO uint32_t CCM3_ARP3_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x401C */
  __IO uint32_t CCM3_ARP4_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4020 */
  __IO uint32_t CCM3_ARP4_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x4024 */
  __IO uint32_t CCM3_ARP5_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4028 */
  __IO uint32_t CCM3_ARP5_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x402C */
  __IO uint32_t CCM3_ARP6_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4030 */
  __IO uint32_t CCM3_ARP6_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x4034 */
  __IO uint32_t CCM3_ARP7_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4038 */
  __IO uint32_t CCM3_ARP7_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x403C */
  __IO uint32_t CCM3_ARP8_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4040 */
  __IO uint32_t CCM3_ARP8_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x4044 */
  __IO uint32_t CCM3_ARP9_CTRL;                    /**< CCM[i] Address Range Protector [a] Control Register, offset: 0x4048 */
  __IO uint32_t CCM3_ARP9_PROT;                    /**< CCM[i] Address Range Protector [a] Protection Register, offset: 0x404C */
  uint8_t RESERVED_71[380];
  __I  uint32_t CCM3_TIO_G0_OUT;                   /**< CCM[i] TIO Group 0,1 Output Register, offset: 0x41CC */
  uint8_t RESERVED_72[4];
  __I  uint32_t CCM3_HW_CONF2;                     /**< CCM[i] 2. Hardware Configuration Register, offset: 0x41D4 */
  __IO uint32_t CCM3_AEIM_STA;                     /**< CCM[i] MCS Bus Master Status Register, offset: 0x41D8 */
  __I  uint32_t CCM3_HW_CONF;                      /**< CCM[i] Hardware Configuration Register, offset: 0x41DC */
  uint8_t RESERVED_73[12];
  __I  uint32_t CCM3_ATOM_OUT;                     /**< CCM[i] ATOM Output Register, offset: 0x41EC */
  __IO uint32_t CCM3_CMU_CLK_CFG;                  /**< CCM[i] CMU Clock Configuration Register, offset: 0x41F0 */
  uint8_t RESERVED_74[4];
  __IO uint32_t CCM3_CFG;                          /**< CCM[i] Configuration Register, offset: 0x41F8 */
  __IO uint32_t CCM3_PROT;                         /**< CCM[i] Protection Register, offset: 0x41FC */
  uint8_t RESERVED_75[768];
  __IO uint32_t CDTM3_DTM4_CTRL;                   /**< CDTM[i]_DTM[d] global configuration and control register, offset: 0x4500 */
  __IO uint32_t CDTM3_DTM4_CH_CTRL1;               /**< CDTM[i]_DTM[d] channel control register 1, offset: 0x4504 */
  __IO uint32_t CDTM3_DTM4_CH_CTRL2;               /**< CDTM[i]_DTM[d] channel control register 2, offset: 0x4508 */
  __IO uint32_t CDTM3_DTM4_CH_CTRL2_SR;            /**< CDTM[i] DTM[j] channel control register 2 shadow, offset: 0x450C */
  __IO uint32_t CDTM3_DTM4_PS_CTRL;                /**< CDTM[i]_DTM[d] phase shift unit configuration and control register, offset: 0x4510 */
  __IO uint32_t CDTM3_DTM4_CH_DTV[GTM_gtm_cls3_CDTM3_DTM4_CH4_DTV_COUNT]; /**< CDTM[i]_DTM[d] channel [x] dead time reload values, array offset: 0x4514, array step: 0x4 */
  __IO uint32_t CDTM3_DTM4_CH_SR;                  /**< CDTM[i]_DTM[d] channel shadow register, offset: 0x4524 */
  __IO uint32_t CDTM3_DTM4_CH_CTRL3;               /**< CDTM[i]_DTM[d] channel control register 3, offset: 0x4528 */
  __IO uint32_t CDTM3_DTM4_CTRL2;                  /**< CDTM[i]_DTM[d] global configuration and control register 2, offset: 0x452C */
  __IO uint32_t CDTM3_DTM4_CH0_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x4530 */
  __IO uint32_t CDTM3_DTM4_CH1_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x4534 */
  __IO uint32_t CDTM3_DTM4_CH2_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x4538 */
  __IO uint32_t CDTM3_DTM4_CH3_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x453C */
  __IO uint32_t CDTM3_DTM5_CTRL;                   /**< CDTM[i]_DTM[d] global configuration and control register, offset: 0x4540 */
  __IO uint32_t CDTM3_DTM5_CH_CTRL1;               /**< CDTM[i]_DTM[d] channel control register 1, offset: 0x4544 */
  __IO uint32_t CDTM3_DTM5_CH_CTRL2;               /**< CDTM[i]_DTM[d] channel control register 2, offset: 0x4548 */
  __IO uint32_t CDTM3_DTM5_CH_CTRL2_SR;            /**< CDTM[i] DTM[j] channel control register 2 shadow, offset: 0x454C */
  __IO uint32_t CDTM3_DTM5_PS_CTRL;                /**< CDTM[i]_DTM[d] phase shift unit configuration and control register, offset: 0x4550 */
  __IO uint32_t CDTM3_DTM5_CH_DTV[GTM_gtm_cls3_CDTM3_DTM5_CH4_DTV_COUNT]; /**< CDTM[i]_DTM[d] channel [x] dead time reload values, array offset: 0x4554, array step: 0x4 */
  __IO uint32_t CDTM3_DTM5_CH_SR;                  /**< CDTM[i]_DTM[d] channel shadow register, offset: 0x4564 */
  __IO uint32_t CDTM3_DTM5_CH_CTRL3;               /**< CDTM[i]_DTM[d] channel control register 3, offset: 0x4568 */
  __IO uint32_t CDTM3_DTM5_CTRL2;                  /**< CDTM[i]_DTM[d] global configuration and control register 2, offset: 0x456C */
  __IO uint32_t CDTM3_DTM5_CH0_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x4570 */
  __IO uint32_t CDTM3_DTM5_CH1_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x4574 */
  __IO uint32_t CDTM3_DTM5_CH2_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x4578 */
  __IO uint32_t CDTM3_DTM5_CH3_DTV_SR;             /**< CDTM[i]_DTM[d] channel [x] dead time shadow values, offset: 0x457C */
  uint8_t RESERVED_76[2688];
  __I  uint32_t AXIM3_FREE;                        /**< AXIM[i] slot allocation status., offset: 0x5000 */
  __I  uint32_t AXIM3_REQUEST;                     /**< AXIM[i] slot request (allocation)., offset: 0x5004 */
  __IO uint32_t AXIM3_RELEASE;                     /**< AXIM[i] slot release (de-allocation)., offset: 0x5008 */
  uint8_t RESERVED_77[20];
  __IO uint32_t AXIM3_SLOT0_ADDR_LOW;              /**< AXIM[i] slot[s] address bits 31:0 of AXI transaction., offset: 0x5020 */
  uint8_t RESERVED_78[4];
  __IO uint32_t AXIM3_SLOT0_DATA_LOW;              /**< AXIM[i] slot[s] data bits 31:0 of AXI transaction., offset: 0x5028 */
  uint8_t RESERVED_79[4];
  __IO uint32_t AXIM3_SLOT0_CFG1;                  /**< AXIM[i] slot [s] configuration 1, offset: 0x5030 */
  __IO uint32_t AXIM3_SLOT0_CFG2;                  /**< AXIM[i] slot[s] configuration 2, offset: 0x5034 */
  __I  uint32_t AXIM3_SLOT0_STATUS;                /**< AXIM[i] slot[s] status, offset: 0x5038 */
  uint8_t RESERVED_80[4];
  __IO uint32_t AXIM3_SLOT1_ADDR_LOW;              /**< AXIM[i] slot[s] address bits 31:0 of AXI transaction., offset: 0x5040 */
  uint8_t RESERVED_81[4];
  __IO uint32_t AXIM3_SLOT1_DATA_LOW;              /**< AXIM[i] slot[s] data bits 31:0 of AXI transaction., offset: 0x5048 */
  uint8_t RESERVED_82[4];
  __IO uint32_t AXIM3_SLOT1_CFG1;                  /**< AXIM[i] slot [s] configuration 1, offset: 0x5050 */
  __IO uint32_t AXIM3_SLOT1_CFG2;                  /**< AXIM[i] slot[s] configuration 2, offset: 0x5054 */
  __I  uint32_t AXIM3_SLOT1_STATUS;                /**< AXIM[i] slot[s] status, offset: 0x5058 */
  uint8_t RESERVED_83[4];
  __IO uint32_t AXIM3_SLOT2_ADDR_LOW;              /**< AXIM[i] slot[s] address bits 31:0 of AXI transaction., offset: 0x5060 */
  uint8_t RESERVED_84[4];
  __IO uint32_t AXIM3_SLOT2_DATA_LOW;              /**< AXIM[i] slot[s] data bits 31:0 of AXI transaction., offset: 0x5068 */
  uint8_t RESERVED_85[4];
  __IO uint32_t AXIM3_SLOT2_CFG1;                  /**< AXIM[i] slot [s] configuration 1, offset: 0x5070 */
  __IO uint32_t AXIM3_SLOT2_CFG2;                  /**< AXIM[i] slot[s] configuration 2, offset: 0x5074 */
  __I  uint32_t AXIM3_SLOT2_STATUS;                /**< AXIM[i] slot[s] status, offset: 0x5078 */
  uint8_t RESERVED_86[4];
  __IO uint32_t AXIM3_SLOT3_ADDR_LOW;              /**< AXIM[i] slot[s] address bits 31:0 of AXI transaction., offset: 0x5080 */
  uint8_t RESERVED_87[4];
  __IO uint32_t AXIM3_SLOT3_DATA_LOW;              /**< AXIM[i] slot[s] data bits 31:0 of AXI transaction., offset: 0x5088 */
  uint8_t RESERVED_88[4];
  __IO uint32_t AXIM3_SLOT3_CFG1;                  /**< AXIM[i] slot [s] configuration 1, offset: 0x5090 */
  __IO uint32_t AXIM3_SLOT3_CFG2;                  /**< AXIM[i] slot[s] configuration 2, offset: 0x5094 */
  __I  uint32_t AXIM3_SLOT3_STATUS;                /**< AXIM[i] slot[s] status, offset: 0x5098 */
  uint8_t RESERVED_89[44900];
  __IO uint32_t MCS3_MEM[GTM_gtm_cls3_MCS3_MEM_COUNT]; /**< MCS[i] memory region, array offset: 0x10000, array step: 0x4 */
} GTM_gtm_cls3_Type, *GTM_gtm_cls3_MemMapPtr;

/** Number of instances of the GTM_gtm_cls3 module. */
#define GTM_gtm_cls3_INSTANCE_COUNT              (1u)

/* GTM_gtm_cls3 - Peripheral instance base addresses */
/** Peripheral GTM_gtm_cls3 base address */
#define IP_GTM_gtm_cls3_BASE                     (0x73060000u)
/** Peripheral GTM_gtm_cls3 base pointer */
#define IP_GTM_gtm_cls3                          ((GTM_gtm_cls3_Type *)IP_GTM_gtm_cls3_BASE)
/** Array initializer of GTM_gtm_cls3 peripheral base addresses */
#define IP_GTM_gtm_cls3_BASE_ADDRS               { IP_GTM_gtm_cls3_BASE }
/** Array initializer of GTM_gtm_cls3 peripheral base pointers */
#define IP_GTM_gtm_cls3_BASE_PTRS                { IP_GTM_gtm_cls3 }

/* ----------------------------------------------------------------------------
   -- GTM_gtm_cls3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GTM_gtm_cls3_Register_Masks GTM_gtm_cls3 Register Masks
 * @{
 */

/*! @name ATOM3_CH0_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH0_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH0_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH0_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH0_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH0_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH0_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH0_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH0_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH0_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH0_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH0_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH0_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH0_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH0_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH0_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH0_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH0_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH0_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH0_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH0_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH0_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH0_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH0_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH0_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH0_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH0_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH0_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH0_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH0_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH1_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH1_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH1_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH1_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH1_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH1_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH1_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH1_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH1_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH1_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH1_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH1_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH1_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH1_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH1_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH1_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH1_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH1_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH1_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH1_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH1_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH1_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH1_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH1_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH1_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH1_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH1_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH1_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH1_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH1_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH2_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH2_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH2_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH2_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH2_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH2_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH2_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH2_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH2_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH2_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH2_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH2_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH2_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH2_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH2_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH2_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH2_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH2_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH2_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH2_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH2_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH2_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH2_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH2_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH2_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH2_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH2_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH2_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH2_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH2_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH3_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH3_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH3_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH3_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH3_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH3_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH3_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH3_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH3_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH3_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH3_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH3_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH3_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH3_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH3_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH3_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH3_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH3_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH3_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH3_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH3_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH3_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH3_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH3_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH3_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH3_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH3_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH3_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH3_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH3_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH4_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH4_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH4_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH4_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH4_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH4_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH4_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH4_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH4_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH4_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH4_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH4_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH4_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH4_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH4_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH4_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH4_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH4_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH4_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH4_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH4_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH4_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH4_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH4_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH4_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH4_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH4_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH4_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH4_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH4_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH5_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH5_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH5_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH5_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH5_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH5_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH5_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH5_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH5_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH5_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH5_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH5_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH5_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH5_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH5_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH5_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH5_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH5_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH5_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH5_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH5_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH5_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH5_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH5_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH5_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH5_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH5_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH5_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH5_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH5_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH6_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH6_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH6_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH6_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH6_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH6_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH6_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH6_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH6_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH6_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH6_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH6_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH6_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH6_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH6_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH6_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH6_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH6_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH6_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH6_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH6_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH6_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH6_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH6_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH6_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH6_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH6_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH6_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH6_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH6_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_CH7_RDADDR - ATOM[i] channel[x] ARU read address register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR0_MASK (0x1FFU)
#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR0_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR0_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR1_MASK (0x1FF0000U)
#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR1_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR1_WIDTH (9U)
#define GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_RDADDR_RDADDR1_MASK)
/*! @} */

/*! @name ATOM3_CH7_CTRL - ATOM[i] channel [x] control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_MODE_MASK    (0x3U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_MODE_SHIFT   (0U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_MODE_WIDTH   (2U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_MODE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_MODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TB12_SEL_MASK (0x4U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TB12_SEL_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TB12_SEL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TB12_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_TB12_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_TB12_SEL_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ARU_EN_MASK  (0x8U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ARU_EN_SHIFT (3U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ARU_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ARU_EN(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_ARU_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_ARU_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ACB_MASK     (0x1F0U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ACB_SHIFT    (4U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ACB_WIDTH    (5U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ACB(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_ACB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_ACB_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CMP_CTRL_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CMP_CTRL_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CMP_CTRL_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CMP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_CMP_CTRL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_CMP_CTRL_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EUPM_MASK    (0x400U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EUPM_SHIFT   (10U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EUPM_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EUPM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_EUPM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_EUPM_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SL_MASK      (0x800U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SL_SHIFT     (11U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_SL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_SL_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CLK_SRC_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CLK_SRC_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CLK_SRC_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_CLK_SRC(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_CLK_SRC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_CLK_SRC_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_WR_REQ_MASK  (0x10000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_WR_REQ_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_WR_REQ_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_WR_REQ(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_WR_REQ_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_WR_REQ_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIG_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIG_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIG_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIG_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIG_PULSE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIG_PULSE_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_UDMODE_MASK  (0xC0000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_UDMODE_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_UDMODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_UDMODE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_UDMODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_UDMODE_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_RST_CCU0_MASK (0x100000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_RST_CCU0_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_RST_CCU0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_RST_CCU0(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_RST_CCU0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_RST_CCU0_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_TRIG_MASK (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_TRIG_SHIFT (21U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_TRIG_MASK (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_TRIG_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_TRIG(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXTTRIGOUT_MASK (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXTTRIGOUT_SHIFT (23U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXTTRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXTTRIGOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_EXTTRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_EXTTRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIGOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIGOUT_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIGOUT_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIGOUT(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIGOUT_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_TRIGOUT_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SLA_MASK     (0x2000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SLA_SHIFT    (25U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SLA_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SLA(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_SLA_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_SLA_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_MASK     (0x4000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_SHIFT    (26U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_OSM_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ABM_MASK     (0x8000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ABM_SHIFT    (27U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ABM_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_ABM(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_ABM_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_ABM_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_FUPD_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_FUPD_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_FUPD_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_FUPD(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_FUPD_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_EXT_FUPD_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SOMB_MASK    (0x40000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SOMB_SHIFT   (30U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SOMB_WIDTH   (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SOMB(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_SOMB_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_SOMB_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_FREEZE_MASK  (0x80000000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_FREEZE_SHIFT (31U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_FREEZE_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_FREEZE(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_FREEZE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_FREEZE_MASK)
/*! @} */

/*! @name ATOM3_CH7_SR0 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_SR0_SR0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH7_SR0_SR0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH7_SR0_SR0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH7_SR0_SR0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_SR0_SR0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_SR0_SR0_MASK)
/*! @} */

/*! @name ATOM3_CH7_SR1 - ATOM[i] channel [x] CCU0 compare shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_SR1_SR1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH7_SR1_SR1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH7_SR1_SR1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH7_SR1_SR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_SR1_SR1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_SR1_SR1_MASK)
/*! @} */

/*! @name ATOM3_CH7_CM0 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_CM0_CM0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH7_CM0_CM0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH7_CM0_CM0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH7_CM0_CM0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CM0_CM0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CM0_CM0_MASK)
/*! @} */

/*! @name ATOM3_CH7_CM1 - ATOM[i] channel [x] CCU0 compare register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_CM1_CM1_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH7_CM1_CM1_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH7_CM1_CM1_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH7_CM1_CM1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CM1_CM1_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CM1_CM1_MASK)
/*! @} */

/*! @name ATOM3_CH7_CN0 - ATOM[i] channel [x] CCU0 counter register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_CN0_CN0_MASK      (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_CH7_CN0_CN0_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH7_CN0_CN0_WIDTH     (24U)
#define GTM_gtm_cls3_ATOM3_CH7_CN0_CN0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CN0_CN0_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CN0_CN0_MASK)
/*! @} */

/*! @name ATOM3_CH7_STAT - ATOM[i] channel [x] status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_STAT_OL_MASK      (0x1U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_OL_SHIFT     (0U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_OL_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_OL(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_OL_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_OL_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBI_MASK    (0x1F0000U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBI_SHIFT   (16U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBI_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBI(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_ACBI_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_ACBI_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_STAT_DV_MASK      (0x200000U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_DV_SHIFT     (21U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_DV_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_DV(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_DV_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_DV_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_STAT_WRF_MASK     (0x400000U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_WRF_SHIFT    (22U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_WRF_WIDTH    (1U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_WRF(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_WRF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_WRF_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_STAT_DR_MASK      (0x800000U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_DR_SHIFT     (23U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_DR_WIDTH     (1U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_DR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_DR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_DR_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBO_MASK    (0x1F000000U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBO_SHIFT   (24U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBO_WIDTH   (5U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_ACBO(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_ACBO_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_ACBO_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_STAT_OSM_RTF_MASK (0x20000000U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_OSM_RTF_SHIFT (29U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_OSM_RTF_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_STAT_OSM_RTF(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_STAT_OSM_RTF_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_STAT_OSM_RTF_MASK)
/*! @} */

/*! @name ATOM3_CH7_IRQ_NOTIFY - ATOM[i] channel [x] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_NOTIFY_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH7_IRQ_EN - ATOM[i] channel [x] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU0TC_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU0TC_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU0TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU0TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU0TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU0TC_IRQ_EN_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU1TC_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU1TC_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU1TC_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU1TC_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU1TC_IRQ_EN_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_EN_CCU1TC_IRQ_EN_MASK)
/*! @} */

/*! @name ATOM3_CH7_IRQ_FORCINT - ATOM[i] channel [x] software interrupt generation */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU0TC_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU0TC_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU0TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU0TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU0TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU0TC_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU1TC_MASK (0x2U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU1TC_SHIFT (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU1TC_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU1TC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU1TC_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_FORCINT_TRG_CCU1TC_MASK)
/*! @} */

/*! @name ATOM3_CH7_IRQ_MODE - ATOM[i] channel [x] interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_CH7_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name ATOM3_CH7_CTRL_SR - ATOM[i] channel [x] control shadow register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_SL_SR_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_SL_SR_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_SL_SR_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_SL_SR(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_SL_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_SL_SR_MASK)

#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_CLK_SRC_SR_MASK (0xF000U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_CLK_SRC_SR_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_CLK_SRC_SR_WIDTH (4U)
#define GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_CLK_SRC_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_CLK_SRC_SR_SHIFT)) & GTM_gtm_cls3_ATOM3_CH7_CTRL_SR_CLK_SRC_SR_MASK)
/*! @} */

/*! @name ATOM3_AGC_GLB_CTRL - ATOM[i] AGC global control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_HOST_TRIG_MASK (0x1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_HOST_TRIG_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_HOST_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_HOST_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_HOST_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_HOST_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH0_MASK (0x100U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH0_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH0_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH1_MASK (0x200U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH1_SHIFT (9U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH1_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH2_MASK (0x400U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH2_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH2_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH3_MASK (0x800U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH3_SHIFT (11U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH3_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH4_MASK (0x1000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH4_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH4_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH5_MASK (0x2000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH5_SHIFT (13U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH5_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH6_MASK (0x4000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH6_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH6_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH7_MASK (0x8000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH7_SHIFT (15U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH7_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_RST_CH7_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL0_MASK (0x30000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL0_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL1_MASK (0xC0000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL1_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL2_MASK (0x300000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL2_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL3_MASK (0xC00000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL3_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL4_MASK (0x3000000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL4_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL5_MASK (0xC000000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL5_SHIFT (26U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL6_MASK (0x30000000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL6_SHIFT (28U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL7_MASK (0xC0000000U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL7_SHIFT (30U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_GLB_CTRL_UPEN_CTRL7_MASK)
/*! @} */

/*! @name ATOM3_AGC_ENDIS_CTRL - ATOM[i] AGC enable/disable control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL0_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL1_MASK (0xCU)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL1_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL2_MASK (0x30U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL2_SHIFT (4U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL3_MASK (0xC0U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL3_SHIFT (6U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL4_MASK (0x300U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL4_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL5_MASK (0xC00U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL5_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL6_MASK (0x3000U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL6_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL7_MASK (0xC000U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL7_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_CTRL_ENDIS_CTRL7_MASK)
/*! @} */

/*! @name ATOM3_AGC_ENDIS_STAT - ATOM[i] AGC enable/disable status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT0_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT1_MASK (0xCU)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT1_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT2_MASK (0x30U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT2_SHIFT (4U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT3_MASK (0xC0U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT3_SHIFT (6U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT4_MASK (0x300U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT4_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT5_MASK (0xC00U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT5_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT6_MASK (0x3000U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT6_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT7_MASK (0xC000U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT7_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ENDIS_STAT_ENDIS_STAT7_MASK)
/*! @} */

/*! @name ATOM3_AGC_ACT_TB - ATOM[i] AGC action time base register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_ACT_TB_MASK (0xFFFFFFU)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_ACT_TB_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_ACT_TB_WIDTH (24U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_ACT_TB(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ACT_TB_ACT_TB_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ACT_TB_ACT_TB_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TB_TRIG_MASK (0x1000000U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TB_TRIG_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TB_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TB_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TB_TRIG_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TB_TRIG_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TBU_SEL_MASK (0x6000000U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TBU_SEL_SHIFT (25U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TBU_SEL_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TBU_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TBU_SEL_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_ACT_TB_TBU_SEL_MASK)
/*! @} */

/*! @name ATOM3_AGC_OUTEN_CTRL - ATOM[i] AGC output enable control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL0_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL1_MASK (0xCU)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL1_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL2_MASK (0x30U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL2_SHIFT (4U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL3_MASK (0xC0U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL3_SHIFT (6U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL4_MASK (0x300U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL4_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL5_MASK (0xC00U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL5_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL6_MASK (0x3000U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL6_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL7_MASK (0xC000U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL7_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_CTRL_OUTEN_CTRL7_MASK)
/*! @} */

/*! @name ATOM3_AGC_OUTEN_STAT - ATOM[i] AGC output enable status register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT0_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT1_MASK (0xCU)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT1_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT2_MASK (0x30U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT2_SHIFT (4U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT3_MASK (0xC0U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT3_SHIFT (6U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT4_MASK (0x300U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT4_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT5_MASK (0xC00U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT5_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT6_MASK (0x3000U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT6_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT7_MASK (0xC000U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT7_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_OUTEN_STAT_OUTEN_STAT7_MASK)
/*! @} */

/*! @name ATOM3_AGC_FUPD_CTRL - ATOM[i] AGC force update control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL0_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL1_MASK (0xCU)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL1_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL2_MASK (0x30U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL2_SHIFT (4U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL3_MASK (0xC0U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL3_SHIFT (6U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL4_MASK (0x300U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL4_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL5_MASK (0xC00U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL5_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL6_MASK (0x3000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL6_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL7_MASK (0xC000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL7_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_FUPD_CTRL7_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH0_MASK (0x30000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH0_SHIFT (16U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH1_MASK (0xC0000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH1_SHIFT (18U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH2_MASK (0x300000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH2_SHIFT (20U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH3_MASK (0xC00000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH3_SHIFT (22U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH4_MASK (0x3000000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH4_SHIFT (24U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH5_MASK (0xC000000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH5_SHIFT (26U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH6_MASK (0x30000000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH6_SHIFT (28U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH7_MASK (0xC0000000U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH7_SHIFT (30U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_FUPD_CTRL_RSTCN0_CH7_MASK)
/*! @} */

/*! @name ATOM3_AGC_INT_TRIG - ATOM[i] AGC internal trigger control register */
/*! @{ */

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG0_MASK (0x3U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG0_SHIFT (0U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG0_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG0_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG0_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG1_MASK (0xCU)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG1_SHIFT (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG1_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG1_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG1_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG2_MASK (0x30U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG2_SHIFT (4U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG2_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG2_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG2_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG3_MASK (0xC0U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG3_SHIFT (6U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG3_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG3_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG3_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG4_MASK (0x300U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG4_SHIFT (8U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG4_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG4_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG4_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG5_MASK (0xC00U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG5_SHIFT (10U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG5_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG5_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG5_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG6_MASK (0x3000U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG6_SHIFT (12U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG6_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG6_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG6_MASK)

#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG7_MASK (0xC000U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG7_SHIFT (14U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG7_WIDTH (2U)
#define GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG7_SHIFT)) & GTM_gtm_cls3_ATOM3_AGC_INT_TRIG_INT_TRIG7_MASK)
/*! @} */

/*! @name MCS3_CH0_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH0_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH0_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH0_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH0_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH0_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH0_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH0_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH0_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH0_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH0_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH0_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH0_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH0_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH0_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH0_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH0_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH0_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH0_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH0_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH1_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH1_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH1_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH1_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH1_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH1_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH1_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH1_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH1_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH1_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH1_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH1_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH1_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH1_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH1_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH1_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH1_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH1_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH1_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH1_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH2_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH2_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH2_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH2_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH2_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH2_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH2_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH2_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH2_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH2_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH2_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH2_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH2_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH2_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH2_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH2_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH2_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH2_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH2_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH2_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH3_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH3_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH3_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH3_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH3_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH3_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH3_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH3_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH3_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH3_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH3_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH3_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH3_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH3_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH3_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH3_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH3_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH3_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH3_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH3_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH4_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH4_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH4_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH4_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH4_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH4_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH4_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH4_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH4_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH4_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH4_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH4_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH4_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH4_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH4_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH4_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH4_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH4_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH4_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH4_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH5_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH5_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH5_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH5_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH5_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH5_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH5_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH5_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH5_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH5_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH5_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH5_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH5_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH5_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH5_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH5_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH5_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH5_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH5_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH5_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH6_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH6_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH6_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH6_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH6_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH6_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH6_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH6_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH6_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH6_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH6_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH6_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH6_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH6_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH6_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH6_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH6_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH6_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH6_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH6_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH7_R0 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R0_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R0_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R0_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R0_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R0_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R0_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R1 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R1_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R1_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R1_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R1_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R1_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R1_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R2 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R2_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R2_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R2_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R2_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R2_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R2_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R3 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R3_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R3_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R3_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R3_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R3_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R3_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R4 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R4_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R4_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R4_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R4_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R4_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R4_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R5 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R5_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R5_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R5_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R5_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R5_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R5_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R6 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R6_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R6_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R6_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R6_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R6_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R6_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_R7 - MCS[i] channel x general purpose register [y] */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_R7_DATA_MASK       (0xFFFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_R7_DATA_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_R7_DATA_WIDTH      (24U)
#define GTM_gtm_cls3_MCS3_CH7_R7_DATA(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_R7_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_R7_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_CTRL - MCS[i] channel x control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_CTRL_EN_MASK       (0x1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_EN_SHIFT      (0U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_EN_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_EN(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_IRQ_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_IRQ_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_IRQ_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_ERR_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_ERR_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_ERR_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_ERR_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_CY_MASK       (0x10U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CY_SHIFT      (4U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CY_WIDTH      (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CY(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_CY_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_CY_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_Z_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_Z_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_Z_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_Z(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_Z_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_Z_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_V_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_V_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_V_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_V(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_V_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_V_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_N_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_N_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_N_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_N(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_N_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_N_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_CAT_MASK      (0x100U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CAT_SHIFT     (8U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_CAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_CAT_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_CWT_MASK      (0x200U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CWT_SHIFT     (9U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CWT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_CWT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_CWT_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_CWT_MASK)

#define GTM_gtm_cls3_MCS3_CH7_CTRL_SAT_MASK      (0x400U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_SAT_SHIFT     (10U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_SAT_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_CTRL_SAT(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_CTRL_SAT_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_CTRL_SAT_MASK)
/*! @} */

/*! @name MCS3_CH7_ACB - MCS[i] channel x ARU control Bit register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB0_MASK      (0x1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB0_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB0_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_ACB_ACB0_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_ACB_ACB0_MASK)

#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB1_MASK      (0x2U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB1_SHIFT     (1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB1_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_ACB_ACB1_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_ACB_ACB1_MASK)

#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB2_MASK      (0x4U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB2_SHIFT     (2U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB2_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_ACB_ACB2_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_ACB_ACB2_MASK)

#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB3_MASK      (0x8U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB3_SHIFT     (3U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB3_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_ACB_ACB3_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_ACB_ACB3_MASK)

#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB4_MASK      (0x10U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB4_SHIFT     (4U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB4_WIDTH     (1U)
#define GTM_gtm_cls3_MCS3_CH7_ACB_ACB4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_ACB_ACB4_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_ACB_ACB4_MASK)
/*! @} */

/*! @name MCS3_CH7_MHB - MCS[i] channel x memory high byte register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_MHB_DATA_MASK      (0xFFU)
#define GTM_gtm_cls3_MCS3_CH7_MHB_DATA_SHIFT     (0U)
#define GTM_gtm_cls3_MCS3_CH7_MHB_DATA_WIDTH     (8U)
#define GTM_gtm_cls3_MCS3_CH7_MHB_DATA(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_MHB_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_MHB_DATA_MASK)
/*! @} */

/*! @name MCS3_CH7_PC - MCS[i] channel x program counter register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_PC_PC_MASK         (0xFFFFU)
#define GTM_gtm_cls3_MCS3_CH7_PC_PC_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CH7_PC_PC_WIDTH        (16U)
#define GTM_gtm_cls3_MCS3_CH7_PC_PC(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_PC_PC_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_PC_PC_MASK)
/*! @} */

/*! @name MCS3_CH7_IRQ_NOTIFY - MCS[i] channel x interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_NOTIFY_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH7_IRQ_EN - MCS[i] channel x interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_MCS_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_MCS_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_MCS_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_MCS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_EN_MCS_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_EN_MCS_IRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_ERR_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_ERR_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_ERR_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_EN_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_EN_ERR_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_EN_ERR_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CH7_IRQ_FORCINT - MCS[i] channel x force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_MCS_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_MCS_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_MCS_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_MCS_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_MCS_IRQ_MASK)

#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_ERR_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_ERR_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_ERR_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_FORCINT_TRG_ERR_IRQ_MASK)
/*! @} */

/*! @name MCS3_CH7_IRQ_MODE - MCS[i] channel x IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CH7_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_CH7_EIRQ_EN - MCS[i] channel x error interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_MCS_EIRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_MCS_EIRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_MCS_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_MCS_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_MCS_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_MCS_EIRQ_EN_MASK)

#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_ERR_EIRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_ERR_EIRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_ERR_EIRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_ERR_EIRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_ERR_EIRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_CH7_EIRQ_EN_ERR_EIRQ_EN_MASK)
/*! @} */

/*! @name MCS3_CTRG - MCS[i] clear trigger control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CTRG_TRG0_MASK         (0x1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG0_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG0_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG0(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG0_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG0_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG1_MASK         (0x2U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG1_SHIFT        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG1_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG1(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG1_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG1_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG2_MASK         (0x4U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG2_SHIFT        (2U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG2_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG2(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG2_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG2_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG3_MASK         (0x8U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG3_SHIFT        (3U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG3_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG3(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG3_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG3_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG4_MASK         (0x10U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG4_SHIFT        (4U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG4_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG4(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG4_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG4_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG5_MASK         (0x20U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG5_SHIFT        (5U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG5_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG5(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG5_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG5_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG6_MASK         (0x40U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG6_SHIFT        (6U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG6_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG6(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG6_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG6_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG7_MASK         (0x80U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG7_SHIFT        (7U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG7_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG7(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG7_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG7_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG8_MASK         (0x100U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG8_SHIFT        (8U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG8_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG8(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG8_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG8_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG9_MASK         (0x200U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG9_SHIFT        (9U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG9_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG9(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG9_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG9_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG10_MASK        (0x400U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG10_SHIFT       (10U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG10_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG10(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG10_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG10_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG11_MASK        (0x800U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG11_SHIFT       (11U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG11_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG11(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG11_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG11_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG12_MASK        (0x1000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG12_SHIFT       (12U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG12_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG12(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG12_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG12_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG13_MASK        (0x2000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG13_SHIFT       (13U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG13_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG13(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG13_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG13_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG14_MASK        (0x4000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG14_SHIFT       (14U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG14_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG14(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG14_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG14_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG15_MASK        (0x8000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG15_SHIFT       (15U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG15_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG15(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG15_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG15_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG16_MASK        (0x10000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG16_SHIFT       (16U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG16_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG16(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG16_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG16_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG17_MASK        (0x20000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG17_SHIFT       (17U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG17_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG17(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG17_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG17_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG18_MASK        (0x40000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG18_SHIFT       (18U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG18_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG18(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG18_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG18_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG19_MASK        (0x80000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG19_SHIFT       (19U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG19_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG19(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG19_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG19_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG20_MASK        (0x100000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG20_SHIFT       (20U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG20_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG20(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG20_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG20_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG21_MASK        (0x200000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG21_SHIFT       (21U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG21_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG21(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG21_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG21_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG22_MASK        (0x400000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG22_SHIFT       (22U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG22_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG22(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG22_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG22_MASK)

#define GTM_gtm_cls3_MCS3_CTRG_TRG23_MASK        (0x800000U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG23_SHIFT       (23U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG23_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_CTRG_TRG23(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRG_TRG23_SHIFT)) & GTM_gtm_cls3_MCS3_CTRG_TRG23_MASK)
/*! @} */

/*! @name MCS3_STRG - MCS[i] set trigger control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_STRG_TRG0_MASK         (0x1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG0_SHIFT        (0U)
#define GTM_gtm_cls3_MCS3_STRG_TRG0_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG0(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG0_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG0_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG1_MASK         (0x2U)
#define GTM_gtm_cls3_MCS3_STRG_TRG1_SHIFT        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG1_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG1(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG1_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG1_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG2_MASK         (0x4U)
#define GTM_gtm_cls3_MCS3_STRG_TRG2_SHIFT        (2U)
#define GTM_gtm_cls3_MCS3_STRG_TRG2_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG2(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG2_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG2_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG3_MASK         (0x8U)
#define GTM_gtm_cls3_MCS3_STRG_TRG3_SHIFT        (3U)
#define GTM_gtm_cls3_MCS3_STRG_TRG3_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG3(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG3_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG3_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG4_MASK         (0x10U)
#define GTM_gtm_cls3_MCS3_STRG_TRG4_SHIFT        (4U)
#define GTM_gtm_cls3_MCS3_STRG_TRG4_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG4(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG4_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG4_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG5_MASK         (0x20U)
#define GTM_gtm_cls3_MCS3_STRG_TRG5_SHIFT        (5U)
#define GTM_gtm_cls3_MCS3_STRG_TRG5_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG5(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG5_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG5_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG6_MASK         (0x40U)
#define GTM_gtm_cls3_MCS3_STRG_TRG6_SHIFT        (6U)
#define GTM_gtm_cls3_MCS3_STRG_TRG6_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG6(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG6_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG6_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG7_MASK         (0x80U)
#define GTM_gtm_cls3_MCS3_STRG_TRG7_SHIFT        (7U)
#define GTM_gtm_cls3_MCS3_STRG_TRG7_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG7(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG7_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG7_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG8_MASK         (0x100U)
#define GTM_gtm_cls3_MCS3_STRG_TRG8_SHIFT        (8U)
#define GTM_gtm_cls3_MCS3_STRG_TRG8_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG8(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG8_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG8_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG9_MASK         (0x200U)
#define GTM_gtm_cls3_MCS3_STRG_TRG9_SHIFT        (9U)
#define GTM_gtm_cls3_MCS3_STRG_TRG9_WIDTH        (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG9(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG9_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG9_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG10_MASK        (0x400U)
#define GTM_gtm_cls3_MCS3_STRG_TRG10_SHIFT       (10U)
#define GTM_gtm_cls3_MCS3_STRG_TRG10_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG10(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG10_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG10_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG11_MASK        (0x800U)
#define GTM_gtm_cls3_MCS3_STRG_TRG11_SHIFT       (11U)
#define GTM_gtm_cls3_MCS3_STRG_TRG11_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG11(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG11_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG11_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG12_MASK        (0x1000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG12_SHIFT       (12U)
#define GTM_gtm_cls3_MCS3_STRG_TRG12_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG12(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG12_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG12_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG13_MASK        (0x2000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG13_SHIFT       (13U)
#define GTM_gtm_cls3_MCS3_STRG_TRG13_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG13(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG13_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG13_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG14_MASK        (0x4000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG14_SHIFT       (14U)
#define GTM_gtm_cls3_MCS3_STRG_TRG14_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG14(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG14_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG14_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG15_MASK        (0x8000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG15_SHIFT       (15U)
#define GTM_gtm_cls3_MCS3_STRG_TRG15_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG15(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG15_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG15_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG16_MASK        (0x10000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG16_SHIFT       (16U)
#define GTM_gtm_cls3_MCS3_STRG_TRG16_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG16(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG16_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG16_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG17_MASK        (0x20000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG17_SHIFT       (17U)
#define GTM_gtm_cls3_MCS3_STRG_TRG17_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG17(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG17_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG17_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG18_MASK        (0x40000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG18_SHIFT       (18U)
#define GTM_gtm_cls3_MCS3_STRG_TRG18_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG18(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG18_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG18_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG19_MASK        (0x80000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG19_SHIFT       (19U)
#define GTM_gtm_cls3_MCS3_STRG_TRG19_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG19(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG19_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG19_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG20_MASK        (0x100000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG20_SHIFT       (20U)
#define GTM_gtm_cls3_MCS3_STRG_TRG20_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG20(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG20_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG20_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG21_MASK        (0x200000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG21_SHIFT       (21U)
#define GTM_gtm_cls3_MCS3_STRG_TRG21_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG21(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG21_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG21_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG22_MASK        (0x400000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG22_SHIFT       (22U)
#define GTM_gtm_cls3_MCS3_STRG_TRG22_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG22(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG22_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG22_MASK)

#define GTM_gtm_cls3_MCS3_STRG_TRG23_MASK        (0x800000U)
#define GTM_gtm_cls3_MCS3_STRG_TRG23_SHIFT       (23U)
#define GTM_gtm_cls3_MCS3_STRG_TRG23_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_STRG_TRG23(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_STRG_TRG23_SHIFT)) & GTM_gtm_cls3_MCS3_STRG_TRG23_MASK)
/*! @} */

/*! @name MCS3_CTRL_STAT - MCS[i] control and status register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_MODE(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_MODE_MASK)

#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_CH_MASK  (0xF00U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_CH_SHIFT (8U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_CH_WIDTH (4U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_CH(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_CH_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_SCD_CH_MASK)

#define GTM_gtm_cls3_MCS3_CTRL_STAT_RAM_RST_MASK (0x10000U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_RAM_RST_SHIFT (16U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_RAM_RST_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_RAM_RST(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_RAM_RST_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_RAM_RST_MASK)

#define GTM_gtm_cls3_MCS3_CTRL_STAT_ERR_SRC_ID_MASK (0x700000U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_ERR_SRC_ID_SHIFT (20U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_ERR_SRC_ID_WIDTH (3U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_ERR_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_ERR_SRC_ID_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_ERR_SRC_ID_MASK)

#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_TIM_FOUT_MASK (0x1000000U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_TIM_FOUT_SHIFT (24U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_TIM_FOUT_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_TIM_FOUT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_EN_TIM_FOUT_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_EN_TIM_FOUT_MASK)

#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_HVD_MASK  (0x2000000U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_HVD_SHIFT (25U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_HVD_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_EN_HVD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_EN_HVD_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_EN_HVD_MASK)

#define GTM_gtm_cls3_MCS3_CTRL_STAT_HLT_AEIM_ERR_MASK (0x4000000U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_HLT_AEIM_ERR_SHIFT (26U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_HLT_AEIM_ERR_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_CTRL_STAT_HLT_AEIM_ERR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CTRL_STAT_HLT_AEIM_ERR_SHIFT)) & GTM_gtm_cls3_MCS3_CTRL_STAT_HLT_AEIM_ERR_MASK)
/*! @} */

/*! @name MCS3_RESET - MCS[i] reset register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_RESET_RST0_MASK        (0x1U)
#define GTM_gtm_cls3_MCS3_RESET_RST0_SHIFT       (0U)
#define GTM_gtm_cls3_MCS3_RESET_RST0_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST0(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST0_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST0_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST1_MASK        (0x2U)
#define GTM_gtm_cls3_MCS3_RESET_RST1_SHIFT       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST1_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST1(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST1_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST1_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST2_MASK        (0x4U)
#define GTM_gtm_cls3_MCS3_RESET_RST2_SHIFT       (2U)
#define GTM_gtm_cls3_MCS3_RESET_RST2_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST2(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST2_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST2_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST3_MASK        (0x8U)
#define GTM_gtm_cls3_MCS3_RESET_RST3_SHIFT       (3U)
#define GTM_gtm_cls3_MCS3_RESET_RST3_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST3(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST3_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST3_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST4_MASK        (0x10U)
#define GTM_gtm_cls3_MCS3_RESET_RST4_SHIFT       (4U)
#define GTM_gtm_cls3_MCS3_RESET_RST4_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST4(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST4_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST4_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST5_MASK        (0x20U)
#define GTM_gtm_cls3_MCS3_RESET_RST5_SHIFT       (5U)
#define GTM_gtm_cls3_MCS3_RESET_RST5_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST5(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST5_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST5_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST6_MASK        (0x40U)
#define GTM_gtm_cls3_MCS3_RESET_RST6_SHIFT       (6U)
#define GTM_gtm_cls3_MCS3_RESET_RST6_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST6(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST6_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST6_MASK)

#define GTM_gtm_cls3_MCS3_RESET_RST7_MASK        (0x80U)
#define GTM_gtm_cls3_MCS3_RESET_RST7_SHIFT       (7U)
#define GTM_gtm_cls3_MCS3_RESET_RST7_WIDTH       (1U)
#define GTM_gtm_cls3_MCS3_RESET_RST7(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_RESET_RST7_SHIFT)) & GTM_gtm_cls3_MCS3_RESET_RST7_MASK)
/*! @} */

/*! @name MCS3_CAT - MCS[i] cancel ARU transfer instruction */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CAT_CAT0_MASK          (0x1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT0_SHIFT         (0U)
#define GTM_gtm_cls3_MCS3_CAT_CAT0_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT0(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT0_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT0_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT1_MASK          (0x2U)
#define GTM_gtm_cls3_MCS3_CAT_CAT1_SHIFT         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT1_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT1(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT1_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT1_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT2_MASK          (0x4U)
#define GTM_gtm_cls3_MCS3_CAT_CAT2_SHIFT         (2U)
#define GTM_gtm_cls3_MCS3_CAT_CAT2_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT2(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT2_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT2_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT3_MASK          (0x8U)
#define GTM_gtm_cls3_MCS3_CAT_CAT3_SHIFT         (3U)
#define GTM_gtm_cls3_MCS3_CAT_CAT3_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT3(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT3_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT3_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT4_MASK          (0x10U)
#define GTM_gtm_cls3_MCS3_CAT_CAT4_SHIFT         (4U)
#define GTM_gtm_cls3_MCS3_CAT_CAT4_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT4(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT4_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT4_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT5_MASK          (0x20U)
#define GTM_gtm_cls3_MCS3_CAT_CAT5_SHIFT         (5U)
#define GTM_gtm_cls3_MCS3_CAT_CAT5_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT5(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT5_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT5_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT6_MASK          (0x40U)
#define GTM_gtm_cls3_MCS3_CAT_CAT6_SHIFT         (6U)
#define GTM_gtm_cls3_MCS3_CAT_CAT6_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT6(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT6_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT6_MASK)

#define GTM_gtm_cls3_MCS3_CAT_CAT7_MASK          (0x80U)
#define GTM_gtm_cls3_MCS3_CAT_CAT7_SHIFT         (7U)
#define GTM_gtm_cls3_MCS3_CAT_CAT7_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CAT_CAT7(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CAT_CAT7_SHIFT)) & GTM_gtm_cls3_MCS3_CAT_CAT7_MASK)
/*! @} */

/*! @name MCS3_CWT - MCS[i] cancel waiting instruction */
/*! @{ */

#define GTM_gtm_cls3_MCS3_CWT_CWT0_MASK          (0x1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT0_SHIFT         (0U)
#define GTM_gtm_cls3_MCS3_CWT_CWT0_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT0(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT0_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT0_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT1_MASK          (0x2U)
#define GTM_gtm_cls3_MCS3_CWT_CWT1_SHIFT         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT1_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT1(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT1_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT1_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT2_MASK          (0x4U)
#define GTM_gtm_cls3_MCS3_CWT_CWT2_SHIFT         (2U)
#define GTM_gtm_cls3_MCS3_CWT_CWT2_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT2(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT2_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT2_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT3_MASK          (0x8U)
#define GTM_gtm_cls3_MCS3_CWT_CWT3_SHIFT         (3U)
#define GTM_gtm_cls3_MCS3_CWT_CWT3_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT3(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT3_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT3_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT4_MASK          (0x10U)
#define GTM_gtm_cls3_MCS3_CWT_CWT4_SHIFT         (4U)
#define GTM_gtm_cls3_MCS3_CWT_CWT4_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT4(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT4_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT4_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT5_MASK          (0x20U)
#define GTM_gtm_cls3_MCS3_CWT_CWT5_SHIFT         (5U)
#define GTM_gtm_cls3_MCS3_CWT_CWT5_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT5(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT5_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT5_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT6_MASK          (0x40U)
#define GTM_gtm_cls3_MCS3_CWT_CWT6_SHIFT         (6U)
#define GTM_gtm_cls3_MCS3_CWT_CWT6_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT6(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT6_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT6_MASK)

#define GTM_gtm_cls3_MCS3_CWT_CWT7_MASK          (0x80U)
#define GTM_gtm_cls3_MCS3_CWT_CWT7_SHIFT         (7U)
#define GTM_gtm_cls3_MCS3_CWT_CWT7_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_CWT_CWT7(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_CWT_CWT7_SHIFT)) & GTM_gtm_cls3_MCS3_CWT_CWT7_MASK)
/*! @} */

/*! @name MCS3_ERR - MCS[i] error register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_ERR_ERR0_MASK          (0x1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR0_SHIFT         (0U)
#define GTM_gtm_cls3_MCS3_ERR_ERR0_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR0(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR0_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR0_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR1_MASK          (0x2U)
#define GTM_gtm_cls3_MCS3_ERR_ERR1_SHIFT         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR1_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR1(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR1_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR1_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR2_MASK          (0x4U)
#define GTM_gtm_cls3_MCS3_ERR_ERR2_SHIFT         (2U)
#define GTM_gtm_cls3_MCS3_ERR_ERR2_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR2(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR2_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR2_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR3_MASK          (0x8U)
#define GTM_gtm_cls3_MCS3_ERR_ERR3_SHIFT         (3U)
#define GTM_gtm_cls3_MCS3_ERR_ERR3_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR3(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR3_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR3_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR4_MASK          (0x10U)
#define GTM_gtm_cls3_MCS3_ERR_ERR4_SHIFT         (4U)
#define GTM_gtm_cls3_MCS3_ERR_ERR4_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR4(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR4_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR4_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR5_MASK          (0x20U)
#define GTM_gtm_cls3_MCS3_ERR_ERR5_SHIFT         (5U)
#define GTM_gtm_cls3_MCS3_ERR_ERR5_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR5(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR5_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR5_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR6_MASK          (0x40U)
#define GTM_gtm_cls3_MCS3_ERR_ERR6_SHIFT         (6U)
#define GTM_gtm_cls3_MCS3_ERR_ERR6_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR6(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR6_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR6_MASK)

#define GTM_gtm_cls3_MCS3_ERR_ERR7_MASK          (0x80U)
#define GTM_gtm_cls3_MCS3_ERR_ERR7_SHIFT         (7U)
#define GTM_gtm_cls3_MCS3_ERR_ERR7_WIDTH         (1U)
#define GTM_gtm_cls3_MCS3_ERR_ERR7(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_ERR_ERR7_SHIFT)) & GTM_gtm_cls3_MCS3_ERR_ERR7_MASK)
/*! @} */

/*! @name MCS3_REG_PROT - MCS[i] write protection register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT0_MASK   (0x3U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT0_SHIFT  (0U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT0_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT0(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT1_MASK   (0xCU)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT1_SHIFT  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT1_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT1(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT2_MASK   (0x30U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT2_SHIFT  (4U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT2_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT2(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT3_MASK   (0xC0U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT3_SHIFT  (6U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT3_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT3(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT4_MASK   (0x300U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT4_SHIFT  (8U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT4_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT4(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT5_MASK   (0xC00U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT5_SHIFT  (10U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT5_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT5(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT6_MASK   (0x3000U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT6_SHIFT  (12U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT6_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT6(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT7_MASK   (0xC000U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT7_SHIFT  (14U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT7_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_REG_PROT_WPROT7(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_REG_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_MCS3_REG_PROT_WPROT7_MASK)
/*! @} */

/*! @name MCS3_SINT_IRQ_NOTIFY - MCS[i] shared interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ0_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ0_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ0_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ0_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ0_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ1_MASK (0x2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ1_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ1_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ1_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ1_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ2_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ2_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ2_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ2_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ2_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ3_MASK (0x8U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ3_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ3_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ3_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ3_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ4_MASK (0x10U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ4_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ4_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ4_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ4_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ5_MASK (0x20U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ5_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ5_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ5_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ5_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ6_MASK (0x40U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ6_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ6_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ6_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ6_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ7_MASK (0x80U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ7_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ7_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ7_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_NOTIFY_S_IRQ7_MASK)
/*! @} */

/*! @name MCS3_SINT_IRQ_EN - MCS[i] shared interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ0_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ0_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ0_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ0_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ0_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ0_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ1_EN_MASK (0x2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ1_EN_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ1_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ1_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ1_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ1_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ2_EN_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ2_EN_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ2_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ2_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ2_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ2_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ3_EN_MASK (0x8U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ3_EN_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ3_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ3_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ3_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ3_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ4_EN_MASK (0x10U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ4_EN_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ4_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ4_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ4_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ4_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ5_EN_MASK (0x20U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ5_EN_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ5_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ5_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ5_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ5_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ6_EN_MASK (0x40U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ6_EN_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ6_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ6_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ6_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ6_EN_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ7_EN_MASK (0x80U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ7_EN_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ7_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ7_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ7_EN_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_EN_S_IRQ7_EN_MASK)
/*! @} */

/*! @name MCS3_SINT_IRQ_FORCINT - MCS[i] force shared interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ0_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ0_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ0_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ0_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ0_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ1_MASK (0x2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ1_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ1_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ1_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ1_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ2_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ2_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ2_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ2_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ2_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ3_MASK (0x8U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ3_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ3_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ3_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ3_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ4_MASK (0x10U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ4_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ4_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ4_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ4_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ5_MASK (0x20U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ5_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ5_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ5_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ5_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ6_MASK (0x40U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ6_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ6_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ6_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ6_MASK)

#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ7_MASK (0x80U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ7_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ7_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ7_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_FORCINT_TRG_S_IRQ7_MASK)
/*! @} */

/*! @name MCS3_SINT_IRQ_MODE - MCS[i] shared interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_SINT_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_SINT_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_SINT_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_SINT_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_HBP0_CTRL - MCS[i] hardware break point h control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH0_MASK  (0x1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH0_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH0_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH1_MASK  (0x2U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH1_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH1_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH2_MASK  (0x4U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH2_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH2_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH3_MASK  (0x8U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH3_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH3_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH4_MASK  (0x10U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH4_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH4_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH5_MASK  (0x20U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH5_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH5_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH6_MASK  (0x40U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH6_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH6_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH7_MASK  (0x80U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH7_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_EN_CH7_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_SCOPE_MASK   (0x300U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_SCOPE_SHIFT  (8U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_SCOPE_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_SCOPE(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_SCOPE_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_SCOPE_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_TYPE_MASK    (0x7000U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_TYPE_SHIFT   (12U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_TYPE_WIDTH   (3U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_TYPE_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_TYPE_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_AND_MASK     (0x10000U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_AND_SHIFT    (16U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_AND_WIDTH    (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_AND(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_AND_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_AND_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_CTRL_NOT_MASK     (0x20000U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_NOT_SHIFT    (17U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_NOT_WIDTH    (1U)
#define GTM_gtm_cls3_MCS3_HBP0_CTRL_NOT(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_CTRL_NOT_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_CTRL_NOT_MASK)
/*! @} */

/*! @name MCS3_HBP0_PATTERN - MCS[i] hardware break point pattern register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_PATTERN_DATA_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_MCS3_HBP0_PATTERN_DATA_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_PATTERN_DATA_WIDTH (32U)
#define GTM_gtm_cls3_MCS3_HBP0_PATTERN_DATA(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_PATTERN_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_PATTERN_DATA_MASK)
/*! @} */

/*! @name MCS3_HBP0_STATUS - MCS[i] hardware break point status register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH0_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH0_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH0_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH0_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH0_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH1_MASK (0x2U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH1_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH1_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH1_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH1_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH2_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH2_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH2_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH2_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH2_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH3_MASK (0x8U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH3_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH3_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH3_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH3_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH4_MASK (0x10U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH4_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH4_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH4_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH4_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH5_MASK (0x20U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH5_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH5_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH5_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH5_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH6_MASK (0x40U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH6_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH6_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH6_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH6_MASK)

#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH7_MASK (0x80U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH7_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH7_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH7_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_STATUS_HALT_CH7_MASK)
/*! @} */

/*! @name MCS3_HBP0_IRQ_NOTIFY - MCS[i] hardware break point interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_IRQ_NOTIFY_HBP_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_NOTIFY_HBP_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_NOTIFY_HBP_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_NOTIFY_HBP_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_IRQ_NOTIFY_HBP_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_IRQ_NOTIFY_HBP_IRQ_MASK)
/*! @} */

/*! @name MCS3_HBP0_IRQ_EN - MCS[i] hardware break point interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_IRQ_EN_HBP_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_EN_HBP_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_EN_HBP_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_EN_HBP_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_IRQ_EN_HBP_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_IRQ_EN_HBP_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_HBP0_IRQ_FORCINT - MCS[i] force hardware break point interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_IRQ_FORCINT_TRG_HBP_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_FORCINT_TRG_HBP_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_FORCINT_TRG_HBP_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_FORCINT_TRG_HBP_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_IRQ_FORCINT_TRG_HBP_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_IRQ_FORCINT_TRG_HBP_IRQ_MASK)
/*! @} */

/*! @name MCS3_HBP0_IRQ_MODE - MCS[i] break point h interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP0_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_HBP0_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP0_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_HBP0_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name MCS3_HBP1_CTRL - MCS[i] hardware break point h control register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH0_MASK  (0x1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH0_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH0_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH1_MASK  (0x2U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH1_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH1_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH2_MASK  (0x4U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH2_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH2_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH3_MASK  (0x8U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH3_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH3_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH4_MASK  (0x10U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH4_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH4_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH5_MASK  (0x20U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH5_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH5_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH6_MASK  (0x40U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH6_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH6_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH7_MASK  (0x80U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH7_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_EN_CH7_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_SCOPE_MASK   (0x300U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_SCOPE_SHIFT  (8U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_SCOPE_WIDTH  (2U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_SCOPE(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_SCOPE_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_SCOPE_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_TYPE_MASK    (0x7000U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_TYPE_SHIFT   (12U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_TYPE_WIDTH   (3U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_TYPE_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_TYPE_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_AND_MASK     (0x10000U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_AND_SHIFT    (16U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_AND_WIDTH    (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_AND(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_AND_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_AND_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_CTRL_NOT_MASK     (0x20000U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_NOT_SHIFT    (17U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_NOT_WIDTH    (1U)
#define GTM_gtm_cls3_MCS3_HBP1_CTRL_NOT(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_CTRL_NOT_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_CTRL_NOT_MASK)
/*! @} */

/*! @name MCS3_HBP1_PATTERN - MCS[i] hardware break point pattern register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_PATTERN_DATA_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_MCS3_HBP1_PATTERN_DATA_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_PATTERN_DATA_WIDTH (32U)
#define GTM_gtm_cls3_MCS3_HBP1_PATTERN_DATA(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_PATTERN_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_PATTERN_DATA_MASK)
/*! @} */

/*! @name MCS3_HBP1_STATUS - MCS[i] hardware break point status register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH0_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH0_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH0_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH0_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH0_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH1_MASK (0x2U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH1_SHIFT (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH1_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH1_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH1_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH2_MASK (0x4U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH2_SHIFT (2U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH2_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH2_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH2_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH3_MASK (0x8U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH3_SHIFT (3U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH3_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH3_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH3_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH4_MASK (0x10U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH4_SHIFT (4U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH4_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH4_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH4_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH5_MASK (0x20U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH5_SHIFT (5U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH5_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH5_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH5_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH6_MASK (0x40U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH6_SHIFT (6U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH6_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH6_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH6_MASK)

#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH7_MASK (0x80U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH7_SHIFT (7U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH7_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH7_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_STATUS_HALT_CH7_MASK)
/*! @} */

/*! @name MCS3_HBP1_IRQ_NOTIFY - MCS[i] hardware break point interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_IRQ_NOTIFY_HBP_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_NOTIFY_HBP_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_NOTIFY_HBP_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_NOTIFY_HBP_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_IRQ_NOTIFY_HBP_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_IRQ_NOTIFY_HBP_IRQ_MASK)
/*! @} */

/*! @name MCS3_HBP1_IRQ_EN - MCS[i] hardware break point interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_IRQ_EN_HBP_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_EN_HBP_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_EN_HBP_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_EN_HBP_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_IRQ_EN_HBP_IRQ_EN_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_IRQ_EN_HBP_IRQ_EN_MASK)
/*! @} */

/*! @name MCS3_HBP1_IRQ_FORCINT - MCS[i] force hardware break point interrupt register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_IRQ_FORCINT_TRG_HBP_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_FORCINT_TRG_HBP_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_FORCINT_TRG_HBP_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_FORCINT_TRG_HBP_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_IRQ_FORCINT_TRG_HBP_IRQ_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_IRQ_FORCINT_TRG_HBP_IRQ_MASK)
/*! @} */

/*! @name MCS3_HBP1_IRQ_MODE - MCS[i] break point h interrupt mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_MCS3_HBP1_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_MCS3_HBP1_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_HBP1_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_MCS3_HBP1_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH0_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH0_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH0_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH0_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH0_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH0_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH0_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH0_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH0_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH1_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH1_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH1_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH1_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH1_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH1_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH1_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH1_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH1_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH2_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH2_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH2_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH2_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH2_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH2_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH2_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH2_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH2_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH3_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH3_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH3_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH3_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH3_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH3_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH3_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH3_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH3_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH4_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH4_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH4_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH4_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH4_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH4_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH4_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH4_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH4_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH5_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH5_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH5_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH5_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH5_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH5_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH5_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH5_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH5_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH6_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH6_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH6_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH6_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH6_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH6_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH6_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH6_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH6_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_CTRL - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_RE_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_RE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_FE_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_FE_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_RE_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_RE_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_FE_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_FE_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PL_EVT_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_INIT_TRIG_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_INIT_TRIG_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_INIT_TRIG_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_INIT_TRIG_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_UPDATE_SRC_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_UPDATE_SRC_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_UPDATE_SRC_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_UPDATE_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_UPDATE_SRC_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_UPDATE_SRC_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_MODE_MASK (0x3000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_MODE_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_S_EN_MASK (0x4000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_S_EN_SHIFT (14U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_S_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_S_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_S_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_S_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_BUFF_MASK (0x8000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_BUFF_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_BUFF_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_BUFF(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_BUFF_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_CYCLIC_BUFF_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_MODE_MASK (0x70000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_MODE_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_MODE_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_MODE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_O_EN_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_O_EN_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_O_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_O_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_O_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_FREEZE_O_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_ODIS_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_ODIS_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_ODIS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_ODIS(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_ODIS_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_ODIS_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_SEL_IN_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_SEL_IN_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_SEL_IN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_SEL_IN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_SEL_IN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_SEL_IN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_TRIG_OUT_EN_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_TRIG_OUT_EN_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_O_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_TRIG_OUT_EN_MASK (0x800000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_TRIG_OUT_EN_SHIFT (23U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_TRIG_OUT_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_TRIG_OUT_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_TRIG_OUT_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_S_TRIG_OUT_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_RE_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_FE_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_S_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_RE_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_RE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_RE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_RE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_RE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_FE_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_FE_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_FE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_FE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_O_FE_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PL_EVT_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PL_EVT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PL_EVT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PL_EVT_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_EN_PREV_PL_TRIG_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_UPD_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL_PL_TRIG_OUT_UPD_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_IRQ_NOTIFY - TIO[i] channel [c] interrupt notification register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_NOTIFY_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_IRQ_EN - TIO[i] channel [c] interrupt enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_RE_IRQ_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_RE_IRQ_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_FE_IRQ_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_FE_IRQ_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_S_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_RE_IRQ_EN_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_RE_IRQ_EN_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_RE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_RE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_RE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_RE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_FE_IRQ_EN_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_FE_IRQ_EN_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_FE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_FE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_FE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_O_FE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_UPDATE_IRQ_EN_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_UPDATE_IRQ_EN_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_UPDATE_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_UPDATE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_UPDATE_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_UPDATE_IRQ_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_PL_EVT_IRQ_EN_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_PL_EVT_IRQ_EN_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_PL_EVT_IRQ_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_PL_EVT_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_PL_EVT_IRQ_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_EN_PL_EVT_IRQ_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_IRQ_FORCINT - TIO[i] channel [c] force interrupt register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_RE_IRQ_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_FE_IRQ_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_S_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_RE_IRQ_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_RE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_RE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_RE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_RE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_FE_IRQ_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_FE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_FE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_FE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_O_FE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_UPDATE_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_UPDATE_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_UPDATE_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_UPDATE_IRQ_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_PL_EVT_IRQ_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_PL_EVT_IRQ(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_PL_EVT_IRQ_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_FORCINT_TRG_PL_EVT_IRQ_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_IRQ_MODE - TIO[i] channel [c] IRQ mode configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_MODE_IRQ_MODE_MASK (0x3U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_MODE_IRQ_MODE_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_MODE_IRQ_MODE_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_IRQ_MODE_IRQ_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_IRQ_MODE_IRQ_MODE_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_IRQ_MODE_IRQ_MODE_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_CTRL2 - TIO[i] group [g] channel [c] control register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_EN_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_EN_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_MST_EN_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_MST_EN_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_MST_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_MST_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_MST_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_CTRL2_DUAL_CMP_MST_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_SINST - TIO[i] channel [c] resource S instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_SCMD - TIO[i] channel [c] resource S command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_SOP - TIO[i] channel [c] resource S operand register TIO[i]_G[g]_CH[c]_CTRL.PL_S_MODE=0b0- or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b10- or TIO[i]_G[g]_OP_USAGE.MODE[c]=0b1-0 ) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_SOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH7_SOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_OINST - TIO[i] channel [c] resource O instruction register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE =0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_OP_MASK   (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_OP_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_OP_WIDTH  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_OP(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OINST_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OINST_OP_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_CMD_MASK  (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_CMD_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_CMD_WIDTH (6U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_CMD(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OINST_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OINST_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OINST_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OINST_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OINST_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OINST_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OINST_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_OCMD - TIO[i] channel [c] resource O command register (buffer operation) TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b00- */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_CMD_MASK   (0x3F000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_CMD_SHIFT  (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_CMD_WIDTH  (6U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_CMD(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OCMD_CMD_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OCMD_CMD_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_DATA_PUSH_EN_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_DATA_PUSH_EN_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_DATA_PUSH_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_DATA_PUSH_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OCMD_DATA_PUSH_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OCMD_DATA_PUSH_EN_MASK)

#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_INSTR_PULL_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_INSTR_PULL_EN_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_INSTR_PULL_EN_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OCMD_INSTR_PULL_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OCMD_INSTR_PULL_EN_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OCMD_INSTR_PULL_EN_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_OOP - TIO[i] channel [c] resource O operand register !(TIO[i]_G[g]_CH[c]_CTRL.PL_O_MODE=0b1--) or (TIO[i]_G[g]_OP_USAGE.MODE[c]=0b11-) */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_OOP_OP_MASK     (0xFFFFFFU)
#define GTM_gtm_cls3_TIO3_G0_CH7_OOP_OP_SHIFT    (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OOP_OP_WIDTH    (24U)
#define GTM_gtm_cls3_TIO3_G0_CH7_OOP_OP(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_OOP_OP_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_OOP_OP_MASK)
/*! @} */

/*! @name TIO3_G0_CH7_SHIFTCNT - TIO[i] channel [c] resource shift count register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_CH7_SHIFTCNT_CNT_MASK (0x1FU)
#define GTM_gtm_cls3_TIO3_G0_CH7_SHIFTCNT_CNT_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SHIFTCNT_CNT_WIDTH (5U)
#define GTM_gtm_cls3_TIO3_G0_CH7_SHIFTCNT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_CH7_SHIFTCNT_CNT_SHIFT)) & GTM_gtm_cls3_TIO3_G0_CH7_SHIFTCNT_CNT_MASK)
/*! @} */

/*! @name TIO3_G0_ISEL0_CTRL1 - TIO[i] input selection register 1 */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_0_MASK (0xFU)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_0_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_1_MASK (0xF0U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_1_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_1_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_2_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_2_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_2_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_2_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_3_MASK (0xF000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_3_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_3_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_LUT2_3_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL0_MASK (0x10000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL0_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL1_MASK (0x20000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL1_SHIFT (17U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL2_MASK (0x40000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL2_SHIFT (18U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL2_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL3_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL3_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_OUT_SEL3_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN0_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN0_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN1_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN1_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN2_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN2_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN2_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN3_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN3_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL1_WRITE_EN3_MASK)
/*! @} */

/*! @name TIO3_G0_ISEL0_CTRL2 - TIO[i] input selection register 2 */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3_MASK (0xFFU)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3_WIDTH (8U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_QOUT_SEL_MASK (0x30000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_QOUT_SEL_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_QOUT_SEL_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_QOUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_QOUT_SEL_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_QOUT_SEL_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL0_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL0_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL1_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL1_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL2_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL2_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL0_CTRL2_LUT3IN_SEL2_MASK)
/*! @} */

/*! @name TIO3_G0_ISEL1_CTRL1 - TIO[i] input selection register 1 */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_0_MASK (0xFU)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_0_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_1_MASK (0xF0U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_1_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_1_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_2_MASK (0xF00U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_2_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_2_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_2_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_3_MASK (0xF000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_3_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_3_WIDTH (4U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_LUT2_3_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL0_MASK (0x10000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL0_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL1_MASK (0x20000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL1_SHIFT (17U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL2_MASK (0x40000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL2_SHIFT (18U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL2_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL3_MASK (0x80000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL3_SHIFT (19U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_OUT_SEL3_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN0_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN0_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN1_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN1_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN2_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN2_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN2_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN3_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN3_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL1_WRITE_EN3_MASK)
/*! @} */

/*! @name TIO3_G0_ISEL1_CTRL2 - TIO[i] input selection register 2 */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3_MASK (0xFFU)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3_WIDTH (8U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_QOUT_SEL_MASK (0x30000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_QOUT_SEL_SHIFT (16U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_QOUT_SEL_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_QOUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_QOUT_SEL_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_QOUT_SEL_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL0_MASK (0x100000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL0_SHIFT (20U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL0_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL1_MASK (0x200000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL1_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL1_MASK)

#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL2_MASK (0x400000U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL2_SHIFT (22U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_ISEL1_CTRL2_LUT3IN_SEL2_MASK)
/*! @} */

/*! @name TIO3_G0_OP_USAGE - TIO[i] operand usage selection register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE0_MASK (0x7U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE0_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE0(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE0_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE1_MASK (0x38U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE1_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE1_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE1(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE1_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE2_MASK (0x1C0U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE2_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE2_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE2(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE2_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE3_MASK (0xE00U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE3_SHIFT (9U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE3_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE3(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE3_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE4_MASK (0x7000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE4_SHIFT (12U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE4_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE4(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE4_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE4_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE5_MASK (0x38000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE5_SHIFT (15U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE5_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE5(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE5_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE5_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE6_MASK (0x1C0000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE6_SHIFT (18U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE6_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE6(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE6_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE6_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE7_MASK (0xE00000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE7_SHIFT (21U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE7_WIDTH (3U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE7(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE7_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_MODE7_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN0_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN0_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN0_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN0_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN1_MASK (0x2000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN1_SHIFT (25U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN1_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN1_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN2_MASK (0x4000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN2_SHIFT (26U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN2_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN2_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN3_MASK (0x8000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN3_SHIFT (27U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN3_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN3_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN4_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN4_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN4_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN4_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN5_MASK (0x20000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN5_SHIFT (29U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN5_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN5_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN6_MASK (0x40000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN6_SHIFT (30U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN6_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN6_MASK)

#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN7_MASK (0x80000000U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN7_SHIFT (31U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN7_SHIFT)) & GTM_gtm_cls3_TIO3_G0_OP_USAGE_WRITE_EN7_MASK)
/*! @} */

/*! @name TIO3_S - TIO[i] signal sampling register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_S_CH0_MASK             (0x1U)
#define GTM_gtm_cls3_TIO3_S_CH0_SHIFT            (0U)
#define GTM_gtm_cls3_TIO3_S_CH0_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH0(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH0_MASK)

#define GTM_gtm_cls3_TIO3_S_CH1_MASK             (0x2U)
#define GTM_gtm_cls3_TIO3_S_CH1_SHIFT            (1U)
#define GTM_gtm_cls3_TIO3_S_CH1_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH1(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH1_MASK)

#define GTM_gtm_cls3_TIO3_S_CH2_MASK             (0x4U)
#define GTM_gtm_cls3_TIO3_S_CH2_SHIFT            (2U)
#define GTM_gtm_cls3_TIO3_S_CH2_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH2(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH2_MASK)

#define GTM_gtm_cls3_TIO3_S_CH3_MASK             (0x8U)
#define GTM_gtm_cls3_TIO3_S_CH3_SHIFT            (3U)
#define GTM_gtm_cls3_TIO3_S_CH3_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH3(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH3_MASK)

#define GTM_gtm_cls3_TIO3_S_CH4_MASK             (0x10U)
#define GTM_gtm_cls3_TIO3_S_CH4_SHIFT            (4U)
#define GTM_gtm_cls3_TIO3_S_CH4_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH4(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH4_MASK)

#define GTM_gtm_cls3_TIO3_S_CH5_MASK             (0x20U)
#define GTM_gtm_cls3_TIO3_S_CH5_SHIFT            (5U)
#define GTM_gtm_cls3_TIO3_S_CH5_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH5(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH5_MASK)

#define GTM_gtm_cls3_TIO3_S_CH6_MASK             (0x40U)
#define GTM_gtm_cls3_TIO3_S_CH6_SHIFT            (6U)
#define GTM_gtm_cls3_TIO3_S_CH6_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH6(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH6_MASK)

#define GTM_gtm_cls3_TIO3_S_CH7_MASK             (0x80U)
#define GTM_gtm_cls3_TIO3_S_CH7_SHIFT            (7U)
#define GTM_gtm_cls3_TIO3_S_CH7_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_S_CH7(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_S_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_S_CH7_MASK)
/*! @} */

/*! @name TIO3_O - TIO[i] output register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_O_CH0_MASK             (0x1U)
#define GTM_gtm_cls3_TIO3_O_CH0_SHIFT            (0U)
#define GTM_gtm_cls3_TIO3_O_CH0_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH0(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH0_MASK)

#define GTM_gtm_cls3_TIO3_O_CH1_MASK             (0x2U)
#define GTM_gtm_cls3_TIO3_O_CH1_SHIFT            (1U)
#define GTM_gtm_cls3_TIO3_O_CH1_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH1(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH1_MASK)

#define GTM_gtm_cls3_TIO3_O_CH2_MASK             (0x4U)
#define GTM_gtm_cls3_TIO3_O_CH2_SHIFT            (2U)
#define GTM_gtm_cls3_TIO3_O_CH2_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH2(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH2_MASK)

#define GTM_gtm_cls3_TIO3_O_CH3_MASK             (0x8U)
#define GTM_gtm_cls3_TIO3_O_CH3_SHIFT            (3U)
#define GTM_gtm_cls3_TIO3_O_CH3_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH3(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH3_MASK)

#define GTM_gtm_cls3_TIO3_O_CH4_MASK             (0x10U)
#define GTM_gtm_cls3_TIO3_O_CH4_SHIFT            (4U)
#define GTM_gtm_cls3_TIO3_O_CH4_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH4(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH4_MASK)

#define GTM_gtm_cls3_TIO3_O_CH5_MASK             (0x20U)
#define GTM_gtm_cls3_TIO3_O_CH5_SHIFT            (5U)
#define GTM_gtm_cls3_TIO3_O_CH5_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH5(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH5_MASK)

#define GTM_gtm_cls3_TIO3_O_CH6_MASK             (0x40U)
#define GTM_gtm_cls3_TIO3_O_CH6_SHIFT            (6U)
#define GTM_gtm_cls3_TIO3_O_CH6_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH6(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH6_MASK)

#define GTM_gtm_cls3_TIO3_O_CH7_MASK             (0x80U)
#define GTM_gtm_cls3_TIO3_O_CH7_SHIFT            (7U)
#define GTM_gtm_cls3_TIO3_O_CH7_WIDTH            (1U)
#define GTM_gtm_cls3_TIO3_O_CH7(x)               (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_O_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_O_CH7_MASK)
/*! @} */

/*! @name TIO3_ENDIS - TIO[i] enable/disable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_ENDIS_CH0_MASK         (0x1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH0_SHIFT        (0U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH0_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH0(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH1_MASK         (0x2U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH1_SHIFT        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH1_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH1(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH2_MASK         (0x4U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH2_SHIFT        (2U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH2_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH2(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH3_MASK         (0x8U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH3_SHIFT        (3U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH3_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH3(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH4_MASK         (0x10U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH4_SHIFT        (4U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH4_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH4(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH5_MASK         (0x20U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH5_SHIFT        (5U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH5_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH5(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH6_MASK         (0x40U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH6_SHIFT        (6U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH6_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH6(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_ENDIS_CH7_MASK         (0x80U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH7_SHIFT        (7U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH7_WIDTH        (1U)
#define GTM_gtm_cls3_TIO3_ENDIS_CH7(x)           (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ENDIS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_ENDIS_CH7_MASK)
/*! @} */

/*! @name TIO3_INVERT - TIO[i] signal invert register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_INVERT_CH0_MASK        (0x1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH0_SHIFT       (0U)
#define GTM_gtm_cls3_TIO3_INVERT_CH0_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH0(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH0_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH1_MASK        (0x2U)
#define GTM_gtm_cls3_TIO3_INVERT_CH1_SHIFT       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH1_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH1(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH1_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH2_MASK        (0x4U)
#define GTM_gtm_cls3_TIO3_INVERT_CH2_SHIFT       (2U)
#define GTM_gtm_cls3_TIO3_INVERT_CH2_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH2(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH2_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH3_MASK        (0x8U)
#define GTM_gtm_cls3_TIO3_INVERT_CH3_SHIFT       (3U)
#define GTM_gtm_cls3_TIO3_INVERT_CH3_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH3(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH3_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH4_MASK        (0x10U)
#define GTM_gtm_cls3_TIO3_INVERT_CH4_SHIFT       (4U)
#define GTM_gtm_cls3_TIO3_INVERT_CH4_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH4(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH4_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH5_MASK        (0x20U)
#define GTM_gtm_cls3_TIO3_INVERT_CH5_SHIFT       (5U)
#define GTM_gtm_cls3_TIO3_INVERT_CH5_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH5(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH5_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH6_MASK        (0x40U)
#define GTM_gtm_cls3_TIO3_INVERT_CH6_SHIFT       (6U)
#define GTM_gtm_cls3_TIO3_INVERT_CH6_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH6(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH6_MASK)

#define GTM_gtm_cls3_TIO3_INVERT_CH7_MASK        (0x80U)
#define GTM_gtm_cls3_TIO3_INVERT_CH7_SHIFT       (7U)
#define GTM_gtm_cls3_TIO3_INVERT_CH7_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_INVERT_CH7(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INVERT_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_INVERT_CH7_MASK)
/*! @} */

/*! @name TIO3_INPUT_MODE - TIO[i] input mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH0_MASK    (0x1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH0_SHIFT   (0U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH0_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH0(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH1_MASK    (0x2U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH1_SHIFT   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH1_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH1(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH2_MASK    (0x4U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH2_SHIFT   (2U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH2_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH2(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH3_MASK    (0x8U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH3_SHIFT   (3U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH3_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH3(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH4_MASK    (0x10U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH4_SHIFT   (4U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH4_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH4(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH5_MASK    (0x20U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH5_SHIFT   (5U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH5_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH5(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH6_MASK    (0x40U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH6_SHIFT   (6U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH6_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH6(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH7_MASK    (0x80U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH7_SHIFT   (7U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH7_WIDTH   (1U)
#define GTM_gtm_cls3_TIO3_INPUT_MODE_CH7(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_INPUT_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_INPUT_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_CYCLIC_MODE - TIO[i] cyclic mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH0_MASK   (0x1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH0_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH0_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH0(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH1_MASK   (0x2U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH1_SHIFT  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH1_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH1(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH2_MASK   (0x4U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH2_SHIFT  (2U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH2_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH2(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH3_MASK   (0x8U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH3_SHIFT  (3U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH3_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH3(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH4_MASK   (0x10U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH4_SHIFT  (4U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH4_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH4(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH5_MASK   (0x20U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH5_SHIFT  (5U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH5_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH5(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH6_MASK   (0x40U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH6_SHIFT  (6U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH6_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH6(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH7_MASK   (0x80U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH7_SHIFT  (7U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH7_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH7(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CYCLIC_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_TRIG_OUT_GATE_EN - TIO[i] enable Trigger Output, output gating register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH0_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH0_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH1_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH1_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH2_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH2_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH3_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH3_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH4_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH4_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH5_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH5_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH6_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH6_MASK)

#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH7_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_TRIG_OUT_GATE_EN_CH7_MASK)
/*! @} */

/*! @name TIO3_PLTRIG_OUT_GATE_EN - TIO[i] enable PL_TRIG_OUT output gating register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH0_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH0_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH1_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH1_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH2_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH2_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH3_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH3_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH4_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH4_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH5_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH5_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH6_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH6_MASK)

#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH7_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_PLTRIG_OUT_GATE_EN_CH7_MASK)
/*! @} */

/*! @name TIO3_CS - TIO[i] clear signal sampling register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CS_CH0_MASK            (0x1U)
#define GTM_gtm_cls3_TIO3_CS_CH0_SHIFT           (0U)
#define GTM_gtm_cls3_TIO3_CS_CH0_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH0(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH1_MASK            (0x2U)
#define GTM_gtm_cls3_TIO3_CS_CH1_SHIFT           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH1_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH1(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH2_MASK            (0x4U)
#define GTM_gtm_cls3_TIO3_CS_CH2_SHIFT           (2U)
#define GTM_gtm_cls3_TIO3_CS_CH2_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH2(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH3_MASK            (0x8U)
#define GTM_gtm_cls3_TIO3_CS_CH3_SHIFT           (3U)
#define GTM_gtm_cls3_TIO3_CS_CH3_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH3(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH4_MASK            (0x10U)
#define GTM_gtm_cls3_TIO3_CS_CH4_SHIFT           (4U)
#define GTM_gtm_cls3_TIO3_CS_CH4_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH4(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH5_MASK            (0x20U)
#define GTM_gtm_cls3_TIO3_CS_CH5_SHIFT           (5U)
#define GTM_gtm_cls3_TIO3_CS_CH5_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH5(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH6_MASK            (0x40U)
#define GTM_gtm_cls3_TIO3_CS_CH6_SHIFT           (6U)
#define GTM_gtm_cls3_TIO3_CS_CH6_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH6(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CS_CH7_MASK            (0x80U)
#define GTM_gtm_cls3_TIO3_CS_CH7_SHIFT           (7U)
#define GTM_gtm_cls3_TIO3_CS_CH7_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CS_CH7(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CS_CH7_MASK)
/*! @} */

/*! @name TIO3_CO - TIO[i] clear output register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CO_CH0_MASK            (0x1U)
#define GTM_gtm_cls3_TIO3_CO_CH0_SHIFT           (0U)
#define GTM_gtm_cls3_TIO3_CO_CH0_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH0(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH1_MASK            (0x2U)
#define GTM_gtm_cls3_TIO3_CO_CH1_SHIFT           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH1_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH1(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH2_MASK            (0x4U)
#define GTM_gtm_cls3_TIO3_CO_CH2_SHIFT           (2U)
#define GTM_gtm_cls3_TIO3_CO_CH2_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH2(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH3_MASK            (0x8U)
#define GTM_gtm_cls3_TIO3_CO_CH3_SHIFT           (3U)
#define GTM_gtm_cls3_TIO3_CO_CH3_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH3(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH4_MASK            (0x10U)
#define GTM_gtm_cls3_TIO3_CO_CH4_SHIFT           (4U)
#define GTM_gtm_cls3_TIO3_CO_CH4_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH4(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH5_MASK            (0x20U)
#define GTM_gtm_cls3_TIO3_CO_CH5_SHIFT           (5U)
#define GTM_gtm_cls3_TIO3_CO_CH5_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH5(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH6_MASK            (0x40U)
#define GTM_gtm_cls3_TIO3_CO_CH6_SHIFT           (6U)
#define GTM_gtm_cls3_TIO3_CO_CH6_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH6(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CO_CH7_MASK            (0x80U)
#define GTM_gtm_cls3_TIO3_CO_CH7_SHIFT           (7U)
#define GTM_gtm_cls3_TIO3_CO_CH7_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_CO_CH7(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CO_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CO_CH7_MASK)
/*! @} */

/*! @name TIO3_CENDIS - TIO[i] disable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CENDIS_CH0_MASK        (0x1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH0_SHIFT       (0U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH0_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH0(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH1_MASK        (0x2U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH1_SHIFT       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH1_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH1(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH2_MASK        (0x4U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH2_SHIFT       (2U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH2_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH2(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH3_MASK        (0x8U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH3_SHIFT       (3U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH3_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH3(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH4_MASK        (0x10U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH4_SHIFT       (4U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH4_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH4(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH5_MASK        (0x20U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH5_SHIFT       (5U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH5_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH5(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH6_MASK        (0x40U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH6_SHIFT       (6U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH6_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH6(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CENDIS_CH7_MASK        (0x80U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH7_SHIFT       (7U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH7_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_CENDIS_CH7(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CENDIS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CENDIS_CH7_MASK)
/*! @} */

/*! @name TIO3_CINVERT - TIO[i] clear signal invert register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CINVERT_CH0_MASK       (0x1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH0_SHIFT      (0U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH0_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH0(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH1_MASK       (0x2U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH1_SHIFT      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH1_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH1(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH2_MASK       (0x4U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH2_SHIFT      (2U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH2_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH2(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH3_MASK       (0x8U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH3_SHIFT      (3U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH3_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH3(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH4_MASK       (0x10U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH4_SHIFT      (4U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH4_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH4(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH5_MASK       (0x20U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH5_SHIFT      (5U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH5_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH5(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH6_MASK       (0x40U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH6_SHIFT      (6U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH6_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH6(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CINVERT_CH7_MASK       (0x80U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH7_SHIFT      (7U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH7_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_CINVERT_CH7(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINVERT_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CINVERT_CH7_MASK)
/*! @} */

/*! @name TIO3_CINPUT_MODE - TIO[i] disable input mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH0_MASK   (0x1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH0_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH0_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH0(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH1_MASK   (0x2U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH1_SHIFT  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH1_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH1(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH2_MASK   (0x4U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH2_SHIFT  (2U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH2_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH2(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH3_MASK   (0x8U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH3_SHIFT  (3U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH3_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH3(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH4_MASK   (0x10U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH4_SHIFT  (4U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH4_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH4(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH5_MASK   (0x20U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH5_SHIFT  (5U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH5_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH5(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH6_MASK   (0x40U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH6_SHIFT  (6U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH6_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH6(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH7_MASK   (0x80U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH7_SHIFT  (7U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH7_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_CINPUT_MODE_CH7(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CINPUT_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CINPUT_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_CCYCLIC_MODE - TIO[i] disable cyclic mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH0_MASK  (0x1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH1_MASK  (0x2U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH2_MASK  (0x4U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH3_MASK  (0x8U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH4_MASK  (0x10U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH5_MASK  (0x20U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH6_MASK  (0x40U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH7_MASK  (0x80U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CCYCLIC_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_CTRIG_OUT_GATE_EN - TIO[i] clear Trigger Output, output gating register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH0_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH1_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH2_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH3_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH4_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH5_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH6_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH7_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CTRIG_OUT_GATE_EN_CH7_MASK)
/*! @} */

/*! @name TIO3_CPLTRIG_OUT_GATE_EN - TIO[i] clear PL_TRIG_OUT output gating register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH0_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH0_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH1_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH1_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH2_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH2_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH3_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH3_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH4_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH4_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH5_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH5_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH6_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH6_MASK)

#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH7_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_CPLTRIG_OUT_GATE_EN_CH7_MASK)
/*! @} */

/*! @name TIO3_SS - TIO[i] set signal sampling register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SS_CH0_MASK            (0x1U)
#define GTM_gtm_cls3_TIO3_SS_CH0_SHIFT           (0U)
#define GTM_gtm_cls3_TIO3_SS_CH0_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH0(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH1_MASK            (0x2U)
#define GTM_gtm_cls3_TIO3_SS_CH1_SHIFT           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH1_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH1(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH2_MASK            (0x4U)
#define GTM_gtm_cls3_TIO3_SS_CH2_SHIFT           (2U)
#define GTM_gtm_cls3_TIO3_SS_CH2_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH2(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH3_MASK            (0x8U)
#define GTM_gtm_cls3_TIO3_SS_CH3_SHIFT           (3U)
#define GTM_gtm_cls3_TIO3_SS_CH3_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH3(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH4_MASK            (0x10U)
#define GTM_gtm_cls3_TIO3_SS_CH4_SHIFT           (4U)
#define GTM_gtm_cls3_TIO3_SS_CH4_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH4(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH5_MASK            (0x20U)
#define GTM_gtm_cls3_TIO3_SS_CH5_SHIFT           (5U)
#define GTM_gtm_cls3_TIO3_SS_CH5_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH5(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH6_MASK            (0x40U)
#define GTM_gtm_cls3_TIO3_SS_CH6_SHIFT           (6U)
#define GTM_gtm_cls3_TIO3_SS_CH6_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH6(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SS_CH7_MASK            (0x80U)
#define GTM_gtm_cls3_TIO3_SS_CH7_SHIFT           (7U)
#define GTM_gtm_cls3_TIO3_SS_CH7_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SS_CH7(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SS_CH7_MASK)
/*! @} */

/*! @name TIO3_SO - TIO[i] set output register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SO_CH0_MASK            (0x1U)
#define GTM_gtm_cls3_TIO3_SO_CH0_SHIFT           (0U)
#define GTM_gtm_cls3_TIO3_SO_CH0_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH0(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH1_MASK            (0x2U)
#define GTM_gtm_cls3_TIO3_SO_CH1_SHIFT           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH1_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH1(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH2_MASK            (0x4U)
#define GTM_gtm_cls3_TIO3_SO_CH2_SHIFT           (2U)
#define GTM_gtm_cls3_TIO3_SO_CH2_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH2(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH3_MASK            (0x8U)
#define GTM_gtm_cls3_TIO3_SO_CH3_SHIFT           (3U)
#define GTM_gtm_cls3_TIO3_SO_CH3_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH3(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH4_MASK            (0x10U)
#define GTM_gtm_cls3_TIO3_SO_CH4_SHIFT           (4U)
#define GTM_gtm_cls3_TIO3_SO_CH4_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH4(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH5_MASK            (0x20U)
#define GTM_gtm_cls3_TIO3_SO_CH5_SHIFT           (5U)
#define GTM_gtm_cls3_TIO3_SO_CH5_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH5(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH6_MASK            (0x40U)
#define GTM_gtm_cls3_TIO3_SO_CH6_SHIFT           (6U)
#define GTM_gtm_cls3_TIO3_SO_CH6_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH6(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SO_CH7_MASK            (0x80U)
#define GTM_gtm_cls3_TIO3_SO_CH7_SHIFT           (7U)
#define GTM_gtm_cls3_TIO3_SO_CH7_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_SO_CH7(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SO_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SO_CH7_MASK)
/*! @} */

/*! @name TIO3_SENDIS - TIO[i] enable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SENDIS_CH0_MASK        (0x1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH0_SHIFT       (0U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH0_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH0(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH1_MASK        (0x2U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH1_SHIFT       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH1_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH1(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH2_MASK        (0x4U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH2_SHIFT       (2U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH2_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH2(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH3_MASK        (0x8U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH3_SHIFT       (3U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH3_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH3(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH4_MASK        (0x10U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH4_SHIFT       (4U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH4_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH4(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH5_MASK        (0x20U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH5_SHIFT       (5U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH5_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH5(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH6_MASK        (0x40U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH6_SHIFT       (6U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH6_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH6(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SENDIS_CH7_MASK        (0x80U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH7_SHIFT       (7U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH7_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_SENDIS_CH7(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SENDIS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SENDIS_CH7_MASK)
/*! @} */

/*! @name TIO3_SINVERT - TIO[i] set signal invert register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SINVERT_CH0_MASK       (0x1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH0_SHIFT      (0U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH0_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH0(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH1_MASK       (0x2U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH1_SHIFT      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH1_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH1(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH2_MASK       (0x4U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH2_SHIFT      (2U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH2_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH2(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH3_MASK       (0x8U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH3_SHIFT      (3U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH3_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH3(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH4_MASK       (0x10U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH4_SHIFT      (4U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH4_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH4(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH5_MASK       (0x20U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH5_SHIFT      (5U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH5_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH5(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH6_MASK       (0x40U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH6_SHIFT      (6U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH6_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH6(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SINVERT_CH7_MASK       (0x80U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH7_SHIFT      (7U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH7_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_SINVERT_CH7(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINVERT_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SINVERT_CH7_MASK)
/*! @} */

/*! @name TIO3_SINPUT_MODE - TIO[i] enable input mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH0_MASK   (0x1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH0_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH0_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH0(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH1_MASK   (0x2U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH1_SHIFT  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH1_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH1(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH2_MASK   (0x4U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH2_SHIFT  (2U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH2_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH2(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH3_MASK   (0x8U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH3_SHIFT  (3U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH3_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH3(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH4_MASK   (0x10U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH4_SHIFT  (4U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH4_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH4(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH5_MASK   (0x20U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH5_SHIFT  (5U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH5_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH5(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH6_MASK   (0x40U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH6_SHIFT  (6U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH6_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH6(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH7_MASK   (0x80U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH7_SHIFT  (7U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH7_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_SINPUT_MODE_CH7(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SINPUT_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SINPUT_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_SCYCLIC_MODE - TIO[i] enable cyclic mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH0_MASK  (0x1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH1_MASK  (0x2U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH2_MASK  (0x4U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH3_MASK  (0x8U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH4_MASK  (0x10U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH5_MASK  (0x20U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH6_MASK  (0x40U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH7_MASK  (0x80U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SCYCLIC_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_STRIG_OUT_GATE_EN - TIO[i] set Trigger Output, output gating register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH0_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH0_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH1_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH1_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH2_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH2_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH3_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH3_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH4_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH4_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH5_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH5_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH6_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH6_MASK)

#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH7_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_STRIG_OUT_GATE_EN_CH7_MASK)
/*! @} */

/*! @name TIO3_SPLTRIG_OUT_GATE_EN - TIO[i] set PL_TRIG_OUT output gating register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH0_MASK (0x1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH0_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH1_MASK (0x2U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH1_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH2_MASK (0x4U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH2_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH3_MASK (0x8U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH3_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH4_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH4_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH5_MASK (0x20U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH5_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH6_MASK (0x40U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH6_MASK)

#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH7_MASK (0x80U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_SPLTRIG_OUT_GATE_EN_CH7_MASK)
/*! @} */

/*! @name TIO3_IS - TIO[i] invert signal sampling register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_IS_CH0_MASK            (0x1U)
#define GTM_gtm_cls3_TIO3_IS_CH0_SHIFT           (0U)
#define GTM_gtm_cls3_TIO3_IS_CH0_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH0(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH1_MASK            (0x2U)
#define GTM_gtm_cls3_TIO3_IS_CH1_SHIFT           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH1_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH1(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH2_MASK            (0x4U)
#define GTM_gtm_cls3_TIO3_IS_CH2_SHIFT           (2U)
#define GTM_gtm_cls3_TIO3_IS_CH2_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH2(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH3_MASK            (0x8U)
#define GTM_gtm_cls3_TIO3_IS_CH3_SHIFT           (3U)
#define GTM_gtm_cls3_TIO3_IS_CH3_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH3(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH4_MASK            (0x10U)
#define GTM_gtm_cls3_TIO3_IS_CH4_SHIFT           (4U)
#define GTM_gtm_cls3_TIO3_IS_CH4_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH4(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH5_MASK            (0x20U)
#define GTM_gtm_cls3_TIO3_IS_CH5_SHIFT           (5U)
#define GTM_gtm_cls3_TIO3_IS_CH5_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH5(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH6_MASK            (0x40U)
#define GTM_gtm_cls3_TIO3_IS_CH6_SHIFT           (6U)
#define GTM_gtm_cls3_TIO3_IS_CH6_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH6(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_IS_CH7_MASK            (0x80U)
#define GTM_gtm_cls3_TIO3_IS_CH7_SHIFT           (7U)
#define GTM_gtm_cls3_TIO3_IS_CH7_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IS_CH7(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_IS_CH7_MASK)
/*! @} */

/*! @name TIO3_IO - TIO[i] invert output register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_IO_CH0_MASK            (0x1U)
#define GTM_gtm_cls3_TIO3_IO_CH0_SHIFT           (0U)
#define GTM_gtm_cls3_TIO3_IO_CH0_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH0(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH0_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH1_MASK            (0x2U)
#define GTM_gtm_cls3_TIO3_IO_CH1_SHIFT           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH1_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH1(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH1_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH2_MASK            (0x4U)
#define GTM_gtm_cls3_TIO3_IO_CH2_SHIFT           (2U)
#define GTM_gtm_cls3_TIO3_IO_CH2_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH2(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH2_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH3_MASK            (0x8U)
#define GTM_gtm_cls3_TIO3_IO_CH3_SHIFT           (3U)
#define GTM_gtm_cls3_TIO3_IO_CH3_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH3(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH3_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH4_MASK            (0x10U)
#define GTM_gtm_cls3_TIO3_IO_CH4_SHIFT           (4U)
#define GTM_gtm_cls3_TIO3_IO_CH4_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH4(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH4_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH5_MASK            (0x20U)
#define GTM_gtm_cls3_TIO3_IO_CH5_SHIFT           (5U)
#define GTM_gtm_cls3_TIO3_IO_CH5_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH5(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH5_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH6_MASK            (0x40U)
#define GTM_gtm_cls3_TIO3_IO_CH6_SHIFT           (6U)
#define GTM_gtm_cls3_TIO3_IO_CH6_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH6(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH6_MASK)

#define GTM_gtm_cls3_TIO3_IO_CH7_MASK            (0x80U)
#define GTM_gtm_cls3_TIO3_IO_CH7_SHIFT           (7U)
#define GTM_gtm_cls3_TIO3_IO_CH7_WIDTH           (1U)
#define GTM_gtm_cls3_TIO3_IO_CH7(x)              (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IO_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_IO_CH7_MASK)
/*! @} */

/*! @name TIO3_IENDIS - TIO[i] toggle enable/disable register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_IENDIS_CH0_MASK        (0x1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH0_SHIFT       (0U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH0_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH0(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH0_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH1_MASK        (0x2U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH1_SHIFT       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH1_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH1(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH1_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH2_MASK        (0x4U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH2_SHIFT       (2U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH2_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH2(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH2_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH3_MASK        (0x8U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH3_SHIFT       (3U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH3_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH3(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH3_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH4_MASK        (0x10U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH4_SHIFT       (4U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH4_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH4(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH4_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH5_MASK        (0x20U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH5_SHIFT       (5U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH5_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH5(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH5_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH6_MASK        (0x40U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH6_SHIFT       (6U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH6_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH6(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH6_MASK)

#define GTM_gtm_cls3_TIO3_IENDIS_CH7_MASK        (0x80U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH7_SHIFT       (7U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH7_WIDTH       (1U)
#define GTM_gtm_cls3_TIO3_IENDIS_CH7(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IENDIS_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_IENDIS_CH7_MASK)
/*! @} */

/*! @name TIO3_IINVERT - TIO[i] toggle signal invert register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_IINVERT_CH0_MASK       (0x1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH0_SHIFT      (0U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH0_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH0(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH0_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH1_MASK       (0x2U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH1_SHIFT      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH1_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH1(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH1_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH2_MASK       (0x4U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH2_SHIFT      (2U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH2_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH2(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH2_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH3_MASK       (0x8U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH3_SHIFT      (3U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH3_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH3(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH3_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH4_MASK       (0x10U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH4_SHIFT      (4U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH4_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH4(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH4_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH5_MASK       (0x20U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH5_SHIFT      (5U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH5_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH5(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH5_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH6_MASK       (0x40U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH6_SHIFT      (6U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH6_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH6(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH6_MASK)

#define GTM_gtm_cls3_TIO3_IINVERT_CH7_MASK       (0x80U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH7_SHIFT      (7U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH7_WIDTH      (1U)
#define GTM_gtm_cls3_TIO3_IINVERT_CH7(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINVERT_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_IINVERT_CH7_MASK)
/*! @} */

/*! @name TIO3_IINPUT_MODE - TIO[i] enable input mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH0_MASK   (0x1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH0_SHIFT  (0U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH0_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH0(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH1_MASK   (0x2U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH1_SHIFT  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH1_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH1(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH2_MASK   (0x4U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH2_SHIFT  (2U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH2_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH2(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH3_MASK   (0x8U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH3_SHIFT  (3U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH3_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH3(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH4_MASK   (0x10U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH4_SHIFT  (4U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH4_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH4(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH5_MASK   (0x20U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH5_SHIFT  (5U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH5_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH5(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH6_MASK   (0x40U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH6_SHIFT  (6U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH6_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH6(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH7_MASK   (0x80U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH7_SHIFT  (7U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH7_WIDTH  (1U)
#define GTM_gtm_cls3_TIO3_IINPUT_MODE_CH7(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_IINPUT_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_IINPUT_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_ICYCLIC_MODE - TIO[i] enable cyclic mode register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH0_MASK  (0x1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH0_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH0_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH1_MASK  (0x2U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH1_SHIFT (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH1_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH1_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH2_MASK  (0x4U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH2_SHIFT (2U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH2_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH2_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH3_MASK  (0x8U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH3_SHIFT (3U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH3_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH3_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH4_MASK  (0x10U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH4_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH4_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH4_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH5_MASK  (0x20U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH5_SHIFT (5U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH5_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH5_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH6_MASK  (0x40U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH6_SHIFT (6U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH6_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH6_MASK)

#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH7_MASK  (0x80U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH7_SHIFT (7U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH7_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_ICYCLIC_MODE_CH7_MASK)
/*! @} */

/*! @name TIO3_FUPD - TIO[i] force update register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_FUPD_CH0_MASK          (0x1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH0_SHIFT         (0U)
#define GTM_gtm_cls3_TIO3_FUPD_CH0_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH0(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH0_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH1_MASK          (0x2U)
#define GTM_gtm_cls3_TIO3_FUPD_CH1_SHIFT         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH1_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH1(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH1_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH2_MASK          (0x4U)
#define GTM_gtm_cls3_TIO3_FUPD_CH2_SHIFT         (2U)
#define GTM_gtm_cls3_TIO3_FUPD_CH2_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH2(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH2_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH3_MASK          (0x8U)
#define GTM_gtm_cls3_TIO3_FUPD_CH3_SHIFT         (3U)
#define GTM_gtm_cls3_TIO3_FUPD_CH3_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH3(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH3_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH4_MASK          (0x10U)
#define GTM_gtm_cls3_TIO3_FUPD_CH4_SHIFT         (4U)
#define GTM_gtm_cls3_TIO3_FUPD_CH4_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH4(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH4_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH5_MASK          (0x20U)
#define GTM_gtm_cls3_TIO3_FUPD_CH5_SHIFT         (5U)
#define GTM_gtm_cls3_TIO3_FUPD_CH5_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH5(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH5_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH6_MASK          (0x40U)
#define GTM_gtm_cls3_TIO3_FUPD_CH6_SHIFT         (6U)
#define GTM_gtm_cls3_TIO3_FUPD_CH6_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH6(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH6_MASK)

#define GTM_gtm_cls3_TIO3_FUPD_CH7_MASK          (0x80U)
#define GTM_gtm_cls3_TIO3_FUPD_CH7_SHIFT         (7U)
#define GTM_gtm_cls3_TIO3_FUPD_CH7_WIDTH         (1U)
#define GTM_gtm_cls3_TIO3_FUPD_CH7(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_FUPD_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_FUPD_CH7_MASK)
/*! @} */

/*! @name TIO3_HW_CONF - TIO[i] configuration register */
/*! @{ */

#define GTM_gtm_cls3_TIO3_HW_CONF_NTIO_CH8_MASK  (0x3U)
#define GTM_gtm_cls3_TIO3_HW_CONF_NTIO_CH8_SHIFT (0U)
#define GTM_gtm_cls3_TIO3_HW_CONF_NTIO_CH8_WIDTH (2U)
#define GTM_gtm_cls3_TIO3_HW_CONF_NTIO_CH8(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_HW_CONF_NTIO_CH8_SHIFT)) & GTM_gtm_cls3_TIO3_HW_CONF_NTIO_CH8_MASK)

#define GTM_gtm_cls3_TIO3_HW_CONF_TIO_PLUS_MASK  (0x10U)
#define GTM_gtm_cls3_TIO3_HW_CONF_TIO_PLUS_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_HW_CONF_TIO_PLUS_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_HW_CONF_TIO_PLUS(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_HW_CONF_TIO_PLUS_SHIFT)) & GTM_gtm_cls3_TIO3_HW_CONF_TIO_PLUS_MASK)
/*! @} */

/*! @name TIO3_RSEL_CTRL1 - TIO[i] resource selection control register 1 */
/*! @{ */

#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN6_0_MASK (0x1000000U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN6_0_SHIFT (24U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN6_0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN6_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN6_0_SHIFT)) & GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN6_0_MASK)

#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN7_0_MASK (0x10000000U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN7_0_SHIFT (28U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN7_0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN7_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN7_0_SHIFT)) & GTM_gtm_cls3_TIO3_RSEL_CTRL1_SEL_CLKEN7_0_MASK)
/*! @} */

/*! @name TIO3_RSEL_CTRL2 - TIO[i] resource selection control register 2 */
/*! @{ */

#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB1_0_MASK (0x10U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB1_0_SHIFT (4U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB1_0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB1_0_SHIFT)) & GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB1_0_MASK)

#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB2_0_MASK (0x100U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB2_0_SHIFT (8U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB2_0_WIDTH (1U)
#define GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB2_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB2_0_SHIFT)) & GTM_gtm_cls3_TIO3_RSEL_CTRL2_SEL_TB2_0_MASK)
/*! @} */

/*! @name TIO3_PL_SWRST - TIO[i] software reset for TIO Plus functionality */
/*! @{ */

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH0_MASK      (0x1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH0_SHIFT     (0U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH0_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH0(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH0_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH0_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH1_MASK      (0x2U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH1_SHIFT     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH1_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH1_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH1_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH2_MASK      (0x4U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH2_SHIFT     (2U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH2_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH2_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH2_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH3_MASK      (0x8U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH3_SHIFT     (3U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH3_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH3(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH3_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH3_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH4_MASK      (0x10U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH4_SHIFT     (4U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH4_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH4(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH4_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH4_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH5_MASK      (0x20U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH5_SHIFT     (5U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH5_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH5(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH5_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH5_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH6_MASK      (0x40U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH6_SHIFT     (6U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH6_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH6(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH6_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH6_MASK)

#define GTM_gtm_cls3_TIO3_PL_SWRST_CH7_MASK      (0x80U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH7_SHIFT     (7U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH7_WIDTH     (1U)
#define GTM_gtm_cls3_TIO3_PL_SWRST_CH7(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_TIO3_PL_SWRST_CH7_SHIFT)) & GTM_gtm_cls3_TIO3_PL_SWRST_CH7_MASK)
/*! @} */

/*! @name CCM3_ARP0_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP0_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP0_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP0_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP1_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP1_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP1_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP1_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP2_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP2_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP2_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP2_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP3_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP3_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP3_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP3_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP4_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP4_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP4_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP4_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP5_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP5_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP5_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP5_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP6_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP6_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP6_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP6_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP7_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP7_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP7_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP7_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP8_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP8_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP8_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP8_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_ARP9_CTRL - CCM[i] Address Range Protector [a] Control Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP9_CTRL_ADDR_MASK    (0xFFFFU)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_ADDR_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_ADDR_WIDTH   (16U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_CTRL_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_CTRL_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_CTRL_SIZE_MASK    (0xF0000U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_SIZE_SHIFT   (16U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_SIZE_WIDTH   (4U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_CTRL_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_CTRL_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_CTRL_DIS_PROT_MASK (0x1000000U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_DIS_PROT_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_DIS_PROT_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_DIS_PROT(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_CTRL_DIS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_CTRL_DIS_PROT_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_CTRL_WPROT_AEI_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_WPROT_AEI_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_WPROT_AEI_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_CTRL_WPROT_AEI(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_CTRL_WPROT_AEI_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_CTRL_WPROT_AEI_MASK)
/*! @} */

/*! @name CCM3_ARP9_PROT - CCM[i] Address Range Protector [a] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT0_MASK  (0x1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT0_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT0_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT1_MASK  (0x2U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT1_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT1_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT2_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT2_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT2_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT3_MASK  (0x8U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT3_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT3_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT4_MASK  (0x10U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT4(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT4_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT4_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT5_MASK  (0x20U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT5(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT5_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT5_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT6_MASK  (0x40U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT6(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT6_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT6_MASK)

#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT7_MASK  (0x80U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT7(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT7_SHIFT)) & GTM_gtm_cls3_CCM3_ARP9_PROT_WPROT7_MASK)
/*! @} */

/*! @name CCM3_TIO_G0_OUT - CCM[i] TIO Group 0,1 Output Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT0_MASK (0x1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT0_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT0_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT1_MASK (0x2U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT1_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT1_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT2_MASK (0x4U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT2_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT2_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT3_MASK (0x8U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT3_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT3_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT4_MASK (0x10U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT4_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT4_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT5_MASK (0x20U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT5_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT5_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT6_MASK (0x40U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT6_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT6_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT7_MASK (0x80U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT7_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT7_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N0_MASK (0x10000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N0_SHIFT (16U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N0_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N0_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N1_MASK (0x20000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N1_SHIFT (17U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N1_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N1_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N2_MASK (0x40000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N2_SHIFT (18U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N2_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N2_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N3_MASK (0x80000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N3_SHIFT (19U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N3_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N3_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N4_MASK (0x100000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N4_SHIFT (20U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N4_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N4_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N5_MASK (0x200000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N5_SHIFT (21U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N5_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N5_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N6_MASK (0x400000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N6_SHIFT (22U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N6_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N6_MASK)

#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N7_MASK (0x800000U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N7_SHIFT (23U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N7_SHIFT)) & GTM_gtm_cls3_CCM3_TIO_G0_OUT_TIO_G0_OUT_N7_MASK)
/*! @} */

/*! @name CCM3_HW_CONF2 - CCM[i] 2. Hardware Configuration Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_ID_WIDTH_MASK (0x1FU)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_ID_WIDTH_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_ID_WIDTH_WIDTH (5U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_ID_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_ID_WIDTH_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_ID_WIDTH_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_PRIV_ACC_MASK (0x20U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_PRIV_ACC_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_PRIV_ACC_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_PRIV_ACC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_PRIV_ACC_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_PRIV_ACC_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_SEC_ACC_MASK (0x40U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_SEC_ACC_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_SEC_ACC_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_SEC_ACC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_SEC_ACC_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_SEC_ACC_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_POSTED_WRITE_MASK (0x80U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_POSTED_WRITE_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_POSTED_WRITE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_POSTED_WRITE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_POSTED_WRITE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_POSTED_WRITE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF2_TIO_OUT_RST_MASK (0x200U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_TIO_OUT_RST_SHIFT (9U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_TIO_OUT_RST_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_TIO_OUT_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_TIO_OUT_RST_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_TIO_OUT_RST_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIS_DATA_SIZE_MASK (0x10000U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIS_DATA_SIZE_SHIFT (16U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIS_DATA_SIZE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIS_DATA_SIZE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_AXIS_DATA_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_AXIS_DATA_SIZE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_DATA_SIZE_MASK (0x40000U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_DATA_SIZE_SHIFT (18U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_DATA_SIZE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_DATA_SIZE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_DATA_SIZE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF2_AXIM_DATA_SIZE_MASK)
/*! @} */

/*! @name CCM3_AEIM_STA - CCM[i] MCS Bus Master Status Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_ADDR_MASK (0xFFFFU)
#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_ADDR_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_ADDR_WIDTH (16U)
#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_ADDR_SHIFT)) & GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_ADDR_MASK)

#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_STA_MASK (0x3000000U)
#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_STA_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_STA_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_STA(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_STA_SHIFT)) & GTM_gtm_cls3_CCM3_AEIM_STA_AEIM_XPT_STA_MASK)
/*! @} */

/*! @name CCM3_HW_CONF - CCM[i] Hardware Configuration Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_HW_CONF_GRSTEN_MASK    (0x1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_GRSTEN_SHIFT   (0U)
#define GTM_gtm_cls3_CCM3_HW_CONF_GRSTEN_WIDTH   (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_GRSTEN(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_GRSTEN_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_GRSTEN_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_BRIDGE_MODE_RST_MASK (0x2U)
#define GTM_gtm_cls3_CCM3_HW_CONF_BRIDGE_MODE_RST_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_BRIDGE_MODE_RST_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_BRIDGE_MODE_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_BRIDGE_MODE_RST_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_BRIDGE_MODE_RST_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_SYNC_INPUT_REG_MASK (0x4U)
#define GTM_gtm_cls3_CCM3_HW_CONF_SYNC_INPUT_REG_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_HW_CONF_SYNC_INPUT_REG_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_SYNC_INPUT_REG(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_SYNC_INPUT_REG_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_SYNC_INPUT_REG_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_CFG_CLOCK_RATE_MASK (0x8U)
#define GTM_gtm_cls3_CCM3_HW_CONF_CFG_CLOCK_RATE_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_HW_CONF_CFG_CLOCK_RATE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_CFG_CLOCK_RATE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_CFG_CLOCK_RATE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_CFG_CLOCK_RATE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_OUT_RST_MASK (0x10U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_OUT_RST_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_OUT_RST_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_OUT_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_ATOM_OUT_RST_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_ATOM_OUT_RST_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_CHAIN_MASK (0xE0U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_CHAIN_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_CHAIN_WIDTH (3U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_CHAIN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_CHAIN_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_CHAIN_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_OUT_RST_MASK (0x100U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_OUT_RST_SHIFT (8U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_OUT_RST_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_OUT_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_TOM_OUT_RST_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_TOM_OUT_RST_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_CHAIN_MASK (0xE00U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_CHAIN_SHIFT (9U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_CHAIN_WIDTH (3U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_CHAIN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_CHAIN_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_CHAIN_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_RAM_INIT_RST_MASK (0x1000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_RAM_INIT_RST_SHIFT (12U)
#define GTM_gtm_cls3_CCM3_HW_CONF_RAM_INIT_RST_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_RAM_INIT_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_RAM_INIT_RST_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_RAM_INIT_RST_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_ERM_MASK       (0x2000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ERM_SHIFT      (13U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ERM_WIDTH      (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ERM(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_ERM_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_ERM_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_RESET_ACTIVE_MASK (0x8000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_RESET_ACTIVE_SHIFT (15U)
#define GTM_gtm_cls3_CCM3_HW_CONF_RESET_ACTIVE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_RESET_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_RESET_ACTIVE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_RESET_ACTIVE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_LEVEL_MASK (0x10000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_LEVEL_SHIFT (16U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_LEVEL_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_LEVEL_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_LEVEL_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_MASK (0x20000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_SHIFT (17U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_NOTIFY_MASK (0x40000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_NOTIFY_SHIFT (18U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_NOTIFY_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_NOTIFY(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_NOTIFY_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_PULSE_NOTIFY_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_SINGLE_PULSE_MASK (0x80000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_SINGLE_PULSE_SHIFT (19U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_SINGLE_PULSE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_SINGLE_PULSE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_SINGLE_PULSE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_IRQ_MODE_SINGLE_PULSE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_INTCHAIN_MASK (0xF00000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_INTCHAIN_SHIFT (20U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_INTCHAIN_WIDTH (4U)
#define GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_INTCHAIN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_INTCHAIN_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_ATOM_TRIG_INTCHAIN_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_INTCHAIN_MASK (0x1F000000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_INTCHAIN_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_INTCHAIN_WIDTH (5U)
#define GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_INTCHAIN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_INTCHAIN_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_TOM_TRIG_INTCHAIN_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_INT_CLK_EN_GEN_MASK (0x20000000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_INT_CLK_EN_GEN_SHIFT (29U)
#define GTM_gtm_cls3_CCM3_HW_CONF_INT_CLK_EN_GEN_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_INT_CLK_EN_GEN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_INT_CLK_EN_GEN_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_INT_CLK_EN_GEN_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_ADDR_PIPELINE_STAGE_MASK (0x40000000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_ADDR_PIPELINE_STAGE_SHIFT (30U)
#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_ADDR_PIPELINE_STAGE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_ADDR_PIPELINE_STAGE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_AEI_ADDR_PIPELINE_STAGE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_AEI_ADDR_PIPELINE_STAGE_MASK)

#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_RDATA_PIPELINE_STAGE_MASK (0x80000000U)
#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_RDATA_PIPELINE_STAGE_SHIFT (31U)
#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_RDATA_PIPELINE_STAGE_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_HW_CONF_AEI_RDATA_PIPELINE_STAGE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_HW_CONF_AEI_RDATA_PIPELINE_STAGE_SHIFT)) & GTM_gtm_cls3_CCM3_HW_CONF_AEI_RDATA_PIPELINE_STAGE_MASK)
/*! @} */

/*! @name CCM3_ATOM_OUT - CCM[i] ATOM Output Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT0_MASK (0x1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT0_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT0_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT0_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT1_MASK (0x2U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT1_SHIFT (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT1_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT1_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT2_MASK (0x4U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT2_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT2_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT2_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT3_MASK (0x8U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT3_SHIFT (3U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT3_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT3_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT4_MASK (0x10U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT4_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT4_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT4_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT5_MASK (0x20U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT5_SHIFT (5U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT5_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT5_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT6_MASK (0x40U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT6_SHIFT (6U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT6_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT6_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT7_MASK (0x80U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT7_SHIFT (7U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT7_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT7_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N0_MASK (0x100U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N0_SHIFT (8U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N0_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N0_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N0_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N1_MASK (0x200U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N1_SHIFT (9U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N1_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N1_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N1_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N2_MASK (0x400U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N2_SHIFT (10U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N2_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N2_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N2_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N3_MASK (0x800U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N3_SHIFT (11U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N3_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N3_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N3_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N4_MASK (0x1000U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N4_SHIFT (12U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N4_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N4(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N4_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N4_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N5_MASK (0x2000U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N5_SHIFT (13U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N5_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N5(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N5_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N5_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N6_MASK (0x4000U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N6_SHIFT (14U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N6_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N6(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N6_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N6_MASK)

#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N7_MASK (0x8000U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N7_SHIFT (15U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N7_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N7(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N7_SHIFT)) & GTM_gtm_cls3_CCM3_ATOM_OUT_ATOM_I_OUT_N7_MASK)
/*! @} */

/*! @name CCM3_CMU_CLK_CFG - CCM[i] CMU Clock Configuration Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK0_SRC_MASK (0x3U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK0_SRC_SHIFT (0U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK0_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK0_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK0_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK0_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK1_SRC_MASK (0x30U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK1_SRC_SHIFT (4U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK1_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK1_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK1_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK1_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK2_SRC_MASK (0x300U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK2_SRC_SHIFT (8U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK2_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK2_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK2_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK2_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK3_SRC_MASK (0x3000U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK3_SRC_SHIFT (12U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK3_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK3_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK3_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK3_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK4_SRC_MASK (0x30000U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK4_SRC_SHIFT (16U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK4_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK4_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK4_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK4_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK5_SRC_MASK (0x300000U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK5_SRC_SHIFT (20U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK5_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK5_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK5_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK5_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK6_SRC_MASK (0x3000000U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK6_SRC_SHIFT (24U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK6_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK6_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK6_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK6_SRC_MASK)

#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK7_SRC_MASK (0x30000000U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK7_SRC_SHIFT (28U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK7_SRC_WIDTH (2U)
#define GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK7_SRC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK7_SRC_SHIFT)) & GTM_gtm_cls3_CCM3_CMU_CLK_CFG_CLK7_SRC_MASK)
/*! @} */

/*! @name CCM3_CFG - CCM[i] Configuration Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_CFG_EN_ATOM_ADTM_MASK  (0x4U)
#define GTM_gtm_cls3_CCM3_CFG_EN_ATOM_ADTM_SHIFT (2U)
#define GTM_gtm_cls3_CCM3_CFG_EN_ATOM_ADTM_WIDTH (1U)
#define GTM_gtm_cls3_CCM3_CFG_EN_ATOM_ADTM(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CFG_EN_ATOM_ADTM_SHIFT)) & GTM_gtm_cls3_CCM3_CFG_EN_ATOM_ADTM_MASK)

#define GTM_gtm_cls3_CCM3_CFG_EN_MCS_MASK        (0x8U)
#define GTM_gtm_cls3_CCM3_CFG_EN_MCS_SHIFT       (3U)
#define GTM_gtm_cls3_CCM3_CFG_EN_MCS_WIDTH       (1U)
#define GTM_gtm_cls3_CCM3_CFG_EN_MCS(x)          (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CFG_EN_MCS_SHIFT)) & GTM_gtm_cls3_CCM3_CFG_EN_MCS_MASK)

#define GTM_gtm_cls3_CCM3_CFG_EN_TIO_DTM_MASK    (0x100U)
#define GTM_gtm_cls3_CCM3_CFG_EN_TIO_DTM_SHIFT   (8U)
#define GTM_gtm_cls3_CCM3_CFG_EN_TIO_DTM_WIDTH   (1U)
#define GTM_gtm_cls3_CCM3_CFG_EN_TIO_DTM(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CFG_EN_TIO_DTM_SHIFT)) & GTM_gtm_cls3_CCM3_CFG_EN_TIO_DTM_MASK)

#define GTM_gtm_cls3_CCM3_CFG_CLS_CLK_DIV_MASK   (0x30000U)
#define GTM_gtm_cls3_CCM3_CFG_CLS_CLK_DIV_SHIFT  (16U)
#define GTM_gtm_cls3_CCM3_CFG_CLS_CLK_DIV_WIDTH  (2U)
#define GTM_gtm_cls3_CCM3_CFG_CLS_CLK_DIV(x)     (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CFG_CLS_CLK_DIV_SHIFT)) & GTM_gtm_cls3_CCM3_CFG_CLS_CLK_DIV_MASK)

#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR1_MASK      (0x40000000U)
#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR1_SHIFT     (30U)
#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR1_WIDTH     (1U)
#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR1(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CFG_TBU_DIR1_SHIFT)) & GTM_gtm_cls3_CCM3_CFG_TBU_DIR1_MASK)

#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR2_MASK      (0x80000000U)
#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR2_SHIFT     (31U)
#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR2_WIDTH     (1U)
#define GTM_gtm_cls3_CCM3_CFG_TBU_DIR2(x)        (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_CFG_TBU_DIR2_SHIFT)) & GTM_gtm_cls3_CCM3_CFG_TBU_DIR2_MASK)
/*! @} */

/*! @name CCM3_PROT - CCM[i] Protection Register */
/*! @{ */

#define GTM_gtm_cls3_CCM3_PROT_CLS_PROT_MASK     (0x1U)
#define GTM_gtm_cls3_CCM3_PROT_CLS_PROT_SHIFT    (0U)
#define GTM_gtm_cls3_CCM3_PROT_CLS_PROT_WIDTH    (1U)
#define GTM_gtm_cls3_CCM3_PROT_CLS_PROT(x)       (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CCM3_PROT_CLS_PROT_SHIFT)) & GTM_gtm_cls3_CCM3_PROT_CLS_PROT_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CTRL - CDTM[i]_DTM[d] global configuration and control register */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CLK_SEL_MASK (0x3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CLK_SEL_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CLK_SEL_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL_CLK_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL_CLK_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_DTM_SEL_MASK (0xCU)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_DTM_SEL_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_DTM_SEL_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_DTM_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL_DTM_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL_DTM_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_UPD_MODE_MASK (0x70U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_UPD_MODE_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_UPD_MODE_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_UPD_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL_UPD_MODE_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL_UPD_MODE_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CH_SHUTOFF_EN_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CH_SHUTOFF_EN_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CH_SHUTOFF_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_CH_SHUTOFF_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL_CH_SHUTOFF_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL_CH_SHUTOFF_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SR_UPD_EN_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SR_UPD_EN_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SR_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SR_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL_SR_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL_SR_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SHUT_OFF_RST_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SHUT_OFF_RST_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SHUT_OFF_RST_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL_SHUT_OFF_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL_SHUT_OFF_RST_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL_SHUT_OFF_RST_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH_CTRL1 - CDTM[i]_DTM[d] channel control register 1 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_0_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_0_MASK (0x30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_0_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_0_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_0_1_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_0_1_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_1_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_1_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_1_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_1_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_1_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_1_MASK (0x3000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_1_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_1_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_2_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_2_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_2_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_2_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_2_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_2_MASK (0x300000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_2_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_2_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_2_3_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_2_3_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_2_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_2_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_2_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_XDT_EN_2_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_3_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1SEL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_3_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_3_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_I1SEL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_3_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_3_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SH_EN_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_SWAP_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_3_MASK (0x30000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_3_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_3_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL1_O1F_3_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH_CTRL2 - CDTM[i]_DTM[d] channel control register 2 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_0_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_0_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_0_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_0_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_0_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_0_MASK (0x10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_0_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_0_MASK (0x20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_0_SHIFT (5U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_0_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_0_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_0_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_0_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_1_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_1_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_1_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_1_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_1_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_1_MASK (0x1000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_1_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_1_MASK (0x2000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_1_SHIFT (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_1_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_1_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_2_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_2_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_2_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_2_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_2_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_2_MASK (0x100000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_2_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_2_MASK (0x200000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_2_SHIFT (21U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_2_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_2_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_2_MASK (0x800000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_2_SHIFT (23U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_3_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_3_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_3_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_3_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_3_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_3_MASK (0x10000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_3_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_POL1_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_3_MASK (0x20000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_3_SHIFT (29U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_OC1_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_3_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_3_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SL1_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_3_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_3_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_DT1_3_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH_CTRL2_SR - CDTM[i] DTM[j] channel control register 2 shadow */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_0_SR_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_0_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_0_SR_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_0_SR_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_0_SR_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_0_SR_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_0_SR_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_0_SR_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_0_SR_MASK (0x10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_0_SR_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_0_SR_MASK (0x20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_0_SR_SHIFT (5U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_0_SR_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_0_SR_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_0_SR_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_0_SR_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_1_SR_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_1_SR_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_1_SR_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_1_SR_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_1_SR_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_1_SR_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_1_SR_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_1_SR_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_1_SR_MASK (0x1000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_1_SR_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_1_SR_MASK (0x2000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_1_SR_SHIFT (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_1_SR_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_1_SR_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_1_SR_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_1_SR_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_2_SR_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_2_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_2_SR_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_2_SR_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_2_SR_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_2_SR_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_2_SR_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_2_SR_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_2_SR_MASK (0x100000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_2_SR_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_2_SR_MASK (0x200000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_2_SR_SHIFT (21U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_2_SR_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_2_SR_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_2_SR_MASK (0x800000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_2_SR_SHIFT (23U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_3_SR_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_3_SR_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_3_SR_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_3_SR_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_3_SR_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_3_SR_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_3_SR_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_3_SR_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_3_SR_MASK (0x10000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_3_SR_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_POL1_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_3_SR_MASK (0x20000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_3_SR_SHIFT (29U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_OC1_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_3_SR_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_3_SR_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_SL1_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_3_SR_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_3_SR_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL2_SR_DT1_3_SR_MASK)
/*! @} */

/*! @name CDTM3_DTM4_PS_CTRL - CDTM[i]_DTM[d] phase shift unit configuration and control register */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_RELBLK_MASK (0x3FFU)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_RELBLK_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_RELBLK_WIDTH (10U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_RELBLK(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_RELBLK_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_RELBLK_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_PSU_IN_SEL_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_PSU_IN_SEL_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_PSU_IN_SEL_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_PSU_IN_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_PSU_IN_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_PSU_IN_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_IN_POL_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_IN_POL_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_IN_POL_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_IN_POL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_IN_POL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_IN_POL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_TIM_SEL_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_TIM_SEL_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_TIM_SEL_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_TIM_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_TIM_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_TIM_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_SHIFT_SEL_MASK (0x300000U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_SHIFT_SEL_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_SHIFT_SEL_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_SHIFT_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_SHIFT_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_PS_CTRL_SHIFT_SEL_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH_DTV - CDTM[i]_DTM[d] channel [x] dead time reload values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELRISE_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELRISE_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELRISE_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELRISE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELRISE_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELRISE_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELFALL_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELFALL_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELFALL_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELFALL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELFALL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_DTV_RELFALL_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH_SR - CDTM[i]_DTM[d] channel shadow register */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_0_SR_SR_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_0_SR_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_0_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_0_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_0_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_0_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_0_SR_SR_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_0_SR_SR_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_0_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_0_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_0_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_0_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_1_SR_SR_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_1_SR_SR_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_1_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_1_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_1_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_1_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_1_SR_SR_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_1_SR_SR_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_1_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_1_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_1_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_1_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_2_SR_SR_MASK (0x10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_2_SR_SR_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_2_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_2_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_2_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_2_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_2_SR_SR_MASK (0x20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_2_SR_SR_SHIFT (5U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_2_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_2_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_2_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_2_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_3_SR_SR_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_3_SR_SR_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_3_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_3_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_3_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL0_3_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_3_SR_SR_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_3_SR_SR_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_3_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_3_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_3_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_SR_SL1_3_SR_SR_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH_CTRL3 - CDTM[i]_DTM[d] channel control register 3 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII0_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS0_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS0_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_0_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_0_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII1_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS1_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS1_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_1_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_1_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII2_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS2_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS2_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_2_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_2_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII3_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CII3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS3_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS3_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_CIS3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_3_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_3_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH_CTRL3_TSEL1_3_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CTRL2 - CDTM[i]_DTM[d] global configuration and control register 2 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_0_MASK (0x7U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_0_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_0_MASK (0x30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_0_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_0_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_0_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_0_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_0_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_0_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_1_MASK (0x700U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_1_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_1_MASK (0x3000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_1_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_1_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_1_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_1_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_2_MASK (0x70000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_2_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_2_MASK (0x300000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_2_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_2_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_2_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_2_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_2_MASK (0x800000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_2_SHIFT (23U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_3_MASK (0x7000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_3_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_SEL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUTOFF_POL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_3_MASK (0x30000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_3_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_3_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_UPD_MODE_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_3_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_3_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_SHUT_OFF_RST_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_3_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_3_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CTRL2_WR_EN_3_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH0_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH0_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH1_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH1_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH2_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH2_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM4_CH3_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM4_CH3_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CTRL - CDTM[i]_DTM[d] global configuration and control register */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CLK_SEL_MASK (0x3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CLK_SEL_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CLK_SEL_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL_CLK_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL_CLK_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_DTM_SEL_MASK (0xCU)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_DTM_SEL_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_DTM_SEL_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_DTM_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL_DTM_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL_DTM_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_UPD_MODE_MASK (0x70U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_UPD_MODE_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_UPD_MODE_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_UPD_MODE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL_UPD_MODE_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL_UPD_MODE_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CH_SHUTOFF_EN_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CH_SHUTOFF_EN_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CH_SHUTOFF_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_CH_SHUTOFF_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL_CH_SHUTOFF_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL_CH_SHUTOFF_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SR_UPD_EN_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SR_UPD_EN_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SR_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SR_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL_SR_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL_SR_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SHUT_OFF_RST_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SHUT_OFF_RST_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SHUT_OFF_RST_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL_SHUT_OFF_RST(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL_SHUT_OFF_RST_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL_SHUT_OFF_RST_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH_CTRL1 - CDTM[i]_DTM[d] channel control register 1 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_0_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_0_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_0_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_0_MASK (0x30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_0_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_0_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_0_1_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_0_1_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_1_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_1_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_1_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_1_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_1_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_1_MASK (0x3000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_1_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_1_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_2_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_2_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_2_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_2_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_2_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_2_MASK (0x300000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_2_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_2_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_2_3_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_2_3_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_2_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_2_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_2_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_XDT_EN_2_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_3_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1SEL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_3_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_3_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_I1SEL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_3_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_3_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SH_EN_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_SWAP_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_3_MASK (0x30000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_3_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_3_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL1_O1F_3_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH_CTRL2 - CDTM[i]_DTM[d] channel control register 2 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_0_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_0_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_0_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_0_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_0_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_0_MASK (0x10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_0_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_0_MASK (0x20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_0_SHIFT (5U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_0_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_0_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_0_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_0_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_1_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_1_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_1_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_1_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_1_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_1_MASK (0x1000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_1_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_1_MASK (0x2000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_1_SHIFT (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_1_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_1_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_2_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_2_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_2_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_2_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_2_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_2_MASK (0x100000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_2_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_2_MASK (0x200000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_2_SHIFT (21U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_2_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_2_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_2_MASK (0x800000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_2_SHIFT (23U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_3_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_3_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_3_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_3_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_3_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_3_MASK (0x10000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_3_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_POL1_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_3_MASK (0x20000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_3_SHIFT (29U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_OC1_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_3_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_3_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SL1_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_3_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_3_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_DT1_3_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH_CTRL2_SR - CDTM[i] DTM[j] channel control register 2 shadow */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_0_SR_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_0_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_0_SR_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_0_SR_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_0_SR_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_0_SR_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_0_SR_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_0_SR_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_0_SR_MASK (0x10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_0_SR_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_0_SR_MASK (0x20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_0_SR_SHIFT (5U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_0_SR_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_0_SR_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_0_SR_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_0_SR_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_0_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_0_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_0_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_0_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_1_SR_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_1_SR_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_1_SR_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_1_SR_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_1_SR_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_1_SR_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_1_SR_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_1_SR_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_1_SR_MASK (0x1000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_1_SR_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_1_SR_MASK (0x2000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_1_SR_SHIFT (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_1_SR_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_1_SR_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_1_SR_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_1_SR_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_1_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_1_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_1_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_1_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_2_SR_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_2_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_2_SR_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_2_SR_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_2_SR_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_2_SR_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_2_SR_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_2_SR_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_2_SR_MASK (0x100000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_2_SR_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_2_SR_MASK (0x200000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_2_SR_SHIFT (21U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_2_SR_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_2_SR_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_2_SR_MASK (0x800000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_2_SR_SHIFT (23U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_2_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_2_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_2_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_2_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_3_SR_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_3_SR_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_3_SR_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_3_SR_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_3_SR_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_3_SR_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_3_SR_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_3_SR_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT0_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_3_SR_MASK (0x10000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_3_SR_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_POL1_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_3_SR_MASK (0x20000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_3_SR_SHIFT (29U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_OC1_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_3_SR_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_3_SR_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_SL1_3_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_3_SR_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_3_SR_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_3_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_3_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_3_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL2_SR_DT1_3_SR_MASK)
/*! @} */

/*! @name CDTM3_DTM5_PS_CTRL - CDTM[i]_DTM[d] phase shift unit configuration and control register */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_RELBLK_MASK (0x3FFU)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_RELBLK_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_RELBLK_WIDTH (10U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_RELBLK(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_RELBLK_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_RELBLK_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_PSU_IN_SEL_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_PSU_IN_SEL_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_PSU_IN_SEL_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_PSU_IN_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_PSU_IN_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_PSU_IN_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_IN_POL_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_IN_POL_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_IN_POL_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_IN_POL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_IN_POL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_IN_POL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_TIM_SEL_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_TIM_SEL_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_TIM_SEL_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_TIM_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_TIM_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_TIM_SEL_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_SHIFT_SEL_MASK (0x300000U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_SHIFT_SEL_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_SHIFT_SEL_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_SHIFT_SEL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_SHIFT_SEL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_PS_CTRL_SHIFT_SEL_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH_DTV - CDTM[i]_DTM[d] channel [x] dead time reload values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELRISE_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELRISE_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELRISE_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELRISE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELRISE_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELRISE_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELFALL_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELFALL_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELFALL_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELFALL(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELFALL_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_DTV_RELFALL_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH_SR - CDTM[i]_DTM[d] channel shadow register */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_0_SR_SR_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_0_SR_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_0_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_0_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_0_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_0_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_0_SR_SR_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_0_SR_SR_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_0_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_0_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_0_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_0_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_1_SR_SR_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_1_SR_SR_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_1_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_1_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_1_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_1_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_1_SR_SR_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_1_SR_SR_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_1_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_1_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_1_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_1_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_2_SR_SR_MASK (0x10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_2_SR_SR_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_2_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_2_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_2_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_2_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_2_SR_SR_MASK (0x20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_2_SR_SR_SHIFT (5U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_2_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_2_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_2_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_2_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_3_SR_SR_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_3_SR_SR_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_3_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_3_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_3_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL0_3_SR_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_3_SR_SR_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_3_SR_SR_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_3_SR_SR_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_3_SR_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_3_SR_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_SR_SL1_3_SR_SR_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH_CTRL3 - CDTM[i]_DTM[d] channel control register 3 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII0_MASK (0x1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS0_MASK (0x2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS0_SHIFT (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_0_MASK (0x4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_0_SHIFT (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII1_MASK (0x100U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS1_MASK (0x200U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS1_SHIFT (9U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_1_MASK (0x400U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_1_SHIFT (10U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII2_MASK (0x10000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS2_MASK (0x20000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS2_SHIFT (17U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_2_MASK (0x40000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_2_SHIFT (18U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII3_MASK (0x1000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CII3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS3_MASK (0x2000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS3_SHIFT (25U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_CIS3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_3_MASK (0x4000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_3_SHIFT (26U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL0_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH_CTRL3_TSEL1_3_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CTRL2 - CDTM[i]_DTM[d] global configuration and control register 2 */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_0_MASK (0x7U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_0_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_0_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_0_MASK (0x8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_0_SHIFT (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_0_MASK (0x30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_0_SHIFT (4U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_0_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_0_MASK (0x40U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_0_SHIFT (6U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_0_MASK (0x80U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_0_SHIFT (7U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_0_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_0(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_0_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_0_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_1_MASK (0x700U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_1_SHIFT (8U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_1_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_1_MASK (0x800U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_1_SHIFT (11U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_1_MASK (0x3000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_1_SHIFT (12U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_1_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_1_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_1_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_2_MASK (0x70000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_2_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_2_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_2_MASK (0x80000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_2_SHIFT (19U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_2_MASK (0x300000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_2_SHIFT (20U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_2_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_2_MASK (0x400000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_2_SHIFT (22U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_2_MASK (0x800000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_2_SHIFT (23U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_2_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_2(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_2_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_2_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_3_MASK (0x7000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_3_SHIFT (24U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_3_WIDTH (3U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_SEL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_3_MASK (0x8000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_3_SHIFT (27U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUTOFF_POL_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_3_MASK (0x30000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_3_SHIFT (28U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_3_WIDTH (2U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_UPD_MODE_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_3_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_3_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_SHUT_OFF_RST_3_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_3_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_3_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_3_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_3(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_3_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CTRL2_WR_EN_3_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH0_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH0_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH1_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH1_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH2_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH2_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name CDTM3_DTM5_CH3_DTV_SR - CDTM[i]_DTM[d] channel [x] dead time shadow values */
/*! @{ */

#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_SR_MASK (0x1FFFU)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_SR_SHIFT (0U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_FE0RE1_MASK (0x4000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT (14U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_EN_MASK (0x8000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_EN_SHIFT (15U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELRISE_UPD_EN_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_SR_MASK (0x1FFF0000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_SR_SHIFT (16U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_SR_WIDTH (13U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_SR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_SR_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_SR_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_FE0RE1_MASK (0x40000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT (30U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_FE0RE1_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_FE0RE1(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_FE0RE1_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_FE0RE1_MASK)

#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_EN_MASK (0x80000000U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_EN_SHIFT (31U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_EN_WIDTH (1U)
#define GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_EN(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_EN_SHIFT)) & GTM_gtm_cls3_CDTM3_DTM5_CH3_DTV_SR_RELFALL_UPD_EN_MASK)
/*! @} */

/*! @name AXIM3_FREE - AXIM[i] slot allocation status. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_FREE_FREE0_MASK       (0x1U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE0_SHIFT      (0U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE0_WIDTH      (1U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE0(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_FREE_FREE0_SHIFT)) & GTM_gtm_cls3_AXIM3_FREE_FREE0_MASK)

#define GTM_gtm_cls3_AXIM3_FREE_FREE1_MASK       (0x2U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE1_SHIFT      (1U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE1_WIDTH      (1U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE1(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_FREE_FREE1_SHIFT)) & GTM_gtm_cls3_AXIM3_FREE_FREE1_MASK)

#define GTM_gtm_cls3_AXIM3_FREE_FREE2_MASK       (0x4U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE2_SHIFT      (2U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE2_WIDTH      (1U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE2(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_FREE_FREE2_SHIFT)) & GTM_gtm_cls3_AXIM3_FREE_FREE2_MASK)

#define GTM_gtm_cls3_AXIM3_FREE_FREE3_MASK       (0x8U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE3_SHIFT      (3U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE3_WIDTH      (1U)
#define GTM_gtm_cls3_AXIM3_FREE_FREE3(x)         (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_FREE_FREE3_SHIFT)) & GTM_gtm_cls3_AXIM3_FREE_FREE3_MASK)
/*! @} */

/*! @name AXIM3_REQUEST - AXIM[i] slot request (allocation). */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT0_MASK (0x1U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT0_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT0_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT0(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT0_SHIFT)) & GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT0_MASK)

#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT1_MASK (0x2U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT1_SHIFT (1U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT1_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT1(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT1_SHIFT)) & GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT1_MASK)

#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT2_MASK (0x4U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT2_SHIFT (2U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT2_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT2(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT2_SHIFT)) & GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT2_MASK)

#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT3_MASK (0x8U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT3_SHIFT (3U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT3_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT3(x)   (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT3_SHIFT)) & GTM_gtm_cls3_AXIM3_REQUEST_REQ1HOT3_MASK)

#define GTM_gtm_cls3_AXIM3_REQUEST_REQID_MASK    (0xFF000000U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQID_SHIFT   (24U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQID_WIDTH   (8U)
#define GTM_gtm_cls3_AXIM3_REQUEST_REQID(x)      (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_REQUEST_REQID_SHIFT)) & GTM_gtm_cls3_AXIM3_REQUEST_REQID_MASK)
/*! @} */

/*! @name AXIM3_RELEASE - AXIM[i] slot release (de-allocation). */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ0_MASK  (0x1U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ0_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ0_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ0(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_RELEASE_RELREQ0_SHIFT)) & GTM_gtm_cls3_AXIM3_RELEASE_RELREQ0_MASK)

#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ1_MASK  (0x2U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ1_SHIFT (1U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ1_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ1(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_RELEASE_RELREQ1_SHIFT)) & GTM_gtm_cls3_AXIM3_RELEASE_RELREQ1_MASK)

#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ2_MASK  (0x4U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ2_SHIFT (2U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ2_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ2(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_RELEASE_RELREQ2_SHIFT)) & GTM_gtm_cls3_AXIM3_RELEASE_RELREQ2_MASK)

#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ3_MASK  (0x8U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ3_SHIFT (3U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ3_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_RELEASE_RELREQ3(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_RELEASE_RELREQ3_SHIFT)) & GTM_gtm_cls3_AXIM3_RELEASE_RELREQ3_MASK)
/*! @} */

/*! @name AXIM3_SLOT0_ADDR_LOW - AXIM[i] slot[s] address bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT0_ADDR_LOW_AXI_ADDR_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT0_ADDR_LOW_AXI_ADDR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT0_ADDR_LOW_AXI_ADDR_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT0_ADDR_LOW_AXI_ADDR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_ADDR_LOW_AXI_ADDR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_ADDR_LOW_AXI_ADDR_MASK)
/*! @} */

/*! @name AXIM3_SLOT0_DATA_LOW - AXIM[i] slot[s] data bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT0_DATA_LOW_AXI_DATA_LOW_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT0_DATA_LOW_AXI_DATA_LOW_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT0_DATA_LOW_AXI_DATA_LOW_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT0_DATA_LOW_AXI_DATA_LOW(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_DATA_LOW_AXI_DATA_LOW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_DATA_LOW_AXI_DATA_LOW_MASK)
/*! @} */

/*! @name AXIM3_SLOT0_CFG1 - AXIM[i] slot [s] configuration 1 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_INCR_MASK  (0xFU)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_INCR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_INCR_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_INCR(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AUTO_INCR_MASK (0x10U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AUTO_INCR_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AUTO_INCR_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AUTO_INCR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AUTO_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AUTO_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_PRIO_MASK  (0x60U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_PRIO_SHIFT (5U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_PRIO_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_PRIO(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_PRIO_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_PRIO_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_PROT_MASK (0x3800U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_PROT_SHIFT (11U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_PROT_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_PROT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_PROT_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_PROT_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_CACHE_MASK (0x3C000U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_CACHE_SHIFT (14U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_CACHE_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_CACHE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_CACHE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_CACHE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_LOCK_MASK (0xC0000U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_LOCK_SHIFT (18U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_LOCK_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_LOCK(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_LOCK_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_LOCK_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_SIZE_MASK (0x1C00000U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_SIZE_SHIFT (22U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_SIZE_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_SIZE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_SIZE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_SIZE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_RW_MASK (0x2000000U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_RW_SHIFT (25U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_RW_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_RW(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_RW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG1_AXI_RW_MASK)
/*! @} */

/*! @name AXIM3_SLOT0_CFG2 - AXIM[i] slot[s] configuration 2 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT0_CFG2_AXI_ID_MASK (0xFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG2_AXI_ID_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG2_AXI_ID_WIDTH (16U)
#define GTM_gtm_cls3_AXIM3_SLOT0_CFG2_AXI_ID(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_CFG2_AXI_ID_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_CFG2_AXI_ID_MASK)
/*! @} */

/*! @name AXIM3_SLOT0_STATUS - AXIM[i] slot[s] status */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_ALLOC_MASK (0x1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_ALLOC_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_ALLOC_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_STATUS_ALLOC_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_STATUS_ALLOC_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_QUEUED_MASK (0x2U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_QUEUED_SHIFT (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_QUEUED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_QUEUED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_STATUS_QUEUED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_STATUS_QUEUED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_STARTED_MASK (0x4U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_STARTED_SHIFT (2U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_STARTED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_STARTED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_STATUS_STARTED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_STATUS_STARTED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_READY_MASK (0x8U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_READY_SHIFT (3U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_READY_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_READY(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_STATUS_READY_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_STATUS_READY_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_RESP_MASK (0x30U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_RESP_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_RESP_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT0_STATUS_RESP(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT0_STATUS_RESP_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT0_STATUS_RESP_MASK)
/*! @} */

/*! @name AXIM3_SLOT1_ADDR_LOW - AXIM[i] slot[s] address bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT1_ADDR_LOW_AXI_ADDR_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT1_ADDR_LOW_AXI_ADDR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT1_ADDR_LOW_AXI_ADDR_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT1_ADDR_LOW_AXI_ADDR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_ADDR_LOW_AXI_ADDR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_ADDR_LOW_AXI_ADDR_MASK)
/*! @} */

/*! @name AXIM3_SLOT1_DATA_LOW - AXIM[i] slot[s] data bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT1_DATA_LOW_AXI_DATA_LOW_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT1_DATA_LOW_AXI_DATA_LOW_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT1_DATA_LOW_AXI_DATA_LOW_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT1_DATA_LOW_AXI_DATA_LOW(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_DATA_LOW_AXI_DATA_LOW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_DATA_LOW_AXI_DATA_LOW_MASK)
/*! @} */

/*! @name AXIM3_SLOT1_CFG1 - AXIM[i] slot [s] configuration 1 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_INCR_MASK  (0xFU)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_INCR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_INCR_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_INCR(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AUTO_INCR_MASK (0x10U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AUTO_INCR_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AUTO_INCR_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AUTO_INCR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AUTO_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AUTO_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_PRIO_MASK  (0x60U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_PRIO_SHIFT (5U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_PRIO_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_PRIO(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_PRIO_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_PRIO_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_PROT_MASK (0x3800U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_PROT_SHIFT (11U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_PROT_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_PROT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_PROT_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_PROT_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_CACHE_MASK (0x3C000U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_CACHE_SHIFT (14U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_CACHE_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_CACHE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_CACHE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_CACHE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_LOCK_MASK (0xC0000U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_LOCK_SHIFT (18U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_LOCK_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_LOCK(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_LOCK_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_LOCK_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_SIZE_MASK (0x1C00000U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_SIZE_SHIFT (22U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_SIZE_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_SIZE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_SIZE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_SIZE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_RW_MASK (0x2000000U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_RW_SHIFT (25U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_RW_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_RW(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_RW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG1_AXI_RW_MASK)
/*! @} */

/*! @name AXIM3_SLOT1_CFG2 - AXIM[i] slot[s] configuration 2 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT1_CFG2_AXI_ID_MASK (0xFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG2_AXI_ID_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG2_AXI_ID_WIDTH (16U)
#define GTM_gtm_cls3_AXIM3_SLOT1_CFG2_AXI_ID(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_CFG2_AXI_ID_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_CFG2_AXI_ID_MASK)
/*! @} */

/*! @name AXIM3_SLOT1_STATUS - AXIM[i] slot[s] status */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_ALLOC_MASK (0x1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_ALLOC_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_ALLOC_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_STATUS_ALLOC_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_STATUS_ALLOC_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_QUEUED_MASK (0x2U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_QUEUED_SHIFT (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_QUEUED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_QUEUED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_STATUS_QUEUED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_STATUS_QUEUED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_STARTED_MASK (0x4U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_STARTED_SHIFT (2U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_STARTED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_STARTED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_STATUS_STARTED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_STATUS_STARTED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_READY_MASK (0x8U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_READY_SHIFT (3U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_READY_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_READY(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_STATUS_READY_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_STATUS_READY_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_RESP_MASK (0x30U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_RESP_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_RESP_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT1_STATUS_RESP(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT1_STATUS_RESP_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT1_STATUS_RESP_MASK)
/*! @} */

/*! @name AXIM3_SLOT2_ADDR_LOW - AXIM[i] slot[s] address bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT2_ADDR_LOW_AXI_ADDR_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT2_ADDR_LOW_AXI_ADDR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT2_ADDR_LOW_AXI_ADDR_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT2_ADDR_LOW_AXI_ADDR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_ADDR_LOW_AXI_ADDR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_ADDR_LOW_AXI_ADDR_MASK)
/*! @} */

/*! @name AXIM3_SLOT2_DATA_LOW - AXIM[i] slot[s] data bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT2_DATA_LOW_AXI_DATA_LOW_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT2_DATA_LOW_AXI_DATA_LOW_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT2_DATA_LOW_AXI_DATA_LOW_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT2_DATA_LOW_AXI_DATA_LOW(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_DATA_LOW_AXI_DATA_LOW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_DATA_LOW_AXI_DATA_LOW_MASK)
/*! @} */

/*! @name AXIM3_SLOT2_CFG1 - AXIM[i] slot [s] configuration 1 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_INCR_MASK  (0xFU)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_INCR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_INCR_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_INCR(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AUTO_INCR_MASK (0x10U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AUTO_INCR_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AUTO_INCR_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AUTO_INCR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AUTO_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AUTO_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_PRIO_MASK  (0x60U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_PRIO_SHIFT (5U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_PRIO_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_PRIO(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_PRIO_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_PRIO_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_PROT_MASK (0x3800U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_PROT_SHIFT (11U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_PROT_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_PROT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_PROT_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_PROT_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_CACHE_MASK (0x3C000U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_CACHE_SHIFT (14U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_CACHE_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_CACHE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_CACHE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_CACHE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_LOCK_MASK (0xC0000U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_LOCK_SHIFT (18U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_LOCK_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_LOCK(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_LOCK_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_LOCK_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_SIZE_MASK (0x1C00000U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_SIZE_SHIFT (22U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_SIZE_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_SIZE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_SIZE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_SIZE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_RW_MASK (0x2000000U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_RW_SHIFT (25U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_RW_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_RW(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_RW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG1_AXI_RW_MASK)
/*! @} */

/*! @name AXIM3_SLOT2_CFG2 - AXIM[i] slot[s] configuration 2 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT2_CFG2_AXI_ID_MASK (0xFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG2_AXI_ID_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG2_AXI_ID_WIDTH (16U)
#define GTM_gtm_cls3_AXIM3_SLOT2_CFG2_AXI_ID(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_CFG2_AXI_ID_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_CFG2_AXI_ID_MASK)
/*! @} */

/*! @name AXIM3_SLOT2_STATUS - AXIM[i] slot[s] status */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_ALLOC_MASK (0x1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_ALLOC_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_ALLOC_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_STATUS_ALLOC_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_STATUS_ALLOC_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_QUEUED_MASK (0x2U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_QUEUED_SHIFT (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_QUEUED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_QUEUED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_STATUS_QUEUED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_STATUS_QUEUED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_STARTED_MASK (0x4U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_STARTED_SHIFT (2U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_STARTED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_STARTED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_STATUS_STARTED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_STATUS_STARTED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_READY_MASK (0x8U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_READY_SHIFT (3U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_READY_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_READY(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_STATUS_READY_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_STATUS_READY_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_RESP_MASK (0x30U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_RESP_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_RESP_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT2_STATUS_RESP(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT2_STATUS_RESP_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT2_STATUS_RESP_MASK)
/*! @} */

/*! @name AXIM3_SLOT3_ADDR_LOW - AXIM[i] slot[s] address bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT3_ADDR_LOW_AXI_ADDR_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT3_ADDR_LOW_AXI_ADDR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT3_ADDR_LOW_AXI_ADDR_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT3_ADDR_LOW_AXI_ADDR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_ADDR_LOW_AXI_ADDR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_ADDR_LOW_AXI_ADDR_MASK)
/*! @} */

/*! @name AXIM3_SLOT3_DATA_LOW - AXIM[i] slot[s] data bits 31:0 of AXI transaction. */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT3_DATA_LOW_AXI_DATA_LOW_MASK (0xFFFFFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT3_DATA_LOW_AXI_DATA_LOW_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT3_DATA_LOW_AXI_DATA_LOW_WIDTH (32U)
#define GTM_gtm_cls3_AXIM3_SLOT3_DATA_LOW_AXI_DATA_LOW(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_DATA_LOW_AXI_DATA_LOW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_DATA_LOW_AXI_DATA_LOW_MASK)
/*! @} */

/*! @name AXIM3_SLOT3_CFG1 - AXIM[i] slot [s] configuration 1 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_INCR_MASK  (0xFU)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_INCR_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_INCR_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_INCR(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AUTO_INCR_MASK (0x10U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AUTO_INCR_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AUTO_INCR_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AUTO_INCR(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AUTO_INCR_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AUTO_INCR_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_PRIO_MASK  (0x60U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_PRIO_SHIFT (5U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_PRIO_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_PRIO(x)    (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_PRIO_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_PRIO_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_PROT_MASK (0x3800U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_PROT_SHIFT (11U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_PROT_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_PROT(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_PROT_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_PROT_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_CACHE_MASK (0x3C000U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_CACHE_SHIFT (14U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_CACHE_WIDTH (4U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_CACHE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_CACHE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_CACHE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_LOCK_MASK (0xC0000U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_LOCK_SHIFT (18U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_LOCK_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_LOCK(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_LOCK_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_LOCK_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_SIZE_MASK (0x1C00000U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_SIZE_SHIFT (22U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_SIZE_WIDTH (3U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_SIZE(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_SIZE_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_SIZE_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_RW_MASK (0x2000000U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_RW_SHIFT (25U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_RW_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_RW(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_RW_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG1_AXI_RW_MASK)
/*! @} */

/*! @name AXIM3_SLOT3_CFG2 - AXIM[i] slot[s] configuration 2 */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT3_CFG2_AXI_ID_MASK (0xFFFFU)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG2_AXI_ID_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG2_AXI_ID_WIDTH (16U)
#define GTM_gtm_cls3_AXIM3_SLOT3_CFG2_AXI_ID(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_CFG2_AXI_ID_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_CFG2_AXI_ID_MASK)
/*! @} */

/*! @name AXIM3_SLOT3_STATUS - AXIM[i] slot[s] status */
/*! @{ */

#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_ALLOC_MASK (0x1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_ALLOC_SHIFT (0U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_ALLOC_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_STATUS_ALLOC_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_STATUS_ALLOC_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_QUEUED_MASK (0x2U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_QUEUED_SHIFT (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_QUEUED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_QUEUED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_STATUS_QUEUED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_STATUS_QUEUED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_STARTED_MASK (0x4U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_STARTED_SHIFT (2U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_STARTED_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_STARTED(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_STATUS_STARTED_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_STATUS_STARTED_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_READY_MASK (0x8U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_READY_SHIFT (3U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_READY_WIDTH (1U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_READY(x) (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_STATUS_READY_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_STATUS_READY_MASK)

#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_RESP_MASK (0x30U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_RESP_SHIFT (4U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_RESP_WIDTH (2U)
#define GTM_gtm_cls3_AXIM3_SLOT3_STATUS_RESP(x)  (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_AXIM3_SLOT3_STATUS_RESP_SHIFT)) & GTM_gtm_cls3_AXIM3_SLOT3_STATUS_RESP_MASK)
/*! @} */

/*! @name MCS3_MEM - MCS[i] memory region */
/*! @{ */

#define GTM_gtm_cls3_MCS3_MEM_DATA_MASK          (0xFFFFFFFFU)
#define GTM_gtm_cls3_MCS3_MEM_DATA_SHIFT         (0U)
#define GTM_gtm_cls3_MCS3_MEM_DATA_WIDTH         (32U)
#define GTM_gtm_cls3_MCS3_MEM_DATA(x)            (((uint32_t)(((uint32_t)(x)) << GTM_gtm_cls3_MCS3_MEM_DATA_SHIFT)) & GTM_gtm_cls3_MCS3_MEM_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GTM_gtm_cls3_Register_Masks */

/*!
 * @}
 */ /* end of group GTM_gtm_cls3_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_GTM_gtm_cls3_H_) */
