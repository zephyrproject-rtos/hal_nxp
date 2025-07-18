/*
** ###################################################################
**     Processors:          MC56F80623VLC
**                          MC56F80626VLF
**                          MC56F80643VLC
**                          MC56F80646VLF
**                          MC56F80648VLH
**                          MC56F80723VLC
**                          MC56F80726VLF
**                          MC56F80733VFM
**                          MC56F80736VLF
**                          MC56F80738VLH
**                          MC56F80743VFM
**                          MC56F80743VLC
**                          MC56F80746MLF
**                          MC56F80746VLF
**                          MC56F80748MLH
**                          MC56F80748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2022-01-12)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FMC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FMC
 *
 * CMSIS Peripheral Access Layer for FMC
 */

#if !defined(PERI_FMC_H_)
#define PERI_FMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F80623VLC))
#include "MC56F80623_COMMON.h"
#elif (defined(CPU_MC56F80626VLF))
#include "MC56F80626_COMMON.h"
#elif (defined(CPU_MC56F80643VLC))
#include "MC56F80643_COMMON.h"
#elif (defined(CPU_MC56F80646VLF))
#include "MC56F80646_COMMON.h"
#elif (defined(CPU_MC56F80648VLH))
#include "MC56F80648_COMMON.h"
#elif (defined(CPU_MC56F80723VLC))
#include "MC56F80723_COMMON.h"
#elif (defined(CPU_MC56F80726VLF))
#include "MC56F80726_COMMON.h"
#elif (defined(CPU_MC56F80733VFM))
#include "MC56F80733_COMMON.h"
#elif (defined(CPU_MC56F80736VLF))
#include "MC56F80736_COMMON.h"
#elif (defined(CPU_MC56F80738VLH))
#include "MC56F80738_COMMON.h"
#elif (defined(CPU_MC56F80743VFM) || defined(CPU_MC56F80743VLC))
#include "MC56F80743_COMMON.h"
#elif (defined(CPU_MC56F80746MLF) || defined(CPU_MC56F80746VLF))
#include "MC56F80746_COMMON.h"
#elif (defined(CPU_MC56F80748MLH) || defined(CPU_MC56F80748VLH))
#include "MC56F80748_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Size of Registers Arrays */
#define FMC_TAGVDW0S_COUNT                        4u
#define FMC_TAGVDW1S_COUNT                        4u
#define FMC_TAGVDW2S_COUNT                        4u
#define FMC_TAGVDW3S_COUNT                        4u
#define FMC_DATAW0S_COUNT                         4u
#define FMC_DATAW1S_COUNT                         4u
#define FMC_DATAW2S_COUNT                         4u
#define FMC_DATAW3S_COUNT                         4u

/** FMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PFAPR;                             /**< Flash Access Protection Register, offset: 0x0 */
  __IO uint32_t PFB0CR;                            /**< Flash Control Register, offset: 0x2 */
       uint16_t RESERVED_0[124];
  __IO uint32_t TAGVDW0S[FMC_TAGVDW0S_COUNT];      /**< Cache Tag Storage, array offset: 0x80, array step: 0x2 */
  __IO uint32_t TAGVDW1S[FMC_TAGVDW1S_COUNT];      /**< Cache Tag Storage, array offset: 0x88, array step: 0x2 */
  __IO uint32_t TAGVDW2S[FMC_TAGVDW2S_COUNT];      /**< Cache Tag Storage, array offset: 0x90, array step: 0x2 */
  __IO uint32_t TAGVDW3S[FMC_TAGVDW3S_COUNT];      /**< Cache Tag Storage, array offset: 0x98, array step: 0x2 */
       uint16_t RESERVED_1[96];
  __IO uint32_t DATAW0S[FMC_DATAW0S_COUNT];        /**< Cache Data Storage, array offset: 0x100, array step: 0x2 */
  __IO uint32_t DATAW1S[FMC_DATAW1S_COUNT];        /**< Cache Data Storage, array offset: 0x108, array step: 0x2 */
  __IO uint32_t DATAW2S[FMC_DATAW2S_COUNT];        /**< Cache Data Storage, array offset: 0x110, array step: 0x2 */
  __IO uint32_t DATAW3S[FMC_DATAW3S_COUNT];        /**< Cache Data Storage, array offset: 0x118, array step: 0x2 */
} FMC_Type;

