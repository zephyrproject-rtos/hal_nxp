/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMA
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
 * @file PERI_DMA.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_MP_GRPRI_COUNT                        32u
#define DMA_CH_COUNT                              12u

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Management Page Control, offset: 0x0 */
  __I  uint32_t ES;                                /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t INT;                               /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t HRS;                               /**< Management Page Hardware Request Status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[DMA_MP_GRPRI_COUNT];      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[16000];
  struct {                                         /* offset: 0x4000, array step: 0x4000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x4000, array step: 0x4000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x4004, array step: 0x4000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x4008, array step: 0x4000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0x400C, array step: 0x4000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x4010, array step: 0x4000 */
         uint8_t RESERVED_0[12];
    __IO uint32_t TCD_SADDR;                         /**< TCD Source Address, array offset: 0x4020, array step: 0x4000 */
    __IO uint16_t TCD_SOFF;                          /**< TCD Signed Source Address Offset, array offset: 0x4024, array step: 0x4000 */
    __IO uint16_t TCD_ATTR;                          /**< TCD Transfer Attributes, array offset: 0x4026, array step: 0x4000 */
    union {                                          /* offset: 0x4028, array step: 0x4000 */
      __IO uint32_t TCD_NBYTES_MLOFFNO;                /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x4028, array step: 0x4000 */
      __IO uint32_t TCD_NBYTES_MLOFFYES;               /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x4028, array step: 0x4000 */
    };
    __IO uint32_t TCD_SLAST_SDA;                     /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset: 0x402C, array step: 0x4000 */
    __IO uint32_t TCD_DADDR;                         /**< TCD Destination Address, array offset: 0x4030, array step: 0x4000 */
    __IO uint16_t TCD_DOFF;                          /**< TCD Signed Destination Address Offset, array offset: 0x4034, array step: 0x4000 */
    union {                                          /* offset: 0x4036, array step: 0x4000 */
      __IO uint16_t TCD_CITER_ELINKNO;                 /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x4036, array step: 0x4000 */
      __IO uint16_t TCD_CITER_ELINKYES;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x4036, array step: 0x4000 */
    };
    __IO uint32_t TCD_DLAST_SGA;                     /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array offset: 0x4038, array step: 0x4000 */
    __IO uint16_t TCD_CSR;                           /**< TCD Control and Status, array offset: 0x403C, array step: 0x4000 */
    union {                                          /* offset: 0x403E, array step: 0x4000 */
      __IO uint16_t TCD_BITER_ELINKNO;                 /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x403E, array step: 0x4000 */
      __IO uint16_t TCD_BITER_ELINKYES;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x403E, array step: 0x4000 */
    };
         uint8_t RESERVED_1[16320];
  } CH[DMA_CH_COUNT];
       uint8_t RESERVED_2[1900544];
  __IO uint32_t CH12_CSR;                          /**< Channel Control and Status, offset: 0x204000 */
  __IO uint32_t CH12_ES;                           /**< Channel Error Status, offset: 0x204004 */
  __IO uint32_t CH12_INT;                          /**< Channel Interrupt Status, offset: 0x204008 */
  __IO uint32_t CH12_SBR;                          /**< Channel System Bus, offset: 0x20400C */
  __IO uint32_t CH12_PRI;                          /**< Channel Priority, offset: 0x204010 */
       uint8_t RESERVED_3[12];
  __IO uint32_t TCD12_SADDR;                       /**< TCD Source Address, offset: 0x204020 */
  __IO uint16_t TCD12_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x204024 */
  __IO uint16_t TCD12_ATTR;                        /**< TCD Transfer Attributes, offset: 0x204026 */
  union {                                          /* offset: 0x204028 */
    __IO uint32_t TCD12_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x204028 */
    __IO uint32_t TCD12_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x204028 */
  };
  __IO uint32_t TCD12_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x20402C */
  __IO uint32_t TCD12_DADDR;                       /**< TCD Destination Address, offset: 0x204030 */
  __IO uint16_t TCD12_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x204034 */
  union {                                          /* offset: 0x204036 */
    __IO uint16_t TCD12_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x204036 */
    __IO uint16_t TCD12_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x204036 */
  };
  __IO uint32_t TCD12_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x204038 */
  __IO uint16_t TCD12_CSR;                         /**< TCD Control and Status, offset: 0x20403C */
  union {                                          /* offset: 0x20403E */
    __IO uint16_t TCD12_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x20403E */
    __IO uint16_t TCD12_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x20403E */
  };
       uint8_t RESERVED_4[16320];
  __IO uint32_t CH13_CSR;                          /**< Channel Control and Status, offset: 0x208000 */
  __IO uint32_t CH13_ES;                           /**< Channel Error Status, offset: 0x208004 */
  __IO uint32_t CH13_INT;                          /**< Channel Interrupt Status, offset: 0x208008 */
  __IO uint32_t CH13_SBR;                          /**< Channel System Bus, offset: 0x20800C */
  __IO uint32_t CH13_PRI;                          /**< Channel Priority, offset: 0x208010 */
       uint8_t RESERVED_5[12];
  __IO uint32_t TCD13_SADDR;                       /**< TCD Source Address, offset: 0x208020 */
  __IO uint16_t TCD13_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x208024 */
  __IO uint16_t TCD13_ATTR;                        /**< TCD Transfer Attributes, offset: 0x208026 */
  union {                                          /* offset: 0x208028 */
    __IO uint32_t TCD13_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x208028 */
    __IO uint32_t TCD13_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x208028 */
  };
  __IO uint32_t TCD13_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x20802C */
  __IO uint32_t TCD13_DADDR;                       /**< TCD Destination Address, offset: 0x208030 */
  __IO uint16_t TCD13_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x208034 */
  union {                                          /* offset: 0x208036 */
    __IO uint16_t TCD13_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x208036 */
    __IO uint16_t TCD13_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x208036 */
  };
  __IO uint32_t TCD13_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x208038 */
  __IO uint16_t TCD13_CSR;                         /**< TCD Control and Status, offset: 0x20803C */
  union {                                          /* offset: 0x20803E */
    __IO uint16_t TCD13_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x20803E */
    __IO uint16_t TCD13_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x20803E */
  };
       uint8_t RESERVED_6[16320];
  __IO uint32_t CH14_CSR;                          /**< Channel Control and Status, offset: 0x20C000 */
  __IO uint32_t CH14_ES;                           /**< Channel Error Status, offset: 0x20C004 */
  __IO uint32_t CH14_INT;                          /**< Channel Interrupt Status, offset: 0x20C008 */
  __IO uint32_t CH14_SBR;                          /**< Channel System Bus, offset: 0x20C00C */
  __IO uint32_t CH14_PRI;                          /**< Channel Priority, offset: 0x20C010 */
       uint8_t RESERVED_7[12];
  __IO uint32_t TCD14_SADDR;                       /**< TCD Source Address, offset: 0x20C020 */
  __IO uint16_t TCD14_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x20C024 */
  __IO uint16_t TCD14_ATTR;                        /**< TCD Transfer Attributes, offset: 0x20C026 */
  union {                                          /* offset: 0x20C028 */
    __IO uint32_t TCD14_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x20C028 */
    __IO uint32_t TCD14_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x20C028 */
  };
  __IO uint32_t TCD14_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x20C02C */
  __IO uint32_t TCD14_DADDR;                       /**< TCD Destination Address, offset: 0x20C030 */
  __IO uint16_t TCD14_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x20C034 */
  union {                                          /* offset: 0x20C036 */
    __IO uint16_t TCD14_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x20C036 */
    __IO uint16_t TCD14_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x20C036 */
  };
  __IO uint32_t TCD14_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x20C038 */
  __IO uint16_t TCD14_CSR;                         /**< TCD Control and Status, offset: 0x20C03C */
  union {                                          /* offset: 0x20C03E */
    __IO uint16_t TCD14_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x20C03E */
    __IO uint16_t TCD14_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x20C03E */
  };
       uint8_t RESERVED_8[16320];
  __IO uint32_t CH15_CSR;                          /**< Channel Control and Status, offset: 0x210000 */
  __IO uint32_t CH15_ES;                           /**< Channel Error Status, offset: 0x210004 */
  __IO uint32_t CH15_INT;                          /**< Channel Interrupt Status, offset: 0x210008 */
  __IO uint32_t CH15_SBR;                          /**< Channel System Bus, offset: 0x21000C */
  __IO uint32_t CH15_PRI;                          /**< Channel Priority, offset: 0x210010 */
       uint8_t RESERVED_9[12];
  __IO uint32_t TCD15_SADDR;                       /**< TCD Source Address, offset: 0x210020 */
  __IO uint16_t TCD15_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x210024 */
  __IO uint16_t TCD15_ATTR;                        /**< TCD Transfer Attributes, offset: 0x210026 */
  union {                                          /* offset: 0x210028 */
    __IO uint32_t TCD15_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x210028 */
    __IO uint32_t TCD15_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x210028 */
  };
  __IO uint32_t TCD15_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x21002C */
  __IO uint32_t TCD15_DADDR;                       /**< TCD Destination Address, offset: 0x210030 */
  __IO uint16_t TCD15_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x210034 */
  union {                                          /* offset: 0x210036 */
    __IO uint16_t TCD15_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x210036 */
    __IO uint16_t TCD15_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x210036 */
  };
  __IO uint32_t TCD15_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x210038 */
  __IO uint16_t TCD15_CSR;                         /**< TCD Control and Status, offset: 0x21003C */
  union {                                          /* offset: 0x21003E */
    __IO uint16_t TCD15_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x21003E */
    __IO uint16_t TCD15_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x21003E */
  };
       uint8_t RESERVED_10[16320];
  __IO uint32_t CH16_CSR;                          /**< Channel Control and Status, offset: 0x214000 */
  __IO uint32_t CH16_ES;                           /**< Channel Error Status, offset: 0x214004 */
  __IO uint32_t CH16_INT;                          /**< Channel Interrupt Status, offset: 0x214008 */
  __IO uint32_t CH16_SBR;                          /**< Channel System Bus, offset: 0x21400C */
  __IO uint32_t CH16_PRI;                          /**< Channel Priority, offset: 0x214010 */
       uint8_t RESERVED_11[12];
  __IO uint32_t TCD16_SADDR;                       /**< TCD Source Address, offset: 0x214020 */
  __IO uint16_t TCD16_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x214024 */
  __IO uint16_t TCD16_ATTR;                        /**< TCD Transfer Attributes, offset: 0x214026 */
  union {                                          /* offset: 0x214028 */
    __IO uint32_t TCD16_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x214028 */
    __IO uint32_t TCD16_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x214028 */
  };
  __IO uint32_t TCD16_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x21402C */
  __IO uint32_t TCD16_DADDR;                       /**< TCD Destination Address, offset: 0x214030 */
  __IO uint16_t TCD16_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x214034 */
  union {                                          /* offset: 0x214036 */
    __IO uint16_t TCD16_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x214036 */
    __IO uint16_t TCD16_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x214036 */
  };
  __IO uint32_t TCD16_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x214038 */
  __IO uint16_t TCD16_CSR;                         /**< TCD Control and Status, offset: 0x21403C */
  union {                                          /* offset: 0x21403E */
    __IO uint16_t TCD16_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x21403E */
    __IO uint16_t TCD16_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x21403E */
  };
       uint8_t RESERVED_12[16320];
  __IO uint32_t CH17_CSR;                          /**< Channel Control and Status, offset: 0x218000 */
  __IO uint32_t CH17_ES;                           /**< Channel Error Status, offset: 0x218004 */
  __IO uint32_t CH17_INT;                          /**< Channel Interrupt Status, offset: 0x218008 */
  __IO uint32_t CH17_SBR;                          /**< Channel System Bus, offset: 0x21800C */
  __IO uint32_t CH17_PRI;                          /**< Channel Priority, offset: 0x218010 */
       uint8_t RESERVED_13[12];
  __IO uint32_t TCD17_SADDR;                       /**< TCD Source Address, offset: 0x218020 */
  __IO uint16_t TCD17_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x218024 */
  __IO uint16_t TCD17_ATTR;                        /**< TCD Transfer Attributes, offset: 0x218026 */
  union {                                          /* offset: 0x218028 */
    __IO uint32_t TCD17_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x218028 */
    __IO uint32_t TCD17_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x218028 */
  };
  __IO uint32_t TCD17_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x21802C */
  __IO uint32_t TCD17_DADDR;                       /**< TCD Destination Address, offset: 0x218030 */
  __IO uint16_t TCD17_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x218034 */
  union {                                          /* offset: 0x218036 */
    __IO uint16_t TCD17_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x218036 */
    __IO uint16_t TCD17_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x218036 */
  };
  __IO uint32_t TCD17_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x218038 */
  __IO uint16_t TCD17_CSR;                         /**< TCD Control and Status, offset: 0x21803C */
  union {                                          /* offset: 0x21803E */
    __IO uint16_t TCD17_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x21803E */
    __IO uint16_t TCD17_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x21803E */
  };
       uint8_t RESERVED_14[16320];
  __IO uint32_t CH18_CSR;                          /**< Channel Control and Status, offset: 0x21C000 */
  __IO uint32_t CH18_ES;                           /**< Channel Error Status, offset: 0x21C004 */
  __IO uint32_t CH18_INT;                          /**< Channel Interrupt Status, offset: 0x21C008 */
  __IO uint32_t CH18_SBR;                          /**< Channel System Bus, offset: 0x21C00C */
  __IO uint32_t CH18_PRI;                          /**< Channel Priority, offset: 0x21C010 */
       uint8_t RESERVED_15[12];
  __IO uint32_t TCD18_SADDR;                       /**< TCD Source Address, offset: 0x21C020 */
  __IO uint16_t TCD18_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x21C024 */
  __IO uint16_t TCD18_ATTR;                        /**< TCD Transfer Attributes, offset: 0x21C026 */
  union {                                          /* offset: 0x21C028 */
    __IO uint32_t TCD18_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x21C028 */
    __IO uint32_t TCD18_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x21C028 */
  };
  __IO uint32_t TCD18_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x21C02C */
  __IO uint32_t TCD18_DADDR;                       /**< TCD Destination Address, offset: 0x21C030 */
  __IO uint16_t TCD18_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x21C034 */
  union {                                          /* offset: 0x21C036 */
    __IO uint16_t TCD18_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x21C036 */
    __IO uint16_t TCD18_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x21C036 */
  };
  __IO uint32_t TCD18_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x21C038 */
  __IO uint16_t TCD18_CSR;                         /**< TCD Control and Status, offset: 0x21C03C */
  union {                                          /* offset: 0x21C03E */
    __IO uint16_t TCD18_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x21C03E */
    __IO uint16_t TCD18_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x21C03E */
  };
       uint8_t RESERVED_16[16320];
  __IO uint32_t CH19_CSR;                          /**< Channel Control and Status, offset: 0x220000 */
  __IO uint32_t CH19_ES;                           /**< Channel Error Status, offset: 0x220004 */
  __IO uint32_t CH19_INT;                          /**< Channel Interrupt Status, offset: 0x220008 */
  __IO uint32_t CH19_SBR;                          /**< Channel System Bus, offset: 0x22000C */
  __IO uint32_t CH19_PRI;                          /**< Channel Priority, offset: 0x220010 */
       uint8_t RESERVED_17[12];
  __IO uint32_t TCD19_SADDR;                       /**< TCD Source Address, offset: 0x220020 */
  __IO uint16_t TCD19_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x220024 */
  __IO uint16_t TCD19_ATTR;                        /**< TCD Transfer Attributes, offset: 0x220026 */
  union {                                          /* offset: 0x220028 */
    __IO uint32_t TCD19_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x220028 */
    __IO uint32_t TCD19_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x220028 */
  };
  __IO uint32_t TCD19_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x22002C */
  __IO uint32_t TCD19_DADDR;                       /**< TCD Destination Address, offset: 0x220030 */
  __IO uint16_t TCD19_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x220034 */
  union {                                          /* offset: 0x220036 */
    __IO uint16_t TCD19_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x220036 */
    __IO uint16_t TCD19_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x220036 */
  };
  __IO uint32_t TCD19_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x220038 */
  __IO uint16_t TCD19_CSR;                         /**< TCD Control and Status, offset: 0x22003C */
  union {                                          /* offset: 0x22003E */
    __IO uint16_t TCD19_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x22003E */
    __IO uint16_t TCD19_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x22003E */
  };
       uint8_t RESERVED_18[16320];
  __IO uint32_t CH20_CSR;                          /**< Channel Control and Status, offset: 0x224000 */
  __IO uint32_t CH20_ES;                           /**< Channel Error Status, offset: 0x224004 */
  __IO uint32_t CH20_INT;                          /**< Channel Interrupt Status, offset: 0x224008 */
  __IO uint32_t CH20_SBR;                          /**< Channel System Bus, offset: 0x22400C */
  __IO uint32_t CH20_PRI;                          /**< Channel Priority, offset: 0x224010 */
       uint8_t RESERVED_19[12];
  __IO uint32_t TCD20_SADDR;                       /**< TCD Source Address, offset: 0x224020 */
  __IO uint16_t TCD20_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x224024 */
  __IO uint16_t TCD20_ATTR;                        /**< TCD Transfer Attributes, offset: 0x224026 */
  union {                                          /* offset: 0x224028 */
    __IO uint32_t TCD20_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x224028 */
    __IO uint32_t TCD20_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x224028 */
  };
  __IO uint32_t TCD20_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x22402C */
  __IO uint32_t TCD20_DADDR;                       /**< TCD Destination Address, offset: 0x224030 */
  __IO uint16_t TCD20_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x224034 */
  union {                                          /* offset: 0x224036 */
    __IO uint16_t TCD20_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x224036 */
    __IO uint16_t TCD20_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x224036 */
  };
  __IO uint32_t TCD20_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x224038 */
  __IO uint16_t TCD20_CSR;                         /**< TCD Control and Status, offset: 0x22403C */
  union {                                          /* offset: 0x22403E */
    __IO uint16_t TCD20_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x22403E */
    __IO uint16_t TCD20_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x22403E */
  };
       uint8_t RESERVED_20[16320];
  __IO uint32_t CH21_CSR;                          /**< Channel Control and Status, offset: 0x228000 */
  __IO uint32_t CH21_ES;                           /**< Channel Error Status, offset: 0x228004 */
  __IO uint32_t CH21_INT;                          /**< Channel Interrupt Status, offset: 0x228008 */
  __IO uint32_t CH21_SBR;                          /**< Channel System Bus, offset: 0x22800C */
  __IO uint32_t CH21_PRI;                          /**< Channel Priority, offset: 0x228010 */
       uint8_t RESERVED_21[12];
  __IO uint32_t TCD21_SADDR;                       /**< TCD Source Address, offset: 0x228020 */
  __IO uint16_t TCD21_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x228024 */
  __IO uint16_t TCD21_ATTR;                        /**< TCD Transfer Attributes, offset: 0x228026 */
  union {                                          /* offset: 0x228028 */
    __IO uint32_t TCD21_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x228028 */
    __IO uint32_t TCD21_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x228028 */
  };
  __IO uint32_t TCD21_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x22802C */
  __IO uint32_t TCD21_DADDR;                       /**< TCD Destination Address, offset: 0x228030 */
  __IO uint16_t TCD21_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x228034 */
  union {                                          /* offset: 0x228036 */
    __IO uint16_t TCD21_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x228036 */
    __IO uint16_t TCD21_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x228036 */
  };
  __IO uint32_t TCD21_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x228038 */
  __IO uint16_t TCD21_CSR;                         /**< TCD Control and Status, offset: 0x22803C */
  union {                                          /* offset: 0x22803E */
    __IO uint16_t TCD21_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x22803E */
    __IO uint16_t TCD21_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x22803E */
  };
       uint8_t RESERVED_22[16320];
  __IO uint32_t CH22_CSR;                          /**< Channel Control and Status, offset: 0x22C000 */
  __IO uint32_t CH22_ES;                           /**< Channel Error Status, offset: 0x22C004 */
  __IO uint32_t CH22_INT;                          /**< Channel Interrupt Status, offset: 0x22C008 */
  __IO uint32_t CH22_SBR;                          /**< Channel System Bus, offset: 0x22C00C */
  __IO uint32_t CH22_PRI;                          /**< Channel Priority, offset: 0x22C010 */
       uint8_t RESERVED_23[12];
  __IO uint32_t TCD22_SADDR;                       /**< TCD Source Address, offset: 0x22C020 */
  __IO uint16_t TCD22_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x22C024 */
  __IO uint16_t TCD22_ATTR;                        /**< TCD Transfer Attributes, offset: 0x22C026 */
  union {                                          /* offset: 0x22C028 */
    __IO uint32_t TCD22_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x22C028 */
    __IO uint32_t TCD22_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x22C028 */
  };
  __IO uint32_t TCD22_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x22C02C */
  __IO uint32_t TCD22_DADDR;                       /**< TCD Destination Address, offset: 0x22C030 */
  __IO uint16_t TCD22_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x22C034 */
  union {                                          /* offset: 0x22C036 */
    __IO uint16_t TCD22_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x22C036 */
    __IO uint16_t TCD22_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x22C036 */
  };
  __IO uint32_t TCD22_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x22C038 */
  __IO uint16_t TCD22_CSR;                         /**< TCD Control and Status, offset: 0x22C03C */
  union {                                          /* offset: 0x22C03E */
    __IO uint16_t TCD22_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x22C03E */
    __IO uint16_t TCD22_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x22C03E */
  };
       uint8_t RESERVED_24[16320];
  __IO uint32_t CH23_CSR;                          /**< Channel Control and Status, offset: 0x230000 */
  __IO uint32_t CH23_ES;                           /**< Channel Error Status, offset: 0x230004 */
  __IO uint32_t CH23_INT;                          /**< Channel Interrupt Status, offset: 0x230008 */
  __IO uint32_t CH23_SBR;                          /**< Channel System Bus, offset: 0x23000C */
  __IO uint32_t CH23_PRI;                          /**< Channel Priority, offset: 0x230010 */
       uint8_t RESERVED_25[12];
  __IO uint32_t TCD23_SADDR;                       /**< TCD Source Address, offset: 0x230020 */
  __IO uint16_t TCD23_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x230024 */
  __IO uint16_t TCD23_ATTR;                        /**< TCD Transfer Attributes, offset: 0x230026 */
  union {                                          /* offset: 0x230028 */
    __IO uint32_t TCD23_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x230028 */
    __IO uint32_t TCD23_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x230028 */
  };
  __IO uint32_t TCD23_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x23002C */
  __IO uint32_t TCD23_DADDR;                       /**< TCD Destination Address, offset: 0x230030 */
  __IO uint16_t TCD23_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x230034 */
  union {                                          /* offset: 0x230036 */
    __IO uint16_t TCD23_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x230036 */
    __IO uint16_t TCD23_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x230036 */
  };
  __IO uint32_t TCD23_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x230038 */
  __IO uint16_t TCD23_CSR;                         /**< TCD Control and Status, offset: 0x23003C */
  union {                                          /* offset: 0x23003E */
    __IO uint16_t TCD23_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x23003E */
    __IO uint16_t TCD23_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x23003E */
  };
       uint8_t RESERVED_26[16320];
  __IO uint32_t CH24_CSR;                          /**< Channel Control and Status, offset: 0x234000 */
  __IO uint32_t CH24_ES;                           /**< Channel Error Status, offset: 0x234004 */
  __IO uint32_t CH24_INT;                          /**< Channel Interrupt Status, offset: 0x234008 */
  __IO uint32_t CH24_SBR;                          /**< Channel System Bus, offset: 0x23400C */
  __IO uint32_t CH24_PRI;                          /**< Channel Priority, offset: 0x234010 */
       uint8_t RESERVED_27[12];
  __IO uint32_t TCD24_SADDR;                       /**< TCD Source Address, offset: 0x234020 */
  __IO uint16_t TCD24_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x234024 */
  __IO uint16_t TCD24_ATTR;                        /**< TCD Transfer Attributes, offset: 0x234026 */
  union {                                          /* offset: 0x234028 */
    __IO uint32_t TCD24_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x234028 */
    __IO uint32_t TCD24_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x234028 */
  };
  __IO uint32_t TCD24_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x23402C */
  __IO uint32_t TCD24_DADDR;                       /**< TCD Destination Address, offset: 0x234030 */
  __IO uint16_t TCD24_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x234034 */
  union {                                          /* offset: 0x234036 */
    __IO uint16_t TCD24_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x234036 */
    __IO uint16_t TCD24_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x234036 */
  };
  __IO uint32_t TCD24_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x234038 */
  __IO uint16_t TCD24_CSR;                         /**< TCD Control and Status, offset: 0x23403C */
  union {                                          /* offset: 0x23403E */
    __IO uint16_t TCD24_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x23403E */
    __IO uint16_t TCD24_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x23403E */
  };
       uint8_t RESERVED_28[16320];
  __IO uint32_t CH25_CSR;                          /**< Channel Control and Status, offset: 0x238000 */
  __IO uint32_t CH25_ES;                           /**< Channel Error Status, offset: 0x238004 */
  __IO uint32_t CH25_INT;                          /**< Channel Interrupt Status, offset: 0x238008 */
  __IO uint32_t CH25_SBR;                          /**< Channel System Bus, offset: 0x23800C */
  __IO uint32_t CH25_PRI;                          /**< Channel Priority, offset: 0x238010 */
       uint8_t RESERVED_29[12];
  __IO uint32_t TCD25_SADDR;                       /**< TCD Source Address, offset: 0x238020 */
  __IO uint16_t TCD25_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x238024 */
  __IO uint16_t TCD25_ATTR;                        /**< TCD Transfer Attributes, offset: 0x238026 */
  union {                                          /* offset: 0x238028 */
    __IO uint32_t TCD25_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x238028 */
    __IO uint32_t TCD25_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x238028 */
  };
  __IO uint32_t TCD25_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x23802C */
  __IO uint32_t TCD25_DADDR;                       /**< TCD Destination Address, offset: 0x238030 */
  __IO uint16_t TCD25_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x238034 */
  union {                                          /* offset: 0x238036 */
    __IO uint16_t TCD25_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x238036 */
    __IO uint16_t TCD25_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x238036 */
  };
  __IO uint32_t TCD25_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x238038 */
  __IO uint16_t TCD25_CSR;                         /**< TCD Control and Status, offset: 0x23803C */
  union {                                          /* offset: 0x23803E */
    __IO uint16_t TCD25_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x23803E */
    __IO uint16_t TCD25_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x23803E */
  };
       uint8_t RESERVED_30[16320];
  __IO uint32_t CH26_CSR;                          /**< Channel Control and Status, offset: 0x23C000 */
  __IO uint32_t CH26_ES;                           /**< Channel Error Status, offset: 0x23C004 */
  __IO uint32_t CH26_INT;                          /**< Channel Interrupt Status, offset: 0x23C008 */
  __IO uint32_t CH26_SBR;                          /**< Channel System Bus, offset: 0x23C00C */
  __IO uint32_t CH26_PRI;                          /**< Channel Priority, offset: 0x23C010 */
       uint8_t RESERVED_31[12];
  __IO uint32_t TCD26_SADDR;                       /**< TCD Source Address, offset: 0x23C020 */
  __IO uint16_t TCD26_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x23C024 */
  __IO uint16_t TCD26_ATTR;                        /**< TCD Transfer Attributes, offset: 0x23C026 */
  union {                                          /* offset: 0x23C028 */
    __IO uint32_t TCD26_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x23C028 */
    __IO uint32_t TCD26_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x23C028 */
  };
  __IO uint32_t TCD26_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x23C02C */
  __IO uint32_t TCD26_DADDR;                       /**< TCD Destination Address, offset: 0x23C030 */
  __IO uint16_t TCD26_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x23C034 */
  union {                                          /* offset: 0x23C036 */
    __IO uint16_t TCD26_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x23C036 */
    __IO uint16_t TCD26_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x23C036 */
  };
  __IO uint32_t TCD26_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x23C038 */
  __IO uint16_t TCD26_CSR;                         /**< TCD Control and Status, offset: 0x23C03C */
  union {                                          /* offset: 0x23C03E */
    __IO uint16_t TCD26_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x23C03E */
    __IO uint16_t TCD26_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x23C03E */
  };
       uint8_t RESERVED_32[16320];
  __IO uint32_t CH27_CSR;                          /**< Channel Control and Status, offset: 0x240000 */
  __IO uint32_t CH27_ES;                           /**< Channel Error Status, offset: 0x240004 */
  __IO uint32_t CH27_INT;                          /**< Channel Interrupt Status, offset: 0x240008 */
  __IO uint32_t CH27_SBR;                          /**< Channel System Bus, offset: 0x24000C */
  __IO uint32_t CH27_PRI;                          /**< Channel Priority, offset: 0x240010 */
       uint8_t RESERVED_33[12];
  __IO uint32_t TCD27_SADDR;                       /**< TCD Source Address, offset: 0x240020 */
  __IO uint16_t TCD27_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x240024 */
  __IO uint16_t TCD27_ATTR;                        /**< TCD Transfer Attributes, offset: 0x240026 */
  union {                                          /* offset: 0x240028 */
    __IO uint32_t TCD27_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x240028 */
    __IO uint32_t TCD27_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x240028 */
  };
  __IO uint32_t TCD27_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x24002C */
  __IO uint32_t TCD27_DADDR;                       /**< TCD Destination Address, offset: 0x240030 */
  __IO uint16_t TCD27_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x240034 */
  union {                                          /* offset: 0x240036 */
    __IO uint16_t TCD27_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x240036 */
    __IO uint16_t TCD27_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x240036 */
  };
  __IO uint32_t TCD27_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x240038 */
  __IO uint16_t TCD27_CSR;                         /**< TCD Control and Status, offset: 0x24003C */
  union {                                          /* offset: 0x24003E */
    __IO uint16_t TCD27_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x24003E */
    __IO uint16_t TCD27_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x24003E */
  };
       uint8_t RESERVED_34[16320];
  __IO uint32_t CH28_CSR;                          /**< Channel Control and Status, offset: 0x244000 */
  __IO uint32_t CH28_ES;                           /**< Channel Error Status, offset: 0x244004 */
  __IO uint32_t CH28_INT;                          /**< Channel Interrupt Status, offset: 0x244008 */
  __IO uint32_t CH28_SBR;                          /**< Channel System Bus, offset: 0x24400C */
  __IO uint32_t CH28_PRI;                          /**< Channel Priority, offset: 0x244010 */
       uint8_t RESERVED_35[12];
  __IO uint32_t TCD28_SADDR;                       /**< TCD Source Address, offset: 0x244020 */
  __IO uint16_t TCD28_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x244024 */
  __IO uint16_t TCD28_ATTR;                        /**< TCD Transfer Attributes, offset: 0x244026 */
  union {                                          /* offset: 0x244028 */
    __IO uint32_t TCD28_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x244028 */
    __IO uint32_t TCD28_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x244028 */
  };
  __IO uint32_t TCD28_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x24402C */
  __IO uint32_t TCD28_DADDR;                       /**< TCD Destination Address, offset: 0x244030 */
  __IO uint16_t TCD28_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x244034 */
  union {                                          /* offset: 0x244036 */
    __IO uint16_t TCD28_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x244036 */
    __IO uint16_t TCD28_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x244036 */
  };
  __IO uint32_t TCD28_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x244038 */
  __IO uint16_t TCD28_CSR;                         /**< TCD Control and Status, offset: 0x24403C */
  union {                                          /* offset: 0x24403E */
    __IO uint16_t TCD28_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x24403E */
    __IO uint16_t TCD28_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x24403E */
  };
       uint8_t RESERVED_36[16320];
  __IO uint32_t CH29_CSR;                          /**< Channel Control and Status, offset: 0x248000 */
  __IO uint32_t CH29_ES;                           /**< Channel Error Status, offset: 0x248004 */
  __IO uint32_t CH29_INT;                          /**< Channel Interrupt Status, offset: 0x248008 */
  __IO uint32_t CH29_SBR;                          /**< Channel System Bus, offset: 0x24800C */
  __IO uint32_t CH29_PRI;                          /**< Channel Priority, offset: 0x248010 */
       uint8_t RESERVED_37[12];
  __IO uint32_t TCD29_SADDR;                       /**< TCD Source Address, offset: 0x248020 */
  __IO uint16_t TCD29_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x248024 */
  __IO uint16_t TCD29_ATTR;                        /**< TCD Transfer Attributes, offset: 0x248026 */
  union {                                          /* offset: 0x248028 */
    __IO uint32_t TCD29_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x248028 */
    __IO uint32_t TCD29_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x248028 */
  };
  __IO uint32_t TCD29_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x24802C */
  __IO uint32_t TCD29_DADDR;                       /**< TCD Destination Address, offset: 0x248030 */
  __IO uint16_t TCD29_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x248034 */
  union {                                          /* offset: 0x248036 */
    __IO uint16_t TCD29_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x248036 */
    __IO uint16_t TCD29_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x248036 */
  };
  __IO uint32_t TCD29_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x248038 */
  __IO uint16_t TCD29_CSR;                         /**< TCD Control and Status, offset: 0x24803C */
  union {                                          /* offset: 0x24803E */
    __IO uint16_t TCD29_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x24803E */
    __IO uint16_t TCD29_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x24803E */
  };
       uint8_t RESERVED_38[16320];
  __IO uint32_t CH30_CSR;                          /**< Channel Control and Status, offset: 0x24C000 */
  __IO uint32_t CH30_ES;                           /**< Channel Error Status, offset: 0x24C004 */
  __IO uint32_t CH30_INT;                          /**< Channel Interrupt Status, offset: 0x24C008 */
  __IO uint32_t CH30_SBR;                          /**< Channel System Bus, offset: 0x24C00C */
  __IO uint32_t CH30_PRI;                          /**< Channel Priority, offset: 0x24C010 */
       uint8_t RESERVED_39[12];
  __IO uint32_t TCD30_SADDR;                       /**< TCD Source Address, offset: 0x24C020 */
  __IO uint16_t TCD30_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x24C024 */
  __IO uint16_t TCD30_ATTR;                        /**< TCD Transfer Attributes, offset: 0x24C026 */
  union {                                          /* offset: 0x24C028 */
    __IO uint32_t TCD30_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x24C028 */
    __IO uint32_t TCD30_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x24C028 */
  };
  __IO uint32_t TCD30_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x24C02C */
  __IO uint32_t TCD30_DADDR;                       /**< TCD Destination Address, offset: 0x24C030 */
  __IO uint16_t TCD30_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x24C034 */
  union {                                          /* offset: 0x24C036 */
    __IO uint16_t TCD30_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x24C036 */
    __IO uint16_t TCD30_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x24C036 */
  };
  __IO uint32_t TCD30_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x24C038 */
  __IO uint16_t TCD30_CSR;                         /**< TCD Control and Status, offset: 0x24C03C */
  union {                                          /* offset: 0x24C03E */
    __IO uint16_t TCD30_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x24C03E */
    __IO uint16_t TCD30_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x24C03E */
  };
       uint8_t RESERVED_40[16320];
  __IO uint32_t CH31_CSR;                          /**< Channel Control and Status, offset: 0x250000 */
  __IO uint32_t CH31_ES;                           /**< Channel Error Status, offset: 0x250004 */
  __IO uint32_t CH31_INT;                          /**< Channel Interrupt Status, offset: 0x250008 */
  __IO uint32_t CH31_SBR;                          /**< Channel System Bus, offset: 0x25000C */
  __IO uint32_t CH31_PRI;                          /**< Channel Priority, offset: 0x250010 */
       uint8_t RESERVED_41[12];
  __IO uint32_t TCD31_SADDR;                       /**< TCD Source Address, offset: 0x250020 */
  __IO uint16_t TCD31_SOFF;                        /**< TCD Signed Source Address Offset, offset: 0x250024 */
  __IO uint16_t TCD31_ATTR;                        /**< TCD Transfer Attributes, offset: 0x250026 */
  union {                                          /* offset: 0x250028 */
    __IO uint32_t TCD31_NBYTES_MLOFFNO;              /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x250028 */
    __IO uint32_t TCD31_NBYTES_MLOFFYES;             /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x250028 */
  };
  __IO uint32_t TCD31_SLAST_SDA;                   /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x25002C */
  __IO uint32_t TCD31_DADDR;                       /**< TCD Destination Address, offset: 0x250030 */
  __IO uint16_t TCD31_DOFF;                        /**< TCD Signed Destination Address Offset, offset: 0x250034 */
  union {                                          /* offset: 0x250036 */
    __IO uint16_t TCD31_CITER_ELINKNO;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x250036 */
    __IO uint16_t TCD31_CITER_ELINKYES;              /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x250036 */
  };
  __IO uint32_t TCD31_DLAST_SGA;                   /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x250038 */
  __IO uint16_t TCD31_CSR;                         /**< TCD Control and Status, offset: 0x25003C */
  union {                                          /* offset: 0x25003E */
    __IO uint16_t TCD31_BITER_ELINKNO;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x25003E */
    __IO uint16_t TCD31_BITER_ELINKYES;              /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x25003E */
  };
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name CSR - Management Page Control */
/*! @{ */

