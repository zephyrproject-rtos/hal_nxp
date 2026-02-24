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
**         CMSIS Peripheral Access Layer for sig3
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
 * @file PERI_sig3.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for sig3
 *
 * CMSIS Peripheral Access Layer for sig3
 */

#if !defined(PERI_SIG3_H_)
#define PERI_SIG3_H_                             /**< Symbol preventing repeated inclusion */

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
   -- sig3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup sig3_Peripheral_Access_Layer sig3 Peripheral Access Layer
 * @{
 */

/** sig3 - Register Layout Typedef */
typedef struct {
  __I  uint32_t CRCRW0;                            /**< CRC_R_Window0, offset: 0x0 */
  __I  uint32_t CRCGW0;                            /**< CRC_G_Window0, offset: 0x4 */
  __I  uint32_t CRCBW0;                            /**< CRC_B_Window0, offset: 0x8 */
  __I  uint32_t CRCRW1;                            /**< CRC_R_Window1, offset: 0xC */
  __I  uint32_t CRCGW1;                            /**< CRC_G_Window1, offset: 0x10 */
  __I  uint32_t CRCBW1;                            /**< CRC_B_Window1, offset: 0x14 */
  __I  uint32_t CRCRW2;                            /**< CRC_R_Window2, offset: 0x18 */
  __I  uint32_t CRCGW2;                            /**< CRC_G_Window2, offset: 0x1C */
  __I  uint32_t CRCBW2;                            /**< CRC_B_Window2, offset: 0x20 */
  __I  uint32_t CRCRW3;                            /**< CRC_R_Window3, offset: 0x24 */
  __I  uint32_t CRCGW3;                            /**< CRC_G_Window3, offset: 0x28 */
  __I  uint32_t CRCBW3;                            /**< CRC_B_Window3, offset: 0x2C */
  __I  uint32_t CRCRW4;                            /**< CRC_R_Window4, offset: 0x30 */
  __I  uint32_t CRCGW4;                            /**< CRC_G_Window4, offset: 0x34 */
  __I  uint32_t CRCBW4;                            /**< CRC_B_Window4, offset: 0x38 */
  __I  uint32_t CRCRW5;                            /**< CRC_R_Window5, offset: 0x3C */
  __I  uint32_t CRCGW5;                            /**< CRC_G_Window5, offset: 0x40 */
  __I  uint32_t CRCBW5;                            /**< CRC_B_Window5, offset: 0x44 */
  __I  uint32_t CRCRW6;                            /**< CRC_R_Window6, offset: 0x48 */
  __I  uint32_t CRCGW6;                            /**< CRC_G_Window6, offset: 0x4C */
  __I  uint32_t CRCBW6;                            /**< CRC_B_Window6, offset: 0x50 */
  __I  uint32_t CRCRW7;                            /**< CRC_R_Window7, offset: 0x54 */
  __I  uint32_t CRCGW7;                            /**< CRC_G_Window7, offset: 0x58 */
  __I  uint32_t CRCBW7;                            /**< CRC_B_Window7, offset: 0x5C */
  __I  uint32_t STATUC0;                           /**< Status_Cluster0, offset: 0x60 */
  __I  uint32_t COUNTC0;                           /**< Counter_Cluster0, offset: 0x64 */
  __I  uint32_t VEC0CL0;                           /**< Vector0_Cluster0, offset: 0x68 */
  __I  uint32_t VEC1CL0;                           /**< Vector1_Cluster0, offset: 0x6C */
  __I  uint32_t VEC2CL0;                           /**< Vector2_Cluster0, offset: 0x70 */
  __I  uint32_t VEC3CL0;                           /**< Vector3_Cluster0, offset: 0x74 */
  __I  uint32_t STATUC1;                           /**< Status_Cluster1, offset: 0x78 */
  __I  uint32_t COUNTC1;                           /**< Counter_Cluster1, offset: 0x7C */
  __I  uint32_t VEC0CL1;                           /**< Vector0_Cluster1, offset: 0x80 */
  __I  uint32_t VEC1CL1;                           /**< Vector1_Cluster1, offset: 0x84 */
  __I  uint32_t VEC2CL1;                           /**< Vector2_Cluster1, offset: 0x88 */
  __I  uint32_t VEC3CL1;                           /**< Vector3_Cluster1, offset: 0x8C */
  __I  uint32_t STATUC2;                           /**< Status_Cluster2, offset: 0x90 */
  __I  uint32_t COUNTC2;                           /**< Counter_Cluster2, offset: 0x94 */
  __I  uint32_t VEC0CL2;                           /**< Vector0_Cluster2, offset: 0x98 */
  __I  uint32_t VEC1CL2;                           /**< Vector1_Cluster2, offset: 0x9C */
  __I  uint32_t VEC2CL2;                           /**< Vector2_Cluster2, offset: 0xA0 */
  __I  uint32_t VEC3CL2;                           /**< Vector3_Cluster2, offset: 0xA4 */
  __I  uint32_t STATUC3;                           /**< Status_Cluster3, offset: 0xA8 */
  __I  uint32_t COUNTC3;                           /**< Counter_Cluster3, offset: 0xAC */
  __I  uint32_t VEC0CL3;                           /**< Vector0_Cluster3, offset: 0xB0 */
  __I  uint32_t VEC1CL3;                           /**< Vector1_Cluster3, offset: 0xB4 */
  __I  uint32_t VEC2CL3;                           /**< Vector2_Cluster3, offset: 0xB8 */
  __I  uint32_t VEC3CL3;                           /**< Vector3_Cluster3, offset: 0xBC */
  __I  uint32_t PIXCS0W0;                          /**< PixCnt_Stats0_Win0, offset: 0xC0 */
  __I  uint32_t PIMAS0W0;                          /**< PixMax_Stats0_Win0, offset: 0xC4 */
  __I  uint32_t PIMIS0W0;                          /**< PixMin_Stats0_Win0, offset: 0xC8 */
  __I  uint32_t RESUS0W0;                          /**< RedSum_Stats0_Win0, offset: 0xCC */
  __I  uint32_t GRESS0W0;                          /**< GreenSum_Stats0_Win0, offset: 0xD0 */
  __I  uint32_t BLSUS0W0;                          /**< BlueSum_Stats0_Win0, offset: 0xD4 */
  __I  uint32_t LUSUS0W0;                          /**< LumSum_Stats0_Win0, offset: 0xD8 */
  __I  uint32_t PIXCS1W0;                          /**< PixCnt_Stats1_Win0, offset: 0xDC */
  __I  uint32_t PIMAS1W0;                          /**< PixMax_Stats1_Win0, offset: 0xE0 */
  __I  uint32_t PIMIS1W0;                          /**< PixMin_Stats1_Win0, offset: 0xE4 */
  __I  uint32_t RESUS1W0;                          /**< RedSum_Stats1_Win0, offset: 0xE8 */
  __I  uint32_t GRESS1W0;                          /**< GreenSum_Stats1_Win0, offset: 0xEC */
  __I  uint32_t BLSUS1W0;                          /**< BlueSum_Stats1_Win0, offset: 0xF0 */
  __I  uint32_t PIXCS0W1;                          /**< PixCnt_Stats0_Win1, offset: 0xF4 */
  __I  uint32_t PIMAS0W1;                          /**< PixMax_Stats0_Win1, offset: 0xF8 */
  __I  uint32_t PIMIS0W1;                          /**< PixMin_Stats0_Win1, offset: 0xFC */
  __I  uint32_t RESUS0W1;                          /**< RedSum_Stats0_Win1, offset: 0x100 */
  __I  uint32_t GRESS0W1;                          /**< GreenSum_Stats0_Win1, offset: 0x104 */
  __I  uint32_t BLSUS0W1;                          /**< BlueSum_Stats0_Win1, offset: 0x108 */
  __I  uint32_t LUSUS0W1;                          /**< LumSum_Stats0_Win1, offset: 0x10C */
  __I  uint32_t PIXCS1W1;                          /**< PixCnt_Stats1_Win1, offset: 0x110 */
  __I  uint32_t PIMAS1W1;                          /**< PixMax_Stats1_Win1, offset: 0x114 */
  __I  uint32_t PIMIS1W1;                          /**< PixMin_Stats1_Win1, offset: 0x118 */
  __I  uint32_t RESUS1W1;                          /**< RedSum_Stats1_Win1, offset: 0x11C */
  __I  uint32_t GRESS1W1;                          /**< GreenSum_Stats1_Win1, offset: 0x120 */
  __I  uint32_t BLSUS1W1;                          /**< BlueSum_Stats1_Win1, offset: 0x124 */
  __I  uint32_t PIXCS0W2;                          /**< PixCnt_Stats0_Win2, offset: 0x128 */
  __I  uint32_t PIMAS0W2;                          /**< PixMax_Stats0_Win2, offset: 0x12C */
  __I  uint32_t PIMIS0W2;                          /**< PixMin_Stats0_Win2, offset: 0x130 */
  __I  uint32_t RESUS0W2;                          /**< RedSum_Stats0_Win2, offset: 0x134 */
  __I  uint32_t GRESS0W2;                          /**< GreenSum_Stats0_Win2, offset: 0x138 */
  __I  uint32_t BLSUS0W2;                          /**< BlueSum_Stats0_Win2, offset: 0x13C */
  __I  uint32_t LUSUS0W2;                          /**< LumSum_Stats0_Win2, offset: 0x140 */
  __I  uint32_t PIXCS1W2;                          /**< PixCnt_Stats1_Win2, offset: 0x144 */
  __I  uint32_t PIMAS1W2;                          /**< PixMax_Stats1_Win2, offset: 0x148 */
  __I  uint32_t PIMIS1W2;                          /**< PixMin_Stats1_Win2, offset: 0x14C */
  __I  uint32_t RESUS1W2;                          /**< RedSum_Stats1_Win2, offset: 0x150 */
  __I  uint32_t GRESS1W2;                          /**< GreenSum_Stats1_Win2, offset: 0x154 */
  __I  uint32_t BLSUS1W2;                          /**< BlueSum_Stats1_Win2, offset: 0x158 */
  __I  uint32_t PIXCS0W3;                          /**< PixCnt_Stats0_Win3, offset: 0x15C */
  __I  uint32_t PIMAS0W3;                          /**< PixMax_Stats0_Win3, offset: 0x160 */
  __I  uint32_t PIMIS0W3;                          /**< PixMin_Stats0_Win3, offset: 0x164 */
  __I  uint32_t RESUS0W3;                          /**< RedSum_Stats0_Win3, offset: 0x168 */
  __I  uint32_t GRESS0W3;                          /**< GreenSum_Stats0_Win3, offset: 0x16C */
  __I  uint32_t BLSUS0W3;                          /**< BlueSum_Stats0_Win3, offset: 0x170 */
  __I  uint32_t LUSUS0W3;                          /**< LumSum_Stats0_Win3, offset: 0x174 */
  __I  uint32_t PIXCS1W3;                          /**< PixCnt_Stats1_Win3, offset: 0x178 */
  __I  uint32_t PIMAS1W3;                          /**< PixMax_Stats1_Win3, offset: 0x17C */
  __I  uint32_t PIMIS1W3;                          /**< PixMin_Stats1_Win3, offset: 0x180 */
  __I  uint32_t RESUS1W3;                          /**< RedSum_Stats1_Win3, offset: 0x184 */
  __I  uint32_t GRESS1W3;                          /**< GreenSum_Stats1_Win3, offset: 0x188 */
  __I  uint32_t BLSUS1W3;                          /**< BlueSum_Stats1_Win3, offset: 0x18C */
} sig3_Type;

/* ----------------------------------------------------------------------------
   -- sig3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup sig3_Register_Masks sig3 Register Masks
 * @{
 */

/*! @name CRCRW0 - CRC_R_Window0 */
/*! @{ */

#define sig3_CRCRW0_CRCRW0_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW0_CRCRW0_SHIFT                 (0U)
/*! CRCRW0 - CRC_R_Window0 */
#define sig3_CRCRW0_CRCRW0(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW0_CRCRW0_SHIFT)) & sig3_CRCRW0_CRCRW0_MASK)
/*! @} */

/*! @name CRCGW0 - CRC_G_Window0 */
/*! @{ */

#define sig3_CRCGW0_CRCGW0_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW0_CRCGW0_SHIFT                 (0U)
/*! CRCGW0 - CRC_G_Window0 */
#define sig3_CRCGW0_CRCGW0(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW0_CRCGW0_SHIFT)) & sig3_CRCGW0_CRCGW0_MASK)
/*! @} */

/*! @name CRCBW0 - CRC_B_Window0 */
/*! @{ */

#define sig3_CRCBW0_CRCBW0_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW0_CRCBW0_SHIFT                 (0U)
/*! CRCBW0 - CRC_B_Window0 */
#define sig3_CRCBW0_CRCBW0(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW0_CRCBW0_SHIFT)) & sig3_CRCBW0_CRCBW0_MASK)
/*! @} */

/*! @name CRCRW1 - CRC_R_Window1 */
/*! @{ */

#define sig3_CRCRW1_CRCRW1_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW1_CRCRW1_SHIFT                 (0U)
/*! CRCRW1 - CRC_R_Window1 */
#define sig3_CRCRW1_CRCRW1(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW1_CRCRW1_SHIFT)) & sig3_CRCRW1_CRCRW1_MASK)
/*! @} */

/*! @name CRCGW1 - CRC_G_Window1 */
/*! @{ */

#define sig3_CRCGW1_CRCGW1_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW1_CRCGW1_SHIFT                 (0U)
/*! CRCGW1 - CRC_G_Window1 */
#define sig3_CRCGW1_CRCGW1(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW1_CRCGW1_SHIFT)) & sig3_CRCGW1_CRCGW1_MASK)
/*! @} */

/*! @name CRCBW1 - CRC_B_Window1 */
/*! @{ */

#define sig3_CRCBW1_CRCBW1_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW1_CRCBW1_SHIFT                 (0U)
/*! CRCBW1 - CRC_B_Window1 */
#define sig3_CRCBW1_CRCBW1(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW1_CRCBW1_SHIFT)) & sig3_CRCBW1_CRCBW1_MASK)
/*! @} */

/*! @name CRCRW2 - CRC_R_Window2 */
/*! @{ */

#define sig3_CRCRW2_CRCRW2_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW2_CRCRW2_SHIFT                 (0U)
/*! CRCRW2 - CRC_R_Window2 */
#define sig3_CRCRW2_CRCRW2(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW2_CRCRW2_SHIFT)) & sig3_CRCRW2_CRCRW2_MASK)
/*! @} */

/*! @name CRCGW2 - CRC_G_Window2 */
/*! @{ */

#define sig3_CRCGW2_CRCGW2_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW2_CRCGW2_SHIFT                 (0U)
/*! CRCGW2 - CRC_G_Window2 */
#define sig3_CRCGW2_CRCGW2(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW2_CRCGW2_SHIFT)) & sig3_CRCGW2_CRCGW2_MASK)
/*! @} */

/*! @name CRCBW2 - CRC_B_Window2 */
/*! @{ */

#define sig3_CRCBW2_CRCBW2_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW2_CRCBW2_SHIFT                 (0U)
/*! CRCBW2 - CRC_B_Window2 */
#define sig3_CRCBW2_CRCBW2(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW2_CRCBW2_SHIFT)) & sig3_CRCBW2_CRCBW2_MASK)
/*! @} */

/*! @name CRCRW3 - CRC_R_Window3 */
/*! @{ */

#define sig3_CRCRW3_CRCRW3_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW3_CRCRW3_SHIFT                 (0U)
/*! CRCRW3 - CRC_R_Window3 */
#define sig3_CRCRW3_CRCRW3(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW3_CRCRW3_SHIFT)) & sig3_CRCRW3_CRCRW3_MASK)
/*! @} */

/*! @name CRCGW3 - CRC_G_Window3 */
/*! @{ */

#define sig3_CRCGW3_CRCGW3_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW3_CRCGW3_SHIFT                 (0U)
/*! CRCGW3 - CRC_G_Window3 */
#define sig3_CRCGW3_CRCGW3(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW3_CRCGW3_SHIFT)) & sig3_CRCGW3_CRCGW3_MASK)
/*! @} */

/*! @name CRCBW3 - CRC_B_Window3 */
/*! @{ */

#define sig3_CRCBW3_CRCBW3_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW3_CRCBW3_SHIFT                 (0U)
/*! CRCBW3 - CRC_B_Window3 */
#define sig3_CRCBW3_CRCBW3(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW3_CRCBW3_SHIFT)) & sig3_CRCBW3_CRCBW3_MASK)
/*! @} */

/*! @name CRCRW4 - CRC_R_Window4 */
/*! @{ */

#define sig3_CRCRW4_CRCRW4_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW4_CRCRW4_SHIFT                 (0U)
/*! CRCRW4 - CRC_R_Window4 */
#define sig3_CRCRW4_CRCRW4(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW4_CRCRW4_SHIFT)) & sig3_CRCRW4_CRCRW4_MASK)
/*! @} */

/*! @name CRCGW4 - CRC_G_Window4 */
/*! @{ */

#define sig3_CRCGW4_CRCGW4_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW4_CRCGW4_SHIFT                 (0U)
/*! CRCGW4 - CRC_G_Window4 */
#define sig3_CRCGW4_CRCGW4(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW4_CRCGW4_SHIFT)) & sig3_CRCGW4_CRCGW4_MASK)
/*! @} */

/*! @name CRCBW4 - CRC_B_Window4 */
/*! @{ */

#define sig3_CRCBW4_CRCBW4_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW4_CRCBW4_SHIFT                 (0U)
/*! CRCBW4 - CRC_B_Window4 */
#define sig3_CRCBW4_CRCBW4(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW4_CRCBW4_SHIFT)) & sig3_CRCBW4_CRCBW4_MASK)
/*! @} */

/*! @name CRCRW5 - CRC_R_Window5 */
/*! @{ */

#define sig3_CRCRW5_CRCRW5_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW5_CRCRW5_SHIFT                 (0U)
/*! CRCRW5 - CRC_R_Window5 */
#define sig3_CRCRW5_CRCRW5(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW5_CRCRW5_SHIFT)) & sig3_CRCRW5_CRCRW5_MASK)
/*! @} */

/*! @name CRCGW5 - CRC_G_Window5 */
/*! @{ */

#define sig3_CRCGW5_CRCGW5_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW5_CRCGW5_SHIFT                 (0U)
/*! CRCGW5 - CRC_G_Window5 */
#define sig3_CRCGW5_CRCGW5(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW5_CRCGW5_SHIFT)) & sig3_CRCGW5_CRCGW5_MASK)
/*! @} */

/*! @name CRCBW5 - CRC_B_Window5 */
/*! @{ */

#define sig3_CRCBW5_CRCBW5_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW5_CRCBW5_SHIFT                 (0U)
/*! CRCBW5 - CRC_B_Window5 */
#define sig3_CRCBW5_CRCBW5(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW5_CRCBW5_SHIFT)) & sig3_CRCBW5_CRCBW5_MASK)
/*! @} */

/*! @name CRCRW6 - CRC_R_Window6 */
/*! @{ */

#define sig3_CRCRW6_CRCRW6_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW6_CRCRW6_SHIFT                 (0U)
/*! CRCRW6 - CRC_R_Window6 */
#define sig3_CRCRW6_CRCRW6(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW6_CRCRW6_SHIFT)) & sig3_CRCRW6_CRCRW6_MASK)
/*! @} */

/*! @name CRCGW6 - CRC_G_Window6 */
/*! @{ */

#define sig3_CRCGW6_CRCGW6_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW6_CRCGW6_SHIFT                 (0U)
/*! CRCGW6 - CRC_G_Window6 */
#define sig3_CRCGW6_CRCGW6(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW6_CRCGW6_SHIFT)) & sig3_CRCGW6_CRCGW6_MASK)
/*! @} */

/*! @name CRCBW6 - CRC_B_Window6 */
/*! @{ */

#define sig3_CRCBW6_CRCBW6_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW6_CRCBW6_SHIFT                 (0U)
/*! CRCBW6 - CRC_B_Window6 */
#define sig3_CRCBW6_CRCBW6(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW6_CRCBW6_SHIFT)) & sig3_CRCBW6_CRCBW6_MASK)
/*! @} */

/*! @name CRCRW7 - CRC_R_Window7 */
/*! @{ */

#define sig3_CRCRW7_CRCRW7_MASK                  (0xFFFFFFFFU)
#define sig3_CRCRW7_CRCRW7_SHIFT                 (0U)
/*! CRCRW7 - CRC_R_Window7 */
#define sig3_CRCRW7_CRCRW7(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCRW7_CRCRW7_SHIFT)) & sig3_CRCRW7_CRCRW7_MASK)
/*! @} */

/*! @name CRCGW7 - CRC_G_Window7 */
/*! @{ */

#define sig3_CRCGW7_CRCGW7_MASK                  (0xFFFFFFFFU)
#define sig3_CRCGW7_CRCGW7_SHIFT                 (0U)
/*! CRCGW7 - CRC_G_Window7 */
#define sig3_CRCGW7_CRCGW7(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCGW7_CRCGW7_SHIFT)) & sig3_CRCGW7_CRCGW7_MASK)
/*! @} */

/*! @name CRCBW7 - CRC_B_Window7 */
/*! @{ */

#define sig3_CRCBW7_CRCBW7_MASK                  (0xFFFFFFFFU)
#define sig3_CRCBW7_CRCBW7_SHIFT                 (0U)
/*! CRCBW7 - CRC_B_Window7 */
#define sig3_CRCBW7_CRCBW7(x)                    (((uint32_t)(((uint32_t)(x)) << sig3_CRCBW7_CRCBW7_SHIFT)) & sig3_CRCBW7_CRCBW7_MASK)
/*! @} */

/*! @name STATUC0 - Status_Cluster0 */
/*! @{ */

#define sig3_STATUC0_Sts00C0_MASK                (0x1U)
#define sig3_STATUC0_Sts00C0_SHIFT               (0U)
/*! Sts00C0 - Sts00_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts00C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts00C0_SHIFT)) & sig3_STATUC0_Sts00C0_MASK)

#define sig3_STATUC0_Sts01C0_MASK                (0x2U)
#define sig3_STATUC0_Sts01C0_SHIFT               (1U)
/*! Sts01C0 - Sts01_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts01C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts01C0_SHIFT)) & sig3_STATUC0_Sts01C0_MASK)

#define sig3_STATUC0_Sts10C0_MASK                (0x4U)
#define sig3_STATUC0_Sts10C0_SHIFT               (2U)
/*! Sts10C0 - Sts10_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts10C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts10C0_SHIFT)) & sig3_STATUC0_Sts10C0_MASK)

#define sig3_STATUC0_Sts11C0_MASK                (0x8U)
#define sig3_STATUC0_Sts11C0_SHIFT               (3U)
/*! Sts11C0 - Sts11_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts11C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts11C0_SHIFT)) & sig3_STATUC0_Sts11C0_MASK)

#define sig3_STATUC0_Sts20C0_MASK                (0x10U)
#define sig3_STATUC0_Sts20C0_SHIFT               (4U)
/*! Sts20C0 - Sts20_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts20C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts20C0_SHIFT)) & sig3_STATUC0_Sts20C0_MASK)

#define sig3_STATUC0_Sts21C0_MASK                (0x20U)
#define sig3_STATUC0_Sts21C0_SHIFT               (5U)
/*! Sts21C0 - Sts21_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts21C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts21C0_SHIFT)) & sig3_STATUC0_Sts21C0_MASK)

#define sig3_STATUC0_Sts30C0_MASK                (0x40U)
#define sig3_STATUC0_Sts30C0_SHIFT               (6U)
/*! Sts30C0 - Sts30_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts30C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts30C0_SHIFT)) & sig3_STATUC0_Sts30C0_MASK)

#define sig3_STATUC0_Sts31C0_MASK                (0x80U)
#define sig3_STATUC0_Sts31C0_SHIFT               (7U)
/*! Sts31C0 - Sts31_Cluster0
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC0_Sts31C0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC0_Sts31C0_SHIFT)) & sig3_STATUC0_Sts31C0_MASK)
/*! @} */

/*! @name COUNTC0 - Counter_Cluster0 */
/*! @{ */

#define sig3_COUNTC0_MatCtC0_MASK                (0xFFU)
#define sig3_COUNTC0_MatCtC0_SHIFT               (0U)
/*! MatCtC0 - MatchCount_Cluster0 */
#define sig3_COUNTC0_MatCtC0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC0_MatCtC0_SHIFT)) & sig3_COUNTC0_MatCtC0_MASK)

#define sig3_COUNTC0_ErCClu0_MASK                (0xFF0000U)
#define sig3_COUNTC0_ErCClu0_SHIFT               (16U)
/*! ErCClu0 - ErrorCount_Cluster0 */
#define sig3_COUNTC0_ErCClu0(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC0_ErCClu0_SHIFT)) & sig3_COUNTC0_ErCClu0_MASK)
/*! @} */

/*! @name VEC0CL0 - Vector0_Cluster0 */
/*! @{ */

#define sig3_VEC0CL0_Px0B10C0_MASK               (0x3U)
#define sig3_VEC0CL0_Px0B10C0_SHIFT              (0U)
/*! Px0B10C0 - Pix0_B10_Cluster0 */
#define sig3_VEC0CL0_Px0B10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px0B10C0_SHIFT)) & sig3_VEC0CL0_Px0B10C0_MASK)

#define sig3_VEC0CL0_Px0G10C0_MASK               (0xCU)
#define sig3_VEC0CL0_Px0G10C0_SHIFT              (2U)
/*! Px0G10C0 - Pix0_G10_Cluster0 */
#define sig3_VEC0CL0_Px0G10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px0G10C0_SHIFT)) & sig3_VEC0CL0_Px0G10C0_MASK)

#define sig3_VEC0CL0_Px0R10C0_MASK               (0x30U)
#define sig3_VEC0CL0_Px0R10C0_SHIFT              (4U)
/*! Px0R10C0 - Pix0_R10_Cluster0 */
#define sig3_VEC0CL0_Px0R10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px0R10C0_SHIFT)) & sig3_VEC0CL0_Px0R10C0_MASK)

#define sig3_VEC0CL0_Px1B10C0_MASK               (0xC0U)
#define sig3_VEC0CL0_Px1B10C0_SHIFT              (6U)
/*! Px1B10C0 - Pix1_B10_Cluster0 */
#define sig3_VEC0CL0_Px1B10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px1B10C0_SHIFT)) & sig3_VEC0CL0_Px1B10C0_MASK)

#define sig3_VEC0CL0_Px1G10C0_MASK               (0x300U)
#define sig3_VEC0CL0_Px1G10C0_SHIFT              (8U)
/*! Px1G10C0 - Pix1_G10_Cluster0 */
#define sig3_VEC0CL0_Px1G10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px1G10C0_SHIFT)) & sig3_VEC0CL0_Px1G10C0_MASK)

#define sig3_VEC0CL0_Px1R10C0_MASK               (0xC00U)
#define sig3_VEC0CL0_Px1R10C0_SHIFT              (10U)
/*! Px1R10C0 - Pix1_R10_Cluster0 */
#define sig3_VEC0CL0_Px1R10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px1R10C0_SHIFT)) & sig3_VEC0CL0_Px1R10C0_MASK)

#define sig3_VEC0CL0_Px2B10C0_MASK               (0x3000U)
#define sig3_VEC0CL0_Px2B10C0_SHIFT              (12U)
/*! Px2B10C0 - Pix2_B10_Cluster0 */
#define sig3_VEC0CL0_Px2B10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px2B10C0_SHIFT)) & sig3_VEC0CL0_Px2B10C0_MASK)

#define sig3_VEC0CL0_Px2G10C0_MASK               (0xC000U)
#define sig3_VEC0CL0_Px2G10C0_SHIFT              (14U)
/*! Px2G10C0 - Pix2_G10_Cluster0 */
#define sig3_VEC0CL0_Px2G10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px2G10C0_SHIFT)) & sig3_VEC0CL0_Px2G10C0_MASK)

#define sig3_VEC0CL0_Px2R10C0_MASK               (0x30000U)
#define sig3_VEC0CL0_Px2R10C0_SHIFT              (16U)
/*! Px2R10C0 - Pix2_R10_Cluster0 */
#define sig3_VEC0CL0_Px2R10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px2R10C0_SHIFT)) & sig3_VEC0CL0_Px2R10C0_MASK)

#define sig3_VEC0CL0_Px3B10C0_MASK               (0xC0000U)
#define sig3_VEC0CL0_Px3B10C0_SHIFT              (18U)
/*! Px3B10C0 - Pix3_B10_Cluster0 */
#define sig3_VEC0CL0_Px3B10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px3B10C0_SHIFT)) & sig3_VEC0CL0_Px3B10C0_MASK)

#define sig3_VEC0CL0_Px3G10C0_MASK               (0x300000U)
#define sig3_VEC0CL0_Px3G10C0_SHIFT              (20U)
/*! Px3G10C0 - Pix3_G10_Cluster0 */
#define sig3_VEC0CL0_Px3G10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px3G10C0_SHIFT)) & sig3_VEC0CL0_Px3G10C0_MASK)

#define sig3_VEC0CL0_Px3R10C0_MASK               (0xC00000U)
#define sig3_VEC0CL0_Px3R10C0_SHIFT              (22U)
/*! Px3R10C0 - Pix3_R10_Cluster0 */
#define sig3_VEC0CL0_Px3R10C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL0_Px3R10C0_SHIFT)) & sig3_VEC0CL0_Px3R10C0_MASK)
/*! @} */

/*! @name VEC1CL0 - Vector1_Cluster0 */
/*! @{ */

#define sig3_VEC1CL0_Px0B32C0_MASK               (0x3U)
#define sig3_VEC1CL0_Px0B32C0_SHIFT              (0U)
/*! Px0B32C0 - Pix0_B32_Cluster0 */
#define sig3_VEC1CL0_Px0B32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px0B32C0_SHIFT)) & sig3_VEC1CL0_Px0B32C0_MASK)

#define sig3_VEC1CL0_Px0G32C0_MASK               (0xCU)
#define sig3_VEC1CL0_Px0G32C0_SHIFT              (2U)
/*! Px0G32C0 - Pix0_G32_Cluster0 */
#define sig3_VEC1CL0_Px0G32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px0G32C0_SHIFT)) & sig3_VEC1CL0_Px0G32C0_MASK)

#define sig3_VEC1CL0_Px0R32C0_MASK               (0x30U)
#define sig3_VEC1CL0_Px0R32C0_SHIFT              (4U)
/*! Px0R32C0 - Pix0_R32_Cluster0 */
#define sig3_VEC1CL0_Px0R32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px0R32C0_SHIFT)) & sig3_VEC1CL0_Px0R32C0_MASK)

#define sig3_VEC1CL0_Px1B32C0_MASK               (0xC0U)
#define sig3_VEC1CL0_Px1B32C0_SHIFT              (6U)
/*! Px1B32C0 - Pix1_B32_Cluster0 */
#define sig3_VEC1CL0_Px1B32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px1B32C0_SHIFT)) & sig3_VEC1CL0_Px1B32C0_MASK)

#define sig3_VEC1CL0_Px1G32C0_MASK               (0x300U)
#define sig3_VEC1CL0_Px1G32C0_SHIFT              (8U)
/*! Px1G32C0 - Pix1_G32_Cluster0 */
#define sig3_VEC1CL0_Px1G32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px1G32C0_SHIFT)) & sig3_VEC1CL0_Px1G32C0_MASK)

#define sig3_VEC1CL0_Px1R32C0_MASK               (0xC00U)
#define sig3_VEC1CL0_Px1R32C0_SHIFT              (10U)
/*! Px1R32C0 - Pix1_R32_Cluster0 */
#define sig3_VEC1CL0_Px1R32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px1R32C0_SHIFT)) & sig3_VEC1CL0_Px1R32C0_MASK)

#define sig3_VEC1CL0_Px2B32C0_MASK               (0x3000U)
#define sig3_VEC1CL0_Px2B32C0_SHIFT              (12U)
/*! Px2B32C0 - Pix2_B32_Cluster0 */
#define sig3_VEC1CL0_Px2B32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px2B32C0_SHIFT)) & sig3_VEC1CL0_Px2B32C0_MASK)

#define sig3_VEC1CL0_Px2G32C0_MASK               (0xC000U)
#define sig3_VEC1CL0_Px2G32C0_SHIFT              (14U)
/*! Px2G32C0 - Pix2_G32_Cluster0 */
#define sig3_VEC1CL0_Px2G32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px2G32C0_SHIFT)) & sig3_VEC1CL0_Px2G32C0_MASK)

#define sig3_VEC1CL0_Px2R32C0_MASK               (0x30000U)
#define sig3_VEC1CL0_Px2R32C0_SHIFT              (16U)
/*! Px2R32C0 - Pix2_R32_Cluster0 */
#define sig3_VEC1CL0_Px2R32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px2R32C0_SHIFT)) & sig3_VEC1CL0_Px2R32C0_MASK)

#define sig3_VEC1CL0_Px3B32C0_MASK               (0xC0000U)
#define sig3_VEC1CL0_Px3B32C0_SHIFT              (18U)
/*! Px3B32C0 - Pix3_B32_Cluster0 */
#define sig3_VEC1CL0_Px3B32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px3B32C0_SHIFT)) & sig3_VEC1CL0_Px3B32C0_MASK)

#define sig3_VEC1CL0_Px3G32C0_MASK               (0x300000U)
#define sig3_VEC1CL0_Px3G32C0_SHIFT              (20U)
/*! Px3G32C0 - Pix3_G32_Cluster0 */
#define sig3_VEC1CL0_Px3G32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px3G32C0_SHIFT)) & sig3_VEC1CL0_Px3G32C0_MASK)

#define sig3_VEC1CL0_Px3R32C0_MASK               (0xC00000U)
#define sig3_VEC1CL0_Px3R32C0_SHIFT              (22U)
/*! Px3R32C0 - Pix3_R32_Cluster0 */
#define sig3_VEC1CL0_Px3R32C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL0_Px3R32C0_SHIFT)) & sig3_VEC1CL0_Px3R32C0_MASK)
/*! @} */

/*! @name VEC2CL0 - Vector2_Cluster0 */
/*! @{ */

#define sig3_VEC2CL0_Px0B54C0_MASK               (0x3U)
#define sig3_VEC2CL0_Px0B54C0_SHIFT              (0U)
/*! Px0B54C0 - Pix0_B54_Cluster0 */
#define sig3_VEC2CL0_Px0B54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px0B54C0_SHIFT)) & sig3_VEC2CL0_Px0B54C0_MASK)

#define sig3_VEC2CL0_Px0G54C0_MASK               (0xCU)
#define sig3_VEC2CL0_Px0G54C0_SHIFT              (2U)
/*! Px0G54C0 - Pix0_G54_Cluster0 */
#define sig3_VEC2CL0_Px0G54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px0G54C0_SHIFT)) & sig3_VEC2CL0_Px0G54C0_MASK)

#define sig3_VEC2CL0_Px0R54C0_MASK               (0x30U)
#define sig3_VEC2CL0_Px0R54C0_SHIFT              (4U)
/*! Px0R54C0 - Pix0_R54_Cluster0 */
#define sig3_VEC2CL0_Px0R54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px0R54C0_SHIFT)) & sig3_VEC2CL0_Px0R54C0_MASK)

#define sig3_VEC2CL0_Px1B54C0_MASK               (0xC0U)
#define sig3_VEC2CL0_Px1B54C0_SHIFT              (6U)
/*! Px1B54C0 - Pix1_B54_Cluster0 */
#define sig3_VEC2CL0_Px1B54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px1B54C0_SHIFT)) & sig3_VEC2CL0_Px1B54C0_MASK)

#define sig3_VEC2CL0_Px1G54C0_MASK               (0x300U)
#define sig3_VEC2CL0_Px1G54C0_SHIFT              (8U)
/*! Px1G54C0 - Pix1_G54_Cluster0 */
#define sig3_VEC2CL0_Px1G54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px1G54C0_SHIFT)) & sig3_VEC2CL0_Px1G54C0_MASK)

#define sig3_VEC2CL0_Px1R54C0_MASK               (0xC00U)
#define sig3_VEC2CL0_Px1R54C0_SHIFT              (10U)
/*! Px1R54C0 - Pix1_R54_Cluster0 */
#define sig3_VEC2CL0_Px1R54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px1R54C0_SHIFT)) & sig3_VEC2CL0_Px1R54C0_MASK)

#define sig3_VEC2CL0_Px2B54C0_MASK               (0x3000U)
#define sig3_VEC2CL0_Px2B54C0_SHIFT              (12U)
/*! Px2B54C0 - Pix2_B54_Cluster0 */
#define sig3_VEC2CL0_Px2B54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px2B54C0_SHIFT)) & sig3_VEC2CL0_Px2B54C0_MASK)

#define sig3_VEC2CL0_Px2G54C0_MASK               (0xC000U)
#define sig3_VEC2CL0_Px2G54C0_SHIFT              (14U)
/*! Px2G54C0 - Pix2_G54_Cluster0 */
#define sig3_VEC2CL0_Px2G54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px2G54C0_SHIFT)) & sig3_VEC2CL0_Px2G54C0_MASK)

#define sig3_VEC2CL0_Px2R54C0_MASK               (0x30000U)
#define sig3_VEC2CL0_Px2R54C0_SHIFT              (16U)
/*! Px2R54C0 - Pix2_R54_Cluster0 */
#define sig3_VEC2CL0_Px2R54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px2R54C0_SHIFT)) & sig3_VEC2CL0_Px2R54C0_MASK)

#define sig3_VEC2CL0_Px3B54C0_MASK               (0xC0000U)
#define sig3_VEC2CL0_Px3B54C0_SHIFT              (18U)
/*! Px3B54C0 - Pix3_B54_Cluster0 */
#define sig3_VEC2CL0_Px3B54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px3B54C0_SHIFT)) & sig3_VEC2CL0_Px3B54C0_MASK)

#define sig3_VEC2CL0_Px3G54C0_MASK               (0x300000U)
#define sig3_VEC2CL0_Px3G54C0_SHIFT              (20U)
/*! Px3G54C0 - Pix3_G54_Cluster0 */
#define sig3_VEC2CL0_Px3G54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px3G54C0_SHIFT)) & sig3_VEC2CL0_Px3G54C0_MASK)

#define sig3_VEC2CL0_Px3R54C0_MASK               (0xC00000U)
#define sig3_VEC2CL0_Px3R54C0_SHIFT              (22U)
/*! Px3R54C0 - Pix3_R54_Cluster0 */
#define sig3_VEC2CL0_Px3R54C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL0_Px3R54C0_SHIFT)) & sig3_VEC2CL0_Px3R54C0_MASK)
/*! @} */

/*! @name VEC3CL0 - Vector3_Cluster0 */
/*! @{ */

#define sig3_VEC3CL0_Px0B76C0_MASK               (0x3U)
#define sig3_VEC3CL0_Px0B76C0_SHIFT              (0U)
/*! Px0B76C0 - Pix0_B76_Cluster0 */
#define sig3_VEC3CL0_Px0B76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px0B76C0_SHIFT)) & sig3_VEC3CL0_Px0B76C0_MASK)

#define sig3_VEC3CL0_Px0G76C0_MASK               (0xCU)
#define sig3_VEC3CL0_Px0G76C0_SHIFT              (2U)
/*! Px0G76C0 - Pix0_G76_Cluster0 */
#define sig3_VEC3CL0_Px0G76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px0G76C0_SHIFT)) & sig3_VEC3CL0_Px0G76C0_MASK)

#define sig3_VEC3CL0_Px0R76C0_MASK               (0x30U)
#define sig3_VEC3CL0_Px0R76C0_SHIFT              (4U)
/*! Px0R76C0 - Pix0_R76_Cluster0 */
#define sig3_VEC3CL0_Px0R76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px0R76C0_SHIFT)) & sig3_VEC3CL0_Px0R76C0_MASK)

#define sig3_VEC3CL0_Px1B76C0_MASK               (0xC0U)
#define sig3_VEC3CL0_Px1B76C0_SHIFT              (6U)
/*! Px1B76C0 - Pix1_B76_Cluster0 */
#define sig3_VEC3CL0_Px1B76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px1B76C0_SHIFT)) & sig3_VEC3CL0_Px1B76C0_MASK)

#define sig3_VEC3CL0_Px1G76C0_MASK               (0x300U)
#define sig3_VEC3CL0_Px1G76C0_SHIFT              (8U)
/*! Px1G76C0 - Pix1_G76_Cluster0 */
#define sig3_VEC3CL0_Px1G76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px1G76C0_SHIFT)) & sig3_VEC3CL0_Px1G76C0_MASK)

#define sig3_VEC3CL0_Px1R76C0_MASK               (0xC00U)
#define sig3_VEC3CL0_Px1R76C0_SHIFT              (10U)
/*! Px1R76C0 - Pix1_R76_Cluster0 */
#define sig3_VEC3CL0_Px1R76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px1R76C0_SHIFT)) & sig3_VEC3CL0_Px1R76C0_MASK)

#define sig3_VEC3CL0_Px2B76C0_MASK               (0x3000U)
#define sig3_VEC3CL0_Px2B76C0_SHIFT              (12U)
/*! Px2B76C0 - Pix2_B76_Cluster0 */
#define sig3_VEC3CL0_Px2B76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px2B76C0_SHIFT)) & sig3_VEC3CL0_Px2B76C0_MASK)

#define sig3_VEC3CL0_Px2G76C0_MASK               (0xC000U)
#define sig3_VEC3CL0_Px2G76C0_SHIFT              (14U)
/*! Px2G76C0 - Pix2_G76_Cluster0 */
#define sig3_VEC3CL0_Px2G76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px2G76C0_SHIFT)) & sig3_VEC3CL0_Px2G76C0_MASK)

#define sig3_VEC3CL0_Px2R76C0_MASK               (0x30000U)
#define sig3_VEC3CL0_Px2R76C0_SHIFT              (16U)
/*! Px2R76C0 - Pix2_R76_Cluster0 */
#define sig3_VEC3CL0_Px2R76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px2R76C0_SHIFT)) & sig3_VEC3CL0_Px2R76C0_MASK)

#define sig3_VEC3CL0_Px3B76C0_MASK               (0xC0000U)
#define sig3_VEC3CL0_Px3B76C0_SHIFT              (18U)
/*! Px3B76C0 - Pix3_B76_Cluster0 */
#define sig3_VEC3CL0_Px3B76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px3B76C0_SHIFT)) & sig3_VEC3CL0_Px3B76C0_MASK)

#define sig3_VEC3CL0_Px3G76C0_MASK               (0x300000U)
#define sig3_VEC3CL0_Px3G76C0_SHIFT              (20U)
/*! Px3G76C0 - Pix3_G76_Cluster0 */
#define sig3_VEC3CL0_Px3G76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px3G76C0_SHIFT)) & sig3_VEC3CL0_Px3G76C0_MASK)

#define sig3_VEC3CL0_Px3R76C0_MASK               (0xC00000U)
#define sig3_VEC3CL0_Px3R76C0_SHIFT              (22U)
/*! Px3R76C0 - Pix3_R76_Cluster0 */
#define sig3_VEC3CL0_Px3R76C0(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL0_Px3R76C0_SHIFT)) & sig3_VEC3CL0_Px3R76C0_MASK)
/*! @} */

/*! @name STATUC1 - Status_Cluster1 */
/*! @{ */

#define sig3_STATUC1_Sts00C1_MASK                (0x1U)
#define sig3_STATUC1_Sts00C1_SHIFT               (0U)
/*! Sts00C1 - Sts00_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts00C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts00C1_SHIFT)) & sig3_STATUC1_Sts00C1_MASK)

#define sig3_STATUC1_Sts01C1_MASK                (0x2U)
#define sig3_STATUC1_Sts01C1_SHIFT               (1U)
/*! Sts01C1 - Sts01_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts01C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts01C1_SHIFT)) & sig3_STATUC1_Sts01C1_MASK)

#define sig3_STATUC1_Sts10C1_MASK                (0x4U)
#define sig3_STATUC1_Sts10C1_SHIFT               (2U)
/*! Sts10C1 - Sts10_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts10C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts10C1_SHIFT)) & sig3_STATUC1_Sts10C1_MASK)

#define sig3_STATUC1_Sts11C1_MASK                (0x8U)
#define sig3_STATUC1_Sts11C1_SHIFT               (3U)
/*! Sts11C1 - Sts11_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts11C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts11C1_SHIFT)) & sig3_STATUC1_Sts11C1_MASK)

#define sig3_STATUC1_Sts20C1_MASK                (0x10U)
#define sig3_STATUC1_Sts20C1_SHIFT               (4U)
/*! Sts20C1 - Sts20_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts20C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts20C1_SHIFT)) & sig3_STATUC1_Sts20C1_MASK)

#define sig3_STATUC1_Sts21C1_MASK                (0x20U)
#define sig3_STATUC1_Sts21C1_SHIFT               (5U)
/*! Sts21C1 - Sts21_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts21C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts21C1_SHIFT)) & sig3_STATUC1_Sts21C1_MASK)

#define sig3_STATUC1_Sts30C1_MASK                (0x40U)
#define sig3_STATUC1_Sts30C1_SHIFT               (6U)
/*! Sts30C1 - Sts30_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts30C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts30C1_SHIFT)) & sig3_STATUC1_Sts30C1_MASK)

#define sig3_STATUC1_Sts31C1_MASK                (0x80U)
#define sig3_STATUC1_Sts31C1_SHIFT               (7U)
/*! Sts31C1 - Sts31_Cluster1
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC1_Sts31C1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC1_Sts31C1_SHIFT)) & sig3_STATUC1_Sts31C1_MASK)
/*! @} */

/*! @name COUNTC1 - Counter_Cluster1 */
/*! @{ */

#define sig3_COUNTC1_MatCtC1_MASK                (0xFFU)
#define sig3_COUNTC1_MatCtC1_SHIFT               (0U)
/*! MatCtC1 - MatchCount_Cluster1 */
#define sig3_COUNTC1_MatCtC1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC1_MatCtC1_SHIFT)) & sig3_COUNTC1_MatCtC1_MASK)

#define sig3_COUNTC1_ErCClu1_MASK                (0xFF0000U)
#define sig3_COUNTC1_ErCClu1_SHIFT               (16U)
/*! ErCClu1 - ErrorCount_Cluster1 */
#define sig3_COUNTC1_ErCClu1(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC1_ErCClu1_SHIFT)) & sig3_COUNTC1_ErCClu1_MASK)
/*! @} */

/*! @name VEC0CL1 - Vector0_Cluster1 */
/*! @{ */

#define sig3_VEC0CL1_Px0B10C1_MASK               (0x3U)
#define sig3_VEC0CL1_Px0B10C1_SHIFT              (0U)
/*! Px0B10C1 - Pix0_B10_Cluster1 */
#define sig3_VEC0CL1_Px0B10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px0B10C1_SHIFT)) & sig3_VEC0CL1_Px0B10C1_MASK)

#define sig3_VEC0CL1_Px0G10C1_MASK               (0xCU)
#define sig3_VEC0CL1_Px0G10C1_SHIFT              (2U)
/*! Px0G10C1 - Pix0_G10_Cluster1 */
#define sig3_VEC0CL1_Px0G10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px0G10C1_SHIFT)) & sig3_VEC0CL1_Px0G10C1_MASK)

#define sig3_VEC0CL1_Px0R10C1_MASK               (0x30U)
#define sig3_VEC0CL1_Px0R10C1_SHIFT              (4U)
/*! Px0R10C1 - Pix0_R10_Cluster1 */
#define sig3_VEC0CL1_Px0R10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px0R10C1_SHIFT)) & sig3_VEC0CL1_Px0R10C1_MASK)

#define sig3_VEC0CL1_Px1B10C1_MASK               (0xC0U)
#define sig3_VEC0CL1_Px1B10C1_SHIFT              (6U)
/*! Px1B10C1 - Pix1_B10_Cluster1 */
#define sig3_VEC0CL1_Px1B10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px1B10C1_SHIFT)) & sig3_VEC0CL1_Px1B10C1_MASK)

#define sig3_VEC0CL1_Px1G10C1_MASK               (0x300U)
#define sig3_VEC0CL1_Px1G10C1_SHIFT              (8U)
/*! Px1G10C1 - Pix1_G10_Cluster1 */
#define sig3_VEC0CL1_Px1G10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px1G10C1_SHIFT)) & sig3_VEC0CL1_Px1G10C1_MASK)

#define sig3_VEC0CL1_Px1R10C1_MASK               (0xC00U)
#define sig3_VEC0CL1_Px1R10C1_SHIFT              (10U)
/*! Px1R10C1 - Pix1_R10_Cluster1 */
#define sig3_VEC0CL1_Px1R10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px1R10C1_SHIFT)) & sig3_VEC0CL1_Px1R10C1_MASK)

#define sig3_VEC0CL1_Px2B10C1_MASK               (0x3000U)
#define sig3_VEC0CL1_Px2B10C1_SHIFT              (12U)
/*! Px2B10C1 - Pix2_B10_Cluster1 */
#define sig3_VEC0CL1_Px2B10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px2B10C1_SHIFT)) & sig3_VEC0CL1_Px2B10C1_MASK)

#define sig3_VEC0CL1_Px2G10C1_MASK               (0xC000U)
#define sig3_VEC0CL1_Px2G10C1_SHIFT              (14U)
/*! Px2G10C1 - Pix2_G10_Cluster1 */
#define sig3_VEC0CL1_Px2G10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px2G10C1_SHIFT)) & sig3_VEC0CL1_Px2G10C1_MASK)

#define sig3_VEC0CL1_Px2R10C1_MASK               (0x30000U)
#define sig3_VEC0CL1_Px2R10C1_SHIFT              (16U)
/*! Px2R10C1 - Pix2_R10_Cluster1 */
#define sig3_VEC0CL1_Px2R10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px2R10C1_SHIFT)) & sig3_VEC0CL1_Px2R10C1_MASK)

#define sig3_VEC0CL1_Px3B10C1_MASK               (0xC0000U)
#define sig3_VEC0CL1_Px3B10C1_SHIFT              (18U)
/*! Px3B10C1 - Pix3_B10_Cluster1 */
#define sig3_VEC0CL1_Px3B10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px3B10C1_SHIFT)) & sig3_VEC0CL1_Px3B10C1_MASK)

#define sig3_VEC0CL1_Px3G10C1_MASK               (0x300000U)
#define sig3_VEC0CL1_Px3G10C1_SHIFT              (20U)
/*! Px3G10C1 - Pix3_G10_Cluster1 */
#define sig3_VEC0CL1_Px3G10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px3G10C1_SHIFT)) & sig3_VEC0CL1_Px3G10C1_MASK)

#define sig3_VEC0CL1_Px3R10C1_MASK               (0xC00000U)
#define sig3_VEC0CL1_Px3R10C1_SHIFT              (22U)
/*! Px3R10C1 - Pix3_R10_Cluster1 */
#define sig3_VEC0CL1_Px3R10C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL1_Px3R10C1_SHIFT)) & sig3_VEC0CL1_Px3R10C1_MASK)
/*! @} */

/*! @name VEC1CL1 - Vector1_Cluster1 */
/*! @{ */

#define sig3_VEC1CL1_Px0B32C1_MASK               (0x3U)
#define sig3_VEC1CL1_Px0B32C1_SHIFT              (0U)
/*! Px0B32C1 - Pix0_B32_Cluster1 */
#define sig3_VEC1CL1_Px0B32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px0B32C1_SHIFT)) & sig3_VEC1CL1_Px0B32C1_MASK)

#define sig3_VEC1CL1_Px0G32C1_MASK               (0xCU)
#define sig3_VEC1CL1_Px0G32C1_SHIFT              (2U)
/*! Px0G32C1 - Pix0_G32_Cluster1 */
#define sig3_VEC1CL1_Px0G32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px0G32C1_SHIFT)) & sig3_VEC1CL1_Px0G32C1_MASK)

#define sig3_VEC1CL1_Px0R32C1_MASK               (0x30U)
#define sig3_VEC1CL1_Px0R32C1_SHIFT              (4U)
/*! Px0R32C1 - Pix0_R32_Cluster1 */
#define sig3_VEC1CL1_Px0R32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px0R32C1_SHIFT)) & sig3_VEC1CL1_Px0R32C1_MASK)

#define sig3_VEC1CL1_Px1B32C1_MASK               (0xC0U)
#define sig3_VEC1CL1_Px1B32C1_SHIFT              (6U)
/*! Px1B32C1 - Pix1_B32_Cluster1 */
#define sig3_VEC1CL1_Px1B32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px1B32C1_SHIFT)) & sig3_VEC1CL1_Px1B32C1_MASK)

#define sig3_VEC1CL1_Px1G32C1_MASK               (0x300U)
#define sig3_VEC1CL1_Px1G32C1_SHIFT              (8U)
/*! Px1G32C1 - Pix1_G32_Cluster1 */
#define sig3_VEC1CL1_Px1G32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px1G32C1_SHIFT)) & sig3_VEC1CL1_Px1G32C1_MASK)

#define sig3_VEC1CL1_Px1R32C1_MASK               (0xC00U)
#define sig3_VEC1CL1_Px1R32C1_SHIFT              (10U)
/*! Px1R32C1 - Pix1_R32_Cluster1 */
#define sig3_VEC1CL1_Px1R32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px1R32C1_SHIFT)) & sig3_VEC1CL1_Px1R32C1_MASK)

#define sig3_VEC1CL1_Px2B32C1_MASK               (0x3000U)
#define sig3_VEC1CL1_Px2B32C1_SHIFT              (12U)
/*! Px2B32C1 - Pix2_B32_Cluster1 */
#define sig3_VEC1CL1_Px2B32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px2B32C1_SHIFT)) & sig3_VEC1CL1_Px2B32C1_MASK)

#define sig3_VEC1CL1_Px2G32C1_MASK               (0xC000U)
#define sig3_VEC1CL1_Px2G32C1_SHIFT              (14U)
/*! Px2G32C1 - Pix2_G32_Cluster1 */
#define sig3_VEC1CL1_Px2G32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px2G32C1_SHIFT)) & sig3_VEC1CL1_Px2G32C1_MASK)

#define sig3_VEC1CL1_Px2R32C1_MASK               (0x30000U)
#define sig3_VEC1CL1_Px2R32C1_SHIFT              (16U)
/*! Px2R32C1 - Pix2_R32_Cluster1 */
#define sig3_VEC1CL1_Px2R32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px2R32C1_SHIFT)) & sig3_VEC1CL1_Px2R32C1_MASK)

#define sig3_VEC1CL1_Px3B32C1_MASK               (0xC0000U)
#define sig3_VEC1CL1_Px3B32C1_SHIFT              (18U)
/*! Px3B32C1 - Pix3_B32_Cluster1 */
#define sig3_VEC1CL1_Px3B32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px3B32C1_SHIFT)) & sig3_VEC1CL1_Px3B32C1_MASK)

#define sig3_VEC1CL1_Px3G32C1_MASK               (0x300000U)
#define sig3_VEC1CL1_Px3G32C1_SHIFT              (20U)
/*! Px3G32C1 - Pix3_G32_Cluster1 */
#define sig3_VEC1CL1_Px3G32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px3G32C1_SHIFT)) & sig3_VEC1CL1_Px3G32C1_MASK)

#define sig3_VEC1CL1_Px3R32C1_MASK               (0xC00000U)
#define sig3_VEC1CL1_Px3R32C1_SHIFT              (22U)
/*! Px3R32C1 - Pix3_R32_Cluster1 */
#define sig3_VEC1CL1_Px3R32C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL1_Px3R32C1_SHIFT)) & sig3_VEC1CL1_Px3R32C1_MASK)
/*! @} */

/*! @name VEC2CL1 - Vector2_Cluster1 */
/*! @{ */

#define sig3_VEC2CL1_Px0B54C1_MASK               (0x3U)
#define sig3_VEC2CL1_Px0B54C1_SHIFT              (0U)
/*! Px0B54C1 - Pix0_B54_Cluster1 */
#define sig3_VEC2CL1_Px0B54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px0B54C1_SHIFT)) & sig3_VEC2CL1_Px0B54C1_MASK)

#define sig3_VEC2CL1_Px0G54C1_MASK               (0xCU)
#define sig3_VEC2CL1_Px0G54C1_SHIFT              (2U)
/*! Px0G54C1 - Pix0_G54_Cluster1 */
#define sig3_VEC2CL1_Px0G54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px0G54C1_SHIFT)) & sig3_VEC2CL1_Px0G54C1_MASK)

#define sig3_VEC2CL1_Px0R54C1_MASK               (0x30U)
#define sig3_VEC2CL1_Px0R54C1_SHIFT              (4U)
/*! Px0R54C1 - Pix0_R54_Cluster1 */
#define sig3_VEC2CL1_Px0R54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px0R54C1_SHIFT)) & sig3_VEC2CL1_Px0R54C1_MASK)

#define sig3_VEC2CL1_Px1B54C1_MASK               (0xC0U)
#define sig3_VEC2CL1_Px1B54C1_SHIFT              (6U)
/*! Px1B54C1 - Pix1_B54_Cluster1 */
#define sig3_VEC2CL1_Px1B54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px1B54C1_SHIFT)) & sig3_VEC2CL1_Px1B54C1_MASK)

#define sig3_VEC2CL1_Px1G54C1_MASK               (0x300U)
#define sig3_VEC2CL1_Px1G54C1_SHIFT              (8U)
/*! Px1G54C1 - Pix1_G54_Cluster1 */
#define sig3_VEC2CL1_Px1G54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px1G54C1_SHIFT)) & sig3_VEC2CL1_Px1G54C1_MASK)

#define sig3_VEC2CL1_Px1R54C1_MASK               (0xC00U)
#define sig3_VEC2CL1_Px1R54C1_SHIFT              (10U)
/*! Px1R54C1 - Pix1_R54_Cluster1 */
#define sig3_VEC2CL1_Px1R54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px1R54C1_SHIFT)) & sig3_VEC2CL1_Px1R54C1_MASK)

#define sig3_VEC2CL1_Px2B54C1_MASK               (0x3000U)
#define sig3_VEC2CL1_Px2B54C1_SHIFT              (12U)
/*! Px2B54C1 - Pix2_B54_Cluster1 */
#define sig3_VEC2CL1_Px2B54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px2B54C1_SHIFT)) & sig3_VEC2CL1_Px2B54C1_MASK)

#define sig3_VEC2CL1_Px2G54C1_MASK               (0xC000U)
#define sig3_VEC2CL1_Px2G54C1_SHIFT              (14U)
/*! Px2G54C1 - Pix2_G54_Cluster1 */
#define sig3_VEC2CL1_Px2G54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px2G54C1_SHIFT)) & sig3_VEC2CL1_Px2G54C1_MASK)

#define sig3_VEC2CL1_Px2R54C1_MASK               (0x30000U)
#define sig3_VEC2CL1_Px2R54C1_SHIFT              (16U)
/*! Px2R54C1 - Pix2_R54_Cluster1 */
#define sig3_VEC2CL1_Px2R54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px2R54C1_SHIFT)) & sig3_VEC2CL1_Px2R54C1_MASK)

#define sig3_VEC2CL1_Px3B54C1_MASK               (0xC0000U)
#define sig3_VEC2CL1_Px3B54C1_SHIFT              (18U)
/*! Px3B54C1 - Pix3_B54_Cluster1 */
#define sig3_VEC2CL1_Px3B54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px3B54C1_SHIFT)) & sig3_VEC2CL1_Px3B54C1_MASK)

#define sig3_VEC2CL1_Px3G54C1_MASK               (0x300000U)
#define sig3_VEC2CL1_Px3G54C1_SHIFT              (20U)
/*! Px3G54C1 - Pix3_G54_Cluster1 */
#define sig3_VEC2CL1_Px3G54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px3G54C1_SHIFT)) & sig3_VEC2CL1_Px3G54C1_MASK)

#define sig3_VEC2CL1_Px3R54C1_MASK               (0xC00000U)
#define sig3_VEC2CL1_Px3R54C1_SHIFT              (22U)
/*! Px3R54C1 - Pix3_R54_Cluster1 */
#define sig3_VEC2CL1_Px3R54C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL1_Px3R54C1_SHIFT)) & sig3_VEC2CL1_Px3R54C1_MASK)
/*! @} */

/*! @name VEC3CL1 - Vector3_Cluster1 */
/*! @{ */

#define sig3_VEC3CL1_Px0B76C1_MASK               (0x3U)
#define sig3_VEC3CL1_Px0B76C1_SHIFT              (0U)
/*! Px0B76C1 - Pix0_B76_Cluster1 */
#define sig3_VEC3CL1_Px0B76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px0B76C1_SHIFT)) & sig3_VEC3CL1_Px0B76C1_MASK)

#define sig3_VEC3CL1_Px0G76C1_MASK               (0xCU)
#define sig3_VEC3CL1_Px0G76C1_SHIFT              (2U)
/*! Px0G76C1 - Pix0_G76_Cluster1 */
#define sig3_VEC3CL1_Px0G76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px0G76C1_SHIFT)) & sig3_VEC3CL1_Px0G76C1_MASK)

#define sig3_VEC3CL1_Px0R76C1_MASK               (0x30U)
#define sig3_VEC3CL1_Px0R76C1_SHIFT              (4U)
/*! Px0R76C1 - Pix0_R76_Cluster1 */
#define sig3_VEC3CL1_Px0R76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px0R76C1_SHIFT)) & sig3_VEC3CL1_Px0R76C1_MASK)

#define sig3_VEC3CL1_Px1B76C1_MASK               (0xC0U)
#define sig3_VEC3CL1_Px1B76C1_SHIFT              (6U)
/*! Px1B76C1 - Pix1_B76_Cluster1 */
#define sig3_VEC3CL1_Px1B76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px1B76C1_SHIFT)) & sig3_VEC3CL1_Px1B76C1_MASK)

#define sig3_VEC3CL1_Px1G76C1_MASK               (0x300U)
#define sig3_VEC3CL1_Px1G76C1_SHIFT              (8U)
/*! Px1G76C1 - Pix1_G76_Cluster1 */
#define sig3_VEC3CL1_Px1G76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px1G76C1_SHIFT)) & sig3_VEC3CL1_Px1G76C1_MASK)

#define sig3_VEC3CL1_Px1R76C1_MASK               (0xC00U)
#define sig3_VEC3CL1_Px1R76C1_SHIFT              (10U)
/*! Px1R76C1 - Pix1_R76_Cluster1 */
#define sig3_VEC3CL1_Px1R76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px1R76C1_SHIFT)) & sig3_VEC3CL1_Px1R76C1_MASK)

#define sig3_VEC3CL1_Px2B76C1_MASK               (0x3000U)
#define sig3_VEC3CL1_Px2B76C1_SHIFT              (12U)
/*! Px2B76C1 - Pix2_B76_Cluster1 */
#define sig3_VEC3CL1_Px2B76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px2B76C1_SHIFT)) & sig3_VEC3CL1_Px2B76C1_MASK)

#define sig3_VEC3CL1_Px2G76C1_MASK               (0xC000U)
#define sig3_VEC3CL1_Px2G76C1_SHIFT              (14U)
/*! Px2G76C1 - Pix2_G76_Cluster1 */
#define sig3_VEC3CL1_Px2G76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px2G76C1_SHIFT)) & sig3_VEC3CL1_Px2G76C1_MASK)

#define sig3_VEC3CL1_Px2R76C1_MASK               (0x30000U)
#define sig3_VEC3CL1_Px2R76C1_SHIFT              (16U)
/*! Px2R76C1 - Pix2_R76_Cluster1 */
#define sig3_VEC3CL1_Px2R76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px2R76C1_SHIFT)) & sig3_VEC3CL1_Px2R76C1_MASK)

#define sig3_VEC3CL1_Px3B76C1_MASK               (0xC0000U)
#define sig3_VEC3CL1_Px3B76C1_SHIFT              (18U)
/*! Px3B76C1 - Pix3_B76_Cluster1 */
#define sig3_VEC3CL1_Px3B76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px3B76C1_SHIFT)) & sig3_VEC3CL1_Px3B76C1_MASK)

#define sig3_VEC3CL1_Px3G76C1_MASK               (0x300000U)
#define sig3_VEC3CL1_Px3G76C1_SHIFT              (20U)
/*! Px3G76C1 - Pix3_G76_Cluster1 */
#define sig3_VEC3CL1_Px3G76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px3G76C1_SHIFT)) & sig3_VEC3CL1_Px3G76C1_MASK)

#define sig3_VEC3CL1_Px3R76C1_MASK               (0xC00000U)
#define sig3_VEC3CL1_Px3R76C1_SHIFT              (22U)
/*! Px3R76C1 - Pix3_R76_Cluster1 */
#define sig3_VEC3CL1_Px3R76C1(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL1_Px3R76C1_SHIFT)) & sig3_VEC3CL1_Px3R76C1_MASK)
/*! @} */

/*! @name STATUC2 - Status_Cluster2 */
/*! @{ */

#define sig3_STATUC2_Sts00C2_MASK                (0x1U)
#define sig3_STATUC2_Sts00C2_SHIFT               (0U)
/*! Sts00C2 - Sts00_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts00C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts00C2_SHIFT)) & sig3_STATUC2_Sts00C2_MASK)

#define sig3_STATUC2_Sts01C2_MASK                (0x2U)
#define sig3_STATUC2_Sts01C2_SHIFT               (1U)
/*! Sts01C2 - Sts01_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts01C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts01C2_SHIFT)) & sig3_STATUC2_Sts01C2_MASK)

#define sig3_STATUC2_Sts10C2_MASK                (0x4U)
#define sig3_STATUC2_Sts10C2_SHIFT               (2U)
/*! Sts10C2 - Sts10_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts10C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts10C2_SHIFT)) & sig3_STATUC2_Sts10C2_MASK)

#define sig3_STATUC2_Sts11C2_MASK                (0x8U)
#define sig3_STATUC2_Sts11C2_SHIFT               (3U)
/*! Sts11C2 - Sts11_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts11C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts11C2_SHIFT)) & sig3_STATUC2_Sts11C2_MASK)

#define sig3_STATUC2_Sts20C2_MASK                (0x10U)
#define sig3_STATUC2_Sts20C2_SHIFT               (4U)
/*! Sts20C2 - Sts20_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts20C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts20C2_SHIFT)) & sig3_STATUC2_Sts20C2_MASK)

#define sig3_STATUC2_Sts21C2_MASK                (0x20U)
#define sig3_STATUC2_Sts21C2_SHIFT               (5U)
/*! Sts21C2 - Sts21_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts21C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts21C2_SHIFT)) & sig3_STATUC2_Sts21C2_MASK)

#define sig3_STATUC2_Sts30C2_MASK                (0x40U)
#define sig3_STATUC2_Sts30C2_SHIFT               (6U)
/*! Sts30C2 - Sts30_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts30C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts30C2_SHIFT)) & sig3_STATUC2_Sts30C2_MASK)

#define sig3_STATUC2_Sts31C2_MASK                (0x80U)
#define sig3_STATUC2_Sts31C2_SHIFT               (7U)
/*! Sts31C2 - Sts31_Cluster2
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC2_Sts31C2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC2_Sts31C2_SHIFT)) & sig3_STATUC2_Sts31C2_MASK)
/*! @} */

/*! @name COUNTC2 - Counter_Cluster2 */
/*! @{ */

#define sig3_COUNTC2_MatCtC2_MASK                (0xFFU)
#define sig3_COUNTC2_MatCtC2_SHIFT               (0U)
/*! MatCtC2 - MatchCount_Cluster2 */
#define sig3_COUNTC2_MatCtC2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC2_MatCtC2_SHIFT)) & sig3_COUNTC2_MatCtC2_MASK)

#define sig3_COUNTC2_ErCClu2_MASK                (0xFF0000U)
#define sig3_COUNTC2_ErCClu2_SHIFT               (16U)
/*! ErCClu2 - ErrorCount_Cluster2 */
#define sig3_COUNTC2_ErCClu2(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC2_ErCClu2_SHIFT)) & sig3_COUNTC2_ErCClu2_MASK)
/*! @} */

/*! @name VEC0CL2 - Vector0_Cluster2 */
/*! @{ */

#define sig3_VEC0CL2_Px0B10C2_MASK               (0x3U)
#define sig3_VEC0CL2_Px0B10C2_SHIFT              (0U)
/*! Px0B10C2 - Pix0_B10_Cluster2 */
#define sig3_VEC0CL2_Px0B10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px0B10C2_SHIFT)) & sig3_VEC0CL2_Px0B10C2_MASK)

#define sig3_VEC0CL2_Px0G10C2_MASK               (0xCU)
#define sig3_VEC0CL2_Px0G10C2_SHIFT              (2U)
/*! Px0G10C2 - Pix0_G10_Cluster2 */
#define sig3_VEC0CL2_Px0G10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px0G10C2_SHIFT)) & sig3_VEC0CL2_Px0G10C2_MASK)

#define sig3_VEC0CL2_Px0R10C2_MASK               (0x30U)
#define sig3_VEC0CL2_Px0R10C2_SHIFT              (4U)
/*! Px0R10C2 - Pix0_R10_Cluster2 */
#define sig3_VEC0CL2_Px0R10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px0R10C2_SHIFT)) & sig3_VEC0CL2_Px0R10C2_MASK)

#define sig3_VEC0CL2_Px1B10C2_MASK               (0xC0U)
#define sig3_VEC0CL2_Px1B10C2_SHIFT              (6U)
/*! Px1B10C2 - Pix1_B10_Cluster2 */
#define sig3_VEC0CL2_Px1B10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px1B10C2_SHIFT)) & sig3_VEC0CL2_Px1B10C2_MASK)

#define sig3_VEC0CL2_Px1G10C2_MASK               (0x300U)
#define sig3_VEC0CL2_Px1G10C2_SHIFT              (8U)
/*! Px1G10C2 - Pix1_G10_Cluster2 */
#define sig3_VEC0CL2_Px1G10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px1G10C2_SHIFT)) & sig3_VEC0CL2_Px1G10C2_MASK)

#define sig3_VEC0CL2_Px1R10C2_MASK               (0xC00U)
#define sig3_VEC0CL2_Px1R10C2_SHIFT              (10U)
/*! Px1R10C2 - Pix1_R10_Cluster2 */
#define sig3_VEC0CL2_Px1R10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px1R10C2_SHIFT)) & sig3_VEC0CL2_Px1R10C2_MASK)

#define sig3_VEC0CL2_Px2B10C2_MASK               (0x3000U)
#define sig3_VEC0CL2_Px2B10C2_SHIFT              (12U)
/*! Px2B10C2 - Pix2_B10_Cluster2 */
#define sig3_VEC0CL2_Px2B10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px2B10C2_SHIFT)) & sig3_VEC0CL2_Px2B10C2_MASK)

#define sig3_VEC0CL2_Px2G10C2_MASK               (0xC000U)
#define sig3_VEC0CL2_Px2G10C2_SHIFT              (14U)
/*! Px2G10C2 - Pix2_G10_Cluster2 */
#define sig3_VEC0CL2_Px2G10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px2G10C2_SHIFT)) & sig3_VEC0CL2_Px2G10C2_MASK)

#define sig3_VEC0CL2_Px2R10C2_MASK               (0x30000U)
#define sig3_VEC0CL2_Px2R10C2_SHIFT              (16U)
/*! Px2R10C2 - Pix2_R10_Cluster2 */
#define sig3_VEC0CL2_Px2R10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px2R10C2_SHIFT)) & sig3_VEC0CL2_Px2R10C2_MASK)

#define sig3_VEC0CL2_Px3B10C2_MASK               (0xC0000U)
#define sig3_VEC0CL2_Px3B10C2_SHIFT              (18U)
/*! Px3B10C2 - Pix3_B10_Cluster2 */
#define sig3_VEC0CL2_Px3B10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px3B10C2_SHIFT)) & sig3_VEC0CL2_Px3B10C2_MASK)

#define sig3_VEC0CL2_Px3G10C2_MASK               (0x300000U)
#define sig3_VEC0CL2_Px3G10C2_SHIFT              (20U)
/*! Px3G10C2 - Pix3_G10_Cluster2 */
#define sig3_VEC0CL2_Px3G10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px3G10C2_SHIFT)) & sig3_VEC0CL2_Px3G10C2_MASK)

#define sig3_VEC0CL2_Px3R10C2_MASK               (0xC00000U)
#define sig3_VEC0CL2_Px3R10C2_SHIFT              (22U)
/*! Px3R10C2 - Pix3_R10_Cluster2 */
#define sig3_VEC0CL2_Px3R10C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL2_Px3R10C2_SHIFT)) & sig3_VEC0CL2_Px3R10C2_MASK)
/*! @} */

/*! @name VEC1CL2 - Vector1_Cluster2 */
/*! @{ */

#define sig3_VEC1CL2_Px0B32C2_MASK               (0x3U)
#define sig3_VEC1CL2_Px0B32C2_SHIFT              (0U)
/*! Px0B32C2 - Pix0_B32_Cluster2 */
#define sig3_VEC1CL2_Px0B32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px0B32C2_SHIFT)) & sig3_VEC1CL2_Px0B32C2_MASK)

#define sig3_VEC1CL2_Px0G32C2_MASK               (0xCU)
#define sig3_VEC1CL2_Px0G32C2_SHIFT              (2U)
/*! Px0G32C2 - Pix0_G32_Cluster2 */
#define sig3_VEC1CL2_Px0G32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px0G32C2_SHIFT)) & sig3_VEC1CL2_Px0G32C2_MASK)

#define sig3_VEC1CL2_Px0R32C2_MASK               (0x30U)
#define sig3_VEC1CL2_Px0R32C2_SHIFT              (4U)
/*! Px0R32C2 - Pix0_R32_Cluster2 */
#define sig3_VEC1CL2_Px0R32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px0R32C2_SHIFT)) & sig3_VEC1CL2_Px0R32C2_MASK)

#define sig3_VEC1CL2_Px1B32C2_MASK               (0xC0U)
#define sig3_VEC1CL2_Px1B32C2_SHIFT              (6U)
/*! Px1B32C2 - Pix1_B32_Cluster2 */
#define sig3_VEC1CL2_Px1B32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px1B32C2_SHIFT)) & sig3_VEC1CL2_Px1B32C2_MASK)

#define sig3_VEC1CL2_Px1G32C2_MASK               (0x300U)
#define sig3_VEC1CL2_Px1G32C2_SHIFT              (8U)
/*! Px1G32C2 - Pix1_G32_Cluster2 */
#define sig3_VEC1CL2_Px1G32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px1G32C2_SHIFT)) & sig3_VEC1CL2_Px1G32C2_MASK)

#define sig3_VEC1CL2_Px1R32C2_MASK               (0xC00U)
#define sig3_VEC1CL2_Px1R32C2_SHIFT              (10U)
/*! Px1R32C2 - Pix1_R32_Cluster2 */
#define sig3_VEC1CL2_Px1R32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px1R32C2_SHIFT)) & sig3_VEC1CL2_Px1R32C2_MASK)

#define sig3_VEC1CL2_Px2B32C2_MASK               (0x3000U)
#define sig3_VEC1CL2_Px2B32C2_SHIFT              (12U)
/*! Px2B32C2 - Pix2_B32_Cluster2 */
#define sig3_VEC1CL2_Px2B32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px2B32C2_SHIFT)) & sig3_VEC1CL2_Px2B32C2_MASK)

#define sig3_VEC1CL2_Px2G32C2_MASK               (0xC000U)
#define sig3_VEC1CL2_Px2G32C2_SHIFT              (14U)
/*! Px2G32C2 - Pix2_G32_Cluster2 */
#define sig3_VEC1CL2_Px2G32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px2G32C2_SHIFT)) & sig3_VEC1CL2_Px2G32C2_MASK)

#define sig3_VEC1CL2_Px2R32C2_MASK               (0x30000U)
#define sig3_VEC1CL2_Px2R32C2_SHIFT              (16U)
/*! Px2R32C2 - Pix2_R32_Cluster2 */
#define sig3_VEC1CL2_Px2R32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px2R32C2_SHIFT)) & sig3_VEC1CL2_Px2R32C2_MASK)

#define sig3_VEC1CL2_Px3B32C2_MASK               (0xC0000U)
#define sig3_VEC1CL2_Px3B32C2_SHIFT              (18U)
/*! Px3B32C2 - Pix3_B32_Cluster2 */
#define sig3_VEC1CL2_Px3B32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px3B32C2_SHIFT)) & sig3_VEC1CL2_Px3B32C2_MASK)

#define sig3_VEC1CL2_Px3G32C2_MASK               (0x300000U)
#define sig3_VEC1CL2_Px3G32C2_SHIFT              (20U)
/*! Px3G32C2 - Pix3_G32_Cluster2 */
#define sig3_VEC1CL2_Px3G32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px3G32C2_SHIFT)) & sig3_VEC1CL2_Px3G32C2_MASK)

#define sig3_VEC1CL2_Px3R32C2_MASK               (0xC00000U)
#define sig3_VEC1CL2_Px3R32C2_SHIFT              (22U)
/*! Px3R32C2 - Pix3_R32_Cluster2 */
#define sig3_VEC1CL2_Px3R32C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL2_Px3R32C2_SHIFT)) & sig3_VEC1CL2_Px3R32C2_MASK)
/*! @} */

/*! @name VEC2CL2 - Vector2_Cluster2 */
/*! @{ */

#define sig3_VEC2CL2_Px0B54C2_MASK               (0x3U)
#define sig3_VEC2CL2_Px0B54C2_SHIFT              (0U)
/*! Px0B54C2 - Pix0_B54_Cluster2 */
#define sig3_VEC2CL2_Px0B54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px0B54C2_SHIFT)) & sig3_VEC2CL2_Px0B54C2_MASK)

#define sig3_VEC2CL2_Px0G54C2_MASK               (0xCU)
#define sig3_VEC2CL2_Px0G54C2_SHIFT              (2U)
/*! Px0G54C2 - Pix0_G54_Cluster2 */
#define sig3_VEC2CL2_Px0G54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px0G54C2_SHIFT)) & sig3_VEC2CL2_Px0G54C2_MASK)

#define sig3_VEC2CL2_Px0R54C2_MASK               (0x30U)
#define sig3_VEC2CL2_Px0R54C2_SHIFT              (4U)
/*! Px0R54C2 - Pix0_R54_Cluster2 */
#define sig3_VEC2CL2_Px0R54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px0R54C2_SHIFT)) & sig3_VEC2CL2_Px0R54C2_MASK)

#define sig3_VEC2CL2_Px1B54C2_MASK               (0xC0U)
#define sig3_VEC2CL2_Px1B54C2_SHIFT              (6U)
/*! Px1B54C2 - Pix1_B54_Cluster2 */
#define sig3_VEC2CL2_Px1B54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px1B54C2_SHIFT)) & sig3_VEC2CL2_Px1B54C2_MASK)

#define sig3_VEC2CL2_Px1G54C2_MASK               (0x300U)
#define sig3_VEC2CL2_Px1G54C2_SHIFT              (8U)
/*! Px1G54C2 - Pix1_G54_Cluster2 */
#define sig3_VEC2CL2_Px1G54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px1G54C2_SHIFT)) & sig3_VEC2CL2_Px1G54C2_MASK)

#define sig3_VEC2CL2_Px1R54C2_MASK               (0xC00U)
#define sig3_VEC2CL2_Px1R54C2_SHIFT              (10U)
/*! Px1R54C2 - Pix1_R54_Cluster2 */
#define sig3_VEC2CL2_Px1R54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px1R54C2_SHIFT)) & sig3_VEC2CL2_Px1R54C2_MASK)

#define sig3_VEC2CL2_Px2B54C2_MASK               (0x3000U)
#define sig3_VEC2CL2_Px2B54C2_SHIFT              (12U)
/*! Px2B54C2 - Pix2_B54_Cluster2 */
#define sig3_VEC2CL2_Px2B54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px2B54C2_SHIFT)) & sig3_VEC2CL2_Px2B54C2_MASK)

#define sig3_VEC2CL2_Px2G54C2_MASK               (0xC000U)
#define sig3_VEC2CL2_Px2G54C2_SHIFT              (14U)
/*! Px2G54C2 - Pix2_G54_Cluster2 */
#define sig3_VEC2CL2_Px2G54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px2G54C2_SHIFT)) & sig3_VEC2CL2_Px2G54C2_MASK)

#define sig3_VEC2CL2_Px2R54C2_MASK               (0x30000U)
#define sig3_VEC2CL2_Px2R54C2_SHIFT              (16U)
/*! Px2R54C2 - Pix2_R54_Cluster2 */
#define sig3_VEC2CL2_Px2R54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px2R54C2_SHIFT)) & sig3_VEC2CL2_Px2R54C2_MASK)

#define sig3_VEC2CL2_Px3B54C2_MASK               (0xC0000U)
#define sig3_VEC2CL2_Px3B54C2_SHIFT              (18U)
/*! Px3B54C2 - Pix3_B54_Cluster2 */
#define sig3_VEC2CL2_Px3B54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px3B54C2_SHIFT)) & sig3_VEC2CL2_Px3B54C2_MASK)

#define sig3_VEC2CL2_Px3G54C2_MASK               (0x300000U)
#define sig3_VEC2CL2_Px3G54C2_SHIFT              (20U)
/*! Px3G54C2 - Pix3_G54_Cluster2 */
#define sig3_VEC2CL2_Px3G54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px3G54C2_SHIFT)) & sig3_VEC2CL2_Px3G54C2_MASK)

#define sig3_VEC2CL2_Px3R54C2_MASK               (0xC00000U)
#define sig3_VEC2CL2_Px3R54C2_SHIFT              (22U)
/*! Px3R54C2 - Pix3_R54_Cluster2 */
#define sig3_VEC2CL2_Px3R54C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL2_Px3R54C2_SHIFT)) & sig3_VEC2CL2_Px3R54C2_MASK)
/*! @} */

/*! @name VEC3CL2 - Vector3_Cluster2 */
/*! @{ */

#define sig3_VEC3CL2_Px0B76C2_MASK               (0x3U)
#define sig3_VEC3CL2_Px0B76C2_SHIFT              (0U)
/*! Px0B76C2 - Pix0_B76_Cluster2 */
#define sig3_VEC3CL2_Px0B76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px0B76C2_SHIFT)) & sig3_VEC3CL2_Px0B76C2_MASK)

#define sig3_VEC3CL2_Px0G76C2_MASK               (0xCU)
#define sig3_VEC3CL2_Px0G76C2_SHIFT              (2U)
/*! Px0G76C2 - Pix0_G76_Cluster2 */
#define sig3_VEC3CL2_Px0G76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px0G76C2_SHIFT)) & sig3_VEC3CL2_Px0G76C2_MASK)

#define sig3_VEC3CL2_Px0R76C2_MASK               (0x30U)
#define sig3_VEC3CL2_Px0R76C2_SHIFT              (4U)
/*! Px0R76C2 - Pix0_R76_Cluster2 */
#define sig3_VEC3CL2_Px0R76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px0R76C2_SHIFT)) & sig3_VEC3CL2_Px0R76C2_MASK)

#define sig3_VEC3CL2_Px1B76C2_MASK               (0xC0U)
#define sig3_VEC3CL2_Px1B76C2_SHIFT              (6U)
/*! Px1B76C2 - Pix1_B76_Cluster2 */
#define sig3_VEC3CL2_Px1B76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px1B76C2_SHIFT)) & sig3_VEC3CL2_Px1B76C2_MASK)

#define sig3_VEC3CL2_Px1G76C2_MASK               (0x300U)
#define sig3_VEC3CL2_Px1G76C2_SHIFT              (8U)
/*! Px1G76C2 - Pix1_G76_Cluster2 */
#define sig3_VEC3CL2_Px1G76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px1G76C2_SHIFT)) & sig3_VEC3CL2_Px1G76C2_MASK)

#define sig3_VEC3CL2_Px1R76C2_MASK               (0xC00U)
#define sig3_VEC3CL2_Px1R76C2_SHIFT              (10U)
/*! Px1R76C2 - Pix1_R76_Cluster2 */
#define sig3_VEC3CL2_Px1R76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px1R76C2_SHIFT)) & sig3_VEC3CL2_Px1R76C2_MASK)

#define sig3_VEC3CL2_Px2B76C2_MASK               (0x3000U)
#define sig3_VEC3CL2_Px2B76C2_SHIFT              (12U)
/*! Px2B76C2 - Pix2_B76_Cluster2 */
#define sig3_VEC3CL2_Px2B76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px2B76C2_SHIFT)) & sig3_VEC3CL2_Px2B76C2_MASK)

#define sig3_VEC3CL2_Px2G76C2_MASK               (0xC000U)
#define sig3_VEC3CL2_Px2G76C2_SHIFT              (14U)
/*! Px2G76C2 - Pix2_G76_Cluster2 */
#define sig3_VEC3CL2_Px2G76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px2G76C2_SHIFT)) & sig3_VEC3CL2_Px2G76C2_MASK)

#define sig3_VEC3CL2_Px2R76C2_MASK               (0x30000U)
#define sig3_VEC3CL2_Px2R76C2_SHIFT              (16U)
/*! Px2R76C2 - Pix2_R76_Cluster2 */
#define sig3_VEC3CL2_Px2R76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px2R76C2_SHIFT)) & sig3_VEC3CL2_Px2R76C2_MASK)

#define sig3_VEC3CL2_Px3B76C2_MASK               (0xC0000U)
#define sig3_VEC3CL2_Px3B76C2_SHIFT              (18U)
/*! Px3B76C2 - Pix3_B76_Cluster2 */
#define sig3_VEC3CL2_Px3B76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px3B76C2_SHIFT)) & sig3_VEC3CL2_Px3B76C2_MASK)

#define sig3_VEC3CL2_Px3G76C2_MASK               (0x300000U)
#define sig3_VEC3CL2_Px3G76C2_SHIFT              (20U)
/*! Px3G76C2 - Pix3_G76_Cluster2 */
#define sig3_VEC3CL2_Px3G76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px3G76C2_SHIFT)) & sig3_VEC3CL2_Px3G76C2_MASK)

#define sig3_VEC3CL2_Px3R76C2_MASK               (0xC00000U)
#define sig3_VEC3CL2_Px3R76C2_SHIFT              (22U)
/*! Px3R76C2 - Pix3_R76_Cluster2 */
#define sig3_VEC3CL2_Px3R76C2(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL2_Px3R76C2_SHIFT)) & sig3_VEC3CL2_Px3R76C2_MASK)
/*! @} */

/*! @name STATUC3 - Status_Cluster3 */
/*! @{ */

#define sig3_STATUC3_Sts00C3_MASK                (0x1U)
#define sig3_STATUC3_Sts00C3_SHIFT               (0U)
/*! Sts00C3 - Sts00_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts00C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts00C3_SHIFT)) & sig3_STATUC3_Sts00C3_MASK)

#define sig3_STATUC3_Sts01C3_MASK                (0x2U)
#define sig3_STATUC3_Sts01C3_SHIFT               (1U)
/*! Sts01C3 - Sts01_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts01C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts01C3_SHIFT)) & sig3_STATUC3_Sts01C3_MASK)

#define sig3_STATUC3_Sts10C3_MASK                (0x4U)
#define sig3_STATUC3_Sts10C3_SHIFT               (2U)
/*! Sts10C3 - Sts10_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts10C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts10C3_SHIFT)) & sig3_STATUC3_Sts10C3_MASK)

#define sig3_STATUC3_Sts11C3_MASK                (0x8U)
#define sig3_STATUC3_Sts11C3_SHIFT               (3U)
/*! Sts11C3 - Sts11_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts11C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts11C3_SHIFT)) & sig3_STATUC3_Sts11C3_MASK)

#define sig3_STATUC3_Sts20C3_MASK                (0x10U)
#define sig3_STATUC3_Sts20C3_SHIFT               (4U)
/*! Sts20C3 - Sts20_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts20C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts20C3_SHIFT)) & sig3_STATUC3_Sts20C3_MASK)

#define sig3_STATUC3_Sts21C3_MASK                (0x20U)
#define sig3_STATUC3_Sts21C3_SHIFT               (5U)
/*! Sts21C3 - Sts21_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts21C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts21C3_SHIFT)) & sig3_STATUC3_Sts21C3_MASK)

#define sig3_STATUC3_Sts30C3_MASK                (0x40U)
#define sig3_STATUC3_Sts30C3_SHIFT               (6U)
/*! Sts30C3 - Sts30_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts30C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts30C3_SHIFT)) & sig3_STATUC3_Sts30C3_MASK)

#define sig3_STATUC3_Sts31C3_MASK                (0x80U)
#define sig3_STATUC3_Sts31C3_SHIFT               (7U)
/*! Sts31C3 - Sts31_Cluster3
 *  0b0..Measurement value and reference are equal
 *  0b1..Measurement value and reference are not equal
 */
#define sig3_STATUC3_Sts31C3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_STATUC3_Sts31C3_SHIFT)) & sig3_STATUC3_Sts31C3_MASK)
/*! @} */

/*! @name COUNTC3 - Counter_Cluster3 */
/*! @{ */

#define sig3_COUNTC3_MatCtC3_MASK                (0xFFU)
#define sig3_COUNTC3_MatCtC3_SHIFT               (0U)
/*! MatCtC3 - MatchCount_Cluster3 */
#define sig3_COUNTC3_MatCtC3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC3_MatCtC3_SHIFT)) & sig3_COUNTC3_MatCtC3_MASK)

#define sig3_COUNTC3_ErCClu3_MASK                (0xFF0000U)
#define sig3_COUNTC3_ErCClu3_SHIFT               (16U)
/*! ErCClu3 - ErrorCount_Cluster3 */
#define sig3_COUNTC3_ErCClu3(x)                  (((uint32_t)(((uint32_t)(x)) << sig3_COUNTC3_ErCClu3_SHIFT)) & sig3_COUNTC3_ErCClu3_MASK)
/*! @} */

/*! @name VEC0CL3 - Vector0_Cluster3 */
/*! @{ */

#define sig3_VEC0CL3_Px0B10C3_MASK               (0x3U)
#define sig3_VEC0CL3_Px0B10C3_SHIFT              (0U)
/*! Px0B10C3 - Pix0_B10_Cluster3 */
#define sig3_VEC0CL3_Px0B10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px0B10C3_SHIFT)) & sig3_VEC0CL3_Px0B10C3_MASK)

#define sig3_VEC0CL3_Px0G10C3_MASK               (0xCU)
#define sig3_VEC0CL3_Px0G10C3_SHIFT              (2U)
/*! Px0G10C3 - Pix0_G10_Cluster3 */
#define sig3_VEC0CL3_Px0G10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px0G10C3_SHIFT)) & sig3_VEC0CL3_Px0G10C3_MASK)

#define sig3_VEC0CL3_Px0R10C3_MASK               (0x30U)
#define sig3_VEC0CL3_Px0R10C3_SHIFT              (4U)
/*! Px0R10C3 - Pix0_R10_Cluster3 */
#define sig3_VEC0CL3_Px0R10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px0R10C3_SHIFT)) & sig3_VEC0CL3_Px0R10C3_MASK)

#define sig3_VEC0CL3_Px1B10C3_MASK               (0xC0U)
#define sig3_VEC0CL3_Px1B10C3_SHIFT              (6U)
/*! Px1B10C3 - Pix1_B10_Cluster3 */
#define sig3_VEC0CL3_Px1B10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px1B10C3_SHIFT)) & sig3_VEC0CL3_Px1B10C3_MASK)

#define sig3_VEC0CL3_Px1G10C3_MASK               (0x300U)
#define sig3_VEC0CL3_Px1G10C3_SHIFT              (8U)
/*! Px1G10C3 - Pix1_G10_Cluster3 */
#define sig3_VEC0CL3_Px1G10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px1G10C3_SHIFT)) & sig3_VEC0CL3_Px1G10C3_MASK)

#define sig3_VEC0CL3_Px1R10C3_MASK               (0xC00U)
#define sig3_VEC0CL3_Px1R10C3_SHIFT              (10U)
/*! Px1R10C3 - Pix1_R10_Cluster3 */
#define sig3_VEC0CL3_Px1R10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px1R10C3_SHIFT)) & sig3_VEC0CL3_Px1R10C3_MASK)

#define sig3_VEC0CL3_Px2B10C3_MASK               (0x3000U)
#define sig3_VEC0CL3_Px2B10C3_SHIFT              (12U)
/*! Px2B10C3 - Pix2_B10_Cluster3 */
#define sig3_VEC0CL3_Px2B10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px2B10C3_SHIFT)) & sig3_VEC0CL3_Px2B10C3_MASK)

#define sig3_VEC0CL3_Px2G10C3_MASK               (0xC000U)
#define sig3_VEC0CL3_Px2G10C3_SHIFT              (14U)
/*! Px2G10C3 - Pix2_G10_Cluster3 */
#define sig3_VEC0CL3_Px2G10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px2G10C3_SHIFT)) & sig3_VEC0CL3_Px2G10C3_MASK)

#define sig3_VEC0CL3_Px2R10C3_MASK               (0x30000U)
#define sig3_VEC0CL3_Px2R10C3_SHIFT              (16U)
/*! Px2R10C3 - Pix2_R10_Cluster3 */
#define sig3_VEC0CL3_Px2R10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px2R10C3_SHIFT)) & sig3_VEC0CL3_Px2R10C3_MASK)

#define sig3_VEC0CL3_Px3B10C3_MASK               (0xC0000U)
#define sig3_VEC0CL3_Px3B10C3_SHIFT              (18U)
/*! Px3B10C3 - Pix3_B10_Cluster3 */
#define sig3_VEC0CL3_Px3B10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px3B10C3_SHIFT)) & sig3_VEC0CL3_Px3B10C3_MASK)

#define sig3_VEC0CL3_Px3G10C3_MASK               (0x300000U)
#define sig3_VEC0CL3_Px3G10C3_SHIFT              (20U)
/*! Px3G10C3 - Pix3_G10_Cluster3 */
#define sig3_VEC0CL3_Px3G10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px3G10C3_SHIFT)) & sig3_VEC0CL3_Px3G10C3_MASK)

#define sig3_VEC0CL3_Px3R10C3_MASK               (0xC00000U)
#define sig3_VEC0CL3_Px3R10C3_SHIFT              (22U)
/*! Px3R10C3 - Pix3_R10_Cluster3 */
#define sig3_VEC0CL3_Px3R10C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC0CL3_Px3R10C3_SHIFT)) & sig3_VEC0CL3_Px3R10C3_MASK)
/*! @} */

/*! @name VEC1CL3 - Vector1_Cluster3 */
/*! @{ */

#define sig3_VEC1CL3_Px0B32C3_MASK               (0x3U)
#define sig3_VEC1CL3_Px0B32C3_SHIFT              (0U)
/*! Px0B32C3 - Pix0_B32_Cluster3 */
#define sig3_VEC1CL3_Px0B32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px0B32C3_SHIFT)) & sig3_VEC1CL3_Px0B32C3_MASK)

#define sig3_VEC1CL3_Px0G32C3_MASK               (0xCU)
#define sig3_VEC1CL3_Px0G32C3_SHIFT              (2U)
/*! Px0G32C3 - Pix0_G32_Cluster3 */
#define sig3_VEC1CL3_Px0G32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px0G32C3_SHIFT)) & sig3_VEC1CL3_Px0G32C3_MASK)

#define sig3_VEC1CL3_Px0R32C3_MASK               (0x30U)
#define sig3_VEC1CL3_Px0R32C3_SHIFT              (4U)
/*! Px0R32C3 - Pix0_R32_Cluster3 */
#define sig3_VEC1CL3_Px0R32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px0R32C3_SHIFT)) & sig3_VEC1CL3_Px0R32C3_MASK)

#define sig3_VEC1CL3_Px1B32C3_MASK               (0xC0U)
#define sig3_VEC1CL3_Px1B32C3_SHIFT              (6U)
/*! Px1B32C3 - Pix1_B32_Cluster3 */
#define sig3_VEC1CL3_Px1B32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px1B32C3_SHIFT)) & sig3_VEC1CL3_Px1B32C3_MASK)

#define sig3_VEC1CL3_Px1G32C3_MASK               (0x300U)
#define sig3_VEC1CL3_Px1G32C3_SHIFT              (8U)
/*! Px1G32C3 - Pix1_G32_Cluster3 */
#define sig3_VEC1CL3_Px1G32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px1G32C3_SHIFT)) & sig3_VEC1CL3_Px1G32C3_MASK)

#define sig3_VEC1CL3_Px1R32C3_MASK               (0xC00U)
#define sig3_VEC1CL3_Px1R32C3_SHIFT              (10U)
/*! Px1R32C3 - Pix1_R32_Cluster3 */
#define sig3_VEC1CL3_Px1R32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px1R32C3_SHIFT)) & sig3_VEC1CL3_Px1R32C3_MASK)

#define sig3_VEC1CL3_Px2B32C3_MASK               (0x3000U)
#define sig3_VEC1CL3_Px2B32C3_SHIFT              (12U)
/*! Px2B32C3 - Pix2_B32_Cluster3 */
#define sig3_VEC1CL3_Px2B32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px2B32C3_SHIFT)) & sig3_VEC1CL3_Px2B32C3_MASK)

#define sig3_VEC1CL3_Px2G32C3_MASK               (0xC000U)
#define sig3_VEC1CL3_Px2G32C3_SHIFT              (14U)
/*! Px2G32C3 - Pix2_G32_Cluster3 */
#define sig3_VEC1CL3_Px2G32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px2G32C3_SHIFT)) & sig3_VEC1CL3_Px2G32C3_MASK)

#define sig3_VEC1CL3_Px2R32C3_MASK               (0x30000U)
#define sig3_VEC1CL3_Px2R32C3_SHIFT              (16U)
/*! Px2R32C3 - Pix2_R32_Cluster3 */
#define sig3_VEC1CL3_Px2R32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px2R32C3_SHIFT)) & sig3_VEC1CL3_Px2R32C3_MASK)

#define sig3_VEC1CL3_Px3B32C3_MASK               (0xC0000U)
#define sig3_VEC1CL3_Px3B32C3_SHIFT              (18U)
/*! Px3B32C3 - Pix3_B32_Cluster3 */
#define sig3_VEC1CL3_Px3B32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px3B32C3_SHIFT)) & sig3_VEC1CL3_Px3B32C3_MASK)

#define sig3_VEC1CL3_Px3G32C3_MASK               (0x300000U)
#define sig3_VEC1CL3_Px3G32C3_SHIFT              (20U)
/*! Px3G32C3 - Pix3_G32_Cluster3 */
#define sig3_VEC1CL3_Px3G32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px3G32C3_SHIFT)) & sig3_VEC1CL3_Px3G32C3_MASK)

#define sig3_VEC1CL3_Px3R32C3_MASK               (0xC00000U)
#define sig3_VEC1CL3_Px3R32C3_SHIFT              (22U)
/*! Px3R32C3 - Pix3_R32_Cluster3 */
#define sig3_VEC1CL3_Px3R32C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC1CL3_Px3R32C3_SHIFT)) & sig3_VEC1CL3_Px3R32C3_MASK)
/*! @} */

/*! @name VEC2CL3 - Vector2_Cluster3 */
/*! @{ */

#define sig3_VEC2CL3_Px0B54C3_MASK               (0x3U)
#define sig3_VEC2CL3_Px0B54C3_SHIFT              (0U)
/*! Px0B54C3 - Pix0_B54_Cluster3 */
#define sig3_VEC2CL3_Px0B54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px0B54C3_SHIFT)) & sig3_VEC2CL3_Px0B54C3_MASK)

#define sig3_VEC2CL3_Px0G54C3_MASK               (0xCU)
#define sig3_VEC2CL3_Px0G54C3_SHIFT              (2U)
/*! Px0G54C3 - Pix0_G54_Cluster3 */
#define sig3_VEC2CL3_Px0G54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px0G54C3_SHIFT)) & sig3_VEC2CL3_Px0G54C3_MASK)

#define sig3_VEC2CL3_Px0R54C3_MASK               (0x30U)
#define sig3_VEC2CL3_Px0R54C3_SHIFT              (4U)
/*! Px0R54C3 - Pix0_R54_Cluster3 */
#define sig3_VEC2CL3_Px0R54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px0R54C3_SHIFT)) & sig3_VEC2CL3_Px0R54C3_MASK)

#define sig3_VEC2CL3_Px1B54C3_MASK               (0xC0U)
#define sig3_VEC2CL3_Px1B54C3_SHIFT              (6U)
/*! Px1B54C3 - Pix1_B54_Cluster3 */
#define sig3_VEC2CL3_Px1B54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px1B54C3_SHIFT)) & sig3_VEC2CL3_Px1B54C3_MASK)

#define sig3_VEC2CL3_Px1G54C3_MASK               (0x300U)
#define sig3_VEC2CL3_Px1G54C3_SHIFT              (8U)
/*! Px1G54C3 - Pix1_G54_Cluster3 */
#define sig3_VEC2CL3_Px1G54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px1G54C3_SHIFT)) & sig3_VEC2CL3_Px1G54C3_MASK)

#define sig3_VEC2CL3_Px1R54C3_MASK               (0xC00U)
#define sig3_VEC2CL3_Px1R54C3_SHIFT              (10U)
/*! Px1R54C3 - Pix1_R54_Cluster3 */
#define sig3_VEC2CL3_Px1R54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px1R54C3_SHIFT)) & sig3_VEC2CL3_Px1R54C3_MASK)

#define sig3_VEC2CL3_Px2B54C3_MASK               (0x3000U)
#define sig3_VEC2CL3_Px2B54C3_SHIFT              (12U)
/*! Px2B54C3 - Pix2_B54_Cluster3 */
#define sig3_VEC2CL3_Px2B54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px2B54C3_SHIFT)) & sig3_VEC2CL3_Px2B54C3_MASK)

#define sig3_VEC2CL3_Px2G54C3_MASK               (0xC000U)
#define sig3_VEC2CL3_Px2G54C3_SHIFT              (14U)
/*! Px2G54C3 - Pix2_G54_Cluster3 */
#define sig3_VEC2CL3_Px2G54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px2G54C3_SHIFT)) & sig3_VEC2CL3_Px2G54C3_MASK)

#define sig3_VEC2CL3_Px2R54C3_MASK               (0x30000U)
#define sig3_VEC2CL3_Px2R54C3_SHIFT              (16U)
/*! Px2R54C3 - Pix2_R54_Cluster3 */
#define sig3_VEC2CL3_Px2R54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px2R54C3_SHIFT)) & sig3_VEC2CL3_Px2R54C3_MASK)

#define sig3_VEC2CL3_Px3B54C3_MASK               (0xC0000U)
#define sig3_VEC2CL3_Px3B54C3_SHIFT              (18U)
/*! Px3B54C3 - Pix3_B54_Cluster3 */
#define sig3_VEC2CL3_Px3B54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px3B54C3_SHIFT)) & sig3_VEC2CL3_Px3B54C3_MASK)

#define sig3_VEC2CL3_Px3G54C3_MASK               (0x300000U)
#define sig3_VEC2CL3_Px3G54C3_SHIFT              (20U)
/*! Px3G54C3 - Pix3_G54_Cluster3 */
#define sig3_VEC2CL3_Px3G54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px3G54C3_SHIFT)) & sig3_VEC2CL3_Px3G54C3_MASK)

#define sig3_VEC2CL3_Px3R54C3_MASK               (0xC00000U)
#define sig3_VEC2CL3_Px3R54C3_SHIFT              (22U)
/*! Px3R54C3 - Pix3_R54_Cluster3 */
#define sig3_VEC2CL3_Px3R54C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC2CL3_Px3R54C3_SHIFT)) & sig3_VEC2CL3_Px3R54C3_MASK)
/*! @} */

/*! @name VEC3CL3 - Vector3_Cluster3 */
/*! @{ */

#define sig3_VEC3CL3_Px0B76C3_MASK               (0x3U)
#define sig3_VEC3CL3_Px0B76C3_SHIFT              (0U)
/*! Px0B76C3 - Pix0_B76_Cluster3 */
#define sig3_VEC3CL3_Px0B76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px0B76C3_SHIFT)) & sig3_VEC3CL3_Px0B76C3_MASK)

#define sig3_VEC3CL3_Px0G76C3_MASK               (0xCU)
#define sig3_VEC3CL3_Px0G76C3_SHIFT              (2U)
/*! Px0G76C3 - Pix0_G76_Cluster3 */
#define sig3_VEC3CL3_Px0G76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px0G76C3_SHIFT)) & sig3_VEC3CL3_Px0G76C3_MASK)

#define sig3_VEC3CL3_Px0R76C3_MASK               (0x30U)
#define sig3_VEC3CL3_Px0R76C3_SHIFT              (4U)
/*! Px0R76C3 - Pix0_R76_Cluster3 */
#define sig3_VEC3CL3_Px0R76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px0R76C3_SHIFT)) & sig3_VEC3CL3_Px0R76C3_MASK)

#define sig3_VEC3CL3_Px1B76C3_MASK               (0xC0U)
#define sig3_VEC3CL3_Px1B76C3_SHIFT              (6U)
/*! Px1B76C3 - Pix1_B76_Cluster3 */
#define sig3_VEC3CL3_Px1B76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px1B76C3_SHIFT)) & sig3_VEC3CL3_Px1B76C3_MASK)

#define sig3_VEC3CL3_Px1G76C3_MASK               (0x300U)
#define sig3_VEC3CL3_Px1G76C3_SHIFT              (8U)
/*! Px1G76C3 - Pix1_G76_Cluster3 */
#define sig3_VEC3CL3_Px1G76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px1G76C3_SHIFT)) & sig3_VEC3CL3_Px1G76C3_MASK)

#define sig3_VEC3CL3_Px1R76C3_MASK               (0xC00U)
#define sig3_VEC3CL3_Px1R76C3_SHIFT              (10U)
/*! Px1R76C3 - Pix1_R76_Cluster3 */
#define sig3_VEC3CL3_Px1R76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px1R76C3_SHIFT)) & sig3_VEC3CL3_Px1R76C3_MASK)

#define sig3_VEC3CL3_Px2B76C3_MASK               (0x3000U)
#define sig3_VEC3CL3_Px2B76C3_SHIFT              (12U)
/*! Px2B76C3 - Pix2_B76_Cluster3 */
#define sig3_VEC3CL3_Px2B76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px2B76C3_SHIFT)) & sig3_VEC3CL3_Px2B76C3_MASK)

#define sig3_VEC3CL3_Px2G76C3_MASK               (0xC000U)
#define sig3_VEC3CL3_Px2G76C3_SHIFT              (14U)
/*! Px2G76C3 - Pix2_G76_Cluster3 */
#define sig3_VEC3CL3_Px2G76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px2G76C3_SHIFT)) & sig3_VEC3CL3_Px2G76C3_MASK)

#define sig3_VEC3CL3_Px2R76C3_MASK               (0x30000U)
#define sig3_VEC3CL3_Px2R76C3_SHIFT              (16U)
/*! Px2R76C3 - Pix2_R76_Cluster3 */
#define sig3_VEC3CL3_Px2R76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px2R76C3_SHIFT)) & sig3_VEC3CL3_Px2R76C3_MASK)

#define sig3_VEC3CL3_Px3B76C3_MASK               (0xC0000U)
#define sig3_VEC3CL3_Px3B76C3_SHIFT              (18U)
/*! Px3B76C3 - Pix3_B76_Cluster3 */
#define sig3_VEC3CL3_Px3B76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px3B76C3_SHIFT)) & sig3_VEC3CL3_Px3B76C3_MASK)

#define sig3_VEC3CL3_Px3G76C3_MASK               (0x300000U)
#define sig3_VEC3CL3_Px3G76C3_SHIFT              (20U)
/*! Px3G76C3 - Pix3_G76_Cluster3 */
#define sig3_VEC3CL3_Px3G76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px3G76C3_SHIFT)) & sig3_VEC3CL3_Px3G76C3_MASK)

#define sig3_VEC3CL3_Px3R76C3_MASK               (0xC00000U)
#define sig3_VEC3CL3_Px3R76C3_SHIFT              (22U)
/*! Px3R76C3 - Pix3_R76_Cluster3 */
#define sig3_VEC3CL3_Px3R76C3(x)                 (((uint32_t)(((uint32_t)(x)) << sig3_VEC3CL3_Px3R76C3_SHIFT)) & sig3_VEC3CL3_Px3R76C3_MASK)
/*! @} */

/*! @name PIXCS0W0 - PixCnt_Stats0_Win0 */
/*! @{ */

#define sig3_PIXCS0W0_PxCnS0W0_MASK              (0xFFFFFFFU)
#define sig3_PIXCS0W0_PxCnS0W0_SHIFT             (0U)
/*! PxCnS0W0 - Px_Cnt_S0_Win0 */
#define sig3_PIXCS0W0_PxCnS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS0W0_PxCnS0W0_SHIFT)) & sig3_PIXCS0W0_PxCnS0W0_MASK)
/*! @} */

/*! @name PIMAS0W0 - PixMax_Stats0_Win0 */
/*! @{ */

#define sig3_PIMAS0W0_BlMaS0W0_MASK              (0xFFU)
#define sig3_PIMAS0W0_BlMaS0W0_SHIFT             (0U)
/*! BlMaS0W0 - Bl_Max_S0_Win0 */
#define sig3_PIMAS0W0_BlMaS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W0_BlMaS0W0_SHIFT)) & sig3_PIMAS0W0_BlMaS0W0_MASK)

#define sig3_PIMAS0W0_GnMaS0W0_MASK              (0xFF00U)
#define sig3_PIMAS0W0_GnMaS0W0_SHIFT             (8U)
/*! GnMaS0W0 - Gn_Max_S0_Win0 */
#define sig3_PIMAS0W0_GnMaS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W0_GnMaS0W0_SHIFT)) & sig3_PIMAS0W0_GnMaS0W0_MASK)

#define sig3_PIMAS0W0_RdMaS0W0_MASK              (0xFF0000U)
#define sig3_PIMAS0W0_RdMaS0W0_SHIFT             (16U)
/*! RdMaS0W0 - Rd_Max_S0_Win0 */
#define sig3_PIMAS0W0_RdMaS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W0_RdMaS0W0_SHIFT)) & sig3_PIMAS0W0_RdMaS0W0_MASK)
/*! @} */

/*! @name PIMIS0W0 - PixMin_Stats0_Win0 */
/*! @{ */

#define sig3_PIMIS0W0_BlMiS0W0_MASK              (0xFFU)
#define sig3_PIMIS0W0_BlMiS0W0_SHIFT             (0U)
/*! BlMiS0W0 - Bl_Min_S0_Win0 */
#define sig3_PIMIS0W0_BlMiS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W0_BlMiS0W0_SHIFT)) & sig3_PIMIS0W0_BlMiS0W0_MASK)

#define sig3_PIMIS0W0_GnMiS0W0_MASK              (0xFF00U)
#define sig3_PIMIS0W0_GnMiS0W0_SHIFT             (8U)
/*! GnMiS0W0 - Gn_Min_S0_Win0 */
#define sig3_PIMIS0W0_GnMiS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W0_GnMiS0W0_SHIFT)) & sig3_PIMIS0W0_GnMiS0W0_MASK)

#define sig3_PIMIS0W0_RdMiS0W0_MASK              (0xFF0000U)
#define sig3_PIMIS0W0_RdMiS0W0_SHIFT             (16U)
/*! RdMiS0W0 - Rd_Min_S0_Win0 */
#define sig3_PIMIS0W0_RdMiS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W0_RdMiS0W0_SHIFT)) & sig3_PIMIS0W0_RdMiS0W0_MASK)
/*! @} */

/*! @name RESUS0W0 - RedSum_Stats0_Win0 */
/*! @{ */

#define sig3_RESUS0W0_RdSuS0W0_MASK              (0xFFFFFFFFU)
#define sig3_RESUS0W0_RdSuS0W0_SHIFT             (0U)
/*! RdSuS0W0 - Rd_Sum_S0_Win0 */
#define sig3_RESUS0W0_RdSuS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS0W0_RdSuS0W0_SHIFT)) & sig3_RESUS0W0_RdSuS0W0_MASK)
/*! @} */

/*! @name GRESS0W0 - GreenSum_Stats0_Win0 */
/*! @{ */

#define sig3_GRESS0W0_GnSuS0W0_MASK              (0xFFFFFFFFU)
#define sig3_GRESS0W0_GnSuS0W0_SHIFT             (0U)
/*! GnSuS0W0 - Gn_Sum_S0_Win0 */
#define sig3_GRESS0W0_GnSuS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS0W0_GnSuS0W0_SHIFT)) & sig3_GRESS0W0_GnSuS0W0_MASK)
/*! @} */

/*! @name BLSUS0W0 - BlueSum_Stats0_Win0 */
/*! @{ */

#define sig3_BLSUS0W0_BlSuS0W0_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS0W0_BlSuS0W0_SHIFT             (0U)
/*! BlSuS0W0 - Bl_Sum_S0_Win0 */
#define sig3_BLSUS0W0_BlSuS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS0W0_BlSuS0W0_SHIFT)) & sig3_BLSUS0W0_BlSuS0W0_MASK)
/*! @} */

/*! @name LUSUS0W0 - LumSum_Stats0_Win0 */
/*! @{ */

#define sig3_LUSUS0W0_LmSmS0W0_MASK              (0xFFFFFFFFU)
#define sig3_LUSUS0W0_LmSmS0W0_SHIFT             (0U)
/*! LmSmS0W0 - Lm_Sum_S0_Win0 */
#define sig3_LUSUS0W0_LmSmS0W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_LUSUS0W0_LmSmS0W0_SHIFT)) & sig3_LUSUS0W0_LmSmS0W0_MASK)
/*! @} */

/*! @name PIXCS1W0 - PixCnt_Stats1_Win0 */
/*! @{ */

#define sig3_PIXCS1W0_PxCnS1W0_MASK              (0xFFFFFFFU)
#define sig3_PIXCS1W0_PxCnS1W0_SHIFT             (0U)
/*! PxCnS1W0 - Px_Cnt_S1_Win0 */
#define sig3_PIXCS1W0_PxCnS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS1W0_PxCnS1W0_SHIFT)) & sig3_PIXCS1W0_PxCnS1W0_MASK)
/*! @} */

/*! @name PIMAS1W0 - PixMax_Stats1_Win0 */
/*! @{ */

#define sig3_PIMAS1W0_BlMaS1W0_MASK              (0xFFU)
#define sig3_PIMAS1W0_BlMaS1W0_SHIFT             (0U)
/*! BlMaS1W0 - Bl_Max_S1_Win0 */
#define sig3_PIMAS1W0_BlMaS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W0_BlMaS1W0_SHIFT)) & sig3_PIMAS1W0_BlMaS1W0_MASK)

#define sig3_PIMAS1W0_GnMaS1W0_MASK              (0xFF00U)
#define sig3_PIMAS1W0_GnMaS1W0_SHIFT             (8U)
/*! GnMaS1W0 - Gn_Max_S1_Win0 */
#define sig3_PIMAS1W0_GnMaS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W0_GnMaS1W0_SHIFT)) & sig3_PIMAS1W0_GnMaS1W0_MASK)

#define sig3_PIMAS1W0_RdMaS1W0_MASK              (0xFF0000U)
#define sig3_PIMAS1W0_RdMaS1W0_SHIFT             (16U)
/*! RdMaS1W0 - Rd_Max_S1_Win0 */
#define sig3_PIMAS1W0_RdMaS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W0_RdMaS1W0_SHIFT)) & sig3_PIMAS1W0_RdMaS1W0_MASK)
/*! @} */

/*! @name PIMIS1W0 - PixMin_Stats1_Win0 */
/*! @{ */

#define sig3_PIMIS1W0_BlMiS1W0_MASK              (0xFFU)
#define sig3_PIMIS1W0_BlMiS1W0_SHIFT             (0U)
/*! BlMiS1W0 - Bl_Min_S1_Win0 */
#define sig3_PIMIS1W0_BlMiS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W0_BlMiS1W0_SHIFT)) & sig3_PIMIS1W0_BlMiS1W0_MASK)

#define sig3_PIMIS1W0_GnMiS1W0_MASK              (0xFF00U)
#define sig3_PIMIS1W0_GnMiS1W0_SHIFT             (8U)
/*! GnMiS1W0 - Gn_Min_S1_Win0 */
#define sig3_PIMIS1W0_GnMiS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W0_GnMiS1W0_SHIFT)) & sig3_PIMIS1W0_GnMiS1W0_MASK)

#define sig3_PIMIS1W0_RdMiS1W0_MASK              (0xFF0000U)
#define sig3_PIMIS1W0_RdMiS1W0_SHIFT             (16U)
/*! RdMiS1W0 - Rd_Min_S1_Win0 */
#define sig3_PIMIS1W0_RdMiS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W0_RdMiS1W0_SHIFT)) & sig3_PIMIS1W0_RdMiS1W0_MASK)
/*! @} */

/*! @name RESUS1W0 - RedSum_Stats1_Win0 */
/*! @{ */

#define sig3_RESUS1W0_RdSuS1W0_MASK              (0xFFFFFFFFU)
#define sig3_RESUS1W0_RdSuS1W0_SHIFT             (0U)
/*! RdSuS1W0 - Rd_Sum_S1_Win0 */
#define sig3_RESUS1W0_RdSuS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS1W0_RdSuS1W0_SHIFT)) & sig3_RESUS1W0_RdSuS1W0_MASK)
/*! @} */

/*! @name GRESS1W0 - GreenSum_Stats1_Win0 */
/*! @{ */

#define sig3_GRESS1W0_GnSuS1W0_MASK              (0xFFFFFFFFU)
#define sig3_GRESS1W0_GnSuS1W0_SHIFT             (0U)
/*! GnSuS1W0 - Gn_Sum_S1_Win0 */
#define sig3_GRESS1W0_GnSuS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS1W0_GnSuS1W0_SHIFT)) & sig3_GRESS1W0_GnSuS1W0_MASK)
/*! @} */

/*! @name BLSUS1W0 - BlueSum_Stats1_Win0 */
/*! @{ */

#define sig3_BLSUS1W0_BlSuS1W0_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS1W0_BlSuS1W0_SHIFT             (0U)
/*! BlSuS1W0 - Bl_Sum_S1_Win0 */
#define sig3_BLSUS1W0_BlSuS1W0(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS1W0_BlSuS1W0_SHIFT)) & sig3_BLSUS1W0_BlSuS1W0_MASK)
/*! @} */

/*! @name PIXCS0W1 - PixCnt_Stats0_Win1 */
/*! @{ */

#define sig3_PIXCS0W1_PxCnS0W1_MASK              (0xFFFFFFFU)
#define sig3_PIXCS0W1_PxCnS0W1_SHIFT             (0U)
/*! PxCnS0W1 - Px_Cnt_S0_Win1 */
#define sig3_PIXCS0W1_PxCnS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS0W1_PxCnS0W1_SHIFT)) & sig3_PIXCS0W1_PxCnS0W1_MASK)
/*! @} */

/*! @name PIMAS0W1 - PixMax_Stats0_Win1 */
/*! @{ */

#define sig3_PIMAS0W1_BlMaS0W1_MASK              (0xFFU)
#define sig3_PIMAS0W1_BlMaS0W1_SHIFT             (0U)
/*! BlMaS0W1 - Bl_Max_S0_Win1 */
#define sig3_PIMAS0W1_BlMaS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W1_BlMaS0W1_SHIFT)) & sig3_PIMAS0W1_BlMaS0W1_MASK)

#define sig3_PIMAS0W1_GnMaS0W1_MASK              (0xFF00U)
#define sig3_PIMAS0W1_GnMaS0W1_SHIFT             (8U)
/*! GnMaS0W1 - Gn_Max_S0_Win1 */
#define sig3_PIMAS0W1_GnMaS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W1_GnMaS0W1_SHIFT)) & sig3_PIMAS0W1_GnMaS0W1_MASK)

#define sig3_PIMAS0W1_RdMaS0W1_MASK              (0xFF0000U)
#define sig3_PIMAS0W1_RdMaS0W1_SHIFT             (16U)
/*! RdMaS0W1 - Rd_Max_S0_Win1 */
#define sig3_PIMAS0W1_RdMaS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W1_RdMaS0W1_SHIFT)) & sig3_PIMAS0W1_RdMaS0W1_MASK)
/*! @} */

/*! @name PIMIS0W1 - PixMin_Stats0_Win1 */
/*! @{ */

#define sig3_PIMIS0W1_BlMiS0W1_MASK              (0xFFU)
#define sig3_PIMIS0W1_BlMiS0W1_SHIFT             (0U)
/*! BlMiS0W1 - Bl_Min_S0_Win1 */
#define sig3_PIMIS0W1_BlMiS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W1_BlMiS0W1_SHIFT)) & sig3_PIMIS0W1_BlMiS0W1_MASK)

#define sig3_PIMIS0W1_GnMiS0W1_MASK              (0xFF00U)
#define sig3_PIMIS0W1_GnMiS0W1_SHIFT             (8U)
/*! GnMiS0W1 - Gn_Min_S0_Win1 */
#define sig3_PIMIS0W1_GnMiS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W1_GnMiS0W1_SHIFT)) & sig3_PIMIS0W1_GnMiS0W1_MASK)

#define sig3_PIMIS0W1_RdMiS0W1_MASK              (0xFF0000U)
#define sig3_PIMIS0W1_RdMiS0W1_SHIFT             (16U)
/*! RdMiS0W1 - Rd_Min_S0_Win1 */
#define sig3_PIMIS0W1_RdMiS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W1_RdMiS0W1_SHIFT)) & sig3_PIMIS0W1_RdMiS0W1_MASK)
/*! @} */

/*! @name RESUS0W1 - RedSum_Stats0_Win1 */
/*! @{ */

#define sig3_RESUS0W1_RdSuS0W1_MASK              (0xFFFFFFFFU)
#define sig3_RESUS0W1_RdSuS0W1_SHIFT             (0U)
/*! RdSuS0W1 - Rd_Sum_S0_Win1 */
#define sig3_RESUS0W1_RdSuS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS0W1_RdSuS0W1_SHIFT)) & sig3_RESUS0W1_RdSuS0W1_MASK)
/*! @} */

/*! @name GRESS0W1 - GreenSum_Stats0_Win1 */
/*! @{ */

#define sig3_GRESS0W1_GnSuS0W1_MASK              (0xFFFFFFFFU)
#define sig3_GRESS0W1_GnSuS0W1_SHIFT             (0U)
/*! GnSuS0W1 - Gn_Sum_S0_Win1 */
#define sig3_GRESS0W1_GnSuS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS0W1_GnSuS0W1_SHIFT)) & sig3_GRESS0W1_GnSuS0W1_MASK)
/*! @} */

/*! @name BLSUS0W1 - BlueSum_Stats0_Win1 */
/*! @{ */

#define sig3_BLSUS0W1_BlSuS0W1_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS0W1_BlSuS0W1_SHIFT             (0U)
/*! BlSuS0W1 - Bl_Sum_S0_Win1 */
#define sig3_BLSUS0W1_BlSuS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS0W1_BlSuS0W1_SHIFT)) & sig3_BLSUS0W1_BlSuS0W1_MASK)
/*! @} */

/*! @name LUSUS0W1 - LumSum_Stats0_Win1 */
/*! @{ */

#define sig3_LUSUS0W1_LmSmS0W1_MASK              (0xFFFFFFFFU)
#define sig3_LUSUS0W1_LmSmS0W1_SHIFT             (0U)
/*! LmSmS0W1 - Lm_Sum_S0_Win1 */
#define sig3_LUSUS0W1_LmSmS0W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_LUSUS0W1_LmSmS0W1_SHIFT)) & sig3_LUSUS0W1_LmSmS0W1_MASK)
/*! @} */

/*! @name PIXCS1W1 - PixCnt_Stats1_Win1 */
/*! @{ */

#define sig3_PIXCS1W1_PxCnS1W1_MASK              (0xFFFFFFFU)
#define sig3_PIXCS1W1_PxCnS1W1_SHIFT             (0U)
/*! PxCnS1W1 - Px_Cnt_S1_Win1 */
#define sig3_PIXCS1W1_PxCnS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS1W1_PxCnS1W1_SHIFT)) & sig3_PIXCS1W1_PxCnS1W1_MASK)
/*! @} */

/*! @name PIMAS1W1 - PixMax_Stats1_Win1 */
/*! @{ */

#define sig3_PIMAS1W1_BlMaS1W1_MASK              (0xFFU)
#define sig3_PIMAS1W1_BlMaS1W1_SHIFT             (0U)
/*! BlMaS1W1 - Bl_Max_S1_Win1 */
#define sig3_PIMAS1W1_BlMaS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W1_BlMaS1W1_SHIFT)) & sig3_PIMAS1W1_BlMaS1W1_MASK)

#define sig3_PIMAS1W1_GnMaS1W1_MASK              (0xFF00U)
#define sig3_PIMAS1W1_GnMaS1W1_SHIFT             (8U)
/*! GnMaS1W1 - Gn_Max_S1_Win1 */
#define sig3_PIMAS1W1_GnMaS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W1_GnMaS1W1_SHIFT)) & sig3_PIMAS1W1_GnMaS1W1_MASK)

#define sig3_PIMAS1W1_RdMaS1W1_MASK              (0xFF0000U)
#define sig3_PIMAS1W1_RdMaS1W1_SHIFT             (16U)
/*! RdMaS1W1 - Rd_Max_S1_Win1 */
#define sig3_PIMAS1W1_RdMaS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W1_RdMaS1W1_SHIFT)) & sig3_PIMAS1W1_RdMaS1W1_MASK)
/*! @} */

/*! @name PIMIS1W1 - PixMin_Stats1_Win1 */
/*! @{ */

#define sig3_PIMIS1W1_BlMiS1W1_MASK              (0xFFU)
#define sig3_PIMIS1W1_BlMiS1W1_SHIFT             (0U)
/*! BlMiS1W1 - Bl_Min_S1_Win1 */
#define sig3_PIMIS1W1_BlMiS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W1_BlMiS1W1_SHIFT)) & sig3_PIMIS1W1_BlMiS1W1_MASK)

#define sig3_PIMIS1W1_GnMiS1W1_MASK              (0xFF00U)
#define sig3_PIMIS1W1_GnMiS1W1_SHIFT             (8U)
/*! GnMiS1W1 - Gn_Min_S1_Win1 */
#define sig3_PIMIS1W1_GnMiS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W1_GnMiS1W1_SHIFT)) & sig3_PIMIS1W1_GnMiS1W1_MASK)

#define sig3_PIMIS1W1_RdMiS1W1_MASK              (0xFF0000U)
#define sig3_PIMIS1W1_RdMiS1W1_SHIFT             (16U)
/*! RdMiS1W1 - Rd_Min_S1_Win1 */
#define sig3_PIMIS1W1_RdMiS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W1_RdMiS1W1_SHIFT)) & sig3_PIMIS1W1_RdMiS1W1_MASK)
/*! @} */

/*! @name RESUS1W1 - RedSum_Stats1_Win1 */
/*! @{ */

#define sig3_RESUS1W1_RdSuS1W1_MASK              (0xFFFFFFFFU)
#define sig3_RESUS1W1_RdSuS1W1_SHIFT             (0U)
/*! RdSuS1W1 - Rd_Sum_S1_Win1 */
#define sig3_RESUS1W1_RdSuS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS1W1_RdSuS1W1_SHIFT)) & sig3_RESUS1W1_RdSuS1W1_MASK)
/*! @} */

/*! @name GRESS1W1 - GreenSum_Stats1_Win1 */
/*! @{ */

#define sig3_GRESS1W1_GnSuS1W1_MASK              (0xFFFFFFFFU)
#define sig3_GRESS1W1_GnSuS1W1_SHIFT             (0U)
/*! GnSuS1W1 - Gn_Sum_S1_Win1 */
#define sig3_GRESS1W1_GnSuS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS1W1_GnSuS1W1_SHIFT)) & sig3_GRESS1W1_GnSuS1W1_MASK)
/*! @} */

/*! @name BLSUS1W1 - BlueSum_Stats1_Win1 */
/*! @{ */

#define sig3_BLSUS1W1_BlSuS1W1_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS1W1_BlSuS1W1_SHIFT             (0U)
/*! BlSuS1W1 - Bl_Sum_S1_Win1 */
#define sig3_BLSUS1W1_BlSuS1W1(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS1W1_BlSuS1W1_SHIFT)) & sig3_BLSUS1W1_BlSuS1W1_MASK)
/*! @} */

/*! @name PIXCS0W2 - PixCnt_Stats0_Win2 */
/*! @{ */

#define sig3_PIXCS0W2_PxCnS0W2_MASK              (0xFFFFFFFU)
#define sig3_PIXCS0W2_PxCnS0W2_SHIFT             (0U)
/*! PxCnS0W2 - Px_Cnt_S0_Win2 */
#define sig3_PIXCS0W2_PxCnS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS0W2_PxCnS0W2_SHIFT)) & sig3_PIXCS0W2_PxCnS0W2_MASK)
/*! @} */

/*! @name PIMAS0W2 - PixMax_Stats0_Win2 */
/*! @{ */

#define sig3_PIMAS0W2_BlMaS0W2_MASK              (0xFFU)
#define sig3_PIMAS0W2_BlMaS0W2_SHIFT             (0U)
/*! BlMaS0W2 - Bl_Max_S0_Win2 */
#define sig3_PIMAS0W2_BlMaS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W2_BlMaS0W2_SHIFT)) & sig3_PIMAS0W2_BlMaS0W2_MASK)

#define sig3_PIMAS0W2_GnMaS0W2_MASK              (0xFF00U)
#define sig3_PIMAS0W2_GnMaS0W2_SHIFT             (8U)
/*! GnMaS0W2 - Gn_Max_S0_Win2 */
#define sig3_PIMAS0W2_GnMaS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W2_GnMaS0W2_SHIFT)) & sig3_PIMAS0W2_GnMaS0W2_MASK)

#define sig3_PIMAS0W2_RdMaS0W2_MASK              (0xFF0000U)
#define sig3_PIMAS0W2_RdMaS0W2_SHIFT             (16U)
/*! RdMaS0W2 - Rd_Max_S0_Win2 */
#define sig3_PIMAS0W2_RdMaS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W2_RdMaS0W2_SHIFT)) & sig3_PIMAS0W2_RdMaS0W2_MASK)
/*! @} */

/*! @name PIMIS0W2 - PixMin_Stats0_Win2 */
/*! @{ */

#define sig3_PIMIS0W2_BlMiS0W2_MASK              (0xFFU)
#define sig3_PIMIS0W2_BlMiS0W2_SHIFT             (0U)
/*! BlMiS0W2 - Bl_Min_S0_Win2 */
#define sig3_PIMIS0W2_BlMiS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W2_BlMiS0W2_SHIFT)) & sig3_PIMIS0W2_BlMiS0W2_MASK)

#define sig3_PIMIS0W2_GnMiS0W2_MASK              (0xFF00U)
#define sig3_PIMIS0W2_GnMiS0W2_SHIFT             (8U)
/*! GnMiS0W2 - Gn_Min_S0_Win2 */
#define sig3_PIMIS0W2_GnMiS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W2_GnMiS0W2_SHIFT)) & sig3_PIMIS0W2_GnMiS0W2_MASK)

#define sig3_PIMIS0W2_RdMiS0W2_MASK              (0xFF0000U)
#define sig3_PIMIS0W2_RdMiS0W2_SHIFT             (16U)
/*! RdMiS0W2 - Rd_Min_S0_Win2 */
#define sig3_PIMIS0W2_RdMiS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W2_RdMiS0W2_SHIFT)) & sig3_PIMIS0W2_RdMiS0W2_MASK)
/*! @} */

/*! @name RESUS0W2 - RedSum_Stats0_Win2 */
/*! @{ */

#define sig3_RESUS0W2_RdSuS0W2_MASK              (0xFFFFFFFFU)
#define sig3_RESUS0W2_RdSuS0W2_SHIFT             (0U)
/*! RdSuS0W2 - Rd_Sum_S0_Win2 */
#define sig3_RESUS0W2_RdSuS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS0W2_RdSuS0W2_SHIFT)) & sig3_RESUS0W2_RdSuS0W2_MASK)
/*! @} */

/*! @name GRESS0W2 - GreenSum_Stats0_Win2 */
/*! @{ */

#define sig3_GRESS0W2_GnSuS0W2_MASK              (0xFFFFFFFFU)
#define sig3_GRESS0W2_GnSuS0W2_SHIFT             (0U)
/*! GnSuS0W2 - Gn_Sum_S0_Win2 */
#define sig3_GRESS0W2_GnSuS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS0W2_GnSuS0W2_SHIFT)) & sig3_GRESS0W2_GnSuS0W2_MASK)
/*! @} */

/*! @name BLSUS0W2 - BlueSum_Stats0_Win2 */
/*! @{ */

#define sig3_BLSUS0W2_BlSuS0W2_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS0W2_BlSuS0W2_SHIFT             (0U)
/*! BlSuS0W2 - Bl_Sum_S0_Win2 */
#define sig3_BLSUS0W2_BlSuS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS0W2_BlSuS0W2_SHIFT)) & sig3_BLSUS0W2_BlSuS0W2_MASK)
/*! @} */

/*! @name LUSUS0W2 - LumSum_Stats0_Win2 */
/*! @{ */

#define sig3_LUSUS0W2_LmSmS0W2_MASK              (0xFFFFFFFFU)
#define sig3_LUSUS0W2_LmSmS0W2_SHIFT             (0U)
/*! LmSmS0W2 - Lm_Sum_S0_Win2 */
#define sig3_LUSUS0W2_LmSmS0W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_LUSUS0W2_LmSmS0W2_SHIFT)) & sig3_LUSUS0W2_LmSmS0W2_MASK)
/*! @} */

/*! @name PIXCS1W2 - PixCnt_Stats1_Win2 */
/*! @{ */

#define sig3_PIXCS1W2_PxCnS1W2_MASK              (0xFFFFFFFU)
#define sig3_PIXCS1W2_PxCnS1W2_SHIFT             (0U)
/*! PxCnS1W2 - Px_Cnt_S1_Win2 */
#define sig3_PIXCS1W2_PxCnS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS1W2_PxCnS1W2_SHIFT)) & sig3_PIXCS1W2_PxCnS1W2_MASK)
/*! @} */

/*! @name PIMAS1W2 - PixMax_Stats1_Win2 */
/*! @{ */

#define sig3_PIMAS1W2_BlMaS1W2_MASK              (0xFFU)
#define sig3_PIMAS1W2_BlMaS1W2_SHIFT             (0U)
/*! BlMaS1W2 - Bl_Max_S1_Win2 */
#define sig3_PIMAS1W2_BlMaS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W2_BlMaS1W2_SHIFT)) & sig3_PIMAS1W2_BlMaS1W2_MASK)

#define sig3_PIMAS1W2_GnMaS1W2_MASK              (0xFF00U)
#define sig3_PIMAS1W2_GnMaS1W2_SHIFT             (8U)
/*! GnMaS1W2 - Gn_Max_S1_Win2 */
#define sig3_PIMAS1W2_GnMaS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W2_GnMaS1W2_SHIFT)) & sig3_PIMAS1W2_GnMaS1W2_MASK)

#define sig3_PIMAS1W2_RdMaS1W2_MASK              (0xFF0000U)
#define sig3_PIMAS1W2_RdMaS1W2_SHIFT             (16U)
/*! RdMaS1W2 - Rd_Max_S1_Win2 */
#define sig3_PIMAS1W2_RdMaS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W2_RdMaS1W2_SHIFT)) & sig3_PIMAS1W2_RdMaS1W2_MASK)
/*! @} */

/*! @name PIMIS1W2 - PixMin_Stats1_Win2 */
/*! @{ */

#define sig3_PIMIS1W2_BlMiS1W2_MASK              (0xFFU)
#define sig3_PIMIS1W2_BlMiS1W2_SHIFT             (0U)
/*! BlMiS1W2 - Bl_Min_S1_Win2 */
#define sig3_PIMIS1W2_BlMiS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W2_BlMiS1W2_SHIFT)) & sig3_PIMIS1W2_BlMiS1W2_MASK)

#define sig3_PIMIS1W2_GnMiS1W2_MASK              (0xFF00U)
#define sig3_PIMIS1W2_GnMiS1W2_SHIFT             (8U)
/*! GnMiS1W2 - Gn_Min_S1_Win2 */
#define sig3_PIMIS1W2_GnMiS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W2_GnMiS1W2_SHIFT)) & sig3_PIMIS1W2_GnMiS1W2_MASK)

#define sig3_PIMIS1W2_RdMiS1W2_MASK              (0xFF0000U)
#define sig3_PIMIS1W2_RdMiS1W2_SHIFT             (16U)
/*! RdMiS1W2 - Rd_Min_S1_Win2 */
#define sig3_PIMIS1W2_RdMiS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W2_RdMiS1W2_SHIFT)) & sig3_PIMIS1W2_RdMiS1W2_MASK)
/*! @} */

/*! @name RESUS1W2 - RedSum_Stats1_Win2 */
/*! @{ */

#define sig3_RESUS1W2_RdSuS1W2_MASK              (0xFFFFFFFFU)
#define sig3_RESUS1W2_RdSuS1W2_SHIFT             (0U)
/*! RdSuS1W2 - Rd_Sum_S1_Win2 */
#define sig3_RESUS1W2_RdSuS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS1W2_RdSuS1W2_SHIFT)) & sig3_RESUS1W2_RdSuS1W2_MASK)
/*! @} */

/*! @name GRESS1W2 - GreenSum_Stats1_Win2 */
/*! @{ */

#define sig3_GRESS1W2_GnSuS1W2_MASK              (0xFFFFFFFFU)
#define sig3_GRESS1W2_GnSuS1W2_SHIFT             (0U)
/*! GnSuS1W2 - Gn_Sum_S1_Win2 */
#define sig3_GRESS1W2_GnSuS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS1W2_GnSuS1W2_SHIFT)) & sig3_GRESS1W2_GnSuS1W2_MASK)
/*! @} */

/*! @name BLSUS1W2 - BlueSum_Stats1_Win2 */
/*! @{ */

#define sig3_BLSUS1W2_BlSuS1W2_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS1W2_BlSuS1W2_SHIFT             (0U)
/*! BlSuS1W2 - Bl_Sum_S1_Win2 */
#define sig3_BLSUS1W2_BlSuS1W2(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS1W2_BlSuS1W2_SHIFT)) & sig3_BLSUS1W2_BlSuS1W2_MASK)
/*! @} */

/*! @name PIXCS0W3 - PixCnt_Stats0_Win3 */
/*! @{ */

#define sig3_PIXCS0W3_PxCnS0W3_MASK              (0xFFFFFFFU)
#define sig3_PIXCS0W3_PxCnS0W3_SHIFT             (0U)
/*! PxCnS0W3 - Px_Cnt_S0_Win3 */
#define sig3_PIXCS0W3_PxCnS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS0W3_PxCnS0W3_SHIFT)) & sig3_PIXCS0W3_PxCnS0W3_MASK)
/*! @} */

/*! @name PIMAS0W3 - PixMax_Stats0_Win3 */
/*! @{ */

#define sig3_PIMAS0W3_BlMaS0W3_MASK              (0xFFU)
#define sig3_PIMAS0W3_BlMaS0W3_SHIFT             (0U)
/*! BlMaS0W3 - Bl_Max_S0_Win3 */
#define sig3_PIMAS0W3_BlMaS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W3_BlMaS0W3_SHIFT)) & sig3_PIMAS0W3_BlMaS0W3_MASK)

#define sig3_PIMAS0W3_GnMaS0W3_MASK              (0xFF00U)
#define sig3_PIMAS0W3_GnMaS0W3_SHIFT             (8U)
/*! GnMaS0W3 - Gn_Max_S0_Win3 */
#define sig3_PIMAS0W3_GnMaS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W3_GnMaS0W3_SHIFT)) & sig3_PIMAS0W3_GnMaS0W3_MASK)

#define sig3_PIMAS0W3_RdMaS0W3_MASK              (0xFF0000U)
#define sig3_PIMAS0W3_RdMaS0W3_SHIFT             (16U)
/*! RdMaS0W3 - Rd_Max_S0_Win3 */
#define sig3_PIMAS0W3_RdMaS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS0W3_RdMaS0W3_SHIFT)) & sig3_PIMAS0W3_RdMaS0W3_MASK)
/*! @} */

/*! @name PIMIS0W3 - PixMin_Stats0_Win3 */
/*! @{ */

#define sig3_PIMIS0W3_BlMiS0W3_MASK              (0xFFU)
#define sig3_PIMIS0W3_BlMiS0W3_SHIFT             (0U)
/*! BlMiS0W3 - Bl_Min_S0_Win3 */
#define sig3_PIMIS0W3_BlMiS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W3_BlMiS0W3_SHIFT)) & sig3_PIMIS0W3_BlMiS0W3_MASK)

#define sig3_PIMIS0W3_GnMiS0W3_MASK              (0xFF00U)
#define sig3_PIMIS0W3_GnMiS0W3_SHIFT             (8U)
/*! GnMiS0W3 - Gn_Min_S0_Win3 */
#define sig3_PIMIS0W3_GnMiS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W3_GnMiS0W3_SHIFT)) & sig3_PIMIS0W3_GnMiS0W3_MASK)

#define sig3_PIMIS0W3_RdMiS0W3_MASK              (0xFF0000U)
#define sig3_PIMIS0W3_RdMiS0W3_SHIFT             (16U)
/*! RdMiS0W3 - Rd_Min_S0_Win3 */
#define sig3_PIMIS0W3_RdMiS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS0W3_RdMiS0W3_SHIFT)) & sig3_PIMIS0W3_RdMiS0W3_MASK)
/*! @} */

/*! @name RESUS0W3 - RedSum_Stats0_Win3 */
/*! @{ */

#define sig3_RESUS0W3_RdSuS0W3_MASK              (0xFFFFFFFFU)
#define sig3_RESUS0W3_RdSuS0W3_SHIFT             (0U)
/*! RdSuS0W3 - Rd_Sum_S0_Win3 */
#define sig3_RESUS0W3_RdSuS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS0W3_RdSuS0W3_SHIFT)) & sig3_RESUS0W3_RdSuS0W3_MASK)
/*! @} */

/*! @name GRESS0W3 - GreenSum_Stats0_Win3 */
/*! @{ */

#define sig3_GRESS0W3_GnSuS0W3_MASK              (0xFFFFFFFFU)
#define sig3_GRESS0W3_GnSuS0W3_SHIFT             (0U)
/*! GnSuS0W3 - Gn_Sum_S0_Win3 */
#define sig3_GRESS0W3_GnSuS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS0W3_GnSuS0W3_SHIFT)) & sig3_GRESS0W3_GnSuS0W3_MASK)
/*! @} */

/*! @name BLSUS0W3 - BlueSum_Stats0_Win3 */
/*! @{ */

#define sig3_BLSUS0W3_BlSuS0W3_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS0W3_BlSuS0W3_SHIFT             (0U)
/*! BlSuS0W3 - Bl_Sum_S0_Win3 */
#define sig3_BLSUS0W3_BlSuS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS0W3_BlSuS0W3_SHIFT)) & sig3_BLSUS0W3_BlSuS0W3_MASK)
/*! @} */

/*! @name LUSUS0W3 - LumSum_Stats0_Win3 */
/*! @{ */

#define sig3_LUSUS0W3_LmSmS0W3_MASK              (0xFFFFFFFFU)
#define sig3_LUSUS0W3_LmSmS0W3_SHIFT             (0U)
/*! LmSmS0W3 - Lm_Sum_S0_Win3 */
#define sig3_LUSUS0W3_LmSmS0W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_LUSUS0W3_LmSmS0W3_SHIFT)) & sig3_LUSUS0W3_LmSmS0W3_MASK)
/*! @} */

/*! @name PIXCS1W3 - PixCnt_Stats1_Win3 */
/*! @{ */

#define sig3_PIXCS1W3_PxCnS1W3_MASK              (0xFFFFFFFU)
#define sig3_PIXCS1W3_PxCnS1W3_SHIFT             (0U)
/*! PxCnS1W3 - Px_Cnt_S1_Win3 */
#define sig3_PIXCS1W3_PxCnS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIXCS1W3_PxCnS1W3_SHIFT)) & sig3_PIXCS1W3_PxCnS1W3_MASK)
/*! @} */

/*! @name PIMAS1W3 - PixMax_Stats1_Win3 */
/*! @{ */

#define sig3_PIMAS1W3_BlMaS1W3_MASK              (0xFFU)
#define sig3_PIMAS1W3_BlMaS1W3_SHIFT             (0U)
/*! BlMaS1W3 - Bl_Max_S1_Win3 */
#define sig3_PIMAS1W3_BlMaS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W3_BlMaS1W3_SHIFT)) & sig3_PIMAS1W3_BlMaS1W3_MASK)

#define sig3_PIMAS1W3_GnMaS1W3_MASK              (0xFF00U)
#define sig3_PIMAS1W3_GnMaS1W3_SHIFT             (8U)
/*! GnMaS1W3 - Gn_Max_S1_Win3 */
#define sig3_PIMAS1W3_GnMaS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W3_GnMaS1W3_SHIFT)) & sig3_PIMAS1W3_GnMaS1W3_MASK)

#define sig3_PIMAS1W3_RdMaS1W3_MASK              (0xFF0000U)
#define sig3_PIMAS1W3_RdMaS1W3_SHIFT             (16U)
/*! RdMaS1W3 - Rd_Max_S1_Win3 */
#define sig3_PIMAS1W3_RdMaS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMAS1W3_RdMaS1W3_SHIFT)) & sig3_PIMAS1W3_RdMaS1W3_MASK)
/*! @} */

/*! @name PIMIS1W3 - PixMin_Stats1_Win3 */
/*! @{ */

#define sig3_PIMIS1W3_BlMiS1W3_MASK              (0xFFU)
#define sig3_PIMIS1W3_BlMiS1W3_SHIFT             (0U)
/*! BlMiS1W3 - Bl_Min_S1_Win3 */
#define sig3_PIMIS1W3_BlMiS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W3_BlMiS1W3_SHIFT)) & sig3_PIMIS1W3_BlMiS1W3_MASK)

#define sig3_PIMIS1W3_GnMiS1W3_MASK              (0xFF00U)
#define sig3_PIMIS1W3_GnMiS1W3_SHIFT             (8U)
/*! GnMiS1W3 - Gn_Min_S1_Win3 */
#define sig3_PIMIS1W3_GnMiS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W3_GnMiS1W3_SHIFT)) & sig3_PIMIS1W3_GnMiS1W3_MASK)

#define sig3_PIMIS1W3_RdMiS1W3_MASK              (0xFF0000U)
#define sig3_PIMIS1W3_RdMiS1W3_SHIFT             (16U)
/*! RdMiS1W3 - Rd_Min_S1_Win3 */
#define sig3_PIMIS1W3_RdMiS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_PIMIS1W3_RdMiS1W3_SHIFT)) & sig3_PIMIS1W3_RdMiS1W3_MASK)
/*! @} */

/*! @name RESUS1W3 - RedSum_Stats1_Win3 */
/*! @{ */

#define sig3_RESUS1W3_RdSuS1W3_MASK              (0xFFFFFFFFU)
#define sig3_RESUS1W3_RdSuS1W3_SHIFT             (0U)
/*! RdSuS1W3 - Rd_Sum_S1_Win3 */
#define sig3_RESUS1W3_RdSuS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_RESUS1W3_RdSuS1W3_SHIFT)) & sig3_RESUS1W3_RdSuS1W3_MASK)
/*! @} */

/*! @name GRESS1W3 - GreenSum_Stats1_Win3 */
/*! @{ */

#define sig3_GRESS1W3_GnSuS1W3_MASK              (0xFFFFFFFFU)
#define sig3_GRESS1W3_GnSuS1W3_SHIFT             (0U)
/*! GnSuS1W3 - Gn_Sum_S1_Win3 */
#define sig3_GRESS1W3_GnSuS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_GRESS1W3_GnSuS1W3_SHIFT)) & sig3_GRESS1W3_GnSuS1W3_MASK)
/*! @} */

/*! @name BLSUS1W3 - BlueSum_Stats1_Win3 */
/*! @{ */

#define sig3_BLSUS1W3_BlSuS1W3_MASK              (0xFFFFFFFFU)
#define sig3_BLSUS1W3_BlSuS1W3_SHIFT             (0U)
/*! BlSuS1W3 - Bl_Sum_S1_Win3 */
#define sig3_BLSUS1W3_BlSuS1W3(x)                (((uint32_t)(((uint32_t)(x)) << sig3_BLSUS1W3_BlSuS1W3_SHIFT)) & sig3_BLSUS1W3_BlSuS1W3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group sig3_Register_Masks */


/*!
 * @}
 */ /* end of group sig3_Peripheral_Access_Layer */


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


#endif  /* PERI_SIG3_H_ */

