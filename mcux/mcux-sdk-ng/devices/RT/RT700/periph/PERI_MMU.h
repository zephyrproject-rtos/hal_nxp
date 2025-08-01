/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MMU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MMU
 *
 * CMSIS Peripheral Access Layer for MMU
 */

#if !defined(PERI_MMU_H_)
#define PERI_MMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- MMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMU_Peripheral_Access_Layer MMU Peripheral Access Layer
 * @{
 */

/** MMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< MMU Control, offset: 0x0 */
  __IO uint32_t STS;                               /**< MMU Status, offset: 0x4 */
  __IO uint32_t INTEN;                             /**< Interrupt Enable, offset: 0x8 */
  __IO uint32_t ADDR_RANGE;                        /**< Address Range, offset: 0xC */
  __I  uint32_t FAIL_INFO;                         /**< Fail Information, offset: 0x10 */
  __I  uint32_t FAIL_ADDR;                         /**< Fail Address, offset: 0x14 */
  __IO uint32_t LUT_WDATA;                         /**< LUT Write Data, offset: 0x18 */
  __I  uint32_t LUT_RDATA;                         /**< LUT Read Data, offset: 0x1C */
  __IO uint32_t WRITE_PTR;                         /**< Write Pointer, offset: 0x20 */
  __IO uint32_t READ_PTR;                          /**< Read Pointer, offset: 0x24 */
  __IO uint32_t READ_VFY;                          /**< Read Verify, offset: 0x28 */
} MMU_Type;

/* ----------------------------------------------------------------------------
   -- MMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMU_Register_Masks MMU Register Masks
 * @{
 */

/*! @name CTRL - MMU Control */
/*! @{ */

#define MMU_CTRL_SWRST_MASK                      (0x1U)
#define MMU_CTRL_SWRST_SHIFT                     (0U)
/*! SWRST - Software Reset
 *  0b0..No reset
 *  0b1..Reset MMU logic
 */
#define MMU_CTRL_SWRST(x)                        (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_SWRST_SHIFT)) & MMU_CTRL_SWRST_MASK)

#define MMU_CTRL_MMU_EN_MASK                     (0x2U)
#define MMU_CTRL_MMU_EN_SHIFT                    (1U)
/*! MMU_EN - MMU Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MMU_CTRL_MMU_EN(x)                       (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_MMU_EN_SHIFT)) & MMU_CTRL_MMU_EN_MASK)

#define MMU_CTRL_CLK_DIS_MASK                    (0x4U)
#define MMU_CTRL_CLK_DIS_SHIFT                   (2U)
/*! CLK_DIS - Clock Gate
 *  0b0..Enable
 *  0b1..Disable
 */
#define MMU_CTRL_CLK_DIS(x)                      (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_CLK_DIS_SHIFT)) & MMU_CTRL_CLK_DIS_MASK)

#define MMU_CTRL_LOCK_LUT_MASK                   (0x8U)
#define MMU_CTRL_LOCK_LUT_SHIFT                  (3U)
/*! LOCK_LUT - Lock LUT
 *  0b0..Unlock
 *  0b1..Lock
 */
#define MMU_CTRL_LOCK_LUT(x)                     (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_LOCK_LUT_SHIFT)) & MMU_CTRL_LOCK_LUT_MASK)

#define MMU_CTRL_INV_ADDR_MODE_MASK              (0x10U)
#define MMU_CTRL_INV_ADDR_MODE_SHIFT             (4U)
/*! INV_ADDR_MODE - Invalid Address Mode
 *  0b0..Respond with a transfer error
 *  0b1..Allow transfer
 */
#define MMU_CTRL_INV_ADDR_MODE(x)                (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_INV_ADDR_MODE_SHIFT)) & MMU_CTRL_INV_ADDR_MODE_MASK)

#define MMU_CTRL_PAGE_MODE_MASK                  (0x20U)
#define MMU_CTRL_PAGE_MODE_SHIFT                 (5U)
/*! PAGE_MODE - Page Mode
 *  0b0..MMU takes LUT SRAM as 1 page for address remapping
 *  0b1..MMU takes LUT SRAM as 4 pages for address remapping
 */
#define MMU_CTRL_PAGE_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_PAGE_MODE_SHIFT)) & MMU_CTRL_PAGE_MODE_MASK)

#define MMU_CTRL_PAGE_SEL_MASK                   (0xC0U)
#define MMU_CTRL_PAGE_SEL_SHIFT                  (6U)
/*! PAGE_SEL - Page Select
 *  0b00..Uses LUT SRAM low 2 KB words for address remapping
 *  0b01..Uses LUT SRAM mid-low 2 KB words for address remapping
 *  0b10..Uses LUT SRAM mid-high 2 KB words for address remapping
 *  0b11..Uses LUT SRAM high 2 KB words for address remapping
 */
