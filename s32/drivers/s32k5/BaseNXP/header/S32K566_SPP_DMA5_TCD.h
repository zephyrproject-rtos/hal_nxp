/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_spp_dma5_TCD.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_spp_dma5_TCD
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
#if !defined(S32K566_spp_dma5_TCD_H_)  /* Check if memory map has not been already included */
#define S32K566_spp_dma5_TCD_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- spp_dma5_TCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup spp_dma5_TCD_Peripheral_Access_Layer spp_dma5_TCD Peripheral Access Layer
 * @{
 */

/** spp_dma5_TCD - Register Layout Typedef */
typedef struct spp_dma5_TCD_Struct {
  __IO uint32_t CH0_CSR;                           /**< Channel Control and Status, offset: 0x0 */
  __IO uint32_t CH0_ES;                            /**< Channel Error Status, offset: 0x4 */
  __IO uint32_t CH0_INT;                           /**< Channel Interrupt Status, offset: 0x8 */
  __I  uint32_t CH0_SBR;                           /**< Channel System Bus, offset: 0xC */
  __IO uint32_t CH0_PRI;                           /**< Channel Priority, offset: 0x10 */
  uint8_t RESERVED_0[4];
  __IO uint32_t CH0_MATTR;                         /**< Memory Attributes, offset: 0x18 */
  uint8_t RESERVED_1[4];
  __IO uint32_t TCD0_SADDR;                        /**< TCD Source Address, offset: 0x20 */
  __IO uint32_t TCD0_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x24 */
  __IO uint16_t TCD0_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x28 */
  __IO uint16_t TCD0_ATTR;                         /**< TCD Transfer Attributes, offset: 0x2A */
  union {                                          /* offset: 0x2C */
    __IO uint32_t TCD0_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2C */
    __IO uint32_t TCD0_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2C */
  } NBYTES0;
  __IO uint32_t TCD0_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x30 */
  __IO uint32_t TCD0_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x34 */
  __IO uint32_t TCD0_DADDR;                        /**< TCD Destination Address, offset: 0x38 */
  __IO uint32_t TCD0_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x3C */
  __IO uint32_t TCD0_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x40 */
  __IO uint32_t TCD0_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x44 */
  __IO uint16_t TCD0_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x48 */
  union {                                          /* offset: 0x4A */
    __IO uint16_t TCD0_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x4A */
    __IO uint16_t TCD0_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x4A */
  } CITER0;
  __IO uint16_t TCD0_CSR;                          /**< TCD Control and Status, offset: 0x4C */
  union {                                          /* offset: 0x4E */
    __IO uint16_t TCD0_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x4E */
    __IO uint16_t TCD0_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x4E */
  } BITER0;
  uint8_t RESERVED_2[8112];
  __IO uint32_t CH1_CSR;                           /**< Channel Control and Status, offset: 0x2000 */
  __IO uint32_t CH1_ES;                            /**< Channel Error Status, offset: 0x2004 */
  __IO uint32_t CH1_INT;                           /**< Channel Interrupt Status, offset: 0x2008 */
  __I  uint32_t CH1_SBR;                           /**< Channel System Bus, offset: 0x200C */
  __IO uint32_t CH1_PRI;                           /**< Channel Priority, offset: 0x2010 */
  uint8_t RESERVED_3[4];
  __IO uint32_t CH1_MATTR;                         /**< Memory Attributes, offset: 0x2018 */
  uint8_t RESERVED_4[4];
  __IO uint32_t TCD1_SADDR;                        /**< TCD Source Address, offset: 0x2020 */
  __IO uint32_t TCD1_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x2024 */
  __IO uint16_t TCD1_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x2028 */
  __IO uint16_t TCD1_ATTR;                         /**< TCD Transfer Attributes, offset: 0x202A */
  union {                                          /* offset: 0x202C */
    __IO uint32_t TCD1_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x202C */
    __IO uint32_t TCD1_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x202C */
  } NBYTES1;
  __IO uint32_t TCD1_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x2030 */
  __IO uint32_t TCD1_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x2034 */
  __IO uint32_t TCD1_DADDR;                        /**< TCD Destination Address, offset: 0x2038 */
  __IO uint32_t TCD1_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x203C */
  __IO uint32_t TCD1_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x2040 */
  __IO uint32_t TCD1_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x2044 */
  __IO uint16_t TCD1_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x2048 */
  union {                                          /* offset: 0x204A */
    __IO uint16_t TCD1_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x204A */
    __IO uint16_t TCD1_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x204A */
  } CITER1;
  __IO uint16_t TCD1_CSR;                          /**< TCD Control and Status, offset: 0x204C */
  union {                                          /* offset: 0x204E */
    __IO uint16_t TCD1_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x204E */
    __IO uint16_t TCD1_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x204E */
  } BITER1;
  uint8_t RESERVED_5[24496];
  __IO uint32_t CH2_CSR;                           /**< Channel Control and Status, offset: 0x8000 */
  __IO uint32_t CH2_ES;                            /**< Channel Error Status, offset: 0x8004 */
  __IO uint32_t CH2_INT;                           /**< Channel Interrupt Status, offset: 0x8008 */
  __I  uint32_t CH2_SBR;                           /**< Channel System Bus, offset: 0x800C */
  __IO uint32_t CH2_PRI;                           /**< Channel Priority, offset: 0x8010 */
  uint8_t RESERVED_6[4];
  __IO uint32_t CH2_MATTR;                         /**< Memory Attributes, offset: 0x8018 */
  uint8_t RESERVED_7[4];
  __IO uint32_t TCD2_SADDR;                        /**< TCD Source Address, offset: 0x8020 */
  __IO uint32_t TCD2_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x8024 */
  __IO uint16_t TCD2_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x8028 */
  __IO uint16_t TCD2_ATTR;                         /**< TCD Transfer Attributes, offset: 0x802A */
  union {                                          /* offset: 0x802C */
    __IO uint32_t TCD2_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x802C */
    __IO uint32_t TCD2_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x802C */
  } NBYTES2;
  __IO uint32_t TCD2_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x8030 */
  __IO uint32_t TCD2_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x8034 */
  __IO uint32_t TCD2_DADDR;                        /**< TCD Destination Address, offset: 0x8038 */
  __IO uint32_t TCD2_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x803C */
  __IO uint32_t TCD2_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x8040 */
  __IO uint32_t TCD2_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x8044 */
  __IO uint16_t TCD2_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x8048 */
  union {                                          /* offset: 0x804A */
    __IO uint16_t TCD2_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x804A */
    __IO uint16_t TCD2_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x804A */
  } CITER2;
  __IO uint16_t TCD2_CSR;                          /**< TCD Control and Status, offset: 0x804C */
  union {                                          /* offset: 0x804E */
    __IO uint16_t TCD2_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x804E */
    __IO uint16_t TCD2_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x804E */
  } BITER2;
  uint8_t RESERVED_8[8112];
  __IO uint32_t CH3_CSR;                           /**< Channel Control and Status, offset: 0xA000 */
  __IO uint32_t CH3_ES;                            /**< Channel Error Status, offset: 0xA004 */
  __IO uint32_t CH3_INT;                           /**< Channel Interrupt Status, offset: 0xA008 */
  __I  uint32_t CH3_SBR;                           /**< Channel System Bus, offset: 0xA00C */
  __IO uint32_t CH3_PRI;                           /**< Channel Priority, offset: 0xA010 */
  uint8_t RESERVED_9[4];
  __IO uint32_t CH3_MATTR;                         /**< Memory Attributes, offset: 0xA018 */
  uint8_t RESERVED_10[4];
  __IO uint32_t TCD3_SADDR;                        /**< TCD Source Address, offset: 0xA020 */
  __IO uint32_t TCD3_SADDR_HIGH;                   /**< TCD Source Address, offset: 0xA024 */
  __IO uint16_t TCD3_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0xA028 */
  __IO uint16_t TCD3_ATTR;                         /**< TCD Transfer Attributes, offset: 0xA02A */
  union {                                          /* offset: 0xA02C */
    __IO uint32_t TCD3_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0xA02C */
    __IO uint32_t TCD3_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0xA02C */
  } NBYTES3;
  __IO uint32_t TCD3_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0xA030 */
  __IO uint32_t TCD3_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0xA034 */
  __IO uint32_t TCD3_DADDR;                        /**< TCD Destination Address, offset: 0xA038 */
  __IO uint32_t TCD3_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0xA03C */
  __IO uint32_t TCD3_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0xA040 */
  __IO uint32_t TCD3_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0xA044 */
  __IO uint16_t TCD3_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0xA048 */
  union {                                          /* offset: 0xA04A */
    __IO uint16_t TCD3_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0xA04A */
    __IO uint16_t TCD3_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0xA04A */
  } CITER3;
  __IO uint16_t TCD3_CSR;                          /**< TCD Control and Status, offset: 0xA04C */
  union {                                          /* offset: 0xA04E */
    __IO uint16_t TCD3_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0xA04E */
    __IO uint16_t TCD3_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0xA04E */
  } BITER3;
  uint8_t RESERVED_11[24496];
  __IO uint32_t CH4_CSR;                           /**< Channel Control and Status, offset: 0x10000 */
  __IO uint32_t CH4_ES;                            /**< Channel Error Status, offset: 0x10004 */
  __IO uint32_t CH4_INT;                           /**< Channel Interrupt Status, offset: 0x10008 */
  __I  uint32_t CH4_SBR;                           /**< Channel System Bus, offset: 0x1000C */
  __IO uint32_t CH4_PRI;                           /**< Channel Priority, offset: 0x10010 */
  uint8_t RESERVED_12[4];
  __IO uint32_t CH4_MATTR;                         /**< Memory Attributes, offset: 0x10018 */
  uint8_t RESERVED_13[4];
  __IO uint32_t TCD4_SADDR;                        /**< TCD Source Address, offset: 0x10020 */
  __IO uint32_t TCD4_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x10024 */
  __IO uint16_t TCD4_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x10028 */
  __IO uint16_t TCD4_ATTR;                         /**< TCD Transfer Attributes, offset: 0x1002A */
  union {                                          /* offset: 0x1002C */
    __IO uint32_t TCD4_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x1002C */
    __IO uint32_t TCD4_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x1002C */
  } NBYTES4;
  __IO uint32_t TCD4_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x10030 */
  __IO uint32_t TCD4_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x10034 */
  __IO uint32_t TCD4_DADDR;                        /**< TCD Destination Address, offset: 0x10038 */
  __IO uint32_t TCD4_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x1003C */
  __IO uint32_t TCD4_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x10040 */
  __IO uint32_t TCD4_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x10044 */
  __IO uint16_t TCD4_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x10048 */
  union {                                          /* offset: 0x1004A */
    __IO uint16_t TCD4_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1004A */
    __IO uint16_t TCD4_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1004A */
  } CITER4;
  __IO uint16_t TCD4_CSR;                          /**< TCD Control and Status, offset: 0x1004C */
  union {                                          /* offset: 0x1004E */
    __IO uint16_t TCD4_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1004E */
    __IO uint16_t TCD4_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1004E */
  } BITER4;
  uint8_t RESERVED_14[8112];
  __IO uint32_t CH5_CSR;                           /**< Channel Control and Status, offset: 0x12000 */
  __IO uint32_t CH5_ES;                            /**< Channel Error Status, offset: 0x12004 */
  __IO uint32_t CH5_INT;                           /**< Channel Interrupt Status, offset: 0x12008 */
  __I  uint32_t CH5_SBR;                           /**< Channel System Bus, offset: 0x1200C */
  __IO uint32_t CH5_PRI;                           /**< Channel Priority, offset: 0x12010 */
  uint8_t RESERVED_15[4];
  __IO uint32_t CH5_MATTR;                         /**< Memory Attributes, offset: 0x12018 */
  uint8_t RESERVED_16[4];
  __IO uint32_t TCD5_SADDR;                        /**< TCD Source Address, offset: 0x12020 */
  __IO uint32_t TCD5_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x12024 */
  __IO uint16_t TCD5_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x12028 */
  __IO uint16_t TCD5_ATTR;                         /**< TCD Transfer Attributes, offset: 0x1202A */
  union {                                          /* offset: 0x1202C */
    __IO uint32_t TCD5_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x1202C */
    __IO uint32_t TCD5_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x1202C */
  } NBYTES5;
  __IO uint32_t TCD5_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x12030 */
  __IO uint32_t TCD5_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x12034 */
  __IO uint32_t TCD5_DADDR;                        /**< TCD Destination Address, offset: 0x12038 */
  __IO uint32_t TCD5_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x1203C */
  __IO uint32_t TCD5_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x12040 */
  __IO uint32_t TCD5_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x12044 */
  __IO uint16_t TCD5_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x12048 */
  union {                                          /* offset: 0x1204A */
    __IO uint16_t TCD5_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1204A */
    __IO uint16_t TCD5_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1204A */
  } CITER5;
  __IO uint16_t TCD5_CSR;                          /**< TCD Control and Status, offset: 0x1204C */
  union {                                          /* offset: 0x1204E */
    __IO uint16_t TCD5_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1204E */
    __IO uint16_t TCD5_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1204E */
  } BITER5;
  uint8_t RESERVED_17[24496];
  __IO uint32_t CH6_CSR;                           /**< Channel Control and Status, offset: 0x18000 */
  __IO uint32_t CH6_ES;                            /**< Channel Error Status, offset: 0x18004 */
  __IO uint32_t CH6_INT;                           /**< Channel Interrupt Status, offset: 0x18008 */
  __I  uint32_t CH6_SBR;                           /**< Channel System Bus, offset: 0x1800C */
  __IO uint32_t CH6_PRI;                           /**< Channel Priority, offset: 0x18010 */
  uint8_t RESERVED_18[4];
  __IO uint32_t CH6_MATTR;                         /**< Memory Attributes, offset: 0x18018 */
  uint8_t RESERVED_19[4];
  __IO uint32_t TCD6_SADDR;                        /**< TCD Source Address, offset: 0x18020 */
  __IO uint32_t TCD6_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x18024 */
  __IO uint16_t TCD6_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x18028 */
  __IO uint16_t TCD6_ATTR;                         /**< TCD Transfer Attributes, offset: 0x1802A */
  union {                                          /* offset: 0x1802C */
    __IO uint32_t TCD6_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x1802C */
    __IO uint32_t TCD6_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x1802C */
  } NBYTES6;
  __IO uint32_t TCD6_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x18030 */
  __IO uint32_t TCD6_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x18034 */
  __IO uint32_t TCD6_DADDR;                        /**< TCD Destination Address, offset: 0x18038 */
  __IO uint32_t TCD6_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x1803C */
  __IO uint32_t TCD6_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x18040 */
  __IO uint32_t TCD6_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x18044 */
  __IO uint16_t TCD6_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x18048 */
  union {                                          /* offset: 0x1804A */
    __IO uint16_t TCD6_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1804A */
    __IO uint16_t TCD6_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1804A */
  } CITER6;
  __IO uint16_t TCD6_CSR;                          /**< TCD Control and Status, offset: 0x1804C */
  union {                                          /* offset: 0x1804E */
    __IO uint16_t TCD6_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1804E */
    __IO uint16_t TCD6_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1804E */
  } BITER6;
  uint8_t RESERVED_20[8112];
  __IO uint32_t CH7_CSR;                           /**< Channel Control and Status, offset: 0x1A000 */
  __IO uint32_t CH7_ES;                            /**< Channel Error Status, offset: 0x1A004 */
  __IO uint32_t CH7_INT;                           /**< Channel Interrupt Status, offset: 0x1A008 */
  __I  uint32_t CH7_SBR;                           /**< Channel System Bus, offset: 0x1A00C */
  __IO uint32_t CH7_PRI;                           /**< Channel Priority, offset: 0x1A010 */
  uint8_t RESERVED_21[4];
  __IO uint32_t CH7_MATTR;                         /**< Memory Attributes, offset: 0x1A018 */
  uint8_t RESERVED_22[4];
  __IO uint32_t TCD7_SADDR;                        /**< TCD Source Address, offset: 0x1A020 */
  __IO uint32_t TCD7_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x1A024 */
  __IO uint16_t TCD7_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x1A028 */
  __IO uint16_t TCD7_ATTR;                         /**< TCD Transfer Attributes, offset: 0x1A02A */
  union {                                          /* offset: 0x1A02C */
    __IO uint32_t TCD7_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x1A02C */
    __IO uint32_t TCD7_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x1A02C */
  } NBYTES7;
  __IO uint32_t TCD7_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x1A030 */
  __IO uint32_t TCD7_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x1A034 */
  __IO uint32_t TCD7_DADDR;                        /**< TCD Destination Address, offset: 0x1A038 */
  __IO uint32_t TCD7_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x1A03C */
  __IO uint32_t TCD7_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x1A040 */
  __IO uint32_t TCD7_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x1A044 */
  __IO uint16_t TCD7_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x1A048 */
  union {                                          /* offset: 0x1A04A */
    __IO uint16_t TCD7_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1A04A */
    __IO uint16_t TCD7_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1A04A */
  } CITER7;
  __IO uint16_t TCD7_CSR;                          /**< TCD Control and Status, offset: 0x1A04C */
  union {                                          /* offset: 0x1A04E */
    __IO uint16_t TCD7_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1A04E */
    __IO uint16_t TCD7_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1A04E */
  } BITER7;
  uint8_t RESERVED_23[24496];
  __IO uint32_t CH8_CSR;                           /**< Channel Control and Status, offset: 0x20000 */
  __IO uint32_t CH8_ES;                            /**< Channel Error Status, offset: 0x20004 */
  __IO uint32_t CH8_INT;                           /**< Channel Interrupt Status, offset: 0x20008 */
  __I  uint32_t CH8_SBR;                           /**< Channel System Bus, offset: 0x2000C */
  __IO uint32_t CH8_PRI;                           /**< Channel Priority, offset: 0x20010 */
  uint8_t RESERVED_24[4];
  __IO uint32_t CH8_MATTR;                         /**< Memory Attributes, offset: 0x20018 */
  uint8_t RESERVED_25[4];
  __IO uint32_t TCD8_SADDR;                        /**< TCD Source Address, offset: 0x20020 */
  __IO uint32_t TCD8_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x20024 */
  __IO uint16_t TCD8_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x20028 */
  __IO uint16_t TCD8_ATTR;                         /**< TCD Transfer Attributes, offset: 0x2002A */
  union {                                          /* offset: 0x2002C */
    __IO uint32_t TCD8_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2002C */
    __IO uint32_t TCD8_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2002C */
  } NBYTES8;
  __IO uint32_t TCD8_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x20030 */
  __IO uint32_t TCD8_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x20034 */
  __IO uint32_t TCD8_DADDR;                        /**< TCD Destination Address, offset: 0x20038 */
  __IO uint32_t TCD8_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x2003C */
  __IO uint32_t TCD8_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x20040 */
  __IO uint32_t TCD8_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x20044 */
  __IO uint16_t TCD8_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x20048 */
  union {                                          /* offset: 0x2004A */
    __IO uint16_t TCD8_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2004A */
    __IO uint16_t TCD8_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2004A */
  } CITER8;
  __IO uint16_t TCD8_CSR;                          /**< TCD Control and Status, offset: 0x2004C */
  union {                                          /* offset: 0x2004E */
    __IO uint16_t TCD8_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2004E */
    __IO uint16_t TCD8_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2004E */
  } BITER8;
  uint8_t RESERVED_26[8112];
  __IO uint32_t CH9_CSR;                           /**< Channel Control and Status, offset: 0x22000 */
  __IO uint32_t CH9_ES;                            /**< Channel Error Status, offset: 0x22004 */
  __IO uint32_t CH9_INT;                           /**< Channel Interrupt Status, offset: 0x22008 */
  __I  uint32_t CH9_SBR;                           /**< Channel System Bus, offset: 0x2200C */
  __IO uint32_t CH9_PRI;                           /**< Channel Priority, offset: 0x22010 */
  uint8_t RESERVED_27[4];
  __IO uint32_t CH9_MATTR;                         /**< Memory Attributes, offset: 0x22018 */
  uint8_t RESERVED_28[4];
  __IO uint32_t TCD9_SADDR;                        /**< TCD Source Address, offset: 0x22020 */
  __IO uint32_t TCD9_SADDR_HIGH;                   /**< TCD Source Address, offset: 0x22024 */
  __IO uint16_t TCD9_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x22028 */
  __IO uint16_t TCD9_ATTR;                         /**< TCD Transfer Attributes, offset: 0x2202A */
  union {                                          /* offset: 0x2202C */
    __IO uint32_t TCD9_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2202C */
    __IO uint32_t TCD9_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2202C */
  } NBYTES9;
  __IO uint32_t TCD9_SLAST_SDA;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x22030 */
  __IO uint32_t TCD9_SLAST_SDA_HIGH;               /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x22034 */
  __IO uint32_t TCD9_DADDR;                        /**< TCD Destination Address, offset: 0x22038 */
  __IO uint32_t TCD9_DADDR_HIGH;                   /**< TCD Destination Address, offset: 0x2203C */
  __IO uint32_t TCD9_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x22040 */
  __IO uint32_t TCD9_DLAST_SGA_HIGH;               /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x22044 */
  __IO uint16_t TCD9_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x22048 */
  union {                                          /* offset: 0x2204A */
    __IO uint16_t TCD9_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2204A */
    __IO uint16_t TCD9_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2204A */
  } CITER9;
  __IO uint16_t TCD9_CSR;                          /**< TCD Control and Status, offset: 0x2204C */
  union {                                          /* offset: 0x2204E */
    __IO uint16_t TCD9_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2204E */
    __IO uint16_t TCD9_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2204E */
  } BITER9;
  uint8_t RESERVED_29[24496];
  __IO uint32_t CH10_CSR;                          /**< Channel Control and Status, offset: 0x28000 */
  __IO uint32_t CH10_ES;                           /**< Channel Error Status, offset: 0x28004 */
  __IO uint32_t CH10_INT;                          /**< Channel Interrupt Status, offset: 0x28008 */
  __I  uint32_t CH10_SBR;                          /**< Channel System Bus, offset: 0x2800C */
  __IO uint32_t CH10_PRI;                          /**< Channel Priority, offset: 0x28010 */
  uint8_t RESERVED_30[4];
  __IO uint32_t CH10_MATTR;                        /**< Memory Attributes, offset: 0x28018 */
  uint8_t RESERVED_31[4];
  __IO uint32_t TCD10_SADDR;                       /**< TCD Source Address, offset: 0x28020 */
  __IO uint32_t TCD10_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x28024 */
  __IO uint16_t TCD10_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x28028 */
  __IO uint16_t TCD10_ATTR;                        /**< TCD Transfer Attributes, offset: 0x2802A */
  union {                                          /* offset: 0x2802C */
    __IO uint32_t TCD10_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2802C */
    __IO uint32_t TCD10_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2802C */
  } NBYTES10;
  __IO uint32_t TCD10_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x28030 */
  __IO uint32_t TCD10_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x28034 */
  __IO uint32_t TCD10_DADDR;                       /**< TCD Destination Address, offset: 0x28038 */
  __IO uint32_t TCD10_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x2803C */
  __IO uint32_t TCD10_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x28040 */
  __IO uint32_t TCD10_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x28044 */
  __IO uint16_t TCD10_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x28048 */
  union {                                          /* offset: 0x2804A */
    __IO uint16_t TCD10_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2804A */
    __IO uint16_t TCD10_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2804A */
  } CITER10;
  __IO uint16_t TCD10_CSR;                         /**< TCD Control and Status, offset: 0x2804C */
  union {                                          /* offset: 0x2804E */
    __IO uint16_t TCD10_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2804E */
    __IO uint16_t TCD10_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2804E */
  } BITER10;
  uint8_t RESERVED_32[8112];
  __IO uint32_t CH11_CSR;                          /**< Channel Control and Status, offset: 0x2A000 */
  __IO uint32_t CH11_ES;                           /**< Channel Error Status, offset: 0x2A004 */
  __IO uint32_t CH11_INT;                          /**< Channel Interrupt Status, offset: 0x2A008 */
  __I  uint32_t CH11_SBR;                          /**< Channel System Bus, offset: 0x2A00C */
  __IO uint32_t CH11_PRI;                          /**< Channel Priority, offset: 0x2A010 */
  uint8_t RESERVED_33[4];
  __IO uint32_t CH11_MATTR;                        /**< Memory Attributes, offset: 0x2A018 */
  uint8_t RESERVED_34[4];
  __IO uint32_t TCD11_SADDR;                       /**< TCD Source Address, offset: 0x2A020 */
  __IO uint32_t TCD11_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x2A024 */
  __IO uint16_t TCD11_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x2A028 */
  __IO uint16_t TCD11_ATTR;                        /**< TCD Transfer Attributes, offset: 0x2A02A */
  union {                                          /* offset: 0x2A02C */
    __IO uint32_t TCD11_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2A02C */
    __IO uint32_t TCD11_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2A02C */
  } NBYTES11;
  __IO uint32_t TCD11_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x2A030 */
  __IO uint32_t TCD11_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x2A034 */
  __IO uint32_t TCD11_DADDR;                       /**< TCD Destination Address, offset: 0x2A038 */
  __IO uint32_t TCD11_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x2A03C */
  __IO uint32_t TCD11_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x2A040 */
  __IO uint32_t TCD11_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x2A044 */
  __IO uint16_t TCD11_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x2A048 */
  union {                                          /* offset: 0x2A04A */
    __IO uint16_t TCD11_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2A04A */
    __IO uint16_t TCD11_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2A04A */
  } CITER11;
  __IO uint16_t TCD11_CSR;                         /**< TCD Control and Status, offset: 0x2A04C */
  union {                                          /* offset: 0x2A04E */
    __IO uint16_t TCD11_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2A04E */
    __IO uint16_t TCD11_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2A04E */
  } BITER11;
  uint8_t RESERVED_35[24496];
  __IO uint32_t CH12_CSR;                          /**< Channel Control and Status, offset: 0x30000 */
  __IO uint32_t CH12_ES;                           /**< Channel Error Status, offset: 0x30004 */
  __IO uint32_t CH12_INT;                          /**< Channel Interrupt Status, offset: 0x30008 */
  __I  uint32_t CH12_SBR;                          /**< Channel System Bus, offset: 0x3000C */
  __IO uint32_t CH12_PRI;                          /**< Channel Priority, offset: 0x30010 */
  uint8_t RESERVED_36[4];
  __IO uint32_t CH12_MATTR;                        /**< Memory Attributes, offset: 0x30018 */
  uint8_t RESERVED_37[4];
  __IO uint32_t TCD12_SADDR;                       /**< TCD Source Address, offset: 0x30020 */
  __IO uint32_t TCD12_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x30024 */
  __IO uint16_t TCD12_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x30028 */
  __IO uint16_t TCD12_ATTR;                        /**< TCD Transfer Attributes, offset: 0x3002A */
  union {                                          /* offset: 0x3002C */
    __IO uint32_t TCD12_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x3002C */
    __IO uint32_t TCD12_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x3002C */
  } NBYTES12;
  __IO uint32_t TCD12_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x30030 */
  __IO uint32_t TCD12_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x30034 */
  __IO uint32_t TCD12_DADDR;                       /**< TCD Destination Address, offset: 0x30038 */
  __IO uint32_t TCD12_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x3003C */
  __IO uint32_t TCD12_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x30040 */
  __IO uint32_t TCD12_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x30044 */
  __IO uint16_t TCD12_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x30048 */
  union {                                          /* offset: 0x3004A */
    __IO uint16_t TCD12_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3004A */
    __IO uint16_t TCD12_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3004A */
  } CITER12;
  __IO uint16_t TCD12_CSR;                         /**< TCD Control and Status, offset: 0x3004C */
  union {                                          /* offset: 0x3004E */
    __IO uint16_t TCD12_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3004E */
    __IO uint16_t TCD12_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3004E */
  } BITER12;
  uint8_t RESERVED_38[8112];
  __IO uint32_t CH13_CSR;                          /**< Channel Control and Status, offset: 0x32000 */
  __IO uint32_t CH13_ES;                           /**< Channel Error Status, offset: 0x32004 */
  __IO uint32_t CH13_INT;                          /**< Channel Interrupt Status, offset: 0x32008 */
  __I  uint32_t CH13_SBR;                          /**< Channel System Bus, offset: 0x3200C */
  __IO uint32_t CH13_PRI;                          /**< Channel Priority, offset: 0x32010 */
  uint8_t RESERVED_39[4];
  __IO uint32_t CH13_MATTR;                        /**< Memory Attributes, offset: 0x32018 */
  uint8_t RESERVED_40[4];
  __IO uint32_t TCD13_SADDR;                       /**< TCD Source Address, offset: 0x32020 */
  __IO uint32_t TCD13_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x32024 */
  __IO uint16_t TCD13_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x32028 */
  __IO uint16_t TCD13_ATTR;                        /**< TCD Transfer Attributes, offset: 0x3202A */
  union {                                          /* offset: 0x3202C */
    __IO uint32_t TCD13_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x3202C */
    __IO uint32_t TCD13_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x3202C */
  } NBYTES13;
  __IO uint32_t TCD13_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x32030 */
  __IO uint32_t TCD13_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x32034 */
  __IO uint32_t TCD13_DADDR;                       /**< TCD Destination Address, offset: 0x32038 */
  __IO uint32_t TCD13_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x3203C */
  __IO uint32_t TCD13_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x32040 */
  __IO uint32_t TCD13_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x32044 */
  __IO uint16_t TCD13_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x32048 */
  union {                                          /* offset: 0x3204A */
    __IO uint16_t TCD13_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3204A */
    __IO uint16_t TCD13_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3204A */
  } CITER13;
  __IO uint16_t TCD13_CSR;                         /**< TCD Control and Status, offset: 0x3204C */
  union {                                          /* offset: 0x3204E */
    __IO uint16_t TCD13_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3204E */
    __IO uint16_t TCD13_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3204E */
  } BITER13;
  uint8_t RESERVED_41[24496];
  __IO uint32_t CH14_CSR;                          /**< Channel Control and Status, offset: 0x38000 */
  __IO uint32_t CH14_ES;                           /**< Channel Error Status, offset: 0x38004 */
  __IO uint32_t CH14_INT;                          /**< Channel Interrupt Status, offset: 0x38008 */
  __I  uint32_t CH14_SBR;                          /**< Channel System Bus, offset: 0x3800C */
  __IO uint32_t CH14_PRI;                          /**< Channel Priority, offset: 0x38010 */
  uint8_t RESERVED_42[4];
  __IO uint32_t CH14_MATTR;                        /**< Memory Attributes, offset: 0x38018 */
  uint8_t RESERVED_43[4];
  __IO uint32_t TCD14_SADDR;                       /**< TCD Source Address, offset: 0x38020 */
  __IO uint32_t TCD14_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x38024 */
  __IO uint16_t TCD14_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x38028 */
  __IO uint16_t TCD14_ATTR;                        /**< TCD Transfer Attributes, offset: 0x3802A */
  union {                                          /* offset: 0x3802C */
    __IO uint32_t TCD14_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x3802C */
    __IO uint32_t TCD14_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x3802C */
  } NBYTES14;
  __IO uint32_t TCD14_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x38030 */
  __IO uint32_t TCD14_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x38034 */
  __IO uint32_t TCD14_DADDR;                       /**< TCD Destination Address, offset: 0x38038 */
  __IO uint32_t TCD14_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x3803C */
  __IO uint32_t TCD14_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x38040 */
  __IO uint32_t TCD14_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x38044 */
  __IO uint16_t TCD14_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x38048 */
  union {                                          /* offset: 0x3804A */
    __IO uint16_t TCD14_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3804A */
    __IO uint16_t TCD14_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3804A */
  } CITER14;
  __IO uint16_t TCD14_CSR;                         /**< TCD Control and Status, offset: 0x3804C */
  union {                                          /* offset: 0x3804E */
    __IO uint16_t TCD14_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3804E */
    __IO uint16_t TCD14_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3804E */
  } BITER14;
  uint8_t RESERVED_44[8112];
  __IO uint32_t CH15_CSR;                          /**< Channel Control and Status, offset: 0x3A000 */
  __IO uint32_t CH15_ES;                           /**< Channel Error Status, offset: 0x3A004 */
  __IO uint32_t CH15_INT;                          /**< Channel Interrupt Status, offset: 0x3A008 */
  __I  uint32_t CH15_SBR;                          /**< Channel System Bus, offset: 0x3A00C */
  __IO uint32_t CH15_PRI;                          /**< Channel Priority, offset: 0x3A010 */
  uint8_t RESERVED_45[4];
  __IO uint32_t CH15_MATTR;                        /**< Memory Attributes, offset: 0x3A018 */
  uint8_t RESERVED_46[4];
  __IO uint32_t TCD15_SADDR;                       /**< TCD Source Address, offset: 0x3A020 */
  __IO uint32_t TCD15_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x3A024 */
  __IO uint16_t TCD15_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x3A028 */
  __IO uint16_t TCD15_ATTR;                        /**< TCD Transfer Attributes, offset: 0x3A02A */
  union {                                          /* offset: 0x3A02C */
    __IO uint32_t TCD15_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x3A02C */
    __IO uint32_t TCD15_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x3A02C */
  } NBYTES15;
  __IO uint32_t TCD15_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x3A030 */
  __IO uint32_t TCD15_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x3A034 */
  __IO uint32_t TCD15_DADDR;                       /**< TCD Destination Address, offset: 0x3A038 */
  __IO uint32_t TCD15_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x3A03C */
  __IO uint32_t TCD15_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x3A040 */
  __IO uint32_t TCD15_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x3A044 */
  __IO uint16_t TCD15_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x3A048 */
  union {                                          /* offset: 0x3A04A */
    __IO uint16_t TCD15_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3A04A */
    __IO uint16_t TCD15_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3A04A */
  } CITER15;
  __IO uint16_t TCD15_CSR;                         /**< TCD Control and Status, offset: 0x3A04C */
  union {                                          /* offset: 0x3A04E */
    __IO uint16_t TCD15_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3A04E */
    __IO uint16_t TCD15_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3A04E */
  } BITER15;
  uint8_t RESERVED_47[6102960];
  __IO uint32_t CH16_CSR;                          /**< Channel Control and Status, offset: 0x60C000 */
  __IO uint32_t CH16_ES;                           /**< Channel Error Status, offset: 0x60C004 */
  __IO uint32_t CH16_INT;                          /**< Channel Interrupt Status, offset: 0x60C008 */
  __I  uint32_t CH16_SBR;                          /**< Channel System Bus, offset: 0x60C00C */
  __IO uint32_t CH16_PRI;                          /**< Channel Priority, offset: 0x60C010 */
  uint8_t RESERVED_48[4];
  __IO uint32_t CH16_MATTR;                        /**< Memory Attributes, offset: 0x60C018 */
  uint8_t RESERVED_49[4];
  __IO uint32_t TCD16_SADDR;                       /**< TCD Source Address, offset: 0x60C020 */
  __IO uint32_t TCD16_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x60C024 */
  __IO uint16_t TCD16_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x60C028 */
  __IO uint16_t TCD16_ATTR;                        /**< TCD Transfer Attributes, offset: 0x60C02A */
  union {                                          /* offset: 0x60C02C */
    __IO uint32_t TCD16_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x60C02C */
    __IO uint32_t TCD16_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x60C02C */
  } NBYTES16;
  __IO uint32_t TCD16_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x60C030 */
  __IO uint32_t TCD16_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x60C034 */
  __IO uint32_t TCD16_DADDR;                       /**< TCD Destination Address, offset: 0x60C038 */
  __IO uint32_t TCD16_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x60C03C */
  __IO uint32_t TCD16_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x60C040 */
  __IO uint32_t TCD16_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x60C044 */
  __IO uint16_t TCD16_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x60C048 */
  union {                                          /* offset: 0x60C04A */
    __IO uint16_t TCD16_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x60C04A */
    __IO uint16_t TCD16_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x60C04A */
  } CITER16;
  __IO uint16_t TCD16_CSR;                         /**< TCD Control and Status, offset: 0x60C04C */
  union {                                          /* offset: 0x60C04E */
    __IO uint16_t TCD16_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x60C04E */
    __IO uint16_t TCD16_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x60C04E */
  } BITER16;
  uint8_t RESERVED_50[8112];
  __IO uint32_t CH17_CSR;                          /**< Channel Control and Status, offset: 0x60E000 */
  __IO uint32_t CH17_ES;                           /**< Channel Error Status, offset: 0x60E004 */
  __IO uint32_t CH17_INT;                          /**< Channel Interrupt Status, offset: 0x60E008 */
  __I  uint32_t CH17_SBR;                          /**< Channel System Bus, offset: 0x60E00C */
  __IO uint32_t CH17_PRI;                          /**< Channel Priority, offset: 0x60E010 */
  uint8_t RESERVED_51[4];
  __IO uint32_t CH17_MATTR;                        /**< Memory Attributes, offset: 0x60E018 */
  uint8_t RESERVED_52[4];
  __IO uint32_t TCD17_SADDR;                       /**< TCD Source Address, offset: 0x60E020 */
  __IO uint32_t TCD17_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x60E024 */
  __IO uint16_t TCD17_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x60E028 */
  __IO uint16_t TCD17_ATTR;                        /**< TCD Transfer Attributes, offset: 0x60E02A */
  union {                                          /* offset: 0x60E02C */
    __IO uint32_t TCD17_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x60E02C */
    __IO uint32_t TCD17_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x60E02C */
  } NBYTES17;
  __IO uint32_t TCD17_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x60E030 */
  __IO uint32_t TCD17_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x60E034 */
  __IO uint32_t TCD17_DADDR;                       /**< TCD Destination Address, offset: 0x60E038 */
  __IO uint32_t TCD17_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x60E03C */
  __IO uint32_t TCD17_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x60E040 */
  __IO uint32_t TCD17_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x60E044 */
  __IO uint16_t TCD17_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x60E048 */
  union {                                          /* offset: 0x60E04A */
    __IO uint16_t TCD17_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x60E04A */
    __IO uint16_t TCD17_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x60E04A */
  } CITER17;
  __IO uint16_t TCD17_CSR;                         /**< TCD Control and Status, offset: 0x60E04C */
  union {                                          /* offset: 0x60E04E */
    __IO uint16_t TCD17_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x60E04E */
    __IO uint16_t TCD17_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x60E04E */
  } BITER17;
  uint8_t RESERVED_53[24496];
  __IO uint32_t CH18_CSR;                          /**< Channel Control and Status, offset: 0x614000 */
  __IO uint32_t CH18_ES;                           /**< Channel Error Status, offset: 0x614004 */
  __IO uint32_t CH18_INT;                          /**< Channel Interrupt Status, offset: 0x614008 */
  __I  uint32_t CH18_SBR;                          /**< Channel System Bus, offset: 0x61400C */
  __IO uint32_t CH18_PRI;                          /**< Channel Priority, offset: 0x614010 */
  uint8_t RESERVED_54[4];
  __IO uint32_t CH18_MATTR;                        /**< Memory Attributes, offset: 0x614018 */
  uint8_t RESERVED_55[4];
  __IO uint32_t TCD18_SADDR;                       /**< TCD Source Address, offset: 0x614020 */
  __IO uint32_t TCD18_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x614024 */
  __IO uint16_t TCD18_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x614028 */
  __IO uint16_t TCD18_ATTR;                        /**< TCD Transfer Attributes, offset: 0x61402A */
  union {                                          /* offset: 0x61402C */
    __IO uint32_t TCD18_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x61402C */
    __IO uint32_t TCD18_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x61402C */
  } NBYTES18;
  __IO uint32_t TCD18_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x614030 */
  __IO uint32_t TCD18_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x614034 */
  __IO uint32_t TCD18_DADDR;                       /**< TCD Destination Address, offset: 0x614038 */
  __IO uint32_t TCD18_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x61403C */
  __IO uint32_t TCD18_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x614040 */
  __IO uint32_t TCD18_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x614044 */
  __IO uint16_t TCD18_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x614048 */
  union {                                          /* offset: 0x61404A */
    __IO uint16_t TCD18_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61404A */
    __IO uint16_t TCD18_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61404A */
  } CITER18;
  __IO uint16_t TCD18_CSR;                         /**< TCD Control and Status, offset: 0x61404C */
  union {                                          /* offset: 0x61404E */
    __IO uint16_t TCD18_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61404E */
    __IO uint16_t TCD18_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61404E */
  } BITER18;
  uint8_t RESERVED_56[8112];
  __IO uint32_t CH19_CSR;                          /**< Channel Control and Status, offset: 0x616000 */
  __IO uint32_t CH19_ES;                           /**< Channel Error Status, offset: 0x616004 */
  __IO uint32_t CH19_INT;                          /**< Channel Interrupt Status, offset: 0x616008 */
  __I  uint32_t CH19_SBR;                          /**< Channel System Bus, offset: 0x61600C */
  __IO uint32_t CH19_PRI;                          /**< Channel Priority, offset: 0x616010 */
  uint8_t RESERVED_57[4];
  __IO uint32_t CH19_MATTR;                        /**< Memory Attributes, offset: 0x616018 */
  uint8_t RESERVED_58[4];
  __IO uint32_t TCD19_SADDR;                       /**< TCD Source Address, offset: 0x616020 */
  __IO uint32_t TCD19_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x616024 */
  __IO uint16_t TCD19_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x616028 */
  __IO uint16_t TCD19_ATTR;                        /**< TCD Transfer Attributes, offset: 0x61602A */
  union {                                          /* offset: 0x61602C */
    __IO uint32_t TCD19_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x61602C */
    __IO uint32_t TCD19_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x61602C */
  } NBYTES19;
  __IO uint32_t TCD19_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x616030 */
  __IO uint32_t TCD19_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x616034 */
  __IO uint32_t TCD19_DADDR;                       /**< TCD Destination Address, offset: 0x616038 */
  __IO uint32_t TCD19_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x61603C */
  __IO uint32_t TCD19_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x616040 */
  __IO uint32_t TCD19_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x616044 */
  __IO uint16_t TCD19_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x616048 */
  union {                                          /* offset: 0x61604A */
    __IO uint16_t TCD19_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61604A */
    __IO uint16_t TCD19_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61604A */
  } CITER19;
  __IO uint16_t TCD19_CSR;                         /**< TCD Control and Status, offset: 0x61604C */
  union {                                          /* offset: 0x61604E */
    __IO uint16_t TCD19_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61604E */
    __IO uint16_t TCD19_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61604E */
  } BITER19;
  uint8_t RESERVED_59[24496];
  __IO uint32_t CH20_CSR;                          /**< Channel Control and Status, offset: 0x61C000 */
  __IO uint32_t CH20_ES;                           /**< Channel Error Status, offset: 0x61C004 */
  __IO uint32_t CH20_INT;                          /**< Channel Interrupt Status, offset: 0x61C008 */
  __I  uint32_t CH20_SBR;                          /**< Channel System Bus, offset: 0x61C00C */
  __IO uint32_t CH20_PRI;                          /**< Channel Priority, offset: 0x61C010 */
  uint8_t RESERVED_60[4];
  __IO uint32_t CH20_MATTR;                        /**< Memory Attributes, offset: 0x61C018 */
  uint8_t RESERVED_61[4];
  __IO uint32_t TCD20_SADDR;                       /**< TCD Source Address, offset: 0x61C020 */
  __IO uint32_t TCD20_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x61C024 */
  __IO uint16_t TCD20_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x61C028 */
  __IO uint16_t TCD20_ATTR;                        /**< TCD Transfer Attributes, offset: 0x61C02A */
  union {                                          /* offset: 0x61C02C */
    __IO uint32_t TCD20_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x61C02C */
    __IO uint32_t TCD20_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x61C02C */
  } NBYTES20;
  __IO uint32_t TCD20_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x61C030 */
  __IO uint32_t TCD20_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x61C034 */
  __IO uint32_t TCD20_DADDR;                       /**< TCD Destination Address, offset: 0x61C038 */
  __IO uint32_t TCD20_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x61C03C */
  __IO uint32_t TCD20_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x61C040 */
  __IO uint32_t TCD20_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x61C044 */
  __IO uint16_t TCD20_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x61C048 */
  union {                                          /* offset: 0x61C04A */
    __IO uint16_t TCD20_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61C04A */
    __IO uint16_t TCD20_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61C04A */
  } CITER20;
  __IO uint16_t TCD20_CSR;                         /**< TCD Control and Status, offset: 0x61C04C */
  union {                                          /* offset: 0x61C04E */
    __IO uint16_t TCD20_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61C04E */
    __IO uint16_t TCD20_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61C04E */
  } BITER20;
  uint8_t RESERVED_62[8112];
  __IO uint32_t CH21_CSR;                          /**< Channel Control and Status, offset: 0x61E000 */
  __IO uint32_t CH21_ES;                           /**< Channel Error Status, offset: 0x61E004 */
  __IO uint32_t CH21_INT;                          /**< Channel Interrupt Status, offset: 0x61E008 */
  __I  uint32_t CH21_SBR;                          /**< Channel System Bus, offset: 0x61E00C */
  __IO uint32_t CH21_PRI;                          /**< Channel Priority, offset: 0x61E010 */
  uint8_t RESERVED_63[4];
  __IO uint32_t CH21_MATTR;                        /**< Memory Attributes, offset: 0x61E018 */
  uint8_t RESERVED_64[4];
  __IO uint32_t TCD21_SADDR;                       /**< TCD Source Address, offset: 0x61E020 */
  __IO uint32_t TCD21_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x61E024 */
  __IO uint16_t TCD21_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x61E028 */
  __IO uint16_t TCD21_ATTR;                        /**< TCD Transfer Attributes, offset: 0x61E02A */
  union {                                          /* offset: 0x61E02C */
    __IO uint32_t TCD21_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x61E02C */
    __IO uint32_t TCD21_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x61E02C */
  } NBYTES21;
  __IO uint32_t TCD21_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x61E030 */
  __IO uint32_t TCD21_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x61E034 */
  __IO uint32_t TCD21_DADDR;                       /**< TCD Destination Address, offset: 0x61E038 */
  __IO uint32_t TCD21_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x61E03C */
  __IO uint32_t TCD21_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x61E040 */
  __IO uint32_t TCD21_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x61E044 */
  __IO uint16_t TCD21_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x61E048 */
  union {                                          /* offset: 0x61E04A */
    __IO uint16_t TCD21_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61E04A */
    __IO uint16_t TCD21_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61E04A */
  } CITER21;
  __IO uint16_t TCD21_CSR;                         /**< TCD Control and Status, offset: 0x61E04C */
  union {                                          /* offset: 0x61E04E */
    __IO uint16_t TCD21_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x61E04E */
    __IO uint16_t TCD21_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x61E04E */
  } BITER21;
  uint8_t RESERVED_65[24496];
  __IO uint32_t CH22_CSR;                          /**< Channel Control and Status, offset: 0x624000 */
  __IO uint32_t CH22_ES;                           /**< Channel Error Status, offset: 0x624004 */
  __IO uint32_t CH22_INT;                          /**< Channel Interrupt Status, offset: 0x624008 */
  __I  uint32_t CH22_SBR;                          /**< Channel System Bus, offset: 0x62400C */
  __IO uint32_t CH22_PRI;                          /**< Channel Priority, offset: 0x624010 */
  uint8_t RESERVED_66[4];
  __IO uint32_t CH22_MATTR;                        /**< Memory Attributes, offset: 0x624018 */
  uint8_t RESERVED_67[4];
  __IO uint32_t TCD22_SADDR;                       /**< TCD Source Address, offset: 0x624020 */
  __IO uint32_t TCD22_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x624024 */
  __IO uint16_t TCD22_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x624028 */
  __IO uint16_t TCD22_ATTR;                        /**< TCD Transfer Attributes, offset: 0x62402A */
  union {                                          /* offset: 0x62402C */
    __IO uint32_t TCD22_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x62402C */
    __IO uint32_t TCD22_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x62402C */
  } NBYTES22;
  __IO uint32_t TCD22_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x624030 */
  __IO uint32_t TCD22_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x624034 */
  __IO uint32_t TCD22_DADDR;                       /**< TCD Destination Address, offset: 0x624038 */
  __IO uint32_t TCD22_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x62403C */
  __IO uint32_t TCD22_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x624040 */
  __IO uint32_t TCD22_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x624044 */
  __IO uint16_t TCD22_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x624048 */
  union {                                          /* offset: 0x62404A */
    __IO uint16_t TCD22_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62404A */
    __IO uint16_t TCD22_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62404A */
  } CITER22;
  __IO uint16_t TCD22_CSR;                         /**< TCD Control and Status, offset: 0x62404C */
  union {                                          /* offset: 0x62404E */
    __IO uint16_t TCD22_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62404E */
    __IO uint16_t TCD22_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62404E */
  } BITER22;
  uint8_t RESERVED_68[8112];
  __IO uint32_t CH23_CSR;                          /**< Channel Control and Status, offset: 0x626000 */
  __IO uint32_t CH23_ES;                           /**< Channel Error Status, offset: 0x626004 */
  __IO uint32_t CH23_INT;                          /**< Channel Interrupt Status, offset: 0x626008 */
  __I  uint32_t CH23_SBR;                          /**< Channel System Bus, offset: 0x62600C */
  __IO uint32_t CH23_PRI;                          /**< Channel Priority, offset: 0x626010 */
  uint8_t RESERVED_69[4];
  __IO uint32_t CH23_MATTR;                        /**< Memory Attributes, offset: 0x626018 */
  uint8_t RESERVED_70[4];
  __IO uint32_t TCD23_SADDR;                       /**< TCD Source Address, offset: 0x626020 */
  __IO uint32_t TCD23_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x626024 */
  __IO uint16_t TCD23_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x626028 */
  __IO uint16_t TCD23_ATTR;                        /**< TCD Transfer Attributes, offset: 0x62602A */
  union {                                          /* offset: 0x62602C */
    __IO uint32_t TCD23_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x62602C */
    __IO uint32_t TCD23_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x62602C */
  } NBYTES23;
  __IO uint32_t TCD23_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x626030 */
  __IO uint32_t TCD23_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x626034 */
  __IO uint32_t TCD23_DADDR;                       /**< TCD Destination Address, offset: 0x626038 */
  __IO uint32_t TCD23_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x62603C */
  __IO uint32_t TCD23_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x626040 */
  __IO uint32_t TCD23_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x626044 */
  __IO uint16_t TCD23_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x626048 */
  union {                                          /* offset: 0x62604A */
    __IO uint16_t TCD23_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62604A */
    __IO uint16_t TCD23_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62604A */
  } CITER23;
  __IO uint16_t TCD23_CSR;                         /**< TCD Control and Status, offset: 0x62604C */
  union {                                          /* offset: 0x62604E */
    __IO uint16_t TCD23_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62604E */
    __IO uint16_t TCD23_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62604E */
  } BITER23;
  uint8_t RESERVED_71[24496];
  __IO uint32_t CH24_CSR;                          /**< Channel Control and Status, offset: 0x62C000 */
  __IO uint32_t CH24_ES;                           /**< Channel Error Status, offset: 0x62C004 */
  __IO uint32_t CH24_INT;                          /**< Channel Interrupt Status, offset: 0x62C008 */
  __I  uint32_t CH24_SBR;                          /**< Channel System Bus, offset: 0x62C00C */
  __IO uint32_t CH24_PRI;                          /**< Channel Priority, offset: 0x62C010 */
  uint8_t RESERVED_72[4];
  __IO uint32_t CH24_MATTR;                        /**< Memory Attributes, offset: 0x62C018 */
  uint8_t RESERVED_73[4];
  __IO uint32_t TCD24_SADDR;                       /**< TCD Source Address, offset: 0x62C020 */
  __IO uint32_t TCD24_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x62C024 */
  __IO uint16_t TCD24_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x62C028 */
  __IO uint16_t TCD24_ATTR;                        /**< TCD Transfer Attributes, offset: 0x62C02A */
  union {                                          /* offset: 0x62C02C */
    __IO uint32_t TCD24_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x62C02C */
    __IO uint32_t TCD24_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x62C02C */
  } NBYTES24;
  __IO uint32_t TCD24_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x62C030 */
  __IO uint32_t TCD24_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x62C034 */
  __IO uint32_t TCD24_DADDR;                       /**< TCD Destination Address, offset: 0x62C038 */
  __IO uint32_t TCD24_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x62C03C */
  __IO uint32_t TCD24_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x62C040 */
  __IO uint32_t TCD24_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x62C044 */
  __IO uint16_t TCD24_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x62C048 */
  union {                                          /* offset: 0x62C04A */
    __IO uint16_t TCD24_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62C04A */
    __IO uint16_t TCD24_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62C04A */
  } CITER24;
  __IO uint16_t TCD24_CSR;                         /**< TCD Control and Status, offset: 0x62C04C */
  union {                                          /* offset: 0x62C04E */
    __IO uint16_t TCD24_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62C04E */
    __IO uint16_t TCD24_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62C04E */
  } BITER24;
  uint8_t RESERVED_74[8112];
  __IO uint32_t CH25_CSR;                          /**< Channel Control and Status, offset: 0x62E000 */
  __IO uint32_t CH25_ES;                           /**< Channel Error Status, offset: 0x62E004 */
  __IO uint32_t CH25_INT;                          /**< Channel Interrupt Status, offset: 0x62E008 */
  __I  uint32_t CH25_SBR;                          /**< Channel System Bus, offset: 0x62E00C */
  __IO uint32_t CH25_PRI;                          /**< Channel Priority, offset: 0x62E010 */
  uint8_t RESERVED_75[4];
  __IO uint32_t CH25_MATTR;                        /**< Memory Attributes, offset: 0x62E018 */
  uint8_t RESERVED_76[4];
  __IO uint32_t TCD25_SADDR;                       /**< TCD Source Address, offset: 0x62E020 */
  __IO uint32_t TCD25_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x62E024 */
  __IO uint16_t TCD25_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x62E028 */
  __IO uint16_t TCD25_ATTR;                        /**< TCD Transfer Attributes, offset: 0x62E02A */
  union {                                          /* offset: 0x62E02C */
    __IO uint32_t TCD25_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x62E02C */
    __IO uint32_t TCD25_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x62E02C */
  } NBYTES25;
  __IO uint32_t TCD25_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x62E030 */
  __IO uint32_t TCD25_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x62E034 */
  __IO uint32_t TCD25_DADDR;                       /**< TCD Destination Address, offset: 0x62E038 */
  __IO uint32_t TCD25_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x62E03C */
  __IO uint32_t TCD25_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x62E040 */
  __IO uint32_t TCD25_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x62E044 */
  __IO uint16_t TCD25_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x62E048 */
  union {                                          /* offset: 0x62E04A */
    __IO uint16_t TCD25_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62E04A */
    __IO uint16_t TCD25_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62E04A */
  } CITER25;
  __IO uint16_t TCD25_CSR;                         /**< TCD Control and Status, offset: 0x62E04C */
  union {                                          /* offset: 0x62E04E */
    __IO uint16_t TCD25_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x62E04E */
    __IO uint16_t TCD25_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x62E04E */
  } BITER25;
  uint8_t RESERVED_77[24496];
  __IO uint32_t CH26_CSR;                          /**< Channel Control and Status, offset: 0x634000 */
  __IO uint32_t CH26_ES;                           /**< Channel Error Status, offset: 0x634004 */
  __IO uint32_t CH26_INT;                          /**< Channel Interrupt Status, offset: 0x634008 */
  __I  uint32_t CH26_SBR;                          /**< Channel System Bus, offset: 0x63400C */
  __IO uint32_t CH26_PRI;                          /**< Channel Priority, offset: 0x634010 */
  uint8_t RESERVED_78[4];
  __IO uint32_t CH26_MATTR;                        /**< Memory Attributes, offset: 0x634018 */
  uint8_t RESERVED_79[4];
  __IO uint32_t TCD26_SADDR;                       /**< TCD Source Address, offset: 0x634020 */
  __IO uint32_t TCD26_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x634024 */
  __IO uint16_t TCD26_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x634028 */
  __IO uint16_t TCD26_ATTR;                        /**< TCD Transfer Attributes, offset: 0x63402A */
  union {                                          /* offset: 0x63402C */
    __IO uint32_t TCD26_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x63402C */
    __IO uint32_t TCD26_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x63402C */
  } NBYTES26;
  __IO uint32_t TCD26_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x634030 */
  __IO uint32_t TCD26_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x634034 */
  __IO uint32_t TCD26_DADDR;                       /**< TCD Destination Address, offset: 0x634038 */
  __IO uint32_t TCD26_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x63403C */
  __IO uint32_t TCD26_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x634040 */
  __IO uint32_t TCD26_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x634044 */
  __IO uint16_t TCD26_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x634048 */
  union {                                          /* offset: 0x63404A */
    __IO uint16_t TCD26_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63404A */
    __IO uint16_t TCD26_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63404A */
  } CITER26;
  __IO uint16_t TCD26_CSR;                         /**< TCD Control and Status, offset: 0x63404C */
  union {                                          /* offset: 0x63404E */
    __IO uint16_t TCD26_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63404E */
    __IO uint16_t TCD26_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63404E */
  } BITER26;
  uint8_t RESERVED_80[8112];
  __IO uint32_t CH27_CSR;                          /**< Channel Control and Status, offset: 0x636000 */
  __IO uint32_t CH27_ES;                           /**< Channel Error Status, offset: 0x636004 */
  __IO uint32_t CH27_INT;                          /**< Channel Interrupt Status, offset: 0x636008 */
  __I  uint32_t CH27_SBR;                          /**< Channel System Bus, offset: 0x63600C */
  __IO uint32_t CH27_PRI;                          /**< Channel Priority, offset: 0x636010 */
  uint8_t RESERVED_81[4];
  __IO uint32_t CH27_MATTR;                        /**< Memory Attributes, offset: 0x636018 */
  uint8_t RESERVED_82[4];
  __IO uint32_t TCD27_SADDR;                       /**< TCD Source Address, offset: 0x636020 */
  __IO uint32_t TCD27_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x636024 */
  __IO uint16_t TCD27_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x636028 */
  __IO uint16_t TCD27_ATTR;                        /**< TCD Transfer Attributes, offset: 0x63602A */
  union {                                          /* offset: 0x63602C */
    __IO uint32_t TCD27_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x63602C */
    __IO uint32_t TCD27_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x63602C */
  } NBYTES27;
  __IO uint32_t TCD27_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x636030 */
  __IO uint32_t TCD27_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x636034 */
  __IO uint32_t TCD27_DADDR;                       /**< TCD Destination Address, offset: 0x636038 */
  __IO uint32_t TCD27_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x63603C */
  __IO uint32_t TCD27_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x636040 */
  __IO uint32_t TCD27_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x636044 */
  __IO uint16_t TCD27_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x636048 */
  union {                                          /* offset: 0x63604A */
    __IO uint16_t TCD27_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63604A */
    __IO uint16_t TCD27_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63604A */
  } CITER27;
  __IO uint16_t TCD27_CSR;                         /**< TCD Control and Status, offset: 0x63604C */
  union {                                          /* offset: 0x63604E */
    __IO uint16_t TCD27_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63604E */
    __IO uint16_t TCD27_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63604E */
  } BITER27;
  uint8_t RESERVED_83[24496];
  __IO uint32_t CH28_CSR;                          /**< Channel Control and Status, offset: 0x63C000 */
  __IO uint32_t CH28_ES;                           /**< Channel Error Status, offset: 0x63C004 */
  __IO uint32_t CH28_INT;                          /**< Channel Interrupt Status, offset: 0x63C008 */
  __I  uint32_t CH28_SBR;                          /**< Channel System Bus, offset: 0x63C00C */
  __IO uint32_t CH28_PRI;                          /**< Channel Priority, offset: 0x63C010 */
  uint8_t RESERVED_84[4];
  __IO uint32_t CH28_MATTR;                        /**< Memory Attributes, offset: 0x63C018 */
  uint8_t RESERVED_85[4];
  __IO uint32_t TCD28_SADDR;                       /**< TCD Source Address, offset: 0x63C020 */
  __IO uint32_t TCD28_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x63C024 */
  __IO uint16_t TCD28_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x63C028 */
  __IO uint16_t TCD28_ATTR;                        /**< TCD Transfer Attributes, offset: 0x63C02A */
  union {                                          /* offset: 0x63C02C */
    __IO uint32_t TCD28_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x63C02C */
    __IO uint32_t TCD28_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x63C02C */
  } NBYTES28;
  __IO uint32_t TCD28_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x63C030 */
  __IO uint32_t TCD28_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x63C034 */
  __IO uint32_t TCD28_DADDR;                       /**< TCD Destination Address, offset: 0x63C038 */
  __IO uint32_t TCD28_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x63C03C */
  __IO uint32_t TCD28_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x63C040 */
  __IO uint32_t TCD28_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x63C044 */
  __IO uint16_t TCD28_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x63C048 */
  union {                                          /* offset: 0x63C04A */
    __IO uint16_t TCD28_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63C04A */
    __IO uint16_t TCD28_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63C04A */
  } CITER28;
  __IO uint16_t TCD28_CSR;                         /**< TCD Control and Status, offset: 0x63C04C */
  union {                                          /* offset: 0x63C04E */
    __IO uint16_t TCD28_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63C04E */
    __IO uint16_t TCD28_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63C04E */
  } BITER28;
  uint8_t RESERVED_86[8112];
  __IO uint32_t CH29_CSR;                          /**< Channel Control and Status, offset: 0x63E000 */
  __IO uint32_t CH29_ES;                           /**< Channel Error Status, offset: 0x63E004 */
  __IO uint32_t CH29_INT;                          /**< Channel Interrupt Status, offset: 0x63E008 */
  __I  uint32_t CH29_SBR;                          /**< Channel System Bus, offset: 0x63E00C */
  __IO uint32_t CH29_PRI;                          /**< Channel Priority, offset: 0x63E010 */
  uint8_t RESERVED_87[4];
  __IO uint32_t CH29_MATTR;                        /**< Memory Attributes, offset: 0x63E018 */
  uint8_t RESERVED_88[4];
  __IO uint32_t TCD29_SADDR;                       /**< TCD Source Address, offset: 0x63E020 */
  __IO uint32_t TCD29_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x63E024 */
  __IO uint16_t TCD29_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x63E028 */
  __IO uint16_t TCD29_ATTR;                        /**< TCD Transfer Attributes, offset: 0x63E02A */
  union {                                          /* offset: 0x63E02C */
    __IO uint32_t TCD29_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x63E02C */
    __IO uint32_t TCD29_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x63E02C */
  } NBYTES29;
  __IO uint32_t TCD29_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x63E030 */
  __IO uint32_t TCD29_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x63E034 */
  __IO uint32_t TCD29_DADDR;                       /**< TCD Destination Address, offset: 0x63E038 */
  __IO uint32_t TCD29_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x63E03C */
  __IO uint32_t TCD29_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x63E040 */
  __IO uint32_t TCD29_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x63E044 */
  __IO uint16_t TCD29_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x63E048 */
  union {                                          /* offset: 0x63E04A */
    __IO uint16_t TCD29_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63E04A */
    __IO uint16_t TCD29_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63E04A */
  } CITER29;
  __IO uint16_t TCD29_CSR;                         /**< TCD Control and Status, offset: 0x63E04C */
  union {                                          /* offset: 0x63E04E */
    __IO uint16_t TCD29_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x63E04E */
    __IO uint16_t TCD29_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x63E04E */
  } BITER29;
  uint8_t RESERVED_89[24496];
  __IO uint32_t CH30_CSR;                          /**< Channel Control and Status, offset: 0x644000 */
  __IO uint32_t CH30_ES;                           /**< Channel Error Status, offset: 0x644004 */
  __IO uint32_t CH30_INT;                          /**< Channel Interrupt Status, offset: 0x644008 */
  __I  uint32_t CH30_SBR;                          /**< Channel System Bus, offset: 0x64400C */
  __IO uint32_t CH30_PRI;                          /**< Channel Priority, offset: 0x644010 */
  uint8_t RESERVED_90[4];
  __IO uint32_t CH30_MATTR;                        /**< Memory Attributes, offset: 0x644018 */
  uint8_t RESERVED_91[4];
  __IO uint32_t TCD30_SADDR;                       /**< TCD Source Address, offset: 0x644020 */
  __IO uint32_t TCD30_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x644024 */
  __IO uint16_t TCD30_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x644028 */
  __IO uint16_t TCD30_ATTR;                        /**< TCD Transfer Attributes, offset: 0x64402A */
  union {                                          /* offset: 0x64402C */
    __IO uint32_t TCD30_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x64402C */
    __IO uint32_t TCD30_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x64402C */
  } NBYTES30;
  __IO uint32_t TCD30_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x644030 */
  __IO uint32_t TCD30_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x644034 */
  __IO uint32_t TCD30_DADDR;                       /**< TCD Destination Address, offset: 0x644038 */
  __IO uint32_t TCD30_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x64403C */
  __IO uint32_t TCD30_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x644040 */
  __IO uint32_t TCD30_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x644044 */
  __IO uint16_t TCD30_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x644048 */
  union {                                          /* offset: 0x64404A */
    __IO uint16_t TCD30_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x64404A */
    __IO uint16_t TCD30_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x64404A */
  } CITER30;
  __IO uint16_t TCD30_CSR;                         /**< TCD Control and Status, offset: 0x64404C */
  union {                                          /* offset: 0x64404E */
    __IO uint16_t TCD30_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x64404E */
    __IO uint16_t TCD30_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x64404E */
  } BITER30;
  uint8_t RESERVED_92[8112];
  __IO uint32_t CH31_CSR;                          /**< Channel Control and Status, offset: 0x646000 */
  __IO uint32_t CH31_ES;                           /**< Channel Error Status, offset: 0x646004 */
  __IO uint32_t CH31_INT;                          /**< Channel Interrupt Status, offset: 0x646008 */
  __I  uint32_t CH31_SBR;                          /**< Channel System Bus, offset: 0x64600C */
  __IO uint32_t CH31_PRI;                          /**< Channel Priority, offset: 0x646010 */
  uint8_t RESERVED_93[4];
  __IO uint32_t CH31_MATTR;                        /**< Memory Attributes, offset: 0x646018 */
  uint8_t RESERVED_94[4];
  __IO uint32_t TCD31_SADDR;                       /**< TCD Source Address, offset: 0x646020 */
  __IO uint32_t TCD31_SADDR_HIGH;                  /**< TCD Source Address, offset: 0x646024 */
  __IO uint16_t TCD31_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x646028 */
  __IO uint16_t TCD31_ATTR;                        /**< TCD Transfer Attributes, offset: 0x64602A */
  union {                                          /* offset: 0x64602C */
    __IO uint32_t TCD31_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x64602C */
    __IO uint32_t TCD31_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x64602C */
  } NBYTES31;
  __IO uint32_t TCD31_SLAST_SDA;                   /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x646030 */
  __IO uint32_t TCD31_SLAST_SDA_HIGH;              /**< TCD Last Source Address Adjustment and Store DADDR Address, offset: 0x646034 */
  __IO uint32_t TCD31_DADDR;                       /**< TCD Destination Address, offset: 0x646038 */
  __IO uint32_t TCD31_DADDR_HIGH;                  /**< TCD Destination Address, offset: 0x64603C */
  __IO uint32_t TCD31_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x646040 */
  __IO uint32_t TCD31_DLAST_SGA_HIGH;              /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, offset: 0x646044 */
  __IO uint16_t TCD31_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x646048 */
  union {                                          /* offset: 0x64604A */
    __IO uint16_t TCD31_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x64604A */
    __IO uint16_t TCD31_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x64604A */
  } CITER31;
  __IO uint16_t TCD31_CSR;                         /**< TCD Control and Status, offset: 0x64604C */
  union {                                          /* offset: 0x64604E */
    __IO uint16_t TCD31_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x64604E */
    __IO uint16_t TCD31_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x64604E */
  } BITER31;
} spp_dma5_TCD_Type, *spp_dma5_TCD_MemMapPtr;

/** Number of instances of the spp_dma5_TCD module. */
#define spp_dma5_TCD_INSTANCE_COUNT              (1u)

/* spp_dma5_TCD - Peripheral instance base addresses */
/** Peripheral EDMA5_TCD0_1 base address */
#define IP_EDMA5_TCD0_1_BASE                     (0x40414000u)
/** Peripheral EDMA5_TCD0_1 base pointer */
#define IP_EDMA5_TCD0_1                          ((spp_dma5_TCD_Type *)IP_EDMA5_TCD0_1_BASE)
/** Array initializer of spp_dma5_TCD peripheral base addresses */
#define IP_spp_dma5_TCD_BASE_ADDRS               { IP_EDMA5_TCD0_1_BASE }
/** Array initializer of spp_dma5_TCD peripheral base pointers */
#define IP_spp_dma5_TCD_BASE_PTRS                { IP_EDMA5_TCD0_1 }

/* ----------------------------------------------------------------------------
   -- spp_dma5_TCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup spp_dma5_TCD_Register_Masks spp_dma5_TCD Register Masks
 * @{
 */

/*! @name CH0_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH0_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH0_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH0_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH0_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH0_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH0_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH0_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH0_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH0_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH0_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH0_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH0_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH0_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH0_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH0_CSR_EEI_MASK)

#define spp_dma5_TCD_CH0_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH0_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH0_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH0_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_CX_SHIFT)) & spp_dma5_TCD_CH0_CSR_CX_MASK)

#define spp_dma5_TCD_CH0_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH0_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH0_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH0_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH0_CSR_ECX_MASK)

#define spp_dma5_TCD_CH0_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH0_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH0_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH0_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH0_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH0_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH0_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH0_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH0_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH0_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH0_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH0_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH0_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH0_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH0_CSR_DONE_MASK)

#define spp_dma5_TCD_CH0_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH0_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH0_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH0_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH0_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH0_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH0_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH0_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH0_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_DBE_SHIFT)) & spp_dma5_TCD_CH0_ES_DBE_MASK)

#define spp_dma5_TCD_CH0_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH0_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH0_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_SBE_SHIFT)) & spp_dma5_TCD_CH0_ES_SBE_MASK)

#define spp_dma5_TCD_CH0_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH0_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH0_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_SGE_SHIFT)) & spp_dma5_TCD_CH0_ES_SGE_MASK)

#define spp_dma5_TCD_CH0_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH0_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH0_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_NCE_SHIFT)) & spp_dma5_TCD_CH0_ES_NCE_MASK)

#define spp_dma5_TCD_CH0_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH0_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH0_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_DOE_SHIFT)) & spp_dma5_TCD_CH0_ES_DOE_MASK)

#define spp_dma5_TCD_CH0_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH0_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH0_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_DAE_SHIFT)) & spp_dma5_TCD_CH0_ES_DAE_MASK)

#define spp_dma5_TCD_CH0_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH0_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH0_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_SOE_SHIFT)) & spp_dma5_TCD_CH0_ES_SOE_MASK)

#define spp_dma5_TCD_CH0_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH0_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH0_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_SAE_SHIFT)) & spp_dma5_TCD_CH0_ES_SAE_MASK)

#define spp_dma5_TCD_CH0_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH0_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH0_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_ECX_SHIFT)) & spp_dma5_TCD_CH0_ES_ECX_MASK)

#define spp_dma5_TCD_CH0_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH0_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH0_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_UCE_SHIFT)) & spp_dma5_TCD_CH0_ES_UCE_MASK)

#define spp_dma5_TCD_CH0_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH0_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH0_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH0_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_ES_ERR_SHIFT)) & spp_dma5_TCD_CH0_ES_ERR_MASK)
/*! @} */

/*! @name CH0_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH0_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH0_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH0_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH0_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_INT_INT_SHIFT)) & spp_dma5_TCD_CH0_INT_INT_MASK)
/*! @} */

/*! @name CH0_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH0_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH0_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH0_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH0_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_SBR_MID_SHIFT)) & spp_dma5_TCD_CH0_SBR_MID_MASK)

#define spp_dma5_TCD_CH0_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH0_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH0_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH0_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH0_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH0_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH0_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH0_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH0_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH0_SBR_PAL_MASK)

#define spp_dma5_TCD_CH0_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH0_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH0_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH0_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH0_SBR_EMI_MASK)
/*! @} */

/*! @name CH0_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH0_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH0_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH0_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH0_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_PRI_APL_SHIFT)) & spp_dma5_TCD_CH0_PRI_APL_MASK)

#define spp_dma5_TCD_CH0_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH0_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH0_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH0_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH0_PRI_DPA_MASK)

#define spp_dma5_TCD_CH0_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH0_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH0_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH0_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH0_PRI_ECP_MASK)
/*! @} */

/*! @name CH0_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH0_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH0_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH0_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH0_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH0_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH0_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH0_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH0_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH0_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH0_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH0_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD0_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD0_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD0_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD0_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD0_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD0_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD0_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD0_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD0_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD0_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD0_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD0_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD0_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD0_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD0_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD0_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD0_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD0_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD0_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD0_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD0_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD0_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD0_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD0_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD0_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD0_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD0_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD0_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD0_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD0_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD0_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD0_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD0_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD0_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD0_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD0_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD0_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD0_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD0_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD0_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD0_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD0_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD0_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD0_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD0_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD0_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD0_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD0_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD0_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD0_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD0_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD0_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD0_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD0_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD0_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD0_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_START_SHIFT)) & spp_dma5_TCD_TCD0_CSR_START_MASK)

#define spp_dma5_TCD_TCD0_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD0_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD0_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD0_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD0_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD0_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD0_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD0_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD0_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD0_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD0_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD0_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD0_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD0_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD0_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD0_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD0_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD0_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD0_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD0_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD0_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD0_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD0_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD0_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD0_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD0_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD0_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD0_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD0_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD0_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD0_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD0_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD0_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD0_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD0_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD0_CSR_TMC_MASK)
/*! @} */

/*! @name TCD0_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD0_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH1_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH1_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH1_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH1_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH1_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH1_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH1_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH1_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH1_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH1_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH1_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH1_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH1_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH1_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH1_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH1_CSR_EEI_MASK)

#define spp_dma5_TCD_CH1_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH1_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH1_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH1_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_CX_SHIFT)) & spp_dma5_TCD_CH1_CSR_CX_MASK)

#define spp_dma5_TCD_CH1_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH1_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH1_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH1_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH1_CSR_ECX_MASK)

#define spp_dma5_TCD_CH1_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH1_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH1_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH1_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH1_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH1_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH1_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH1_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH1_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH1_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH1_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH1_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH1_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH1_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH1_CSR_DONE_MASK)

#define spp_dma5_TCD_CH1_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH1_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH1_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH1_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH1_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH1_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH1_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH1_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH1_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_DBE_SHIFT)) & spp_dma5_TCD_CH1_ES_DBE_MASK)

#define spp_dma5_TCD_CH1_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH1_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH1_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_SBE_SHIFT)) & spp_dma5_TCD_CH1_ES_SBE_MASK)

#define spp_dma5_TCD_CH1_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH1_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH1_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_SGE_SHIFT)) & spp_dma5_TCD_CH1_ES_SGE_MASK)

#define spp_dma5_TCD_CH1_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH1_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH1_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_NCE_SHIFT)) & spp_dma5_TCD_CH1_ES_NCE_MASK)

#define spp_dma5_TCD_CH1_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH1_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH1_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_DOE_SHIFT)) & spp_dma5_TCD_CH1_ES_DOE_MASK)

#define spp_dma5_TCD_CH1_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH1_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH1_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_DAE_SHIFT)) & spp_dma5_TCD_CH1_ES_DAE_MASK)

#define spp_dma5_TCD_CH1_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH1_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH1_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_SOE_SHIFT)) & spp_dma5_TCD_CH1_ES_SOE_MASK)

#define spp_dma5_TCD_CH1_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH1_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH1_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_SAE_SHIFT)) & spp_dma5_TCD_CH1_ES_SAE_MASK)

#define spp_dma5_TCD_CH1_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH1_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH1_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_ECX_SHIFT)) & spp_dma5_TCD_CH1_ES_ECX_MASK)

#define spp_dma5_TCD_CH1_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH1_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH1_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_UCE_SHIFT)) & spp_dma5_TCD_CH1_ES_UCE_MASK)

#define spp_dma5_TCD_CH1_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH1_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH1_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH1_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_ES_ERR_SHIFT)) & spp_dma5_TCD_CH1_ES_ERR_MASK)
/*! @} */

/*! @name CH1_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH1_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH1_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH1_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH1_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_INT_INT_SHIFT)) & spp_dma5_TCD_CH1_INT_INT_MASK)
/*! @} */

/*! @name CH1_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH1_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH1_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH1_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH1_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_SBR_MID_SHIFT)) & spp_dma5_TCD_CH1_SBR_MID_MASK)

#define spp_dma5_TCD_CH1_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH1_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH1_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH1_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH1_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH1_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH1_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH1_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH1_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH1_SBR_PAL_MASK)

#define spp_dma5_TCD_CH1_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH1_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH1_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH1_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH1_SBR_EMI_MASK)
/*! @} */

/*! @name CH1_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH1_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH1_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH1_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH1_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_PRI_APL_SHIFT)) & spp_dma5_TCD_CH1_PRI_APL_MASK)

#define spp_dma5_TCD_CH1_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH1_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH1_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH1_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH1_PRI_DPA_MASK)

#define spp_dma5_TCD_CH1_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH1_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH1_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH1_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH1_PRI_ECP_MASK)
/*! @} */

/*! @name CH1_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH1_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH1_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH1_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH1_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH1_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH1_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH1_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH1_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH1_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH1_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH1_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD1_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD1_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD1_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD1_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD1_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD1_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD1_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD1_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD1_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD1_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD1_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD1_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD1_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD1_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD1_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD1_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD1_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD1_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD1_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD1_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD1_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD1_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD1_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD1_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD1_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD1_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD1_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD1_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD1_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD1_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD1_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD1_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD1_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD1_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD1_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD1_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD1_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD1_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD1_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD1_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD1_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD1_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD1_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD1_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD1_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD1_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD1_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD1_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD1_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD1_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD1_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD1_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD1_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD1_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD1_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD1_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD1_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD1_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD1_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD1_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD1_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD1_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD1_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD1_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD1_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD1_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD1_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD1_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD1_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD1_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD1_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD1_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD1_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD1_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD1_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD1_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD1_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD1_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD1_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD1_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD1_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD1_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD1_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD1_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD1_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD1_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD1_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD1_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD1_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD1_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD1_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD1_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD1_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD1_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_START_SHIFT)) & spp_dma5_TCD_TCD1_CSR_START_MASK)

#define spp_dma5_TCD_TCD1_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD1_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD1_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD1_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD1_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD1_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD1_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD1_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD1_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD1_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD1_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD1_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD1_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD1_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD1_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD1_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD1_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD1_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD1_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD1_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD1_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD1_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD1_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD1_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD1_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD1_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD1_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD1_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD1_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD1_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD1_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD1_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD1_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD1_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD1_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD1_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD1_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD1_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD1_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD1_CSR_TMC_MASK)
/*! @} */

/*! @name TCD1_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD1_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD1_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD1_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD1_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD1_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD1_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD1_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD1_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD1_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD1_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD1_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD1_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD1_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD1_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD1_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD1_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD1_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD1_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD1_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH2_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH2_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH2_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH2_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH2_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH2_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH2_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH2_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH2_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH2_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH2_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH2_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH2_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH2_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH2_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH2_CSR_EEI_MASK)

#define spp_dma5_TCD_CH2_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH2_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH2_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH2_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_CX_SHIFT)) & spp_dma5_TCD_CH2_CSR_CX_MASK)

#define spp_dma5_TCD_CH2_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH2_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH2_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH2_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH2_CSR_ECX_MASK)

#define spp_dma5_TCD_CH2_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH2_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH2_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH2_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH2_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH2_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH2_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH2_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH2_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH2_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH2_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH2_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH2_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH2_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH2_CSR_DONE_MASK)

#define spp_dma5_TCD_CH2_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH2_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH2_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH2_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH2_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH2_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH2_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH2_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH2_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_DBE_SHIFT)) & spp_dma5_TCD_CH2_ES_DBE_MASK)

#define spp_dma5_TCD_CH2_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH2_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH2_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_SBE_SHIFT)) & spp_dma5_TCD_CH2_ES_SBE_MASK)

#define spp_dma5_TCD_CH2_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH2_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH2_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_SGE_SHIFT)) & spp_dma5_TCD_CH2_ES_SGE_MASK)

#define spp_dma5_TCD_CH2_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH2_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH2_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_NCE_SHIFT)) & spp_dma5_TCD_CH2_ES_NCE_MASK)

#define spp_dma5_TCD_CH2_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH2_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH2_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_DOE_SHIFT)) & spp_dma5_TCD_CH2_ES_DOE_MASK)

#define spp_dma5_TCD_CH2_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH2_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH2_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_DAE_SHIFT)) & spp_dma5_TCD_CH2_ES_DAE_MASK)

#define spp_dma5_TCD_CH2_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH2_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH2_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_SOE_SHIFT)) & spp_dma5_TCD_CH2_ES_SOE_MASK)

#define spp_dma5_TCD_CH2_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH2_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH2_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_SAE_SHIFT)) & spp_dma5_TCD_CH2_ES_SAE_MASK)

#define spp_dma5_TCD_CH2_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH2_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH2_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_ECX_SHIFT)) & spp_dma5_TCD_CH2_ES_ECX_MASK)

#define spp_dma5_TCD_CH2_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH2_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH2_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_UCE_SHIFT)) & spp_dma5_TCD_CH2_ES_UCE_MASK)

#define spp_dma5_TCD_CH2_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH2_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH2_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH2_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_ES_ERR_SHIFT)) & spp_dma5_TCD_CH2_ES_ERR_MASK)
/*! @} */

/*! @name CH2_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH2_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH2_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH2_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH2_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_INT_INT_SHIFT)) & spp_dma5_TCD_CH2_INT_INT_MASK)
/*! @} */

/*! @name CH2_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH2_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH2_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH2_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH2_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_SBR_MID_SHIFT)) & spp_dma5_TCD_CH2_SBR_MID_MASK)

#define spp_dma5_TCD_CH2_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH2_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH2_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH2_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH2_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH2_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH2_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH2_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH2_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH2_SBR_PAL_MASK)

#define spp_dma5_TCD_CH2_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH2_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH2_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH2_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH2_SBR_EMI_MASK)
/*! @} */

/*! @name CH2_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH2_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH2_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH2_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH2_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_PRI_APL_SHIFT)) & spp_dma5_TCD_CH2_PRI_APL_MASK)

#define spp_dma5_TCD_CH2_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH2_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH2_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH2_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH2_PRI_DPA_MASK)

#define spp_dma5_TCD_CH2_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH2_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH2_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH2_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH2_PRI_ECP_MASK)
/*! @} */

/*! @name CH2_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH2_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH2_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH2_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH2_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH2_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH2_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH2_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH2_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH2_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH2_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH2_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD2_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD2_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD2_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD2_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD2_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD2_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD2_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD2_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD2_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD2_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD2_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD2_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD2_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD2_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD2_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD2_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD2_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD2_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD2_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD2_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD2_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD2_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD2_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD2_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD2_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD2_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD2_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD2_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD2_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD2_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD2_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD2_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD2_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD2_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD2_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD2_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD2_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD2_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD2_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD2_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD2_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD2_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD2_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD2_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD2_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD2_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD2_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD2_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD2_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD2_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD2_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD2_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD2_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD2_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD2_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD2_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD2_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD2_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD2_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD2_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD2_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD2_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD2_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD2_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD2_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD2_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD2_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD2_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD2_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD2_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD2_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD2_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD2_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD2_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD2_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD2_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD2_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD2_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD2_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD2_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD2_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD2_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD2_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD2_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD2_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD2_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD2_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD2_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD2_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD2_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD2_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD2_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD2_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD2_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_START_SHIFT)) & spp_dma5_TCD_TCD2_CSR_START_MASK)

#define spp_dma5_TCD_TCD2_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD2_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD2_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD2_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD2_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD2_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD2_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD2_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD2_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD2_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD2_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD2_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD2_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD2_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD2_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD2_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD2_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD2_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD2_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD2_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD2_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD2_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD2_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD2_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD2_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD2_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD2_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD2_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD2_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD2_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD2_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD2_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD2_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD2_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD2_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD2_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD2_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD2_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD2_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD2_CSR_TMC_MASK)
/*! @} */

/*! @name TCD2_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD2_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD2_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD2_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD2_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD2_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD2_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD2_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD2_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD2_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD2_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD2_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD2_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD2_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD2_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD2_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD2_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD2_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD2_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD2_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH3_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH3_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH3_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH3_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH3_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH3_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH3_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH3_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH3_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH3_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH3_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH3_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH3_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH3_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH3_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH3_CSR_EEI_MASK)

#define spp_dma5_TCD_CH3_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH3_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH3_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH3_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_CX_SHIFT)) & spp_dma5_TCD_CH3_CSR_CX_MASK)

#define spp_dma5_TCD_CH3_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH3_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH3_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH3_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH3_CSR_ECX_MASK)

#define spp_dma5_TCD_CH3_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH3_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH3_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH3_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH3_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH3_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH3_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH3_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH3_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH3_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH3_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH3_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH3_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH3_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH3_CSR_DONE_MASK)

#define spp_dma5_TCD_CH3_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH3_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH3_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH3_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH3_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH3_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH3_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH3_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH3_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_DBE_SHIFT)) & spp_dma5_TCD_CH3_ES_DBE_MASK)

#define spp_dma5_TCD_CH3_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH3_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH3_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_SBE_SHIFT)) & spp_dma5_TCD_CH3_ES_SBE_MASK)

#define spp_dma5_TCD_CH3_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH3_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH3_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_SGE_SHIFT)) & spp_dma5_TCD_CH3_ES_SGE_MASK)

#define spp_dma5_TCD_CH3_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH3_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH3_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_NCE_SHIFT)) & spp_dma5_TCD_CH3_ES_NCE_MASK)

#define spp_dma5_TCD_CH3_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH3_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH3_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_DOE_SHIFT)) & spp_dma5_TCD_CH3_ES_DOE_MASK)

#define spp_dma5_TCD_CH3_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH3_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH3_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_DAE_SHIFT)) & spp_dma5_TCD_CH3_ES_DAE_MASK)

#define spp_dma5_TCD_CH3_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH3_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH3_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_SOE_SHIFT)) & spp_dma5_TCD_CH3_ES_SOE_MASK)

#define spp_dma5_TCD_CH3_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH3_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH3_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_SAE_SHIFT)) & spp_dma5_TCD_CH3_ES_SAE_MASK)

#define spp_dma5_TCD_CH3_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH3_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH3_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_ECX_SHIFT)) & spp_dma5_TCD_CH3_ES_ECX_MASK)

#define spp_dma5_TCD_CH3_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH3_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH3_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_UCE_SHIFT)) & spp_dma5_TCD_CH3_ES_UCE_MASK)

#define spp_dma5_TCD_CH3_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH3_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH3_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH3_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_ES_ERR_SHIFT)) & spp_dma5_TCD_CH3_ES_ERR_MASK)
/*! @} */

/*! @name CH3_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH3_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH3_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH3_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH3_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_INT_INT_SHIFT)) & spp_dma5_TCD_CH3_INT_INT_MASK)
/*! @} */

/*! @name CH3_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH3_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH3_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH3_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH3_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_SBR_MID_SHIFT)) & spp_dma5_TCD_CH3_SBR_MID_MASK)

#define spp_dma5_TCD_CH3_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH3_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH3_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH3_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH3_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH3_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH3_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH3_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH3_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH3_SBR_PAL_MASK)

#define spp_dma5_TCD_CH3_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH3_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH3_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH3_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH3_SBR_EMI_MASK)
/*! @} */

/*! @name CH3_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH3_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH3_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH3_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH3_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_PRI_APL_SHIFT)) & spp_dma5_TCD_CH3_PRI_APL_MASK)

#define spp_dma5_TCD_CH3_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH3_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH3_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH3_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH3_PRI_DPA_MASK)

#define spp_dma5_TCD_CH3_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH3_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH3_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH3_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH3_PRI_ECP_MASK)
/*! @} */

/*! @name CH3_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH3_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH3_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH3_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH3_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH3_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH3_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH3_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH3_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH3_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH3_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH3_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD3_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD3_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD3_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD3_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD3_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD3_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD3_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD3_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD3_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD3_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD3_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD3_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD3_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD3_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD3_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD3_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD3_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD3_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD3_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD3_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD3_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD3_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD3_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD3_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD3_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD3_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD3_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD3_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD3_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD3_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD3_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD3_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD3_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD3_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD3_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD3_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD3_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD3_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD3_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD3_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD3_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD3_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD3_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD3_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD3_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD3_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD3_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD3_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD3_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD3_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD3_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD3_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD3_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD3_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD3_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD3_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD3_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD3_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD3_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD3_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD3_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD3_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD3_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD3_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD3_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD3_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD3_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD3_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD3_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD3_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD3_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD3_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD3_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD3_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD3_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD3_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD3_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD3_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD3_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD3_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD3_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD3_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD3_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD3_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD3_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD3_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD3_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD3_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD3_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD3_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD3_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD3_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD3_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD3_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_START_SHIFT)) & spp_dma5_TCD_TCD3_CSR_START_MASK)

#define spp_dma5_TCD_TCD3_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD3_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD3_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD3_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD3_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD3_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD3_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD3_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD3_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD3_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD3_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD3_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD3_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD3_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD3_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD3_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD3_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD3_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD3_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD3_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD3_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD3_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD3_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD3_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD3_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD3_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD3_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD3_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD3_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD3_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD3_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD3_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD3_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD3_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD3_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD3_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD3_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD3_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD3_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD3_CSR_TMC_MASK)
/*! @} */

/*! @name TCD3_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD3_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD3_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD3_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD3_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD3_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD3_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD3_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD3_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD3_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD3_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD3_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD3_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD3_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD3_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD3_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD3_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD3_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD3_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD3_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH4_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH4_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH4_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH4_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH4_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH4_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH4_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH4_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH4_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH4_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH4_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH4_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH4_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH4_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH4_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH4_CSR_EEI_MASK)

#define spp_dma5_TCD_CH4_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH4_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH4_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH4_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_CX_SHIFT)) & spp_dma5_TCD_CH4_CSR_CX_MASK)

#define spp_dma5_TCD_CH4_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH4_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH4_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH4_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH4_CSR_ECX_MASK)

#define spp_dma5_TCD_CH4_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH4_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH4_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH4_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH4_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH4_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH4_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH4_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH4_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH4_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH4_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH4_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH4_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH4_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH4_CSR_DONE_MASK)

#define spp_dma5_TCD_CH4_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH4_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH4_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH4_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH4_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH4_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH4_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH4_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH4_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_DBE_SHIFT)) & spp_dma5_TCD_CH4_ES_DBE_MASK)

#define spp_dma5_TCD_CH4_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH4_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH4_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_SBE_SHIFT)) & spp_dma5_TCD_CH4_ES_SBE_MASK)

#define spp_dma5_TCD_CH4_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH4_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH4_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_SGE_SHIFT)) & spp_dma5_TCD_CH4_ES_SGE_MASK)

#define spp_dma5_TCD_CH4_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH4_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH4_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_NCE_SHIFT)) & spp_dma5_TCD_CH4_ES_NCE_MASK)

#define spp_dma5_TCD_CH4_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH4_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH4_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_DOE_SHIFT)) & spp_dma5_TCD_CH4_ES_DOE_MASK)

#define spp_dma5_TCD_CH4_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH4_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH4_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_DAE_SHIFT)) & spp_dma5_TCD_CH4_ES_DAE_MASK)

#define spp_dma5_TCD_CH4_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH4_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH4_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_SOE_SHIFT)) & spp_dma5_TCD_CH4_ES_SOE_MASK)

#define spp_dma5_TCD_CH4_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH4_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH4_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_SAE_SHIFT)) & spp_dma5_TCD_CH4_ES_SAE_MASK)

#define spp_dma5_TCD_CH4_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH4_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH4_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_ECX_SHIFT)) & spp_dma5_TCD_CH4_ES_ECX_MASK)

#define spp_dma5_TCD_CH4_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH4_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH4_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_UCE_SHIFT)) & spp_dma5_TCD_CH4_ES_UCE_MASK)

#define spp_dma5_TCD_CH4_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH4_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH4_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH4_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_ES_ERR_SHIFT)) & spp_dma5_TCD_CH4_ES_ERR_MASK)
/*! @} */

/*! @name CH4_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH4_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH4_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH4_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH4_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_INT_INT_SHIFT)) & spp_dma5_TCD_CH4_INT_INT_MASK)
/*! @} */

/*! @name CH4_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH4_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH4_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH4_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH4_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_SBR_MID_SHIFT)) & spp_dma5_TCD_CH4_SBR_MID_MASK)

#define spp_dma5_TCD_CH4_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH4_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH4_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH4_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH4_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH4_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH4_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH4_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH4_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH4_SBR_PAL_MASK)

#define spp_dma5_TCD_CH4_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH4_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH4_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH4_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH4_SBR_EMI_MASK)
/*! @} */

/*! @name CH4_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH4_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH4_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH4_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH4_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_PRI_APL_SHIFT)) & spp_dma5_TCD_CH4_PRI_APL_MASK)

#define spp_dma5_TCD_CH4_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH4_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH4_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH4_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH4_PRI_DPA_MASK)

#define spp_dma5_TCD_CH4_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH4_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH4_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH4_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH4_PRI_ECP_MASK)
/*! @} */

/*! @name CH4_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH4_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH4_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH4_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH4_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH4_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH4_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH4_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH4_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH4_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH4_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH4_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD4_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD4_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD4_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD4_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD4_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD4_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD4_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD4_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD4_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD4_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD4_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD4_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD4_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD4_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD4_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD4_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD4_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD4_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD4_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD4_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD4_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD4_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD4_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD4_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD4_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD4_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD4_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD4_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD4_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD4_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD4_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD4_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD4_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD4_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD4_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD4_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD4_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD4_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD4_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD4_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD4_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD4_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD4_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD4_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD4_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD4_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD4_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD4_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD4_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD4_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD4_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD4_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD4_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD4_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD4_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD4_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD4_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD4_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD4_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD4_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD4_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD4_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD4_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD4_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD4_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD4_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD4_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD4_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD4_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD4_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD4_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD4_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD4_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD4_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD4_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD4_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD4_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD4_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD4_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD4_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD4_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD4_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD4_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD4_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD4_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD4_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD4_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD4_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD4_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD4_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD4_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD4_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD4_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD4_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_START_SHIFT)) & spp_dma5_TCD_TCD4_CSR_START_MASK)

#define spp_dma5_TCD_TCD4_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD4_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD4_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD4_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD4_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD4_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD4_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD4_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD4_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD4_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD4_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD4_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD4_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD4_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD4_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD4_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD4_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD4_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD4_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD4_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD4_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD4_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD4_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD4_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD4_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD4_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD4_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD4_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD4_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD4_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD4_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD4_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD4_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD4_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD4_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD4_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD4_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD4_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD4_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD4_CSR_TMC_MASK)
/*! @} */

/*! @name TCD4_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD4_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD4_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD4_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD4_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD4_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD4_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD4_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD4_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD4_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD4_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD4_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD4_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD4_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD4_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD4_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD4_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD4_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD4_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD4_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH5_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH5_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH5_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH5_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH5_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH5_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH5_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH5_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH5_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH5_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH5_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH5_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH5_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH5_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH5_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH5_CSR_EEI_MASK)

#define spp_dma5_TCD_CH5_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH5_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH5_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH5_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_CX_SHIFT)) & spp_dma5_TCD_CH5_CSR_CX_MASK)

#define spp_dma5_TCD_CH5_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH5_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH5_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH5_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH5_CSR_ECX_MASK)

#define spp_dma5_TCD_CH5_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH5_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH5_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH5_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH5_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH5_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH5_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH5_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH5_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH5_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH5_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH5_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH5_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH5_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH5_CSR_DONE_MASK)

#define spp_dma5_TCD_CH5_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH5_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH5_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH5_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH5_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH5_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH5_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH5_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH5_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_DBE_SHIFT)) & spp_dma5_TCD_CH5_ES_DBE_MASK)

#define spp_dma5_TCD_CH5_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH5_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH5_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_SBE_SHIFT)) & spp_dma5_TCD_CH5_ES_SBE_MASK)

#define spp_dma5_TCD_CH5_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH5_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH5_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_SGE_SHIFT)) & spp_dma5_TCD_CH5_ES_SGE_MASK)

#define spp_dma5_TCD_CH5_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH5_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH5_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_NCE_SHIFT)) & spp_dma5_TCD_CH5_ES_NCE_MASK)

#define spp_dma5_TCD_CH5_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH5_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH5_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_DOE_SHIFT)) & spp_dma5_TCD_CH5_ES_DOE_MASK)

#define spp_dma5_TCD_CH5_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH5_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH5_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_DAE_SHIFT)) & spp_dma5_TCD_CH5_ES_DAE_MASK)

#define spp_dma5_TCD_CH5_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH5_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH5_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_SOE_SHIFT)) & spp_dma5_TCD_CH5_ES_SOE_MASK)

#define spp_dma5_TCD_CH5_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH5_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH5_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_SAE_SHIFT)) & spp_dma5_TCD_CH5_ES_SAE_MASK)

#define spp_dma5_TCD_CH5_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH5_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH5_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_ECX_SHIFT)) & spp_dma5_TCD_CH5_ES_ECX_MASK)

#define spp_dma5_TCD_CH5_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH5_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH5_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_UCE_SHIFT)) & spp_dma5_TCD_CH5_ES_UCE_MASK)

#define spp_dma5_TCD_CH5_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH5_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH5_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH5_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_ES_ERR_SHIFT)) & spp_dma5_TCD_CH5_ES_ERR_MASK)
/*! @} */

/*! @name CH5_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH5_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH5_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH5_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH5_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_INT_INT_SHIFT)) & spp_dma5_TCD_CH5_INT_INT_MASK)
/*! @} */

/*! @name CH5_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH5_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH5_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH5_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH5_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_SBR_MID_SHIFT)) & spp_dma5_TCD_CH5_SBR_MID_MASK)

#define spp_dma5_TCD_CH5_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH5_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH5_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH5_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH5_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH5_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH5_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH5_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH5_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH5_SBR_PAL_MASK)

#define spp_dma5_TCD_CH5_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH5_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH5_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH5_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH5_SBR_EMI_MASK)
/*! @} */

/*! @name CH5_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH5_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH5_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH5_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH5_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_PRI_APL_SHIFT)) & spp_dma5_TCD_CH5_PRI_APL_MASK)

#define spp_dma5_TCD_CH5_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH5_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH5_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH5_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH5_PRI_DPA_MASK)

#define spp_dma5_TCD_CH5_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH5_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH5_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH5_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH5_PRI_ECP_MASK)
/*! @} */

/*! @name CH5_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH5_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH5_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH5_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH5_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH5_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH5_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH5_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH5_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH5_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH5_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH5_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD5_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD5_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD5_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD5_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD5_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD5_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD5_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD5_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD5_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD5_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD5_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD5_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD5_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD5_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD5_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD5_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD5_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD5_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD5_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD5_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD5_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD5_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD5_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD5_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD5_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD5_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD5_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD5_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD5_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD5_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD5_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD5_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD5_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD5_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD5_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD5_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD5_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD5_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD5_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD5_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD5_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD5_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD5_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD5_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD5_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD5_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD5_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD5_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD5_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD5_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD5_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD5_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD5_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD5_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD5_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD5_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD5_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD5_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD5_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD5_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD5_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD5_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD5_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD5_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD5_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD5_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD5_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD5_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD5_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD5_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD5_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD5_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD5_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD5_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD5_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD5_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD5_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD5_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD5_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD5_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD5_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD5_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD5_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD5_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD5_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD5_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD5_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD5_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD5_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD5_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD5_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD5_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD5_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD5_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_START_SHIFT)) & spp_dma5_TCD_TCD5_CSR_START_MASK)

#define spp_dma5_TCD_TCD5_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD5_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD5_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD5_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD5_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD5_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD5_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD5_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD5_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD5_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD5_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD5_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD5_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD5_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD5_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD5_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD5_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD5_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD5_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD5_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD5_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD5_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD5_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD5_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD5_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD5_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD5_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD5_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD5_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD5_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD5_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD5_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD5_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD5_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD5_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD5_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD5_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD5_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD5_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD5_CSR_TMC_MASK)
/*! @} */

/*! @name TCD5_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD5_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD5_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD5_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD5_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD5_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD5_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD5_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD5_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD5_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD5_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD5_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD5_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD5_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD5_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD5_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD5_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD5_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD5_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD5_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH6_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH6_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH6_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH6_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH6_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH6_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH6_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH6_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH6_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH6_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH6_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH6_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH6_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH6_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH6_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH6_CSR_EEI_MASK)

#define spp_dma5_TCD_CH6_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH6_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH6_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH6_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_CX_SHIFT)) & spp_dma5_TCD_CH6_CSR_CX_MASK)

#define spp_dma5_TCD_CH6_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH6_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH6_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH6_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH6_CSR_ECX_MASK)

#define spp_dma5_TCD_CH6_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH6_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH6_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH6_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH6_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH6_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH6_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH6_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH6_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH6_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH6_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH6_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH6_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH6_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH6_CSR_DONE_MASK)

#define spp_dma5_TCD_CH6_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH6_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH6_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH6_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH6_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH6_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH6_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH6_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH6_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_DBE_SHIFT)) & spp_dma5_TCD_CH6_ES_DBE_MASK)

#define spp_dma5_TCD_CH6_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH6_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH6_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_SBE_SHIFT)) & spp_dma5_TCD_CH6_ES_SBE_MASK)

#define spp_dma5_TCD_CH6_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH6_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH6_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_SGE_SHIFT)) & spp_dma5_TCD_CH6_ES_SGE_MASK)

#define spp_dma5_TCD_CH6_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH6_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH6_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_NCE_SHIFT)) & spp_dma5_TCD_CH6_ES_NCE_MASK)

#define spp_dma5_TCD_CH6_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH6_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH6_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_DOE_SHIFT)) & spp_dma5_TCD_CH6_ES_DOE_MASK)

#define spp_dma5_TCD_CH6_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH6_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH6_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_DAE_SHIFT)) & spp_dma5_TCD_CH6_ES_DAE_MASK)

#define spp_dma5_TCD_CH6_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH6_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH6_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_SOE_SHIFT)) & spp_dma5_TCD_CH6_ES_SOE_MASK)

#define spp_dma5_TCD_CH6_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH6_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH6_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_SAE_SHIFT)) & spp_dma5_TCD_CH6_ES_SAE_MASK)

#define spp_dma5_TCD_CH6_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH6_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH6_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_ECX_SHIFT)) & spp_dma5_TCD_CH6_ES_ECX_MASK)

#define spp_dma5_TCD_CH6_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH6_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH6_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_UCE_SHIFT)) & spp_dma5_TCD_CH6_ES_UCE_MASK)

#define spp_dma5_TCD_CH6_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH6_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH6_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH6_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_ES_ERR_SHIFT)) & spp_dma5_TCD_CH6_ES_ERR_MASK)
/*! @} */

/*! @name CH6_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH6_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH6_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH6_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH6_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_INT_INT_SHIFT)) & spp_dma5_TCD_CH6_INT_INT_MASK)
/*! @} */

/*! @name CH6_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH6_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH6_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH6_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH6_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_SBR_MID_SHIFT)) & spp_dma5_TCD_CH6_SBR_MID_MASK)

#define spp_dma5_TCD_CH6_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH6_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH6_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH6_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH6_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH6_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH6_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH6_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH6_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH6_SBR_PAL_MASK)

#define spp_dma5_TCD_CH6_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH6_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH6_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH6_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH6_SBR_EMI_MASK)
/*! @} */

/*! @name CH6_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH6_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH6_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH6_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH6_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_PRI_APL_SHIFT)) & spp_dma5_TCD_CH6_PRI_APL_MASK)

#define spp_dma5_TCD_CH6_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH6_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH6_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH6_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH6_PRI_DPA_MASK)

#define spp_dma5_TCD_CH6_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH6_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH6_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH6_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH6_PRI_ECP_MASK)
/*! @} */

/*! @name CH6_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH6_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH6_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH6_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH6_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH6_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH6_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH6_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH6_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH6_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH6_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH6_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD6_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD6_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD6_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD6_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD6_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD6_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD6_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD6_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD6_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD6_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD6_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD6_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD6_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD6_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD6_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD6_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD6_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD6_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD6_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD6_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD6_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD6_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD6_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD6_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD6_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD6_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD6_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD6_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD6_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD6_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD6_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD6_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD6_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD6_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD6_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD6_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD6_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD6_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD6_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD6_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD6_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD6_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD6_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD6_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD6_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD6_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD6_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD6_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD6_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD6_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD6_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD6_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD6_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD6_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD6_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD6_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD6_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD6_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD6_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD6_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD6_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD6_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD6_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD6_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD6_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD6_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD6_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD6_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD6_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD6_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD6_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD6_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD6_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD6_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD6_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD6_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD6_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD6_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD6_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD6_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD6_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD6_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD6_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD6_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD6_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD6_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD6_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD6_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD6_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD6_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD6_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD6_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD6_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD6_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_START_SHIFT)) & spp_dma5_TCD_TCD6_CSR_START_MASK)

#define spp_dma5_TCD_TCD6_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD6_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD6_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD6_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD6_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD6_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD6_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD6_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD6_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD6_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD6_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD6_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD6_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD6_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD6_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD6_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD6_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD6_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD6_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD6_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD6_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD6_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD6_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD6_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD6_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD6_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD6_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD6_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD6_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD6_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD6_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD6_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD6_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD6_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD6_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD6_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD6_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD6_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD6_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD6_CSR_TMC_MASK)
/*! @} */

/*! @name TCD6_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD6_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD6_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD6_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD6_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD6_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD6_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD6_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD6_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD6_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD6_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD6_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD6_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD6_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD6_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD6_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD6_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD6_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD6_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD6_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH7_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH7_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH7_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH7_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH7_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH7_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH7_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH7_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH7_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH7_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH7_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH7_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH7_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH7_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH7_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH7_CSR_EEI_MASK)

#define spp_dma5_TCD_CH7_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH7_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH7_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH7_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_CX_SHIFT)) & spp_dma5_TCD_CH7_CSR_CX_MASK)

#define spp_dma5_TCD_CH7_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH7_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH7_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH7_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH7_CSR_ECX_MASK)

#define spp_dma5_TCD_CH7_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH7_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH7_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH7_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH7_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH7_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH7_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH7_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH7_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH7_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH7_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH7_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH7_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH7_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH7_CSR_DONE_MASK)

#define spp_dma5_TCD_CH7_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH7_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH7_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH7_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH7_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH7_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH7_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH7_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH7_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_DBE_SHIFT)) & spp_dma5_TCD_CH7_ES_DBE_MASK)

#define spp_dma5_TCD_CH7_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH7_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH7_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_SBE_SHIFT)) & spp_dma5_TCD_CH7_ES_SBE_MASK)

#define spp_dma5_TCD_CH7_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH7_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH7_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_SGE_SHIFT)) & spp_dma5_TCD_CH7_ES_SGE_MASK)

#define spp_dma5_TCD_CH7_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH7_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH7_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_NCE_SHIFT)) & spp_dma5_TCD_CH7_ES_NCE_MASK)

#define spp_dma5_TCD_CH7_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH7_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH7_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_DOE_SHIFT)) & spp_dma5_TCD_CH7_ES_DOE_MASK)

#define spp_dma5_TCD_CH7_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH7_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH7_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_DAE_SHIFT)) & spp_dma5_TCD_CH7_ES_DAE_MASK)

#define spp_dma5_TCD_CH7_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH7_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH7_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_SOE_SHIFT)) & spp_dma5_TCD_CH7_ES_SOE_MASK)

#define spp_dma5_TCD_CH7_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH7_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH7_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_SAE_SHIFT)) & spp_dma5_TCD_CH7_ES_SAE_MASK)

#define spp_dma5_TCD_CH7_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH7_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH7_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_ECX_SHIFT)) & spp_dma5_TCD_CH7_ES_ECX_MASK)

#define spp_dma5_TCD_CH7_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH7_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH7_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_UCE_SHIFT)) & spp_dma5_TCD_CH7_ES_UCE_MASK)

#define spp_dma5_TCD_CH7_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH7_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH7_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH7_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_ES_ERR_SHIFT)) & spp_dma5_TCD_CH7_ES_ERR_MASK)
/*! @} */

/*! @name CH7_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH7_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH7_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH7_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH7_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_INT_INT_SHIFT)) & spp_dma5_TCD_CH7_INT_INT_MASK)
/*! @} */

/*! @name CH7_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH7_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH7_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH7_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH7_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_SBR_MID_SHIFT)) & spp_dma5_TCD_CH7_SBR_MID_MASK)

#define spp_dma5_TCD_CH7_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH7_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH7_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH7_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH7_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH7_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH7_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH7_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH7_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH7_SBR_PAL_MASK)

#define spp_dma5_TCD_CH7_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH7_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH7_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH7_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH7_SBR_EMI_MASK)
/*! @} */

/*! @name CH7_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH7_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH7_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH7_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH7_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_PRI_APL_SHIFT)) & spp_dma5_TCD_CH7_PRI_APL_MASK)

#define spp_dma5_TCD_CH7_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH7_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH7_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH7_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH7_PRI_DPA_MASK)

#define spp_dma5_TCD_CH7_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH7_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH7_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH7_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH7_PRI_ECP_MASK)
/*! @} */

/*! @name CH7_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH7_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH7_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH7_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH7_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH7_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH7_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH7_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH7_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH7_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH7_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH7_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD7_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD7_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD7_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD7_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD7_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD7_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD7_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD7_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD7_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD7_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD7_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD7_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD7_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD7_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD7_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD7_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD7_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD7_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD7_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD7_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD7_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD7_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD7_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD7_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD7_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD7_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD7_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD7_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD7_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD7_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD7_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD7_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD7_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD7_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD7_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD7_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD7_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD7_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD7_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD7_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD7_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD7_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD7_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD7_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD7_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD7_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD7_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD7_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD7_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD7_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD7_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD7_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD7_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD7_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD7_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD7_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD7_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD7_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD7_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD7_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD7_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD7_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD7_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD7_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD7_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD7_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD7_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD7_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD7_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD7_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD7_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD7_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD7_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD7_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD7_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD7_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD7_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD7_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD7_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD7_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD7_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD7_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD7_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD7_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD7_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD7_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD7_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD7_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD7_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD7_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD7_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD7_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD7_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD7_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_START_SHIFT)) & spp_dma5_TCD_TCD7_CSR_START_MASK)

#define spp_dma5_TCD_TCD7_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD7_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD7_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD7_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD7_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD7_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD7_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD7_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD7_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD7_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD7_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD7_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD7_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD7_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD7_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD7_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD7_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD7_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD7_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD7_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD7_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD7_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD7_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD7_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD7_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD7_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD7_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD7_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD7_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD7_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD7_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD7_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD7_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD7_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD7_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD7_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD7_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD7_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD7_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD7_CSR_TMC_MASK)
/*! @} */

/*! @name TCD7_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD7_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD7_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD7_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD7_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD7_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD7_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD7_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD7_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD7_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD7_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD7_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD7_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD7_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD7_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD7_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD7_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD7_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD7_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD7_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH8_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH8_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH8_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH8_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH8_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH8_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH8_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH8_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH8_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH8_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH8_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH8_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH8_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH8_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH8_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH8_CSR_EEI_MASK)

#define spp_dma5_TCD_CH8_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH8_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH8_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH8_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_CX_SHIFT)) & spp_dma5_TCD_CH8_CSR_CX_MASK)

#define spp_dma5_TCD_CH8_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH8_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH8_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH8_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH8_CSR_ECX_MASK)

#define spp_dma5_TCD_CH8_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH8_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH8_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH8_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH8_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH8_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH8_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH8_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH8_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH8_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH8_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH8_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH8_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH8_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH8_CSR_DONE_MASK)

#define spp_dma5_TCD_CH8_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH8_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH8_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH8_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH8_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH8_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH8_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH8_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH8_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_DBE_SHIFT)) & spp_dma5_TCD_CH8_ES_DBE_MASK)

#define spp_dma5_TCD_CH8_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH8_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH8_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_SBE_SHIFT)) & spp_dma5_TCD_CH8_ES_SBE_MASK)

#define spp_dma5_TCD_CH8_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH8_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH8_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_SGE_SHIFT)) & spp_dma5_TCD_CH8_ES_SGE_MASK)

#define spp_dma5_TCD_CH8_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH8_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH8_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_NCE_SHIFT)) & spp_dma5_TCD_CH8_ES_NCE_MASK)

#define spp_dma5_TCD_CH8_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH8_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH8_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_DOE_SHIFT)) & spp_dma5_TCD_CH8_ES_DOE_MASK)

#define spp_dma5_TCD_CH8_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH8_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH8_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_DAE_SHIFT)) & spp_dma5_TCD_CH8_ES_DAE_MASK)

#define spp_dma5_TCD_CH8_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH8_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH8_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_SOE_SHIFT)) & spp_dma5_TCD_CH8_ES_SOE_MASK)

#define spp_dma5_TCD_CH8_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH8_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH8_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_SAE_SHIFT)) & spp_dma5_TCD_CH8_ES_SAE_MASK)

#define spp_dma5_TCD_CH8_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH8_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH8_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_ECX_SHIFT)) & spp_dma5_TCD_CH8_ES_ECX_MASK)

#define spp_dma5_TCD_CH8_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH8_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH8_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_UCE_SHIFT)) & spp_dma5_TCD_CH8_ES_UCE_MASK)

#define spp_dma5_TCD_CH8_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH8_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH8_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH8_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_ES_ERR_SHIFT)) & spp_dma5_TCD_CH8_ES_ERR_MASK)
/*! @} */

/*! @name CH8_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH8_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH8_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH8_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH8_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_INT_INT_SHIFT)) & spp_dma5_TCD_CH8_INT_INT_MASK)
/*! @} */

/*! @name CH8_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH8_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH8_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH8_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH8_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_SBR_MID_SHIFT)) & spp_dma5_TCD_CH8_SBR_MID_MASK)

#define spp_dma5_TCD_CH8_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH8_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH8_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH8_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH8_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH8_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH8_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH8_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH8_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH8_SBR_PAL_MASK)

#define spp_dma5_TCD_CH8_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH8_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH8_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH8_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH8_SBR_EMI_MASK)
/*! @} */

/*! @name CH8_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH8_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH8_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH8_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH8_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_PRI_APL_SHIFT)) & spp_dma5_TCD_CH8_PRI_APL_MASK)

#define spp_dma5_TCD_CH8_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH8_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH8_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH8_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH8_PRI_DPA_MASK)

#define spp_dma5_TCD_CH8_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH8_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH8_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH8_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH8_PRI_ECP_MASK)
/*! @} */

/*! @name CH8_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH8_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH8_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH8_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH8_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH8_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH8_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH8_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH8_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH8_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH8_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH8_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD8_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD8_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD8_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD8_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD8_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD8_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD8_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD8_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD8_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD8_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD8_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD8_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD8_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD8_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD8_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD8_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD8_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD8_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD8_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD8_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD8_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD8_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD8_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD8_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD8_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD8_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD8_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD8_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD8_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD8_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD8_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD8_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD8_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD8_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD8_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD8_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD8_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD8_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD8_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD8_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD8_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD8_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD8_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD8_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD8_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD8_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD8_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD8_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD8_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD8_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD8_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD8_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD8_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD8_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD8_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD8_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD8_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD8_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD8_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD8_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD8_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD8_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD8_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD8_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD8_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD8_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD8_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD8_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD8_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD8_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD8_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD8_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD8_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD8_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD8_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD8_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD8_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD8_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD8_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD8_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD8_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD8_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD8_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD8_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD8_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD8_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD8_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD8_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD8_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD8_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD8_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD8_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD8_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD8_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_START_SHIFT)) & spp_dma5_TCD_TCD8_CSR_START_MASK)

#define spp_dma5_TCD_TCD8_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD8_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD8_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD8_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD8_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD8_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD8_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD8_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD8_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD8_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD8_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD8_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD8_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD8_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD8_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD8_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD8_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD8_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD8_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD8_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD8_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD8_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD8_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD8_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD8_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD8_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD8_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD8_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD8_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD8_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD8_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD8_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD8_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD8_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD8_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD8_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD8_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD8_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD8_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD8_CSR_TMC_MASK)
/*! @} */

/*! @name TCD8_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD8_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD8_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD8_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD8_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD8_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD8_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD8_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD8_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD8_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD8_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD8_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD8_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD8_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD8_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD8_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD8_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD8_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD8_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD8_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH9_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH9_CSR_ERQ_MASK            (0x1U)
#define spp_dma5_TCD_CH9_CSR_ERQ_SHIFT           (0U)
#define spp_dma5_TCD_CH9_CSR_ERQ_WIDTH           (1U)
#define spp_dma5_TCD_CH9_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH9_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH9_CSR_EARQ_MASK           (0x2U)
#define spp_dma5_TCD_CH9_CSR_EARQ_SHIFT          (1U)
#define spp_dma5_TCD_CH9_CSR_EARQ_WIDTH          (1U)
#define spp_dma5_TCD_CH9_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH9_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH9_CSR_EEI_MASK            (0x4U)
#define spp_dma5_TCD_CH9_CSR_EEI_SHIFT           (2U)
#define spp_dma5_TCD_CH9_CSR_EEI_WIDTH           (1U)
#define spp_dma5_TCD_CH9_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH9_CSR_EEI_MASK)

#define spp_dma5_TCD_CH9_CSR_CX_MASK             (0x40U)
#define spp_dma5_TCD_CH9_CSR_CX_SHIFT            (6U)
#define spp_dma5_TCD_CH9_CSR_CX_WIDTH            (1U)
#define spp_dma5_TCD_CH9_CSR_CX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_CX_SHIFT)) & spp_dma5_TCD_CH9_CSR_CX_MASK)

#define spp_dma5_TCD_CH9_CSR_ECX_MASK            (0x80U)
#define spp_dma5_TCD_CH9_CSR_ECX_SHIFT           (7U)
#define spp_dma5_TCD_CH9_CSR_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH9_CSR_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH9_CSR_ECX_MASK)

#define spp_dma5_TCD_CH9_CSR_SWAP_MASK           (0xF000U)
#define spp_dma5_TCD_CH9_CSR_SWAP_SHIFT          (12U)
#define spp_dma5_TCD_CH9_CSR_SWAP_WIDTH          (4U)
#define spp_dma5_TCD_CH9_CSR_SWAP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH9_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH9_CSR_SIGNEXT_MASK        (0x3F0000U)
#define spp_dma5_TCD_CH9_CSR_SIGNEXT_SHIFT       (16U)
#define spp_dma5_TCD_CH9_CSR_SIGNEXT_WIDTH       (6U)
#define spp_dma5_TCD_CH9_CSR_SIGNEXT(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH9_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH9_CSR_DONE_MASK           (0x40000000U)
#define spp_dma5_TCD_CH9_CSR_DONE_SHIFT          (30U)
#define spp_dma5_TCD_CH9_CSR_DONE_WIDTH          (1U)
#define spp_dma5_TCD_CH9_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH9_CSR_DONE_MASK)

#define spp_dma5_TCD_CH9_CSR_ACTIVE_MASK         (0x80000000U)
#define spp_dma5_TCD_CH9_CSR_ACTIVE_SHIFT        (31U)
#define spp_dma5_TCD_CH9_CSR_ACTIVE_WIDTH        (1U)
#define spp_dma5_TCD_CH9_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH9_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH9_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH9_ES_DBE_MASK             (0x1U)
#define spp_dma5_TCD_CH9_ES_DBE_SHIFT            (0U)
#define spp_dma5_TCD_CH9_ES_DBE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_DBE_SHIFT)) & spp_dma5_TCD_CH9_ES_DBE_MASK)

#define spp_dma5_TCD_CH9_ES_SBE_MASK             (0x2U)
#define spp_dma5_TCD_CH9_ES_SBE_SHIFT            (1U)
#define spp_dma5_TCD_CH9_ES_SBE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_SBE_SHIFT)) & spp_dma5_TCD_CH9_ES_SBE_MASK)

#define spp_dma5_TCD_CH9_ES_SGE_MASK             (0x4U)
#define spp_dma5_TCD_CH9_ES_SGE_SHIFT            (2U)
#define spp_dma5_TCD_CH9_ES_SGE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_SGE_SHIFT)) & spp_dma5_TCD_CH9_ES_SGE_MASK)

#define spp_dma5_TCD_CH9_ES_NCE_MASK             (0x8U)
#define spp_dma5_TCD_CH9_ES_NCE_SHIFT            (3U)
#define spp_dma5_TCD_CH9_ES_NCE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_NCE_SHIFT)) & spp_dma5_TCD_CH9_ES_NCE_MASK)

#define spp_dma5_TCD_CH9_ES_DOE_MASK             (0x10U)
#define spp_dma5_TCD_CH9_ES_DOE_SHIFT            (4U)
#define spp_dma5_TCD_CH9_ES_DOE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_DOE_SHIFT)) & spp_dma5_TCD_CH9_ES_DOE_MASK)

#define spp_dma5_TCD_CH9_ES_DAE_MASK             (0x20U)
#define spp_dma5_TCD_CH9_ES_DAE_SHIFT            (5U)
#define spp_dma5_TCD_CH9_ES_DAE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_DAE_SHIFT)) & spp_dma5_TCD_CH9_ES_DAE_MASK)

#define spp_dma5_TCD_CH9_ES_SOE_MASK             (0x40U)
#define spp_dma5_TCD_CH9_ES_SOE_SHIFT            (6U)
#define spp_dma5_TCD_CH9_ES_SOE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_SOE_SHIFT)) & spp_dma5_TCD_CH9_ES_SOE_MASK)

#define spp_dma5_TCD_CH9_ES_SAE_MASK             (0x80U)
#define spp_dma5_TCD_CH9_ES_SAE_SHIFT            (7U)
#define spp_dma5_TCD_CH9_ES_SAE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_SAE_SHIFT)) & spp_dma5_TCD_CH9_ES_SAE_MASK)

#define spp_dma5_TCD_CH9_ES_ECX_MASK             (0x100U)
#define spp_dma5_TCD_CH9_ES_ECX_SHIFT            (8U)
#define spp_dma5_TCD_CH9_ES_ECX_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_ECX(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_ECX_SHIFT)) & spp_dma5_TCD_CH9_ES_ECX_MASK)

#define spp_dma5_TCD_CH9_ES_UCE_MASK             (0x200U)
#define spp_dma5_TCD_CH9_ES_UCE_SHIFT            (9U)
#define spp_dma5_TCD_CH9_ES_UCE_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_UCE(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_UCE_SHIFT)) & spp_dma5_TCD_CH9_ES_UCE_MASK)

#define spp_dma5_TCD_CH9_ES_ERR_MASK             (0x80000000U)
#define spp_dma5_TCD_CH9_ES_ERR_SHIFT            (31U)
#define spp_dma5_TCD_CH9_ES_ERR_WIDTH            (1U)
#define spp_dma5_TCD_CH9_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_ES_ERR_SHIFT)) & spp_dma5_TCD_CH9_ES_ERR_MASK)
/*! @} */

/*! @name CH9_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH9_INT_INT_MASK            (0x1U)
#define spp_dma5_TCD_CH9_INT_INT_SHIFT           (0U)
#define spp_dma5_TCD_CH9_INT_INT_WIDTH           (1U)
#define spp_dma5_TCD_CH9_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_INT_INT_SHIFT)) & spp_dma5_TCD_CH9_INT_INT_MASK)
/*! @} */

/*! @name CH9_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH9_SBR_MID_MASK            (0x3FU)
#define spp_dma5_TCD_CH9_SBR_MID_SHIFT           (0U)
#define spp_dma5_TCD_CH9_SBR_MID_WIDTH           (6U)
#define spp_dma5_TCD_CH9_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_SBR_MID_SHIFT)) & spp_dma5_TCD_CH9_SBR_MID_MASK)

#define spp_dma5_TCD_CH9_SBR_INSTR_MASK          (0x2000U)
#define spp_dma5_TCD_CH9_SBR_INSTR_SHIFT         (13U)
#define spp_dma5_TCD_CH9_SBR_INSTR_WIDTH         (1U)
#define spp_dma5_TCD_CH9_SBR_INSTR(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH9_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH9_SBR_PAL_MASK            (0x8000U)
#define spp_dma5_TCD_CH9_SBR_PAL_SHIFT           (15U)
#define spp_dma5_TCD_CH9_SBR_PAL_WIDTH           (1U)
#define spp_dma5_TCD_CH9_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH9_SBR_PAL_MASK)

#define spp_dma5_TCD_CH9_SBR_EMI_MASK            (0x10000U)
#define spp_dma5_TCD_CH9_SBR_EMI_SHIFT           (16U)
#define spp_dma5_TCD_CH9_SBR_EMI_WIDTH           (1U)
#define spp_dma5_TCD_CH9_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH9_SBR_EMI_MASK)
/*! @} */

/*! @name CH9_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH9_PRI_APL_MASK            (0x7U)
#define spp_dma5_TCD_CH9_PRI_APL_SHIFT           (0U)
#define spp_dma5_TCD_CH9_PRI_APL_WIDTH           (3U)
#define spp_dma5_TCD_CH9_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_PRI_APL_SHIFT)) & spp_dma5_TCD_CH9_PRI_APL_MASK)

#define spp_dma5_TCD_CH9_PRI_DPA_MASK            (0x40000000U)
#define spp_dma5_TCD_CH9_PRI_DPA_SHIFT           (30U)
#define spp_dma5_TCD_CH9_PRI_DPA_WIDTH           (1U)
#define spp_dma5_TCD_CH9_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH9_PRI_DPA_MASK)

#define spp_dma5_TCD_CH9_PRI_ECP_MASK            (0x80000000U)
#define spp_dma5_TCD_CH9_PRI_ECP_SHIFT           (31U)
#define spp_dma5_TCD_CH9_PRI_ECP_WIDTH           (1U)
#define spp_dma5_TCD_CH9_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH9_PRI_ECP_MASK)
/*! @} */

/*! @name CH9_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH9_MATTR_RCACHE_MASK       (0xFU)
#define spp_dma5_TCD_CH9_MATTR_RCACHE_SHIFT      (0U)
#define spp_dma5_TCD_CH9_MATTR_RCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH9_MATTR_RCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH9_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH9_MATTR_WCACHE_MASK       (0xF0U)
#define spp_dma5_TCD_CH9_MATTR_WCACHE_SHIFT      (4U)
#define spp_dma5_TCD_CH9_MATTR_WCACHE_WIDTH      (4U)
#define spp_dma5_TCD_CH9_MATTR_WCACHE(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH9_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH9_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD9_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_SADDR_SADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD9_SADDR_SADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD9_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD9_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD9_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_SADDR_HIGH_SADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD9_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD9_SADDR_HIGH_SADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD9_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD9_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD9_SOFF_SOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD9_SOFF_SOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD9_SOFF_SOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD9_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD9_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD9_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD9_ATTR_DSIZE_MASK        (0x7U)
#define spp_dma5_TCD_TCD9_ATTR_DSIZE_SHIFT       (0U)
#define spp_dma5_TCD_TCD9_ATTR_DSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD9_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD9_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD9_ATTR_DMOD_MASK         (0xF8U)
#define spp_dma5_TCD_TCD9_ATTR_DMOD_SHIFT        (3U)
#define spp_dma5_TCD_TCD9_ATTR_DMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD9_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD9_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD9_ATTR_SSIZE_MASK        (0x700U)
#define spp_dma5_TCD_TCD9_ATTR_SSIZE_SHIFT       (8U)
#define spp_dma5_TCD_TCD9_ATTR_SSIZE_WIDTH       (3U)
#define spp_dma5_TCD_TCD9_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD9_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD9_ATTR_SMOD_MASK         (0xF800U)
#define spp_dma5_TCD_TCD9_ATTR_SMOD_SHIFT        (11U)
#define spp_dma5_TCD_TCD9_ATTR_SMOD_WIDTH        (5U)
#define spp_dma5_TCD_TCD9_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD9_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD9_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD9_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD9_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD9_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD9_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD9_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD9_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD9_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD9_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD9_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD9_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_DADDR_DADDR_SHIFT      (0U)
#define spp_dma5_TCD_TCD9_DADDR_DADDR_WIDTH      (32U)
#define spp_dma5_TCD_TCD9_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD9_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD9_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_DADDR_HIGH_DADDR_MASK  (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD9_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD9_DADDR_HIGH_DADDR(x)    (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD9_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD9_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD9_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD9_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD9_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD9_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD9_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD9_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD9_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD9_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD9_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD9_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD9_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD9_DOFF_DOFF_MASK         (0xFFFFU)
#define spp_dma5_TCD_TCD9_DOFF_DOFF_SHIFT        (0U)
#define spp_dma5_TCD_TCD9_DOFF_DOFF_WIDTH        (16U)
#define spp_dma5_TCD_TCD9_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD9_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD9_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD9_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD9_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD9_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD9_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD9_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD9_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD9_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD9_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD9_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD9_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD9_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD9_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD9_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD9_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD9_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD9_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD9_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD9_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD9_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD9_CSR_START_MASK         (0x1U)
#define spp_dma5_TCD_TCD9_CSR_START_SHIFT        (0U)
#define spp_dma5_TCD_TCD9_CSR_START_WIDTH        (1U)
#define spp_dma5_TCD_TCD9_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_START_SHIFT)) & spp_dma5_TCD_TCD9_CSR_START_MASK)

#define spp_dma5_TCD_TCD9_CSR_INTMAJOR_MASK      (0x2U)
#define spp_dma5_TCD_TCD9_CSR_INTMAJOR_SHIFT     (1U)
#define spp_dma5_TCD_TCD9_CSR_INTMAJOR_WIDTH     (1U)
#define spp_dma5_TCD_TCD9_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD9_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD9_CSR_INTHALF_MASK       (0x4U)
#define spp_dma5_TCD_TCD9_CSR_INTHALF_SHIFT      (2U)
#define spp_dma5_TCD_TCD9_CSR_INTHALF_WIDTH      (1U)
#define spp_dma5_TCD_TCD9_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD9_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD9_CSR_DREQ_MASK          (0x8U)
#define spp_dma5_TCD_TCD9_CSR_DREQ_SHIFT         (3U)
#define spp_dma5_TCD_TCD9_CSR_DREQ_WIDTH         (1U)
#define spp_dma5_TCD_TCD9_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD9_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD9_CSR_ESG_MASK           (0x10U)
#define spp_dma5_TCD_TCD9_CSR_ESG_SHIFT          (4U)
#define spp_dma5_TCD_TCD9_CSR_ESG_WIDTH          (1U)
#define spp_dma5_TCD_TCD9_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD9_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD9_CSR_MAJORELINK_MASK    (0x20U)
#define spp_dma5_TCD_TCD9_CSR_MAJORELINK_SHIFT   (5U)
#define spp_dma5_TCD_TCD9_CSR_MAJORELINK_WIDTH   (1U)
#define spp_dma5_TCD_TCD9_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD9_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD9_CSR_ESDA_MASK          (0x80U)
#define spp_dma5_TCD_TCD9_CSR_ESDA_SHIFT         (7U)
#define spp_dma5_TCD_TCD9_CSR_ESDA_WIDTH         (1U)
#define spp_dma5_TCD_TCD9_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD9_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD9_CSR_MAJORLINKCH_MASK   (0x3F00U)
#define spp_dma5_TCD_TCD9_CSR_MAJORLINKCH_SHIFT  (8U)
#define spp_dma5_TCD_TCD9_CSR_MAJORLINKCH_WIDTH  (6U)
#define spp_dma5_TCD_TCD9_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD9_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD9_CSR_TMC_MASK           (0xC000U)
#define spp_dma5_TCD_TCD9_CSR_TMC_SHIFT          (14U)
#define spp_dma5_TCD_TCD9_CSR_TMC_WIDTH          (2U)
#define spp_dma5_TCD_TCD9_CSR_TMC(x)             (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD9_CSR_TMC_MASK)
/*! @} */

/*! @name TCD9_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD9_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD9_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD9_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD9_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD9_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD9_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD9_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD9_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD9_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD9_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD9_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD9_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD9_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD9_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD9_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD9_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD9_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD9_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD9_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH10_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH10_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH10_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH10_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH10_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH10_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH10_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH10_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH10_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH10_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH10_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH10_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH10_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH10_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH10_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH10_CSR_EEI_MASK)

#define spp_dma5_TCD_CH10_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH10_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH10_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH10_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_CX_SHIFT)) & spp_dma5_TCD_CH10_CSR_CX_MASK)

#define spp_dma5_TCD_CH10_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH10_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH10_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH10_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH10_CSR_ECX_MASK)

#define spp_dma5_TCD_CH10_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH10_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH10_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH10_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH10_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH10_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH10_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH10_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH10_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH10_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH10_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH10_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH10_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH10_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH10_CSR_DONE_MASK)

#define spp_dma5_TCD_CH10_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH10_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH10_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH10_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH10_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH10_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH10_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH10_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH10_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_DBE_SHIFT)) & spp_dma5_TCD_CH10_ES_DBE_MASK)

#define spp_dma5_TCD_CH10_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH10_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH10_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_SBE_SHIFT)) & spp_dma5_TCD_CH10_ES_SBE_MASK)

#define spp_dma5_TCD_CH10_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH10_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH10_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_SGE_SHIFT)) & spp_dma5_TCD_CH10_ES_SGE_MASK)

#define spp_dma5_TCD_CH10_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH10_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH10_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_NCE_SHIFT)) & spp_dma5_TCD_CH10_ES_NCE_MASK)

#define spp_dma5_TCD_CH10_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH10_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH10_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_DOE_SHIFT)) & spp_dma5_TCD_CH10_ES_DOE_MASK)

#define spp_dma5_TCD_CH10_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH10_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH10_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_DAE_SHIFT)) & spp_dma5_TCD_CH10_ES_DAE_MASK)

#define spp_dma5_TCD_CH10_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH10_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH10_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_SOE_SHIFT)) & spp_dma5_TCD_CH10_ES_SOE_MASK)

#define spp_dma5_TCD_CH10_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH10_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH10_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_SAE_SHIFT)) & spp_dma5_TCD_CH10_ES_SAE_MASK)

#define spp_dma5_TCD_CH10_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH10_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH10_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_ECX_SHIFT)) & spp_dma5_TCD_CH10_ES_ECX_MASK)

#define spp_dma5_TCD_CH10_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH10_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH10_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_UCE_SHIFT)) & spp_dma5_TCD_CH10_ES_UCE_MASK)

#define spp_dma5_TCD_CH10_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH10_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH10_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH10_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_ES_ERR_SHIFT)) & spp_dma5_TCD_CH10_ES_ERR_MASK)
/*! @} */

/*! @name CH10_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH10_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH10_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH10_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH10_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_INT_INT_SHIFT)) & spp_dma5_TCD_CH10_INT_INT_MASK)
/*! @} */

/*! @name CH10_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH10_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH10_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH10_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH10_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_SBR_MID_SHIFT)) & spp_dma5_TCD_CH10_SBR_MID_MASK)

#define spp_dma5_TCD_CH10_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH10_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH10_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH10_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH10_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH10_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH10_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH10_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH10_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH10_SBR_PAL_MASK)

#define spp_dma5_TCD_CH10_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH10_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH10_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH10_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH10_SBR_EMI_MASK)
/*! @} */

/*! @name CH10_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH10_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH10_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH10_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH10_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_PRI_APL_SHIFT)) & spp_dma5_TCD_CH10_PRI_APL_MASK)

#define spp_dma5_TCD_CH10_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH10_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH10_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH10_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH10_PRI_DPA_MASK)

#define spp_dma5_TCD_CH10_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH10_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH10_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH10_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH10_PRI_ECP_MASK)
/*! @} */

/*! @name CH10_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH10_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH10_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH10_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH10_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH10_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH10_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH10_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH10_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH10_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH10_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH10_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD10_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD10_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD10_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD10_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD10_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD10_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD10_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD10_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD10_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD10_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD10_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD10_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD10_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD10_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD10_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD10_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD10_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD10_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD10_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD10_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD10_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD10_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD10_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD10_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD10_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD10_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD10_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD10_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD10_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD10_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD10_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD10_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD10_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD10_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD10_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD10_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD10_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD10_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD10_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD10_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD10_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD10_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD10_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD10_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD10_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD10_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD10_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD10_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD10_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD10_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD10_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD10_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD10_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD10_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD10_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD10_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD10_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD10_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD10_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD10_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD10_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD10_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD10_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD10_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD10_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD10_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD10_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD10_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD10_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD10_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD10_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD10_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD10_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD10_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD10_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD10_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD10_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD10_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD10_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD10_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD10_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD10_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD10_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD10_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD10_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD10_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD10_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD10_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD10_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD10_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD10_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD10_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD10_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD10_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_START_SHIFT)) & spp_dma5_TCD_TCD10_CSR_START_MASK)

#define spp_dma5_TCD_TCD10_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD10_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD10_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD10_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD10_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD10_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD10_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD10_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD10_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD10_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD10_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD10_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD10_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD10_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD10_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD10_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD10_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD10_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD10_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD10_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD10_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD10_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD10_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD10_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD10_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD10_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD10_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD10_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD10_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD10_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD10_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD10_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD10_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD10_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD10_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD10_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD10_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD10_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD10_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD10_CSR_TMC_MASK)
/*! @} */

/*! @name TCD10_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD10_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD10_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD10_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD10_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD10_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD10_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD10_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD10_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD10_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD10_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD10_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD10_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD10_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD10_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD10_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD10_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD10_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD10_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD10_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH11_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH11_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH11_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH11_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH11_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH11_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH11_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH11_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH11_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH11_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH11_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH11_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH11_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH11_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH11_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH11_CSR_EEI_MASK)

#define spp_dma5_TCD_CH11_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH11_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH11_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH11_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_CX_SHIFT)) & spp_dma5_TCD_CH11_CSR_CX_MASK)

#define spp_dma5_TCD_CH11_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH11_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH11_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH11_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH11_CSR_ECX_MASK)

#define spp_dma5_TCD_CH11_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH11_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH11_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH11_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH11_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH11_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH11_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH11_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH11_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH11_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH11_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH11_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH11_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH11_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH11_CSR_DONE_MASK)

#define spp_dma5_TCD_CH11_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH11_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH11_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH11_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH11_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH11_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH11_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH11_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH11_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_DBE_SHIFT)) & spp_dma5_TCD_CH11_ES_DBE_MASK)

#define spp_dma5_TCD_CH11_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH11_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH11_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_SBE_SHIFT)) & spp_dma5_TCD_CH11_ES_SBE_MASK)

#define spp_dma5_TCD_CH11_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH11_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH11_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_SGE_SHIFT)) & spp_dma5_TCD_CH11_ES_SGE_MASK)

#define spp_dma5_TCD_CH11_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH11_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH11_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_NCE_SHIFT)) & spp_dma5_TCD_CH11_ES_NCE_MASK)

#define spp_dma5_TCD_CH11_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH11_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH11_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_DOE_SHIFT)) & spp_dma5_TCD_CH11_ES_DOE_MASK)

#define spp_dma5_TCD_CH11_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH11_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH11_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_DAE_SHIFT)) & spp_dma5_TCD_CH11_ES_DAE_MASK)

#define spp_dma5_TCD_CH11_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH11_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH11_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_SOE_SHIFT)) & spp_dma5_TCD_CH11_ES_SOE_MASK)

#define spp_dma5_TCD_CH11_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH11_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH11_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_SAE_SHIFT)) & spp_dma5_TCD_CH11_ES_SAE_MASK)

#define spp_dma5_TCD_CH11_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH11_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH11_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_ECX_SHIFT)) & spp_dma5_TCD_CH11_ES_ECX_MASK)

#define spp_dma5_TCD_CH11_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH11_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH11_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_UCE_SHIFT)) & spp_dma5_TCD_CH11_ES_UCE_MASK)

#define spp_dma5_TCD_CH11_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH11_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH11_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH11_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_ES_ERR_SHIFT)) & spp_dma5_TCD_CH11_ES_ERR_MASK)
/*! @} */

/*! @name CH11_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH11_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH11_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH11_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH11_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_INT_INT_SHIFT)) & spp_dma5_TCD_CH11_INT_INT_MASK)
/*! @} */

/*! @name CH11_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH11_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH11_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH11_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH11_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_SBR_MID_SHIFT)) & spp_dma5_TCD_CH11_SBR_MID_MASK)

#define spp_dma5_TCD_CH11_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH11_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH11_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH11_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH11_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH11_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH11_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH11_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH11_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH11_SBR_PAL_MASK)

#define spp_dma5_TCD_CH11_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH11_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH11_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH11_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH11_SBR_EMI_MASK)
/*! @} */

/*! @name CH11_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH11_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH11_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH11_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH11_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_PRI_APL_SHIFT)) & spp_dma5_TCD_CH11_PRI_APL_MASK)

#define spp_dma5_TCD_CH11_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH11_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH11_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH11_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH11_PRI_DPA_MASK)

#define spp_dma5_TCD_CH11_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH11_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH11_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH11_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH11_PRI_ECP_MASK)
/*! @} */

/*! @name CH11_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH11_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH11_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH11_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH11_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH11_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH11_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH11_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH11_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH11_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH11_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH11_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD11_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD11_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD11_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD11_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD11_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD11_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD11_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD11_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD11_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD11_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD11_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD11_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD11_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD11_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD11_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD11_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD11_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD11_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD11_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD11_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD11_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD11_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD11_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD11_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD11_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD11_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD11_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD11_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD11_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD11_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD11_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD11_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD11_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD11_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD11_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD11_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD11_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD11_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD11_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD11_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD11_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD11_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD11_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD11_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD11_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD11_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD11_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD11_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD11_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD11_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD11_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD11_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD11_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD11_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD11_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD11_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD11_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD11_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD11_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD11_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD11_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD11_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD11_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD11_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD11_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD11_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD11_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD11_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD11_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD11_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD11_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD11_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD11_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD11_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD11_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD11_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD11_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD11_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD11_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD11_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD11_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD11_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD11_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD11_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD11_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD11_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD11_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD11_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD11_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD11_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD11_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD11_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD11_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD11_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_START_SHIFT)) & spp_dma5_TCD_TCD11_CSR_START_MASK)

#define spp_dma5_TCD_TCD11_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD11_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD11_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD11_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD11_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD11_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD11_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD11_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD11_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD11_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD11_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD11_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD11_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD11_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD11_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD11_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD11_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD11_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD11_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD11_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD11_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD11_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD11_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD11_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD11_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD11_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD11_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD11_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD11_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD11_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD11_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD11_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD11_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD11_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD11_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD11_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD11_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD11_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD11_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD11_CSR_TMC_MASK)
/*! @} */

/*! @name TCD11_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD11_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD11_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD11_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD11_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD11_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD11_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD11_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD11_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD11_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD11_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD11_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD11_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD11_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD11_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD11_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD11_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD11_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD11_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD11_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH12_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH12_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH12_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH12_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH12_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH12_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH12_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH12_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH12_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH12_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH12_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH12_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH12_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH12_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH12_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH12_CSR_EEI_MASK)

#define spp_dma5_TCD_CH12_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH12_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH12_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH12_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_CX_SHIFT)) & spp_dma5_TCD_CH12_CSR_CX_MASK)

#define spp_dma5_TCD_CH12_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH12_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH12_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH12_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH12_CSR_ECX_MASK)

#define spp_dma5_TCD_CH12_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH12_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH12_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH12_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH12_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH12_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH12_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH12_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH12_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH12_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH12_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH12_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH12_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH12_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH12_CSR_DONE_MASK)

#define spp_dma5_TCD_CH12_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH12_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH12_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH12_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH12_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH12_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH12_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH12_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH12_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_DBE_SHIFT)) & spp_dma5_TCD_CH12_ES_DBE_MASK)

#define spp_dma5_TCD_CH12_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH12_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH12_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_SBE_SHIFT)) & spp_dma5_TCD_CH12_ES_SBE_MASK)

#define spp_dma5_TCD_CH12_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH12_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH12_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_SGE_SHIFT)) & spp_dma5_TCD_CH12_ES_SGE_MASK)

#define spp_dma5_TCD_CH12_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH12_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH12_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_NCE_SHIFT)) & spp_dma5_TCD_CH12_ES_NCE_MASK)

#define spp_dma5_TCD_CH12_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH12_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH12_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_DOE_SHIFT)) & spp_dma5_TCD_CH12_ES_DOE_MASK)

#define spp_dma5_TCD_CH12_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH12_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH12_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_DAE_SHIFT)) & spp_dma5_TCD_CH12_ES_DAE_MASK)

#define spp_dma5_TCD_CH12_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH12_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH12_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_SOE_SHIFT)) & spp_dma5_TCD_CH12_ES_SOE_MASK)

#define spp_dma5_TCD_CH12_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH12_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH12_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_SAE_SHIFT)) & spp_dma5_TCD_CH12_ES_SAE_MASK)

#define spp_dma5_TCD_CH12_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH12_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH12_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_ECX_SHIFT)) & spp_dma5_TCD_CH12_ES_ECX_MASK)

#define spp_dma5_TCD_CH12_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH12_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH12_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_UCE_SHIFT)) & spp_dma5_TCD_CH12_ES_UCE_MASK)

#define spp_dma5_TCD_CH12_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH12_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH12_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH12_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_ES_ERR_SHIFT)) & spp_dma5_TCD_CH12_ES_ERR_MASK)
/*! @} */

/*! @name CH12_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH12_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH12_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH12_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH12_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_INT_INT_SHIFT)) & spp_dma5_TCD_CH12_INT_INT_MASK)
/*! @} */

/*! @name CH12_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH12_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH12_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH12_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH12_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_SBR_MID_SHIFT)) & spp_dma5_TCD_CH12_SBR_MID_MASK)

#define spp_dma5_TCD_CH12_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH12_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH12_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH12_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH12_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH12_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH12_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH12_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH12_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH12_SBR_PAL_MASK)

#define spp_dma5_TCD_CH12_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH12_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH12_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH12_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH12_SBR_EMI_MASK)
/*! @} */

/*! @name CH12_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH12_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH12_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH12_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH12_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_PRI_APL_SHIFT)) & spp_dma5_TCD_CH12_PRI_APL_MASK)

#define spp_dma5_TCD_CH12_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH12_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH12_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH12_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH12_PRI_DPA_MASK)

#define spp_dma5_TCD_CH12_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH12_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH12_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH12_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH12_PRI_ECP_MASK)
/*! @} */

/*! @name CH12_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH12_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH12_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH12_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH12_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH12_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH12_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH12_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH12_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH12_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH12_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH12_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD12_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD12_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD12_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD12_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD12_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD12_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD12_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD12_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD12_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD12_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD12_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD12_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD12_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD12_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD12_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD12_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD12_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD12_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD12_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD12_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD12_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD12_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD12_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD12_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD12_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD12_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD12_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD12_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD12_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD12_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD12_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD12_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD12_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD12_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD12_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD12_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD12_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD12_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD12_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD12_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD12_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD12_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD12_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD12_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD12_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD12_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD12_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD12_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD12_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD12_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD12_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD12_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD12_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD12_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD12_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD12_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD12_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD12_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD12_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD12_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD12_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD12_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD12_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD12_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD12_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD12_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD12_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD12_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD12_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD12_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD12_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD12_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD12_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD12_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD12_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD12_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD12_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD12_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD12_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD12_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD12_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD12_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD12_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD12_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD12_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD12_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD12_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD12_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD12_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD12_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD12_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD12_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD12_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD12_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD12_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_START_SHIFT)) & spp_dma5_TCD_TCD12_CSR_START_MASK)

#define spp_dma5_TCD_TCD12_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD12_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD12_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD12_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD12_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD12_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD12_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD12_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD12_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD12_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD12_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD12_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD12_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD12_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD12_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD12_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD12_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD12_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD12_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD12_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD12_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD12_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD12_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD12_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD12_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD12_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD12_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD12_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD12_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD12_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD12_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD12_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD12_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD12_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD12_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD12_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD12_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD12_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD12_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD12_CSR_TMC_MASK)
/*! @} */

/*! @name TCD12_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD12_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD12_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD12_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD12_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD12_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD12_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD12_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD12_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD12_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD12_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD12_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD12_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD12_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD12_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD12_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD12_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD12_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD12_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD12_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH13_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH13_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH13_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH13_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH13_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH13_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH13_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH13_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH13_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH13_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH13_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH13_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH13_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH13_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH13_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH13_CSR_EEI_MASK)

#define spp_dma5_TCD_CH13_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH13_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH13_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH13_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_CX_SHIFT)) & spp_dma5_TCD_CH13_CSR_CX_MASK)

#define spp_dma5_TCD_CH13_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH13_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH13_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH13_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH13_CSR_ECX_MASK)

#define spp_dma5_TCD_CH13_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH13_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH13_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH13_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH13_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH13_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH13_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH13_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH13_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH13_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH13_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH13_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH13_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH13_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH13_CSR_DONE_MASK)

#define spp_dma5_TCD_CH13_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH13_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH13_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH13_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH13_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH13_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH13_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH13_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH13_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_DBE_SHIFT)) & spp_dma5_TCD_CH13_ES_DBE_MASK)

#define spp_dma5_TCD_CH13_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH13_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH13_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_SBE_SHIFT)) & spp_dma5_TCD_CH13_ES_SBE_MASK)

#define spp_dma5_TCD_CH13_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH13_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH13_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_SGE_SHIFT)) & spp_dma5_TCD_CH13_ES_SGE_MASK)

#define spp_dma5_TCD_CH13_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH13_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH13_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_NCE_SHIFT)) & spp_dma5_TCD_CH13_ES_NCE_MASK)

#define spp_dma5_TCD_CH13_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH13_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH13_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_DOE_SHIFT)) & spp_dma5_TCD_CH13_ES_DOE_MASK)

#define spp_dma5_TCD_CH13_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH13_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH13_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_DAE_SHIFT)) & spp_dma5_TCD_CH13_ES_DAE_MASK)

#define spp_dma5_TCD_CH13_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH13_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH13_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_SOE_SHIFT)) & spp_dma5_TCD_CH13_ES_SOE_MASK)

#define spp_dma5_TCD_CH13_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH13_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH13_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_SAE_SHIFT)) & spp_dma5_TCD_CH13_ES_SAE_MASK)

#define spp_dma5_TCD_CH13_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH13_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH13_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_ECX_SHIFT)) & spp_dma5_TCD_CH13_ES_ECX_MASK)

#define spp_dma5_TCD_CH13_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH13_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH13_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_UCE_SHIFT)) & spp_dma5_TCD_CH13_ES_UCE_MASK)

#define spp_dma5_TCD_CH13_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH13_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH13_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH13_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_ES_ERR_SHIFT)) & spp_dma5_TCD_CH13_ES_ERR_MASK)
/*! @} */

/*! @name CH13_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH13_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH13_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH13_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH13_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_INT_INT_SHIFT)) & spp_dma5_TCD_CH13_INT_INT_MASK)
/*! @} */

/*! @name CH13_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH13_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH13_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH13_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH13_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_SBR_MID_SHIFT)) & spp_dma5_TCD_CH13_SBR_MID_MASK)

#define spp_dma5_TCD_CH13_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH13_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH13_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH13_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH13_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH13_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH13_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH13_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH13_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH13_SBR_PAL_MASK)

#define spp_dma5_TCD_CH13_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH13_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH13_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH13_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH13_SBR_EMI_MASK)
/*! @} */

/*! @name CH13_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH13_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH13_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH13_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH13_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_PRI_APL_SHIFT)) & spp_dma5_TCD_CH13_PRI_APL_MASK)

#define spp_dma5_TCD_CH13_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH13_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH13_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH13_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH13_PRI_DPA_MASK)

#define spp_dma5_TCD_CH13_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH13_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH13_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH13_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH13_PRI_ECP_MASK)
/*! @} */

/*! @name CH13_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH13_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH13_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH13_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH13_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH13_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH13_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH13_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH13_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH13_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH13_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH13_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD13_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD13_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD13_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD13_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD13_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD13_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD13_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD13_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD13_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD13_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD13_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD13_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD13_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD13_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD13_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD13_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD13_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD13_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD13_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD13_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD13_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD13_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD13_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD13_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD13_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD13_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD13_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD13_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD13_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD13_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD13_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD13_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD13_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD13_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD13_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD13_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD13_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD13_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD13_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD13_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD13_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD13_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD13_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD13_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD13_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD13_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD13_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD13_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD13_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD13_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD13_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD13_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD13_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD13_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD13_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD13_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD13_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD13_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD13_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD13_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD13_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD13_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD13_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD13_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD13_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD13_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD13_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD13_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD13_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD13_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD13_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD13_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD13_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD13_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD13_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD13_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD13_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD13_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD13_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD13_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD13_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD13_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD13_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD13_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD13_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD13_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD13_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD13_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD13_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD13_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD13_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD13_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD13_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD13_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD13_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_START_SHIFT)) & spp_dma5_TCD_TCD13_CSR_START_MASK)

#define spp_dma5_TCD_TCD13_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD13_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD13_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD13_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD13_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD13_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD13_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD13_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD13_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD13_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD13_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD13_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD13_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD13_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD13_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD13_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD13_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD13_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD13_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD13_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD13_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD13_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD13_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD13_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD13_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD13_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD13_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD13_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD13_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD13_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD13_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD13_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD13_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD13_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD13_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD13_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD13_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD13_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD13_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD13_CSR_TMC_MASK)
/*! @} */

/*! @name TCD13_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD13_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD13_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD13_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD13_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD13_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD13_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD13_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD13_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD13_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD13_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD13_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD13_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD13_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD13_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD13_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD13_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD13_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD13_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD13_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH14_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH14_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH14_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH14_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH14_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH14_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH14_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH14_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH14_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH14_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH14_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH14_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH14_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH14_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH14_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH14_CSR_EEI_MASK)

#define spp_dma5_TCD_CH14_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH14_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH14_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH14_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_CX_SHIFT)) & spp_dma5_TCD_CH14_CSR_CX_MASK)

#define spp_dma5_TCD_CH14_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH14_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH14_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH14_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH14_CSR_ECX_MASK)

#define spp_dma5_TCD_CH14_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH14_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH14_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH14_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH14_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH14_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH14_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH14_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH14_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH14_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH14_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH14_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH14_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH14_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH14_CSR_DONE_MASK)

#define spp_dma5_TCD_CH14_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH14_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH14_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH14_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH14_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH14_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH14_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH14_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH14_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_DBE_SHIFT)) & spp_dma5_TCD_CH14_ES_DBE_MASK)

#define spp_dma5_TCD_CH14_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH14_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH14_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_SBE_SHIFT)) & spp_dma5_TCD_CH14_ES_SBE_MASK)

#define spp_dma5_TCD_CH14_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH14_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH14_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_SGE_SHIFT)) & spp_dma5_TCD_CH14_ES_SGE_MASK)

#define spp_dma5_TCD_CH14_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH14_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH14_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_NCE_SHIFT)) & spp_dma5_TCD_CH14_ES_NCE_MASK)

#define spp_dma5_TCD_CH14_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH14_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH14_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_DOE_SHIFT)) & spp_dma5_TCD_CH14_ES_DOE_MASK)

#define spp_dma5_TCD_CH14_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH14_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH14_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_DAE_SHIFT)) & spp_dma5_TCD_CH14_ES_DAE_MASK)

#define spp_dma5_TCD_CH14_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH14_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH14_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_SOE_SHIFT)) & spp_dma5_TCD_CH14_ES_SOE_MASK)

#define spp_dma5_TCD_CH14_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH14_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH14_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_SAE_SHIFT)) & spp_dma5_TCD_CH14_ES_SAE_MASK)

#define spp_dma5_TCD_CH14_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH14_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH14_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_ECX_SHIFT)) & spp_dma5_TCD_CH14_ES_ECX_MASK)

#define spp_dma5_TCD_CH14_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH14_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH14_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_UCE_SHIFT)) & spp_dma5_TCD_CH14_ES_UCE_MASK)

#define spp_dma5_TCD_CH14_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH14_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH14_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH14_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_ES_ERR_SHIFT)) & spp_dma5_TCD_CH14_ES_ERR_MASK)
/*! @} */

/*! @name CH14_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH14_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH14_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH14_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH14_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_INT_INT_SHIFT)) & spp_dma5_TCD_CH14_INT_INT_MASK)
/*! @} */

/*! @name CH14_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH14_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH14_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH14_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH14_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_SBR_MID_SHIFT)) & spp_dma5_TCD_CH14_SBR_MID_MASK)

#define spp_dma5_TCD_CH14_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH14_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH14_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH14_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH14_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH14_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH14_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH14_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH14_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH14_SBR_PAL_MASK)

#define spp_dma5_TCD_CH14_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH14_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH14_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH14_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH14_SBR_EMI_MASK)
/*! @} */

/*! @name CH14_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH14_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH14_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH14_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH14_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_PRI_APL_SHIFT)) & spp_dma5_TCD_CH14_PRI_APL_MASK)

#define spp_dma5_TCD_CH14_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH14_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH14_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH14_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH14_PRI_DPA_MASK)

#define spp_dma5_TCD_CH14_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH14_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH14_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH14_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH14_PRI_ECP_MASK)
/*! @} */

/*! @name CH14_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH14_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH14_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH14_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH14_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH14_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH14_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH14_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH14_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH14_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH14_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH14_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD14_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD14_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD14_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD14_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD14_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD14_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD14_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD14_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD14_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD14_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD14_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD14_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD14_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD14_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD14_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD14_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD14_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD14_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD14_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD14_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD14_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD14_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD14_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD14_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD14_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD14_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD14_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD14_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD14_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD14_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD14_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD14_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD14_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD14_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD14_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD14_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD14_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD14_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD14_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD14_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD14_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD14_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD14_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD14_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD14_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD14_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD14_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD14_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD14_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD14_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD14_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD14_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD14_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD14_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD14_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD14_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD14_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD14_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD14_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD14_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD14_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD14_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD14_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD14_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD14_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD14_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD14_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD14_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD14_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD14_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD14_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD14_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD14_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD14_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD14_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD14_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD14_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD14_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD14_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD14_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD14_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD14_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD14_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD14_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD14_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD14_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD14_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD14_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD14_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD14_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD14_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD14_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD14_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD14_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD14_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_START_SHIFT)) & spp_dma5_TCD_TCD14_CSR_START_MASK)

#define spp_dma5_TCD_TCD14_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD14_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD14_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD14_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD14_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD14_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD14_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD14_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD14_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD14_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD14_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD14_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD14_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD14_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD14_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD14_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD14_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD14_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD14_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD14_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD14_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD14_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD14_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD14_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD14_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD14_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD14_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD14_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD14_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD14_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD14_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD14_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD14_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD14_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD14_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD14_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD14_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD14_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD14_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD14_CSR_TMC_MASK)
/*! @} */

/*! @name TCD14_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD14_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD14_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD14_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD14_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD14_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD14_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD14_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD14_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD14_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD14_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD14_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD14_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD14_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD14_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD14_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD14_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD14_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD14_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD14_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH15_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH15_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH15_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH15_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH15_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH15_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH15_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH15_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH15_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH15_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH15_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH15_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH15_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH15_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH15_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH15_CSR_EEI_MASK)

#define spp_dma5_TCD_CH15_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH15_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH15_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH15_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_CX_SHIFT)) & spp_dma5_TCD_CH15_CSR_CX_MASK)

#define spp_dma5_TCD_CH15_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH15_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH15_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH15_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH15_CSR_ECX_MASK)

#define spp_dma5_TCD_CH15_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH15_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH15_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH15_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH15_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH15_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH15_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH15_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH15_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH15_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH15_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH15_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH15_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH15_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH15_CSR_DONE_MASK)

#define spp_dma5_TCD_CH15_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH15_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH15_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH15_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH15_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH15_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH15_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH15_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH15_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_DBE_SHIFT)) & spp_dma5_TCD_CH15_ES_DBE_MASK)

#define spp_dma5_TCD_CH15_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH15_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH15_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_SBE_SHIFT)) & spp_dma5_TCD_CH15_ES_SBE_MASK)

#define spp_dma5_TCD_CH15_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH15_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH15_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_SGE_SHIFT)) & spp_dma5_TCD_CH15_ES_SGE_MASK)

#define spp_dma5_TCD_CH15_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH15_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH15_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_NCE_SHIFT)) & spp_dma5_TCD_CH15_ES_NCE_MASK)

#define spp_dma5_TCD_CH15_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH15_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH15_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_DOE_SHIFT)) & spp_dma5_TCD_CH15_ES_DOE_MASK)

#define spp_dma5_TCD_CH15_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH15_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH15_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_DAE_SHIFT)) & spp_dma5_TCD_CH15_ES_DAE_MASK)

#define spp_dma5_TCD_CH15_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH15_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH15_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_SOE_SHIFT)) & spp_dma5_TCD_CH15_ES_SOE_MASK)

#define spp_dma5_TCD_CH15_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH15_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH15_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_SAE_SHIFT)) & spp_dma5_TCD_CH15_ES_SAE_MASK)

#define spp_dma5_TCD_CH15_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH15_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH15_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_ECX_SHIFT)) & spp_dma5_TCD_CH15_ES_ECX_MASK)

#define spp_dma5_TCD_CH15_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH15_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH15_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_UCE_SHIFT)) & spp_dma5_TCD_CH15_ES_UCE_MASK)

#define spp_dma5_TCD_CH15_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH15_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH15_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH15_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_ES_ERR_SHIFT)) & spp_dma5_TCD_CH15_ES_ERR_MASK)
/*! @} */

/*! @name CH15_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH15_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH15_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH15_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH15_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_INT_INT_SHIFT)) & spp_dma5_TCD_CH15_INT_INT_MASK)
/*! @} */

/*! @name CH15_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH15_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH15_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH15_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH15_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_SBR_MID_SHIFT)) & spp_dma5_TCD_CH15_SBR_MID_MASK)

#define spp_dma5_TCD_CH15_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH15_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH15_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH15_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH15_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH15_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH15_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH15_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH15_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH15_SBR_PAL_MASK)

#define spp_dma5_TCD_CH15_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH15_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH15_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH15_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH15_SBR_EMI_MASK)
/*! @} */

/*! @name CH15_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH15_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH15_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH15_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH15_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_PRI_APL_SHIFT)) & spp_dma5_TCD_CH15_PRI_APL_MASK)

#define spp_dma5_TCD_CH15_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH15_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH15_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH15_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH15_PRI_DPA_MASK)

#define spp_dma5_TCD_CH15_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH15_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH15_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH15_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH15_PRI_ECP_MASK)
/*! @} */

/*! @name CH15_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH15_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH15_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH15_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH15_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH15_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH15_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH15_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH15_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH15_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH15_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH15_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD15_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD15_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD15_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD15_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD15_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD15_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD15_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD15_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD15_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD15_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD15_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD15_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD15_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD15_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD15_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD15_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD15_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD15_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD15_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD15_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD15_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD15_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD15_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD15_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD15_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD15_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD15_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD15_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD15_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD15_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD15_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD15_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD15_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD15_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD15_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD15_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD15_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD15_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD15_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD15_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD15_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD15_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD15_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD15_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD15_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD15_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD15_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD15_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD15_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD15_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD15_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD15_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD15_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD15_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD15_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD15_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD15_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD15_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD15_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD15_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD15_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD15_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD15_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD15_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD15_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD15_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD15_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD15_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD15_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD15_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD15_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD15_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD15_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD15_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD15_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD15_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD15_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD15_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD15_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD15_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD15_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD15_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD15_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD15_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD15_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD15_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD15_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD15_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD15_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD15_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD15_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD15_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD15_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD15_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD15_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_START_SHIFT)) & spp_dma5_TCD_TCD15_CSR_START_MASK)

#define spp_dma5_TCD_TCD15_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD15_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD15_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD15_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD15_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD15_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD15_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD15_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD15_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD15_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD15_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD15_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD15_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD15_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD15_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD15_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD15_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD15_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD15_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD15_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD15_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD15_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD15_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD15_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD15_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD15_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD15_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD15_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD15_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD15_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD15_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD15_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD15_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD15_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD15_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD15_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD15_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD15_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD15_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD15_CSR_TMC_MASK)
/*! @} */

/*! @name TCD15_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD15_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD15_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD15_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD15_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD15_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD15_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD15_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD15_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD15_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD15_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD15_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD15_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD15_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD15_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD15_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD15_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD15_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD15_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD15_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH16_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH16_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH16_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH16_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH16_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH16_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH16_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH16_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH16_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH16_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH16_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH16_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH16_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH16_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH16_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH16_CSR_EEI_MASK)

#define spp_dma5_TCD_CH16_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH16_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH16_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH16_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_CX_SHIFT)) & spp_dma5_TCD_CH16_CSR_CX_MASK)

#define spp_dma5_TCD_CH16_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH16_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH16_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH16_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH16_CSR_ECX_MASK)

#define spp_dma5_TCD_CH16_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH16_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH16_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH16_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH16_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH16_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH16_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH16_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH16_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH16_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH16_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH16_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH16_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH16_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH16_CSR_DONE_MASK)

#define spp_dma5_TCD_CH16_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH16_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH16_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH16_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH16_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH16_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH16_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH16_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH16_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_DBE_SHIFT)) & spp_dma5_TCD_CH16_ES_DBE_MASK)

#define spp_dma5_TCD_CH16_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH16_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH16_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_SBE_SHIFT)) & spp_dma5_TCD_CH16_ES_SBE_MASK)

#define spp_dma5_TCD_CH16_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH16_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH16_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_SGE_SHIFT)) & spp_dma5_TCD_CH16_ES_SGE_MASK)

#define spp_dma5_TCD_CH16_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH16_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH16_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_NCE_SHIFT)) & spp_dma5_TCD_CH16_ES_NCE_MASK)

#define spp_dma5_TCD_CH16_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH16_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH16_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_DOE_SHIFT)) & spp_dma5_TCD_CH16_ES_DOE_MASK)

#define spp_dma5_TCD_CH16_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH16_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH16_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_DAE_SHIFT)) & spp_dma5_TCD_CH16_ES_DAE_MASK)

#define spp_dma5_TCD_CH16_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH16_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH16_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_SOE_SHIFT)) & spp_dma5_TCD_CH16_ES_SOE_MASK)

#define spp_dma5_TCD_CH16_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH16_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH16_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_SAE_SHIFT)) & spp_dma5_TCD_CH16_ES_SAE_MASK)

#define spp_dma5_TCD_CH16_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH16_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH16_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_ECX_SHIFT)) & spp_dma5_TCD_CH16_ES_ECX_MASK)

#define spp_dma5_TCD_CH16_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH16_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH16_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_UCE_SHIFT)) & spp_dma5_TCD_CH16_ES_UCE_MASK)

#define spp_dma5_TCD_CH16_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH16_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH16_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH16_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_ES_ERR_SHIFT)) & spp_dma5_TCD_CH16_ES_ERR_MASK)
/*! @} */

/*! @name CH16_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH16_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH16_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH16_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH16_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_INT_INT_SHIFT)) & spp_dma5_TCD_CH16_INT_INT_MASK)
/*! @} */

/*! @name CH16_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH16_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH16_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH16_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH16_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_SBR_MID_SHIFT)) & spp_dma5_TCD_CH16_SBR_MID_MASK)

#define spp_dma5_TCD_CH16_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH16_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH16_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH16_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH16_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH16_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH16_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH16_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH16_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH16_SBR_PAL_MASK)

#define spp_dma5_TCD_CH16_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH16_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH16_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH16_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH16_SBR_EMI_MASK)
/*! @} */

/*! @name CH16_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH16_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH16_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH16_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH16_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_PRI_APL_SHIFT)) & spp_dma5_TCD_CH16_PRI_APL_MASK)

#define spp_dma5_TCD_CH16_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH16_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH16_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH16_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH16_PRI_DPA_MASK)

#define spp_dma5_TCD_CH16_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH16_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH16_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH16_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH16_PRI_ECP_MASK)
/*! @} */

/*! @name CH16_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH16_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH16_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH16_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH16_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH16_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH16_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH16_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH16_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH16_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH16_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH16_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD16_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD16_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD16_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD16_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD16_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD16_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD16_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD16_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD16_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD16_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD16_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD16_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD16_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD16_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD16_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD16_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD16_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD16_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD16_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD16_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD16_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD16_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD16_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD16_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD16_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD16_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD16_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD16_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD16_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD16_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD16_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD16_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD16_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD16_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD16_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD16_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD16_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD16_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD16_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD16_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD16_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD16_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD16_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD16_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD16_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD16_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD16_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD16_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD16_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD16_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD16_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD16_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD16_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD16_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD16_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD16_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD16_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD16_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD16_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD16_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD16_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD16_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD16_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD16_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD16_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD16_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD16_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD16_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD16_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD16_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD16_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD16_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD16_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD16_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD16_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD16_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD16_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD16_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD16_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD16_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD16_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD16_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD16_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD16_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD16_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD16_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD16_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD16_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD16_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD16_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD16_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD16_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD16_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD16_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD16_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_START_SHIFT)) & spp_dma5_TCD_TCD16_CSR_START_MASK)

#define spp_dma5_TCD_TCD16_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD16_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD16_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD16_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD16_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD16_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD16_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD16_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD16_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD16_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD16_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD16_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD16_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD16_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD16_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD16_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD16_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD16_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD16_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD16_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD16_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD16_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD16_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD16_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD16_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD16_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD16_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD16_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD16_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD16_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD16_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD16_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD16_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD16_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD16_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD16_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD16_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD16_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD16_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD16_CSR_TMC_MASK)
/*! @} */

/*! @name TCD16_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD16_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD16_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD16_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD16_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD16_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD16_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD16_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD16_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD16_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD16_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD16_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD16_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD16_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD16_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD16_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD16_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD16_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD16_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD16_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH17_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH17_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH17_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH17_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH17_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH17_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH17_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH17_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH17_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH17_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH17_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH17_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH17_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH17_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH17_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH17_CSR_EEI_MASK)

#define spp_dma5_TCD_CH17_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH17_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH17_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH17_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_CX_SHIFT)) & spp_dma5_TCD_CH17_CSR_CX_MASK)

#define spp_dma5_TCD_CH17_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH17_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH17_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH17_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH17_CSR_ECX_MASK)

#define spp_dma5_TCD_CH17_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH17_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH17_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH17_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH17_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH17_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH17_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH17_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH17_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH17_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH17_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH17_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH17_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH17_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH17_CSR_DONE_MASK)

#define spp_dma5_TCD_CH17_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH17_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH17_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH17_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH17_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH17_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH17_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH17_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH17_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_DBE_SHIFT)) & spp_dma5_TCD_CH17_ES_DBE_MASK)

#define spp_dma5_TCD_CH17_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH17_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH17_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_SBE_SHIFT)) & spp_dma5_TCD_CH17_ES_SBE_MASK)

#define spp_dma5_TCD_CH17_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH17_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH17_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_SGE_SHIFT)) & spp_dma5_TCD_CH17_ES_SGE_MASK)

#define spp_dma5_TCD_CH17_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH17_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH17_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_NCE_SHIFT)) & spp_dma5_TCD_CH17_ES_NCE_MASK)

#define spp_dma5_TCD_CH17_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH17_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH17_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_DOE_SHIFT)) & spp_dma5_TCD_CH17_ES_DOE_MASK)

#define spp_dma5_TCD_CH17_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH17_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH17_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_DAE_SHIFT)) & spp_dma5_TCD_CH17_ES_DAE_MASK)

#define spp_dma5_TCD_CH17_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH17_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH17_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_SOE_SHIFT)) & spp_dma5_TCD_CH17_ES_SOE_MASK)

#define spp_dma5_TCD_CH17_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH17_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH17_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_SAE_SHIFT)) & spp_dma5_TCD_CH17_ES_SAE_MASK)

#define spp_dma5_TCD_CH17_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH17_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH17_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_ECX_SHIFT)) & spp_dma5_TCD_CH17_ES_ECX_MASK)

#define spp_dma5_TCD_CH17_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH17_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH17_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_UCE_SHIFT)) & spp_dma5_TCD_CH17_ES_UCE_MASK)

#define spp_dma5_TCD_CH17_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH17_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH17_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH17_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_ES_ERR_SHIFT)) & spp_dma5_TCD_CH17_ES_ERR_MASK)
/*! @} */

/*! @name CH17_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH17_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH17_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH17_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH17_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_INT_INT_SHIFT)) & spp_dma5_TCD_CH17_INT_INT_MASK)
/*! @} */

/*! @name CH17_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH17_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH17_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH17_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH17_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_SBR_MID_SHIFT)) & spp_dma5_TCD_CH17_SBR_MID_MASK)

#define spp_dma5_TCD_CH17_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH17_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH17_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH17_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH17_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH17_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH17_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH17_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH17_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH17_SBR_PAL_MASK)

#define spp_dma5_TCD_CH17_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH17_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH17_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH17_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH17_SBR_EMI_MASK)
/*! @} */

/*! @name CH17_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH17_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH17_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH17_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH17_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_PRI_APL_SHIFT)) & spp_dma5_TCD_CH17_PRI_APL_MASK)

#define spp_dma5_TCD_CH17_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH17_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH17_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH17_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH17_PRI_DPA_MASK)

#define spp_dma5_TCD_CH17_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH17_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH17_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH17_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH17_PRI_ECP_MASK)
/*! @} */

/*! @name CH17_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH17_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH17_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH17_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH17_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH17_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH17_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH17_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH17_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH17_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH17_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH17_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD17_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD17_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD17_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD17_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD17_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD17_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD17_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD17_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD17_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD17_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD17_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD17_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD17_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD17_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD17_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD17_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD17_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD17_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD17_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD17_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD17_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD17_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD17_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD17_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD17_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD17_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD17_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD17_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD17_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD17_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD17_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD17_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD17_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD17_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD17_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD17_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD17_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD17_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD17_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD17_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD17_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD17_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD17_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD17_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD17_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD17_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD17_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD17_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD17_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD17_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD17_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD17_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD17_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD17_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD17_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD17_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD17_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD17_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD17_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD17_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD17_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD17_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD17_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD17_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD17_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD17_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD17_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD17_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD17_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD17_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD17_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD17_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD17_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD17_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD17_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD17_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD17_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD17_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD17_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD17_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD17_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD17_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD17_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD17_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD17_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD17_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD17_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD17_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD17_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD17_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD17_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD17_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD17_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD17_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD17_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_START_SHIFT)) & spp_dma5_TCD_TCD17_CSR_START_MASK)

#define spp_dma5_TCD_TCD17_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD17_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD17_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD17_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD17_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD17_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD17_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD17_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD17_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD17_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD17_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD17_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD17_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD17_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD17_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD17_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD17_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD17_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD17_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD17_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD17_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD17_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD17_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD17_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD17_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD17_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD17_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD17_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD17_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD17_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD17_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD17_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD17_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD17_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD17_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD17_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD17_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD17_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD17_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD17_CSR_TMC_MASK)
/*! @} */

/*! @name TCD17_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD17_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD17_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD17_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD17_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD17_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD17_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD17_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD17_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD17_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD17_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD17_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD17_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD17_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD17_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD17_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD17_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD17_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD17_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD17_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH18_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH18_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH18_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH18_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH18_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH18_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH18_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH18_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH18_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH18_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH18_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH18_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH18_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH18_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH18_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH18_CSR_EEI_MASK)

#define spp_dma5_TCD_CH18_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH18_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH18_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH18_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_CX_SHIFT)) & spp_dma5_TCD_CH18_CSR_CX_MASK)

#define spp_dma5_TCD_CH18_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH18_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH18_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH18_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH18_CSR_ECX_MASK)

#define spp_dma5_TCD_CH18_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH18_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH18_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH18_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH18_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH18_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH18_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH18_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH18_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH18_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH18_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH18_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH18_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH18_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH18_CSR_DONE_MASK)

#define spp_dma5_TCD_CH18_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH18_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH18_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH18_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH18_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH18_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH18_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH18_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH18_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_DBE_SHIFT)) & spp_dma5_TCD_CH18_ES_DBE_MASK)

#define spp_dma5_TCD_CH18_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH18_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH18_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_SBE_SHIFT)) & spp_dma5_TCD_CH18_ES_SBE_MASK)

#define spp_dma5_TCD_CH18_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH18_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH18_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_SGE_SHIFT)) & spp_dma5_TCD_CH18_ES_SGE_MASK)

#define spp_dma5_TCD_CH18_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH18_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH18_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_NCE_SHIFT)) & spp_dma5_TCD_CH18_ES_NCE_MASK)

#define spp_dma5_TCD_CH18_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH18_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH18_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_DOE_SHIFT)) & spp_dma5_TCD_CH18_ES_DOE_MASK)

#define spp_dma5_TCD_CH18_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH18_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH18_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_DAE_SHIFT)) & spp_dma5_TCD_CH18_ES_DAE_MASK)

#define spp_dma5_TCD_CH18_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH18_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH18_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_SOE_SHIFT)) & spp_dma5_TCD_CH18_ES_SOE_MASK)

#define spp_dma5_TCD_CH18_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH18_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH18_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_SAE_SHIFT)) & spp_dma5_TCD_CH18_ES_SAE_MASK)

#define spp_dma5_TCD_CH18_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH18_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH18_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_ECX_SHIFT)) & spp_dma5_TCD_CH18_ES_ECX_MASK)

#define spp_dma5_TCD_CH18_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH18_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH18_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_UCE_SHIFT)) & spp_dma5_TCD_CH18_ES_UCE_MASK)

#define spp_dma5_TCD_CH18_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH18_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH18_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH18_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_ES_ERR_SHIFT)) & spp_dma5_TCD_CH18_ES_ERR_MASK)
/*! @} */

/*! @name CH18_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH18_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH18_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH18_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH18_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_INT_INT_SHIFT)) & spp_dma5_TCD_CH18_INT_INT_MASK)
/*! @} */

/*! @name CH18_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH18_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH18_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH18_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH18_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_SBR_MID_SHIFT)) & spp_dma5_TCD_CH18_SBR_MID_MASK)

#define spp_dma5_TCD_CH18_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH18_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH18_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH18_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH18_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH18_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH18_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH18_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH18_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH18_SBR_PAL_MASK)

#define spp_dma5_TCD_CH18_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH18_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH18_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH18_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH18_SBR_EMI_MASK)
/*! @} */

/*! @name CH18_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH18_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH18_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH18_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH18_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_PRI_APL_SHIFT)) & spp_dma5_TCD_CH18_PRI_APL_MASK)

#define spp_dma5_TCD_CH18_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH18_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH18_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH18_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH18_PRI_DPA_MASK)

#define spp_dma5_TCD_CH18_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH18_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH18_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH18_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH18_PRI_ECP_MASK)
/*! @} */

/*! @name CH18_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH18_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH18_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH18_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH18_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH18_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH18_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH18_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH18_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH18_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH18_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH18_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD18_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD18_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD18_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD18_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD18_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD18_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD18_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD18_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD18_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD18_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD18_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD18_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD18_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD18_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD18_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD18_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD18_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD18_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD18_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD18_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD18_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD18_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD18_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD18_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD18_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD18_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD18_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD18_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD18_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD18_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD18_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD18_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD18_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD18_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD18_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD18_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD18_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD18_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD18_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD18_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD18_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD18_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD18_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD18_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD18_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD18_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD18_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD18_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD18_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD18_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD18_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD18_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD18_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD18_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD18_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD18_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD18_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD18_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD18_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD18_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD18_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD18_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD18_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD18_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD18_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD18_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD18_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD18_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD18_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD18_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD18_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD18_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD18_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD18_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD18_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD18_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD18_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD18_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD18_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD18_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD18_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD18_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD18_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD18_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD18_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD18_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD18_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD18_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD18_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD18_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD18_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD18_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD18_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD18_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD18_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_START_SHIFT)) & spp_dma5_TCD_TCD18_CSR_START_MASK)

#define spp_dma5_TCD_TCD18_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD18_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD18_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD18_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD18_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD18_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD18_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD18_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD18_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD18_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD18_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD18_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD18_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD18_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD18_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD18_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD18_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD18_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD18_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD18_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD18_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD18_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD18_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD18_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD18_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD18_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD18_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD18_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD18_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD18_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD18_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD18_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD18_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD18_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD18_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD18_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD18_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD18_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD18_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD18_CSR_TMC_MASK)
/*! @} */

/*! @name TCD18_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD18_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD18_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD18_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD18_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD18_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD18_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD18_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD18_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD18_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD18_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD18_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD18_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD18_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD18_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD18_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD18_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD18_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD18_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD18_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH19_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH19_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH19_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH19_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH19_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH19_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH19_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH19_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH19_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH19_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH19_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH19_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH19_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH19_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH19_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH19_CSR_EEI_MASK)

#define spp_dma5_TCD_CH19_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH19_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH19_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH19_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_CX_SHIFT)) & spp_dma5_TCD_CH19_CSR_CX_MASK)

#define spp_dma5_TCD_CH19_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH19_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH19_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH19_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH19_CSR_ECX_MASK)

#define spp_dma5_TCD_CH19_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH19_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH19_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH19_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH19_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH19_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH19_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH19_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH19_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH19_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH19_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH19_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH19_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH19_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH19_CSR_DONE_MASK)

#define spp_dma5_TCD_CH19_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH19_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH19_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH19_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH19_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH19_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH19_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH19_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH19_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_DBE_SHIFT)) & spp_dma5_TCD_CH19_ES_DBE_MASK)

#define spp_dma5_TCD_CH19_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH19_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH19_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_SBE_SHIFT)) & spp_dma5_TCD_CH19_ES_SBE_MASK)

#define spp_dma5_TCD_CH19_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH19_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH19_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_SGE_SHIFT)) & spp_dma5_TCD_CH19_ES_SGE_MASK)

#define spp_dma5_TCD_CH19_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH19_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH19_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_NCE_SHIFT)) & spp_dma5_TCD_CH19_ES_NCE_MASK)

#define spp_dma5_TCD_CH19_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH19_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH19_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_DOE_SHIFT)) & spp_dma5_TCD_CH19_ES_DOE_MASK)

#define spp_dma5_TCD_CH19_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH19_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH19_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_DAE_SHIFT)) & spp_dma5_TCD_CH19_ES_DAE_MASK)

#define spp_dma5_TCD_CH19_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH19_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH19_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_SOE_SHIFT)) & spp_dma5_TCD_CH19_ES_SOE_MASK)

#define spp_dma5_TCD_CH19_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH19_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH19_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_SAE_SHIFT)) & spp_dma5_TCD_CH19_ES_SAE_MASK)

#define spp_dma5_TCD_CH19_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH19_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH19_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_ECX_SHIFT)) & spp_dma5_TCD_CH19_ES_ECX_MASK)

#define spp_dma5_TCD_CH19_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH19_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH19_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_UCE_SHIFT)) & spp_dma5_TCD_CH19_ES_UCE_MASK)

#define spp_dma5_TCD_CH19_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH19_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH19_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH19_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_ES_ERR_SHIFT)) & spp_dma5_TCD_CH19_ES_ERR_MASK)
/*! @} */

/*! @name CH19_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH19_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH19_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH19_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH19_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_INT_INT_SHIFT)) & spp_dma5_TCD_CH19_INT_INT_MASK)
/*! @} */

/*! @name CH19_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH19_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH19_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH19_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH19_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_SBR_MID_SHIFT)) & spp_dma5_TCD_CH19_SBR_MID_MASK)

#define spp_dma5_TCD_CH19_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH19_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH19_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH19_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH19_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH19_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH19_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH19_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH19_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH19_SBR_PAL_MASK)

#define spp_dma5_TCD_CH19_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH19_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH19_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH19_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH19_SBR_EMI_MASK)
/*! @} */

/*! @name CH19_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH19_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH19_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH19_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH19_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_PRI_APL_SHIFT)) & spp_dma5_TCD_CH19_PRI_APL_MASK)

#define spp_dma5_TCD_CH19_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH19_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH19_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH19_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH19_PRI_DPA_MASK)

#define spp_dma5_TCD_CH19_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH19_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH19_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH19_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH19_PRI_ECP_MASK)
/*! @} */

/*! @name CH19_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH19_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH19_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH19_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH19_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH19_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH19_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH19_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH19_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH19_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH19_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH19_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD19_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD19_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD19_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD19_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD19_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD19_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD19_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD19_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD19_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD19_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD19_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD19_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD19_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD19_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD19_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD19_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD19_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD19_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD19_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD19_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD19_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD19_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD19_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD19_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD19_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD19_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD19_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD19_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD19_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD19_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD19_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD19_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD19_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD19_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD19_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD19_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD19_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD19_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD19_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD19_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD19_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD19_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD19_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD19_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD19_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD19_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD19_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD19_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD19_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD19_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD19_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD19_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD19_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD19_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD19_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD19_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD19_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD19_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD19_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD19_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD19_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD19_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD19_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD19_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD19_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD19_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD19_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD19_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD19_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD19_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD19_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD19_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD19_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD19_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD19_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD19_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD19_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD19_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD19_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD19_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD19_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD19_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD19_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD19_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD19_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD19_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD19_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD19_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD19_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD19_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD19_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD19_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD19_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD19_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD19_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_START_SHIFT)) & spp_dma5_TCD_TCD19_CSR_START_MASK)

#define spp_dma5_TCD_TCD19_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD19_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD19_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD19_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD19_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD19_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD19_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD19_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD19_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD19_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD19_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD19_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD19_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD19_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD19_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD19_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD19_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD19_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD19_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD19_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD19_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD19_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD19_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD19_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD19_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD19_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD19_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD19_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD19_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD19_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD19_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD19_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD19_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD19_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD19_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD19_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD19_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD19_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD19_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD19_CSR_TMC_MASK)
/*! @} */

/*! @name TCD19_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD19_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD19_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD19_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD19_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD19_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD19_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD19_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD19_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD19_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD19_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD19_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD19_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD19_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD19_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD19_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD19_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD19_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD19_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD19_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH20_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH20_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH20_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH20_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH20_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH20_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH20_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH20_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH20_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH20_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH20_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH20_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH20_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH20_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH20_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH20_CSR_EEI_MASK)

#define spp_dma5_TCD_CH20_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH20_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH20_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH20_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_CX_SHIFT)) & spp_dma5_TCD_CH20_CSR_CX_MASK)

#define spp_dma5_TCD_CH20_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH20_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH20_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH20_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH20_CSR_ECX_MASK)

#define spp_dma5_TCD_CH20_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH20_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH20_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH20_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH20_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH20_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH20_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH20_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH20_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH20_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH20_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH20_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH20_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH20_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH20_CSR_DONE_MASK)

#define spp_dma5_TCD_CH20_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH20_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH20_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH20_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH20_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH20_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH20_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH20_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH20_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_DBE_SHIFT)) & spp_dma5_TCD_CH20_ES_DBE_MASK)

#define spp_dma5_TCD_CH20_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH20_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH20_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_SBE_SHIFT)) & spp_dma5_TCD_CH20_ES_SBE_MASK)

#define spp_dma5_TCD_CH20_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH20_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH20_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_SGE_SHIFT)) & spp_dma5_TCD_CH20_ES_SGE_MASK)

#define spp_dma5_TCD_CH20_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH20_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH20_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_NCE_SHIFT)) & spp_dma5_TCD_CH20_ES_NCE_MASK)

#define spp_dma5_TCD_CH20_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH20_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH20_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_DOE_SHIFT)) & spp_dma5_TCD_CH20_ES_DOE_MASK)

#define spp_dma5_TCD_CH20_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH20_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH20_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_DAE_SHIFT)) & spp_dma5_TCD_CH20_ES_DAE_MASK)

#define spp_dma5_TCD_CH20_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH20_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH20_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_SOE_SHIFT)) & spp_dma5_TCD_CH20_ES_SOE_MASK)

#define spp_dma5_TCD_CH20_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH20_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH20_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_SAE_SHIFT)) & spp_dma5_TCD_CH20_ES_SAE_MASK)

#define spp_dma5_TCD_CH20_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH20_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH20_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_ECX_SHIFT)) & spp_dma5_TCD_CH20_ES_ECX_MASK)

#define spp_dma5_TCD_CH20_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH20_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH20_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_UCE_SHIFT)) & spp_dma5_TCD_CH20_ES_UCE_MASK)

#define spp_dma5_TCD_CH20_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH20_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH20_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH20_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_ES_ERR_SHIFT)) & spp_dma5_TCD_CH20_ES_ERR_MASK)
/*! @} */

/*! @name CH20_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH20_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH20_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH20_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH20_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_INT_INT_SHIFT)) & spp_dma5_TCD_CH20_INT_INT_MASK)
/*! @} */

/*! @name CH20_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH20_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH20_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH20_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH20_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_SBR_MID_SHIFT)) & spp_dma5_TCD_CH20_SBR_MID_MASK)

#define spp_dma5_TCD_CH20_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH20_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH20_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH20_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH20_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH20_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH20_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH20_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH20_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH20_SBR_PAL_MASK)

#define spp_dma5_TCD_CH20_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH20_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH20_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH20_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH20_SBR_EMI_MASK)
/*! @} */

/*! @name CH20_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH20_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH20_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH20_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH20_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_PRI_APL_SHIFT)) & spp_dma5_TCD_CH20_PRI_APL_MASK)

#define spp_dma5_TCD_CH20_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH20_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH20_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH20_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH20_PRI_DPA_MASK)

#define spp_dma5_TCD_CH20_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH20_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH20_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH20_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH20_PRI_ECP_MASK)
/*! @} */

/*! @name CH20_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH20_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH20_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH20_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH20_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH20_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH20_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH20_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH20_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH20_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH20_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH20_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD20_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD20_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD20_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD20_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD20_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD20_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD20_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD20_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD20_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD20_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD20_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD20_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD20_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD20_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD20_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD20_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD20_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD20_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD20_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD20_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD20_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD20_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD20_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD20_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD20_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD20_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD20_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD20_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD20_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD20_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD20_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD20_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD20_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD20_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD20_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD20_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD20_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD20_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD20_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD20_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD20_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD20_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD20_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD20_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD20_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD20_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD20_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD20_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD20_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD20_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD20_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD20_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD20_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD20_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD20_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD20_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD20_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD20_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD20_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD20_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD20_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD20_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD20_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD20_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD20_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD20_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD20_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD20_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD20_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD20_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD20_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD20_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD20_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD20_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD20_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD20_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD20_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD20_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD20_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD20_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD20_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD20_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD20_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD20_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD20_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD20_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD20_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD20_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD20_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD20_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD20_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD20_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD20_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD20_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD20_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_START_SHIFT)) & spp_dma5_TCD_TCD20_CSR_START_MASK)

#define spp_dma5_TCD_TCD20_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD20_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD20_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD20_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD20_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD20_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD20_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD20_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD20_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD20_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD20_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD20_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD20_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD20_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD20_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD20_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD20_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD20_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD20_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD20_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD20_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD20_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD20_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD20_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD20_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD20_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD20_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD20_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD20_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD20_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD20_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD20_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD20_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD20_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD20_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD20_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD20_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD20_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD20_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD20_CSR_TMC_MASK)
/*! @} */

/*! @name TCD20_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD20_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD20_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD20_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD20_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD20_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD20_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD20_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD20_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD20_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD20_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD20_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD20_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD20_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD20_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD20_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD20_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD20_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD20_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD20_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH21_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH21_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH21_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH21_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH21_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH21_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH21_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH21_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH21_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH21_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH21_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH21_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH21_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH21_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH21_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH21_CSR_EEI_MASK)

#define spp_dma5_TCD_CH21_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH21_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH21_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH21_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_CX_SHIFT)) & spp_dma5_TCD_CH21_CSR_CX_MASK)

#define spp_dma5_TCD_CH21_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH21_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH21_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH21_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH21_CSR_ECX_MASK)

#define spp_dma5_TCD_CH21_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH21_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH21_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH21_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH21_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH21_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH21_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH21_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH21_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH21_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH21_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH21_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH21_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH21_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH21_CSR_DONE_MASK)

#define spp_dma5_TCD_CH21_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH21_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH21_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH21_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH21_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH21_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH21_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH21_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH21_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_DBE_SHIFT)) & spp_dma5_TCD_CH21_ES_DBE_MASK)

#define spp_dma5_TCD_CH21_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH21_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH21_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_SBE_SHIFT)) & spp_dma5_TCD_CH21_ES_SBE_MASK)

#define spp_dma5_TCD_CH21_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH21_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH21_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_SGE_SHIFT)) & spp_dma5_TCD_CH21_ES_SGE_MASK)

#define spp_dma5_TCD_CH21_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH21_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH21_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_NCE_SHIFT)) & spp_dma5_TCD_CH21_ES_NCE_MASK)

#define spp_dma5_TCD_CH21_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH21_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH21_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_DOE_SHIFT)) & spp_dma5_TCD_CH21_ES_DOE_MASK)

#define spp_dma5_TCD_CH21_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH21_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH21_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_DAE_SHIFT)) & spp_dma5_TCD_CH21_ES_DAE_MASK)

#define spp_dma5_TCD_CH21_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH21_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH21_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_SOE_SHIFT)) & spp_dma5_TCD_CH21_ES_SOE_MASK)

#define spp_dma5_TCD_CH21_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH21_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH21_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_SAE_SHIFT)) & spp_dma5_TCD_CH21_ES_SAE_MASK)

#define spp_dma5_TCD_CH21_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH21_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH21_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_ECX_SHIFT)) & spp_dma5_TCD_CH21_ES_ECX_MASK)

#define spp_dma5_TCD_CH21_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH21_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH21_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_UCE_SHIFT)) & spp_dma5_TCD_CH21_ES_UCE_MASK)

#define spp_dma5_TCD_CH21_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH21_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH21_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH21_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_ES_ERR_SHIFT)) & spp_dma5_TCD_CH21_ES_ERR_MASK)
/*! @} */

/*! @name CH21_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH21_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH21_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH21_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH21_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_INT_INT_SHIFT)) & spp_dma5_TCD_CH21_INT_INT_MASK)
/*! @} */

/*! @name CH21_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH21_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH21_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH21_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH21_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_SBR_MID_SHIFT)) & spp_dma5_TCD_CH21_SBR_MID_MASK)

#define spp_dma5_TCD_CH21_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH21_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH21_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH21_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH21_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH21_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH21_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH21_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH21_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH21_SBR_PAL_MASK)

#define spp_dma5_TCD_CH21_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH21_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH21_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH21_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH21_SBR_EMI_MASK)
/*! @} */

/*! @name CH21_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH21_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH21_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH21_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH21_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_PRI_APL_SHIFT)) & spp_dma5_TCD_CH21_PRI_APL_MASK)

#define spp_dma5_TCD_CH21_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH21_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH21_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH21_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH21_PRI_DPA_MASK)

#define spp_dma5_TCD_CH21_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH21_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH21_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH21_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH21_PRI_ECP_MASK)
/*! @} */

/*! @name CH21_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH21_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH21_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH21_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH21_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH21_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH21_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH21_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH21_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH21_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH21_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH21_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD21_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD21_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD21_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD21_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD21_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD21_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD21_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD21_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD21_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD21_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD21_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD21_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD21_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD21_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD21_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD21_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD21_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD21_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD21_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD21_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD21_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD21_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD21_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD21_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD21_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD21_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD21_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD21_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD21_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD21_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD21_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD21_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD21_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD21_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD21_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD21_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD21_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD21_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD21_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD21_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD21_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD21_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD21_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD21_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD21_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD21_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD21_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD21_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD21_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD21_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD21_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD21_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD21_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD21_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD21_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD21_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD21_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD21_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD21_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD21_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD21_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD21_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD21_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD21_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD21_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD21_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD21_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD21_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD21_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD21_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD21_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD21_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD21_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD21_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD21_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD21_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD21_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD21_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD21_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD21_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD21_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD21_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD21_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD21_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD21_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD21_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD21_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD21_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD21_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD21_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD21_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD21_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD21_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD21_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD21_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_START_SHIFT)) & spp_dma5_TCD_TCD21_CSR_START_MASK)

#define spp_dma5_TCD_TCD21_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD21_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD21_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD21_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD21_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD21_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD21_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD21_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD21_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD21_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD21_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD21_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD21_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD21_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD21_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD21_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD21_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD21_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD21_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD21_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD21_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD21_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD21_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD21_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD21_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD21_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD21_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD21_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD21_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD21_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD21_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD21_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD21_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD21_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD21_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD21_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD21_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD21_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD21_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD21_CSR_TMC_MASK)
/*! @} */

/*! @name TCD21_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD21_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD21_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD21_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD21_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD21_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD21_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD21_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD21_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD21_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD21_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD21_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD21_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD21_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD21_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD21_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD21_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD21_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD21_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD21_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH22_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH22_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH22_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH22_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH22_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH22_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH22_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH22_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH22_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH22_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH22_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH22_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH22_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH22_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH22_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH22_CSR_EEI_MASK)

#define spp_dma5_TCD_CH22_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH22_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH22_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH22_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_CX_SHIFT)) & spp_dma5_TCD_CH22_CSR_CX_MASK)

#define spp_dma5_TCD_CH22_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH22_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH22_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH22_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH22_CSR_ECX_MASK)

#define spp_dma5_TCD_CH22_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH22_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH22_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH22_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH22_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH22_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH22_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH22_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH22_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH22_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH22_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH22_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH22_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH22_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH22_CSR_DONE_MASK)

#define spp_dma5_TCD_CH22_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH22_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH22_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH22_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH22_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH22_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH22_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH22_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH22_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_DBE_SHIFT)) & spp_dma5_TCD_CH22_ES_DBE_MASK)

#define spp_dma5_TCD_CH22_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH22_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH22_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_SBE_SHIFT)) & spp_dma5_TCD_CH22_ES_SBE_MASK)

#define spp_dma5_TCD_CH22_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH22_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH22_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_SGE_SHIFT)) & spp_dma5_TCD_CH22_ES_SGE_MASK)

#define spp_dma5_TCD_CH22_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH22_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH22_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_NCE_SHIFT)) & spp_dma5_TCD_CH22_ES_NCE_MASK)

#define spp_dma5_TCD_CH22_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH22_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH22_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_DOE_SHIFT)) & spp_dma5_TCD_CH22_ES_DOE_MASK)

#define spp_dma5_TCD_CH22_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH22_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH22_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_DAE_SHIFT)) & spp_dma5_TCD_CH22_ES_DAE_MASK)

#define spp_dma5_TCD_CH22_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH22_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH22_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_SOE_SHIFT)) & spp_dma5_TCD_CH22_ES_SOE_MASK)

#define spp_dma5_TCD_CH22_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH22_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH22_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_SAE_SHIFT)) & spp_dma5_TCD_CH22_ES_SAE_MASK)

#define spp_dma5_TCD_CH22_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH22_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH22_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_ECX_SHIFT)) & spp_dma5_TCD_CH22_ES_ECX_MASK)

#define spp_dma5_TCD_CH22_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH22_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH22_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_UCE_SHIFT)) & spp_dma5_TCD_CH22_ES_UCE_MASK)

#define spp_dma5_TCD_CH22_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH22_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH22_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH22_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_ES_ERR_SHIFT)) & spp_dma5_TCD_CH22_ES_ERR_MASK)
/*! @} */

/*! @name CH22_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH22_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH22_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH22_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH22_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_INT_INT_SHIFT)) & spp_dma5_TCD_CH22_INT_INT_MASK)
/*! @} */

/*! @name CH22_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH22_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH22_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH22_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH22_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_SBR_MID_SHIFT)) & spp_dma5_TCD_CH22_SBR_MID_MASK)

#define spp_dma5_TCD_CH22_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH22_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH22_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH22_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH22_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH22_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH22_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH22_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH22_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH22_SBR_PAL_MASK)

#define spp_dma5_TCD_CH22_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH22_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH22_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH22_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH22_SBR_EMI_MASK)
/*! @} */

/*! @name CH22_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH22_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH22_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH22_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH22_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_PRI_APL_SHIFT)) & spp_dma5_TCD_CH22_PRI_APL_MASK)

#define spp_dma5_TCD_CH22_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH22_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH22_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH22_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH22_PRI_DPA_MASK)

#define spp_dma5_TCD_CH22_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH22_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH22_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH22_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH22_PRI_ECP_MASK)
/*! @} */

/*! @name CH22_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH22_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH22_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH22_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH22_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH22_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH22_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH22_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH22_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH22_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH22_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH22_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD22_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD22_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD22_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD22_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD22_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD22_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD22_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD22_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD22_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD22_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD22_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD22_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD22_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD22_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD22_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD22_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD22_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD22_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD22_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD22_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD22_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD22_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD22_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD22_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD22_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD22_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD22_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD22_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD22_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD22_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD22_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD22_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD22_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD22_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD22_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD22_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD22_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD22_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD22_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD22_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD22_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD22_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD22_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD22_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD22_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD22_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD22_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD22_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD22_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD22_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD22_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD22_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD22_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD22_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD22_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD22_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD22_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD22_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD22_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD22_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD22_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD22_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD22_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD22_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD22_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD22_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD22_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD22_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD22_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD22_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD22_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD22_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD22_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD22_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD22_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD22_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD22_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD22_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD22_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD22_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD22_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD22_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD22_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD22_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD22_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD22_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD22_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD22_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD22_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD22_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD22_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD22_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD22_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD22_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD22_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_START_SHIFT)) & spp_dma5_TCD_TCD22_CSR_START_MASK)

#define spp_dma5_TCD_TCD22_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD22_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD22_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD22_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD22_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD22_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD22_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD22_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD22_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD22_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD22_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD22_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD22_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD22_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD22_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD22_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD22_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD22_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD22_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD22_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD22_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD22_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD22_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD22_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD22_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD22_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD22_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD22_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD22_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD22_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD22_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD22_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD22_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD22_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD22_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD22_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD22_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD22_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD22_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD22_CSR_TMC_MASK)
/*! @} */

/*! @name TCD22_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD22_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD22_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD22_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD22_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD22_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD22_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD22_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD22_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD22_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD22_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD22_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD22_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD22_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD22_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD22_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD22_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD22_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD22_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD22_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH23_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH23_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH23_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH23_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH23_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH23_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH23_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH23_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH23_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH23_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH23_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH23_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH23_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH23_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH23_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH23_CSR_EEI_MASK)

#define spp_dma5_TCD_CH23_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH23_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH23_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH23_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_CX_SHIFT)) & spp_dma5_TCD_CH23_CSR_CX_MASK)

#define spp_dma5_TCD_CH23_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH23_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH23_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH23_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH23_CSR_ECX_MASK)

#define spp_dma5_TCD_CH23_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH23_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH23_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH23_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH23_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH23_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH23_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH23_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH23_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH23_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH23_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH23_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH23_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH23_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH23_CSR_DONE_MASK)

#define spp_dma5_TCD_CH23_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH23_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH23_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH23_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH23_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH23_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH23_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH23_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH23_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_DBE_SHIFT)) & spp_dma5_TCD_CH23_ES_DBE_MASK)

#define spp_dma5_TCD_CH23_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH23_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH23_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_SBE_SHIFT)) & spp_dma5_TCD_CH23_ES_SBE_MASK)

#define spp_dma5_TCD_CH23_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH23_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH23_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_SGE_SHIFT)) & spp_dma5_TCD_CH23_ES_SGE_MASK)

#define spp_dma5_TCD_CH23_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH23_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH23_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_NCE_SHIFT)) & spp_dma5_TCD_CH23_ES_NCE_MASK)

#define spp_dma5_TCD_CH23_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH23_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH23_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_DOE_SHIFT)) & spp_dma5_TCD_CH23_ES_DOE_MASK)

#define spp_dma5_TCD_CH23_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH23_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH23_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_DAE_SHIFT)) & spp_dma5_TCD_CH23_ES_DAE_MASK)

#define spp_dma5_TCD_CH23_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH23_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH23_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_SOE_SHIFT)) & spp_dma5_TCD_CH23_ES_SOE_MASK)

#define spp_dma5_TCD_CH23_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH23_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH23_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_SAE_SHIFT)) & spp_dma5_TCD_CH23_ES_SAE_MASK)

#define spp_dma5_TCD_CH23_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH23_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH23_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_ECX_SHIFT)) & spp_dma5_TCD_CH23_ES_ECX_MASK)

#define spp_dma5_TCD_CH23_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH23_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH23_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_UCE_SHIFT)) & spp_dma5_TCD_CH23_ES_UCE_MASK)

#define spp_dma5_TCD_CH23_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH23_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH23_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH23_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_ES_ERR_SHIFT)) & spp_dma5_TCD_CH23_ES_ERR_MASK)
/*! @} */

/*! @name CH23_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH23_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH23_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH23_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH23_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_INT_INT_SHIFT)) & spp_dma5_TCD_CH23_INT_INT_MASK)
/*! @} */

/*! @name CH23_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH23_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH23_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH23_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH23_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_SBR_MID_SHIFT)) & spp_dma5_TCD_CH23_SBR_MID_MASK)

#define spp_dma5_TCD_CH23_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH23_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH23_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH23_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH23_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH23_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH23_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH23_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH23_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH23_SBR_PAL_MASK)

#define spp_dma5_TCD_CH23_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH23_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH23_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH23_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH23_SBR_EMI_MASK)
/*! @} */

/*! @name CH23_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH23_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH23_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH23_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH23_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_PRI_APL_SHIFT)) & spp_dma5_TCD_CH23_PRI_APL_MASK)

#define spp_dma5_TCD_CH23_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH23_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH23_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH23_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH23_PRI_DPA_MASK)

#define spp_dma5_TCD_CH23_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH23_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH23_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH23_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH23_PRI_ECP_MASK)
/*! @} */

/*! @name CH23_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH23_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH23_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH23_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH23_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH23_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH23_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH23_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH23_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH23_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH23_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH23_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD23_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD23_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD23_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD23_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD23_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD23_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD23_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD23_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD23_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD23_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD23_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD23_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD23_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD23_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD23_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD23_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD23_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD23_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD23_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD23_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD23_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD23_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD23_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD23_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD23_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD23_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD23_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD23_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD23_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD23_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD23_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD23_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD23_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD23_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD23_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD23_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD23_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD23_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD23_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD23_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD23_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD23_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD23_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD23_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD23_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD23_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD23_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD23_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD23_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD23_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD23_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD23_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD23_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD23_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD23_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD23_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD23_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD23_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD23_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD23_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD23_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD23_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD23_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD23_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD23_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD23_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD23_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD23_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD23_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD23_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD23_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD23_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD23_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD23_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD23_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD23_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD23_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD23_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD23_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD23_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD23_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD23_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD23_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD23_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD23_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD23_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD23_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD23_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD23_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD23_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD23_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD23_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD23_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD23_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD23_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_START_SHIFT)) & spp_dma5_TCD_TCD23_CSR_START_MASK)

#define spp_dma5_TCD_TCD23_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD23_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD23_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD23_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD23_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD23_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD23_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD23_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD23_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD23_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD23_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD23_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD23_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD23_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD23_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD23_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD23_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD23_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD23_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD23_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD23_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD23_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD23_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD23_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD23_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD23_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD23_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD23_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD23_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD23_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD23_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD23_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD23_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD23_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD23_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD23_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD23_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD23_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD23_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD23_CSR_TMC_MASK)
/*! @} */

/*! @name TCD23_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD23_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD23_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD23_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD23_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD23_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD23_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD23_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD23_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD23_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD23_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD23_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD23_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD23_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD23_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD23_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD23_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD23_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD23_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD23_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH24_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH24_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH24_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH24_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH24_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH24_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH24_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH24_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH24_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH24_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH24_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH24_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH24_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH24_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH24_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH24_CSR_EEI_MASK)

#define spp_dma5_TCD_CH24_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH24_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH24_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH24_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_CX_SHIFT)) & spp_dma5_TCD_CH24_CSR_CX_MASK)

#define spp_dma5_TCD_CH24_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH24_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH24_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH24_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH24_CSR_ECX_MASK)

#define spp_dma5_TCD_CH24_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH24_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH24_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH24_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH24_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH24_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH24_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH24_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH24_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH24_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH24_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH24_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH24_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH24_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH24_CSR_DONE_MASK)

#define spp_dma5_TCD_CH24_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH24_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH24_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH24_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH24_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH24_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH24_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH24_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH24_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_DBE_SHIFT)) & spp_dma5_TCD_CH24_ES_DBE_MASK)

#define spp_dma5_TCD_CH24_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH24_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH24_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_SBE_SHIFT)) & spp_dma5_TCD_CH24_ES_SBE_MASK)

#define spp_dma5_TCD_CH24_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH24_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH24_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_SGE_SHIFT)) & spp_dma5_TCD_CH24_ES_SGE_MASK)

#define spp_dma5_TCD_CH24_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH24_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH24_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_NCE_SHIFT)) & spp_dma5_TCD_CH24_ES_NCE_MASK)

#define spp_dma5_TCD_CH24_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH24_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH24_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_DOE_SHIFT)) & spp_dma5_TCD_CH24_ES_DOE_MASK)

#define spp_dma5_TCD_CH24_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH24_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH24_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_DAE_SHIFT)) & spp_dma5_TCD_CH24_ES_DAE_MASK)

#define spp_dma5_TCD_CH24_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH24_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH24_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_SOE_SHIFT)) & spp_dma5_TCD_CH24_ES_SOE_MASK)

#define spp_dma5_TCD_CH24_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH24_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH24_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_SAE_SHIFT)) & spp_dma5_TCD_CH24_ES_SAE_MASK)

#define spp_dma5_TCD_CH24_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH24_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH24_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_ECX_SHIFT)) & spp_dma5_TCD_CH24_ES_ECX_MASK)

#define spp_dma5_TCD_CH24_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH24_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH24_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_UCE_SHIFT)) & spp_dma5_TCD_CH24_ES_UCE_MASK)

#define spp_dma5_TCD_CH24_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH24_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH24_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH24_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_ES_ERR_SHIFT)) & spp_dma5_TCD_CH24_ES_ERR_MASK)
/*! @} */

/*! @name CH24_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH24_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH24_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH24_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH24_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_INT_INT_SHIFT)) & spp_dma5_TCD_CH24_INT_INT_MASK)
/*! @} */

/*! @name CH24_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH24_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH24_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH24_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH24_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_SBR_MID_SHIFT)) & spp_dma5_TCD_CH24_SBR_MID_MASK)

#define spp_dma5_TCD_CH24_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH24_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH24_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH24_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH24_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH24_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH24_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH24_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH24_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH24_SBR_PAL_MASK)

#define spp_dma5_TCD_CH24_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH24_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH24_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH24_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH24_SBR_EMI_MASK)
/*! @} */

/*! @name CH24_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH24_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH24_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH24_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH24_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_PRI_APL_SHIFT)) & spp_dma5_TCD_CH24_PRI_APL_MASK)

#define spp_dma5_TCD_CH24_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH24_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH24_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH24_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH24_PRI_DPA_MASK)

#define spp_dma5_TCD_CH24_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH24_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH24_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH24_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH24_PRI_ECP_MASK)
/*! @} */

/*! @name CH24_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH24_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH24_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH24_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH24_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH24_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH24_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH24_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH24_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH24_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH24_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH24_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD24_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD24_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD24_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD24_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD24_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD24_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD24_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD24_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD24_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD24_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD24_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD24_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD24_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD24_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD24_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD24_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD24_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD24_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD24_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD24_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD24_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD24_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD24_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD24_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD24_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD24_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD24_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD24_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD24_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD24_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD24_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD24_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD24_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD24_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD24_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD24_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD24_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD24_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD24_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD24_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD24_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD24_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD24_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD24_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD24_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD24_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD24_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD24_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD24_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD24_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD24_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD24_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD24_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD24_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD24_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD24_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD24_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD24_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD24_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD24_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD24_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD24_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD24_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD24_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD24_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD24_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD24_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD24_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD24_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD24_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD24_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD24_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD24_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD24_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD24_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD24_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD24_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD24_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD24_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD24_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD24_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD24_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD24_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD24_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD24_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD24_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD24_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD24_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD24_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD24_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD24_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD24_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD24_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD24_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD24_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_START_SHIFT)) & spp_dma5_TCD_TCD24_CSR_START_MASK)

#define spp_dma5_TCD_TCD24_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD24_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD24_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD24_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD24_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD24_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD24_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD24_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD24_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD24_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD24_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD24_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD24_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD24_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD24_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD24_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD24_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD24_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD24_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD24_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD24_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD24_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD24_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD24_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD24_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD24_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD24_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD24_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD24_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD24_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD24_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD24_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD24_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD24_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD24_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD24_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD24_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD24_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD24_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD24_CSR_TMC_MASK)
/*! @} */

/*! @name TCD24_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD24_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD24_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD24_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD24_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD24_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD24_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD24_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD24_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD24_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD24_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD24_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD24_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD24_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD24_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD24_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD24_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD24_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD24_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD24_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH25_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH25_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH25_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH25_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH25_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH25_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH25_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH25_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH25_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH25_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH25_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH25_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH25_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH25_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH25_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH25_CSR_EEI_MASK)

#define spp_dma5_TCD_CH25_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH25_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH25_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH25_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_CX_SHIFT)) & spp_dma5_TCD_CH25_CSR_CX_MASK)

#define spp_dma5_TCD_CH25_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH25_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH25_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH25_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH25_CSR_ECX_MASK)

#define spp_dma5_TCD_CH25_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH25_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH25_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH25_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH25_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH25_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH25_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH25_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH25_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH25_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH25_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH25_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH25_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH25_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH25_CSR_DONE_MASK)

#define spp_dma5_TCD_CH25_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH25_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH25_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH25_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH25_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH25_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH25_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH25_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH25_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_DBE_SHIFT)) & spp_dma5_TCD_CH25_ES_DBE_MASK)

#define spp_dma5_TCD_CH25_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH25_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH25_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_SBE_SHIFT)) & spp_dma5_TCD_CH25_ES_SBE_MASK)

#define spp_dma5_TCD_CH25_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH25_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH25_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_SGE_SHIFT)) & spp_dma5_TCD_CH25_ES_SGE_MASK)

#define spp_dma5_TCD_CH25_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH25_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH25_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_NCE_SHIFT)) & spp_dma5_TCD_CH25_ES_NCE_MASK)

#define spp_dma5_TCD_CH25_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH25_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH25_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_DOE_SHIFT)) & spp_dma5_TCD_CH25_ES_DOE_MASK)

#define spp_dma5_TCD_CH25_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH25_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH25_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_DAE_SHIFT)) & spp_dma5_TCD_CH25_ES_DAE_MASK)

#define spp_dma5_TCD_CH25_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH25_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH25_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_SOE_SHIFT)) & spp_dma5_TCD_CH25_ES_SOE_MASK)

#define spp_dma5_TCD_CH25_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH25_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH25_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_SAE_SHIFT)) & spp_dma5_TCD_CH25_ES_SAE_MASK)

#define spp_dma5_TCD_CH25_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH25_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH25_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_ECX_SHIFT)) & spp_dma5_TCD_CH25_ES_ECX_MASK)

#define spp_dma5_TCD_CH25_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH25_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH25_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_UCE_SHIFT)) & spp_dma5_TCD_CH25_ES_UCE_MASK)

#define spp_dma5_TCD_CH25_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH25_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH25_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH25_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_ES_ERR_SHIFT)) & spp_dma5_TCD_CH25_ES_ERR_MASK)
/*! @} */

/*! @name CH25_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH25_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH25_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH25_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH25_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_INT_INT_SHIFT)) & spp_dma5_TCD_CH25_INT_INT_MASK)
/*! @} */

/*! @name CH25_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH25_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH25_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH25_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH25_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_SBR_MID_SHIFT)) & spp_dma5_TCD_CH25_SBR_MID_MASK)

#define spp_dma5_TCD_CH25_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH25_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH25_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH25_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH25_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH25_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH25_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH25_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH25_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH25_SBR_PAL_MASK)

#define spp_dma5_TCD_CH25_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH25_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH25_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH25_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH25_SBR_EMI_MASK)
/*! @} */

/*! @name CH25_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH25_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH25_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH25_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH25_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_PRI_APL_SHIFT)) & spp_dma5_TCD_CH25_PRI_APL_MASK)

#define spp_dma5_TCD_CH25_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH25_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH25_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH25_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH25_PRI_DPA_MASK)

#define spp_dma5_TCD_CH25_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH25_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH25_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH25_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH25_PRI_ECP_MASK)
/*! @} */

/*! @name CH25_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH25_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH25_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH25_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH25_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH25_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH25_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH25_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH25_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH25_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH25_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH25_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD25_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD25_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD25_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD25_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD25_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD25_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD25_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD25_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD25_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD25_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD25_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD25_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD25_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD25_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD25_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD25_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD25_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD25_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD25_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD25_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD25_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD25_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD25_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD25_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD25_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD25_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD25_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD25_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD25_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD25_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD25_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD25_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD25_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD25_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD25_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD25_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD25_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD25_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD25_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD25_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD25_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD25_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD25_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD25_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD25_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD25_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD25_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD25_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD25_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD25_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD25_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD25_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD25_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD25_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD25_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD25_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD25_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD25_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD25_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD25_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD25_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD25_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD25_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD25_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD25_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD25_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD25_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD25_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD25_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD25_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD25_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD25_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD25_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD25_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD25_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD25_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD25_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD25_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD25_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD25_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD25_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD25_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD25_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD25_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD25_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD25_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD25_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD25_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD25_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD25_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD25_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD25_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD25_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD25_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD25_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_START_SHIFT)) & spp_dma5_TCD_TCD25_CSR_START_MASK)

#define spp_dma5_TCD_TCD25_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD25_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD25_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD25_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD25_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD25_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD25_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD25_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD25_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD25_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD25_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD25_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD25_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD25_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD25_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD25_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD25_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD25_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD25_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD25_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD25_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD25_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD25_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD25_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD25_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD25_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD25_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD25_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD25_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD25_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD25_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD25_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD25_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD25_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD25_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD25_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD25_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD25_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD25_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD25_CSR_TMC_MASK)
/*! @} */

/*! @name TCD25_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD25_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD25_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD25_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD25_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD25_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD25_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD25_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD25_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD25_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD25_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD25_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD25_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD25_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD25_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD25_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD25_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD25_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD25_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD25_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH26_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH26_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH26_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH26_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH26_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH26_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH26_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH26_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH26_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH26_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH26_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH26_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH26_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH26_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH26_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH26_CSR_EEI_MASK)

#define spp_dma5_TCD_CH26_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH26_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH26_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH26_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_CX_SHIFT)) & spp_dma5_TCD_CH26_CSR_CX_MASK)

#define spp_dma5_TCD_CH26_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH26_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH26_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH26_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH26_CSR_ECX_MASK)

#define spp_dma5_TCD_CH26_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH26_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH26_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH26_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH26_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH26_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH26_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH26_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH26_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH26_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH26_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH26_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH26_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH26_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH26_CSR_DONE_MASK)

#define spp_dma5_TCD_CH26_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH26_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH26_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH26_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH26_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH26_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH26_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH26_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH26_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_DBE_SHIFT)) & spp_dma5_TCD_CH26_ES_DBE_MASK)

#define spp_dma5_TCD_CH26_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH26_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH26_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_SBE_SHIFT)) & spp_dma5_TCD_CH26_ES_SBE_MASK)

#define spp_dma5_TCD_CH26_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH26_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH26_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_SGE_SHIFT)) & spp_dma5_TCD_CH26_ES_SGE_MASK)

#define spp_dma5_TCD_CH26_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH26_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH26_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_NCE_SHIFT)) & spp_dma5_TCD_CH26_ES_NCE_MASK)

#define spp_dma5_TCD_CH26_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH26_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH26_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_DOE_SHIFT)) & spp_dma5_TCD_CH26_ES_DOE_MASK)

#define spp_dma5_TCD_CH26_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH26_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH26_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_DAE_SHIFT)) & spp_dma5_TCD_CH26_ES_DAE_MASK)

#define spp_dma5_TCD_CH26_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH26_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH26_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_SOE_SHIFT)) & spp_dma5_TCD_CH26_ES_SOE_MASK)

#define spp_dma5_TCD_CH26_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH26_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH26_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_SAE_SHIFT)) & spp_dma5_TCD_CH26_ES_SAE_MASK)

#define spp_dma5_TCD_CH26_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH26_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH26_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_ECX_SHIFT)) & spp_dma5_TCD_CH26_ES_ECX_MASK)

#define spp_dma5_TCD_CH26_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH26_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH26_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_UCE_SHIFT)) & spp_dma5_TCD_CH26_ES_UCE_MASK)

#define spp_dma5_TCD_CH26_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH26_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH26_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH26_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_ES_ERR_SHIFT)) & spp_dma5_TCD_CH26_ES_ERR_MASK)
/*! @} */

/*! @name CH26_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH26_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH26_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH26_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH26_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_INT_INT_SHIFT)) & spp_dma5_TCD_CH26_INT_INT_MASK)
/*! @} */

/*! @name CH26_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH26_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH26_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH26_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH26_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_SBR_MID_SHIFT)) & spp_dma5_TCD_CH26_SBR_MID_MASK)

#define spp_dma5_TCD_CH26_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH26_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH26_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH26_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH26_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH26_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH26_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH26_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH26_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH26_SBR_PAL_MASK)

#define spp_dma5_TCD_CH26_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH26_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH26_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH26_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH26_SBR_EMI_MASK)
/*! @} */

/*! @name CH26_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH26_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH26_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH26_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH26_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_PRI_APL_SHIFT)) & spp_dma5_TCD_CH26_PRI_APL_MASK)

#define spp_dma5_TCD_CH26_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH26_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH26_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH26_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH26_PRI_DPA_MASK)

#define spp_dma5_TCD_CH26_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH26_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH26_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH26_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH26_PRI_ECP_MASK)
/*! @} */

/*! @name CH26_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH26_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH26_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH26_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH26_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH26_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH26_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH26_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH26_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH26_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH26_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH26_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD26_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD26_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD26_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD26_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD26_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD26_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD26_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD26_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD26_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD26_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD26_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD26_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD26_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD26_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD26_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD26_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD26_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD26_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD26_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD26_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD26_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD26_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD26_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD26_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD26_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD26_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD26_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD26_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD26_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD26_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD26_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD26_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD26_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD26_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD26_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD26_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD26_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD26_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD26_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD26_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD26_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD26_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD26_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD26_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD26_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD26_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD26_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD26_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD26_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD26_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD26_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD26_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD26_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD26_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD26_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD26_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD26_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD26_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD26_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD26_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD26_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD26_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD26_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD26_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD26_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD26_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD26_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD26_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD26_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD26_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD26_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD26_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD26_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD26_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD26_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD26_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD26_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD26_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD26_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD26_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD26_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD26_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD26_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD26_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD26_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD26_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD26_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD26_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD26_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD26_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD26_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD26_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD26_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD26_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD26_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_START_SHIFT)) & spp_dma5_TCD_TCD26_CSR_START_MASK)

#define spp_dma5_TCD_TCD26_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD26_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD26_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD26_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD26_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD26_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD26_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD26_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD26_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD26_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD26_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD26_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD26_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD26_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD26_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD26_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD26_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD26_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD26_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD26_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD26_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD26_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD26_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD26_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD26_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD26_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD26_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD26_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD26_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD26_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD26_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD26_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD26_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD26_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD26_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD26_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD26_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD26_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD26_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD26_CSR_TMC_MASK)
/*! @} */

/*! @name TCD26_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD26_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD26_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD26_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD26_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD26_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD26_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD26_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD26_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD26_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD26_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD26_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD26_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD26_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD26_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD26_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD26_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD26_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD26_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD26_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH27_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH27_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH27_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH27_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH27_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH27_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH27_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH27_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH27_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH27_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH27_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH27_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH27_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH27_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH27_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH27_CSR_EEI_MASK)

#define spp_dma5_TCD_CH27_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH27_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH27_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH27_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_CX_SHIFT)) & spp_dma5_TCD_CH27_CSR_CX_MASK)

#define spp_dma5_TCD_CH27_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH27_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH27_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH27_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH27_CSR_ECX_MASK)

#define spp_dma5_TCD_CH27_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH27_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH27_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH27_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH27_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH27_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH27_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH27_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH27_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH27_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH27_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH27_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH27_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH27_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH27_CSR_DONE_MASK)

#define spp_dma5_TCD_CH27_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH27_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH27_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH27_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH27_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH27_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH27_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH27_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH27_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_DBE_SHIFT)) & spp_dma5_TCD_CH27_ES_DBE_MASK)

#define spp_dma5_TCD_CH27_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH27_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH27_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_SBE_SHIFT)) & spp_dma5_TCD_CH27_ES_SBE_MASK)

#define spp_dma5_TCD_CH27_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH27_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH27_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_SGE_SHIFT)) & spp_dma5_TCD_CH27_ES_SGE_MASK)

#define spp_dma5_TCD_CH27_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH27_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH27_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_NCE_SHIFT)) & spp_dma5_TCD_CH27_ES_NCE_MASK)

#define spp_dma5_TCD_CH27_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH27_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH27_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_DOE_SHIFT)) & spp_dma5_TCD_CH27_ES_DOE_MASK)

#define spp_dma5_TCD_CH27_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH27_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH27_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_DAE_SHIFT)) & spp_dma5_TCD_CH27_ES_DAE_MASK)

#define spp_dma5_TCD_CH27_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH27_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH27_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_SOE_SHIFT)) & spp_dma5_TCD_CH27_ES_SOE_MASK)

#define spp_dma5_TCD_CH27_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH27_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH27_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_SAE_SHIFT)) & spp_dma5_TCD_CH27_ES_SAE_MASK)

#define spp_dma5_TCD_CH27_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH27_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH27_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_ECX_SHIFT)) & spp_dma5_TCD_CH27_ES_ECX_MASK)

#define spp_dma5_TCD_CH27_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH27_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH27_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_UCE_SHIFT)) & spp_dma5_TCD_CH27_ES_UCE_MASK)

#define spp_dma5_TCD_CH27_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH27_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH27_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH27_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_ES_ERR_SHIFT)) & spp_dma5_TCD_CH27_ES_ERR_MASK)
/*! @} */

/*! @name CH27_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH27_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH27_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH27_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH27_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_INT_INT_SHIFT)) & spp_dma5_TCD_CH27_INT_INT_MASK)
/*! @} */

/*! @name CH27_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH27_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH27_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH27_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH27_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_SBR_MID_SHIFT)) & spp_dma5_TCD_CH27_SBR_MID_MASK)

#define spp_dma5_TCD_CH27_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH27_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH27_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH27_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH27_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH27_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH27_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH27_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH27_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH27_SBR_PAL_MASK)

#define spp_dma5_TCD_CH27_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH27_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH27_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH27_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH27_SBR_EMI_MASK)
/*! @} */

/*! @name CH27_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH27_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH27_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH27_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH27_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_PRI_APL_SHIFT)) & spp_dma5_TCD_CH27_PRI_APL_MASK)

#define spp_dma5_TCD_CH27_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH27_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH27_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH27_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH27_PRI_DPA_MASK)

#define spp_dma5_TCD_CH27_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH27_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH27_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH27_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH27_PRI_ECP_MASK)
/*! @} */

/*! @name CH27_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH27_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH27_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH27_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH27_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH27_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH27_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH27_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH27_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH27_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH27_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH27_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD27_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD27_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD27_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD27_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD27_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD27_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD27_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD27_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD27_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD27_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD27_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD27_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD27_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD27_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD27_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD27_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD27_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD27_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD27_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD27_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD27_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD27_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD27_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD27_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD27_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD27_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD27_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD27_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD27_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD27_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD27_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD27_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD27_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD27_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD27_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD27_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD27_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD27_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD27_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD27_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD27_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD27_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD27_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD27_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD27_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD27_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD27_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD27_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD27_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD27_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD27_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD27_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD27_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD27_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD27_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD27_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD27_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD27_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD27_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD27_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD27_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD27_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD27_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD27_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD27_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD27_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD27_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD27_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD27_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD27_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD27_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD27_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD27_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD27_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD27_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD27_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD27_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD27_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD27_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD27_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD27_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD27_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD27_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD27_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD27_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD27_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD27_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD27_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD27_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD27_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD27_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD27_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD27_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD27_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD27_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_START_SHIFT)) & spp_dma5_TCD_TCD27_CSR_START_MASK)

#define spp_dma5_TCD_TCD27_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD27_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD27_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD27_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD27_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD27_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD27_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD27_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD27_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD27_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD27_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD27_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD27_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD27_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD27_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD27_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD27_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD27_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD27_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD27_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD27_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD27_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD27_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD27_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD27_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD27_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD27_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD27_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD27_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD27_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD27_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD27_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD27_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD27_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD27_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD27_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD27_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD27_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD27_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD27_CSR_TMC_MASK)
/*! @} */

/*! @name TCD27_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD27_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD27_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD27_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD27_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD27_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD27_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD27_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD27_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD27_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD27_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD27_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD27_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD27_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD27_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD27_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD27_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD27_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD27_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD27_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH28_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH28_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH28_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH28_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH28_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH28_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH28_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH28_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH28_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH28_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH28_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH28_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH28_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH28_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH28_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH28_CSR_EEI_MASK)

#define spp_dma5_TCD_CH28_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH28_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH28_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH28_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_CX_SHIFT)) & spp_dma5_TCD_CH28_CSR_CX_MASK)

#define spp_dma5_TCD_CH28_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH28_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH28_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH28_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH28_CSR_ECX_MASK)

#define spp_dma5_TCD_CH28_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH28_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH28_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH28_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH28_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH28_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH28_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH28_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH28_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH28_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH28_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH28_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH28_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH28_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH28_CSR_DONE_MASK)

#define spp_dma5_TCD_CH28_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH28_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH28_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH28_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH28_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH28_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH28_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH28_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH28_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_DBE_SHIFT)) & spp_dma5_TCD_CH28_ES_DBE_MASK)

#define spp_dma5_TCD_CH28_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH28_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH28_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_SBE_SHIFT)) & spp_dma5_TCD_CH28_ES_SBE_MASK)

#define spp_dma5_TCD_CH28_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH28_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH28_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_SGE_SHIFT)) & spp_dma5_TCD_CH28_ES_SGE_MASK)

#define spp_dma5_TCD_CH28_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH28_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH28_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_NCE_SHIFT)) & spp_dma5_TCD_CH28_ES_NCE_MASK)

#define spp_dma5_TCD_CH28_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH28_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH28_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_DOE_SHIFT)) & spp_dma5_TCD_CH28_ES_DOE_MASK)

#define spp_dma5_TCD_CH28_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH28_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH28_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_DAE_SHIFT)) & spp_dma5_TCD_CH28_ES_DAE_MASK)

#define spp_dma5_TCD_CH28_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH28_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH28_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_SOE_SHIFT)) & spp_dma5_TCD_CH28_ES_SOE_MASK)

#define spp_dma5_TCD_CH28_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH28_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH28_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_SAE_SHIFT)) & spp_dma5_TCD_CH28_ES_SAE_MASK)

#define spp_dma5_TCD_CH28_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH28_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH28_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_ECX_SHIFT)) & spp_dma5_TCD_CH28_ES_ECX_MASK)

#define spp_dma5_TCD_CH28_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH28_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH28_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_UCE_SHIFT)) & spp_dma5_TCD_CH28_ES_UCE_MASK)

#define spp_dma5_TCD_CH28_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH28_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH28_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH28_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_ES_ERR_SHIFT)) & spp_dma5_TCD_CH28_ES_ERR_MASK)
/*! @} */

/*! @name CH28_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH28_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH28_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH28_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH28_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_INT_INT_SHIFT)) & spp_dma5_TCD_CH28_INT_INT_MASK)
/*! @} */

/*! @name CH28_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH28_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH28_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH28_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH28_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_SBR_MID_SHIFT)) & spp_dma5_TCD_CH28_SBR_MID_MASK)

#define spp_dma5_TCD_CH28_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH28_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH28_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH28_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH28_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH28_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH28_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH28_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH28_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH28_SBR_PAL_MASK)

#define spp_dma5_TCD_CH28_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH28_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH28_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH28_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH28_SBR_EMI_MASK)
/*! @} */

/*! @name CH28_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH28_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH28_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH28_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH28_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_PRI_APL_SHIFT)) & spp_dma5_TCD_CH28_PRI_APL_MASK)

#define spp_dma5_TCD_CH28_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH28_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH28_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH28_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH28_PRI_DPA_MASK)

#define spp_dma5_TCD_CH28_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH28_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH28_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH28_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH28_PRI_ECP_MASK)
/*! @} */

/*! @name CH28_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH28_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH28_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH28_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH28_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH28_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH28_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH28_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH28_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH28_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH28_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH28_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD28_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD28_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD28_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD28_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD28_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD28_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD28_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD28_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD28_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD28_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD28_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD28_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD28_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD28_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD28_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD28_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD28_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD28_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD28_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD28_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD28_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD28_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD28_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD28_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD28_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD28_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD28_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD28_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD28_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD28_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD28_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD28_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD28_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD28_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD28_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD28_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD28_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD28_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD28_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD28_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD28_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD28_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD28_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD28_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD28_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD28_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD28_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD28_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD28_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD28_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD28_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD28_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD28_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD28_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD28_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD28_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD28_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD28_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD28_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD28_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD28_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD28_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD28_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD28_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD28_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD28_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD28_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD28_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD28_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD28_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD28_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD28_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD28_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD28_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD28_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD28_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD28_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD28_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD28_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD28_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD28_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD28_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD28_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD28_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD28_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD28_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD28_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD28_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD28_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD28_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD28_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD28_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD28_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD28_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD28_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_START_SHIFT)) & spp_dma5_TCD_TCD28_CSR_START_MASK)

#define spp_dma5_TCD_TCD28_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD28_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD28_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD28_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD28_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD28_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD28_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD28_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD28_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD28_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD28_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD28_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD28_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD28_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD28_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD28_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD28_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD28_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD28_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD28_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD28_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD28_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD28_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD28_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD28_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD28_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD28_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD28_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD28_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD28_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD28_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD28_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD28_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD28_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD28_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD28_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD28_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD28_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD28_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD28_CSR_TMC_MASK)
/*! @} */

/*! @name TCD28_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD28_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD28_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD28_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD28_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD28_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD28_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD28_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD28_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD28_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD28_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD28_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD28_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD28_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD28_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD28_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD28_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD28_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD28_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD28_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH29_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH29_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH29_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH29_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH29_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH29_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH29_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH29_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH29_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH29_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH29_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH29_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH29_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH29_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH29_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH29_CSR_EEI_MASK)

#define spp_dma5_TCD_CH29_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH29_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH29_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH29_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_CX_SHIFT)) & spp_dma5_TCD_CH29_CSR_CX_MASK)

#define spp_dma5_TCD_CH29_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH29_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH29_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH29_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH29_CSR_ECX_MASK)

#define spp_dma5_TCD_CH29_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH29_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH29_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH29_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH29_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH29_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH29_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH29_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH29_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH29_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH29_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH29_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH29_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH29_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH29_CSR_DONE_MASK)

#define spp_dma5_TCD_CH29_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH29_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH29_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH29_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH29_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH29_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH29_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH29_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH29_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_DBE_SHIFT)) & spp_dma5_TCD_CH29_ES_DBE_MASK)

#define spp_dma5_TCD_CH29_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH29_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH29_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_SBE_SHIFT)) & spp_dma5_TCD_CH29_ES_SBE_MASK)

#define spp_dma5_TCD_CH29_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH29_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH29_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_SGE_SHIFT)) & spp_dma5_TCD_CH29_ES_SGE_MASK)

#define spp_dma5_TCD_CH29_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH29_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH29_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_NCE_SHIFT)) & spp_dma5_TCD_CH29_ES_NCE_MASK)

#define spp_dma5_TCD_CH29_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH29_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH29_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_DOE_SHIFT)) & spp_dma5_TCD_CH29_ES_DOE_MASK)

#define spp_dma5_TCD_CH29_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH29_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH29_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_DAE_SHIFT)) & spp_dma5_TCD_CH29_ES_DAE_MASK)

#define spp_dma5_TCD_CH29_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH29_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH29_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_SOE_SHIFT)) & spp_dma5_TCD_CH29_ES_SOE_MASK)

#define spp_dma5_TCD_CH29_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH29_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH29_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_SAE_SHIFT)) & spp_dma5_TCD_CH29_ES_SAE_MASK)

#define spp_dma5_TCD_CH29_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH29_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH29_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_ECX_SHIFT)) & spp_dma5_TCD_CH29_ES_ECX_MASK)

#define spp_dma5_TCD_CH29_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH29_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH29_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_UCE_SHIFT)) & spp_dma5_TCD_CH29_ES_UCE_MASK)

#define spp_dma5_TCD_CH29_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH29_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH29_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH29_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_ES_ERR_SHIFT)) & spp_dma5_TCD_CH29_ES_ERR_MASK)
/*! @} */

/*! @name CH29_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH29_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH29_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH29_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH29_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_INT_INT_SHIFT)) & spp_dma5_TCD_CH29_INT_INT_MASK)
/*! @} */

/*! @name CH29_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH29_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH29_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH29_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH29_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_SBR_MID_SHIFT)) & spp_dma5_TCD_CH29_SBR_MID_MASK)

#define spp_dma5_TCD_CH29_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH29_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH29_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH29_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH29_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH29_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH29_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH29_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH29_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH29_SBR_PAL_MASK)

#define spp_dma5_TCD_CH29_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH29_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH29_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH29_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH29_SBR_EMI_MASK)
/*! @} */

/*! @name CH29_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH29_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH29_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH29_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH29_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_PRI_APL_SHIFT)) & spp_dma5_TCD_CH29_PRI_APL_MASK)

#define spp_dma5_TCD_CH29_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH29_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH29_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH29_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH29_PRI_DPA_MASK)

#define spp_dma5_TCD_CH29_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH29_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH29_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH29_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH29_PRI_ECP_MASK)
/*! @} */

/*! @name CH29_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH29_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH29_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH29_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH29_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH29_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH29_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH29_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH29_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH29_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH29_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH29_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD29_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD29_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD29_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD29_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD29_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD29_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD29_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD29_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD29_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD29_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD29_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD29_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD29_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD29_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD29_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD29_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD29_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD29_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD29_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD29_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD29_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD29_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD29_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD29_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD29_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD29_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD29_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD29_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD29_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD29_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD29_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD29_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD29_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD29_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD29_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD29_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD29_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD29_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD29_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD29_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD29_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD29_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD29_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD29_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD29_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD29_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD29_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD29_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD29_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD29_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD29_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD29_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD29_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD29_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD29_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD29_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD29_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD29_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD29_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD29_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD29_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD29_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD29_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD29_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD29_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD29_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD29_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD29_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD29_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD29_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD29_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD29_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD29_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD29_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD29_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD29_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD29_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD29_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD29_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD29_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD29_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD29_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD29_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD29_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD29_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD29_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD29_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD29_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD29_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD29_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD29_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD29_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD29_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD29_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD29_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_START_SHIFT)) & spp_dma5_TCD_TCD29_CSR_START_MASK)

#define spp_dma5_TCD_TCD29_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD29_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD29_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD29_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD29_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD29_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD29_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD29_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD29_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD29_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD29_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD29_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD29_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD29_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD29_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD29_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD29_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD29_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD29_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD29_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD29_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD29_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD29_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD29_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD29_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD29_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD29_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD29_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD29_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD29_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD29_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD29_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD29_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD29_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD29_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD29_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD29_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD29_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD29_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD29_CSR_TMC_MASK)
/*! @} */

/*! @name TCD29_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD29_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD29_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD29_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD29_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD29_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD29_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD29_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD29_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD29_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD29_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD29_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD29_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD29_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD29_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD29_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD29_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD29_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD29_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD29_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH30_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH30_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH30_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH30_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH30_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH30_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH30_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH30_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH30_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH30_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH30_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH30_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH30_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH30_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH30_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH30_CSR_EEI_MASK)

#define spp_dma5_TCD_CH30_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH30_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH30_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH30_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_CX_SHIFT)) & spp_dma5_TCD_CH30_CSR_CX_MASK)

#define spp_dma5_TCD_CH30_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH30_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH30_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH30_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH30_CSR_ECX_MASK)

#define spp_dma5_TCD_CH30_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH30_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH30_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH30_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH30_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH30_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH30_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH30_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH30_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH30_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH30_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH30_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH30_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH30_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH30_CSR_DONE_MASK)

#define spp_dma5_TCD_CH30_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH30_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH30_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH30_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH30_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH30_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH30_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH30_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH30_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_DBE_SHIFT)) & spp_dma5_TCD_CH30_ES_DBE_MASK)

#define spp_dma5_TCD_CH30_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH30_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH30_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_SBE_SHIFT)) & spp_dma5_TCD_CH30_ES_SBE_MASK)

#define spp_dma5_TCD_CH30_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH30_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH30_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_SGE_SHIFT)) & spp_dma5_TCD_CH30_ES_SGE_MASK)

#define spp_dma5_TCD_CH30_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH30_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH30_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_NCE_SHIFT)) & spp_dma5_TCD_CH30_ES_NCE_MASK)

#define spp_dma5_TCD_CH30_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH30_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH30_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_DOE_SHIFT)) & spp_dma5_TCD_CH30_ES_DOE_MASK)

#define spp_dma5_TCD_CH30_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH30_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH30_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_DAE_SHIFT)) & spp_dma5_TCD_CH30_ES_DAE_MASK)

#define spp_dma5_TCD_CH30_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH30_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH30_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_SOE_SHIFT)) & spp_dma5_TCD_CH30_ES_SOE_MASK)

#define spp_dma5_TCD_CH30_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH30_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH30_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_SAE_SHIFT)) & spp_dma5_TCD_CH30_ES_SAE_MASK)

#define spp_dma5_TCD_CH30_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH30_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH30_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_ECX_SHIFT)) & spp_dma5_TCD_CH30_ES_ECX_MASK)

#define spp_dma5_TCD_CH30_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH30_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH30_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_UCE_SHIFT)) & spp_dma5_TCD_CH30_ES_UCE_MASK)

#define spp_dma5_TCD_CH30_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH30_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH30_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH30_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_ES_ERR_SHIFT)) & spp_dma5_TCD_CH30_ES_ERR_MASK)
/*! @} */

/*! @name CH30_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH30_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH30_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH30_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH30_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_INT_INT_SHIFT)) & spp_dma5_TCD_CH30_INT_INT_MASK)
/*! @} */

/*! @name CH30_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH30_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH30_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH30_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH30_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_SBR_MID_SHIFT)) & spp_dma5_TCD_CH30_SBR_MID_MASK)

#define spp_dma5_TCD_CH30_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH30_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH30_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH30_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH30_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH30_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH30_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH30_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH30_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH30_SBR_PAL_MASK)

#define spp_dma5_TCD_CH30_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH30_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH30_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH30_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH30_SBR_EMI_MASK)
/*! @} */

/*! @name CH30_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH30_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH30_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH30_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH30_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_PRI_APL_SHIFT)) & spp_dma5_TCD_CH30_PRI_APL_MASK)

#define spp_dma5_TCD_CH30_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH30_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH30_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH30_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH30_PRI_DPA_MASK)

#define spp_dma5_TCD_CH30_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH30_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH30_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH30_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH30_PRI_ECP_MASK)
/*! @} */

/*! @name CH30_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH30_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH30_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH30_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH30_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH30_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH30_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH30_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH30_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH30_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH30_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH30_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD30_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD30_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD30_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD30_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD30_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD30_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD30_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD30_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD30_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD30_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD30_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD30_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD30_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD30_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD30_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD30_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD30_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD30_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD30_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD30_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD30_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD30_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD30_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD30_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD30_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD30_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD30_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD30_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD30_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD30_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD30_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD30_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD30_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD30_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD30_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD30_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD30_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD30_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD30_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD30_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD30_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD30_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD30_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD30_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD30_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD30_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD30_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD30_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD30_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD30_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD30_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD30_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD30_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD30_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD30_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD30_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD30_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD30_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD30_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD30_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD30_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD30_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD30_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD30_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD30_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD30_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD30_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD30_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD30_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD30_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD30_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD30_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD30_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD30_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD30_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD30_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD30_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD30_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD30_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD30_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD30_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD30_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD30_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD30_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD30_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD30_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD30_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD30_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD30_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD30_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD30_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD30_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD30_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD30_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD30_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_START_SHIFT)) & spp_dma5_TCD_TCD30_CSR_START_MASK)

#define spp_dma5_TCD_TCD30_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD30_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD30_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD30_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD30_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD30_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD30_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD30_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD30_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD30_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD30_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD30_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD30_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD30_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD30_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD30_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD30_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD30_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD30_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD30_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD30_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD30_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD30_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD30_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD30_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD30_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD30_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD30_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD30_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD30_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD30_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD30_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD30_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD30_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD30_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD30_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD30_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD30_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD30_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD30_CSR_TMC_MASK)
/*! @} */

/*! @name TCD30_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD30_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD30_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD30_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD30_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD30_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD30_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD30_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD30_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD30_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD30_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD30_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD30_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD30_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD30_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD30_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD30_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD30_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD30_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD30_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH31_CSR - Channel Control and Status */
/*! @{ */

#define spp_dma5_TCD_CH31_CSR_ERQ_MASK           (0x1U)
#define spp_dma5_TCD_CH31_CSR_ERQ_SHIFT          (0U)
#define spp_dma5_TCD_CH31_CSR_ERQ_WIDTH          (1U)
#define spp_dma5_TCD_CH31_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_ERQ_SHIFT)) & spp_dma5_TCD_CH31_CSR_ERQ_MASK)

#define spp_dma5_TCD_CH31_CSR_EARQ_MASK          (0x2U)
#define spp_dma5_TCD_CH31_CSR_EARQ_SHIFT         (1U)
#define spp_dma5_TCD_CH31_CSR_EARQ_WIDTH         (1U)
#define spp_dma5_TCD_CH31_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_EARQ_SHIFT)) & spp_dma5_TCD_CH31_CSR_EARQ_MASK)

#define spp_dma5_TCD_CH31_CSR_EEI_MASK           (0x4U)
#define spp_dma5_TCD_CH31_CSR_EEI_SHIFT          (2U)
#define spp_dma5_TCD_CH31_CSR_EEI_WIDTH          (1U)
#define spp_dma5_TCD_CH31_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_EEI_SHIFT)) & spp_dma5_TCD_CH31_CSR_EEI_MASK)

#define spp_dma5_TCD_CH31_CSR_CX_MASK            (0x40U)
#define spp_dma5_TCD_CH31_CSR_CX_SHIFT           (6U)
#define spp_dma5_TCD_CH31_CSR_CX_WIDTH           (1U)
#define spp_dma5_TCD_CH31_CSR_CX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_CX_SHIFT)) & spp_dma5_TCD_CH31_CSR_CX_MASK)

#define spp_dma5_TCD_CH31_CSR_ECX_MASK           (0x80U)
#define spp_dma5_TCD_CH31_CSR_ECX_SHIFT          (7U)
#define spp_dma5_TCD_CH31_CSR_ECX_WIDTH          (1U)
#define spp_dma5_TCD_CH31_CSR_ECX(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_ECX_SHIFT)) & spp_dma5_TCD_CH31_CSR_ECX_MASK)

#define spp_dma5_TCD_CH31_CSR_SWAP_MASK          (0xF000U)
#define spp_dma5_TCD_CH31_CSR_SWAP_SHIFT         (12U)
#define spp_dma5_TCD_CH31_CSR_SWAP_WIDTH         (4U)
#define spp_dma5_TCD_CH31_CSR_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_SWAP_SHIFT)) & spp_dma5_TCD_CH31_CSR_SWAP_MASK)

#define spp_dma5_TCD_CH31_CSR_SIGNEXT_MASK       (0x3F0000U)
#define spp_dma5_TCD_CH31_CSR_SIGNEXT_SHIFT      (16U)
#define spp_dma5_TCD_CH31_CSR_SIGNEXT_WIDTH      (6U)
#define spp_dma5_TCD_CH31_CSR_SIGNEXT(x)         (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_SIGNEXT_SHIFT)) & spp_dma5_TCD_CH31_CSR_SIGNEXT_MASK)

#define spp_dma5_TCD_CH31_CSR_DONE_MASK          (0x40000000U)
#define spp_dma5_TCD_CH31_CSR_DONE_SHIFT         (30U)
#define spp_dma5_TCD_CH31_CSR_DONE_WIDTH         (1U)
#define spp_dma5_TCD_CH31_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_DONE_SHIFT)) & spp_dma5_TCD_CH31_CSR_DONE_MASK)

#define spp_dma5_TCD_CH31_CSR_ACTIVE_MASK        (0x80000000U)
#define spp_dma5_TCD_CH31_CSR_ACTIVE_SHIFT       (31U)
#define spp_dma5_TCD_CH31_CSR_ACTIVE_WIDTH       (1U)
#define spp_dma5_TCD_CH31_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_CSR_ACTIVE_SHIFT)) & spp_dma5_TCD_CH31_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH31_ES - Channel Error Status */
/*! @{ */

#define spp_dma5_TCD_CH31_ES_DBE_MASK            (0x1U)
#define spp_dma5_TCD_CH31_ES_DBE_SHIFT           (0U)
#define spp_dma5_TCD_CH31_ES_DBE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_DBE_SHIFT)) & spp_dma5_TCD_CH31_ES_DBE_MASK)

#define spp_dma5_TCD_CH31_ES_SBE_MASK            (0x2U)
#define spp_dma5_TCD_CH31_ES_SBE_SHIFT           (1U)
#define spp_dma5_TCD_CH31_ES_SBE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_SBE_SHIFT)) & spp_dma5_TCD_CH31_ES_SBE_MASK)

#define spp_dma5_TCD_CH31_ES_SGE_MASK            (0x4U)
#define spp_dma5_TCD_CH31_ES_SGE_SHIFT           (2U)
#define spp_dma5_TCD_CH31_ES_SGE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_SGE_SHIFT)) & spp_dma5_TCD_CH31_ES_SGE_MASK)

#define spp_dma5_TCD_CH31_ES_NCE_MASK            (0x8U)
#define spp_dma5_TCD_CH31_ES_NCE_SHIFT           (3U)
#define spp_dma5_TCD_CH31_ES_NCE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_NCE_SHIFT)) & spp_dma5_TCD_CH31_ES_NCE_MASK)

#define spp_dma5_TCD_CH31_ES_DOE_MASK            (0x10U)
#define spp_dma5_TCD_CH31_ES_DOE_SHIFT           (4U)
#define spp_dma5_TCD_CH31_ES_DOE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_DOE_SHIFT)) & spp_dma5_TCD_CH31_ES_DOE_MASK)

#define spp_dma5_TCD_CH31_ES_DAE_MASK            (0x20U)
#define spp_dma5_TCD_CH31_ES_DAE_SHIFT           (5U)
#define spp_dma5_TCD_CH31_ES_DAE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_DAE_SHIFT)) & spp_dma5_TCD_CH31_ES_DAE_MASK)

#define spp_dma5_TCD_CH31_ES_SOE_MASK            (0x40U)
#define spp_dma5_TCD_CH31_ES_SOE_SHIFT           (6U)
#define spp_dma5_TCD_CH31_ES_SOE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_SOE_SHIFT)) & spp_dma5_TCD_CH31_ES_SOE_MASK)

#define spp_dma5_TCD_CH31_ES_SAE_MASK            (0x80U)
#define spp_dma5_TCD_CH31_ES_SAE_SHIFT           (7U)
#define spp_dma5_TCD_CH31_ES_SAE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_SAE_SHIFT)) & spp_dma5_TCD_CH31_ES_SAE_MASK)

#define spp_dma5_TCD_CH31_ES_ECX_MASK            (0x100U)
#define spp_dma5_TCD_CH31_ES_ECX_SHIFT           (8U)
#define spp_dma5_TCD_CH31_ES_ECX_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_ECX(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_ECX_SHIFT)) & spp_dma5_TCD_CH31_ES_ECX_MASK)

#define spp_dma5_TCD_CH31_ES_UCE_MASK            (0x200U)
#define spp_dma5_TCD_CH31_ES_UCE_SHIFT           (9U)
#define spp_dma5_TCD_CH31_ES_UCE_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_UCE(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_UCE_SHIFT)) & spp_dma5_TCD_CH31_ES_UCE_MASK)

#define spp_dma5_TCD_CH31_ES_ERR_MASK            (0x80000000U)
#define spp_dma5_TCD_CH31_ES_ERR_SHIFT           (31U)
#define spp_dma5_TCD_CH31_ES_ERR_WIDTH           (1U)
#define spp_dma5_TCD_CH31_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_ES_ERR_SHIFT)) & spp_dma5_TCD_CH31_ES_ERR_MASK)
/*! @} */

/*! @name CH31_INT - Channel Interrupt Status */
/*! @{ */

#define spp_dma5_TCD_CH31_INT_INT_MASK           (0x1U)
#define spp_dma5_TCD_CH31_INT_INT_SHIFT          (0U)
#define spp_dma5_TCD_CH31_INT_INT_WIDTH          (1U)
#define spp_dma5_TCD_CH31_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_INT_INT_SHIFT)) & spp_dma5_TCD_CH31_INT_INT_MASK)
/*! @} */

/*! @name CH31_SBR - Channel System Bus */
/*! @{ */

#define spp_dma5_TCD_CH31_SBR_MID_MASK           (0x3FU)
#define spp_dma5_TCD_CH31_SBR_MID_SHIFT          (0U)
#define spp_dma5_TCD_CH31_SBR_MID_WIDTH          (6U)
#define spp_dma5_TCD_CH31_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_SBR_MID_SHIFT)) & spp_dma5_TCD_CH31_SBR_MID_MASK)

#define spp_dma5_TCD_CH31_SBR_INSTR_MASK         (0x2000U)
#define spp_dma5_TCD_CH31_SBR_INSTR_SHIFT        (13U)
#define spp_dma5_TCD_CH31_SBR_INSTR_WIDTH        (1U)
#define spp_dma5_TCD_CH31_SBR_INSTR(x)           (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_SBR_INSTR_SHIFT)) & spp_dma5_TCD_CH31_SBR_INSTR_MASK)

#define spp_dma5_TCD_CH31_SBR_PAL_MASK           (0x8000U)
#define spp_dma5_TCD_CH31_SBR_PAL_SHIFT          (15U)
#define spp_dma5_TCD_CH31_SBR_PAL_WIDTH          (1U)
#define spp_dma5_TCD_CH31_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_SBR_PAL_SHIFT)) & spp_dma5_TCD_CH31_SBR_PAL_MASK)

#define spp_dma5_TCD_CH31_SBR_EMI_MASK           (0x10000U)
#define spp_dma5_TCD_CH31_SBR_EMI_SHIFT          (16U)
#define spp_dma5_TCD_CH31_SBR_EMI_WIDTH          (1U)
#define spp_dma5_TCD_CH31_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_SBR_EMI_SHIFT)) & spp_dma5_TCD_CH31_SBR_EMI_MASK)
/*! @} */

/*! @name CH31_PRI - Channel Priority */
/*! @{ */

#define spp_dma5_TCD_CH31_PRI_APL_MASK           (0x7U)
#define spp_dma5_TCD_CH31_PRI_APL_SHIFT          (0U)
#define spp_dma5_TCD_CH31_PRI_APL_WIDTH          (3U)
#define spp_dma5_TCD_CH31_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_PRI_APL_SHIFT)) & spp_dma5_TCD_CH31_PRI_APL_MASK)

#define spp_dma5_TCD_CH31_PRI_DPA_MASK           (0x40000000U)
#define spp_dma5_TCD_CH31_PRI_DPA_SHIFT          (30U)
#define spp_dma5_TCD_CH31_PRI_DPA_WIDTH          (1U)
#define spp_dma5_TCD_CH31_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_PRI_DPA_SHIFT)) & spp_dma5_TCD_CH31_PRI_DPA_MASK)

#define spp_dma5_TCD_CH31_PRI_ECP_MASK           (0x80000000U)
#define spp_dma5_TCD_CH31_PRI_ECP_SHIFT          (31U)
#define spp_dma5_TCD_CH31_PRI_ECP_WIDTH          (1U)
#define spp_dma5_TCD_CH31_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_PRI_ECP_SHIFT)) & spp_dma5_TCD_CH31_PRI_ECP_MASK)
/*! @} */

/*! @name CH31_MATTR - Memory Attributes */
/*! @{ */

#define spp_dma5_TCD_CH31_MATTR_RCACHE_MASK      (0xFU)
#define spp_dma5_TCD_CH31_MATTR_RCACHE_SHIFT     (0U)
#define spp_dma5_TCD_CH31_MATTR_RCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH31_MATTR_RCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_MATTR_RCACHE_SHIFT)) & spp_dma5_TCD_CH31_MATTR_RCACHE_MASK)

#define spp_dma5_TCD_CH31_MATTR_WCACHE_MASK      (0xF0U)
#define spp_dma5_TCD_CH31_MATTR_WCACHE_SHIFT     (4U)
#define spp_dma5_TCD_CH31_MATTR_WCACHE_WIDTH     (4U)
#define spp_dma5_TCD_CH31_MATTR_WCACHE(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_CH31_MATTR_WCACHE_SHIFT)) & spp_dma5_TCD_CH31_MATTR_WCACHE_MASK)
/*! @} */

/*! @name TCD31_SADDR - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_SADDR_SADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD31_SADDR_SADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD31_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_SADDR_SADDR_SHIFT)) & spp_dma5_TCD_TCD31_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD31_SADDR_HIGH - TCD Source Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_SADDR_HIGH_SADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_SADDR_HIGH_SADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD31_SADDR_HIGH_SADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD31_SADDR_HIGH_SADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_SADDR_HIGH_SADDR_SHIFT)) & spp_dma5_TCD_TCD31_SADDR_HIGH_SADDR_MASK)
/*! @} */

/*! @name TCD31_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD31_SOFF_SOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD31_SOFF_SOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD31_SOFF_SOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD31_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_SOFF_SOFF_SHIFT)) & spp_dma5_TCD_TCD31_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD31_ATTR - TCD Transfer Attributes */
/*! @{ */

#define spp_dma5_TCD_TCD31_ATTR_DSIZE_MASK       (0x7U)
#define spp_dma5_TCD_TCD31_ATTR_DSIZE_SHIFT      (0U)
#define spp_dma5_TCD_TCD31_ATTR_DSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD31_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_ATTR_DSIZE_SHIFT)) & spp_dma5_TCD_TCD31_ATTR_DSIZE_MASK)

#define spp_dma5_TCD_TCD31_ATTR_DMOD_MASK        (0xF8U)
#define spp_dma5_TCD_TCD31_ATTR_DMOD_SHIFT       (3U)
#define spp_dma5_TCD_TCD31_ATTR_DMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD31_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_ATTR_DMOD_SHIFT)) & spp_dma5_TCD_TCD31_ATTR_DMOD_MASK)

#define spp_dma5_TCD_TCD31_ATTR_SSIZE_MASK       (0x700U)
#define spp_dma5_TCD_TCD31_ATTR_SSIZE_SHIFT      (8U)
#define spp_dma5_TCD_TCD31_ATTR_SSIZE_WIDTH      (3U)
#define spp_dma5_TCD_TCD31_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_ATTR_SSIZE_SHIFT)) & spp_dma5_TCD_TCD31_ATTR_SSIZE_MASK)

#define spp_dma5_TCD_TCD31_ATTR_SMOD_MASK        (0xF800U)
#define spp_dma5_TCD_TCD31_ATTR_SMOD_SHIFT       (11U)
#define spp_dma5_TCD_TCD31_ATTR_SMOD_WIDTH       (5U)
#define spp_dma5_TCD_TCD31_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_ATTR_SMOD_SHIFT)) & spp_dma5_TCD_TCD31_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD31_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_NBYTES_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_NBYTES_MASK)

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_DMLOE_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_DMLOE_MASK)

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_SMLOE_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD31_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_NBYTES_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_NBYTES_MASK)

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_MLOFF_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_MLOFF_MASK)

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_DMLOE_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_DMLOE_MASK)

