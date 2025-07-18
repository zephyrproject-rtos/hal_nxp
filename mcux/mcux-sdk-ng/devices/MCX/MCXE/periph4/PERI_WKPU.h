/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WKPU
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
 * @file PERI_WKPU.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for WKPU
 *
 * CMSIS Peripheral Access Layer for WKPU
 */

#if !defined(PERI_WKPU_H_)
#define PERI_WKPU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- WKPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKPU_Peripheral_Access_Layer WKPU Peripheral Access Layer
 * @{
 */

/** WKPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t NSR;                               /**< NMI Status Flag Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t NCR;                               /**< NMI Configuration Register, offset: 0x8 */
       uint8_t RESERVED_1[8];
  __IO uint32_t WISR;                              /**< Wakeup/Interrupt Status Flag Register, offset: 0x14 */
  __IO uint32_t IRER;                              /**< Interrupt Request Enable Register, offset: 0x18 */
  __IO uint32_t WRER;                              /**< Wakeup Request Enable Register, offset: 0x1C */
       uint8_t RESERVED_2[8];
  __IO uint32_t WIREER;                            /**< Wakeup/Interrupt Rising-Edge Event Enable Register, offset: 0x28 */
  __IO uint32_t WIFEER;                            /**< Wakeup/Interrupt Falling-Edge Event Enable Register, offset: 0x2C */
  __IO uint32_t WIFER;                             /**< Wakeup/Interrupt Filter Enable Register, offset: 0x30 */
       uint8_t RESERVED_3[32];
  __IO uint32_t WISR_64;                           /**< Wakeup/Interrupt Status Flag Register, offset: 0x54 */
  __IO uint32_t IRER_64;                           /**< Interrupt Request Enable Register, offset: 0x58 */
  __IO uint32_t WRER_64;                           /**< Wakeup Request Enable Register, offset: 0x5C */
       uint8_t RESERVED_4[8];
  __IO uint32_t WIREER_64;                         /**< Wakeup/Interrupt Rising-Edge Event Enable Register, offset: 0x68 */
  __IO uint32_t WIFEER_64;                         /**< Wakeup/Interrupt Falling-Edge Event Enable Register, offset: 0x6C */
  __IO uint32_t WIFER_64;                          /**< Wakeup/Interrupt Filter Enable Register, offset: 0x70 */
} WKPU_Type;

/* ----------------------------------------------------------------------------
   -- WKPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKPU_Register_Masks WKPU Register Masks
 * @{
 */

/*! @name NSR - NMI Status Flag Register */
/*! @{ */

#define WKPU_NSR_NOVF0_MASK                      (0x40000000U)
#define WKPU_NSR_NOVF0_SHIFT                     (30U)
/*! NOVF0 - NMI Overrun Status Flag 0
 *  0b0..No overrun has occurred on NMI input 0
 *  0b1..An overrun has occurred on NMI input 0
 */
#define WKPU_NSR_NOVF0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NOVF0_SHIFT)) & WKPU_NSR_NOVF0_MASK)

#define WKPU_NSR_NIF0_MASK                       (0x80000000U)
#define WKPU_NSR_NIF0_SHIFT                      (31U)
/*! NIF0 - NMI Status Flag 0 */
#define WKPU_NSR_NIF0(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NSR_NIF0_SHIFT)) & WKPU_NSR_NIF0_MASK)
/*! @} */

/*! @name NCR - NMI Configuration Register */
/*! @{ */

#define WKPU_NCR_NFE0_MASK                       (0x1000000U)
#define WKPU_NCR_NFE0_SHIFT                      (24U)
/*! NFE0 - NMI Filter Enable 0
 *  0b0..Filter is disabled
 *  0b1..Filter is enabled
 */
#define WKPU_NCR_NFE0(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFE0_SHIFT)) & WKPU_NCR_NFE0_MASK)

#define WKPU_NCR_NFEE0_MASK                      (0x2000000U)
#define WKPU_NCR_NFEE0_SHIFT                     (25U)
/*! NFEE0 - NMI Falling-edge Events Enable 0 */
#define WKPU_NCR_NFEE0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NFEE0_SHIFT)) & WKPU_NCR_NFEE0_MASK)