#define DMA_CSR_EDBG_MASK                        (0x2U)
#define DMA_CSR_EDBG_SHIFT                       (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode disabled
 *  0b1..Debug mode is enabled.
 */
#define DMA_CSR_EDBG(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CSR_EDBG_SHIFT)) & DMA_CSR_EDBG_MASK)

#define DMA_CSR_ERCA_MASK                        (0x4U)
#define DMA_CSR_ERCA_SHIFT                       (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round-robin channel arbitration disabled
 *  0b1..Round-robin channel arbitration enabled
 */
#define DMA_CSR_ERCA(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CSR_ERCA_SHIFT)) & DMA_CSR_ERCA_MASK)

#define DMA_CSR_HAE_MASK                         (0x10U)
#define DMA_CSR_HAE_SHIFT                        (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT field to be set to 1
 */
#define DMA_CSR_HAE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CSR_HAE_SHIFT)) & DMA_CSR_HAE_MASK)

#define DMA_CSR_HALT_MASK                        (0x20U)
#define DMA_CSR_HALT_SHIFT                       (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels
 */
#define DMA_CSR_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CSR_HALT_SHIFT)) & DMA_CSR_HALT_MASK)

#define DMA_CSR_GCLC_MASK                        (0x40U)
#define DMA_CSR_GCLC_SHIFT                       (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking disabled for all channels
 *  0b1..Channel linking available and controlled by each channel's link settings
 */
#define DMA_CSR_GCLC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CSR_GCLC_SHIFT)) & DMA_CSR_GCLC_MASK)

#define DMA_CSR_GMRC_MASK                        (0x80U)
#define DMA_CSR_GMRC_SHIFT                       (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication disabled for all channels
 *  0b1..Master ID replication available and controlled by each channel's CHn_SBR[EMI] setting
 */
#define DMA_CSR_GMRC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_CSR_GMRC_SHIFT)) & DMA_CSR_GMRC_MASK)

#define DMA_CSR_ECX_MASK                         (0x100U)
#define DMA_CSR_ECX_SHIFT                        (8U)
/*! ECX - Cancel Transfer With Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_CSR_ECX(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CSR_ECX_SHIFT)) & DMA_CSR_ECX_MASK)

#define DMA_CSR_CX_MASK                          (0x200U)
#define DMA_CSR_CX_SHIFT                         (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_CSR_CX(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_CSR_CX_SHIFT)) & DMA_CSR_CX_MASK)

#define DMA_CSR_ACTIVE_ID_MASK                   (0x1F000000U)
#define DMA_CSR_ACTIVE_ID_SHIFT                  (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA_CSR_ACTIVE_ID(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CSR_ACTIVE_ID_SHIFT)) & DMA_CSR_ACTIVE_ID_MASK)

#define DMA_CSR_ACTIVE_MASK                      (0x80000000U)
#define DMA_CSR_ACTIVE_SHIFT                     (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle
 *  0b1..eDMA is executing a channel
 */
#define DMA_CSR_ACTIVE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CSR_ACTIVE_SHIFT)) & DMA_CSR_ACTIVE_MASK)
/*! @} */

/*! @name ES - Management Page Error Status */
/*! @{ */

#define DMA_ES_DBE_MASK                          (0x1U)
#define DMA_ES_DBE_SHIFT                         (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was a bus error on a destination write
 */
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_DBE_SHIFT)) & DMA_ES_DBE_MASK)

#define DMA_ES_SBE_MASK                          (0x2U)
#define DMA_ES_SBE_SHIFT                         (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was a bus error on a source read
 */
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SBE_SHIFT)) & DMA_ES_SBE_MASK)

#define DMA_ES_SGE_MASK                          (0x4U)
#define DMA_ES_SGE_SHIFT                         (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SGE_SHIFT)) & DMA_ES_SGE_MASK)

#define DMA_ES_NCE_MASK                          (0x8U)
#define DMA_ES_NCE_SHIFT                         (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_NCE_SHIFT)) & DMA_ES_NCE_MASK)

#define DMA_ES_DOE_MASK                          (0x10U)
#define DMA_ES_DOE_SHIFT                         (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_DOE_SHIFT)) & DMA_ES_DOE_MASK)

#define DMA_ES_DAE_MASK                          (0x20U)
#define DMA_ES_DAE_SHIFT                         (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_DAE_SHIFT)) & DMA_ES_DAE_MASK)

#define DMA_ES_SOE_MASK                          (0x40U)
#define DMA_ES_SOE_SHIFT                         (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SOE_SHIFT)) & DMA_ES_SOE_MASK)

#define DMA_ES_SAE_MASK                          (0x80U)
#define DMA_ES_SAE_SHIFT                         (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SAE_SHIFT)) & DMA_ES_SAE_MASK)

#define DMA_ES_ECX_MASK                          (0x100U)
#define DMA_ES_ECX_SHIFT                         (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_ECX_SHIFT)) & DMA_ES_ECX_MASK)

#define DMA_ES_UCE_MASK                          (0x200U)
#define DMA_ES_UCE_SHIFT                         (9U)
/*! UCE - Uncorrectable TCD Error During Channel Execution
 *  0b0..No uncorrectable ECC error
 *  0b1..Last recorded error was an uncorrectable TCD RAM error
 */
#define DMA_ES_UCE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_UCE_SHIFT)) & DMA_ES_UCE_MASK)

#define DMA_ES_ERRCHN_MASK                       (0x1F000000U)
#define DMA_ES_ERRCHN_SHIFT                      (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ES_ERRCHN_SHIFT)) & DMA_ES_ERRCHN_MASK)

#define DMA_ES_VLD_MASK                          (0x80000000U)
#define DMA_ES_VLD_SHIFT                         (31U)
/*! VLD - Valid
 *  0b0..No ERR fields are set to 1
 *  0b1..At least one ERR field is set to 1, indicating a valid error exists that software has not cleared
 */
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_VLD_SHIFT)) & DMA_ES_VLD_MASK)
/*! @} */

/*! @name INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_INT_INT_MASK                         (0xFFFFFFFFU)
#define DMA_INT_INT_SHIFT                        (0U)
/*! INT - Interrupt Request Status */
#define DMA_INT_INT(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT_SHIFT)) & DMA_INT_INT_MASK)
/*! @} */

/*! @name HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_HRS_HRS_MASK                         (0xFFFFFFFFU)
#define DMA_HRS_HRS_SHIFT                        (0U)
/*! HRS - Hardware Request Status */
#define DMA_HRS_HRS(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS_SHIFT)) & DMA_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK                  (0x1FU)
#define DMA_CH_GRPRI_GRPRI_SHIFT                 (0U)
/*! GRPRI - Arbitration Group For Channel n */
#define DMA_CH_GRPRI_GRPRI(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CH_GRPRI_GRPRI_SHIFT)) & DMA_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA_CH_GRPRI */
#define DMA_CH_GRPRI_COUNT                       (32U)

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH_CSR_ERQ_MASK                      (0x1U)
#define DMA_CH_CSR_ERQ_SHIFT                     (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH_CSR_ERQ(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ERQ_SHIFT)) & DMA_CH_CSR_ERQ_MASK)

#define DMA_CH_CSR_EARQ_MASK                     (0x2U)
#define DMA_CH_CSR_EARQ_SHIFT                    (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH_CSR_EARQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EARQ_SHIFT)) & DMA_CH_CSR_EARQ_MASK)

#define DMA_CH_CSR_EEI_MASK                      (0x4U)
#define DMA_CH_CSR_EEI_SHIFT                     (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH_CSR_EEI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EEI_SHIFT)) & DMA_CH_CSR_EEI_MASK)

#define DMA_CH_CSR_EBW_MASK                      (0x8U)
#define DMA_CH_CSR_EBW_SHIFT                     (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH_CSR_EBW(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EBW_SHIFT)) & DMA_CH_CSR_EBW_MASK)

#define DMA_CH_CSR_DONE_MASK                     (0x40000000U)
#define DMA_CH_CSR_DONE_SHIFT                    (30U)
/*! DONE - Channel Done */
#define DMA_CH_CSR_DONE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_DONE_SHIFT)) & DMA_CH_CSR_DONE_MASK)

#define DMA_CH_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_CH_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ACTIVE_SHIFT)) & DMA_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA_CH_CSR */
#define DMA_CH_CSR_COUNT                         (12U)

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_CH_ES_DBE_MASK                       (0x1U)
#define DMA_CH_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DBE_SHIFT)) & DMA_CH_ES_DBE_MASK)

#define DMA_CH_ES_SBE_MASK                       (0x2U)
#define DMA_CH_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SBE_SHIFT)) & DMA_CH_ES_SBE_MASK)

#define DMA_CH_ES_SGE_MASK                       (0x4U)
#define DMA_CH_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SGE_SHIFT)) & DMA_CH_ES_SGE_MASK)

#define DMA_CH_ES_NCE_MASK                       (0x8U)
#define DMA_CH_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_NCE_SHIFT)) & DMA_CH_ES_NCE_MASK)

#define DMA_CH_ES_DOE_MASK                       (0x10U)
#define DMA_CH_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DOE_SHIFT)) & DMA_CH_ES_DOE_MASK)

#define DMA_CH_ES_DAE_MASK                       (0x20U)
#define DMA_CH_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DAE_SHIFT)) & DMA_CH_ES_DAE_MASK)

#define DMA_CH_ES_SOE_MASK                       (0x40U)
#define DMA_CH_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SOE_SHIFT)) & DMA_CH_ES_SOE_MASK)

#define DMA_CH_ES_SAE_MASK                       (0x80U)
#define DMA_CH_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SAE_SHIFT)) & DMA_CH_ES_SAE_MASK)

#define DMA_CH_ES_ERR_MASK                       (0x80000000U)
#define DMA_CH_ES_ERR_SHIFT                      (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH_ES_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_ERR_SHIFT)) & DMA_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA_CH_ES */
#define DMA_CH_ES_COUNT                          (12U)

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH_INT_INT_MASK                      (0x1U)
#define DMA_CH_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_INT_INT_SHIFT)) & DMA_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA_CH_INT */
#define DMA_CH_INT_COUNT                         (12U)

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH_SBR_MID_MASK                      (0xFU)
#define DMA_CH_SBR_MID_SHIFT                     (0U)
/*! MID - Master ID */
#define DMA_CH_SBR_MID(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_MID_SHIFT)) & DMA_CH_SBR_MID_MASK)

#define DMA_CH_SBR_PAL_MASK                      (0x8000U)
#define DMA_CH_SBR_PAL_SHIFT                     (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH_SBR_PAL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_PAL_SHIFT)) & DMA_CH_SBR_PAL_MASK)

#define DMA_CH_SBR_EMI_MASK                      (0x10000U)
#define DMA_CH_SBR_EMI_SHIFT                     (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH_SBR_EMI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_EMI_SHIFT)) & DMA_CH_SBR_EMI_MASK)

#define DMA_CH_SBR_ATTR_MASK                     (0xE0000U)
#define DMA_CH_SBR_ATTR_SHIFT                    (17U)
/*! ATTR - Attribute Output */
#define DMA_CH_SBR_ATTR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_ATTR_SHIFT)) & DMA_CH_SBR_ATTR_MASK)
/*! @} */

/* The count of DMA_CH_SBR */
#define DMA_CH_SBR_COUNT                         (12U)

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_CH_PRI_APL_MASK                      (0x7U)
#define DMA_CH_PRI_APL_SHIFT                     (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH_PRI_APL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_APL_SHIFT)) & DMA_CH_PRI_APL_MASK)

#define DMA_CH_PRI_DPA_MASK                      (0x40000000U)
#define DMA_CH_PRI_DPA_SHIFT                     (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH_PRI_DPA(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_DPA_SHIFT)) & DMA_CH_PRI_DPA_MASK)

#define DMA_CH_PRI_ECP_MASK                      (0x80000000U)
#define DMA_CH_PRI_ECP_SHIFT                     (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH_PRI_ECP(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_ECP_SHIFT)) & DMA_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA_CH_PRI */
#define DMA_CH_PRI_COUNT                         (12U)

/*! @name TCD_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD_SADDR_SADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_SADDR_SADDR_SHIFT                (0U)
/*! SADDR - Source Address */
#define DMA_TCD_SADDR_SADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SADDR_SADDR_SHIFT)) & DMA_TCD_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA_TCD_SADDR */
#define DMA_TCD_SADDR_COUNT                      (12U)

/*! @name TCD_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD_SOFF_SOFF_MASK                   (0xFFFFU)
#define DMA_TCD_SOFF_SOFF_SHIFT                  (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD_SOFF_SOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_SOFF_SOFF_SHIFT)) & DMA_TCD_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA_TCD_SOFF */
#define DMA_TCD_SOFF_COUNT                       (12U)

/*! @name TCD_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD_ATTR_DSIZE_MASK                  (0x7U)
#define DMA_TCD_ATTR_DSIZE_SHIFT                 (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD_ATTR_DSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DSIZE_SHIFT)) & DMA_TCD_ATTR_DSIZE_MASK)

#define DMA_TCD_ATTR_DMOD_MASK                   (0xF8U)
#define DMA_TCD_ATTR_DMOD_SHIFT                  (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD_ATTR_DMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DMOD_SHIFT)) & DMA_TCD_ATTR_DMOD_MASK)

#define DMA_TCD_ATTR_SSIZE_MASK                  (0x700U)
#define DMA_TCD_ATTR_SSIZE_SHIFT                 (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD_ATTR_SSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SSIZE_SHIFT)) & DMA_TCD_ATTR_SSIZE_MASK)

#define DMA_TCD_ATTR_SMOD_MASK                   (0xF800U)
#define DMA_TCD_ATTR_SMOD_SHIFT                  (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD_ATTR_SMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SMOD_SHIFT)) & DMA_TCD_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA_TCD_ATTR */
#define DMA_TCD_ATTR_COUNT                       (12U)

/*! @name TCD_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK       (0x3FFFFFFFU)
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT      (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK        (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT       (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK        (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT       (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFNO */
#define DMA_TCD_NBYTES_MLOFFNO_COUNT             (12U)

/*! @name TCD_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK      (0x3FFU)
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT     (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK       (0x3FFFFC00U)
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT      (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK       (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT      (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK       (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT      (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFYES */
#define DMA_TCD_NBYTES_MLOFFYES_COUNT            (12U)

/*! @name TCD_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD_SLAST_SDA_SLAST_SDA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT        (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD_SLAST_SDA_SLAST_SDA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA_TCD_SLAST_SDA */
#define DMA_TCD_SLAST_SDA_COUNT                  (12U)

/*! @name TCD_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD_DADDR_DADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_DADDR_DADDR_SHIFT                (0U)
/*! DADDR - Destination Address */
#define DMA_TCD_DADDR_DADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DADDR_DADDR_SHIFT)) & DMA_TCD_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA_TCD_DADDR */
#define DMA_TCD_DADDR_COUNT                      (12U)

/*! @name TCD_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD_DOFF_DOFF_MASK                   (0xFFFFU)
#define DMA_TCD_DOFF_DOFF_SHIFT                  (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD_DOFF_DOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_DOFF_DOFF_SHIFT)) & DMA_TCD_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA_TCD_DOFF */
#define DMA_TCD_DOFF_COUNT                       (12U)

/*! @name TCD_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKNO_CITER_MASK         (0x7FFFU)
#define DMA_TCD_CITER_ELINKNO_CITER_SHIFT        (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKNO_CITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD_CITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_CITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKNO */
#define DMA_TCD_CITER_ELINKNO_COUNT              (12U)

/*! @name TCD_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKYES_CITER_MASK        (0x1FFU)
#define DMA_TCD_CITER_ELINKYES_CITER_SHIFT       (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKYES_CITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD_CITER_ELINKYES_LINKCH_MASK       (0x3E00U)
#define DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_CITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_CITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKYES */
#define DMA_TCD_CITER_ELINKYES_COUNT             (12U)

/*! @name TCD_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD_DLAST_SGA_DLAST_SGA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT        (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA_TCD_DLAST_SGA */
#define DMA_TCD_DLAST_SGA_COUNT                  (12U)

