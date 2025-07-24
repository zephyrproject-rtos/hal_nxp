/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPDDR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LPDDR.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPDDR
 *
 * CMSIS Peripheral Access Layer for LPDDR
 */

#if !defined(PERI_LPDDR_H_)
#define PERI_LPDDR_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- LPDDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDDR_Peripheral_Access_Layer LPDDR Peripheral Access Layer
 * @{
 */

/** LPDDR - Size of Registers Arrays */
#define LPDDR_DENALI_CTL_COUNT                    615u

/** LPDDR - Register Layout Typedef */
typedef struct {
  __IO uint32_t DENALI_CTL[LPDDR_DENALI_CTL_COUNT]; /**< DENALI_CTL_0..DENALI_CTL_614, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_0[5732];
  __IO uint32_t DENALI_PI_0;                       /**< DENALI_PI_0, offset: 0x2000 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DENALI_PI_3;                       /**< DENALI_PI_3, offset: 0x200C */
  __IO uint32_t DENALI_PI_4;                       /**< DENALI_PI_4, offset: 0x2010 */
  __IO uint32_t DENALI_PI_5;                       /**< DENALI_PI_5, offset: 0x2014 */
       uint8_t RESERVED_2[20];
  __IO uint32_t DENALI_PI_11;                      /**< DENALI_PI_11, offset: 0x202C */
  __IO uint32_t DENALI_PI_12;                      /**< DENALI_PI_12, offset: 0x2030 */
  __IO uint32_t DENALI_PI_13;                      /**< DENALI_PI_13, offset: 0x2034 */
  __IO uint32_t DENALI_PI_14;                      /**< DENALI_PI_14, offset: 0x2038 */
  __IO uint32_t DENALI_PI_15;                      /**< DENALI_PI_15, offset: 0x203C */
  __IO uint32_t DENALI_PI_16;                      /**< DENALI_PI_16, offset: 0x2040 */
       uint8_t RESERVED_3[48];
  __IO uint32_t DENALI_PI_29;                      /**< DENALI_PI_29, offset: 0x2074 */
       uint8_t RESERVED_4[56];
  __IO uint32_t DENALI_PI_44;                      /**< DENALI_PI_44, offset: 0x20B0 */
  __IO uint32_t DENALI_PI_45;                      /**< DENALI_PI_45, offset: 0x20B4 */
       uint8_t RESERVED_5[36];
  __IO uint32_t DENALI_PI_55;                      /**< DENALI_PI_55, offset: 0x20DC */
       uint8_t RESERVED_6[32];
  __IO uint32_t DENALI_PI_64;                      /**< DENALI_PI_64, offset: 0x2100 */
       uint8_t RESERVED_7[20];
  __IO uint32_t DENALI_PI_70;                      /**< DENALI_PI_70, offset: 0x2118 */
  __IO uint32_t DENALI_PI_71;                      /**< DENALI_PI_71, offset: 0x211C */
       uint8_t RESERVED_8[72];
  __IO uint32_t DENALI_PI_90;                      /**< DENALI_PI_90, offset: 0x2168 */
  __IO uint32_t DENALI_PI_91;                      /**< DENALI_PI_91, offset: 0x216C */
  __IO uint32_t DENALI_PI_92;                      /**< DENALI_PI_92, offset: 0x2170 */
       uint8_t RESERVED_9[272];
  __IO uint32_t DENALI_PI_161;                     /**< DENALI_PI_161, offset: 0x2284 */
  __IO uint32_t DENALI_PI_162;                     /**< DENALI_PI_162, offset: 0x2288 */
  __IO uint32_t DENALI_PI_163;                     /**< DENALI_PI_163, offset: 0x228C */
  __IO uint32_t DENALI_PI_164;                     /**< DENALI_PI_164, offset: 0x2290 */
  __IO uint32_t DENALI_PI_165;                     /**< DENALI_PI_165, offset: 0x2294 */
  __IO uint32_t DENALI_PI_166;                     /**< DENALI_PI_166, offset: 0x2298 */
  __IO uint32_t DENALI_PI_167;                     /**< DENALI_PI_167, offset: 0x229C */
  __IO uint32_t DENALI_PI_168;                     /**< DENALI_PI_168, offset: 0x22A0 */
  __IO uint32_t DENALI_PI_169;                     /**< DENALI_PI_169, offset: 0x22A4 */
  __IO uint32_t DENALI_PI_170;                     /**< DENALI_PI_170, offset: 0x22A8 */
  __IO uint32_t DENALI_PI_171;                     /**< DENALI_PI_171, offset: 0x22AC */
  __IO uint32_t DENALI_PI_172;                     /**< DENALI_PI_172, offset: 0x22B0 */
  __IO uint32_t DENALI_PI_173;                     /**< DENALI_PI_173, offset: 0x22B4 */
  __IO uint32_t DENALI_PI_174;                     /**< DENALI_PI_174, offset: 0x22B8 */
  __IO uint32_t DENALI_PI_175;                     /**< DENALI_PI_175, offset: 0x22BC */
  __IO uint32_t DENALI_PI_176;                     /**< DENALI_PI_176, offset: 0x22C0 */
  __IO uint32_t DENALI_PI_177;                     /**< DENALI_PI_177, offset: 0x22C4 */
  __IO uint32_t DENALI_PI_178;                     /**< DENALI_PI_178, offset: 0x22C8 */
       uint8_t RESERVED_10[8];
  __IO uint32_t DENALI_PI_181;                     /**< DENALI_PI_181, offset: 0x22D4 */
  __IO uint32_t DENALI_PI_182;                     /**< DENALI_PI_182, offset: 0x22D8 */
       uint8_t RESERVED_11[12];
  __IO uint32_t DENALI_PI_186;                     /**< DENALI_PI_186, offset: 0x22E8 */
  __IO uint32_t DENALI_PI_187;                     /**< DENALI_PI_187, offset: 0x22EC */
  __IO uint32_t DENALI_PI_188;                     /**< DENALI_PI_188, offset: 0x22F0 */
  __IO uint32_t DENALI_PI_189;                     /**< DENALI_PI_189, offset: 0x22F4 */
  __IO uint32_t DENALI_PI_190;                     /**< DENALI_PI_190, offset: 0x22F8 */
  __IO uint32_t DENALI_PI_191;                     /**< DENALI_PI_191, offset: 0x22FC */
  __IO uint32_t DENALI_PI_192;                     /**< DENALI_PI_192, offset: 0x2300 */
  __IO uint32_t DENALI_PI_193;                     /**< DENALI_PI_193, offset: 0x2304 */
  __IO uint32_t DENALI_PI_194;                     /**< DENALI_PI_194, offset: 0x2308 */
  __IO uint32_t DENALI_PI_195;                     /**< DENALI_PI_195, offset: 0x230C */
  __IO uint32_t DENALI_PI_196;                     /**< DENALI_PI_196, offset: 0x2310 */
  __IO uint32_t DENALI_PI_197;                     /**< DENALI_PI_197, offset: 0x2314 */
  __IO uint32_t DENALI_PI_198;                     /**< DENALI_PI_198, offset: 0x2318 */
  __IO uint32_t DENALI_PI_199;                     /**< DENALI_PI_199, offset: 0x231C */
  __IO uint32_t DENALI_PI_200;                     /**< DENALI_PI_200, offset: 0x2320 */
  __IO uint32_t DENALI_PI_201;                     /**< DENALI_PI_201, offset: 0x2324 */
  __IO uint32_t DENALI_PI_202;                     /**< DENALI_PI_202, offset: 0x2328 */
  __IO uint32_t DENALI_PI_203;                     /**< DENALI_PI_203, offset: 0x232C */
  __IO uint32_t DENALI_PI_204;                     /**< DENALI_PI_204, offset: 0x2330 */
  __IO uint32_t DENALI_PI_205;                     /**< DENALI_PI_205, offset: 0x2334 */
  __IO uint32_t DENALI_PI_206;                     /**< DENALI_PI_206, offset: 0x2338 */
  __IO uint32_t DENALI_PI_207;                     /**< DENALI_PI_207, offset: 0x233C */
  __IO uint32_t DENALI_PI_208;                     /**< DENALI_PI_208, offset: 0x2340 */
  __IO uint32_t DENALI_PI_209;                     /**< DENALI_PI_209, offset: 0x2344 */
  __IO uint32_t DENALI_PI_210;                     /**< DENALI_PI_210, offset: 0x2348 */
  __IO uint32_t DENALI_PI_211;                     /**< DENALI_PI_211, offset: 0x234C */
  __IO uint32_t DENALI_PI_212;                     /**< DENALI_PI_212, offset: 0x2350 */
  __IO uint32_t DENALI_PI_213;                     /**< DENALI_PI_213, offset: 0x2354 */
  __IO uint32_t DENALI_PI_214;                     /**< DENALI_PI_214, offset: 0x2358 */
  __IO uint32_t DENALI_PI_215;                     /**< DENALI_PI_215, offset: 0x235C */
  __IO uint32_t DENALI_PI_216;                     /**< DENALI_PI_216, offset: 0x2360 */
  __IO uint32_t DENALI_PI_217;                     /**< DENALI_PI_217, offset: 0x2364 */
  __IO uint32_t DENALI_PI_218;                     /**< DENALI_PI_218, offset: 0x2368 */
  __IO uint32_t DENALI_PI_219;                     /**< DENALI_PI_219, offset: 0x236C */
  __IO uint32_t DENALI_PI_220;                     /**< DENALI_PI_220, offset: 0x2370 */
  __IO uint32_t DENALI_PI_221;                     /**< DENALI_PI_221, offset: 0x2374 */
  __IO uint32_t DENALI_PI_222;                     /**< DENALI_PI_222, offset: 0x2378 */
  __IO uint32_t DENALI_PI_223;                     /**< DENALI_PI_223, offset: 0x237C */
  __IO uint32_t DENALI_PI_224;                     /**< DENALI_PI_224, offset: 0x2380 */
  __IO uint32_t DENALI_PI_225;                     /**< DENALI_PI_225, offset: 0x2384 */
  __IO uint32_t DENALI_PI_226;                     /**< DENALI_PI_226, offset: 0x2388 */
  __IO uint32_t DENALI_PI_227;                     /**< DENALI_PI_227, offset: 0x238C */
  __IO uint32_t DENALI_PI_228;                     /**< DENALI_PI_228, offset: 0x2390 */
  __IO uint32_t DENALI_PI_229;                     /**< DENALI_PI_229, offset: 0x2394 */
  __IO uint32_t DENALI_PI_230;                     /**< DENALI_PI_230, offset: 0x2398 */
  __IO uint32_t DENALI_PI_231;                     /**< DENALI_PI_231, offset: 0x239C */
  __IO uint32_t DENALI_PI_232;                     /**< DENALI_PI_232, offset: 0x23A0 */
  __IO uint32_t DENALI_PI_233;                     /**< DENALI_PI_233, offset: 0x23A4 */
  __IO uint32_t DENALI_PI_234;                     /**< DENALI_PI_234, offset: 0x23A8 */
  __IO uint32_t DENALI_PI_235;                     /**< DENALI_PI_235, offset: 0x23AC */
  __IO uint32_t DENALI_PI_236;                     /**< DENALI_PI_236, offset: 0x23B0 */
  __IO uint32_t DENALI_PI_237;                     /**< DENALI_PI_237, offset: 0x23B4 */
  __IO uint32_t DENALI_PI_238;                     /**< DENALI_PI_238, offset: 0x23B8 */
  __IO uint32_t DENALI_PI_239;                     /**< DENALI_PI_239, offset: 0x23BC */
       uint8_t RESERVED_12[8];
  __IO uint32_t DENALI_PI_242;                     /**< DENALI_PI_242, offset: 0x23C8 */
  __IO uint32_t DENALI_PI_243;                     /**< DENALI_PI_243, offset: 0x23CC */
  __IO uint32_t DENALI_PI_244;                     /**< DENALI_PI_244, offset: 0x23D0 */
       uint8_t RESERVED_13[4];
  __IO uint32_t DENALI_PI_246;                     /**< DENALI_PI_246, offset: 0x23D8 */
  __IO uint32_t DENALI_PI_247;                     /**< DENALI_PI_247, offset: 0x23DC */
  __IO uint32_t DENALI_PI_248;                     /**< DENALI_PI_248, offset: 0x23E0 */
  __IO uint32_t DENALI_PI_249;                     /**< DENALI_PI_249, offset: 0x23E4 */
       uint8_t RESERVED_14[4];
  __IO uint32_t DENALI_PI_251;                     /**< DENALI_PI_251, offset: 0x23EC */
  __IO uint32_t DENALI_PI_252;                     /**< DENALI_PI_252, offset: 0x23F0 */
  __IO uint32_t DENALI_PI_253;                     /**< DENALI_PI_253, offset: 0x23F4 */
  __IO uint32_t DENALI_PI_254;                     /**< DENALI_PI_254, offset: 0x23F8 */
  __IO uint32_t DENALI_PI_255;                     /**< DENALI_PI_255, offset: 0x23FC */
  __IO uint32_t DENALI_PI_256;                     /**< DENALI_PI_256, offset: 0x2400 */
  __IO uint32_t DENALI_PI_257;                     /**< DENALI_PI_257, offset: 0x2404 */
  __IO uint32_t DENALI_PI_258;                     /**< DENALI_PI_258, offset: 0x2408 */
       uint8_t RESERVED_15[8];
  __IO uint32_t DENALI_PI_261;                     /**< DENALI_PI_261, offset: 0x2414 */
       uint8_t RESERVED_16[60];
  __IO uint32_t DENALI_PI_277;                     /**< DENALI_PI_277, offset: 0x2454 */
  __IO uint32_t DENALI_PI_278;                     /**< DENALI_PI_278, offset: 0x2458 */
  __IO uint32_t DENALI_PI_279;                     /**< DENALI_PI_279, offset: 0x245C */
  __IO uint32_t DENALI_PI_280;                     /**< DENALI_PI_280, offset: 0x2460 */
  __IO uint32_t DENALI_PI_281;                     /**< DENALI_PI_281, offset: 0x2464 */
  __IO uint32_t DENALI_PI_282;                     /**< DENALI_PI_282, offset: 0x2468 */
  __IO uint32_t DENALI_PI_283;                     /**< DENALI_PI_283, offset: 0x246C */
  __IO uint32_t DENALI_PI_284;                     /**< DENALI_PI_284, offset: 0x2470 */
  __IO uint32_t DENALI_PI_285;                     /**< DENALI_PI_285, offset: 0x2474 */
  __IO uint32_t DENALI_PI_286;                     /**< DENALI_PI_286, offset: 0x2478 */
  __IO uint32_t DENALI_PI_287;                     /**< DENALI_PI_287, offset: 0x247C */
  __IO uint32_t DENALI_PI_288;                     /**< DENALI_PI_288, offset: 0x2480 */
  __IO uint32_t DENALI_PI_289;                     /**< DENALI_PI_289, offset: 0x2484 */
  __IO uint32_t DENALI_PI_290;                     /**< DENALI_PI_290, offset: 0x2488 */
  __IO uint32_t DENALI_PI_291;                     /**< DENALI_PI_291, offset: 0x248C */
  __IO uint32_t DENALI_PI_292;                     /**< DENALI_PI_292, offset: 0x2490 */
  __IO uint32_t DENALI_PI_293;                     /**< DENALI_PI_293, offset: 0x2494 */
  __IO uint32_t DENALI_PI_294;                     /**< DENALI_PI_294, offset: 0x2498 */
  __IO uint32_t DENALI_PI_295;                     /**< DENALI_PI_295, offset: 0x249C */
  __IO uint32_t DENALI_PI_296;                     /**< DENALI_PI_296, offset: 0x24A0 */
  __IO uint32_t DENALI_PI_297;                     /**< DENALI_PI_297, offset: 0x24A4 */
       uint8_t RESERVED_17[7124];
  __IO uint32_t DENALI_PHY_31;                     /**< DENALI_PHY_31, offset: 0x407C */
       uint8_t RESERVED_18[4];
  __IO uint32_t DENALI_PHY_33;                     /**< DENALI_PHY_33, offset: 0x4084 */
       uint8_t RESERVED_19[36];
  __IO uint32_t DENALI_PHY_43;                     /**< DENALI_PHY_43, offset: 0x40AC */
       uint8_t RESERVED_20[112];
  __IO uint32_t DENALI_PHY_72;                     /**< DENALI_PHY_72, offset: 0x4120 */
  __IO uint32_t DENALI_PHY_73;                     /**< DENALI_PHY_73, offset: 0x4124 */
  __IO uint32_t DENALI_PHY_74;                     /**< DENALI_PHY_74, offset: 0x4128 */
  __IO uint32_t DENALI_PHY_75;                     /**< DENALI_PHY_75, offset: 0x412C */
       uint8_t RESERVED_21[16];
  __IO uint32_t DENALI_PHY_80;                     /**< DENALI_PHY_80, offset: 0x4140 */
       uint8_t RESERVED_22[28];
  __IO uint32_t DENALI_PHY_88;                     /**< DENALI_PHY_88, offset: 0x4160 */
  __IO uint32_t DENALI_PHY_89;                     /**< DENALI_PHY_89, offset: 0x4164 */
  __IO uint32_t DENALI_PHY_90;                     /**< DENALI_PHY_90, offset: 0x4168 */
       uint8_t RESERVED_23[4];
  __IO uint32_t DENALI_PHY_92;                     /**< DENALI_PHY_92, offset: 0x4170 */
  __IO uint32_t DENALI_PHY_93;                     /**< DENALI_PHY_93, offset: 0x4174 */
       uint8_t RESERVED_24[4];
  __IO uint32_t DENALI_PHY_95;                     /**< DENALI_PHY_95, offset: 0x417C */
  __IO uint32_t DENALI_PHY_96;                     /**< DENALI_PHY_96, offset: 0x4180 */
  __IO uint32_t DENALI_PHY_97;                     /**< DENALI_PHY_97, offset: 0x4184 */
  __IO uint32_t DENALI_PHY_98;                     /**< DENALI_PHY_98, offset: 0x4188 */
       uint8_t RESERVED_25[4];
  __IO uint32_t DENALI_PHY_100;                    /**< DENALI_PHY_100, offset: 0x4190 */
  __IO uint32_t DENALI_PHY_101;                    /**< DENALI_PHY_101, offset: 0x4194 */
  __IO uint32_t DENALI_PHY_102;                    /**< DENALI_PHY_102, offset: 0x4198 */
  __IO uint32_t DENALI_PHY_103;                    /**< DENALI_PHY_103, offset: 0x419C */
  __IO uint32_t DENALI_PHY_104;                    /**< DENALI_PHY_104, offset: 0x41A0 */
       uint8_t RESERVED_26[36];
  __IO uint32_t DENALI_PHY_114;                    /**< DENALI_PHY_114, offset: 0x41C8 */
       uint8_t RESERVED_27[688];
  __IO uint32_t DENALI_PHY_287;                    /**< DENALI_PHY_287, offset: 0x447C */
       uint8_t RESERVED_28[4];
  __IO uint32_t DENALI_PHY_289;                    /**< DENALI_PHY_289, offset: 0x4484 */
       uint8_t RESERVED_29[36];
  __IO uint32_t DENALI_PHY_299;                    /**< DENALI_PHY_299, offset: 0x44AC */
       uint8_t RESERVED_30[112];
  __IO uint32_t DENALI_PHY_328;                    /**< DENALI_PHY_328, offset: 0x4520 */
  __IO uint32_t DENALI_PHY_329;                    /**< DENALI_PHY_329, offset: 0x4524 */
  __IO uint32_t DENALI_PHY_330;                    /**< DENALI_PHY_330, offset: 0x4528 */
  __IO uint32_t DENALI_PHY_331;                    /**< DENALI_PHY_331, offset: 0x452C */
       uint8_t RESERVED_31[16];
  __IO uint32_t DENALI_PHY_336;                    /**< DENALI_PHY_336, offset: 0x4540 */
       uint8_t RESERVED_32[28];
  __IO uint32_t DENALI_PHY_344;                    /**< DENALI_PHY_344, offset: 0x4560 */
  __IO uint32_t DENALI_PHY_345;                    /**< DENALI_PHY_345, offset: 0x4564 */
  __IO uint32_t DENALI_PHY_346;                    /**< DENALI_PHY_346, offset: 0x4568 */
       uint8_t RESERVED_33[4];
  __IO uint32_t DENALI_PHY_348;                    /**< DENALI_PHY_348, offset: 0x4570 */
  __IO uint32_t DENALI_PHY_349;                    /**< DENALI_PHY_349, offset: 0x4574 */
       uint8_t RESERVED_34[4];
  __IO uint32_t DENALI_PHY_351;                    /**< DENALI_PHY_351, offset: 0x457C */
  __IO uint32_t DENALI_PHY_352;                    /**< DENALI_PHY_352, offset: 0x4580 */
  __IO uint32_t DENALI_PHY_353;                    /**< DENALI_PHY_353, offset: 0x4584 */
  __IO uint32_t DENALI_PHY_354;                    /**< DENALI_PHY_354, offset: 0x4588 */
       uint8_t RESERVED_35[4];
  __IO uint32_t DENALI_PHY_356;                    /**< DENALI_PHY_356, offset: 0x4590 */
  __IO uint32_t DENALI_PHY_357;                    /**< DENALI_PHY_357, offset: 0x4594 */
  __IO uint32_t DENALI_PHY_358;                    /**< DENALI_PHY_358, offset: 0x4598 */
  __IO uint32_t DENALI_PHY_359;                    /**< DENALI_PHY_359, offset: 0x459C */
  __IO uint32_t DENALI_PHY_360;                    /**< DENALI_PHY_360, offset: 0x45A0 */
       uint8_t RESERVED_36[36];
  __IO uint32_t DENALI_PHY_370;                    /**< DENALI_PHY_370, offset: 0x45C8 */
       uint8_t RESERVED_37[688];
  __IO uint32_t DENALI_PHY_543;                    /**< DENALI_PHY_543, offset: 0x487C */
       uint8_t RESERVED_38[4];
  __IO uint32_t DENALI_PHY_545;                    /**< DENALI_PHY_545, offset: 0x4884 */
       uint8_t RESERVED_39[36];
  __IO uint32_t DENALI_PHY_555;                    /**< DENALI_PHY_555, offset: 0x48AC */
       uint8_t RESERVED_40[112];
  __IO uint32_t DENALI_PHY_584;                    /**< DENALI_PHY_584, offset: 0x4920 */
  __IO uint32_t DENALI_PHY_585;                    /**< DENALI_PHY_585, offset: 0x4924 */
  __IO uint32_t DENALI_PHY_586;                    /**< DENALI_PHY_586, offset: 0x4928 */
  __IO uint32_t DENALI_PHY_587;                    /**< DENALI_PHY_587, offset: 0x492C */
       uint8_t RESERVED_41[16];
  __IO uint32_t DENALI_PHY_592;                    /**< DENALI_PHY_592, offset: 0x4940 */
       uint8_t RESERVED_42[28];
  __IO uint32_t DENALI_PHY_600;                    /**< DENALI_PHY_600, offset: 0x4960 */
  __IO uint32_t DENALI_PHY_601;                    /**< DENALI_PHY_601, offset: 0x4964 */
  __IO uint32_t DENALI_PHY_602;                    /**< DENALI_PHY_602, offset: 0x4968 */
       uint8_t RESERVED_43[4];
  __IO uint32_t DENALI_PHY_604;                    /**< DENALI_PHY_604, offset: 0x4970 */
  __IO uint32_t DENALI_PHY_605;                    /**< DENALI_PHY_605, offset: 0x4974 */
       uint8_t RESERVED_44[4];
  __IO uint32_t DENALI_PHY_607;                    /**< DENALI_PHY_607, offset: 0x497C */
  __IO uint32_t DENALI_PHY_608;                    /**< DENALI_PHY_608, offset: 0x4980 */
  __IO uint32_t DENALI_PHY_609;                    /**< DENALI_PHY_609, offset: 0x4984 */
  __IO uint32_t DENALI_PHY_610;                    /**< DENALI_PHY_610, offset: 0x4988 */
       uint8_t RESERVED_45[4];
  __IO uint32_t DENALI_PHY_612;                    /**< DENALI_PHY_612, offset: 0x4990 */
  __IO uint32_t DENALI_PHY_613;                    /**< DENALI_PHY_613, offset: 0x4994 */
  __IO uint32_t DENALI_PHY_614;                    /**< DENALI_PHY_614, offset: 0x4998 */
  __IO uint32_t DENALI_PHY_615;                    /**< DENALI_PHY_615, offset: 0x499C */
  __IO uint32_t DENALI_PHY_616;                    /**< DENALI_PHY_616, offset: 0x49A0 */
       uint8_t RESERVED_46[36];
  __IO uint32_t DENALI_PHY_626;                    /**< DENALI_PHY_626, offset: 0x49C8 */
       uint8_t RESERVED_47[688];
  __IO uint32_t DENALI_PHY_799;                    /**< DENALI_PHY_799, offset: 0x4C7C */
       uint8_t RESERVED_48[4];
  __IO uint32_t DENALI_PHY_801;                    /**< DENALI_PHY_801, offset: 0x4C84 */
       uint8_t RESERVED_49[36];
  __IO uint32_t DENALI_PHY_811;                    /**< DENALI_PHY_811, offset: 0x4CAC */
       uint8_t RESERVED_50[112];
  __IO uint32_t DENALI_PHY_840;                    /**< DENALI_PHY_840, offset: 0x4D20 */
  __IO uint32_t DENALI_PHY_841;                    /**< DENALI_PHY_841, offset: 0x4D24 */
  __IO uint32_t DENALI_PHY_842;                    /**< DENALI_PHY_842, offset: 0x4D28 */
  __IO uint32_t DENALI_PHY_843;                    /**< DENALI_PHY_843, offset: 0x4D2C */
       uint8_t RESERVED_51[16];
  __IO uint32_t DENALI_PHY_848;                    /**< DENALI_PHY_848, offset: 0x4D40 */
       uint8_t RESERVED_52[28];
  __IO uint32_t DENALI_PHY_856;                    /**< DENALI_PHY_856, offset: 0x4D60 */
  __IO uint32_t DENALI_PHY_857;                    /**< DENALI_PHY_857, offset: 0x4D64 */
  __IO uint32_t DENALI_PHY_858;                    /**< DENALI_PHY_858, offset: 0x4D68 */
       uint8_t RESERVED_53[4];
  __IO uint32_t DENALI_PHY_860;                    /**< DENALI_PHY_860, offset: 0x4D70 */
  __IO uint32_t DENALI_PHY_861;                    /**< DENALI_PHY_861, offset: 0x4D74 */
       uint8_t RESERVED_54[4];
  __IO uint32_t DENALI_PHY_863;                    /**< DENALI_PHY_863, offset: 0x4D7C */
  __IO uint32_t DENALI_PHY_864;                    /**< DENALI_PHY_864, offset: 0x4D80 */
  __IO uint32_t DENALI_PHY_865;                    /**< DENALI_PHY_865, offset: 0x4D84 */
  __IO uint32_t DENALI_PHY_866;                    /**< DENALI_PHY_866, offset: 0x4D88 */
       uint8_t RESERVED_55[4];
  __IO uint32_t DENALI_PHY_868;                    /**< DENALI_PHY_868, offset: 0x4D90 */
  __IO uint32_t DENALI_PHY_869;                    /**< DENALI_PHY_869, offset: 0x4D94 */
  __IO uint32_t DENALI_PHY_870;                    /**< DENALI_PHY_870, offset: 0x4D98 */
  __IO uint32_t DENALI_PHY_871;                    /**< DENALI_PHY_871, offset: 0x4D9C */
  __IO uint32_t DENALI_PHY_872;                    /**< DENALI_PHY_872, offset: 0x4DA0 */
       uint8_t RESERVED_56[36];
  __IO uint32_t DENALI_PHY_882;                    /**< DENALI_PHY_882, offset: 0x4DC8 */
       uint8_t RESERVED_57[588];
  __IO uint32_t DENALI_PHY_1030;                   /**< DENALI_PHY_1030, offset: 0x5018 */
       uint8_t RESERVED_58[96];
  __IO uint32_t DENALI_PHY_1055;                   /**< DENALI_PHY_1055, offset: 0x507C */
       uint8_t RESERVED_59[28];
  __IO uint32_t DENALI_PHY_1063;                   /**< DENALI_PHY_1063, offset: 0x509C */
       uint8_t RESERVED_60[888];
  __IO uint32_t DENALI_PHY_1286;                   /**< DENALI_PHY_1286, offset: 0x5418 */
       uint8_t RESERVED_61[96];
  __IO uint32_t DENALI_PHY_1311;                   /**< DENALI_PHY_1311, offset: 0x547C */
       uint8_t RESERVED_62[28];
  __IO uint32_t DENALI_PHY_1319;                   /**< DENALI_PHY_1319, offset: 0x549C */
       uint8_t RESERVED_63[864];
  __IO uint32_t DENALI_PHY_1536;                   /**< DENALI_PHY_1536, offset: 0x5800 */
  __IO uint32_t DENALI_PHY_1537;                   /**< DENALI_PHY_1537, offset: 0x5804 */
       uint8_t RESERVED_64[36];
  __IO uint32_t DENALI_PHY_1547;                   /**< DENALI_PHY_1547, offset: 0x582C */
       uint8_t RESERVED_65[28];
  __IO uint32_t DENALI_PHY_1555;                   /**< DENALI_PHY_1555, offset: 0x584C */
       uint8_t RESERVED_66[32];
  __I  uint32_t DENALI_PHY_1564;                   /**< DENALI_PHY_1564, offset: 0x5870 */
  __IO uint32_t DENALI_PHY_1565;                   /**< DENALI_PHY_1565, offset: 0x5874 */
  __IO uint32_t DENALI_PHY_1566;                   /**< DENALI_PHY_1566, offset: 0x5878 */
       uint8_t RESERVED_67[8];
  __IO uint32_t DENALI_PHY_1569;                   /**< DENALI_PHY_1569, offset: 0x5884 */
       uint8_t RESERVED_68[40];
  __IO uint32_t DENALI_PHY_1580;                   /**< DENALI_PHY_1580, offset: 0x58B0 */
       uint8_t RESERVED_69[4];
  __IO uint32_t DENALI_PHY_1582;                   /**< DENALI_PHY_1582, offset: 0x58B8 */
       uint8_t RESERVED_70[44];
  __IO uint32_t DENALI_PHY_1594;                   /**< DENALI_PHY_1594, offset: 0x58E8 */
       uint8_t RESERVED_71[48];
  __IO uint32_t DENALI_PHY_1607;                   /**< DENALI_PHY_1607, offset: 0x591C */
  __IO uint32_t DENALI_PHY_1608;                   /**< DENALI_PHY_1608, offset: 0x5920 */
       uint8_t RESERVED_72[52];
  __IO uint32_t DENALI_PHY_1622;                   /**< DENALI_PHY_1622, offset: 0x5958 */
       uint8_t RESERVED_73[4];
  __IO uint32_t DENALI_PHY_1624;                   /**< DENALI_PHY_1624, offset: 0x5960 */
  __IO uint32_t DENALI_PHY_1625;                   /**< DENALI_PHY_1625, offset: 0x5964 */
  __IO uint32_t DENALI_PHY_1626;                   /**< DENALI_PHY_1626, offset: 0x5968 */
       uint8_t RESERVED_74[32];
  __IO uint32_t DENALI_PHY_1635;                   /**< DENALI_PHY_1635, offset: 0x598C */
  __IO uint32_t DENALI_PHY_1636;                   /**< DENALI_PHY_1636, offset: 0x5990 */
  __IO uint32_t DENALI_PHY_1637;                   /**< DENALI_PHY_1637, offset: 0x5994 */
       uint8_t RESERVED_75[4];
  __IO uint32_t DENALI_PHY_1639;                   /**< DENALI_PHY_1639, offset: 0x599C */
       uint8_t RESERVED_76[4];
  __IO uint32_t DENALI_PHY_1641;                   /**< DENALI_PHY_1641, offset: 0x59A4 */
  __IO uint32_t DENALI_PHY_1642;                   /**< DENALI_PHY_1642, offset: 0x59A8 */
  __IO uint32_t DENALI_PHY_1643;                   /**< DENALI_PHY_1643, offset: 0x59AC */
  __IO uint32_t DENALI_PHY_1644;                   /**< DENALI_PHY_1644, offset: 0x59B0 */
  __IO uint32_t DENALI_PHY_1645;                   /**< DENALI_PHY_1645, offset: 0x59B4 */
  __IO uint32_t DENALI_PHY_1646;                   /**< DENALI_PHY_1646, offset: 0x59B8 */
  __IO uint32_t DENALI_PHY_1647;                   /**< DENALI_PHY_1647, offset: 0x59BC */
  __IO uint32_t DENALI_PHY_1648;                   /**< DENALI_PHY_1648, offset: 0x59C0 */
  __IO uint32_t DENALI_PHY_1649;                   /**< DENALI_PHY_1649, offset: 0x59C4 */
  __IO uint32_t DENALI_PHY_1650;                   /**< DENALI_PHY_1650, offset: 0x59C8 */
  __IO uint32_t DENALI_PHY_1651;                   /**< DENALI_PHY_1651, offset: 0x59CC */
  __IO uint32_t DENALI_PHY_1652;                   /**< DENALI_PHY_1652, offset: 0x59D0 */
  __IO uint32_t DENALI_PHY_1653;                   /**< DENALI_PHY_1653, offset: 0x59D4 */
} LPDDR_Type;

/* ----------------------------------------------------------------------------
   -- LPDDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDDR_Register_Masks LPDDR Register Masks
 * @{
 */

/*! @name DENALI_CTL - DENALI_CTL_0..DENALI_CTL_614 */
/*! @{ */

#define LPDDR_DENALI_CTL_ADDR_CMP_EN_MASK        (0x1U)
#define LPDDR_DENALI_CTL_ADDR_CMP_EN_SHIFT       (0U)
/*! ADDR_CMP_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_ADDR_CMP_EN(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ADDR_CMP_EN_SHIFT)) & LPDDR_DENALI_CTL_ADDR_CMP_EN_MASK)

#define LPDDR_DENALI_CTL_AP_MASK                 (0x1U)
#define LPDDR_DENALI_CTL_AP_SHIFT                (0U)
/*! AP
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_AP(x)                   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AP_SHIFT)) & LPDDR_DENALI_CTL_AP_MASK)

#define LPDDR_DENALI_CTL_AXI0_R_PRIORITY_MASK    (0x7U)
#define LPDDR_DENALI_CTL_AXI0_R_PRIORITY_SHIFT   (0U)
#define LPDDR_DENALI_CTL_AXI0_R_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI0_R_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI0_R_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_AXI1_FIXED_PORT_PRIORITY_ENABLE_MASK (0x1U)
#define LPDDR_DENALI_CTL_AXI1_FIXED_PORT_PRIORITY_ENABLE_SHIFT (0U)
#define LPDDR_DENALI_CTL_AXI1_FIXED_PORT_PRIORITY_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI1_FIXED_PORT_PRIORITY_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI1_FIXED_PORT_PRIORITY_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI2_ALL_STROBES_USED_ENABLE_MASK (0x1U)
#define LPDDR_DENALI_CTL_AXI2_ALL_STROBES_USED_ENABLE_SHIFT (0U)
#define LPDDR_DENALI_CTL_AXI2_ALL_STROBES_USED_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI2_ALL_STROBES_USED_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI2_ALL_STROBES_USED_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI2_FIFO_TYPE_REG_MASK (0x3U)
#define LPDDR_DENALI_CTL_AXI2_FIFO_TYPE_REG_SHIFT (0U)
#define LPDDR_DENALI_CTL_AXI2_FIFO_TYPE_REG(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI2_FIFO_TYPE_REG_SHIFT)) & LPDDR_DENALI_CTL_AXI2_FIFO_TYPE_REG_MASK)

#define LPDDR_DENALI_CTL_AXI3_W_PRIORITY_MASK    (0x7U)
#define LPDDR_DENALI_CTL_AXI3_W_PRIORITY_SHIFT   (0U)
#define LPDDR_DENALI_CTL_AXI3_W_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI3_W_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI3_W_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_BANK_ADDR_INTLV_EN_MASK (0x1U)
#define LPDDR_DENALI_CTL_BANK_ADDR_INTLV_EN_SHIFT (0U)
/*! BANK_ADDR_INTLV_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_BANK_ADDR_INTLV_EN(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BANK_ADDR_INTLV_EN_SHIFT)) & LPDDR_DENALI_CTL_BANK_ADDR_INTLV_EN_MASK)

#define LPDDR_DENALI_CTL_BIST_ERR_COUNT_MASK     (0xFFFU)
#define LPDDR_DENALI_CTL_BIST_ERR_COUNT_SHIFT    (0U)
/*! BIST_ERR_COUNT - Indicates the number of BIST errors found when the BIST_TEST_MODE parameter is programmed to 1, 2 or 3. */
#define LPDDR_DENALI_CTL_BIST_ERR_COUNT(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BIST_ERR_COUNT_SHIFT)) & LPDDR_DENALI_CTL_BIST_ERR_COUNT_MASK)

#define LPDDR_DENALI_CTL_CASLAT_LIN_F0_MASK      (0x7FU)
#define LPDDR_DENALI_CTL_CASLAT_LIN_F0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_CASLAT_LIN_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CASLAT_LIN_F0_SHIFT)) & LPDDR_DENALI_CTL_CASLAT_LIN_F0_MASK)

#define LPDDR_DENALI_CTL_CASLAT_LIN_F2_MASK      (0x7FU)
#define LPDDR_DENALI_CTL_CASLAT_LIN_F2_SHIFT     (0U)
#define LPDDR_DENALI_CTL_CASLAT_LIN_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CASLAT_LIN_F2_SHIFT)) & LPDDR_DENALI_CTL_CASLAT_LIN_F2_MASK)

#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F1_MASK  (0x1U)
#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F1_SHIFT)) & LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F1_MASK)

#define LPDDR_DENALI_CTL_CKE_INACTIVE_MASK       (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_CKE_INACTIVE_SHIFT      (0U)
#define LPDDR_DENALI_CTL_CKE_INACTIVE(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CKE_INACTIVE_SHIFT)) & LPDDR_DENALI_CTL_CKE_INACTIVE_MASK)

#define LPDDR_DENALI_CTL_CKSRX_F2_MASK           (0xFFU)
#define LPDDR_DENALI_CTL_CKSRX_F2_SHIFT          (0U)
/*! CKSRX_F2 - Clock stable delay on self-refresh exit for frequency set 2. */
#define LPDDR_DENALI_CTL_CKSRX_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CKSRX_F2_SHIFT)) & LPDDR_DENALI_CTL_CKSRX_F2_MASK)

#define LPDDR_DENALI_CTL_CTRLUPD_REQ_PER_AREF_EN_MASK (0x1U)
#define LPDDR_DENALI_CTL_CTRLUPD_REQ_PER_AREF_EN_SHIFT (0U)
/*! CTRLUPD_REQ_PER_AREF_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_CTRLUPD_REQ_PER_AREF_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CTRLUPD_REQ_PER_AREF_EN_SHIFT)) & LPDDR_DENALI_CTL_CTRLUPD_REQ_PER_AREF_EN_MASK)

#define LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS1_MASK  (0xFU)
#define LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS1_SHIFT (0U)
#define LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS1_SHIFT)) & LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS1_MASK)

#define LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS0_MASK  (0xFU)
#define LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS0_SHIFT (0U)
#define LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS0_SHIFT)) & LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS0_MASK)

#define LPDDR_DENALI_CTL_DFIBUS_BOOT_FREQ_MASK   (0x3U)
#define LPDDR_DENALI_CTL_DFIBUS_BOOT_FREQ_SHIFT  (0U)
/*! DFIBUS_BOOT_FREQ - Defines the DFI bus boot frequency. */
#define LPDDR_DENALI_CTL_DFIBUS_BOOT_FREQ(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFIBUS_BOOT_FREQ_SHIFT)) & LPDDR_DENALI_CTL_DFIBUS_BOOT_FREQ_MASK)

#define LPDDR_DENALI_CTL_DFI_ERROR_MASK          (0x1FU)
#define LPDDR_DENALI_CTL_DFI_ERROR_SHIFT         (0U)
#define LPDDR_DENALI_CTL_DFI_ERROR(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFI_ERROR_SHIFT)) & LPDDR_DENALI_CTL_DFI_ERROR_MASK)

#define LPDDR_DENALI_CTL_DFS_ALWAYS_WRITE_FSP_MASK (0x1U)
#define LPDDR_DENALI_CTL_DFS_ALWAYS_WRITE_FSP_SHIFT (0U)
/*! DFS_ALWAYS_WRITE_FSP
 *  0b0..The FSP mode registers may or may not be written
 *  0b1..Write the FSP mode registers
 */
#define LPDDR_DENALI_CTL_DFS_ALWAYS_WRITE_FSP(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFS_ALWAYS_WRITE_FSP_SHIFT)) & LPDDR_DENALI_CTL_DFS_ALWAYS_WRITE_FSP_MASK)

#define LPDDR_DENALI_CTL_DISABLE_RD_INTERLEAVE_MASK (0x1U)
#define LPDDR_DENALI_CTL_DISABLE_RD_INTERLEAVE_SHIFT (0U)
/*! DISABLE_RD_INTERLEAVE
 *  0b0..Allow read data interleaving
 *  0b1..Disable read data interleaving
 */
#define LPDDR_DENALI_CTL_DISABLE_RD_INTERLEAVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DISABLE_RD_INTERLEAVE_SHIFT)) & LPDDR_DENALI_CTL_DISABLE_RD_INTERLEAVE_MASK)

#define LPDDR_DENALI_CTL_DQS_OSC_PERIOD_MASK     (0x7FFFU)
#define LPDDR_DENALI_CTL_DQS_OSC_PERIOD_SHIFT    (0U)
#define LPDDR_DENALI_CTL_DQS_OSC_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DQS_OSC_PERIOD_SHIFT)) & LPDDR_DENALI_CTL_DQS_OSC_PERIOD_MASK)

#define LPDDR_DENALI_CTL_EN_ODT_ASSERT_EXCEPT_RD_MASK (0x1U)
#define LPDDR_DENALI_CTL_EN_ODT_ASSERT_EXCEPT_RD_SHIFT (0U)
/*! EN_ODT_ASSERT_EXCEPT_RD
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_EN_ODT_ASSERT_EXCEPT_RD(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_EN_ODT_ASSERT_EXCEPT_RD_SHIFT)) & LPDDR_DENALI_CTL_EN_ODT_ASSERT_EXCEPT_RD_MASK)

#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F0_MASK (0x3U)
#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F0_SHIFT (0U)
/*! FREQ_CHANGE_TYPE_F0 - Defines the encoded frequency driven out on the cntrl_freq_change_req_type signal during a frequency change operation. */
#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F0_SHIFT)) & LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F0_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_FREQ_MASK       (0xFFU)
#define LPDDR_DENALI_CTL_INT_ACK_FREQ_SHIFT      (0U)
#define LPDDR_DENALI_CTL_INT_ACK_FREQ(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_FREQ_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_FREQ_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_TIMEOUT_MASK    (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_INT_ACK_TIMEOUT_SHIFT   (0U)
#define LPDDR_DENALI_CTL_INT_ACK_TIMEOUT(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_TIMEOUT_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_TIMEOUT_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_TRAINING_MASK   (0xFFFFU)
#define LPDDR_DENALI_CTL_INT_ACK_TRAINING_SHIFT  (0U)
#define LPDDR_DENALI_CTL_INT_ACK_TRAINING(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_TRAINING_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_TRAINING_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_FREQ_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_INT_MASK_FREQ_SHIFT     (0U)
#define LPDDR_DENALI_CTL_INT_MASK_FREQ(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_FREQ_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_FREQ_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_MASTER_MASK    (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_INT_MASK_MASTER_SHIFT   (0U)
/*! INT_MASK_MASTER
 *  0b00000000000000000000000000000000..Do not mask interrupt
 *  0b00000000000000000000000000000001..Mask interrupt
 */
#define LPDDR_DENALI_CTL_INT_MASK_MASTER(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_MASTER_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_MASTER_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_TIMEOUT_MASK   (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_INT_MASK_TIMEOUT_SHIFT  (0U)
#define LPDDR_DENALI_CTL_INT_MASK_TIMEOUT(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_TIMEOUT_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_TIMEOUT_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_TRAINING_MASK  (0xFFFFU)
#define LPDDR_DENALI_CTL_INT_MASK_TRAINING_SHIFT (0U)
#define LPDDR_DENALI_CTL_INT_MASK_TRAINING(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_TRAINING_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_TRAINING_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_FREQ_MASK    (0xFFU)
#define LPDDR_DENALI_CTL_INT_STATUS_FREQ_SHIFT   (0U)
#define LPDDR_DENALI_CTL_INT_STATUS_FREQ(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_FREQ_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_FREQ_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_MASTER_MASK  (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_INT_STATUS_MASTER_SHIFT (0U)
#define LPDDR_DENALI_CTL_INT_STATUS_MASTER(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_MASTER_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_MASTER_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_TIMEOUT_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_INT_STATUS_TIMEOUT_SHIFT (0U)
#define LPDDR_DENALI_CTL_INT_STATUS_TIMEOUT(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_TIMEOUT_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_TIMEOUT_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_TRAINING_MASK (0xFFFFU)
#define LPDDR_DENALI_CTL_INT_STATUS_TRAINING_SHIFT (0U)
#define LPDDR_DENALI_CTL_INT_STATUS_TRAINING(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_TRAINING_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_TRAINING_MASK)

#define LPDDR_DENALI_CTL_IN_ORDER_ACCEPT_MASK    (0x1U)
#define LPDDR_DENALI_CTL_IN_ORDER_ACCEPT_SHIFT   (0U)
/*! IN_ORDER_ACCEPT - Forces the controller to accept commands in the order in which they are placed in the command queue.
 *  0b0..Uses the selection logic to select the ideal command for execution
 *  0b1..Disables the selection logic and executes commands in order
 */
#define LPDDR_DENALI_CTL_IN_ORDER_ACCEPT(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_IN_ORDER_ACCEPT_SHIFT)) & LPDDR_DENALI_CTL_IN_ORDER_ACCEPT_MASK)

#define LPDDR_DENALI_CTL_LPDDR2_S4_MASK          (0x1U)
#define LPDDR_DENALI_CTL_LPDDR2_S4_SHIFT         (0U)
#define LPDDR_DENALI_CTL_LPDDR2_S4(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPDDR2_S4_SHIFT)) & LPDDR_DENALI_CTL_LPDDR2_S4_MASK)

#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F2_MASK (0xFU)
#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F2_SHIFT (0U)
/*! LPI_IDLE_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when controller is idle for frequency set 2. */
#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F2_MASK   (0xFU)
#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F2_SHIFT  (0U)
/*! LPI_PD_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when
 *    memory is in any of the power-down states (with or without memory clock gating) for frequency
 *    set 2.
 */
#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F2(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F0_MASK (0xFU)
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F0_SHIFT (0U)
/*! LPI_SRPD_LONG_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be
 *    driven when memory is in the self-refresh power-down long state (with or without memory clock
 *    gating), for frequency set 0.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F1_MASK (0xFU)
#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F1_SHIFT (0U)
/*! LPI_SRPD_SHORT_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be
 *    driven when memory is in the self-refresh power-down short state (with or without memory clock
 *    gating), for frequency set 1.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F0_MASK (0xFU)
#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F0_SHIFT (0U)
/*! LPI_SR_LONG_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven
 *    when memory is in the self-refresh long state (with or without memory clock gating) for
 *    frequency set 0.
 */
#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F1_MASK (0xFU)
#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F1_SHIFT (0U)
/*! LPI_SR_SHORT_WAKEUP_F1 - LPI_SR_SHORT_WAKEUP_F1 */
#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_TIMER_COUNT_MASK    (0xFFFU)
#define LPDDR_DENALI_CTL_LPI_TIMER_COUNT_SHIFT   (0U)
/*! LPI_TIMER_COUNT - Defines the LPI timer count. */
#define LPDDR_DENALI_CTL_LPI_TIMER_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_TIMER_COUNT_SHIFT)) & LPDDR_DENALI_CTL_LPI_TIMER_COUNT_MASK)

#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F2_MASK (0xFU)
#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F2_SHIFT (0U)
/*! LPI_TIMER_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when the LPI timer expires for frequency set 2. */
#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_EXIT_EN_MASK    (0xFU)
#define LPDDR_DENALI_CTL_LP_AUTO_EXIT_EN_SHIFT   (0U)
/*! LP_AUTO_EXIT_EN - Enable auto exit from each of the low power states when a read or write command enters the command queue. */
#define LPDDR_DENALI_CTL_LP_AUTO_EXIT_EN(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_EXIT_EN_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_EXIT_EN_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_SR_SHORT_IDLE_MASK (0xFFFU)
#define LPDDR_DENALI_CTL_LP_AUTO_SR_SHORT_IDLE_SHIFT (0U)
/*! LP_AUTO_SR_SHORT_IDLE - Defines the idle time (in controller clocks) until the controller will
 *    automatically issue an entry into the self-refresh short or self-refresh power-down short (with
 *    or without memory clock gating) low power states.
 */
#define LPDDR_DENALI_CTL_LP_AUTO_SR_SHORT_IDLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_SR_SHORT_IDLE_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_SR_SHORT_IDLE_MASK)

#define LPDDR_DENALI_CTL_MR1_DATA_F0_0_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_MR1_DATA_F0_0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_MR1_DATA_F0_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR1_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR1_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR1_DATA_F1_1_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_MR1_DATA_F1_1_SHIFT     (0U)
#define LPDDR_DENALI_CTL_MR1_DATA_F1_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR1_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR1_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR1_DATA_F2_0_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_MR1_DATA_F2_0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_MR1_DATA_F2_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR1_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR1_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR3_DATA_F1_0_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_MR3_DATA_F1_0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_MR3_DATA_F1_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR3_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR3_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR4_DATA_F0_1_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_MR4_DATA_F0_1_SHIFT     (0U)
#define LPDDR_DENALI_CTL_MR4_DATA_F0_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR4_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR4_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR4_DATA_F2_0_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_MR4_DATA_F2_0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_MR4_DATA_F2_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR4_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR4_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR11_DATA_F0_1_MASK     (0xFFU)
#define LPDDR_DENALI_CTL_MR11_DATA_F0_1_SHIFT    (0U)
#define LPDDR_DENALI_CTL_MR11_DATA_F0_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR11_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR11_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR11_DATA_F2_0_MASK     (0xFFU)
#define LPDDR_DENALI_CTL_MR11_DATA_F2_0_SHIFT    (0U)
#define LPDDR_DENALI_CTL_MR11_DATA_F2_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR11_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR11_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR12_DATA_F1_1_MASK     (0xFFU)
#define LPDDR_DENALI_CTL_MR12_DATA_F1_1_SHIFT    (0U)
#define LPDDR_DENALI_CTL_MR12_DATA_F1_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR12_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR12_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR13_DATA_0_MASK        (0xFFU)
#define LPDDR_DENALI_CTL_MR13_DATA_0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_MR13_DATA_0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR13_DATA_0_SHIFT)) & LPDDR_DENALI_CTL_MR13_DATA_0_MASK)

#define LPDDR_DENALI_CTL_MR14_DATA_F1_1_MASK     (0xFFU)
#define LPDDR_DENALI_CTL_MR14_DATA_F1_1_SHIFT    (0U)
#define LPDDR_DENALI_CTL_MR14_DATA_F1_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR14_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR14_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR16_DATA_0_MASK        (0xFFU)
#define LPDDR_DENALI_CTL_MR16_DATA_0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_MR16_DATA_0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR16_DATA_0_SHIFT)) & LPDDR_DENALI_CTL_MR16_DATA_0_MASK)

#define LPDDR_DENALI_CTL_MR20_DATA_1_MASK        (0xFFU)
#define LPDDR_DENALI_CTL_MR20_DATA_1_SHIFT       (0U)
#define LPDDR_DENALI_CTL_MR20_DATA_1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR20_DATA_1_SHIFT)) & LPDDR_DENALI_CTL_MR20_DATA_1_MASK)

#define LPDDR_DENALI_CTL_MR22_DATA_F1_0_MASK     (0xFFU)
#define LPDDR_DENALI_CTL_MR22_DATA_F1_0_SHIFT    (0U)
#define LPDDR_DENALI_CTL_MR22_DATA_F1_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR22_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR22_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR23_DATA_MASK          (0xFFU)
#define LPDDR_DENALI_CTL_MR23_DATA_SHIFT         (0U)
/*! MR23_DATA - Data to program into memory mode register 23. */
#define LPDDR_DENALI_CTL_MR23_DATA(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR23_DATA_SHIFT)) & LPDDR_DENALI_CTL_MR23_DATA_MASK)

#define LPDDR_DENALI_CTL_MRR_ERROR_STATUS_MASK   (0x1U)
#define LPDDR_DENALI_CTL_MRR_ERROR_STATUS_SHIFT  (0U)
/*! MRR_ERROR_STATUS
 *  0b0..MRR was not issued while in self-refresh
 *  0b1..MRR was issued while in self-refresh
 */
#define LPDDR_DENALI_CTL_MRR_ERROR_STATUS(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MRR_ERROR_STATUS_SHIFT)) & LPDDR_DENALI_CTL_MRR_ERROR_STATUS_MASK)

#define LPDDR_DENALI_CTL_MRSINGLE_DATA_1_MASK    (0xFFU)
#define LPDDR_DENALI_CTL_MRSINGLE_DATA_1_SHIFT   (0U)
#define LPDDR_DENALI_CTL_MRSINGLE_DATA_1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MRSINGLE_DATA_1_SHIFT)) & LPDDR_DENALI_CTL_MRSINGLE_DATA_1_MASK)

#define LPDDR_DENALI_CTL_MRW_DFS_UPDATE_FRC_MASK (0x3U)
#define LPDDR_DENALI_CTL_MRW_DFS_UPDATE_FRC_SHIFT (0U)
#define LPDDR_DENALI_CTL_MRW_DFS_UPDATE_FRC(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MRW_DFS_UPDATE_FRC_SHIFT)) & LPDDR_DENALI_CTL_MRW_DFS_UPDATE_FRC_MASK)

#define LPDDR_DENALI_CTL_NWR_F1_MASK             (0xFFU)
#define LPDDR_DENALI_CTL_NWR_F1_SHIFT            (0U)
#define LPDDR_DENALI_CTL_NWR_F1(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NWR_F1_SHIFT)) & LPDDR_DENALI_CTL_NWR_F1_MASK)

#define LPDDR_DENALI_CTL_ODT_RD_MAP_CS0_MASK     (0x3U)
#define LPDDR_DENALI_CTL_ODT_RD_MAP_CS0_SHIFT    (0U)
#define LPDDR_DENALI_CTL_ODT_RD_MAP_CS0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_RD_MAP_CS0_SHIFT)) & LPDDR_DENALI_CTL_ODT_RD_MAP_CS0_MASK)

#define LPDDR_DENALI_CTL_PBR_BANK_SELECT_DELAY_MASK (0xFU)
#define LPDDR_DENALI_CTL_PBR_BANK_SELECT_DELAY_SHIFT (0U)
/*! PBR_BANK_SELECT_DELAY - Defines the PBR bank select to command delay, the time from bank
 *    selection to when the command queue bank selection logic is guaranteed to have blocked the bank.
 */
#define LPDDR_DENALI_CTL_PBR_BANK_SELECT_DELAY(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PBR_BANK_SELECT_DELAY_SHIFT)) & LPDDR_DENALI_CTL_PBR_BANK_SELECT_DELAY_MASK)

#define LPDDR_DENALI_CTL_PBR_EN_MASK             (0x1U)
#define LPDDR_DENALI_CTL_PBR_EN_SHIFT            (0U)
/*! PBR_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PBR_EN(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PBR_EN_SHIFT)) & LPDDR_DENALI_CTL_PBR_EN_MASK)

#define LPDDR_DENALI_CTL_PHY_INDEP_TRAIN_MODE_MASK (0x1U)
#define LPDDR_DENALI_CTL_PHY_INDEP_TRAIN_MODE_SHIFT (0U)
/*! PHY_INDEP_TRAIN_MODE
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PHY_INDEP_TRAIN_MODE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PHY_INDEP_TRAIN_MODE_SHIFT)) & LPDDR_DENALI_CTL_PHY_INDEP_TRAIN_MODE_MASK)

#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F2_MASK (0x3U)
#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F2_SHIFT (0U)
/*! PREAMBLE_SUPPORT_F2 - Selects the preamble for read and write burst transfers for frequency set 2. */
#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F2_SHIFT)) & LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F2_MASK)

#define LPDDR_DENALI_CTL_PRIORITY_EN_MASK        (0x1U)
#define LPDDR_DENALI_CTL_PRIORITY_EN_SHIFT       (0U)
/*! PRIORITY_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PRIORITY_EN(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PRIORITY_EN_SHIFT)) & LPDDR_DENALI_CTL_PRIORITY_EN_MASK)

#define LPDDR_DENALI_CTL_PWRUP_SREFRESH_EXIT_MASK (0x1U)
#define LPDDR_DENALI_CTL_PWRUP_SREFRESH_EXIT_SHIFT (0U)
/*! PWRUP_SREFRESH_EXIT
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PWRUP_SREFRESH_EXIT(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PWRUP_SREFRESH_EXIT_SHIFT)) & LPDDR_DENALI_CTL_PWRUP_SREFRESH_EXIT_MASK)

#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F1_MASK  (0x1FU)
#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F1_SHIFT)) & LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F1_MASK)

#define LPDDR_DENALI_CTL_RDLAT_ADJ_F0_MASK       (0x7FU)
#define LPDDR_DENALI_CTL_RDLAT_ADJ_F0_SHIFT      (0U)
#define LPDDR_DENALI_CTL_RDLAT_ADJ_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RDLAT_ADJ_F0_SHIFT)) & LPDDR_DENALI_CTL_RDLAT_ADJ_F0_MASK)

#define LPDDR_DENALI_CTL_RDLAT_ADJ_F1_MASK       (0x7FU)
#define LPDDR_DENALI_CTL_RDLAT_ADJ_F1_SHIFT      (0U)
#define LPDDR_DENALI_CTL_RDLAT_ADJ_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RDLAT_ADJ_F1_SHIFT)) & LPDDR_DENALI_CTL_RDLAT_ADJ_F1_MASK)

#define LPDDR_DENALI_CTL_RDLAT_ADJ_F2_MASK       (0x7FU)
#define LPDDR_DENALI_CTL_RDLAT_ADJ_F2_SHIFT      (0U)
#define LPDDR_DENALI_CTL_RDLAT_ADJ_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RDLAT_ADJ_F2_SHIFT)) & LPDDR_DENALI_CTL_RDLAT_ADJ_F2_MASK)

#define LPDDR_DENALI_CTL_RD_TO_ODTH_F0_MASK      (0x3FU)
#define LPDDR_DENALI_CTL_RD_TO_ODTH_F0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_RD_TO_ODTH_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RD_TO_ODTH_F0_SHIFT)) & LPDDR_DENALI_CTL_RD_TO_ODTH_F0_MASK)

#define LPDDR_DENALI_CTL_RL3_SUPPORT_EN_MASK     (0x3U)
#define LPDDR_DENALI_CTL_RL3_SUPPORT_EN_SHIFT    (0U)
#define LPDDR_DENALI_CTL_RL3_SUPPORT_EN(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RL3_SUPPORT_EN_SHIFT)) & LPDDR_DENALI_CTL_RL3_SUPPORT_EN_MASK)

#define LPDDR_DENALI_CTL_RW2MRW_DLY_F1_MASK      (0x1FU)
#define LPDDR_DENALI_CTL_RW2MRW_DLY_F1_SHIFT     (0U)
#define LPDDR_DENALI_CTL_RW2MRW_DLY_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RW2MRW_DLY_F1_SHIFT)) & LPDDR_DENALI_CTL_RW2MRW_DLY_F1_MASK)

#define LPDDR_DENALI_CTL_START_MASK              (0x1U)
#define LPDDR_DENALI_CTL_START_SHIFT             (0U)
/*! START
 *  0b0..Controller is not in active mode.
 *  0b1..Initiate active mode for the controller.
 */
#define LPDDR_DENALI_CTL_START(x)                (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_START_SHIFT)) & LPDDR_DENALI_CTL_START_MASK)

#define LPDDR_DENALI_CTL_TCKELCMD_F0_MASK        (0x1FU)
#define LPDDR_DENALI_CTL_TCKELCMD_F0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TCKELCMD_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELCMD_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKELCMD_F0_MASK)

#define LPDDR_DENALI_CTL_TCKELCMD_F1_MASK        (0x1FU)
#define LPDDR_DENALI_CTL_TCKELCMD_F1_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TCKELCMD_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELCMD_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKELCMD_F1_MASK)

#define LPDDR_DENALI_CTL_TCKELCMD_F2_MASK        (0x1FU)
#define LPDDR_DENALI_CTL_TCKELCMD_F2_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TCKELCMD_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELCMD_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKELCMD_F2_MASK)

#define LPDDR_DENALI_CTL_TCKELCS_F1_MASK         (0x1FU)
#define LPDDR_DENALI_CTL_TCKELCS_F1_SHIFT        (0U)
#define LPDDR_DENALI_CTL_TCKELCS_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELCS_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKELCS_F1_MASK)

#define LPDDR_DENALI_CTL_TCKESR_F0_MASK          (0xFFU)
#define LPDDR_DENALI_CTL_TCKESR_F0_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TCKESR_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKESR_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKESR_F0_MASK)

#define LPDDR_DENALI_CTL_TCKESR_F1_MASK          (0xFFU)
#define LPDDR_DENALI_CTL_TCKESR_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TCKESR_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKESR_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKESR_F1_MASK)

#define LPDDR_DENALI_CTL_TCKESR_F2_MASK          (0xFFU)
#define LPDDR_DENALI_CTL_TCKESR_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TCKESR_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKESR_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKESR_F2_MASK)

#define LPDDR_DENALI_CTL_TCKFSPE_F0_MASK         (0x1FU)
#define LPDDR_DENALI_CTL_TCKFSPE_F0_SHIFT        (0U)
#define LPDDR_DENALI_CTL_TCKFSPE_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKFSPE_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKFSPE_F0_MASK)

#define LPDDR_DENALI_CTL_TDAL_F1_MASK            (0xFFU)
#define LPDDR_DENALI_CTL_TDAL_F1_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TDAL_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDAL_F1_SHIFT)) & LPDDR_DENALI_CTL_TDAL_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_INTERVAL_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F0_MASK (0x1FFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F1_MASK (0x1FFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F2_MASK (0x1FFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_MAX_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MIN_MASK   (0xFFFFU)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MIN_SHIFT  (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRLUPD_MIN(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRLUPD_MIN_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRLUPD_MIN_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F2_MASK (0xFU)
#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_LP_RESP_MASK       (0x7U)
#define LPDDR_DENALI_CTL_TDFI_LP_RESP_SHIFT      (0U)
/*! TDFI_LP_RESP - Defines the DFI tLP_RESP timing parameter (in DFI clocks), the maximum cycles
 *    between a dfi_lp_req assertion and a dfi_lp_ack assertion.
 */
#define LPDDR_DENALI_CTL_TDFI_LP_RESP(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_LP_RESP_SHIFT)) & LPDDR_DENALI_CTL_TDFI_LP_RESP_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE0_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE1_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE2_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_MAX_TYPE3_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F0_MASK (0xFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F1_MASK (0xFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F2_MASK (0xFFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYMSTR_RESP_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F0_MASK (0x7FFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F1_MASK (0x7FFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F2_MASK (0x7FFFFFU)
#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHYUPD_RESP_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F2_MASK  (0x7FU)
#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F1_MASK (0x7U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_WRLAT_MASK     (0x7FU)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRLAT_SHIFT    (0U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRLAT(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_WRLAT_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_WRLAT_MASK)

#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F1_MASK    (0x7FU)
#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F1_SHIFT   (0U)
#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_RDCSLAT_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_RDCSLAT_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_WRDATA_DELAY_MASK  (0xFFU)
#define LPDDR_DENALI_CTL_TDFI_WRDATA_DELAY_SHIFT (0U)
#define LPDDR_DENALI_CTL_TDFI_WRDATA_DELAY(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_WRDATA_DELAY_SHIFT)) & LPDDR_DENALI_CTL_TDFI_WRDATA_DELAY_MASK)

#define LPDDR_DENALI_CTL_TDQSCK_MAX_F0_MASK      (0xFU)
#define LPDDR_DENALI_CTL_TDQSCK_MAX_F0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_TDQSCK_MAX_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDQSCK_MAX_F0_SHIFT)) & LPDDR_DENALI_CTL_TDQSCK_MAX_F0_MASK)

#define LPDDR_DENALI_CTL_TDQSCK_MAX_F2_MASK      (0xFU)
#define LPDDR_DENALI_CTL_TDQSCK_MAX_F2_SHIFT     (0U)
#define LPDDR_DENALI_CTL_TDQSCK_MAX_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDQSCK_MAX_F2_SHIFT)) & LPDDR_DENALI_CTL_TDQSCK_MAX_F2_MASK)

#define LPDDR_DENALI_CTL_TESCKE_F0_MASK          (0x7U)
#define LPDDR_DENALI_CTL_TESCKE_F0_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TESCKE_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TESCKE_F0_SHIFT)) & LPDDR_DENALI_CTL_TESCKE_F0_MASK)

#define LPDDR_DENALI_CTL_TESCKE_F1_MASK          (0x7U)
#define LPDDR_DENALI_CTL_TESCKE_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TESCKE_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TESCKE_F1_SHIFT)) & LPDDR_DENALI_CTL_TESCKE_F1_MASK)

#define LPDDR_DENALI_CTL_TESCKE_F2_MASK          (0x7U)
#define LPDDR_DENALI_CTL_TESCKE_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TESCKE_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TESCKE_F2_SHIFT)) & LPDDR_DENALI_CTL_TESCKE_F2_MASK)

#define LPDDR_DENALI_CTL_TFAW_F0_MASK            (0x1FFU)
#define LPDDR_DENALI_CTL_TFAW_F0_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TFAW_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TFAW_F0_SHIFT)) & LPDDR_DENALI_CTL_TFAW_F0_MASK)

#define LPDDR_DENALI_CTL_TFAW_F2_MASK            (0x1FFU)
#define LPDDR_DENALI_CTL_TFAW_F2_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TFAW_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TFAW_F2_SHIFT)) & LPDDR_DENALI_CTL_TFAW_F2_MASK)

#define LPDDR_DENALI_CTL_TFC_F1_MASK             (0x3FFU)
#define LPDDR_DENALI_CTL_TFC_F1_SHIFT            (0U)
#define LPDDR_DENALI_CTL_TFC_F1(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TFC_F1_SHIFT)) & LPDDR_DENALI_CTL_TFC_F1_MASK)

#define LPDDR_DENALI_CTL_TFC_F2_MASK             (0x3FFU)
#define LPDDR_DENALI_CTL_TFC_F2_SHIFT            (0U)
#define LPDDR_DENALI_CTL_TFC_F2(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TFC_F2_SHIFT)) & LPDDR_DENALI_CTL_TFC_F2_MASK)

#define LPDDR_DENALI_CTL_TINIT3_F0_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT3_F0_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT3_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT3_F0_SHIFT)) & LPDDR_DENALI_CTL_TINIT3_F0_MASK)

#define LPDDR_DENALI_CTL_TINIT3_F1_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT3_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT3_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT3_F1_SHIFT)) & LPDDR_DENALI_CTL_TINIT3_F1_MASK)

#define LPDDR_DENALI_CTL_TINIT3_F2_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT3_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT3_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT3_F2_SHIFT)) & LPDDR_DENALI_CTL_TINIT3_F2_MASK)

#define LPDDR_DENALI_CTL_TINIT4_F0_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT4_F0_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT4_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT4_F0_SHIFT)) & LPDDR_DENALI_CTL_TINIT4_F0_MASK)

#define LPDDR_DENALI_CTL_TINIT4_F1_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT4_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT4_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT4_F1_SHIFT)) & LPDDR_DENALI_CTL_TINIT4_F1_MASK)

#define LPDDR_DENALI_CTL_TINIT4_F2_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT4_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT4_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT4_F2_SHIFT)) & LPDDR_DENALI_CTL_TINIT4_F2_MASK)

#define LPDDR_DENALI_CTL_TINIT5_F0_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT5_F0_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT5_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT5_F0_SHIFT)) & LPDDR_DENALI_CTL_TINIT5_F0_MASK)

#define LPDDR_DENALI_CTL_TINIT5_F1_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT5_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT5_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT5_F1_SHIFT)) & LPDDR_DENALI_CTL_TINIT5_F1_MASK)

#define LPDDR_DENALI_CTL_TINIT5_F2_MASK          (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT5_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TINIT5_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT5_F2_SHIFT)) & LPDDR_DENALI_CTL_TINIT5_F2_MASK)

#define LPDDR_DENALI_CTL_TINIT_F1_MASK           (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT_F1_SHIFT          (0U)
#define LPDDR_DENALI_CTL_TINIT_F1(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT_F1_SHIFT)) & LPDDR_DENALI_CTL_TINIT_F1_MASK)

#define LPDDR_DENALI_CTL_TINIT_F2_MASK           (0xFFFFFFU)
#define LPDDR_DENALI_CTL_TINIT_F2_SHIFT          (0U)
#define LPDDR_DENALI_CTL_TINIT_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT_F2_SHIFT)) & LPDDR_DENALI_CTL_TINIT_F2_MASK)

#define LPDDR_DENALI_CTL_TMRD_F0_MASK            (0xFFU)
#define LPDDR_DENALI_CTL_TMRD_F0_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TMRD_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRD_F0_SHIFT)) & LPDDR_DENALI_CTL_TMRD_F0_MASK)

#define LPDDR_DENALI_CTL_TMRRI_F2_MASK           (0xFFU)
#define LPDDR_DENALI_CTL_TMRRI_F2_SHIFT          (0U)
#define LPDDR_DENALI_CTL_TMRRI_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRRI_F2_SHIFT)) & LPDDR_DENALI_CTL_TMRRI_F2_MASK)

#define LPDDR_DENALI_CTL_TMRWCKEL_F0_MASK        (0x1FU)
#define LPDDR_DENALI_CTL_TMRWCKEL_F0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TMRWCKEL_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRWCKEL_F0_SHIFT)) & LPDDR_DENALI_CTL_TMRWCKEL_F0_MASK)

#define LPDDR_DENALI_CTL_TMRWCKEL_F2_MASK        (0x1FU)
#define LPDDR_DENALI_CTL_TMRWCKEL_F2_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TMRWCKEL_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRWCKEL_F2_SHIFT)) & LPDDR_DENALI_CTL_TMRWCKEL_F2_MASK)

#define LPDDR_DENALI_CTL_TODTH_RD_F2_MASK        (0xFU)
#define LPDDR_DENALI_CTL_TODTH_RD_F2_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TODTH_RD_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTH_RD_F2_SHIFT)) & LPDDR_DENALI_CTL_TODTH_RD_F2_MASK)

#define LPDDR_DENALI_CTL_TODTH_WR_F1_MASK        (0xFU)
#define LPDDR_DENALI_CTL_TODTH_WR_F1_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TODTH_WR_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTH_WR_F1_SHIFT)) & LPDDR_DENALI_CTL_TODTH_WR_F1_MASK)

#define LPDDR_DENALI_CTL_TODTL_2CMD_F0_MASK      (0xFFU)
#define LPDDR_DENALI_CTL_TODTL_2CMD_F0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_TODTL_2CMD_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTL_2CMD_F0_SHIFT)) & LPDDR_DENALI_CTL_TODTL_2CMD_F0_MASK)

#define LPDDR_DENALI_CTL_TOSCO_F1_MASK           (0xFFU)
#define LPDDR_DENALI_CTL_TOSCO_F1_SHIFT          (0U)
#define LPDDR_DENALI_CTL_TOSCO_F1(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TOSCO_F1_SHIFT)) & LPDDR_DENALI_CTL_TOSCO_F1_MASK)

#define LPDDR_DENALI_CTL_TPDEX_F0_MASK           (0xFFFFU)
#define LPDDR_DENALI_CTL_TPDEX_F0_SHIFT          (0U)
#define LPDDR_DENALI_CTL_TPDEX_F0(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TPDEX_F0_SHIFT)) & LPDDR_DENALI_CTL_TPDEX_F0_MASK)

#define LPDDR_DENALI_CTL_TPDEX_F2_MASK           (0xFFFFU)
#define LPDDR_DENALI_CTL_TPDEX_F2_SHIFT          (0U)
#define LPDDR_DENALI_CTL_TPDEX_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TPDEX_F2_SHIFT)) & LPDDR_DENALI_CTL_TPDEX_F2_MASK)

#define LPDDR_DENALI_CTL_TRAS_MAX_F0_MASK        (0x1FFFFU)
#define LPDDR_DENALI_CTL_TRAS_MAX_F0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TRAS_MAX_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_MAX_F0_SHIFT)) & LPDDR_DENALI_CTL_TRAS_MAX_F0_MASK)

#define LPDDR_DENALI_CTL_TRAS_MAX_F1_MASK        (0x1FFFFU)
#define LPDDR_DENALI_CTL_TRAS_MAX_F1_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TRAS_MAX_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_MAX_F1_SHIFT)) & LPDDR_DENALI_CTL_TRAS_MAX_F1_MASK)

#define LPDDR_DENALI_CTL_TRAS_MAX_F2_MASK        (0x1FFFFU)
#define LPDDR_DENALI_CTL_TRAS_MAX_F2_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TRAS_MAX_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_MAX_F2_SHIFT)) & LPDDR_DENALI_CTL_TRAS_MAX_F2_MASK)

#define LPDDR_DENALI_CTL_TRAS_MIN_F0_MASK        (0x1FFU)
#define LPDDR_DENALI_CTL_TRAS_MIN_F0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TRAS_MIN_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_MIN_F0_SHIFT)) & LPDDR_DENALI_CTL_TRAS_MIN_F0_MASK)

#define LPDDR_DENALI_CTL_TRAS_MIN_F2_MASK        (0x1FFU)
#define LPDDR_DENALI_CTL_TRAS_MIN_F2_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TRAS_MIN_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_MIN_F2_SHIFT)) & LPDDR_DENALI_CTL_TRAS_MIN_F2_MASK)

#define LPDDR_DENALI_CTL_TRC_F1_MASK             (0x1FFU)
#define LPDDR_DENALI_CTL_TRC_F1_SHIFT            (0U)
#define LPDDR_DENALI_CTL_TRC_F1(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRC_F1_SHIFT)) & LPDDR_DENALI_CTL_TRC_F1_MASK)

#define LPDDR_DENALI_CTL_TREFI_PB_F0_MASK        (0xFFFFU)
#define LPDDR_DENALI_CTL_TREFI_PB_F0_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TREFI_PB_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREFI_PB_F0_SHIFT)) & LPDDR_DENALI_CTL_TREFI_PB_F0_MASK)

#define LPDDR_DENALI_CTL_TREFI_PB_F1_MASK        (0xFFFFU)
#define LPDDR_DENALI_CTL_TREFI_PB_F1_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TREFI_PB_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREFI_PB_F1_SHIFT)) & LPDDR_DENALI_CTL_TREFI_PB_F1_MASK)

#define LPDDR_DENALI_CTL_TREFI_PB_F2_MASK        (0xFFFFU)
#define LPDDR_DENALI_CTL_TREFI_PB_F2_SHIFT       (0U)
#define LPDDR_DENALI_CTL_TREFI_PB_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREFI_PB_F2_SHIFT)) & LPDDR_DENALI_CTL_TREFI_PB_F2_MASK)

#define LPDDR_DENALI_CTL_TREF_F0_MASK            (0xFFFFFU)
#define LPDDR_DENALI_CTL_TREF_F0_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TREF_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREF_F0_SHIFT)) & LPDDR_DENALI_CTL_TREF_F0_MASK)

#define LPDDR_DENALI_CTL_TREF_F1_MASK            (0xFFFFFU)
#define LPDDR_DENALI_CTL_TREF_F1_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TREF_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREF_F1_SHIFT)) & LPDDR_DENALI_CTL_TREF_F1_MASK)

#define LPDDR_DENALI_CTL_TREF_F2_MASK            (0xFFFFFU)
#define LPDDR_DENALI_CTL_TREF_F2_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TREF_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREF_F2_SHIFT)) & LPDDR_DENALI_CTL_TREF_F2_MASK)

#define LPDDR_DENALI_CTL_TREF_INTERVAL_MASK      (0xFFFFFU)
#define LPDDR_DENALI_CTL_TREF_INTERVAL_SHIFT     (0U)
/*! TREF_INTERVAL - Defines the cycles between refreshes to different chip selects. */
#define LPDDR_DENALI_CTL_TREF_INTERVAL(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TREF_INTERVAL_SHIFT)) & LPDDR_DENALI_CTL_TREF_INTERVAL_MASK)

#define LPDDR_DENALI_CTL_TRFC_F1_MASK            (0x3FFU)
#define LPDDR_DENALI_CTL_TRFC_F1_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TRFC_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRFC_F1_SHIFT)) & LPDDR_DENALI_CTL_TRFC_F1_MASK)

#define LPDDR_DENALI_CTL_TRFC_F2_MASK            (0x3FFU)
#define LPDDR_DENALI_CTL_TRFC_F2_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TRFC_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRFC_F2_SHIFT)) & LPDDR_DENALI_CTL_TRFC_F2_MASK)

#define LPDDR_DENALI_CTL_TRP_AB_F1_MASK          (0xFFU)
#define LPDDR_DENALI_CTL_TRP_AB_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TRP_AB_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRP_AB_F1_SHIFT)) & LPDDR_DENALI_CTL_TRP_AB_F1_MASK)

#define LPDDR_DENALI_CTL_TRRD_F0_MASK            (0xFFU)
#define LPDDR_DENALI_CTL_TRRD_F0_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TRRD_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRRD_F0_SHIFT)) & LPDDR_DENALI_CTL_TRRD_F0_MASK)

#define LPDDR_DENALI_CTL_TRRD_F2_MASK            (0xFFU)
#define LPDDR_DENALI_CTL_TRRD_F2_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TRRD_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRRD_F2_SHIFT)) & LPDDR_DENALI_CTL_TRRD_F2_MASK)

#define LPDDR_DENALI_CTL_TRST_PWRON_MASK         (0xFFFFFFFFU)
#define LPDDR_DENALI_CTL_TRST_PWRON_SHIFT        (0U)
#define LPDDR_DENALI_CTL_TRST_PWRON(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRST_PWRON_SHIFT)) & LPDDR_DENALI_CTL_TRST_PWRON_MASK)

#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F0_MASK   (0x3FFU)
#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F0_SHIFT  (0U)
#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F0(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVRCG_DISABLE_F0_SHIFT)) & LPDDR_DENALI_CTL_TVRCG_DISABLE_F0_MASK)

#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F1_MASK    (0x3FFU)
#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F1_SHIFT   (0U)
#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVRCG_ENABLE_F1_SHIFT)) & LPDDR_DENALI_CTL_TVRCG_ENABLE_F1_MASK)

#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F2_MASK    (0x3FFU)
#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F2_SHIFT   (0U)
#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVRCG_ENABLE_F2_SHIFT)) & LPDDR_DENALI_CTL_TVRCG_ENABLE_F2_MASK)

#define LPDDR_DENALI_CTL_TVREF_LONG_F0_MASK      (0xFFFFFU)
#define LPDDR_DENALI_CTL_TVREF_LONG_F0_SHIFT     (0U)
#define LPDDR_DENALI_CTL_TVREF_LONG_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVREF_LONG_F0_SHIFT)) & LPDDR_DENALI_CTL_TVREF_LONG_F0_MASK)

#define LPDDR_DENALI_CTL_TVREF_LONG_F1_MASK      (0xFFFFFU)
#define LPDDR_DENALI_CTL_TVREF_LONG_F1_SHIFT     (0U)
#define LPDDR_DENALI_CTL_TVREF_LONG_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVREF_LONG_F1_SHIFT)) & LPDDR_DENALI_CTL_TVREF_LONG_F1_MASK)

#define LPDDR_DENALI_CTL_TVREF_LONG_F2_MASK      (0xFFFFFU)
#define LPDDR_DENALI_CTL_TVREF_LONG_F2_SHIFT     (0U)
#define LPDDR_DENALI_CTL_TVREF_LONG_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVREF_LONG_F2_SHIFT)) & LPDDR_DENALI_CTL_TVREF_LONG_F2_MASK)

#define LPDDR_DENALI_CTL_TWR_F1_MASK             (0xFFU)
#define LPDDR_DENALI_CTL_TWR_F1_SHIFT            (0U)
#define LPDDR_DENALI_CTL_TWR_F1(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TWR_F1_SHIFT)) & LPDDR_DENALI_CTL_TWR_F1_MASK)

#define LPDDR_DENALI_CTL_TWTR_F1_MASK            (0x3FU)
#define LPDDR_DENALI_CTL_TWTR_F1_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TWTR_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TWTR_F1_SHIFT)) & LPDDR_DENALI_CTL_TWTR_F1_MASK)

#define LPDDR_DENALI_CTL_TXSR_F0_MASK            (0xFFFFU)
#define LPDDR_DENALI_CTL_TXSR_F0_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TXSR_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TXSR_F0_SHIFT)) & LPDDR_DENALI_CTL_TXSR_F0_MASK)

#define LPDDR_DENALI_CTL_TXSR_F1_MASK            (0xFFFFU)
#define LPDDR_DENALI_CTL_TXSR_F1_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TXSR_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TXSR_F1_SHIFT)) & LPDDR_DENALI_CTL_TXSR_F1_MASK)

#define LPDDR_DENALI_CTL_TXSR_F2_MASK            (0xFFFFU)
#define LPDDR_DENALI_CTL_TXSR_F2_SHIFT           (0U)
#define LPDDR_DENALI_CTL_TXSR_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TXSR_F2_SHIFT)) & LPDDR_DENALI_CTL_TXSR_F2_MASK)

#define LPDDR_DENALI_CTL_TZQCAL_F1_MASK          (0xFFFU)
#define LPDDR_DENALI_CTL_TZQCAL_F1_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TZQCAL_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQCAL_F1_SHIFT)) & LPDDR_DENALI_CTL_TZQCAL_F1_MASK)

#define LPDDR_DENALI_CTL_TZQLAT_F0_MASK          (0x7FU)
#define LPDDR_DENALI_CTL_TZQLAT_F0_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TZQLAT_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQLAT_F0_SHIFT)) & LPDDR_DENALI_CTL_TZQLAT_F0_MASK)

#define LPDDR_DENALI_CTL_TZQLAT_F2_MASK          (0x7FU)
#define LPDDR_DENALI_CTL_TZQLAT_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_TZQLAT_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQLAT_F2_SHIFT)) & LPDDR_DENALI_CTL_TZQLAT_F2_MASK)

#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F0_MASK  (0x1FU)
#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F0_SHIFT (0U)
#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F0_SHIFT)) & LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F0_MASK)

#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F1_MASK  (0x1FU)
#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F1_SHIFT (0U)
#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F1_SHIFT)) & LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F1_MASK)

#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F2_MASK  (0x1FU)
#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F2_SHIFT (0U)
#define LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F2_SHIFT)) & LPDDR_DENALI_CTL_W2R_DIFFCS_DLY_F2_MASK)

#define LPDDR_DENALI_CTL_W2R_SPLIT_EN_MASK       (0x1U)
#define LPDDR_DENALI_CTL_W2R_SPLIT_EN_SHIFT      (0U)
/*! W2R_SPLIT_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_W2R_SPLIT_EN(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2R_SPLIT_EN_SHIFT)) & LPDDR_DENALI_CTL_W2R_SPLIT_EN_MASK)

#define LPDDR_DENALI_CTL_WRITEINTERP_MASK        (0x1U)
#define LPDDR_DENALI_CTL_WRITEINTERP_SHIFT       (0U)
#define LPDDR_DENALI_CTL_WRITEINTERP(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRITEINTERP_SHIFT)) & LPDDR_DENALI_CTL_WRITEINTERP_MASK)

#define LPDDR_DENALI_CTL_WRITE_MODEREG_MASK      (0x7FFFFFFU)
#define LPDDR_DENALI_CTL_WRITE_MODEREG_SHIFT     (0U)
#define LPDDR_DENALI_CTL_WRITE_MODEREG(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRITE_MODEREG_SHIFT)) & LPDDR_DENALI_CTL_WRITE_MODEREG_MASK)

#define LPDDR_DENALI_CTL_ZQCL_F1_MASK            (0xFFFU)
#define LPDDR_DENALI_CTL_ZQCL_F1_SHIFT           (0U)
#define LPDDR_DENALI_CTL_ZQCL_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQCL_F1_SHIFT)) & LPDDR_DENALI_CTL_ZQCL_F1_MASK)

#define LPDDR_DENALI_CTL_ZQCS_F0_MASK            (0xFFFU)
#define LPDDR_DENALI_CTL_ZQCS_F0_SHIFT           (0U)
#define LPDDR_DENALI_CTL_ZQCS_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQCS_F0_SHIFT)) & LPDDR_DENALI_CTL_ZQCS_F0_MASK)

#define LPDDR_DENALI_CTL_ZQCS_F2_MASK            (0xFFFU)
#define LPDDR_DENALI_CTL_ZQCS_F2_SHIFT           (0U)
#define LPDDR_DENALI_CTL_ZQCS_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQCS_F2_SHIFT)) & LPDDR_DENALI_CTL_ZQCS_F2_MASK)

#define LPDDR_DENALI_CTL_ZQINIT_F2_MASK          (0xFFFU)
#define LPDDR_DENALI_CTL_ZQINIT_F2_SHIFT         (0U)
#define LPDDR_DENALI_CTL_ZQINIT_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQINIT_F2_SHIFT)) & LPDDR_DENALI_CTL_ZQINIT_F2_MASK)

#define LPDDR_DENALI_CTL_ZQRESET_F0_MASK         (0xFFFU)
#define LPDDR_DENALI_CTL_ZQRESET_F0_SHIFT        (0U)
#define LPDDR_DENALI_CTL_ZQRESET_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQRESET_F0_SHIFT)) & LPDDR_DENALI_CTL_ZQRESET_F0_MASK)

#define LPDDR_DENALI_CTL_ZQRESET_F2_MASK         (0xFFFU)
#define LPDDR_DENALI_CTL_ZQRESET_F2_SHIFT        (0U)
#define LPDDR_DENALI_CTL_ZQRESET_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQRESET_F2_SHIFT)) & LPDDR_DENALI_CTL_ZQRESET_F2_MASK)

#define LPDDR_DENALI_CTL_ADDR_COLLISION_MPM_DIS_MASK (0x100U)
#define LPDDR_DENALI_CTL_ADDR_COLLISION_MPM_DIS_SHIFT (8U)
/*! ADDR_COLLISION_MPM_DIS
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_ADDR_COLLISION_MPM_DIS(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ADDR_COLLISION_MPM_DIS_SHIFT)) & LPDDR_DENALI_CTL_ADDR_COLLISION_MPM_DIS_MASK)

#define LPDDR_DENALI_CTL_APREBIT_MASK            (0x1F00U)
#define LPDDR_DENALI_CTL_APREBIT_SHIFT           (8U)
#define LPDDR_DENALI_CTL_APREBIT(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_APREBIT_SHIFT)) & LPDDR_DENALI_CTL_APREBIT_MASK)

#define LPDDR_DENALI_CTL_AXI0_W_PRIORITY_MASK    (0x700U)
#define LPDDR_DENALI_CTL_AXI0_W_PRIORITY_SHIFT   (8U)
#define LPDDR_DENALI_CTL_AXI0_W_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI0_W_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI0_W_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_AXI1_R_PRIORITY_MASK    (0x700U)
#define LPDDR_DENALI_CTL_AXI1_R_PRIORITY_SHIFT   (8U)
#define LPDDR_DENALI_CTL_AXI1_R_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI1_R_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI1_R_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_AXI2_FIXED_PORT_PRIORITY_ENABLE_MASK (0x100U)
#define LPDDR_DENALI_CTL_AXI2_FIXED_PORT_PRIORITY_ENABLE_SHIFT (8U)
#define LPDDR_DENALI_CTL_AXI2_FIXED_PORT_PRIORITY_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI2_FIXED_PORT_PRIORITY_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI2_FIXED_PORT_PRIORITY_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI3_ALL_STROBES_USED_ENABLE_MASK (0x100U)
#define LPDDR_DENALI_CTL_AXI3_ALL_STROBES_USED_ENABLE_SHIFT (8U)
#define LPDDR_DENALI_CTL_AXI3_ALL_STROBES_USED_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI3_ALL_STROBES_USED_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI3_ALL_STROBES_USED_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI3_FIFO_TYPE_REG_MASK (0x300U)
#define LPDDR_DENALI_CTL_AXI3_FIFO_TYPE_REG_SHIFT (8U)
#define LPDDR_DENALI_CTL_AXI3_FIFO_TYPE_REG(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI3_FIFO_TYPE_REG_SHIFT)) & LPDDR_DENALI_CTL_AXI3_FIFO_TYPE_REG_MASK)

#define LPDDR_DENALI_CTL_CONCURRENTAP_MASK       (0x100U)
#define LPDDR_DENALI_CTL_CONCURRENTAP_SHIFT      (8U)
/*! CONCURRENTAP
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_CONCURRENTAP(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CONCURRENTAP_SHIFT)) & LPDDR_DENALI_CTL_CONCURRENTAP_MASK)

#define LPDDR_DENALI_CTL_CS_COMPARISON_FOR_REFRESH_DEPTH_MASK (0x1F00U)
#define LPDDR_DENALI_CTL_CS_COMPARISON_FOR_REFRESH_DEPTH_SHIFT (8U)
#define LPDDR_DENALI_CTL_CS_COMPARISON_FOR_REFRESH_DEPTH(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CS_COMPARISON_FOR_REFRESH_DEPTH_SHIFT)) & LPDDR_DENALI_CTL_CS_COMPARISON_FOR_REFRESH_DEPTH_MASK)

#define LPDDR_DENALI_CTL_CTRLUPD_AREF_HP_ENABLE_MASK (0x100U)
#define LPDDR_DENALI_CTL_CTRLUPD_AREF_HP_ENABLE_SHIFT (8U)
#define LPDDR_DENALI_CTL_CTRLUPD_AREF_HP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CTRLUPD_AREF_HP_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_CTRLUPD_AREF_HP_ENABLE_MASK)

#define LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS1_MASK  (0xF00U)
#define LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS1_SHIFT (8U)
#define LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS1_SHIFT)) & LPDDR_DENALI_CTL_DEVICE2_BYTE0_CS1_MASK)

#define LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS0_MASK  (0xF00U)
#define LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS0_SHIFT (8U)
#define LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS0_SHIFT)) & LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS0_MASK)

#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F0_MASK     (0x1F00U)
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F0_SHIFT    (8U)
/*! DFIBUS_FREQ_F0 - Defines the DFI bus frequency for frequency set 0. */
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFIBUS_FREQ_F0_SHIFT)) & LPDDR_DENALI_CTL_DFIBUS_FREQ_F0_MASK)

#define LPDDR_DENALI_CTL_DFI_ERROR_INFO_MASK     (0xFFFFF00U)
#define LPDDR_DENALI_CTL_DFI_ERROR_INFO_SHIFT    (8U)
#define LPDDR_DENALI_CTL_DFI_ERROR_INFO(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFI_ERROR_INFO_SHIFT)) & LPDDR_DENALI_CTL_DFI_ERROR_INFO_MASK)

#define LPDDR_DENALI_CTL_DFI_INV_DATA_CS_MASK    (0x100U)
#define LPDDR_DENALI_CTL_DFI_INV_DATA_CS_SHIFT   (8U)
#define LPDDR_DENALI_CTL_DFI_INV_DATA_CS(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFI_INV_DATA_CS_SHIFT)) & LPDDR_DENALI_CTL_DFI_INV_DATA_CS_MASK)

#define LPDDR_DENALI_CTL_DISABLE_RW_GROUP_W_BNK_CONFLICT_MASK (0x300U)
#define LPDDR_DENALI_CTL_DISABLE_RW_GROUP_W_BNK_CONFLICT_SHIFT (8U)
/*! DISABLE_RW_GROUP_W_BNK_CONFLICT
 *  0b00..Allowed
 *  0b01..Prohibited
 */
#define LPDDR_DENALI_CTL_DISABLE_RW_GROUP_W_BNK_CONFLICT(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DISABLE_RW_GROUP_W_BNK_CONFLICT_SHIFT)) & LPDDR_DENALI_CTL_DISABLE_RW_GROUP_W_BNK_CONFLICT_MASK)

#define LPDDR_DENALI_CTL_DRAM_CLASS_MASK         (0xF00U)
#define LPDDR_DENALI_CTL_DRAM_CLASS_SHIFT        (8U)
/*! DRAM_CLASS - Defines the class of DRAM memory which is connected to the controller. */
#define LPDDR_DENALI_CTL_DRAM_CLASS(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DRAM_CLASS_SHIFT)) & LPDDR_DENALI_CTL_DRAM_CLASS_MASK)

#define LPDDR_DENALI_CTL_EN_1T_TIMING_MASK       (0x100U)
#define LPDDR_DENALI_CTL_EN_1T_TIMING_SHIFT      (8U)
/*! EN_1T_TIMING
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_EN_1T_TIMING(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_EN_1T_TIMING_SHIFT)) & LPDDR_DENALI_CTL_EN_1T_TIMING_MASK)

#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F1_MASK (0x300U)
#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F1_SHIFT (8U)
/*! FREQ_CHANGE_TYPE_F1 - Defines the encoded frequency driven out on the cntrl_freq_change_req_type signal during a frequency change operation. */
#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F1_SHIFT)) & LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F1_MASK)

#define LPDDR_DENALI_CTL_FSP_STATUS_MASK         (0x100U)
#define LPDDR_DENALI_CTL_FSP_STATUS_SHIFT        (8U)
/*! FSP_STATUS
 *  0b0..No change
 *  0b1..FSP registers were updated
 */
#define LPDDR_DENALI_CTL_FSP_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FSP_STATUS_SHIFT)) & LPDDR_DENALI_CTL_FSP_STATUS_MASK)

#define LPDDR_DENALI_CTL_INHIBIT_DRAM_CMD_MASK   (0x300U)
#define LPDDR_DENALI_CTL_INHIBIT_DRAM_CMD_SHIFT  (8U)
#define LPDDR_DENALI_CTL_INHIBIT_DRAM_CMD(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INHIBIT_DRAM_CMD_SHIFT)) & LPDDR_DENALI_CTL_INHIBIT_DRAM_CMD_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_INIT_MASK       (0xFF00U)
#define LPDDR_DENALI_CTL_INT_ACK_INIT_SHIFT      (8U)
#define LPDDR_DENALI_CTL_INT_ACK_INIT(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_INIT_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_INIT_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_INIT_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_INT_MASK_INIT_SHIFT     (8U)
#define LPDDR_DENALI_CTL_INT_MASK_INIT(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_INIT_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_INIT_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_INIT_MASK    (0xFF00U)
#define LPDDR_DENALI_CTL_INT_STATUS_INIT_SHIFT   (8U)
#define LPDDR_DENALI_CTL_INT_STATUS_INIT(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_INIT_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_INIT_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F0_MASK (0xF00U)
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F0_SHIFT (8U)
/*! LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks)
 *    to be driven when memory is in the self-refresh power-down long with memory and controller
 *    clock gating state, for frequency set 0.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F1_MASK (0xF00U)
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F1_SHIFT (8U)
/*! LPI_SRPD_LONG_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be
 *    driven when memory is in the self-refresh power-down long state (with or without memory clock
 *    gating), for frequency set 1.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F2_MASK (0xF00U)
#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F2_SHIFT (8U)
/*! LPI_SRPD_SHORT_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be
 *    driven when memory is in the self-refresh power-down short state (with or without memory clock
 *    gating), for frequency set 2.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F0_MASK (0xF00U)
#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F0_SHIFT (8U)
/*! LPI_SR_LONG_MCCLK_GATE_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks)
 *    to be driven when memory is in the self-refresh long with memory and controller clock gating
 *    state, for frequency set 0.
 */
#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F1_MASK (0xF00U)
#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F1_SHIFT (8U)
/*! LPI_SR_LONG_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven
 *    when memory is in the self-refresh long state (with or without memory clock gating) for
 *    frequency set 1.
 */
#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F2_MASK (0xF00U)
#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F2_SHIFT (8U)
/*! LPI_SR_SHORT_WAKEUP_F2 - LPI_SR_SHORT_WAKEUP_F2 */
#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_WAKEUP_EN_MASK      (0x3F00U)
#define LPDDR_DENALI_CTL_LPI_WAKEUP_EN_SHIFT     (8U)
/*! LPI_WAKEUP_EN - Enables the various low power state wakeup parameters for LPI request uses. */
#define LPDDR_DENALI_CTL_LPI_WAKEUP_EN(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_WAKEUP_EN_SHIFT)) & LPDDR_DENALI_CTL_LPI_WAKEUP_EN_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_MEM_GATE_EN_MASK (0x700U)
#define LPDDR_DENALI_CTL_LP_AUTO_MEM_GATE_EN_SHIFT (8U)
/*! LP_AUTO_MEM_GATE_EN - Enable memory clock gating when entering a low power state via the auto low power counters. */
#define LPDDR_DENALI_CTL_LP_AUTO_MEM_GATE_EN(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_MEM_GATE_EN_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_MEM_GATE_EN_MASK)

#define LPDDR_DENALI_CTL_LP_CMD_MASK             (0x7F00U)
#define LPDDR_DENALI_CTL_LP_CMD_SHIFT            (8U)
/*! LP_CMD - Low power software command request interface. */
#define LPDDR_DENALI_CTL_LP_CMD(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_CMD_SHIFT)) & LPDDR_DENALI_CTL_LP_CMD_MASK)

#define LPDDR_DENALI_CTL_LP_STATE_CS0_MASK       (0x7F00U)
#define LPDDR_DENALI_CTL_LP_STATE_CS0_SHIFT      (8U)
/*! LP_STATE_CS0 - Low power state status parameter for chip select 0. */
#define LPDDR_DENALI_CTL_LP_STATE_CS0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_STATE_CS0_SHIFT)) & LPDDR_DENALI_CTL_LP_STATE_CS0_MASK)

#define LPDDR_DENALI_CTL_MEMDATA_RATIO_0_MASK    (0x700U)
#define LPDDR_DENALI_CTL_MEMDATA_RATIO_0_SHIFT   (8U)
#define LPDDR_DENALI_CTL_MEMDATA_RATIO_0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MEMDATA_RATIO_0_SHIFT)) & LPDDR_DENALI_CTL_MEMDATA_RATIO_0_MASK)

#define LPDDR_DENALI_CTL_MR2_DATA_F0_0_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_MR2_DATA_F0_0_SHIFT     (8U)
#define LPDDR_DENALI_CTL_MR2_DATA_F0_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR2_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR2_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR2_DATA_F1_1_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_MR2_DATA_F1_1_SHIFT     (8U)
#define LPDDR_DENALI_CTL_MR2_DATA_F1_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR2_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR2_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR2_DATA_F2_0_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_MR2_DATA_F2_0_SHIFT     (8U)
#define LPDDR_DENALI_CTL_MR2_DATA_F2_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR2_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR2_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR3_DATA_F0_1_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_MR3_DATA_F0_1_SHIFT     (8U)
#define LPDDR_DENALI_CTL_MR3_DATA_F0_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR3_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR3_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR3_DATA_F2_0_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_MR3_DATA_F2_0_SHIFT     (8U)
#define LPDDR_DENALI_CTL_MR3_DATA_F2_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR3_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR3_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR4_DATA_F1_1_MASK      (0xFF00U)
#define LPDDR_DENALI_CTL_MR4_DATA_F1_1_SHIFT     (8U)
#define LPDDR_DENALI_CTL_MR4_DATA_F1_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR4_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR4_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR8_DATA_0_MASK         (0xFF00U)
#define LPDDR_DENALI_CTL_MR8_DATA_0_SHIFT        (8U)
#define LPDDR_DENALI_CTL_MR8_DATA_0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR8_DATA_0_SHIFT)) & LPDDR_DENALI_CTL_MR8_DATA_0_MASK)

#define LPDDR_DENALI_CTL_MR11_DATA_F1_1_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR11_DATA_F1_1_SHIFT    (8U)
#define LPDDR_DENALI_CTL_MR11_DATA_F1_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR11_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR11_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR12_DATA_F0_0_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR12_DATA_F0_0_SHIFT    (8U)
#define LPDDR_DENALI_CTL_MR12_DATA_F0_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR12_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR12_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR12_DATA_F2_1_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR12_DATA_F2_1_SHIFT    (8U)
#define LPDDR_DENALI_CTL_MR12_DATA_F2_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR12_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR12_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR14_DATA_F0_0_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR14_DATA_F0_0_SHIFT    (8U)
/*! MR14_DATA_F0_0 - Data to program into memory mode register 14 for chip select 0. */
#define LPDDR_DENALI_CTL_MR14_DATA_F0_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR14_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR14_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR14_DATA_F2_1_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR14_DATA_F2_1_SHIFT    (8U)
#define LPDDR_DENALI_CTL_MR14_DATA_F2_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR14_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR14_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR17_DATA_0_MASK        (0xFF00U)
#define LPDDR_DENALI_CTL_MR17_DATA_0_SHIFT       (8U)
/*! MR17_DATA_0 - Data to program into memory mode register 17 for chip select 0. */
#define LPDDR_DENALI_CTL_MR17_DATA_0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR17_DATA_0_SHIFT)) & LPDDR_DENALI_CTL_MR17_DATA_0_MASK)

#define LPDDR_DENALI_CTL_MR22_DATA_F0_1_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR22_DATA_F0_1_SHIFT    (8U)
#define LPDDR_DENALI_CTL_MR22_DATA_F0_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR22_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR22_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR22_DATA_F2_0_MASK     (0xFF00U)
#define LPDDR_DENALI_CTL_MR22_DATA_F2_0_SHIFT    (8U)
#define LPDDR_DENALI_CTL_MR22_DATA_F2_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR22_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR22_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F0_MASK (0x100U)
#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F0_SHIFT (8U)
/*! MR_FSP_DATA_VALID_F0
 *  0b0..Memory training is in progress or was not performed
 *  0b1..Memory was trained
 */
#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F0_SHIFT)) & LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F0_MASK)

#define LPDDR_DENALI_CTL_NWR_F2_MASK             (0xFF00U)
#define LPDDR_DENALI_CTL_NWR_F2_SHIFT            (8U)
#define LPDDR_DENALI_CTL_NWR_F2(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NWR_F2_SHIFT)) & LPDDR_DENALI_CTL_NWR_F2_MASK)

#define LPDDR_DENALI_CTL_ODT_EN_F0_MASK          (0x100U)
#define LPDDR_DENALI_CTL_ODT_EN_F0_SHIFT         (8U)
#define LPDDR_DENALI_CTL_ODT_EN_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_EN_F0_SHIFT)) & LPDDR_DENALI_CTL_ODT_EN_F0_MASK)

#define LPDDR_DENALI_CTL_ODT_WR_MAP_CS0_MASK     (0x300U)
#define LPDDR_DENALI_CTL_ODT_WR_MAP_CS0_SHIFT    (8U)
#define LPDDR_DENALI_CTL_ODT_WR_MAP_CS0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_WR_MAP_CS0_SHIFT)) & LPDDR_DENALI_CTL_ODT_WR_MAP_CS0_MASK)

#define LPDDR_DENALI_CTL_PBR_CONT_REQ_EN_MASK    (0x100U)
#define LPDDR_DENALI_CTL_PBR_CONT_REQ_EN_SHIFT   (8U)
/*! PBR_CONT_REQ_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PBR_CONT_REQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PBR_CONT_REQ_EN_SHIFT)) & LPDDR_DENALI_CTL_PBR_CONT_REQ_EN_MASK)

#define LPDDR_DENALI_CTL_PBR_NUMERIC_ORDER_MASK  (0x100U)
#define LPDDR_DENALI_CTL_PBR_NUMERIC_ORDER_SHIFT (8U)
/*! PBR_NUMERIC_ORDER
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PBR_NUMERIC_ORDER(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PBR_NUMERIC_ORDER_SHIFT)) & LPDDR_DENALI_CTL_PBR_NUMERIC_ORDER_MASK)

#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F2_MASK  (0x1F00U)
#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F2_SHIFT (8U)
#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F2_SHIFT)) & LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F2_MASK)

#define LPDDR_DENALI_CTL_RD_PREAMBLE_TRAINING_EN_MASK (0x100U)
#define LPDDR_DENALI_CTL_RD_PREAMBLE_TRAINING_EN_SHIFT (8U)
/*! RD_PREAMBLE_TRAINING_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_RD_PREAMBLE_TRAINING_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RD_PREAMBLE_TRAINING_EN_SHIFT)) & LPDDR_DENALI_CTL_RD_PREAMBLE_TRAINING_EN_MASK)

#define LPDDR_DENALI_CTL_RD_TO_ODTH_F1_MASK      (0x3F00U)
#define LPDDR_DENALI_CTL_RD_TO_ODTH_F1_SHIFT     (8U)
#define LPDDR_DENALI_CTL_RD_TO_ODTH_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RD_TO_ODTH_F1_SHIFT)) & LPDDR_DENALI_CTL_RD_TO_ODTH_F1_MASK)

#define LPDDR_DENALI_CTL_RW2MRW_DLY_F2_MASK      (0x1F00U)
#define LPDDR_DENALI_CTL_RW2MRW_DLY_F2_SHIFT     (8U)
#define LPDDR_DENALI_CTL_RW2MRW_DLY_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RW2MRW_DLY_F2_SHIFT)) & LPDDR_DENALI_CTL_RW2MRW_DLY_F2_MASK)

#define LPDDR_DENALI_CTL_RW_SAME_EN_MASK         (0x100U)
#define LPDDR_DENALI_CTL_RW_SAME_EN_SHIFT        (8U)
/*! RW_SAME_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_RW_SAME_EN(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RW_SAME_EN_SHIFT)) & LPDDR_DENALI_CTL_RW_SAME_EN_MASK)

#define LPDDR_DENALI_CTL_TCKEHCMD_F0_MASK        (0x1F00U)
#define LPDDR_DENALI_CTL_TCKEHCMD_F0_SHIFT       (8U)
#define LPDDR_DENALI_CTL_TCKEHCMD_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKEHCMD_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKEHCMD_F0_MASK)

#define LPDDR_DENALI_CTL_TCKEHCMD_F1_MASK        (0x1F00U)
#define LPDDR_DENALI_CTL_TCKEHCMD_F1_SHIFT       (8U)
#define LPDDR_DENALI_CTL_TCKEHCMD_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKEHCMD_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKEHCMD_F1_MASK)

#define LPDDR_DENALI_CTL_TCKEHCMD_F2_MASK        (0x1F00U)
#define LPDDR_DENALI_CTL_TCKEHCMD_F2_SHIFT       (8U)
#define LPDDR_DENALI_CTL_TCKEHCMD_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKEHCMD_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKEHCMD_F2_MASK)

#define LPDDR_DENALI_CTL_TCKEHCS_F1_MASK         (0x1F00U)
#define LPDDR_DENALI_CTL_TCKEHCS_F1_SHIFT        (8U)
#define LPDDR_DENALI_CTL_TCKEHCS_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKEHCS_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKEHCS_F1_MASK)

#define LPDDR_DENALI_CTL_TCKELPD_F0_MASK         (0x1F00U)
#define LPDDR_DENALI_CTL_TCKELPD_F0_SHIFT        (8U)
#define LPDDR_DENALI_CTL_TCKELPD_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELPD_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKELPD_F0_MASK)

#define LPDDR_DENALI_CTL_TCKELPD_F1_MASK         (0x1F00U)
#define LPDDR_DENALI_CTL_TCKELPD_F1_SHIFT        (8U)
#define LPDDR_DENALI_CTL_TCKELPD_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELPD_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKELPD_F1_MASK)

#define LPDDR_DENALI_CTL_TCKELPD_F2_MASK         (0x1F00U)
#define LPDDR_DENALI_CTL_TCKELPD_F2_SHIFT        (8U)
#define LPDDR_DENALI_CTL_TCKELPD_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELPD_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKELPD_F2_MASK)

#define LPDDR_DENALI_CTL_TCKFSPX_F0_MASK         (0x1F00U)
#define LPDDR_DENALI_CTL_TCKFSPX_F0_SHIFT        (8U)
#define LPDDR_DENALI_CTL_TCKFSPX_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKFSPX_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKFSPX_F0_MASK)

#define LPDDR_DENALI_CTL_TCSCKE_F0_MASK          (0x1F00U)
#define LPDDR_DENALI_CTL_TCSCKE_F0_SHIFT         (8U)
#define LPDDR_DENALI_CTL_TCSCKE_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCSCKE_F0_SHIFT)) & LPDDR_DENALI_CTL_TCSCKE_F0_MASK)

#define LPDDR_DENALI_CTL_TCSCKE_F2_MASK          (0x1F00U)
#define LPDDR_DENALI_CTL_TCSCKE_F2_SHIFT         (8U)
#define LPDDR_DENALI_CTL_TCSCKE_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCSCKE_F2_SHIFT)) & LPDDR_DENALI_CTL_TCSCKE_F2_MASK)

#define LPDDR_DENALI_CTL_TDAL_F2_MASK            (0xFF00U)
#define LPDDR_DENALI_CTL_TDAL_F2_SHIFT           (8U)
#define LPDDR_DENALI_CTL_TDAL_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDAL_F2_SHIFT)) & LPDDR_DENALI_CTL_TDAL_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_DRAM_CLK_DISABLE_MASK (0xF00U)
#define LPDDR_DENALI_CTL_TDFI_DRAM_CLK_DISABLE_SHIFT (8U)
#define LPDDR_DENALI_CTL_TDFI_DRAM_CLK_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_DRAM_CLK_DISABLE_SHIFT)) & LPDDR_DENALI_CTL_TDFI_DRAM_CLK_DISABLE_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F2_MASK (0x700U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F2_SHIFT (8U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_RDDATA_EN_MASK     (0x7F00U)
#define LPDDR_DENALI_CTL_TDFI_RDDATA_EN_SHIFT    (8U)
#define LPDDR_DENALI_CTL_TDFI_RDDATA_EN(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_RDDATA_EN_SHIFT)) & LPDDR_DENALI_CTL_TDFI_RDDATA_EN_MASK)

#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F1_MASK    (0x7F00U)
#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F1_SHIFT   (8U)
#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_WRCSLAT_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_WRCSLAT_F1_MASK)

#define LPDDR_DENALI_CTL_TDQSCK_MIN_F0_MASK      (0x700U)
#define LPDDR_DENALI_CTL_TDQSCK_MIN_F0_SHIFT     (8U)
#define LPDDR_DENALI_CTL_TDQSCK_MIN_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDQSCK_MIN_F0_SHIFT)) & LPDDR_DENALI_CTL_TDQSCK_MIN_F0_MASK)

#define LPDDR_DENALI_CTL_TDQSCK_MIN_F2_MASK      (0x700U)
#define LPDDR_DENALI_CTL_TDQSCK_MIN_F2_SHIFT     (8U)
#define LPDDR_DENALI_CTL_TDQSCK_MIN_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDQSCK_MIN_F2_SHIFT)) & LPDDR_DENALI_CTL_TDQSCK_MIN_F2_MASK)

#define LPDDR_DENALI_CTL_TINIT_F0_MASK           (0xFFFFFF00U)
#define LPDDR_DENALI_CTL_TINIT_F0_SHIFT          (8U)
#define LPDDR_DENALI_CTL_TINIT_F0(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TINIT_F0_SHIFT)) & LPDDR_DENALI_CTL_TINIT_F0_MASK)

#define LPDDR_DENALI_CTL_TMOD_F0_MASK            (0xFF00U)
#define LPDDR_DENALI_CTL_TMOD_F0_SHIFT           (8U)
#define LPDDR_DENALI_CTL_TMOD_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMOD_F0_SHIFT)) & LPDDR_DENALI_CTL_TMOD_F0_MASK)

#define LPDDR_DENALI_CTL_TODTH_RD_F1_MASK        (0xF00U)
#define LPDDR_DENALI_CTL_TODTH_RD_F1_SHIFT       (8U)
#define LPDDR_DENALI_CTL_TODTH_RD_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTH_RD_F1_SHIFT)) & LPDDR_DENALI_CTL_TODTH_RD_F1_MASK)

#define LPDDR_DENALI_CTL_TODTH_WR_F0_MASK        (0xF00U)
#define LPDDR_DENALI_CTL_TODTH_WR_F0_SHIFT       (8U)
#define LPDDR_DENALI_CTL_TODTH_WR_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTH_WR_F0_SHIFT)) & LPDDR_DENALI_CTL_TODTH_WR_F0_MASK)

#define LPDDR_DENALI_CTL_TOSCO_F2_MASK           (0xFF00U)
#define LPDDR_DENALI_CTL_TOSCO_F2_SHIFT          (8U)
#define LPDDR_DENALI_CTL_TOSCO_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TOSCO_F2_SHIFT)) & LPDDR_DENALI_CTL_TOSCO_F2_MASK)

#define LPDDR_DENALI_CTL_TPPD_MASK               (0x700U)
#define LPDDR_DENALI_CTL_TPPD_SHIFT              (8U)
#define LPDDR_DENALI_CTL_TPPD(x)                 (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TPPD_SHIFT)) & LPDDR_DENALI_CTL_TPPD_MASK)

#define LPDDR_DENALI_CTL_TRCD_F0_MASK            (0xFF00U)
#define LPDDR_DENALI_CTL_TRCD_F0_SHIFT           (8U)
#define LPDDR_DENALI_CTL_TRCD_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRCD_F0_SHIFT)) & LPDDR_DENALI_CTL_TRCD_F0_MASK)

#define LPDDR_DENALI_CTL_TRCD_F2_MASK            (0xFF00U)
#define LPDDR_DENALI_CTL_TRCD_F2_SHIFT           (8U)
#define LPDDR_DENALI_CTL_TRCD_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRCD_F2_SHIFT)) & LPDDR_DENALI_CTL_TRCD_F2_MASK)

#define LPDDR_DENALI_CTL_TRC_F0_MASK             (0x1FF00U)
#define LPDDR_DENALI_CTL_TRC_F0_SHIFT            (8U)
#define LPDDR_DENALI_CTL_TRC_F0(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRC_F0_SHIFT)) & LPDDR_DENALI_CTL_TRC_F0_MASK)

#define LPDDR_DENALI_CTL_TRC_F2_MASK             (0x1FF00U)
#define LPDDR_DENALI_CTL_TRC_F2_SHIFT            (8U)
#define LPDDR_DENALI_CTL_TRC_F2(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRC_F2_SHIFT)) & LPDDR_DENALI_CTL_TRC_F2_MASK)

#define LPDDR_DENALI_CTL_TRP_AB_F2_MASK          (0xFF00U)
#define LPDDR_DENALI_CTL_TRP_AB_F2_SHIFT         (8U)
#define LPDDR_DENALI_CTL_TRP_AB_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRP_AB_F2_SHIFT)) & LPDDR_DENALI_CTL_TRP_AB_F2_MASK)

#define LPDDR_DENALI_CTL_TRP_F1_MASK             (0xFF00U)
#define LPDDR_DENALI_CTL_TRP_F1_SHIFT            (8U)
#define LPDDR_DENALI_CTL_TRP_F1(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRP_F1_SHIFT)) & LPDDR_DENALI_CTL_TRP_F1_MASK)

#define LPDDR_DENALI_CTL_TRTP_F1_MASK            (0xFF00U)
#define LPDDR_DENALI_CTL_TRTP_F1_SHIFT           (8U)
#define LPDDR_DENALI_CTL_TRTP_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRTP_F1_SHIFT)) & LPDDR_DENALI_CTL_TRTP_F1_MASK)

#define LPDDR_DENALI_CTL_TRTP_F2_MASK            (0xFF00U)
#define LPDDR_DENALI_CTL_TRTP_F2_SHIFT           (8U)
#define LPDDR_DENALI_CTL_TRTP_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRTP_F2_SHIFT)) & LPDDR_DENALI_CTL_TRTP_F2_MASK)

#define LPDDR_DENALI_CTL_TSREF2PHYMSTR_MASK      (0x3F00U)
#define LPDDR_DENALI_CTL_TSREF2PHYMSTR_SHIFT     (8U)
#define LPDDR_DENALI_CTL_TSREF2PHYMSTR(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TSREF2PHYMSTR_SHIFT)) & LPDDR_DENALI_CTL_TSREF2PHYMSTR_MASK)

#define LPDDR_DENALI_CTL_TZQCKE_F0_MASK          (0xF00U)
#define LPDDR_DENALI_CTL_TZQCKE_F0_SHIFT         (8U)
#define LPDDR_DENALI_CTL_TZQCKE_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQCKE_F0_SHIFT)) & LPDDR_DENALI_CTL_TZQCKE_F0_MASK)

#define LPDDR_DENALI_CTL_TZQCKE_F2_MASK          (0xF00U)
#define LPDDR_DENALI_CTL_TZQCKE_F2_SHIFT         (8U)
#define LPDDR_DENALI_CTL_TZQCKE_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQCKE_F2_SHIFT)) & LPDDR_DENALI_CTL_TZQCKE_F2_MASK)

#define LPDDR_DENALI_CTL_UPDATE_ERROR_STATUS_MASK (0x7F00U)
#define LPDDR_DENALI_CTL_UPDATE_ERROR_STATUS_SHIFT (8U)
#define LPDDR_DENALI_CTL_UPDATE_ERROR_STATUS(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_UPDATE_ERROR_STATUS_SHIFT)) & LPDDR_DENALI_CTL_UPDATE_ERROR_STATUS_MASK)

#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F0_MASK  (0x1F00U)
#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F0_SHIFT (8U)
#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F0_SHIFT)) & LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F0_MASK)

#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F1_MASK  (0x1F00U)
#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F1_SHIFT (8U)
#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F1_SHIFT)) & LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F1_MASK)

#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F2_MASK  (0x1F00U)
#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F2_SHIFT (8U)
#define LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F2_SHIFT)) & LPDDR_DENALI_CTL_W2W_DIFFCS_DLY_F2_MASK)

#define LPDDR_DENALI_CTL_WRLAT_ADJ_F0_MASK       (0x7F00U)
#define LPDDR_DENALI_CTL_WRLAT_ADJ_F0_SHIFT      (8U)
#define LPDDR_DENALI_CTL_WRLAT_ADJ_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRLAT_ADJ_F0_SHIFT)) & LPDDR_DENALI_CTL_WRLAT_ADJ_F0_MASK)

#define LPDDR_DENALI_CTL_WRLAT_ADJ_F1_MASK       (0x7F00U)
#define LPDDR_DENALI_CTL_WRLAT_ADJ_F1_SHIFT      (8U)
#define LPDDR_DENALI_CTL_WRLAT_ADJ_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRLAT_ADJ_F1_SHIFT)) & LPDDR_DENALI_CTL_WRLAT_ADJ_F1_MASK)

#define LPDDR_DENALI_CTL_WRLAT_ADJ_F2_MASK       (0x7F00U)
#define LPDDR_DENALI_CTL_WRLAT_ADJ_F2_SHIFT      (8U)
#define LPDDR_DENALI_CTL_WRLAT_ADJ_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRLAT_ADJ_F2_SHIFT)) & LPDDR_DENALI_CTL_WRLAT_ADJ_F2_MASK)

#define LPDDR_DENALI_CTL_WRLAT_F0_MASK           (0x7F00U)
#define LPDDR_DENALI_CTL_WRLAT_F0_SHIFT          (8U)
#define LPDDR_DENALI_CTL_WRLAT_F0(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRLAT_F0_SHIFT)) & LPDDR_DENALI_CTL_WRLAT_F0_MASK)

#define LPDDR_DENALI_CTL_WRLAT_F2_MASK           (0x7F00U)
#define LPDDR_DENALI_CTL_WRLAT_F2_SHIFT          (8U)
#define LPDDR_DENALI_CTL_WRLAT_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRLAT_F2_SHIFT)) & LPDDR_DENALI_CTL_WRLAT_F2_MASK)

#define LPDDR_DENALI_CTL_WR_ORDER_REQ_MASK       (0x300U)
#define LPDDR_DENALI_CTL_WR_ORDER_REQ_SHIFT      (8U)
#define LPDDR_DENALI_CTL_WR_ORDER_REQ(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WR_ORDER_REQ_SHIFT)) & LPDDR_DENALI_CTL_WR_ORDER_REQ_MASK)

#define LPDDR_DENALI_CTL_WR_TO_ODTH_F0_MASK      (0x3F00U)
#define LPDDR_DENALI_CTL_WR_TO_ODTH_F0_SHIFT     (8U)
#define LPDDR_DENALI_CTL_WR_TO_ODTH_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WR_TO_ODTH_F0_SHIFT)) & LPDDR_DENALI_CTL_WR_TO_ODTH_F0_MASK)

#define LPDDR_DENALI_CTL_ZQINIT_F1_MASK          (0xFFF00U)
#define LPDDR_DENALI_CTL_ZQINIT_F1_SHIFT         (8U)
#define LPDDR_DENALI_CTL_ZQINIT_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQINIT_F1_SHIFT)) & LPDDR_DENALI_CTL_ZQINIT_F1_MASK)

#define LPDDR_DENALI_CTL_ZQ_SW_REQ_START_LATCH_MAP_MASK (0x300U)
#define LPDDR_DENALI_CTL_ZQ_SW_REQ_START_LATCH_MAP_SHIFT (8U)
/*! ZQ_SW_REQ_START_LATCH_MAP - Specifies which chip selects will simultaneously receive a ZQ start
 *    or latch command once the ZQ_REQ bit is written with a ZQ Start or ZQ Latch command.
 */
#define LPDDR_DENALI_CTL_ZQ_SW_REQ_START_LATCH_MAP(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQ_SW_REQ_START_LATCH_MAP_SHIFT)) & LPDDR_DENALI_CTL_ZQ_SW_REQ_START_LATCH_MAP_MASK)

#define LPDDR_DENALI_CTL_AGE_COUNT_MASK          (0xFF0000U)
#define LPDDR_DENALI_CTL_AGE_COUNT_SHIFT         (16U)
#define LPDDR_DENALI_CTL_AGE_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AGE_COUNT_SHIFT)) & LPDDR_DENALI_CTL_AGE_COUNT_MASK)

#define LPDDR_DENALI_CTL_AREF_PBR_CONT_EN_THRESHOLD_MASK (0x1F0000U)
#define LPDDR_DENALI_CTL_AREF_PBR_CONT_EN_THRESHOLD_SHIFT (16U)
/*! AREF_PBR_CONT_EN_THRESHOLD - Sets the auto-refresh request count threshold when the PBR continuous refresh request enable will be asserted. */
#define LPDDR_DENALI_CTL_AREF_PBR_CONT_EN_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AREF_PBR_CONT_EN_THRESHOLD_SHIFT)) & LPDDR_DENALI_CTL_AREF_PBR_CONT_EN_THRESHOLD_MASK)

#define LPDDR_DENALI_CTL_AXI0_ALL_STROBES_USED_ENABLE_MASK (0x10000U)
#define LPDDR_DENALI_CTL_AXI0_ALL_STROBES_USED_ENABLE_SHIFT (16U)
#define LPDDR_DENALI_CTL_AXI0_ALL_STROBES_USED_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI0_ALL_STROBES_USED_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI0_ALL_STROBES_USED_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI0_FIFO_TYPE_REG_MASK (0x30000U)
#define LPDDR_DENALI_CTL_AXI0_FIFO_TYPE_REG_SHIFT (16U)
#define LPDDR_DENALI_CTL_AXI0_FIFO_TYPE_REG(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI0_FIFO_TYPE_REG_SHIFT)) & LPDDR_DENALI_CTL_AXI0_FIFO_TYPE_REG_MASK)

#define LPDDR_DENALI_CTL_AXI1_W_PRIORITY_MASK    (0x70000U)
#define LPDDR_DENALI_CTL_AXI1_W_PRIORITY_SHIFT   (16U)
#define LPDDR_DENALI_CTL_AXI1_W_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI1_W_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI1_W_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_AXI2_R_PRIORITY_MASK    (0x70000U)
#define LPDDR_DENALI_CTL_AXI2_R_PRIORITY_SHIFT   (16U)
#define LPDDR_DENALI_CTL_AXI2_R_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI2_R_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI2_R_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_AXI3_FIXED_PORT_PRIORITY_ENABLE_MASK (0x10000U)
#define LPDDR_DENALI_CTL_AXI3_FIXED_PORT_PRIORITY_ENABLE_SHIFT (16U)
#define LPDDR_DENALI_CTL_AXI3_FIXED_PORT_PRIORITY_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI3_FIXED_PORT_PRIORITY_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI3_FIXED_PORT_PRIORITY_ENABLE_MASK)

#define LPDDR_DENALI_CTL_BANK_DIFF_MASK          (0x30000U)
#define LPDDR_DENALI_CTL_BANK_DIFF_SHIFT         (16U)
#define LPDDR_DENALI_CTL_BANK_DIFF(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BANK_DIFF_SHIFT)) & LPDDR_DENALI_CTL_BANK_DIFF_MASK)

#define LPDDR_DENALI_CTL_BANK_SPLIT_EN_MASK      (0x10000U)
#define LPDDR_DENALI_CTL_BANK_SPLIT_EN_SHIFT     (16U)
/*! BANK_SPLIT_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_BANK_SPLIT_EN(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BANK_SPLIT_EN_SHIFT)) & LPDDR_DENALI_CTL_BANK_SPLIT_EN_MASK)

#define LPDDR_DENALI_CTL_BSTLEN_MASK             (0x1F0000U)
#define LPDDR_DENALI_CTL_BSTLEN_SHIFT            (16U)
#define LPDDR_DENALI_CTL_BSTLEN(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BSTLEN_SHIFT)) & LPDDR_DENALI_CTL_BSTLEN_MASK)

#define LPDDR_DENALI_CTL_CASLAT_LIN_F1_MASK      (0x7F0000U)
#define LPDDR_DENALI_CTL_CASLAT_LIN_F1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_CASLAT_LIN_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CASLAT_LIN_F1_SHIFT)) & LPDDR_DENALI_CTL_CASLAT_LIN_F1_MASK)

#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F0_MASK  (0x10000U)
#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F0_SHIFT (16U)
#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F0_SHIFT)) & LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F0_MASK)

#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F2_MASK  (0x10000U)
#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F2_SHIFT (16U)
#define LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F2_SHIFT)) & LPDDR_DENALI_CTL_CA_DEFAULT_VAL_F2_MASK)

#define LPDDR_DENALI_CTL_CONTROLLER_BUSY_MASK    (0x10000U)
#define LPDDR_DENALI_CTL_CONTROLLER_BUSY_SHIFT   (16U)
/*! CONTROLLER_BUSY
 *  0b0..Controller is not busy
 *  0b1..Controller is busy
 */
#define LPDDR_DENALI_CTL_CONTROLLER_BUSY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CONTROLLER_BUSY_SHIFT)) & LPDDR_DENALI_CTL_CONTROLLER_BUSY_MASK)

#define LPDDR_DENALI_CTL_CONTROLLER_ID_MASK      (0xFFFF0000U)
#define LPDDR_DENALI_CTL_CONTROLLER_ID_SHIFT     (16U)
#define LPDDR_DENALI_CTL_CONTROLLER_ID(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CONTROLLER_ID_SHIFT)) & LPDDR_DENALI_CTL_CONTROLLER_ID_MASK)

#define LPDDR_DENALI_CTL_CS_LOWER_ADDR_EN_MASK   (0x10000U)
#define LPDDR_DENALI_CTL_CS_LOWER_ADDR_EN_SHIFT  (16U)
/*! CS_LOWER_ADDR_EN
 *  0b0..The address map is CS - Row - Bank - Column - Datapath
 *  0b1..The address map is Row - CS - Bank - Column - Datapath
 */
#define LPDDR_DENALI_CTL_CS_LOWER_ADDR_EN(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CS_LOWER_ADDR_EN_SHIFT)) & LPDDR_DENALI_CTL_CS_LOWER_ADDR_EN_MASK)

#define LPDDR_DENALI_CTL_CS_MAP_MASK             (0x30000U)
#define LPDDR_DENALI_CTL_CS_MAP_SHIFT            (16U)
#define LPDDR_DENALI_CTL_CS_MAP(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CS_MAP_SHIFT)) & LPDDR_DENALI_CTL_CS_MAP_MASK)

#define LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS0_MASK  (0xF0000U)
#define LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS0_SHIFT (16U)
#define LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS0_SHIFT)) & LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS0_MASK)

#define LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS1_MASK  (0xF0000U)
#define LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS1_SHIFT (16U)
#define LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS1_SHIFT)) & LPDDR_DENALI_CTL_DEVICE3_BYTE0_CS1_MASK)

#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F1_MASK     (0x1F0000U)
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F1_SHIFT    (16U)
/*! DFIBUS_FREQ_F1 - Defines the DFI bus frequency for frequency set 1. */
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFIBUS_FREQ_F1_SHIFT)) & LPDDR_DENALI_CTL_DFIBUS_FREQ_F1_MASK)

#define LPDDR_DENALI_CTL_DFI_LP_VERSION_MASK     (0x10000U)
#define LPDDR_DENALI_CTL_DFI_LP_VERSION_SHIFT    (16U)
/*! DFI_LP_VERSION - When set to 1 enables DFI 5. */
#define LPDDR_DENALI_CTL_DFI_LP_VERSION(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFI_LP_VERSION_SHIFT)) & LPDDR_DENALI_CTL_DFI_LP_VERSION_MASK)

#define LPDDR_DENALI_CTL_DISABLE_MEMORY_MASKED_WRITE_MASK (0x10000U)
#define LPDDR_DENALI_CTL_DISABLE_MEMORY_MASKED_WRITE_SHIFT (16U)
/*! DISABLE_MEMORY_MASKED_WRITE
 *  0b0..Allow masked writes
 *  0b1..Restrict masked writes
 */
#define LPDDR_DENALI_CTL_DISABLE_MEMORY_MASKED_WRITE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DISABLE_MEMORY_MASKED_WRITE_SHIFT)) & LPDDR_DENALI_CTL_DISABLE_MEMORY_MASKED_WRITE_MASK)

#define LPDDR_DENALI_CTL_DQS_OSC_IN_PROGRESS_STATUS_MASK (0x10000U)
#define LPDDR_DENALI_CTL_DQS_OSC_IN_PROGRESS_STATUS_SHIFT (16U)
/*! DQS_OSC_IN_PROGRESS_STATUS
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define LPDDR_DENALI_CTL_DQS_OSC_IN_PROGRESS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DQS_OSC_IN_PROGRESS_STATUS_SHIFT)) & LPDDR_DENALI_CTL_DQS_OSC_IN_PROGRESS_STATUS_MASK)

#define LPDDR_DENALI_CTL_DRAM_CLK_DISABLE_MASK   (0x30000U)
#define LPDDR_DENALI_CTL_DRAM_CLK_DISABLE_SHIFT  (16U)
/*! DRAM_CLK_DISABLE
 *  0b00..Enable
 *  0b01..Disable
 */
#define LPDDR_DENALI_CTL_DRAM_CLK_DISABLE(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DRAM_CLK_DISABLE_SHIFT)) & LPDDR_DENALI_CTL_DRAM_CLK_DISABLE_MASK)

#define LPDDR_DENALI_CTL_ENABLE_QUICK_SREFRESH_MASK (0x10000U)
#define LPDDR_DENALI_CTL_ENABLE_QUICK_SREFRESH_SHIFT (16U)
#define LPDDR_DENALI_CTL_ENABLE_QUICK_SREFRESH(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ENABLE_QUICK_SREFRESH_SHIFT)) & LPDDR_DENALI_CTL_ENABLE_QUICK_SREFRESH_MASK)

#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F2_MASK (0x30000U)
#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F2_SHIFT (16U)
/*! FREQ_CHANGE_TYPE_F2 - Defines the encoded frequency driven out on the cntrl_freq_change_req_type signal during a frequency change operation. */
#define LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F2_SHIFT)) & LPDDR_DENALI_CTL_FREQ_CHANGE_TYPE_F2_MASK)

#define LPDDR_DENALI_CTL_FSP_OP_CURRENT_MASK     (0x10000U)
#define LPDDR_DENALI_CTL_FSP_OP_CURRENT_SHIFT    (16U)
/*! FSP_OP_CURRENT
 *  0b0..FSP set 0
 *  0b1..FSP set 1
 */
#define LPDDR_DENALI_CTL_FSP_OP_CURRENT(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FSP_OP_CURRENT_SHIFT)) & LPDDR_DENALI_CTL_FSP_OP_CURRENT_MASK)

#define LPDDR_DENALI_CTL_FUNC_VALID_CYCLES_MASK  (0xF0000U)
#define LPDDR_DENALI_CTL_FUNC_VALID_CYCLES_SHIFT (16U)
/*! FUNC_VALID_CYCLES - Number of cycles to hold dfi_function_valid asserted. */
#define LPDDR_DENALI_CTL_FUNC_VALID_CYCLES(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FUNC_VALID_CYCLES_SHIFT)) & LPDDR_DENALI_CTL_FUNC_VALID_CYCLES_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_LOWPOWER_MASK   (0xFFFF0000U)
#define LPDDR_DENALI_CTL_INT_ACK_LOWPOWER_SHIFT  (16U)
#define LPDDR_DENALI_CTL_INT_ACK_LOWPOWER(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_LOWPOWER_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_LOWPOWER_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_MISC_MASK       (0xFF0000U)
#define LPDDR_DENALI_CTL_INT_ACK_MISC_SHIFT      (16U)
#define LPDDR_DENALI_CTL_INT_ACK_MISC(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_MISC_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_MISC_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_USERIF_MASK     (0xFFFF0000U)
#define LPDDR_DENALI_CTL_INT_ACK_USERIF_SHIFT    (16U)
#define LPDDR_DENALI_CTL_INT_ACK_USERIF(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_USERIF_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_USERIF_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_LOWPOWER_MASK  (0xFFFF0000U)
#define LPDDR_DENALI_CTL_INT_MASK_LOWPOWER_SHIFT (16U)
#define LPDDR_DENALI_CTL_INT_MASK_LOWPOWER(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_LOWPOWER_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_LOWPOWER_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_MISC_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_INT_MASK_MISC_SHIFT     (16U)
#define LPDDR_DENALI_CTL_INT_MASK_MISC(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_MISC_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_MISC_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_USERIF_MASK    (0xFFFF0000U)
#define LPDDR_DENALI_CTL_INT_MASK_USERIF_SHIFT   (16U)
#define LPDDR_DENALI_CTL_INT_MASK_USERIF(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_USERIF_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_USERIF_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_LOWPOWER_MASK (0xFFFF0000U)
#define LPDDR_DENALI_CTL_INT_STATUS_LOWPOWER_SHIFT (16U)
#define LPDDR_DENALI_CTL_INT_STATUS_LOWPOWER(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_LOWPOWER_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_LOWPOWER_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_MISC_MASK    (0xFF0000U)
#define LPDDR_DENALI_CTL_INT_STATUS_MISC_SHIFT   (16U)
#define LPDDR_DENALI_CTL_INT_STATUS_MISC(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_MISC_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_MISC_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_USERIF_MASK  (0xFFFF0000U)
#define LPDDR_DENALI_CTL_INT_STATUS_USERIF_SHIFT (16U)
#define LPDDR_DENALI_CTL_INT_STATUS_USERIF(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_USERIF_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_USERIF_MASK)

#define LPDDR_DENALI_CTL_LONG_COUNT_MASK_MASK    (0x1F0000U)
#define LPDDR_DENALI_CTL_LONG_COUNT_MASK_SHIFT   (16U)
/*! LONG_COUNT_MASK - Reduces the length of the long counter from 1024 cycles. */
#define LPDDR_DENALI_CTL_LONG_COUNT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LONG_COUNT_MASK_SHIFT)) & LPDDR_DENALI_CTL_LONG_COUNT_MASK_MASK)

#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F0_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F0_SHIFT (16U)
/*! LPI_IDLE_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when controller is idle for frequency set 0. */
#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F0_MASK   (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F0_SHIFT  (16U)
/*! LPI_PD_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when
 *    memory is in any of the power-down states (with or without memory clock gating) for frequency
 *    set 0.
 */
#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F0(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F1_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F1_SHIFT (16U)
/*! LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks)
 *    to be driven when memory is in the self-refresh power-down long with memory and controller
 *    clock gating state, for frequency set 1.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F2_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F2_SHIFT (16U)
/*! LPI_SRPD_LONG_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be
 *    driven when memory is in the self-refresh power-down long state (with or without memory clock
 *    gating), for frequency set 2.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_LONG_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F1_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F1_SHIFT (16U)
/*! LPI_SR_LONG_MCCLK_GATE_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks)
 *    to be driven when memory is in the self-refresh long with memory and controller clock gating
 *    state, for frequency set 1.
 */
#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F2_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F2_SHIFT (16U)
/*! LPI_SR_LONG_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven
 *    when memory is in the self-refresh long state (with or without memory clock gating) for
 *    frequency set 2.
 */
#define LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_LONG_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F0_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F0_SHIFT (16U)
/*! LPI_TIMER_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when the LPI timer expires for frequency set 0. */
#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_WAKEUP_TIMEOUT_MASK (0xFFF0000U)
#define LPDDR_DENALI_CTL_LPI_WAKEUP_TIMEOUT_SHIFT (16U)
/*! LPI_WAKEUP_TIMEOUT - Defines the LPI timeout time, the maximum cycles between a dfi_lp_req de-assertion and a dfi_lp_ack de-assertion. */
#define LPDDR_DENALI_CTL_LPI_WAKEUP_TIMEOUT(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_WAKEUP_TIMEOUT_SHIFT)) & LPDDR_DENALI_CTL_LPI_WAKEUP_TIMEOUT_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_PD_IDLE_MASK    (0xFFF0000U)
#define LPDDR_DENALI_CTL_LP_AUTO_PD_IDLE_SHIFT   (16U)
/*! LP_AUTO_PD_IDLE - Defines the idle time (in controller clocks) until the controller will
 *    automatically issue an entry into one of the power-down low power states.
 */
#define LPDDR_DENALI_CTL_LP_AUTO_PD_IDLE(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_PD_IDLE_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_PD_IDLE_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_IDLE_MASK (0xFF0000U)
#define LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_IDLE_SHIFT (16U)
/*! LP_AUTO_SR_LONG_IDLE - Defines the idle time (in long counts) until the controller will
 *    automatically issue an entry into the self-refresh long or self-refresh power-down long (with or
 *    without memory clock gating) low power states.
 */
#define LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_IDLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_IDLE_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_IDLE_MASK)

#define LPDDR_DENALI_CTL_LP_STATE_CS1_MASK       (0x7F0000U)
#define LPDDR_DENALI_CTL_LP_STATE_CS1_SHIFT      (16U)
/*! LP_STATE_CS1 - Low power state status parameter for chip select 1. */
#define LPDDR_DENALI_CTL_LP_STATE_CS1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_STATE_CS1_SHIFT)) & LPDDR_DENALI_CTL_LP_STATE_CS1_MASK)

#define LPDDR_DENALI_CTL_MEMDATA_RATIO_1_MASK    (0x70000U)
#define LPDDR_DENALI_CTL_MEMDATA_RATIO_1_SHIFT   (16U)
#define LPDDR_DENALI_CTL_MEMDATA_RATIO_1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MEMDATA_RATIO_1_SHIFT)) & LPDDR_DENALI_CTL_MEMDATA_RATIO_1_MASK)

#define LPDDR_DENALI_CTL_MR1_DATA_F0_1_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_MR1_DATA_F0_1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_MR1_DATA_F0_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR1_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR1_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR1_DATA_F1_0_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_MR1_DATA_F1_0_SHIFT     (16U)
#define LPDDR_DENALI_CTL_MR1_DATA_F1_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR1_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR1_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR1_DATA_F2_1_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_MR1_DATA_F2_1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_MR1_DATA_F2_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR1_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR1_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR3_DATA_F1_1_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_MR3_DATA_F1_1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_MR3_DATA_F1_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR3_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR3_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MR4_DATA_F0_0_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_MR4_DATA_F0_0_SHIFT     (16U)
#define LPDDR_DENALI_CTL_MR4_DATA_F0_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR4_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR4_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR4_DATA_F2_1_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_MR4_DATA_F2_1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_MR4_DATA_F2_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR4_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR4_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR11_DATA_F0_0_MASK     (0xFF0000U)
#define LPDDR_DENALI_CTL_MR11_DATA_F0_0_SHIFT    (16U)
#define LPDDR_DENALI_CTL_MR11_DATA_F0_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR11_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR11_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR11_DATA_F2_1_MASK     (0xFF0000U)
#define LPDDR_DENALI_CTL_MR11_DATA_F2_1_SHIFT    (16U)
#define LPDDR_DENALI_CTL_MR11_DATA_F2_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR11_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR11_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR12_DATA_F1_0_MASK     (0xFF0000U)
#define LPDDR_DENALI_CTL_MR12_DATA_F1_0_SHIFT    (16U)
#define LPDDR_DENALI_CTL_MR12_DATA_F1_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR12_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR12_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR13_DATA_1_MASK        (0xFF0000U)
#define LPDDR_DENALI_CTL_MR13_DATA_1_SHIFT       (16U)
#define LPDDR_DENALI_CTL_MR13_DATA_1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR13_DATA_1_SHIFT)) & LPDDR_DENALI_CTL_MR13_DATA_1_MASK)

#define LPDDR_DENALI_CTL_MR14_DATA_F1_0_MASK     (0xFF0000U)
#define LPDDR_DENALI_CTL_MR14_DATA_F1_0_SHIFT    (16U)
/*! MR14_DATA_F1_0 - Data to program into memory mode register 14 for chip select 0. */
#define LPDDR_DENALI_CTL_MR14_DATA_F1_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR14_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR14_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR16_DATA_1_MASK        (0xFF0000U)
#define LPDDR_DENALI_CTL_MR16_DATA_1_SHIFT       (16U)
#define LPDDR_DENALI_CTL_MR16_DATA_1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR16_DATA_1_SHIFT)) & LPDDR_DENALI_CTL_MR16_DATA_1_MASK)

#define LPDDR_DENALI_CTL_MR20_DATA_0_MASK        (0xFF0000U)
#define LPDDR_DENALI_CTL_MR20_DATA_0_SHIFT       (16U)
#define LPDDR_DENALI_CTL_MR20_DATA_0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR20_DATA_0_SHIFT)) & LPDDR_DENALI_CTL_MR20_DATA_0_MASK)

#define LPDDR_DENALI_CTL_MR22_DATA_F1_1_MASK     (0xFF0000U)
#define LPDDR_DENALI_CTL_MR22_DATA_F1_1_SHIFT    (16U)
#define LPDDR_DENALI_CTL_MR22_DATA_F1_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR22_DATA_F1_1_SHIFT)) & LPDDR_DENALI_CTL_MR22_DATA_F1_1_MASK)

#define LPDDR_DENALI_CTL_MRSINGLE_DATA_0_MASK    (0xFF0000U)
#define LPDDR_DENALI_CTL_MRSINGLE_DATA_0_SHIFT   (16U)
#define LPDDR_DENALI_CTL_MRSINGLE_DATA_0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MRSINGLE_DATA_0_SHIFT)) & LPDDR_DENALI_CTL_MRSINGLE_DATA_0_MASK)

#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F1_MASK (0x10000U)
#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F1_SHIFT (16U)
/*! MR_FSP_DATA_VALID_F1
 *  0b0..Memory training is in progress or was not performed
 *  0b1..Memory was trained
 */
#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F1_SHIFT)) & LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F1_MASK)

#define LPDDR_DENALI_CTL_NO_MRW_INIT_MASK        (0x10000U)
#define LPDDR_DENALI_CTL_NO_MRW_INIT_SHIFT       (16U)
#define LPDDR_DENALI_CTL_NO_MRW_INIT(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NO_MRW_INIT_SHIFT)) & LPDDR_DENALI_CTL_NO_MRW_INIT_MASK)

#define LPDDR_DENALI_CTL_NO_ZQ_INIT_MASK         (0x10000U)
#define LPDDR_DENALI_CTL_NO_ZQ_INIT_SHIFT        (16U)
/*! NO_ZQ_INIT
 *  0b0..ZQ operations allowed during initialization
 *  0b1..ZQ operations disabled during initialization
 */
#define LPDDR_DENALI_CTL_NO_ZQ_INIT(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NO_ZQ_INIT_SHIFT)) & LPDDR_DENALI_CTL_NO_ZQ_INIT_MASK)

#define LPDDR_DENALI_CTL_NUM_Q_ENTRIES_ACT_DISABLE_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_NUM_Q_ENTRIES_ACT_DISABLE_SHIFT (16U)
#define LPDDR_DENALI_CTL_NUM_Q_ENTRIES_ACT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NUM_Q_ENTRIES_ACT_DISABLE_SHIFT)) & LPDDR_DENALI_CTL_NUM_Q_ENTRIES_ACT_DISABLE_MASK)

#define LPDDR_DENALI_CTL_ODT_EN_F1_MASK          (0x10000U)
#define LPDDR_DENALI_CTL_ODT_EN_F1_SHIFT         (16U)
#define LPDDR_DENALI_CTL_ODT_EN_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_EN_F1_SHIFT)) & LPDDR_DENALI_CTL_ODT_EN_F1_MASK)

#define LPDDR_DENALI_CTL_ODT_RD_MAP_CS1_MASK     (0x30000U)
#define LPDDR_DENALI_CTL_ODT_RD_MAP_CS1_SHIFT    (16U)
#define LPDDR_DENALI_CTL_ODT_RD_MAP_CS1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_RD_MAP_CS1_SHIFT)) & LPDDR_DENALI_CTL_ODT_RD_MAP_CS1_MASK)

#define LPDDR_DENALI_CTL_PBR_MAX_BANK_WAIT_MASK  (0xFFFF0000U)
#define LPDDR_DENALI_CTL_PBR_MAX_BANK_WAIT_SHIFT (16U)
/*! PBR_MAX_BANK_WAIT - Defines the maximum number of cycles that the PBR module will wait for
 *    Strategy to release the target bank until the PBR will assert the inhibit and close the target bank.
 */
#define LPDDR_DENALI_CTL_PBR_MAX_BANK_WAIT(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PBR_MAX_BANK_WAIT_SHIFT)) & LPDDR_DENALI_CTL_PBR_MAX_BANK_WAIT_MASK)

#define LPDDR_DENALI_CTL_PHY_INDEP_INIT_MODE_MASK (0x10000U)
#define LPDDR_DENALI_CTL_PHY_INDEP_INIT_MODE_SHIFT (16U)
/*! PHY_INDEP_INIT_MODE
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PHY_INDEP_INIT_MODE(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PHY_INDEP_INIT_MODE_SHIFT)) & LPDDR_DENALI_CTL_PHY_INDEP_INIT_MODE_MASK)

#define LPDDR_DENALI_CTL_PORT_ADDR_PROTECTION_EN_MASK (0x10000U)
#define LPDDR_DENALI_CTL_PORT_ADDR_PROTECTION_EN_SHIFT (16U)
#define LPDDR_DENALI_CTL_PORT_ADDR_PROTECTION_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PORT_ADDR_PROTECTION_EN_SHIFT)) & LPDDR_DENALI_CTL_PORT_ADDR_PROTECTION_EN_MASK)

#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F0_MASK (0x30000U)
#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F0_SHIFT (16U)
/*! PREAMBLE_SUPPORT_F0 - Selects the preamble for read and write burst transfers for frequency set 0. */
#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F0_SHIFT)) & LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F0_MASK)

#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F0_MASK  (0x1F0000U)
#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F0_SHIFT (16U)
#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F0_SHIFT)) & LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F0_MASK)

#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F1_MASK  (0x1F0000U)
#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F1_SHIFT (16U)
#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F1_SHIFT)) & LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F1_MASK)

#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F2_MASK  (0x1F0000U)
#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F2_SHIFT (16U)
#define LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F2_SHIFT)) & LPDDR_DENALI_CTL_R2R_DIFFCS_DLY_F2_MASK)

#define LPDDR_DENALI_CTL_R2R_SAMECS_DLY_MASK     (0x1F0000U)
#define LPDDR_DENALI_CTL_R2R_SAMECS_DLY_SHIFT    (16U)
#define LPDDR_DENALI_CTL_R2R_SAMECS_DLY(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2R_SAMECS_DLY_SHIFT)) & LPDDR_DENALI_CTL_R2R_SAMECS_DLY_MASK)

#define LPDDR_DENALI_CTL_RD_TO_ODTH_F2_MASK      (0x3F0000U)
#define LPDDR_DENALI_CTL_RD_TO_ODTH_F2_SHIFT     (16U)
#define LPDDR_DENALI_CTL_RD_TO_ODTH_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RD_TO_ODTH_F2_SHIFT)) & LPDDR_DENALI_CTL_RD_TO_ODTH_F2_MASK)

#define LPDDR_DENALI_CTL_RW_SAME_PAGE_EN_MASK    (0x10000U)
#define LPDDR_DENALI_CTL_RW_SAME_PAGE_EN_SHIFT   (16U)
/*! RW_SAME_PAGE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_RW_SAME_PAGE_EN(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RW_SAME_PAGE_EN_SHIFT)) & LPDDR_DENALI_CTL_RW_SAME_PAGE_EN_MASK)

#define LPDDR_DENALI_CTL_TBST_INT_INTERVAL_MASK  (0x70000U)
#define LPDDR_DENALI_CTL_TBST_INT_INTERVAL_SHIFT (16U)
#define LPDDR_DENALI_CTL_TBST_INT_INTERVAL(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TBST_INT_INTERVAL_SHIFT)) & LPDDR_DENALI_CTL_TBST_INT_INTERVAL_MASK)

#define LPDDR_DENALI_CTL_TCCDMW_MASK             (0x3F0000U)
#define LPDDR_DENALI_CTL_TCCDMW_SHIFT            (16U)
#define LPDDR_DENALI_CTL_TCCDMW(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCCDMW_SHIFT)) & LPDDR_DENALI_CTL_TCCDMW_MASK)

#define LPDDR_DENALI_CTL_TCKCKEL_F0_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKCKEL_F0_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKCKEL_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKCKEL_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKCKEL_F0_MASK)

#define LPDDR_DENALI_CTL_TCKCKEL_F1_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKCKEL_F1_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKCKEL_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKCKEL_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKCKEL_F1_MASK)

#define LPDDR_DENALI_CTL_TCKCKEL_F2_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKCKEL_F2_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKCKEL_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKCKEL_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKCKEL_F2_MASK)

#define LPDDR_DENALI_CTL_TCKELCS_F0_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKELCS_F0_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKELCS_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELCS_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKELCS_F0_MASK)

#define LPDDR_DENALI_CTL_TCKELCS_F2_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKELCS_F2_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKELCS_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKELCS_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKELCS_F2_MASK)

#define LPDDR_DENALI_CTL_TCKFSPE_F1_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKFSPE_F1_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKFSPE_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKFSPE_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKFSPE_F1_MASK)

#define LPDDR_DENALI_CTL_TCKFSPE_F2_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCKFSPE_F2_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCKFSPE_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKFSPE_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKFSPE_F2_MASK)

#define LPDDR_DENALI_CTL_TCSCKEH_F0_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCSCKEH_F0_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCSCKEH_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCSCKEH_F0_SHIFT)) & LPDDR_DENALI_CTL_TCSCKEH_F0_MASK)

#define LPDDR_DENALI_CTL_TCSCKEH_F1_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCSCKEH_F1_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCSCKEH_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCSCKEH_F1_SHIFT)) & LPDDR_DENALI_CTL_TCSCKEH_F1_MASK)

#define LPDDR_DENALI_CTL_TCSCKEH_F2_MASK         (0x1F0000U)
#define LPDDR_DENALI_CTL_TCSCKEH_F2_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TCSCKEH_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCSCKEH_F2_SHIFT)) & LPDDR_DENALI_CTL_TCSCKEH_F2_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F0_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F0_SHIFT (16U)
#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_DRAM_CLK_ENABLE_MASK (0xF0000U)
#define LPDDR_DENALI_CTL_TDFI_DRAM_CLK_ENABLE_SHIFT (16U)
#define LPDDR_DENALI_CTL_TDFI_DRAM_CLK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_DRAM_CLK_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_TDFI_DRAM_CLK_ENABLE_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F0_MASK  (0x7F0000U)
#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F0_SHIFT (16U)
/*! TDFI_PHY_RDLAT_F0 - Defines the DFI tPHY_RDLAT timing parameter (in DFI PHY clocks), the maximum
 *    cycles between a dfi_rddata_en assertion and a dfi_rddata_valid assertion.
 */
#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F0_MASK    (0x7F0000U)
#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F0_SHIFT   (16U)
#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_RDCSLAT_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_RDCSLAT_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F2_MASK    (0x7F0000U)
#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F2_SHIFT   (16U)
#define LPDDR_DENALI_CTL_TDFI_RDCSLAT_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_RDCSLAT_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_RDCSLAT_F2_MASK)

#define LPDDR_DENALI_CTL_TDQSCK_MAX_F1_MASK      (0xF0000U)
#define LPDDR_DENALI_CTL_TDQSCK_MAX_F1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_TDQSCK_MAX_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDQSCK_MAX_F1_SHIFT)) & LPDDR_DENALI_CTL_TDQSCK_MAX_F1_MASK)

#define LPDDR_DENALI_CTL_TFAW_F1_MASK            (0x1FF0000U)
#define LPDDR_DENALI_CTL_TFAW_F1_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TFAW_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TFAW_F1_SHIFT)) & LPDDR_DENALI_CTL_TFAW_F1_MASK)

#define LPDDR_DENALI_CTL_TFC_F0_MASK             (0x3FF0000U)
#define LPDDR_DENALI_CTL_TFC_F0_SHIFT            (16U)
#define LPDDR_DENALI_CTL_TFC_F0(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TFC_F0_SHIFT)) & LPDDR_DENALI_CTL_TFC_F0_MASK)

#define LPDDR_DENALI_CTL_TMRD_F1_MASK            (0xFF0000U)
#define LPDDR_DENALI_CTL_TMRD_F1_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TMRD_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRD_F1_SHIFT)) & LPDDR_DENALI_CTL_TMRD_F1_MASK)

#define LPDDR_DENALI_CTL_TMRD_F2_MASK            (0xFF0000U)
#define LPDDR_DENALI_CTL_TMRD_F2_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TMRD_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRD_F2_SHIFT)) & LPDDR_DENALI_CTL_TMRD_F2_MASK)

#define LPDDR_DENALI_CTL_TMRRI_F0_MASK           (0xFF0000U)
#define LPDDR_DENALI_CTL_TMRRI_F0_SHIFT          (16U)
#define LPDDR_DENALI_CTL_TMRRI_F0(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRRI_F0_SHIFT)) & LPDDR_DENALI_CTL_TMRRI_F0_MASK)

#define LPDDR_DENALI_CTL_TMRWCKEL_F1_MASK        (0x1F0000U)
#define LPDDR_DENALI_CTL_TMRWCKEL_F1_SHIFT       (16U)
#define LPDDR_DENALI_CTL_TMRWCKEL_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRWCKEL_F1_SHIFT)) & LPDDR_DENALI_CTL_TMRWCKEL_F1_MASK)

#define LPDDR_DENALI_CTL_TODTH_RD_F0_MASK        (0xF0000U)
#define LPDDR_DENALI_CTL_TODTH_RD_F0_SHIFT       (16U)
#define LPDDR_DENALI_CTL_TODTH_RD_F0(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTH_RD_F0_SHIFT)) & LPDDR_DENALI_CTL_TODTH_RD_F0_MASK)

#define LPDDR_DENALI_CTL_TODTL_2CMD_F2_MASK      (0xFF0000U)
#define LPDDR_DENALI_CTL_TODTL_2CMD_F2_SHIFT     (16U)
#define LPDDR_DENALI_CTL_TODTL_2CMD_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTL_2CMD_F2_SHIFT)) & LPDDR_DENALI_CTL_TODTL_2CMD_F2_MASK)

#define LPDDR_DENALI_CTL_TPDEX_F1_MASK           (0xFFFF0000U)
#define LPDDR_DENALI_CTL_TPDEX_F1_SHIFT          (16U)
#define LPDDR_DENALI_CTL_TPDEX_F1(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TPDEX_F1_SHIFT)) & LPDDR_DENALI_CTL_TPDEX_F1_MASK)

#define LPDDR_DENALI_CTL_TRAS_LOCKOUT_MASK       (0x10000U)
#define LPDDR_DENALI_CTL_TRAS_LOCKOUT_SHIFT      (16U)
/*! TRAS_LOCKOUT
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_TRAS_LOCKOUT(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_LOCKOUT_SHIFT)) & LPDDR_DENALI_CTL_TRAS_LOCKOUT_MASK)

#define LPDDR_DENALI_CTL_TRAS_MIN_F1_MASK        (0x1FF0000U)
#define LPDDR_DENALI_CTL_TRAS_MIN_F1_SHIFT       (16U)
#define LPDDR_DENALI_CTL_TRAS_MIN_F1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRAS_MIN_F1_SHIFT)) & LPDDR_DENALI_CTL_TRAS_MIN_F1_MASK)

#define LPDDR_DENALI_CTL_TRFC_F0_MASK            (0x3FF0000U)
#define LPDDR_DENALI_CTL_TRFC_F0_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TRFC_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRFC_F0_SHIFT)) & LPDDR_DENALI_CTL_TRFC_F0_MASK)

#define LPDDR_DENALI_CTL_TRFC_PB_F0_MASK         (0x3FF0000U)
#define LPDDR_DENALI_CTL_TRFC_PB_F0_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TRFC_PB_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRFC_PB_F0_SHIFT)) & LPDDR_DENALI_CTL_TRFC_PB_F0_MASK)

#define LPDDR_DENALI_CTL_TRFC_PB_F1_MASK         (0x3FF0000U)
#define LPDDR_DENALI_CTL_TRFC_PB_F1_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TRFC_PB_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRFC_PB_F1_SHIFT)) & LPDDR_DENALI_CTL_TRFC_PB_F1_MASK)

#define LPDDR_DENALI_CTL_TRFC_PB_F2_MASK         (0x3FF0000U)
#define LPDDR_DENALI_CTL_TRFC_PB_F2_SHIFT        (16U)
#define LPDDR_DENALI_CTL_TRFC_PB_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRFC_PB_F2_SHIFT)) & LPDDR_DENALI_CTL_TRFC_PB_F2_MASK)

#define LPDDR_DENALI_CTL_TRRD_F1_MASK            (0xFF0000U)
#define LPDDR_DENALI_CTL_TRRD_F1_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TRRD_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRRD_F1_SHIFT)) & LPDDR_DENALI_CTL_TRRD_F1_MASK)

#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F1_MASK   (0x3FF0000U)
#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F1_SHIFT  (16U)
#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F1(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVRCG_DISABLE_F1_SHIFT)) & LPDDR_DENALI_CTL_TVRCG_DISABLE_F1_MASK)

#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F2_MASK   (0x3FF0000U)
#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F2_SHIFT  (16U)
#define LPDDR_DENALI_CTL_TVRCG_DISABLE_F2(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVRCG_DISABLE_F2_SHIFT)) & LPDDR_DENALI_CTL_TVRCG_DISABLE_F2_MASK)

#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F0_MASK    (0x3FF0000U)
#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F0_SHIFT   (16U)
#define LPDDR_DENALI_CTL_TVRCG_ENABLE_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TVRCG_ENABLE_F0_SHIFT)) & LPDDR_DENALI_CTL_TVRCG_ENABLE_F0_MASK)

#define LPDDR_DENALI_CTL_TWR_F0_MASK             (0xFF0000U)
#define LPDDR_DENALI_CTL_TWR_F0_SHIFT            (16U)
#define LPDDR_DENALI_CTL_TWR_F0(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TWR_F0_SHIFT)) & LPDDR_DENALI_CTL_TWR_F0_MASK)

#define LPDDR_DENALI_CTL_TWR_F2_MASK             (0xFF0000U)
#define LPDDR_DENALI_CTL_TWR_F2_SHIFT            (16U)
#define LPDDR_DENALI_CTL_TWR_F2(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TWR_F2_SHIFT)) & LPDDR_DENALI_CTL_TWR_F2_MASK)

#define LPDDR_DENALI_CTL_TWTR_F0_MASK            (0x3F0000U)
#define LPDDR_DENALI_CTL_TWTR_F0_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TWTR_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TWTR_F0_SHIFT)) & LPDDR_DENALI_CTL_TWTR_F0_MASK)

#define LPDDR_DENALI_CTL_TWTR_F2_MASK            (0x3F0000U)
#define LPDDR_DENALI_CTL_TWTR_F2_SHIFT           (16U)
#define LPDDR_DENALI_CTL_TWTR_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TWTR_F2_SHIFT)) & LPDDR_DENALI_CTL_TWTR_F2_MASK)

#define LPDDR_DENALI_CTL_TXSNR_F0_MASK           (0xFFFF0000U)
#define LPDDR_DENALI_CTL_TXSNR_F0_SHIFT          (16U)
#define LPDDR_DENALI_CTL_TXSNR_F0(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TXSNR_F0_SHIFT)) & LPDDR_DENALI_CTL_TXSNR_F0_MASK)

#define LPDDR_DENALI_CTL_TXSNR_F1_MASK           (0xFFFF0000U)
#define LPDDR_DENALI_CTL_TXSNR_F1_SHIFT          (16U)
#define LPDDR_DENALI_CTL_TXSNR_F1(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TXSNR_F1_SHIFT)) & LPDDR_DENALI_CTL_TXSNR_F1_MASK)

#define LPDDR_DENALI_CTL_TXSNR_F2_MASK           (0xFFFF0000U)
#define LPDDR_DENALI_CTL_TXSNR_F2_SHIFT          (16U)
#define LPDDR_DENALI_CTL_TXSNR_F2(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TXSNR_F2_SHIFT)) & LPDDR_DENALI_CTL_TXSNR_F2_MASK)

#define LPDDR_DENALI_CTL_TZQCAL_F0_MASK          (0xFFF0000U)
#define LPDDR_DENALI_CTL_TZQCAL_F0_SHIFT         (16U)
#define LPDDR_DENALI_CTL_TZQCAL_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQCAL_F0_SHIFT)) & LPDDR_DENALI_CTL_TZQCAL_F0_MASK)

#define LPDDR_DENALI_CTL_TZQCAL_F2_MASK          (0xFFF0000U)
#define LPDDR_DENALI_CTL_TZQCAL_F2_SHIFT         (16U)
#define LPDDR_DENALI_CTL_TZQCAL_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQCAL_F2_SHIFT)) & LPDDR_DENALI_CTL_TZQCAL_F2_MASK)

#define LPDDR_DENALI_CTL_TZQLAT_F1_MASK          (0x7F0000U)
#define LPDDR_DENALI_CTL_TZQLAT_F1_SHIFT         (16U)
#define LPDDR_DENALI_CTL_TZQLAT_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQLAT_F1_SHIFT)) & LPDDR_DENALI_CTL_TZQLAT_F1_MASK)

#define LPDDR_DENALI_CTL_W2R_SAMECS_DLY_MASK     (0x1F0000U)
#define LPDDR_DENALI_CTL_W2R_SAMECS_DLY_SHIFT    (16U)
#define LPDDR_DENALI_CTL_W2R_SAMECS_DLY(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2R_SAMECS_DLY_SHIFT)) & LPDDR_DENALI_CTL_W2R_SAMECS_DLY_MASK)

#define LPDDR_DENALI_CTL_WR_DBI_EN_MASK          (0x10000U)
#define LPDDR_DENALI_CTL_WR_DBI_EN_SHIFT         (16U)
/*! WR_DBI_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_WR_DBI_EN(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WR_DBI_EN_SHIFT)) & LPDDR_DENALI_CTL_WR_DBI_EN_MASK)

#define LPDDR_DENALI_CTL_WR_TO_ODTH_F1_MASK      (0x3F0000U)
#define LPDDR_DENALI_CTL_WR_TO_ODTH_F1_SHIFT     (16U)
#define LPDDR_DENALI_CTL_WR_TO_ODTH_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WR_TO_ODTH_F1_SHIFT)) & LPDDR_DENALI_CTL_WR_TO_ODTH_F1_MASK)

#define LPDDR_DENALI_CTL_ZQCL_F2_MASK            (0xFFF0000U)
#define LPDDR_DENALI_CTL_ZQCL_F2_SHIFT           (16U)
#define LPDDR_DENALI_CTL_ZQCL_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQCL_F2_SHIFT)) & LPDDR_DENALI_CTL_ZQCL_F2_MASK)

#define LPDDR_DENALI_CTL_ZQCS_F1_MASK            (0xFFF0000U)
#define LPDDR_DENALI_CTL_ZQCS_F1_SHIFT           (16U)
#define LPDDR_DENALI_CTL_ZQCS_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQCS_F1_SHIFT)) & LPDDR_DENALI_CTL_ZQCS_F1_MASK)

#define LPDDR_DENALI_CTL_ZQRESET_F1_MASK         (0xFFF0000U)
#define LPDDR_DENALI_CTL_ZQRESET_F1_SHIFT        (16U)
#define LPDDR_DENALI_CTL_ZQRESET_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQRESET_F1_SHIFT)) & LPDDR_DENALI_CTL_ZQRESET_F1_MASK)

#define LPDDR_DENALI_CTL_ZQ_REQ_MASK             (0xF0000U)
#define LPDDR_DENALI_CTL_ZQ_REQ_SHIFT            (16U)
#define LPDDR_DENALI_CTL_ZQ_REQ(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQ_REQ_SHIFT)) & LPDDR_DENALI_CTL_ZQ_REQ_MASK)

#define LPDDR_DENALI_CTL_AREF_NORM_THRESHOLD_MASK (0x1F000000U)
#define LPDDR_DENALI_CTL_AREF_NORM_THRESHOLD_SHIFT (24U)
/*! AREF_NORM_THRESHOLD - AREF number of pending refreshes until the normal priority request is asserted. */
#define LPDDR_DENALI_CTL_AREF_NORM_THRESHOLD(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AREF_NORM_THRESHOLD_SHIFT)) & LPDDR_DENALI_CTL_AREF_NORM_THRESHOLD_MASK)

#define LPDDR_DENALI_CTL_AREF_PBR_CONT_DIS_THRESHOLD_MASK (0x1F000000U)
#define LPDDR_DENALI_CTL_AREF_PBR_CONT_DIS_THRESHOLD_SHIFT (24U)
/*! AREF_PBR_CONT_DIS_THRESHOLD - Sets the auto-refresh request count threshold when the PBR continuous refresh request enable will be deasserted. */
#define LPDDR_DENALI_CTL_AREF_PBR_CONT_DIS_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AREF_PBR_CONT_DIS_THRESHOLD_SHIFT)) & LPDDR_DENALI_CTL_AREF_PBR_CONT_DIS_THRESHOLD_MASK)

#define LPDDR_DENALI_CTL_AXI0_FIXED_PORT_PRIORITY_ENABLE_MASK (0x1000000U)
#define LPDDR_DENALI_CTL_AXI0_FIXED_PORT_PRIORITY_ENABLE_SHIFT (24U)
#define LPDDR_DENALI_CTL_AXI0_FIXED_PORT_PRIORITY_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI0_FIXED_PORT_PRIORITY_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI0_FIXED_PORT_PRIORITY_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI1_ALL_STROBES_USED_ENABLE_MASK (0x1000000U)
#define LPDDR_DENALI_CTL_AXI1_ALL_STROBES_USED_ENABLE_SHIFT (24U)
#define LPDDR_DENALI_CTL_AXI1_ALL_STROBES_USED_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI1_ALL_STROBES_USED_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_AXI1_ALL_STROBES_USED_ENABLE_MASK)

#define LPDDR_DENALI_CTL_AXI1_FIFO_TYPE_REG_MASK (0x3000000U)
#define LPDDR_DENALI_CTL_AXI1_FIFO_TYPE_REG_SHIFT (24U)
#define LPDDR_DENALI_CTL_AXI1_FIFO_TYPE_REG(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI1_FIFO_TYPE_REG_SHIFT)) & LPDDR_DENALI_CTL_AXI1_FIFO_TYPE_REG_MASK)

#define LPDDR_DENALI_CTL_AXI2_W_PRIORITY_MASK    (0x7000000U)
#define LPDDR_DENALI_CTL_AXI2_W_PRIORITY_SHIFT   (24U)
#define LPDDR_DENALI_CTL_AXI2_W_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI2_W_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI2_W_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_AXI3_R_PRIORITY_MASK    (0x7000000U)
#define LPDDR_DENALI_CTL_AXI3_R_PRIORITY_SHIFT   (24U)
#define LPDDR_DENALI_CTL_AXI3_R_PRIORITY(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_AXI3_R_PRIORITY_SHIFT)) & LPDDR_DENALI_CTL_AXI3_R_PRIORITY_MASK)

#define LPDDR_DENALI_CTL_BANK_START_BIT_MASK     (0x1F000000U)
#define LPDDR_DENALI_CTL_BANK_START_BIT_SHIFT    (24U)
/*! BANK_START_BIT - Defines the LSbit of the bank address within the page of the user address when the BANK_ADDR_INTLV_EN bit is set. */
#define LPDDR_DENALI_CTL_BANK_START_BIT(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BANK_START_BIT_SHIFT)) & LPDDR_DENALI_CTL_BANK_START_BIT_MASK)

#define LPDDR_DENALI_CTL_BL_ON_FLY_ENABLE_MASK   (0x1000000U)
#define LPDDR_DENALI_CTL_BL_ON_FLY_ENABLE_SHIFT  (24U)
/*! BL_ON_FLY_ENABLE
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_BL_ON_FLY_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_BL_ON_FLY_ENABLE_SHIFT)) & LPDDR_DENALI_CTL_BL_ON_FLY_ENABLE_MASK)

#define LPDDR_DENALI_CTL_COMMAND_AGE_COUNT_MASK  (0xFF000000U)
#define LPDDR_DENALI_CTL_COMMAND_AGE_COUNT_SHIFT (24U)
#define LPDDR_DENALI_CTL_COMMAND_AGE_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_COMMAND_AGE_COUNT_SHIFT)) & LPDDR_DENALI_CTL_COMMAND_AGE_COUNT_MASK)

#define LPDDR_DENALI_CTL_CS_SAME_EN_MASK         (0x1000000U)
#define LPDDR_DENALI_CTL_CS_SAME_EN_SHIFT        (24U)
/*! CS_SAME_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_CS_SAME_EN(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CS_SAME_EN_SHIFT)) & LPDDR_DENALI_CTL_CS_SAME_EN_MASK)

#define LPDDR_DENALI_CTL_CTRLUPD_REQ_MASK        (0x1000000U)
#define LPDDR_DENALI_CTL_CTRLUPD_REQ_SHIFT       (24U)
/*! CTRLUPD_REQ
 *  0b0..No action
 *  0b1..Trigger a controller-initiate update request
 */
#define LPDDR_DENALI_CTL_CTRLUPD_REQ(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_CTRLUPD_REQ_SHIFT)) & LPDDR_DENALI_CTL_CTRLUPD_REQ_MASK)

#define LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS1_MASK  (0xF000000U)
#define LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS1_SHIFT (24U)
#define LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS1_SHIFT)) & LPDDR_DENALI_CTL_DEVICE0_BYTE0_CS1_MASK)

#define LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS0_MASK  (0xF000000U)
#define LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS0_SHIFT (24U)
#define LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS0_SHIFT)) & LPDDR_DENALI_CTL_DEVICE1_BYTE0_CS0_MASK)

#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F2_MASK     (0x1F000000U)
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F2_SHIFT    (24U)
/*! DFIBUS_FREQ_F2 - Defines the DFI bus frequency for frequency set 2. */
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_F2(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFIBUS_FREQ_F2_SHIFT)) & LPDDR_DENALI_CTL_DFIBUS_FREQ_F2_MASK)

#define LPDDR_DENALI_CTL_DFIBUS_FREQ_INIT_MASK   (0x3000000U)
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_INIT_SHIFT  (24U)
/*! DFIBUS_FREQ_INIT - Defines the initial DFI bus frequency. */
#define LPDDR_DENALI_CTL_DFIBUS_FREQ_INIT(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_DFIBUS_FREQ_INIT_SHIFT)) & LPDDR_DENALI_CTL_DFIBUS_FREQ_INIT_MASK)

#define LPDDR_DENALI_CTL_FSP_PHY_UPDATE_MRW_MASK (0x1000000U)
#define LPDDR_DENALI_CTL_FSP_PHY_UPDATE_MRW_SHIFT (24U)
/*! FSP_PHY_UPDATE_MRW
 *  0b0..Controller
 *  0b1..PHY or PI
 */
#define LPDDR_DENALI_CTL_FSP_PHY_UPDATE_MRW(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FSP_PHY_UPDATE_MRW_SHIFT)) & LPDDR_DENALI_CTL_FSP_PHY_UPDATE_MRW_MASK)

#define LPDDR_DENALI_CTL_FSP_WR_CURRENT_MASK     (0x1000000U)
#define LPDDR_DENALI_CTL_FSP_WR_CURRENT_SHIFT    (24U)
/*! FSP_WR_CURRENT
 *  0b0..FSP set 0
 *  0b1..FSP set 1
 */
#define LPDDR_DENALI_CTL_FSP_WR_CURRENT(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_FSP_WR_CURRENT_SHIFT)) & LPDDR_DENALI_CTL_FSP_WR_CURRENT_MASK)

#define LPDDR_DENALI_CTL_INT_ACK_MODE_MASK       (0xFF000000U)
#define LPDDR_DENALI_CTL_INT_ACK_MODE_SHIFT      (24U)
#define LPDDR_DENALI_CTL_INT_ACK_MODE(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_ACK_MODE_SHIFT)) & LPDDR_DENALI_CTL_INT_ACK_MODE_MASK)

#define LPDDR_DENALI_CTL_INT_MASK_MODE_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_INT_MASK_MODE_SHIFT     (24U)
#define LPDDR_DENALI_CTL_INT_MASK_MODE(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_MASK_MODE_SHIFT)) & LPDDR_DENALI_CTL_INT_MASK_MODE_MASK)

#define LPDDR_DENALI_CTL_INT_STATUS_MODE_MASK    (0xFF000000U)
#define LPDDR_DENALI_CTL_INT_STATUS_MODE_SHIFT   (24U)
#define LPDDR_DENALI_CTL_INT_STATUS_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_INT_STATUS_MODE_SHIFT)) & LPDDR_DENALI_CTL_INT_STATUS_MODE_MASK)

#define LPDDR_DENALI_CTL_LPI_CTRL_REQ_EN_MASK    (0x1000000U)
#define LPDDR_DENALI_CTL_LPI_CTRL_REQ_EN_SHIFT   (24U)
/*! LPI_CTRL_REQ_EN - Enables the dfi_lpi_ctrl_req signal for the LPI. */
#define LPDDR_DENALI_CTL_LPI_CTRL_REQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_CTRL_REQ_EN_SHIFT)) & LPDDR_DENALI_CTL_LPI_CTRL_REQ_EN_MASK)

#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F1_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F1_SHIFT (24U)
/*! LPI_IDLE_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when controller is idle for frequency set 1. */
#define LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_IDLE_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F1_MASK   (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F1_SHIFT  (24U)
/*! LPI_PD_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when
 *    memory is in any of the power-down states (with or without memory clock gating) for frequency
 *    set 1.
 */
#define LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F1(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_PD_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F2_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F2_SHIFT (24U)
/*! LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks)
 *    to be driven when memory is in the self-refresh power-down long with memory and controller
 *    clock gating state, for frequency set 2.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_LONG_MCCLK_GATE_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F0_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F0_SHIFT (24U)
/*! LPI_SRPD_SHORT_WAKEUP_F0 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be
 *    driven when memory is in the self-refresh power-down short state (with or without memory clock
 *    gating), for frequency set 0.
 */
#define LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_SRPD_SHORT_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F2_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F2_SHIFT (24U)
/*! LPI_SR_LONG_MCCLK_GATE_WAKEUP_F2 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks)
 *    to be driven when memory is in the self-refresh long with memory and controller clock gating
 *    state, for frequency set 2.
 */
#define LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F2_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_LONG_MCCLK_GATE_WAKEUP_F2_MASK)

#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F0_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F0_SHIFT (24U)
/*! LPI_SR_SHORT_WAKEUP_F0 - LPI_SR_SHORT_WAKEUP_F0 */
#define LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F0_SHIFT)) & LPDDR_DENALI_CTL_LPI_SR_SHORT_WAKEUP_F0_MASK)

#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F1_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F1_SHIFT (24U)
/*! LPI_TIMER_WAKEUP_F1 - Defines the DFI tLP_WAKEUP timing parameter (in DFI clocks) to be driven when the LPI timer expires for frequency set 1. */
#define LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F1_SHIFT)) & LPDDR_DENALI_CTL_LPI_TIMER_WAKEUP_F1_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_ENTRY_EN_MASK   (0xF000000U)
#define LPDDR_DENALI_CTL_LP_AUTO_ENTRY_EN_SHIFT  (24U)
/*! LP_AUTO_ENTRY_EN - Enable auto entry into each of the low power states when the associated idle timer expires. */
#define LPDDR_DENALI_CTL_LP_AUTO_ENTRY_EN(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_ENTRY_EN_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_ENTRY_EN_MASK)

#define LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_MC_GATE_IDLE_MASK (0xFF000000U)
#define LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_MC_GATE_IDLE_SHIFT (24U)
/*! LP_AUTO_SR_LONG_MC_GATE_IDLE - Defines the idle time (in long counts) until the controller will
 *    automatically issue an entry into the self-refresh long with memory and controller clock
 *    gating or self-refresh power-down long with memory and controller clock gating low power states.
 */
#define LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_MC_GATE_IDLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_MC_GATE_IDLE_SHIFT)) & LPDDR_DENALI_CTL_LP_AUTO_SR_LONG_MC_GATE_IDLE_MASK)

#define LPDDR_DENALI_CTL_MR2_DATA_F0_1_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_MR2_DATA_F0_1_SHIFT     (24U)
#define LPDDR_DENALI_CTL_MR2_DATA_F0_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR2_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR2_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR2_DATA_F1_0_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_MR2_DATA_F1_0_SHIFT     (24U)
#define LPDDR_DENALI_CTL_MR2_DATA_F1_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR2_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR2_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR2_DATA_F2_1_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_MR2_DATA_F2_1_SHIFT     (24U)
#define LPDDR_DENALI_CTL_MR2_DATA_F2_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR2_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR2_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR3_DATA_F0_0_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_MR3_DATA_F0_0_SHIFT     (24U)
#define LPDDR_DENALI_CTL_MR3_DATA_F0_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR3_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR3_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR3_DATA_F2_1_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_MR3_DATA_F2_1_SHIFT     (24U)
#define LPDDR_DENALI_CTL_MR3_DATA_F2_1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR3_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR3_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR4_DATA_F1_0_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_MR4_DATA_F1_0_SHIFT     (24U)
#define LPDDR_DENALI_CTL_MR4_DATA_F1_0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR4_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR4_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR8_DATA_1_MASK         (0xFF000000U)
#define LPDDR_DENALI_CTL_MR8_DATA_1_SHIFT        (24U)
#define LPDDR_DENALI_CTL_MR8_DATA_1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR8_DATA_1_SHIFT)) & LPDDR_DENALI_CTL_MR8_DATA_1_MASK)

#define LPDDR_DENALI_CTL_MR11_DATA_F1_0_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR11_DATA_F1_0_SHIFT    (24U)
#define LPDDR_DENALI_CTL_MR11_DATA_F1_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR11_DATA_F1_0_SHIFT)) & LPDDR_DENALI_CTL_MR11_DATA_F1_0_MASK)

#define LPDDR_DENALI_CTL_MR12_DATA_F0_1_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR12_DATA_F0_1_SHIFT    (24U)
#define LPDDR_DENALI_CTL_MR12_DATA_F0_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR12_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR12_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR12_DATA_F2_0_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR12_DATA_F2_0_SHIFT    (24U)
#define LPDDR_DENALI_CTL_MR12_DATA_F2_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR12_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR12_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR14_DATA_F0_1_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR14_DATA_F0_1_SHIFT    (24U)
#define LPDDR_DENALI_CTL_MR14_DATA_F0_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR14_DATA_F0_1_SHIFT)) & LPDDR_DENALI_CTL_MR14_DATA_F0_1_MASK)

#define LPDDR_DENALI_CTL_MR14_DATA_F2_0_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR14_DATA_F2_0_SHIFT    (24U)
/*! MR14_DATA_F2_0 - Data to program into memory mode register 14 for chip select 0. */
#define LPDDR_DENALI_CTL_MR14_DATA_F2_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR14_DATA_F2_0_SHIFT)) & LPDDR_DENALI_CTL_MR14_DATA_F2_0_MASK)

#define LPDDR_DENALI_CTL_MR17_DATA_1_MASK        (0xFF000000U)
#define LPDDR_DENALI_CTL_MR17_DATA_1_SHIFT       (24U)
#define LPDDR_DENALI_CTL_MR17_DATA_1(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR17_DATA_1_SHIFT)) & LPDDR_DENALI_CTL_MR17_DATA_1_MASK)

#define LPDDR_DENALI_CTL_MR22_DATA_F0_0_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR22_DATA_F0_0_SHIFT    (24U)
/*! MR22_DATA_F0_0 - Data to program into memory mode register 22 for chip select 0. */
#define LPDDR_DENALI_CTL_MR22_DATA_F0_0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR22_DATA_F0_0_SHIFT)) & LPDDR_DENALI_CTL_MR22_DATA_F0_0_MASK)

#define LPDDR_DENALI_CTL_MR22_DATA_F2_1_MASK     (0xFF000000U)
#define LPDDR_DENALI_CTL_MR22_DATA_F2_1_SHIFT    (24U)
#define LPDDR_DENALI_CTL_MR22_DATA_F2_1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR22_DATA_F2_1_SHIFT)) & LPDDR_DENALI_CTL_MR22_DATA_F2_1_MASK)

#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F2_MASK (0x1000000U)
#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F2_SHIFT (24U)
/*! MR_FSP_DATA_VALID_F2
 *  0b0..Memory training is in progress or was not performed
 *  0b1..Memory was trained
 */
#define LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F2_SHIFT)) & LPDDR_DENALI_CTL_MR_FSP_DATA_VALID_F2_MASK)

#define LPDDR_DENALI_CTL_NO_AUTO_MRR_INIT_MASK   (0x1000000U)
#define LPDDR_DENALI_CTL_NO_AUTO_MRR_INIT_SHIFT  (24U)
/*! NO_AUTO_MRR_INIT
 *  0b0..No restrictions on MRR commands during initialization.
 *  0b1..Do not issue MRR commands during DLL initialization of the DRAM memories.
 */
#define LPDDR_DENALI_CTL_NO_AUTO_MRR_INIT(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NO_AUTO_MRR_INIT_SHIFT)) & LPDDR_DENALI_CTL_NO_AUTO_MRR_INIT_MASK)

#define LPDDR_DENALI_CTL_NWR_F0_MASK             (0xFF000000U)
#define LPDDR_DENALI_CTL_NWR_F0_SHIFT            (24U)
#define LPDDR_DENALI_CTL_NWR_F0(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_NWR_F0_SHIFT)) & LPDDR_DENALI_CTL_NWR_F0_MASK)

#define LPDDR_DENALI_CTL_ODT_EN_F2_MASK          (0x1000000U)
#define LPDDR_DENALI_CTL_ODT_EN_F2_SHIFT         (24U)
#define LPDDR_DENALI_CTL_ODT_EN_F2(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_EN_F2_SHIFT)) & LPDDR_DENALI_CTL_ODT_EN_F2_MASK)

#define LPDDR_DENALI_CTL_ODT_VALUE_MASK          (0x1000000U)
#define LPDDR_DENALI_CTL_ODT_VALUE_SHIFT         (24U)
/*! ODT_VALUE - When using LPDDR4, this value will be driven out on the dfi_odt signal. */
#define LPDDR_DENALI_CTL_ODT_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_VALUE_SHIFT)) & LPDDR_DENALI_CTL_ODT_VALUE_MASK)

#define LPDDR_DENALI_CTL_ODT_WR_MAP_CS1_MASK     (0x3000000U)
#define LPDDR_DENALI_CTL_ODT_WR_MAP_CS1_SHIFT    (24U)
#define LPDDR_DENALI_CTL_ODT_WR_MAP_CS1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ODT_WR_MAP_CS1_SHIFT)) & LPDDR_DENALI_CTL_ODT_WR_MAP_CS1_MASK)

#define LPDDR_DENALI_CTL_PHYMSTR_NO_AREF_MASK    (0x1000000U)
#define LPDDR_DENALI_CTL_PHYMSTR_NO_AREF_SHIFT   (24U)
/*! PHYMSTR_NO_AREF
 *  0b0..Allow refreshes while the dfi_phymstr_req and dfi_phymstr_ack signals are asserted.
 *  0b1..Disable refreshes while the dfi_phymstr_req and dfi_phymstr_ack signals are asserted.
 */
#define LPDDR_DENALI_CTL_PHYMSTR_NO_AREF(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PHYMSTR_NO_AREF_SHIFT)) & LPDDR_DENALI_CTL_PHYMSTR_NO_AREF_MASK)

#define LPDDR_DENALI_CTL_PLACEMENT_EN_MASK       (0x1000000U)
#define LPDDR_DENALI_CTL_PLACEMENT_EN_SHIFT      (24U)
/*! PLACEMENT_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_PLACEMENT_EN(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PLACEMENT_EN_SHIFT)) & LPDDR_DENALI_CTL_PLACEMENT_EN_MASK)

#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F1_MASK (0x3000000U)
#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F1_SHIFT (24U)
/*! PREAMBLE_SUPPORT_F1 - Selects the preamble for read and write burst transfers for frequency set 1. */
#define LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F1_SHIFT)) & LPDDR_DENALI_CTL_PREAMBLE_SUPPORT_F1_MASK)

#define LPDDR_DENALI_CTL_Q_FULLNESS_MASK         (0xF000000U)
#define LPDDR_DENALI_CTL_Q_FULLNESS_SHIFT        (24U)
#define LPDDR_DENALI_CTL_Q_FULLNESS(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_Q_FULLNESS_SHIFT)) & LPDDR_DENALI_CTL_Q_FULLNESS_MASK)

#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F0_MASK  (0x1F000000U)
#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F0_SHIFT (24U)
#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F0_SHIFT)) & LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F0_MASK)

#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F1_MASK  (0x1F000000U)
#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F1_SHIFT (24U)
#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F1_SHIFT)) & LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F1_MASK)

#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F2_MASK  (0x1F000000U)
#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F2_SHIFT (24U)
#define LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F2_SHIFT)) & LPDDR_DENALI_CTL_R2W_DIFFCS_DLY_F2_MASK)

#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F0_MASK  (0x1F000000U)
#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F0_SHIFT (24U)
#define LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F0_SHIFT)) & LPDDR_DENALI_CTL_R2W_SAMECS_DLY_F0_MASK)

#define LPDDR_DENALI_CTL_RD_DBI_EN_MASK          (0x1000000U)
#define LPDDR_DENALI_CTL_RD_DBI_EN_SHIFT         (24U)
/*! RD_DBI_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_RD_DBI_EN(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RD_DBI_EN_SHIFT)) & LPDDR_DENALI_CTL_RD_DBI_EN_MASK)

#define LPDDR_DENALI_CTL_REDUC_MASK              (0x1000000U)
#define LPDDR_DENALI_CTL_REDUC_SHIFT             (24U)
#define LPDDR_DENALI_CTL_REDUC(x)                (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_REDUC_SHIFT)) & LPDDR_DENALI_CTL_REDUC_MASK)

#define LPDDR_DENALI_CTL_ROW_DIFF_MASK           (0x7000000U)
#define LPDDR_DENALI_CTL_ROW_DIFF_SHIFT          (24U)
#define LPDDR_DENALI_CTL_ROW_DIFF(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ROW_DIFF_SHIFT)) & LPDDR_DENALI_CTL_ROW_DIFF_MASK)

#define LPDDR_DENALI_CTL_RW2MRW_DLY_F0_MASK      (0x1F000000U)
#define LPDDR_DENALI_CTL_RW2MRW_DLY_F0_SHIFT     (24U)
#define LPDDR_DENALI_CTL_RW2MRW_DLY_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_RW2MRW_DLY_F0_SHIFT)) & LPDDR_DENALI_CTL_RW2MRW_DLY_F0_MASK)

#define LPDDR_DENALI_CTL_SWAP_EN_MASK            (0x1000000U)
#define LPDDR_DENALI_CTL_SWAP_EN_SHIFT           (24U)
/*! SWAP_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_CTL_SWAP_EN(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_SWAP_EN_SHIFT)) & LPDDR_DENALI_CTL_SWAP_EN_MASK)

#define LPDDR_DENALI_CTL_TCCD_MASK               (0x1F000000U)
#define LPDDR_DENALI_CTL_TCCD_SHIFT              (24U)
#define LPDDR_DENALI_CTL_TCCD(x)                 (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCCD_SHIFT)) & LPDDR_DENALI_CTL_TCCD_MASK)

#define LPDDR_DENALI_CTL_TCKEHCS_F0_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKEHCS_F0_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCKEHCS_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKEHCS_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKEHCS_F0_MASK)

#define LPDDR_DENALI_CTL_TCKEHCS_F2_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKEHCS_F2_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCKEHCS_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKEHCS_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKEHCS_F2_MASK)

#define LPDDR_DENALI_CTL_TCKE_F0_MASK            (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKE_F0_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TCKE_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKE_F0_SHIFT)) & LPDDR_DENALI_CTL_TCKE_F0_MASK)

#define LPDDR_DENALI_CTL_TCKE_F1_MASK            (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKE_F1_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TCKE_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKE_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKE_F1_MASK)

#define LPDDR_DENALI_CTL_TCKE_F2_MASK            (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKE_F2_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TCKE_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKE_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKE_F2_MASK)

#define LPDDR_DENALI_CTL_TCKFSPX_F1_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKFSPX_F1_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCKFSPX_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKFSPX_F1_SHIFT)) & LPDDR_DENALI_CTL_TCKFSPX_F1_MASK)

#define LPDDR_DENALI_CTL_TCKFSPX_F2_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCKFSPX_F2_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCKFSPX_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCKFSPX_F2_SHIFT)) & LPDDR_DENALI_CTL_TCKFSPX_F2_MASK)

#define LPDDR_DENALI_CTL_TCMDCKE_F0_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCMDCKE_F0_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCMDCKE_F0(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCMDCKE_F0_SHIFT)) & LPDDR_DENALI_CTL_TCMDCKE_F0_MASK)

#define LPDDR_DENALI_CTL_TCMDCKE_F1_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCMDCKE_F1_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCMDCKE_F1(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCMDCKE_F1_SHIFT)) & LPDDR_DENALI_CTL_TCMDCKE_F1_MASK)

#define LPDDR_DENALI_CTL_TCMDCKE_F2_MASK         (0x1F000000U)
#define LPDDR_DENALI_CTL_TCMDCKE_F2_SHIFT        (24U)
#define LPDDR_DENALI_CTL_TCMDCKE_F2(x)           (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCMDCKE_F2_SHIFT)) & LPDDR_DENALI_CTL_TCMDCKE_F2_MASK)

#define LPDDR_DENALI_CTL_TCSCKE_F1_MASK          (0x1F000000U)
#define LPDDR_DENALI_CTL_TCSCKE_F1_SHIFT         (24U)
#define LPDDR_DENALI_CTL_TCSCKE_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TCSCKE_F1_SHIFT)) & LPDDR_DENALI_CTL_TCSCKE_F1_MASK)

#define LPDDR_DENALI_CTL_TDAL_F0_MASK            (0xFF000000U)
#define LPDDR_DENALI_CTL_TDAL_F0_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TDAL_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDAL_F0_SHIFT)) & LPDDR_DENALI_CTL_TDAL_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F1_MASK (0xF000000U)
#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F1_SHIFT (24U)
#define LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_CTRL_DELAY_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F1_MASK  (0x7F000000U)
#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F1_SHIFT (24U)
/*! TDFI_PHY_RDLAT_F1 - Defines the DFI tPHY_RDLAT timing parameter (in DFI PHY clocks), the maximum
 *    cycles between a dfi_rddata_en assertion and a dfi_rddata_valid assertion.
 */
#define LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F1_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_RDLAT_F1_MASK)

#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F0_MASK (0x7000000U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F0_SHIFT (24U)
#define LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_PHY_WRDATA_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F0_MASK    (0x7F000000U)
#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F0_SHIFT   (24U)
#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_WRCSLAT_F0_SHIFT)) & LPDDR_DENALI_CTL_TDFI_WRCSLAT_F0_MASK)

#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F2_MASK    (0x7F000000U)
#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F2_SHIFT   (24U)
#define LPDDR_DENALI_CTL_TDFI_WRCSLAT_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDFI_WRCSLAT_F2_SHIFT)) & LPDDR_DENALI_CTL_TDFI_WRCSLAT_F2_MASK)

#define LPDDR_DENALI_CTL_TDQSCK_MIN_F1_MASK      (0x7000000U)
#define LPDDR_DENALI_CTL_TDQSCK_MIN_F1_SHIFT     (24U)
#define LPDDR_DENALI_CTL_TDQSCK_MIN_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TDQSCK_MIN_F1_SHIFT)) & LPDDR_DENALI_CTL_TDQSCK_MIN_F1_MASK)

#define LPDDR_DENALI_CTL_TMOD_F1_MASK            (0xFF000000U)
#define LPDDR_DENALI_CTL_TMOD_F1_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TMOD_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMOD_F1_SHIFT)) & LPDDR_DENALI_CTL_TMOD_F1_MASK)

#define LPDDR_DENALI_CTL_TMOD_F2_MASK            (0xFF000000U)
#define LPDDR_DENALI_CTL_TMOD_F2_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TMOD_F2(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMOD_F2_SHIFT)) & LPDDR_DENALI_CTL_TMOD_F2_MASK)

#define LPDDR_DENALI_CTL_TMRR_MASK               (0xF000000U)
#define LPDDR_DENALI_CTL_TMRR_SHIFT              (24U)
#define LPDDR_DENALI_CTL_TMRR(x)                 (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRR_SHIFT)) & LPDDR_DENALI_CTL_TMRR_MASK)

#define LPDDR_DENALI_CTL_TMRRI_F1_MASK           (0xFF000000U)
#define LPDDR_DENALI_CTL_TMRRI_F1_SHIFT          (24U)
#define LPDDR_DENALI_CTL_TMRRI_F1(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TMRRI_F1_SHIFT)) & LPDDR_DENALI_CTL_TMRRI_F1_MASK)

#define LPDDR_DENALI_CTL_TODTH_WR_F2_MASK        (0xF000000U)
#define LPDDR_DENALI_CTL_TODTH_WR_F2_SHIFT       (24U)
#define LPDDR_DENALI_CTL_TODTH_WR_F2(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTH_WR_F2_SHIFT)) & LPDDR_DENALI_CTL_TODTH_WR_F2_MASK)

#define LPDDR_DENALI_CTL_TODTL_2CMD_F1_MASK      (0xFF000000U)
#define LPDDR_DENALI_CTL_TODTL_2CMD_F1_SHIFT     (24U)
#define LPDDR_DENALI_CTL_TODTL_2CMD_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TODTL_2CMD_F1_SHIFT)) & LPDDR_DENALI_CTL_TODTL_2CMD_F1_MASK)

#define LPDDR_DENALI_CTL_TOSCO_F0_MASK           (0xFF000000U)
#define LPDDR_DENALI_CTL_TOSCO_F0_SHIFT          (24U)
#define LPDDR_DENALI_CTL_TOSCO_F0(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TOSCO_F0_SHIFT)) & LPDDR_DENALI_CTL_TOSCO_F0_MASK)

#define LPDDR_DENALI_CTL_TRCD_F1_MASK            (0xFF000000U)
#define LPDDR_DENALI_CTL_TRCD_F1_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TRCD_F1(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRCD_F1_SHIFT)) & LPDDR_DENALI_CTL_TRCD_F1_MASK)

#define LPDDR_DENALI_CTL_TRP_AB_F0_MASK          (0xFF000000U)
#define LPDDR_DENALI_CTL_TRP_AB_F0_SHIFT         (24U)
#define LPDDR_DENALI_CTL_TRP_AB_F0(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRP_AB_F0_SHIFT)) & LPDDR_DENALI_CTL_TRP_AB_F0_MASK)

#define LPDDR_DENALI_CTL_TRP_F0_MASK             (0xFF000000U)
#define LPDDR_DENALI_CTL_TRP_F0_SHIFT            (24U)
#define LPDDR_DENALI_CTL_TRP_F0(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRP_F0_SHIFT)) & LPDDR_DENALI_CTL_TRP_F0_MASK)

#define LPDDR_DENALI_CTL_TRP_F2_MASK             (0xFF000000U)
#define LPDDR_DENALI_CTL_TRP_F2_SHIFT            (24U)
#define LPDDR_DENALI_CTL_TRP_F2(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRP_F2_SHIFT)) & LPDDR_DENALI_CTL_TRP_F2_MASK)

#define LPDDR_DENALI_CTL_TRTP_F0_MASK            (0xFF000000U)
#define LPDDR_DENALI_CTL_TRTP_F0_SHIFT           (24U)
#define LPDDR_DENALI_CTL_TRTP_F0(x)              (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TRTP_F0_SHIFT)) & LPDDR_DENALI_CTL_TRTP_F0_MASK)

#define LPDDR_DENALI_CTL_TSR_F0_MASK             (0xFF000000U)
#define LPDDR_DENALI_CTL_TSR_F0_SHIFT            (24U)
#define LPDDR_DENALI_CTL_TSR_F0(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TSR_F0_SHIFT)) & LPDDR_DENALI_CTL_TSR_F0_MASK)

#define LPDDR_DENALI_CTL_TSR_F1_MASK             (0xFF000000U)
#define LPDDR_DENALI_CTL_TSR_F1_SHIFT            (24U)
#define LPDDR_DENALI_CTL_TSR_F1(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TSR_F1_SHIFT)) & LPDDR_DENALI_CTL_TSR_F1_MASK)

#define LPDDR_DENALI_CTL_TSR_F2_MASK             (0xFF000000U)
#define LPDDR_DENALI_CTL_TSR_F2_SHIFT            (24U)
#define LPDDR_DENALI_CTL_TSR_F2(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TSR_F2_SHIFT)) & LPDDR_DENALI_CTL_TSR_F2_MASK)

#define LPDDR_DENALI_CTL_TZQCKE_F1_MASK          (0xF000000U)
#define LPDDR_DENALI_CTL_TZQCKE_F1_SHIFT         (24U)
#define LPDDR_DENALI_CTL_TZQCKE_F1(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_TZQCKE_F1_SHIFT)) & LPDDR_DENALI_CTL_TZQCKE_F1_MASK)

#define LPDDR_DENALI_CTL_W2W_SAMECS_DLY_MASK     (0x1F000000U)
#define LPDDR_DENALI_CTL_W2W_SAMECS_DLY_SHIFT    (24U)
#define LPDDR_DENALI_CTL_W2W_SAMECS_DLY(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_W2W_SAMECS_DLY_SHIFT)) & LPDDR_DENALI_CTL_W2W_SAMECS_DLY_MASK)

#define LPDDR_DENALI_CTL_WRLAT_F1_MASK           (0x7F000000U)
#define LPDDR_DENALI_CTL_WRLAT_F1_SHIFT          (24U)
#define LPDDR_DENALI_CTL_WRLAT_F1(x)             (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WRLAT_F1_SHIFT)) & LPDDR_DENALI_CTL_WRLAT_F1_MASK)

#define LPDDR_DENALI_CTL_WR_TO_ODTH_F2_MASK      (0x3F000000U)
#define LPDDR_DENALI_CTL_WR_TO_ODTH_F2_SHIFT     (24U)
#define LPDDR_DENALI_CTL_WR_TO_ODTH_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_WR_TO_ODTH_F2_SHIFT)) & LPDDR_DENALI_CTL_WR_TO_ODTH_F2_MASK)

#define LPDDR_DENALI_CTL_ZQCS_ROTATE_MASK        (0x1000000U)
#define LPDDR_DENALI_CTL_ZQCS_ROTATE_SHIFT       (24U)
#define LPDDR_DENALI_CTL_ZQCS_ROTATE(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQCS_ROTATE_SHIFT)) & LPDDR_DENALI_CTL_ZQCS_ROTATE_MASK)

#define LPDDR_DENALI_CTL_ZQ_REQ_PENDING_MASK     (0x1000000U)
#define LPDDR_DENALI_CTL_ZQ_REQ_PENDING_SHIFT    (24U)
/*! ZQ_REQ_PENDING
 *  0b0..Not in progress or waiting
 *  0b1..In progress or Waiting. No writes should occur to zq_req while this bit is set to 'b1.
 */
#define LPDDR_DENALI_CTL_ZQ_REQ_PENDING(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_CTL_ZQ_REQ_PENDING_SHIFT)) & LPDDR_DENALI_CTL_ZQ_REQ_PENDING_MASK)
/*! @} */

/*! @name DENALI_PI_0 - DENALI_PI_0 */
/*! @{ */

#define LPDDR_DENALI_PI_0_PI_START_MASK          (0x1U)
#define LPDDR_DENALI_PI_0_PI_START_SHIFT         (0U)
#define LPDDR_DENALI_PI_0_PI_START(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_0_PI_START_SHIFT)) & LPDDR_DENALI_PI_0_PI_START_MASK)

#define LPDDR_DENALI_PI_0_PI_DRAM_CLASS_MASK     (0xF00U)
#define LPDDR_DENALI_PI_0_PI_DRAM_CLASS_SHIFT    (8U)
#define LPDDR_DENALI_PI_0_PI_DRAM_CLASS(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_0_PI_DRAM_CLASS_SHIFT)) & LPDDR_DENALI_PI_0_PI_DRAM_CLASS_MASK)
/*! @} */

/*! @name DENALI_PI_3 - DENALI_PI_3 */
/*! @{ */

#define LPDDR_DENALI_PI_3_PI_ID_MASK             (0xFFFFU)
#define LPDDR_DENALI_PI_3_PI_ID_SHIFT            (0U)
#define LPDDR_DENALI_PI_3_PI_ID(x)               (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_3_PI_ID_SHIFT)) & LPDDR_DENALI_PI_3_PI_ID_MASK)

#define LPDDR_DENALI_PI_3_PI_RELEASE_DFI_MASK    (0x10000U)
#define LPDDR_DENALI_PI_3_PI_RELEASE_DFI_SHIFT   (16U)
/*! PI_RELEASE_DFI
 *  0b0..DFI is released
 *  0b1..DFI under PI control
 */
#define LPDDR_DENALI_PI_3_PI_RELEASE_DFI(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_3_PI_RELEASE_DFI_SHIFT)) & LPDDR_DENALI_PI_3_PI_RELEASE_DFI_MASK)

#define LPDDR_DENALI_PI_3_PI_NORMAL_LVL_SEQ_MASK (0x1000000U)
#define LPDDR_DENALI_PI_3_PI_NORMAL_LVL_SEQ_SHIFT (24U)
/*! PI_NORMAL_LVL_SEQ
 *  0b0..Return DFI bus to the controller after current leveling request is complete (except for initialization)
 *  0b1..Return DFI bus to the controller after all pending leveling requests are complete
 */
#define LPDDR_DENALI_PI_3_PI_NORMAL_LVL_SEQ(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_3_PI_NORMAL_LVL_SEQ_SHIFT)) & LPDDR_DENALI_PI_3_PI_NORMAL_LVL_SEQ_MASK)
/*! @} */

/*! @name DENALI_PI_4 - DENALI_PI_4 */
/*! @{ */

#define LPDDR_DENALI_PI_4_PI_INIT_LVL_EN_MASK    (0x1U)
#define LPDDR_DENALI_PI_4_PI_INIT_LVL_EN_SHIFT   (0U)
/*! PI_INIT_LVL_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PI_4_PI_INIT_LVL_EN(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_4_PI_INIT_LVL_EN_SHIFT)) & LPDDR_DENALI_PI_4_PI_INIT_LVL_EN_MASK)

#define LPDDR_DENALI_PI_4_PI_NOTCARE_PHYUPD_MASK (0x300U)
#define LPDDR_DENALI_PI_4_PI_NOTCARE_PHYUPD_SHIFT (8U)
/*! PI_NOTCARE_PHYUPD
 *  0b00..PI not issue master request
 *  0b01..PI issue master request
 */
#define LPDDR_DENALI_PI_4_PI_NOTCARE_PHYUPD(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_4_PI_NOTCARE_PHYUPD_SHIFT)) & LPDDR_DENALI_PI_4_PI_NOTCARE_PHYUPD_MASK)

#define LPDDR_DENALI_PI_4_PI_TCMD_GAP_MASK       (0xFFFF0000U)
#define LPDDR_DENALI_PI_4_PI_TCMD_GAP_SHIFT      (16U)
#define LPDDR_DENALI_PI_4_PI_TCMD_GAP(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_4_PI_TCMD_GAP_SHIFT)) & LPDDR_DENALI_PI_4_PI_TCMD_GAP_MASK)
/*! @} */

/*! @name DENALI_PI_5 - DENALI_PI_5 */
/*! @{ */

#define LPDDR_DENALI_PI_5_PI_TRAIN_ALL_FREQ_REQ_MASK (0x100U)
#define LPDDR_DENALI_PI_5_PI_TRAIN_ALL_FREQ_REQ_SHIFT (8U)
#define LPDDR_DENALI_PI_5_PI_TRAIN_ALL_FREQ_REQ(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_5_PI_TRAIN_ALL_FREQ_REQ_SHIFT)) & LPDDR_DENALI_PI_5_PI_TRAIN_ALL_FREQ_REQ_MASK)

#define LPDDR_DENALI_PI_5_PI_DFI_VERSION_MASK    (0x10000U)
#define LPDDR_DENALI_PI_5_PI_DFI_VERSION_SHIFT   (16U)
/*! PI_DFI_VERSION
 *  0b0..DFI 4.0 version
 *  0b1..DFI 4.1 version
 */
#define LPDDR_DENALI_PI_5_PI_DFI_VERSION(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_5_PI_DFI_VERSION_SHIFT)) & LPDDR_DENALI_PI_5_PI_DFI_VERSION_MASK)

#define LPDDR_DENALI_PI_5_PI_DFI_PHYMSTR_TYPE_MASK (0x3000000U)
#define LPDDR_DENALI_PI_5_PI_DFI_PHYMSTR_TYPE_SHIFT (24U)
/*! PI_DFI_PHYMSTR_TYPE
 *  0b00..IDLE. The MC should close all pages.
 *  0b01..IDLE or Self Refresh.
 */
#define LPDDR_DENALI_PI_5_PI_DFI_PHYMSTR_TYPE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_5_PI_DFI_PHYMSTR_TYPE_SHIFT)) & LPDDR_DENALI_PI_5_PI_DFI_PHYMSTR_TYPE_MASK)
/*! @} */

/*! @name DENALI_PI_11 - DENALI_PI_11 */
/*! @{ */

#define LPDDR_DENALI_PI_11_PI_EXIT_AFTER_INIT_CALVL_MASK (0x1U)
#define LPDDR_DENALI_PI_11_PI_EXIT_AFTER_INIT_CALVL_SHIFT (0U)
#define LPDDR_DENALI_PI_11_PI_EXIT_AFTER_INIT_CALVL(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_11_PI_EXIT_AFTER_INIT_CALVL_SHIFT)) & LPDDR_DENALI_PI_11_PI_EXIT_AFTER_INIT_CALVL_MASK)

#define LPDDR_DENALI_PI_11_PI_INIT_WORK_FREQ_MASK (0x1F00U)
#define LPDDR_DENALI_PI_11_PI_INIT_WORK_FREQ_SHIFT (8U)
/*! PI_INIT_WORK_FREQ - Indicates the initial work frequency after initialization and initial leveling sequence. */
#define LPDDR_DENALI_PI_11_PI_INIT_WORK_FREQ(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_11_PI_INIT_WORK_FREQ_SHIFT)) & LPDDR_DENALI_PI_11_PI_INIT_WORK_FREQ_MASK)

#define LPDDR_DENALI_PI_11_PI_INIT_DFS_CALVL_ONLY_MASK (0x10000U)
#define LPDDR_DENALI_PI_11_PI_INIT_DFS_CALVL_ONLY_SHIFT (16U)
/*! PI_INIT_DFS_CALVL_ONLY
 *  0b0..Perform all trainings at each frequency.
 *  0b1..Perform frequency training only for CA leveling.
 */
#define LPDDR_DENALI_PI_11_PI_INIT_DFS_CALVL_ONLY(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_11_PI_INIT_DFS_CALVL_ONLY_SHIFT)) & LPDDR_DENALI_PI_11_PI_INIT_DFS_CALVL_ONLY_MASK)
/*! @} */

/*! @name DENALI_PI_12 - DENALI_PI_12 */
/*! @{ */

#define LPDDR_DENALI_PI_12_PI_FREQ_MAP_MASK      (0xFFFFFFFFU)
#define LPDDR_DENALI_PI_12_PI_FREQ_MAP_SHIFT     (0U)
#define LPDDR_DENALI_PI_12_PI_FREQ_MAP(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_12_PI_FREQ_MAP_SHIFT)) & LPDDR_DENALI_PI_12_PI_FREQ_MAP_MASK)
/*! @} */

/*! @name DENALI_PI_13 - DENALI_PI_13 */
/*! @{ */

#define LPDDR_DENALI_PI_13_PI_SW_RST_N_MASK      (0x1U)
#define LPDDR_DENALI_PI_13_PI_SW_RST_N_SHIFT     (0U)
#define LPDDR_DENALI_PI_13_PI_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_13_PI_SW_RST_N_SHIFT)) & LPDDR_DENALI_PI_13_PI_SW_RST_N_MASK)

#define LPDDR_DENALI_PI_13_PI_CS_MAP_MASK        (0xF0000U)
#define LPDDR_DENALI_PI_13_PI_CS_MAP_SHIFT       (16U)
/*! PI_CS_MAP - Defines which chip selects are active. */
#define LPDDR_DENALI_PI_13_PI_CS_MAP(x)          (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_13_PI_CS_MAP_SHIFT)) & LPDDR_DENALI_PI_13_PI_CS_MAP_MASK)

#define LPDDR_DENALI_PI_13_PI_RANK_NUM_PER_CKE_MASK (0x1F000000U)
#define LPDDR_DENALI_PI_13_PI_RANK_NUM_PER_CKE_SHIFT (24U)
/*! PI_RANK_NUM_PER_CKE - Defines the number of chip selects share one cke */
#define LPDDR_DENALI_PI_13_PI_RANK_NUM_PER_CKE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_13_PI_RANK_NUM_PER_CKE_SHIFT)) & LPDDR_DENALI_PI_13_PI_RANK_NUM_PER_CKE_MASK)
/*! @} */

/*! @name DENALI_PI_14 - DENALI_PI_14 */
/*! @{ */

#define LPDDR_DENALI_PI_14_PI_SRX_LVL_TARGET_CS_EN_MASK (0x1U)
#define LPDDR_DENALI_PI_14_PI_SRX_LVL_TARGET_CS_EN_SHIFT (0U)
/*! PI_SRX_LVL_TARGET_CS_EN
 *  0b0..All CS defined by pi_cs_map
 *  0b1..Only target CS
 */
#define LPDDR_DENALI_PI_14_PI_SRX_LVL_TARGET_CS_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_14_PI_SRX_LVL_TARGET_CS_EN_SHIFT)) & LPDDR_DENALI_PI_14_PI_SRX_LVL_TARGET_CS_EN_MASK)

#define LPDDR_DENALI_PI_14_PI_TMRR_MASK          (0xF00U)
#define LPDDR_DENALI_PI_14_PI_TMRR_SHIFT         (8U)
/*! PI_TMRR - DRAM tMRR value in memory clock cycles. */
#define LPDDR_DENALI_PI_14_PI_TMRR(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_14_PI_TMRR_SHIFT)) & LPDDR_DENALI_PI_14_PI_TMRR_MASK)

#define LPDDR_DENALI_PI_14_PI_PREAMBLE_SUPPORT_MASK (0x30000U)
#define LPDDR_DENALI_PI_14_PI_PREAMBLE_SUPPORT_SHIFT (16U)
#define LPDDR_DENALI_PI_14_PI_PREAMBLE_SUPPORT(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_14_PI_PREAMBLE_SUPPORT_SHIFT)) & LPDDR_DENALI_PI_14_PI_PREAMBLE_SUPPORT_MASK)

#define LPDDR_DENALI_PI_14_PI_VRCG_EN_MASK       (0x3000000U)
#define LPDDR_DENALI_PI_14_PI_VRCG_EN_SHIFT      (24U)
#define LPDDR_DENALI_PI_14_PI_VRCG_EN(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_14_PI_VRCG_EN_SHIFT)) & LPDDR_DENALI_PI_14_PI_VRCG_EN_MASK)
/*! @} */

/*! @name DENALI_PI_15 - DENALI_PI_15 */
/*! @{ */

#define LPDDR_DENALI_PI_15_PI_MCAREF_FORWARD_ONLY_MASK (0x1U)
#define LPDDR_DENALI_PI_15_PI_MCAREF_FORWARD_ONLY_SHIFT (0U)
/*! PI_MCAREF_FORWARD_ONLY
 *  0b0..PI generates AREF commands
 *  0b1..PI does not generate AREF; only forwards AREF from the memory controller
 */
#define LPDDR_DENALI_PI_15_PI_MCAREF_FORWARD_ONLY(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_15_PI_MCAREF_FORWARD_ONLY_SHIFT)) & LPDDR_DENALI_PI_15_PI_MCAREF_FORWARD_ONLY_MASK)
/*! @} */

/*! @name DENALI_PI_16 - DENALI_PI_16 */
/*! @{ */

#define LPDDR_DENALI_PI_16_PI_TREF_INTERVAL_MASK (0xFFFFFU)
#define LPDDR_DENALI_PI_16_PI_TREF_INTERVAL_SHIFT (0U)
/*! PI_TREF_INTERVAL - Defines the cycles between refreshes to different chip selects. */
#define LPDDR_DENALI_PI_16_PI_TREF_INTERVAL(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_16_PI_TREF_INTERVAL_SHIFT)) & LPDDR_DENALI_PI_16_PI_TREF_INTERVAL_MASK)

#define LPDDR_DENALI_PI_16_PI_ON_DFIBUS_MASK     (0x1000000U)
#define LPDDR_DENALI_PI_16_PI_ON_DFIBUS_SHIFT    (24U)
/*! PI_ON_DFIBUS
 *  0b0..PI not controlling the DFI bus
 *  0b1..PI in control of the DFI bus
 */
#define LPDDR_DENALI_PI_16_PI_ON_DFIBUS(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_16_PI_ON_DFIBUS_SHIFT)) & LPDDR_DENALI_PI_16_PI_ON_DFIBUS_MASK)
/*! @} */

/*! @name DENALI_PI_29 - DENALI_PI_29 */
/*! @{ */

#define LPDDR_DENALI_PI_29_PI_WRLVL_CS_MAP_MASK  (0xFU)
#define LPDDR_DENALI_PI_29_PI_WRLVL_CS_MAP_SHIFT (0U)
#define LPDDR_DENALI_PI_29_PI_WRLVL_CS_MAP(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_29_PI_WRLVL_CS_MAP_SHIFT)) & LPDDR_DENALI_PI_29_PI_WRLVL_CS_MAP_MASK)

#define LPDDR_DENALI_PI_29_PI_WRLVL_ERROR_STATUS_MASK (0x100U)
#define LPDDR_DENALI_PI_29_PI_WRLVL_ERROR_STATUS_SHIFT (8U)
#define LPDDR_DENALI_PI_29_PI_WRLVL_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_29_PI_WRLVL_ERROR_STATUS_SHIFT)) & LPDDR_DENALI_PI_29_PI_WRLVL_ERROR_STATUS_MASK)

#define LPDDR_DENALI_PI_29_PI_TDFI_WRLVL_EN_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_29_PI_TDFI_WRLVL_EN_SHIFT (16U)
#define LPDDR_DENALI_PI_29_PI_TDFI_WRLVL_EN(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_29_PI_TDFI_WRLVL_EN_SHIFT)) & LPDDR_DENALI_PI_29_PI_TDFI_WRLVL_EN_MASK)
/*! @} */

/*! @name DENALI_PI_44 - DENALI_PI_44 */
/*! @{ */

#define LPDDR_DENALI_PI_44_PI_RDLVL_CS_MAP_MASK  (0xF0000U)
#define LPDDR_DENALI_PI_44_PI_RDLVL_CS_MAP_SHIFT (16U)
/*! PI_RDLVL_CS_MAP
 *  0b0000..Do not use this chip for data eye training
 *  0b0001..Use this chip for data eye training
 */
#define LPDDR_DENALI_PI_44_PI_RDLVL_CS_MAP(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_44_PI_RDLVL_CS_MAP_SHIFT)) & LPDDR_DENALI_PI_44_PI_RDLVL_CS_MAP_MASK)

#define LPDDR_DENALI_PI_44_PI_RDLVL_GATE_CS_MAP_MASK (0xF000000U)
#define LPDDR_DENALI_PI_44_PI_RDLVL_GATE_CS_MAP_SHIFT (24U)
/*! PI_RDLVL_GATE_CS_MAP
 *  0b0000..Do not use this chip for gate training
 *  0b0001..Use this chip for gate training
 */
#define LPDDR_DENALI_PI_44_PI_RDLVL_GATE_CS_MAP(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_44_PI_RDLVL_GATE_CS_MAP_SHIFT)) & LPDDR_DENALI_PI_44_PI_RDLVL_GATE_CS_MAP_MASK)
/*! @} */

/*! @name DENALI_PI_45 - DENALI_PI_45 */
/*! @{ */

#define LPDDR_DENALI_PI_45_PI_TDFI_RDLVL_RR_MASK (0x3FFU)
#define LPDDR_DENALI_PI_45_PI_TDFI_RDLVL_RR_SHIFT (0U)
#define LPDDR_DENALI_PI_45_PI_TDFI_RDLVL_RR(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_45_PI_TDFI_RDLVL_RR_SHIFT)) & LPDDR_DENALI_PI_45_PI_TDFI_RDLVL_RR_MASK)
/*! @} */

/*! @name DENALI_PI_55 - DENALI_PI_55 */
/*! @{ */

#define LPDDR_DENALI_PI_55_PI_CALVL_CS_MAP_MASK  (0xF00U)
#define LPDDR_DENALI_PI_55_PI_CALVL_CS_MAP_SHIFT (8U)
#define LPDDR_DENALI_PI_55_PI_CALVL_CS_MAP(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_55_PI_CALVL_CS_MAP_SHIFT)) & LPDDR_DENALI_PI_55_PI_CALVL_CS_MAP_MASK)

#define LPDDR_DENALI_PI_55_PI_TDFI_CALVL_EN_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_55_PI_TDFI_CALVL_EN_SHIFT (16U)
#define LPDDR_DENALI_PI_55_PI_TDFI_CALVL_EN(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_55_PI_TDFI_CALVL_EN_SHIFT)) & LPDDR_DENALI_PI_55_PI_TDFI_CALVL_EN_MASK)
/*! @} */

/*! @name DENALI_PI_64 - DENALI_PI_64 */
/*! @{ */

#define LPDDR_DENALI_PI_64_PI_WDQLVL_BST_NUM_MASK (0x7U)
#define LPDDR_DENALI_PI_64_PI_WDQLVL_BST_NUM_SHIFT (0U)
/*! PI_WDQLVL_BST_NUM - Defines the number of write/read bursts issued at each step in write DQ training. */
#define LPDDR_DENALI_PI_64_PI_WDQLVL_BST_NUM(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_64_PI_WDQLVL_BST_NUM_SHIFT)) & LPDDR_DENALI_PI_64_PI_WDQLVL_BST_NUM_MASK)

#define LPDDR_DENALI_PI_64_PI_WDQLVL_RESP_MASK_MASK (0xF00U)
#define LPDDR_DENALI_PI_64_PI_WDQLVL_RESP_MASK_SHIFT (8U)
#define LPDDR_DENALI_PI_64_PI_WDQLVL_RESP_MASK(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_64_PI_WDQLVL_RESP_MASK_SHIFT)) & LPDDR_DENALI_PI_64_PI_WDQLVL_RESP_MASK_MASK)

#define LPDDR_DENALI_PI_64_PI_WDQLVL_CS_MAP_MASK (0xF000000U)
#define LPDDR_DENALI_PI_64_PI_WDQLVL_CS_MAP_SHIFT (24U)
/*! PI_WDQLVL_CS_MAP
 *  0b0000..Do not use this chip for data eye training
 *  0b0001..Use this chip for data eye training
 */
#define LPDDR_DENALI_PI_64_PI_WDQLVL_CS_MAP(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_64_PI_WDQLVL_CS_MAP_SHIFT)) & LPDDR_DENALI_PI_64_PI_WDQLVL_CS_MAP_MASK)
/*! @} */

/*! @name DENALI_PI_70 - DENALI_PI_70 */
/*! @{ */

#define LPDDR_DENALI_PI_70_PI_WDQLVL_DISABLE_DFS_MASK (0x1U)
#define LPDDR_DENALI_PI_70_PI_WDQLVL_DISABLE_DFS_SHIFT (0U)
/*! PI_WDQLVL_DISABLE_DFS
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define LPDDR_DENALI_PI_70_PI_WDQLVL_DISABLE_DFS(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_70_PI_WDQLVL_DISABLE_DFS_SHIFT)) & LPDDR_DENALI_PI_70_PI_WDQLVL_DISABLE_DFS_MASK)

#define LPDDR_DENALI_PI_70_PI_WDQLVL_OSC_EN_MASK (0x10000U)
#define LPDDR_DENALI_PI_70_PI_WDQLVL_OSC_EN_SHIFT (16U)
/*! PI_WDQLVL_OSC_EN - Enable for DQS oscillator triggered write DQ training.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PI_70_PI_WDQLVL_OSC_EN(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_70_PI_WDQLVL_OSC_EN_SHIFT)) & LPDDR_DENALI_PI_70_PI_WDQLVL_OSC_EN_MASK)

#define LPDDR_DENALI_PI_70_PI_PARALLEL_WDQLVL_EN_MASK (0x1000000U)
#define LPDDR_DENALI_PI_70_PI_PARALLEL_WDQLVL_EN_SHIFT (24U)
/*! PI_PARALLEL_WDQLVL_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PI_70_PI_PARALLEL_WDQLVL_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_70_PI_PARALLEL_WDQLVL_EN_SHIFT)) & LPDDR_DENALI_PI_70_PI_PARALLEL_WDQLVL_EN_MASK)
/*! @} */

/*! @name DENALI_PI_71 - DENALI_PI_71 */
/*! @{ */

#define LPDDR_DENALI_PI_71_PI_BANK_DIFF_MASK     (0x3U)
#define LPDDR_DENALI_PI_71_PI_BANK_DIFF_SHIFT    (0U)
#define LPDDR_DENALI_PI_71_PI_BANK_DIFF(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_71_PI_BANK_DIFF_SHIFT)) & LPDDR_DENALI_PI_71_PI_BANK_DIFF_MASK)

#define LPDDR_DENALI_PI_71_PI_ROW_DIFF_MASK      (0x700U)
#define LPDDR_DENALI_PI_71_PI_ROW_DIFF_SHIFT     (8U)
#define LPDDR_DENALI_PI_71_PI_ROW_DIFF(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_71_PI_ROW_DIFF_SHIFT)) & LPDDR_DENALI_PI_71_PI_ROW_DIFF_MASK)

#define LPDDR_DENALI_PI_71_PI_TCCD_MASK          (0x1F0000U)
#define LPDDR_DENALI_PI_71_PI_TCCD_SHIFT         (16U)
#define LPDDR_DENALI_PI_71_PI_TCCD(x)            (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_71_PI_TCCD_SHIFT)) & LPDDR_DENALI_PI_71_PI_TCCD_MASK)
/*! @} */

/*! @name DENALI_PI_90 - DENALI_PI_90 */
/*! @{ */

#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_EN_MASK (0x1U)
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_EN_SHIFT (0U)
/*! PI_DATA_BYTE_SWAP_EN - DATA pin swap function enable */
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_EN_SHIFT)) & LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_EN_MASK)

#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE0_MASK (0x300U)
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE0_SHIFT (8U)
/*! PI_DATA_BYTE_SWAP_SLICE0 - DATA pin 0 mux selector */
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE0_SHIFT)) & LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE0_MASK)

#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE1_MASK (0x30000U)
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE1_SHIFT (16U)
/*! PI_DATA_BYTE_SWAP_SLICE1 - DATA pin 1 mux selector */
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE1_SHIFT)) & LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE1_MASK)

#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE2_MASK (0x3000000U)
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE2_SHIFT (24U)
/*! PI_DATA_BYTE_SWAP_SLICE2 - DATA pin 2 mux selector */
#define LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE2_SHIFT)) & LPDDR_DENALI_PI_90_PI_DATA_BYTE_SWAP_SLICE2_MASK)
/*! @} */

/*! @name DENALI_PI_91 - DENALI_PI_91 */
/*! @{ */

#define LPDDR_DENALI_PI_91_PI_DATA_BYTE_SWAP_SLICE3_MASK (0x3U)
#define LPDDR_DENALI_PI_91_PI_DATA_BYTE_SWAP_SLICE3_SHIFT (0U)
/*! PI_DATA_BYTE_SWAP_SLICE3 - DATA pin 3 mux selector */
#define LPDDR_DENALI_PI_91_PI_DATA_BYTE_SWAP_SLICE3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_91_PI_DATA_BYTE_SWAP_SLICE3_SHIFT)) & LPDDR_DENALI_PI_91_PI_DATA_BYTE_SWAP_SLICE3_MASK)

#define LPDDR_DENALI_PI_91_PI_CTRLUPD_REQ_PER_AREF_EN_MASK (0x100U)
#define LPDDR_DENALI_PI_91_PI_CTRLUPD_REQ_PER_AREF_EN_SHIFT (8U)
/*! PI_CTRLUPD_REQ_PER_AREF_EN - Enable an automatic PI initiated update (dfi_ctrlupd_req) after every refresh. */
#define LPDDR_DENALI_PI_91_PI_CTRLUPD_REQ_PER_AREF_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_91_PI_CTRLUPD_REQ_PER_AREF_EN_SHIFT)) & LPDDR_DENALI_PI_91_PI_CTRLUPD_REQ_PER_AREF_EN_MASK)

#define LPDDR_DENALI_PI_91_PI_TDFI_CTRLUPD_MIN_MASK (0xFFFF0000U)
#define LPDDR_DENALI_PI_91_PI_TDFI_CTRLUPD_MIN_SHIFT (16U)
/*! PI_TDFI_CTRLUPD_MIN - Reports the DFI tCTRLUPD_MIN timing parameter (in DFI clocks), the minimum cycles that dfi_ctrlupd_req must be asserted. */
#define LPDDR_DENALI_PI_91_PI_TDFI_CTRLUPD_MIN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_91_PI_TDFI_CTRLUPD_MIN_SHIFT)) & LPDDR_DENALI_PI_91_PI_TDFI_CTRLUPD_MIN_MASK)
/*! @} */

/*! @name DENALI_PI_92 - DENALI_PI_92 */
/*! @{ */

#define LPDDR_DENALI_PI_92_PI_UPDATE_ERROR_STATUS_MASK (0x3U)
#define LPDDR_DENALI_PI_92_PI_UPDATE_ERROR_STATUS_SHIFT (0U)
#define LPDDR_DENALI_PI_92_PI_UPDATE_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_92_PI_UPDATE_ERROR_STATUS_SHIFT)) & LPDDR_DENALI_PI_92_PI_UPDATE_ERROR_STATUS_MASK)

#define LPDDR_DENALI_PI_92_PI_BIST_GO_MASK       (0x100U)
#define LPDDR_DENALI_PI_92_PI_BIST_GO_SHIFT      (8U)
#define LPDDR_DENALI_PI_92_PI_BIST_GO(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_92_PI_BIST_GO_SHIFT)) & LPDDR_DENALI_PI_92_PI_BIST_GO_MASK)

#define LPDDR_DENALI_PI_92_PI_BIST_RESULT_MASK   (0x30000U)
#define LPDDR_DENALI_PI_92_PI_BIST_RESULT_SHIFT  (16U)
#define LPDDR_DENALI_PI_92_PI_BIST_RESULT(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_92_PI_BIST_RESULT_SHIFT)) & LPDDR_DENALI_PI_92_PI_BIST_RESULT_MASK)

#define LPDDR_DENALI_PI_92_PI_BIST_LFSR_PATTERN_DONE_MASK (0x1000000U)
#define LPDDR_DENALI_PI_92_PI_BIST_LFSR_PATTERN_DONE_SHIFT (24U)
#define LPDDR_DENALI_PI_92_PI_BIST_LFSR_PATTERN_DONE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_92_PI_BIST_LFSR_PATTERN_DONE_SHIFT)) & LPDDR_DENALI_PI_92_PI_BIST_LFSR_PATTERN_DONE_MASK)
/*! @} */

/*! @name DENALI_PI_161 - DENALI_PI_161 */
/*! @{ */

#define LPDDR_DENALI_PI_161_PI_NOTCARE_MC_INIT_START_MASK (0x1U)
#define LPDDR_DENALI_PI_161_PI_NOTCARE_MC_INIT_START_SHIFT (0U)
/*! PI_NOTCARE_MC_INIT_START
 *  0b0..No waiting for dfi_init_start.
 *  0b1..Wait for dfi_init_start
 */
#define LPDDR_DENALI_PI_161_PI_NOTCARE_MC_INIT_START(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_161_PI_NOTCARE_MC_INIT_START_SHIFT)) & LPDDR_DENALI_PI_161_PI_NOTCARE_MC_INIT_START_MASK)

#define LPDDR_DENALI_PI_161_PI_TSDO_F0_MASK      (0xFF0000U)
#define LPDDR_DENALI_PI_161_PI_TSDO_F0_SHIFT     (16U)
/*! PI_TSDO_F0 - The delay from the read preamble training MRS command to the data strobe drive out for frequency set 0, in PI clocks. */
#define LPDDR_DENALI_PI_161_PI_TSDO_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_161_PI_TSDO_F0_SHIFT)) & LPDDR_DENALI_PI_161_PI_TSDO_F0_MASK)

#define LPDDR_DENALI_PI_161_PI_TSDO_F1_MASK      (0xFF000000U)
#define LPDDR_DENALI_PI_161_PI_TSDO_F1_SHIFT     (24U)
/*! PI_TSDO_F1 - The delay from the read preamble training MRS command to the data strobe drive out for frequency set 1, in PI clocks. */
#define LPDDR_DENALI_PI_161_PI_TSDO_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_161_PI_TSDO_F1_SHIFT)) & LPDDR_DENALI_PI_161_PI_TSDO_F1_MASK)
/*! @} */

/*! @name DENALI_PI_162 - DENALI_PI_162 */
/*! @{ */

#define LPDDR_DENALI_PI_162_PI_TSDO_F2_MASK      (0xFFU)
#define LPDDR_DENALI_PI_162_PI_TSDO_F2_SHIFT     (0U)
/*! PI_TSDO_F2 - The delay from the read preamble training MRS command to the data strobe drive out for frequency set 2, in PI clocks */
#define LPDDR_DENALI_PI_162_PI_TSDO_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_162_PI_TSDO_F2_SHIFT)) & LPDDR_DENALI_PI_162_PI_TSDO_F2_MASK)
/*! @} */

/*! @name DENALI_PI_163 - DENALI_PI_163 */
/*! @{ */

#define LPDDR_DENALI_PI_163_PI_TDELAY_RDWR_2_BUS_IDLE_F0_MASK (0xFFU)
#define LPDDR_DENALI_PI_163_PI_TDELAY_RDWR_2_BUS_IDLE_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_163_PI_TDELAY_RDWR_2_BUS_IDLE_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_163_PI_TDELAY_RDWR_2_BUS_IDLE_F0_SHIFT)) & LPDDR_DENALI_PI_163_PI_TDELAY_RDWR_2_BUS_IDLE_F0_MASK)
/*! @} */

/*! @name DENALI_PI_164 - DENALI_PI_164 */
/*! @{ */

#define LPDDR_DENALI_PI_164_PI_TDELAY_RDWR_2_BUS_IDLE_F1_MASK (0xFFU)
#define LPDDR_DENALI_PI_164_PI_TDELAY_RDWR_2_BUS_IDLE_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_164_PI_TDELAY_RDWR_2_BUS_IDLE_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_164_PI_TDELAY_RDWR_2_BUS_IDLE_F1_SHIFT)) & LPDDR_DENALI_PI_164_PI_TDELAY_RDWR_2_BUS_IDLE_F1_MASK)
/*! @} */

/*! @name DENALI_PI_165 - DENALI_PI_165 */
/*! @{ */

#define LPDDR_DENALI_PI_165_PI_TDELAY_RDWR_2_BUS_IDLE_F2_MASK (0xFFU)
#define LPDDR_DENALI_PI_165_PI_TDELAY_RDWR_2_BUS_IDLE_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_165_PI_TDELAY_RDWR_2_BUS_IDLE_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_165_PI_TDELAY_RDWR_2_BUS_IDLE_F2_SHIFT)) & LPDDR_DENALI_PI_165_PI_TDELAY_RDWR_2_BUS_IDLE_F2_MASK)

#define LPDDR_DENALI_PI_165_PI_ZQINIT_F0_MASK    (0xFFF00U)
#define LPDDR_DENALI_PI_165_PI_ZQINIT_F0_SHIFT   (8U)
#define LPDDR_DENALI_PI_165_PI_ZQINIT_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_165_PI_ZQINIT_F0_SHIFT)) & LPDDR_DENALI_PI_165_PI_ZQINIT_F0_MASK)
/*! @} */

/*! @name DENALI_PI_166 - DENALI_PI_166 */
/*! @{ */

#define LPDDR_DENALI_PI_166_PI_ZQINIT_F1_MASK    (0xFFFU)
#define LPDDR_DENALI_PI_166_PI_ZQINIT_F1_SHIFT   (0U)
#define LPDDR_DENALI_PI_166_PI_ZQINIT_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_166_PI_ZQINIT_F1_SHIFT)) & LPDDR_DENALI_PI_166_PI_ZQINIT_F1_MASK)

#define LPDDR_DENALI_PI_166_PI_ZQINIT_F2_MASK    (0xFFF0000U)
#define LPDDR_DENALI_PI_166_PI_ZQINIT_F2_SHIFT   (16U)
#define LPDDR_DENALI_PI_166_PI_ZQINIT_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_166_PI_ZQINIT_F2_SHIFT)) & LPDDR_DENALI_PI_166_PI_ZQINIT_F2_MASK)
/*! @} */

/*! @name DENALI_PI_167 - DENALI_PI_167 */
/*! @{ */

#define LPDDR_DENALI_PI_167_PI_WRLAT_F0_MASK     (0x7FU)
#define LPDDR_DENALI_PI_167_PI_WRLAT_F0_SHIFT    (0U)
#define LPDDR_DENALI_PI_167_PI_WRLAT_F0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_167_PI_WRLAT_F0_SHIFT)) & LPDDR_DENALI_PI_167_PI_WRLAT_F0_MASK)

#define LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F0_MASK (0x7F00U)
#define LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F0_SHIFT)) & LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F0_MASK)

#define LPDDR_DENALI_PI_167_PI_WRLAT_F1_MASK     (0x7F0000U)
#define LPDDR_DENALI_PI_167_PI_WRLAT_F1_SHIFT    (16U)
#define LPDDR_DENALI_PI_167_PI_WRLAT_F1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_167_PI_WRLAT_F1_SHIFT)) & LPDDR_DENALI_PI_167_PI_WRLAT_F1_MASK)

#define LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F1_MASK (0x7F000000U)
#define LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F1_SHIFT (24U)
#define LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F1_SHIFT)) & LPDDR_DENALI_PI_167_PI_CASLAT_LIN_F1_MASK)
/*! @} */

/*! @name DENALI_PI_168 - DENALI_PI_168 */
/*! @{ */

#define LPDDR_DENALI_PI_168_PI_WRLAT_F2_MASK     (0x7FU)
#define LPDDR_DENALI_PI_168_PI_WRLAT_F2_SHIFT    (0U)
#define LPDDR_DENALI_PI_168_PI_WRLAT_F2(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_168_PI_WRLAT_F2_SHIFT)) & LPDDR_DENALI_PI_168_PI_WRLAT_F2_MASK)

#define LPDDR_DENALI_PI_168_PI_CASLAT_LIN_F2_MASK (0x7F00U)
#define LPDDR_DENALI_PI_168_PI_CASLAT_LIN_F2_SHIFT (8U)
#define LPDDR_DENALI_PI_168_PI_CASLAT_LIN_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_168_PI_CASLAT_LIN_F2_SHIFT)) & LPDDR_DENALI_PI_168_PI_CASLAT_LIN_F2_MASK)

#define LPDDR_DENALI_PI_168_PI_TRFC_F0_MASK      (0x3FF0000U)
#define LPDDR_DENALI_PI_168_PI_TRFC_F0_SHIFT     (16U)
#define LPDDR_DENALI_PI_168_PI_TRFC_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_168_PI_TRFC_F0_SHIFT)) & LPDDR_DENALI_PI_168_PI_TRFC_F0_MASK)
/*! @} */

/*! @name DENALI_PI_169 - DENALI_PI_169 */
/*! @{ */

#define LPDDR_DENALI_PI_169_PI_TREF_F0_MASK      (0xFFFFFU)
#define LPDDR_DENALI_PI_169_PI_TREF_F0_SHIFT     (0U)
#define LPDDR_DENALI_PI_169_PI_TREF_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_169_PI_TREF_F0_SHIFT)) & LPDDR_DENALI_PI_169_PI_TREF_F0_MASK)
/*! @} */

/*! @name DENALI_PI_170 - DENALI_PI_170 */
/*! @{ */

#define LPDDR_DENALI_PI_170_PI_TRFC_F1_MASK      (0x3FFU)
#define LPDDR_DENALI_PI_170_PI_TRFC_F1_SHIFT     (0U)
#define LPDDR_DENALI_PI_170_PI_TRFC_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_170_PI_TRFC_F1_SHIFT)) & LPDDR_DENALI_PI_170_PI_TRFC_F1_MASK)
/*! @} */

/*! @name DENALI_PI_171 - DENALI_PI_171 */
/*! @{ */

#define LPDDR_DENALI_PI_171_PI_TREF_F1_MASK      (0xFFFFFU)
#define LPDDR_DENALI_PI_171_PI_TREF_F1_SHIFT     (0U)
#define LPDDR_DENALI_PI_171_PI_TREF_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_171_PI_TREF_F1_SHIFT)) & LPDDR_DENALI_PI_171_PI_TREF_F1_MASK)
/*! @} */

/*! @name DENALI_PI_172 - DENALI_PI_172 */
/*! @{ */

#define LPDDR_DENALI_PI_172_PI_TRFC_F2_MASK      (0x3FFU)
#define LPDDR_DENALI_PI_172_PI_TRFC_F2_SHIFT     (0U)
#define LPDDR_DENALI_PI_172_PI_TRFC_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_172_PI_TRFC_F2_SHIFT)) & LPDDR_DENALI_PI_172_PI_TRFC_F2_MASK)
/*! @} */

/*! @name DENALI_PI_173 - DENALI_PI_173 */
/*! @{ */

#define LPDDR_DENALI_PI_173_PI_TREF_F2_MASK      (0xFFFFFU)
#define LPDDR_DENALI_PI_173_PI_TREF_F2_SHIFT     (0U)
#define LPDDR_DENALI_PI_173_PI_TREF_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_173_PI_TREF_F2_SHIFT)) & LPDDR_DENALI_PI_173_PI_TREF_F2_MASK)

#define LPDDR_DENALI_PI_173_PI_TDFI_CTRL_DELAY_F0_MASK (0xF000000U)
#define LPDDR_DENALI_PI_173_PI_TDFI_CTRL_DELAY_F0_SHIFT (24U)
#define LPDDR_DENALI_PI_173_PI_TDFI_CTRL_DELAY_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_173_PI_TDFI_CTRL_DELAY_F0_SHIFT)) & LPDDR_DENALI_PI_173_PI_TDFI_CTRL_DELAY_F0_MASK)
/*! @} */

/*! @name DENALI_PI_174 - DENALI_PI_174 */
/*! @{ */

#define LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F1_MASK (0xFU)
#define LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F1_SHIFT)) & LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F1_MASK)

#define LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F2_MASK (0xF00U)
#define LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F2_SHIFT (8U)
#define LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F2_SHIFT)) & LPDDR_DENALI_PI_174_PI_TDFI_CTRL_DELAY_F2_MASK)

#define LPDDR_DENALI_PI_174_PI_WRLVL_EN_F0_MASK  (0x30000U)
#define LPDDR_DENALI_PI_174_PI_WRLVL_EN_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_174_PI_WRLVL_EN_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_174_PI_WRLVL_EN_F0_SHIFT)) & LPDDR_DENALI_PI_174_PI_WRLVL_EN_F0_MASK)

#define LPDDR_DENALI_PI_174_PI_WRLVL_EN_F1_MASK  (0x3000000U)
#define LPDDR_DENALI_PI_174_PI_WRLVL_EN_F1_SHIFT (24U)
#define LPDDR_DENALI_PI_174_PI_WRLVL_EN_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_174_PI_WRLVL_EN_F1_SHIFT)) & LPDDR_DENALI_PI_174_PI_WRLVL_EN_F1_MASK)
/*! @} */

/*! @name DENALI_PI_175 - DENALI_PI_175 */
/*! @{ */

#define LPDDR_DENALI_PI_175_PI_WRLVL_EN_F2_MASK  (0x3U)
#define LPDDR_DENALI_PI_175_PI_WRLVL_EN_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_175_PI_WRLVL_EN_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_175_PI_WRLVL_EN_F2_SHIFT)) & LPDDR_DENALI_PI_175_PI_WRLVL_EN_F2_MASK)

#define LPDDR_DENALI_PI_175_PI_TDFI_WRLVL_WW_F0_MASK (0x3FF00U)
#define LPDDR_DENALI_PI_175_PI_TDFI_WRLVL_WW_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_175_PI_TDFI_WRLVL_WW_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_175_PI_TDFI_WRLVL_WW_F0_SHIFT)) & LPDDR_DENALI_PI_175_PI_TDFI_WRLVL_WW_F0_MASK)
/*! @} */

/*! @name DENALI_PI_176 - DENALI_PI_176 */
/*! @{ */

#define LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F1_MASK (0x3FFU)
#define LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F1_SHIFT)) & LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F1_MASK)

#define LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F2_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F2_SHIFT)) & LPDDR_DENALI_PI_176_PI_TDFI_WRLVL_WW_F2_MASK)
/*! @} */

/*! @name DENALI_PI_177 - DENALI_PI_177 */
/*! @{ */

#define LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F0_MASK (0xFFU)
#define LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F0_SHIFT)) & LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F0_MASK)

#define LPDDR_DENALI_PI_177_PI_ODT_EN_F0_MASK    (0x100U)
#define LPDDR_DENALI_PI_177_PI_ODT_EN_F0_SHIFT   (8U)
#define LPDDR_DENALI_PI_177_PI_ODT_EN_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_177_PI_ODT_EN_F0_SHIFT)) & LPDDR_DENALI_PI_177_PI_ODT_EN_F0_MASK)

#define LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F1_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F1_SHIFT)) & LPDDR_DENALI_PI_177_PI_TODTL_2CMD_F1_MASK)

#define LPDDR_DENALI_PI_177_PI_ODT_EN_F1_MASK    (0x1000000U)
#define LPDDR_DENALI_PI_177_PI_ODT_EN_F1_SHIFT   (24U)
#define LPDDR_DENALI_PI_177_PI_ODT_EN_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_177_PI_ODT_EN_F1_SHIFT)) & LPDDR_DENALI_PI_177_PI_ODT_EN_F1_MASK)
/*! @} */

/*! @name DENALI_PI_178 - DENALI_PI_178 */
/*! @{ */

#define LPDDR_DENALI_PI_178_PI_TODTL_2CMD_F2_MASK (0xFFU)
#define LPDDR_DENALI_PI_178_PI_TODTL_2CMD_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_178_PI_TODTL_2CMD_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_178_PI_TODTL_2CMD_F2_SHIFT)) & LPDDR_DENALI_PI_178_PI_TODTL_2CMD_F2_MASK)

#define LPDDR_DENALI_PI_178_PI_ODT_EN_F2_MASK    (0x100U)
#define LPDDR_DENALI_PI_178_PI_ODT_EN_F2_SHIFT   (8U)
#define LPDDR_DENALI_PI_178_PI_ODT_EN_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_178_PI_ODT_EN_F2_SHIFT)) & LPDDR_DENALI_PI_178_PI_ODT_EN_F2_MASK)

#define LPDDR_DENALI_PI_178_PI_ODTLON_F0_MASK    (0xF0000U)
#define LPDDR_DENALI_PI_178_PI_ODTLON_F0_SHIFT   (16U)
/*! PI_ODTLON_F0 - Defines the latency from a CAS-2 command to the tODTon reference for frequency set 0. */
#define LPDDR_DENALI_PI_178_PI_ODTLON_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_178_PI_ODTLON_F0_SHIFT)) & LPDDR_DENALI_PI_178_PI_ODTLON_F0_MASK)

#define LPDDR_DENALI_PI_178_PI_TODTON_MIN_F0_MASK (0xF000000U)
#define LPDDR_DENALI_PI_178_PI_TODTON_MIN_F0_SHIFT (24U)
/*! PI_TODTON_MIN_F0 - Defines the point in time when the device termination circuit leaves High-Z
 *    and ODT resistance begins to turn on for frequency set 0.
 */
#define LPDDR_DENALI_PI_178_PI_TODTON_MIN_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_178_PI_TODTON_MIN_F0_SHIFT)) & LPDDR_DENALI_PI_178_PI_TODTON_MIN_F0_MASK)
/*! @} */

/*! @name DENALI_PI_181 - DENALI_PI_181 */
/*! @{ */

#define LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F1_MASK (0x3FU)
#define LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F1_SHIFT (0U)
/*! PI_RD_TO_ODTH_F1 - Defines the delay from a read command to ODT assertion for frequency set 1. */
#define LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F1_SHIFT)) & LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F1_MASK)

#define LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F2_MASK (0x3F00U)
#define LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F2_SHIFT (8U)
/*! PI_RD_TO_ODTH_F2 - Defines the delay from a read command to ODT assertion for frequency set 2. */
#define LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F2_SHIFT)) & LPDDR_DENALI_PI_181_PI_RD_TO_ODTH_F2_MASK)

#define LPDDR_DENALI_PI_181_PI_RDLVL_EN_F0_MASK  (0x30000U)
#define LPDDR_DENALI_PI_181_PI_RDLVL_EN_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_181_PI_RDLVL_EN_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_181_PI_RDLVL_EN_F0_SHIFT)) & LPDDR_DENALI_PI_181_PI_RDLVL_EN_F0_MASK)

#define LPDDR_DENALI_PI_181_PI_RDLVL_GATE_EN_F0_MASK (0x3000000U)
#define LPDDR_DENALI_PI_181_PI_RDLVL_GATE_EN_F0_SHIFT (24U)
#define LPDDR_DENALI_PI_181_PI_RDLVL_GATE_EN_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_181_PI_RDLVL_GATE_EN_F0_SHIFT)) & LPDDR_DENALI_PI_181_PI_RDLVL_GATE_EN_F0_MASK)
/*! @} */

/*! @name DENALI_PI_182 - DENALI_PI_182 */
/*! @{ */

#define LPDDR_DENALI_PI_182_PI_RDLVL_EN_F1_MASK  (0x3U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_EN_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_EN_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_182_PI_RDLVL_EN_F1_SHIFT)) & LPDDR_DENALI_PI_182_PI_RDLVL_EN_F1_MASK)

#define LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F1_MASK (0x300U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F1_SHIFT (8U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F1_SHIFT)) & LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F1_MASK)

#define LPDDR_DENALI_PI_182_PI_RDLVL_EN_F2_MASK  (0x30000U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_EN_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_EN_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_182_PI_RDLVL_EN_F2_SHIFT)) & LPDDR_DENALI_PI_182_PI_RDLVL_EN_F2_MASK)

#define LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F2_MASK (0x3000000U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F2_SHIFT (24U)
#define LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F2_SHIFT)) & LPDDR_DENALI_PI_182_PI_RDLVL_GATE_EN_F2_MASK)
/*! @} */

/*! @name DENALI_PI_186 - DENALI_PI_186 */
/*! @{ */

#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F0_MASK (0x7FU)
#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F0_SHIFT)) & LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F0_MASK)

#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F1_MASK (0x7F00U)
#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F1_SHIFT (8U)
#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F1_SHIFT)) & LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F1_MASK)

#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F2_MASK (0x7F0000U)
#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F2_SHIFT)) & LPDDR_DENALI_PI_186_PI_RDLAT_ADJ_F2_MASK)

#define LPDDR_DENALI_PI_186_PI_WRLAT_ADJ_F0_MASK (0x7F000000U)
#define LPDDR_DENALI_PI_186_PI_WRLAT_ADJ_F0_SHIFT (24U)
#define LPDDR_DENALI_PI_186_PI_WRLAT_ADJ_F0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_186_PI_WRLAT_ADJ_F0_SHIFT)) & LPDDR_DENALI_PI_186_PI_WRLAT_ADJ_F0_MASK)
/*! @} */

/*! @name DENALI_PI_187 - DENALI_PI_187 */
/*! @{ */

#define LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F1_MASK (0x7FU)
#define LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F1_SHIFT)) & LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F1_MASK)

#define LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F2_MASK (0x7F00U)
#define LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F2_SHIFT (8U)
#define LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F2_SHIFT)) & LPDDR_DENALI_PI_187_PI_WRLAT_ADJ_F2_MASK)

#define LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F0_MASK (0x70000U)
#define LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F0_SHIFT (16U)
/*! PI_TDFI_PHY_WRDATA_F0 - Defines the DFI tPHY_WRDATA timing (in DFI PHY clocks) for frequency set
 *    0, the maximum cycles between a dfi_wrdata_en assertion and a dfi_wrdata signal.
 */
#define LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F0_SHIFT)) & LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F0_MASK)

#define LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F1_MASK (0x7000000U)
#define LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F1_SHIFT (24U)
/*! PI_TDFI_PHY_WRDATA_F1 - Defines the DFI tPHY_WRDATA timing (in DFI PHY clocks) for frequency set
 *    1, the maximum cycles between a dfi_wrdata_en assertion and a dfi_wrdata signal.
 */
#define LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F1_SHIFT)) & LPDDR_DENALI_PI_187_PI_TDFI_PHY_WRDATA_F1_MASK)
/*! @} */

/*! @name DENALI_PI_188 - DENALI_PI_188 */
/*! @{ */

#define LPDDR_DENALI_PI_188_PI_TDFI_PHY_WRDATA_F2_MASK (0x7U)
#define LPDDR_DENALI_PI_188_PI_TDFI_PHY_WRDATA_F2_SHIFT (0U)
/*! PI_TDFI_PHY_WRDATA_F2 - Defines the DFI tPHY_WRDATA timing (in DFI PHY clocks) for frequency set
 *    2, the maximum cycles between a dfi_wrdata_en assertion and a dfi_wrdata signal.
 */
#define LPDDR_DENALI_PI_188_PI_TDFI_PHY_WRDATA_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_188_PI_TDFI_PHY_WRDATA_F2_SHIFT)) & LPDDR_DENALI_PI_188_PI_TDFI_PHY_WRDATA_F2_MASK)

#define LPDDR_DENALI_PI_188_PI_TDFI_CALVL_CC_F0_MASK (0x3FF00U)
#define LPDDR_DENALI_PI_188_PI_TDFI_CALVL_CC_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_188_PI_TDFI_CALVL_CC_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_188_PI_TDFI_CALVL_CC_F0_SHIFT)) & LPDDR_DENALI_PI_188_PI_TDFI_CALVL_CC_F0_MASK)
/*! @} */

/*! @name DENALI_PI_189 - DENALI_PI_189 */
/*! @{ */

#define LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CAPTURE_F0_MASK (0x3FFU)
#define LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CAPTURE_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CAPTURE_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CAPTURE_F0_SHIFT)) & LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CAPTURE_F0_MASK)

#define LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CC_F1_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CC_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CC_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CC_F1_SHIFT)) & LPDDR_DENALI_PI_189_PI_TDFI_CALVL_CC_F1_MASK)
/*! @} */

/*! @name DENALI_PI_190 - DENALI_PI_190 */
/*! @{ */

#define LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CAPTURE_F1_MASK (0x3FFU)
#define LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CAPTURE_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CAPTURE_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CAPTURE_F1_SHIFT)) & LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CAPTURE_F1_MASK)

#define LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CC_F2_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CC_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CC_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CC_F2_SHIFT)) & LPDDR_DENALI_PI_190_PI_TDFI_CALVL_CC_F2_MASK)
/*! @} */

/*! @name DENALI_PI_191 - DENALI_PI_191 */
/*! @{ */

#define LPDDR_DENALI_PI_191_PI_TDFI_CALVL_CAPTURE_F2_MASK (0x3FFU)
#define LPDDR_DENALI_PI_191_PI_TDFI_CALVL_CAPTURE_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_191_PI_TDFI_CALVL_CAPTURE_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_191_PI_TDFI_CALVL_CAPTURE_F2_SHIFT)) & LPDDR_DENALI_PI_191_PI_TDFI_CALVL_CAPTURE_F2_MASK)

#define LPDDR_DENALI_PI_191_PI_CALVL_EN_F0_MASK  (0x30000U)
#define LPDDR_DENALI_PI_191_PI_CALVL_EN_F0_SHIFT (16U)
/*! PI_CALVL_EN_F0
 *  0b00..Disable
 *  0b01..Enable
 */
#define LPDDR_DENALI_PI_191_PI_CALVL_EN_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_191_PI_CALVL_EN_F0_SHIFT)) & LPDDR_DENALI_PI_191_PI_CALVL_EN_F0_MASK)

#define LPDDR_DENALI_PI_191_PI_CALVL_EN_F1_MASK  (0x3000000U)
#define LPDDR_DENALI_PI_191_PI_CALVL_EN_F1_SHIFT (24U)
/*! PI_CALVL_EN_F1
 *  0b00..Disable
 *  0b01..Enable
 */
#define LPDDR_DENALI_PI_191_PI_CALVL_EN_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_191_PI_CALVL_EN_F1_SHIFT)) & LPDDR_DENALI_PI_191_PI_CALVL_EN_F1_MASK)
/*! @} */

/*! @name DENALI_PI_192 - DENALI_PI_192 */
/*! @{ */

#define LPDDR_DENALI_PI_192_PI_CALVL_EN_F2_MASK  (0x3U)
#define LPDDR_DENALI_PI_192_PI_CALVL_EN_F2_SHIFT (0U)
/*! PI_CALVL_EN_F2
 *  0b00..Disable
 *  0b01..Enable
 */
#define LPDDR_DENALI_PI_192_PI_CALVL_EN_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_192_PI_CALVL_EN_F2_SHIFT)) & LPDDR_DENALI_PI_192_PI_CALVL_EN_F2_MASK)

#define LPDDR_DENALI_PI_192_PI_TMRZ_F0_MASK      (0x1F00U)
#define LPDDR_DENALI_PI_192_PI_TMRZ_F0_SHIFT     (8U)
#define LPDDR_DENALI_PI_192_PI_TMRZ_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_192_PI_TMRZ_F0_SHIFT)) & LPDDR_DENALI_PI_192_PI_TMRZ_F0_MASK)

#define LPDDR_DENALI_PI_192_PI_TCAENT_F0_MASK    (0x3FFF0000U)
#define LPDDR_DENALI_PI_192_PI_TCAENT_F0_SHIFT   (16U)
#define LPDDR_DENALI_PI_192_PI_TCAENT_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_192_PI_TCAENT_F0_SHIFT)) & LPDDR_DENALI_PI_192_PI_TCAENT_F0_MASK)
/*! @} */

/*! @name DENALI_PI_193 - DENALI_PI_193 */
/*! @{ */

#define LPDDR_DENALI_PI_193_PI_TMRZ_F1_MASK      (0x1FU)
#define LPDDR_DENALI_PI_193_PI_TMRZ_F1_SHIFT     (0U)
#define LPDDR_DENALI_PI_193_PI_TMRZ_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_193_PI_TMRZ_F1_SHIFT)) & LPDDR_DENALI_PI_193_PI_TMRZ_F1_MASK)

#define LPDDR_DENALI_PI_193_PI_TCAENT_F1_MASK    (0x3FFF00U)
#define LPDDR_DENALI_PI_193_PI_TCAENT_F1_SHIFT   (8U)
#define LPDDR_DENALI_PI_193_PI_TCAENT_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_193_PI_TCAENT_F1_SHIFT)) & LPDDR_DENALI_PI_193_PI_TCAENT_F1_MASK)

#define LPDDR_DENALI_PI_193_PI_TMRZ_F2_MASK      (0x1F000000U)
#define LPDDR_DENALI_PI_193_PI_TMRZ_F2_SHIFT     (24U)
#define LPDDR_DENALI_PI_193_PI_TMRZ_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_193_PI_TMRZ_F2_SHIFT)) & LPDDR_DENALI_PI_193_PI_TMRZ_F2_MASK)
/*! @} */

/*! @name DENALI_PI_194 - DENALI_PI_194 */
/*! @{ */

#define LPDDR_DENALI_PI_194_PI_TCAENT_F2_MASK    (0x3FFFU)
#define LPDDR_DENALI_PI_194_PI_TCAENT_F2_SHIFT   (0U)
#define LPDDR_DENALI_PI_194_PI_TCAENT_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_194_PI_TCAENT_F2_SHIFT)) & LPDDR_DENALI_PI_194_PI_TCAENT_F2_MASK)

#define LPDDR_DENALI_PI_194_PI_TDFI_CACSCA_F0_MASK (0x1F0000U)
#define LPDDR_DENALI_PI_194_PI_TDFI_CACSCA_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_194_PI_TDFI_CACSCA_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_194_PI_TDFI_CACSCA_F0_SHIFT)) & LPDDR_DENALI_PI_194_PI_TDFI_CACSCA_F0_MASK)

#define LPDDR_DENALI_PI_194_PI_TDFI_CASEL_F0_MASK (0x1F000000U)
#define LPDDR_DENALI_PI_194_PI_TDFI_CASEL_F0_SHIFT (24U)
#define LPDDR_DENALI_PI_194_PI_TDFI_CASEL_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_194_PI_TDFI_CASEL_F0_SHIFT)) & LPDDR_DENALI_PI_194_PI_TDFI_CASEL_F0_MASK)
/*! @} */

/*! @name DENALI_PI_195 - DENALI_PI_195 */
/*! @{ */

#define LPDDR_DENALI_PI_195_PI_TVREF_SHORT_F0_MASK (0x3FFU)
#define LPDDR_DENALI_PI_195_PI_TVREF_SHORT_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_195_PI_TVREF_SHORT_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_195_PI_TVREF_SHORT_F0_SHIFT)) & LPDDR_DENALI_PI_195_PI_TVREF_SHORT_F0_MASK)

#define LPDDR_DENALI_PI_195_PI_TVREF_LONG_F0_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_195_PI_TVREF_LONG_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_195_PI_TVREF_LONG_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_195_PI_TVREF_LONG_F0_SHIFT)) & LPDDR_DENALI_PI_195_PI_TVREF_LONG_F0_MASK)
/*! @} */

/*! @name DENALI_PI_196 - DENALI_PI_196 */
/*! @{ */

#define LPDDR_DENALI_PI_196_PI_TDFI_CACSCA_F1_MASK (0x1FU)
#define LPDDR_DENALI_PI_196_PI_TDFI_CACSCA_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_196_PI_TDFI_CACSCA_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_196_PI_TDFI_CACSCA_F1_SHIFT)) & LPDDR_DENALI_PI_196_PI_TDFI_CACSCA_F1_MASK)

#define LPDDR_DENALI_PI_196_PI_TDFI_CASEL_F1_MASK (0x1F00U)
#define LPDDR_DENALI_PI_196_PI_TDFI_CASEL_F1_SHIFT (8U)
#define LPDDR_DENALI_PI_196_PI_TDFI_CASEL_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_196_PI_TDFI_CASEL_F1_SHIFT)) & LPDDR_DENALI_PI_196_PI_TDFI_CASEL_F1_MASK)

#define LPDDR_DENALI_PI_196_PI_TVREF_SHORT_F1_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_196_PI_TVREF_SHORT_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_196_PI_TVREF_SHORT_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_196_PI_TVREF_SHORT_F1_SHIFT)) & LPDDR_DENALI_PI_196_PI_TVREF_SHORT_F1_MASK)
/*! @} */

/*! @name DENALI_PI_197 - DENALI_PI_197 */
/*! @{ */

#define LPDDR_DENALI_PI_197_PI_TVREF_LONG_F1_MASK (0x3FFU)
#define LPDDR_DENALI_PI_197_PI_TVREF_LONG_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_197_PI_TVREF_LONG_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_197_PI_TVREF_LONG_F1_SHIFT)) & LPDDR_DENALI_PI_197_PI_TVREF_LONG_F1_MASK)

#define LPDDR_DENALI_PI_197_PI_TDFI_CACSCA_F2_MASK (0x1F0000U)
#define LPDDR_DENALI_PI_197_PI_TDFI_CACSCA_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_197_PI_TDFI_CACSCA_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_197_PI_TDFI_CACSCA_F2_SHIFT)) & LPDDR_DENALI_PI_197_PI_TDFI_CACSCA_F2_MASK)

#define LPDDR_DENALI_PI_197_PI_TDFI_CASEL_F2_MASK (0x1F000000U)
#define LPDDR_DENALI_PI_197_PI_TDFI_CASEL_F2_SHIFT (24U)
#define LPDDR_DENALI_PI_197_PI_TDFI_CASEL_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_197_PI_TDFI_CASEL_F2_SHIFT)) & LPDDR_DENALI_PI_197_PI_TDFI_CASEL_F2_MASK)
/*! @} */

/*! @name DENALI_PI_198 - DENALI_PI_198 */
/*! @{ */

#define LPDDR_DENALI_PI_198_PI_TVREF_SHORT_F2_MASK (0x3FFU)
#define LPDDR_DENALI_PI_198_PI_TVREF_SHORT_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_198_PI_TVREF_SHORT_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_198_PI_TVREF_SHORT_F2_SHIFT)) & LPDDR_DENALI_PI_198_PI_TVREF_SHORT_F2_MASK)

#define LPDDR_DENALI_PI_198_PI_TVREF_LONG_F2_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_198_PI_TVREF_LONG_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_198_PI_TVREF_LONG_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_198_PI_TVREF_LONG_F2_SHIFT)) & LPDDR_DENALI_PI_198_PI_TVREF_LONG_F2_MASK)
/*! @} */

/*! @name DENALI_PI_199 - DENALI_PI_199 */
/*! @{ */

#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F0_MASK (0x7FU)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F0_SHIFT)) & LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F0_MASK)

#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F0_MASK (0x7F00U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F0_SHIFT)) & LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F0_MASK)

#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F1_MASK (0x7F0000U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F1_SHIFT)) & LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_START_POINT_F1_MASK)

#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F1_MASK (0x7F000000U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F1_SHIFT (24U)
#define LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F1_SHIFT)) & LPDDR_DENALI_PI_199_PI_CALVL_VREF_INITIAL_STOP_POINT_F1_MASK)
/*! @} */

/*! @name DENALI_PI_200 - DENALI_PI_200 */
/*! @{ */

#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_START_POINT_F2_MASK (0x7FU)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_START_POINT_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_START_POINT_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_START_POINT_F2_SHIFT)) & LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_START_POINT_F2_MASK)

#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_STOP_POINT_F2_MASK (0x7F00U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_STOP_POINT_F2_SHIFT (8U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_STOP_POINT_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_STOP_POINT_F2_SHIFT)) & LPDDR_DENALI_PI_200_PI_CALVL_VREF_INITIAL_STOP_POINT_F2_MASK)

#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F0_MASK (0xF0000U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F0_SHIFT)) & LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F0_MASK)

#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F1_MASK (0xF000000U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F1_SHIFT (24U)
#define LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F1_SHIFT)) & LPDDR_DENALI_PI_200_PI_CALVL_VREF_DELTA_F1_MASK)
/*! @} */

/*! @name DENALI_PI_201 - DENALI_PI_201 */
/*! @{ */

#define LPDDR_DENALI_PI_201_PI_CALVL_VREF_DELTA_F2_MASK (0xFU)
#define LPDDR_DENALI_PI_201_PI_CALVL_VREF_DELTA_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_201_PI_CALVL_VREF_DELTA_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_201_PI_CALVL_VREF_DELTA_F2_SHIFT)) & LPDDR_DENALI_PI_201_PI_CALVL_VREF_DELTA_F2_MASK)

#define LPDDR_DENALI_PI_201_PI_TDFI_CALVL_STROBE_F0_MASK (0xF00U)
#define LPDDR_DENALI_PI_201_PI_TDFI_CALVL_STROBE_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_201_PI_TDFI_CALVL_STROBE_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_201_PI_TDFI_CALVL_STROBE_F0_SHIFT)) & LPDDR_DENALI_PI_201_PI_TDFI_CALVL_STROBE_F0_MASK)

#define LPDDR_DENALI_PI_201_PI_TXP_F0_MASK       (0x1F0000U)
#define LPDDR_DENALI_PI_201_PI_TXP_F0_SHIFT      (16U)
#define LPDDR_DENALI_PI_201_PI_TXP_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_201_PI_TXP_F0_SHIFT)) & LPDDR_DENALI_PI_201_PI_TXP_F0_MASK)

#define LPDDR_DENALI_PI_201_PI_TMRWCKEL_F0_MASK  (0xFF000000U)
#define LPDDR_DENALI_PI_201_PI_TMRWCKEL_F0_SHIFT (24U)
#define LPDDR_DENALI_PI_201_PI_TMRWCKEL_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_201_PI_TMRWCKEL_F0_SHIFT)) & LPDDR_DENALI_PI_201_PI_TMRWCKEL_F0_MASK)
/*! @} */

/*! @name DENALI_PI_202 - DENALI_PI_202 */
/*! @{ */

#define LPDDR_DENALI_PI_202_PI_TCKELCK_F0_MASK   (0x1FU)
#define LPDDR_DENALI_PI_202_PI_TCKELCK_F0_SHIFT  (0U)
#define LPDDR_DENALI_PI_202_PI_TCKELCK_F0(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_202_PI_TCKELCK_F0_SHIFT)) & LPDDR_DENALI_PI_202_PI_TCKELCK_F0_MASK)

#define LPDDR_DENALI_PI_202_PI_TDFI_CALVL_STROBE_F1_MASK (0xF00U)
#define LPDDR_DENALI_PI_202_PI_TDFI_CALVL_STROBE_F1_SHIFT (8U)
#define LPDDR_DENALI_PI_202_PI_TDFI_CALVL_STROBE_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_202_PI_TDFI_CALVL_STROBE_F1_SHIFT)) & LPDDR_DENALI_PI_202_PI_TDFI_CALVL_STROBE_F1_MASK)

#define LPDDR_DENALI_PI_202_PI_TXP_F1_MASK       (0x1F0000U)
#define LPDDR_DENALI_PI_202_PI_TXP_F1_SHIFT      (16U)
#define LPDDR_DENALI_PI_202_PI_TXP_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_202_PI_TXP_F1_SHIFT)) & LPDDR_DENALI_PI_202_PI_TXP_F1_MASK)

#define LPDDR_DENALI_PI_202_PI_TMRWCKEL_F1_MASK  (0xFF000000U)
#define LPDDR_DENALI_PI_202_PI_TMRWCKEL_F1_SHIFT (24U)
#define LPDDR_DENALI_PI_202_PI_TMRWCKEL_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_202_PI_TMRWCKEL_F1_SHIFT)) & LPDDR_DENALI_PI_202_PI_TMRWCKEL_F1_MASK)
/*! @} */

/*! @name DENALI_PI_203 - DENALI_PI_203 */
/*! @{ */

#define LPDDR_DENALI_PI_203_PI_TCKELCK_F1_MASK   (0x1FU)
#define LPDDR_DENALI_PI_203_PI_TCKELCK_F1_SHIFT  (0U)
#define LPDDR_DENALI_PI_203_PI_TCKELCK_F1(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_203_PI_TCKELCK_F1_SHIFT)) & LPDDR_DENALI_PI_203_PI_TCKELCK_F1_MASK)

#define LPDDR_DENALI_PI_203_PI_TDFI_CALVL_STROBE_F2_MASK (0xF00U)
#define LPDDR_DENALI_PI_203_PI_TDFI_CALVL_STROBE_F2_SHIFT (8U)
#define LPDDR_DENALI_PI_203_PI_TDFI_CALVL_STROBE_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_203_PI_TDFI_CALVL_STROBE_F2_SHIFT)) & LPDDR_DENALI_PI_203_PI_TDFI_CALVL_STROBE_F2_MASK)

#define LPDDR_DENALI_PI_203_PI_TXP_F2_MASK       (0x1F0000U)
#define LPDDR_DENALI_PI_203_PI_TXP_F2_SHIFT      (16U)
#define LPDDR_DENALI_PI_203_PI_TXP_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_203_PI_TXP_F2_SHIFT)) & LPDDR_DENALI_PI_203_PI_TXP_F2_MASK)

#define LPDDR_DENALI_PI_203_PI_TMRWCKEL_F2_MASK  (0xFF000000U)
#define LPDDR_DENALI_PI_203_PI_TMRWCKEL_F2_SHIFT (24U)
#define LPDDR_DENALI_PI_203_PI_TMRWCKEL_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_203_PI_TMRWCKEL_F2_SHIFT)) & LPDDR_DENALI_PI_203_PI_TMRWCKEL_F2_MASK)
/*! @} */

/*! @name DENALI_PI_204 - DENALI_PI_204 */
/*! @{ */

#define LPDDR_DENALI_PI_204_PI_TCKELCK_F2_MASK   (0x1FU)
#define LPDDR_DENALI_PI_204_PI_TCKELCK_F2_SHIFT  (0U)
#define LPDDR_DENALI_PI_204_PI_TCKELCK_F2(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_204_PI_TCKELCK_F2_SHIFT)) & LPDDR_DENALI_PI_204_PI_TCKELCK_F2_MASK)

#define LPDDR_DENALI_PI_204_PI_TDFI_INIT_START_F0_MASK (0x3FF00U)
#define LPDDR_DENALI_PI_204_PI_TDFI_INIT_START_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_204_PI_TDFI_INIT_START_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_204_PI_TDFI_INIT_START_F0_SHIFT)) & LPDDR_DENALI_PI_204_PI_TDFI_INIT_START_F0_MASK)
/*! @} */

/*! @name DENALI_PI_205 - DENALI_PI_205 */
/*! @{ */

#define LPDDR_DENALI_PI_205_PI_TDFI_INIT_COMPLETE_F0_MASK (0xFFFFU)
#define LPDDR_DENALI_PI_205_PI_TDFI_INIT_COMPLETE_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_205_PI_TDFI_INIT_COMPLETE_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_205_PI_TDFI_INIT_COMPLETE_F0_SHIFT)) & LPDDR_DENALI_PI_205_PI_TDFI_INIT_COMPLETE_F0_MASK)

#define LPDDR_DENALI_PI_205_PI_TDFI_INIT_START_F1_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_205_PI_TDFI_INIT_START_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_205_PI_TDFI_INIT_START_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_205_PI_TDFI_INIT_START_F1_SHIFT)) & LPDDR_DENALI_PI_205_PI_TDFI_INIT_START_F1_MASK)
/*! @} */

/*! @name DENALI_PI_206 - DENALI_PI_206 */
/*! @{ */

#define LPDDR_DENALI_PI_206_PI_TDFI_INIT_COMPLETE_F1_MASK (0xFFFFU)
#define LPDDR_DENALI_PI_206_PI_TDFI_INIT_COMPLETE_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_206_PI_TDFI_INIT_COMPLETE_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_206_PI_TDFI_INIT_COMPLETE_F1_SHIFT)) & LPDDR_DENALI_PI_206_PI_TDFI_INIT_COMPLETE_F1_MASK)

#define LPDDR_DENALI_PI_206_PI_TDFI_INIT_START_F2_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_206_PI_TDFI_INIT_START_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_206_PI_TDFI_INIT_START_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_206_PI_TDFI_INIT_START_F2_SHIFT)) & LPDDR_DENALI_PI_206_PI_TDFI_INIT_START_F2_MASK)
/*! @} */

/*! @name DENALI_PI_207 - DENALI_PI_207 */
/*! @{ */

#define LPDDR_DENALI_PI_207_PI_TDFI_INIT_COMPLETE_F2_MASK (0xFFFFU)
#define LPDDR_DENALI_PI_207_PI_TDFI_INIT_COMPLETE_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_207_PI_TDFI_INIT_COMPLETE_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_207_PI_TDFI_INIT_COMPLETE_F2_SHIFT)) & LPDDR_DENALI_PI_207_PI_TDFI_INIT_COMPLETE_F2_MASK)

#define LPDDR_DENALI_PI_207_PI_TCKEHDQS_F0_MASK  (0x3F0000U)
#define LPDDR_DENALI_PI_207_PI_TCKEHDQS_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_207_PI_TCKEHDQS_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_207_PI_TCKEHDQS_F0_SHIFT)) & LPDDR_DENALI_PI_207_PI_TCKEHDQS_F0_MASK)
/*! @} */

/*! @name DENALI_PI_208 - DENALI_PI_208 */
/*! @{ */

#define LPDDR_DENALI_PI_208_PI_TFC_F0_MASK       (0x3FFU)
#define LPDDR_DENALI_PI_208_PI_TFC_F0_SHIFT      (0U)
#define LPDDR_DENALI_PI_208_PI_TFC_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_208_PI_TFC_F0_SHIFT)) & LPDDR_DENALI_PI_208_PI_TFC_F0_MASK)

#define LPDDR_DENALI_PI_208_PI_TCKEHDQS_F1_MASK  (0x3F0000U)
#define LPDDR_DENALI_PI_208_PI_TCKEHDQS_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_208_PI_TCKEHDQS_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_208_PI_TCKEHDQS_F1_SHIFT)) & LPDDR_DENALI_PI_208_PI_TCKEHDQS_F1_MASK)
/*! @} */

/*! @name DENALI_PI_209 - DENALI_PI_209 */
/*! @{ */

#define LPDDR_DENALI_PI_209_PI_TFC_F1_MASK       (0x3FFU)
#define LPDDR_DENALI_PI_209_PI_TFC_F1_SHIFT      (0U)
#define LPDDR_DENALI_PI_209_PI_TFC_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_209_PI_TFC_F1_SHIFT)) & LPDDR_DENALI_PI_209_PI_TFC_F1_MASK)

#define LPDDR_DENALI_PI_209_PI_TCKEHDQS_F2_MASK  (0x3F0000U)
#define LPDDR_DENALI_PI_209_PI_TCKEHDQS_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_209_PI_TCKEHDQS_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_209_PI_TCKEHDQS_F2_SHIFT)) & LPDDR_DENALI_PI_209_PI_TCKEHDQS_F2_MASK)
/*! @} */

/*! @name DENALI_PI_210 - DENALI_PI_210 */
/*! @{ */

#define LPDDR_DENALI_PI_210_PI_TFC_F2_MASK       (0x3FFU)
#define LPDDR_DENALI_PI_210_PI_TFC_F2_SHIFT      (0U)
#define LPDDR_DENALI_PI_210_PI_TFC_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_210_PI_TFC_F2_SHIFT)) & LPDDR_DENALI_PI_210_PI_TFC_F2_MASK)

#define LPDDR_DENALI_PI_210_PI_TDFI_WDQLVL_WR_F0_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_210_PI_TDFI_WDQLVL_WR_F0_SHIFT (16U)
/*! PI_TDFI_WDQLVL_WR_F0 - Switch time from write to read for frequency set 0. */
#define LPDDR_DENALI_PI_210_PI_TDFI_WDQLVL_WR_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_210_PI_TDFI_WDQLVL_WR_F0_SHIFT)) & LPDDR_DENALI_PI_210_PI_TDFI_WDQLVL_WR_F0_MASK)
/*! @} */

/*! @name DENALI_PI_211 - DENALI_PI_211 */
/*! @{ */

#define LPDDR_DENALI_PI_211_PI_TDFI_WDQLVL_RW_F0_MASK (0x3FFU)
#define LPDDR_DENALI_PI_211_PI_TDFI_WDQLVL_RW_F0_SHIFT (0U)
/*! PI_TDFI_WDQLVL_RW_F0 - Switch time from read to write for frequency set 0. */
#define LPDDR_DENALI_PI_211_PI_TDFI_WDQLVL_RW_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_211_PI_TDFI_WDQLVL_RW_F0_SHIFT)) & LPDDR_DENALI_PI_211_PI_TDFI_WDQLVL_RW_F0_MASK)

#define LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_START_POINT_F0_MASK (0x7F0000U)
#define LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_START_POINT_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_START_POINT_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_START_POINT_F0_SHIFT)) & LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_START_POINT_F0_MASK)

#define LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F0_MASK (0x7F000000U)
#define LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F0_SHIFT (24U)
#define LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F0_SHIFT)) & LPDDR_DENALI_PI_211_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F0_MASK)
/*! @} */

/*! @name DENALI_PI_212 - DENALI_PI_212 */
/*! @{ */

#define LPDDR_DENALI_PI_212_PI_WDQLVL_VREF_DELTA_F0_MASK (0xFU)
#define LPDDR_DENALI_PI_212_PI_WDQLVL_VREF_DELTA_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_212_PI_WDQLVL_VREF_DELTA_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_212_PI_WDQLVL_VREF_DELTA_F0_SHIFT)) & LPDDR_DENALI_PI_212_PI_WDQLVL_VREF_DELTA_F0_MASK)

#define LPDDR_DENALI_PI_212_PI_WDQLVL_EN_F0_MASK (0x300U)
#define LPDDR_DENALI_PI_212_PI_WDQLVL_EN_F0_SHIFT (8U)
#define LPDDR_DENALI_PI_212_PI_WDQLVL_EN_F0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_212_PI_WDQLVL_EN_F0_SHIFT)) & LPDDR_DENALI_PI_212_PI_WDQLVL_EN_F0_MASK)

#define LPDDR_DENALI_PI_212_PI_NTP_TRAIN_EN_F0_MASK (0x30000U)
#define LPDDR_DENALI_PI_212_PI_NTP_TRAIN_EN_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_212_PI_NTP_TRAIN_EN_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_212_PI_NTP_TRAIN_EN_F0_SHIFT)) & LPDDR_DENALI_PI_212_PI_NTP_TRAIN_EN_F0_MASK)
/*! @} */

/*! @name DENALI_PI_213 - DENALI_PI_213 */
/*! @{ */

#define LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_WR_F1_MASK (0x3FFU)
#define LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_WR_F1_SHIFT (0U)
/*! PI_TDFI_WDQLVL_WR_F1 - Switch time from write to read for frequency set 1. */
#define LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_WR_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_WR_F1_SHIFT)) & LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_WR_F1_MASK)

#define LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_RW_F1_MASK (0x3FF0000U)
#define LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_RW_F1_SHIFT (16U)
/*! PI_TDFI_WDQLVL_RW_F1 - Switch time from read to write for frequency set 1. */
#define LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_RW_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_RW_F1_SHIFT)) & LPDDR_DENALI_PI_213_PI_TDFI_WDQLVL_RW_F1_MASK)
/*! @} */

/*! @name DENALI_PI_214 - DENALI_PI_214 */
/*! @{ */

#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_START_POINT_F1_MASK (0x7FU)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_START_POINT_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_START_POINT_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_START_POINT_F1_SHIFT)) & LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_START_POINT_F1_MASK)

#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F1_MASK (0x7F00U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F1_SHIFT (8U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F1_SHIFT)) & LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F1_MASK)

#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_DELTA_F1_MASK (0xF0000U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_DELTA_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_DELTA_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_DELTA_F1_SHIFT)) & LPDDR_DENALI_PI_214_PI_WDQLVL_VREF_DELTA_F1_MASK)

#define LPDDR_DENALI_PI_214_PI_WDQLVL_EN_F1_MASK (0x3000000U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_EN_F1_SHIFT (24U)
#define LPDDR_DENALI_PI_214_PI_WDQLVL_EN_F1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_214_PI_WDQLVL_EN_F1_SHIFT)) & LPDDR_DENALI_PI_214_PI_WDQLVL_EN_F1_MASK)
/*! @} */

/*! @name DENALI_PI_215 - DENALI_PI_215 */
/*! @{ */

#define LPDDR_DENALI_PI_215_PI_NTP_TRAIN_EN_F1_MASK (0x3U)
#define LPDDR_DENALI_PI_215_PI_NTP_TRAIN_EN_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_215_PI_NTP_TRAIN_EN_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_215_PI_NTP_TRAIN_EN_F1_SHIFT)) & LPDDR_DENALI_PI_215_PI_NTP_TRAIN_EN_F1_MASK)

#define LPDDR_DENALI_PI_215_PI_TDFI_WDQLVL_WR_F2_MASK (0x3FF00U)
#define LPDDR_DENALI_PI_215_PI_TDFI_WDQLVL_WR_F2_SHIFT (8U)
/*! PI_TDFI_WDQLVL_WR_F2 - Switch time from write to read for frequency set 2. */
#define LPDDR_DENALI_PI_215_PI_TDFI_WDQLVL_WR_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_215_PI_TDFI_WDQLVL_WR_F2_SHIFT)) & LPDDR_DENALI_PI_215_PI_TDFI_WDQLVL_WR_F2_MASK)
/*! @} */

/*! @name DENALI_PI_216 - DENALI_PI_216 */
/*! @{ */

#define LPDDR_DENALI_PI_216_PI_TDFI_WDQLVL_RW_F2_MASK (0x3FFU)
#define LPDDR_DENALI_PI_216_PI_TDFI_WDQLVL_RW_F2_SHIFT (0U)
/*! PI_TDFI_WDQLVL_RW_F2 - Switch time from read to write for frequency set 2. */
#define LPDDR_DENALI_PI_216_PI_TDFI_WDQLVL_RW_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_216_PI_TDFI_WDQLVL_RW_F2_SHIFT)) & LPDDR_DENALI_PI_216_PI_TDFI_WDQLVL_RW_F2_MASK)

#define LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_START_POINT_F2_MASK (0x7F0000U)
#define LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_START_POINT_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_START_POINT_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_START_POINT_F2_SHIFT)) & LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_START_POINT_F2_MASK)

#define LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F2_MASK (0x7F000000U)
#define LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F2_SHIFT (24U)
#define LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F2_SHIFT)) & LPDDR_DENALI_PI_216_PI_WDQLVL_VREF_INITIAL_STOP_POINT_F2_MASK)
/*! @} */

/*! @name DENALI_PI_217 - DENALI_PI_217 */
/*! @{ */

#define LPDDR_DENALI_PI_217_PI_WDQLVL_VREF_DELTA_F2_MASK (0xFU)
#define LPDDR_DENALI_PI_217_PI_WDQLVL_VREF_DELTA_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_217_PI_WDQLVL_VREF_DELTA_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_217_PI_WDQLVL_VREF_DELTA_F2_SHIFT)) & LPDDR_DENALI_PI_217_PI_WDQLVL_VREF_DELTA_F2_MASK)

#define LPDDR_DENALI_PI_217_PI_WDQLVL_EN_F2_MASK (0x300U)
#define LPDDR_DENALI_PI_217_PI_WDQLVL_EN_F2_SHIFT (8U)
#define LPDDR_DENALI_PI_217_PI_WDQLVL_EN_F2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_217_PI_WDQLVL_EN_F2_SHIFT)) & LPDDR_DENALI_PI_217_PI_WDQLVL_EN_F2_MASK)

#define LPDDR_DENALI_PI_217_PI_NTP_TRAIN_EN_F2_MASK (0x30000U)
#define LPDDR_DENALI_PI_217_PI_NTP_TRAIN_EN_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_217_PI_NTP_TRAIN_EN_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_217_PI_NTP_TRAIN_EN_F2_SHIFT)) & LPDDR_DENALI_PI_217_PI_NTP_TRAIN_EN_F2_MASK)

#define LPDDR_DENALI_PI_217_PI_TRTP_F0_MASK      (0xFF000000U)
#define LPDDR_DENALI_PI_217_PI_TRTP_F0_SHIFT     (24U)
#define LPDDR_DENALI_PI_217_PI_TRTP_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_217_PI_TRTP_F0_SHIFT)) & LPDDR_DENALI_PI_217_PI_TRTP_F0_MASK)
/*! @} */

/*! @name DENALI_PI_218 - DENALI_PI_218 */
/*! @{ */

#define LPDDR_DENALI_PI_218_PI_TRP_F0_MASK       (0xFFU)
#define LPDDR_DENALI_PI_218_PI_TRP_F0_SHIFT      (0U)
#define LPDDR_DENALI_PI_218_PI_TRP_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_218_PI_TRP_F0_SHIFT)) & LPDDR_DENALI_PI_218_PI_TRP_F0_MASK)

#define LPDDR_DENALI_PI_218_PI_TRCD_F0_MASK      (0xFF00U)
#define LPDDR_DENALI_PI_218_PI_TRCD_F0_SHIFT     (8U)
#define LPDDR_DENALI_PI_218_PI_TRCD_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_218_PI_TRCD_F0_SHIFT)) & LPDDR_DENALI_PI_218_PI_TRCD_F0_MASK)

#define LPDDR_DENALI_PI_218_PI_TWTR_F0_MASK      (0x3F0000U)
#define LPDDR_DENALI_PI_218_PI_TWTR_F0_SHIFT     (16U)
#define LPDDR_DENALI_PI_218_PI_TWTR_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_218_PI_TWTR_F0_SHIFT)) & LPDDR_DENALI_PI_218_PI_TWTR_F0_MASK)

#define LPDDR_DENALI_PI_218_PI_TWR_F0_MASK       (0xFF000000U)
#define LPDDR_DENALI_PI_218_PI_TWR_F0_SHIFT      (24U)
#define LPDDR_DENALI_PI_218_PI_TWR_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_218_PI_TWR_F0_SHIFT)) & LPDDR_DENALI_PI_218_PI_TWR_F0_MASK)
/*! @} */

/*! @name DENALI_PI_219 - DENALI_PI_219 */
/*! @{ */

#define LPDDR_DENALI_PI_219_PI_TRAS_MAX_F0_MASK  (0x1FFFFU)
#define LPDDR_DENALI_PI_219_PI_TRAS_MAX_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_219_PI_TRAS_MAX_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_219_PI_TRAS_MAX_F0_SHIFT)) & LPDDR_DENALI_PI_219_PI_TRAS_MAX_F0_MASK)
/*! @} */

/*! @name DENALI_PI_220 - DENALI_PI_220 */
/*! @{ */

#define LPDDR_DENALI_PI_220_PI_TRAS_MIN_F0_MASK  (0x1FFU)
#define LPDDR_DENALI_PI_220_PI_TRAS_MIN_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_220_PI_TRAS_MIN_F0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_220_PI_TRAS_MIN_F0_SHIFT)) & LPDDR_DENALI_PI_220_PI_TRAS_MIN_F0_MASK)

#define LPDDR_DENALI_PI_220_PI_TDQSCK_MAX_F0_MASK (0xF0000U)
#define LPDDR_DENALI_PI_220_PI_TDQSCK_MAX_F0_SHIFT (16U)
#define LPDDR_DENALI_PI_220_PI_TDQSCK_MAX_F0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_220_PI_TDQSCK_MAX_F0_SHIFT)) & LPDDR_DENALI_PI_220_PI_TDQSCK_MAX_F0_MASK)

#define LPDDR_DENALI_PI_220_PI_TCCDMW_F0_MASK    (0x3F000000U)
#define LPDDR_DENALI_PI_220_PI_TCCDMW_F0_SHIFT   (24U)
#define LPDDR_DENALI_PI_220_PI_TCCDMW_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_220_PI_TCCDMW_F0_SHIFT)) & LPDDR_DENALI_PI_220_PI_TCCDMW_F0_MASK)
/*! @} */

/*! @name DENALI_PI_221 - DENALI_PI_221 */
/*! @{ */

#define LPDDR_DENALI_PI_221_PI_TSR_F0_MASK       (0xFFU)
#define LPDDR_DENALI_PI_221_PI_TSR_F0_SHIFT      (0U)
#define LPDDR_DENALI_PI_221_PI_TSR_F0(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_221_PI_TSR_F0_SHIFT)) & LPDDR_DENALI_PI_221_PI_TSR_F0_MASK)

#define LPDDR_DENALI_PI_221_PI_TMRD_F0_MASK      (0xFF00U)
#define LPDDR_DENALI_PI_221_PI_TMRD_F0_SHIFT     (8U)
#define LPDDR_DENALI_PI_221_PI_TMRD_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_221_PI_TMRD_F0_SHIFT)) & LPDDR_DENALI_PI_221_PI_TMRD_F0_MASK)

#define LPDDR_DENALI_PI_221_PI_TMRW_F0_MASK      (0xFF0000U)
#define LPDDR_DENALI_PI_221_PI_TMRW_F0_SHIFT     (16U)
#define LPDDR_DENALI_PI_221_PI_TMRW_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_221_PI_TMRW_F0_SHIFT)) & LPDDR_DENALI_PI_221_PI_TMRW_F0_MASK)

#define LPDDR_DENALI_PI_221_PI_TRTP_F1_MASK      (0xFF000000U)
#define LPDDR_DENALI_PI_221_PI_TRTP_F1_SHIFT     (24U)
#define LPDDR_DENALI_PI_221_PI_TRTP_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_221_PI_TRTP_F1_SHIFT)) & LPDDR_DENALI_PI_221_PI_TRTP_F1_MASK)
/*! @} */

/*! @name DENALI_PI_222 - DENALI_PI_222 */
/*! @{ */

#define LPDDR_DENALI_PI_222_PI_TRP_F1_MASK       (0xFFU)
#define LPDDR_DENALI_PI_222_PI_TRP_F1_SHIFT      (0U)
#define LPDDR_DENALI_PI_222_PI_TRP_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_222_PI_TRP_F1_SHIFT)) & LPDDR_DENALI_PI_222_PI_TRP_F1_MASK)

#define LPDDR_DENALI_PI_222_PI_TRCD_F1_MASK      (0xFF00U)
#define LPDDR_DENALI_PI_222_PI_TRCD_F1_SHIFT     (8U)
#define LPDDR_DENALI_PI_222_PI_TRCD_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_222_PI_TRCD_F1_SHIFT)) & LPDDR_DENALI_PI_222_PI_TRCD_F1_MASK)

#define LPDDR_DENALI_PI_222_PI_TWTR_F1_MASK      (0x3F0000U)
#define LPDDR_DENALI_PI_222_PI_TWTR_F1_SHIFT     (16U)
#define LPDDR_DENALI_PI_222_PI_TWTR_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_222_PI_TWTR_F1_SHIFT)) & LPDDR_DENALI_PI_222_PI_TWTR_F1_MASK)

#define LPDDR_DENALI_PI_222_PI_TWR_F1_MASK       (0xFF000000U)
#define LPDDR_DENALI_PI_222_PI_TWR_F1_SHIFT      (24U)
#define LPDDR_DENALI_PI_222_PI_TWR_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_222_PI_TWR_F1_SHIFT)) & LPDDR_DENALI_PI_222_PI_TWR_F1_MASK)
/*! @} */

/*! @name DENALI_PI_223 - DENALI_PI_223 */
/*! @{ */

#define LPDDR_DENALI_PI_223_PI_TRAS_MAX_F1_MASK  (0x1FFFFU)
#define LPDDR_DENALI_PI_223_PI_TRAS_MAX_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_223_PI_TRAS_MAX_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_223_PI_TRAS_MAX_F1_SHIFT)) & LPDDR_DENALI_PI_223_PI_TRAS_MAX_F1_MASK)
/*! @} */

/*! @name DENALI_PI_224 - DENALI_PI_224 */
/*! @{ */

#define LPDDR_DENALI_PI_224_PI_TRAS_MIN_F1_MASK  (0x1FFU)
#define LPDDR_DENALI_PI_224_PI_TRAS_MIN_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_224_PI_TRAS_MIN_F1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_224_PI_TRAS_MIN_F1_SHIFT)) & LPDDR_DENALI_PI_224_PI_TRAS_MIN_F1_MASK)

#define LPDDR_DENALI_PI_224_PI_TDQSCK_MAX_F1_MASK (0xF0000U)
#define LPDDR_DENALI_PI_224_PI_TDQSCK_MAX_F1_SHIFT (16U)
#define LPDDR_DENALI_PI_224_PI_TDQSCK_MAX_F1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_224_PI_TDQSCK_MAX_F1_SHIFT)) & LPDDR_DENALI_PI_224_PI_TDQSCK_MAX_F1_MASK)

#define LPDDR_DENALI_PI_224_PI_TCCDMW_F1_MASK    (0x3F000000U)
#define LPDDR_DENALI_PI_224_PI_TCCDMW_F1_SHIFT   (24U)
#define LPDDR_DENALI_PI_224_PI_TCCDMW_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_224_PI_TCCDMW_F1_SHIFT)) & LPDDR_DENALI_PI_224_PI_TCCDMW_F1_MASK)
/*! @} */

/*! @name DENALI_PI_225 - DENALI_PI_225 */
/*! @{ */

#define LPDDR_DENALI_PI_225_PI_TSR_F1_MASK       (0xFFU)
#define LPDDR_DENALI_PI_225_PI_TSR_F1_SHIFT      (0U)
#define LPDDR_DENALI_PI_225_PI_TSR_F1(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_225_PI_TSR_F1_SHIFT)) & LPDDR_DENALI_PI_225_PI_TSR_F1_MASK)

#define LPDDR_DENALI_PI_225_PI_TMRD_F1_MASK      (0xFF00U)
#define LPDDR_DENALI_PI_225_PI_TMRD_F1_SHIFT     (8U)
#define LPDDR_DENALI_PI_225_PI_TMRD_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_225_PI_TMRD_F1_SHIFT)) & LPDDR_DENALI_PI_225_PI_TMRD_F1_MASK)

#define LPDDR_DENALI_PI_225_PI_TMRW_F1_MASK      (0xFF0000U)
#define LPDDR_DENALI_PI_225_PI_TMRW_F1_SHIFT     (16U)
#define LPDDR_DENALI_PI_225_PI_TMRW_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_225_PI_TMRW_F1_SHIFT)) & LPDDR_DENALI_PI_225_PI_TMRW_F1_MASK)

#define LPDDR_DENALI_PI_225_PI_TRTP_F2_MASK      (0xFF000000U)
#define LPDDR_DENALI_PI_225_PI_TRTP_F2_SHIFT     (24U)
#define LPDDR_DENALI_PI_225_PI_TRTP_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_225_PI_TRTP_F2_SHIFT)) & LPDDR_DENALI_PI_225_PI_TRTP_F2_MASK)
/*! @} */

/*! @name DENALI_PI_226 - DENALI_PI_226 */
/*! @{ */

#define LPDDR_DENALI_PI_226_PI_TRP_F2_MASK       (0xFFU)
#define LPDDR_DENALI_PI_226_PI_TRP_F2_SHIFT      (0U)
#define LPDDR_DENALI_PI_226_PI_TRP_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_226_PI_TRP_F2_SHIFT)) & LPDDR_DENALI_PI_226_PI_TRP_F2_MASK)

#define LPDDR_DENALI_PI_226_PI_TRCD_F2_MASK      (0xFF00U)
#define LPDDR_DENALI_PI_226_PI_TRCD_F2_SHIFT     (8U)
#define LPDDR_DENALI_PI_226_PI_TRCD_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_226_PI_TRCD_F2_SHIFT)) & LPDDR_DENALI_PI_226_PI_TRCD_F2_MASK)

#define LPDDR_DENALI_PI_226_PI_TWTR_F2_MASK      (0x3F0000U)
#define LPDDR_DENALI_PI_226_PI_TWTR_F2_SHIFT     (16U)
#define LPDDR_DENALI_PI_226_PI_TWTR_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_226_PI_TWTR_F2_SHIFT)) & LPDDR_DENALI_PI_226_PI_TWTR_F2_MASK)

#define LPDDR_DENALI_PI_226_PI_TWR_F2_MASK       (0xFF000000U)
#define LPDDR_DENALI_PI_226_PI_TWR_F2_SHIFT      (24U)
#define LPDDR_DENALI_PI_226_PI_TWR_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_226_PI_TWR_F2_SHIFT)) & LPDDR_DENALI_PI_226_PI_TWR_F2_MASK)
/*! @} */

/*! @name DENALI_PI_227 - DENALI_PI_227 */
/*! @{ */

#define LPDDR_DENALI_PI_227_PI_TRAS_MAX_F2_MASK  (0x1FFFFU)
#define LPDDR_DENALI_PI_227_PI_TRAS_MAX_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_227_PI_TRAS_MAX_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_227_PI_TRAS_MAX_F2_SHIFT)) & LPDDR_DENALI_PI_227_PI_TRAS_MAX_F2_MASK)
/*! @} */

/*! @name DENALI_PI_228 - DENALI_PI_228 */
/*! @{ */

#define LPDDR_DENALI_PI_228_PI_TRAS_MIN_F2_MASK  (0x1FFU)
#define LPDDR_DENALI_PI_228_PI_TRAS_MIN_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_228_PI_TRAS_MIN_F2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_228_PI_TRAS_MIN_F2_SHIFT)) & LPDDR_DENALI_PI_228_PI_TRAS_MIN_F2_MASK)

#define LPDDR_DENALI_PI_228_PI_TDQSCK_MAX_F2_MASK (0xF0000U)
#define LPDDR_DENALI_PI_228_PI_TDQSCK_MAX_F2_SHIFT (16U)
#define LPDDR_DENALI_PI_228_PI_TDQSCK_MAX_F2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_228_PI_TDQSCK_MAX_F2_SHIFT)) & LPDDR_DENALI_PI_228_PI_TDQSCK_MAX_F2_MASK)

#define LPDDR_DENALI_PI_228_PI_TCCDMW_F2_MASK    (0x3F000000U)
#define LPDDR_DENALI_PI_228_PI_TCCDMW_F2_SHIFT   (24U)
#define LPDDR_DENALI_PI_228_PI_TCCDMW_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_228_PI_TCCDMW_F2_SHIFT)) & LPDDR_DENALI_PI_228_PI_TCCDMW_F2_MASK)
/*! @} */

/*! @name DENALI_PI_229 - DENALI_PI_229 */
/*! @{ */

#define LPDDR_DENALI_PI_229_PI_TSR_F2_MASK       (0xFFU)
#define LPDDR_DENALI_PI_229_PI_TSR_F2_SHIFT      (0U)
#define LPDDR_DENALI_PI_229_PI_TSR_F2(x)         (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_229_PI_TSR_F2_SHIFT)) & LPDDR_DENALI_PI_229_PI_TSR_F2_MASK)

#define LPDDR_DENALI_PI_229_PI_TMRD_F2_MASK      (0xFF00U)
#define LPDDR_DENALI_PI_229_PI_TMRD_F2_SHIFT     (8U)
#define LPDDR_DENALI_PI_229_PI_TMRD_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_229_PI_TMRD_F2_SHIFT)) & LPDDR_DENALI_PI_229_PI_TMRD_F2_MASK)

#define LPDDR_DENALI_PI_229_PI_TMRW_F2_MASK      (0xFF0000U)
#define LPDDR_DENALI_PI_229_PI_TMRW_F2_SHIFT     (16U)
#define LPDDR_DENALI_PI_229_PI_TMRW_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_229_PI_TMRW_F2_SHIFT)) & LPDDR_DENALI_PI_229_PI_TMRW_F2_MASK)
/*! @} */

/*! @name DENALI_PI_230 - DENALI_PI_230 */
/*! @{ */

#define LPDDR_DENALI_PI_230_PI_TDFI_CTRLUPD_MAX_F0_MASK (0x1FFFFFU)
#define LPDDR_DENALI_PI_230_PI_TDFI_CTRLUPD_MAX_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_230_PI_TDFI_CTRLUPD_MAX_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_230_PI_TDFI_CTRLUPD_MAX_F0_SHIFT)) & LPDDR_DENALI_PI_230_PI_TDFI_CTRLUPD_MAX_F0_MASK)
/*! @} */

/*! @name DENALI_PI_231 - DENALI_PI_231 */
/*! @{ */

#define LPDDR_DENALI_PI_231_PI_TDFI_CTRLUPD_INTERVAL_F0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PI_231_PI_TDFI_CTRLUPD_INTERVAL_F0_SHIFT (0U)
#define LPDDR_DENALI_PI_231_PI_TDFI_CTRLUPD_INTERVAL_F0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_231_PI_TDFI_CTRLUPD_INTERVAL_F0_SHIFT)) & LPDDR_DENALI_PI_231_PI_TDFI_CTRLUPD_INTERVAL_F0_MASK)
/*! @} */

/*! @name DENALI_PI_232 - DENALI_PI_232 */
/*! @{ */

#define LPDDR_DENALI_PI_232_PI_TDFI_CTRLUPD_MAX_F1_MASK (0x1FFFFFU)
#define LPDDR_DENALI_PI_232_PI_TDFI_CTRLUPD_MAX_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_232_PI_TDFI_CTRLUPD_MAX_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_232_PI_TDFI_CTRLUPD_MAX_F1_SHIFT)) & LPDDR_DENALI_PI_232_PI_TDFI_CTRLUPD_MAX_F1_MASK)
/*! @} */

/*! @name DENALI_PI_233 - DENALI_PI_233 */
/*! @{ */

#define LPDDR_DENALI_PI_233_PI_TDFI_CTRLUPD_INTERVAL_F1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PI_233_PI_TDFI_CTRLUPD_INTERVAL_F1_SHIFT (0U)
#define LPDDR_DENALI_PI_233_PI_TDFI_CTRLUPD_INTERVAL_F1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_233_PI_TDFI_CTRLUPD_INTERVAL_F1_SHIFT)) & LPDDR_DENALI_PI_233_PI_TDFI_CTRLUPD_INTERVAL_F1_MASK)
/*! @} */

/*! @name DENALI_PI_234 - DENALI_PI_234 */
/*! @{ */

#define LPDDR_DENALI_PI_234_PI_TDFI_CTRLUPD_MAX_F2_MASK (0x1FFFFFU)
#define LPDDR_DENALI_PI_234_PI_TDFI_CTRLUPD_MAX_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_234_PI_TDFI_CTRLUPD_MAX_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_234_PI_TDFI_CTRLUPD_MAX_F2_SHIFT)) & LPDDR_DENALI_PI_234_PI_TDFI_CTRLUPD_MAX_F2_MASK)
/*! @} */

/*! @name DENALI_PI_235 - DENALI_PI_235 */
/*! @{ */

#define LPDDR_DENALI_PI_235_PI_TDFI_CTRLUPD_INTERVAL_F2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PI_235_PI_TDFI_CTRLUPD_INTERVAL_F2_SHIFT (0U)
#define LPDDR_DENALI_PI_235_PI_TDFI_CTRLUPD_INTERVAL_F2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_235_PI_TDFI_CTRLUPD_INTERVAL_F2_SHIFT)) & LPDDR_DENALI_PI_235_PI_TDFI_CTRLUPD_INTERVAL_F2_MASK)
/*! @} */

/*! @name DENALI_PI_236 - DENALI_PI_236 */
/*! @{ */

#define LPDDR_DENALI_PI_236_PI_TXSR_F0_MASK      (0xFFFFU)
#define LPDDR_DENALI_PI_236_PI_TXSR_F0_SHIFT     (0U)
#define LPDDR_DENALI_PI_236_PI_TXSR_F0(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_236_PI_TXSR_F0_SHIFT)) & LPDDR_DENALI_PI_236_PI_TXSR_F0_MASK)

#define LPDDR_DENALI_PI_236_PI_TXSR_F1_MASK      (0xFFFF0000U)
#define LPDDR_DENALI_PI_236_PI_TXSR_F1_SHIFT     (16U)
#define LPDDR_DENALI_PI_236_PI_TXSR_F1(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_236_PI_TXSR_F1_SHIFT)) & LPDDR_DENALI_PI_236_PI_TXSR_F1_MASK)
/*! @} */

/*! @name DENALI_PI_237 - DENALI_PI_237 */
/*! @{ */

#define LPDDR_DENALI_PI_237_PI_TXSR_F2_MASK      (0xFFFFU)
#define LPDDR_DENALI_PI_237_PI_TXSR_F2_SHIFT     (0U)
#define LPDDR_DENALI_PI_237_PI_TXSR_F2(x)        (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_237_PI_TXSR_F2_SHIFT)) & LPDDR_DENALI_PI_237_PI_TXSR_F2_MASK)

#define LPDDR_DENALI_PI_237_PI_TEXCKE_F0_MASK    (0x3F0000U)
#define LPDDR_DENALI_PI_237_PI_TEXCKE_F0_SHIFT   (16U)
#define LPDDR_DENALI_PI_237_PI_TEXCKE_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_237_PI_TEXCKE_F0_SHIFT)) & LPDDR_DENALI_PI_237_PI_TEXCKE_F0_MASK)

#define LPDDR_DENALI_PI_237_PI_TEXCKE_F1_MASK    (0x3F000000U)
#define LPDDR_DENALI_PI_237_PI_TEXCKE_F1_SHIFT   (24U)
#define LPDDR_DENALI_PI_237_PI_TEXCKE_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_237_PI_TEXCKE_F1_SHIFT)) & LPDDR_DENALI_PI_237_PI_TEXCKE_F1_MASK)
/*! @} */

/*! @name DENALI_PI_238 - DENALI_PI_238 */
/*! @{ */

#define LPDDR_DENALI_PI_238_PI_TEXCKE_F2_MASK    (0x3FU)
#define LPDDR_DENALI_PI_238_PI_TEXCKE_F2_SHIFT   (0U)
#define LPDDR_DENALI_PI_238_PI_TEXCKE_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_238_PI_TEXCKE_F2_SHIFT)) & LPDDR_DENALI_PI_238_PI_TEXCKE_F2_MASK)

#define LPDDR_DENALI_PI_238_PI_TINIT_F0_MASK     (0xFFFFFF00U)
#define LPDDR_DENALI_PI_238_PI_TINIT_F0_SHIFT    (8U)
#define LPDDR_DENALI_PI_238_PI_TINIT_F0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_238_PI_TINIT_F0_SHIFT)) & LPDDR_DENALI_PI_238_PI_TINIT_F0_MASK)
/*! @} */

/*! @name DENALI_PI_239 - DENALI_PI_239 */
/*! @{ */

#define LPDDR_DENALI_PI_239_PI_TINIT3_F0_MASK    (0xFFFFFFU)
#define LPDDR_DENALI_PI_239_PI_TINIT3_F0_SHIFT   (0U)
#define LPDDR_DENALI_PI_239_PI_TINIT3_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_239_PI_TINIT3_F0_SHIFT)) & LPDDR_DENALI_PI_239_PI_TINIT3_F0_MASK)
/*! @} */

/*! @name DENALI_PI_242 - DENALI_PI_242 */
/*! @{ */

#define LPDDR_DENALI_PI_242_PI_TXSNR_F0_MASK     (0xFFFFU)
#define LPDDR_DENALI_PI_242_PI_TXSNR_F0_SHIFT    (0U)
#define LPDDR_DENALI_PI_242_PI_TXSNR_F0(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_242_PI_TXSNR_F0_SHIFT)) & LPDDR_DENALI_PI_242_PI_TXSNR_F0_MASK)
/*! @} */

/*! @name DENALI_PI_243 - DENALI_PI_243 */
/*! @{ */

#define LPDDR_DENALI_PI_243_PI_TINIT_F1_MASK     (0xFFFFFFU)
#define LPDDR_DENALI_PI_243_PI_TINIT_F1_SHIFT    (0U)
#define LPDDR_DENALI_PI_243_PI_TINIT_F1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_243_PI_TINIT_F1_SHIFT)) & LPDDR_DENALI_PI_243_PI_TINIT_F1_MASK)
/*! @} */

/*! @name DENALI_PI_244 - DENALI_PI_244 */
/*! @{ */

#define LPDDR_DENALI_PI_244_PI_TINIT3_F1_MASK    (0xFFFFFFU)
#define LPDDR_DENALI_PI_244_PI_TINIT3_F1_SHIFT   (0U)
#define LPDDR_DENALI_PI_244_PI_TINIT3_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_244_PI_TINIT3_F1_SHIFT)) & LPDDR_DENALI_PI_244_PI_TINIT3_F1_MASK)
/*! @} */

/*! @name DENALI_PI_246 - DENALI_PI_246 */
/*! @{ */

#define LPDDR_DENALI_PI_246_PI_TINIT5_F1_MASK    (0xFFFFFFU)
#define LPDDR_DENALI_PI_246_PI_TINIT5_F1_SHIFT   (0U)
#define LPDDR_DENALI_PI_246_PI_TINIT5_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_246_PI_TINIT5_F1_SHIFT)) & LPDDR_DENALI_PI_246_PI_TINIT5_F1_MASK)
/*! @} */

/*! @name DENALI_PI_247 - DENALI_PI_247 */
/*! @{ */

#define LPDDR_DENALI_PI_247_PI_TXSNR_F1_MASK     (0xFFFFU)
#define LPDDR_DENALI_PI_247_PI_TXSNR_F1_SHIFT    (0U)
#define LPDDR_DENALI_PI_247_PI_TXSNR_F1(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_247_PI_TXSNR_F1_SHIFT)) & LPDDR_DENALI_PI_247_PI_TXSNR_F1_MASK)
/*! @} */

/*! @name DENALI_PI_248 - DENALI_PI_248 */
/*! @{ */

#define LPDDR_DENALI_PI_248_PI_TINIT_F2_MASK     (0xFFFFFFU)
#define LPDDR_DENALI_PI_248_PI_TINIT_F2_SHIFT    (0U)
#define LPDDR_DENALI_PI_248_PI_TINIT_F2(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_248_PI_TINIT_F2_SHIFT)) & LPDDR_DENALI_PI_248_PI_TINIT_F2_MASK)
/*! @} */

/*! @name DENALI_PI_249 - DENALI_PI_249 */
/*! @{ */

#define LPDDR_DENALI_PI_249_PI_TINIT3_F2_MASK    (0xFFFFFFU)
#define LPDDR_DENALI_PI_249_PI_TINIT3_F2_SHIFT   (0U)
#define LPDDR_DENALI_PI_249_PI_TINIT3_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_249_PI_TINIT3_F2_SHIFT)) & LPDDR_DENALI_PI_249_PI_TINIT3_F2_MASK)
/*! @} */

/*! @name DENALI_PI_251 - DENALI_PI_251 */
/*! @{ */

#define LPDDR_DENALI_PI_251_PI_TINIT5_F2_MASK    (0xFFFFFFU)
#define LPDDR_DENALI_PI_251_PI_TINIT5_F2_SHIFT   (0U)
#define LPDDR_DENALI_PI_251_PI_TINIT5_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_251_PI_TINIT5_F2_SHIFT)) & LPDDR_DENALI_PI_251_PI_TINIT5_F2_MASK)
/*! @} */

/*! @name DENALI_PI_252 - DENALI_PI_252 */
/*! @{ */

#define LPDDR_DENALI_PI_252_PI_TXSNR_F2_MASK     (0xFFFFU)
#define LPDDR_DENALI_PI_252_PI_TXSNR_F2_SHIFT    (0U)
#define LPDDR_DENALI_PI_252_PI_TXSNR_F2(x)       (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_252_PI_TXSNR_F2_SHIFT)) & LPDDR_DENALI_PI_252_PI_TXSNR_F2_MASK)
/*! @} */

/*! @name DENALI_PI_253 - DENALI_PI_253 */
/*! @{ */

#define LPDDR_DENALI_PI_253_PI_TZQCAL_F0_MASK    (0xFFF0000U)
#define LPDDR_DENALI_PI_253_PI_TZQCAL_F0_SHIFT   (16U)
#define LPDDR_DENALI_PI_253_PI_TZQCAL_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_253_PI_TZQCAL_F0_SHIFT)) & LPDDR_DENALI_PI_253_PI_TZQCAL_F0_MASK)
/*! @} */

/*! @name DENALI_PI_254 - DENALI_PI_254 */
/*! @{ */

#define LPDDR_DENALI_PI_254_PI_TZQLAT_F0_MASK    (0x7FU)
#define LPDDR_DENALI_PI_254_PI_TZQLAT_F0_SHIFT   (0U)
#define LPDDR_DENALI_PI_254_PI_TZQLAT_F0(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_254_PI_TZQLAT_F0_SHIFT)) & LPDDR_DENALI_PI_254_PI_TZQLAT_F0_MASK)
/*! @} */

/*! @name DENALI_PI_255 - DENALI_PI_255 */
/*! @{ */

#define LPDDR_DENALI_PI_255_PI_TZQCAL_F1_MASK    (0xFFF0000U)
#define LPDDR_DENALI_PI_255_PI_TZQCAL_F1_SHIFT   (16U)
#define LPDDR_DENALI_PI_255_PI_TZQCAL_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_255_PI_TZQCAL_F1_SHIFT)) & LPDDR_DENALI_PI_255_PI_TZQCAL_F1_MASK)
/*! @} */

/*! @name DENALI_PI_256 - DENALI_PI_256 */
/*! @{ */

#define LPDDR_DENALI_PI_256_PI_TZQLAT_F1_MASK    (0x7FU)
#define LPDDR_DENALI_PI_256_PI_TZQLAT_F1_SHIFT   (0U)
#define LPDDR_DENALI_PI_256_PI_TZQLAT_F1(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_256_PI_TZQLAT_F1_SHIFT)) & LPDDR_DENALI_PI_256_PI_TZQLAT_F1_MASK)
/*! @} */

/*! @name DENALI_PI_257 - DENALI_PI_257 */
/*! @{ */

#define LPDDR_DENALI_PI_257_PI_TZQCAL_F2_MASK    (0xFFF0000U)
#define LPDDR_DENALI_PI_257_PI_TZQCAL_F2_SHIFT   (16U)
#define LPDDR_DENALI_PI_257_PI_TZQCAL_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_257_PI_TZQCAL_F2_SHIFT)) & LPDDR_DENALI_PI_257_PI_TZQCAL_F2_MASK)
/*! @} */

/*! @name DENALI_PI_258 - DENALI_PI_258 */
/*! @{ */

#define LPDDR_DENALI_PI_258_PI_TZQLAT_F2_MASK    (0x7FU)
#define LPDDR_DENALI_PI_258_PI_TZQLAT_F2_SHIFT   (0U)
#define LPDDR_DENALI_PI_258_PI_TZQLAT_F2(x)      (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_258_PI_TZQLAT_F2_SHIFT)) & LPDDR_DENALI_PI_258_PI_TZQLAT_F2_MASK)
/*! @} */

/*! @name DENALI_PI_261 - DENALI_PI_261 */
/*! @{ */

#define LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS0_MASK (0xFU)
#define LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS0_SHIFT (0U)
#define LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS0_SHIFT)) & LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS0_MASK)

#define LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS0_MASK (0xF00U)
#define LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS0_SHIFT (8U)
#define LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS0_SHIFT)) & LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS0_MASK)

#define LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS1_MASK (0xF0000U)
#define LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS1_SHIFT (16U)
#define LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS1_SHIFT)) & LPDDR_DENALI_PI_261_PI_ODT_RD_MAP_CS1_MASK)

#define LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS1_MASK (0xF000000U)
#define LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS1_SHIFT (24U)
#define LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS1_SHIFT)) & LPDDR_DENALI_PI_261_PI_ODT_WR_MAP_CS1_MASK)
/*! @} */

/*! @name DENALI_PI_277 - DENALI_PI_277 */
/*! @{ */

#define LPDDR_DENALI_PI_277_PI_MR1_DATA_F0_0_MASK (0xFFU)
#define LPDDR_DENALI_PI_277_PI_MR1_DATA_F0_0_SHIFT (0U)
#define LPDDR_DENALI_PI_277_PI_MR1_DATA_F0_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_277_PI_MR1_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_277_PI_MR1_DATA_F0_0_MASK)

#define LPDDR_DENALI_PI_277_PI_MR2_DATA_F0_0_MASK (0xFF00U)
#define LPDDR_DENALI_PI_277_PI_MR2_DATA_F0_0_SHIFT (8U)
#define LPDDR_DENALI_PI_277_PI_MR2_DATA_F0_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_277_PI_MR2_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_277_PI_MR2_DATA_F0_0_MASK)

#define LPDDR_DENALI_PI_277_PI_MR3_DATA_F0_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_277_PI_MR3_DATA_F0_0_SHIFT (16U)
#define LPDDR_DENALI_PI_277_PI_MR3_DATA_F0_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_277_PI_MR3_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_277_PI_MR3_DATA_F0_0_MASK)

#define LPDDR_DENALI_PI_277_PI_MR11_DATA_F0_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_277_PI_MR11_DATA_F0_0_SHIFT (24U)
#define LPDDR_DENALI_PI_277_PI_MR11_DATA_F0_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_277_PI_MR11_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_277_PI_MR11_DATA_F0_0_MASK)
/*! @} */

/*! @name DENALI_PI_278 - DENALI_PI_278 */
/*! @{ */

#define LPDDR_DENALI_PI_278_PI_MR12_DATA_F0_0_MASK (0xFFU)
#define LPDDR_DENALI_PI_278_PI_MR12_DATA_F0_0_SHIFT (0U)
#define LPDDR_DENALI_PI_278_PI_MR12_DATA_F0_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_278_PI_MR12_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_278_PI_MR12_DATA_F0_0_MASK)

#define LPDDR_DENALI_PI_278_PI_MR14_DATA_F0_0_MASK (0xFF00U)
#define LPDDR_DENALI_PI_278_PI_MR14_DATA_F0_0_SHIFT (8U)
#define LPDDR_DENALI_PI_278_PI_MR14_DATA_F0_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_278_PI_MR14_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_278_PI_MR14_DATA_F0_0_MASK)

#define LPDDR_DENALI_PI_278_PI_MR22_DATA_F0_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_278_PI_MR22_DATA_F0_0_SHIFT (16U)
#define LPDDR_DENALI_PI_278_PI_MR22_DATA_F0_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_278_PI_MR22_DATA_F0_0_SHIFT)) & LPDDR_DENALI_PI_278_PI_MR22_DATA_F0_0_MASK)

#define LPDDR_DENALI_PI_278_PI_MR1_DATA_F1_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_278_PI_MR1_DATA_F1_0_SHIFT (24U)
#define LPDDR_DENALI_PI_278_PI_MR1_DATA_F1_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_278_PI_MR1_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_278_PI_MR1_DATA_F1_0_MASK)
/*! @} */

/*! @name DENALI_PI_279 - DENALI_PI_279 */
/*! @{ */

#define LPDDR_DENALI_PI_279_PI_MR2_DATA_F1_0_MASK (0xFFU)
#define LPDDR_DENALI_PI_279_PI_MR2_DATA_F1_0_SHIFT (0U)
#define LPDDR_DENALI_PI_279_PI_MR2_DATA_F1_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_279_PI_MR2_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_279_PI_MR2_DATA_F1_0_MASK)

#define LPDDR_DENALI_PI_279_PI_MR3_DATA_F1_0_MASK (0xFF00U)
#define LPDDR_DENALI_PI_279_PI_MR3_DATA_F1_0_SHIFT (8U)
#define LPDDR_DENALI_PI_279_PI_MR3_DATA_F1_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_279_PI_MR3_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_279_PI_MR3_DATA_F1_0_MASK)

#define LPDDR_DENALI_PI_279_PI_MR11_DATA_F1_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_279_PI_MR11_DATA_F1_0_SHIFT (16U)
#define LPDDR_DENALI_PI_279_PI_MR11_DATA_F1_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_279_PI_MR11_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_279_PI_MR11_DATA_F1_0_MASK)

#define LPDDR_DENALI_PI_279_PI_MR12_DATA_F1_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_279_PI_MR12_DATA_F1_0_SHIFT (24U)
#define LPDDR_DENALI_PI_279_PI_MR12_DATA_F1_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_279_PI_MR12_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_279_PI_MR12_DATA_F1_0_MASK)
/*! @} */

/*! @name DENALI_PI_280 - DENALI_PI_280 */
/*! @{ */

#define LPDDR_DENALI_PI_280_PI_MR14_DATA_F1_0_MASK (0xFFU)
#define LPDDR_DENALI_PI_280_PI_MR14_DATA_F1_0_SHIFT (0U)
#define LPDDR_DENALI_PI_280_PI_MR14_DATA_F1_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_280_PI_MR14_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_280_PI_MR14_DATA_F1_0_MASK)

#define LPDDR_DENALI_PI_280_PI_MR22_DATA_F1_0_MASK (0xFF00U)
#define LPDDR_DENALI_PI_280_PI_MR22_DATA_F1_0_SHIFT (8U)
#define LPDDR_DENALI_PI_280_PI_MR22_DATA_F1_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_280_PI_MR22_DATA_F1_0_SHIFT)) & LPDDR_DENALI_PI_280_PI_MR22_DATA_F1_0_MASK)

#define LPDDR_DENALI_PI_280_PI_MR1_DATA_F2_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_280_PI_MR1_DATA_F2_0_SHIFT (16U)
#define LPDDR_DENALI_PI_280_PI_MR1_DATA_F2_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_280_PI_MR1_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_280_PI_MR1_DATA_F2_0_MASK)

#define LPDDR_DENALI_PI_280_PI_MR2_DATA_F2_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_280_PI_MR2_DATA_F2_0_SHIFT (24U)
#define LPDDR_DENALI_PI_280_PI_MR2_DATA_F2_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_280_PI_MR2_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_280_PI_MR2_DATA_F2_0_MASK)
/*! @} */

/*! @name DENALI_PI_281 - DENALI_PI_281 */
/*! @{ */

#define LPDDR_DENALI_PI_281_PI_MR3_DATA_F2_0_MASK (0xFFU)
#define LPDDR_DENALI_PI_281_PI_MR3_DATA_F2_0_SHIFT (0U)
#define LPDDR_DENALI_PI_281_PI_MR3_DATA_F2_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_281_PI_MR3_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_281_PI_MR3_DATA_F2_0_MASK)

#define LPDDR_DENALI_PI_281_PI_MR11_DATA_F2_0_MASK (0xFF00U)
#define LPDDR_DENALI_PI_281_PI_MR11_DATA_F2_0_SHIFT (8U)
#define LPDDR_DENALI_PI_281_PI_MR11_DATA_F2_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_281_PI_MR11_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_281_PI_MR11_DATA_F2_0_MASK)

#define LPDDR_DENALI_PI_281_PI_MR12_DATA_F2_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_281_PI_MR12_DATA_F2_0_SHIFT (16U)
#define LPDDR_DENALI_PI_281_PI_MR12_DATA_F2_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_281_PI_MR12_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_281_PI_MR12_DATA_F2_0_MASK)

#define LPDDR_DENALI_PI_281_PI_MR14_DATA_F2_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_281_PI_MR14_DATA_F2_0_SHIFT (24U)
#define LPDDR_DENALI_PI_281_PI_MR14_DATA_F2_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_281_PI_MR14_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_281_PI_MR14_DATA_F2_0_MASK)
/*! @} */

/*! @name DENALI_PI_282 - DENALI_PI_282 */
/*! @{ */

#define LPDDR_DENALI_PI_282_PI_MR22_DATA_F2_0_MASK (0xFFU)
#define LPDDR_DENALI_PI_282_PI_MR22_DATA_F2_0_SHIFT (0U)
#define LPDDR_DENALI_PI_282_PI_MR22_DATA_F2_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_282_PI_MR22_DATA_F2_0_SHIFT)) & LPDDR_DENALI_PI_282_PI_MR22_DATA_F2_0_MASK)

#define LPDDR_DENALI_PI_282_PI_MR1_DATA_F0_1_MASK (0xFF00U)
#define LPDDR_DENALI_PI_282_PI_MR1_DATA_F0_1_SHIFT (8U)
#define LPDDR_DENALI_PI_282_PI_MR1_DATA_F0_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_282_PI_MR1_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_282_PI_MR1_DATA_F0_1_MASK)

#define LPDDR_DENALI_PI_282_PI_MR2_DATA_F0_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_282_PI_MR2_DATA_F0_1_SHIFT (16U)
#define LPDDR_DENALI_PI_282_PI_MR2_DATA_F0_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_282_PI_MR2_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_282_PI_MR2_DATA_F0_1_MASK)

#define LPDDR_DENALI_PI_282_PI_MR3_DATA_F0_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_282_PI_MR3_DATA_F0_1_SHIFT (24U)
#define LPDDR_DENALI_PI_282_PI_MR3_DATA_F0_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_282_PI_MR3_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_282_PI_MR3_DATA_F0_1_MASK)
/*! @} */

/*! @name DENALI_PI_283 - DENALI_PI_283 */
/*! @{ */

#define LPDDR_DENALI_PI_283_PI_MR11_DATA_F0_1_MASK (0xFFU)
#define LPDDR_DENALI_PI_283_PI_MR11_DATA_F0_1_SHIFT (0U)
#define LPDDR_DENALI_PI_283_PI_MR11_DATA_F0_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_283_PI_MR11_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_283_PI_MR11_DATA_F0_1_MASK)

#define LPDDR_DENALI_PI_283_PI_MR12_DATA_F0_1_MASK (0xFF00U)
#define LPDDR_DENALI_PI_283_PI_MR12_DATA_F0_1_SHIFT (8U)
#define LPDDR_DENALI_PI_283_PI_MR12_DATA_F0_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_283_PI_MR12_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_283_PI_MR12_DATA_F0_1_MASK)

#define LPDDR_DENALI_PI_283_PI_MR14_DATA_F0_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_283_PI_MR14_DATA_F0_1_SHIFT (16U)
#define LPDDR_DENALI_PI_283_PI_MR14_DATA_F0_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_283_PI_MR14_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_283_PI_MR14_DATA_F0_1_MASK)

#define LPDDR_DENALI_PI_283_PI_MR22_DATA_F0_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_283_PI_MR22_DATA_F0_1_SHIFT (24U)
#define LPDDR_DENALI_PI_283_PI_MR22_DATA_F0_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_283_PI_MR22_DATA_F0_1_SHIFT)) & LPDDR_DENALI_PI_283_PI_MR22_DATA_F0_1_MASK)
/*! @} */

/*! @name DENALI_PI_284 - DENALI_PI_284 */
/*! @{ */

#define LPDDR_DENALI_PI_284_PI_MR1_DATA_F1_1_MASK (0xFFU)
#define LPDDR_DENALI_PI_284_PI_MR1_DATA_F1_1_SHIFT (0U)
#define LPDDR_DENALI_PI_284_PI_MR1_DATA_F1_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_284_PI_MR1_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_284_PI_MR1_DATA_F1_1_MASK)

#define LPDDR_DENALI_PI_284_PI_MR2_DATA_F1_1_MASK (0xFF00U)
#define LPDDR_DENALI_PI_284_PI_MR2_DATA_F1_1_SHIFT (8U)
#define LPDDR_DENALI_PI_284_PI_MR2_DATA_F1_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_284_PI_MR2_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_284_PI_MR2_DATA_F1_1_MASK)

#define LPDDR_DENALI_PI_284_PI_MR3_DATA_F1_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_284_PI_MR3_DATA_F1_1_SHIFT (16U)
#define LPDDR_DENALI_PI_284_PI_MR3_DATA_F1_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_284_PI_MR3_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_284_PI_MR3_DATA_F1_1_MASK)

#define LPDDR_DENALI_PI_284_PI_MR11_DATA_F1_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_284_PI_MR11_DATA_F1_1_SHIFT (24U)
#define LPDDR_DENALI_PI_284_PI_MR11_DATA_F1_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_284_PI_MR11_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_284_PI_MR11_DATA_F1_1_MASK)
/*! @} */

/*! @name DENALI_PI_285 - DENALI_PI_285 */
/*! @{ */

#define LPDDR_DENALI_PI_285_PI_MR12_DATA_F1_1_MASK (0xFFU)
#define LPDDR_DENALI_PI_285_PI_MR12_DATA_F1_1_SHIFT (0U)
#define LPDDR_DENALI_PI_285_PI_MR12_DATA_F1_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_285_PI_MR12_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_285_PI_MR12_DATA_F1_1_MASK)

#define LPDDR_DENALI_PI_285_PI_MR14_DATA_F1_1_MASK (0xFF00U)
#define LPDDR_DENALI_PI_285_PI_MR14_DATA_F1_1_SHIFT (8U)
#define LPDDR_DENALI_PI_285_PI_MR14_DATA_F1_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_285_PI_MR14_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_285_PI_MR14_DATA_F1_1_MASK)

#define LPDDR_DENALI_PI_285_PI_MR22_DATA_F1_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_285_PI_MR22_DATA_F1_1_SHIFT (16U)
#define LPDDR_DENALI_PI_285_PI_MR22_DATA_F1_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_285_PI_MR22_DATA_F1_1_SHIFT)) & LPDDR_DENALI_PI_285_PI_MR22_DATA_F1_1_MASK)

#define LPDDR_DENALI_PI_285_PI_MR1_DATA_F2_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_285_PI_MR1_DATA_F2_1_SHIFT (24U)
#define LPDDR_DENALI_PI_285_PI_MR1_DATA_F2_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_285_PI_MR1_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_285_PI_MR1_DATA_F2_1_MASK)
/*! @} */

/*! @name DENALI_PI_286 - DENALI_PI_286 */
/*! @{ */

#define LPDDR_DENALI_PI_286_PI_MR2_DATA_F2_1_MASK (0xFFU)
#define LPDDR_DENALI_PI_286_PI_MR2_DATA_F2_1_SHIFT (0U)
#define LPDDR_DENALI_PI_286_PI_MR2_DATA_F2_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_286_PI_MR2_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_286_PI_MR2_DATA_F2_1_MASK)

#define LPDDR_DENALI_PI_286_PI_MR3_DATA_F2_1_MASK (0xFF00U)
#define LPDDR_DENALI_PI_286_PI_MR3_DATA_F2_1_SHIFT (8U)
#define LPDDR_DENALI_PI_286_PI_MR3_DATA_F2_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_286_PI_MR3_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_286_PI_MR3_DATA_F2_1_MASK)

#define LPDDR_DENALI_PI_286_PI_MR11_DATA_F2_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_286_PI_MR11_DATA_F2_1_SHIFT (16U)
#define LPDDR_DENALI_PI_286_PI_MR11_DATA_F2_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_286_PI_MR11_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_286_PI_MR11_DATA_F2_1_MASK)

#define LPDDR_DENALI_PI_286_PI_MR12_DATA_F2_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_286_PI_MR12_DATA_F2_1_SHIFT (24U)
#define LPDDR_DENALI_PI_286_PI_MR12_DATA_F2_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_286_PI_MR12_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_286_PI_MR12_DATA_F2_1_MASK)
/*! @} */

/*! @name DENALI_PI_287 - DENALI_PI_287 */
/*! @{ */

#define LPDDR_DENALI_PI_287_PI_MR14_DATA_F2_1_MASK (0xFFU)
#define LPDDR_DENALI_PI_287_PI_MR14_DATA_F2_1_SHIFT (0U)
#define LPDDR_DENALI_PI_287_PI_MR14_DATA_F2_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_287_PI_MR14_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_287_PI_MR14_DATA_F2_1_MASK)

#define LPDDR_DENALI_PI_287_PI_MR22_DATA_F2_1_MASK (0xFF00U)
#define LPDDR_DENALI_PI_287_PI_MR22_DATA_F2_1_SHIFT (8U)
#define LPDDR_DENALI_PI_287_PI_MR22_DATA_F2_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_287_PI_MR22_DATA_F2_1_SHIFT)) & LPDDR_DENALI_PI_287_PI_MR22_DATA_F2_1_MASK)

#define LPDDR_DENALI_PI_287_PI_MR1_DATA_F0_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_287_PI_MR1_DATA_F0_2_SHIFT (16U)
#define LPDDR_DENALI_PI_287_PI_MR1_DATA_F0_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_287_PI_MR1_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_287_PI_MR1_DATA_F0_2_MASK)

#define LPDDR_DENALI_PI_287_PI_MR2_DATA_F0_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_287_PI_MR2_DATA_F0_2_SHIFT (24U)
#define LPDDR_DENALI_PI_287_PI_MR2_DATA_F0_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_287_PI_MR2_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_287_PI_MR2_DATA_F0_2_MASK)
/*! @} */

/*! @name DENALI_PI_288 - DENALI_PI_288 */
/*! @{ */

#define LPDDR_DENALI_PI_288_PI_MR3_DATA_F0_2_MASK (0xFFU)
#define LPDDR_DENALI_PI_288_PI_MR3_DATA_F0_2_SHIFT (0U)
#define LPDDR_DENALI_PI_288_PI_MR3_DATA_F0_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_288_PI_MR3_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_288_PI_MR3_DATA_F0_2_MASK)

#define LPDDR_DENALI_PI_288_PI_MR11_DATA_F0_2_MASK (0xFF00U)
#define LPDDR_DENALI_PI_288_PI_MR11_DATA_F0_2_SHIFT (8U)
#define LPDDR_DENALI_PI_288_PI_MR11_DATA_F0_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_288_PI_MR11_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_288_PI_MR11_DATA_F0_2_MASK)

#define LPDDR_DENALI_PI_288_PI_MR12_DATA_F0_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_288_PI_MR12_DATA_F0_2_SHIFT (16U)
#define LPDDR_DENALI_PI_288_PI_MR12_DATA_F0_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_288_PI_MR12_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_288_PI_MR12_DATA_F0_2_MASK)

#define LPDDR_DENALI_PI_288_PI_MR14_DATA_F0_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_288_PI_MR14_DATA_F0_2_SHIFT (24U)
#define LPDDR_DENALI_PI_288_PI_MR14_DATA_F0_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_288_PI_MR14_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_288_PI_MR14_DATA_F0_2_MASK)
/*! @} */

/*! @name DENALI_PI_289 - DENALI_PI_289 */
/*! @{ */

#define LPDDR_DENALI_PI_289_PI_MR22_DATA_F0_2_MASK (0xFFU)
#define LPDDR_DENALI_PI_289_PI_MR22_DATA_F0_2_SHIFT (0U)
#define LPDDR_DENALI_PI_289_PI_MR22_DATA_F0_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_289_PI_MR22_DATA_F0_2_SHIFT)) & LPDDR_DENALI_PI_289_PI_MR22_DATA_F0_2_MASK)

#define LPDDR_DENALI_PI_289_PI_MR1_DATA_F1_2_MASK (0xFF00U)
#define LPDDR_DENALI_PI_289_PI_MR1_DATA_F1_2_SHIFT (8U)
#define LPDDR_DENALI_PI_289_PI_MR1_DATA_F1_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_289_PI_MR1_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_289_PI_MR1_DATA_F1_2_MASK)

#define LPDDR_DENALI_PI_289_PI_MR2_DATA_F1_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_289_PI_MR2_DATA_F1_2_SHIFT (16U)
#define LPDDR_DENALI_PI_289_PI_MR2_DATA_F1_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_289_PI_MR2_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_289_PI_MR2_DATA_F1_2_MASK)

#define LPDDR_DENALI_PI_289_PI_MR3_DATA_F1_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_289_PI_MR3_DATA_F1_2_SHIFT (24U)
#define LPDDR_DENALI_PI_289_PI_MR3_DATA_F1_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_289_PI_MR3_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_289_PI_MR3_DATA_F1_2_MASK)
/*! @} */

/*! @name DENALI_PI_290 - DENALI_PI_290 */
/*! @{ */

#define LPDDR_DENALI_PI_290_PI_MR11_DATA_F1_2_MASK (0xFFU)
#define LPDDR_DENALI_PI_290_PI_MR11_DATA_F1_2_SHIFT (0U)
#define LPDDR_DENALI_PI_290_PI_MR11_DATA_F1_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_290_PI_MR11_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_290_PI_MR11_DATA_F1_2_MASK)

#define LPDDR_DENALI_PI_290_PI_MR12_DATA_F1_2_MASK (0xFF00U)
#define LPDDR_DENALI_PI_290_PI_MR12_DATA_F1_2_SHIFT (8U)
#define LPDDR_DENALI_PI_290_PI_MR12_DATA_F1_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_290_PI_MR12_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_290_PI_MR12_DATA_F1_2_MASK)

#define LPDDR_DENALI_PI_290_PI_MR14_DATA_F1_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_290_PI_MR14_DATA_F1_2_SHIFT (16U)
#define LPDDR_DENALI_PI_290_PI_MR14_DATA_F1_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_290_PI_MR14_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_290_PI_MR14_DATA_F1_2_MASK)

#define LPDDR_DENALI_PI_290_PI_MR22_DATA_F1_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_290_PI_MR22_DATA_F1_2_SHIFT (24U)
#define LPDDR_DENALI_PI_290_PI_MR22_DATA_F1_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_290_PI_MR22_DATA_F1_2_SHIFT)) & LPDDR_DENALI_PI_290_PI_MR22_DATA_F1_2_MASK)
/*! @} */

/*! @name DENALI_PI_291 - DENALI_PI_291 */
/*! @{ */

#define LPDDR_DENALI_PI_291_PI_MR1_DATA_F2_2_MASK (0xFFU)
#define LPDDR_DENALI_PI_291_PI_MR1_DATA_F2_2_SHIFT (0U)
#define LPDDR_DENALI_PI_291_PI_MR1_DATA_F2_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_291_PI_MR1_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_291_PI_MR1_DATA_F2_2_MASK)

#define LPDDR_DENALI_PI_291_PI_MR2_DATA_F2_2_MASK (0xFF00U)
#define LPDDR_DENALI_PI_291_PI_MR2_DATA_F2_2_SHIFT (8U)
#define LPDDR_DENALI_PI_291_PI_MR2_DATA_F2_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_291_PI_MR2_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_291_PI_MR2_DATA_F2_2_MASK)

#define LPDDR_DENALI_PI_291_PI_MR3_DATA_F2_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_291_PI_MR3_DATA_F2_2_SHIFT (16U)
#define LPDDR_DENALI_PI_291_PI_MR3_DATA_F2_2(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_291_PI_MR3_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_291_PI_MR3_DATA_F2_2_MASK)

#define LPDDR_DENALI_PI_291_PI_MR11_DATA_F2_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_291_PI_MR11_DATA_F2_2_SHIFT (24U)
#define LPDDR_DENALI_PI_291_PI_MR11_DATA_F2_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_291_PI_MR11_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_291_PI_MR11_DATA_F2_2_MASK)
/*! @} */

/*! @name DENALI_PI_292 - DENALI_PI_292 */
/*! @{ */

#define LPDDR_DENALI_PI_292_PI_MR12_DATA_F2_2_MASK (0xFFU)
#define LPDDR_DENALI_PI_292_PI_MR12_DATA_F2_2_SHIFT (0U)
#define LPDDR_DENALI_PI_292_PI_MR12_DATA_F2_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_292_PI_MR12_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_292_PI_MR12_DATA_F2_2_MASK)

#define LPDDR_DENALI_PI_292_PI_MR14_DATA_F2_2_MASK (0xFF00U)
#define LPDDR_DENALI_PI_292_PI_MR14_DATA_F2_2_SHIFT (8U)
#define LPDDR_DENALI_PI_292_PI_MR14_DATA_F2_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_292_PI_MR14_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_292_PI_MR14_DATA_F2_2_MASK)

#define LPDDR_DENALI_PI_292_PI_MR22_DATA_F2_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_292_PI_MR22_DATA_F2_2_SHIFT (16U)
#define LPDDR_DENALI_PI_292_PI_MR22_DATA_F2_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_292_PI_MR22_DATA_F2_2_SHIFT)) & LPDDR_DENALI_PI_292_PI_MR22_DATA_F2_2_MASK)

#define LPDDR_DENALI_PI_292_PI_MR1_DATA_F0_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_292_PI_MR1_DATA_F0_3_SHIFT (24U)
#define LPDDR_DENALI_PI_292_PI_MR1_DATA_F0_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_292_PI_MR1_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_292_PI_MR1_DATA_F0_3_MASK)
/*! @} */

/*! @name DENALI_PI_293 - DENALI_PI_293 */
/*! @{ */

#define LPDDR_DENALI_PI_293_PI_MR2_DATA_F0_3_MASK (0xFFU)
#define LPDDR_DENALI_PI_293_PI_MR2_DATA_F0_3_SHIFT (0U)
#define LPDDR_DENALI_PI_293_PI_MR2_DATA_F0_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_293_PI_MR2_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_293_PI_MR2_DATA_F0_3_MASK)

#define LPDDR_DENALI_PI_293_PI_MR3_DATA_F0_3_MASK (0xFF00U)
#define LPDDR_DENALI_PI_293_PI_MR3_DATA_F0_3_SHIFT (8U)
#define LPDDR_DENALI_PI_293_PI_MR3_DATA_F0_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_293_PI_MR3_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_293_PI_MR3_DATA_F0_3_MASK)

#define LPDDR_DENALI_PI_293_PI_MR11_DATA_F0_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_293_PI_MR11_DATA_F0_3_SHIFT (16U)
#define LPDDR_DENALI_PI_293_PI_MR11_DATA_F0_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_293_PI_MR11_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_293_PI_MR11_DATA_F0_3_MASK)

#define LPDDR_DENALI_PI_293_PI_MR12_DATA_F0_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_293_PI_MR12_DATA_F0_3_SHIFT (24U)
#define LPDDR_DENALI_PI_293_PI_MR12_DATA_F0_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_293_PI_MR12_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_293_PI_MR12_DATA_F0_3_MASK)
/*! @} */

/*! @name DENALI_PI_294 - DENALI_PI_294 */
/*! @{ */

#define LPDDR_DENALI_PI_294_PI_MR14_DATA_F0_3_MASK (0xFFU)
#define LPDDR_DENALI_PI_294_PI_MR14_DATA_F0_3_SHIFT (0U)
#define LPDDR_DENALI_PI_294_PI_MR14_DATA_F0_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_294_PI_MR14_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_294_PI_MR14_DATA_F0_3_MASK)

#define LPDDR_DENALI_PI_294_PI_MR22_DATA_F0_3_MASK (0xFF00U)
#define LPDDR_DENALI_PI_294_PI_MR22_DATA_F0_3_SHIFT (8U)
#define LPDDR_DENALI_PI_294_PI_MR22_DATA_F0_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_294_PI_MR22_DATA_F0_3_SHIFT)) & LPDDR_DENALI_PI_294_PI_MR22_DATA_F0_3_MASK)

#define LPDDR_DENALI_PI_294_PI_MR1_DATA_F1_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_294_PI_MR1_DATA_F1_3_SHIFT (16U)
#define LPDDR_DENALI_PI_294_PI_MR1_DATA_F1_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_294_PI_MR1_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_294_PI_MR1_DATA_F1_3_MASK)

#define LPDDR_DENALI_PI_294_PI_MR2_DATA_F1_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_294_PI_MR2_DATA_F1_3_SHIFT (24U)
#define LPDDR_DENALI_PI_294_PI_MR2_DATA_F1_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_294_PI_MR2_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_294_PI_MR2_DATA_F1_3_MASK)
/*! @} */

/*! @name DENALI_PI_295 - DENALI_PI_295 */
/*! @{ */

#define LPDDR_DENALI_PI_295_PI_MR3_DATA_F1_3_MASK (0xFFU)
#define LPDDR_DENALI_PI_295_PI_MR3_DATA_F1_3_SHIFT (0U)
#define LPDDR_DENALI_PI_295_PI_MR3_DATA_F1_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_295_PI_MR3_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_295_PI_MR3_DATA_F1_3_MASK)

#define LPDDR_DENALI_PI_295_PI_MR11_DATA_F1_3_MASK (0xFF00U)
#define LPDDR_DENALI_PI_295_PI_MR11_DATA_F1_3_SHIFT (8U)
#define LPDDR_DENALI_PI_295_PI_MR11_DATA_F1_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_295_PI_MR11_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_295_PI_MR11_DATA_F1_3_MASK)

#define LPDDR_DENALI_PI_295_PI_MR12_DATA_F1_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_295_PI_MR12_DATA_F1_3_SHIFT (16U)
#define LPDDR_DENALI_PI_295_PI_MR12_DATA_F1_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_295_PI_MR12_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_295_PI_MR12_DATA_F1_3_MASK)

#define LPDDR_DENALI_PI_295_PI_MR14_DATA_F1_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_295_PI_MR14_DATA_F1_3_SHIFT (24U)
#define LPDDR_DENALI_PI_295_PI_MR14_DATA_F1_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_295_PI_MR14_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_295_PI_MR14_DATA_F1_3_MASK)
/*! @} */

/*! @name DENALI_PI_296 - DENALI_PI_296 */
/*! @{ */

#define LPDDR_DENALI_PI_296_PI_MR22_DATA_F1_3_MASK (0xFFU)
#define LPDDR_DENALI_PI_296_PI_MR22_DATA_F1_3_SHIFT (0U)
#define LPDDR_DENALI_PI_296_PI_MR22_DATA_F1_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_296_PI_MR22_DATA_F1_3_SHIFT)) & LPDDR_DENALI_PI_296_PI_MR22_DATA_F1_3_MASK)

#define LPDDR_DENALI_PI_296_PI_MR1_DATA_F2_3_MASK (0xFF00U)
#define LPDDR_DENALI_PI_296_PI_MR1_DATA_F2_3_SHIFT (8U)
#define LPDDR_DENALI_PI_296_PI_MR1_DATA_F2_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_296_PI_MR1_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_296_PI_MR1_DATA_F2_3_MASK)

#define LPDDR_DENALI_PI_296_PI_MR2_DATA_F2_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_296_PI_MR2_DATA_F2_3_SHIFT (16U)
#define LPDDR_DENALI_PI_296_PI_MR2_DATA_F2_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_296_PI_MR2_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_296_PI_MR2_DATA_F2_3_MASK)

#define LPDDR_DENALI_PI_296_PI_MR3_DATA_F2_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_296_PI_MR3_DATA_F2_3_SHIFT (24U)
#define LPDDR_DENALI_PI_296_PI_MR3_DATA_F2_3(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_296_PI_MR3_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_296_PI_MR3_DATA_F2_3_MASK)
/*! @} */

/*! @name DENALI_PI_297 - DENALI_PI_297 */
/*! @{ */

#define LPDDR_DENALI_PI_297_PI_MR11_DATA_F2_3_MASK (0xFFU)
#define LPDDR_DENALI_PI_297_PI_MR11_DATA_F2_3_SHIFT (0U)
#define LPDDR_DENALI_PI_297_PI_MR11_DATA_F2_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_297_PI_MR11_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_297_PI_MR11_DATA_F2_3_MASK)

#define LPDDR_DENALI_PI_297_PI_MR12_DATA_F2_3_MASK (0xFF00U)
#define LPDDR_DENALI_PI_297_PI_MR12_DATA_F2_3_SHIFT (8U)
#define LPDDR_DENALI_PI_297_PI_MR12_DATA_F2_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_297_PI_MR12_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_297_PI_MR12_DATA_F2_3_MASK)

#define LPDDR_DENALI_PI_297_PI_MR14_DATA_F2_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PI_297_PI_MR14_DATA_F2_3_SHIFT (16U)
#define LPDDR_DENALI_PI_297_PI_MR14_DATA_F2_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_297_PI_MR14_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_297_PI_MR14_DATA_F2_3_MASK)

#define LPDDR_DENALI_PI_297_PI_MR22_DATA_F2_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PI_297_PI_MR22_DATA_F2_3_SHIFT (24U)
#define LPDDR_DENALI_PI_297_PI_MR22_DATA_F2_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PI_297_PI_MR22_DATA_F2_3_SHIFT)) & LPDDR_DENALI_PI_297_PI_MR22_DATA_F2_3_MASK)
/*! @} */

/*! @name DENALI_PHY_31 - DENALI_PHY_31 */
/*! @{ */

#define LPDDR_DENALI_PHY_31_PHY_WRLVL_UPDT_WAIT_CNT_0_MASK (0xFU)
#define LPDDR_DENALI_PHY_31_PHY_WRLVL_UPDT_WAIT_CNT_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_31_PHY_WRLVL_UPDT_WAIT_CNT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_31_PHY_WRLVL_UPDT_WAIT_CNT_0_SHIFT)) & LPDDR_DENALI_PHY_31_PHY_WRLVL_UPDT_WAIT_CNT_0_MASK)

#define LPDDR_DENALI_PHY_31_PHY_DQ_MASK_0_MASK   (0xFF00U)
#define LPDDR_DENALI_PHY_31_PHY_DQ_MASK_0_SHIFT  (8U)
#define LPDDR_DENALI_PHY_31_PHY_DQ_MASK_0(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_31_PHY_DQ_MASK_0_SHIFT)) & LPDDR_DENALI_PHY_31_PHY_DQ_MASK_0_MASK)

#define LPDDR_DENALI_PHY_31_PHY_GTLVL_CAPTURE_CNT_0_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_31_PHY_GTLVL_CAPTURE_CNT_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_31_PHY_GTLVL_CAPTURE_CNT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_31_PHY_GTLVL_CAPTURE_CNT_0_SHIFT)) & LPDDR_DENALI_PHY_31_PHY_GTLVL_CAPTURE_CNT_0_MASK)

#define LPDDR_DENALI_PHY_31_PHY_GTLVL_UPDT_WAIT_CNT_0_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_31_PHY_GTLVL_UPDT_WAIT_CNT_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_31_PHY_GTLVL_UPDT_WAIT_CNT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_31_PHY_GTLVL_UPDT_WAIT_CNT_0_SHIFT)) & LPDDR_DENALI_PHY_31_PHY_GTLVL_UPDT_WAIT_CNT_0_MASK)
/*! @} */

/*! @name DENALI_PHY_33 - DENALI_PHY_33 */
/*! @{ */

#define LPDDR_DENALI_PHY_33_PHY_RDLVL_DATA_MASK_0_MASK (0xFFU)
#define LPDDR_DENALI_PHY_33_PHY_RDLVL_DATA_MASK_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_33_PHY_RDLVL_DATA_MASK_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_33_PHY_RDLVL_DATA_MASK_0_SHIFT)) & LPDDR_DENALI_PHY_33_PHY_RDLVL_DATA_MASK_0_MASK)

#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_CLK_JITTER_TOLERANCE_0_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_CLK_JITTER_TOLERANCE_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_CLK_JITTER_TOLERANCE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_33_PHY_WDQLVL_CLK_JITTER_TOLERANCE_0_SHIFT)) & LPDDR_DENALI_PHY_33_PHY_WDQLVL_CLK_JITTER_TOLERANCE_0_MASK)

#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_BURST_CNT_0_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_BURST_CNT_0_SHIFT (16U)
/*! PHY_WDQLVL_BURST_CNT_0 - Defines the write/read burst length in bytes during the write data leveling sequence for slice 0. */
#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_BURST_CNT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_33_PHY_WDQLVL_BURST_CNT_0_SHIFT)) & LPDDR_DENALI_PHY_33_PHY_WDQLVL_BURST_CNT_0_MASK)

#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_PATT_0_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_PATT_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_33_PHY_WDQLVL_PATT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_33_PHY_WDQLVL_PATT_0_SHIFT)) & LPDDR_DENALI_PHY_33_PHY_WDQLVL_PATT_0_MASK)
/*! @} */

/*! @name DENALI_PHY_43 - DENALI_PHY_43 */
/*! @{ */

#define LPDDR_DENALI_PHY_43_PHY_CALVL_VREF_DRIVING_SLICE_0_MASK (0x1U)
#define LPDDR_DENALI_PHY_43_PHY_CALVL_VREF_DRIVING_SLICE_0_SHIFT (0U)
/*! PHY_CALVL_VREF_DRIVING_SLICE_0 - Indicates if slice 0 is used to drive the VREF value to the device during CA training. */
#define LPDDR_DENALI_PHY_43_PHY_CALVL_VREF_DRIVING_SLICE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_43_PHY_CALVL_VREF_DRIVING_SLICE_0_SHIFT)) & LPDDR_DENALI_PHY_43_PHY_CALVL_VREF_DRIVING_SLICE_0_MASK)

#define LPDDR_DENALI_PHY_43_SC_PHY_MANUAL_CLEAR_0_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_43_SC_PHY_MANUAL_CLEAR_0_SHIFT (8U)
/*! SC_PHY_MANUAL_CLEAR_0 - Manual reset/clear of internal logic for slice 0. */
#define LPDDR_DENALI_PHY_43_SC_PHY_MANUAL_CLEAR_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_43_SC_PHY_MANUAL_CLEAR_0_SHIFT)) & LPDDR_DENALI_PHY_43_SC_PHY_MANUAL_CLEAR_0_MASK)

#define LPDDR_DENALI_PHY_43_PHY_FIFO_PTR_OBS_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_43_PHY_FIFO_PTR_OBS_0_SHIFT (16U)
/*! PHY_FIFO_PTR_OBS_0 - Observation register containing read entry FIFO pointers for slice 0. */
#define LPDDR_DENALI_PHY_43_PHY_FIFO_PTR_OBS_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_43_PHY_FIFO_PTR_OBS_0_SHIFT)) & LPDDR_DENALI_PHY_43_PHY_FIFO_PTR_OBS_0_MASK)
/*! @} */

/*! @name DENALI_PHY_72 - DENALI_PHY_72 */
/*! @{ */

#define LPDDR_DENALI_PHY_72_PHY_SLV_DLY_CTRL_GATE_DISABLE_0_MASK (0x1U)
#define LPDDR_DENALI_PHY_72_PHY_SLV_DLY_CTRL_GATE_DISABLE_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_72_PHY_SLV_DLY_CTRL_GATE_DISABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_72_PHY_SLV_DLY_CTRL_GATE_DISABLE_0_SHIFT)) & LPDDR_DENALI_PHY_72_PHY_SLV_DLY_CTRL_GATE_DISABLE_0_MASK)

#define LPDDR_DENALI_PHY_72_PHY_RDPATH_GATE_DISABLE_0_MASK (0x100U)
#define LPDDR_DENALI_PHY_72_PHY_RDPATH_GATE_DISABLE_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_72_PHY_RDPATH_GATE_DISABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_72_PHY_RDPATH_GATE_DISABLE_0_SHIFT)) & LPDDR_DENALI_PHY_72_PHY_RDPATH_GATE_DISABLE_0_MASK)

#define LPDDR_DENALI_PHY_72_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_0_MASK (0x10000U)
#define LPDDR_DENALI_PHY_72_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_72_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_72_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_0_SHIFT)) & LPDDR_DENALI_PHY_72_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_0_MASK)

#define LPDDR_DENALI_PHY_72_PHY_SLICE_PWR_RDC_DISABLE_0_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_72_PHY_SLICE_PWR_RDC_DISABLE_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_72_PHY_SLICE_PWR_RDC_DISABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_72_PHY_SLICE_PWR_RDC_DISABLE_0_SHIFT)) & LPDDR_DENALI_PHY_72_PHY_SLICE_PWR_RDC_DISABLE_0_MASK)
/*! @} */

/*! @name DENALI_PHY_73 - DENALI_PHY_73 */
/*! @{ */

#define LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_ENABLE_0_MASK (0x7U)
#define LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_ENABLE_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_ENABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_ENABLE_0_SHIFT)) & LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_ENABLE_0_MASK)

#define LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_SELECT_0_MASK (0xFFFF00U)
#define LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_SELECT_0_SHIFT (8U)
/*! PHY_DQ_TSEL_SELECT_0 - Operation type tsel select values for DQ/DM signals for slice 0. */
#define LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_SELECT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_SELECT_0_SHIFT)) & LPDDR_DENALI_PHY_73_PHY_DQ_TSEL_SELECT_0_MASK)

#define LPDDR_DENALI_PHY_73_PHY_DQS_TSEL_ENABLE_0_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_73_PHY_DQS_TSEL_ENABLE_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_73_PHY_DQS_TSEL_ENABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_73_PHY_DQS_TSEL_ENABLE_0_SHIFT)) & LPDDR_DENALI_PHY_73_PHY_DQS_TSEL_ENABLE_0_MASK)
/*! @} */

/*! @name DENALI_PHY_74 - DENALI_PHY_74 */
/*! @{ */

#define LPDDR_DENALI_PHY_74_PHY_DQS_TSEL_SELECT_0_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_74_PHY_DQS_TSEL_SELECT_0_SHIFT (0U)
/*! PHY_DQS_TSEL_SELECT_0 - Operation type tsel select values for DQS signals for slice 0. */
#define LPDDR_DENALI_PHY_74_PHY_DQS_TSEL_SELECT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_74_PHY_DQS_TSEL_SELECT_0_SHIFT)) & LPDDR_DENALI_PHY_74_PHY_DQS_TSEL_SELECT_0_MASK)

#define LPDDR_DENALI_PHY_74_PHY_TWO_CYC_PREAMBLE_0_MASK (0x30000U)
#define LPDDR_DENALI_PHY_74_PHY_TWO_CYC_PREAMBLE_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_74_PHY_TWO_CYC_PREAMBLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_74_PHY_TWO_CYC_PREAMBLE_0_SHIFT)) & LPDDR_DENALI_PHY_74_PHY_TWO_CYC_PREAMBLE_0_MASK)

#define LPDDR_DENALI_PHY_74_PHY_VREF_INITIAL_START_POINT_0_MASK (0x7F000000U)
#define LPDDR_DENALI_PHY_74_PHY_VREF_INITIAL_START_POINT_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_74_PHY_VREF_INITIAL_START_POINT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_74_PHY_VREF_INITIAL_START_POINT_0_SHIFT)) & LPDDR_DENALI_PHY_74_PHY_VREF_INITIAL_START_POINT_0_MASK)
/*! @} */

/*! @name DENALI_PHY_75 - DENALI_PHY_75 */
/*! @{ */

#define LPDDR_DENALI_PHY_75_PHY_VREF_INITIAL_STOP_POINT_0_MASK (0x7FU)
#define LPDDR_DENALI_PHY_75_PHY_VREF_INITIAL_STOP_POINT_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_75_PHY_VREF_INITIAL_STOP_POINT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_75_PHY_VREF_INITIAL_STOP_POINT_0_SHIFT)) & LPDDR_DENALI_PHY_75_PHY_VREF_INITIAL_STOP_POINT_0_MASK)

#define LPDDR_DENALI_PHY_75_PHY_VREF_TRAINING_CTRL_0_MASK (0x300U)
#define LPDDR_DENALI_PHY_75_PHY_VREF_TRAINING_CTRL_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_75_PHY_VREF_TRAINING_CTRL_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_75_PHY_VREF_TRAINING_CTRL_0_SHIFT)) & LPDDR_DENALI_PHY_75_PHY_VREF_TRAINING_CTRL_0_MASK)

#define LPDDR_DENALI_PHY_75_PHY_NTP_TRAIN_EN_0_MASK (0x10000U)
#define LPDDR_DENALI_PHY_75_PHY_NTP_TRAIN_EN_0_SHIFT (16U)
/*! PHY_NTP_TRAIN_EN_0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PHY_75_PHY_NTP_TRAIN_EN_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_75_PHY_NTP_TRAIN_EN_0_SHIFT)) & LPDDR_DENALI_PHY_75_PHY_NTP_TRAIN_EN_0_MASK)

#define LPDDR_DENALI_PHY_75_PHY_NTP_WDQ_STEP_SIZE_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_75_PHY_NTP_WDQ_STEP_SIZE_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_75_PHY_NTP_WDQ_STEP_SIZE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_75_PHY_NTP_WDQ_STEP_SIZE_0_SHIFT)) & LPDDR_DENALI_PHY_75_PHY_NTP_WDQ_STEP_SIZE_0_MASK)
/*! @} */

/*! @name DENALI_PHY_80 - DENALI_PHY_80 */
/*! @{ */

#define LPDDR_DENALI_PHY_80_PHY_PAD_DQS_RX_DCD_0_MASK (0x1FU)
#define LPDDR_DENALI_PHY_80_PHY_PAD_DQS_RX_DCD_0_SHIFT (0U)
/*! PHY_PAD_DQS_RX_DCD_0 - Controls RX_DCD pin for DQS pad for slice 0. */
#define LPDDR_DENALI_PHY_80_PHY_PAD_DQS_RX_DCD_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_80_PHY_PAD_DQS_RX_DCD_0_SHIFT)) & LPDDR_DENALI_PHY_80_PHY_PAD_DQS_RX_DCD_0_MASK)

#define LPDDR_DENALI_PHY_80_PHY_PAD_FDBK_RX_DCD_0_MASK (0x1F00U)
#define LPDDR_DENALI_PHY_80_PHY_PAD_FDBK_RX_DCD_0_SHIFT (8U)
/*! PHY_PAD_FDBK_RX_DCD_0 - Controls RX_DCD pin for FDBK pad for slice 0. */
#define LPDDR_DENALI_PHY_80_PHY_PAD_FDBK_RX_DCD_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_80_PHY_PAD_FDBK_RX_DCD_0_SHIFT)) & LPDDR_DENALI_PHY_80_PHY_PAD_FDBK_RX_DCD_0_MASK)

#define LPDDR_DENALI_PHY_80_PHY_PAD_DSLICE_IO_CFG_0_MASK (0x7F0000U)
#define LPDDR_DENALI_PHY_80_PHY_PAD_DSLICE_IO_CFG_0_SHIFT (16U)
/*! PHY_PAD_DSLICE_IO_CFG_0 - Controls PCLK/PARK pin for IO pad for slice 0. */
#define LPDDR_DENALI_PHY_80_PHY_PAD_DSLICE_IO_CFG_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_80_PHY_PAD_DSLICE_IO_CFG_0_SHIFT)) & LPDDR_DENALI_PHY_80_PHY_PAD_DSLICE_IO_CFG_0_MASK)
/*! @} */

/*! @name DENALI_PHY_88 - DENALI_PHY_88 */
/*! @{ */

#define LPDDR_DENALI_PHY_88_PHY_VREF_SETTING_TIME_0_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_88_PHY_VREF_SETTING_TIME_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_88_PHY_VREF_SETTING_TIME_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_88_PHY_VREF_SETTING_TIME_0_SHIFT)) & LPDDR_DENALI_PHY_88_PHY_VREF_SETTING_TIME_0_MASK)

#define LPDDR_DENALI_PHY_88_PHY_PAD_VREF_CTRL_DQ_0_MASK (0xFFF0000U)
#define LPDDR_DENALI_PHY_88_PHY_PAD_VREF_CTRL_DQ_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_88_PHY_PAD_VREF_CTRL_DQ_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_88_PHY_PAD_VREF_CTRL_DQ_0_SHIFT)) & LPDDR_DENALI_PHY_88_PHY_PAD_VREF_CTRL_DQ_0_MASK)
/*! @} */

/*! @name DENALI_PHY_89 - DENALI_PHY_89 */
/*! @{ */

#define LPDDR_DENALI_PHY_89_PHY_PER_CS_TRAINING_EN_0_MASK (0x1U)
#define LPDDR_DENALI_PHY_89_PHY_PER_CS_TRAINING_EN_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_89_PHY_PER_CS_TRAINING_EN_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_89_PHY_PER_CS_TRAINING_EN_0_SHIFT)) & LPDDR_DENALI_PHY_89_PHY_PER_CS_TRAINING_EN_0_MASK)

#define LPDDR_DENALI_PHY_89_PHY_DQ_IE_TIMING_0_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_89_PHY_DQ_IE_TIMING_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_89_PHY_DQ_IE_TIMING_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_89_PHY_DQ_IE_TIMING_0_SHIFT)) & LPDDR_DENALI_PHY_89_PHY_DQ_IE_TIMING_0_MASK)

#define LPDDR_DENALI_PHY_89_PHY_DQS_IE_TIMING_0_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_89_PHY_DQS_IE_TIMING_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_89_PHY_DQS_IE_TIMING_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_89_PHY_DQS_IE_TIMING_0_SHIFT)) & LPDDR_DENALI_PHY_89_PHY_DQS_IE_TIMING_0_MASK)

#define LPDDR_DENALI_PHY_89_PHY_RDDATA_EN_IE_DLY_0_MASK (0x3000000U)
#define LPDDR_DENALI_PHY_89_PHY_RDDATA_EN_IE_DLY_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_89_PHY_RDDATA_EN_IE_DLY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_89_PHY_RDDATA_EN_IE_DLY_0_SHIFT)) & LPDDR_DENALI_PHY_89_PHY_RDDATA_EN_IE_DLY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_90 - DENALI_PHY_90 */
/*! @{ */

#define LPDDR_DENALI_PHY_90_PHY_IE_MODE_0_MASK   (0x3U)
#define LPDDR_DENALI_PHY_90_PHY_IE_MODE_0_SHIFT  (0U)
#define LPDDR_DENALI_PHY_90_PHY_IE_MODE_0(x)     (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_90_PHY_IE_MODE_0_SHIFT)) & LPDDR_DENALI_PHY_90_PHY_IE_MODE_0_MASK)

#define LPDDR_DENALI_PHY_90_PHY_DBI_MODE_0_MASK  (0x100U)
#define LPDDR_DENALI_PHY_90_PHY_DBI_MODE_0_SHIFT (8U)
/*! PHY_DBI_MODE_0
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_PHY_90_PHY_DBI_MODE_0(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_90_PHY_DBI_MODE_0_SHIFT)) & LPDDR_DENALI_PHY_90_PHY_DBI_MODE_0_MASK)

#define LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_TSEL_DLY_0_MASK (0x1F0000U)
#define LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_TSEL_DLY_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_TSEL_DLY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_TSEL_DLY_0_SHIFT)) & LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_TSEL_DLY_0_MASK)

#define LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_OE_DLY_0_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_OE_DLY_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_OE_DLY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_OE_DLY_0_SHIFT)) & LPDDR_DENALI_PHY_90_PHY_RDDATA_EN_OE_DLY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_92 - DENALI_PHY_92 */
/*! @{ */

#define LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_WAIT_0_MASK (0xFFU)
#define LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_WAIT_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_WAIT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_WAIT_0_SHIFT)) & LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_WAIT_0_MASK)

#define LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_HALF_MEASURE_0_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_HALF_MEASURE_0_SHIFT (8U)
/*! PHY_MASTER_DELAY_HALF_MEASURE_0 - Defines the number of delay line elements to be considered in
 *    determing whether to lock to a half clock cycle in the data slice master for slice 0.
 */
#define LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_HALF_MEASURE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_HALF_MEASURE_0_SHIFT)) & LPDDR_DENALI_PHY_92_PHY_MASTER_DELAY_HALF_MEASURE_0_MASK)

#define LPDDR_DENALI_PHY_92_PHY_RPTR_UPDATE_0_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_92_PHY_RPTR_UPDATE_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_92_PHY_RPTR_UPDATE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_92_PHY_RPTR_UPDATE_0_SHIFT)) & LPDDR_DENALI_PHY_92_PHY_RPTR_UPDATE_0_MASK)

#define LPDDR_DENALI_PHY_92_PHY_WRLVL_DLY_STEP_0_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_92_PHY_WRLVL_DLY_STEP_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_92_PHY_WRLVL_DLY_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_92_PHY_WRLVL_DLY_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_92_PHY_WRLVL_DLY_STEP_0_MASK)
/*! @} */

/*! @name DENALI_PHY_93 - DENALI_PHY_93 */
/*! @{ */

#define LPDDR_DENALI_PHY_93_PHY_WRLVL_DLY_FINE_STEP_0_MASK (0xFU)
#define LPDDR_DENALI_PHY_93_PHY_WRLVL_DLY_FINE_STEP_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_93_PHY_WRLVL_DLY_FINE_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_93_PHY_WRLVL_DLY_FINE_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_93_PHY_WRLVL_DLY_FINE_STEP_0_MASK)

#define LPDDR_DENALI_PHY_93_PHY_WRLVL_RESP_WAIT_CNT_0_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_93_PHY_WRLVL_RESP_WAIT_CNT_0_SHIFT (8U)
/*! PHY_WRLVL_RESP_WAIT_CNT_0 - Defines the number of cycles to wait between dfi_wrlvl_strobe and
 *    the sampling of the DQs during write leveling for slice 0.
 */
#define LPDDR_DENALI_PHY_93_PHY_WRLVL_RESP_WAIT_CNT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_93_PHY_WRLVL_RESP_WAIT_CNT_0_SHIFT)) & LPDDR_DENALI_PHY_93_PHY_WRLVL_RESP_WAIT_CNT_0_MASK)

#define LPDDR_DENALI_PHY_93_PHY_GTLVL_DLY_STEP_0_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_93_PHY_GTLVL_DLY_STEP_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_93_PHY_GTLVL_DLY_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_93_PHY_GTLVL_DLY_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_93_PHY_GTLVL_DLY_STEP_0_MASK)

#define LPDDR_DENALI_PHY_93_PHY_GTLVL_RESP_WAIT_CNT_0_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_93_PHY_GTLVL_RESP_WAIT_CNT_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_93_PHY_GTLVL_RESP_WAIT_CNT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_93_PHY_GTLVL_RESP_WAIT_CNT_0_SHIFT)) & LPDDR_DENALI_PHY_93_PHY_GTLVL_RESP_WAIT_CNT_0_MASK)
/*! @} */

/*! @name DENALI_PHY_95 - DENALI_PHY_95 */
/*! @{ */

#define LPDDR_DENALI_PHY_95_PHY_WDQLVL_DLY_STEP_0_MASK (0xFFU)
#define LPDDR_DENALI_PHY_95_PHY_WDQLVL_DLY_STEP_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_95_PHY_WDQLVL_DLY_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_95_PHY_WDQLVL_DLY_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_95_PHY_WDQLVL_DLY_STEP_0_MASK)

#define LPDDR_DENALI_PHY_95_PHY_WDQLVL_QTR_DLY_STEP_0_MASK (0xF00U)
#define LPDDR_DENALI_PHY_95_PHY_WDQLVL_QTR_DLY_STEP_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_95_PHY_WDQLVL_QTR_DLY_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_95_PHY_WDQLVL_QTR_DLY_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_95_PHY_WDQLVL_QTR_DLY_STEP_0_MASK)

#define LPDDR_DENALI_PHY_95_PHY_TOGGLE_PRE_SUPPORT_0_MASK (0x10000U)
#define LPDDR_DENALI_PHY_95_PHY_TOGGLE_PRE_SUPPORT_0_SHIFT (16U)
/*! PHY_TOGGLE_PRE_SUPPORT_0 - Support the toggle read preamble for LPDDR4 for slice 0.
 *  0b0..Static read preamble
 *  0b1..Toggling read preamble
 */
#define LPDDR_DENALI_PHY_95_PHY_TOGGLE_PRE_SUPPORT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_95_PHY_TOGGLE_PRE_SUPPORT_0_SHIFT)) & LPDDR_DENALI_PHY_95_PHY_TOGGLE_PRE_SUPPORT_0_MASK)

#define LPDDR_DENALI_PHY_95_PHY_RDLVL_DLY_STEP_0_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_95_PHY_RDLVL_DLY_STEP_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_95_PHY_RDLVL_DLY_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_95_PHY_RDLVL_DLY_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_95_PHY_RDLVL_DLY_STEP_0_MASK)
/*! @} */

/*! @name DENALI_PHY_96 - DENALI_PHY_96 */
/*! @{ */

#define LPDDR_DENALI_PHY_96_PHY_RDLVL_MAX_EDGE_0_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_96_PHY_RDLVL_MAX_EDGE_0_SHIFT (0U)
/*! PHY_RDLVL_MAX_EDGE_0 - Provides the maximun rdlvl slave delay search window for read eye training for slice 0. */
#define LPDDR_DENALI_PHY_96_PHY_RDLVL_MAX_EDGE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_96_PHY_RDLVL_MAX_EDGE_0_SHIFT)) & LPDDR_DENALI_PHY_96_PHY_RDLVL_MAX_EDGE_0_MASK)
/*! @} */

/*! @name DENALI_PHY_97 - DENALI_PHY_97 */
/*! @{ */

#define LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_DISABLE_0_MASK (0x3U)
#define LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_DISABLE_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_DISABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_DISABLE_0_SHIFT)) & LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_DISABLE_0_MASK)

#define LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_TIMING_0_MASK (0x700U)
#define LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_TIMING_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_TIMING_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_TIMING_0_SHIFT)) & LPDDR_DENALI_PHY_97_PHY_WRPATH_GATE_TIMING_0_MASK)

#define LPDDR_DENALI_PHY_97_PHY_MEAS_DLY_STEP_ENABLE_0_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_97_PHY_MEAS_DLY_STEP_ENABLE_0_SHIFT (16U)
/*! PHY_MEAS_DLY_STEP_ENABLE_0 - Data slice training step definition using phy_meas_dly_step_value for slice 0. */
#define LPDDR_DENALI_PHY_97_PHY_MEAS_DLY_STEP_ENABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_97_PHY_MEAS_DLY_STEP_ENABLE_0_SHIFT)) & LPDDR_DENALI_PHY_97_PHY_MEAS_DLY_STEP_ENABLE_0_MASK)

#define LPDDR_DENALI_PHY_97_PHY_RDDATA_EN_DLY_0_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_97_PHY_RDDATA_EN_DLY_0_SHIFT (24U)
#define LPDDR_DENALI_PHY_97_PHY_RDDATA_EN_DLY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_97_PHY_RDDATA_EN_DLY_0_SHIFT)) & LPDDR_DENALI_PHY_97_PHY_RDDATA_EN_DLY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_98 - DENALI_PHY_98 */
/*! @{ */

#define LPDDR_DENALI_PHY_98_PHY_DQ_DM_SWIZZLE0_0_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_98_PHY_DQ_DM_SWIZZLE0_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_98_PHY_DQ_DM_SWIZZLE0_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_98_PHY_DQ_DM_SWIZZLE0_0_SHIFT)) & LPDDR_DENALI_PHY_98_PHY_DQ_DM_SWIZZLE0_0_MASK)
/*! @} */

/*! @name DENALI_PHY_100 - DENALI_PHY_100 */
/*! @{ */

#define LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ0_SLAVE_DELAY_0_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ0_SLAVE_DELAY_0_SHIFT (0U)
/*! PHY_CLK_WRDQ0_SLAVE_DELAY_0 - Write clock slave delay setting for DQ0 for slice 0. */
#define LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ0_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ0_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ0_SLAVE_DELAY_0_MASK)

#define LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ1_SLAVE_DELAY_0_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ1_SLAVE_DELAY_0_SHIFT (16U)
#define LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ1_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ1_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_100_PHY_CLK_WRDQ1_SLAVE_DELAY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_101 - DENALI_PHY_101 */
/*! @{ */

#define LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ2_SLAVE_DELAY_0_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ2_SLAVE_DELAY_0_SHIFT (0U)
/*! PHY_CLK_WRDQ2_SLAVE_DELAY_0 - Write clock slave delay setting for DQ2 for slice 0. */
#define LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ2_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ2_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ2_SLAVE_DELAY_0_MASK)

#define LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ3_SLAVE_DELAY_0_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ3_SLAVE_DELAY_0_SHIFT (16U)
/*! PHY_CLK_WRDQ3_SLAVE_DELAY_0 - Write clock slave delay setting for DQ3 for slice 0. */
#define LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ3_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ3_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_101_PHY_CLK_WRDQ3_SLAVE_DELAY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_102 - DENALI_PHY_102 */
/*! @{ */

#define LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ4_SLAVE_DELAY_0_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ4_SLAVE_DELAY_0_SHIFT (0U)
/*! PHY_CLK_WRDQ4_SLAVE_DELAY_0 - Write clock slave delay setting for DQ4 for slice 0. */
#define LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ4_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ4_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ4_SLAVE_DELAY_0_MASK)

#define LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ5_SLAVE_DELAY_0_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ5_SLAVE_DELAY_0_SHIFT (16U)
/*! PHY_CLK_WRDQ5_SLAVE_DELAY_0 - Write clock slave delay setting for DQ5 for slice 0. */
#define LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ5_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ5_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_102_PHY_CLK_WRDQ5_SLAVE_DELAY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_103 - DENALI_PHY_103 */
/*! @{ */

#define LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ6_SLAVE_DELAY_0_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ6_SLAVE_DELAY_0_SHIFT (0U)
/*! PHY_CLK_WRDQ6_SLAVE_DELAY_0 - Write clock slave delay setting for DQ6 for slice 0. */
#define LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ6_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ6_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ6_SLAVE_DELAY_0_MASK)

#define LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ7_SLAVE_DELAY_0_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ7_SLAVE_DELAY_0_SHIFT (16U)
/*! PHY_CLK_WRDQ7_SLAVE_DELAY_0 - Write clock slave delay setting for DQ7 for slice 0. */
#define LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ7_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ7_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_103_PHY_CLK_WRDQ7_SLAVE_DELAY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_104 - DENALI_PHY_104 */
/*! @{ */

#define LPDDR_DENALI_PHY_104_PHY_CLK_WRDM_SLAVE_DELAY_0_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_104_PHY_CLK_WRDM_SLAVE_DELAY_0_SHIFT (0U)
/*! PHY_CLK_WRDM_SLAVE_DELAY_0 - Write clock slave delay setting for DM for slice 0. */
#define LPDDR_DENALI_PHY_104_PHY_CLK_WRDM_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_104_PHY_CLK_WRDM_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_104_PHY_CLK_WRDM_SLAVE_DELAY_0_MASK)

#define LPDDR_DENALI_PHY_104_PHY_CLK_WRDQS_SLAVE_DELAY_0_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_104_PHY_CLK_WRDQS_SLAVE_DELAY_0_SHIFT (16U)
/*! PHY_CLK_WRDQS_SLAVE_DELAY_0 - Write clock slave delay setting for DQS for slice 0. */
#define LPDDR_DENALI_PHY_104_PHY_CLK_WRDQS_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_104_PHY_CLK_WRDQS_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_104_PHY_CLK_WRDQS_SLAVE_DELAY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_114 - DENALI_PHY_114 */
/*! @{ */

#define LPDDR_DENALI_PHY_114_PHY_RDDQS_DM_FALL_SLAVE_DELAY_0_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_114_PHY_RDDQS_DM_FALL_SLAVE_DELAY_0_SHIFT (0U)
/*! PHY_RDDQS_DM_FALL_SLAVE_DELAY_0 - Falling edge read DQS slave delay setting for DM for slice 0. */
#define LPDDR_DENALI_PHY_114_PHY_RDDQS_DM_FALL_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_114_PHY_RDDQS_DM_FALL_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_114_PHY_RDDQS_DM_FALL_SLAVE_DELAY_0_MASK)

#define LPDDR_DENALI_PHY_114_PHY_RDDQS_GATE_SLAVE_DELAY_0_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_114_PHY_RDDQS_GATE_SLAVE_DELAY_0_SHIFT (16U)
/*! PHY_RDDQS_GATE_SLAVE_DELAY_0 - Read DQS slave delay setting for slice 0. */
#define LPDDR_DENALI_PHY_114_PHY_RDDQS_GATE_SLAVE_DELAY_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_114_PHY_RDDQS_GATE_SLAVE_DELAY_0_SHIFT)) & LPDDR_DENALI_PHY_114_PHY_RDDQS_GATE_SLAVE_DELAY_0_MASK)
/*! @} */

/*! @name DENALI_PHY_287 - DENALI_PHY_287 */
/*! @{ */

#define LPDDR_DENALI_PHY_287_PHY_WRLVL_UPDT_WAIT_CNT_1_MASK (0xFU)
#define LPDDR_DENALI_PHY_287_PHY_WRLVL_UPDT_WAIT_CNT_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_287_PHY_WRLVL_UPDT_WAIT_CNT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_287_PHY_WRLVL_UPDT_WAIT_CNT_1_SHIFT)) & LPDDR_DENALI_PHY_287_PHY_WRLVL_UPDT_WAIT_CNT_1_MASK)

#define LPDDR_DENALI_PHY_287_PHY_DQ_MASK_1_MASK  (0xFF00U)
#define LPDDR_DENALI_PHY_287_PHY_DQ_MASK_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_287_PHY_DQ_MASK_1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_287_PHY_DQ_MASK_1_SHIFT)) & LPDDR_DENALI_PHY_287_PHY_DQ_MASK_1_MASK)

#define LPDDR_DENALI_PHY_287_PHY_GTLVL_CAPTURE_CNT_1_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_287_PHY_GTLVL_CAPTURE_CNT_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_287_PHY_GTLVL_CAPTURE_CNT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_287_PHY_GTLVL_CAPTURE_CNT_1_SHIFT)) & LPDDR_DENALI_PHY_287_PHY_GTLVL_CAPTURE_CNT_1_MASK)

#define LPDDR_DENALI_PHY_287_PHY_GTLVL_UPDT_WAIT_CNT_1_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_287_PHY_GTLVL_UPDT_WAIT_CNT_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_287_PHY_GTLVL_UPDT_WAIT_CNT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_287_PHY_GTLVL_UPDT_WAIT_CNT_1_SHIFT)) & LPDDR_DENALI_PHY_287_PHY_GTLVL_UPDT_WAIT_CNT_1_MASK)
/*! @} */

/*! @name DENALI_PHY_289 - DENALI_PHY_289 */
/*! @{ */

#define LPDDR_DENALI_PHY_289_PHY_RDLVL_DATA_MASK_1_MASK (0xFFU)
#define LPDDR_DENALI_PHY_289_PHY_RDLVL_DATA_MASK_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_289_PHY_RDLVL_DATA_MASK_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_289_PHY_RDLVL_DATA_MASK_1_SHIFT)) & LPDDR_DENALI_PHY_289_PHY_RDLVL_DATA_MASK_1_MASK)

#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_CLK_JITTER_TOLERANCE_1_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_CLK_JITTER_TOLERANCE_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_CLK_JITTER_TOLERANCE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_289_PHY_WDQLVL_CLK_JITTER_TOLERANCE_1_SHIFT)) & LPDDR_DENALI_PHY_289_PHY_WDQLVL_CLK_JITTER_TOLERANCE_1_MASK)

#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_BURST_CNT_1_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_BURST_CNT_1_SHIFT (16U)
/*! PHY_WDQLVL_BURST_CNT_1 - Defines the write/read burst length in bytes during the write data leveling sequence for slice 1. */
#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_BURST_CNT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_289_PHY_WDQLVL_BURST_CNT_1_SHIFT)) & LPDDR_DENALI_PHY_289_PHY_WDQLVL_BURST_CNT_1_MASK)

#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_PATT_1_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_PATT_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_289_PHY_WDQLVL_PATT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_289_PHY_WDQLVL_PATT_1_SHIFT)) & LPDDR_DENALI_PHY_289_PHY_WDQLVL_PATT_1_MASK)
/*! @} */

/*! @name DENALI_PHY_299 - DENALI_PHY_299 */
/*! @{ */

#define LPDDR_DENALI_PHY_299_PHY_CALVL_VREF_DRIVING_SLICE_1_MASK (0x1U)
#define LPDDR_DENALI_PHY_299_PHY_CALVL_VREF_DRIVING_SLICE_1_SHIFT (0U)
/*! PHY_CALVL_VREF_DRIVING_SLICE_1 - Indicates if slice 1 is used to drive the VREF value to the device during CA training. */
#define LPDDR_DENALI_PHY_299_PHY_CALVL_VREF_DRIVING_SLICE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_299_PHY_CALVL_VREF_DRIVING_SLICE_1_SHIFT)) & LPDDR_DENALI_PHY_299_PHY_CALVL_VREF_DRIVING_SLICE_1_MASK)

#define LPDDR_DENALI_PHY_299_SC_PHY_MANUAL_CLEAR_1_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_299_SC_PHY_MANUAL_CLEAR_1_SHIFT (8U)
/*! SC_PHY_MANUAL_CLEAR_1 - Manual reset/clear of internal logic for slice 1. */
#define LPDDR_DENALI_PHY_299_SC_PHY_MANUAL_CLEAR_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_299_SC_PHY_MANUAL_CLEAR_1_SHIFT)) & LPDDR_DENALI_PHY_299_SC_PHY_MANUAL_CLEAR_1_MASK)

#define LPDDR_DENALI_PHY_299_PHY_FIFO_PTR_OBS_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_299_PHY_FIFO_PTR_OBS_1_SHIFT (16U)
/*! PHY_FIFO_PTR_OBS_1 - Observation register containing read entry FIFO pointers for slice 1. */
#define LPDDR_DENALI_PHY_299_PHY_FIFO_PTR_OBS_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_299_PHY_FIFO_PTR_OBS_1_SHIFT)) & LPDDR_DENALI_PHY_299_PHY_FIFO_PTR_OBS_1_MASK)
/*! @} */

/*! @name DENALI_PHY_328 - DENALI_PHY_328 */
/*! @{ */

#define LPDDR_DENALI_PHY_328_PHY_SLV_DLY_CTRL_GATE_DISABLE_1_MASK (0x1U)
#define LPDDR_DENALI_PHY_328_PHY_SLV_DLY_CTRL_GATE_DISABLE_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_328_PHY_SLV_DLY_CTRL_GATE_DISABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_328_PHY_SLV_DLY_CTRL_GATE_DISABLE_1_SHIFT)) & LPDDR_DENALI_PHY_328_PHY_SLV_DLY_CTRL_GATE_DISABLE_1_MASK)

#define LPDDR_DENALI_PHY_328_PHY_RDPATH_GATE_DISABLE_1_MASK (0x100U)
#define LPDDR_DENALI_PHY_328_PHY_RDPATH_GATE_DISABLE_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_328_PHY_RDPATH_GATE_DISABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_328_PHY_RDPATH_GATE_DISABLE_1_SHIFT)) & LPDDR_DENALI_PHY_328_PHY_RDPATH_GATE_DISABLE_1_MASK)

#define LPDDR_DENALI_PHY_328_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_1_MASK (0x10000U)
#define LPDDR_DENALI_PHY_328_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_328_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_328_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_1_SHIFT)) & LPDDR_DENALI_PHY_328_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_1_MASK)

#define LPDDR_DENALI_PHY_328_PHY_SLICE_PWR_RDC_DISABLE_1_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_328_PHY_SLICE_PWR_RDC_DISABLE_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_328_PHY_SLICE_PWR_RDC_DISABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_328_PHY_SLICE_PWR_RDC_DISABLE_1_SHIFT)) & LPDDR_DENALI_PHY_328_PHY_SLICE_PWR_RDC_DISABLE_1_MASK)
/*! @} */

/*! @name DENALI_PHY_329 - DENALI_PHY_329 */
/*! @{ */

#define LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_ENABLE_1_MASK (0x7U)
#define LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_ENABLE_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_ENABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_ENABLE_1_SHIFT)) & LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_ENABLE_1_MASK)

#define LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_SELECT_1_MASK (0xFFFF00U)
#define LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_SELECT_1_SHIFT (8U)
/*! PHY_DQ_TSEL_SELECT_1 - Operation type tsel select values for DQ/DM signals for slice 1. */
#define LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_SELECT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_SELECT_1_SHIFT)) & LPDDR_DENALI_PHY_329_PHY_DQ_TSEL_SELECT_1_MASK)

#define LPDDR_DENALI_PHY_329_PHY_DQS_TSEL_ENABLE_1_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_329_PHY_DQS_TSEL_ENABLE_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_329_PHY_DQS_TSEL_ENABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_329_PHY_DQS_TSEL_ENABLE_1_SHIFT)) & LPDDR_DENALI_PHY_329_PHY_DQS_TSEL_ENABLE_1_MASK)
/*! @} */

/*! @name DENALI_PHY_330 - DENALI_PHY_330 */
/*! @{ */

#define LPDDR_DENALI_PHY_330_PHY_DQS_TSEL_SELECT_1_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_330_PHY_DQS_TSEL_SELECT_1_SHIFT (0U)
/*! PHY_DQS_TSEL_SELECT_1 - Operation type tsel select values for DQS signals for slice 1. */
#define LPDDR_DENALI_PHY_330_PHY_DQS_TSEL_SELECT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_330_PHY_DQS_TSEL_SELECT_1_SHIFT)) & LPDDR_DENALI_PHY_330_PHY_DQS_TSEL_SELECT_1_MASK)

#define LPDDR_DENALI_PHY_330_PHY_TWO_CYC_PREAMBLE_1_MASK (0x30000U)
#define LPDDR_DENALI_PHY_330_PHY_TWO_CYC_PREAMBLE_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_330_PHY_TWO_CYC_PREAMBLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_330_PHY_TWO_CYC_PREAMBLE_1_SHIFT)) & LPDDR_DENALI_PHY_330_PHY_TWO_CYC_PREAMBLE_1_MASK)

#define LPDDR_DENALI_PHY_330_PHY_VREF_INITIAL_START_POINT_1_MASK (0x7F000000U)
#define LPDDR_DENALI_PHY_330_PHY_VREF_INITIAL_START_POINT_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_330_PHY_VREF_INITIAL_START_POINT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_330_PHY_VREF_INITIAL_START_POINT_1_SHIFT)) & LPDDR_DENALI_PHY_330_PHY_VREF_INITIAL_START_POINT_1_MASK)
/*! @} */

/*! @name DENALI_PHY_331 - DENALI_PHY_331 */
/*! @{ */

#define LPDDR_DENALI_PHY_331_PHY_VREF_INITIAL_STOP_POINT_1_MASK (0x7FU)
#define LPDDR_DENALI_PHY_331_PHY_VREF_INITIAL_STOP_POINT_1_SHIFT (0U)
/*! PHY_VREF_INITIAL_STOP_POINT_1 - Data slice initial VREF training stop value for slice 1. When
 *    programming the write DQ VREF stop point parameter, must set it equal to a multiple of the VREF
 *    (step size + start point).
 */
#define LPDDR_DENALI_PHY_331_PHY_VREF_INITIAL_STOP_POINT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_331_PHY_VREF_INITIAL_STOP_POINT_1_SHIFT)) & LPDDR_DENALI_PHY_331_PHY_VREF_INITIAL_STOP_POINT_1_MASK)

#define LPDDR_DENALI_PHY_331_PHY_VREF_TRAINING_CTRL_1_MASK (0x300U)
#define LPDDR_DENALI_PHY_331_PHY_VREF_TRAINING_CTRL_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_331_PHY_VREF_TRAINING_CTRL_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_331_PHY_VREF_TRAINING_CTRL_1_SHIFT)) & LPDDR_DENALI_PHY_331_PHY_VREF_TRAINING_CTRL_1_MASK)

#define LPDDR_DENALI_PHY_331_PHY_NTP_TRAIN_EN_1_MASK (0x10000U)
#define LPDDR_DENALI_PHY_331_PHY_NTP_TRAIN_EN_1_SHIFT (16U)
/*! PHY_NTP_TRAIN_EN_1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PHY_331_PHY_NTP_TRAIN_EN_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_331_PHY_NTP_TRAIN_EN_1_SHIFT)) & LPDDR_DENALI_PHY_331_PHY_NTP_TRAIN_EN_1_MASK)

#define LPDDR_DENALI_PHY_331_PHY_NTP_WDQ_STEP_SIZE_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_331_PHY_NTP_WDQ_STEP_SIZE_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_331_PHY_NTP_WDQ_STEP_SIZE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_331_PHY_NTP_WDQ_STEP_SIZE_1_SHIFT)) & LPDDR_DENALI_PHY_331_PHY_NTP_WDQ_STEP_SIZE_1_MASK)
/*! @} */

/*! @name DENALI_PHY_336 - DENALI_PHY_336 */
/*! @{ */

#define LPDDR_DENALI_PHY_336_PHY_PAD_DQS_RX_DCD_1_MASK (0x1FU)
#define LPDDR_DENALI_PHY_336_PHY_PAD_DQS_RX_DCD_1_SHIFT (0U)
/*! PHY_PAD_DQS_RX_DCD_1 - Controls RX_DCD pin for dqs pad for slice 1. */
#define LPDDR_DENALI_PHY_336_PHY_PAD_DQS_RX_DCD_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_336_PHY_PAD_DQS_RX_DCD_1_SHIFT)) & LPDDR_DENALI_PHY_336_PHY_PAD_DQS_RX_DCD_1_MASK)

#define LPDDR_DENALI_PHY_336_PHY_PAD_FDBK_RX_DCD_1_MASK (0x1F00U)
#define LPDDR_DENALI_PHY_336_PHY_PAD_FDBK_RX_DCD_1_SHIFT (8U)
/*! PHY_PAD_FDBK_RX_DCD_1 - Controls RX_DCD pin for fdbk pad for slice 1. */
#define LPDDR_DENALI_PHY_336_PHY_PAD_FDBK_RX_DCD_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_336_PHY_PAD_FDBK_RX_DCD_1_SHIFT)) & LPDDR_DENALI_PHY_336_PHY_PAD_FDBK_RX_DCD_1_MASK)

#define LPDDR_DENALI_PHY_336_PHY_PAD_DSLICE_IO_CFG_1_MASK (0x7F0000U)
#define LPDDR_DENALI_PHY_336_PHY_PAD_DSLICE_IO_CFG_1_SHIFT (16U)
/*! PHY_PAD_DSLICE_IO_CFG_1 - Controls PCLK/PARK pin for IO pad for slice 1. */
#define LPDDR_DENALI_PHY_336_PHY_PAD_DSLICE_IO_CFG_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_336_PHY_PAD_DSLICE_IO_CFG_1_SHIFT)) & LPDDR_DENALI_PHY_336_PHY_PAD_DSLICE_IO_CFG_1_MASK)
/*! @} */

/*! @name DENALI_PHY_344 - DENALI_PHY_344 */
/*! @{ */

#define LPDDR_DENALI_PHY_344_PHY_VREF_SETTING_TIME_1_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_344_PHY_VREF_SETTING_TIME_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_344_PHY_VREF_SETTING_TIME_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_344_PHY_VREF_SETTING_TIME_1_SHIFT)) & LPDDR_DENALI_PHY_344_PHY_VREF_SETTING_TIME_1_MASK)

#define LPDDR_DENALI_PHY_344_PHY_PAD_VREF_CTRL_DQ_1_MASK (0xFFF0000U)
#define LPDDR_DENALI_PHY_344_PHY_PAD_VREF_CTRL_DQ_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_344_PHY_PAD_VREF_CTRL_DQ_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_344_PHY_PAD_VREF_CTRL_DQ_1_SHIFT)) & LPDDR_DENALI_PHY_344_PHY_PAD_VREF_CTRL_DQ_1_MASK)
/*! @} */

/*! @name DENALI_PHY_345 - DENALI_PHY_345 */
/*! @{ */

#define LPDDR_DENALI_PHY_345_PHY_PER_CS_TRAINING_EN_1_MASK (0x1U)
#define LPDDR_DENALI_PHY_345_PHY_PER_CS_TRAINING_EN_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_345_PHY_PER_CS_TRAINING_EN_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_345_PHY_PER_CS_TRAINING_EN_1_SHIFT)) & LPDDR_DENALI_PHY_345_PHY_PER_CS_TRAINING_EN_1_MASK)

#define LPDDR_DENALI_PHY_345_PHY_DQ_IE_TIMING_1_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_345_PHY_DQ_IE_TIMING_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_345_PHY_DQ_IE_TIMING_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_345_PHY_DQ_IE_TIMING_1_SHIFT)) & LPDDR_DENALI_PHY_345_PHY_DQ_IE_TIMING_1_MASK)

#define LPDDR_DENALI_PHY_345_PHY_DQS_IE_TIMING_1_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_345_PHY_DQS_IE_TIMING_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_345_PHY_DQS_IE_TIMING_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_345_PHY_DQS_IE_TIMING_1_SHIFT)) & LPDDR_DENALI_PHY_345_PHY_DQS_IE_TIMING_1_MASK)

#define LPDDR_DENALI_PHY_345_PHY_RDDATA_EN_IE_DLY_1_MASK (0x3000000U)
#define LPDDR_DENALI_PHY_345_PHY_RDDATA_EN_IE_DLY_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_345_PHY_RDDATA_EN_IE_DLY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_345_PHY_RDDATA_EN_IE_DLY_1_SHIFT)) & LPDDR_DENALI_PHY_345_PHY_RDDATA_EN_IE_DLY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_346 - DENALI_PHY_346 */
/*! @{ */

#define LPDDR_DENALI_PHY_346_PHY_IE_MODE_1_MASK  (0x3U)
#define LPDDR_DENALI_PHY_346_PHY_IE_MODE_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_346_PHY_IE_MODE_1(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_346_PHY_IE_MODE_1_SHIFT)) & LPDDR_DENALI_PHY_346_PHY_IE_MODE_1_MASK)

#define LPDDR_DENALI_PHY_346_PHY_DBI_MODE_1_MASK (0x100U)
#define LPDDR_DENALI_PHY_346_PHY_DBI_MODE_1_SHIFT (8U)
/*! PHY_DBI_MODE_1
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_PHY_346_PHY_DBI_MODE_1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_346_PHY_DBI_MODE_1_SHIFT)) & LPDDR_DENALI_PHY_346_PHY_DBI_MODE_1_MASK)

#define LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_TSEL_DLY_1_MASK (0x1F0000U)
#define LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_TSEL_DLY_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_TSEL_DLY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_TSEL_DLY_1_SHIFT)) & LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_TSEL_DLY_1_MASK)

#define LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_OE_DLY_1_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_OE_DLY_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_OE_DLY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_OE_DLY_1_SHIFT)) & LPDDR_DENALI_PHY_346_PHY_RDDATA_EN_OE_DLY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_348 - DENALI_PHY_348 */
/*! @{ */

#define LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_WAIT_1_MASK (0xFFU)
#define LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_WAIT_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_WAIT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_WAIT_1_SHIFT)) & LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_WAIT_1_MASK)

#define LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_HALF_MEASURE_1_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_HALF_MEASURE_1_SHIFT (8U)
/*! PHY_MASTER_DELAY_HALF_MEASURE_1 - Defines the number of delay line elements to be considered in
 *    determing whether to lock to a half clock cycle in the data slice master for slice 1.
 */
#define LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_HALF_MEASURE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_HALF_MEASURE_1_SHIFT)) & LPDDR_DENALI_PHY_348_PHY_MASTER_DELAY_HALF_MEASURE_1_MASK)

#define LPDDR_DENALI_PHY_348_PHY_RPTR_UPDATE_1_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_348_PHY_RPTR_UPDATE_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_348_PHY_RPTR_UPDATE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_348_PHY_RPTR_UPDATE_1_SHIFT)) & LPDDR_DENALI_PHY_348_PHY_RPTR_UPDATE_1_MASK)

#define LPDDR_DENALI_PHY_348_PHY_WRLVL_DLY_STEP_1_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_348_PHY_WRLVL_DLY_STEP_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_348_PHY_WRLVL_DLY_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_348_PHY_WRLVL_DLY_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_348_PHY_WRLVL_DLY_STEP_1_MASK)
/*! @} */

/*! @name DENALI_PHY_349 - DENALI_PHY_349 */
/*! @{ */

#define LPDDR_DENALI_PHY_349_PHY_WRLVL_DLY_FINE_STEP_1_MASK (0xFU)
#define LPDDR_DENALI_PHY_349_PHY_WRLVL_DLY_FINE_STEP_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_349_PHY_WRLVL_DLY_FINE_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_349_PHY_WRLVL_DLY_FINE_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_349_PHY_WRLVL_DLY_FINE_STEP_1_MASK)

#define LPDDR_DENALI_PHY_349_PHY_WRLVL_RESP_WAIT_CNT_1_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_349_PHY_WRLVL_RESP_WAIT_CNT_1_SHIFT (8U)
/*! PHY_WRLVL_RESP_WAIT_CNT_1 - Defines the number of cycles to wait between dfi_wrlvl_strobe and
 *    the sampling of the DQs during write leveling for slice 1.
 */
#define LPDDR_DENALI_PHY_349_PHY_WRLVL_RESP_WAIT_CNT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_349_PHY_WRLVL_RESP_WAIT_CNT_1_SHIFT)) & LPDDR_DENALI_PHY_349_PHY_WRLVL_RESP_WAIT_CNT_1_MASK)

#define LPDDR_DENALI_PHY_349_PHY_GTLVL_DLY_STEP_1_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_349_PHY_GTLVL_DLY_STEP_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_349_PHY_GTLVL_DLY_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_349_PHY_GTLVL_DLY_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_349_PHY_GTLVL_DLY_STEP_1_MASK)

#define LPDDR_DENALI_PHY_349_PHY_GTLVL_RESP_WAIT_CNT_1_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_349_PHY_GTLVL_RESP_WAIT_CNT_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_349_PHY_GTLVL_RESP_WAIT_CNT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_349_PHY_GTLVL_RESP_WAIT_CNT_1_SHIFT)) & LPDDR_DENALI_PHY_349_PHY_GTLVL_RESP_WAIT_CNT_1_MASK)
/*! @} */

/*! @name DENALI_PHY_351 - DENALI_PHY_351 */
/*! @{ */

#define LPDDR_DENALI_PHY_351_PHY_WDQLVL_DLY_STEP_1_MASK (0xFFU)
#define LPDDR_DENALI_PHY_351_PHY_WDQLVL_DLY_STEP_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_351_PHY_WDQLVL_DLY_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_351_PHY_WDQLVL_DLY_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_351_PHY_WDQLVL_DLY_STEP_1_MASK)

#define LPDDR_DENALI_PHY_351_PHY_WDQLVL_QTR_DLY_STEP_1_MASK (0xF00U)
#define LPDDR_DENALI_PHY_351_PHY_WDQLVL_QTR_DLY_STEP_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_351_PHY_WDQLVL_QTR_DLY_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_351_PHY_WDQLVL_QTR_DLY_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_351_PHY_WDQLVL_QTR_DLY_STEP_1_MASK)

#define LPDDR_DENALI_PHY_351_PHY_TOGGLE_PRE_SUPPORT_1_MASK (0x10000U)
#define LPDDR_DENALI_PHY_351_PHY_TOGGLE_PRE_SUPPORT_1_SHIFT (16U)
/*! PHY_TOGGLE_PRE_SUPPORT_1 - Support the toggle read preamble for LPDDR4 for slice 1.
 *  0b0..Static read preamble
 *  0b1..Toggling read preamble
 */
#define LPDDR_DENALI_PHY_351_PHY_TOGGLE_PRE_SUPPORT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_351_PHY_TOGGLE_PRE_SUPPORT_1_SHIFT)) & LPDDR_DENALI_PHY_351_PHY_TOGGLE_PRE_SUPPORT_1_MASK)

#define LPDDR_DENALI_PHY_351_PHY_RDLVL_DLY_STEP_1_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_351_PHY_RDLVL_DLY_STEP_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_351_PHY_RDLVL_DLY_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_351_PHY_RDLVL_DLY_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_351_PHY_RDLVL_DLY_STEP_1_MASK)
/*! @} */

/*! @name DENALI_PHY_352 - DENALI_PHY_352 */
/*! @{ */

#define LPDDR_DENALI_PHY_352_PHY_RDLVL_MAX_EDGE_1_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_352_PHY_RDLVL_MAX_EDGE_1_SHIFT (0U)
/*! PHY_RDLVL_MAX_EDGE_1 - Provides the maximun rdlvl slave delay search window for read eye training for slice 1. */
#define LPDDR_DENALI_PHY_352_PHY_RDLVL_MAX_EDGE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_352_PHY_RDLVL_MAX_EDGE_1_SHIFT)) & LPDDR_DENALI_PHY_352_PHY_RDLVL_MAX_EDGE_1_MASK)
/*! @} */

/*! @name DENALI_PHY_353 - DENALI_PHY_353 */
/*! @{ */

#define LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_DISABLE_1_MASK (0x3U)
#define LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_DISABLE_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_DISABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_DISABLE_1_SHIFT)) & LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_DISABLE_1_MASK)

#define LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_TIMING_1_MASK (0x700U)
#define LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_TIMING_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_TIMING_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_TIMING_1_SHIFT)) & LPDDR_DENALI_PHY_353_PHY_WRPATH_GATE_TIMING_1_MASK)

#define LPDDR_DENALI_PHY_353_PHY_MEAS_DLY_STEP_ENABLE_1_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_353_PHY_MEAS_DLY_STEP_ENABLE_1_SHIFT (16U)
/*! PHY_MEAS_DLY_STEP_ENABLE_1 - Data slice training step definition using phy_meas_dly_step_value for slice 1. */
#define LPDDR_DENALI_PHY_353_PHY_MEAS_DLY_STEP_ENABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_353_PHY_MEAS_DLY_STEP_ENABLE_1_SHIFT)) & LPDDR_DENALI_PHY_353_PHY_MEAS_DLY_STEP_ENABLE_1_MASK)

#define LPDDR_DENALI_PHY_353_PHY_RDDATA_EN_DLY_1_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_353_PHY_RDDATA_EN_DLY_1_SHIFT (24U)
#define LPDDR_DENALI_PHY_353_PHY_RDDATA_EN_DLY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_353_PHY_RDDATA_EN_DLY_1_SHIFT)) & LPDDR_DENALI_PHY_353_PHY_RDDATA_EN_DLY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_354 - DENALI_PHY_354 */
/*! @{ */

#define LPDDR_DENALI_PHY_354_PHY_DQ_DM_SWIZZLE0_1_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_354_PHY_DQ_DM_SWIZZLE0_1_SHIFT (0U)
#define LPDDR_DENALI_PHY_354_PHY_DQ_DM_SWIZZLE0_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_354_PHY_DQ_DM_SWIZZLE0_1_SHIFT)) & LPDDR_DENALI_PHY_354_PHY_DQ_DM_SWIZZLE0_1_MASK)
/*! @} */

/*! @name DENALI_PHY_356 - DENALI_PHY_356 */
/*! @{ */

#define LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ0_SLAVE_DELAY_1_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ0_SLAVE_DELAY_1_SHIFT (0U)
/*! PHY_CLK_WRDQ0_SLAVE_DELAY_1 - Write clock slave delay setting for DQ0 for slice 1. */
#define LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ0_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ0_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ0_SLAVE_DELAY_1_MASK)

#define LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ1_SLAVE_DELAY_1_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ1_SLAVE_DELAY_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ1_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ1_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_356_PHY_CLK_WRDQ1_SLAVE_DELAY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_357 - DENALI_PHY_357 */
/*! @{ */

#define LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ2_SLAVE_DELAY_1_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ2_SLAVE_DELAY_1_SHIFT (0U)
/*! PHY_CLK_WRDQ2_SLAVE_DELAY_1 - Write clock slave delay setting for DQ2 for slice 1. */
#define LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ2_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ2_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ2_SLAVE_DELAY_1_MASK)

#define LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ3_SLAVE_DELAY_1_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ3_SLAVE_DELAY_1_SHIFT (16U)
/*! PHY_CLK_WRDQ3_SLAVE_DELAY_1 - Write clock slave delay setting for DQ3 for slice 1. */
#define LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ3_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ3_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_357_PHY_CLK_WRDQ3_SLAVE_DELAY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_358 - DENALI_PHY_358 */
/*! @{ */

#define LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ4_SLAVE_DELAY_1_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ4_SLAVE_DELAY_1_SHIFT (0U)
/*! PHY_CLK_WRDQ4_SLAVE_DELAY_1 - Write clock slave delay setting for DQ4 for slice 1. */
#define LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ4_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ4_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ4_SLAVE_DELAY_1_MASK)

#define LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ5_SLAVE_DELAY_1_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ5_SLAVE_DELAY_1_SHIFT (16U)
/*! PHY_CLK_WRDQ5_SLAVE_DELAY_1 - Write clock slave delay setting for DQ5 for slice 1. */
#define LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ5_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ5_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_358_PHY_CLK_WRDQ5_SLAVE_DELAY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_359 - DENALI_PHY_359 */
/*! @{ */

#define LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ6_SLAVE_DELAY_1_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ6_SLAVE_DELAY_1_SHIFT (0U)
/*! PHY_CLK_WRDQ6_SLAVE_DELAY_1 - Write clock slave delay setting for DQ6 for slice 1. */
#define LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ6_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ6_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ6_SLAVE_DELAY_1_MASK)

#define LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ7_SLAVE_DELAY_1_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ7_SLAVE_DELAY_1_SHIFT (16U)
/*! PHY_CLK_WRDQ7_SLAVE_DELAY_1 - Write clock slave delay setting for DQ7 for slice 1. */
#define LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ7_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ7_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_359_PHY_CLK_WRDQ7_SLAVE_DELAY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_360 - DENALI_PHY_360 */
/*! @{ */

#define LPDDR_DENALI_PHY_360_PHY_CLK_WRDM_SLAVE_DELAY_1_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_360_PHY_CLK_WRDM_SLAVE_DELAY_1_SHIFT (0U)
/*! PHY_CLK_WRDM_SLAVE_DELAY_1 - Write clock slave delay setting for DM for slice 1. */
#define LPDDR_DENALI_PHY_360_PHY_CLK_WRDM_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_360_PHY_CLK_WRDM_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_360_PHY_CLK_WRDM_SLAVE_DELAY_1_MASK)

#define LPDDR_DENALI_PHY_360_PHY_CLK_WRDQS_SLAVE_DELAY_1_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_360_PHY_CLK_WRDQS_SLAVE_DELAY_1_SHIFT (16U)
/*! PHY_CLK_WRDQS_SLAVE_DELAY_1 - Write clock slave delay setting for DQS for slice 1. */
#define LPDDR_DENALI_PHY_360_PHY_CLK_WRDQS_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_360_PHY_CLK_WRDQS_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_360_PHY_CLK_WRDQS_SLAVE_DELAY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_370 - DENALI_PHY_370 */
/*! @{ */

#define LPDDR_DENALI_PHY_370_PHY_RDDQS_DM_FALL_SLAVE_DELAY_1_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_370_PHY_RDDQS_DM_FALL_SLAVE_DELAY_1_SHIFT (0U)
/*! PHY_RDDQS_DM_FALL_SLAVE_DELAY_1 - Falling edge read DQS slave delay setting for DM for slice 1. */
#define LPDDR_DENALI_PHY_370_PHY_RDDQS_DM_FALL_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_370_PHY_RDDQS_DM_FALL_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_370_PHY_RDDQS_DM_FALL_SLAVE_DELAY_1_MASK)

#define LPDDR_DENALI_PHY_370_PHY_RDDQS_GATE_SLAVE_DELAY_1_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_370_PHY_RDDQS_GATE_SLAVE_DELAY_1_SHIFT (16U)
/*! PHY_RDDQS_GATE_SLAVE_DELAY_1 - Read DQS slave delay setting for slice 1. */
#define LPDDR_DENALI_PHY_370_PHY_RDDQS_GATE_SLAVE_DELAY_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_370_PHY_RDDQS_GATE_SLAVE_DELAY_1_SHIFT)) & LPDDR_DENALI_PHY_370_PHY_RDDQS_GATE_SLAVE_DELAY_1_MASK)
/*! @} */

/*! @name DENALI_PHY_543 - DENALI_PHY_543 */
/*! @{ */

#define LPDDR_DENALI_PHY_543_PHY_WRLVL_UPDT_WAIT_CNT_2_MASK (0xFU)
#define LPDDR_DENALI_PHY_543_PHY_WRLVL_UPDT_WAIT_CNT_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_543_PHY_WRLVL_UPDT_WAIT_CNT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_543_PHY_WRLVL_UPDT_WAIT_CNT_2_SHIFT)) & LPDDR_DENALI_PHY_543_PHY_WRLVL_UPDT_WAIT_CNT_2_MASK)

#define LPDDR_DENALI_PHY_543_PHY_DQ_MASK_2_MASK  (0xFF00U)
#define LPDDR_DENALI_PHY_543_PHY_DQ_MASK_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_543_PHY_DQ_MASK_2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_543_PHY_DQ_MASK_2_SHIFT)) & LPDDR_DENALI_PHY_543_PHY_DQ_MASK_2_MASK)

#define LPDDR_DENALI_PHY_543_PHY_GTLVL_CAPTURE_CNT_2_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_543_PHY_GTLVL_CAPTURE_CNT_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_543_PHY_GTLVL_CAPTURE_CNT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_543_PHY_GTLVL_CAPTURE_CNT_2_SHIFT)) & LPDDR_DENALI_PHY_543_PHY_GTLVL_CAPTURE_CNT_2_MASK)

#define LPDDR_DENALI_PHY_543_PHY_GTLVL_UPDT_WAIT_CNT_2_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_543_PHY_GTLVL_UPDT_WAIT_CNT_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_543_PHY_GTLVL_UPDT_WAIT_CNT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_543_PHY_GTLVL_UPDT_WAIT_CNT_2_SHIFT)) & LPDDR_DENALI_PHY_543_PHY_GTLVL_UPDT_WAIT_CNT_2_MASK)
/*! @} */

/*! @name DENALI_PHY_545 - DENALI_PHY_545 */
/*! @{ */

#define LPDDR_DENALI_PHY_545_PHY_RDLVL_DATA_MASK_2_MASK (0xFFU)
#define LPDDR_DENALI_PHY_545_PHY_RDLVL_DATA_MASK_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_545_PHY_RDLVL_DATA_MASK_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_545_PHY_RDLVL_DATA_MASK_2_SHIFT)) & LPDDR_DENALI_PHY_545_PHY_RDLVL_DATA_MASK_2_MASK)

#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_CLK_JITTER_TOLERANCE_2_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_CLK_JITTER_TOLERANCE_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_CLK_JITTER_TOLERANCE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_545_PHY_WDQLVL_CLK_JITTER_TOLERANCE_2_SHIFT)) & LPDDR_DENALI_PHY_545_PHY_WDQLVL_CLK_JITTER_TOLERANCE_2_MASK)

#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_BURST_CNT_2_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_BURST_CNT_2_SHIFT (16U)
/*! PHY_WDQLVL_BURST_CNT_2 - Defines the write/read burst length in bytes during the write data leveling sequence for slice 2. */
#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_BURST_CNT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_545_PHY_WDQLVL_BURST_CNT_2_SHIFT)) & LPDDR_DENALI_PHY_545_PHY_WDQLVL_BURST_CNT_2_MASK)

#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_PATT_2_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_PATT_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_545_PHY_WDQLVL_PATT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_545_PHY_WDQLVL_PATT_2_SHIFT)) & LPDDR_DENALI_PHY_545_PHY_WDQLVL_PATT_2_MASK)
/*! @} */

/*! @name DENALI_PHY_555 - DENALI_PHY_555 */
/*! @{ */

#define LPDDR_DENALI_PHY_555_PHY_CALVL_VREF_DRIVING_SLICE_2_MASK (0x1U)
#define LPDDR_DENALI_PHY_555_PHY_CALVL_VREF_DRIVING_SLICE_2_SHIFT (0U)
/*! PHY_CALVL_VREF_DRIVING_SLICE_2 - Indicates if slice 2 is used to drive the VREF value to the device during CA training. */
#define LPDDR_DENALI_PHY_555_PHY_CALVL_VREF_DRIVING_SLICE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_555_PHY_CALVL_VREF_DRIVING_SLICE_2_SHIFT)) & LPDDR_DENALI_PHY_555_PHY_CALVL_VREF_DRIVING_SLICE_2_MASK)

#define LPDDR_DENALI_PHY_555_SC_PHY_MANUAL_CLEAR_2_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_555_SC_PHY_MANUAL_CLEAR_2_SHIFT (8U)
/*! SC_PHY_MANUAL_CLEAR_2 - Manual reset/clear of internal logic for slice 2. */
#define LPDDR_DENALI_PHY_555_SC_PHY_MANUAL_CLEAR_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_555_SC_PHY_MANUAL_CLEAR_2_SHIFT)) & LPDDR_DENALI_PHY_555_SC_PHY_MANUAL_CLEAR_2_MASK)

#define LPDDR_DENALI_PHY_555_PHY_FIFO_PTR_OBS_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_555_PHY_FIFO_PTR_OBS_2_SHIFT (16U)
/*! PHY_FIFO_PTR_OBS_2 - Observation register containing read entry FIFO pointers for slice 2. */
#define LPDDR_DENALI_PHY_555_PHY_FIFO_PTR_OBS_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_555_PHY_FIFO_PTR_OBS_2_SHIFT)) & LPDDR_DENALI_PHY_555_PHY_FIFO_PTR_OBS_2_MASK)
/*! @} */

/*! @name DENALI_PHY_584 - DENALI_PHY_584 */
/*! @{ */

#define LPDDR_DENALI_PHY_584_PHY_SLV_DLY_CTRL_GATE_DISABLE_2_MASK (0x1U)
#define LPDDR_DENALI_PHY_584_PHY_SLV_DLY_CTRL_GATE_DISABLE_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_584_PHY_SLV_DLY_CTRL_GATE_DISABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_584_PHY_SLV_DLY_CTRL_GATE_DISABLE_2_SHIFT)) & LPDDR_DENALI_PHY_584_PHY_SLV_DLY_CTRL_GATE_DISABLE_2_MASK)

#define LPDDR_DENALI_PHY_584_PHY_RDPATH_GATE_DISABLE_2_MASK (0x100U)
#define LPDDR_DENALI_PHY_584_PHY_RDPATH_GATE_DISABLE_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_584_PHY_RDPATH_GATE_DISABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_584_PHY_RDPATH_GATE_DISABLE_2_SHIFT)) & LPDDR_DENALI_PHY_584_PHY_RDPATH_GATE_DISABLE_2_MASK)

#define LPDDR_DENALI_PHY_584_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_2_MASK (0x10000U)
#define LPDDR_DENALI_PHY_584_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_584_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_584_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_2_SHIFT)) & LPDDR_DENALI_PHY_584_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_2_MASK)

#define LPDDR_DENALI_PHY_584_PHY_SLICE_PWR_RDC_DISABLE_2_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_584_PHY_SLICE_PWR_RDC_DISABLE_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_584_PHY_SLICE_PWR_RDC_DISABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_584_PHY_SLICE_PWR_RDC_DISABLE_2_SHIFT)) & LPDDR_DENALI_PHY_584_PHY_SLICE_PWR_RDC_DISABLE_2_MASK)
/*! @} */

/*! @name DENALI_PHY_585 - DENALI_PHY_585 */
/*! @{ */

#define LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_ENABLE_2_MASK (0x7U)
#define LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_ENABLE_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_ENABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_ENABLE_2_SHIFT)) & LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_ENABLE_2_MASK)

#define LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_SELECT_2_MASK (0xFFFF00U)
#define LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_SELECT_2_SHIFT (8U)
/*! PHY_DQ_TSEL_SELECT_2 - Operation type tsel select values for DQ/DM signals for slice 2. */
#define LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_SELECT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_SELECT_2_SHIFT)) & LPDDR_DENALI_PHY_585_PHY_DQ_TSEL_SELECT_2_MASK)

#define LPDDR_DENALI_PHY_585_PHY_DQS_TSEL_ENABLE_2_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_585_PHY_DQS_TSEL_ENABLE_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_585_PHY_DQS_TSEL_ENABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_585_PHY_DQS_TSEL_ENABLE_2_SHIFT)) & LPDDR_DENALI_PHY_585_PHY_DQS_TSEL_ENABLE_2_MASK)
/*! @} */

/*! @name DENALI_PHY_586 - DENALI_PHY_586 */
/*! @{ */

#define LPDDR_DENALI_PHY_586_PHY_DQS_TSEL_SELECT_2_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_586_PHY_DQS_TSEL_SELECT_2_SHIFT (0U)
/*! PHY_DQS_TSEL_SELECT_2 - Operation type tsel select values for DQS signals for slice 2. */
#define LPDDR_DENALI_PHY_586_PHY_DQS_TSEL_SELECT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_586_PHY_DQS_TSEL_SELECT_2_SHIFT)) & LPDDR_DENALI_PHY_586_PHY_DQS_TSEL_SELECT_2_MASK)

#define LPDDR_DENALI_PHY_586_PHY_TWO_CYC_PREAMBLE_2_MASK (0x30000U)
#define LPDDR_DENALI_PHY_586_PHY_TWO_CYC_PREAMBLE_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_586_PHY_TWO_CYC_PREAMBLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_586_PHY_TWO_CYC_PREAMBLE_2_SHIFT)) & LPDDR_DENALI_PHY_586_PHY_TWO_CYC_PREAMBLE_2_MASK)

#define LPDDR_DENALI_PHY_586_PHY_VREF_INITIAL_START_POINT_2_MASK (0x7F000000U)
#define LPDDR_DENALI_PHY_586_PHY_VREF_INITIAL_START_POINT_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_586_PHY_VREF_INITIAL_START_POINT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_586_PHY_VREF_INITIAL_START_POINT_2_SHIFT)) & LPDDR_DENALI_PHY_586_PHY_VREF_INITIAL_START_POINT_2_MASK)
/*! @} */

/*! @name DENALI_PHY_587 - DENALI_PHY_587 */
/*! @{ */

#define LPDDR_DENALI_PHY_587_PHY_VREF_INITIAL_STOP_POINT_2_MASK (0x7FU)
#define LPDDR_DENALI_PHY_587_PHY_VREF_INITIAL_STOP_POINT_2_SHIFT (0U)
/*! PHY_VREF_INITIAL_STOP_POINT_2 - Data slice initial VREF training stop value for slice 2. When
 *    programming the write DQ VREF stop point parameter, must set it equal to a multiple of the VREF
 *    (step size + start point).
 */
#define LPDDR_DENALI_PHY_587_PHY_VREF_INITIAL_STOP_POINT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_587_PHY_VREF_INITIAL_STOP_POINT_2_SHIFT)) & LPDDR_DENALI_PHY_587_PHY_VREF_INITIAL_STOP_POINT_2_MASK)

#define LPDDR_DENALI_PHY_587_PHY_VREF_TRAINING_CTRL_2_MASK (0x300U)
#define LPDDR_DENALI_PHY_587_PHY_VREF_TRAINING_CTRL_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_587_PHY_VREF_TRAINING_CTRL_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_587_PHY_VREF_TRAINING_CTRL_2_SHIFT)) & LPDDR_DENALI_PHY_587_PHY_VREF_TRAINING_CTRL_2_MASK)

#define LPDDR_DENALI_PHY_587_PHY_NTP_TRAIN_EN_2_MASK (0x10000U)
#define LPDDR_DENALI_PHY_587_PHY_NTP_TRAIN_EN_2_SHIFT (16U)
/*! PHY_NTP_TRAIN_EN_2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PHY_587_PHY_NTP_TRAIN_EN_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_587_PHY_NTP_TRAIN_EN_2_SHIFT)) & LPDDR_DENALI_PHY_587_PHY_NTP_TRAIN_EN_2_MASK)

#define LPDDR_DENALI_PHY_587_PHY_NTP_WDQ_STEP_SIZE_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_587_PHY_NTP_WDQ_STEP_SIZE_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_587_PHY_NTP_WDQ_STEP_SIZE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_587_PHY_NTP_WDQ_STEP_SIZE_2_SHIFT)) & LPDDR_DENALI_PHY_587_PHY_NTP_WDQ_STEP_SIZE_2_MASK)
/*! @} */

/*! @name DENALI_PHY_592 - DENALI_PHY_592 */
/*! @{ */

#define LPDDR_DENALI_PHY_592_PHY_PAD_DQS_RX_DCD_2_MASK (0x1FU)
#define LPDDR_DENALI_PHY_592_PHY_PAD_DQS_RX_DCD_2_SHIFT (0U)
/*! PHY_PAD_DQS_RX_DCD_2 - Controls RX_DCD pin for dqs pad for slice 2. */
#define LPDDR_DENALI_PHY_592_PHY_PAD_DQS_RX_DCD_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_592_PHY_PAD_DQS_RX_DCD_2_SHIFT)) & LPDDR_DENALI_PHY_592_PHY_PAD_DQS_RX_DCD_2_MASK)

#define LPDDR_DENALI_PHY_592_PHY_PAD_FDBK_RX_DCD_2_MASK (0x1F00U)
#define LPDDR_DENALI_PHY_592_PHY_PAD_FDBK_RX_DCD_2_SHIFT (8U)
/*! PHY_PAD_FDBK_RX_DCD_2 - Controls RX_DCD pin for fdbk pad for slice 2. */
#define LPDDR_DENALI_PHY_592_PHY_PAD_FDBK_RX_DCD_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_592_PHY_PAD_FDBK_RX_DCD_2_SHIFT)) & LPDDR_DENALI_PHY_592_PHY_PAD_FDBK_RX_DCD_2_MASK)

#define LPDDR_DENALI_PHY_592_PHY_PAD_DSLICE_IO_CFG_2_MASK (0x7F0000U)
#define LPDDR_DENALI_PHY_592_PHY_PAD_DSLICE_IO_CFG_2_SHIFT (16U)
/*! PHY_PAD_DSLICE_IO_CFG_2 - Controls PCLK/PARK pin for IO pad for slice 2. */
#define LPDDR_DENALI_PHY_592_PHY_PAD_DSLICE_IO_CFG_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_592_PHY_PAD_DSLICE_IO_CFG_2_SHIFT)) & LPDDR_DENALI_PHY_592_PHY_PAD_DSLICE_IO_CFG_2_MASK)
/*! @} */

/*! @name DENALI_PHY_600 - DENALI_PHY_600 */
/*! @{ */

#define LPDDR_DENALI_PHY_600_PHY_VREF_SETTING_TIME_2_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_600_PHY_VREF_SETTING_TIME_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_600_PHY_VREF_SETTING_TIME_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_600_PHY_VREF_SETTING_TIME_2_SHIFT)) & LPDDR_DENALI_PHY_600_PHY_VREF_SETTING_TIME_2_MASK)

#define LPDDR_DENALI_PHY_600_PHY_PAD_VREF_CTRL_DQ_2_MASK (0xFFF0000U)
#define LPDDR_DENALI_PHY_600_PHY_PAD_VREF_CTRL_DQ_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_600_PHY_PAD_VREF_CTRL_DQ_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_600_PHY_PAD_VREF_CTRL_DQ_2_SHIFT)) & LPDDR_DENALI_PHY_600_PHY_PAD_VREF_CTRL_DQ_2_MASK)
/*! @} */

/*! @name DENALI_PHY_601 - DENALI_PHY_601 */
/*! @{ */

#define LPDDR_DENALI_PHY_601_PHY_PER_CS_TRAINING_EN_2_MASK (0x1U)
#define LPDDR_DENALI_PHY_601_PHY_PER_CS_TRAINING_EN_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_601_PHY_PER_CS_TRAINING_EN_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_601_PHY_PER_CS_TRAINING_EN_2_SHIFT)) & LPDDR_DENALI_PHY_601_PHY_PER_CS_TRAINING_EN_2_MASK)

#define LPDDR_DENALI_PHY_601_PHY_DQ_IE_TIMING_2_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_601_PHY_DQ_IE_TIMING_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_601_PHY_DQ_IE_TIMING_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_601_PHY_DQ_IE_TIMING_2_SHIFT)) & LPDDR_DENALI_PHY_601_PHY_DQ_IE_TIMING_2_MASK)

#define LPDDR_DENALI_PHY_601_PHY_DQS_IE_TIMING_2_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_601_PHY_DQS_IE_TIMING_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_601_PHY_DQS_IE_TIMING_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_601_PHY_DQS_IE_TIMING_2_SHIFT)) & LPDDR_DENALI_PHY_601_PHY_DQS_IE_TIMING_2_MASK)

#define LPDDR_DENALI_PHY_601_PHY_RDDATA_EN_IE_DLY_2_MASK (0x3000000U)
#define LPDDR_DENALI_PHY_601_PHY_RDDATA_EN_IE_DLY_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_601_PHY_RDDATA_EN_IE_DLY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_601_PHY_RDDATA_EN_IE_DLY_2_SHIFT)) & LPDDR_DENALI_PHY_601_PHY_RDDATA_EN_IE_DLY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_602 - DENALI_PHY_602 */
/*! @{ */

#define LPDDR_DENALI_PHY_602_PHY_IE_MODE_2_MASK  (0x3U)
#define LPDDR_DENALI_PHY_602_PHY_IE_MODE_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_602_PHY_IE_MODE_2(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_602_PHY_IE_MODE_2_SHIFT)) & LPDDR_DENALI_PHY_602_PHY_IE_MODE_2_MASK)

#define LPDDR_DENALI_PHY_602_PHY_DBI_MODE_2_MASK (0x100U)
#define LPDDR_DENALI_PHY_602_PHY_DBI_MODE_2_SHIFT (8U)
/*! PHY_DBI_MODE_2
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_PHY_602_PHY_DBI_MODE_2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_602_PHY_DBI_MODE_2_SHIFT)) & LPDDR_DENALI_PHY_602_PHY_DBI_MODE_2_MASK)

#define LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_TSEL_DLY_2_MASK (0x1F0000U)
#define LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_TSEL_DLY_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_TSEL_DLY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_TSEL_DLY_2_SHIFT)) & LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_TSEL_DLY_2_MASK)

#define LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_OE_DLY_2_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_OE_DLY_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_OE_DLY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_OE_DLY_2_SHIFT)) & LPDDR_DENALI_PHY_602_PHY_RDDATA_EN_OE_DLY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_604 - DENALI_PHY_604 */
/*! @{ */

#define LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_WAIT_2_MASK (0xFFU)
#define LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_WAIT_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_WAIT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_WAIT_2_SHIFT)) & LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_WAIT_2_MASK)

#define LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_HALF_MEASURE_2_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_HALF_MEASURE_2_SHIFT (8U)
/*! PHY_MASTER_DELAY_HALF_MEASURE_2 - Defines the number of delay line elements to be considered in
 *    determing whether to lock to a half clock cycle in the data slice master for slice 2.
 */
#define LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_HALF_MEASURE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_HALF_MEASURE_2_SHIFT)) & LPDDR_DENALI_PHY_604_PHY_MASTER_DELAY_HALF_MEASURE_2_MASK)

#define LPDDR_DENALI_PHY_604_PHY_RPTR_UPDATE_2_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_604_PHY_RPTR_UPDATE_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_604_PHY_RPTR_UPDATE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_604_PHY_RPTR_UPDATE_2_SHIFT)) & LPDDR_DENALI_PHY_604_PHY_RPTR_UPDATE_2_MASK)

#define LPDDR_DENALI_PHY_604_PHY_WRLVL_DLY_STEP_2_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_604_PHY_WRLVL_DLY_STEP_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_604_PHY_WRLVL_DLY_STEP_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_604_PHY_WRLVL_DLY_STEP_2_SHIFT)) & LPDDR_DENALI_PHY_604_PHY_WRLVL_DLY_STEP_2_MASK)
/*! @} */

/*! @name DENALI_PHY_605 - DENALI_PHY_605 */
/*! @{ */

#define LPDDR_DENALI_PHY_605_PHY_WRLVL_DLY_FINE_STEP_2_MASK (0xFU)
#define LPDDR_DENALI_PHY_605_PHY_WRLVL_DLY_FINE_STEP_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_605_PHY_WRLVL_DLY_FINE_STEP_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_605_PHY_WRLVL_DLY_FINE_STEP_2_SHIFT)) & LPDDR_DENALI_PHY_605_PHY_WRLVL_DLY_FINE_STEP_2_MASK)

#define LPDDR_DENALI_PHY_605_PHY_WRLVL_RESP_WAIT_CNT_2_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_605_PHY_WRLVL_RESP_WAIT_CNT_2_SHIFT (8U)
/*! PHY_WRLVL_RESP_WAIT_CNT_2 - Defines the number of cycles to wait between dfi_wrlvl_strobe and
 *    the sampling of the DQs during write leveling for slice 2.
 */
#define LPDDR_DENALI_PHY_605_PHY_WRLVL_RESP_WAIT_CNT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_605_PHY_WRLVL_RESP_WAIT_CNT_2_SHIFT)) & LPDDR_DENALI_PHY_605_PHY_WRLVL_RESP_WAIT_CNT_2_MASK)

#define LPDDR_DENALI_PHY_605_PHY_GTLVL_DLY_STEP_2_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_605_PHY_GTLVL_DLY_STEP_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_605_PHY_GTLVL_DLY_STEP_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_605_PHY_GTLVL_DLY_STEP_2_SHIFT)) & LPDDR_DENALI_PHY_605_PHY_GTLVL_DLY_STEP_2_MASK)

#define LPDDR_DENALI_PHY_605_PHY_GTLVL_RESP_WAIT_CNT_2_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_605_PHY_GTLVL_RESP_WAIT_CNT_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_605_PHY_GTLVL_RESP_WAIT_CNT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_605_PHY_GTLVL_RESP_WAIT_CNT_2_SHIFT)) & LPDDR_DENALI_PHY_605_PHY_GTLVL_RESP_WAIT_CNT_2_MASK)
/*! @} */

/*! @name DENALI_PHY_607 - DENALI_PHY_607 */
/*! @{ */

#define LPDDR_DENALI_PHY_607_PHY_WDQLVL_DLY_STEP_2_MASK (0xFFU)
#define LPDDR_DENALI_PHY_607_PHY_WDQLVL_DLY_STEP_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_607_PHY_WDQLVL_DLY_STEP_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_607_PHY_WDQLVL_DLY_STEP_2_SHIFT)) & LPDDR_DENALI_PHY_607_PHY_WDQLVL_DLY_STEP_2_MASK)

#define LPDDR_DENALI_PHY_607_PHY_WDQLVL_QTR_DLY_STEP_2_MASK (0xF00U)
#define LPDDR_DENALI_PHY_607_PHY_WDQLVL_QTR_DLY_STEP_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_607_PHY_WDQLVL_QTR_DLY_STEP_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_607_PHY_WDQLVL_QTR_DLY_STEP_2_SHIFT)) & LPDDR_DENALI_PHY_607_PHY_WDQLVL_QTR_DLY_STEP_2_MASK)

#define LPDDR_DENALI_PHY_607_PHY_TOGGLE_PRE_SUPPORT_2_MASK (0x10000U)
#define LPDDR_DENALI_PHY_607_PHY_TOGGLE_PRE_SUPPORT_2_SHIFT (16U)
/*! PHY_TOGGLE_PRE_SUPPORT_2 - Support the toggle read preamble for LPDDR4 for slice 2.
 *  0b0..Static read preamble
 *  0b1..Toggling read preamble
 */
#define LPDDR_DENALI_PHY_607_PHY_TOGGLE_PRE_SUPPORT_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_607_PHY_TOGGLE_PRE_SUPPORT_2_SHIFT)) & LPDDR_DENALI_PHY_607_PHY_TOGGLE_PRE_SUPPORT_2_MASK)

#define LPDDR_DENALI_PHY_607_PHY_RDLVL_DLY_STEP_2_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_607_PHY_RDLVL_DLY_STEP_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_607_PHY_RDLVL_DLY_STEP_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_607_PHY_RDLVL_DLY_STEP_2_SHIFT)) & LPDDR_DENALI_PHY_607_PHY_RDLVL_DLY_STEP_2_MASK)
/*! @} */

/*! @name DENALI_PHY_608 - DENALI_PHY_608 */
/*! @{ */

#define LPDDR_DENALI_PHY_608_PHY_RDLVL_MAX_EDGE_2_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_608_PHY_RDLVL_MAX_EDGE_2_SHIFT (0U)
/*! PHY_RDLVL_MAX_EDGE_2 - Provides the maximun rdlvl slave delay search window for read eye training for slice 2. */
#define LPDDR_DENALI_PHY_608_PHY_RDLVL_MAX_EDGE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_608_PHY_RDLVL_MAX_EDGE_2_SHIFT)) & LPDDR_DENALI_PHY_608_PHY_RDLVL_MAX_EDGE_2_MASK)
/*! @} */

/*! @name DENALI_PHY_609 - DENALI_PHY_609 */
/*! @{ */

#define LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_DISABLE_2_MASK (0x3U)
#define LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_DISABLE_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_DISABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_DISABLE_2_SHIFT)) & LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_DISABLE_2_MASK)

#define LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_TIMING_2_MASK (0x700U)
#define LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_TIMING_2_SHIFT (8U)
#define LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_TIMING_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_TIMING_2_SHIFT)) & LPDDR_DENALI_PHY_609_PHY_WRPATH_GATE_TIMING_2_MASK)

#define LPDDR_DENALI_PHY_609_PHY_MEAS_DLY_STEP_ENABLE_2_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_609_PHY_MEAS_DLY_STEP_ENABLE_2_SHIFT (16U)
/*! PHY_MEAS_DLY_STEP_ENABLE_2 - Data slice training step definition using phy_meas_dly_step_value for slice 2. */
#define LPDDR_DENALI_PHY_609_PHY_MEAS_DLY_STEP_ENABLE_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_609_PHY_MEAS_DLY_STEP_ENABLE_2_SHIFT)) & LPDDR_DENALI_PHY_609_PHY_MEAS_DLY_STEP_ENABLE_2_MASK)

#define LPDDR_DENALI_PHY_609_PHY_RDDATA_EN_DLY_2_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_609_PHY_RDDATA_EN_DLY_2_SHIFT (24U)
#define LPDDR_DENALI_PHY_609_PHY_RDDATA_EN_DLY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_609_PHY_RDDATA_EN_DLY_2_SHIFT)) & LPDDR_DENALI_PHY_609_PHY_RDDATA_EN_DLY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_610 - DENALI_PHY_610 */
/*! @{ */

#define LPDDR_DENALI_PHY_610_PHY_DQ_DM_SWIZZLE0_2_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_610_PHY_DQ_DM_SWIZZLE0_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_610_PHY_DQ_DM_SWIZZLE0_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_610_PHY_DQ_DM_SWIZZLE0_2_SHIFT)) & LPDDR_DENALI_PHY_610_PHY_DQ_DM_SWIZZLE0_2_MASK)
/*! @} */

/*! @name DENALI_PHY_612 - DENALI_PHY_612 */
/*! @{ */

#define LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ0_SLAVE_DELAY_2_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ0_SLAVE_DELAY_2_SHIFT (0U)
/*! PHY_CLK_WRDQ0_SLAVE_DELAY_2 - Write clock slave delay setting for DQ0 for slice 2. */
#define LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ0_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ0_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ0_SLAVE_DELAY_2_MASK)

#define LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ1_SLAVE_DELAY_2_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ1_SLAVE_DELAY_2_SHIFT (16U)
#define LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ1_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ1_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_612_PHY_CLK_WRDQ1_SLAVE_DELAY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_613 - DENALI_PHY_613 */
/*! @{ */

#define LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ2_SLAVE_DELAY_2_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ2_SLAVE_DELAY_2_SHIFT (0U)
/*! PHY_CLK_WRDQ2_SLAVE_DELAY_2 - Write clock slave delay setting for DQ2 for slice 2. */
#define LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ2_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ2_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ2_SLAVE_DELAY_2_MASK)

#define LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ3_SLAVE_DELAY_2_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ3_SLAVE_DELAY_2_SHIFT (16U)
/*! PHY_CLK_WRDQ3_SLAVE_DELAY_2 - Write clock slave delay setting for DQ3 for slice 2. */
#define LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ3_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ3_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_613_PHY_CLK_WRDQ3_SLAVE_DELAY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_614 - DENALI_PHY_614 */
/*! @{ */

#define LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ4_SLAVE_DELAY_2_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ4_SLAVE_DELAY_2_SHIFT (0U)
/*! PHY_CLK_WRDQ4_SLAVE_DELAY_2 - Write clock slave delay setting for DQ4 for slice 2. */
#define LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ4_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ4_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ4_SLAVE_DELAY_2_MASK)

#define LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ5_SLAVE_DELAY_2_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ5_SLAVE_DELAY_2_SHIFT (16U)
/*! PHY_CLK_WRDQ5_SLAVE_DELAY_2 - Write clock slave delay setting for DQ5 for slice 2. */
#define LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ5_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ5_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_614_PHY_CLK_WRDQ5_SLAVE_DELAY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_615 - DENALI_PHY_615 */
/*! @{ */

#define LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ6_SLAVE_DELAY_2_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ6_SLAVE_DELAY_2_SHIFT (0U)
/*! PHY_CLK_WRDQ6_SLAVE_DELAY_2 - Write clock slave delay setting for DQ6 for slice 2. */
#define LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ6_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ6_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ6_SLAVE_DELAY_2_MASK)

#define LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ7_SLAVE_DELAY_2_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ7_SLAVE_DELAY_2_SHIFT (16U)
/*! PHY_CLK_WRDQ7_SLAVE_DELAY_2 - Write clock slave delay setting for DQ7 for slice 2. */
#define LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ7_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ7_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_615_PHY_CLK_WRDQ7_SLAVE_DELAY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_616 - DENALI_PHY_616 */
/*! @{ */

#define LPDDR_DENALI_PHY_616_PHY_CLK_WRDM_SLAVE_DELAY_2_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_616_PHY_CLK_WRDM_SLAVE_DELAY_2_SHIFT (0U)
/*! PHY_CLK_WRDM_SLAVE_DELAY_2 - Write clock slave delay setting for DM for slice 2. */
#define LPDDR_DENALI_PHY_616_PHY_CLK_WRDM_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_616_PHY_CLK_WRDM_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_616_PHY_CLK_WRDM_SLAVE_DELAY_2_MASK)

#define LPDDR_DENALI_PHY_616_PHY_CLK_WRDQS_SLAVE_DELAY_2_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_616_PHY_CLK_WRDQS_SLAVE_DELAY_2_SHIFT (16U)
/*! PHY_CLK_WRDQS_SLAVE_DELAY_2 - Write clock slave delay setting for DQS for slice 2. */
#define LPDDR_DENALI_PHY_616_PHY_CLK_WRDQS_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_616_PHY_CLK_WRDQS_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_616_PHY_CLK_WRDQS_SLAVE_DELAY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_626 - DENALI_PHY_626 */
/*! @{ */

#define LPDDR_DENALI_PHY_626_PHY_RDDQS_DM_FALL_SLAVE_DELAY_2_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_626_PHY_RDDQS_DM_FALL_SLAVE_DELAY_2_SHIFT (0U)
/*! PHY_RDDQS_DM_FALL_SLAVE_DELAY_2 - Falling edge read DQS slave delay setting for DM for slice 2. */
#define LPDDR_DENALI_PHY_626_PHY_RDDQS_DM_FALL_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_626_PHY_RDDQS_DM_FALL_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_626_PHY_RDDQS_DM_FALL_SLAVE_DELAY_2_MASK)

#define LPDDR_DENALI_PHY_626_PHY_RDDQS_GATE_SLAVE_DELAY_2_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_626_PHY_RDDQS_GATE_SLAVE_DELAY_2_SHIFT (16U)
/*! PHY_RDDQS_GATE_SLAVE_DELAY_2 - Read DQS slave delay setting for slice 2. */
#define LPDDR_DENALI_PHY_626_PHY_RDDQS_GATE_SLAVE_DELAY_2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_626_PHY_RDDQS_GATE_SLAVE_DELAY_2_SHIFT)) & LPDDR_DENALI_PHY_626_PHY_RDDQS_GATE_SLAVE_DELAY_2_MASK)
/*! @} */

/*! @name DENALI_PHY_799 - DENALI_PHY_799 */
/*! @{ */

#define LPDDR_DENALI_PHY_799_PHY_WRLVL_UPDT_WAIT_CNT_3_MASK (0xFU)
#define LPDDR_DENALI_PHY_799_PHY_WRLVL_UPDT_WAIT_CNT_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_799_PHY_WRLVL_UPDT_WAIT_CNT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_799_PHY_WRLVL_UPDT_WAIT_CNT_3_SHIFT)) & LPDDR_DENALI_PHY_799_PHY_WRLVL_UPDT_WAIT_CNT_3_MASK)

#define LPDDR_DENALI_PHY_799_PHY_DQ_MASK_3_MASK  (0xFF00U)
#define LPDDR_DENALI_PHY_799_PHY_DQ_MASK_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_799_PHY_DQ_MASK_3(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_799_PHY_DQ_MASK_3_SHIFT)) & LPDDR_DENALI_PHY_799_PHY_DQ_MASK_3_MASK)

#define LPDDR_DENALI_PHY_799_PHY_GTLVL_CAPTURE_CNT_3_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_799_PHY_GTLVL_CAPTURE_CNT_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_799_PHY_GTLVL_CAPTURE_CNT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_799_PHY_GTLVL_CAPTURE_CNT_3_SHIFT)) & LPDDR_DENALI_PHY_799_PHY_GTLVL_CAPTURE_CNT_3_MASK)

#define LPDDR_DENALI_PHY_799_PHY_GTLVL_UPDT_WAIT_CNT_3_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_799_PHY_GTLVL_UPDT_WAIT_CNT_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_799_PHY_GTLVL_UPDT_WAIT_CNT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_799_PHY_GTLVL_UPDT_WAIT_CNT_3_SHIFT)) & LPDDR_DENALI_PHY_799_PHY_GTLVL_UPDT_WAIT_CNT_3_MASK)
/*! @} */

/*! @name DENALI_PHY_801 - DENALI_PHY_801 */
/*! @{ */

#define LPDDR_DENALI_PHY_801_PHY_RDLVL_DATA_MASK_3_MASK (0xFFU)
#define LPDDR_DENALI_PHY_801_PHY_RDLVL_DATA_MASK_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_801_PHY_RDLVL_DATA_MASK_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_801_PHY_RDLVL_DATA_MASK_3_SHIFT)) & LPDDR_DENALI_PHY_801_PHY_RDLVL_DATA_MASK_3_MASK)

#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_CLK_JITTER_TOLERANCE_3_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_CLK_JITTER_TOLERANCE_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_CLK_JITTER_TOLERANCE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_801_PHY_WDQLVL_CLK_JITTER_TOLERANCE_3_SHIFT)) & LPDDR_DENALI_PHY_801_PHY_WDQLVL_CLK_JITTER_TOLERANCE_3_MASK)

#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_BURST_CNT_3_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_BURST_CNT_3_SHIFT (16U)
/*! PHY_WDQLVL_BURST_CNT_3 - Defines the write/read burst length in bytes during the write data leveling sequence for slice 3. */
#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_BURST_CNT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_801_PHY_WDQLVL_BURST_CNT_3_SHIFT)) & LPDDR_DENALI_PHY_801_PHY_WDQLVL_BURST_CNT_3_MASK)

#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_PATT_3_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_PATT_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_801_PHY_WDQLVL_PATT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_801_PHY_WDQLVL_PATT_3_SHIFT)) & LPDDR_DENALI_PHY_801_PHY_WDQLVL_PATT_3_MASK)
/*! @} */

/*! @name DENALI_PHY_811 - DENALI_PHY_811 */
/*! @{ */

#define LPDDR_DENALI_PHY_811_PHY_CALVL_VREF_DRIVING_SLICE_3_MASK (0x1U)
#define LPDDR_DENALI_PHY_811_PHY_CALVL_VREF_DRIVING_SLICE_3_SHIFT (0U)
/*! PHY_CALVL_VREF_DRIVING_SLICE_3 - Indicates if slice 3 is used to drive the VREF value to the device during CA training. */
#define LPDDR_DENALI_PHY_811_PHY_CALVL_VREF_DRIVING_SLICE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_811_PHY_CALVL_VREF_DRIVING_SLICE_3_SHIFT)) & LPDDR_DENALI_PHY_811_PHY_CALVL_VREF_DRIVING_SLICE_3_MASK)

#define LPDDR_DENALI_PHY_811_SC_PHY_MANUAL_CLEAR_3_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_811_SC_PHY_MANUAL_CLEAR_3_SHIFT (8U)
/*! SC_PHY_MANUAL_CLEAR_3 - Manual reset/clear of internal logic for slice 3. */
#define LPDDR_DENALI_PHY_811_SC_PHY_MANUAL_CLEAR_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_811_SC_PHY_MANUAL_CLEAR_3_SHIFT)) & LPDDR_DENALI_PHY_811_SC_PHY_MANUAL_CLEAR_3_MASK)

#define LPDDR_DENALI_PHY_811_PHY_FIFO_PTR_OBS_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_811_PHY_FIFO_PTR_OBS_3_SHIFT (16U)
/*! PHY_FIFO_PTR_OBS_3 - Observation register containing read entry FIFO pointers for slice 3. */
#define LPDDR_DENALI_PHY_811_PHY_FIFO_PTR_OBS_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_811_PHY_FIFO_PTR_OBS_3_SHIFT)) & LPDDR_DENALI_PHY_811_PHY_FIFO_PTR_OBS_3_MASK)
/*! @} */

/*! @name DENALI_PHY_840 - DENALI_PHY_840 */
/*! @{ */

#define LPDDR_DENALI_PHY_840_PHY_SLV_DLY_CTRL_GATE_DISABLE_3_MASK (0x1U)
#define LPDDR_DENALI_PHY_840_PHY_SLV_DLY_CTRL_GATE_DISABLE_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_840_PHY_SLV_DLY_CTRL_GATE_DISABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_840_PHY_SLV_DLY_CTRL_GATE_DISABLE_3_SHIFT)) & LPDDR_DENALI_PHY_840_PHY_SLV_DLY_CTRL_GATE_DISABLE_3_MASK)

#define LPDDR_DENALI_PHY_840_PHY_RDPATH_GATE_DISABLE_3_MASK (0x100U)
#define LPDDR_DENALI_PHY_840_PHY_RDPATH_GATE_DISABLE_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_840_PHY_RDPATH_GATE_DISABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_840_PHY_RDPATH_GATE_DISABLE_3_SHIFT)) & LPDDR_DENALI_PHY_840_PHY_RDPATH_GATE_DISABLE_3_MASK)

#define LPDDR_DENALI_PHY_840_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_3_MASK (0x10000U)
#define LPDDR_DENALI_PHY_840_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_840_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_840_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_3_SHIFT)) & LPDDR_DENALI_PHY_840_PHY_DCC_RXCAL_CTRL_GATE_DISABLE_3_MASK)

#define LPDDR_DENALI_PHY_840_PHY_SLICE_PWR_RDC_DISABLE_3_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_840_PHY_SLICE_PWR_RDC_DISABLE_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_840_PHY_SLICE_PWR_RDC_DISABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_840_PHY_SLICE_PWR_RDC_DISABLE_3_SHIFT)) & LPDDR_DENALI_PHY_840_PHY_SLICE_PWR_RDC_DISABLE_3_MASK)
/*! @} */

/*! @name DENALI_PHY_841 - DENALI_PHY_841 */
/*! @{ */

#define LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_ENABLE_3_MASK (0x7U)
#define LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_ENABLE_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_ENABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_ENABLE_3_SHIFT)) & LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_ENABLE_3_MASK)

#define LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_SELECT_3_MASK (0xFFFF00U)
#define LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_SELECT_3_SHIFT (8U)
/*! PHY_DQ_TSEL_SELECT_3 - Operation type tsel select values for DQ/DM signals for slice 3. */
#define LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_SELECT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_SELECT_3_SHIFT)) & LPDDR_DENALI_PHY_841_PHY_DQ_TSEL_SELECT_3_MASK)

#define LPDDR_DENALI_PHY_841_PHY_DQS_TSEL_ENABLE_3_MASK (0x7000000U)
#define LPDDR_DENALI_PHY_841_PHY_DQS_TSEL_ENABLE_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_841_PHY_DQS_TSEL_ENABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_841_PHY_DQS_TSEL_ENABLE_3_SHIFT)) & LPDDR_DENALI_PHY_841_PHY_DQS_TSEL_ENABLE_3_MASK)
/*! @} */

/*! @name DENALI_PHY_842 - DENALI_PHY_842 */
/*! @{ */

#define LPDDR_DENALI_PHY_842_PHY_DQS_TSEL_SELECT_3_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_842_PHY_DQS_TSEL_SELECT_3_SHIFT (0U)
/*! PHY_DQS_TSEL_SELECT_3 - Operation type tsel select values for DQS signals for slice 3. */
#define LPDDR_DENALI_PHY_842_PHY_DQS_TSEL_SELECT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_842_PHY_DQS_TSEL_SELECT_3_SHIFT)) & LPDDR_DENALI_PHY_842_PHY_DQS_TSEL_SELECT_3_MASK)

#define LPDDR_DENALI_PHY_842_PHY_TWO_CYC_PREAMBLE_3_MASK (0x30000U)
#define LPDDR_DENALI_PHY_842_PHY_TWO_CYC_PREAMBLE_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_842_PHY_TWO_CYC_PREAMBLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_842_PHY_TWO_CYC_PREAMBLE_3_SHIFT)) & LPDDR_DENALI_PHY_842_PHY_TWO_CYC_PREAMBLE_3_MASK)

#define LPDDR_DENALI_PHY_842_PHY_VREF_INITIAL_START_POINT_3_MASK (0x7F000000U)
#define LPDDR_DENALI_PHY_842_PHY_VREF_INITIAL_START_POINT_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_842_PHY_VREF_INITIAL_START_POINT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_842_PHY_VREF_INITIAL_START_POINT_3_SHIFT)) & LPDDR_DENALI_PHY_842_PHY_VREF_INITIAL_START_POINT_3_MASK)
/*! @} */

/*! @name DENALI_PHY_843 - DENALI_PHY_843 */
/*! @{ */

#define LPDDR_DENALI_PHY_843_PHY_VREF_INITIAL_STOP_POINT_3_MASK (0x7FU)
#define LPDDR_DENALI_PHY_843_PHY_VREF_INITIAL_STOP_POINT_3_SHIFT (0U)
/*! PHY_VREF_INITIAL_STOP_POINT_3 - Data slice initial VREF training stop value for slice 3. When
 *    programming the write DQ VREF stop point parameter, must set it equal to a multiple of the VREF
 *    (step size + start point).
 */
#define LPDDR_DENALI_PHY_843_PHY_VREF_INITIAL_STOP_POINT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_843_PHY_VREF_INITIAL_STOP_POINT_3_SHIFT)) & LPDDR_DENALI_PHY_843_PHY_VREF_INITIAL_STOP_POINT_3_MASK)

#define LPDDR_DENALI_PHY_843_PHY_VREF_TRAINING_CTRL_3_MASK (0x300U)
#define LPDDR_DENALI_PHY_843_PHY_VREF_TRAINING_CTRL_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_843_PHY_VREF_TRAINING_CTRL_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_843_PHY_VREF_TRAINING_CTRL_3_SHIFT)) & LPDDR_DENALI_PHY_843_PHY_VREF_TRAINING_CTRL_3_MASK)

#define LPDDR_DENALI_PHY_843_PHY_NTP_TRAIN_EN_3_MASK (0x10000U)
#define LPDDR_DENALI_PHY_843_PHY_NTP_TRAIN_EN_3_SHIFT (16U)
/*! PHY_NTP_TRAIN_EN_3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPDDR_DENALI_PHY_843_PHY_NTP_TRAIN_EN_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_843_PHY_NTP_TRAIN_EN_3_SHIFT)) & LPDDR_DENALI_PHY_843_PHY_NTP_TRAIN_EN_3_MASK)

#define LPDDR_DENALI_PHY_843_PHY_NTP_WDQ_STEP_SIZE_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_843_PHY_NTP_WDQ_STEP_SIZE_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_843_PHY_NTP_WDQ_STEP_SIZE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_843_PHY_NTP_WDQ_STEP_SIZE_3_SHIFT)) & LPDDR_DENALI_PHY_843_PHY_NTP_WDQ_STEP_SIZE_3_MASK)
/*! @} */

/*! @name DENALI_PHY_848 - DENALI_PHY_848 */
/*! @{ */

#define LPDDR_DENALI_PHY_848_PHY_PAD_DQS_RX_DCD_3_MASK (0x1FU)
#define LPDDR_DENALI_PHY_848_PHY_PAD_DQS_RX_DCD_3_SHIFT (0U)
/*! PHY_PAD_DQS_RX_DCD_3 - Controls RX_DCD pin for dqs pad for slice 3. */
#define LPDDR_DENALI_PHY_848_PHY_PAD_DQS_RX_DCD_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_848_PHY_PAD_DQS_RX_DCD_3_SHIFT)) & LPDDR_DENALI_PHY_848_PHY_PAD_DQS_RX_DCD_3_MASK)

#define LPDDR_DENALI_PHY_848_PHY_PAD_FDBK_RX_DCD_3_MASK (0x1F00U)
#define LPDDR_DENALI_PHY_848_PHY_PAD_FDBK_RX_DCD_3_SHIFT (8U)
/*! PHY_PAD_FDBK_RX_DCD_3 - Controls RX_DCD pin for fdbk pad for slice 3. */
#define LPDDR_DENALI_PHY_848_PHY_PAD_FDBK_RX_DCD_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_848_PHY_PAD_FDBK_RX_DCD_3_SHIFT)) & LPDDR_DENALI_PHY_848_PHY_PAD_FDBK_RX_DCD_3_MASK)

#define LPDDR_DENALI_PHY_848_PHY_PAD_DSLICE_IO_CFG_3_MASK (0x7F0000U)
#define LPDDR_DENALI_PHY_848_PHY_PAD_DSLICE_IO_CFG_3_SHIFT (16U)
/*! PHY_PAD_DSLICE_IO_CFG_3 - Controls PCLK/PARK pin for IO pad for slice 3. */
#define LPDDR_DENALI_PHY_848_PHY_PAD_DSLICE_IO_CFG_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_848_PHY_PAD_DSLICE_IO_CFG_3_SHIFT)) & LPDDR_DENALI_PHY_848_PHY_PAD_DSLICE_IO_CFG_3_MASK)
/*! @} */

/*! @name DENALI_PHY_856 - DENALI_PHY_856 */
/*! @{ */

#define LPDDR_DENALI_PHY_856_PHY_VREF_SETTING_TIME_3_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_856_PHY_VREF_SETTING_TIME_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_856_PHY_VREF_SETTING_TIME_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_856_PHY_VREF_SETTING_TIME_3_SHIFT)) & LPDDR_DENALI_PHY_856_PHY_VREF_SETTING_TIME_3_MASK)

#define LPDDR_DENALI_PHY_856_PHY_PAD_VREF_CTRL_DQ_3_MASK (0xFFF0000U)
#define LPDDR_DENALI_PHY_856_PHY_PAD_VREF_CTRL_DQ_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_856_PHY_PAD_VREF_CTRL_DQ_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_856_PHY_PAD_VREF_CTRL_DQ_3_SHIFT)) & LPDDR_DENALI_PHY_856_PHY_PAD_VREF_CTRL_DQ_3_MASK)
/*! @} */

/*! @name DENALI_PHY_857 - DENALI_PHY_857 */
/*! @{ */

#define LPDDR_DENALI_PHY_857_PHY_PER_CS_TRAINING_EN_3_MASK (0x1U)
#define LPDDR_DENALI_PHY_857_PHY_PER_CS_TRAINING_EN_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_857_PHY_PER_CS_TRAINING_EN_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_857_PHY_PER_CS_TRAINING_EN_3_SHIFT)) & LPDDR_DENALI_PHY_857_PHY_PER_CS_TRAINING_EN_3_MASK)

#define LPDDR_DENALI_PHY_857_PHY_DQ_IE_TIMING_3_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_857_PHY_DQ_IE_TIMING_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_857_PHY_DQ_IE_TIMING_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_857_PHY_DQ_IE_TIMING_3_SHIFT)) & LPDDR_DENALI_PHY_857_PHY_DQ_IE_TIMING_3_MASK)

#define LPDDR_DENALI_PHY_857_PHY_DQS_IE_TIMING_3_MASK (0xFF0000U)
#define LPDDR_DENALI_PHY_857_PHY_DQS_IE_TIMING_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_857_PHY_DQS_IE_TIMING_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_857_PHY_DQS_IE_TIMING_3_SHIFT)) & LPDDR_DENALI_PHY_857_PHY_DQS_IE_TIMING_3_MASK)

#define LPDDR_DENALI_PHY_857_PHY_RDDATA_EN_IE_DLY_3_MASK (0x3000000U)
#define LPDDR_DENALI_PHY_857_PHY_RDDATA_EN_IE_DLY_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_857_PHY_RDDATA_EN_IE_DLY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_857_PHY_RDDATA_EN_IE_DLY_3_SHIFT)) & LPDDR_DENALI_PHY_857_PHY_RDDATA_EN_IE_DLY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_858 - DENALI_PHY_858 */
/*! @{ */

#define LPDDR_DENALI_PHY_858_PHY_IE_MODE_3_MASK  (0x3U)
#define LPDDR_DENALI_PHY_858_PHY_IE_MODE_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_858_PHY_IE_MODE_3(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_858_PHY_IE_MODE_3_SHIFT)) & LPDDR_DENALI_PHY_858_PHY_IE_MODE_3_MASK)

#define LPDDR_DENALI_PHY_858_PHY_DBI_MODE_3_MASK (0x100U)
#define LPDDR_DENALI_PHY_858_PHY_DBI_MODE_3_SHIFT (8U)
/*! PHY_DBI_MODE_3
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPDDR_DENALI_PHY_858_PHY_DBI_MODE_3(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_858_PHY_DBI_MODE_3_SHIFT)) & LPDDR_DENALI_PHY_858_PHY_DBI_MODE_3_MASK)

#define LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_TSEL_DLY_3_MASK (0x1F0000U)
#define LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_TSEL_DLY_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_TSEL_DLY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_TSEL_DLY_3_SHIFT)) & LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_TSEL_DLY_3_MASK)

#define LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_OE_DLY_3_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_OE_DLY_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_OE_DLY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_OE_DLY_3_SHIFT)) & LPDDR_DENALI_PHY_858_PHY_RDDATA_EN_OE_DLY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_860 - DENALI_PHY_860 */
/*! @{ */

#define LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_WAIT_3_MASK (0xFFU)
#define LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_WAIT_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_WAIT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_WAIT_3_SHIFT)) & LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_WAIT_3_MASK)

#define LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_HALF_MEASURE_3_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_HALF_MEASURE_3_SHIFT (8U)
/*! PHY_MASTER_DELAY_HALF_MEASURE_3 - Defines the number of delay line elements to be considered in
 *    determing whether to lock to a half clock cycle in the data slice master for slice 3.
 */
#define LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_HALF_MEASURE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_HALF_MEASURE_3_SHIFT)) & LPDDR_DENALI_PHY_860_PHY_MASTER_DELAY_HALF_MEASURE_3_MASK)

#define LPDDR_DENALI_PHY_860_PHY_RPTR_UPDATE_3_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_860_PHY_RPTR_UPDATE_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_860_PHY_RPTR_UPDATE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_860_PHY_RPTR_UPDATE_3_SHIFT)) & LPDDR_DENALI_PHY_860_PHY_RPTR_UPDATE_3_MASK)

#define LPDDR_DENALI_PHY_860_PHY_WRLVL_DLY_STEP_3_MASK (0xFF000000U)
#define LPDDR_DENALI_PHY_860_PHY_WRLVL_DLY_STEP_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_860_PHY_WRLVL_DLY_STEP_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_860_PHY_WRLVL_DLY_STEP_3_SHIFT)) & LPDDR_DENALI_PHY_860_PHY_WRLVL_DLY_STEP_3_MASK)
/*! @} */

/*! @name DENALI_PHY_861 - DENALI_PHY_861 */
/*! @{ */

#define LPDDR_DENALI_PHY_861_PHY_WRLVL_DLY_FINE_STEP_3_MASK (0xFU)
#define LPDDR_DENALI_PHY_861_PHY_WRLVL_DLY_FINE_STEP_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_861_PHY_WRLVL_DLY_FINE_STEP_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_861_PHY_WRLVL_DLY_FINE_STEP_3_SHIFT)) & LPDDR_DENALI_PHY_861_PHY_WRLVL_DLY_FINE_STEP_3_MASK)

#define LPDDR_DENALI_PHY_861_PHY_WRLVL_RESP_WAIT_CNT_3_MASK (0x3F00U)
#define LPDDR_DENALI_PHY_861_PHY_WRLVL_RESP_WAIT_CNT_3_SHIFT (8U)
/*! PHY_WRLVL_RESP_WAIT_CNT_3 - Defines the number of cycles to wait between dfi_wrlvl_strobe and
 *    the sampling of the DQs during write leveling for slice 3.
 */
#define LPDDR_DENALI_PHY_861_PHY_WRLVL_RESP_WAIT_CNT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_861_PHY_WRLVL_RESP_WAIT_CNT_3_SHIFT)) & LPDDR_DENALI_PHY_861_PHY_WRLVL_RESP_WAIT_CNT_3_MASK)

#define LPDDR_DENALI_PHY_861_PHY_GTLVL_DLY_STEP_3_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_861_PHY_GTLVL_DLY_STEP_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_861_PHY_GTLVL_DLY_STEP_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_861_PHY_GTLVL_DLY_STEP_3_SHIFT)) & LPDDR_DENALI_PHY_861_PHY_GTLVL_DLY_STEP_3_MASK)

#define LPDDR_DENALI_PHY_861_PHY_GTLVL_RESP_WAIT_CNT_3_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_861_PHY_GTLVL_RESP_WAIT_CNT_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_861_PHY_GTLVL_RESP_WAIT_CNT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_861_PHY_GTLVL_RESP_WAIT_CNT_3_SHIFT)) & LPDDR_DENALI_PHY_861_PHY_GTLVL_RESP_WAIT_CNT_3_MASK)
/*! @} */

/*! @name DENALI_PHY_863 - DENALI_PHY_863 */
/*! @{ */

#define LPDDR_DENALI_PHY_863_PHY_WDQLVL_DLY_STEP_3_MASK (0xFFU)
#define LPDDR_DENALI_PHY_863_PHY_WDQLVL_DLY_STEP_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_863_PHY_WDQLVL_DLY_STEP_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_863_PHY_WDQLVL_DLY_STEP_3_SHIFT)) & LPDDR_DENALI_PHY_863_PHY_WDQLVL_DLY_STEP_3_MASK)

#define LPDDR_DENALI_PHY_863_PHY_WDQLVL_QTR_DLY_STEP_3_MASK (0xF00U)
#define LPDDR_DENALI_PHY_863_PHY_WDQLVL_QTR_DLY_STEP_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_863_PHY_WDQLVL_QTR_DLY_STEP_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_863_PHY_WDQLVL_QTR_DLY_STEP_3_SHIFT)) & LPDDR_DENALI_PHY_863_PHY_WDQLVL_QTR_DLY_STEP_3_MASK)

#define LPDDR_DENALI_PHY_863_PHY_TOGGLE_PRE_SUPPORT_3_MASK (0x10000U)
#define LPDDR_DENALI_PHY_863_PHY_TOGGLE_PRE_SUPPORT_3_SHIFT (16U)
/*! PHY_TOGGLE_PRE_SUPPORT_3 - Support the toggle read preamble for LPDDR4 for slice 3.
 *  0b0..Static read preamble
 *  0b1..Toggling read preamble
 */
#define LPDDR_DENALI_PHY_863_PHY_TOGGLE_PRE_SUPPORT_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_863_PHY_TOGGLE_PRE_SUPPORT_3_SHIFT)) & LPDDR_DENALI_PHY_863_PHY_TOGGLE_PRE_SUPPORT_3_MASK)

#define LPDDR_DENALI_PHY_863_PHY_RDLVL_DLY_STEP_3_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_863_PHY_RDLVL_DLY_STEP_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_863_PHY_RDLVL_DLY_STEP_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_863_PHY_RDLVL_DLY_STEP_3_SHIFT)) & LPDDR_DENALI_PHY_863_PHY_RDLVL_DLY_STEP_3_MASK)
/*! @} */

/*! @name DENALI_PHY_864 - DENALI_PHY_864 */
/*! @{ */

#define LPDDR_DENALI_PHY_864_PHY_RDLVL_MAX_EDGE_3_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_864_PHY_RDLVL_MAX_EDGE_3_SHIFT (0U)
/*! PHY_RDLVL_MAX_EDGE_3 - Provides the maximun rdlvl slave delay search window for read eye training for slice 3. */
#define LPDDR_DENALI_PHY_864_PHY_RDLVL_MAX_EDGE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_864_PHY_RDLVL_MAX_EDGE_3_SHIFT)) & LPDDR_DENALI_PHY_864_PHY_RDLVL_MAX_EDGE_3_MASK)
/*! @} */

/*! @name DENALI_PHY_865 - DENALI_PHY_865 */
/*! @{ */

#define LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_DISABLE_3_MASK (0x3U)
#define LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_DISABLE_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_DISABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_DISABLE_3_SHIFT)) & LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_DISABLE_3_MASK)

#define LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_TIMING_3_MASK (0x700U)
#define LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_TIMING_3_SHIFT (8U)
#define LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_TIMING_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_TIMING_3_SHIFT)) & LPDDR_DENALI_PHY_865_PHY_WRPATH_GATE_TIMING_3_MASK)

#define LPDDR_DENALI_PHY_865_PHY_MEAS_DLY_STEP_ENABLE_3_MASK (0x3F0000U)
#define LPDDR_DENALI_PHY_865_PHY_MEAS_DLY_STEP_ENABLE_3_SHIFT (16U)
/*! PHY_MEAS_DLY_STEP_ENABLE_3 - Data slice training step definition using phy_meas_dly_step_value for slice 3. */
#define LPDDR_DENALI_PHY_865_PHY_MEAS_DLY_STEP_ENABLE_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_865_PHY_MEAS_DLY_STEP_ENABLE_3_SHIFT)) & LPDDR_DENALI_PHY_865_PHY_MEAS_DLY_STEP_ENABLE_3_MASK)

#define LPDDR_DENALI_PHY_865_PHY_RDDATA_EN_DLY_3_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_865_PHY_RDDATA_EN_DLY_3_SHIFT (24U)
#define LPDDR_DENALI_PHY_865_PHY_RDDATA_EN_DLY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_865_PHY_RDDATA_EN_DLY_3_SHIFT)) & LPDDR_DENALI_PHY_865_PHY_RDDATA_EN_DLY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_866 - DENALI_PHY_866 */
/*! @{ */

#define LPDDR_DENALI_PHY_866_PHY_DQ_DM_SWIZZLE0_3_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_866_PHY_DQ_DM_SWIZZLE0_3_SHIFT (0U)
#define LPDDR_DENALI_PHY_866_PHY_DQ_DM_SWIZZLE0_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_866_PHY_DQ_DM_SWIZZLE0_3_SHIFT)) & LPDDR_DENALI_PHY_866_PHY_DQ_DM_SWIZZLE0_3_MASK)
/*! @} */

/*! @name DENALI_PHY_868 - DENALI_PHY_868 */
/*! @{ */

#define LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ0_SLAVE_DELAY_3_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ0_SLAVE_DELAY_3_SHIFT (0U)
/*! PHY_CLK_WRDQ0_SLAVE_DELAY_3 - Write clock slave delay setting for DQ0 for slice 3. */
#define LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ0_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ0_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ0_SLAVE_DELAY_3_MASK)

#define LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ1_SLAVE_DELAY_3_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ1_SLAVE_DELAY_3_SHIFT (16U)
#define LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ1_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ1_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_868_PHY_CLK_WRDQ1_SLAVE_DELAY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_869 - DENALI_PHY_869 */
/*! @{ */

#define LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ2_SLAVE_DELAY_3_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ2_SLAVE_DELAY_3_SHIFT (0U)
/*! PHY_CLK_WRDQ2_SLAVE_DELAY_3 - Write clock slave delay setting for DQ2 for slice 3. */
#define LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ2_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ2_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ2_SLAVE_DELAY_3_MASK)

#define LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ3_SLAVE_DELAY_3_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ3_SLAVE_DELAY_3_SHIFT (16U)
/*! PHY_CLK_WRDQ3_SLAVE_DELAY_3 - Write clock slave delay setting for DQ3 for slice 3. */
#define LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ3_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ3_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_869_PHY_CLK_WRDQ3_SLAVE_DELAY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_870 - DENALI_PHY_870 */
/*! @{ */

#define LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ4_SLAVE_DELAY_3_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ4_SLAVE_DELAY_3_SHIFT (0U)
/*! PHY_CLK_WRDQ4_SLAVE_DELAY_3 - Write clock slave delay setting for DQ4 for slice 3. */
#define LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ4_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ4_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ4_SLAVE_DELAY_3_MASK)

#define LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ5_SLAVE_DELAY_3_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ5_SLAVE_DELAY_3_SHIFT (16U)
/*! PHY_CLK_WRDQ5_SLAVE_DELAY_3 - Write clock slave delay setting for DQ5 for slice 3. */
#define LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ5_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ5_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_870_PHY_CLK_WRDQ5_SLAVE_DELAY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_871 - DENALI_PHY_871 */
/*! @{ */

#define LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ6_SLAVE_DELAY_3_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ6_SLAVE_DELAY_3_SHIFT (0U)
/*! PHY_CLK_WRDQ6_SLAVE_DELAY_3 - Write clock slave delay setting for DQ6 for slice 3. */
#define LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ6_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ6_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ6_SLAVE_DELAY_3_MASK)

#define LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ7_SLAVE_DELAY_3_MASK (0x7FF0000U)
#define LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ7_SLAVE_DELAY_3_SHIFT (16U)
/*! PHY_CLK_WRDQ7_SLAVE_DELAY_3 - Write clock slave delay setting for DQ7 for slice 3. */
#define LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ7_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ7_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_871_PHY_CLK_WRDQ7_SLAVE_DELAY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_872 - DENALI_PHY_872 */
/*! @{ */

#define LPDDR_DENALI_PHY_872_PHY_CLK_WRDM_SLAVE_DELAY_3_MASK (0x7FFU)
#define LPDDR_DENALI_PHY_872_PHY_CLK_WRDM_SLAVE_DELAY_3_SHIFT (0U)
/*! PHY_CLK_WRDM_SLAVE_DELAY_3 - Write clock slave delay setting for DM for slice 3. */
#define LPDDR_DENALI_PHY_872_PHY_CLK_WRDM_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_872_PHY_CLK_WRDM_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_872_PHY_CLK_WRDM_SLAVE_DELAY_3_MASK)

#define LPDDR_DENALI_PHY_872_PHY_CLK_WRDQS_SLAVE_DELAY_3_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_872_PHY_CLK_WRDQS_SLAVE_DELAY_3_SHIFT (16U)
/*! PHY_CLK_WRDQS_SLAVE_DELAY_3 - Write clock slave delay setting for DQS for slice 3. */
#define LPDDR_DENALI_PHY_872_PHY_CLK_WRDQS_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_872_PHY_CLK_WRDQS_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_872_PHY_CLK_WRDQS_SLAVE_DELAY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_882 - DENALI_PHY_882 */
/*! @{ */

#define LPDDR_DENALI_PHY_882_PHY_RDDQS_DM_FALL_SLAVE_DELAY_3_MASK (0x3FFU)
#define LPDDR_DENALI_PHY_882_PHY_RDDQS_DM_FALL_SLAVE_DELAY_3_SHIFT (0U)
/*! PHY_RDDQS_DM_FALL_SLAVE_DELAY_3 - Falling edge read DQS slave delay setting for DM for slice 3. */
#define LPDDR_DENALI_PHY_882_PHY_RDDQS_DM_FALL_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_882_PHY_RDDQS_DM_FALL_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_882_PHY_RDDQS_DM_FALL_SLAVE_DELAY_3_MASK)

#define LPDDR_DENALI_PHY_882_PHY_RDDQS_GATE_SLAVE_DELAY_3_MASK (0x3FF0000U)
#define LPDDR_DENALI_PHY_882_PHY_RDDQS_GATE_SLAVE_DELAY_3_SHIFT (16U)
/*! PHY_RDDQS_GATE_SLAVE_DELAY_3 - Read DQS slave delay setting for slice 3. */
#define LPDDR_DENALI_PHY_882_PHY_RDDQS_GATE_SLAVE_DELAY_3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_882_PHY_RDDQS_GATE_SLAVE_DELAY_3_SHIFT)) & LPDDR_DENALI_PHY_882_PHY_RDDQS_GATE_SLAVE_DELAY_3_MASK)
/*! @} */

/*! @name DENALI_PHY_1030 - DENALI_PHY_1030 */
/*! @{ */

#define LPDDR_DENALI_PHY_1030_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_0_MASK (0x1U)
#define LPDDR_DENALI_PHY_1030_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_0_SHIFT (0U)
/*! PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_0 - Power reduction slv_dly_control block gate disable for address slice 0. */
#define LPDDR_DENALI_PHY_1030_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1030_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_0_SHIFT)) & LPDDR_DENALI_PHY_1030_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_0_MASK)

#define LPDDR_DENALI_PHY_1030_PHY_ADR_TYPE_0_MASK (0x300U)
#define LPDDR_DENALI_PHY_1030_PHY_ADR_TYPE_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_1030_PHY_ADR_TYPE_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1030_PHY_ADR_TYPE_0_SHIFT)) & LPDDR_DENALI_PHY_1030_PHY_ADR_TYPE_0_MASK)

#define LPDDR_DENALI_PHY_1030_PHY_ADR_IE_MODE_0_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_1030_PHY_ADR_IE_MODE_0_SHIFT (24U)
/*! PHY_ADR_IE_MODE_0
 *  0b0..Input enables off
 *  0b1..Input enables on
 */
#define LPDDR_DENALI_PHY_1030_PHY_ADR_IE_MODE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1030_PHY_ADR_IE_MODE_0_SHIFT)) & LPDDR_DENALI_PHY_1030_PHY_ADR_IE_MODE_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1055 - DENALI_PHY_1055 */
/*! @{ */

#define LPDDR_DENALI_PHY_1055_PHY_ADR_TSEL_SELECT_0_MASK (0xFFU)
#define LPDDR_DENALI_PHY_1055_PHY_ADR_TSEL_SELECT_0_SHIFT (0U)
/*! PHY_ADR_TSEL_SELECT_0 - Tsel select values for address slice 0. */
#define LPDDR_DENALI_PHY_1055_PHY_ADR_TSEL_SELECT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1055_PHY_ADR_TSEL_SELECT_0_SHIFT)) & LPDDR_DENALI_PHY_1055_PHY_ADR_TSEL_SELECT_0_MASK)

#define LPDDR_DENALI_PHY_1055_PHY_PAD_ADR_IO_CFG_0_MASK (0x7FF00U)
#define LPDDR_DENALI_PHY_1055_PHY_PAD_ADR_IO_CFG_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_1055_PHY_PAD_ADR_IO_CFG_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1055_PHY_PAD_ADR_IO_CFG_0_SHIFT)) & LPDDR_DENALI_PHY_1055_PHY_PAD_ADR_IO_CFG_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1063 - DENALI_PHY_1063 */
/*! @{ */

#define LPDDR_DENALI_PHY_1063_PHY_ADR_MASTER_DELAY_HALF_MEASURE_0_MASK (0xFFU)
#define LPDDR_DENALI_PHY_1063_PHY_ADR_MASTER_DELAY_HALF_MEASURE_0_SHIFT (0U)
/*! PHY_ADR_MASTER_DELAY_HALF_MEASURE_0 - Defines the number of delay line elements to be considered
 *    in determing whether to lock to a half clock cycle for the master in address slice 0.
 */
#define LPDDR_DENALI_PHY_1063_PHY_ADR_MASTER_DELAY_HALF_MEASURE_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1063_PHY_ADR_MASTER_DELAY_HALF_MEASURE_0_SHIFT)) & LPDDR_DENALI_PHY_1063_PHY_ADR_MASTER_DELAY_HALF_MEASURE_0_MASK)

#define LPDDR_DENALI_PHY_1063_PHY_ADR_CALVL_DLY_STEP_0_MASK (0xF00U)
#define LPDDR_DENALI_PHY_1063_PHY_ADR_CALVL_DLY_STEP_0_SHIFT (8U)
/*! PHY_ADR_CALVL_DLY_STEP_0 - Sets the delay step size plus 1 during CA training for address slice 0. */
#define LPDDR_DENALI_PHY_1063_PHY_ADR_CALVL_DLY_STEP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1063_PHY_ADR_CALVL_DLY_STEP_0_SHIFT)) & LPDDR_DENALI_PHY_1063_PHY_ADR_CALVL_DLY_STEP_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1286 - DENALI_PHY_1286 */
/*! @{ */

#define LPDDR_DENALI_PHY_1286_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_1_MASK (0x1U)
#define LPDDR_DENALI_PHY_1286_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_1_SHIFT (0U)
/*! PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_1 - Power reduction slv_dly_control block gate disable for address slice 1. */
#define LPDDR_DENALI_PHY_1286_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1286_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_1_SHIFT)) & LPDDR_DENALI_PHY_1286_PHY_ADR_SLV_DLY_CTRL_GATE_DISABLE_1_MASK)

#define LPDDR_DENALI_PHY_1286_PHY_ADR_TYPE_1_MASK (0x300U)
#define LPDDR_DENALI_PHY_1286_PHY_ADR_TYPE_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_1286_PHY_ADR_TYPE_1(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1286_PHY_ADR_TYPE_1_SHIFT)) & LPDDR_DENALI_PHY_1286_PHY_ADR_TYPE_1_MASK)

#define LPDDR_DENALI_PHY_1286_PHY_ADR_IE_MODE_1_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_1286_PHY_ADR_IE_MODE_1_SHIFT (24U)
/*! PHY_ADR_IE_MODE_1
 *  0b0..Input enables off
 *  0b1..Input enables on
 */
#define LPDDR_DENALI_PHY_1286_PHY_ADR_IE_MODE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1286_PHY_ADR_IE_MODE_1_SHIFT)) & LPDDR_DENALI_PHY_1286_PHY_ADR_IE_MODE_1_MASK)
/*! @} */

/*! @name DENALI_PHY_1311 - DENALI_PHY_1311 */
/*! @{ */

#define LPDDR_DENALI_PHY_1311_PHY_ADR_TSEL_SELECT_1_MASK (0xFFU)
#define LPDDR_DENALI_PHY_1311_PHY_ADR_TSEL_SELECT_1_SHIFT (0U)
/*! PHY_ADR_TSEL_SELECT_1 - Tsel select values for address slice 1. */
#define LPDDR_DENALI_PHY_1311_PHY_ADR_TSEL_SELECT_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1311_PHY_ADR_TSEL_SELECT_1_SHIFT)) & LPDDR_DENALI_PHY_1311_PHY_ADR_TSEL_SELECT_1_MASK)

#define LPDDR_DENALI_PHY_1311_PHY_PAD_ADR_IO_CFG_1_MASK (0x7FF00U)
#define LPDDR_DENALI_PHY_1311_PHY_PAD_ADR_IO_CFG_1_SHIFT (8U)
#define LPDDR_DENALI_PHY_1311_PHY_PAD_ADR_IO_CFG_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1311_PHY_PAD_ADR_IO_CFG_1_SHIFT)) & LPDDR_DENALI_PHY_1311_PHY_PAD_ADR_IO_CFG_1_MASK)
/*! @} */

/*! @name DENALI_PHY_1319 - DENALI_PHY_1319 */
/*! @{ */

#define LPDDR_DENALI_PHY_1319_PHY_ADR_MASTER_DELAY_HALF_MEASURE_1_MASK (0xFFU)
#define LPDDR_DENALI_PHY_1319_PHY_ADR_MASTER_DELAY_HALF_MEASURE_1_SHIFT (0U)
/*! PHY_ADR_MASTER_DELAY_HALF_MEASURE_1 - Defines the number of delay line elements to be considered
 *    in determing whether to lock to a half clock cycle for the master in address slice 1.
 */
#define LPDDR_DENALI_PHY_1319_PHY_ADR_MASTER_DELAY_HALF_MEASURE_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1319_PHY_ADR_MASTER_DELAY_HALF_MEASURE_1_SHIFT)) & LPDDR_DENALI_PHY_1319_PHY_ADR_MASTER_DELAY_HALF_MEASURE_1_MASK)

#define LPDDR_DENALI_PHY_1319_PHY_ADR_CALVL_DLY_STEP_1_MASK (0xF00U)
#define LPDDR_DENALI_PHY_1319_PHY_ADR_CALVL_DLY_STEP_1_SHIFT (8U)
/*! PHY_ADR_CALVL_DLY_STEP_1 - Sets the delay step size plus 1 during CA training for address slice 1. */
#define LPDDR_DENALI_PHY_1319_PHY_ADR_CALVL_DLY_STEP_1(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1319_PHY_ADR_CALVL_DLY_STEP_1_SHIFT)) & LPDDR_DENALI_PHY_1319_PHY_ADR_CALVL_DLY_STEP_1_MASK)
/*! @} */

/*! @name DENALI_PHY_1536 - DENALI_PHY_1536 */
/*! @{ */

#define LPDDR_DENALI_PHY_1536_PHY_FREQ_SEL_MASK  (0x3U)
#define LPDDR_DENALI_PHY_1536_PHY_FREQ_SEL_SHIFT (0U)
/*! PHY_FREQ_SEL - Specifies which set of the frequency-dependent timing bit will be used by the PHY. */
#define LPDDR_DENALI_PHY_1536_PHY_FREQ_SEL(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1536_PHY_FREQ_SEL_SHIFT)) & LPDDR_DENALI_PHY_1536_PHY_FREQ_SEL_MASK)
/*! @} */

/*! @name DENALI_PHY_1537 - DENALI_PHY_1537 */
/*! @{ */

#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_FROM_REGIF_MASK (0x1U)
#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_FROM_REGIF_SHIFT (0U)
#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_FROM_REGIF(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_FROM_REGIF_SHIFT)) & LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_FROM_REGIF_MASK)

#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_MULTICAST_EN_MASK (0x100U)
#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_MULTICAST_EN_SHIFT (8U)
#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_MULTICAST_EN(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_MULTICAST_EN_SHIFT)) & LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_MULTICAST_EN_MASK)

#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_INDEX_MASK (0x30000U)
#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_INDEX_SHIFT (16U)
/*! PHY_FREQ_SEL_INDEX - Selects which frequency set to update when PHY_FREQ_SEL_MULTICAST_EN is not set. */
#define LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_INDEX(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_INDEX_SHIFT)) & LPDDR_DENALI_PHY_1537_PHY_FREQ_SEL_INDEX_MASK)

#define LPDDR_DENALI_PHY_1537_PHY_SW_GRP0_SHIFT_0_MASK (0x1F000000U)
#define LPDDR_DENALI_PHY_1537_PHY_SW_GRP0_SHIFT_0_SHIFT (24U)
/*! PHY_SW_GRP0_SHIFT_0 - Address slice slave delay setting for address slice 4. */
#define LPDDR_DENALI_PHY_1537_PHY_SW_GRP0_SHIFT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1537_PHY_SW_GRP0_SHIFT_0_SHIFT)) & LPDDR_DENALI_PHY_1537_PHY_SW_GRP0_SHIFT_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1547 - DENALI_PHY_1547 */
/*! @{ */

#define LPDDR_DENALI_PHY_1547_PHY_CSLVL_ENABLE_MASK (0x1U)
#define LPDDR_DENALI_PHY_1547_PHY_CSLVL_ENABLE_SHIFT (0U)
/*! PHY_CSLVL_ENABLE - CS Training Enable */
#define LPDDR_DENALI_PHY_1547_PHY_CSLVL_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1547_PHY_CSLVL_ENABLE_SHIFT)) & LPDDR_DENALI_PHY_1547_PHY_CSLVL_ENABLE_MASK)

#define LPDDR_DENALI_PHY_1547_PHY_LP4_BOOT_DISABLE_MASK (0x100U)
#define LPDDR_DENALI_PHY_1547_PHY_LP4_BOOT_DISABLE_SHIFT (8U)
#define LPDDR_DENALI_PHY_1547_PHY_LP4_BOOT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1547_PHY_LP4_BOOT_DISABLE_SHIFT)) & LPDDR_DENALI_PHY_1547_PHY_LP4_BOOT_DISABLE_MASK)
/*! @} */

/*! @name DENALI_PHY_1555 - DENALI_PHY_1555 */
/*! @{ */

#define LPDDR_DENALI_PHY_1555_PHY_LP4_BOOT_PLL_BYPASS_MASK (0x1U)
#define LPDDR_DENALI_PHY_1555_PHY_LP4_BOOT_PLL_BYPASS_SHIFT (0U)
/*! PHY_LP4_BOOT_PLL_BYPASS - PHY clock PLL bypass select. */
#define LPDDR_DENALI_PHY_1555_PHY_LP4_BOOT_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1555_PHY_LP4_BOOT_PLL_BYPASS_SHIFT)) & LPDDR_DENALI_PHY_1555_PHY_LP4_BOOT_PLL_BYPASS_MASK)
/*! @} */

/*! @name DENALI_PHY_1564 - DENALI_PHY_1564 */
/*! @{ */

#define LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_0_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_0(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_0_SHIFT)) & LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_0_MASK)

#define LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_1_MASK (0xFFFF0000U)
#define LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_1_SHIFT (16U)
#define LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_1(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_1_SHIFT)) & LPDDR_DENALI_PHY_1564_PHY_PLL_OBS_1_MASK)
/*! @} */

/*! @name DENALI_PHY_1565 - DENALI_PHY_1565 */
/*! @{ */

#define LPDDR_DENALI_PHY_1565_PHY_PLL_OBS_2_MASK (0xFFFFU)
#define LPDDR_DENALI_PHY_1565_PHY_PLL_OBS_2_SHIFT (0U)
#define LPDDR_DENALI_PHY_1565_PHY_PLL_OBS_2(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1565_PHY_PLL_OBS_2_SHIFT)) & LPDDR_DENALI_PHY_1565_PHY_PLL_OBS_2_MASK)

#define LPDDR_DENALI_PHY_1565_PHY_PLL_TESTOUT_SEL_MASK (0x30000U)
#define LPDDR_DENALI_PHY_1565_PHY_PLL_TESTOUT_SEL_SHIFT (16U)
/*! PHY_PLL_TESTOUT_SEL - PHY PLL Testout Select */
#define LPDDR_DENALI_PHY_1565_PHY_PLL_TESTOUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1565_PHY_PLL_TESTOUT_SEL_SHIFT)) & LPDDR_DENALI_PHY_1565_PHY_PLL_TESTOUT_SEL_MASK)

#define LPDDR_DENALI_PHY_1565_PHY_LP4_BOOT_LOW_FREQ_SEL_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_1565_PHY_LP4_BOOT_LOW_FREQ_SEL_SHIFT (24U)
/*! PHY_LP4_BOOT_LOW_FREQ_SEL - Control the PLL domain enter/exit from the negative clock edge for LPDDR4 boot frequency. */
#define LPDDR_DENALI_PHY_1565_PHY_LP4_BOOT_LOW_FREQ_SEL(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1565_PHY_LP4_BOOT_LOW_FREQ_SEL_SHIFT)) & LPDDR_DENALI_PHY_1565_PHY_LP4_BOOT_LOW_FREQ_SEL_MASK)
/*! @} */

/*! @name DENALI_PHY_1566 - DENALI_PHY_1566 */
/*! @{ */

#define LPDDR_DENALI_PHY_1566_PHY_TCKSRE_WAIT_MASK (0xFU)
#define LPDDR_DENALI_PHY_1566_PHY_TCKSRE_WAIT_SHIFT (0U)
/*! PHY_TCKSRE_WAIT - Specifies the number of cycles the PHY should wait before turning off the PLL for a deep sleep or DFS event. */
#define LPDDR_DENALI_PHY_1566_PHY_TCKSRE_WAIT(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1566_PHY_TCKSRE_WAIT_SHIFT)) & LPDDR_DENALI_PHY_1566_PHY_TCKSRE_WAIT_MASK)

#define LPDDR_DENALI_PHY_1566_PHY_LP_WAKEUP_MASK (0xFF00U)
#define LPDDR_DENALI_PHY_1566_PHY_LP_WAKEUP_SHIFT (8U)
/*! PHY_LP_WAKEUP - Specifies the number of cycles the PHY takes to wakeup in low power mode. */
#define LPDDR_DENALI_PHY_1566_PHY_LP_WAKEUP(x)   (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1566_PHY_LP_WAKEUP_SHIFT)) & LPDDR_DENALI_PHY_1566_PHY_LP_WAKEUP_MASK)

#define LPDDR_DENALI_PHY_1566_PHY_LS_IDLE_EN_MASK (0x10000U)
#define LPDDR_DENALI_PHY_1566_PHY_LS_IDLE_EN_SHIFT (16U)
/*! PHY_LS_IDLE_EN - Indicates the Reduced Idle Power State is enabled in low power mode. */
#define LPDDR_DENALI_PHY_1566_PHY_LS_IDLE_EN(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1566_PHY_LS_IDLE_EN_SHIFT)) & LPDDR_DENALI_PHY_1566_PHY_LS_IDLE_EN_MASK)
/*! @} */

/*! @name DENALI_PHY_1569 - DENALI_PHY_1569 */
/*! @{ */

#define LPDDR_DENALI_PHY_1569_PHY_PAD_FDBK_TERM_MASK (0x3FFFFU)
#define LPDDR_DENALI_PHY_1569_PHY_PAD_FDBK_TERM_SHIFT (0U)
/*! PHY_PAD_FDBK_TERM - Controls term settings for gate feedback pads. */
#define LPDDR_DENALI_PHY_1569_PHY_PAD_FDBK_TERM(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1569_PHY_PAD_FDBK_TERM_SHIFT)) & LPDDR_DENALI_PHY_1569_PHY_PAD_FDBK_TERM_MASK)
/*! @} */

/*! @name DENALI_PHY_1580 - DENALI_PHY_1580 */
/*! @{ */

#define LPDDR_DENALI_PHY_1580_PHY_TST_CLK_PAD_CTRL3_MASK (0x7FFFFFU)
#define LPDDR_DENALI_PHY_1580_PHY_TST_CLK_PAD_CTRL3_SHIFT (0U)
/*! PHY_TST_CLK_PAD_CTRL3 - PHY test clock pad additional controls. */
#define LPDDR_DENALI_PHY_1580_PHY_TST_CLK_PAD_CTRL3(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1580_PHY_TST_CLK_PAD_CTRL3_SHIFT)) & LPDDR_DENALI_PHY_1580_PHY_TST_CLK_PAD_CTRL3_MASK)
/*! @} */

/*! @name DENALI_PHY_1582 - DENALI_PHY_1582 */
/*! @{ */

#define LPDDR_DENALI_PHY_1582_PHY_CAL_MODE_0_MASK (0x1FFFU)
#define LPDDR_DENALI_PHY_1582_PHY_CAL_MODE_0_SHIFT (0U)
/*! PHY_CAL_MODE_0 - Pad calibration mode bits for block 0. */
#define LPDDR_DENALI_PHY_1582_PHY_CAL_MODE_0(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1582_PHY_CAL_MODE_0_SHIFT)) & LPDDR_DENALI_PHY_1582_PHY_CAL_MODE_0_MASK)

#define LPDDR_DENALI_PHY_1582_PHY_CAL_CLEAR_0_MASK (0x10000U)
#define LPDDR_DENALI_PHY_1582_PHY_CAL_CLEAR_0_SHIFT (16U)
/*! PHY_CAL_CLEAR_0 - Clear the pad calibration state machine and results for block 0. */
#define LPDDR_DENALI_PHY_1582_PHY_CAL_CLEAR_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1582_PHY_CAL_CLEAR_0_SHIFT)) & LPDDR_DENALI_PHY_1582_PHY_CAL_CLEAR_0_MASK)

#define LPDDR_DENALI_PHY_1582_PHY_CAL_START_0_MASK (0x1000000U)
#define LPDDR_DENALI_PHY_1582_PHY_CAL_START_0_SHIFT (24U)
/*! PHY_CAL_START_0 - Manual start for the pad calibration state machine for block 0. */
#define LPDDR_DENALI_PHY_1582_PHY_CAL_START_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1582_PHY_CAL_START_0_SHIFT)) & LPDDR_DENALI_PHY_1582_PHY_CAL_START_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1594 - DENALI_PHY_1594 */
/*! @{ */

#define LPDDR_DENALI_PHY_1594_PHY_ADRCTL_PVT_MAP_0_MASK (0xFFU)
#define LPDDR_DENALI_PHY_1594_PHY_ADRCTL_PVT_MAP_0_SHIFT (0U)
/*! PHY_ADRCTL_PVT_MAP_0
 *  0b00000000..Use pass 1 results
 *  0b00000001..Use pass 2 results
 */
#define LPDDR_DENALI_PHY_1594_PHY_ADRCTL_PVT_MAP_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1594_PHY_ADRCTL_PVT_MAP_0_SHIFT)) & LPDDR_DENALI_PHY_1594_PHY_ADRCTL_PVT_MAP_0_MASK)

#define LPDDR_DENALI_PHY_1594_PHY_CAL_SLOPE_ADJ_0_MASK (0xFFFFF00U)
#define LPDDR_DENALI_PHY_1594_PHY_CAL_SLOPE_ADJ_0_SHIFT (8U)
#define LPDDR_DENALI_PHY_1594_PHY_CAL_SLOPE_ADJ_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1594_PHY_CAL_SLOPE_ADJ_0_SHIFT)) & LPDDR_DENALI_PHY_1594_PHY_CAL_SLOPE_ADJ_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1607 - DENALI_PHY_1607 */
/*! @{ */

#define LPDDR_DENALI_PHY_1607_PHY_AC_SLV_DLY_CTRL_GATE_DISABLE_MASK (0x1U)
#define LPDDR_DENALI_PHY_1607_PHY_AC_SLV_DLY_CTRL_GATE_DISABLE_SHIFT (0U)
/*! PHY_AC_SLV_DLY_CTRL_GATE_DISABLE
 *  0b0..Slave delay control clock gating is enabled.
 *  0b1..Slave delay control clock gating is disabled.
 */
#define LPDDR_DENALI_PHY_1607_PHY_AC_SLV_DLY_CTRL_GATE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1607_PHY_AC_SLV_DLY_CTRL_GATE_DISABLE_SHIFT)) & LPDDR_DENALI_PHY_1607_PHY_AC_SLV_DLY_CTRL_GATE_DISABLE_MASK)
/*! @} */

/*! @name DENALI_PHY_1608 - DENALI_PHY_1608 */
/*! @{ */

#define LPDDR_DENALI_PHY_1608_PHY_DATA_BYTE_ORDER_SEL_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_1608_PHY_DATA_BYTE_ORDER_SEL_SHIFT (0U)
/*! PHY_DATA_BYTE_ORDER_SEL - Used to define the data slice's byte swap for CA bits 7:0. */
#define LPDDR_DENALI_PHY_1608_PHY_DATA_BYTE_ORDER_SEL(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1608_PHY_DATA_BYTE_ORDER_SEL_SHIFT)) & LPDDR_DENALI_PHY_1608_PHY_DATA_BYTE_ORDER_SEL_MASK)
/*! @} */

/*! @name DENALI_PHY_1622 - DENALI_PHY_1622 */
/*! @{ */

#define LPDDR_DENALI_PHY_1622_PHY_PAD_CAL_IO_CFG_0_MASK (0x3FFFFU)
#define LPDDR_DENALI_PHY_1622_PHY_PAD_CAL_IO_CFG_0_SHIFT (0U)
/*! PHY_PAD_CAL_IO_CFG_0 - Pad calibration Controls PCLK/PARK pin and vref switch. */
#define LPDDR_DENALI_PHY_1622_PHY_PAD_CAL_IO_CFG_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1622_PHY_PAD_CAL_IO_CFG_0_SHIFT)) & LPDDR_DENALI_PHY_1622_PHY_PAD_CAL_IO_CFG_0_MASK)
/*! @} */

/*! @name DENALI_PHY_1624 - DENALI_PHY_1624 */
/*! @{ */

#define LPDDR_DENALI_PHY_1624_PHY_PLL_BYPASS_MASK (0x1U)
#define LPDDR_DENALI_PHY_1624_PHY_PLL_BYPASS_SHIFT (0U)
/*! PHY_PLL_BYPASS - PHY clock PLL bypass select.
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define LPDDR_DENALI_PHY_1624_PHY_PLL_BYPASS(x)  (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1624_PHY_PLL_BYPASS_SHIFT)) & LPDDR_DENALI_PHY_1624_PHY_PLL_BYPASS_MASK)
/*! @} */

/*! @name DENALI_PHY_1625 - DENALI_PHY_1625 */
/*! @{ */

#define LPDDR_DENALI_PHY_1625_PHY_PLL_CTRL_MASK  (0x1FFFU)
#define LPDDR_DENALI_PHY_1625_PHY_PLL_CTRL_SHIFT (0U)
/*! PHY_PLL_CTRL - PHY clock PLL controls. */
#define LPDDR_DENALI_PHY_1625_PHY_PLL_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1625_PHY_PLL_CTRL_SHIFT)) & LPDDR_DENALI_PHY_1625_PHY_PLL_CTRL_MASK)

#define LPDDR_DENALI_PHY_1625_PHY_LOW_FREQ_SEL_MASK (0x10000U)
#define LPDDR_DENALI_PHY_1625_PHY_LOW_FREQ_SEL_SHIFT (16U)
#define LPDDR_DENALI_PHY_1625_PHY_LOW_FREQ_SEL(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1625_PHY_LOW_FREQ_SEL_SHIFT)) & LPDDR_DENALI_PHY_1625_PHY_LOW_FREQ_SEL_MASK)
/*! @} */

/*! @name DENALI_PHY_1626 - DENALI_PHY_1626 */
/*! @{ */

#define LPDDR_DENALI_PHY_1626_PHY_PAD_VREF_CTRL_AC_MASK (0xFFFU)
#define LPDDR_DENALI_PHY_1626_PHY_PAD_VREF_CTRL_AC_SHIFT (0U)
/*! PHY_PAD_VREF_CTRL_AC - Defines the pad VREF control settings for the address/control. */
#define LPDDR_DENALI_PHY_1626_PHY_PAD_VREF_CTRL_AC(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1626_PHY_PAD_VREF_CTRL_AC_SHIFT)) & LPDDR_DENALI_PHY_1626_PHY_PAD_VREF_CTRL_AC_MASK)

#define LPDDR_DENALI_PHY_1626_PHY_CSLVL_CAPTURE_CNT_MASK (0xF0000U)
#define LPDDR_DENALI_PHY_1626_PHY_CSLVL_CAPTURE_CNT_SHIFT (16U)
/*! PHY_CSLVL_CAPTURE_CNT - Defines the number of samples to take at each GRP slave delay setting during CS training. */
#define LPDDR_DENALI_PHY_1626_PHY_CSLVL_CAPTURE_CNT(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1626_PHY_CSLVL_CAPTURE_CNT_SHIFT)) & LPDDR_DENALI_PHY_1626_PHY_CSLVL_CAPTURE_CNT_MASK)

#define LPDDR_DENALI_PHY_1626_PHY_CSLVL_DLY_STEP_MASK (0xF000000U)
#define LPDDR_DENALI_PHY_1626_PHY_CSLVL_DLY_STEP_SHIFT (24U)
/*! PHY_CSLVL_DLY_STEP - Sets the delay step size plus 1 during CS training. */
#define LPDDR_DENALI_PHY_1626_PHY_CSLVL_DLY_STEP(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1626_PHY_CSLVL_DLY_STEP_SHIFT)) & LPDDR_DENALI_PHY_1626_PHY_CSLVL_DLY_STEP_MASK)
/*! @} */

/*! @name DENALI_PHY_1635 - DENALI_PHY_1635 */
/*! @{ */

#define LPDDR_DENALI_PHY_1635_PHY_PAD_FDBK_DRIVE_MASK (0x3FFFFFFFU)
#define LPDDR_DENALI_PHY_1635_PHY_PAD_FDBK_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1635_PHY_PAD_FDBK_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1635_PHY_PAD_FDBK_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1635_PHY_PAD_FDBK_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1636 - DENALI_PHY_1636 */
/*! @{ */

#define LPDDR_DENALI_PHY_1636_PHY_PAD_FDBK_DRIVE2_MASK (0x7FFFFU)
#define LPDDR_DENALI_PHY_1636_PHY_PAD_FDBK_DRIVE2_SHIFT (0U)
/*! PHY_PAD_FDBK_DRIVE2 - Controls drive settings (enslice/boost) for gate feedback pads. */
#define LPDDR_DENALI_PHY_1636_PHY_PAD_FDBK_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1636_PHY_PAD_FDBK_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1636_PHY_PAD_FDBK_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1637 - DENALI_PHY_1637 */
/*! @{ */

#define LPDDR_DENALI_PHY_1637_PHY_PAD_DATA_DRIVE_MASK (0x7FFFFFFFU)
#define LPDDR_DENALI_PHY_1637_PHY_PAD_DATA_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1637_PHY_PAD_DATA_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1637_PHY_PAD_DATA_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1637_PHY_PAD_DATA_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1639 - DENALI_PHY_1639 */
/*! @{ */

#define LPDDR_DENALI_PHY_1639_PHY_PAD_DQS_DRIVE_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_1639_PHY_PAD_DQS_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1639_PHY_PAD_DQS_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1639_PHY_PAD_DQS_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1639_PHY_PAD_DQS_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1641 - DENALI_PHY_1641 */
/*! @{ */

#define LPDDR_DENALI_PHY_1641_PHY_PAD_ADDR_DRIVE_MASK (0x3FFFFFFFU)
#define LPDDR_DENALI_PHY_1641_PHY_PAD_ADDR_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1641_PHY_PAD_ADDR_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1641_PHY_PAD_ADDR_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1641_PHY_PAD_ADDR_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1642 - DENALI_PHY_1642 */
/*! @{ */

#define LPDDR_DENALI_PHY_1642_PHY_PAD_ADDR_DRIVE2_MASK (0x1FFFFFFFU)
#define LPDDR_DENALI_PHY_1642_PHY_PAD_ADDR_DRIVE2_SHIFT (0U)
/*! PHY_PAD_ADDR_DRIVE2 - Controls drive settings for the address/control pads. */
#define LPDDR_DENALI_PHY_1642_PHY_PAD_ADDR_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1642_PHY_PAD_ADDR_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1642_PHY_PAD_ADDR_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1643 - DENALI_PHY_1643 */
/*! @{ */

#define LPDDR_DENALI_PHY_1643_PHY_PAD_CLK_DRIVE_MASK (0xFFFFFFFFU)
#define LPDDR_DENALI_PHY_1643_PHY_PAD_CLK_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1643_PHY_PAD_CLK_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1643_PHY_PAD_CLK_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1643_PHY_PAD_CLK_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1644 - DENALI_PHY_1644 */
/*! @{ */

#define LPDDR_DENALI_PHY_1644_PHY_PAD_CLK_DRIVE2_MASK (0xFFFFFU)
#define LPDDR_DENALI_PHY_1644_PHY_PAD_CLK_DRIVE2_SHIFT (0U)
/*! PHY_PAD_CLK_DRIVE2 - Controls drive settings for clock pads. */
#define LPDDR_DENALI_PHY_1644_PHY_PAD_CLK_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1644_PHY_PAD_CLK_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1644_PHY_PAD_CLK_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1645 - DENALI_PHY_1645 */
/*! @{ */

#define LPDDR_DENALI_PHY_1645_PHY_PAD_CKE_DRIVE_MASK (0x3FFFFFFFU)
#define LPDDR_DENALI_PHY_1645_PHY_PAD_CKE_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1645_PHY_PAD_CKE_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1645_PHY_PAD_CKE_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1645_PHY_PAD_CKE_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1646 - DENALI_PHY_1646 */
/*! @{ */

#define LPDDR_DENALI_PHY_1646_PHY_PAD_CKE_DRIVE2_MASK (0x1FFFFFFFU)
#define LPDDR_DENALI_PHY_1646_PHY_PAD_CKE_DRIVE2_SHIFT (0U)
/*! PHY_PAD_CKE_DRIVE2 - Controls drive settings for CKE pads. */
#define LPDDR_DENALI_PHY_1646_PHY_PAD_CKE_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1646_PHY_PAD_CKE_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1646_PHY_PAD_CKE_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1647 - DENALI_PHY_1647 */
/*! @{ */

#define LPDDR_DENALI_PHY_1647_PHY_PAD_RST_DRIVE_MASK (0x3FFFFFFFU)
#define LPDDR_DENALI_PHY_1647_PHY_PAD_RST_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1647_PHY_PAD_RST_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1647_PHY_PAD_RST_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1647_PHY_PAD_RST_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1648 - DENALI_PHY_1648 */
/*! @{ */

#define LPDDR_DENALI_PHY_1648_PHY_PAD_RST_DRIVE2_MASK (0x1FFFFFFFU)
#define LPDDR_DENALI_PHY_1648_PHY_PAD_RST_DRIVE2_SHIFT (0U)
/*! PHY_PAD_RST_DRIVE2 - Controls drive settings for reset_n pads. */
#define LPDDR_DENALI_PHY_1648_PHY_PAD_RST_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1648_PHY_PAD_RST_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1648_PHY_PAD_RST_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1649 - DENALI_PHY_1649 */
/*! @{ */

#define LPDDR_DENALI_PHY_1649_PHY_PAD_CS_DRIVE_MASK (0x3FFFFFFFU)
#define LPDDR_DENALI_PHY_1649_PHY_PAD_CS_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1649_PHY_PAD_CS_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1649_PHY_PAD_CS_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1649_PHY_PAD_CS_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1650 - DENALI_PHY_1650 */
/*! @{ */

#define LPDDR_DENALI_PHY_1650_PHY_PAD_CS_DRIVE2_MASK (0x1FFFFFFFU)
#define LPDDR_DENALI_PHY_1650_PHY_PAD_CS_DRIVE2_SHIFT (0U)
/*! PHY_PAD_CS_DRIVE2 - Controls drive settings for CS pads. */
#define LPDDR_DENALI_PHY_1650_PHY_PAD_CS_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1650_PHY_PAD_CS_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1650_PHY_PAD_CS_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1651 - DENALI_PHY_1651 */
/*! @{ */

#define LPDDR_DENALI_PHY_1651_PHY_PAD_ODT_DRIVE_MASK (0x3FFFFFFFU)
#define LPDDR_DENALI_PHY_1651_PHY_PAD_ODT_DRIVE_SHIFT (0U)
#define LPDDR_DENALI_PHY_1651_PHY_PAD_ODT_DRIVE(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1651_PHY_PAD_ODT_DRIVE_SHIFT)) & LPDDR_DENALI_PHY_1651_PHY_PAD_ODT_DRIVE_MASK)
/*! @} */

/*! @name DENALI_PHY_1652 - DENALI_PHY_1652 */
/*! @{ */

#define LPDDR_DENALI_PHY_1652_PHY_PAD_ODT_DRIVE2_MASK (0x1FFFFFFFU)
#define LPDDR_DENALI_PHY_1652_PHY_PAD_ODT_DRIVE2_SHIFT (0U)
/*! PHY_PAD_ODT_DRIVE2 - Controls drive settings for ODT pads. */
#define LPDDR_DENALI_PHY_1652_PHY_PAD_ODT_DRIVE2(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1652_PHY_PAD_ODT_DRIVE2_SHIFT)) & LPDDR_DENALI_PHY_1652_PHY_PAD_ODT_DRIVE2_MASK)
/*! @} */

/*! @name DENALI_PHY_1653 - DENALI_PHY_1653 */
/*! @{ */

#define LPDDR_DENALI_PHY_1653_PHY_CAL_CLK_SELECT_0_MASK (0x7U)
#define LPDDR_DENALI_PHY_1653_PHY_CAL_CLK_SELECT_0_SHIFT (0U)
#define LPDDR_DENALI_PHY_1653_PHY_CAL_CLK_SELECT_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1653_PHY_CAL_CLK_SELECT_0_SHIFT)) & LPDDR_DENALI_PHY_1653_PHY_CAL_CLK_SELECT_0_MASK)

#define LPDDR_DENALI_PHY_1653_PHY_CAL_VREF_SWITCH_TIMER_0_MASK (0xFFFF00U)
#define LPDDR_DENALI_PHY_1653_PHY_CAL_VREF_SWITCH_TIMER_0_SHIFT (8U)
/*! PHY_CAL_VREF_SWITCH_TIMER_0 - The settling time for a switch in VREF during IO pad calibration. */
#define LPDDR_DENALI_PHY_1653_PHY_CAL_VREF_SWITCH_TIMER_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1653_PHY_CAL_VREF_SWITCH_TIMER_0_SHIFT)) & LPDDR_DENALI_PHY_1653_PHY_CAL_VREF_SWITCH_TIMER_0_MASK)

#define LPDDR_DENALI_PHY_1653_PHY_CAL_SETTLING_PRD_0_MASK (0x7F000000U)
#define LPDDR_DENALI_PHY_1653_PHY_CAL_SETTLING_PRD_0_SHIFT (24U)
/*! PHY_CAL_SETTLING_PRD_0 - Number of clock cycles to extend dfi_phyupd_req after the dfi_phyupd_ack is received for settling of final values. */
#define LPDDR_DENALI_PHY_1653_PHY_CAL_SETTLING_PRD_0(x) (((uint32_t)(((uint32_t)(x)) << LPDDR_DENALI_PHY_1653_PHY_CAL_SETTLING_PRD_0_SHIFT)) & LPDDR_DENALI_PHY_1653_PHY_CAL_SETTLING_PRD_0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPDDR_Register_Masks */


/*!
 * @}
 */ /* end of group LPDDR_Peripheral_Access_Layer */


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


#endif  /* PERI_LPDDR_H_ */