#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_SMLOE_SHIFT)) & spp_dma5_TCD_TCD31_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD31_SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD31_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD31_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_SLAST_SDA_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD31_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD31_SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_SLAST_SDA_HIGH_SLAST_SDA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_SLAST_SDA_HIGH_SLAST_SDA_SHIFT (0U)
#define spp_dma5_TCD_TCD31_SLAST_SDA_HIGH_SLAST_SDA_WIDTH (32U)
#define spp_dma5_TCD_TCD31_SLAST_SDA_HIGH_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & spp_dma5_TCD_TCD31_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD31_DADDR - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_DADDR_DADDR_SHIFT     (0U)
#define spp_dma5_TCD_TCD31_DADDR_DADDR_WIDTH     (32U)
#define spp_dma5_TCD_TCD31_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_DADDR_DADDR_SHIFT)) & spp_dma5_TCD_TCD31_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD31_DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_DADDR_HIGH_DADDR_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_DADDR_HIGH_DADDR_SHIFT (0U)
#define spp_dma5_TCD_TCD31_DADDR_HIGH_DADDR_WIDTH (32U)
#define spp_dma5_TCD_TCD31_DADDR_HIGH_DADDR(x)   (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_DADDR_HIGH_DADDR_SHIFT)) & spp_dma5_TCD_TCD31_DADDR_HIGH_DADDR_MASK)
/*! @} */