#define MMU_CTRL_PAGE_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_PAGE_SEL_SHIFT)) & MMU_CTRL_PAGE_SEL_MASK)

#define MMU_CTRL_UNIT_SIZE_MASK                  (0x700U)
#define MMU_CTRL_UNIT_SIZE_SHIFT                 (8U)
/*! UNIT_SIZE - Unit Size
 *  0b000..Not supported, must configure to other value
 *  0b001..8 KB
 *  0b010..16 KB
 *  0b011..32 KB
 *  0b100-0b111..64 KB
 */
#define MMU_CTRL_UNIT_SIZE(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_CTRL_UNIT_SIZE_SHIFT)) & MMU_CTRL_UNIT_SIZE_MASK)
/*! @} */

/*! @name STS - MMU Status */
/*! @{ */

#define MMU_STS_BUSY_MASK                        (0x1U)
#define MMU_STS_BUSY_SHIFT                       (0U)
/*! BUSY - Busy
 *  0b0..Not busy
 *  0b1..In initialization sequence, burst-write operation, or read-verify operation
 */
#define MMU_STS_BUSY(x)                          (((uint32_t)(((uint32_t)(x)) << MMU_STS_BUSY_SHIFT)) & MMU_STS_BUSY_MASK)

#define MMU_STS_LUT_INVALID_MASK                 (0x2U)
#define MMU_STS_LUT_INVALID_SHIFT                (1U)
/*! LUT_INVALID - LUT Invalid
 *  0b0..No effect
 *  0b0..Valid
 *  0b1..Clear the flag
 *  0b1..Invalid
 */
#define MMU_STS_LUT_INVALID(x)                   (((uint32_t)(((uint32_t)(x)) << MMU_STS_LUT_INVALID_SHIFT)) & MMU_STS_LUT_INVALID_MASK)

#define MMU_STS_INVALID_ADDR_MASK                (0x4U)
#define MMU_STS_INVALID_ADDR_SHIFT               (2U)
/*! INVALID_ADDR - Invalid Address
 *  0b0..No effect
 *  0b0..Within range
 *  0b1..Clear the flag
 *  0b1..Out of range
 */
#define MMU_STS_INVALID_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << MMU_STS_INVALID_ADDR_SHIFT)) & MMU_STS_INVALID_ADDR_MASK)

#define MMU_STS_PARITY_ERROR_MASK                (0x8U)
#define MMU_STS_PARITY_ERROR_SHIFT               (3U)
/*! PARITY_ERROR - Parity Error
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define MMU_STS_PARITY_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << MMU_STS_PARITY_ERROR_SHIFT)) & MMU_STS_PARITY_ERROR_MASK)

#define MMU_STS_LOCK_ERROR_MASK                  (0x10U)
#define MMU_STS_LOCK_ERROR_SHIFT                 (4U)
/*! LOCK_ERROR - Lock Error
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define MMU_STS_LOCK_ERROR(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_STS_LOCK_ERROR_SHIFT)) & MMU_STS_LOCK_ERROR_MASK)

#define MMU_STS_IPS_READ_ERROR_MASK              (0x20U)
#define MMU_STS_IPS_READ_ERROR_SHIFT             (5U)
/*! IPS_READ_ERROR - IPS Read Error
 *  0b0..No effect
 *  0b0..Not detected
 *  0b1..Clear the flag
 *  0b1..Detected
 */
#define MMU_STS_IPS_READ_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << MMU_STS_IPS_READ_ERROR_SHIFT)) & MMU_STS_IPS_READ_ERROR_MASK)

#define MMU_STS_IPS_ERR_ADDR_MASK                (0x1FFF0000U)
#define MMU_STS_IPS_ERR_ADDR_SHIFT               (16U)
/*! IPS_ERR_ADDR - IPS Error Address */
#define MMU_STS_IPS_ERR_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << MMU_STS_IPS_ERR_ADDR_SHIFT)) & MMU_STS_IPS_ERR_ADDR_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable */
/*! @{ */

