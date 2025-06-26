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
**         CMSIS Peripheral Access Layer for PACKETIZER
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
 * @file PACKETIZER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for PACKETIZER
 *
 * CMSIS Peripheral Access Layer for PACKETIZER
 */

#if !defined(PACKETIZER_H_)
#define PACKETIZER_H_                            /**< Symbol preventing repeated inclusion */

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
   -- PACKETIZER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PACKETIZER_Peripheral_Access_Layer PACKETIZER Peripheral Access Layer
 * @{
 */

/** PACKETIZER - Size of Registers Arrays */
#define PACKETIZER_NEO_PIPE2_PACK_CONF_COUNT      1u

/** PACKETIZER - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0xC */
    __IO uint32_t CH0_CTRL_CAM;                      /**< Camera 0 Channel 0 Control Register, array offset: 0x0, array step: 0xC */
    __IO uint32_t CH12_CTRL_CAM;                     /**< Camera 0 Channel 1,2 Control Register, array offset: 0x4, array step: 0xC */
    __IO uint32_t PACK_CTRL_CAM;                     /**< Camera 0 Pack Control Register, array offset: 0x8, array step: 0xC */
  } NEO_PIPE2_PACK_CONF[PACKETIZER_NEO_PIPE2_PACK_CONF_COUNT];
} PACKETIZER_Type;

/* ----------------------------------------------------------------------------
   -- PACKETIZER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PACKETIZER_Register_Masks PACKETIZER Register Masks
 * @{
 */

/*! @name CH0_CTRL_CAM - Camera 0 Channel 0 Control Register */
/*! @{ */

#define PACKETIZER_CH0_CTRL_CAM_OBPP_MASK        (0xFU)
#define PACKETIZER_CH0_CTRL_CAM_OBPP_SHIFT       (0U)
/*! OBPP
 *  0b0000..12bpp
 *  0b0010..16bpp
 *  0b0100..10bpp
 *  0b0110..8bpp
 */
#define PACKETIZER_CH0_CTRL_CAM_OBPP(x)          (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH0_CTRL_CAM_OBPP_SHIFT)) & PACKETIZER_CH0_CTRL_CAM_OBPP_MASK)

#define PACKETIZER_CH0_CTRL_CAM_RSA_MASK         (0x700U)
#define PACKETIZER_CH0_CTRL_CAM_RSA_SHIFT        (8U)
#define PACKETIZER_CH0_CTRL_CAM_RSA(x)           (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH0_CTRL_CAM_RSA_SHIFT)) & PACKETIZER_CH0_CTRL_CAM_RSA_MASK)

#define PACKETIZER_CH0_CTRL_CAM_LSA_MASK         (0x7000U)
#define PACKETIZER_CH0_CTRL_CAM_LSA_SHIFT        (12U)
#define PACKETIZER_CH0_CTRL_CAM_LSA(x)           (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH0_CTRL_CAM_LSA_SHIFT)) & PACKETIZER_CH0_CTRL_CAM_LSA_MASK)
/*! @} */

/* The count of PACKETIZER_CH0_CTRL_CAM */
#define PACKETIZER_CH0_CTRL_CAM_COUNT            (1U)

/*! @name CH12_CTRL_CAM - Camera 0 Channel 1,2 Control Register */
/*! @{ */

#define PACKETIZER_CH12_CTRL_CAM_OBPP_MASK       (0xFU)
#define PACKETIZER_CH12_CTRL_CAM_OBPP_SHIFT      (0U)
/*! OBPP
 *  0b0000..12bpp
 *  0b0010..16bpp - Should be set only for YUV Semiplanar storage type
 *  0b0100..10bpp
 *  0b0110..8bpp
 */
#define PACKETIZER_CH12_CTRL_CAM_OBPP(x)         (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH12_CTRL_CAM_OBPP_SHIFT)) & PACKETIZER_CH12_CTRL_CAM_OBPP_MASK)

#define PACKETIZER_CH12_CTRL_CAM_RSA_MASK        (0x700U)
#define PACKETIZER_CH12_CTRL_CAM_RSA_SHIFT       (8U)
#define PACKETIZER_CH12_CTRL_CAM_RSA(x)          (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH12_CTRL_CAM_RSA_SHIFT)) & PACKETIZER_CH12_CTRL_CAM_RSA_MASK)