/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/*! @name PFAPR - Flash Access Protection Register */
/*! @{ */

#define FMC_PFAPR_M0AP_MASK                      (0x3UL)
#define FMC_PFAPR_M0AP_SHIFT                     (0UL)
/*! M0AP - Master 0 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M0AP_SHIFT)) & FMC_PFAPR_M0AP_MASK)

#define FMC_PFAPR_M1AP_MASK                      (0xCUL)
#define FMC_PFAPR_M1AP_SHIFT                     (2UL)
/*! M1AP - Master 1 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M1AP_SHIFT)) & FMC_PFAPR_M1AP_MASK)

#define FMC_PFAPR_M2AP_MASK                      (0x30UL)
#define FMC_PFAPR_M2AP_SHIFT                     (4UL)
/*! M2AP - Master 2 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M2AP_SHIFT)) & FMC_PFAPR_M2AP_MASK)

#define FMC_PFAPR_M3AP_MASK                      (0xC0UL)
#define FMC_PFAPR_M3AP_SHIFT                     (6UL)
/*! M3AP - Master 3 Access Protection
 *  0b00..No access may be performed by this master
 *  0b01..Only read accesses may be performed by this master
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M3AP_SHIFT)) & FMC_PFAPR_M3AP_MASK)

#define FMC_PFAPR_M0PFD_MASK                     (0x10000UL)
#define FMC_PFAPR_M0PFD_SHIFT                    (16UL)
/*! M0PFD - Master 0 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M0PFD_SHIFT)) & FMC_PFAPR_M0PFD_MASK)

#define FMC_PFAPR_M1PFD_MASK                     (0x20000UL)
#define FMC_PFAPR_M1PFD_SHIFT                    (17UL)
/*! M1PFD - Master 1 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M1PFD_SHIFT)) & FMC_PFAPR_M1PFD_MASK)

#define FMC_PFAPR_M2PFD_MASK                     (0x40000UL)
#define FMC_PFAPR_M2PFD_SHIFT                    (18UL)
/*! M2PFD - Master 2 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M2PFD_SHIFT)) & FMC_PFAPR_M2PFD_MASK)

#define FMC_PFAPR_M3PFD_MASK                     (0x80000UL)
#define FMC_PFAPR_M3PFD_SHIFT                    (19UL)
/*! M3PFD - Master 3 Prefetch Disable
 *  0b0..Prefetching for this master is enabled.
 *  0b1..Prefetching for this master is disabled.
 */
#define FMC_PFAPR_M3PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M3PFD_SHIFT)) & FMC_PFAPR_M3PFD_MASK)
/*! @} */

/*! @name PFB0CR - Flash Control Register */
/*! @{ */

#define FMC_PFB0CR_B0SEBE_MASK                   (0x1UL)
#define FMC_PFB0CR_B0SEBE_SHIFT                  (0UL)
/*! B0SEBE - Single Entry Buffer Enable
 *  0b0..Single entry buffer is disabled.
 *  0b1..Single entry buffer is enabled.
 */
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0SEBE_SHIFT)) & FMC_PFB0CR_B0SEBE_MASK)

#define FMC_PFB0CR_B0IPE_MASK                    (0x2UL)
#define FMC_PFB0CR_B0IPE_SHIFT                   (1UL)
/*! B0IPE - Instruction Prefetch Enable
 *  0b0..Do not prefetch in response to instruction fetches.
 *  0b1..Enable prefetches in response to instruction fetches.
 */
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0IPE_SHIFT)) & FMC_PFB0CR_B0IPE_MASK)

#define FMC_PFB0CR_B0DPE_MASK                    (0x4UL)
#define FMC_PFB0CR_B0DPE_SHIFT                   (2UL)
/*! B0DPE - Data Prefetch Enable
 *  0b0..Do not prefetch in response to data references.
 *  0b1..Enable prefetches in response to data references.
 */
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0DPE_SHIFT)) & FMC_PFB0CR_B0DPE_MASK)