/*! @name TCD_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD_CSR_START_MASK                   (0x1U)
#define DMA_TCD_CSR_START_SHIFT                  (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD_CSR_START(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_START_SHIFT)) & DMA_TCD_CSR_START_MASK)

#define DMA_TCD_CSR_INTMAJOR_MASK                (0x2U)
#define DMA_TCD_CSR_INTMAJOR_SHIFT               (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD_CSR_INTMAJOR(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTMAJOR_SHIFT)) & DMA_TCD_CSR_INTMAJOR_MASK)

#define DMA_TCD_CSR_INTHALF_MASK                 (0x4U)
#define DMA_TCD_CSR_INTHALF_SHIFT                (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD_CSR_INTHALF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTHALF_SHIFT)) & DMA_TCD_CSR_INTHALF_MASK)

#define DMA_TCD_CSR_DREQ_MASK                    (0x8U)
#define DMA_TCD_CSR_DREQ_SHIFT                   (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD_CSR_DREQ(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_DREQ_SHIFT)) & DMA_TCD_CSR_DREQ_MASK)

#define DMA_TCD_CSR_ESG_MASK                     (0x10U)
#define DMA_TCD_CSR_ESG_SHIFT                    (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD_CSR_ESG(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESG_SHIFT)) & DMA_TCD_CSR_ESG_MASK)

#define DMA_TCD_CSR_MAJORELINK_MASK              (0x20U)
#define DMA_TCD_CSR_MAJORELINK_SHIFT             (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CSR_MAJORELINK(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORELINK_SHIFT)) & DMA_TCD_CSR_MAJORELINK_MASK)

#define DMA_TCD_CSR_EEOP_MASK                    (0x40U)
#define DMA_TCD_CSR_EEOP_SHIFT                   (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD_CSR_EEOP(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_EEOP_SHIFT)) & DMA_TCD_CSR_EEOP_MASK)

#define DMA_TCD_CSR_ESDA_MASK                    (0x80U)
#define DMA_TCD_CSR_ESDA_SHIFT                   (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD_CSR_ESDA(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESDA_SHIFT)) & DMA_TCD_CSR_ESDA_MASK)

#define DMA_TCD_CSR_MAJORLINKCH_MASK             (0x1F00U)
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT            (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD_CSR_MAJORLINKCH(x)               (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD_CSR_MAJORLINKCH_MASK)

#define DMA_TCD_CSR_BWC_MASK                     (0xC000U)
#define DMA_TCD_CSR_BWC_SHIFT                    (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD_CSR_BWC(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_BWC_SHIFT)) & DMA_TCD_CSR_BWC_MASK)
/*! @} */

/* The count of DMA_TCD_CSR */
#define DMA_TCD_CSR_COUNT                        (12U)

/*! @name TCD_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKNO_BITER_MASK         (0x7FFFU)
#define DMA_TCD_BITER_ELINKNO_BITER_SHIFT        (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKNO_BITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD_BITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_BITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKNO */
#define DMA_TCD_BITER_ELINKNO_COUNT              (12U)

/*! @name TCD_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKYES_BITER_MASK        (0x1FFU)
#define DMA_TCD_BITER_ELINKYES_BITER_SHIFT       (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKYES_BITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD_BITER_ELINKYES_LINKCH_MASK       (0x3E00U)
#define DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_BITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_BITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKYES */
#define DMA_TCD_BITER_ELINKYES_COUNT             (12U)

/*! @name CH12_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH12_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH12_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH12_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_CSR_ERQ_SHIFT)) & DMA_CH12_CSR_ERQ_MASK)

#define DMA_CH12_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH12_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH12_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH12_CSR_EARQ_SHIFT)) & DMA_CH12_CSR_EARQ_MASK)

#define DMA_CH12_CSR_EEI_MASK                    (0x4U)
#define DMA_CH12_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH12_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_CSR_EEI_SHIFT)) & DMA_CH12_CSR_EEI_MASK)

#define DMA_CH12_CSR_EBW_MASK                    (0x8U)
#define DMA_CH12_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH12_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_CSR_EBW_SHIFT)) & DMA_CH12_CSR_EBW_MASK)

#define DMA_CH12_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH12_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH12_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH12_CSR_DONE_SHIFT)) & DMA_CH12_CSR_DONE_MASK)

#define DMA_CH12_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH12_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH12_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH12_CSR_ACTIVE_SHIFT)) & DMA_CH12_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH12_ES - Channel Error Status */
/*! @{ */

#define DMA_CH12_ES_DBE_MASK                     (0x1U)
#define DMA_CH12_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH12_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_DBE_SHIFT)) & DMA_CH12_ES_DBE_MASK)

#define DMA_CH12_ES_SBE_MASK                     (0x2U)
#define DMA_CH12_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH12_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_SBE_SHIFT)) & DMA_CH12_ES_SBE_MASK)

#define DMA_CH12_ES_SGE_MASK                     (0x4U)
#define DMA_CH12_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH12_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_SGE_SHIFT)) & DMA_CH12_ES_SGE_MASK)

#define DMA_CH12_ES_NCE_MASK                     (0x8U)
#define DMA_CH12_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH12_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_NCE_SHIFT)) & DMA_CH12_ES_NCE_MASK)

#define DMA_CH12_ES_DOE_MASK                     (0x10U)
#define DMA_CH12_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH12_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_DOE_SHIFT)) & DMA_CH12_ES_DOE_MASK)

#define DMA_CH12_ES_DAE_MASK                     (0x20U)
#define DMA_CH12_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH12_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_DAE_SHIFT)) & DMA_CH12_ES_DAE_MASK)

#define DMA_CH12_ES_SOE_MASK                     (0x40U)
#define DMA_CH12_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH12_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_SOE_SHIFT)) & DMA_CH12_ES_SOE_MASK)

#define DMA_CH12_ES_SAE_MASK                     (0x80U)
#define DMA_CH12_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH12_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_SAE_SHIFT)) & DMA_CH12_ES_SAE_MASK)

#define DMA_CH12_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH12_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH12_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH12_ES_ERR_SHIFT)) & DMA_CH12_ES_ERR_MASK)
/*! @} */

/*! @name CH12_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH12_INT_INT_MASK                    (0x1U)
#define DMA_CH12_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH12_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_INT_INT_SHIFT)) & DMA_CH12_INT_INT_MASK)
/*! @} */

/*! @name CH12_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH12_SBR_MID_MASK                    (0xFU)
#define DMA_CH12_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH12_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_SBR_MID_SHIFT)) & DMA_CH12_SBR_MID_MASK)

#define DMA_CH12_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH12_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH12_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_SBR_PAL_SHIFT)) & DMA_CH12_SBR_PAL_MASK)

#define DMA_CH12_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH12_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH12_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_SBR_EMI_SHIFT)) & DMA_CH12_SBR_EMI_MASK)

#define DMA_CH12_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH12_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH12_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH12_SBR_ATTR_SHIFT)) & DMA_CH12_SBR_ATTR_MASK)
/*! @} */

/*! @name CH12_PRI - Channel Priority */
/*! @{ */

#define DMA_CH12_PRI_APL_MASK                    (0x7U)
#define DMA_CH12_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH12_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_PRI_APL_SHIFT)) & DMA_CH12_PRI_APL_MASK)

#define DMA_CH12_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH12_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH12_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_PRI_DPA_SHIFT)) & DMA_CH12_PRI_DPA_MASK)

#define DMA_CH12_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH12_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH12_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH12_PRI_ECP_SHIFT)) & DMA_CH12_PRI_ECP_MASK)
/*! @} */

/*! @name TCD12_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD12_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD12_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD12_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_SADDR_SADDR_SHIFT)) & DMA_TCD12_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD12_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD12_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD12_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD12_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_SOFF_SOFF_SHIFT)) & DMA_TCD12_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD12_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD12_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD12_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD12_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_ATTR_DSIZE_SHIFT)) & DMA_TCD12_ATTR_DSIZE_MASK)

#define DMA_TCD12_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD12_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD12_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_ATTR_DMOD_SHIFT)) & DMA_TCD12_ATTR_DMOD_MASK)

#define DMA_TCD12_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD12_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD12_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_ATTR_SSIZE_SHIFT)) & DMA_TCD12_ATTR_SSIZE_MASK)

#define DMA_TCD12_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD12_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD12_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_ATTR_SMOD_SHIFT)) & DMA_TCD12_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD12_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD12_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD12_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD12_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD12_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD12_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD12_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD12_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD12_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD12_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD12_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD12_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD12_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD12_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD12_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD12_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD12_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD12_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD12_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD12_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD12_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD12_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD12_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD12_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD12_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD12_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD12_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD12_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD12_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD12_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD12_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD12_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD12_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD12_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD12_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD12_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD12_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD12_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD12_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_DADDR_DADDR_SHIFT)) & DMA_TCD12_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD12_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD12_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD12_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD12_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_DOFF_DOFF_SHIFT)) & DMA_TCD12_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD12_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD12_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD12_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD12_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD12_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD12_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD12_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD12_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD12_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD12_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD12_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD12_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD12_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD12_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD12_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD12_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD12_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD12_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD12_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD12_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD12_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD12_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD12_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD12_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD12_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD12_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD12_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD12_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD12_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD12_CSR_START_MASK                 (0x1U)
#define DMA_TCD12_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD12_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_START_SHIFT)) & DMA_TCD12_CSR_START_MASK)

#define DMA_TCD12_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD12_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD12_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_INTMAJOR_SHIFT)) & DMA_TCD12_CSR_INTMAJOR_MASK)

#define DMA_TCD12_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD12_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD12_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_INTHALF_SHIFT)) & DMA_TCD12_CSR_INTHALF_MASK)

#define DMA_TCD12_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD12_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD12_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_DREQ_SHIFT)) & DMA_TCD12_CSR_DREQ_MASK)

#define DMA_TCD12_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD12_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD12_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_ESG_SHIFT)) & DMA_TCD12_CSR_ESG_MASK)

#define DMA_TCD12_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD12_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD12_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_MAJORELINK_SHIFT)) & DMA_TCD12_CSR_MAJORELINK_MASK)

#define DMA_TCD12_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD12_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD12_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_EEOP_SHIFT)) & DMA_TCD12_CSR_EEOP_MASK)

#define DMA_TCD12_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD12_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD12_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_ESDA_SHIFT)) & DMA_TCD12_CSR_ESDA_MASK)

#define DMA_TCD12_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD12_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD12_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD12_CSR_MAJORLINKCH_MASK)

#define DMA_TCD12_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD12_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD12_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_CSR_BWC_SHIFT)) & DMA_TCD12_CSR_BWC_MASK)
/*! @} */

/*! @name TCD12_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD12_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD12_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD12_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD12_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD12_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD12_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD12_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD12_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD12_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD12_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD12_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD12_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD12_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD12_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD12_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD12_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD12_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD12_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD12_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD12_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD12_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD12_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH13_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH13_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH13_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH13_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_CSR_ERQ_SHIFT)) & DMA_CH13_CSR_ERQ_MASK)

#define DMA_CH13_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH13_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH13_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH13_CSR_EARQ_SHIFT)) & DMA_CH13_CSR_EARQ_MASK)

#define DMA_CH13_CSR_EEI_MASK                    (0x4U)
#define DMA_CH13_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH13_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_CSR_EEI_SHIFT)) & DMA_CH13_CSR_EEI_MASK)

#define DMA_CH13_CSR_EBW_MASK                    (0x8U)
#define DMA_CH13_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH13_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_CSR_EBW_SHIFT)) & DMA_CH13_CSR_EBW_MASK)

#define DMA_CH13_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH13_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH13_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH13_CSR_DONE_SHIFT)) & DMA_CH13_CSR_DONE_MASK)

#define DMA_CH13_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH13_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH13_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH13_CSR_ACTIVE_SHIFT)) & DMA_CH13_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH13_ES - Channel Error Status */
/*! @{ */

#define DMA_CH13_ES_DBE_MASK                     (0x1U)
#define DMA_CH13_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH13_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_DBE_SHIFT)) & DMA_CH13_ES_DBE_MASK)

#define DMA_CH13_ES_SBE_MASK                     (0x2U)
#define DMA_CH13_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH13_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_SBE_SHIFT)) & DMA_CH13_ES_SBE_MASK)

#define DMA_CH13_ES_SGE_MASK                     (0x4U)
#define DMA_CH13_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH13_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_SGE_SHIFT)) & DMA_CH13_ES_SGE_MASK)

#define DMA_CH13_ES_NCE_MASK                     (0x8U)
#define DMA_CH13_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH13_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_NCE_SHIFT)) & DMA_CH13_ES_NCE_MASK)

#define DMA_CH13_ES_DOE_MASK                     (0x10U)
#define DMA_CH13_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH13_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_DOE_SHIFT)) & DMA_CH13_ES_DOE_MASK)

#define DMA_CH13_ES_DAE_MASK                     (0x20U)
#define DMA_CH13_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH13_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_DAE_SHIFT)) & DMA_CH13_ES_DAE_MASK)

#define DMA_CH13_ES_SOE_MASK                     (0x40U)
#define DMA_CH13_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH13_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_SOE_SHIFT)) & DMA_CH13_ES_SOE_MASK)

#define DMA_CH13_ES_SAE_MASK                     (0x80U)
#define DMA_CH13_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH13_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_SAE_SHIFT)) & DMA_CH13_ES_SAE_MASK)

#define DMA_CH13_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH13_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH13_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH13_ES_ERR_SHIFT)) & DMA_CH13_ES_ERR_MASK)
/*! @} */

/*! @name CH13_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH13_INT_INT_MASK                    (0x1U)
#define DMA_CH13_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH13_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_INT_INT_SHIFT)) & DMA_CH13_INT_INT_MASK)
/*! @} */

/*! @name CH13_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH13_SBR_MID_MASK                    (0xFU)
#define DMA_CH13_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH13_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_SBR_MID_SHIFT)) & DMA_CH13_SBR_MID_MASK)

#define DMA_CH13_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH13_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH13_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_SBR_PAL_SHIFT)) & DMA_CH13_SBR_PAL_MASK)

#define DMA_CH13_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH13_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH13_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_SBR_EMI_SHIFT)) & DMA_CH13_SBR_EMI_MASK)

#define DMA_CH13_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH13_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH13_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH13_SBR_ATTR_SHIFT)) & DMA_CH13_SBR_ATTR_MASK)
/*! @} */

/*! @name CH13_PRI - Channel Priority */
/*! @{ */

#define DMA_CH13_PRI_APL_MASK                    (0x7U)
#define DMA_CH13_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH13_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_PRI_APL_SHIFT)) & DMA_CH13_PRI_APL_MASK)

#define DMA_CH13_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH13_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH13_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_PRI_DPA_SHIFT)) & DMA_CH13_PRI_DPA_MASK)

#define DMA_CH13_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH13_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH13_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH13_PRI_ECP_SHIFT)) & DMA_CH13_PRI_ECP_MASK)
/*! @} */

/*! @name TCD13_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD13_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD13_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD13_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_SADDR_SADDR_SHIFT)) & DMA_TCD13_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD13_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD13_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD13_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD13_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_SOFF_SOFF_SHIFT)) & DMA_TCD13_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD13_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD13_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD13_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD13_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_ATTR_DSIZE_SHIFT)) & DMA_TCD13_ATTR_DSIZE_MASK)

#define DMA_TCD13_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD13_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD13_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_ATTR_DMOD_SHIFT)) & DMA_TCD13_ATTR_DMOD_MASK)

#define DMA_TCD13_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD13_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD13_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_ATTR_SSIZE_SHIFT)) & DMA_TCD13_ATTR_SSIZE_MASK)

#define DMA_TCD13_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD13_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD13_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_ATTR_SMOD_SHIFT)) & DMA_TCD13_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD13_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD13_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD13_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD13_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD13_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD13_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD13_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD13_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD13_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD13_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD13_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD13_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD13_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD13_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD13_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD13_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD13_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD13_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD13_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD13_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD13_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD13_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD13_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD13_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD13_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD13_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD13_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD13_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD13_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD13_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD13_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD13_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD13_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD13_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD13_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD13_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD13_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD13_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD13_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_DADDR_DADDR_SHIFT)) & DMA_TCD13_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD13_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD13_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD13_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD13_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_DOFF_DOFF_SHIFT)) & DMA_TCD13_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD13_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD13_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD13_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD13_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD13_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD13_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD13_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD13_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD13_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD13_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD13_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD13_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD13_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD13_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD13_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD13_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD13_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD13_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD13_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD13_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD13_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD13_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD13_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD13_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD13_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD13_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD13_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD13_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD13_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD13_CSR_START_MASK                 (0x1U)
#define DMA_TCD13_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD13_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_START_SHIFT)) & DMA_TCD13_CSR_START_MASK)

#define DMA_TCD13_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD13_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD13_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_INTMAJOR_SHIFT)) & DMA_TCD13_CSR_INTMAJOR_MASK)

#define DMA_TCD13_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD13_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD13_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_INTHALF_SHIFT)) & DMA_TCD13_CSR_INTHALF_MASK)

#define DMA_TCD13_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD13_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD13_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_DREQ_SHIFT)) & DMA_TCD13_CSR_DREQ_MASK)

#define DMA_TCD13_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD13_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD13_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_ESG_SHIFT)) & DMA_TCD13_CSR_ESG_MASK)

#define DMA_TCD13_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD13_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD13_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_MAJORELINK_SHIFT)) & DMA_TCD13_CSR_MAJORELINK_MASK)

#define DMA_TCD13_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD13_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD13_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_EEOP_SHIFT)) & DMA_TCD13_CSR_EEOP_MASK)

#define DMA_TCD13_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD13_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD13_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_ESDA_SHIFT)) & DMA_TCD13_CSR_ESDA_MASK)

#define DMA_TCD13_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD13_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD13_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD13_CSR_MAJORLINKCH_MASK)

#define DMA_TCD13_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD13_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD13_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_CSR_BWC_SHIFT)) & DMA_TCD13_CSR_BWC_MASK)
/*! @} */

/*! @name TCD13_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD13_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD13_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD13_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD13_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD13_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD13_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD13_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD13_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD13_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD13_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD13_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD13_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD13_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD13_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD13_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD13_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD13_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD13_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD13_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD13_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD13_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD13_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH14_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH14_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH14_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH14_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_CSR_ERQ_SHIFT)) & DMA_CH14_CSR_ERQ_MASK)

#define DMA_CH14_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH14_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH14_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH14_CSR_EARQ_SHIFT)) & DMA_CH14_CSR_EARQ_MASK)

#define DMA_CH14_CSR_EEI_MASK                    (0x4U)
#define DMA_CH14_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH14_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_CSR_EEI_SHIFT)) & DMA_CH14_CSR_EEI_MASK)

#define DMA_CH14_CSR_EBW_MASK                    (0x8U)
#define DMA_CH14_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH14_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_CSR_EBW_SHIFT)) & DMA_CH14_CSR_EBW_MASK)

#define DMA_CH14_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH14_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH14_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH14_CSR_DONE_SHIFT)) & DMA_CH14_CSR_DONE_MASK)

#define DMA_CH14_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH14_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH14_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH14_CSR_ACTIVE_SHIFT)) & DMA_CH14_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH14_ES - Channel Error Status */
/*! @{ */

#define DMA_CH14_ES_DBE_MASK                     (0x1U)
#define DMA_CH14_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH14_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_DBE_SHIFT)) & DMA_CH14_ES_DBE_MASK)

#define DMA_CH14_ES_SBE_MASK                     (0x2U)
#define DMA_CH14_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH14_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_SBE_SHIFT)) & DMA_CH14_ES_SBE_MASK)

#define DMA_CH14_ES_SGE_MASK                     (0x4U)
#define DMA_CH14_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH14_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_SGE_SHIFT)) & DMA_CH14_ES_SGE_MASK)

#define DMA_CH14_ES_NCE_MASK                     (0x8U)
#define DMA_CH14_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH14_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_NCE_SHIFT)) & DMA_CH14_ES_NCE_MASK)

#define DMA_CH14_ES_DOE_MASK                     (0x10U)
#define DMA_CH14_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH14_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_DOE_SHIFT)) & DMA_CH14_ES_DOE_MASK)

#define DMA_CH14_ES_DAE_MASK                     (0x20U)
#define DMA_CH14_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH14_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_DAE_SHIFT)) & DMA_CH14_ES_DAE_MASK)

#define DMA_CH14_ES_SOE_MASK                     (0x40U)
#define DMA_CH14_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH14_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_SOE_SHIFT)) & DMA_CH14_ES_SOE_MASK)

#define DMA_CH14_ES_SAE_MASK                     (0x80U)
#define DMA_CH14_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH14_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_SAE_SHIFT)) & DMA_CH14_ES_SAE_MASK)

#define DMA_CH14_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH14_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH14_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH14_ES_ERR_SHIFT)) & DMA_CH14_ES_ERR_MASK)
/*! @} */

/*! @name CH14_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH14_INT_INT_MASK                    (0x1U)
#define DMA_CH14_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH14_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_INT_INT_SHIFT)) & DMA_CH14_INT_INT_MASK)
/*! @} */

/*! @name CH14_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH14_SBR_MID_MASK                    (0xFU)
#define DMA_CH14_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH14_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_SBR_MID_SHIFT)) & DMA_CH14_SBR_MID_MASK)

#define DMA_CH14_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH14_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH14_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_SBR_PAL_SHIFT)) & DMA_CH14_SBR_PAL_MASK)

#define DMA_CH14_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH14_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH14_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_SBR_EMI_SHIFT)) & DMA_CH14_SBR_EMI_MASK)

#define DMA_CH14_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH14_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH14_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH14_SBR_ATTR_SHIFT)) & DMA_CH14_SBR_ATTR_MASK)
/*! @} */

/*! @name CH14_PRI - Channel Priority */
/*! @{ */

#define DMA_CH14_PRI_APL_MASK                    (0x7U)
#define DMA_CH14_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH14_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_PRI_APL_SHIFT)) & DMA_CH14_PRI_APL_MASK)

#define DMA_CH14_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH14_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH14_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_PRI_DPA_SHIFT)) & DMA_CH14_PRI_DPA_MASK)

#define DMA_CH14_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH14_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH14_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH14_PRI_ECP_SHIFT)) & DMA_CH14_PRI_ECP_MASK)
/*! @} */

/*! @name TCD14_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD14_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD14_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD14_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_SADDR_SADDR_SHIFT)) & DMA_TCD14_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD14_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD14_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD14_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD14_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_SOFF_SOFF_SHIFT)) & DMA_TCD14_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD14_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD14_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD14_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD14_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_ATTR_DSIZE_SHIFT)) & DMA_TCD14_ATTR_DSIZE_MASK)

#define DMA_TCD14_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD14_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD14_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_ATTR_DMOD_SHIFT)) & DMA_TCD14_ATTR_DMOD_MASK)

#define DMA_TCD14_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD14_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD14_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_ATTR_SSIZE_SHIFT)) & DMA_TCD14_ATTR_SSIZE_MASK)

#define DMA_TCD14_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD14_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD14_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_ATTR_SMOD_SHIFT)) & DMA_TCD14_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD14_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD14_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD14_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD14_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD14_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD14_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD14_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD14_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD14_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD14_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD14_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD14_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD14_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD14_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD14_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD14_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD14_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD14_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD14_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD14_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD14_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD14_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD14_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD14_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD14_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD14_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD14_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD14_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD14_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD14_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD14_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD14_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD14_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD14_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD14_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD14_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD14_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD14_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD14_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_DADDR_DADDR_SHIFT)) & DMA_TCD14_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD14_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD14_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD14_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD14_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_DOFF_DOFF_SHIFT)) & DMA_TCD14_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD14_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD14_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD14_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD14_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD14_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD14_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD14_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD14_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD14_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD14_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD14_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD14_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD14_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD14_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD14_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD14_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD14_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD14_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD14_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD14_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD14_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD14_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD14_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD14_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD14_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD14_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD14_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD14_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD14_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD14_CSR_START_MASK                 (0x1U)
#define DMA_TCD14_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD14_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_START_SHIFT)) & DMA_TCD14_CSR_START_MASK)

#define DMA_TCD14_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD14_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD14_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_INTMAJOR_SHIFT)) & DMA_TCD14_CSR_INTMAJOR_MASK)

#define DMA_TCD14_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD14_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD14_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_INTHALF_SHIFT)) & DMA_TCD14_CSR_INTHALF_MASK)

#define DMA_TCD14_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD14_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD14_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_DREQ_SHIFT)) & DMA_TCD14_CSR_DREQ_MASK)

#define DMA_TCD14_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD14_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD14_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_ESG_SHIFT)) & DMA_TCD14_CSR_ESG_MASK)

#define DMA_TCD14_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD14_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD14_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_MAJORELINK_SHIFT)) & DMA_TCD14_CSR_MAJORELINK_MASK)

#define DMA_TCD14_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD14_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD14_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_EEOP_SHIFT)) & DMA_TCD14_CSR_EEOP_MASK)

#define DMA_TCD14_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD14_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD14_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_ESDA_SHIFT)) & DMA_TCD14_CSR_ESDA_MASK)

#define DMA_TCD14_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD14_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD14_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD14_CSR_MAJORLINKCH_MASK)

#define DMA_TCD14_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD14_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD14_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_CSR_BWC_SHIFT)) & DMA_TCD14_CSR_BWC_MASK)
/*! @} */

/*! @name TCD14_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD14_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD14_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD14_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD14_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD14_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD14_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD14_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD14_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD14_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD14_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD14_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD14_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD14_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD14_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD14_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD14_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD14_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD14_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD14_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD14_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD14_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD14_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH15_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH15_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH15_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH15_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_CSR_ERQ_SHIFT)) & DMA_CH15_CSR_ERQ_MASK)

#define DMA_CH15_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH15_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH15_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH15_CSR_EARQ_SHIFT)) & DMA_CH15_CSR_EARQ_MASK)

#define DMA_CH15_CSR_EEI_MASK                    (0x4U)
#define DMA_CH15_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH15_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_CSR_EEI_SHIFT)) & DMA_CH15_CSR_EEI_MASK)

#define DMA_CH15_CSR_EBW_MASK                    (0x8U)
#define DMA_CH15_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH15_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_CSR_EBW_SHIFT)) & DMA_CH15_CSR_EBW_MASK)

#define DMA_CH15_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH15_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH15_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH15_CSR_DONE_SHIFT)) & DMA_CH15_CSR_DONE_MASK)

#define DMA_CH15_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH15_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH15_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH15_CSR_ACTIVE_SHIFT)) & DMA_CH15_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH15_ES - Channel Error Status */
/*! @{ */