#define PACKETIZER_CH12_CTRL_CAM_LSA_MASK        (0x7000U)
#define PACKETIZER_CH12_CTRL_CAM_LSA_SHIFT       (12U)
#define PACKETIZER_CH12_CTRL_CAM_LSA(x)          (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH12_CTRL_CAM_LSA_SHIFT)) & PACKETIZER_CH12_CTRL_CAM_LSA_MASK)

#define PACKETIZER_CH12_CTRL_CAM_SUBSAMPLE_MASK  (0x30000U)
#define PACKETIZER_CH12_CTRL_CAM_SUBSAMPLE_SHIFT (16U)
/*! SUBSAMPLE
 *  0b00..No subsample. For YUV444 storage.
 *  0b01..Horizontal subsampling. For YUV422 storage.
 *  0b10..Horizontal & vertical subsampling. For YUV420 storage.
 */
#define PACKETIZER_CH12_CTRL_CAM_SUBSAMPLE(x)    (((uint32_t)(((uint32_t)(x)) << PACKETIZER_CH12_CTRL_CAM_SUBSAMPLE_SHIFT)) & PACKETIZER_CH12_CTRL_CAM_SUBSAMPLE_MASK)
/*! @} */

/* The count of PACKETIZER_CH12_CTRL_CAM */
#define PACKETIZER_CH12_CTRL_CAM_COUNT           (1U)

/*! @name PACK_CTRL_CAM - Camera 0 Pack Control Register */
/*! @{ */

#define PACKETIZER_PACK_CTRL_CAM_TYPE_MASK       (0x1U)
#define PACKETIZER_PACK_CTRL_CAM_TYPE_SHIFT      (0U)
/*! TYPE
 *  0b0..Semi-planar: Y as a separate plane, in memory location pointed by Y base address
 *  0b1..Interleaved: Y in same plane as UV, in memory location pointed by UV base address
 */
#define PACKETIZER_PACK_CTRL_CAM_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << PACKETIZER_PACK_CTRL_CAM_TYPE_SHIFT)) & PACKETIZER_PACK_CTRL_CAM_TYPE_MASK)

#define PACKETIZER_PACK_CTRL_CAM_ORDER0_MASK     (0x300U)
#define PACKETIZER_PACK_CTRL_CAM_ORDER0_SHIFT    (8U)
#define PACKETIZER_PACK_CTRL_CAM_ORDER0(x)       (((uint32_t)(((uint32_t)(x)) << PACKETIZER_PACK_CTRL_CAM_ORDER0_SHIFT)) & PACKETIZER_PACK_CTRL_CAM_ORDER0_MASK)

#define PACKETIZER_PACK_CTRL_CAM_ORDER1_MASK     (0xC00U)
#define PACKETIZER_PACK_CTRL_CAM_ORDER1_SHIFT    (10U)
#define PACKETIZER_PACK_CTRL_CAM_ORDER1(x)       (((uint32_t)(((uint32_t)(x)) << PACKETIZER_PACK_CTRL_CAM_ORDER1_SHIFT)) & PACKETIZER_PACK_CTRL_CAM_ORDER1_MASK)

#define PACKETIZER_PACK_CTRL_CAM_ORDER2_MASK     (0x3000U)
#define PACKETIZER_PACK_CTRL_CAM_ORDER2_SHIFT    (12U)
#define PACKETIZER_PACK_CTRL_CAM_ORDER2(x)       (((uint32_t)(((uint32_t)(x)) << PACKETIZER_PACK_CTRL_CAM_ORDER2_SHIFT)) & PACKETIZER_PACK_CTRL_CAM_ORDER2_MASK)

#define PACKETIZER_PACK_CTRL_CAM_A0S_MASK        (0xF0000U)
#define PACKETIZER_PACK_CTRL_CAM_A0S_SHIFT       (16U)
#define PACKETIZER_PACK_CTRL_CAM_A0S(x)          (((uint32_t)(((uint32_t)(x)) << PACKETIZER_PACK_CTRL_CAM_A0S_SHIFT)) & PACKETIZER_PACK_CTRL_CAM_A0S_MASK)
/*! @} */

/* The count of PACKETIZER_PACK_CTRL_CAM */
#define PACKETIZER_PACK_CTRL_CAM_COUNT           (1U)


/*!
 * @}
 */ /* end of group PACKETIZER_Register_Masks */


/*!
 * @}
 */ /* end of group PACKETIZER_Peripheral_Access_Layer */


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


#endif  /* PACKETIZER_H_ */

