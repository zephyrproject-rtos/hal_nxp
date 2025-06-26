/*
** ###################################################################
**     Processors:          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 2.0, 2023-02-01
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BSP32
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**
** ###################################################################
*/

/*!
 * @file BSP32.h
 * @version 2.0
 * @date 2023-02-01
 * @brief CMSIS Peripheral Access Layer for BSP32
 *
 * CMSIS Peripheral Access Layer for BSP32
 */

#if !defined(BSP32_H_)
#define BSP32_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- BSP32 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BSP32_Peripheral_Access_Layer BSP32 Peripheral Access Layer
 * @{
 */

/** BSP32 - Register Layout Typedef */
typedef struct {
  __IO uint32_t OFFSET_PMEM;                       /**< Offset address register for program memory, offset: 0x0 */
  __IO uint32_t OFFSET_XMEM;                       /**< Offset address register for X-data memory, offset: 0x4 */
  __IO uint32_t OFFSET_YMEM;                       /**< Offset address register for Y-data memory, offset: 0x8 */
  __IO uint32_t OFFSET_MAILBOX;                    /**< Offset address register for mailbox peripheral, offset: 0xC */
  __IO uint32_t INTERRUPTS_EXTERNAL;               /**< External interrupt register, offset: 0x10 */
  __IO uint32_t INTERRUPTS_STATUS;                 /**< Interrupt status register, offset: 0x14 */
  __IO uint32_t CF_GATING_OVERRIDE;                /**< CoolFlux BSP32 gating override, offset: 0x18 */
  __IO uint32_t IVT_OFFSET;                        /**< CoolFlux BSP32 IVT offset register, offset: 0x1C */
  __I  uint32_t SLEEP_MODE;                        /**< CoolFlux BSP32 sleep mode register, offset: 0x20 */
  __IO uint32_t IVT0;                              /**< CoolFlux BSP32 IVT register 0 content, offset: 0x24 */
  __IO uint32_t IVT1;                              /**< CoolFlux BSP32 IVT register 1 content, offset: 0x28 */
  __IO uint32_t IVT2;                              /**< CoolFlux BSP32 IVT register 2 content, offset: 0x2C */
  __IO uint32_t IVT3;                              /**< CoolFlux BSP32 IVT register 3 content, offset: 0x30 */
  __IO uint32_t IVT_DISABLE;                       /**< CoolFlux BSP32 IVT disable register, offset: 0x34 */
} BSP32_Type;

/* ----------------------------------------------------------------------------
   -- BSP32 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BSP32_Register_Masks BSP32 Register Masks
 * @{
 */

/*! @name OFFSET_PMEM - Offset address register for program memory */
/*! @{ */

#define BSP32_OFFSET_PMEM_VAL_MASK               (0x3FU)
#define BSP32_OFFSET_PMEM_VAL_SHIFT              (0U)
/*! val - Offset address register for program memory */
#define BSP32_OFFSET_PMEM_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << BSP32_OFFSET_PMEM_VAL_SHIFT)) & BSP32_OFFSET_PMEM_VAL_MASK)
/*! @} */

/*! @name OFFSET_XMEM - Offset address register for X-data memory */
/*! @{ */

#define BSP32_OFFSET_XMEM_VAL_MASK               (0xFFU)
#define BSP32_OFFSET_XMEM_VAL_SHIFT              (0U)
/*! val - Offset address register for X-data memory */
#define BSP32_OFFSET_XMEM_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << BSP32_OFFSET_XMEM_VAL_SHIFT)) & BSP32_OFFSET_XMEM_VAL_MASK)
/*! @} */

/*! @name OFFSET_YMEM - Offset address register for Y-data memory */
/*! @{ */

#define BSP32_OFFSET_YMEM_VAL_MASK               (0xFFU)
#define BSP32_OFFSET_YMEM_VAL_SHIFT              (0U)
/*! val - Offset address register for Y-data memory */
#define BSP32_OFFSET_YMEM_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << BSP32_OFFSET_YMEM_VAL_SHIFT)) & BSP32_OFFSET_YMEM_VAL_MASK)
/*! @} */

/*! @name OFFSET_MAILBOX - Offset address register for mailbox peripheral */
/*! @{ */

#define BSP32_OFFSET_MAILBOX_VAL_MASK            (0xFFFFFFU)
#define BSP32_OFFSET_MAILBOX_VAL_SHIFT           (0U)
/*! val - Offset address register for mailbox peripheral */
#define BSP32_OFFSET_MAILBOX_VAL(x)              (((uint32_t)(((uint32_t)(x)) << BSP32_OFFSET_MAILBOX_VAL_SHIFT)) & BSP32_OFFSET_MAILBOX_VAL_MASK)
/*! @} */

/*! @name INTERRUPTS_EXTERNAL - External interrupt register */
/*! @{ */

#define BSP32_INTERRUPTS_EXTERNAL_VAL_MASK       (0xFFFFFFFFU)
#define BSP32_INTERRUPTS_EXTERNAL_VAL_SHIFT      (0U)
/*! val - External interrupt register */
#define BSP32_INTERRUPTS_EXTERNAL_VAL(x)         (((uint32_t)(((uint32_t)(x)) << BSP32_INTERRUPTS_EXTERNAL_VAL_SHIFT)) & BSP32_INTERRUPTS_EXTERNAL_VAL_MASK)
/*! @} */

/*! @name INTERRUPTS_STATUS - Interrupt status register */
/*! @{ */

#define BSP32_INTERRUPTS_STATUS_VAL_MASK         (0x1U)
#define BSP32_INTERRUPTS_STATUS_VAL_SHIFT        (0U)
/*! val - Interrupt status register */
#define BSP32_INTERRUPTS_STATUS_VAL(x)           (((uint32_t)(((uint32_t)(x)) << BSP32_INTERRUPTS_STATUS_VAL_SHIFT)) & BSP32_INTERRUPTS_STATUS_VAL_MASK)
/*! @} */

/*! @name CF_GATING_OVERRIDE - CoolFlux BSP32 gating override */
/*! @{ */

#define BSP32_CF_GATING_OVERRIDE_VAL_MASK        (0x1U)
#define BSP32_CF_GATING_OVERRIDE_VAL_SHIFT       (0U)
/*! val - CoolFlux BSP32 gating override */
#define BSP32_CF_GATING_OVERRIDE_VAL(x)          (((uint32_t)(((uint32_t)(x)) << BSP32_CF_GATING_OVERRIDE_VAL_SHIFT)) & BSP32_CF_GATING_OVERRIDE_VAL_MASK)
/*! @} */

/*! @name IVT_OFFSET - CoolFlux BSP32 IVT offset register */
/*! @{ */

#define BSP32_IVT_OFFSET_VAL_MASK                (0xFFFFFFU)
#define BSP32_IVT_OFFSET_VAL_SHIFT               (0U)
/*! val - CoolFlux BSP32 IVT offset register */
#define BSP32_IVT_OFFSET_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << BSP32_IVT_OFFSET_VAL_SHIFT)) & BSP32_IVT_OFFSET_VAL_MASK)
/*! @} */

/*! @name SLEEP_MODE - CoolFlux BSP32 sleep mode register */
/*! @{ */

#define BSP32_SLEEP_MODE_VAL_MASK                (0x1U)
#define BSP32_SLEEP_MODE_VAL_SHIFT               (0U)
/*! val - CoolFlux BSP32 sleep mode register */
#define BSP32_SLEEP_MODE_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << BSP32_SLEEP_MODE_VAL_SHIFT)) & BSP32_SLEEP_MODE_VAL_MASK)
/*! @} */

/*! @name IVT0 - CoolFlux BSP32 IVT register 0 content */
/*! @{ */

#define BSP32_IVT0_VAL_MASK                      (0xFFFFFFU)
#define BSP32_IVT0_VAL_SHIFT                     (0U)
/*! val - CoolFlux BSP32 IVT register 0 content */
#define BSP32_IVT0_VAL(x)                        (((uint32_t)(((uint32_t)(x)) << BSP32_IVT0_VAL_SHIFT)) & BSP32_IVT0_VAL_MASK)
/*! @} */

/*! @name IVT1 - CoolFlux BSP32 IVT register 1 content */
/*! @{ */

#define BSP32_IVT1_VAL_MASK                      (0xFFFFFFU)
#define BSP32_IVT1_VAL_SHIFT                     (0U)
/*! val - CoolFlux BSP32 IVT register 1 content */
#define BSP32_IVT1_VAL(x)                        (((uint32_t)(((uint32_t)(x)) << BSP32_IVT1_VAL_SHIFT)) & BSP32_IVT1_VAL_MASK)
/*! @} */

/*! @name IVT2 - CoolFlux BSP32 IVT register 2 content */
/*! @{ */

#define BSP32_IVT2_VAL_MASK                      (0xFFFFFFU)
#define BSP32_IVT2_VAL_SHIFT                     (0U)
/*! val - CoolFlux BSP32 IVT register 2 content */
#define BSP32_IVT2_VAL(x)                        (((uint32_t)(((uint32_t)(x)) << BSP32_IVT2_VAL_SHIFT)) & BSP32_IVT2_VAL_MASK)
/*! @} */

/*! @name IVT3 - CoolFlux BSP32 IVT register 3 content */
/*! @{ */

#define BSP32_IVT3_VAL_MASK                      (0xFFFFFFU)
#define BSP32_IVT3_VAL_SHIFT                     (0U)
/*! val - CoolFlux BSP32 IVT register 3 content */
#define BSP32_IVT3_VAL(x)                        (((uint32_t)(((uint32_t)(x)) << BSP32_IVT3_VAL_SHIFT)) & BSP32_IVT3_VAL_MASK)
/*! @} */

/*! @name IVT_DISABLE - CoolFlux BSP32 IVT disable register */
/*! @{ */

#define BSP32_IVT_DISABLE_VAL_MASK               (0x1U)
#define BSP32_IVT_DISABLE_VAL_SHIFT              (0U)
/*! val - CoolFlux BSP32 IVT disable register */
#define BSP32_IVT_DISABLE_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << BSP32_IVT_DISABLE_VAL_SHIFT)) & BSP32_IVT_DISABLE_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BSP32_Register_Masks */


/*!
 * @}
 */ /* end of group BSP32_Peripheral_Access_Layer */


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


#endif  /* BSP32_H_ */