/*! @name TCD31_DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD31_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD31_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_DLAST_SGA_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD31_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD31_DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define spp_dma5_TCD_TCD31_DLAST_SGA_HIGH_DLAST_SGA_MASK (0xFFFFFFFFU)
#define spp_dma5_TCD_TCD31_DLAST_SGA_HIGH_DLAST_SGA_SHIFT (0U)
#define spp_dma5_TCD_TCD31_DLAST_SGA_HIGH_DLAST_SGA_WIDTH (32U)
#define spp_dma5_TCD_TCD31_DLAST_SGA_HIGH_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << spp_dma5_TCD_TCD31_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & spp_dma5_TCD_TCD31_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD31_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define spp_dma5_TCD_TCD31_DOFF_DOFF_MASK        (0xFFFFU)
#define spp_dma5_TCD_TCD31_DOFF_DOFF_SHIFT       (0U)
#define spp_dma5_TCD_TCD31_DOFF_DOFF_WIDTH       (16U)
#define spp_dma5_TCD_TCD31_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_DOFF_DOFF_SHIFT)) & spp_dma5_TCD_TCD31_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD31_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD31_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD31_CITER_ELINKNO_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD31_CITER_ELINKNO_CITER_WIDTH (15U)
#define spp_dma5_TCD_TCD31_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CITER_ELINKNO_CITER_SHIFT)) & spp_dma5_TCD_TCD31_CITER_ELINKNO_CITER_MASK)

#define spp_dma5_TCD_TCD31_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD31_CITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD31_CITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD31_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD31_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD31_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD31_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_CITER_SHIFT (0U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_CITER_WIDTH (9U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CITER_ELINKYES_CITER_SHIFT)) & spp_dma5_TCD_TCD31_CITER_ELINKYES_CITER_MASK)

#define spp_dma5_TCD_TCD31_CITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD31_CITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD31_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD31_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD31_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD31_CSR - TCD Control and Status */
/*! @{ */

