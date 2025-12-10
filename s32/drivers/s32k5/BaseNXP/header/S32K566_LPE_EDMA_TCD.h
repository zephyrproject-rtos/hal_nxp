/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LPE_EDMA_TCD.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LPE_EDMA_TCD
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
#if !defined(S32K566_LPE_EDMA_TCD_H_)  /* Check if memory map has not been already included */
#define S32K566_LPE_EDMA_TCD_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPE_EDMA_TCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_EDMA_TCD_Peripheral_Access_Layer LPE_EDMA_TCD Peripheral Access Layer
 * @{
 */

/** LPE_EDMA_TCD - Register Layout Typedef */
typedef struct LPE_EDMA_TCD_Struct {
  __IO uint32_t CH0_CSR;                           /**< Channel Control and Status, offset: 0x0 */
  __IO uint32_t CH0_ES;                            /**< Channel Error Status, offset: 0x4 */
  __IO uint32_t CH0_INT;                           /**< Channel Interrupt Status, offset: 0x8 */
  __IO uint32_t CH0_SBR;                           /**< Channel System Bus, offset: 0xC */
  __IO uint32_t CH0_PRI;                           /**< Channel Priority, offset: 0x10 */
  uint8_t RESERVED_0[12];
  __IO uint32_t TCD0_SADDR;                        /**< TCD Source Address, offset: 0x20 */
  __IO uint16_t TCD0_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x24 */
  __IO uint16_t TCD0_ATTR;                         /**< TCD Transfer Attributes, offset: 0x26 */
  union {                                          /* offset: 0x28 */
    __IO uint32_t TCD0_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x28 */
    __IO uint32_t TCD0_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x28 */
  } NBYTES0;
  __IO uint32_t TCD0_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x2C */
  __IO uint32_t TCD0_DADDR;                        /**< TCD Destination Address, offset: 0x30 */
  __IO uint16_t TCD0_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x34 */
  union {                                          /* offset: 0x36 */
    __IO uint16_t TCD0_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x36 */
    __IO uint16_t TCD0_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x36 */
  } CITER0;
  __IO uint32_t TCD0_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x38 */
  __IO uint16_t TCD0_CSR;                          /**< TCD Control and Status, offset: 0x3C */
  union {                                          /* offset: 0x3E */
    __IO uint16_t TCD0_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3E */
    __IO uint16_t TCD0_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3E */
  } BITER0;
  uint8_t RESERVED_1[8128];
  __IO uint32_t CH1_CSR;                           /**< Channel Control and Status, offset: 0x2000 */
  __IO uint32_t CH1_ES;                            /**< Channel Error Status, offset: 0x2004 */
  __IO uint32_t CH1_INT;                           /**< Channel Interrupt Status, offset: 0x2008 */
  __IO uint32_t CH1_SBR;                           /**< Channel System Bus, offset: 0x200C */
  __IO uint32_t CH1_PRI;                           /**< Channel Priority, offset: 0x2010 */
  uint8_t RESERVED_2[12];
  __IO uint32_t TCD1_SADDR;                        /**< TCD Source Address, offset: 0x2020 */
  __IO uint16_t TCD1_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x2024 */
  __IO uint16_t TCD1_ATTR;                         /**< TCD Transfer Attributes, offset: 0x2026 */
  union {                                          /* offset: 0x2028 */
    __IO uint32_t TCD1_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2028 */
    __IO uint32_t TCD1_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2028 */
  } NBYTES1;
  __IO uint32_t TCD1_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x202C */
  __IO uint32_t TCD1_DADDR;                        /**< TCD Destination Address, offset: 0x2030 */
  __IO uint16_t TCD1_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x2034 */
  union {                                          /* offset: 0x2036 */
    __IO uint16_t TCD1_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2036 */
    __IO uint16_t TCD1_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2036 */
  } CITER1;
  __IO uint32_t TCD1_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x2038 */
  __IO uint16_t TCD1_CSR;                          /**< TCD Control and Status, offset: 0x203C */
  union {                                          /* offset: 0x203E */
    __IO uint16_t TCD1_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x203E */
    __IO uint16_t TCD1_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x203E */
  } BITER1;
  uint8_t RESERVED_3[24512];
  __IO uint32_t CH2_CSR;                           /**< Channel Control and Status, offset: 0x8000 */
  __IO uint32_t CH2_ES;                            /**< Channel Error Status, offset: 0x8004 */
  __IO uint32_t CH2_INT;                           /**< Channel Interrupt Status, offset: 0x8008 */
  __IO uint32_t CH2_SBR;                           /**< Channel System Bus, offset: 0x800C */
  __IO uint32_t CH2_PRI;                           /**< Channel Priority, offset: 0x8010 */
  uint8_t RESERVED_4[12];
  __IO uint32_t TCD2_SADDR;                        /**< TCD Source Address, offset: 0x8020 */
  __IO uint16_t TCD2_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x8024 */
  __IO uint16_t TCD2_ATTR;                         /**< TCD Transfer Attributes, offset: 0x8026 */
  union {                                          /* offset: 0x8028 */
    __IO uint32_t TCD2_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x8028 */
    __IO uint32_t TCD2_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x8028 */
  } NBYTES2;
  __IO uint32_t TCD2_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x802C */
  __IO uint32_t TCD2_DADDR;                        /**< TCD Destination Address, offset: 0x8030 */
  __IO uint16_t TCD2_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x8034 */
  union {                                          /* offset: 0x8036 */
    __IO uint16_t TCD2_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x8036 */
    __IO uint16_t TCD2_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x8036 */
  } CITER2;
  __IO uint32_t TCD2_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x8038 */
  __IO uint16_t TCD2_CSR;                          /**< TCD Control and Status, offset: 0x803C */
  union {                                          /* offset: 0x803E */
    __IO uint16_t TCD2_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x803E */
    __IO uint16_t TCD2_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x803E */
  } BITER2;
  uint8_t RESERVED_5[8128];
  __IO uint32_t CH3_CSR;                           /**< Channel Control and Status, offset: 0xA000 */
  __IO uint32_t CH3_ES;                            /**< Channel Error Status, offset: 0xA004 */
  __IO uint32_t CH3_INT;                           /**< Channel Interrupt Status, offset: 0xA008 */
  __IO uint32_t CH3_SBR;                           /**< Channel System Bus, offset: 0xA00C */
  __IO uint32_t CH3_PRI;                           /**< Channel Priority, offset: 0xA010 */
  uint8_t RESERVED_6[12];
  __IO uint32_t TCD3_SADDR;                        /**< TCD Source Address, offset: 0xA020 */
  __IO uint16_t TCD3_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0xA024 */
  __IO uint16_t TCD3_ATTR;                         /**< TCD Transfer Attributes, offset: 0xA026 */
  union {                                          /* offset: 0xA028 */
    __IO uint32_t TCD3_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0xA028 */
    __IO uint32_t TCD3_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0xA028 */
  } NBYTES3;
  __IO uint32_t TCD3_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0xA02C */
  __IO uint32_t TCD3_DADDR;                        /**< TCD Destination Address, offset: 0xA030 */
  __IO uint16_t TCD3_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0xA034 */
  union {                                          /* offset: 0xA036 */
    __IO uint16_t TCD3_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0xA036 */
    __IO uint16_t TCD3_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0xA036 */
  } CITER3;
  __IO uint32_t TCD3_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0xA038 */
  __IO uint16_t TCD3_CSR;                          /**< TCD Control and Status, offset: 0xA03C */
  union {                                          /* offset: 0xA03E */
    __IO uint16_t TCD3_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0xA03E */
    __IO uint16_t TCD3_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0xA03E */
  } BITER3;
  uint8_t RESERVED_7[24512];
  __IO uint32_t CH4_CSR;                           /**< Channel Control and Status, offset: 0x10000 */
  __IO uint32_t CH4_ES;                            /**< Channel Error Status, offset: 0x10004 */
  __IO uint32_t CH4_INT;                           /**< Channel Interrupt Status, offset: 0x10008 */
  __IO uint32_t CH4_SBR;                           /**< Channel System Bus, offset: 0x1000C */
  __IO uint32_t CH4_PRI;                           /**< Channel Priority, offset: 0x10010 */
  uint8_t RESERVED_8[12];
  __IO uint32_t TCD4_SADDR;                        /**< TCD Source Address, offset: 0x10020 */
  __IO uint16_t TCD4_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x10024 */
  __IO uint16_t TCD4_ATTR;                         /**< TCD Transfer Attributes, offset: 0x10026 */
  union {                                          /* offset: 0x10028 */
    __IO uint32_t TCD4_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x10028 */
    __IO uint32_t TCD4_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x10028 */
  } NBYTES4;
  __IO uint32_t TCD4_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x1002C */
  __IO uint32_t TCD4_DADDR;                        /**< TCD Destination Address, offset: 0x10030 */
  __IO uint16_t TCD4_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x10034 */
  union {                                          /* offset: 0x10036 */
    __IO uint16_t TCD4_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x10036 */
    __IO uint16_t TCD4_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x10036 */
  } CITER4;
  __IO uint32_t TCD4_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x10038 */
  __IO uint16_t TCD4_CSR;                          /**< TCD Control and Status, offset: 0x1003C */
  union {                                          /* offset: 0x1003E */
    __IO uint16_t TCD4_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1003E */
    __IO uint16_t TCD4_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1003E */
  } BITER4;
  uint8_t RESERVED_9[8128];
  __IO uint32_t CH5_CSR;                           /**< Channel Control and Status, offset: 0x12000 */
  __IO uint32_t CH5_ES;                            /**< Channel Error Status, offset: 0x12004 */
  __IO uint32_t CH5_INT;                           /**< Channel Interrupt Status, offset: 0x12008 */
  __IO uint32_t CH5_SBR;                           /**< Channel System Bus, offset: 0x1200C */
  __IO uint32_t CH5_PRI;                           /**< Channel Priority, offset: 0x12010 */
  uint8_t RESERVED_10[12];
  __IO uint32_t TCD5_SADDR;                        /**< TCD Source Address, offset: 0x12020 */
  __IO uint16_t TCD5_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x12024 */
  __IO uint16_t TCD5_ATTR;                         /**< TCD Transfer Attributes, offset: 0x12026 */
  union {                                          /* offset: 0x12028 */
    __IO uint32_t TCD5_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x12028 */
    __IO uint32_t TCD5_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x12028 */
  } NBYTES5;
  __IO uint32_t TCD5_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x1202C */
  __IO uint32_t TCD5_DADDR;                        /**< TCD Destination Address, offset: 0x12030 */
  __IO uint16_t TCD5_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x12034 */
  union {                                          /* offset: 0x12036 */
    __IO uint16_t TCD5_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x12036 */
    __IO uint16_t TCD5_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x12036 */
  } CITER5;
  __IO uint32_t TCD5_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x12038 */
  __IO uint16_t TCD5_CSR;                          /**< TCD Control and Status, offset: 0x1203C */
  union {                                          /* offset: 0x1203E */
    __IO uint16_t TCD5_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1203E */
    __IO uint16_t TCD5_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1203E */
  } BITER5;
  uint8_t RESERVED_11[24512];
  __IO uint32_t CH6_CSR;                           /**< Channel Control and Status, offset: 0x18000 */
  __IO uint32_t CH6_ES;                            /**< Channel Error Status, offset: 0x18004 */
  __IO uint32_t CH6_INT;                           /**< Channel Interrupt Status, offset: 0x18008 */
  __IO uint32_t CH6_SBR;                           /**< Channel System Bus, offset: 0x1800C */
  __IO uint32_t CH6_PRI;                           /**< Channel Priority, offset: 0x18010 */
  uint8_t RESERVED_12[12];
  __IO uint32_t TCD6_SADDR;                        /**< TCD Source Address, offset: 0x18020 */
  __IO uint16_t TCD6_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x18024 */
  __IO uint16_t TCD6_ATTR;                         /**< TCD Transfer Attributes, offset: 0x18026 */
  union {                                          /* offset: 0x18028 */
    __IO uint32_t TCD6_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x18028 */
    __IO uint32_t TCD6_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x18028 */
  } NBYTES6;
  __IO uint32_t TCD6_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x1802C */
  __IO uint32_t TCD6_DADDR;                        /**< TCD Destination Address, offset: 0x18030 */
  __IO uint16_t TCD6_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x18034 */
  union {                                          /* offset: 0x18036 */
    __IO uint16_t TCD6_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x18036 */
    __IO uint16_t TCD6_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x18036 */
  } CITER6;
  __IO uint32_t TCD6_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x18038 */
  __IO uint16_t TCD6_CSR;                          /**< TCD Control and Status, offset: 0x1803C */
  union {                                          /* offset: 0x1803E */
    __IO uint16_t TCD6_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1803E */
    __IO uint16_t TCD6_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1803E */
  } BITER6;
  uint8_t RESERVED_13[8128];
  __IO uint32_t CH7_CSR;                           /**< Channel Control and Status, offset: 0x1A000 */
  __IO uint32_t CH7_ES;                            /**< Channel Error Status, offset: 0x1A004 */
  __IO uint32_t CH7_INT;                           /**< Channel Interrupt Status, offset: 0x1A008 */
  __IO uint32_t CH7_SBR;                           /**< Channel System Bus, offset: 0x1A00C */
  __IO uint32_t CH7_PRI;                           /**< Channel Priority, offset: 0x1A010 */
  uint8_t RESERVED_14[12];
  __IO uint32_t TCD7_SADDR;                        /**< TCD Source Address, offset: 0x1A020 */
  __IO uint16_t TCD7_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x1A024 */
  __IO uint16_t TCD7_ATTR;                         /**< TCD Transfer Attributes, offset: 0x1A026 */
  union {                                          /* offset: 0x1A028 */
    __IO uint32_t TCD7_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x1A028 */
    __IO uint32_t TCD7_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x1A028 */
  } NBYTES7;
  __IO uint32_t TCD7_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x1A02C */
  __IO uint32_t TCD7_DADDR;                        /**< TCD Destination Address, offset: 0x1A030 */
  __IO uint16_t TCD7_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x1A034 */
  union {                                          /* offset: 0x1A036 */
    __IO uint16_t TCD7_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1A036 */
    __IO uint16_t TCD7_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1A036 */
  } CITER7;
  __IO uint32_t TCD7_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x1A038 */
  __IO uint16_t TCD7_CSR;                          /**< TCD Control and Status, offset: 0x1A03C */
  union {                                          /* offset: 0x1A03E */
    __IO uint16_t TCD7_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x1A03E */
    __IO uint16_t TCD7_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x1A03E */
  } BITER7;
  uint8_t RESERVED_15[24512];
  __IO uint32_t CH8_CSR;                           /**< Channel Control and Status, offset: 0x20000 */
  __IO uint32_t CH8_ES;                            /**< Channel Error Status, offset: 0x20004 */
  __IO uint32_t CH8_INT;                           /**< Channel Interrupt Status, offset: 0x20008 */
  __IO uint32_t CH8_SBR;                           /**< Channel System Bus, offset: 0x2000C */
  __IO uint32_t CH8_PRI;                           /**< Channel Priority, offset: 0x20010 */
  uint8_t RESERVED_16[12];
  __IO uint32_t TCD8_SADDR;                        /**< TCD Source Address, offset: 0x20020 */
  __IO uint16_t TCD8_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x20024 */
  __IO uint16_t TCD8_ATTR;                         /**< TCD Transfer Attributes, offset: 0x20026 */
  union {                                          /* offset: 0x20028 */
    __IO uint32_t TCD8_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x20028 */
    __IO uint32_t TCD8_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x20028 */
  } NBYTES8;
  __IO uint32_t TCD8_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x2002C */
  __IO uint32_t TCD8_DADDR;                        /**< TCD Destination Address, offset: 0x20030 */
  __IO uint16_t TCD8_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x20034 */
  union {                                          /* offset: 0x20036 */
    __IO uint16_t TCD8_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x20036 */
    __IO uint16_t TCD8_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x20036 */
  } CITER8;
  __IO uint32_t TCD8_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x20038 */
  __IO uint16_t TCD8_CSR;                          /**< TCD Control and Status, offset: 0x2003C */
  union {                                          /* offset: 0x2003E */
    __IO uint16_t TCD8_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2003E */
    __IO uint16_t TCD8_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2003E */
  } BITER8;
  uint8_t RESERVED_17[8128];
  __IO uint32_t CH9_CSR;                           /**< Channel Control and Status, offset: 0x22000 */
  __IO uint32_t CH9_ES;                            /**< Channel Error Status, offset: 0x22004 */
  __IO uint32_t CH9_INT;                           /**< Channel Interrupt Status, offset: 0x22008 */
  __IO uint32_t CH9_SBR;                           /**< Channel System Bus, offset: 0x2200C */
  __IO uint32_t CH9_PRI;                           /**< Channel Priority, offset: 0x22010 */
  uint8_t RESERVED_18[12];
  __IO uint32_t TCD9_SADDR;                        /**< TCD Source Address, offset: 0x22020 */
  __IO uint16_t TCD9_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x22024 */
  __IO uint16_t TCD9_ATTR;                         /**< TCD Transfer Attributes, offset: 0x22026 */
  union {                                          /* offset: 0x22028 */
    __IO uint32_t TCD9_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x22028 */
    __IO uint32_t TCD9_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x22028 */
  } NBYTES9;
  __IO uint32_t TCD9_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x2202C */
  __IO uint32_t TCD9_DADDR;                        /**< TCD Destination Address, offset: 0x22030 */
  __IO uint16_t TCD9_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x22034 */
  union {                                          /* offset: 0x22036 */
    __IO uint16_t TCD9_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x22036 */
    __IO uint16_t TCD9_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x22036 */
  } CITER9;
  __IO uint32_t TCD9_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x22038 */
  __IO uint16_t TCD9_CSR;                          /**< TCD Control and Status, offset: 0x2203C */
  union {                                          /* offset: 0x2203E */
    __IO uint16_t TCD9_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2203E */
    __IO uint16_t TCD9_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2203E */
  } BITER9;
  uint8_t RESERVED_19[24512];
  __IO uint32_t CH10_CSR;                          /**< Channel Control and Status, offset: 0x28000 */
  __IO uint32_t CH10_ES;                           /**< Channel Error Status, offset: 0x28004 */
  __IO uint32_t CH10_INT;                          /**< Channel Interrupt Status, offset: 0x28008 */
  __IO uint32_t CH10_SBR;                          /**< Channel System Bus, offset: 0x2800C */
  __IO uint32_t CH10_PRI;                          /**< Channel Priority, offset: 0x28010 */
  uint8_t RESERVED_20[12];
  __IO uint32_t TCD10_SADDR;                       /**< TCD Source Address, offset: 0x28020 */
  __IO uint16_t TCD10_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x28024 */
  __IO uint16_t TCD10_ATTR;                        /**< TCD Transfer Attributes, offset: 0x28026 */
  union {                                          /* offset: 0x28028 */
    __IO uint32_t TCD10_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x28028 */
    __IO uint32_t TCD10_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x28028 */
  } NBYTES10;
  __IO uint32_t TCD10_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x2802C */
  __IO uint32_t TCD10_DADDR;                       /**< TCD Destination Address, offset: 0x28030 */
  __IO uint16_t TCD10_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x28034 */
  union {                                          /* offset: 0x28036 */
    __IO uint16_t TCD10_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x28036 */
    __IO uint16_t TCD10_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x28036 */
  } CITER10;
  __IO uint32_t TCD10_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x28038 */
  __IO uint16_t TCD10_CSR;                         /**< TCD Control and Status, offset: 0x2803C */
  union {                                          /* offset: 0x2803E */
    __IO uint16_t TCD10_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2803E */
    __IO uint16_t TCD10_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2803E */
  } BITER10;
  uint8_t RESERVED_21[8128];
  __IO uint32_t CH11_CSR;                          /**< Channel Control and Status, offset: 0x2A000 */
  __IO uint32_t CH11_ES;                           /**< Channel Error Status, offset: 0x2A004 */
  __IO uint32_t CH11_INT;                          /**< Channel Interrupt Status, offset: 0x2A008 */
  __IO uint32_t CH11_SBR;                          /**< Channel System Bus, offset: 0x2A00C */
  __IO uint32_t CH11_PRI;                          /**< Channel Priority, offset: 0x2A010 */
  uint8_t RESERVED_22[12];
  __IO uint32_t TCD11_SADDR;                       /**< TCD Source Address, offset: 0x2A020 */
  __IO uint16_t TCD11_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x2A024 */
  __IO uint16_t TCD11_ATTR;                        /**< TCD Transfer Attributes, offset: 0x2A026 */
  union {                                          /* offset: 0x2A028 */
    __IO uint32_t TCD11_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x2A028 */
    __IO uint32_t TCD11_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x2A028 */
  } NBYTES11;
  __IO uint32_t TCD11_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x2A02C */
  __IO uint32_t TCD11_DADDR;                       /**< TCD Destination Address, offset: 0x2A030 */
  __IO uint16_t TCD11_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x2A034 */
  union {                                          /* offset: 0x2A036 */
    __IO uint16_t TCD11_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2A036 */
    __IO uint16_t TCD11_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2A036 */
  } CITER11;
  __IO uint32_t TCD11_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x2A038 */
  __IO uint16_t TCD11_CSR;                         /**< TCD Control and Status, offset: 0x2A03C */
  union {                                          /* offset: 0x2A03E */
    __IO uint16_t TCD11_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x2A03E */
    __IO uint16_t TCD11_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x2A03E */
  } BITER11;
} LPE_EDMA_TCD_Type, *LPE_EDMA_TCD_MemMapPtr;

/** Number of instances of the LPE_EDMA_TCD module. */
#define LPE_EDMA_TCD_INSTANCE_COUNT              (1u)

/* LPE_EDMA_TCD - Peripheral instance base addresses */
/** Peripheral LPE_EDMA3_TCD0_1 base address */
#define IP_LPE_EDMA3_TCD0_1_BASE                 (0x4200C000u)
/** Peripheral LPE_EDMA3_TCD0_1 base pointer */
#define IP_LPE_EDMA3_TCD0_1                      ((LPE_EDMA_TCD_Type *)IP_LPE_EDMA3_TCD0_1_BASE)
/** Array initializer of LPE_EDMA_TCD peripheral base addresses */
#define IP_LPE_EDMA_TCD_BASE_ADDRS               { IP_LPE_EDMA3_TCD0_1_BASE }
/** Array initializer of LPE_EDMA_TCD peripheral base pointers */
#define IP_LPE_EDMA_TCD_BASE_PTRS                { IP_LPE_EDMA3_TCD0_1 }

/* ----------------------------------------------------------------------------
   -- LPE_EDMA_TCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_EDMA_TCD_Register_Masks LPE_EDMA_TCD Register Masks
 * @{
 */

/*! @name CH0_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH0_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH0_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH0_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH0_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH0_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH0_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH0_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH0_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH0_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH0_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH0_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH0_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH0_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH0_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH0_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH0_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH0_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH0_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH0_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH0_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH0_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH0_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH0_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH0_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH0_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH0_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH0_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH0_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH0_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH0_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH0_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH0_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH0_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH0_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH0_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH0_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH0_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH0_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH0_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH0_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH0_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH0_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH0_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH0_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH0_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH0_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH0_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH0_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH0_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH0_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH0_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH0_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH0_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH0_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH0_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH0_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH0_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH0_ES_ERR_MASK)
/*! @} */

/*! @name CH0_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH0_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH0_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH0_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH0_INT_INT_MASK)
/*! @} */

/*! @name CH0_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH0_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH0_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH0_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH0_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH0_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH0_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH0_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH0_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH0_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH0_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH0_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH0_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH0_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH0_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH0_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH0_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH0_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH0_SBR_ATTR_MASK)
/*! @} */

/*! @name CH0_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH0_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH0_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH0_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH0_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH0_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH0_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH0_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH0_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH0_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH0_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH0_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH0_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH0_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH0_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH0_PRI_ECP_MASK)
/*! @} */

/*! @name TCD0_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD0_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD0_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD0_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD0_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD0_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD0_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD0_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD0_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD0_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD0_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD0_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD0_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD0_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD0_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD0_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD0_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD0_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD0_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD0_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD0_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD0_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD0_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD0_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD0_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD0_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD0_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD0_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD0_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD0_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD0_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD0_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD0_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD0_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD0_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD0_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD0_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD0_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD0_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD0_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD0_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD0_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD0_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD0_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD0_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD0_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD0_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD0_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD0_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD0_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD0_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD0_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD0_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD0_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD0_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD0_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD0_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD0_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD0_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD0_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD0_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD0_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD0_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD0_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD0_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD0_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD0_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD0_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD0_CSR_BWC_MASK)
/*! @} */

/*! @name TCD0_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD0_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH1_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH1_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH1_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH1_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH1_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH1_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH1_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH1_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH1_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH1_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH1_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH1_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH1_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH1_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH1_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH1_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH1_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH1_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH1_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH1_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH1_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH1_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH1_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH1_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH1_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH1_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH1_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH1_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH1_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH1_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH1_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH1_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH1_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH1_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH1_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH1_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH1_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH1_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH1_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH1_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH1_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH1_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH1_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH1_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH1_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH1_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH1_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH1_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH1_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH1_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH1_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH1_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH1_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH1_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH1_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH1_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH1_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH1_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH1_ES_ERR_MASK)
/*! @} */

/*! @name CH1_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH1_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH1_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH1_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH1_INT_INT_MASK)
/*! @} */

/*! @name CH1_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH1_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH1_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH1_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH1_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH1_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH1_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH1_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH1_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH1_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH1_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH1_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH1_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH1_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH1_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH1_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH1_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH1_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH1_SBR_ATTR_MASK)
/*! @} */

/*! @name CH1_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH1_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH1_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH1_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH1_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH1_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH1_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH1_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH1_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH1_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH1_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH1_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH1_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH1_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH1_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH1_PRI_ECP_MASK)
/*! @} */

/*! @name TCD1_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD1_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD1_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD1_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD1_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD1_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD1_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD1_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD1_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD1_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD1_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD1_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD1_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD1_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD1_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD1_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD1_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD1_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD1_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD1_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD1_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD1_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD1_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD1_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD1_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD1_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD1_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD1_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD1_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD1_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD1_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD1_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD1_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD1_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD1_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD1_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD1_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD1_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD1_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD1_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD1_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD1_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD1_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD1_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD1_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD1_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD1_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD1_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD1_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD1_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD1_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD1_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD1_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD1_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD1_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD1_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD1_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD1_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD1_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD1_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD1_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD1_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD1_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD1_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD1_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD1_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD1_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD1_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD1_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD1_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD1_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD1_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD1_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD1_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD1_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD1_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD1_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD1_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD1_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD1_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD1_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD1_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD1_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD1_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD1_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD1_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD1_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD1_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD1_CSR_BWC_MASK)
/*! @} */

/*! @name TCD1_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD1_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD1_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD1_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD1_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD1_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD1_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD1_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD1_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH2_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH2_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH2_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH2_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH2_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH2_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH2_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH2_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH2_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH2_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH2_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH2_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH2_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH2_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH2_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH2_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH2_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH2_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH2_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH2_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH2_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH2_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH2_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH2_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH2_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH2_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH2_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH2_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH2_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH2_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH2_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH2_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH2_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH2_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH2_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH2_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH2_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH2_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH2_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH2_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH2_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH2_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH2_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH2_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH2_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH2_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH2_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH2_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH2_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH2_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH2_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH2_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH2_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH2_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH2_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH2_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH2_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH2_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH2_ES_ERR_MASK)
/*! @} */

/*! @name CH2_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH2_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH2_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH2_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH2_INT_INT_MASK)
/*! @} */

/*! @name CH2_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH2_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH2_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH2_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH2_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH2_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH2_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH2_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH2_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH2_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH2_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH2_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH2_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH2_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH2_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH2_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH2_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH2_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH2_SBR_ATTR_MASK)
/*! @} */

/*! @name CH2_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH2_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH2_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH2_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH2_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH2_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH2_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH2_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH2_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH2_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH2_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH2_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH2_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH2_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH2_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH2_PRI_ECP_MASK)
/*! @} */

/*! @name TCD2_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD2_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD2_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD2_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD2_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD2_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD2_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD2_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD2_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD2_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD2_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD2_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD2_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD2_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD2_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD2_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD2_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD2_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD2_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD2_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD2_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD2_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD2_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD2_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD2_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD2_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD2_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD2_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD2_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD2_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD2_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD2_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD2_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD2_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD2_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD2_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD2_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD2_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD2_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD2_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD2_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD2_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD2_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD2_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD2_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD2_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD2_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD2_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD2_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD2_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD2_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD2_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD2_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD2_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD2_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD2_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD2_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD2_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD2_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD2_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD2_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD2_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD2_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD2_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD2_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD2_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD2_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD2_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD2_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD2_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD2_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD2_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD2_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD2_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD2_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD2_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD2_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD2_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD2_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD2_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD2_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD2_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD2_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD2_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD2_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD2_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD2_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD2_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD2_CSR_BWC_MASK)
/*! @} */

/*! @name TCD2_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD2_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD2_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD2_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD2_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD2_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD2_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD2_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD2_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH3_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH3_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH3_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH3_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH3_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH3_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH3_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH3_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH3_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH3_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH3_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH3_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH3_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH3_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH3_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH3_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH3_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH3_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH3_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH3_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH3_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH3_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH3_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH3_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH3_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH3_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH3_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH3_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH3_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH3_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH3_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH3_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH3_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH3_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH3_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH3_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH3_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH3_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH3_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH3_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH3_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH3_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH3_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH3_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH3_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH3_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH3_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH3_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH3_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH3_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH3_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH3_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH3_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH3_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH3_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH3_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH3_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH3_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH3_ES_ERR_MASK)
/*! @} */

/*! @name CH3_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH3_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH3_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH3_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH3_INT_INT_MASK)
/*! @} */

/*! @name CH3_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH3_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH3_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH3_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH3_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH3_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH3_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH3_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH3_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH3_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH3_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH3_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH3_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH3_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH3_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH3_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH3_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH3_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH3_SBR_ATTR_MASK)
/*! @} */

/*! @name CH3_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH3_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH3_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH3_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH3_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH3_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH3_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH3_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH3_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH3_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH3_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH3_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH3_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH3_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH3_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH3_PRI_ECP_MASK)
/*! @} */

/*! @name TCD3_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD3_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD3_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD3_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD3_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD3_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD3_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD3_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD3_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD3_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD3_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD3_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD3_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD3_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD3_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD3_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD3_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD3_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD3_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD3_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD3_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD3_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD3_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD3_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD3_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD3_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD3_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD3_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD3_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD3_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD3_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD3_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD3_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD3_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD3_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD3_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD3_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD3_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD3_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD3_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD3_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD3_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD3_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD3_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD3_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD3_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD3_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD3_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD3_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD3_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD3_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD3_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD3_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD3_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD3_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD3_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD3_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD3_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD3_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD3_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD3_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD3_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD3_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD3_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD3_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD3_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD3_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD3_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD3_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD3_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD3_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD3_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD3_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD3_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD3_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD3_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD3_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD3_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD3_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD3_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD3_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD3_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD3_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD3_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD3_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD3_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD3_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD3_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD3_CSR_BWC_MASK)
/*! @} */

/*! @name TCD3_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD3_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD3_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD3_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD3_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD3_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD3_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD3_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD3_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH4_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH4_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH4_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH4_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH4_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH4_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH4_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH4_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH4_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH4_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH4_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH4_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH4_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH4_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH4_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH4_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH4_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH4_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH4_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH4_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH4_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH4_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH4_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH4_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH4_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH4_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH4_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH4_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH4_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH4_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH4_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH4_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH4_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH4_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH4_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH4_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH4_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH4_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH4_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH4_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH4_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH4_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH4_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH4_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH4_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH4_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH4_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH4_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH4_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH4_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH4_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH4_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH4_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH4_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH4_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH4_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH4_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH4_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH4_ES_ERR_MASK)
/*! @} */

/*! @name CH4_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH4_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH4_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH4_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH4_INT_INT_MASK)
/*! @} */

/*! @name CH4_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH4_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH4_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH4_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH4_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH4_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH4_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH4_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH4_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH4_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH4_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH4_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH4_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH4_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH4_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH4_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH4_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH4_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH4_SBR_ATTR_MASK)
/*! @} */

/*! @name CH4_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH4_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH4_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH4_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH4_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH4_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH4_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH4_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH4_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH4_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH4_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH4_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH4_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH4_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH4_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH4_PRI_ECP_MASK)
/*! @} */

/*! @name TCD4_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD4_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD4_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD4_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD4_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD4_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD4_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD4_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD4_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD4_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD4_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD4_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD4_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD4_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD4_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD4_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD4_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD4_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD4_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD4_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD4_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD4_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD4_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD4_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD4_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD4_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD4_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD4_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD4_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD4_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD4_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD4_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD4_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD4_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD4_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD4_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD4_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD4_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD4_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD4_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD4_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD4_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD4_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD4_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD4_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD4_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD4_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD4_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD4_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD4_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD4_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD4_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD4_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD4_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD4_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD4_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD4_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD4_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD4_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD4_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD4_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD4_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD4_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD4_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD4_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD4_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD4_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD4_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD4_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD4_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD4_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD4_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD4_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD4_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD4_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD4_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD4_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD4_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD4_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD4_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD4_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD4_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD4_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD4_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD4_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD4_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD4_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD4_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD4_CSR_BWC_MASK)
/*! @} */

/*! @name TCD4_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD4_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD4_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD4_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD4_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD4_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD4_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD4_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD4_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH5_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH5_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH5_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH5_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH5_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH5_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH5_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH5_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH5_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH5_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH5_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH5_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH5_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH5_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH5_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH5_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH5_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH5_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH5_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH5_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH5_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH5_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH5_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH5_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH5_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH5_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH5_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH5_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH5_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH5_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH5_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH5_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH5_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH5_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH5_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH5_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH5_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH5_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH5_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH5_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH5_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH5_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH5_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH5_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH5_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH5_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH5_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH5_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH5_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH5_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH5_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH5_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH5_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH5_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH5_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH5_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH5_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH5_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH5_ES_ERR_MASK)
/*! @} */

/*! @name CH5_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH5_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH5_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH5_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH5_INT_INT_MASK)
/*! @} */

/*! @name CH5_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH5_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH5_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH5_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH5_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH5_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH5_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH5_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH5_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH5_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH5_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH5_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH5_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH5_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH5_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH5_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH5_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH5_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH5_SBR_ATTR_MASK)
/*! @} */

/*! @name CH5_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH5_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH5_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH5_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH5_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH5_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH5_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH5_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH5_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH5_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH5_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH5_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH5_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH5_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH5_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH5_PRI_ECP_MASK)
/*! @} */

/*! @name TCD5_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD5_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD5_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD5_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD5_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD5_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD5_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD5_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD5_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD5_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD5_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD5_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD5_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD5_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD5_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD5_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD5_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD5_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD5_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD5_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD5_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD5_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD5_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD5_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD5_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD5_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD5_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD5_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD5_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD5_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD5_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD5_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD5_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD5_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD5_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD5_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD5_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD5_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD5_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD5_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD5_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD5_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD5_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD5_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD5_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD5_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD5_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD5_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD5_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD5_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD5_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD5_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD5_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD5_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD5_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD5_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD5_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD5_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD5_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD5_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD5_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD5_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD5_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD5_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD5_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD5_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD5_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD5_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD5_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD5_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD5_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD5_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD5_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD5_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD5_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD5_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD5_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD5_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD5_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD5_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD5_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD5_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD5_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD5_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD5_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD5_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD5_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD5_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD5_CSR_BWC_MASK)
/*! @} */

/*! @name TCD5_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD5_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD5_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD5_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD5_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD5_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD5_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD5_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD5_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH6_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH6_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH6_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH6_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH6_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH6_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH6_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH6_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH6_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH6_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH6_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH6_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH6_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH6_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH6_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH6_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH6_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH6_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH6_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH6_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH6_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH6_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH6_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH6_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH6_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH6_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH6_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH6_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH6_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH6_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH6_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH6_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH6_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH6_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH6_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH6_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH6_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH6_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH6_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH6_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH6_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH6_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH6_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH6_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH6_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH6_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH6_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH6_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH6_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH6_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH6_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH6_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH6_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH6_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH6_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH6_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH6_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH6_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH6_ES_ERR_MASK)
/*! @} */

/*! @name CH6_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH6_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH6_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH6_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH6_INT_INT_MASK)
/*! @} */

/*! @name CH6_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH6_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH6_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH6_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH6_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH6_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH6_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH6_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH6_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH6_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH6_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH6_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH6_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH6_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH6_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH6_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH6_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH6_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH6_SBR_ATTR_MASK)
/*! @} */

/*! @name CH6_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH6_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH6_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH6_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH6_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH6_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH6_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH6_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH6_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH6_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH6_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH6_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH6_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH6_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH6_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH6_PRI_ECP_MASK)
/*! @} */

/*! @name TCD6_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD6_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD6_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD6_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD6_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD6_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD6_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD6_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD6_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD6_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD6_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD6_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD6_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD6_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD6_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD6_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD6_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD6_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD6_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD6_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD6_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD6_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD6_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD6_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD6_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD6_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD6_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD6_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD6_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD6_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD6_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD6_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD6_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD6_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD6_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD6_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD6_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD6_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD6_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD6_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD6_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD6_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD6_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD6_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD6_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD6_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD6_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD6_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD6_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD6_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD6_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD6_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD6_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD6_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD6_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD6_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD6_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD6_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD6_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD6_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD6_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD6_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD6_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD6_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD6_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD6_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD6_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD6_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD6_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD6_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD6_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD6_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD6_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD6_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD6_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD6_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD6_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD6_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD6_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD6_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD6_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD6_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD6_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD6_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD6_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD6_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD6_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD6_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD6_CSR_BWC_MASK)
/*! @} */

/*! @name TCD6_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD6_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD6_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD6_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD6_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD6_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD6_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD6_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD6_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH7_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH7_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH7_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH7_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH7_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH7_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH7_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH7_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH7_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH7_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH7_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH7_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH7_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH7_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH7_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH7_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH7_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH7_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH7_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH7_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH7_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH7_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH7_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH7_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH7_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH7_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH7_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH7_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH7_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH7_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH7_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH7_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH7_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH7_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH7_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH7_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH7_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH7_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH7_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH7_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH7_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH7_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH7_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH7_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH7_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH7_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH7_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH7_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH7_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH7_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH7_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH7_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH7_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH7_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH7_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH7_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH7_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH7_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH7_ES_ERR_MASK)
/*! @} */

/*! @name CH7_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH7_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH7_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH7_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH7_INT_INT_MASK)
/*! @} */

/*! @name CH7_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH7_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH7_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH7_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH7_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH7_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH7_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH7_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH7_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH7_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH7_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH7_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH7_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH7_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH7_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH7_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH7_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH7_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH7_SBR_ATTR_MASK)
/*! @} */

/*! @name CH7_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH7_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH7_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH7_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH7_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH7_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH7_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH7_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH7_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH7_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH7_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH7_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH7_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH7_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH7_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH7_PRI_ECP_MASK)
/*! @} */

/*! @name TCD7_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD7_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD7_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD7_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD7_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD7_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD7_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD7_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD7_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD7_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD7_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD7_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD7_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD7_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD7_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD7_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD7_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD7_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD7_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD7_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD7_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD7_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD7_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD7_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD7_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD7_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD7_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD7_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD7_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD7_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD7_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD7_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD7_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD7_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD7_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD7_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD7_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD7_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD7_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD7_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD7_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD7_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD7_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD7_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD7_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD7_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD7_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD7_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD7_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD7_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD7_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD7_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD7_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD7_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD7_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD7_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD7_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD7_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD7_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD7_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD7_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD7_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD7_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD7_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD7_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD7_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD7_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD7_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD7_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD7_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD7_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD7_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD7_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD7_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD7_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD7_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD7_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD7_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD7_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD7_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD7_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD7_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD7_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD7_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD7_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD7_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD7_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD7_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD7_CSR_BWC_MASK)
/*! @} */

/*! @name TCD7_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD7_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD7_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD7_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD7_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD7_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD7_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD7_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD7_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH8_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH8_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH8_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH8_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH8_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH8_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH8_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH8_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH8_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH8_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH8_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH8_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH8_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH8_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH8_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH8_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH8_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH8_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH8_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH8_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH8_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH8_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH8_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH8_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH8_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH8_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH8_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH8_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH8_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH8_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH8_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH8_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH8_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH8_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH8_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH8_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH8_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH8_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH8_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH8_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH8_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH8_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH8_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH8_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH8_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH8_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH8_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH8_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH8_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH8_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH8_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH8_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH8_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH8_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH8_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH8_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH8_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH8_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH8_ES_ERR_MASK)
/*! @} */

/*! @name CH8_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH8_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH8_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH8_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH8_INT_INT_MASK)
/*! @} */

/*! @name CH8_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH8_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH8_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH8_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH8_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH8_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH8_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH8_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH8_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH8_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH8_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH8_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH8_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH8_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH8_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH8_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH8_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH8_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH8_SBR_ATTR_MASK)
/*! @} */

/*! @name CH8_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH8_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH8_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH8_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH8_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH8_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH8_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH8_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH8_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH8_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH8_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH8_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH8_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH8_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH8_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH8_PRI_ECP_MASK)
/*! @} */

/*! @name TCD8_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD8_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD8_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD8_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD8_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD8_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD8_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD8_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD8_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD8_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD8_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD8_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD8_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD8_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD8_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD8_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD8_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD8_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD8_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD8_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD8_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD8_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD8_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD8_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD8_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD8_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD8_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD8_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD8_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD8_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD8_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD8_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD8_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD8_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD8_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD8_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD8_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD8_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD8_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD8_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD8_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD8_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD8_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD8_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD8_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD8_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD8_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD8_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD8_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD8_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD8_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD8_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD8_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD8_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD8_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD8_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD8_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD8_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD8_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD8_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD8_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD8_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD8_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD8_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD8_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD8_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD8_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD8_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD8_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD8_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD8_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD8_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD8_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD8_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD8_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD8_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD8_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD8_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD8_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD8_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD8_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD8_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD8_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD8_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD8_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD8_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD8_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD8_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD8_CSR_BWC_MASK)
/*! @} */

/*! @name TCD8_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD8_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD8_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD8_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD8_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD8_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD8_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD8_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD8_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH9_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH9_CSR_ERQ_MASK            (0x1U)
#define LPE_EDMA_TCD_CH9_CSR_ERQ_SHIFT           (0U)
#define LPE_EDMA_TCD_CH9_CSR_ERQ_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_CSR_ERQ(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH9_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH9_CSR_EARQ_MASK           (0x2U)
#define LPE_EDMA_TCD_CH9_CSR_EARQ_SHIFT          (1U)
#define LPE_EDMA_TCD_CH9_CSR_EARQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH9_CSR_EARQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH9_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH9_CSR_EEI_MASK            (0x4U)
#define LPE_EDMA_TCD_CH9_CSR_EEI_SHIFT           (2U)
#define LPE_EDMA_TCD_CH9_CSR_EEI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_CSR_EEI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH9_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH9_CSR_EBW_MASK            (0x8U)
#define LPE_EDMA_TCD_CH9_CSR_EBW_SHIFT           (3U)
#define LPE_EDMA_TCD_CH9_CSR_EBW_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_CSR_EBW(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH9_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH9_CSR_DONE_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH9_CSR_DONE_SHIFT          (30U)
#define LPE_EDMA_TCD_CH9_CSR_DONE_WIDTH          (1U)
#define LPE_EDMA_TCD_CH9_CSR_DONE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH9_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH9_CSR_ACTIVE_MASK         (0x80000000U)
#define LPE_EDMA_TCD_CH9_CSR_ACTIVE_SHIFT        (31U)
#define LPE_EDMA_TCD_CH9_CSR_ACTIVE_WIDTH        (1U)
#define LPE_EDMA_TCD_CH9_CSR_ACTIVE(x)           (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH9_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH9_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH9_ES_DBE_MASK             (0x1U)
#define LPE_EDMA_TCD_CH9_ES_DBE_SHIFT            (0U)
#define LPE_EDMA_TCD_CH9_ES_DBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_DBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH9_ES_SBE_MASK             (0x2U)
#define LPE_EDMA_TCD_CH9_ES_SBE_SHIFT            (1U)
#define LPE_EDMA_TCD_CH9_ES_SBE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_SBE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH9_ES_SGE_MASK             (0x4U)
#define LPE_EDMA_TCD_CH9_ES_SGE_SHIFT            (2U)
#define LPE_EDMA_TCD_CH9_ES_SGE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_SGE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH9_ES_NCE_MASK             (0x8U)
#define LPE_EDMA_TCD_CH9_ES_NCE_SHIFT            (3U)
#define LPE_EDMA_TCD_CH9_ES_NCE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_NCE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH9_ES_DOE_MASK             (0x10U)
#define LPE_EDMA_TCD_CH9_ES_DOE_SHIFT            (4U)
#define LPE_EDMA_TCD_CH9_ES_DOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_DOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH9_ES_DAE_MASK             (0x20U)
#define LPE_EDMA_TCD_CH9_ES_DAE_SHIFT            (5U)
#define LPE_EDMA_TCD_CH9_ES_DAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_DAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH9_ES_SOE_MASK             (0x40U)
#define LPE_EDMA_TCD_CH9_ES_SOE_SHIFT            (6U)
#define LPE_EDMA_TCD_CH9_ES_SOE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_SOE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH9_ES_SAE_MASK             (0x80U)
#define LPE_EDMA_TCD_CH9_ES_SAE_SHIFT            (7U)
#define LPE_EDMA_TCD_CH9_ES_SAE_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_SAE(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH9_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH9_ES_ERR_MASK             (0x80000000U)
#define LPE_EDMA_TCD_CH9_ES_ERR_SHIFT            (31U)
#define LPE_EDMA_TCD_CH9_ES_ERR_WIDTH            (1U)
#define LPE_EDMA_TCD_CH9_ES_ERR(x)               (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH9_ES_ERR_MASK)
/*! @} */

/*! @name CH9_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH9_INT_INT_MASK            (0x1U)
#define LPE_EDMA_TCD_CH9_INT_INT_SHIFT           (0U)
#define LPE_EDMA_TCD_CH9_INT_INT_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_INT_INT(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH9_INT_INT_MASK)
/*! @} */

/*! @name CH9_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH9_SBR_MID_MASK            (0x3FU)
#define LPE_EDMA_TCD_CH9_SBR_MID_SHIFT           (0U)
#define LPE_EDMA_TCD_CH9_SBR_MID_WIDTH           (6U)
#define LPE_EDMA_TCD_CH9_SBR_MID(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH9_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH9_SBR_PAL_MASK            (0x8000U)
#define LPE_EDMA_TCD_CH9_SBR_PAL_SHIFT           (15U)
#define LPE_EDMA_TCD_CH9_SBR_PAL_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_SBR_PAL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH9_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH9_SBR_EMI_MASK            (0x10000U)
#define LPE_EDMA_TCD_CH9_SBR_EMI_SHIFT           (16U)
#define LPE_EDMA_TCD_CH9_SBR_EMI_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_SBR_EMI(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH9_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH9_SBR_ATTR_MASK           (0x20000U)
#define LPE_EDMA_TCD_CH9_SBR_ATTR_SHIFT          (17U)
#define LPE_EDMA_TCD_CH9_SBR_ATTR_WIDTH          (1U)
#define LPE_EDMA_TCD_CH9_SBR_ATTR(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH9_SBR_ATTR_MASK)
/*! @} */

/*! @name CH9_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH9_PRI_APL_MASK            (0x7U)
#define LPE_EDMA_TCD_CH9_PRI_APL_SHIFT           (0U)
#define LPE_EDMA_TCD_CH9_PRI_APL_WIDTH           (3U)
#define LPE_EDMA_TCD_CH9_PRI_APL(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH9_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH9_PRI_DPA_MASK            (0x40000000U)
#define LPE_EDMA_TCD_CH9_PRI_DPA_SHIFT           (30U)
#define LPE_EDMA_TCD_CH9_PRI_DPA_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_PRI_DPA(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH9_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH9_PRI_ECP_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH9_PRI_ECP_SHIFT           (31U)
#define LPE_EDMA_TCD_CH9_PRI_ECP_WIDTH           (1U)
#define LPE_EDMA_TCD_CH9_PRI_ECP(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH9_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH9_PRI_ECP_MASK)
/*! @} */

/*! @name TCD9_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_SADDR_SADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD9_SADDR_SADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD9_SADDR_SADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD9_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD9_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD9_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_SOFF_SOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD9_SOFF_SOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD9_SOFF_SOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD9_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD9_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD9_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_ATTR_DSIZE_MASK        (0x7U)
#define LPE_EDMA_TCD_TCD9_ATTR_DSIZE_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD9_ATTR_DSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD9_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD9_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD9_ATTR_DMOD_MASK         (0xF8U)
#define LPE_EDMA_TCD_TCD9_ATTR_DMOD_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD9_ATTR_DMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD9_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD9_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD9_ATTR_SSIZE_MASK        (0x700U)
#define LPE_EDMA_TCD_TCD9_ATTR_SSIZE_SHIFT       (8U)
#define LPE_EDMA_TCD_TCD9_ATTR_SSIZE_WIDTH       (3U)
#define LPE_EDMA_TCD_TCD9_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD9_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD9_ATTR_SMOD_MASK         (0xF800U)
#define LPE_EDMA_TCD_TCD9_ATTR_SMOD_SHIFT        (11U)
#define LPE_EDMA_TCD_TCD9_ATTR_SMOD_WIDTH        (5U)
#define LPE_EDMA_TCD_TCD9_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD9_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD9_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD9_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD9_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD9_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD9_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD9_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD9_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD9_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_DADDR_DADDR_MASK       (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD9_DADDR_DADDR_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD9_DADDR_DADDR_WIDTH      (32U)
#define LPE_EDMA_TCD_TCD9_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD9_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD9_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_DOFF_DOFF_MASK         (0xFFFFU)
#define LPE_EDMA_TCD_TCD9_DOFF_DOFF_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD9_DOFF_DOFF_WIDTH        (16U)
#define LPE_EDMA_TCD_TCD9_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD9_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD9_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD9_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD9_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD9_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD9_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD9_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD9_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD9_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD9_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD9_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD9_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD9_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD9_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_CSR_START_MASK         (0x1U)
#define LPE_EDMA_TCD_TCD9_CSR_START_SHIFT        (0U)
#define LPE_EDMA_TCD_TCD9_CSR_START_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD9_CSR_START(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_INTMAJOR_MASK      (0x2U)
#define LPE_EDMA_TCD_TCD9_CSR_INTMAJOR_SHIFT     (1U)
#define LPE_EDMA_TCD_TCD9_CSR_INTMAJOR_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD9_CSR_INTMAJOR(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_INTHALF_MASK       (0x4U)
#define LPE_EDMA_TCD_TCD9_CSR_INTHALF_SHIFT      (2U)
#define LPE_EDMA_TCD_TCD9_CSR_INTHALF_WIDTH      (1U)
#define LPE_EDMA_TCD_TCD9_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_DREQ_MASK          (0x8U)
#define LPE_EDMA_TCD_TCD9_CSR_DREQ_SHIFT         (3U)
#define LPE_EDMA_TCD_TCD9_CSR_DREQ_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD9_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_ESG_MASK           (0x10U)
#define LPE_EDMA_TCD_TCD9_CSR_ESG_SHIFT          (4U)
#define LPE_EDMA_TCD_TCD9_CSR_ESG_WIDTH          (1U)
#define LPE_EDMA_TCD_TCD9_CSR_ESG(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_MAJORELINK_MASK    (0x20U)
#define LPE_EDMA_TCD_TCD9_CSR_MAJORELINK_SHIFT   (5U)
#define LPE_EDMA_TCD_TCD9_CSR_MAJORELINK_WIDTH   (1U)
#define LPE_EDMA_TCD_TCD9_CSR_MAJORELINK(x)      (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_ESDA_MASK          (0x80U)
#define LPE_EDMA_TCD_TCD9_CSR_ESDA_SHIFT         (7U)
#define LPE_EDMA_TCD_TCD9_CSR_ESDA_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD9_CSR_ESDA(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_MAJORLINKCH_MASK   (0xF00U)
#define LPE_EDMA_TCD_TCD9_CSR_MAJORLINKCH_SHIFT  (8U)
#define LPE_EDMA_TCD_TCD9_CSR_MAJORLINKCH_WIDTH  (4U)
#define LPE_EDMA_TCD_TCD9_CSR_MAJORLINKCH(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD9_CSR_BWC_MASK           (0xC000U)
#define LPE_EDMA_TCD_TCD9_CSR_BWC_SHIFT          (14U)
#define LPE_EDMA_TCD_TCD9_CSR_BWC_WIDTH          (2U)
#define LPE_EDMA_TCD_TCD9_CSR_BWC(x)             (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD9_CSR_BWC_MASK)
/*! @} */

/*! @name TCD9_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD9_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD9_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD9_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD9_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD9_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD9_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD9_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD9_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH10_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH10_CSR_ERQ_MASK           (0x1U)
#define LPE_EDMA_TCD_CH10_CSR_ERQ_SHIFT          (0U)
#define LPE_EDMA_TCD_CH10_CSR_ERQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH10_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH10_CSR_EARQ_MASK          (0x2U)
#define LPE_EDMA_TCD_CH10_CSR_EARQ_SHIFT         (1U)
#define LPE_EDMA_TCD_CH10_CSR_EARQ_WIDTH         (1U)
#define LPE_EDMA_TCD_CH10_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH10_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH10_CSR_EEI_MASK           (0x4U)
#define LPE_EDMA_TCD_CH10_CSR_EEI_SHIFT          (2U)
#define LPE_EDMA_TCD_CH10_CSR_EEI_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH10_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH10_CSR_EBW_MASK           (0x8U)
#define LPE_EDMA_TCD_CH10_CSR_EBW_SHIFT          (3U)
#define LPE_EDMA_TCD_CH10_CSR_EBW_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_CSR_EBW(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH10_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH10_CSR_DONE_MASK          (0x40000000U)
#define LPE_EDMA_TCD_CH10_CSR_DONE_SHIFT         (30U)
#define LPE_EDMA_TCD_CH10_CSR_DONE_WIDTH         (1U)
#define LPE_EDMA_TCD_CH10_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH10_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH10_CSR_ACTIVE_MASK        (0x80000000U)
#define LPE_EDMA_TCD_CH10_CSR_ACTIVE_SHIFT       (31U)
#define LPE_EDMA_TCD_CH10_CSR_ACTIVE_WIDTH       (1U)
#define LPE_EDMA_TCD_CH10_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH10_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH10_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH10_ES_DBE_MASK            (0x1U)
#define LPE_EDMA_TCD_CH10_ES_DBE_SHIFT           (0U)
#define LPE_EDMA_TCD_CH10_ES_DBE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH10_ES_SBE_MASK            (0x2U)
#define LPE_EDMA_TCD_CH10_ES_SBE_SHIFT           (1U)
#define LPE_EDMA_TCD_CH10_ES_SBE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH10_ES_SGE_MASK            (0x4U)
#define LPE_EDMA_TCD_CH10_ES_SGE_SHIFT           (2U)
#define LPE_EDMA_TCD_CH10_ES_SGE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH10_ES_NCE_MASK            (0x8U)
#define LPE_EDMA_TCD_CH10_ES_NCE_SHIFT           (3U)
#define LPE_EDMA_TCD_CH10_ES_NCE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH10_ES_DOE_MASK            (0x10U)
#define LPE_EDMA_TCD_CH10_ES_DOE_SHIFT           (4U)
#define LPE_EDMA_TCD_CH10_ES_DOE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH10_ES_DAE_MASK            (0x20U)
#define LPE_EDMA_TCD_CH10_ES_DAE_SHIFT           (5U)
#define LPE_EDMA_TCD_CH10_ES_DAE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH10_ES_SOE_MASK            (0x40U)
#define LPE_EDMA_TCD_CH10_ES_SOE_SHIFT           (6U)
#define LPE_EDMA_TCD_CH10_ES_SOE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH10_ES_SAE_MASK            (0x80U)
#define LPE_EDMA_TCD_CH10_ES_SAE_SHIFT           (7U)
#define LPE_EDMA_TCD_CH10_ES_SAE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH10_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH10_ES_ERR_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH10_ES_ERR_SHIFT           (31U)
#define LPE_EDMA_TCD_CH10_ES_ERR_WIDTH           (1U)
#define LPE_EDMA_TCD_CH10_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH10_ES_ERR_MASK)
/*! @} */

/*! @name CH10_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH10_INT_INT_MASK           (0x1U)
#define LPE_EDMA_TCD_CH10_INT_INT_SHIFT          (0U)
#define LPE_EDMA_TCD_CH10_INT_INT_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH10_INT_INT_MASK)
/*! @} */

/*! @name CH10_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH10_SBR_MID_MASK           (0x3FU)
#define LPE_EDMA_TCD_CH10_SBR_MID_SHIFT          (0U)
#define LPE_EDMA_TCD_CH10_SBR_MID_WIDTH          (6U)
#define LPE_EDMA_TCD_CH10_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH10_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH10_SBR_PAL_MASK           (0x8000U)
#define LPE_EDMA_TCD_CH10_SBR_PAL_SHIFT          (15U)
#define LPE_EDMA_TCD_CH10_SBR_PAL_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH10_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH10_SBR_EMI_MASK           (0x10000U)
#define LPE_EDMA_TCD_CH10_SBR_EMI_SHIFT          (16U)
#define LPE_EDMA_TCD_CH10_SBR_EMI_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH10_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH10_SBR_ATTR_MASK          (0x20000U)
#define LPE_EDMA_TCD_CH10_SBR_ATTR_SHIFT         (17U)
#define LPE_EDMA_TCD_CH10_SBR_ATTR_WIDTH         (1U)
#define LPE_EDMA_TCD_CH10_SBR_ATTR(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH10_SBR_ATTR_MASK)
/*! @} */

/*! @name CH10_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH10_PRI_APL_MASK           (0x7U)
#define LPE_EDMA_TCD_CH10_PRI_APL_SHIFT          (0U)
#define LPE_EDMA_TCD_CH10_PRI_APL_WIDTH          (3U)
#define LPE_EDMA_TCD_CH10_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH10_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH10_PRI_DPA_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH10_PRI_DPA_SHIFT          (30U)
#define LPE_EDMA_TCD_CH10_PRI_DPA_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH10_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH10_PRI_ECP_MASK           (0x80000000U)
#define LPE_EDMA_TCD_CH10_PRI_ECP_SHIFT          (31U)
#define LPE_EDMA_TCD_CH10_PRI_ECP_WIDTH          (1U)
#define LPE_EDMA_TCD_CH10_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH10_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH10_PRI_ECP_MASK)
/*! @} */

/*! @name TCD10_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD10_SADDR_SADDR_SHIFT     (0U)
#define LPE_EDMA_TCD_TCD10_SADDR_SADDR_WIDTH     (32U)
#define LPE_EDMA_TCD_TCD10_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD10_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD10_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_SOFF_SOFF_MASK        (0xFFFFU)
#define LPE_EDMA_TCD_TCD10_SOFF_SOFF_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD10_SOFF_SOFF_WIDTH       (16U)
#define LPE_EDMA_TCD_TCD10_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD10_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD10_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_ATTR_DSIZE_MASK       (0x7U)
#define LPE_EDMA_TCD_TCD10_ATTR_DSIZE_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD10_ATTR_DSIZE_WIDTH      (3U)
#define LPE_EDMA_TCD_TCD10_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD10_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD10_ATTR_DMOD_MASK        (0xF8U)
#define LPE_EDMA_TCD_TCD10_ATTR_DMOD_SHIFT       (3U)
#define LPE_EDMA_TCD_TCD10_ATTR_DMOD_WIDTH       (5U)
#define LPE_EDMA_TCD_TCD10_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD10_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD10_ATTR_SSIZE_MASK       (0x700U)
#define LPE_EDMA_TCD_TCD10_ATTR_SSIZE_SHIFT      (8U)
#define LPE_EDMA_TCD_TCD10_ATTR_SSIZE_WIDTH      (3U)
#define LPE_EDMA_TCD_TCD10_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD10_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD10_ATTR_SMOD_MASK        (0xF800U)
#define LPE_EDMA_TCD_TCD10_ATTR_SMOD_SHIFT       (11U)
#define LPE_EDMA_TCD_TCD10_ATTR_SMOD_WIDTH       (5U)
#define LPE_EDMA_TCD_TCD10_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD10_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD10_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD10_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD10_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD10_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD10_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD10_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD10_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD10_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD10_DADDR_DADDR_SHIFT     (0U)
#define LPE_EDMA_TCD_TCD10_DADDR_DADDR_WIDTH     (32U)
#define LPE_EDMA_TCD_TCD10_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD10_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD10_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_DOFF_DOFF_MASK        (0xFFFFU)
#define LPE_EDMA_TCD_TCD10_DOFF_DOFF_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD10_DOFF_DOFF_WIDTH       (16U)
#define LPE_EDMA_TCD_TCD10_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD10_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD10_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD10_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD10_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD10_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD10_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD10_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD10_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD10_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD10_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD10_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD10_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD10_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD10_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_CSR_START_MASK        (0x1U)
#define LPE_EDMA_TCD_TCD10_CSR_START_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD10_CSR_START_WIDTH       (1U)
#define LPE_EDMA_TCD_TCD10_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_INTMAJOR_MASK     (0x2U)
#define LPE_EDMA_TCD_TCD10_CSR_INTMAJOR_SHIFT    (1U)
#define LPE_EDMA_TCD_TCD10_CSR_INTMAJOR_WIDTH    (1U)
#define LPE_EDMA_TCD_TCD10_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_INTHALF_MASK      (0x4U)
#define LPE_EDMA_TCD_TCD10_CSR_INTHALF_SHIFT     (2U)
#define LPE_EDMA_TCD_TCD10_CSR_INTHALF_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD10_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_DREQ_MASK         (0x8U)
#define LPE_EDMA_TCD_TCD10_CSR_DREQ_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD10_CSR_DREQ_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD10_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_ESG_MASK          (0x10U)
#define LPE_EDMA_TCD_TCD10_CSR_ESG_SHIFT         (4U)
#define LPE_EDMA_TCD_TCD10_CSR_ESG_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD10_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_MAJORELINK_MASK   (0x20U)
#define LPE_EDMA_TCD_TCD10_CSR_MAJORELINK_SHIFT  (5U)
#define LPE_EDMA_TCD_TCD10_CSR_MAJORELINK_WIDTH  (1U)
#define LPE_EDMA_TCD_TCD10_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_ESDA_MASK         (0x80U)
#define LPE_EDMA_TCD_TCD10_CSR_ESDA_SHIFT        (7U)
#define LPE_EDMA_TCD_TCD10_CSR_ESDA_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD10_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_MAJORLINKCH_MASK  (0xF00U)
#define LPE_EDMA_TCD_TCD10_CSR_MAJORLINKCH_SHIFT (8U)
#define LPE_EDMA_TCD_TCD10_CSR_MAJORLINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD10_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD10_CSR_BWC_MASK          (0xC000U)
#define LPE_EDMA_TCD_TCD10_CSR_BWC_SHIFT         (14U)
#define LPE_EDMA_TCD_TCD10_CSR_BWC_WIDTH         (2U)
#define LPE_EDMA_TCD_TCD10_CSR_BWC(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD10_CSR_BWC_MASK)
/*! @} */

/*! @name TCD10_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD10_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD10_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD10_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD10_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD10_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD10_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD10_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD10_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH11_CSR - Channel Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_CH11_CSR_ERQ_MASK           (0x1U)
#define LPE_EDMA_TCD_CH11_CSR_ERQ_SHIFT          (0U)
#define LPE_EDMA_TCD_CH11_CSR_ERQ_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_CSR_ERQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_CSR_ERQ_SHIFT)) & LPE_EDMA_TCD_CH11_CSR_ERQ_MASK)

#define LPE_EDMA_TCD_CH11_CSR_EARQ_MASK          (0x2U)
#define LPE_EDMA_TCD_CH11_CSR_EARQ_SHIFT         (1U)
#define LPE_EDMA_TCD_CH11_CSR_EARQ_WIDTH         (1U)
#define LPE_EDMA_TCD_CH11_CSR_EARQ(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_CSR_EARQ_SHIFT)) & LPE_EDMA_TCD_CH11_CSR_EARQ_MASK)

#define LPE_EDMA_TCD_CH11_CSR_EEI_MASK           (0x4U)
#define LPE_EDMA_TCD_CH11_CSR_EEI_SHIFT          (2U)
#define LPE_EDMA_TCD_CH11_CSR_EEI_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_CSR_EEI(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_CSR_EEI_SHIFT)) & LPE_EDMA_TCD_CH11_CSR_EEI_MASK)

#define LPE_EDMA_TCD_CH11_CSR_EBW_MASK           (0x8U)
#define LPE_EDMA_TCD_CH11_CSR_EBW_SHIFT          (3U)
#define LPE_EDMA_TCD_CH11_CSR_EBW_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_CSR_EBW(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_CSR_EBW_SHIFT)) & LPE_EDMA_TCD_CH11_CSR_EBW_MASK)

#define LPE_EDMA_TCD_CH11_CSR_DONE_MASK          (0x40000000U)
#define LPE_EDMA_TCD_CH11_CSR_DONE_SHIFT         (30U)
#define LPE_EDMA_TCD_CH11_CSR_DONE_WIDTH         (1U)
#define LPE_EDMA_TCD_CH11_CSR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_CSR_DONE_SHIFT)) & LPE_EDMA_TCD_CH11_CSR_DONE_MASK)

#define LPE_EDMA_TCD_CH11_CSR_ACTIVE_MASK        (0x80000000U)
#define LPE_EDMA_TCD_CH11_CSR_ACTIVE_SHIFT       (31U)
#define LPE_EDMA_TCD_CH11_CSR_ACTIVE_WIDTH       (1U)
#define LPE_EDMA_TCD_CH11_CSR_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_CSR_ACTIVE_SHIFT)) & LPE_EDMA_TCD_CH11_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH11_ES - Channel Error Status */
/*! @{ */

#define LPE_EDMA_TCD_CH11_ES_DBE_MASK            (0x1U)
#define LPE_EDMA_TCD_CH11_ES_DBE_SHIFT           (0U)
#define LPE_EDMA_TCD_CH11_ES_DBE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_DBE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_DBE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_DBE_MASK)

#define LPE_EDMA_TCD_CH11_ES_SBE_MASK            (0x2U)
#define LPE_EDMA_TCD_CH11_ES_SBE_SHIFT           (1U)
#define LPE_EDMA_TCD_CH11_ES_SBE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_SBE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_SBE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_SBE_MASK)

#define LPE_EDMA_TCD_CH11_ES_SGE_MASK            (0x4U)
#define LPE_EDMA_TCD_CH11_ES_SGE_SHIFT           (2U)
#define LPE_EDMA_TCD_CH11_ES_SGE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_SGE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_SGE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_SGE_MASK)

#define LPE_EDMA_TCD_CH11_ES_NCE_MASK            (0x8U)
#define LPE_EDMA_TCD_CH11_ES_NCE_SHIFT           (3U)
#define LPE_EDMA_TCD_CH11_ES_NCE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_NCE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_NCE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_NCE_MASK)

#define LPE_EDMA_TCD_CH11_ES_DOE_MASK            (0x10U)
#define LPE_EDMA_TCD_CH11_ES_DOE_SHIFT           (4U)
#define LPE_EDMA_TCD_CH11_ES_DOE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_DOE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_DOE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_DOE_MASK)

#define LPE_EDMA_TCD_CH11_ES_DAE_MASK            (0x20U)
#define LPE_EDMA_TCD_CH11_ES_DAE_SHIFT           (5U)
#define LPE_EDMA_TCD_CH11_ES_DAE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_DAE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_DAE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_DAE_MASK)

#define LPE_EDMA_TCD_CH11_ES_SOE_MASK            (0x40U)
#define LPE_EDMA_TCD_CH11_ES_SOE_SHIFT           (6U)
#define LPE_EDMA_TCD_CH11_ES_SOE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_SOE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_SOE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_SOE_MASK)

#define LPE_EDMA_TCD_CH11_ES_SAE_MASK            (0x80U)
#define LPE_EDMA_TCD_CH11_ES_SAE_SHIFT           (7U)
#define LPE_EDMA_TCD_CH11_ES_SAE_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_SAE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_SAE_SHIFT)) & LPE_EDMA_TCD_CH11_ES_SAE_MASK)

#define LPE_EDMA_TCD_CH11_ES_ERR_MASK            (0x80000000U)
#define LPE_EDMA_TCD_CH11_ES_ERR_SHIFT           (31U)
#define LPE_EDMA_TCD_CH11_ES_ERR_WIDTH           (1U)
#define LPE_EDMA_TCD_CH11_ES_ERR(x)              (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_ES_ERR_SHIFT)) & LPE_EDMA_TCD_CH11_ES_ERR_MASK)
/*! @} */

/*! @name CH11_INT - Channel Interrupt Status */
/*! @{ */

#define LPE_EDMA_TCD_CH11_INT_INT_MASK           (0x1U)
#define LPE_EDMA_TCD_CH11_INT_INT_SHIFT          (0U)
#define LPE_EDMA_TCD_CH11_INT_INT_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_INT_INT(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_INT_INT_SHIFT)) & LPE_EDMA_TCD_CH11_INT_INT_MASK)
/*! @} */

/*! @name CH11_SBR - Channel System Bus */
/*! @{ */

#define LPE_EDMA_TCD_CH11_SBR_MID_MASK           (0x3FU)
#define LPE_EDMA_TCD_CH11_SBR_MID_SHIFT          (0U)
#define LPE_EDMA_TCD_CH11_SBR_MID_WIDTH          (6U)
#define LPE_EDMA_TCD_CH11_SBR_MID(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_SBR_MID_SHIFT)) & LPE_EDMA_TCD_CH11_SBR_MID_MASK)

#define LPE_EDMA_TCD_CH11_SBR_PAL_MASK           (0x8000U)
#define LPE_EDMA_TCD_CH11_SBR_PAL_SHIFT          (15U)
#define LPE_EDMA_TCD_CH11_SBR_PAL_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_SBR_PAL(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_SBR_PAL_SHIFT)) & LPE_EDMA_TCD_CH11_SBR_PAL_MASK)

#define LPE_EDMA_TCD_CH11_SBR_EMI_MASK           (0x10000U)
#define LPE_EDMA_TCD_CH11_SBR_EMI_SHIFT          (16U)
#define LPE_EDMA_TCD_CH11_SBR_EMI_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_SBR_EMI(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_SBR_EMI_SHIFT)) & LPE_EDMA_TCD_CH11_SBR_EMI_MASK)

#define LPE_EDMA_TCD_CH11_SBR_ATTR_MASK          (0x20000U)
#define LPE_EDMA_TCD_CH11_SBR_ATTR_SHIFT         (17U)
#define LPE_EDMA_TCD_CH11_SBR_ATTR_WIDTH         (1U)
#define LPE_EDMA_TCD_CH11_SBR_ATTR(x)            (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_SBR_ATTR_SHIFT)) & LPE_EDMA_TCD_CH11_SBR_ATTR_MASK)
/*! @} */

/*! @name CH11_PRI - Channel Priority */
/*! @{ */

#define LPE_EDMA_TCD_CH11_PRI_APL_MASK           (0x7U)
#define LPE_EDMA_TCD_CH11_PRI_APL_SHIFT          (0U)
#define LPE_EDMA_TCD_CH11_PRI_APL_WIDTH          (3U)
#define LPE_EDMA_TCD_CH11_PRI_APL(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_PRI_APL_SHIFT)) & LPE_EDMA_TCD_CH11_PRI_APL_MASK)

#define LPE_EDMA_TCD_CH11_PRI_DPA_MASK           (0x40000000U)
#define LPE_EDMA_TCD_CH11_PRI_DPA_SHIFT          (30U)
#define LPE_EDMA_TCD_CH11_PRI_DPA_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_PRI_DPA(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_PRI_DPA_SHIFT)) & LPE_EDMA_TCD_CH11_PRI_DPA_MASK)

#define LPE_EDMA_TCD_CH11_PRI_ECP_MASK           (0x80000000U)
#define LPE_EDMA_TCD_CH11_PRI_ECP_SHIFT          (31U)
#define LPE_EDMA_TCD_CH11_PRI_ECP_WIDTH          (1U)
#define LPE_EDMA_TCD_CH11_PRI_ECP(x)             (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_CH11_PRI_ECP_SHIFT)) & LPE_EDMA_TCD_CH11_PRI_ECP_MASK)
/*! @} */

/*! @name TCD11_SADDR - TCD Source Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_SADDR_SADDR_MASK      (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD11_SADDR_SADDR_SHIFT     (0U)
#define LPE_EDMA_TCD_TCD11_SADDR_SADDR_WIDTH     (32U)
#define LPE_EDMA_TCD_TCD11_SADDR_SADDR(x)        (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_SADDR_SADDR_SHIFT)) & LPE_EDMA_TCD_TCD11_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD11_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_SOFF_SOFF_MASK        (0xFFFFU)
#define LPE_EDMA_TCD_TCD11_SOFF_SOFF_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD11_SOFF_SOFF_WIDTH       (16U)
#define LPE_EDMA_TCD_TCD11_SOFF_SOFF(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_SOFF_SOFF_SHIFT)) & LPE_EDMA_TCD_TCD11_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD11_ATTR - TCD Transfer Attributes */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_ATTR_DSIZE_MASK       (0x7U)
#define LPE_EDMA_TCD_TCD11_ATTR_DSIZE_SHIFT      (0U)
#define LPE_EDMA_TCD_TCD11_ATTR_DSIZE_WIDTH      (3U)
#define LPE_EDMA_TCD_TCD11_ATTR_DSIZE(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_ATTR_DSIZE_SHIFT)) & LPE_EDMA_TCD_TCD11_ATTR_DSIZE_MASK)

#define LPE_EDMA_TCD_TCD11_ATTR_DMOD_MASK        (0xF8U)
#define LPE_EDMA_TCD_TCD11_ATTR_DMOD_SHIFT       (3U)
#define LPE_EDMA_TCD_TCD11_ATTR_DMOD_WIDTH       (5U)
#define LPE_EDMA_TCD_TCD11_ATTR_DMOD(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_ATTR_DMOD_SHIFT)) & LPE_EDMA_TCD_TCD11_ATTR_DMOD_MASK)

#define LPE_EDMA_TCD_TCD11_ATTR_SSIZE_MASK       (0x700U)
#define LPE_EDMA_TCD_TCD11_ATTR_SSIZE_SHIFT      (8U)
#define LPE_EDMA_TCD_TCD11_ATTR_SSIZE_WIDTH      (3U)
#define LPE_EDMA_TCD_TCD11_ATTR_SSIZE(x)         (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_ATTR_SSIZE_SHIFT)) & LPE_EDMA_TCD_TCD11_ATTR_SSIZE_MASK)

#define LPE_EDMA_TCD_TCD11_ATTR_SMOD_MASK        (0xF800U)
#define LPE_EDMA_TCD_TCD11_ATTR_SMOD_SHIFT       (11U)
#define LPE_EDMA_TCD_TCD11_ATTR_SMOD_WIDTH       (5U)
#define LPE_EDMA_TCD_TCD11_ATTR_SMOD(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_ATTR_SMOD_SHIFT)) & LPE_EDMA_TCD_TCD11_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD11_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_MASK (0x3FFFFFFFU)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_WIDTH (30U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD11_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_MASK (0x3FFU)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_WIDTH (10U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_NBYTES_MASK)

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_MASK (0x3FFFFC00U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_SHIFT (10U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_WIDTH (20U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_MLOFF(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_MLOFF_MASK)

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_MASK (0x40000000U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_SHIFT (30U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_DMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_DMLOE_MASK)

#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_MASK (0x80000000U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_SHIFT (31U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_SMLOE(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_SHIFT)) & LPE_EDMA_TCD_TCD11_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD11_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_SLAST_SDA_SLAST_SDA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD11_SLAST_SDA_SLAST_SDA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_SLAST_SDA_SLAST_SDA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD11_SLAST_SDA_SLAST_SDA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_SLAST_SDA_SLAST_SDA_SHIFT)) & LPE_EDMA_TCD_TCD11_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD11_DADDR - TCD Destination Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_DADDR_DADDR_MASK      (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD11_DADDR_DADDR_SHIFT     (0U)
#define LPE_EDMA_TCD_TCD11_DADDR_DADDR_WIDTH     (32U)
#define LPE_EDMA_TCD_TCD11_DADDR_DADDR(x)        (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_DADDR_DADDR_SHIFT)) & LPE_EDMA_TCD_TCD11_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD11_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_DOFF_DOFF_MASK        (0xFFFFU)
#define LPE_EDMA_TCD_TCD11_DOFF_DOFF_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD11_DOFF_DOFF_WIDTH       (16U)
#define LPE_EDMA_TCD_TCD11_DOFF_DOFF(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_DOFF_DOFF_SHIFT)) & LPE_EDMA_TCD_TCD11_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD11_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_CITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_CITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CITER_ELINKNO_CITER_SHIFT)) & LPE_EDMA_TCD_TCD11_CITER_ELINKNO_CITER_MASK)

#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD11_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD11_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_CITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_CITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_CITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_CITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CITER_ELINKYES_CITER_SHIFT)) & LPE_EDMA_TCD_TCD11_CITER_ELINKYES_CITER_MASK)

#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD11_CITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_CITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD11_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD11_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_DLAST_SGA_DLAST_SGA_MASK (0xFFFFFFFFU)
#define LPE_EDMA_TCD_TCD11_DLAST_SGA_DLAST_SGA_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_DLAST_SGA_DLAST_SGA_WIDTH (32U)
#define LPE_EDMA_TCD_TCD11_DLAST_SGA_DLAST_SGA(x) (((uint32_t)(((uint32_t)(x)) << LPE_EDMA_TCD_TCD11_DLAST_SGA_DLAST_SGA_SHIFT)) & LPE_EDMA_TCD_TCD11_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD11_CSR - TCD Control and Status */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_CSR_START_MASK        (0x1U)
#define LPE_EDMA_TCD_TCD11_CSR_START_SHIFT       (0U)
#define LPE_EDMA_TCD_TCD11_CSR_START_WIDTH       (1U)
#define LPE_EDMA_TCD_TCD11_CSR_START(x)          (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_START_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_START_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_INTMAJOR_MASK     (0x2U)
#define LPE_EDMA_TCD_TCD11_CSR_INTMAJOR_SHIFT    (1U)
#define LPE_EDMA_TCD_TCD11_CSR_INTMAJOR_WIDTH    (1U)
#define LPE_EDMA_TCD_TCD11_CSR_INTMAJOR(x)       (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_INTMAJOR_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_INTMAJOR_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_INTHALF_MASK      (0x4U)
#define LPE_EDMA_TCD_TCD11_CSR_INTHALF_SHIFT     (2U)
#define LPE_EDMA_TCD_TCD11_CSR_INTHALF_WIDTH     (1U)
#define LPE_EDMA_TCD_TCD11_CSR_INTHALF(x)        (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_INTHALF_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_INTHALF_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_DREQ_MASK         (0x8U)
#define LPE_EDMA_TCD_TCD11_CSR_DREQ_SHIFT        (3U)
#define LPE_EDMA_TCD_TCD11_CSR_DREQ_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD11_CSR_DREQ(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_DREQ_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_DREQ_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_ESG_MASK          (0x10U)
#define LPE_EDMA_TCD_TCD11_CSR_ESG_SHIFT         (4U)
#define LPE_EDMA_TCD_TCD11_CSR_ESG_WIDTH         (1U)
#define LPE_EDMA_TCD_TCD11_CSR_ESG(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_ESG_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_ESG_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_MAJORELINK_MASK   (0x20U)
#define LPE_EDMA_TCD_TCD11_CSR_MAJORELINK_SHIFT  (5U)
#define LPE_EDMA_TCD_TCD11_CSR_MAJORELINK_WIDTH  (1U)
#define LPE_EDMA_TCD_TCD11_CSR_MAJORELINK(x)     (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_MAJORELINK_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_MAJORELINK_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_ESDA_MASK         (0x80U)
#define LPE_EDMA_TCD_TCD11_CSR_ESDA_SHIFT        (7U)
#define LPE_EDMA_TCD_TCD11_CSR_ESDA_WIDTH        (1U)
#define LPE_EDMA_TCD_TCD11_CSR_ESDA(x)           (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_ESDA_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_ESDA_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_MAJORLINKCH_MASK  (0xF00U)
#define LPE_EDMA_TCD_TCD11_CSR_MAJORLINKCH_SHIFT (8U)
#define LPE_EDMA_TCD_TCD11_CSR_MAJORLINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD11_CSR_MAJORLINKCH(x)    (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_MAJORLINKCH_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_MAJORLINKCH_MASK)

#define LPE_EDMA_TCD_TCD11_CSR_BWC_MASK          (0xC000U)
#define LPE_EDMA_TCD_TCD11_CSR_BWC_SHIFT         (14U)
#define LPE_EDMA_TCD_TCD11_CSR_BWC_WIDTH         (2U)
#define LPE_EDMA_TCD_TCD11_CSR_BWC(x)            (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_CSR_BWC_SHIFT)) & LPE_EDMA_TCD_TCD11_CSR_BWC_MASK)
/*! @} */

/*! @name TCD11_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_BITER_MASK (0x7FFFU)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_BITER_WIDTH (15U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_BITER_ELINKNO_BITER_SHIFT)) & LPE_EDMA_TCD_TCD11_BITER_ELINKNO_BITER_MASK)

#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKNO_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_BITER_ELINKNO_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD11_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD11_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_BITER_MASK (0x1FFU)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_BITER_SHIFT (0U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_BITER_WIDTH (9U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_BITER(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_BITER_ELINKYES_BITER_SHIFT)) & LPE_EDMA_TCD_TCD11_BITER_ELINKYES_BITER_MASK)

#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_LINKCH_MASK (0x1E00U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_LINKCH_SHIFT (9U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_LINKCH_WIDTH (4U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_LINKCH(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_BITER_ELINKYES_LINKCH_SHIFT)) & LPE_EDMA_TCD_TCD11_BITER_ELINKYES_LINKCH_MASK)

#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_ELINK_MASK (0x8000U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_ELINK_SHIFT (15U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_ELINK_WIDTH (1U)
#define LPE_EDMA_TCD_TCD11_BITER_ELINKYES_ELINK(x) (((uint16_t)(((uint16_t)(x)) << LPE_EDMA_TCD_TCD11_BITER_ELINKYES_ELINK_SHIFT)) & LPE_EDMA_TCD_TCD11_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPE_EDMA_TCD_Register_Masks */

/*!
 * @}
 */ /* end of group LPE_EDMA_TCD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LPE_EDMA_TCD_H_) */