#define WKPU_NCR_NREE0_MASK                      (0x4000000U)
#define WKPU_NCR_NREE0_SHIFT                     (26U)
/*! NREE0 - NMI Rising-Edge Events Enable 0
 *  0b0..Rising-edge event is disabled
 *  0b1..Rising-edge event is enabled
 */
#define WKPU_NCR_NREE0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NREE0_SHIFT)) & WKPU_NCR_NREE0_MASK)

#define WKPU_NCR_NWRE0_MASK                      (0x10000000U)
#define WKPU_NCR_NWRE0_SHIFT                     (28U)
/*! NWRE0 - NMI Wakeup Request Enable 0
 *  0b0..System wakeup requests from the corresponding NIF0 field are disabled
 *  0b1..Causes a system wakeup request when NIF0 = 1 or NOVF0 = 1
 */
#define WKPU_NCR_NWRE0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NWRE0_SHIFT)) & WKPU_NCR_NWRE0_MASK)

#define WKPU_NCR_NDSS0_MASK                      (0x60000000U)
#define WKPU_NCR_NDSS0_SHIFT                     (29U)
/*! NDSS0 - NMI Destination Source Select 0
 *  0b00..Non-maskable interrupt
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define WKPU_NCR_NDSS0(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NDSS0_SHIFT)) & WKPU_NCR_NDSS0_MASK)

#define WKPU_NCR_NLOCK0_MASK                     (0x80000000U)
#define WKPU_NCR_NLOCK0_SHIFT                    (31U)
/*! NLOCK0 - NMI Configuration Lock Register 0 */
#define WKPU_NCR_NLOCK0(x)                       (((uint32_t)(((uint32_t)(x)) << WKPU_NCR_NLOCK0_SHIFT)) & WKPU_NCR_NLOCK0_MASK)
/*! @} */

/*! @name WISR - Wakeup/Interrupt Status Flag Register */
/*! @{ */

#define WKPU_WISR_EIF_MASK                       (0xFFFFFFFFU)
#define WKPU_WISR_EIF_SHIFT                      (0U)
/*! EIF - External Wakeup/Interrupt Status Flag x */
#define WKPU_WISR_EIF(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_WISR_EIF_SHIFT)) & WKPU_WISR_EIF_MASK)
/*! @} */

/*! @name IRER - Interrupt Request Enable Register */
/*! @{ */

#define WKPU_IRER_EIRE_MASK                      (0xFFFFFFFFU)
#define WKPU_IRER_EIRE_SHIFT                     (0U)
/*! EIRE - External Interrupt Request Enable x */
#define WKPU_IRER_EIRE(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_IRER_EIRE_SHIFT)) & WKPU_IRER_EIRE_MASK)
/*! @} */

/*! @name WRER - Wakeup Request Enable Register */
/*! @{ */

#define WKPU_WRER_WRE_MASK                       (0xFFFFFFFFU)
#define WKPU_WRER_WRE_SHIFT                      (0U)
/*! WRE - External Wakeup Request Enable x */
#define WKPU_WRER_WRE(x)                         (((uint32_t)(((uint32_t)(x)) << WKPU_WRER_WRE_SHIFT)) & WKPU_WRER_WRE_MASK)
/*! @} */

/*! @name WIREER - Wakeup/Interrupt Rising-Edge Event Enable Register */
/*! @{ */

#define WKPU_WIREER_IREE_MASK                    (0xFFFFFFFFU)
#define WKPU_WIREER_IREE_SHIFT                   (0U)
/*! IREE - External Interrupt Rising-edge Events Enable x */
#define WKPU_WIREER_IREE(x)                      (((uint32_t)(((uint32_t)(x)) << WKPU_WIREER_IREE_SHIFT)) & WKPU_WIREER_IREE_MASK)
/*! @} */

/*! @name WIFEER - Wakeup/Interrupt Falling-Edge Event Enable Register */
/*! @{ */

#define WKPU_WIFEER_IFEEx_MASK                   (0xFFFFFFFFU)
#define WKPU_WIFEER_IFEEx_SHIFT                  (0U)
/*! IFEEx - External Interrupt Falling-edge Events Enable x */
#define WKPU_WIFEER_IFEEx(x)                     (((uint32_t)(((uint32_t)(x)) << WKPU_WIFEER_IFEEx_SHIFT)) & WKPU_WIFEER_IFEEx_MASK)
/*! @} */