#define spp_dma5_TCD_TCD31_CSR_START_MASK        (0x1U)
#define spp_dma5_TCD_TCD31_CSR_START_SHIFT       (0U)
#define spp_dma5_TCD_TCD31_CSR_START_WIDTH       (1U)
#define spp_dma5_TCD_TCD31_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_START_SHIFT)) & spp_dma5_TCD_TCD31_CSR_START_MASK)

#define spp_dma5_TCD_TCD31_CSR_INTMAJOR_MASK     (0x2U)
#define spp_dma5_TCD_TCD31_CSR_INTMAJOR_SHIFT    (1U)
#define spp_dma5_TCD_TCD31_CSR_INTMAJOR_WIDTH    (1U)
#define spp_dma5_TCD_TCD31_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_INTMAJOR_SHIFT)) & spp_dma5_TCD_TCD31_CSR_INTMAJOR_MASK)

#define spp_dma5_TCD_TCD31_CSR_INTHALF_MASK      (0x4U)
#define spp_dma5_TCD_TCD31_CSR_INTHALF_SHIFT     (2U)
#define spp_dma5_TCD_TCD31_CSR_INTHALF_WIDTH     (1U)
#define spp_dma5_TCD_TCD31_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_INTHALF_SHIFT)) & spp_dma5_TCD_TCD31_CSR_INTHALF_MASK)

