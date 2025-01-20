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
**         CMSIS Peripheral Access Layer for VIGNETTING
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
 * @file VIGNETTING.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for VIGNETTING
 *
 * CMSIS Peripheral Access Layer for VIGNETTING
 */

#if !defined(VIGNETTING_H_)
#define VIGNETTING_H_                            /**< Symbol preventing repeated inclusion */

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
   -- VIGNETTING Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIGNETTING_Peripheral_Access_Layer VIGNETTING Peripheral Access Layer
 * @{
 */

/** VIGNETTING - Size of Registers Arrays */
#define VIGNETTING_NEO_PIPE1_VIGNETTING_CONF_COUNT 1u

/** VIGNETTING - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x2C */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 VIGNETTING Control Register, array offset: 0x0, array step: 0x2C */
    __IO uint32_t BLK_CONF_CAM;                      /**< Camera 0 Block Configuration Register, array offset: 0x4, array step: 0x2C */
    __IO uint32_t BLK_SIZE_CAM;                      /**< Camera 0 Block Size Register, array offset: 0x8, array step: 0x2C */
    __IO uint32_t BLK_STEPY_CAM;                     /**< Camera 0 Block Y Step Register, array offset: 0xC, array step: 0x2C */
    __IO uint32_t BLK_STEPX_CAM;                     /**< Camera 0 Block X Step Register, array offset: 0x10, array step: 0x2C */
         uint8_t RESERVED_0[12];
    __I  uint32_t BLK_C_LINE_CAM;                    /**< Camera 0 Current Line Inside Block Register, array offset: 0x20, array step: 0x2C */
    __I  uint32_t BLK_C_ROW_CAM;                     /**< Camera 0 Current Block Row Register, array offset: 0x24, array step: 0x2C */
    __I  uint32_t BLK_C_FRACY_CAM;                   /**< Camera 0 Current Y Step Register, array offset: 0x28, array step: 0x2C */
  } NEO_PIPE1_VIGNETTING_CONF[VIGNETTING_NEO_PIPE1_VIGNETTING_CONF_COUNT];
} VIGNETTING_Type;

/* ----------------------------------------------------------------------------
   -- VIGNETTING Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIGNETTING_Register_Masks VIGNETTING Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 VIGNETTING Control Register */
/*! @{ */

#define VIGNETTING_CTRL_CAM_ENABLE_MASK          (0x80000000U)
#define VIGNETTING_CTRL_CAM_ENABLE_SHIFT         (31U)
/*! ENABLE
 *  0b0..Disabled; the input pixels are passed unchanged to the output.
 *  0b1..Enabled
 */
#define VIGNETTING_CTRL_CAM_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << VIGNETTING_CTRL_CAM_ENABLE_SHIFT)) & VIGNETTING_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of VIGNETTING_CTRL_CAM */
#define VIGNETTING_CTRL_CAM_COUNT                (1U)

/*! @name BLK_CONF_CAM - Camera 0 Block Configuration Register */
/*! @{ */

#define VIGNETTING_BLK_CONF_CAM_COLS_MASK        (0xFFU)
#define VIGNETTING_BLK_CONF_CAM_COLS_SHIFT       (0U)
#define VIGNETTING_BLK_CONF_CAM_COLS(x)          (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_CONF_CAM_COLS_SHIFT)) & VIGNETTING_BLK_CONF_CAM_COLS_MASK)

#define VIGNETTING_BLK_CONF_CAM_ROWS_MASK        (0xFF0000U)
#define VIGNETTING_BLK_CONF_CAM_ROWS_SHIFT       (16U)
#define VIGNETTING_BLK_CONF_CAM_ROWS(x)          (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_CONF_CAM_ROWS_SHIFT)) & VIGNETTING_BLK_CONF_CAM_ROWS_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_CONF_CAM */
#define VIGNETTING_BLK_CONF_CAM_COUNT            (1U)

/*! @name BLK_SIZE_CAM - Camera 0 Block Size Register */
/*! @{ */

#define VIGNETTING_BLK_SIZE_CAM_XSIZE_MASK       (0xFFFFU)
#define VIGNETTING_BLK_SIZE_CAM_XSIZE_SHIFT      (0U)
#define VIGNETTING_BLK_SIZE_CAM_XSIZE(x)         (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_SIZE_CAM_XSIZE_SHIFT)) & VIGNETTING_BLK_SIZE_CAM_XSIZE_MASK)