/*! @name WIFER - Wakeup/Interrupt Filter Enable Register */
/*! @{ */

#define WKPU_WIFER_IFE_MASK                      (0xFFFFFFFFU)
#define WKPU_WIFER_IFE_SHIFT                     (0U)
/*! IFE - External Interrupt Filter Enable x */
#define WKPU_WIFER_IFE(x)                        (((uint32_t)(((uint32_t)(x)) << WKPU_WIFER_IFE_SHIFT)) & WKPU_WIFER_IFE_MASK)
/*! @} */

/*! @name WISR_64 - Wakeup/Interrupt Status Flag Register */
/*! @{ */

#define WKPU_WISR_64_EIF_1_MASK                  (0xFFFFFFFFU)
#define WKPU_WISR_64_EIF_1_SHIFT                 (0U)
/*! EIF_1 - External Wakeup/Interrupt Status Flag x */
#define WKPU_WISR_64_EIF_1(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WISR_64_EIF_1_SHIFT)) & WKPU_WISR_64_EIF_1_MASK)
/*! @} */

/*! @name IRER_64 - Interrupt Request Enable Register */
/*! @{ */

#define WKPU_IRER_64_EIRE_1_MASK                 (0xFFFFFFFFU)
#define WKPU_IRER_64_EIRE_1_SHIFT                (0U)
/*! EIRE_1 - External Interrupt Request Enable x */
#define WKPU_IRER_64_EIRE_1(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_IRER_64_EIRE_1_SHIFT)) & WKPU_IRER_64_EIRE_1_MASK)
/*! @} */

/*! @name WRER_64 - Wakeup Request Enable Register */
/*! @{ */

#define WKPU_WRER_64_WRE_1_MASK                  (0xFFFFFFFFU)
#define WKPU_WRER_64_WRE_1_SHIFT                 (0U)
/*! WRE_1 - External Wakeup Request Enable x */
#define WKPU_WRER_64_WRE_1(x)                    (((uint32_t)(((uint32_t)(x)) << WKPU_WRER_64_WRE_1_SHIFT)) & WKPU_WRER_64_WRE_1_MASK)
/*! @} */

/*! @name WIREER_64 - Wakeup/Interrupt Rising-Edge Event Enable Register */
/*! @{ */

#define WKPU_WIREER_64_IREE_1_MASK               (0xFFFFFFFFU)
#define WKPU_WIREER_64_IREE_1_SHIFT              (0U)
/*! IREE_1 - External Interrupt Rising-edge Events Enable x */
#define WKPU_WIREER_64_IREE_1(x)                 (((uint32_t)(((uint32_t)(x)) << WKPU_WIREER_64_IREE_1_SHIFT)) & WKPU_WIREER_64_IREE_1_MASK)
/*! @} */

/*! @name WIFEER_64 - Wakeup/Interrupt Falling-Edge Event Enable Register */
/*! @{ */

#define WKPU_WIFEER_64_IFEEx_1_MASK              (0xFFFFFFFFU)
#define WKPU_WIFEER_64_IFEEx_1_SHIFT             (0U)
/*! IFEEx_1 - External Interrupt Falling-edge Events Enable x */
#define WKPU_WIFEER_64_IFEEx_1(x)                (((uint32_t)(((uint32_t)(x)) << WKPU_WIFEER_64_IFEEx_1_SHIFT)) & WKPU_WIFEER_64_IFEEx_1_MASK)
/*! @} */

/*! @name WIFER_64 - Wakeup/Interrupt Filter Enable Register */
/*! @{ */

#define WKPU_WIFER_64_IFE_1_MASK                 (0xFFFFFFFFU)
#define WKPU_WIFER_64_IFE_1_SHIFT                (0U)
/*! IFE_1 - External Interrupt Filter Enable x */
#define WKPU_WIFER_64_IFE_1(x)                   (((uint32_t)(((uint32_t)(x)) << WKPU_WIFER_64_IFE_1_SHIFT)) & WKPU_WIFER_64_IFE_1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WKPU_Register_Masks */


/*!
 * @}
 */ /* end of group WKPU_Peripheral_Access_Layer */


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


#endif  /* PERI_WKPU_H_ */