#define DMA_CH15_ES_DBE_MASK                     (0x1U)
#define DMA_CH15_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH15_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_DBE_SHIFT)) & DMA_CH15_ES_DBE_MASK)

#define DMA_CH15_ES_SBE_MASK                     (0x2U)
#define DMA_CH15_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH15_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_SBE_SHIFT)) & DMA_CH15_ES_SBE_MASK)

#define DMA_CH15_ES_SGE_MASK                     (0x4U)
#define DMA_CH15_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH15_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_SGE_SHIFT)) & DMA_CH15_ES_SGE_MASK)

#define DMA_CH15_ES_NCE_MASK                     (0x8U)
#define DMA_CH15_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH15_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_NCE_SHIFT)) & DMA_CH15_ES_NCE_MASK)

#define DMA_CH15_ES_DOE_MASK                     (0x10U)
#define DMA_CH15_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH15_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_DOE_SHIFT)) & DMA_CH15_ES_DOE_MASK)

#define DMA_CH15_ES_DAE_MASK                     (0x20U)
#define DMA_CH15_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH15_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_DAE_SHIFT)) & DMA_CH15_ES_DAE_MASK)

#define DMA_CH15_ES_SOE_MASK                     (0x40U)
#define DMA_CH15_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH15_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_SOE_SHIFT)) & DMA_CH15_ES_SOE_MASK)

#define DMA_CH15_ES_SAE_MASK                     (0x80U)
#define DMA_CH15_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH15_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_SAE_SHIFT)) & DMA_CH15_ES_SAE_MASK)

#define DMA_CH15_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH15_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH15_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH15_ES_ERR_SHIFT)) & DMA_CH15_ES_ERR_MASK)
/*! @} */

/*! @name CH15_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH15_INT_INT_MASK                    (0x1U)
#define DMA_CH15_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH15_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_INT_INT_SHIFT)) & DMA_CH15_INT_INT_MASK)
/*! @} */

/*! @name CH15_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH15_SBR_MID_MASK                    (0xFU)
#define DMA_CH15_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH15_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_SBR_MID_SHIFT)) & DMA_CH15_SBR_MID_MASK)

#define DMA_CH15_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH15_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH15_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_SBR_PAL_SHIFT)) & DMA_CH15_SBR_PAL_MASK)

#define DMA_CH15_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH15_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH15_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_SBR_EMI_SHIFT)) & DMA_CH15_SBR_EMI_MASK)

#define DMA_CH15_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH15_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH15_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH15_SBR_ATTR_SHIFT)) & DMA_CH15_SBR_ATTR_MASK)
/*! @} */

/*! @name CH15_PRI - Channel Priority */
/*! @{ */

#define DMA_CH15_PRI_APL_MASK                    (0x7U)
#define DMA_CH15_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH15_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_PRI_APL_SHIFT)) & DMA_CH15_PRI_APL_MASK)

#define DMA_CH15_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH15_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH15_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_PRI_DPA_SHIFT)) & DMA_CH15_PRI_DPA_MASK)

#define DMA_CH15_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH15_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH15_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH15_PRI_ECP_SHIFT)) & DMA_CH15_PRI_ECP_MASK)
/*! @} */

/*! @name TCD15_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD15_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD15_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD15_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_SADDR_SADDR_SHIFT)) & DMA_TCD15_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD15_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD15_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD15_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD15_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_SOFF_SOFF_SHIFT)) & DMA_TCD15_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD15_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD15_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD15_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD15_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_ATTR_DSIZE_SHIFT)) & DMA_TCD15_ATTR_DSIZE_MASK)

#define DMA_TCD15_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD15_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD15_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_ATTR_DMOD_SHIFT)) & DMA_TCD15_ATTR_DMOD_MASK)

#define DMA_TCD15_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD15_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD15_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_ATTR_SSIZE_SHIFT)) & DMA_TCD15_ATTR_SSIZE_MASK)

#define DMA_TCD15_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD15_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD15_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_ATTR_SMOD_SHIFT)) & DMA_TCD15_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD15_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD15_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD15_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD15_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD15_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD15_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD15_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD15_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD15_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD15_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD15_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD15_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD15_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD15_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD15_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD15_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD15_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD15_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD15_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD15_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD15_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD15_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD15_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD15_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD15_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD15_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD15_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD15_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD15_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD15_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD15_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD15_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD15_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD15_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD15_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD15_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD15_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD15_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD15_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_DADDR_DADDR_SHIFT)) & DMA_TCD15_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD15_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD15_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD15_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD15_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_DOFF_DOFF_SHIFT)) & DMA_TCD15_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD15_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD15_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD15_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD15_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD15_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD15_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD15_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD15_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD15_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD15_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD15_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD15_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD15_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD15_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD15_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD15_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD15_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD15_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD15_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD15_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD15_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD15_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD15_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD15_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD15_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD15_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD15_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD15_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD15_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD15_CSR_START_MASK                 (0x1U)
#define DMA_TCD15_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD15_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_START_SHIFT)) & DMA_TCD15_CSR_START_MASK)

#define DMA_TCD15_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD15_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD15_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_INTMAJOR_SHIFT)) & DMA_TCD15_CSR_INTMAJOR_MASK)

#define DMA_TCD15_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD15_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD15_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_INTHALF_SHIFT)) & DMA_TCD15_CSR_INTHALF_MASK)

#define DMA_TCD15_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD15_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD15_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_DREQ_SHIFT)) & DMA_TCD15_CSR_DREQ_MASK)

#define DMA_TCD15_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD15_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD15_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_ESG_SHIFT)) & DMA_TCD15_CSR_ESG_MASK)

#define DMA_TCD15_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD15_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD15_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_MAJORELINK_SHIFT)) & DMA_TCD15_CSR_MAJORELINK_MASK)

#define DMA_TCD15_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD15_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD15_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_EEOP_SHIFT)) & DMA_TCD15_CSR_EEOP_MASK)

#define DMA_TCD15_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD15_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD15_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_ESDA_SHIFT)) & DMA_TCD15_CSR_ESDA_MASK)

#define DMA_TCD15_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD15_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD15_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD15_CSR_MAJORLINKCH_MASK)

#define DMA_TCD15_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD15_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD15_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_CSR_BWC_SHIFT)) & DMA_TCD15_CSR_BWC_MASK)
/*! @} */

/*! @name TCD15_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD15_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD15_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD15_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD15_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD15_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD15_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD15_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD15_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD15_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD15_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD15_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD15_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD15_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD15_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD15_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD15_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD15_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD15_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD15_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD15_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD15_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD15_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH16_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH16_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH16_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH16_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_CSR_ERQ_SHIFT)) & DMA_CH16_CSR_ERQ_MASK)

#define DMA_CH16_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH16_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH16_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH16_CSR_EARQ_SHIFT)) & DMA_CH16_CSR_EARQ_MASK)

#define DMA_CH16_CSR_EEI_MASK                    (0x4U)
#define DMA_CH16_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH16_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_CSR_EEI_SHIFT)) & DMA_CH16_CSR_EEI_MASK)

#define DMA_CH16_CSR_EBW_MASK                    (0x8U)
#define DMA_CH16_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH16_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_CSR_EBW_SHIFT)) & DMA_CH16_CSR_EBW_MASK)

#define DMA_CH16_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH16_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH16_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH16_CSR_DONE_SHIFT)) & DMA_CH16_CSR_DONE_MASK)

#define DMA_CH16_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH16_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH16_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH16_CSR_ACTIVE_SHIFT)) & DMA_CH16_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH16_ES - Channel Error Status */
/*! @{ */

#define DMA_CH16_ES_DBE_MASK                     (0x1U)
#define DMA_CH16_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH16_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_DBE_SHIFT)) & DMA_CH16_ES_DBE_MASK)

#define DMA_CH16_ES_SBE_MASK                     (0x2U)
#define DMA_CH16_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH16_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_SBE_SHIFT)) & DMA_CH16_ES_SBE_MASK)

#define DMA_CH16_ES_SGE_MASK                     (0x4U)
#define DMA_CH16_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH16_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_SGE_SHIFT)) & DMA_CH16_ES_SGE_MASK)

#define DMA_CH16_ES_NCE_MASK                     (0x8U)
#define DMA_CH16_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH16_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_NCE_SHIFT)) & DMA_CH16_ES_NCE_MASK)

#define DMA_CH16_ES_DOE_MASK                     (0x10U)
#define DMA_CH16_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH16_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_DOE_SHIFT)) & DMA_CH16_ES_DOE_MASK)

#define DMA_CH16_ES_DAE_MASK                     (0x20U)
#define DMA_CH16_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH16_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_DAE_SHIFT)) & DMA_CH16_ES_DAE_MASK)

#define DMA_CH16_ES_SOE_MASK                     (0x40U)
#define DMA_CH16_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH16_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_SOE_SHIFT)) & DMA_CH16_ES_SOE_MASK)

#define DMA_CH16_ES_SAE_MASK                     (0x80U)
#define DMA_CH16_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH16_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_SAE_SHIFT)) & DMA_CH16_ES_SAE_MASK)

#define DMA_CH16_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH16_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH16_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH16_ES_ERR_SHIFT)) & DMA_CH16_ES_ERR_MASK)
/*! @} */

/*! @name CH16_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH16_INT_INT_MASK                    (0x1U)
#define DMA_CH16_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH16_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_INT_INT_SHIFT)) & DMA_CH16_INT_INT_MASK)
/*! @} */

/*! @name CH16_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH16_SBR_MID_MASK                    (0xFU)
#define DMA_CH16_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH16_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_SBR_MID_SHIFT)) & DMA_CH16_SBR_MID_MASK)

#define DMA_CH16_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH16_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH16_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_SBR_PAL_SHIFT)) & DMA_CH16_SBR_PAL_MASK)

#define DMA_CH16_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH16_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH16_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_SBR_EMI_SHIFT)) & DMA_CH16_SBR_EMI_MASK)

#define DMA_CH16_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH16_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH16_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH16_SBR_ATTR_SHIFT)) & DMA_CH16_SBR_ATTR_MASK)
/*! @} */

/*! @name CH16_PRI - Channel Priority */
/*! @{ */

#define DMA_CH16_PRI_APL_MASK                    (0x7U)
#define DMA_CH16_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH16_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_PRI_APL_SHIFT)) & DMA_CH16_PRI_APL_MASK)

#define DMA_CH16_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH16_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH16_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_PRI_DPA_SHIFT)) & DMA_CH16_PRI_DPA_MASK)

#define DMA_CH16_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH16_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH16_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH16_PRI_ECP_SHIFT)) & DMA_CH16_PRI_ECP_MASK)
/*! @} */

/*! @name TCD16_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD16_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD16_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD16_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_SADDR_SADDR_SHIFT)) & DMA_TCD16_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD16_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD16_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD16_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD16_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_SOFF_SOFF_SHIFT)) & DMA_TCD16_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD16_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD16_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD16_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD16_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_ATTR_DSIZE_SHIFT)) & DMA_TCD16_ATTR_DSIZE_MASK)

#define DMA_TCD16_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD16_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD16_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_ATTR_DMOD_SHIFT)) & DMA_TCD16_ATTR_DMOD_MASK)

#define DMA_TCD16_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD16_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD16_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_ATTR_SSIZE_SHIFT)) & DMA_TCD16_ATTR_SSIZE_MASK)

#define DMA_TCD16_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD16_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD16_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_ATTR_SMOD_SHIFT)) & DMA_TCD16_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD16_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD16_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD16_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD16_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD16_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD16_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD16_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD16_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD16_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD16_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD16_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD16_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD16_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD16_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD16_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD16_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD16_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD16_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD16_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD16_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD16_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD16_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD16_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD16_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD16_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD16_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD16_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD16_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD16_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD16_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD16_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD16_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD16_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD16_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD16_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD16_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD16_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD16_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD16_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_DADDR_DADDR_SHIFT)) & DMA_TCD16_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD16_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD16_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD16_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD16_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_DOFF_DOFF_SHIFT)) & DMA_TCD16_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD16_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD16_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD16_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD16_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD16_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD16_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD16_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD16_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD16_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD16_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD16_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD16_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD16_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD16_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD16_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD16_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD16_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD16_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD16_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD16_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD16_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD16_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD16_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD16_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD16_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD16_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD16_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD16_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD16_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD16_CSR_START_MASK                 (0x1U)
#define DMA_TCD16_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD16_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_START_SHIFT)) & DMA_TCD16_CSR_START_MASK)

#define DMA_TCD16_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD16_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD16_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_INTMAJOR_SHIFT)) & DMA_TCD16_CSR_INTMAJOR_MASK)

#define DMA_TCD16_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD16_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD16_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_INTHALF_SHIFT)) & DMA_TCD16_CSR_INTHALF_MASK)

#define DMA_TCD16_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD16_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD16_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_DREQ_SHIFT)) & DMA_TCD16_CSR_DREQ_MASK)

#define DMA_TCD16_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD16_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD16_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_ESG_SHIFT)) & DMA_TCD16_CSR_ESG_MASK)

#define DMA_TCD16_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD16_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD16_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_MAJORELINK_SHIFT)) & DMA_TCD16_CSR_MAJORELINK_MASK)

#define DMA_TCD16_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD16_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD16_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_EEOP_SHIFT)) & DMA_TCD16_CSR_EEOP_MASK)

#define DMA_TCD16_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD16_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD16_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_ESDA_SHIFT)) & DMA_TCD16_CSR_ESDA_MASK)

#define DMA_TCD16_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD16_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD16_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD16_CSR_MAJORLINKCH_MASK)

#define DMA_TCD16_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD16_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD16_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_CSR_BWC_SHIFT)) & DMA_TCD16_CSR_BWC_MASK)
/*! @} */

/*! @name TCD16_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD16_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD16_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD16_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD16_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD16_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD16_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD16_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD16_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD16_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD16_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD16_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD16_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD16_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD16_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD16_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD16_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD16_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD16_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD16_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD16_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD16_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD16_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH17_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH17_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH17_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH17_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_CSR_ERQ_SHIFT)) & DMA_CH17_CSR_ERQ_MASK)

#define DMA_CH17_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH17_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH17_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH17_CSR_EARQ_SHIFT)) & DMA_CH17_CSR_EARQ_MASK)

#define DMA_CH17_CSR_EEI_MASK                    (0x4U)
#define DMA_CH17_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH17_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_CSR_EEI_SHIFT)) & DMA_CH17_CSR_EEI_MASK)

#define DMA_CH17_CSR_EBW_MASK                    (0x8U)
#define DMA_CH17_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH17_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_CSR_EBW_SHIFT)) & DMA_CH17_CSR_EBW_MASK)

#define DMA_CH17_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH17_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH17_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH17_CSR_DONE_SHIFT)) & DMA_CH17_CSR_DONE_MASK)

#define DMA_CH17_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH17_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH17_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH17_CSR_ACTIVE_SHIFT)) & DMA_CH17_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH17_ES - Channel Error Status */
/*! @{ */

#define DMA_CH17_ES_DBE_MASK                     (0x1U)
#define DMA_CH17_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH17_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_DBE_SHIFT)) & DMA_CH17_ES_DBE_MASK)

#define DMA_CH17_ES_SBE_MASK                     (0x2U)
#define DMA_CH17_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH17_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_SBE_SHIFT)) & DMA_CH17_ES_SBE_MASK)

#define DMA_CH17_ES_SGE_MASK                     (0x4U)
#define DMA_CH17_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH17_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_SGE_SHIFT)) & DMA_CH17_ES_SGE_MASK)

#define DMA_CH17_ES_NCE_MASK                     (0x8U)
#define DMA_CH17_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH17_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_NCE_SHIFT)) & DMA_CH17_ES_NCE_MASK)

#define DMA_CH17_ES_DOE_MASK                     (0x10U)
#define DMA_CH17_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH17_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_DOE_SHIFT)) & DMA_CH17_ES_DOE_MASK)

#define DMA_CH17_ES_DAE_MASK                     (0x20U)
#define DMA_CH17_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH17_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_DAE_SHIFT)) & DMA_CH17_ES_DAE_MASK)

#define DMA_CH17_ES_SOE_MASK                     (0x40U)
#define DMA_CH17_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH17_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_SOE_SHIFT)) & DMA_CH17_ES_SOE_MASK)

#define DMA_CH17_ES_SAE_MASK                     (0x80U)
#define DMA_CH17_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH17_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_SAE_SHIFT)) & DMA_CH17_ES_SAE_MASK)

#define DMA_CH17_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH17_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH17_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH17_ES_ERR_SHIFT)) & DMA_CH17_ES_ERR_MASK)
/*! @} */

/*! @name CH17_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH17_INT_INT_MASK                    (0x1U)
#define DMA_CH17_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH17_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_INT_INT_SHIFT)) & DMA_CH17_INT_INT_MASK)
/*! @} */

/*! @name CH17_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH17_SBR_MID_MASK                    (0xFU)
#define DMA_CH17_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH17_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_SBR_MID_SHIFT)) & DMA_CH17_SBR_MID_MASK)

#define DMA_CH17_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH17_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH17_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_SBR_PAL_SHIFT)) & DMA_CH17_SBR_PAL_MASK)

#define DMA_CH17_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH17_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH17_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_SBR_EMI_SHIFT)) & DMA_CH17_SBR_EMI_MASK)

#define DMA_CH17_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH17_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH17_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH17_SBR_ATTR_SHIFT)) & DMA_CH17_SBR_ATTR_MASK)
/*! @} */

/*! @name CH17_PRI - Channel Priority */
/*! @{ */

#define DMA_CH17_PRI_APL_MASK                    (0x7U)
#define DMA_CH17_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH17_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_PRI_APL_SHIFT)) & DMA_CH17_PRI_APL_MASK)

#define DMA_CH17_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH17_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH17_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_PRI_DPA_SHIFT)) & DMA_CH17_PRI_DPA_MASK)

#define DMA_CH17_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH17_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH17_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH17_PRI_ECP_SHIFT)) & DMA_CH17_PRI_ECP_MASK)
/*! @} */

/*! @name TCD17_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD17_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD17_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD17_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_SADDR_SADDR_SHIFT)) & DMA_TCD17_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD17_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD17_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD17_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD17_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_SOFF_SOFF_SHIFT)) & DMA_TCD17_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD17_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD17_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD17_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD17_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_ATTR_DSIZE_SHIFT)) & DMA_TCD17_ATTR_DSIZE_MASK)

#define DMA_TCD17_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD17_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD17_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_ATTR_DMOD_SHIFT)) & DMA_TCD17_ATTR_DMOD_MASK)

#define DMA_TCD17_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD17_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD17_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_ATTR_SSIZE_SHIFT)) & DMA_TCD17_ATTR_SSIZE_MASK)

#define DMA_TCD17_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD17_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD17_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_ATTR_SMOD_SHIFT)) & DMA_TCD17_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD17_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD17_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD17_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD17_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD17_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD17_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD17_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD17_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD17_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD17_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD17_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD17_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD17_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD17_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD17_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD17_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD17_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD17_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD17_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD17_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD17_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD17_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD17_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD17_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD17_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD17_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD17_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD17_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD17_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD17_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD17_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD17_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD17_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD17_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD17_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD17_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD17_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD17_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD17_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_DADDR_DADDR_SHIFT)) & DMA_TCD17_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD17_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD17_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD17_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD17_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_DOFF_DOFF_SHIFT)) & DMA_TCD17_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD17_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD17_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD17_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD17_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD17_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD17_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD17_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD17_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD17_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD17_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD17_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD17_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD17_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD17_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD17_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD17_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD17_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD17_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD17_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD17_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD17_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD17_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD17_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD17_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD17_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD17_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD17_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD17_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD17_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD17_CSR_START_MASK                 (0x1U)
#define DMA_TCD17_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD17_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_START_SHIFT)) & DMA_TCD17_CSR_START_MASK)

#define DMA_TCD17_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD17_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD17_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_INTMAJOR_SHIFT)) & DMA_TCD17_CSR_INTMAJOR_MASK)

#define DMA_TCD17_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD17_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD17_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_INTHALF_SHIFT)) & DMA_TCD17_CSR_INTHALF_MASK)

#define DMA_TCD17_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD17_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD17_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_DREQ_SHIFT)) & DMA_TCD17_CSR_DREQ_MASK)

#define DMA_TCD17_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD17_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD17_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_ESG_SHIFT)) & DMA_TCD17_CSR_ESG_MASK)

#define DMA_TCD17_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD17_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD17_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_MAJORELINK_SHIFT)) & DMA_TCD17_CSR_MAJORELINK_MASK)

#define DMA_TCD17_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD17_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD17_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_EEOP_SHIFT)) & DMA_TCD17_CSR_EEOP_MASK)

#define DMA_TCD17_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD17_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD17_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_ESDA_SHIFT)) & DMA_TCD17_CSR_ESDA_MASK)

#define DMA_TCD17_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD17_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD17_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD17_CSR_MAJORLINKCH_MASK)

#define DMA_TCD17_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD17_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD17_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_CSR_BWC_SHIFT)) & DMA_TCD17_CSR_BWC_MASK)
/*! @} */

/*! @name TCD17_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD17_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD17_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD17_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD17_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD17_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD17_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD17_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD17_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD17_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD17_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD17_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD17_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD17_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD17_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD17_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD17_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD17_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD17_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD17_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD17_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD17_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD17_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH18_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH18_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH18_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH18_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_CSR_ERQ_SHIFT)) & DMA_CH18_CSR_ERQ_MASK)

#define DMA_CH18_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH18_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH18_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH18_CSR_EARQ_SHIFT)) & DMA_CH18_CSR_EARQ_MASK)

#define DMA_CH18_CSR_EEI_MASK                    (0x4U)
#define DMA_CH18_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH18_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_CSR_EEI_SHIFT)) & DMA_CH18_CSR_EEI_MASK)

#define DMA_CH18_CSR_EBW_MASK                    (0x8U)
#define DMA_CH18_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH18_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_CSR_EBW_SHIFT)) & DMA_CH18_CSR_EBW_MASK)

#define DMA_CH18_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH18_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH18_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH18_CSR_DONE_SHIFT)) & DMA_CH18_CSR_DONE_MASK)

#define DMA_CH18_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH18_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH18_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH18_CSR_ACTIVE_SHIFT)) & DMA_CH18_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH18_ES - Channel Error Status */
/*! @{ */

#define DMA_CH18_ES_DBE_MASK                     (0x1U)
#define DMA_CH18_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH18_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_DBE_SHIFT)) & DMA_CH18_ES_DBE_MASK)

#define DMA_CH18_ES_SBE_MASK                     (0x2U)
#define DMA_CH18_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH18_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_SBE_SHIFT)) & DMA_CH18_ES_SBE_MASK)

#define DMA_CH18_ES_SGE_MASK                     (0x4U)
#define DMA_CH18_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH18_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_SGE_SHIFT)) & DMA_CH18_ES_SGE_MASK)

#define DMA_CH18_ES_NCE_MASK                     (0x8U)
#define DMA_CH18_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH18_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_NCE_SHIFT)) & DMA_CH18_ES_NCE_MASK)

#define DMA_CH18_ES_DOE_MASK                     (0x10U)
#define DMA_CH18_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH18_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_DOE_SHIFT)) & DMA_CH18_ES_DOE_MASK)

#define DMA_CH18_ES_DAE_MASK                     (0x20U)
#define DMA_CH18_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH18_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_DAE_SHIFT)) & DMA_CH18_ES_DAE_MASK)

#define DMA_CH18_ES_SOE_MASK                     (0x40U)
#define DMA_CH18_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH18_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_SOE_SHIFT)) & DMA_CH18_ES_SOE_MASK)

#define DMA_CH18_ES_SAE_MASK                     (0x80U)
#define DMA_CH18_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH18_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_SAE_SHIFT)) & DMA_CH18_ES_SAE_MASK)

#define DMA_CH18_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH18_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH18_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH18_ES_ERR_SHIFT)) & DMA_CH18_ES_ERR_MASK)
/*! @} */

/*! @name CH18_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH18_INT_INT_MASK                    (0x1U)
#define DMA_CH18_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH18_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_INT_INT_SHIFT)) & DMA_CH18_INT_INT_MASK)
/*! @} */

/*! @name CH18_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH18_SBR_MID_MASK                    (0xFU)
#define DMA_CH18_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH18_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_SBR_MID_SHIFT)) & DMA_CH18_SBR_MID_MASK)

#define DMA_CH18_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH18_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH18_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_SBR_PAL_SHIFT)) & DMA_CH18_SBR_PAL_MASK)

#define DMA_CH18_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH18_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH18_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_SBR_EMI_SHIFT)) & DMA_CH18_SBR_EMI_MASK)

#define DMA_CH18_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH18_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH18_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH18_SBR_ATTR_SHIFT)) & DMA_CH18_SBR_ATTR_MASK)
/*! @} */

/*! @name CH18_PRI - Channel Priority */
/*! @{ */

#define DMA_CH18_PRI_APL_MASK                    (0x7U)
#define DMA_CH18_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH18_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_PRI_APL_SHIFT)) & DMA_CH18_PRI_APL_MASK)

#define DMA_CH18_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH18_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH18_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_PRI_DPA_SHIFT)) & DMA_CH18_PRI_DPA_MASK)

#define DMA_CH18_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH18_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH18_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH18_PRI_ECP_SHIFT)) & DMA_CH18_PRI_ECP_MASK)
/*! @} */

