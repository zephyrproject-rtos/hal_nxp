/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CACHE64_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CACHE64_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CACHE64_CTRL
 *
 * CMSIS Peripheral Access Layer for CACHE64_CTRL
 */

#if !defined(PERI_CACHE64_CTRL_H_)
#define PERI_CACHE64_CTRL_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- CACHE64_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_CTRL_Peripheral_Access_Layer CACHE64_CTRL Peripheral Access Layer
 * @{
 */

/** CACHE64_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __IO uint32_t CCR;                               /**< Cache control register, offset: 0x800 */
  __IO uint32_t CLCR;                              /**< Cache line control register, offset: 0x804 */
  __IO uint32_t CSAR;                              /**< Cache search address register, offset: 0x808 */
  __IO uint32_t CCVR;                              /**< Cache read/write value register, offset: 0x80C */
} CACHE64_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- CACHE64_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_CTRL_Register_Masks CACHE64_CTRL Register Masks
 * @{
 */

/*! @name CCR - Cache control register */
/*! @{ */

#define CACHE64_CTRL_CCR_ENCACHE_MASK            (0x1U)
#define CACHE64_CTRL_CCR_ENCACHE_SHIFT           (0U)
/*! ENCACHE - Cache enable
 *  0b0..Cache disabled
 *  0b1..Cache enabled
 */
#define CACHE64_CTRL_CCR_ENCACHE(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_ENCACHE_SHIFT)) & CACHE64_CTRL_CCR_ENCACHE_MASK)

#define CACHE64_CTRL_CCR_ENWRBUF_MASK            (0x2U)
#define CACHE64_CTRL_CCR_ENWRBUF_SHIFT           (1U)
/*! ENWRBUF - Enable Write Buffer
 *  0b0..Write buffer disabled
 *  0b1..Write buffer enabled
 */
#define CACHE64_CTRL_CCR_ENWRBUF(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_ENWRBUF_SHIFT)) & CACHE64_CTRL_CCR_ENWRBUF_MASK)

#define CACHE64_CTRL_CCR_INVW0_MASK              (0x1000000U)
#define CACHE64_CTRL_CCR_INVW0_SHIFT             (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 0.
 */
#define CACHE64_CTRL_CCR_INVW0(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_INVW0_SHIFT)) & CACHE64_CTRL_CCR_INVW0_MASK)

#define CACHE64_CTRL_CCR_PUSHW0_MASK             (0x2000000U)
#define CACHE64_CTRL_CCR_PUSHW0_SHIFT            (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 0
 */
#define CACHE64_CTRL_CCR_PUSHW0(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_PUSHW0_SHIFT)) & CACHE64_CTRL_CCR_PUSHW0_MASK)

#define CACHE64_CTRL_CCR_INVW1_MASK              (0x4000000U)
#define CACHE64_CTRL_CCR_INVW1_SHIFT             (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 1
 */
#define CACHE64_CTRL_CCR_INVW1(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_INVW1_SHIFT)) & CACHE64_CTRL_CCR_INVW1_MASK)

#define CACHE64_CTRL_CCR_PUSHW1_MASK             (0x8000000U)
#define CACHE64_CTRL_CCR_PUSHW1_SHIFT            (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 1
 */
#define CACHE64_CTRL_CCR_PUSHW1(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_PUSHW1_SHIFT)) & CACHE64_CTRL_CCR_PUSHW1_MASK)

#define CACHE64_CTRL_CCR_GO_MASK                 (0x80000000U)
#define CACHE64_CTRL_CCR_GO_SHIFT                (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active.
 *  0b1..Write: initiate command indicated by bits 27-24. Read: cache command active.
 */
#define CACHE64_CTRL_CCR_GO(x)                   (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCR_GO_SHIFT)) & CACHE64_CTRL_CCR_GO_MASK)
/*! @} */

/*! @name CLCR - Cache line control register */
/*! @{ */

#define CACHE64_CTRL_CLCR_LGO_MASK               (0x1U)
#define CACHE64_CTRL_CLCR_LGO_SHIFT              (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits 27-24. Read: line command active.
 */
#define CACHE64_CTRL_CLCR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LGO_SHIFT)) & CACHE64_CTRL_CLCR_LGO_MASK)

#define CACHE64_CTRL_CLCR_CACHEADDR_MASK         (0xFFCU)
#define CACHE64_CTRL_CLCR_CACHEADDR_SHIFT        (2U)
/*! CACHEADDR - Cache address */
#define CACHE64_CTRL_CLCR_CACHEADDR(x)           (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_CACHEADDR_SHIFT)) & CACHE64_CTRL_CLCR_CACHEADDR_MASK)

#define CACHE64_CTRL_CLCR_WSEL_MASK              (0x4000U)
#define CACHE64_CTRL_CLCR_WSEL_SHIFT             (14U)
/*! WSEL - Way select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define CACHE64_CTRL_CLCR_WSEL(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_WSEL_SHIFT)) & CACHE64_CTRL_CLCR_WSEL_MASK)

#define CACHE64_CTRL_CLCR_TDSEL_MASK             (0x10000U)
#define CACHE64_CTRL_CLCR_TDSEL_SHIFT            (16U)
/*! TDSEL - Tag/Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define CACHE64_CTRL_CLCR_TDSEL(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_TDSEL_SHIFT)) & CACHE64_CTRL_CLCR_TDSEL_MASK)

#define CACHE64_CTRL_CLCR_LCIVB_MASK             (0x100000U)
#define CACHE64_CTRL_CLCR_LCIVB_SHIFT            (20U)
/*! LCIVB - Line Command Initial Valid Bit
 *  0b0..If command uses Cache Address and Way, then the initial state of the valid bit is 0. If command uses a
 *       Physical Address and is a hit, then the initial state of the valid bit is 0. If command uses a Physical
 *       Address and is a miss, then this bit reads 0.
 *  0b1..If command uses Cache Address and Way, then the initial state of the valid bit is 1. If command uses a
 *       Physical Address and is a hit, then the initial state of the valid bit is 1.
 */
#define CACHE64_CTRL_CLCR_LCIVB(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCIVB_SHIFT)) & CACHE64_CTRL_CLCR_LCIVB_MASK)

#define CACHE64_CTRL_CLCR_LCIMB_MASK             (0x200000U)
#define CACHE64_CTRL_CLCR_LCIMB_SHIFT            (21U)
/*! LCIMB - Line Command Initial Modified Bit
 *  0b0..If command uses Cache Address and Way, then the initial state of the modified bit is 0. If command uses a
 *       Physical Address and is a hit, then the initial state of the modified bit is 0. If command uses a
 *       Physical Address and is a miss, then this bit reads 0.
 *  0b1..If command uses Cache Address and Way, then the initial state of the modified bit is 1. If command uses a
 *       Physical Address and is a hit, then the initial state of the modified bit is 1.
 */
#define CACHE64_CTRL_CLCR_LCIMB(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCIMB_SHIFT)) & CACHE64_CTRL_CLCR_LCIMB_MASK)

#define CACHE64_CTRL_CLCR_LCWAY_MASK             (0x400000U)
#define CACHE64_CTRL_CLCR_LCWAY_SHIFT            (22U)
/*! LCWAY - Line Command Way
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define CACHE64_CTRL_CLCR_LCWAY(x)               (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCWAY_SHIFT)) & CACHE64_CTRL_CLCR_LCWAY_MASK)

#define CACHE64_CTRL_CLCR_LCMD_MASK              (0x3000000U)
#define CACHE64_CTRL_CLCR_LCMD_SHIFT             (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write. LACC bit determines if operation is a read or write.
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define CACHE64_CTRL_CLCR_LCMD(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LCMD_SHIFT)) & CACHE64_CTRL_CLCR_LCMD_MASK)

#define CACHE64_CTRL_CLCR_LADSEL_MASK            (0x4000000U)
#define CACHE64_CTRL_CLCR_LADSEL_SHIFT           (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address. WSEL and CACHEADDR bitfields specify the address.
 *  0b1..Physical address. CSAR register specifies the address.
 */
#define CACHE64_CTRL_CLCR_LADSEL(x)              (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LADSEL_SHIFT)) & CACHE64_CTRL_CLCR_LADSEL_MASK)

#define CACHE64_CTRL_CLCR_LACC_MASK              (0x8000000U)
#define CACHE64_CTRL_CLCR_LACC_SHIFT             (27U)
/*! LACC - Line access type
 *  0b0..Read
 *  0b1..Write
 */
#define CACHE64_CTRL_CLCR_LACC(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CLCR_LACC_SHIFT)) & CACHE64_CTRL_CLCR_LACC_MASK)
/*! @} */

/*! @name CSAR - Cache search address register */
/*! @{ */

#define CACHE64_CTRL_CSAR_LGO_MASK               (0x1U)
#define CACHE64_CTRL_CSAR_LGO_SHIFT              (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits CLCR[27:24]. Read: line command active.
 */
#define CACHE64_CTRL_CSAR_LGO(x)                 (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_LGO_SHIFT)) & CACHE64_CTRL_CSAR_LGO_MASK)

#define CACHE64_CTRL_CSAR_PHYADDR_MASK           (0xFFFFFFFEU)
#define CACHE64_CTRL_CSAR_PHYADDR_SHIFT          (1U)
/*! PHYADDR - Physical Address */
#define CACHE64_CTRL_CSAR_PHYADDR(x)             (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CSAR_PHYADDR_SHIFT)) & CACHE64_CTRL_CSAR_PHYADDR_MASK)
/*! @} */

/*! @name CCVR - Cache read/write value register */
/*! @{ */

#define CACHE64_CTRL_CCVR_DATA_MASK              (0xFFFFFFFFU)
#define CACHE64_CTRL_CCVR_DATA_SHIFT             (0U)
/*! DATA - Cache read/write Data */
#define CACHE64_CTRL_CCVR_DATA(x)                (((uint32_t)(((uint32_t)(x)) << CACHE64_CTRL_CCVR_DATA_SHIFT)) & CACHE64_CTRL_CCVR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CACHE64_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group CACHE64_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_CACHE64_CTRL_H_ */