#define VIGNETTING_BLK_SIZE_CAM_YSIZE_MASK       (0xFFFF0000U)
#define VIGNETTING_BLK_SIZE_CAM_YSIZE_SHIFT      (16U)
#define VIGNETTING_BLK_SIZE_CAM_YSIZE(x)         (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_SIZE_CAM_YSIZE_SHIFT)) & VIGNETTING_BLK_SIZE_CAM_YSIZE_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_SIZE_CAM */
#define VIGNETTING_BLK_SIZE_CAM_COUNT            (1U)

/*! @name BLK_STEPY_CAM - Camera 0 Block Y Step Register */
/*! @{ */

#define VIGNETTING_BLK_STEPY_CAM_STEP_MASK       (0xFFFFU)
#define VIGNETTING_BLK_STEPY_CAM_STEP_SHIFT      (0U)
#define VIGNETTING_BLK_STEPY_CAM_STEP(x)         (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_STEPY_CAM_STEP_SHIFT)) & VIGNETTING_BLK_STEPY_CAM_STEP_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_STEPY_CAM */
#define VIGNETTING_BLK_STEPY_CAM_COUNT           (1U)

/*! @name BLK_STEPX_CAM - Camera 0 Block X Step Register */
/*! @{ */

#define VIGNETTING_BLK_STEPX_CAM_STEP_MASK       (0xFFFFU)
#define VIGNETTING_BLK_STEPX_CAM_STEP_SHIFT      (0U)
#define VIGNETTING_BLK_STEPX_CAM_STEP(x)         (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_STEPX_CAM_STEP_SHIFT)) & VIGNETTING_BLK_STEPX_CAM_STEP_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_STEPX_CAM */
#define VIGNETTING_BLK_STEPX_CAM_COUNT           (1U)

/*! @name BLK_C_LINE_CAM - Camera 0 Current Line Inside Block Register */
/*! @{ */

#define VIGNETTING_BLK_C_LINE_CAM_LINE_MASK      (0xFFFFU)
#define VIGNETTING_BLK_C_LINE_CAM_LINE_SHIFT     (0U)
#define VIGNETTING_BLK_C_LINE_CAM_LINE(x)        (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_C_LINE_CAM_LINE_SHIFT)) & VIGNETTING_BLK_C_LINE_CAM_LINE_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_C_LINE_CAM */
#define VIGNETTING_BLK_C_LINE_CAM_COUNT          (1U)

/*! @name BLK_C_ROW_CAM - Camera 0 Current Block Row Register */
/*! @{ */

#define VIGNETTING_BLK_C_ROW_CAM_BLKROW_MASK     (0xFFU)
#define VIGNETTING_BLK_C_ROW_CAM_BLKROW_SHIFT    (0U)
#define VIGNETTING_BLK_C_ROW_CAM_BLKROW(x)       (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_C_ROW_CAM_BLKROW_SHIFT)) & VIGNETTING_BLK_C_ROW_CAM_BLKROW_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_C_ROW_CAM */
#define VIGNETTING_BLK_C_ROW_CAM_COUNT           (1U)

/*! @name BLK_C_FRACY_CAM - Camera 0 Current Y Step Register */
/*! @{ */

#define VIGNETTING_BLK_C_FRACY_CAM_FRAC_MASK     (0xFFFFFFFFU)
#define VIGNETTING_BLK_C_FRACY_CAM_FRAC_SHIFT    (0U)
#define VIGNETTING_BLK_C_FRACY_CAM_FRAC(x)       (((uint32_t)(((uint32_t)(x)) << VIGNETTING_BLK_C_FRACY_CAM_FRAC_SHIFT)) & VIGNETTING_BLK_C_FRACY_CAM_FRAC_MASK)
/*! @} */

/* The count of VIGNETTING_BLK_C_FRACY_CAM */
#define VIGNETTING_BLK_C_FRACY_CAM_COUNT         (1U)


/*!
 * @}
 */ /* end of group VIGNETTING_Register_Masks */


/*!
 * @}
 */ /* end of group VIGNETTING_Peripheral_Access_Layer */


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


#endif  /* VIGNETTING_H_ */