/*! @name TCD18_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD18_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD18_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD18_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_SADDR_SADDR_SHIFT)) & DMA_TCD18_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD18_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD18_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD18_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD18_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_SOFF_SOFF_SHIFT)) & DMA_TCD18_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD18_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD18_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD18_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD18_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_ATTR_DSIZE_SHIFT)) & DMA_TCD18_ATTR_DSIZE_MASK)

#define DMA_TCD18_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD18_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD18_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_ATTR_DMOD_SHIFT)) & DMA_TCD18_ATTR_DMOD_MASK)

#define DMA_TCD18_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD18_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD18_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_ATTR_SSIZE_SHIFT)) & DMA_TCD18_ATTR_SSIZE_MASK)

#define DMA_TCD18_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD18_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD18_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_ATTR_SMOD_SHIFT)) & DMA_TCD18_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD18_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD18_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD18_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD18_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD18_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD18_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD18_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD18_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD18_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD18_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD18_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD18_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD18_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD18_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD18_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD18_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD18_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD18_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD18_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD18_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD18_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD18_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD18_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD18_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD18_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD18_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD18_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD18_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD18_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD18_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD18_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD18_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD18_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD18_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD18_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD18_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD18_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD18_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD18_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_DADDR_DADDR_SHIFT)) & DMA_TCD18_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD18_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD18_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD18_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD18_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_DOFF_DOFF_SHIFT)) & DMA_TCD18_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD18_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD18_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD18_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD18_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD18_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD18_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD18_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD18_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD18_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD18_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD18_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD18_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD18_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD18_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD18_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD18_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD18_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD18_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD18_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD18_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD18_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD18_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD18_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD18_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD18_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD18_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD18_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD18_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD18_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD18_CSR_START_MASK                 (0x1U)
#define DMA_TCD18_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD18_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_START_SHIFT)) & DMA_TCD18_CSR_START_MASK)

#define DMA_TCD18_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD18_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD18_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_INTMAJOR_SHIFT)) & DMA_TCD18_CSR_INTMAJOR_MASK)

#define DMA_TCD18_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD18_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD18_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_INTHALF_SHIFT)) & DMA_TCD18_CSR_INTHALF_MASK)

#define DMA_TCD18_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD18_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD18_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_DREQ_SHIFT)) & DMA_TCD18_CSR_DREQ_MASK)

#define DMA_TCD18_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD18_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD18_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_ESG_SHIFT)) & DMA_TCD18_CSR_ESG_MASK)

#define DMA_TCD18_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD18_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD18_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_MAJORELINK_SHIFT)) & DMA_TCD18_CSR_MAJORELINK_MASK)

#define DMA_TCD18_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD18_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD18_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_EEOP_SHIFT)) & DMA_TCD18_CSR_EEOP_MASK)

#define DMA_TCD18_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD18_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD18_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_ESDA_SHIFT)) & DMA_TCD18_CSR_ESDA_MASK)

#define DMA_TCD18_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD18_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD18_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD18_CSR_MAJORLINKCH_MASK)

#define DMA_TCD18_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD18_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD18_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_CSR_BWC_SHIFT)) & DMA_TCD18_CSR_BWC_MASK)
/*! @} */

/*! @name TCD18_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD18_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD18_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD18_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD18_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD18_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD18_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD18_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD18_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD18_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD18_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD18_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD18_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD18_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD18_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD18_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD18_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD18_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD18_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD18_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD18_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD18_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD18_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH19_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH19_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH19_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH19_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_CSR_ERQ_SHIFT)) & DMA_CH19_CSR_ERQ_MASK)

#define DMA_CH19_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH19_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH19_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH19_CSR_EARQ_SHIFT)) & DMA_CH19_CSR_EARQ_MASK)

#define DMA_CH19_CSR_EEI_MASK                    (0x4U)
#define DMA_CH19_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH19_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_CSR_EEI_SHIFT)) & DMA_CH19_CSR_EEI_MASK)

#define DMA_CH19_CSR_EBW_MASK                    (0x8U)
#define DMA_CH19_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH19_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_CSR_EBW_SHIFT)) & DMA_CH19_CSR_EBW_MASK)

#define DMA_CH19_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH19_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH19_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH19_CSR_DONE_SHIFT)) & DMA_CH19_CSR_DONE_MASK)

#define DMA_CH19_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH19_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH19_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH19_CSR_ACTIVE_SHIFT)) & DMA_CH19_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH19_ES - Channel Error Status */
/*! @{ */

#define DMA_CH19_ES_DBE_MASK                     (0x1U)
#define DMA_CH19_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH19_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_DBE_SHIFT)) & DMA_CH19_ES_DBE_MASK)

#define DMA_CH19_ES_SBE_MASK                     (0x2U)
#define DMA_CH19_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH19_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_SBE_SHIFT)) & DMA_CH19_ES_SBE_MASK)

#define DMA_CH19_ES_SGE_MASK                     (0x4U)
#define DMA_CH19_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH19_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_SGE_SHIFT)) & DMA_CH19_ES_SGE_MASK)

#define DMA_CH19_ES_NCE_MASK                     (0x8U)
#define DMA_CH19_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH19_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_NCE_SHIFT)) & DMA_CH19_ES_NCE_MASK)

#define DMA_CH19_ES_DOE_MASK                     (0x10U)
#define DMA_CH19_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH19_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_DOE_SHIFT)) & DMA_CH19_ES_DOE_MASK)

#define DMA_CH19_ES_DAE_MASK                     (0x20U)
#define DMA_CH19_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH19_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_DAE_SHIFT)) & DMA_CH19_ES_DAE_MASK)

#define DMA_CH19_ES_SOE_MASK                     (0x40U)
#define DMA_CH19_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH19_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_SOE_SHIFT)) & DMA_CH19_ES_SOE_MASK)

#define DMA_CH19_ES_SAE_MASK                     (0x80U)
#define DMA_CH19_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH19_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_SAE_SHIFT)) & DMA_CH19_ES_SAE_MASK)

#define DMA_CH19_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH19_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH19_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH19_ES_ERR_SHIFT)) & DMA_CH19_ES_ERR_MASK)
/*! @} */

/*! @name CH19_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH19_INT_INT_MASK                    (0x1U)
#define DMA_CH19_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH19_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_INT_INT_SHIFT)) & DMA_CH19_INT_INT_MASK)
/*! @} */

/*! @name CH19_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH19_SBR_MID_MASK                    (0xFU)
#define DMA_CH19_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH19_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_SBR_MID_SHIFT)) & DMA_CH19_SBR_MID_MASK)

#define DMA_CH19_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH19_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH19_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_SBR_PAL_SHIFT)) & DMA_CH19_SBR_PAL_MASK)

#define DMA_CH19_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH19_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH19_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_SBR_EMI_SHIFT)) & DMA_CH19_SBR_EMI_MASK)

#define DMA_CH19_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH19_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH19_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH19_SBR_ATTR_SHIFT)) & DMA_CH19_SBR_ATTR_MASK)
/*! @} */

/*! @name CH19_PRI - Channel Priority */
/*! @{ */

#define DMA_CH19_PRI_APL_MASK                    (0x7U)
#define DMA_CH19_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH19_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_PRI_APL_SHIFT)) & DMA_CH19_PRI_APL_MASK)

#define DMA_CH19_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH19_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH19_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_PRI_DPA_SHIFT)) & DMA_CH19_PRI_DPA_MASK)

#define DMA_CH19_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH19_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH19_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH19_PRI_ECP_SHIFT)) & DMA_CH19_PRI_ECP_MASK)
/*! @} */

/*! @name TCD19_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD19_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD19_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD19_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_SADDR_SADDR_SHIFT)) & DMA_TCD19_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD19_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD19_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD19_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD19_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_SOFF_SOFF_SHIFT)) & DMA_TCD19_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD19_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD19_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD19_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD19_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_ATTR_DSIZE_SHIFT)) & DMA_TCD19_ATTR_DSIZE_MASK)

#define DMA_TCD19_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD19_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD19_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_ATTR_DMOD_SHIFT)) & DMA_TCD19_ATTR_DMOD_MASK)

#define DMA_TCD19_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD19_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD19_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_ATTR_SSIZE_SHIFT)) & DMA_TCD19_ATTR_SSIZE_MASK)

#define DMA_TCD19_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD19_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD19_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_ATTR_SMOD_SHIFT)) & DMA_TCD19_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD19_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD19_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD19_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD19_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD19_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD19_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD19_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD19_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD19_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD19_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD19_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD19_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD19_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD19_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD19_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD19_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD19_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD19_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD19_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD19_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD19_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD19_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD19_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD19_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD19_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD19_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD19_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD19_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD19_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD19_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD19_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD19_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD19_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD19_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD19_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD19_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD19_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD19_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD19_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_DADDR_DADDR_SHIFT)) & DMA_TCD19_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD19_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD19_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD19_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD19_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_DOFF_DOFF_SHIFT)) & DMA_TCD19_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD19_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD19_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD19_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD19_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD19_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD19_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD19_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD19_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD19_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD19_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD19_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD19_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD19_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD19_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD19_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD19_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD19_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD19_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD19_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD19_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD19_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD19_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD19_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD19_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD19_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD19_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD19_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD19_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD19_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD19_CSR_START_MASK                 (0x1U)
#define DMA_TCD19_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD19_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_START_SHIFT)) & DMA_TCD19_CSR_START_MASK)

#define DMA_TCD19_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD19_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD19_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_INTMAJOR_SHIFT)) & DMA_TCD19_CSR_INTMAJOR_MASK)

#define DMA_TCD19_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD19_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD19_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_INTHALF_SHIFT)) & DMA_TCD19_CSR_INTHALF_MASK)

#define DMA_TCD19_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD19_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD19_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_DREQ_SHIFT)) & DMA_TCD19_CSR_DREQ_MASK)

#define DMA_TCD19_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD19_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD19_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_ESG_SHIFT)) & DMA_TCD19_CSR_ESG_MASK)

#define DMA_TCD19_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD19_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD19_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_MAJORELINK_SHIFT)) & DMA_TCD19_CSR_MAJORELINK_MASK)

#define DMA_TCD19_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD19_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD19_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_EEOP_SHIFT)) & DMA_TCD19_CSR_EEOP_MASK)

#define DMA_TCD19_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD19_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD19_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_ESDA_SHIFT)) & DMA_TCD19_CSR_ESDA_MASK)

#define DMA_TCD19_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD19_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD19_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD19_CSR_MAJORLINKCH_MASK)

#define DMA_TCD19_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD19_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD19_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_CSR_BWC_SHIFT)) & DMA_TCD19_CSR_BWC_MASK)
/*! @} */

/*! @name TCD19_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD19_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD19_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD19_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD19_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD19_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD19_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD19_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD19_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD19_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD19_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD19_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD19_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD19_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD19_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD19_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD19_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD19_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD19_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD19_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD19_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD19_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD19_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH20_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH20_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH20_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH20_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_CSR_ERQ_SHIFT)) & DMA_CH20_CSR_ERQ_MASK)

#define DMA_CH20_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH20_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH20_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH20_CSR_EARQ_SHIFT)) & DMA_CH20_CSR_EARQ_MASK)

#define DMA_CH20_CSR_EEI_MASK                    (0x4U)
#define DMA_CH20_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH20_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_CSR_EEI_SHIFT)) & DMA_CH20_CSR_EEI_MASK)

#define DMA_CH20_CSR_EBW_MASK                    (0x8U)
#define DMA_CH20_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH20_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_CSR_EBW_SHIFT)) & DMA_CH20_CSR_EBW_MASK)

#define DMA_CH20_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH20_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH20_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH20_CSR_DONE_SHIFT)) & DMA_CH20_CSR_DONE_MASK)

#define DMA_CH20_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH20_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH20_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH20_CSR_ACTIVE_SHIFT)) & DMA_CH20_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH20_ES - Channel Error Status */
/*! @{ */

#define DMA_CH20_ES_DBE_MASK                     (0x1U)
#define DMA_CH20_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH20_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_DBE_SHIFT)) & DMA_CH20_ES_DBE_MASK)

#define DMA_CH20_ES_SBE_MASK                     (0x2U)
#define DMA_CH20_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH20_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_SBE_SHIFT)) & DMA_CH20_ES_SBE_MASK)

#define DMA_CH20_ES_SGE_MASK                     (0x4U)
#define DMA_CH20_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH20_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_SGE_SHIFT)) & DMA_CH20_ES_SGE_MASK)

#define DMA_CH20_ES_NCE_MASK                     (0x8U)
#define DMA_CH20_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH20_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_NCE_SHIFT)) & DMA_CH20_ES_NCE_MASK)

#define DMA_CH20_ES_DOE_MASK                     (0x10U)
#define DMA_CH20_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH20_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_DOE_SHIFT)) & DMA_CH20_ES_DOE_MASK)

#define DMA_CH20_ES_DAE_MASK                     (0x20U)
#define DMA_CH20_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH20_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_DAE_SHIFT)) & DMA_CH20_ES_DAE_MASK)

#define DMA_CH20_ES_SOE_MASK                     (0x40U)
#define DMA_CH20_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH20_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_SOE_SHIFT)) & DMA_CH20_ES_SOE_MASK)

#define DMA_CH20_ES_SAE_MASK                     (0x80U)
#define DMA_CH20_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH20_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_SAE_SHIFT)) & DMA_CH20_ES_SAE_MASK)

#define DMA_CH20_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH20_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH20_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH20_ES_ERR_SHIFT)) & DMA_CH20_ES_ERR_MASK)
/*! @} */

/*! @name CH20_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH20_INT_INT_MASK                    (0x1U)
#define DMA_CH20_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH20_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_INT_INT_SHIFT)) & DMA_CH20_INT_INT_MASK)
/*! @} */

/*! @name CH20_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH20_SBR_MID_MASK                    (0xFU)
#define DMA_CH20_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH20_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_SBR_MID_SHIFT)) & DMA_CH20_SBR_MID_MASK)

#define DMA_CH20_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH20_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH20_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_SBR_PAL_SHIFT)) & DMA_CH20_SBR_PAL_MASK)

#define DMA_CH20_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH20_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH20_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_SBR_EMI_SHIFT)) & DMA_CH20_SBR_EMI_MASK)

#define DMA_CH20_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH20_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH20_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH20_SBR_ATTR_SHIFT)) & DMA_CH20_SBR_ATTR_MASK)
/*! @} */

/*! @name CH20_PRI - Channel Priority */
/*! @{ */

#define DMA_CH20_PRI_APL_MASK                    (0x7U)
#define DMA_CH20_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH20_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_PRI_APL_SHIFT)) & DMA_CH20_PRI_APL_MASK)

#define DMA_CH20_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH20_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH20_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_PRI_DPA_SHIFT)) & DMA_CH20_PRI_DPA_MASK)

#define DMA_CH20_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH20_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH20_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH20_PRI_ECP_SHIFT)) & DMA_CH20_PRI_ECP_MASK)
/*! @} */

/*! @name TCD20_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD20_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD20_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD20_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_SADDR_SADDR_SHIFT)) & DMA_TCD20_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD20_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD20_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD20_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD20_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_SOFF_SOFF_SHIFT)) & DMA_TCD20_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD20_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD20_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD20_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD20_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_ATTR_DSIZE_SHIFT)) & DMA_TCD20_ATTR_DSIZE_MASK)

#define DMA_TCD20_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD20_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD20_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_ATTR_DMOD_SHIFT)) & DMA_TCD20_ATTR_DMOD_MASK)

#define DMA_TCD20_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD20_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD20_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_ATTR_SSIZE_SHIFT)) & DMA_TCD20_ATTR_SSIZE_MASK)

#define DMA_TCD20_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD20_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD20_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_ATTR_SMOD_SHIFT)) & DMA_TCD20_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD20_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD20_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD20_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD20_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD20_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD20_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD20_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD20_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD20_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD20_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD20_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD20_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD20_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD20_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD20_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD20_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD20_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD20_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD20_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD20_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD20_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD20_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD20_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD20_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD20_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD20_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD20_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD20_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD20_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD20_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD20_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD20_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD20_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD20_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD20_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD20_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD20_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD20_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD20_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_DADDR_DADDR_SHIFT)) & DMA_TCD20_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD20_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD20_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD20_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD20_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_DOFF_DOFF_SHIFT)) & DMA_TCD20_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD20_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD20_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD20_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD20_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD20_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD20_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD20_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD20_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD20_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD20_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD20_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD20_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD20_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD20_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD20_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD20_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD20_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD20_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD20_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD20_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD20_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD20_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD20_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD20_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD20_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD20_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD20_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD20_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD20_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD20_CSR_START_MASK                 (0x1U)
#define DMA_TCD20_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD20_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_START_SHIFT)) & DMA_TCD20_CSR_START_MASK)

#define DMA_TCD20_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD20_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD20_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_INTMAJOR_SHIFT)) & DMA_TCD20_CSR_INTMAJOR_MASK)

#define DMA_TCD20_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD20_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD20_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_INTHALF_SHIFT)) & DMA_TCD20_CSR_INTHALF_MASK)

#define DMA_TCD20_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD20_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD20_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_DREQ_SHIFT)) & DMA_TCD20_CSR_DREQ_MASK)

#define DMA_TCD20_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD20_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD20_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_ESG_SHIFT)) & DMA_TCD20_CSR_ESG_MASK)

#define DMA_TCD20_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD20_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD20_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_MAJORELINK_SHIFT)) & DMA_TCD20_CSR_MAJORELINK_MASK)

#define DMA_TCD20_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD20_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD20_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_EEOP_SHIFT)) & DMA_TCD20_CSR_EEOP_MASK)

#define DMA_TCD20_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD20_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD20_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_ESDA_SHIFT)) & DMA_TCD20_CSR_ESDA_MASK)

#define DMA_TCD20_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD20_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD20_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD20_CSR_MAJORLINKCH_MASK)

#define DMA_TCD20_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD20_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD20_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_CSR_BWC_SHIFT)) & DMA_TCD20_CSR_BWC_MASK)
/*! @} */

/*! @name TCD20_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD20_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD20_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD20_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD20_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD20_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD20_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD20_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD20_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD20_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD20_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD20_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD20_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD20_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD20_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD20_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD20_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD20_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD20_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD20_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD20_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD20_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD20_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH21_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH21_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH21_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH21_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_CSR_ERQ_SHIFT)) & DMA_CH21_CSR_ERQ_MASK)

#define DMA_CH21_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH21_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH21_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH21_CSR_EARQ_SHIFT)) & DMA_CH21_CSR_EARQ_MASK)

#define DMA_CH21_CSR_EEI_MASK                    (0x4U)
#define DMA_CH21_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH21_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_CSR_EEI_SHIFT)) & DMA_CH21_CSR_EEI_MASK)

#define DMA_CH21_CSR_EBW_MASK                    (0x8U)
#define DMA_CH21_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH21_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_CSR_EBW_SHIFT)) & DMA_CH21_CSR_EBW_MASK)

#define DMA_CH21_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH21_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH21_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH21_CSR_DONE_SHIFT)) & DMA_CH21_CSR_DONE_MASK)

#define DMA_CH21_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH21_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH21_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH21_CSR_ACTIVE_SHIFT)) & DMA_CH21_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH21_ES - Channel Error Status */
/*! @{ */

#define DMA_CH21_ES_DBE_MASK                     (0x1U)
#define DMA_CH21_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH21_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_DBE_SHIFT)) & DMA_CH21_ES_DBE_MASK)

#define DMA_CH21_ES_SBE_MASK                     (0x2U)
#define DMA_CH21_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH21_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_SBE_SHIFT)) & DMA_CH21_ES_SBE_MASK)

#define DMA_CH21_ES_SGE_MASK                     (0x4U)
#define DMA_CH21_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH21_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_SGE_SHIFT)) & DMA_CH21_ES_SGE_MASK)

#define DMA_CH21_ES_NCE_MASK                     (0x8U)
#define DMA_CH21_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH21_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_NCE_SHIFT)) & DMA_CH21_ES_NCE_MASK)

#define DMA_CH21_ES_DOE_MASK                     (0x10U)
#define DMA_CH21_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH21_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_DOE_SHIFT)) & DMA_CH21_ES_DOE_MASK)

#define DMA_CH21_ES_DAE_MASK                     (0x20U)
#define DMA_CH21_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH21_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_DAE_SHIFT)) & DMA_CH21_ES_DAE_MASK)

#define DMA_CH21_ES_SOE_MASK                     (0x40U)
#define DMA_CH21_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH21_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_SOE_SHIFT)) & DMA_CH21_ES_SOE_MASK)

#define DMA_CH21_ES_SAE_MASK                     (0x80U)
#define DMA_CH21_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH21_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_SAE_SHIFT)) & DMA_CH21_ES_SAE_MASK)

#define DMA_CH21_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH21_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH21_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH21_ES_ERR_SHIFT)) & DMA_CH21_ES_ERR_MASK)
/*! @} */

/*! @name CH21_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH21_INT_INT_MASK                    (0x1U)
#define DMA_CH21_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH21_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_INT_INT_SHIFT)) & DMA_CH21_INT_INT_MASK)
/*! @} */

/*! @name CH21_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH21_SBR_MID_MASK                    (0xFU)
#define DMA_CH21_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH21_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_SBR_MID_SHIFT)) & DMA_CH21_SBR_MID_MASK)

#define DMA_CH21_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH21_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH21_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_SBR_PAL_SHIFT)) & DMA_CH21_SBR_PAL_MASK)

#define DMA_CH21_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH21_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH21_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_SBR_EMI_SHIFT)) & DMA_CH21_SBR_EMI_MASK)

#define DMA_CH21_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH21_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH21_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH21_SBR_ATTR_SHIFT)) & DMA_CH21_SBR_ATTR_MASK)
/*! @} */

/*! @name CH21_PRI - Channel Priority */
/*! @{ */

#define DMA_CH21_PRI_APL_MASK                    (0x7U)
#define DMA_CH21_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH21_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_PRI_APL_SHIFT)) & DMA_CH21_PRI_APL_MASK)

#define DMA_CH21_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH21_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH21_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_PRI_DPA_SHIFT)) & DMA_CH21_PRI_DPA_MASK)

#define DMA_CH21_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH21_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH21_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH21_PRI_ECP_SHIFT)) & DMA_CH21_PRI_ECP_MASK)
/*! @} */

/*! @name TCD21_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD21_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD21_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD21_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_SADDR_SADDR_SHIFT)) & DMA_TCD21_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD21_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD21_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD21_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD21_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_SOFF_SOFF_SHIFT)) & DMA_TCD21_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD21_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD21_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD21_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD21_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_ATTR_DSIZE_SHIFT)) & DMA_TCD21_ATTR_DSIZE_MASK)

#define DMA_TCD21_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD21_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD21_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_ATTR_DMOD_SHIFT)) & DMA_TCD21_ATTR_DMOD_MASK)

#define DMA_TCD21_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD21_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD21_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_ATTR_SSIZE_SHIFT)) & DMA_TCD21_ATTR_SSIZE_MASK)

#define DMA_TCD21_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD21_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD21_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_ATTR_SMOD_SHIFT)) & DMA_TCD21_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD21_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD21_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD21_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD21_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD21_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD21_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD21_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD21_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD21_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD21_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD21_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD21_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD21_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD21_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD21_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD21_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD21_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD21_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD21_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD21_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD21_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD21_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD21_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD21_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD21_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD21_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD21_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD21_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD21_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD21_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD21_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD21_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD21_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD21_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD21_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD21_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD21_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD21_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD21_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_DADDR_DADDR_SHIFT)) & DMA_TCD21_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD21_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD21_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD21_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD21_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_DOFF_DOFF_SHIFT)) & DMA_TCD21_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD21_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD21_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD21_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD21_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD21_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD21_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD21_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD21_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD21_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD21_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD21_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD21_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD21_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD21_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD21_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD21_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD21_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD21_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD21_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD21_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD21_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD21_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD21_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD21_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD21_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD21_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD21_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD21_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD21_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD21_CSR_START_MASK                 (0x1U)
#define DMA_TCD21_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD21_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_START_SHIFT)) & DMA_TCD21_CSR_START_MASK)

#define DMA_TCD21_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD21_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD21_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_INTMAJOR_SHIFT)) & DMA_TCD21_CSR_INTMAJOR_MASK)

#define DMA_TCD21_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD21_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD21_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_INTHALF_SHIFT)) & DMA_TCD21_CSR_INTHALF_MASK)

#define DMA_TCD21_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD21_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD21_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_DREQ_SHIFT)) & DMA_TCD21_CSR_DREQ_MASK)

#define DMA_TCD21_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD21_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD21_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_ESG_SHIFT)) & DMA_TCD21_CSR_ESG_MASK)

#define DMA_TCD21_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD21_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD21_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_MAJORELINK_SHIFT)) & DMA_TCD21_CSR_MAJORELINK_MASK)

#define DMA_TCD21_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD21_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD21_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_EEOP_SHIFT)) & DMA_TCD21_CSR_EEOP_MASK)

#define DMA_TCD21_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD21_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD21_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_ESDA_SHIFT)) & DMA_TCD21_CSR_ESDA_MASK)

#define DMA_TCD21_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD21_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD21_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD21_CSR_MAJORLINKCH_MASK)

#define DMA_TCD21_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD21_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD21_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_CSR_BWC_SHIFT)) & DMA_TCD21_CSR_BWC_MASK)
/*! @} */

/*! @name TCD21_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD21_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD21_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD21_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD21_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD21_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD21_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD21_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD21_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD21_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD21_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD21_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD21_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD21_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD21_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD21_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD21_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD21_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD21_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD21_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD21_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD21_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD21_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH22_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH22_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH22_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH22_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_CSR_ERQ_SHIFT)) & DMA_CH22_CSR_ERQ_MASK)

#define DMA_CH22_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH22_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH22_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH22_CSR_EARQ_SHIFT)) & DMA_CH22_CSR_EARQ_MASK)

#define DMA_CH22_CSR_EEI_MASK                    (0x4U)
#define DMA_CH22_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH22_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_CSR_EEI_SHIFT)) & DMA_CH22_CSR_EEI_MASK)

#define DMA_CH22_CSR_EBW_MASK                    (0x8U)
#define DMA_CH22_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH22_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_CSR_EBW_SHIFT)) & DMA_CH22_CSR_EBW_MASK)

#define DMA_CH22_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH22_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH22_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH22_CSR_DONE_SHIFT)) & DMA_CH22_CSR_DONE_MASK)

#define DMA_CH22_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH22_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH22_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH22_CSR_ACTIVE_SHIFT)) & DMA_CH22_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH22_ES - Channel Error Status */
/*! @{ */

#define DMA_CH22_ES_DBE_MASK                     (0x1U)
#define DMA_CH22_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH22_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_DBE_SHIFT)) & DMA_CH22_ES_DBE_MASK)

#define DMA_CH22_ES_SBE_MASK                     (0x2U)
#define DMA_CH22_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH22_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_SBE_SHIFT)) & DMA_CH22_ES_SBE_MASK)

#define DMA_CH22_ES_SGE_MASK                     (0x4U)
#define DMA_CH22_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH22_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_SGE_SHIFT)) & DMA_CH22_ES_SGE_MASK)

#define DMA_CH22_ES_NCE_MASK                     (0x8U)
#define DMA_CH22_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH22_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_NCE_SHIFT)) & DMA_CH22_ES_NCE_MASK)

#define DMA_CH22_ES_DOE_MASK                     (0x10U)
#define DMA_CH22_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH22_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_DOE_SHIFT)) & DMA_CH22_ES_DOE_MASK)

#define DMA_CH22_ES_DAE_MASK                     (0x20U)
#define DMA_CH22_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH22_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_DAE_SHIFT)) & DMA_CH22_ES_DAE_MASK)