#define MMU_INTEN_LUT_INVALID_EN_MASK            (0x2U)
#define MMU_INTEN_LUT_INVALID_EN_SHIFT           (1U)
/*! LUT_INVALID_EN - LUT Invalid Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MMU_INTEN_LUT_INVALID_EN(x)              (((uint32_t)(((uint32_t)(x)) << MMU_INTEN_LUT_INVALID_EN_SHIFT)) & MMU_INTEN_LUT_INVALID_EN_MASK)

#define MMU_INTEN_INVALID_ADDR_EN_MASK           (0x4U)
#define MMU_INTEN_INVALID_ADDR_EN_SHIFT          (2U)
/*! INVALID_ADDR_EN - Invalid Address Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MMU_INTEN_INVALID_ADDR_EN(x)             (((uint32_t)(((uint32_t)(x)) << MMU_INTEN_INVALID_ADDR_EN_SHIFT)) & MMU_INTEN_INVALID_ADDR_EN_MASK)

#define MMU_INTEN_PARITY_ERROR_EN_MASK           (0x8U)
#define MMU_INTEN_PARITY_ERROR_EN_SHIFT          (3U)
/*! PARITY_ERROR_EN - Parity Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MMU_INTEN_PARITY_ERROR_EN(x)             (((uint32_t)(((uint32_t)(x)) << MMU_INTEN_PARITY_ERROR_EN_SHIFT)) & MMU_INTEN_PARITY_ERROR_EN_MASK)

#define MMU_INTEN_LOCK_ERROR_EN_MASK             (0x10U)
#define MMU_INTEN_LOCK_ERROR_EN_SHIFT            (4U)
/*! LOCK_ERROR_EN - Lock Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MMU_INTEN_LOCK_ERROR_EN(x)               (((uint32_t)(((uint32_t)(x)) << MMU_INTEN_LOCK_ERROR_EN_SHIFT)) & MMU_INTEN_LOCK_ERROR_EN_MASK)

#define MMU_INTEN_IPS_READ_ERROR_EN_MASK         (0x20U)
#define MMU_INTEN_IPS_READ_ERROR_EN_SHIFT        (5U)
/*! IPS_READ_ERROR_EN - IPS Read Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MMU_INTEN_IPS_READ_ERROR_EN(x)           (((uint32_t)(((uint32_t)(x)) << MMU_INTEN_IPS_READ_ERROR_EN_SHIFT)) & MMU_INTEN_IPS_READ_ERROR_EN_MASK)
/*! @} */

/*! @name ADDR_RANGE - Address Range */
/*! @{ */

#define MMU_ADDR_RANGE_BASE_ADDR_MASK            (0xFFFFU)
#define MMU_ADDR_RANGE_BASE_ADDR_SHIFT           (0U)
/*! BASE_ADDR - Base Address */
#define MMU_ADDR_RANGE_BASE_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << MMU_ADDR_RANGE_BASE_ADDR_SHIFT)) & MMU_ADDR_RANGE_BASE_ADDR_MASK)

#define MMU_ADDR_RANGE_MAX_ADDR_MASK             (0xFFFF0000U)
#define MMU_ADDR_RANGE_MAX_ADDR_SHIFT            (16U)
/*! MAX_ADDR - Maximum Address */
#define MMU_ADDR_RANGE_MAX_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << MMU_ADDR_RANGE_MAX_ADDR_SHIFT)) & MMU_ADDR_RANGE_MAX_ADDR_MASK)
/*! @} */

/*! @name FAIL_INFO - Fail Information */
/*! @{ */

#define MMU_FAIL_INFO_MASTER_ID_MASK             (0xFFU)
#define MMU_FAIL_INFO_MASTER_ID_SHIFT            (0U)
/*! MASTER_ID - Initiator ID */
#define MMU_FAIL_INFO_MASTER_ID(x)               (((uint32_t)(((uint32_t)(x)) << MMU_FAIL_INFO_MASTER_ID_SHIFT)) & MMU_FAIL_INFO_MASTER_ID_MASK)

#define MMU_FAIL_INFO_PROT_MASK                  (0x7F00U)
#define MMU_FAIL_INFO_PROT_SHIFT                 (8U)
/*! PROT - Protection */
#define MMU_FAIL_INFO_PROT(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_FAIL_INFO_PROT_SHIFT)) & MMU_FAIL_INFO_PROT_MASK)

#define MMU_FAIL_INFO_ACC_TYPE_MASK              (0x8000U)
#define MMU_FAIL_INFO_ACC_TYPE_SHIFT             (15U)
/*! ACC_TYPE - Access Type
 *  0b0..Read
 *  0b1..Write
 */
#define MMU_FAIL_INFO_ACC_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << MMU_FAIL_INFO_ACC_TYPE_SHIFT)) & MMU_FAIL_INFO_ACC_TYPE_MASK)