#define FMC_PFB0CR_B0ICE_MASK                    (0x8UL)
#define FMC_PFB0CR_B0ICE_SHIFT                   (3UL)
/*! B0ICE - Instruction Cache Enable
 *  0b0..Do not cache instruction fetches.
 *  0b1..Cache instruction fetches.
 */
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0ICE_SHIFT)) & FMC_PFB0CR_B0ICE_MASK)

#define FMC_PFB0CR_B0DCE_MASK                    (0x10UL)
#define FMC_PFB0CR_B0DCE_SHIFT                   (4UL)
/*! B0DCE - Data Cache Enable
 *  0b0..Do not cache data references.
 *  0b1..Cache data references.
 */
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0DCE_SHIFT)) & FMC_PFB0CR_B0DCE_MASK)

#define FMC_PFB0CR_CRC_MASK                      (0xE0UL)
#define FMC_PFB0CR_CRC_SHIFT                     (5UL)
/*! CRC - Cache Replacement Control
 *  0b000..LRU replacement algorithm per set across all four ways
 *  0b001..Reserved
 *  0b010..Independent LRU with ways [0-1] for ifetches, [2-3] for data
 *  0b011..Independent LRU with ways [0-2] for ifetches, [3] for data
 *  0b1xx..Reserved
 */
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CRC_SHIFT)) & FMC_PFB0CR_CRC_MASK)

#define FMC_PFB0CR_B0MW_MASK                     (0x60000UL)
#define FMC_PFB0CR_B0MW_SHIFT                    (17UL)
/*! B0MW - Memory Width
 *  0b00..32 bits
 *  0b01..64 bits
 *  0b1x..Reserved
 */
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0MW_SHIFT)) & FMC_PFB0CR_B0MW_MASK)

#define FMC_PFB0CR_S_B_INV_MASK                  (0x80000UL)
#define FMC_PFB0CR_S_B_INV_SHIFT                 (19UL)
/*! S_B_INV - Invalidate Prefetch Speculation Buffer
 *  0b0..Speculation buffer and single entry buffer are not affected.
 *  0b1..Invalidate (clear) speculation buffer and single entry buffer.
 */
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_S_B_INV_SHIFT)) & FMC_PFB0CR_S_B_INV_MASK)

#define FMC_PFB0CR_CINV_WAY_MASK                 (0xF00000UL)
#define FMC_PFB0CR_CINV_WAY_SHIFT                (20UL)
/*! CINV_WAY - Cache Invalidate Way x
 *  0b0000..No cache way invalidation for the corresponding cache
 *  0b0001..Invalidate cache way for the corresponding cache: clear the tag, data, and vld bits of ways selected
 */
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CINV_WAY_SHIFT)) & FMC_PFB0CR_CINV_WAY_MASK)

#define FMC_PFB0CR_CLCK_WAY_MASK                 (0xF000000UL)
#define FMC_PFB0CR_CLCK_WAY_SHIFT                (24UL)
/*! CLCK_WAY - Cache Lock Way x
 *  0b0000..Cache way is unlocked and may be displaced
 *  0b0001..Cache way is locked and its contents are not displaced
 */
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CLCK_WAY_SHIFT)) & FMC_PFB0CR_CLCK_WAY_MASK)

#define FMC_PFB0CR_B0RWSC_MASK                   (0xF0000000UL)
#define FMC_PFB0CR_B0RWSC_SHIFT                  (28UL)
/*! B0RWSC - Read Wait State Control */
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0RWSC_SHIFT)) & FMC_PFB0CR_B0RWSC_MASK)
/*! @} */

/*! @name TAGVDW0S - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW0S_VALID_MASK                  (0x1UL)
#define FMC_TAGVDW0S_VALID_SHIFT                 (0UL)
/*! VALID - 1-bit valid for cache entry */
#define FMC_TAGVDW0S_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S_VALID_SHIFT)) & FMC_TAGVDW0S_VALID_MASK)

#define FMC_TAGVDW0S_TAG_MASK                    (0xFFFF0UL)
#define FMC_TAGVDW0S_TAG_SHIFT                   (4UL)
/*! TAG - 16-bit17-bit tag for cache entry */
#define FMC_TAGVDW0S_TAG(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S_TAG_SHIFT)) & FMC_TAGVDW0S_TAG_MASK)
/*! @} */