#define spp_dma5_TCD_TCD31_CSR_DREQ_MASK         (0x8U)
#define spp_dma5_TCD_TCD31_CSR_DREQ_SHIFT        (3U)
#define spp_dma5_TCD_TCD31_CSR_DREQ_WIDTH        (1U)
#define spp_dma5_TCD_TCD31_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_DREQ_SHIFT)) & spp_dma5_TCD_TCD31_CSR_DREQ_MASK)

#define spp_dma5_TCD_TCD31_CSR_ESG_MASK          (0x10U)
#define spp_dma5_TCD_TCD31_CSR_ESG_SHIFT         (4U)
#define spp_dma5_TCD_TCD31_CSR_ESG_WIDTH         (1U)
#define spp_dma5_TCD_TCD31_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_ESG_SHIFT)) & spp_dma5_TCD_TCD31_CSR_ESG_MASK)

#define spp_dma5_TCD_TCD31_CSR_MAJORELINK_MASK   (0x20U)
#define spp_dma5_TCD_TCD31_CSR_MAJORELINK_SHIFT  (5U)
#define spp_dma5_TCD_TCD31_CSR_MAJORELINK_WIDTH  (1U)
#define spp_dma5_TCD_TCD31_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_MAJORELINK_SHIFT)) & spp_dma5_TCD_TCD31_CSR_MAJORELINK_MASK)