#define DMA_CH22_ES_SOE_MASK                     (0x40U)
#define DMA_CH22_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH22_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_SOE_SHIFT)) & DMA_CH22_ES_SOE_MASK)

#define DMA_CH22_ES_SAE_MASK                     (0x80U)
#define DMA_CH22_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH22_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_SAE_SHIFT)) & DMA_CH22_ES_SAE_MASK)

#define DMA_CH22_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH22_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH22_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH22_ES_ERR_SHIFT)) & DMA_CH22_ES_ERR_MASK)
/*! @} */

/*! @name CH22_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH22_INT_INT_MASK                    (0x1U)
#define DMA_CH22_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH22_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_INT_INT_SHIFT)) & DMA_CH22_INT_INT_MASK)
/*! @} */

/*! @name CH22_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH22_SBR_MID_MASK                    (0xFU)
#define DMA_CH22_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH22_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_SBR_MID_SHIFT)) & DMA_CH22_SBR_MID_MASK)

#define DMA_CH22_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH22_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH22_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_SBR_PAL_SHIFT)) & DMA_CH22_SBR_PAL_MASK)

#define DMA_CH22_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH22_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH22_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_SBR_EMI_SHIFT)) & DMA_CH22_SBR_EMI_MASK)

#define DMA_CH22_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH22_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH22_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH22_SBR_ATTR_SHIFT)) & DMA_CH22_SBR_ATTR_MASK)
/*! @} */

/*! @name CH22_PRI - Channel Priority */
/*! @{ */

#define DMA_CH22_PRI_APL_MASK                    (0x7U)
#define DMA_CH22_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH22_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_PRI_APL_SHIFT)) & DMA_CH22_PRI_APL_MASK)

#define DMA_CH22_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH22_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH22_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_PRI_DPA_SHIFT)) & DMA_CH22_PRI_DPA_MASK)

#define DMA_CH22_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH22_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH22_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH22_PRI_ECP_SHIFT)) & DMA_CH22_PRI_ECP_MASK)
/*! @} */

/*! @name TCD22_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD22_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD22_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD22_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_SADDR_SADDR_SHIFT)) & DMA_TCD22_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD22_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD22_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD22_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD22_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_SOFF_SOFF_SHIFT)) & DMA_TCD22_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD22_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD22_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD22_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD22_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_ATTR_DSIZE_SHIFT)) & DMA_TCD22_ATTR_DSIZE_MASK)

#define DMA_TCD22_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD22_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD22_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_ATTR_DMOD_SHIFT)) & DMA_TCD22_ATTR_DMOD_MASK)

#define DMA_TCD22_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD22_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD22_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_ATTR_SSIZE_SHIFT)) & DMA_TCD22_ATTR_SSIZE_MASK)

#define DMA_TCD22_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD22_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD22_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_ATTR_SMOD_SHIFT)) & DMA_TCD22_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD22_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD22_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD22_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD22_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD22_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD22_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD22_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD22_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD22_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD22_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD22_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD22_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD22_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD22_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD22_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD22_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD22_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD22_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD22_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD22_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD22_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD22_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD22_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD22_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD22_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD22_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD22_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD22_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD22_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD22_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD22_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD22_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD22_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD22_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD22_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD22_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD22_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD22_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD22_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_DADDR_DADDR_SHIFT)) & DMA_TCD22_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD22_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD22_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD22_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD22_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_DOFF_DOFF_SHIFT)) & DMA_TCD22_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD22_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD22_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD22_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD22_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD22_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD22_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD22_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD22_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD22_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD22_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD22_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD22_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD22_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD22_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD22_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD22_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD22_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD22_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD22_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD22_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD22_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD22_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD22_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD22_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD22_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD22_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD22_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD22_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD22_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD22_CSR_START_MASK                 (0x1U)
#define DMA_TCD22_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD22_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_START_SHIFT)) & DMA_TCD22_CSR_START_MASK)

#define DMA_TCD22_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD22_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD22_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_INTMAJOR_SHIFT)) & DMA_TCD22_CSR_INTMAJOR_MASK)

#define DMA_TCD22_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD22_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD22_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_INTHALF_SHIFT)) & DMA_TCD22_CSR_INTHALF_MASK)

#define DMA_TCD22_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD22_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD22_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_DREQ_SHIFT)) & DMA_TCD22_CSR_DREQ_MASK)

#define DMA_TCD22_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD22_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD22_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_ESG_SHIFT)) & DMA_TCD22_CSR_ESG_MASK)

#define DMA_TCD22_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD22_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD22_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_MAJORELINK_SHIFT)) & DMA_TCD22_CSR_MAJORELINK_MASK)

#define DMA_TCD22_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD22_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD22_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_EEOP_SHIFT)) & DMA_TCD22_CSR_EEOP_MASK)

#define DMA_TCD22_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD22_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD22_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_ESDA_SHIFT)) & DMA_TCD22_CSR_ESDA_MASK)

#define DMA_TCD22_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD22_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD22_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD22_CSR_MAJORLINKCH_MASK)

#define DMA_TCD22_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD22_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD22_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_CSR_BWC_SHIFT)) & DMA_TCD22_CSR_BWC_MASK)
/*! @} */

/*! @name TCD22_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD22_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD22_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD22_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD22_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD22_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD22_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD22_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD22_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD22_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD22_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD22_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD22_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD22_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD22_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD22_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD22_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD22_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD22_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD22_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD22_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD22_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD22_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH23_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH23_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH23_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH23_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_CSR_ERQ_SHIFT)) & DMA_CH23_CSR_ERQ_MASK)

#define DMA_CH23_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH23_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH23_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH23_CSR_EARQ_SHIFT)) & DMA_CH23_CSR_EARQ_MASK)

#define DMA_CH23_CSR_EEI_MASK                    (0x4U)
#define DMA_CH23_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH23_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_CSR_EEI_SHIFT)) & DMA_CH23_CSR_EEI_MASK)

#define DMA_CH23_CSR_EBW_MASK                    (0x8U)
#define DMA_CH23_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH23_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_CSR_EBW_SHIFT)) & DMA_CH23_CSR_EBW_MASK)

#define DMA_CH23_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH23_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH23_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH23_CSR_DONE_SHIFT)) & DMA_CH23_CSR_DONE_MASK)

#define DMA_CH23_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH23_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH23_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH23_CSR_ACTIVE_SHIFT)) & DMA_CH23_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH23_ES - Channel Error Status */
/*! @{ */

#define DMA_CH23_ES_DBE_MASK                     (0x1U)
#define DMA_CH23_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH23_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_DBE_SHIFT)) & DMA_CH23_ES_DBE_MASK)

#define DMA_CH23_ES_SBE_MASK                     (0x2U)
#define DMA_CH23_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH23_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_SBE_SHIFT)) & DMA_CH23_ES_SBE_MASK)

#define DMA_CH23_ES_SGE_MASK                     (0x4U)
#define DMA_CH23_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH23_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_SGE_SHIFT)) & DMA_CH23_ES_SGE_MASK)

#define DMA_CH23_ES_NCE_MASK                     (0x8U)
#define DMA_CH23_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH23_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_NCE_SHIFT)) & DMA_CH23_ES_NCE_MASK)

#define DMA_CH23_ES_DOE_MASK                     (0x10U)
#define DMA_CH23_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH23_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_DOE_SHIFT)) & DMA_CH23_ES_DOE_MASK)

#define DMA_CH23_ES_DAE_MASK                     (0x20U)
#define DMA_CH23_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH23_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_DAE_SHIFT)) & DMA_CH23_ES_DAE_MASK)

#define DMA_CH23_ES_SOE_MASK                     (0x40U)
#define DMA_CH23_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH23_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_SOE_SHIFT)) & DMA_CH23_ES_SOE_MASK)

#define DMA_CH23_ES_SAE_MASK                     (0x80U)
#define DMA_CH23_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH23_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_SAE_SHIFT)) & DMA_CH23_ES_SAE_MASK)

#define DMA_CH23_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH23_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH23_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH23_ES_ERR_SHIFT)) & DMA_CH23_ES_ERR_MASK)
/*! @} */

/*! @name CH23_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH23_INT_INT_MASK                    (0x1U)
#define DMA_CH23_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH23_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_INT_INT_SHIFT)) & DMA_CH23_INT_INT_MASK)
/*! @} */

/*! @name CH23_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH23_SBR_MID_MASK                    (0xFU)
#define DMA_CH23_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH23_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_SBR_MID_SHIFT)) & DMA_CH23_SBR_MID_MASK)

#define DMA_CH23_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH23_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH23_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_SBR_PAL_SHIFT)) & DMA_CH23_SBR_PAL_MASK)

#define DMA_CH23_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH23_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH23_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_SBR_EMI_SHIFT)) & DMA_CH23_SBR_EMI_MASK)

#define DMA_CH23_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH23_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH23_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH23_SBR_ATTR_SHIFT)) & DMA_CH23_SBR_ATTR_MASK)
/*! @} */

/*! @name CH23_PRI - Channel Priority */
/*! @{ */

#define DMA_CH23_PRI_APL_MASK                    (0x7U)
#define DMA_CH23_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH23_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_PRI_APL_SHIFT)) & DMA_CH23_PRI_APL_MASK)

#define DMA_CH23_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH23_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH23_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_PRI_DPA_SHIFT)) & DMA_CH23_PRI_DPA_MASK)

#define DMA_CH23_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH23_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH23_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH23_PRI_ECP_SHIFT)) & DMA_CH23_PRI_ECP_MASK)
/*! @} */

/*! @name TCD23_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD23_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD23_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD23_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_SADDR_SADDR_SHIFT)) & DMA_TCD23_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD23_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD23_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD23_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD23_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_SOFF_SOFF_SHIFT)) & DMA_TCD23_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD23_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD23_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD23_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD23_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_ATTR_DSIZE_SHIFT)) & DMA_TCD23_ATTR_DSIZE_MASK)

#define DMA_TCD23_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD23_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD23_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_ATTR_DMOD_SHIFT)) & DMA_TCD23_ATTR_DMOD_MASK)

#define DMA_TCD23_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD23_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD23_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_ATTR_SSIZE_SHIFT)) & DMA_TCD23_ATTR_SSIZE_MASK)

#define DMA_TCD23_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD23_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD23_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_ATTR_SMOD_SHIFT)) & DMA_TCD23_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD23_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD23_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD23_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD23_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD23_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD23_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD23_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD23_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD23_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD23_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD23_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD23_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD23_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD23_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD23_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD23_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD23_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD23_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD23_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD23_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD23_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD23_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD23_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD23_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD23_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD23_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD23_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD23_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD23_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD23_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD23_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD23_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD23_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD23_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD23_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD23_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD23_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD23_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD23_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_DADDR_DADDR_SHIFT)) & DMA_TCD23_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD23_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD23_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD23_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD23_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_DOFF_DOFF_SHIFT)) & DMA_TCD23_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD23_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD23_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD23_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD23_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD23_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD23_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD23_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD23_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD23_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD23_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD23_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD23_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD23_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD23_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD23_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD23_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD23_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD23_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD23_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD23_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD23_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD23_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD23_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD23_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD23_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD23_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD23_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD23_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD23_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD23_CSR_START_MASK                 (0x1U)
#define DMA_TCD23_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD23_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_START_SHIFT)) & DMA_TCD23_CSR_START_MASK)

#define DMA_TCD23_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD23_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD23_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_INTMAJOR_SHIFT)) & DMA_TCD23_CSR_INTMAJOR_MASK)

#define DMA_TCD23_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD23_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD23_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_INTHALF_SHIFT)) & DMA_TCD23_CSR_INTHALF_MASK)

#define DMA_TCD23_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD23_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD23_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_DREQ_SHIFT)) & DMA_TCD23_CSR_DREQ_MASK)

#define DMA_TCD23_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD23_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD23_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_ESG_SHIFT)) & DMA_TCD23_CSR_ESG_MASK)

#define DMA_TCD23_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD23_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD23_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_MAJORELINK_SHIFT)) & DMA_TCD23_CSR_MAJORELINK_MASK)

#define DMA_TCD23_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD23_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD23_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_EEOP_SHIFT)) & DMA_TCD23_CSR_EEOP_MASK)

#define DMA_TCD23_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD23_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD23_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_ESDA_SHIFT)) & DMA_TCD23_CSR_ESDA_MASK)

#define DMA_TCD23_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD23_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD23_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD23_CSR_MAJORLINKCH_MASK)

#define DMA_TCD23_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD23_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD23_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_CSR_BWC_SHIFT)) & DMA_TCD23_CSR_BWC_MASK)
/*! @} */

/*! @name TCD23_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD23_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD23_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD23_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD23_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD23_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD23_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD23_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD23_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD23_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD23_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD23_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD23_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD23_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD23_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD23_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD23_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD23_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD23_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD23_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD23_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD23_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD23_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH24_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH24_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH24_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH24_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_CSR_ERQ_SHIFT)) & DMA_CH24_CSR_ERQ_MASK)

#define DMA_CH24_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH24_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH24_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH24_CSR_EARQ_SHIFT)) & DMA_CH24_CSR_EARQ_MASK)

#define DMA_CH24_CSR_EEI_MASK                    (0x4U)
#define DMA_CH24_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH24_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_CSR_EEI_SHIFT)) & DMA_CH24_CSR_EEI_MASK)

#define DMA_CH24_CSR_EBW_MASK                    (0x8U)
#define DMA_CH24_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH24_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_CSR_EBW_SHIFT)) & DMA_CH24_CSR_EBW_MASK)

#define DMA_CH24_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH24_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH24_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH24_CSR_DONE_SHIFT)) & DMA_CH24_CSR_DONE_MASK)

#define DMA_CH24_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH24_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH24_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH24_CSR_ACTIVE_SHIFT)) & DMA_CH24_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH24_ES - Channel Error Status */
/*! @{ */

#define DMA_CH24_ES_DBE_MASK                     (0x1U)
#define DMA_CH24_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH24_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_DBE_SHIFT)) & DMA_CH24_ES_DBE_MASK)

#define DMA_CH24_ES_SBE_MASK                     (0x2U)
#define DMA_CH24_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH24_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_SBE_SHIFT)) & DMA_CH24_ES_SBE_MASK)

#define DMA_CH24_ES_SGE_MASK                     (0x4U)
#define DMA_CH24_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH24_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_SGE_SHIFT)) & DMA_CH24_ES_SGE_MASK)

#define DMA_CH24_ES_NCE_MASK                     (0x8U)
#define DMA_CH24_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH24_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_NCE_SHIFT)) & DMA_CH24_ES_NCE_MASK)

#define DMA_CH24_ES_DOE_MASK                     (0x10U)
#define DMA_CH24_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH24_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_DOE_SHIFT)) & DMA_CH24_ES_DOE_MASK)

#define DMA_CH24_ES_DAE_MASK                     (0x20U)
#define DMA_CH24_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH24_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_DAE_SHIFT)) & DMA_CH24_ES_DAE_MASK)

#define DMA_CH24_ES_SOE_MASK                     (0x40U)
#define DMA_CH24_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH24_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_SOE_SHIFT)) & DMA_CH24_ES_SOE_MASK)

#define DMA_CH24_ES_SAE_MASK                     (0x80U)
#define DMA_CH24_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH24_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_SAE_SHIFT)) & DMA_CH24_ES_SAE_MASK)

#define DMA_CH24_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH24_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH24_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH24_ES_ERR_SHIFT)) & DMA_CH24_ES_ERR_MASK)
/*! @} */

/*! @name CH24_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH24_INT_INT_MASK                    (0x1U)
#define DMA_CH24_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH24_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_INT_INT_SHIFT)) & DMA_CH24_INT_INT_MASK)
/*! @} */

/*! @name CH24_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH24_SBR_MID_MASK                    (0xFU)
#define DMA_CH24_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH24_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_SBR_MID_SHIFT)) & DMA_CH24_SBR_MID_MASK)

#define DMA_CH24_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH24_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH24_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_SBR_PAL_SHIFT)) & DMA_CH24_SBR_PAL_MASK)

#define DMA_CH24_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH24_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH24_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_SBR_EMI_SHIFT)) & DMA_CH24_SBR_EMI_MASK)

#define DMA_CH24_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH24_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH24_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH24_SBR_ATTR_SHIFT)) & DMA_CH24_SBR_ATTR_MASK)
/*! @} */

/*! @name CH24_PRI - Channel Priority */
/*! @{ */

#define DMA_CH24_PRI_APL_MASK                    (0x7U)
#define DMA_CH24_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH24_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_PRI_APL_SHIFT)) & DMA_CH24_PRI_APL_MASK)

#define DMA_CH24_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH24_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH24_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_PRI_DPA_SHIFT)) & DMA_CH24_PRI_DPA_MASK)

#define DMA_CH24_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH24_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH24_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH24_PRI_ECP_SHIFT)) & DMA_CH24_PRI_ECP_MASK)
/*! @} */

/*! @name TCD24_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD24_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD24_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD24_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_SADDR_SADDR_SHIFT)) & DMA_TCD24_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD24_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD24_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD24_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD24_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_SOFF_SOFF_SHIFT)) & DMA_TCD24_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD24_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD24_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD24_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD24_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_ATTR_DSIZE_SHIFT)) & DMA_TCD24_ATTR_DSIZE_MASK)

#define DMA_TCD24_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD24_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD24_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_ATTR_DMOD_SHIFT)) & DMA_TCD24_ATTR_DMOD_MASK)

#define DMA_TCD24_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD24_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD24_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_ATTR_SSIZE_SHIFT)) & DMA_TCD24_ATTR_SSIZE_MASK)

#define DMA_TCD24_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD24_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD24_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_ATTR_SMOD_SHIFT)) & DMA_TCD24_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD24_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD24_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD24_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD24_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD24_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD24_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD24_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD24_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD24_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD24_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD24_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD24_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD24_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD24_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD24_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD24_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD24_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD24_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD24_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD24_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD24_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD24_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD24_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD24_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD24_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD24_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD24_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD24_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD24_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD24_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD24_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD24_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD24_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD24_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD24_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD24_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD24_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD24_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD24_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_DADDR_DADDR_SHIFT)) & DMA_TCD24_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD24_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD24_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD24_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD24_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_DOFF_DOFF_SHIFT)) & DMA_TCD24_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD24_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD24_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD24_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD24_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD24_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD24_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD24_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD24_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD24_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD24_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD24_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD24_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD24_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD24_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD24_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD24_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD24_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD24_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD24_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD24_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD24_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD24_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD24_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD24_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD24_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD24_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD24_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD24_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD24_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD24_CSR_START_MASK                 (0x1U)
#define DMA_TCD24_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD24_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_START_SHIFT)) & DMA_TCD24_CSR_START_MASK)

#define DMA_TCD24_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD24_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD24_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_INTMAJOR_SHIFT)) & DMA_TCD24_CSR_INTMAJOR_MASK)

#define DMA_TCD24_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD24_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD24_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_INTHALF_SHIFT)) & DMA_TCD24_CSR_INTHALF_MASK)

#define DMA_TCD24_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD24_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD24_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_DREQ_SHIFT)) & DMA_TCD24_CSR_DREQ_MASK)

#define DMA_TCD24_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD24_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD24_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_ESG_SHIFT)) & DMA_TCD24_CSR_ESG_MASK)

#define DMA_TCD24_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD24_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD24_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_MAJORELINK_SHIFT)) & DMA_TCD24_CSR_MAJORELINK_MASK)

#define DMA_TCD24_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD24_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD24_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_EEOP_SHIFT)) & DMA_TCD24_CSR_EEOP_MASK)

#define DMA_TCD24_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD24_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD24_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_ESDA_SHIFT)) & DMA_TCD24_CSR_ESDA_MASK)

#define DMA_TCD24_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD24_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD24_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD24_CSR_MAJORLINKCH_MASK)

#define DMA_TCD24_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD24_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD24_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_CSR_BWC_SHIFT)) & DMA_TCD24_CSR_BWC_MASK)
/*! @} */

/*! @name TCD24_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD24_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD24_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD24_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD24_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD24_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD24_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD24_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD24_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD24_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD24_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD24_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD24_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD24_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD24_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD24_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD24_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD24_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD24_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD24_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD24_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD24_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD24_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH25_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH25_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH25_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH25_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_CSR_ERQ_SHIFT)) & DMA_CH25_CSR_ERQ_MASK)

#define DMA_CH25_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH25_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH25_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH25_CSR_EARQ_SHIFT)) & DMA_CH25_CSR_EARQ_MASK)

#define DMA_CH25_CSR_EEI_MASK                    (0x4U)
#define DMA_CH25_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH25_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_CSR_EEI_SHIFT)) & DMA_CH25_CSR_EEI_MASK)

#define DMA_CH25_CSR_EBW_MASK                    (0x8U)
#define DMA_CH25_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH25_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_CSR_EBW_SHIFT)) & DMA_CH25_CSR_EBW_MASK)

#define DMA_CH25_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH25_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH25_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH25_CSR_DONE_SHIFT)) & DMA_CH25_CSR_DONE_MASK)

#define DMA_CH25_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH25_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH25_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH25_CSR_ACTIVE_SHIFT)) & DMA_CH25_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH25_ES - Channel Error Status */
/*! @{ */

#define DMA_CH25_ES_DBE_MASK                     (0x1U)
#define DMA_CH25_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH25_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_DBE_SHIFT)) & DMA_CH25_ES_DBE_MASK)

#define DMA_CH25_ES_SBE_MASK                     (0x2U)
#define DMA_CH25_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH25_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_SBE_SHIFT)) & DMA_CH25_ES_SBE_MASK)

#define DMA_CH25_ES_SGE_MASK                     (0x4U)
#define DMA_CH25_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH25_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_SGE_SHIFT)) & DMA_CH25_ES_SGE_MASK)

#define DMA_CH25_ES_NCE_MASK                     (0x8U)
#define DMA_CH25_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH25_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_NCE_SHIFT)) & DMA_CH25_ES_NCE_MASK)

#define DMA_CH25_ES_DOE_MASK                     (0x10U)
#define DMA_CH25_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH25_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_DOE_SHIFT)) & DMA_CH25_ES_DOE_MASK)

#define DMA_CH25_ES_DAE_MASK                     (0x20U)
#define DMA_CH25_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH25_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_DAE_SHIFT)) & DMA_CH25_ES_DAE_MASK)

#define DMA_CH25_ES_SOE_MASK                     (0x40U)
#define DMA_CH25_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH25_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_SOE_SHIFT)) & DMA_CH25_ES_SOE_MASK)

#define DMA_CH25_ES_SAE_MASK                     (0x80U)
#define DMA_CH25_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH25_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_SAE_SHIFT)) & DMA_CH25_ES_SAE_MASK)

#define DMA_CH25_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH25_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH25_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH25_ES_ERR_SHIFT)) & DMA_CH25_ES_ERR_MASK)
/*! @} */

/*! @name CH25_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH25_INT_INT_MASK                    (0x1U)
#define DMA_CH25_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH25_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_INT_INT_SHIFT)) & DMA_CH25_INT_INT_MASK)
/*! @} */

/*! @name CH25_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH25_SBR_MID_MASK                    (0xFU)
#define DMA_CH25_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH25_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_SBR_MID_SHIFT)) & DMA_CH25_SBR_MID_MASK)

#define DMA_CH25_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH25_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH25_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_SBR_PAL_SHIFT)) & DMA_CH25_SBR_PAL_MASK)

#define DMA_CH25_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH25_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH25_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_SBR_EMI_SHIFT)) & DMA_CH25_SBR_EMI_MASK)

#define DMA_CH25_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH25_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH25_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH25_SBR_ATTR_SHIFT)) & DMA_CH25_SBR_ATTR_MASK)
/*! @} */

/*! @name CH25_PRI - Channel Priority */
/*! @{ */

#define DMA_CH25_PRI_APL_MASK                    (0x7U)
#define DMA_CH25_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH25_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_PRI_APL_SHIFT)) & DMA_CH25_PRI_APL_MASK)

#define DMA_CH25_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH25_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH25_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_PRI_DPA_SHIFT)) & DMA_CH25_PRI_DPA_MASK)

#define DMA_CH25_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH25_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH25_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH25_PRI_ECP_SHIFT)) & DMA_CH25_PRI_ECP_MASK)
/*! @} */

/*! @name TCD25_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD25_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD25_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD25_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_SADDR_SADDR_SHIFT)) & DMA_TCD25_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD25_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD25_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD25_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD25_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_SOFF_SOFF_SHIFT)) & DMA_TCD25_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD25_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD25_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD25_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD25_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_ATTR_DSIZE_SHIFT)) & DMA_TCD25_ATTR_DSIZE_MASK)

#define DMA_TCD25_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD25_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD25_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_ATTR_DMOD_SHIFT)) & DMA_TCD25_ATTR_DMOD_MASK)

#define DMA_TCD25_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD25_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD25_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_ATTR_SSIZE_SHIFT)) & DMA_TCD25_ATTR_SSIZE_MASK)

#define DMA_TCD25_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD25_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD25_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_ATTR_SMOD_SHIFT)) & DMA_TCD25_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD25_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD25_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD25_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD25_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD25_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD25_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD25_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD25_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD25_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD25_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD25_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD25_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD25_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD25_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD25_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD25_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD25_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD25_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD25_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD25_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD25_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD25_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD25_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD25_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD25_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD25_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD25_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD25_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD25_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD25_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD25_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD25_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD25_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD25_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD25_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD25_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD25_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD25_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD25_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_DADDR_DADDR_SHIFT)) & DMA_TCD25_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD25_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD25_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD25_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD25_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_DOFF_DOFF_SHIFT)) & DMA_TCD25_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD25_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD25_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD25_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD25_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD25_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD25_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD25_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD25_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD25_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD25_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD25_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD25_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD25_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD25_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD25_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD25_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD25_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD25_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD25_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD25_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD25_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD25_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD25_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD25_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD25_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD25_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD25_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD25_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD25_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD25_CSR_START_MASK                 (0x1U)
#define DMA_TCD25_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD25_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_START_SHIFT)) & DMA_TCD25_CSR_START_MASK)

#define DMA_TCD25_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD25_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD25_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_INTMAJOR_SHIFT)) & DMA_TCD25_CSR_INTMAJOR_MASK)

#define DMA_TCD25_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD25_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD25_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_INTHALF_SHIFT)) & DMA_TCD25_CSR_INTHALF_MASK)

#define DMA_TCD25_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD25_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD25_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_DREQ_SHIFT)) & DMA_TCD25_CSR_DREQ_MASK)

#define DMA_TCD25_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD25_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD25_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_ESG_SHIFT)) & DMA_TCD25_CSR_ESG_MASK)

#define DMA_TCD25_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD25_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD25_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_MAJORELINK_SHIFT)) & DMA_TCD25_CSR_MAJORELINK_MASK)

#define DMA_TCD25_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD25_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD25_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_EEOP_SHIFT)) & DMA_TCD25_CSR_EEOP_MASK)

#define DMA_TCD25_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD25_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD25_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_ESDA_SHIFT)) & DMA_TCD25_CSR_ESDA_MASK)

#define DMA_TCD25_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD25_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD25_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD25_CSR_MAJORLINKCH_MASK)

#define DMA_TCD25_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD25_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD25_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_CSR_BWC_SHIFT)) & DMA_TCD25_CSR_BWC_MASK)
/*! @} */