#define MMU_FAIL_INFO_ERR_TYPE_MASK              (0x70000U)
#define MMU_FAIL_INFO_ERR_TYPE_SHIFT             (16U)
/*! ERR_TYPE - Error Type
 *  0b1xx..Parity error
 *  0bx1x..Invalid address error
 *  0bxx1..LUT invalid error
 */
#define MMU_FAIL_INFO_ERR_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << MMU_FAIL_INFO_ERR_TYPE_SHIFT)) & MMU_FAIL_INFO_ERR_TYPE_MASK)
/*! @} */

/*! @name FAIL_ADDR - Fail Address */
/*! @{ */

#define MMU_FAIL_ADDR_ADDR_MASK                  (0xFFFFFFFFU)
#define MMU_FAIL_ADDR_ADDR_SHIFT                 (0U)
/*! ADDR - Address */
#define MMU_FAIL_ADDR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_FAIL_ADDR_ADDR_SHIFT)) & MMU_FAIL_ADDR_ADDR_MASK)
/*! @} */

/*! @name LUT_WDATA - LUT Write Data */
/*! @{ */

#define MMU_LUT_WDATA_ADDR_MASK                  (0x7FFFU)
#define MMU_LUT_WDATA_ADDR_SHIFT                 (0U)
/*! ADDR - LUT Address Map Bits */
#define MMU_LUT_WDATA_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_LUT_WDATA_ADDR_SHIFT)) & MMU_LUT_WDATA_ADDR_MASK)

#define MMU_LUT_WDATA_VALID_MASK                 (0x8000U)
#define MMU_LUT_WDATA_VALID_SHIFT                (15U)
/*! VALID - LUT Address Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define MMU_LUT_WDATA_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << MMU_LUT_WDATA_VALID_SHIFT)) & MMU_LUT_WDATA_VALID_MASK)

#define MMU_LUT_WDATA_COUNT_MASK                 (0x1FFF0000U)
#define MMU_LUT_WDATA_COUNT_SHIFT                (16U)
/*! COUNT - Write Count */
#define MMU_LUT_WDATA_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << MMU_LUT_WDATA_COUNT_SHIFT)) & MMU_LUT_WDATA_COUNT_MASK)
/*! @} */

/*! @name LUT_RDATA - LUT Read Data */
/*! @{ */

#define MMU_LUT_RDATA_DATA_MASK                  (0xFFFFU)
#define MMU_LUT_RDATA_DATA_SHIFT                 (0U)
/*! DATA - Read Data */
#define MMU_LUT_RDATA_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_LUT_RDATA_DATA_SHIFT)) & MMU_LUT_RDATA_DATA_MASK)
/*! @} */

/*! @name WRITE_PTR - Write Pointer */
/*! @{ */

#define MMU_WRITE_PTR_POINTER_MASK               (0x1FFFU)
#define MMU_WRITE_PTR_POINTER_SHIFT              (0U)
/*! POINTER - Write Pointer */
#define MMU_WRITE_PTR_POINTER(x)                 (((uint32_t)(((uint32_t)(x)) << MMU_WRITE_PTR_POINTER_SHIFT)) & MMU_WRITE_PTR_POINTER_MASK)
/*! @} */

/*! @name READ_PTR - Read Pointer */
/*! @{ */

#define MMU_READ_PTR_POINTER_MASK                (0x1FFFU)
#define MMU_READ_PTR_POINTER_SHIFT               (0U)
/*! POINTER - Read Pointer */
#define MMU_READ_PTR_POINTER(x)                  (((uint32_t)(((uint32_t)(x)) << MMU_READ_PTR_POINTER_SHIFT)) & MMU_READ_PTR_POINTER_MASK)
/*! @} */

/*! @name READ_VFY - Read Verify */
/*! @{ */

#define MMU_READ_VFY_DATA_MASK                   (0xFFFFU)
#define MMU_READ_VFY_DATA_SHIFT                  (0U)
/*! DATA - Read Data */
#define MMU_READ_VFY_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << MMU_READ_VFY_DATA_SHIFT)) & MMU_READ_VFY_DATA_MASK)

#define MMU_READ_VFY_COUNT_MASK                  (0x1FFF0000U)
#define MMU_READ_VFY_COUNT_SHIFT                 (16U)
/*! COUNT - Read Count */
#define MMU_READ_VFY_COUNT(x)                    (((uint32_t)(((uint32_t)(x)) << MMU_READ_VFY_COUNT_SHIFT)) & MMU_READ_VFY_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MMU_Register_Masks */


/*!
 * @}
 */ /* end of group MMU_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_MMU_H_ */