#define spp_dma5_TCD_TCD31_CSR_ESDA_MASK         (0x80U)
#define spp_dma5_TCD_TCD31_CSR_ESDA_SHIFT        (7U)
#define spp_dma5_TCD_TCD31_CSR_ESDA_WIDTH        (1U)
#define spp_dma5_TCD_TCD31_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_ESDA_SHIFT)) & spp_dma5_TCD_TCD31_CSR_ESDA_MASK)

#define spp_dma5_TCD_TCD31_CSR_MAJORLINKCH_MASK  (0x3F00U)
#define spp_dma5_TCD_TCD31_CSR_MAJORLINKCH_SHIFT (8U)
#define spp_dma5_TCD_TCD31_CSR_MAJORLINKCH_WIDTH (6U)
#define spp_dma5_TCD_TCD31_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_MAJORLINKCH_SHIFT)) & spp_dma5_TCD_TCD31_CSR_MAJORLINKCH_MASK)

#define spp_dma5_TCD_TCD31_CSR_TMC_MASK          (0xC000U)
#define spp_dma5_TCD_TCD31_CSR_TMC_SHIFT         (14U)
#define spp_dma5_TCD_TCD31_CSR_TMC_WIDTH         (2U)
#define spp_dma5_TCD_TCD31_CSR_TMC(x)            (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_CSR_TMC_SHIFT)) & spp_dma5_TCD_TCD31_CSR_TMC_MASK)
/*! @} */

