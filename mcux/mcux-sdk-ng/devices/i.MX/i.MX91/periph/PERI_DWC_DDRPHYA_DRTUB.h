/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_DRTUB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_DRTUB.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_DRTUB
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_DRTUB
 */

#if !defined(PERI_DWC_DDRPHYA_DRTUB_H_)
#define PERI_DWC_DDRPHYA_DRTUB_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- DWC_DDRPHYA_DRTUB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DRTUB_Peripheral_Access_Layer DWC_DDRPHYA_DRTUB Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_DRTUB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t DCTSHADOWREGS;                     /**< PMU/Controller Protocol - PMU Read-only Shadow, offset: 0x8 */
       uint8_t RESERVED_1[86];
  __I  uint16_t DCTWRITEONLYSHADOW;                /**< Read-only view of DctWriteOnly., offset: 0x60 */
       uint8_t RESERVED_2[2];
  __IO uint16_t UCTWRITEONLY;                      /**< UCT upstream message mailbox CSR., offset: 0x64 */
  __IO uint16_t UCTWRITEPROT;                      /**< UCT upstream mailbox protocol CSR., offset: 0x66 */
  __IO uint16_t UCTDATWRITEONLY;                   /**< UCT upstream data mailbox CSR., offset: 0x68 */
  __IO uint16_t UCTDATWRITEPROT;                   /**< UCT upstream data mailbox protocol CSR., offset: 0x6A */
  __IO uint16_t UCTLERR;                           /**< UCT Error output., offset: 0x6C */
       uint8_t RESERVED_3[146];
  __IO uint16_t UCCLKHCLKENABLES;                  /**< Ucclk and Hclk enables, offset: 0x100 */
  __IO uint16_t CURPSTATE0B;                       /**< PIE current Pstate value, offset: 0x102 */
       uint8_t RESERVED_4[38];
  __IO uint16_t CLRWAKEUPSTICKY;                   /**< PMU interrupt sticky bit control, offset: 0x12A */
  __IO uint16_t WAKEUPMASK;                        /**< Wake up mask, offset: 0x12C */
       uint8_t RESERVED_5[172];
  __I  uint16_t CUSTPUBREV;                        /**< Customer settable by the customer, offset: 0x1DA */
  __I  uint16_t PUBREV;                            /**< The hardware version of this PUB, excluding the PHY, offset: 0x1DC */
} DWC_DDRPHYA_DRTUB_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_DRTUB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DRTUB_Register_Masks DWC_DDRPHYA_DRTUB Register Masks
 * @{
 */

/*! @name DCTSHADOWREGS - PMU/Controller Protocol - PMU Read-only Shadow */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_DCTSHADOWREGS_RFU_DctShadowRegs_MASK (0x1U)
#define DWC_DDRPHYA_DRTUB_DCTSHADOWREGS_RFU_DctShadowRegs_SHIFT (0U)
/*! RFU_DctShadowRegs - RFU_DctShadowRegs */
#define DWC_DDRPHYA_DRTUB_DCTSHADOWREGS_RFU_DctShadowRegs(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_DCTSHADOWREGS_RFU_DctShadowRegs_SHIFT)) & DWC_DDRPHYA_DRTUB_DCTSHADOWREGS_RFU_DctShadowRegs_MASK)
/*! @} */

/*! @name DCTWRITEONLYSHADOW - Read-only view of DctWriteOnly. */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_DCTWRITEONLYSHADOW_DctWriteOnlyShadow_MASK (0xFFFFU)
#define DWC_DDRPHYA_DRTUB_DCTWRITEONLYSHADOW_DctWriteOnlyShadow_SHIFT (0U)
/*! DctWriteOnlyShadow - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_DCTWRITEONLYSHADOW_DctWriteOnlyShadow(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_DCTWRITEONLYSHADOW_DctWriteOnlyShadow_SHIFT)) & DWC_DDRPHYA_DRTUB_DCTWRITEONLYSHADOW_DctWriteOnlyShadow_MASK)
/*! @} */

/*! @name UCTWRITEONLY - UCT upstream message mailbox CSR. */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCTWRITEONLY_UctWriteOnly_MASK (0xFFFFU)
#define DWC_DDRPHYA_DRTUB_UCTWRITEONLY_UctWriteOnly_SHIFT (0U)
/*! UctWriteOnly - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_UCTWRITEONLY_UctWriteOnly(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCTWRITEONLY_UctWriteOnly_SHIFT)) & DWC_DDRPHYA_DRTUB_UCTWRITEONLY_UctWriteOnly_MASK)
/*! @} */

/*! @name UCTWRITEPROT - UCT upstream mailbox protocol CSR. */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCTWRITEPROT_UctWriteProt_MASK (0x1U)
#define DWC_DDRPHYA_DRTUB_UCTWRITEPROT_UctWriteProt_SHIFT (0U)
/*! UctWriteProt - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_UCTWRITEPROT_UctWriteProt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCTWRITEPROT_UctWriteProt_SHIFT)) & DWC_DDRPHYA_DRTUB_UCTWRITEPROT_UctWriteProt_MASK)
/*! @} */

/*! @name UCTDATWRITEONLY - UCT upstream data mailbox CSR. */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCTDATWRITEONLY_UctDatWriteOnly_MASK (0xFFFFU)
#define DWC_DDRPHYA_DRTUB_UCTDATWRITEONLY_UctDatWriteOnly_SHIFT (0U)
/*! UctDatWriteOnly - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_UCTDATWRITEONLY_UctDatWriteOnly(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCTDATWRITEONLY_UctDatWriteOnly_SHIFT)) & DWC_DDRPHYA_DRTUB_UCTDATWRITEONLY_UctDatWriteOnly_MASK)
/*! @} */

/*! @name UCTDATWRITEPROT - UCT upstream data mailbox protocol CSR. */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCTDATWRITEPROT_UctDatWriteProt_MASK (0x1U)
#define DWC_DDRPHYA_DRTUB_UCTDATWRITEPROT_UctDatWriteProt_SHIFT (0U)
/*! UctDatWriteProt - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_UCTDATWRITEPROT_UctDatWriteProt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCTDATWRITEPROT_UctDatWriteProt_SHIFT)) & DWC_DDRPHYA_DRTUB_UCTDATWRITEPROT_UctDatWriteProt_MASK)
/*! @} */

/*! @name UCTLERR - UCT Error output. */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCTLERR_UctlErr_MASK   (0x1U)
#define DWC_DDRPHYA_DRTUB_UCTLERR_UctlErr_SHIFT  (0U)
/*! UctlErr - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_UCTLERR_UctlErr(x)     (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCTLERR_UctlErr_SHIFT)) & DWC_DDRPHYA_DRTUB_UCTLERR_UctlErr_MASK)
/*! @} */

/*! @name UCCLKHCLKENABLES - Ucclk and Hclk enables */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UcclkEn_MASK (0x1U)
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UcclkEn_SHIFT (0U)
/*! UcclkEn - When training has completed (and assuming no further need for the microcontroller),
 *    the enable should be set to 0 to reduce power.
 */
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UcclkEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UcclkEn_SHIFT)) & DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UcclkEn_MASK)

