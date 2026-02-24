/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ieprc_ierb
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ieprc_ierb.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ieprc_ierb
 *
 * CMSIS Peripheral Access Layer for ieprc_ierb
 */

#if !defined(PERI_IEPRC_IERB_H_)
#define PERI_IEPRC_IERB_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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


#endif  /* PERI_IEPRC_IERB_H_ */