/*! @name TCD31_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define spp_dma5_TCD_TCD31_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define spp_dma5_TCD_TCD31_BITER_ELINKNO_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD31_BITER_ELINKNO_BITER_WIDTH (15U)
#define spp_dma5_TCD_TCD31_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_BITER_ELINKNO_BITER_SHIFT)) & spp_dma5_TCD_TCD31_BITER_ELINKNO_BITER_MASK)

#define spp_dma5_TCD_TCD31_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD31_BITER_ELINKNO_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD31_BITER_ELINKNO_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD31_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_BITER_ELINKNO_ELINK_SHIFT)) & spp_dma5_TCD_TCD31_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD31_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define spp_dma5_TCD_TCD31_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_BITER_SHIFT (0U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_BITER_WIDTH (9U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_BITER_ELINKYES_BITER_SHIFT)) & spp_dma5_TCD_TCD31_BITER_ELINKYES_BITER_MASK)

#define spp_dma5_TCD_TCD31_BITER_ELINKYES_LINKCH_MASK (0x3E00U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_LINKCH_WIDTH (5U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_BITER_ELINKYES_LINKCH_SHIFT)) & spp_dma5_TCD_TCD31_BITER_ELINKYES_LINKCH_MASK)

#define spp_dma5_TCD_TCD31_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_ELINK_SHIFT (15U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_ELINK_WIDTH (1U)
#define spp_dma5_TCD_TCD31_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << spp_dma5_TCD_TCD31_BITER_ELINKYES_ELINK_SHIFT)) & spp_dma5_TCD_TCD31_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group spp_dma5_TCD_Register_Masks */

/*!
 * @}
 */ /* end of group spp_dma5_TCD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_spp_dma5_TCD_H_) */