#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HclkEn_MASK (0x2U)
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HclkEn_SHIFT (1U)
/*! HclkEn - When training has completed (and assuming no further need for the training hardware),
 *    the enable should be set to 0 to reduce power.
 */
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HclkEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HclkEn_SHIFT)) & DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HclkEn_MASK)
/*! @} */

/*! @name CURPSTATE0B - PIE current Pstate value */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_CURPSTATE0B_CurPstate0b_MASK (0xFU)
#define DWC_DDRPHYA_DRTUB_CURPSTATE0B_CurPstate0b_SHIFT (0U)
/*! CurPstate0b - CurPstate0b */
#define DWC_DDRPHYA_DRTUB_CURPSTATE0B_CurPstate0b(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_CURPSTATE0B_CurPstate0b_SHIFT)) & DWC_DDRPHYA_DRTUB_CURPSTATE0B_CurPstate0b_MASK)
/*! @} */

/*! @name CLRWAKEUPSTICKY - PMU interrupt sticky bit control */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_CLRWAKEUPSTICKY_ClrWakeupSticky_MASK (0xFU)
#define DWC_DDRPHYA_DRTUB_CLRWAKEUPSTICKY_ClrWakeupSticky_SHIFT (0U)
/*! ClrWakeupSticky - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_CLRWAKEUPSTICKY_ClrWakeupSticky(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_CLRWAKEUPSTICKY_ClrWakeupSticky_SHIFT)) & DWC_DDRPHYA_DRTUB_CLRWAKEUPSTICKY_ClrWakeupSticky_MASK)
/*! @} */

/*! @name WAKEUPMASK - Wake up mask */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_WAKEUPMASK_WakeupMask_MASK (0xFU)
#define DWC_DDRPHYA_DRTUB_WAKEUPMASK_WakeupMask_SHIFT (0U)
/*! WakeupMask - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DRTUB_WAKEUPMASK_WakeupMask(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_WAKEUPMASK_WakeupMask_SHIFT)) & DWC_DDRPHYA_DRTUB_WAKEUPMASK_WakeupMask_MASK)
/*! @} */

/*! @name CUSTPUBREV - Customer settable by the customer */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_MASK (0x3FU)
#define DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_SHIFT (0U)
/*! CUSTPUBREV - The customer settable PUB version number. */
#define DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_SHIFT)) & DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_MASK)
/*! @} */

/*! @name PUBREV - The hardware version of this PUB, excluding the PHY */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_MASK     (0xFU)
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_SHIFT    (0U)
/*! PUBMNR - Indicates minor update of the PUB. */
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_SHIFT)) & DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_MASK)

#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_MASK     (0xF0U)
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_SHIFT    (4U)
/*! PUBMDR - Indicates moderate revision of the PUB. */
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_SHIFT)) & DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_MASK)

#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_MASK     (0xFF00U)
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_SHIFT    (8U)
/*! PUBMJR - Indicates major revision of the PUB. */
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_SHIFT)) & DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_DRTUB_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_DRTUB_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_DRTUB_H_ */
