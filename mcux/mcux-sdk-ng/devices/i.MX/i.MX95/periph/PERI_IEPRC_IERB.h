/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ieprc_ierb
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ieprc_ierb.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ieprc_ierb
 *
 * CMSIS Peripheral Access Layer for ieprc_ierb
 */

#if !defined(ieprc_ierb_H_)
#define ieprc_ierb_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- ieprc_ierb Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_ierb_Peripheral_Access_Layer ieprc_ierb Peripheral Access Layer
 * @{
 */

/** ieprc_ierb - Size of Registers Arrays */
#define ieprc_ierb_BUSX_COUNT                     2u

/** ieprc_ierb - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x20 */
    __IO uint32_t B_EC_F0_CFH_DIDVID;                /**< Bus n EC Function 0 config header device ID and vendor ID register, array offset: 0x0, array step: 0x20 */
    __IO uint32_t B_EC_F0_CFH_SIDSVID;               /**< Bus n EC Function 0 config header subsystem ID and subsystem vendor ID register, array offset: 0x4, array step: 0x20 */
    __IO uint32_t B_EC_F0_CFH_REVID;                 /**< Bus n EC Function 0 config header revision register, array offset: 0x8, array step: 0x20 */
         uint8_t RESERVED_0[20];
  } BUSX[ieprc_ierb_BUSX_COUNT];
       uint8_t RESERVED_0[8128];
  __I  uint32_t CAP0;                              /**< Capability 0 register, offset: 0x2000 */
       uint8_t RESERVED_1[12];
  __IO uint32_t EC_CFG;                            /**< EC Configuration register, offset: 0x2010 */
} ieprc_ierb_Type;

/* ----------------------------------------------------------------------------
   -- ieprc_ierb Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_ierb_Register_Masks ieprc_ierb Register Masks
 * @{
 */

/*! @name B_EC_F0_CFH_DIDVID - Bus n EC Function 0 config header device ID and vendor ID register */
/*! @{ */

#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_SHIFT (0U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_MASK)

#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_MASK (0xFFFF0000U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_SHIFT (16U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/* The count of ieprc_ierb_B_EC_F0_CFH_DIDVID */
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_COUNT      (2U)

/*! @name B_EC_F0_CFH_SIDSVID - Bus n EC Function 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/* The count of ieprc_ierb_B_EC_F0_CFH_SIDSVID */
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_COUNT     (2U)

/*! @name B_EC_F0_CFH_REVID - Bus n EC Function 0 config header revision register */
/*! @{ */

#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_MASK (0xFFU)
#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_SHIFT (0U)
#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_MASK)
/*! @} */

/* The count of ieprc_ierb_B_EC_F0_CFH_REVID */
#define ieprc_ierb_B_EC_F0_CFH_REVID_COUNT       (2U)

/*! @name CAP0 - Capability 0 register */
/*! @{ */

#define ieprc_ierb_CAP0_NUM_EP_MASK              (0x7U)
#define ieprc_ierb_CAP0_NUM_EP_SHIFT             (0U)
#define ieprc_ierb_CAP0_NUM_EP(x)                (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_NUM_EP_SHIFT)) & ieprc_ierb_CAP0_NUM_EP_MASK)

#define ieprc_ierb_CAP0_INT_TYPE_MASK            (0x8U)
#define ieprc_ierb_CAP0_INT_TYPE_SHIFT           (3U)
#define ieprc_ierb_CAP0_INT_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_INT_TYPE_SHIFT)) & ieprc_ierb_CAP0_INT_TYPE_MASK)

#define ieprc_ierb_CAP0_NUM_PCI_BUS_MASK         (0x7F0000U)
#define ieprc_ierb_CAP0_NUM_PCI_BUS_SHIFT        (16U)
#define ieprc_ierb_CAP0_NUM_PCI_BUS(x)           (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_NUM_PCI_BUS_SHIFT)) & ieprc_ierb_CAP0_NUM_PCI_BUS_MASK)

#define ieprc_ierb_CAP0_NUM_RCEC_MASK            (0x7F000000U)
#define ieprc_ierb_CAP0_NUM_RCEC_SHIFT           (24U)
#define ieprc_ierb_CAP0_NUM_RCEC(x)              (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_NUM_RCEC_SHIFT)) & ieprc_ierb_CAP0_NUM_RCEC_MASK)
/*! @} */

/*! @name EC_CFG - EC Configuration register */
/*! @{ */

#define ieprc_ierb_EC_CFG_FUNC_NUM_MASK          (0x7U)
#define ieprc_ierb_EC_CFG_FUNC_NUM_SHIFT         (0U)
#define ieprc_ierb_EC_CFG_FUNC_NUM(x)            (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_EC_CFG_FUNC_NUM_SHIFT)) & ieprc_ierb_EC_CFG_FUNC_NUM_MASK)

#define ieprc_ierb_EC_CFG_DEV_NUM_MASK           (0xF8U)
#define ieprc_ierb_EC_CFG_DEV_NUM_SHIFT          (3U)
#define ieprc_ierb_EC_CFG_DEV_NUM(x)             (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_EC_CFG_DEV_NUM_SHIFT)) & ieprc_ierb_EC_CFG_DEV_NUM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ieprc_ierb_Register_Masks */


/*!
 * @}
 */ /* end of group ieprc_ierb_Peripheral_Access_Layer */


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


#endif  /* ieprc_ierb_H_ */