/*! @name TAGVDW1S - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW1S_VALID_MASK                  (0x1UL)
#define FMC_TAGVDW1S_VALID_SHIFT                 (0UL)
/*! VALID - 1-bit valid for cache entry */
#define FMC_TAGVDW1S_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S_VALID_SHIFT)) & FMC_TAGVDW1S_VALID_MASK)

#define FMC_TAGVDW1S_TAG_MASK                    (0xFFFF0UL)
#define FMC_TAGVDW1S_TAG_SHIFT                   (4UL)
/*! TAG - 16-bit17-bit tag for cache entry */
#define FMC_TAGVDW1S_TAG(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S_TAG_SHIFT)) & FMC_TAGVDW1S_TAG_MASK)
/*! @} */

/*! @name TAGVDW2S - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW2S_VALID_MASK                  (0x1UL)
#define FMC_TAGVDW2S_VALID_SHIFT                 (0UL)
/*! VALID - 1-bit valid for cache entry */
#define FMC_TAGVDW2S_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S_VALID_SHIFT)) & FMC_TAGVDW2S_VALID_MASK)

#define FMC_TAGVDW2S_TAG_MASK                    (0xFFFF0UL)
#define FMC_TAGVDW2S_TAG_SHIFT                   (4UL)
/*! TAG - 16-bit17-bit tag for cache entry */
#define FMC_TAGVDW2S_TAG(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S_TAG_SHIFT)) & FMC_TAGVDW2S_TAG_MASK)
/*! @} */

/*! @name TAGVDW3S - Cache Tag Storage */
/*! @{ */

#define FMC_TAGVDW3S_VALID_MASK                  (0x1UL)
#define FMC_TAGVDW3S_VALID_SHIFT                 (0UL)
/*! VALID - 1-bit valid for cache entry */
#define FMC_TAGVDW3S_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S_VALID_SHIFT)) & FMC_TAGVDW3S_VALID_MASK)

#define FMC_TAGVDW3S_TAG_MASK                    (0xFFFF0UL)
#define FMC_TAGVDW3S_TAG_SHIFT                   (4UL)
/*! TAG - 16-bit17-bit tag for cache entry */
#define FMC_TAGVDW3S_TAG(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S_TAG_SHIFT)) & FMC_TAGVDW3S_TAG_MASK)
/*! @} */

/*! @name DATAW0S - Cache Data Storage */
/*! @{ */

#define FMC_DATAW0S_DATA_MASK                    (0xFFFFFFFFUL)
#define FMC_DATAW0S_DATA_SHIFT                   (0UL)
/*! DATA - Bits [31:0] of data entry */
#define FMC_DATAW0S_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_DATAW0S_DATA_SHIFT)) & FMC_DATAW0S_DATA_MASK)
/*! @} */

/*! @name DATAW1S - Cache Data Storage */
/*! @{ */

#define FMC_DATAW1S_DATA_MASK                    (0xFFFFFFFFUL)
#define FMC_DATAW1S_DATA_SHIFT                   (0UL)
/*! DATA - Bits [31:0] of data entry */
#define FMC_DATAW1S_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_DATAW1S_DATA_SHIFT)) & FMC_DATAW1S_DATA_MASK)
/*! @} */

/*! @name DATAW2S - Cache Data Storage */
/*! @{ */

#define FMC_DATAW2S_DATA_MASK                    (0xFFFFFFFFUL)
#define FMC_DATAW2S_DATA_SHIFT                   (0UL)
/*! DATA - Bits [31:0] of data entry */
#define FMC_DATAW2S_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_DATAW2S_DATA_SHIFT)) & FMC_DATAW2S_DATA_MASK)
/*! @} */

/*! @name DATAW3S - Cache Data Storage */
/*! @{ */

#define FMC_DATAW3S_DATA_MASK                    (0xFFFFFFFFUL)
#define FMC_DATAW3S_DATA_SHIFT                   (0UL)
/*! DATA - Bits [31:0] of data entry */
#define FMC_DATAW3S_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_DATAW3S_DATA_SHIFT)) & FMC_DATAW3S_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_FMC_H_ */