/*! @name TCD25_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD25_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD25_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD25_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD25_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD25_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD25_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD25_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD25_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD25_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD25_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD25_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD25_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD25_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD25_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD25_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD25_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD25_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD25_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD25_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD25_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD25_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD25_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH26_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH26_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH26_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH26_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_CSR_ERQ_SHIFT)) & DMA_CH26_CSR_ERQ_MASK)

#define DMA_CH26_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH26_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH26_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH26_CSR_EARQ_SHIFT)) & DMA_CH26_CSR_EARQ_MASK)

#define DMA_CH26_CSR_EEI_MASK                    (0x4U)
#define DMA_CH26_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH26_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_CSR_EEI_SHIFT)) & DMA_CH26_CSR_EEI_MASK)

#define DMA_CH26_CSR_EBW_MASK                    (0x8U)
#define DMA_CH26_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH26_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_CSR_EBW_SHIFT)) & DMA_CH26_CSR_EBW_MASK)

#define DMA_CH26_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH26_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH26_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH26_CSR_DONE_SHIFT)) & DMA_CH26_CSR_DONE_MASK)

#define DMA_CH26_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH26_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH26_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH26_CSR_ACTIVE_SHIFT)) & DMA_CH26_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH26_ES - Channel Error Status */
/*! @{ */

#define DMA_CH26_ES_DBE_MASK                     (0x1U)
#define DMA_CH26_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH26_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_DBE_SHIFT)) & DMA_CH26_ES_DBE_MASK)

#define DMA_CH26_ES_SBE_MASK                     (0x2U)
#define DMA_CH26_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH26_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_SBE_SHIFT)) & DMA_CH26_ES_SBE_MASK)

#define DMA_CH26_ES_SGE_MASK                     (0x4U)
#define DMA_CH26_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH26_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_SGE_SHIFT)) & DMA_CH26_ES_SGE_MASK)

#define DMA_CH26_ES_NCE_MASK                     (0x8U)
#define DMA_CH26_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH26_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_NCE_SHIFT)) & DMA_CH26_ES_NCE_MASK)

#define DMA_CH26_ES_DOE_MASK                     (0x10U)
#define DMA_CH26_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH26_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_DOE_SHIFT)) & DMA_CH26_ES_DOE_MASK)

#define DMA_CH26_ES_DAE_MASK                     (0x20U)
#define DMA_CH26_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH26_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_DAE_SHIFT)) & DMA_CH26_ES_DAE_MASK)

#define DMA_CH26_ES_SOE_MASK                     (0x40U)
#define DMA_CH26_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH26_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_SOE_SHIFT)) & DMA_CH26_ES_SOE_MASK)

#define DMA_CH26_ES_SAE_MASK                     (0x80U)
#define DMA_CH26_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH26_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_SAE_SHIFT)) & DMA_CH26_ES_SAE_MASK)

#define DMA_CH26_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH26_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH26_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH26_ES_ERR_SHIFT)) & DMA_CH26_ES_ERR_MASK)
/*! @} */

/*! @name CH26_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH26_INT_INT_MASK                    (0x1U)
#define DMA_CH26_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH26_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_INT_INT_SHIFT)) & DMA_CH26_INT_INT_MASK)
/*! @} */

/*! @name CH26_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH26_SBR_MID_MASK                    (0xFU)
#define DMA_CH26_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH26_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_SBR_MID_SHIFT)) & DMA_CH26_SBR_MID_MASK)

#define DMA_CH26_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH26_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH26_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_SBR_PAL_SHIFT)) & DMA_CH26_SBR_PAL_MASK)

#define DMA_CH26_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH26_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH26_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_SBR_EMI_SHIFT)) & DMA_CH26_SBR_EMI_MASK)

#define DMA_CH26_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH26_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH26_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH26_SBR_ATTR_SHIFT)) & DMA_CH26_SBR_ATTR_MASK)
/*! @} */

/*! @name CH26_PRI - Channel Priority */
/*! @{ */

#define DMA_CH26_PRI_APL_MASK                    (0x7U)
#define DMA_CH26_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH26_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_PRI_APL_SHIFT)) & DMA_CH26_PRI_APL_MASK)

#define DMA_CH26_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH26_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH26_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_PRI_DPA_SHIFT)) & DMA_CH26_PRI_DPA_MASK)

#define DMA_CH26_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH26_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH26_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH26_PRI_ECP_SHIFT)) & DMA_CH26_PRI_ECP_MASK)
/*! @} */

/*! @name TCD26_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD26_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD26_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD26_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_SADDR_SADDR_SHIFT)) & DMA_TCD26_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD26_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD26_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD26_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD26_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_SOFF_SOFF_SHIFT)) & DMA_TCD26_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD26_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD26_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD26_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD26_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_ATTR_DSIZE_SHIFT)) & DMA_TCD26_ATTR_DSIZE_MASK)

#define DMA_TCD26_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD26_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD26_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_ATTR_DMOD_SHIFT)) & DMA_TCD26_ATTR_DMOD_MASK)

#define DMA_TCD26_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD26_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD26_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_ATTR_SSIZE_SHIFT)) & DMA_TCD26_ATTR_SSIZE_MASK)

#define DMA_TCD26_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD26_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD26_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_ATTR_SMOD_SHIFT)) & DMA_TCD26_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD26_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD26_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD26_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD26_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD26_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD26_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD26_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD26_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD26_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD26_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD26_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD26_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD26_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD26_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD26_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD26_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD26_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD26_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD26_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD26_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD26_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD26_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD26_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD26_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD26_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD26_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD26_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD26_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD26_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD26_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD26_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD26_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD26_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD26_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD26_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD26_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD26_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD26_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD26_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_DADDR_DADDR_SHIFT)) & DMA_TCD26_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD26_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD26_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD26_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD26_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_DOFF_DOFF_SHIFT)) & DMA_TCD26_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD26_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD26_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD26_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD26_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD26_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD26_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD26_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD26_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD26_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD26_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD26_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD26_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD26_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD26_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD26_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD26_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD26_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD26_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD26_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD26_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD26_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD26_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD26_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD26_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD26_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD26_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD26_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD26_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD26_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD26_CSR_START_MASK                 (0x1U)
#define DMA_TCD26_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD26_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_START_SHIFT)) & DMA_TCD26_CSR_START_MASK)

#define DMA_TCD26_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD26_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD26_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_INTMAJOR_SHIFT)) & DMA_TCD26_CSR_INTMAJOR_MASK)

#define DMA_TCD26_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD26_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD26_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_INTHALF_SHIFT)) & DMA_TCD26_CSR_INTHALF_MASK)

#define DMA_TCD26_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD26_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD26_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_DREQ_SHIFT)) & DMA_TCD26_CSR_DREQ_MASK)

#define DMA_TCD26_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD26_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD26_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_ESG_SHIFT)) & DMA_TCD26_CSR_ESG_MASK)

#define DMA_TCD26_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD26_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD26_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_MAJORELINK_SHIFT)) & DMA_TCD26_CSR_MAJORELINK_MASK)

#define DMA_TCD26_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD26_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD26_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_EEOP_SHIFT)) & DMA_TCD26_CSR_EEOP_MASK)

#define DMA_TCD26_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD26_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD26_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_ESDA_SHIFT)) & DMA_TCD26_CSR_ESDA_MASK)

#define DMA_TCD26_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD26_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD26_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD26_CSR_MAJORLINKCH_MASK)

#define DMA_TCD26_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD26_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD26_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_CSR_BWC_SHIFT)) & DMA_TCD26_CSR_BWC_MASK)
/*! @} */

/*! @name TCD26_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD26_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD26_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD26_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD26_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD26_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD26_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD26_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD26_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD26_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD26_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD26_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD26_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD26_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD26_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD26_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD26_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD26_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD26_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD26_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD26_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD26_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD26_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH27_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH27_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH27_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH27_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_CSR_ERQ_SHIFT)) & DMA_CH27_CSR_ERQ_MASK)

#define DMA_CH27_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH27_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH27_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH27_CSR_EARQ_SHIFT)) & DMA_CH27_CSR_EARQ_MASK)

#define DMA_CH27_CSR_EEI_MASK                    (0x4U)
#define DMA_CH27_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH27_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_CSR_EEI_SHIFT)) & DMA_CH27_CSR_EEI_MASK)

#define DMA_CH27_CSR_EBW_MASK                    (0x8U)
#define DMA_CH27_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH27_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_CSR_EBW_SHIFT)) & DMA_CH27_CSR_EBW_MASK)

#define DMA_CH27_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH27_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH27_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH27_CSR_DONE_SHIFT)) & DMA_CH27_CSR_DONE_MASK)

#define DMA_CH27_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH27_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH27_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH27_CSR_ACTIVE_SHIFT)) & DMA_CH27_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH27_ES - Channel Error Status */
/*! @{ */

#define DMA_CH27_ES_DBE_MASK                     (0x1U)
#define DMA_CH27_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH27_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_DBE_SHIFT)) & DMA_CH27_ES_DBE_MASK)

#define DMA_CH27_ES_SBE_MASK                     (0x2U)
#define DMA_CH27_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH27_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_SBE_SHIFT)) & DMA_CH27_ES_SBE_MASK)

#define DMA_CH27_ES_SGE_MASK                     (0x4U)
#define DMA_CH27_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH27_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_SGE_SHIFT)) & DMA_CH27_ES_SGE_MASK)

#define DMA_CH27_ES_NCE_MASK                     (0x8U)
#define DMA_CH27_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH27_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_NCE_SHIFT)) & DMA_CH27_ES_NCE_MASK)

#define DMA_CH27_ES_DOE_MASK                     (0x10U)
#define DMA_CH27_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH27_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_DOE_SHIFT)) & DMA_CH27_ES_DOE_MASK)

#define DMA_CH27_ES_DAE_MASK                     (0x20U)
#define DMA_CH27_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH27_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_DAE_SHIFT)) & DMA_CH27_ES_DAE_MASK)

#define DMA_CH27_ES_SOE_MASK                     (0x40U)
#define DMA_CH27_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH27_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_SOE_SHIFT)) & DMA_CH27_ES_SOE_MASK)

#define DMA_CH27_ES_SAE_MASK                     (0x80U)
#define DMA_CH27_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH27_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_SAE_SHIFT)) & DMA_CH27_ES_SAE_MASK)

#define DMA_CH27_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH27_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH27_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH27_ES_ERR_SHIFT)) & DMA_CH27_ES_ERR_MASK)
/*! @} */

/*! @name CH27_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH27_INT_INT_MASK                    (0x1U)
#define DMA_CH27_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH27_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_INT_INT_SHIFT)) & DMA_CH27_INT_INT_MASK)
/*! @} */

/*! @name CH27_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH27_SBR_MID_MASK                    (0xFU)
#define DMA_CH27_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH27_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_SBR_MID_SHIFT)) & DMA_CH27_SBR_MID_MASK)

#define DMA_CH27_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH27_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH27_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_SBR_PAL_SHIFT)) & DMA_CH27_SBR_PAL_MASK)

#define DMA_CH27_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH27_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH27_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_SBR_EMI_SHIFT)) & DMA_CH27_SBR_EMI_MASK)

#define DMA_CH27_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH27_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH27_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH27_SBR_ATTR_SHIFT)) & DMA_CH27_SBR_ATTR_MASK)
/*! @} */

/*! @name CH27_PRI - Channel Priority */
/*! @{ */

#define DMA_CH27_PRI_APL_MASK                    (0x7U)
#define DMA_CH27_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH27_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_PRI_APL_SHIFT)) & DMA_CH27_PRI_APL_MASK)

#define DMA_CH27_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH27_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH27_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_PRI_DPA_SHIFT)) & DMA_CH27_PRI_DPA_MASK)

#define DMA_CH27_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH27_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH27_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH27_PRI_ECP_SHIFT)) & DMA_CH27_PRI_ECP_MASK)
/*! @} */

/*! @name TCD27_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD27_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD27_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD27_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_SADDR_SADDR_SHIFT)) & DMA_TCD27_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD27_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD27_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD27_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD27_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_SOFF_SOFF_SHIFT)) & DMA_TCD27_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD27_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD27_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD27_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD27_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_ATTR_DSIZE_SHIFT)) & DMA_TCD27_ATTR_DSIZE_MASK)

#define DMA_TCD27_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD27_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD27_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_ATTR_DMOD_SHIFT)) & DMA_TCD27_ATTR_DMOD_MASK)

#define DMA_TCD27_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD27_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD27_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_ATTR_SSIZE_SHIFT)) & DMA_TCD27_ATTR_SSIZE_MASK)

#define DMA_TCD27_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD27_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD27_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_ATTR_SMOD_SHIFT)) & DMA_TCD27_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD27_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD27_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD27_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD27_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD27_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD27_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD27_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD27_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD27_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD27_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD27_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD27_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD27_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD27_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD27_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD27_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD27_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD27_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD27_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD27_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD27_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD27_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD27_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD27_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD27_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD27_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD27_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD27_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD27_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD27_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD27_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD27_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD27_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD27_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD27_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD27_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD27_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD27_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD27_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_DADDR_DADDR_SHIFT)) & DMA_TCD27_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD27_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD27_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD27_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD27_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_DOFF_DOFF_SHIFT)) & DMA_TCD27_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD27_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD27_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD27_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD27_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD27_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD27_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD27_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD27_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD27_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD27_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD27_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD27_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD27_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD27_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD27_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD27_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD27_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD27_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD27_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD27_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD27_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD27_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD27_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD27_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD27_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD27_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD27_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD27_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD27_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD27_CSR_START_MASK                 (0x1U)
#define DMA_TCD27_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD27_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_START_SHIFT)) & DMA_TCD27_CSR_START_MASK)

#define DMA_TCD27_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD27_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD27_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_INTMAJOR_SHIFT)) & DMA_TCD27_CSR_INTMAJOR_MASK)

#define DMA_TCD27_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD27_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD27_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_INTHALF_SHIFT)) & DMA_TCD27_CSR_INTHALF_MASK)

#define DMA_TCD27_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD27_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD27_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_DREQ_SHIFT)) & DMA_TCD27_CSR_DREQ_MASK)

#define DMA_TCD27_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD27_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD27_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_ESG_SHIFT)) & DMA_TCD27_CSR_ESG_MASK)

#define DMA_TCD27_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD27_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD27_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_MAJORELINK_SHIFT)) & DMA_TCD27_CSR_MAJORELINK_MASK)

#define DMA_TCD27_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD27_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD27_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_EEOP_SHIFT)) & DMA_TCD27_CSR_EEOP_MASK)

#define DMA_TCD27_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD27_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD27_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_ESDA_SHIFT)) & DMA_TCD27_CSR_ESDA_MASK)

#define DMA_TCD27_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD27_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD27_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD27_CSR_MAJORLINKCH_MASK)

#define DMA_TCD27_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD27_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD27_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_CSR_BWC_SHIFT)) & DMA_TCD27_CSR_BWC_MASK)
/*! @} */

/*! @name TCD27_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD27_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD27_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD27_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD27_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD27_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD27_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD27_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD27_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD27_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD27_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD27_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD27_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD27_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD27_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD27_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD27_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD27_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD27_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD27_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD27_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD27_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD27_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH28_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH28_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH28_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH28_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_CSR_ERQ_SHIFT)) & DMA_CH28_CSR_ERQ_MASK)

#define DMA_CH28_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH28_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH28_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH28_CSR_EARQ_SHIFT)) & DMA_CH28_CSR_EARQ_MASK)

#define DMA_CH28_CSR_EEI_MASK                    (0x4U)
#define DMA_CH28_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH28_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_CSR_EEI_SHIFT)) & DMA_CH28_CSR_EEI_MASK)

#define DMA_CH28_CSR_EBW_MASK                    (0x8U)
#define DMA_CH28_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH28_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_CSR_EBW_SHIFT)) & DMA_CH28_CSR_EBW_MASK)

#define DMA_CH28_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH28_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH28_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH28_CSR_DONE_SHIFT)) & DMA_CH28_CSR_DONE_MASK)

#define DMA_CH28_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH28_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH28_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH28_CSR_ACTIVE_SHIFT)) & DMA_CH28_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH28_ES - Channel Error Status */
/*! @{ */

#define DMA_CH28_ES_DBE_MASK                     (0x1U)
#define DMA_CH28_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH28_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_DBE_SHIFT)) & DMA_CH28_ES_DBE_MASK)

#define DMA_CH28_ES_SBE_MASK                     (0x2U)
#define DMA_CH28_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH28_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_SBE_SHIFT)) & DMA_CH28_ES_SBE_MASK)

#define DMA_CH28_ES_SGE_MASK                     (0x4U)
#define DMA_CH28_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH28_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_SGE_SHIFT)) & DMA_CH28_ES_SGE_MASK)

#define DMA_CH28_ES_NCE_MASK                     (0x8U)
#define DMA_CH28_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH28_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_NCE_SHIFT)) & DMA_CH28_ES_NCE_MASK)

#define DMA_CH28_ES_DOE_MASK                     (0x10U)
#define DMA_CH28_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH28_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_DOE_SHIFT)) & DMA_CH28_ES_DOE_MASK)

#define DMA_CH28_ES_DAE_MASK                     (0x20U)
#define DMA_CH28_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH28_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_DAE_SHIFT)) & DMA_CH28_ES_DAE_MASK)

#define DMA_CH28_ES_SOE_MASK                     (0x40U)
#define DMA_CH28_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH28_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_SOE_SHIFT)) & DMA_CH28_ES_SOE_MASK)

#define DMA_CH28_ES_SAE_MASK                     (0x80U)
#define DMA_CH28_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH28_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_SAE_SHIFT)) & DMA_CH28_ES_SAE_MASK)

#define DMA_CH28_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH28_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH28_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH28_ES_ERR_SHIFT)) & DMA_CH28_ES_ERR_MASK)
/*! @} */

/*! @name CH28_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH28_INT_INT_MASK                    (0x1U)
#define DMA_CH28_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH28_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_INT_INT_SHIFT)) & DMA_CH28_INT_INT_MASK)
/*! @} */

/*! @name CH28_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH28_SBR_MID_MASK                    (0xFU)
#define DMA_CH28_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH28_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_SBR_MID_SHIFT)) & DMA_CH28_SBR_MID_MASK)

#define DMA_CH28_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH28_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH28_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_SBR_PAL_SHIFT)) & DMA_CH28_SBR_PAL_MASK)

#define DMA_CH28_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH28_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH28_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_SBR_EMI_SHIFT)) & DMA_CH28_SBR_EMI_MASK)

#define DMA_CH28_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH28_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH28_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH28_SBR_ATTR_SHIFT)) & DMA_CH28_SBR_ATTR_MASK)
/*! @} */

/*! @name CH28_PRI - Channel Priority */
/*! @{ */

#define DMA_CH28_PRI_APL_MASK                    (0x7U)
#define DMA_CH28_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH28_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_PRI_APL_SHIFT)) & DMA_CH28_PRI_APL_MASK)

#define DMA_CH28_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH28_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH28_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_PRI_DPA_SHIFT)) & DMA_CH28_PRI_DPA_MASK)

#define DMA_CH28_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH28_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH28_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH28_PRI_ECP_SHIFT)) & DMA_CH28_PRI_ECP_MASK)
/*! @} */

/*! @name TCD28_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD28_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD28_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD28_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_SADDR_SADDR_SHIFT)) & DMA_TCD28_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD28_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD28_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD28_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD28_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_SOFF_SOFF_SHIFT)) & DMA_TCD28_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD28_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD28_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD28_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD28_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_ATTR_DSIZE_SHIFT)) & DMA_TCD28_ATTR_DSIZE_MASK)

#define DMA_TCD28_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD28_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD28_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_ATTR_DMOD_SHIFT)) & DMA_TCD28_ATTR_DMOD_MASK)

#define DMA_TCD28_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD28_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD28_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_ATTR_SSIZE_SHIFT)) & DMA_TCD28_ATTR_SSIZE_MASK)

#define DMA_TCD28_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD28_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD28_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_ATTR_SMOD_SHIFT)) & DMA_TCD28_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD28_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD28_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD28_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD28_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD28_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD28_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD28_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD28_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD28_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD28_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD28_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD28_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD28_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD28_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD28_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD28_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD28_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD28_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD28_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD28_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD28_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD28_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD28_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD28_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD28_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD28_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD28_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD28_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD28_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD28_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD28_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD28_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD28_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD28_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD28_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD28_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD28_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD28_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD28_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_DADDR_DADDR_SHIFT)) & DMA_TCD28_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD28_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD28_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD28_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD28_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_DOFF_DOFF_SHIFT)) & DMA_TCD28_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD28_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD28_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD28_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD28_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD28_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD28_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD28_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD28_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD28_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD28_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD28_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD28_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD28_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD28_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD28_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD28_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD28_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD28_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD28_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD28_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD28_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD28_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD28_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD28_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD28_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD28_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD28_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD28_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD28_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD28_CSR_START_MASK                 (0x1U)
#define DMA_TCD28_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD28_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_START_SHIFT)) & DMA_TCD28_CSR_START_MASK)

#define DMA_TCD28_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD28_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD28_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_INTMAJOR_SHIFT)) & DMA_TCD28_CSR_INTMAJOR_MASK)

#define DMA_TCD28_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD28_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD28_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_INTHALF_SHIFT)) & DMA_TCD28_CSR_INTHALF_MASK)

#define DMA_TCD28_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD28_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD28_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_DREQ_SHIFT)) & DMA_TCD28_CSR_DREQ_MASK)

#define DMA_TCD28_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD28_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD28_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_ESG_SHIFT)) & DMA_TCD28_CSR_ESG_MASK)

#define DMA_TCD28_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD28_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD28_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_MAJORELINK_SHIFT)) & DMA_TCD28_CSR_MAJORELINK_MASK)

#define DMA_TCD28_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD28_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD28_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_EEOP_SHIFT)) & DMA_TCD28_CSR_EEOP_MASK)

#define DMA_TCD28_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD28_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD28_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_ESDA_SHIFT)) & DMA_TCD28_CSR_ESDA_MASK)

#define DMA_TCD28_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD28_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD28_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD28_CSR_MAJORLINKCH_MASK)

#define DMA_TCD28_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD28_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD28_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_CSR_BWC_SHIFT)) & DMA_TCD28_CSR_BWC_MASK)
/*! @} */

/*! @name TCD28_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD28_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD28_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD28_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD28_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD28_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD28_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD28_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD28_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD28_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD28_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD28_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD28_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD28_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD28_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD28_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD28_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD28_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD28_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD28_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD28_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD28_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD28_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH29_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH29_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH29_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH29_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_CSR_ERQ_SHIFT)) & DMA_CH29_CSR_ERQ_MASK)

#define DMA_CH29_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH29_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH29_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH29_CSR_EARQ_SHIFT)) & DMA_CH29_CSR_EARQ_MASK)

#define DMA_CH29_CSR_EEI_MASK                    (0x4U)
#define DMA_CH29_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH29_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_CSR_EEI_SHIFT)) & DMA_CH29_CSR_EEI_MASK)

#define DMA_CH29_CSR_EBW_MASK                    (0x8U)
#define DMA_CH29_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH29_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_CSR_EBW_SHIFT)) & DMA_CH29_CSR_EBW_MASK)

#define DMA_CH29_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH29_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH29_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH29_CSR_DONE_SHIFT)) & DMA_CH29_CSR_DONE_MASK)

#define DMA_CH29_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH29_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH29_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH29_CSR_ACTIVE_SHIFT)) & DMA_CH29_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH29_ES - Channel Error Status */
/*! @{ */

#define DMA_CH29_ES_DBE_MASK                     (0x1U)
#define DMA_CH29_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH29_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_DBE_SHIFT)) & DMA_CH29_ES_DBE_MASK)

#define DMA_CH29_ES_SBE_MASK                     (0x2U)
#define DMA_CH29_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH29_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_SBE_SHIFT)) & DMA_CH29_ES_SBE_MASK)

#define DMA_CH29_ES_SGE_MASK                     (0x4U)
#define DMA_CH29_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH29_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_SGE_SHIFT)) & DMA_CH29_ES_SGE_MASK)

#define DMA_CH29_ES_NCE_MASK                     (0x8U)
#define DMA_CH29_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH29_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_NCE_SHIFT)) & DMA_CH29_ES_NCE_MASK)

#define DMA_CH29_ES_DOE_MASK                     (0x10U)
#define DMA_CH29_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH29_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_DOE_SHIFT)) & DMA_CH29_ES_DOE_MASK)

#define DMA_CH29_ES_DAE_MASK                     (0x20U)
#define DMA_CH29_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH29_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_DAE_SHIFT)) & DMA_CH29_ES_DAE_MASK)

#define DMA_CH29_ES_SOE_MASK                     (0x40U)
#define DMA_CH29_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH29_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_SOE_SHIFT)) & DMA_CH29_ES_SOE_MASK)

#define DMA_CH29_ES_SAE_MASK                     (0x80U)
#define DMA_CH29_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH29_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_SAE_SHIFT)) & DMA_CH29_ES_SAE_MASK)

#define DMA_CH29_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH29_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH29_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH29_ES_ERR_SHIFT)) & DMA_CH29_ES_ERR_MASK)
/*! @} */

/*! @name CH29_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH29_INT_INT_MASK                    (0x1U)
#define DMA_CH29_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH29_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_INT_INT_SHIFT)) & DMA_CH29_INT_INT_MASK)
/*! @} */

/*! @name CH29_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH29_SBR_MID_MASK                    (0xFU)
#define DMA_CH29_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH29_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_SBR_MID_SHIFT)) & DMA_CH29_SBR_MID_MASK)

#define DMA_CH29_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH29_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH29_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_SBR_PAL_SHIFT)) & DMA_CH29_SBR_PAL_MASK)

#define DMA_CH29_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH29_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH29_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_SBR_EMI_SHIFT)) & DMA_CH29_SBR_EMI_MASK)

#define DMA_CH29_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH29_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH29_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH29_SBR_ATTR_SHIFT)) & DMA_CH29_SBR_ATTR_MASK)
/*! @} */

