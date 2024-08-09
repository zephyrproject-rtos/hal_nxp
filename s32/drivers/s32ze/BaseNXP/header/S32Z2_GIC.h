/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_GIC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_GIC
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
#if !defined(S32Z2_GIC_H_)  /* Check if memory map has not been already included */
#define S32Z2_GIC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- S32_GIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_GIC_Peripheral_Access_Layer S32_GIC Peripheral Access Layer
 * @{
 */

/** \brief  Structure type to access the Generic Interrupt Controller Distributor (GICD)
*/

/** S32_GICD - Size of Registers Arrays */
#define S32_GICD_IGROUPR_COUNT                      30u
#define S32_GICD_ISENABLER_COUNT                    30u
#define S32_GICD_ICENABLER_COUNT                    30u
#define S32_GICD_ISPENDR_COUNT                      30u
#define S32_GICD_ICPENDR_COUNT                      30u
#define S32_GICD_ISACTIVER_COUNT                    30u
#define S32_GICD_ICACTIVER_COUNT                    30u
#define S32_GICD_IPRIORITYR_COUNT                   240u
#define S32_GICD_ICFGR_COUNT                        60u
#define S32_GICD_IROUTER_COUNT                      960u
typedef struct
{
  __IO uint32_t GICD_CTLR;                                       /*!< \brief  Offset: 0x000 (R/W) Distributor Control Register */
  __I  uint32_t GICD_TYPRE;                                      /*!< \brief  Offset: 0x004 (RO) Interrupt Controller Type Register */
  __I  uint32_t GICD_IIDR;                                       /*!< \brief  Offset: 0x008 (RO) Distributor Implementer Identification Register */
       uint32_t RESERVED_0[30];
  __IO uint32_t GICD_IGROUPR[S32_GICD_IGROUPR_COUNT];            /*!< \brief  Offset: 0x084 (R/W) Interrupt Group Registers */
       uint32_t RESERVED_1[2];
  __IO uint32_t GICD_ISENABLER[S32_GICD_ISENABLER_COUNT];        /*!< \brief  Offset: 0x104 (R/W) Interrupt Set-Enable Registers */
       uint32_t RESERVED_2[2];
  __IO uint32_t GICD_ICENABLER[S32_GICD_ICENABLER_COUNT];        /*!< \brief  Offset: 0x184 (R/W) Interrupt Clear-Enable Registers */
       uint32_t RESERVED_3[2];
  __IO uint32_t GICD_ISPENDR[S32_GICD_ISPENDR_COUNT];            /*!< \brief  Offset: 0x204 (R/W) Interrupt Set-Pending Registers */
       uint32_t RESERVED_4[2];
  __IO uint32_t GICD_ICPENDR[S32_GICD_ICPENDR_COUNT];            /*!< \brief  Offset: 0x284 (R/W) Interrupt Clear-Pending Registers */
       uint32_t RESERVED_5[2];
  __IO uint32_t GICD_ISACTIVER[S32_GICD_ISACTIVER_COUNT];        /*!< \brief  Offset: 0x304 (R/W) Interrupt Set-Active Registers */
       uint32_t RESERVED_6[2];
  __IO uint32_t GICD_ICACTIVER[S32_GICD_ICACTIVER_COUNT];        /*!< \brief  Offset: 0x384 (R/W) Interrupt Clear-Active Registers */
       uint32_t RESERVED_7[9];
  __IO uint32_t GICD_IPRIORITYR[S32_GICD_IPRIORITYR_COUNT];      /*!< \brief  Offset: 0x420 (R/W) Interrupt Priority Registers */
       uint32_t RESERVED_8[266];
  __IO uint32_t GICD_ICFGR[S32_GICD_ICFGR_COUNT];                /*!< \brief  Offset: 0xC08 (R/W) Interrupt Configuration Registers */
       uint32_t RESERVED_9[5378];
  __IO uint64_t GICD_IROUTER[S32_GICD_IROUTER_COUNT];            /*!< \brief  Offset: 0x6100(R/W) Interrupt Routing Registers */
       uint32_t RESERVED_10[8244];
  __I  uint32_t GICD_PIDR4;                                      /*!< \brief  Offset: +0xFFD0 - RO - Identification Register */
  __I  uint32_t GICD_PIDR5;                                      /*!< \brief  Offset: +0xFFD4 - RO - Identification Register */
  __I  uint32_t GICD_PIDR6;                                      /*!< \brief  Offset: +0xFFD8 - RO - Identification Register */
  __I  uint32_t GICD_PIDR7;                                      /*!< \brief  Offset: +0xFFDC - RO - Identification Register */
  __I  uint32_t GICD_PIDR0;                                      /*!< \brief  Offset: +0xFFE0 - RO - Identification Register */
  __I  uint32_t GICD_PIDR1;                                      /*!< \brief  Offset: +0xFFE4 - RO - Identification Register */
  __I  uint32_t GICD_PIDR2;                                      /*!< \brief  Offset: +0xFFE8 - RO - Identification Register */
  __I  uint32_t GICD_PIDR3;                                      /*!< \brief  Offset: +0xFFEC - RO - Identification Register */
  __I  uint32_t GICD_CIDR0;                                      /*!< \brief  Offset: +0xFFF0 - RO - Component Identification Register */
  __I  uint32_t GICD_CIDR1;                                      /*!< \brief  Offset: +0xFFF4 - RO - Component Identification Register */
  __I  uint32_t GICD_CIDR2;                                      /*!< \brief  Offset: +0xFFF8 - RO - Component Identification Register */
  __I  uint32_t GICD_CIDR3;                                      /*!< \brief  Offset: +0xFFFC - RO - Component Identification Register */
}  S32_GICD_Type, *S32_GICDMemMapPtr;

/* S32_GICD - Peripheral instance base addresses */
/** Peripheral S32_GICD base address */
#define IP_S32_GICD_BASE                         (0x47800000u)
/** Peripheral S32_GICD base pointer */
#define S32_GICD                                 ((S32_GICD_Type *)IP_S32_GICD_BASE)

/** \brief  Structure type to access the Generic Interrupt Controller Redistributor (GICR)
*/

/** S32_GICR - Size of Registers Arrays */
#define S32_GICR_IPRIORITYR_COUNT                      8u

typedef struct
{
  __I  uint32_t GICR_CTLR;                                       /*!< \brief  Offset: 0x000 (RO) Redistributor Control Register */
  __I  uint32_t GICR_IIDR;                                       /*!< \brief  Offset: 0x004 (RO) Redistributor Implementer Identification Register */
  __I  uint32_t GICR_TYPER;                                      /*!< \brief  Offset: 0x008 (RO) Interrupt Controller Type Register */
       uint32_t RESERVED_0;
  __IO uint32_t GICR_WAKER;                                      /*!< \brief  Offset: 0x014 (R/W) Redistributor Wake Register */
       uint32_t RESERVED_1[26];
  __IO uint32_t GICR_IGROUPR;                                    /*!< \brief  Offset: 0x080 (R/W) Interrupt Group Registers */
       uint32_t RESERVED_2[31];
  __IO uint32_t GICR_ISENABLER;                                  /*!< \brief  Offset: 0x100 (R/W) Interrupt Set-Enable Registers */
       uint32_t RESERVED_3[31];
  __IO uint32_t GICR_ICENABLER;                                  /*!< \brief  Offset: 0x180 (R/W) Interrupt Clear-Enable Registers */
       uint32_t RESERVED_4[31];
  __IO uint32_t GICR_ISPENDR;                                    /*!< \brief  Offset: 0x200 (R/W) Interrupt Set-Pending Registers */
       uint32_t RESERVED_5[31];
  __IO uint32_t GICR_ICPENDR;                                    /*!< \brief  Offset: 0x280 (R/W) Interrupt Clear-Pending Registers */
       uint32_t RESERVED_6[31];
  __IO uint32_t GICR_ISACTIVER;                                  /*!< \brief  Offset: 0x300 (R/W) Interrupt Set-Active Registers */
       uint32_t RESERVED_7[31];
  __IO uint32_t GICR_ICACTIVER;                                  /*!< \brief  Offset: 0x380 (R/W) Interrupt Clear-Active Registers */
       uint32_t RESERVED_8[31];
  __IO uint32_t GICR_IPRIORITYR[S32_GICR_IPRIORITYR_COUNT];      /*!< \brief  Offset: 0x400 (R/W) Interrupt Priority Registers */
       uint32_t RESERVED_9[504];
  __IO uint32_t GICR_ICFGR0;                                     /*!< \brief  Offset: 0xC00 (R/W) Interrupt Configuration Registers 0 */
  __IO uint32_t GICR_ICFGR1;                                     /*!< \brief  Offset: 0xC04 (R/W) Interrupt Configuration Registers 1 */
       uint32_t RESERVED_10[15602];
  __I  uint32_t GICR_PIDR4;                                      /*!< \brief  Offset: +0xFFD0 - RO - Identification Register */
  __I  uint32_t GICR_PIDR5;                                      /*!< \brief  Offset: +0xFFD4 - RO - Identification Register */
  __I  uint32_t GICR_PIDR6;                                      /*!< \brief  Offset: +0xFFD8 - RO - Identification Register */
  __I  uint32_t GICR_PIDR7;                                      /*!< \brief  Offset: +0xFFDC - RO - Identification Register */
  __I  uint32_t GICR_PIDR0;                                      /*!< \brief  Offset: +0xFFE0 - RO - Identification Register */
  __I  uint32_t GICR_PIDR1;                                      /*!< \brief  Offset: +0xFFE4 - RO - Identification Register */
  __I  uint32_t GICR_PIDR2;                                      /*!< \brief  Offset: +0xFFE8 - RO - Identification Register */
  __I  uint32_t GICR_PIDR3;                                      /*!< \brief  Offset: +0xFFEC - RO - Identification Register */
  __I  uint32_t GICR_CIDR0;                                      /*!< \brief  Offset: +0xFFF0 - RO - Component Identification Register */
  __I  uint32_t GICR_CIDR1;                                      /*!< \brief  Offset: +0xFFF4 - RO - Component Identification Register */
  __I  uint32_t GICR_CIDR2;                                      /*!< \brief  Offset: +0xFFF8 - RO - Component Identification Register */
  __I  uint32_t GICR_CIDR3;                                      /*!< \brief  Offset: +0xFFFC - RO - Component Identification Register */
}  S32_GICR_Type, *S32_GICRMemMapPtr;

/* S32_GICR - Peripheral instance base addresses */
/** Peripheral S32_GICR base address */
#define IP_S32_GICR_BASE                         (0x47800000u)
/** Peripheral S32_GICR base pointer */
#define S32_GICR                                 ((S32_GICR_Type *)IP_S32_GICR_BASE)

/* ----------------------------------------------------------------------------
   -- S32_GIC Register Masks
   ---------------------------------------------------------------------------- */


/*!
 * @}
 */ /* end of group S32_GIC_Register_Masks */

/*!
 * @}
 */ /* end of group S32_GIC_Peripheral_Access_Layer */
/* Set this to 20, as stated by the R52 TRM, if the current value doesn't work */
#define GIC500_MSB                         (20U)
#define GIC500_REDIST_OFFSET               (1U << GIC500_MSB)
#define GIC500_PADDING_BYTES               (GIC500_REDIST_OFFSET - 0x40000U) 
 
#define IP_GIC500_BASE                     (0x47800000U)
#define IP_GIC500                          ((GIC500_Type *)IP_GIC500_BASE)
#define IP_GIC500_BASE_ADDRS               { IP_GIC500_BASE }
#define IP_GIC500_BASE_PTRS                { IP_GIC500 }

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum {
    GIC500_INTG_G0,
    GIC500_INTG_G1

} GIC500_IntGroupType;

typedef enum {
    GIC500_INTS_LEVEL,
    GIC500_INTS_EDGE

} GIC500_IntSignalType;

/* Follows the MPIDR_EL1 layout of Aff1 and Aff0 */
#define GIC500_AFF_CLUSTER0_CPU0    (0x0000UL)
#define GIC500_AFF_CLUSTER0_CPU1    (0x0001UL)
#define GIC500_AFF_CLUSTER0_CPU2    (0x0002UL)
#define GIC500_AFF_CLUSTER0_CPU3    (0x0003UL)

#define GIC500_AFF_CLUSTER1_CPU0    (0x0100UL)
#define GIC500_AFF_CLUSTER1_CPU1    (0x0101UL)
#define GIC500_AFF_CLUSTER1_CPU2    (0x0102UL)
#define GIC500_AFF_CLUSTER1_CPU3    (0x0103UL)

/* Special value - Use this to route to the executing core */
#define GIC500_AFF_CURRENT_PE       (0xFF55UL)

/* Special value - Use this to route to any participating PE ("1 of N") */
#define GIC500_AFF_ANY_PE           (0xFFAAUL)

/*
* The GIC-500 only supports topologies where affinity levels 2 and above are the same. That is,
* all cores must have MPIDR values of the form 0.0.c.d, where c and d are variables. The range
* for c is assumed to start at 0 and be contiguous. The range for d is also assumed to start at 0 and
* be contiguous for each c. For example, the first processor must have IDs 0.0.0.0 to 0.0.0.x and
* the second processor must have IDs 0.0.1.0 to 0.0.1.y
*/

/* Clusters map to Aff1 */
#define GIC500_CLUSTER_COUNT               (2U)
/* Cores map to Aff0 */
#define GIC500_CPU_PER_CLUSTER_COUNT       (4U)


#define GIC500_PRIO_BITS_COUNT             (5U)


#define GIC500_MIN_SGI_ID                  (0U)
#define GIC500_MIN_PPI_ID                  (16U)
#define GIC500_MIN_SPI_ID                  (32U)
#define GIC500_MAX_SPI_ID                  (960U)
#define GIC500_MAX_INT_ID                  (GIC500_MAX_SPI_ID + 32U)


/* MSB = 17 + max(1, ceil(log2 (total_number_of_cpus))) */
#define GIC500_CPU_COUNT                   (GIC500_CLUSTER_COUNT * GIC500_CPU_PER_CLUSTER_COUNT)
/* Set this to 20, as stated by the R52 TRM, if the current value doesn't work */
#define GIC500_MSB                         (20U)
#define GIC500_REDIST_OFFSET               (1U << GIC500_MSB)
#define GIC500_PADDING_BYTES               (GIC500_REDIST_OFFSET - 0x40000U)


#define IP_GIC500_BASE                     (0x47800000U)
#define IP_GIC500                          ((GIC500_Type *)IP_GIC500_BASE)
#define IP_GIC500_BASE_ADDRS               { IP_GIC500_BASE }
#define IP_GIC500_BASE_PTRS                { IP_GIC500 }
                                                                                                                                                        
#define GIC500_GICD_IROUTER_AFF2_MASK              (0x00FF0000UL)
#define GIC500_GICD_IROUTER_AFF2_SHIFT             (16UL)
#define GIC500_GICD_IROUTER_AFF2(x)                (((uint32)(((uint32)(x)) << GIC500_GICD_IROUTER_AFF2_SHIFT)) & GIC500_GICD_IROUTER_AFF2_MASK)

#define GIC500_GICD_IROUTER_AFF1_MASK              (0x0000FF00UL)
#define GIC500_GICD_IROUTER_AFF1_SHIFT             (8UL)
#define GIC500_GICD_IROUTER_AFF1(x)                (((uint32)(((uint32)(x)) << GIC500_GICD_IROUTER_AFF1_SHIFT)) & GIC500_GICD_IROUTER_AFF1_MASK)

#define GIC500_GICD_IROUTER_AFF0_MASK              (0x000000FFUL)
#define GIC500_GICD_IROUTER_AFF0_SHIFT             (0UL)
#define GIC500_GICD_IROUTER_AFF0(x)                (((uint32)(((uint32)(x)) << GIC500_GICD_IROUTER_AFF0_SHIFT)) & GIC500_GICD_IROUTER_AFF0_MASK)

#define GIC500_GICD_IROUTER_IRM_MASK               (0x80000000UL)
#define GIC500_GICD_IROUTER_IRM_SHIFT              (31UL)
#define GIC500_GICD_IROUTER_IRM(x)                 (((uint32)(((uint32)(x)) << GIC500_GICD_IROUTER_IRM_SHIFT)) & GIC500_GICD_IROUTER_IRM_MASK)
/*==================================================================================================
*                                          USER TYPES
==================================================================================================*/
struct gic500_gicd_if
{
          volatile uint32 CTLR;               /* +0x0000 - RW - Distributor Control Register */
    const volatile uint32 TYPER;              /* +0x0004 - RO - Interrupt Controller Type Register */
    const volatile uint32 IIDR;               /* +0x0008 - RO - Distributor Implementer Identification Register */
    const volatile uint32 padding0[13];       /* Reserved */      
          volatile uint32 SETSPI_NSR;         /* +0x0040 - WO - Non-Secure SPI Set Register (Used when SPI is signalled using MSI) */
    const volatile uint32 padding1;           /* Reserved */
          volatile uint32 CLRSPI_NSR;         /* +0x0048 - WO - Non-Secure SPI Clear Register (Used when SPI is signalled using MSI) */
    const volatile uint32 padding2;           /* Reserved */
          volatile uint32 SETSPI_SR;          /* +0x0050 - WO - Secure SPI Set Register (Used when SPI is signalled using MSI) */
    const volatile uint32 padding3;           /* Reserved */
          volatile uint32 CLRSPI_SR;          /* +0x0058 - WO - Secure SPI Clear Register (Used when SPI is signalled using MSI) */
    const volatile uint32 padding4[9];        /* Reserved */
          volatile uint32 IGROUPR[31];        /* +0x0080 - RW - Interrupt Group Registers */
    const volatile uint32 padding5;           /* Reserved */
          volatile uint32 ISENABLER[31];      /* +0x0100 - RW - Interrupt Set-Enable Registers */
    const volatile uint32 padding6;           /* Reserved */
          volatile uint32 ICENABLER[31];      /* +0x0180 - RW - Interrupt Clear-Enable Registers */
    const volatile uint32 padding7;           /* Reserved */
          volatile uint32 ISPENDR[31];        /* +0x0200 - RW - Interrupt Set-Pending Registers  */
    const volatile uint32 padding8;           /* Reserved */
          volatile uint32 ICPENDR[31];        /* +0x0280 - RW - Interrupt Clear-Pending Registers */
    const volatile uint32 padding9;           /* Reserved */
          volatile uint32 ISACTIVER[31];      /* +0x0300 - RW - Interrupt Set-Active Register */
    const volatile uint32 padding10;          /* Reserved */
          volatile uint32 ICACTIVER[31];      /* +0x0380 - RW - Interrupt Clear-Active Register */
    const volatile uint32 padding11;          /* Reserved */
          volatile uint32 IPRIORITYR[248];    /* +0x0400 - RW - Interrupt Priority Registers */
    const volatile uint32 padding12[8];       /* Reserved */
          volatile uint32 ITARGETSR[248];     /* +0x0800 - RW - Interrupt Processor Targets Registers */
    const volatile uint32 padding13[8];       /* Reserved */
          volatile uint32 ICFGR[62];          /* +0x0C00 - RW - Interrupt Configuration Registers */
    const volatile uint32 padding14[2];       /* Reserved */
    const volatile uint32 padding15[31];      /* Reserved */
    const volatile uint32 padding16[33];      /* Reserved */
          volatile uint32 NSACR[62];          /* +0x0E00 - RW - Non-Secure Access Control Registers */
    const volatile uint32 padding17[2];       /* Reserved */
          volatile uint32 SGIR;               /* +0x0F00 - WO - Software Generated Interrupt Register */
    const volatile uint32 padding18[3];       /* Reserved */
          volatile uint32 CPENDSGIR[4];       /* +0x0F10 - RW - SGI Clear-Pending Registers */
          volatile uint32 SPENDSGIR[4];       /* +0x0F20 - RW - SGI Set-Pending Registers */
    const volatile uint32 padding19[5236];    /* Reserved */
          volatile uint64 IROUTER[960];       /* +0x6100 - RW - Interrupt Routing Registers (Controls SPI routing when ARE=1) */
    const volatile uint32 padding20[4160];    /* Reserved */
    const volatile uint32 ESTATUSR;           /* +0xC000 - RO - Extended Status Register*/
          volatile uint32 ERRTESTR;           /* +0xC004 - WO - Error Test Register*/
    const volatile uint32 padding21[31];      /* Reserved */
    const volatile uint32 SPISR[30];          /* +0xC084 - RO - GIC-500 Shared Peripheral Interrupt Status Registers */
    const volatile uint32 padding22[4021];    /* Reserved */
    const volatile uint32 PIDR4;              /* +0xFFD0 - RO - Peripheral ID 4 Register */
    const volatile uint32 PIDR5;              /* +0xFFD4 - RO - Peripheral ID 5 Register */
    const volatile uint32 PIDR6;              /* +0xFFD8 - RO - Peripheral ID 6 Register */
    const volatile uint32 PIDR7;              /* +0xFFDC - RO - Peripheral ID 7 Register */
    const volatile uint32 PIDR0;              /* +0xFFE0 - RO - Peripheral ID 0 Register */
    const volatile uint32 PIDR1;              /* +0xFFE4 - RO - Peripheral ID 1 Register */
    const volatile uint32 PIDR2;              /* +0xFFE8 - RO - Peripheral ID 2 Register */
    const volatile uint32 PIDR3;              /* +0xFFEC - RO - Peripheral ID 3 Register */
    const volatile uint32 CIDR0;              /* +0xFFF0 - RO - Component ID 0 Register */
    const volatile uint32 CIDR1;              /* +0xFFF4 - RO - Component ID 1 Register */
    const volatile uint32 CIDR2;              /* +0xFFF8 - RO - Component ID 2 Register */
    const volatile uint32 CIDR3;              /* +0xFFFC - RO - Component ID 3 Register */
};

struct gic500_gicd_mbspi_if
{
    const volatile uint32 padding0[16];       /* Reserved */
          volatile uint32 SETSPI_NSR;         /* +0x0040 - WO - Aliased Non-secure SPI Set Register */
    const volatile uint32 padding1;           /* Reserved */
          volatile uint32 CLRSPI_NSR;         /* +0x0048 - WO - Aliased Non-secure SPI Clear Register */
    const volatile uint32 padding2;           /* Reserved */
          volatile uint32 SETSPI_SR;          /* +0x0050 - WO - Aliased Secure SPI Set Register */
    const volatile uint32 padding3;           /* Reserved */
          volatile uint32 CLRSPI_SR;          /* +0x0058 - WO - Aliased Secure SPI Clear Register */
    const volatile uint32 padding4[16361];    /* Reserved */
};

typedef struct gic500_gicr_if
{
          volatile uint32 CTLR;               /* +0x0000 - RW - Redistributor Control Register */
    const volatile uint32 IIDR;               /* +0x0004 - RO - Redistributor Implementer Identification Register */
    const volatile uint64 TYPER;              /* +0x0008 - RO - Redistributor Type Register */
    const volatile uint32 padding0;           /* Reserved */
          volatile uint32 WAKER;              /* +0x0014 - RW - Power Management Control Register */
    const volatile uint32 padding1[22];       /* Reserved */
          volatile uint64 PROPBASER;          /* +0x0070 - RW - Common LPI Configuration Table Register */
          volatile uint64 PENDBASER;          /* +0x0078 - RW - LPI Pending Table Base Register */
    const volatile uint32 padding2[16340];    /* Reserved */
    const volatile uint32 PIDR4;              /* +0xFFD0 - RO - Peripheral ID 4 Register */
    const volatile uint32 PIDR5;              /* +0xFFD4 - RO - Peripheral ID 5 Register */
    const volatile uint32 PIDR6;              /* +0xFFD8 - RO - Peripheral ID 6 Register */
    const volatile uint32 PIDR7;              /* +0xFFDC - RO - Peripheral ID 7 Register */
    const volatile uint32 PIDR0;              /* +0xFFE0 - RO - Peripheral ID 0 Register */
    const volatile uint32 PIDR1;              /* +0xFFE4 - RO - Peripheral ID 1 Register */
    const volatile uint32 PIDR2;              /* +0xFFE8 - RO - Peripheral ID 2 Register */
    const volatile uint32 PIDR3;              /* +0xFFEC - RO - Peripheral ID 3 Register */
    const volatile uint32 CIDR0;              /* +0xFFF0 - RO - Component ID 0 Register */
    const volatile uint32 CIDR1;              /* +0xFFF4 - RO - Component ID 1 Register */
    const volatile uint32 CIDR2;              /* +0xFFF8 - RO - Component ID 2 Register */
    const volatile uint32 CIDR3;              /* +0xFFFC - RO - Component ID 3 Register */
}gic500_gicr_if;

struct gic500_gicr_sgii_if
{
    const volatile uint32 padding0[32];       /* Reserved */
          volatile uint32 IGROUPR0;           /* +0x0080 - RW - Interrupt Group Registers */
    const volatile uint32 padding1[31];       /* Reserved */
          volatile uint32 ISENABLER0;         /* +0x0100 - RW - Interrupt Set-Enable Registers */
    const volatile uint32 padding2[31];       /* Reserved */
          volatile uint32 ICENABLER0;         /* +0x0180 - RW - Interrupt Clear-Enable Registers */
    const volatile uint32 padding3[31];       /* Reserved */
          volatile uint32 ISPENDR0;           /* +0x0200 - RW - Interrupt Set-Pending Registers */
    const volatile uint32 padding4[31];       /* Reserved */
          volatile uint32 ICPENDR0;           /* +0x0280 - RW - Interrupt Clear-Pending Registers */
    const volatile uint32 padding5[31];       /* Reserved */
          volatile uint32 ISACTIVER0;         /* +0x0300 - RW - Interrupt Set-Active Register */
    const volatile uint32 padding6[31];       /* Reserved */
          volatile uint32 ICACTIVER0;         /* +0x0380 - RW - Interrupt Clear-Active Register */
    const volatile uint32 padding7[31];       /* Reserved */
          volatile uint32 IPRIORITYR[8];      /* +0x0400 - RW - Interrupt Priority Registers */
    const volatile uint32 padding8[504];      /* Reserved */
          volatile uint32 ICFGR[2];           /* +0x0C00 - RW - Interrupt Configuration Registers */
    const volatile uint32 padding9[62];       /* Reserved */
    const volatile uint32 padding10;          /* Reserved */
    const volatile uint32 padding11[63];      /* Reserved */
          volatile uint32 NSACR;              /* +0x0E00 - RW - Non-Secure Access Control Register */
    const volatile uint32 padding12[11391];   /* Reserved */
    const volatile uint32 MISCSTATUSR;        /* +0xC000 - RO - Miscellaneous Status Register */
    const volatile uint32 padding13[31];      /* Reserved */
    const volatile uint32 PPISR;              /* +0xC080 - RO - Private Peripheral Interrupt Status Register */
    const volatile uint32 padding14[4063];    /* Reserved */
};


struct gic500_gits_if
{
          volatile uint32 CTLR;               /* +0x0000 - RW - ITS Control Register */
    const volatile uint32 IIDR;               /* +0x0004 - RO - Implementer Identification Register */
    const volatile uint64 TYPER;              /* +0x0008 - RO - ITS Type Register */
    const volatile uint32 padding0[28];       /* Reserved */
          volatile uint64 CBASER;             /* +0x0080 - RW - Command Queue Control Register */
          volatile uint64 CWRITER;            /* +0x0088 - RW - Command Queue Write Pointer Register */
    const volatile uint64 CREADR;             /* +0x0090 - RO - Command Queue Read Pointer Register */
    const volatile uint32 padding1[26];       /* Reserved */
    const volatile uint64 BASER;              /* +0x0100 - RW - ITS Table Control Register */
    const volatile uint32 padding2[12222];    /* Reserved */
          volatile uint32 TRKCTLR;            /* +0x0C00 - WO - Tracking Control Register */
    const volatile uint32 TRKR;               /* +0x0C04 - RO - Tracking Status Register */
    const volatile uint32 TRKDIDR;            /* +0x0C08 - RO - Debug Tracked DID Register */
    const volatile uint32 TRKPIDR;            /* +0x0C0C - RO - Debug Tracked PID Register */
    const volatile uint32 TRKVIDR;            /* +0x0C10 - RO - Debug Tracked VID Register */
    const volatile uint32 TRKTGTR;            /* +0x0C14 - RO - Debug Tracked Target Register */
    const volatile uint32 TRKICR;             /* +0x0C18 - RO - Debug ITE Cache Statistics Register */
    const volatile uint32 TRKLCR;             /* +0x0C1C - RO - Debug LPI Cache Statistics Register */
    const volatile uint32 padding3[4076];     /* Reserved */
    const volatile uint32 PIDR4;              /* +0xFFD0 - RO - Peripheral ID 4 Register */
    const volatile uint32 PIDR5;              /* +0xFFD4 - RO - Peripheral ID 5 Register */
    const volatile uint32 PIDR6;              /* +0xFFD8 - RO - Peripheral ID 6 Register */
    const volatile uint32 PIDR7;              /* +0xFFDC - RO - Peripheral ID 7 Register */
    const volatile uint32 PIDR0;              /* +0xFFE0 - RO - Peripheral ID 0 Register */
    const volatile uint32 PIDR1;              /* +0xFFE4 - RO - Peripheral ID 1 Register */
    const volatile uint32 PIDR2;              /* +0xFFE8 - RO - Peripheral ID 2 Register */
    const volatile uint32 PIDR3;              /* +0xFFEC - RO - Peripheral ID 3 Register */
    const volatile uint32 CIDR0;              /* +0xFFF0 - RO - Component ID 0 Register */
    const volatile uint32 CIDR1;              /* +0xFFF4 - RO - Component ID 1 Register */
    const volatile uint32 CIDR2;              /* +0xFFF8 - RO - Component ID 2 Register */
    const volatile uint32 CIDR3;              /* +0xFFFC - RO - Component ID 3 Register */
};


struct gic500_gits_tln_if
{
    const volatile uint32 padding0[16];       /* Reserved */
          volatile uint32 TRANSLATER;         /* +0x0040 - WO - ITS Translation Register */
    const volatile uint32 padding3[16367];    /* Reserved */
};


typedef struct {
    struct gic500_gicd_if        GICD;
    struct gic500_gicd_mbspi_if  GICD_MBSPI;
    struct gic500_gits_if        GITS;
    struct gic500_gits_tln_if    GITS_TLN;

#if (GIC500_PADDING_BYTES > 0)
    const volatile uint8 padding0[GIC500_PADDING_BYTES];
#endif

    struct wrapper0 {
        struct gic500_gicr_if      GICR;
        struct gic500_gicr_sgii_if GICR_SGII;
    } CPU[GIC500_CPU_COUNT];

} GIC500_Type;
 
 

#endif  /* #if !defined(S32Z2_GIC_H_) */