/*! @name CH29_PRI - Channel Priority */
/*! @{ */

#define DMA_CH29_PRI_APL_MASK                    (0x7U)
#define DMA_CH29_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH29_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_PRI_APL_SHIFT)) & DMA_CH29_PRI_APL_MASK)

#define DMA_CH29_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH29_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH29_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_PRI_DPA_SHIFT)) & DMA_CH29_PRI_DPA_MASK)

#define DMA_CH29_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH29_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH29_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH29_PRI_ECP_SHIFT)) & DMA_CH29_PRI_ECP_MASK)
/*! @} */

/*! @name TCD29_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD29_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD29_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD29_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_SADDR_SADDR_SHIFT)) & DMA_TCD29_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD29_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD29_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD29_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD29_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_SOFF_SOFF_SHIFT)) & DMA_TCD29_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD29_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD29_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD29_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD29_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_ATTR_DSIZE_SHIFT)) & DMA_TCD29_ATTR_DSIZE_MASK)

#define DMA_TCD29_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD29_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD29_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_ATTR_DMOD_SHIFT)) & DMA_TCD29_ATTR_DMOD_MASK)

#define DMA_TCD29_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD29_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD29_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_ATTR_SSIZE_SHIFT)) & DMA_TCD29_ATTR_SSIZE_MASK)

#define DMA_TCD29_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD29_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD29_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_ATTR_SMOD_SHIFT)) & DMA_TCD29_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD29_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD29_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD29_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD29_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD29_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD29_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD29_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD29_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD29_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD29_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD29_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD29_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD29_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD29_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD29_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD29_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD29_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD29_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD29_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD29_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD29_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD29_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD29_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD29_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD29_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD29_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD29_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD29_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD29_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD29_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD29_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD29_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD29_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD29_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD29_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD29_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD29_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD29_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD29_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_DADDR_DADDR_SHIFT)) & DMA_TCD29_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD29_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD29_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD29_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD29_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_DOFF_DOFF_SHIFT)) & DMA_TCD29_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD29_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD29_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD29_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD29_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD29_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD29_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD29_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD29_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD29_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD29_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD29_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD29_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD29_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD29_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD29_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD29_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD29_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD29_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD29_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD29_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD29_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD29_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD29_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD29_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD29_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD29_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD29_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD29_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD29_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD29_CSR_START_MASK                 (0x1U)
#define DMA_TCD29_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD29_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_START_SHIFT)) & DMA_TCD29_CSR_START_MASK)

#define DMA_TCD29_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD29_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD29_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_INTMAJOR_SHIFT)) & DMA_TCD29_CSR_INTMAJOR_MASK)

#define DMA_TCD29_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD29_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD29_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_INTHALF_SHIFT)) & DMA_TCD29_CSR_INTHALF_MASK)

#define DMA_TCD29_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD29_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD29_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_DREQ_SHIFT)) & DMA_TCD29_CSR_DREQ_MASK)

#define DMA_TCD29_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD29_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD29_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_ESG_SHIFT)) & DMA_TCD29_CSR_ESG_MASK)

#define DMA_TCD29_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD29_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD29_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_MAJORELINK_SHIFT)) & DMA_TCD29_CSR_MAJORELINK_MASK)

#define DMA_TCD29_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD29_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD29_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_EEOP_SHIFT)) & DMA_TCD29_CSR_EEOP_MASK)

#define DMA_TCD29_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD29_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD29_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_ESDA_SHIFT)) & DMA_TCD29_CSR_ESDA_MASK)

#define DMA_TCD29_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD29_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD29_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD29_CSR_MAJORLINKCH_MASK)

#define DMA_TCD29_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD29_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD29_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_CSR_BWC_SHIFT)) & DMA_TCD29_CSR_BWC_MASK)
/*! @} */

/*! @name TCD29_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD29_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD29_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD29_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD29_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD29_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD29_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD29_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD29_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD29_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD29_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD29_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD29_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD29_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD29_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD29_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD29_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD29_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD29_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD29_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD29_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD29_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD29_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH30_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH30_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH30_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH30_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_CSR_ERQ_SHIFT)) & DMA_CH30_CSR_ERQ_MASK)

#define DMA_CH30_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH30_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH30_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH30_CSR_EARQ_SHIFT)) & DMA_CH30_CSR_EARQ_MASK)

#define DMA_CH30_CSR_EEI_MASK                    (0x4U)
#define DMA_CH30_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH30_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_CSR_EEI_SHIFT)) & DMA_CH30_CSR_EEI_MASK)

#define DMA_CH30_CSR_EBW_MASK                    (0x8U)
#define DMA_CH30_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH30_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_CSR_EBW_SHIFT)) & DMA_CH30_CSR_EBW_MASK)

#define DMA_CH30_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH30_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH30_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH30_CSR_DONE_SHIFT)) & DMA_CH30_CSR_DONE_MASK)

#define DMA_CH30_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH30_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH30_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH30_CSR_ACTIVE_SHIFT)) & DMA_CH30_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH30_ES - Channel Error Status */
/*! @{ */

#define DMA_CH30_ES_DBE_MASK                     (0x1U)
#define DMA_CH30_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH30_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_DBE_SHIFT)) & DMA_CH30_ES_DBE_MASK)

#define DMA_CH30_ES_SBE_MASK                     (0x2U)
#define DMA_CH30_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH30_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_SBE_SHIFT)) & DMA_CH30_ES_SBE_MASK)

#define DMA_CH30_ES_SGE_MASK                     (0x4U)
#define DMA_CH30_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH30_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_SGE_SHIFT)) & DMA_CH30_ES_SGE_MASK)

#define DMA_CH30_ES_NCE_MASK                     (0x8U)
#define DMA_CH30_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH30_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_NCE_SHIFT)) & DMA_CH30_ES_NCE_MASK)

#define DMA_CH30_ES_DOE_MASK                     (0x10U)
#define DMA_CH30_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH30_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_DOE_SHIFT)) & DMA_CH30_ES_DOE_MASK)

#define DMA_CH30_ES_DAE_MASK                     (0x20U)
#define DMA_CH30_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH30_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_DAE_SHIFT)) & DMA_CH30_ES_DAE_MASK)

#define DMA_CH30_ES_SOE_MASK                     (0x40U)
#define DMA_CH30_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH30_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_SOE_SHIFT)) & DMA_CH30_ES_SOE_MASK)

#define DMA_CH30_ES_SAE_MASK                     (0x80U)
#define DMA_CH30_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH30_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_SAE_SHIFT)) & DMA_CH30_ES_SAE_MASK)

#define DMA_CH30_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH30_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH30_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH30_ES_ERR_SHIFT)) & DMA_CH30_ES_ERR_MASK)
/*! @} */

/*! @name CH30_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH30_INT_INT_MASK                    (0x1U)
#define DMA_CH30_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH30_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_INT_INT_SHIFT)) & DMA_CH30_INT_INT_MASK)
/*! @} */

/*! @name CH30_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH30_SBR_MID_MASK                    (0xFU)
#define DMA_CH30_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH30_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_SBR_MID_SHIFT)) & DMA_CH30_SBR_MID_MASK)

#define DMA_CH30_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH30_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH30_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_SBR_PAL_SHIFT)) & DMA_CH30_SBR_PAL_MASK)

#define DMA_CH30_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH30_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH30_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_SBR_EMI_SHIFT)) & DMA_CH30_SBR_EMI_MASK)

#define DMA_CH30_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH30_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH30_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH30_SBR_ATTR_SHIFT)) & DMA_CH30_SBR_ATTR_MASK)
/*! @} */

/*! @name CH30_PRI - Channel Priority */
/*! @{ */

#define DMA_CH30_PRI_APL_MASK                    (0x7U)
#define DMA_CH30_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH30_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_PRI_APL_SHIFT)) & DMA_CH30_PRI_APL_MASK)

#define DMA_CH30_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH30_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH30_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_PRI_DPA_SHIFT)) & DMA_CH30_PRI_DPA_MASK)

#define DMA_CH30_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH30_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH30_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH30_PRI_ECP_SHIFT)) & DMA_CH30_PRI_ECP_MASK)
/*! @} */

/*! @name TCD30_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD30_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD30_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD30_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_SADDR_SADDR_SHIFT)) & DMA_TCD30_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD30_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD30_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD30_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD30_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_SOFF_SOFF_SHIFT)) & DMA_TCD30_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD30_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD30_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD30_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD30_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_ATTR_DSIZE_SHIFT)) & DMA_TCD30_ATTR_DSIZE_MASK)

#define DMA_TCD30_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD30_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD30_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_ATTR_DMOD_SHIFT)) & DMA_TCD30_ATTR_DMOD_MASK)

#define DMA_TCD30_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD30_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD30_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_ATTR_SSIZE_SHIFT)) & DMA_TCD30_ATTR_SSIZE_MASK)

#define DMA_TCD30_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD30_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD30_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_ATTR_SMOD_SHIFT)) & DMA_TCD30_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD30_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD30_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD30_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD30_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD30_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD30_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD30_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD30_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD30_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD30_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD30_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD30_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD30_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD30_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD30_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD30_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD30_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD30_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD30_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD30_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD30_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD30_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD30_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD30_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD30_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD30_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD30_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD30_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD30_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD30_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD30_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD30_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD30_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD30_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD30_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD30_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD30_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD30_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD30_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_DADDR_DADDR_SHIFT)) & DMA_TCD30_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD30_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD30_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD30_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD30_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_DOFF_DOFF_SHIFT)) & DMA_TCD30_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD30_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD30_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD30_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD30_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD30_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD30_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD30_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD30_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD30_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD30_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD30_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD30_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD30_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD30_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD30_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD30_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD30_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD30_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD30_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD30_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD30_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD30_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD30_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD30_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD30_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD30_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD30_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD30_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD30_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD30_CSR_START_MASK                 (0x1U)
#define DMA_TCD30_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD30_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_START_SHIFT)) & DMA_TCD30_CSR_START_MASK)

#define DMA_TCD30_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD30_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD30_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_INTMAJOR_SHIFT)) & DMA_TCD30_CSR_INTMAJOR_MASK)

#define DMA_TCD30_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD30_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD30_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_INTHALF_SHIFT)) & DMA_TCD30_CSR_INTHALF_MASK)

#define DMA_TCD30_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD30_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD30_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_DREQ_SHIFT)) & DMA_TCD30_CSR_DREQ_MASK)

#define DMA_TCD30_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD30_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD30_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_ESG_SHIFT)) & DMA_TCD30_CSR_ESG_MASK)

#define DMA_TCD30_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD30_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD30_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_MAJORELINK_SHIFT)) & DMA_TCD30_CSR_MAJORELINK_MASK)

#define DMA_TCD30_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD30_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD30_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_EEOP_SHIFT)) & DMA_TCD30_CSR_EEOP_MASK)

#define DMA_TCD30_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD30_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD30_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_ESDA_SHIFT)) & DMA_TCD30_CSR_ESDA_MASK)

#define DMA_TCD30_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD30_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD30_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD30_CSR_MAJORLINKCH_MASK)

#define DMA_TCD30_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD30_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD30_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_CSR_BWC_SHIFT)) & DMA_TCD30_CSR_BWC_MASK)
/*! @} */

/*! @name TCD30_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD30_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD30_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD30_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD30_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD30_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD30_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD30_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD30_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD30_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD30_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD30_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD30_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD30_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD30_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD30_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD30_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD30_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD30_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD30_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD30_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD30_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD30_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name CH31_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH31_CSR_ERQ_MASK                    (0x1U)
#define DMA_CH31_CSR_ERQ_SHIFT                   (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH31_CSR_ERQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_CSR_ERQ_SHIFT)) & DMA_CH31_CSR_ERQ_MASK)

#define DMA_CH31_CSR_EARQ_MASK                   (0x2U)
#define DMA_CH31_CSR_EARQ_SHIFT                  (1U)
/*! EARQ - Enable Asynchronous DMA Request In Stop Mode For Channel
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH31_CSR_EARQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH31_CSR_EARQ_SHIFT)) & DMA_CH31_CSR_EARQ_MASK)

#define DMA_CH31_CSR_EEI_MASK                    (0x4U)
#define DMA_CH31_CSR_EEI_SHIFT                   (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH31_CSR_EEI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_CSR_EEI_SHIFT)) & DMA_CH31_CSR_EEI_MASK)

#define DMA_CH31_CSR_EBW_MASK                    (0x8U)
#define DMA_CH31_CSR_EBW_SHIFT                   (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH31_CSR_EBW(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_CSR_EBW_SHIFT)) & DMA_CH31_CSR_EBW_MASK)

#define DMA_CH31_CSR_DONE_MASK                   (0x40000000U)
#define DMA_CH31_CSR_DONE_SHIFT                  (30U)
/*! DONE - Channel Done */
#define DMA_CH31_CSR_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH31_CSR_DONE_SHIFT)) & DMA_CH31_CSR_DONE_MASK)

#define DMA_CH31_CSR_ACTIVE_MASK                 (0x80000000U)
#define DMA_CH31_CSR_ACTIVE_SHIFT                (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH31_CSR_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CH31_CSR_ACTIVE_SHIFT)) & DMA_CH31_CSR_ACTIVE_MASK)
/*! @} */

/*! @name CH31_ES - Channel Error Status */
/*! @{ */

#define DMA_CH31_ES_DBE_MASK                     (0x1U)
#define DMA_CH31_ES_DBE_SHIFT                    (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH31_ES_DBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_DBE_SHIFT)) & DMA_CH31_ES_DBE_MASK)

#define DMA_CH31_ES_SBE_MASK                     (0x2U)
#define DMA_CH31_ES_SBE_SHIFT                    (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH31_ES_SBE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_SBE_SHIFT)) & DMA_CH31_ES_SBE_MASK)

#define DMA_CH31_ES_SGE_MASK                     (0x4U)
#define DMA_CH31_ES_SGE_SHIFT                    (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH31_ES_SGE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_SGE_SHIFT)) & DMA_CH31_ES_SGE_MASK)

#define DMA_CH31_ES_NCE_MASK                     (0x8U)
#define DMA_CH31_ES_NCE_SHIFT                    (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH31_ES_NCE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_NCE_SHIFT)) & DMA_CH31_ES_NCE_MASK)

#define DMA_CH31_ES_DOE_MASK                     (0x10U)
#define DMA_CH31_ES_DOE_SHIFT                    (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH31_ES_DOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_DOE_SHIFT)) & DMA_CH31_ES_DOE_MASK)

#define DMA_CH31_ES_DAE_MASK                     (0x20U)
#define DMA_CH31_ES_DAE_SHIFT                    (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH31_ES_DAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_DAE_SHIFT)) & DMA_CH31_ES_DAE_MASK)

#define DMA_CH31_ES_SOE_MASK                     (0x40U)
#define DMA_CH31_ES_SOE_SHIFT                    (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH31_ES_SOE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_SOE_SHIFT)) & DMA_CH31_ES_SOE_MASK)

#define DMA_CH31_ES_SAE_MASK                     (0x80U)
#define DMA_CH31_ES_SAE_SHIFT                    (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH31_ES_SAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_SAE_SHIFT)) & DMA_CH31_ES_SAE_MASK)

#define DMA_CH31_ES_ERR_MASK                     (0x80000000U)
#define DMA_CH31_ES_ERR_SHIFT                    (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH31_ES_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH31_ES_ERR_SHIFT)) & DMA_CH31_ES_ERR_MASK)
/*! @} */

/*! @name CH31_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH31_INT_INT_MASK                    (0x1U)
#define DMA_CH31_INT_INT_SHIFT                   (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH31_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_INT_INT_SHIFT)) & DMA_CH31_INT_INT_MASK)
/*! @} */

/*! @name CH31_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH31_SBR_MID_MASK                    (0xFU)
#define DMA_CH31_SBR_MID_SHIFT                   (0U)
/*! MID - Master ID */
#define DMA_CH31_SBR_MID(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_SBR_MID_SHIFT)) & DMA_CH31_SBR_MID_MASK)

#define DMA_CH31_SBR_PAL_MASK                    (0x8000U)
#define DMA_CH31_SBR_PAL_SHIFT                   (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH31_SBR_PAL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_SBR_PAL_SHIFT)) & DMA_CH31_SBR_PAL_MASK)

#define DMA_CH31_SBR_EMI_MASK                    (0x10000U)
#define DMA_CH31_SBR_EMI_SHIFT                   (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH31_SBR_EMI(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_SBR_EMI_SHIFT)) & DMA_CH31_SBR_EMI_MASK)

#define DMA_CH31_SBR_ATTR_MASK                   (0xE0000U)
#define DMA_CH31_SBR_ATTR_SHIFT                  (17U)
/*! ATTR - Attribute Output */
#define DMA_CH31_SBR_ATTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH31_SBR_ATTR_SHIFT)) & DMA_CH31_SBR_ATTR_MASK)
/*! @} */

/*! @name CH31_PRI - Channel Priority */
/*! @{ */

#define DMA_CH31_PRI_APL_MASK                    (0x7U)
#define DMA_CH31_PRI_APL_SHIFT                   (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH31_PRI_APL(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_PRI_APL_SHIFT)) & DMA_CH31_PRI_APL_MASK)

#define DMA_CH31_PRI_DPA_MASK                    (0x40000000U)
#define DMA_CH31_PRI_DPA_SHIFT                   (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH31_PRI_DPA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_PRI_DPA_SHIFT)) & DMA_CH31_PRI_DPA_MASK)

#define DMA_CH31_PRI_ECP_MASK                    (0x80000000U)
#define DMA_CH31_PRI_ECP_SHIFT                   (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH31_PRI_ECP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CH31_PRI_ECP_SHIFT)) & DMA_CH31_PRI_ECP_MASK)
/*! @} */

/*! @name TCD31_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD31_SADDR_SADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD31_SADDR_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA_TCD31_SADDR_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_SADDR_SADDR_SHIFT)) & DMA_TCD31_SADDR_SADDR_MASK)
/*! @} */

/*! @name TCD31_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD31_SOFF_SOFF_MASK                 (0xFFFFU)
#define DMA_TCD31_SOFF_SOFF_SHIFT                (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD31_SOFF_SOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_SOFF_SOFF_SHIFT)) & DMA_TCD31_SOFF_SOFF_MASK)
/*! @} */

/*! @name TCD31_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD31_ATTR_DSIZE_MASK                (0x7U)
#define DMA_TCD31_ATTR_DSIZE_SHIFT               (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD31_ATTR_DSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_ATTR_DSIZE_SHIFT)) & DMA_TCD31_ATTR_DSIZE_MASK)

#define DMA_TCD31_ATTR_DMOD_MASK                 (0xF8U)
#define DMA_TCD31_ATTR_DMOD_SHIFT                (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD31_ATTR_DMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_ATTR_DMOD_SHIFT)) & DMA_TCD31_ATTR_DMOD_MASK)

#define DMA_TCD31_ATTR_SSIZE_MASK                (0x700U)
#define DMA_TCD31_ATTR_SSIZE_SHIFT               (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..Reserved
 */
#define DMA_TCD31_ATTR_SSIZE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_ATTR_SSIZE_SHIFT)) & DMA_TCD31_ATTR_SSIZE_MASK)

#define DMA_TCD31_ATTR_SMOD_MASK                 (0xF800U)
#define DMA_TCD31_ATTR_SMOD_SHIFT                (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD31_ATTR_SMOD(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_ATTR_SMOD_SHIFT)) & DMA_TCD31_ATTR_SMOD_MASK)
/*! @} */

/*! @name TCD31_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD31_NBYTES_MLOFFNO_NBYTES_MASK     (0x3FFFFFFFU)
#define DMA_TCD31_NBYTES_MLOFFNO_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD31_NBYTES_MLOFFNO_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD31_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD31_NBYTES_MLOFFNO_DMLOE_MASK      (0x40000000U)
#define DMA_TCD31_NBYTES_MLOFFNO_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD31_NBYTES_MLOFFNO_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD31_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD31_NBYTES_MLOFFNO_SMLOE_MASK      (0x80000000U)
#define DMA_TCD31_NBYTES_MLOFFNO_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD31_NBYTES_MLOFFNO_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD31_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/*! @name TCD31_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD31_NBYTES_MLOFFYES_NBYTES_MASK    (0x3FFU)
#define DMA_TCD31_NBYTES_MLOFFYES_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD31_NBYTES_MLOFFYES_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD31_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD31_NBYTES_MLOFFYES_MLOFF_MASK     (0x3FFFFC00U)
#define DMA_TCD31_NBYTES_MLOFFYES_MLOFF_SHIFT    (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD31_NBYTES_MLOFFYES_MLOFF(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD31_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD31_NBYTES_MLOFFYES_DMLOE_MASK     (0x40000000U)
#define DMA_TCD31_NBYTES_MLOFFYES_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD31_NBYTES_MLOFFYES_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD31_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD31_NBYTES_MLOFFYES_SMLOE_MASK     (0x80000000U)
#define DMA_TCD31_NBYTES_MLOFFYES_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD31_NBYTES_MLOFFYES_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD31_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/*! @name TCD31_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD31_SLAST_SDA_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA_TCD31_SLAST_SDA_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD31_SLAST_SDA_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD31_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/*! @name TCD31_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD31_DADDR_DADDR_MASK               (0xFFFFFFFFU)
#define DMA_TCD31_DADDR_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA_TCD31_DADDR_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_DADDR_DADDR_SHIFT)) & DMA_TCD31_DADDR_DADDR_MASK)
/*! @} */

/*! @name TCD31_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD31_DOFF_DOFF_MASK                 (0xFFFFU)
#define DMA_TCD31_DOFF_DOFF_SHIFT                (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD31_DOFF_DOFF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_DOFF_DOFF_SHIFT)) & DMA_TCD31_DOFF_DOFF_MASK)
/*! @} */

/*! @name TCD31_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD31_CITER_ELINKNO_CITER_MASK       (0x7FFFU)
#define DMA_TCD31_CITER_ELINKNO_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD31_CITER_ELINKNO_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD31_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD31_CITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD31_CITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD31_CITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD31_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD31_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD31_CITER_ELINKYES_CITER_MASK      (0x1FFU)
#define DMA_TCD31_CITER_ELINKYES_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD31_CITER_ELINKYES_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD31_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD31_CITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD31_CITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD31_CITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD31_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD31_CITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD31_CITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD31_CITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD31_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/*! @name TCD31_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD31_DLAST_SGA_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA_TCD31_DLAST_SGA_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD31_DLAST_SGA_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD31_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD31_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/*! @name TCD31_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD31_CSR_START_MASK                 (0x1U)
#define DMA_TCD31_CSR_START_SHIFT                (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD31_CSR_START(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_START_SHIFT)) & DMA_TCD31_CSR_START_MASK)

#define DMA_TCD31_CSR_INTMAJOR_MASK              (0x2U)
#define DMA_TCD31_CSR_INTMAJOR_SHIFT             (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD31_CSR_INTMAJOR(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_INTMAJOR_SHIFT)) & DMA_TCD31_CSR_INTMAJOR_MASK)

#define DMA_TCD31_CSR_INTHALF_MASK               (0x4U)
#define DMA_TCD31_CSR_INTHALF_SHIFT              (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD31_CSR_INTHALF(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_INTHALF_SHIFT)) & DMA_TCD31_CSR_INTHALF_MASK)

#define DMA_TCD31_CSR_DREQ_MASK                  (0x8U)
#define DMA_TCD31_CSR_DREQ_SHIFT                 (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD31_CSR_DREQ(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_DREQ_SHIFT)) & DMA_TCD31_CSR_DREQ_MASK)

#define DMA_TCD31_CSR_ESG_MASK                   (0x10U)
#define DMA_TCD31_CSR_ESG_SHIFT                  (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD31_CSR_ESG(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_ESG_SHIFT)) & DMA_TCD31_CSR_ESG_MASK)

#define DMA_TCD31_CSR_MAJORELINK_MASK            (0x20U)
#define DMA_TCD31_CSR_MAJORELINK_SHIFT           (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD31_CSR_MAJORELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_MAJORELINK_SHIFT)) & DMA_TCD31_CSR_MAJORELINK_MASK)

#define DMA_TCD31_CSR_EEOP_MASK                  (0x40U)
#define DMA_TCD31_CSR_EEOP_SHIFT                 (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD31_CSR_EEOP(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_EEOP_SHIFT)) & DMA_TCD31_CSR_EEOP_MASK)

#define DMA_TCD31_CSR_ESDA_MASK                  (0x80U)
#define DMA_TCD31_CSR_ESDA_SHIFT                 (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD31_CSR_ESDA(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_ESDA_SHIFT)) & DMA_TCD31_CSR_ESDA_MASK)

#define DMA_TCD31_CSR_MAJORLINKCH_MASK           (0x1F00U)
#define DMA_TCD31_CSR_MAJORLINKCH_SHIFT          (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD31_CSR_MAJORLINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD31_CSR_MAJORLINKCH_MASK)

#define DMA_TCD31_CSR_BWC_MASK                   (0xC000U)
#define DMA_TCD31_CSR_BWC_SHIFT                  (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD31_CSR_BWC(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_CSR_BWC_SHIFT)) & DMA_TCD31_CSR_BWC_MASK)
/*! @} */

/*! @name TCD31_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD31_BITER_ELINKNO_BITER_MASK       (0x7FFFU)
#define DMA_TCD31_BITER_ELINKNO_BITER_SHIFT      (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD31_BITER_ELINKNO_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD31_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD31_BITER_ELINKNO_ELINK_MASK       (0x8000U)
#define DMA_TCD31_BITER_ELINKNO_ELINK_SHIFT      (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD31_BITER_ELINKNO_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD31_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/*! @name TCD31_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD31_BITER_ELINKYES_BITER_MASK      (0x1FFU)
#define DMA_TCD31_BITER_ELINKYES_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD31_BITER_ELINKYES_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD31_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD31_BITER_ELINKYES_LINKCH_MASK     (0x3E00U)
#define DMA_TCD31_BITER_ELINKYES_LINKCH_SHIFT    (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD31_BITER_ELINKYES_LINKCH(x)       (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD31_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD31_BITER_ELINKYES_ELINK_MASK      (0x8000U)
#define DMA_TCD31_BITER_ELINKYES_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD31_BITER_ELINKYES_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_TCD31_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD31_BITER_ELINKYES_ELINK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA_H_ */

