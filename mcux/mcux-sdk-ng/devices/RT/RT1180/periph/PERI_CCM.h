/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CCM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CCM
 *
 * CMSIS Peripheral Access Layer for CCM
 */

#if !defined(PERI_CCM_H_)
#define PERI_CCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Size of Registers Arrays */
#define CCM_CLOCK_ROOT_COUNT                      74u
#define CCM_OBSERVE_COUNT                         2u
#define CCM_GPR_SHARED_STATUS_COUNT               8u
#define CCM_GPR_PRIVATE_COUNT                     4u
#define CCM_OSCPLL_COUNT                          25u
#define CCM_LPCG_COUNT                            149u

/** CCM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x80 */
    __IO uint32_t CONTROL;                           /**< Clock Root Control Register, array offset: 0x0, array step: 0x80 */
    __IO uint32_t CONTROL_SET;                       /**< Clock Root Control Register, array offset: 0x4, array step: 0x80 */
    __IO uint32_t CONTROL_CLR;                       /**< Clock Root Control Register, array offset: 0x8, array step: 0x80 */
    __IO uint32_t CONTROL_TOG;                       /**< Clock Root Control Register, array offset: 0xC, array step: 0x80 */
         uint8_t RESERVED_0[16];
    __I  uint32_t STATUS0;                           /**< Clock root working status, array offset: 0x20, array step: 0x80 */
         uint8_t RESERVED_1[12];
    __IO uint32_t AUTHEN;                            /**< Clock root access control, array offset: 0x30, array step: 0x80 */
         uint8_t RESERVED_2[76];
  } CLOCK_ROOT[CCM_CLOCK_ROOT_COUNT];
       uint8_t RESERVED_0[7936];
  struct {                                         /* offset: 0x4400, array step: 0x80 */
    __IO uint32_t CONTROL;                           /**< Observe control, array offset: 0x4400, array step: 0x80 */
    __IO uint32_t CONTROL_SET;                       /**< Observe control, array offset: 0x4404, array step: 0x80 */
    __IO uint32_t CONTROL_CLR;                       /**< Observe control, array offset: 0x4408, array step: 0x80 */
    __IO uint32_t CONTROL_TOG;                       /**< Observe control, array offset: 0x440C, array step: 0x80 */
         uint8_t RESERVED_0[16];
    __I  uint32_t STATUS;                            /**< Observe status, array offset: 0x4420, array step: 0x80 */
         uint8_t RESERVED_1[12];
    __IO uint32_t AUTHEN;                            /**< Observe access control, array offset: 0x4430, array step: 0x80 */
    __IO uint32_t AUTHEN_SET;                        /**< Observe access control, array offset: 0x4434, array step: 0x80 */
    __IO uint32_t AUTHEN_CLR;                        /**< Observe access control, array offset: 0x4438, array step: 0x80 */
    __IO uint32_t AUTHEN_TOG;                        /**< Observe access control, array offset: 0x443C, array step: 0x80 */
    __I  uint32_t FREQUENCY_CURRENT;                 /**< Current frequency detected, array offset: 0x4440, array step: 0x80 */
    __I  uint32_t FREQUENCY_MIN;                     /**< Minimum frequency detected, array offset: 0x4444, array step: 0x80 */
    __I  uint32_t FREQUENCY_MAX;                     /**< Maximum frequency detected, array offset: 0x4448, array step: 0x80 */
         uint8_t RESERVED_2[4];
    __I  uint32_t PERIOD_CURRENT;                    /**< Current period time detected, array offset: 0x4450, array step: 0x80 */
    __I  uint32_t PERIOD_MIN;                        /**< Minimum period time detected, array offset: 0x4454, array step: 0x80 */
    __I  uint32_t PERIOD_MAX;                        /**< Maximum period time detected, array offset: 0x4458, array step: 0x80 */
         uint8_t RESERVED_3[4];
    __I  uint32_t HIGH_CURRENT;                      /**< Current high level time detected, array offset: 0x4460, array step: 0x80 */
    __I  uint32_t HIGH_MIN;                          /**< Minimum high level time detected, array offset: 0x4464, array step: 0x80 */
    __I  uint32_t HIGH_MAX;                          /**< Maximum high level time detected, array offset: 0x4468, array step: 0x80 */
         uint8_t RESERVED_4[4];
    __I  uint32_t LOW_CURRENT;                       /**< Current high level time detected, array offset: 0x4470, array step: 0x80 */
    __I  uint32_t LOW_MIN;                           /**< Minimum high level time detected, array offset: 0x4474, array step: 0x80 */
    __I  uint32_t LOW_MAX;                           /**< Maximum high level time detected, array offset: 0x4478, array step: 0x80 */
         uint8_t RESERVED_5[4];
  } OBSERVE[CCM_OBSERVE_COUNT];
       uint8_t RESERVED_1[768];
       uint32_t GPR_SHARED0;                       /**< General Purpose Register, offset: 0x4800 */
       uint32_t GPR_SHARED0_SET;                   /**< General Purpose Register, offset: 0x4804 */
       uint32_t GPR_SHARED0_CLR;                   /**< General Purpose Register, offset: 0x4808 */
       uint32_t GPR_SHARED0_TOG;                   /**< General Purpose Register, offset: 0x480C */
  __IO uint32_t GPR_SHARED0_AUTHEN;                /**< GPR access control, offset: 0x4810 */
  __IO uint32_t GPR_SHARED0_AUTHEN_SET;            /**< GPR access control, offset: 0x4814 */
  __IO uint32_t GPR_SHARED0_AUTHEN_CLR;            /**< GPR access control, offset: 0x4818 */
  __IO uint32_t GPR_SHARED0_AUTHEN_TOG;            /**< GPR access control, offset: 0x481C */
       uint32_t GPR_SHARED1;                       /**< General Purpose Register, offset: 0x4820 */
       uint32_t GPR_SHARED1_SET;                   /**< General Purpose Register, offset: 0x4824 */
       uint32_t GPR_SHARED1_CLR;                   /**< General Purpose Register, offset: 0x4828 */
       uint32_t GPR_SHARED1_TOG;                   /**< General Purpose Register, offset: 0x482C */
  __IO uint32_t GPR_SHARED1_AUTHEN;                /**< GPR access control, offset: 0x4830 */
  __IO uint32_t GPR_SHARED1_AUTHEN_SET;            /**< GPR access control, offset: 0x4834 */
  __IO uint32_t GPR_SHARED1_AUTHEN_CLR;            /**< GPR access control, offset: 0x4838 */
  __IO uint32_t GPR_SHARED1_AUTHEN_TOG;            /**< GPR access control, offset: 0x483C */
  __IO uint32_t GPR_SHARED2;                       /**< General Purpose Register, offset: 0x4840 */
  __IO uint32_t GPR_SHARED2_SET;                   /**< General Purpose Register, offset: 0x4844 */
  __IO uint32_t GPR_SHARED2_CLR;                   /**< General Purpose Register, offset: 0x4848 */
  __IO uint32_t GPR_SHARED2_TOG;                   /**< General Purpose Register, offset: 0x484C */
  __IO uint32_t GPR_SHARED2_AUTHEN;                /**< GPR access control, offset: 0x4850 */
  __IO uint32_t GPR_SHARED2_AUTHEN_SET;            /**< GPR access control, offset: 0x4854 */
  __IO uint32_t GPR_SHARED2_AUTHEN_CLR;            /**< GPR access control, offset: 0x4858 */
  __IO uint32_t GPR_SHARED2_AUTHEN_TOG;            /**< GPR access control, offset: 0x485C */
  __IO uint32_t GPR_SHARED3;                       /**< General Purpose Register, offset: 0x4860 */
  __IO uint32_t GPR_SHARED3_SET;                   /**< General Purpose Register, offset: 0x4864 */
  __IO uint32_t GPR_SHARED3_CLR;                   /**< General Purpose Register, offset: 0x4868 */
  __IO uint32_t GPR_SHARED3_TOG;                   /**< General Purpose Register, offset: 0x486C */
  __IO uint32_t GPR_SHARED3_AUTHEN;                /**< GPR access control, offset: 0x4870 */
  __IO uint32_t GPR_SHARED3_AUTHEN_SET;            /**< GPR access control, offset: 0x4874 */
  __IO uint32_t GPR_SHARED3_AUTHEN_CLR;            /**< GPR access control, offset: 0x4878 */
  __IO uint32_t GPR_SHARED3_AUTHEN_TOG;            /**< GPR access control, offset: 0x487C */
  __IO uint32_t GPR_SHARED4;                       /**< General Purpose Register, offset: 0x4880 */
  __IO uint32_t GPR_SHARED4_SET;                   /**< General Purpose Register, offset: 0x4884 */
  __IO uint32_t GPR_SHARED4_CLR;                   /**< General Purpose Register, offset: 0x4888 */
  __IO uint32_t GPR_SHARED4_TOG;                   /**< General Purpose Register, offset: 0x488C */
  __IO uint32_t GPR_SHARED4_AUTHEN;                /**< GPR access control, offset: 0x4890 */
  __IO uint32_t GPR_SHARED4_AUTHEN_SET;            /**< GPR access control, offset: 0x4894 */
  __IO uint32_t GPR_SHARED4_AUTHEN_CLR;            /**< GPR access control, offset: 0x4898 */
  __IO uint32_t GPR_SHARED4_AUTHEN_TOG;            /**< GPR access control, offset: 0x489C */
  __IO uint32_t GPR_SHARED5;                       /**< General Purpose Register, offset: 0x48A0 */
  __IO uint32_t GPR_SHARED5_SET;                   /**< General Purpose Register, offset: 0x48A4 */
  __IO uint32_t GPR_SHARED5_CLR;                   /**< General Purpose Register, offset: 0x48A8 */
  __IO uint32_t GPR_SHARED5_TOG;                   /**< General Purpose Register, offset: 0x48AC */
  __IO uint32_t GPR_SHARED5_AUTHEN;                /**< GPR access control, offset: 0x48B0 */
  __IO uint32_t GPR_SHARED5_AUTHEN_SET;            /**< GPR access control, offset: 0x48B4 */
  __IO uint32_t GPR_SHARED5_AUTHEN_CLR;            /**< GPR access control, offset: 0x48B8 */
  __IO uint32_t GPR_SHARED5_AUTHEN_TOG;            /**< GPR access control, offset: 0x48BC */
  __IO uint32_t GPR_SHARED6;                       /**< General Purpose Register, offset: 0x48C0 */
  __IO uint32_t GPR_SHARED6_SET;                   /**< General Purpose Register, offset: 0x48C4 */
  __IO uint32_t GPR_SHARED6_CLR;                   /**< General Purpose Register, offset: 0x48C8 */
  __IO uint32_t GPR_SHARED6_TOG;                   /**< General Purpose Register, offset: 0x48CC */
  __IO uint32_t GPR_SHARED6_AUTHEN;                /**< GPR access control, offset: 0x48D0 */
  __IO uint32_t GPR_SHARED6_AUTHEN_SET;            /**< GPR access control, offset: 0x48D4 */
  __IO uint32_t GPR_SHARED6_AUTHEN_CLR;            /**< GPR access control, offset: 0x48D8 */
  __IO uint32_t GPR_SHARED6_AUTHEN_TOG;            /**< GPR access control, offset: 0x48DC */
  __IO uint32_t GPR_SHARED7;                       /**< General Purpose Register, offset: 0x48E0 */
  __IO uint32_t GPR_SHARED7_SET;                   /**< General Purpose Register, offset: 0x48E4 */
  __IO uint32_t GPR_SHARED7_CLR;                   /**< General Purpose Register, offset: 0x48E8 */
  __IO uint32_t GPR_SHARED7_TOG;                   /**< General Purpose Register, offset: 0x48EC */
  __IO uint32_t GPR_SHARED7_AUTHEN;                /**< GPR access control, offset: 0x48F0 */
  __IO uint32_t GPR_SHARED7_AUTHEN_SET;            /**< GPR access control, offset: 0x48F4 */
  __IO uint32_t GPR_SHARED7_AUTHEN_CLR;            /**< GPR access control, offset: 0x48F8 */
  __IO uint32_t GPR_SHARED7_AUTHEN_TOG;            /**< GPR access control, offset: 0x48FC */
  __IO uint32_t GPR_SHARED8;                       /**< General Purpose Register, offset: 0x4900 */
  __IO uint32_t GPR_SHARED8_SET;                   /**< General Purpose Register, offset: 0x4904 */
  __IO uint32_t GPR_SHARED8_CLR;                   /**< General Purpose Register, offset: 0x4908 */
  __IO uint32_t GPR_SHARED8_TOG;                   /**< General Purpose Register, offset: 0x490C */
  __IO uint32_t GPR_SHARED8_AUTHEN;                /**< GPR access control, offset: 0x4910 */
  __IO uint32_t GPR_SHARED8_AUTHEN_SET;            /**< GPR access control, offset: 0x4914 */
  __IO uint32_t GPR_SHARED8_AUTHEN_CLR;            /**< GPR access control, offset: 0x4918 */
  __IO uint32_t GPR_SHARED8_AUTHEN_TOG;            /**< GPR access control, offset: 0x491C */
  __IO uint32_t GPR_SHARED9;                       /**< General Purpose Register, offset: 0x4920 */
  __IO uint32_t GPR_SHARED9_SET;                   /**< General Purpose Register, offset: 0x4924 */
  __IO uint32_t GPR_SHARED9_CLR;                   /**< General Purpose Register, offset: 0x4928 */
  __IO uint32_t GPR_SHARED9_TOG;                   /**< General Purpose Register, offset: 0x492C */
  __IO uint32_t GPR_SHARED9_AUTHEN;                /**< GPR access control, offset: 0x4930 */
  __IO uint32_t GPR_SHARED9_AUTHEN_SET;            /**< GPR access control, offset: 0x4934 */
  __IO uint32_t GPR_SHARED9_AUTHEN_CLR;            /**< GPR access control, offset: 0x4938 */
  __IO uint32_t GPR_SHARED9_AUTHEN_TOG;            /**< GPR access control, offset: 0x493C */
  __IO uint32_t GPR_SHARED10;                      /**< General Purpose Register, offset: 0x4940 */
  __IO uint32_t GPR_SHARED10_SET;                  /**< General Purpose Register, offset: 0x4944 */
  __IO uint32_t GPR_SHARED10_CLR;                  /**< General Purpose Register, offset: 0x4948 */
  __IO uint32_t GPR_SHARED10_TOG;                  /**< General Purpose Register, offset: 0x494C */
  __IO uint32_t GPR_SHARED10_AUTHEN;               /**< GPR access control, offset: 0x4950 */
  __IO uint32_t GPR_SHARED10_AUTHEN_SET;           /**< GPR access control, offset: 0x4954 */
  __IO uint32_t GPR_SHARED10_AUTHEN_CLR;           /**< GPR access control, offset: 0x4958 */
  __IO uint32_t GPR_SHARED10_AUTHEN_TOG;           /**< GPR access control, offset: 0x495C */
  __IO uint32_t GPR_SHARED11;                      /**< General Purpose Register, offset: 0x4960 */
  __IO uint32_t GPR_SHARED11_SET;                  /**< General Purpose Register, offset: 0x4964 */
  __IO uint32_t GPR_SHARED11_CLR;                  /**< General Purpose Register, offset: 0x4968 */
  __IO uint32_t GPR_SHARED11_TOG;                  /**< General Purpose Register, offset: 0x496C */
  __IO uint32_t GPR_SHARED11_AUTHEN;               /**< GPR access control, offset: 0x4970 */
  __IO uint32_t GPR_SHARED11_AUTHEN_SET;           /**< GPR access control, offset: 0x4974 */
  __IO uint32_t GPR_SHARED11_AUTHEN_CLR;           /**< GPR access control, offset: 0x4978 */
  __IO uint32_t GPR_SHARED11_AUTHEN_TOG;           /**< GPR access control, offset: 0x497C */
  __IO uint32_t GPR_SHARED12;                      /**< General Purpose Register, offset: 0x4980 */
  __IO uint32_t GPR_SHARED12_SET;                  /**< General Purpose Register, offset: 0x4984 */
  __IO uint32_t GPR_SHARED12_CLR;                  /**< General Purpose Register, offset: 0x4988 */
  __IO uint32_t GPR_SHARED12_TOG;                  /**< General Purpose Register, offset: 0x498C */
  __IO uint32_t GPR_SHARED12_AUTHEN;               /**< GPR access control, offset: 0x4990 */
  __IO uint32_t GPR_SHARED12_AUTHEN_SET;           /**< GPR access control, offset: 0x4994 */
  __IO uint32_t GPR_SHARED12_AUTHEN_CLR;           /**< GPR access control, offset: 0x4998 */
  __IO uint32_t GPR_SHARED12_AUTHEN_TOG;           /**< GPR access control, offset: 0x499C */
  __IO uint32_t GPR_SHARED13;                      /**< General Purpose Register, offset: 0x49A0 */
  __IO uint32_t GPR_SHARED13_SET;                  /**< General Purpose Register, offset: 0x49A4 */
  __IO uint32_t GPR_SHARED13_CLR;                  /**< General Purpose Register, offset: 0x49A8 */
  __IO uint32_t GPR_SHARED13_TOG;                  /**< General Purpose Register, offset: 0x49AC */
  __IO uint32_t GPR_SHARED13_AUTHEN;               /**< GPR access control, offset: 0x49B0 */
  __IO uint32_t GPR_SHARED13_AUTHEN_SET;           /**< GPR access control, offset: 0x49B4 */
  __IO uint32_t GPR_SHARED13_AUTHEN_CLR;           /**< GPR access control, offset: 0x49B8 */
  __IO uint32_t GPR_SHARED13_AUTHEN_TOG;           /**< GPR access control, offset: 0x49BC */
  __IO uint32_t GPR_SHARED14;                      /**< General Purpose Register, offset: 0x49C0 */
  __IO uint32_t GPR_SHARED14_SET;                  /**< General Purpose Register, offset: 0x49C4 */
  __IO uint32_t GPR_SHARED14_CLR;                  /**< General Purpose Register, offset: 0x49C8 */
  __IO uint32_t GPR_SHARED14_TOG;                  /**< General Purpose Register, offset: 0x49CC */
  __IO uint32_t GPR_SHARED14_AUTHEN;               /**< GPR access control, offset: 0x49D0 */
  __IO uint32_t GPR_SHARED14_AUTHEN_SET;           /**< GPR access control, offset: 0x49D4 */
  __IO uint32_t GPR_SHARED14_AUTHEN_CLR;           /**< GPR access control, offset: 0x49D8 */
  __IO uint32_t GPR_SHARED14_AUTHEN_TOG;           /**< GPR access control, offset: 0x49DC */
  __IO uint32_t GPR_SHARED15;                      /**< General Purpose Register, offset: 0x49E0 */
  __IO uint32_t GPR_SHARED15_SET;                  /**< General Purpose Register, offset: 0x49E4 */
  __IO uint32_t GPR_SHARED15_CLR;                  /**< General Purpose Register, offset: 0x49E8 */
  __IO uint32_t GPR_SHARED15_TOG;                  /**< General Purpose Register, offset: 0x49EC */
  __IO uint32_t GPR_SHARED15_AUTHEN;               /**< GPR access control, offset: 0x49F0 */
  __IO uint32_t GPR_SHARED15_AUTHEN_SET;           /**< GPR access control, offset: 0x49F4 */
  __IO uint32_t GPR_SHARED15_AUTHEN_CLR;           /**< GPR access control, offset: 0x49F8 */
  __IO uint32_t GPR_SHARED15_AUTHEN_TOG;           /**< GPR access control, offset: 0x49FC */
  __I  uint32_t GPR_SHARED_STATUS[CCM_GPR_SHARED_STATUS_COUNT]; /**< General purpose status register for CM33..General purpose status register for CM7, array offset: 0x4A00, array step: 0x4 */
       uint8_t RESERVED_2[480];
  struct {                                         /* offset: 0x4C00, array step: 0x20 */
    __IO uint32_t GPR_PRIVATE;                       /**< General purpose register, array offset: 0x4C00, array step: 0x20 */
    __IO uint32_t SET;                               /**< General purpose register, array offset: 0x4C04, array step: 0x20 */
    __IO uint32_t CLR;                               /**< General purpose register, array offset: 0x4C08, array step: 0x20 */
    __IO uint32_t TOG;                               /**< General purpose register, array offset: 0x4C0C, array step: 0x20 */
    __IO uint32_t AUTHEN;                            /**< GPR access control, array offset: 0x4C10, array step: 0x20 */
    __IO uint32_t AUTHEN_SET;                        /**< GPR access control, array offset: 0x4C14, array step: 0x20 */
    __IO uint32_t AUTHEN_CLR;                        /**< GPR access control, array offset: 0x4C18, array step: 0x20 */
    __IO uint32_t AUTHEN_TOG;                        /**< GPR access control, array offset: 0x4C1C, array step: 0x20 */
  } GPR_PRIVATE[CCM_GPR_PRIVATE_COUNT];
       uint8_t RESERVED_3[896];
  struct {                                         /* offset: 0x5000, array step: 0x40 */
    __IO uint32_t DIRECT;                            /**< Clock source direct control, array offset: 0x5000, array step: 0x40 */
         uint8_t RESERVED_0[12];
    __IO uint32_t LPM0;                              /**< Clock source low power mode setting, array offset: 0x5010, array step: 0x40 */
    __IO uint32_t LPM1;                              /**< clock source low power mode setting, array offset: 0x5014, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __IO uint32_t LPM_CUR;                           /**< LPM setting of current CPU domain, array offset: 0x501C, array step: 0x40 */
    __I  uint32_t STATUS0;                           /**< Clock source working status, array offset: 0x5020, array step: 0x40 */
    __I  uint32_t STATUS1;                           /**< Clock source domain status, array offset: 0x5024, array step: 0x40 */
         uint8_t RESERVED_2[8];
    __IO uint32_t AUTHEN;                            /**< Clock Source access control, array offset: 0x5030, array step: 0x40 */
         uint8_t RESERVED_3[12];
  } OSCPLL[CCM_OSCPLL_COUNT];
       uint8_t RESERVED_4[10688];
  struct {                                         /* offset: 0x8000, array step: 0x40 */
    __IO uint32_t DIRECT;                            /**< LPCG direct control, array offset: 0x8000, array step: 0x40 */
         uint8_t RESERVED_0[12];
    __IO uint32_t LPM0;                              /**< Clock source low power mode setting, array offset: 0x8010, array step: 0x40 */
    __IO uint32_t LPM1;                              /**< clock source low power mode setting, array offset: 0x8014, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __IO uint32_t LPM_CUR;                           /**< LPM setting of current CPU domain, array offset: 0x801C, array step: 0x40 */
    __I  uint32_t STATUS0;                           /**< LPCG working status, array offset: 0x8020, array step: 0x40 */
    __I  uint32_t STATUS1;                           /**< LPCG domain status, array offset: 0x8024, array step: 0x40 */
         uint8_t RESERVED_2[8];
    __IO uint32_t AUTHEN;                            /**< LPCG access control, array offset: 0x8030, array step: 0x40 */
         uint8_t RESERVED_3[12];
  } LPCG[CCM_LPCG_COUNT];
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name CLOCK_ROOT_CONTROL - Clock Root Control Register */
/*! @{ */

#define CCM_CLOCK_ROOT_CONTROL_DIV_MASK          (0xFFU)
#define CCM_CLOCK_ROOT_CONTROL_DIV_SHIFT         (0U)
/*! DIV - Clock division fraction. */
#define CCM_CLOCK_ROOT_CONTROL_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_DIV_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_DIV_MASK)

#define CCM_CLOCK_ROOT_CONTROL_MUX_MASK          (0x300U)
#define CCM_CLOCK_ROOT_CONTROL_MUX_SHIFT         (8U)
/*! MUX - Clock multiplexer.
 *  0b00..Select clock source 0
 *  0b01..Select clock source 1
 *  0b10..Select clock source 2
 *  0b11..Select clock source 3
 */
#define CCM_CLOCK_ROOT_CONTROL_MUX(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_MUX_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_MUX_MASK)

#define CCM_CLOCK_ROOT_CONTROL_OFF_MASK          (0x1000000U)
#define CCM_CLOCK_ROOT_CONTROL_OFF_SHIFT         (24U)
/*! OFF - Shutdown clock root.
 *  0b0..Clock root is enabled
 *  0b1..Clock root is disabled
 */
#define CCM_CLOCK_ROOT_CONTROL_OFF(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_OFF_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_OFF_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_CONTROL */
#define CCM_CLOCK_ROOT_CONTROL_COUNT             (74U)

/*! @name CLOCK_ROOT_CONTROL_SET - Clock Root Control Register */
/*! @{ */

#define CCM_CLOCK_ROOT_CONTROL_SET_DIV_MASK      (0xFFU)
#define CCM_CLOCK_ROOT_CONTROL_SET_DIV_SHIFT     (0U)
/*! DIV - Clock division fraction. */
#define CCM_CLOCK_ROOT_CONTROL_SET_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_SET_DIV_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_SET_DIV_MASK)

#define CCM_CLOCK_ROOT_CONTROL_SET_MUX_MASK      (0x300U)
#define CCM_CLOCK_ROOT_CONTROL_SET_MUX_SHIFT     (8U)
/*! MUX - Clock multiplexer. */
#define CCM_CLOCK_ROOT_CONTROL_SET_MUX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_SET_MUX_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_SET_MUX_MASK)

#define CCM_CLOCK_ROOT_CONTROL_SET_OFF_MASK      (0x1000000U)
#define CCM_CLOCK_ROOT_CONTROL_SET_OFF_SHIFT     (24U)
/*! OFF - Shutdown clock root. */
#define CCM_CLOCK_ROOT_CONTROL_SET_OFF(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_SET_OFF_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_SET_OFF_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_CONTROL_SET */
#define CCM_CLOCK_ROOT_CONTROL_SET_COUNT         (74U)

/*! @name CLOCK_ROOT_CONTROL_CLR - Clock Root Control Register */
/*! @{ */

#define CCM_CLOCK_ROOT_CONTROL_CLR_DIV_MASK      (0xFFU)
#define CCM_CLOCK_ROOT_CONTROL_CLR_DIV_SHIFT     (0U)
/*! DIV - Clock division fraction. */
#define CCM_CLOCK_ROOT_CONTROL_CLR_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_CLR_DIV_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_CLR_DIV_MASK)

#define CCM_CLOCK_ROOT_CONTROL_CLR_MUX_MASK      (0x300U)
#define CCM_CLOCK_ROOT_CONTROL_CLR_MUX_SHIFT     (8U)
/*! MUX - Clock multiplexer. */
#define CCM_CLOCK_ROOT_CONTROL_CLR_MUX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_CLR_MUX_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_CLR_MUX_MASK)

#define CCM_CLOCK_ROOT_CONTROL_CLR_OFF_MASK      (0x1000000U)
#define CCM_CLOCK_ROOT_CONTROL_CLR_OFF_SHIFT     (24U)
/*! OFF - Shutdown clock root. */
#define CCM_CLOCK_ROOT_CONTROL_CLR_OFF(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_CLR_OFF_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_CLR_OFF_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_CONTROL_CLR */
#define CCM_CLOCK_ROOT_CONTROL_CLR_COUNT         (74U)

/*! @name CLOCK_ROOT_CONTROL_TOG - Clock Root Control Register */
/*! @{ */

#define CCM_CLOCK_ROOT_CONTROL_TOG_DIV_MASK      (0xFFU)
#define CCM_CLOCK_ROOT_CONTROL_TOG_DIV_SHIFT     (0U)
/*! DIV - Clock division fraction. */
#define CCM_CLOCK_ROOT_CONTROL_TOG_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_TOG_DIV_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_TOG_DIV_MASK)

#define CCM_CLOCK_ROOT_CONTROL_TOG_MUX_MASK      (0x300U)
#define CCM_CLOCK_ROOT_CONTROL_TOG_MUX_SHIFT     (8U)
/*! MUX - Clock multiplexer. */
#define CCM_CLOCK_ROOT_CONTROL_TOG_MUX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_TOG_MUX_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_TOG_MUX_MASK)

#define CCM_CLOCK_ROOT_CONTROL_TOG_OFF_MASK      (0x1000000U)
#define CCM_CLOCK_ROOT_CONTROL_TOG_OFF_SHIFT     (24U)
/*! OFF - Shutdown clock root. */
#define CCM_CLOCK_ROOT_CONTROL_TOG_OFF(x)        (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_CONTROL_TOG_OFF_SHIFT)) & CCM_CLOCK_ROOT_CONTROL_TOG_OFF_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_CONTROL_TOG */
#define CCM_CLOCK_ROOT_CONTROL_TOG_COUNT         (74U)

/*! @name CLOCK_ROOT_STATUS0 - Clock root working status */
/*! @{ */

#define CCM_CLOCK_ROOT_STATUS0_DIV_MASK          (0xFFU)
#define CCM_CLOCK_ROOT_STATUS0_DIV_SHIFT         (0U)
/*! DIV - Current clock root DIV setting */
#define CCM_CLOCK_ROOT_STATUS0_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_DIV_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_DIV_MASK)

#define CCM_CLOCK_ROOT_STATUS0_MUX_MASK          (0x300U)
#define CCM_CLOCK_ROOT_STATUS0_MUX_SHIFT         (8U)
/*! MUX - Current clock root MUX setting */
#define CCM_CLOCK_ROOT_STATUS0_MUX(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_MUX_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_MUX_MASK)

#define CCM_CLOCK_ROOT_STATUS0_OFF_MASK          (0x1000000U)
#define CCM_CLOCK_ROOT_STATUS0_OFF_SHIFT         (24U)
/*! OFF - Current clock root OFF setting
 *  0b0..Clock root is enabled
 *  0b1..Clock root is disabled
 */
#define CCM_CLOCK_ROOT_STATUS0_OFF(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_OFF_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_OFF_MASK)

#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_MASK   (0x10000000U)
#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_SHIFT  (28U)
/*! SLICE_BUSY - Internal updating in generation logic Indication for clock generation logic is applying new setting.
 *  0b0..Clock generation logic is not busy
 *  0b1..Clock generation logic is applying the new setting
 */
#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY(x)     (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_MASK)

#define CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_MASK (0x20000000U)
#define CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_SHIFT (29U)
/*! UPDATE_FORWARD - Internal status synchronization to clock generation logic Indication for clock status is synchronizing for clock root.
 *  0b0..Synchronization not in process
 *  0b1..Synchronization in process
 */
#define CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD(x) (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_MASK)

#define CCM_CLOCK_ROOT_STATUS0_CHANGING_MASK     (0x80000000U)
#define CCM_CLOCK_ROOT_STATUS0_CHANGING_SHIFT    (31U)
/*! CHANGING - Indication for clock root internal logic is updating. This status is a combination of UPDATE_FORWARD and SLICE_BUSY.
 *  0b0..Clock Status is not updating currently
 *  0b1..Clock generation logic is currently updating
 */
#define CCM_CLOCK_ROOT_STATUS0_CHANGING(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_CHANGING_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_CHANGING_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_STATUS0 */
#define CCM_CLOCK_ROOT_STATUS0_COUNT             (74U)

/*! @name CLOCK_ROOT_AUTHEN - Clock root access control */
/*! @{ */

#define CCM_CLOCK_ROOT_AUTHEN_TZ_USER_MASK       (0x100U)
#define CCM_CLOCK_ROOT_AUTHEN_TZ_USER_SHIFT      (8U)
/*! TZ_USER - User access permission
 *  0b0..Clock Root settings cannot be changed in user mode.
 *  0b1..Clock Root settings can be changed in user mode.
 */
#define CCM_CLOCK_ROOT_AUTHEN_TZ_USER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_TZ_USER_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_TZ_USER_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_TZ_NS_MASK         (0x200U)
#define CCM_CLOCK_ROOT_AUTHEN_TZ_NS_SHIFT        (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_CLOCK_ROOT_AUTHEN_TZ_NS(x)           (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_TZ_NS_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_TZ_NS_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_MASK       (0x800U)
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_SHIFT      (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ(x)         (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_MASK     (0x8000U)
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_SHIFT    (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_MASK    (0xFFFF0000U)
#define CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_SHIFT   (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_AUTHEN */
#define CCM_CLOCK_ROOT_AUTHEN_COUNT              (74U)

/*! @name OBSERVE_CONTROL - Observe control */
/*! @{ */

#define CCM_OBSERVE_CONTROL_SELECT_MASK          (0x1FFU)
#define CCM_OBSERVE_CONTROL_SELECT_SHIFT         (0U)
/*! SELECT - Observe signal selector */
#define CCM_OBSERVE_CONTROL_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SELECT_SHIFT)) & CCM_OBSERVE_CONTROL_SELECT_MASK)

#define CCM_OBSERVE_CONTROL_RAW_MASK             (0x1000U)
#define CCM_OBSERVE_CONTROL_RAW_SHIFT            (12U)
/*! RAW - Observe raw signal
 *  0b0..Select divided signal.
 *  0b1..Select raw signal.
 */
#define CCM_OBSERVE_CONTROL_RAW(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_RAW_SHIFT)) & CCM_OBSERVE_CONTROL_RAW_MASK)

#define CCM_OBSERVE_CONTROL_INV_MASK             (0x2000U)
#define CCM_OBSERVE_CONTROL_INV_SHIFT            (13U)
/*! INV
 *  0b0..Clock phase remain same.
 *  0b1..Invert clock phase before measurement or send to IO.
 */
#define CCM_OBSERVE_CONTROL_INV(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_INV_SHIFT)) & CCM_OBSERVE_CONTROL_INV_MASK)

#define CCM_OBSERVE_CONTROL_RESET_MASK           (0x8000U)
#define CCM_OBSERVE_CONTROL_RESET_SHIFT          (15U)
/*! RESET - Reset observe divider
 *  0b0..Reset deasserts
 *  0b1..Reset asserts
 */
#define CCM_OBSERVE_CONTROL_RESET(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_RESET_SHIFT)) & CCM_OBSERVE_CONTROL_RESET_MASK)

#define CCM_OBSERVE_CONTROL_DIVIDE_MASK          (0xFF0000U)
#define CCM_OBSERVE_CONTROL_DIVIDE_SHIFT         (16U)
/*! DIVIDE - Division factor of the divider for observed signal */
#define CCM_OBSERVE_CONTROL_DIVIDE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_DIVIDE_SHIFT)) & CCM_OBSERVE_CONTROL_DIVIDE_MASK)

#define CCM_OBSERVE_CONTROL_OFF_MASK             (0x1000000U)
#define CCM_OBSERVE_CONTROL_OFF_SHIFT            (24U)
/*! OFF - Turn off
 *  0b0..observe slice is on
 *  0b1..observe slice is off
 */
#define CCM_OBSERVE_CONTROL_OFF(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_OFF_SHIFT)) & CCM_OBSERVE_CONTROL_OFF_MASK)
/*! @} */

/* The count of CCM_OBSERVE_CONTROL */
#define CCM_OBSERVE_CONTROL_COUNT                (2U)

/*! @name OBSERVE_CONTROL_SET - Observe control */
/*! @{ */

#define CCM_OBSERVE_CONTROL_SET_SELECT_MASK      (0x1FFU)
#define CCM_OBSERVE_CONTROL_SET_SELECT_SHIFT     (0U)
/*! SELECT - Observe signal selector */
#define CCM_OBSERVE_CONTROL_SET_SELECT(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SET_SELECT_SHIFT)) & CCM_OBSERVE_CONTROL_SET_SELECT_MASK)

#define CCM_OBSERVE_CONTROL_SET_RAW_MASK         (0x1000U)
#define CCM_OBSERVE_CONTROL_SET_RAW_SHIFT        (12U)
/*! RAW - Observe raw signal */
#define CCM_OBSERVE_CONTROL_SET_RAW(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SET_RAW_SHIFT)) & CCM_OBSERVE_CONTROL_SET_RAW_MASK)

#define CCM_OBSERVE_CONTROL_SET_INV_MASK         (0x2000U)
#define CCM_OBSERVE_CONTROL_SET_INV_SHIFT        (13U)
#define CCM_OBSERVE_CONTROL_SET_INV(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SET_INV_SHIFT)) & CCM_OBSERVE_CONTROL_SET_INV_MASK)

#define CCM_OBSERVE_CONTROL_SET_RESET_MASK       (0x8000U)
#define CCM_OBSERVE_CONTROL_SET_RESET_SHIFT      (15U)
/*! RESET - Reset observe divider */
#define CCM_OBSERVE_CONTROL_SET_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SET_RESET_SHIFT)) & CCM_OBSERVE_CONTROL_SET_RESET_MASK)

#define CCM_OBSERVE_CONTROL_SET_DIVIDE_MASK      (0xFF0000U)
#define CCM_OBSERVE_CONTROL_SET_DIVIDE_SHIFT     (16U)
/*! DIVIDE - Division factor of the divider for observed signal */
#define CCM_OBSERVE_CONTROL_SET_DIVIDE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SET_DIVIDE_SHIFT)) & CCM_OBSERVE_CONTROL_SET_DIVIDE_MASK)

#define CCM_OBSERVE_CONTROL_SET_OFF_MASK         (0x1000000U)
#define CCM_OBSERVE_CONTROL_SET_OFF_SHIFT        (24U)
/*! OFF - Turn off */
#define CCM_OBSERVE_CONTROL_SET_OFF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_SET_OFF_SHIFT)) & CCM_OBSERVE_CONTROL_SET_OFF_MASK)
/*! @} */

/* The count of CCM_OBSERVE_CONTROL_SET */
#define CCM_OBSERVE_CONTROL_SET_COUNT            (2U)

/*! @name OBSERVE_CONTROL_CLR - Observe control */
/*! @{ */

#define CCM_OBSERVE_CONTROL_CLR_SELECT_MASK      (0x1FFU)
#define CCM_OBSERVE_CONTROL_CLR_SELECT_SHIFT     (0U)
/*! SELECT - Observe signal selector */
#define CCM_OBSERVE_CONTROL_CLR_SELECT(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_CLR_SELECT_SHIFT)) & CCM_OBSERVE_CONTROL_CLR_SELECT_MASK)

#define CCM_OBSERVE_CONTROL_CLR_RAW_MASK         (0x1000U)
#define CCM_OBSERVE_CONTROL_CLR_RAW_SHIFT        (12U)
/*! RAW - Observe raw signal */
#define CCM_OBSERVE_CONTROL_CLR_RAW(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_CLR_RAW_SHIFT)) & CCM_OBSERVE_CONTROL_CLR_RAW_MASK)

#define CCM_OBSERVE_CONTROL_CLR_INV_MASK         (0x2000U)
#define CCM_OBSERVE_CONTROL_CLR_INV_SHIFT        (13U)
#define CCM_OBSERVE_CONTROL_CLR_INV(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_CLR_INV_SHIFT)) & CCM_OBSERVE_CONTROL_CLR_INV_MASK)

#define CCM_OBSERVE_CONTROL_CLR_RESET_MASK       (0x8000U)
#define CCM_OBSERVE_CONTROL_CLR_RESET_SHIFT      (15U)
/*! RESET - Reset observe divider */
#define CCM_OBSERVE_CONTROL_CLR_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_CLR_RESET_SHIFT)) & CCM_OBSERVE_CONTROL_CLR_RESET_MASK)

#define CCM_OBSERVE_CONTROL_CLR_DIVIDE_MASK      (0xFF0000U)
#define CCM_OBSERVE_CONTROL_CLR_DIVIDE_SHIFT     (16U)
/*! DIVIDE - Division factor of the divider for observed signal */
#define CCM_OBSERVE_CONTROL_CLR_DIVIDE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_CLR_DIVIDE_SHIFT)) & CCM_OBSERVE_CONTROL_CLR_DIVIDE_MASK)

#define CCM_OBSERVE_CONTROL_CLR_OFF_MASK         (0x1000000U)
#define CCM_OBSERVE_CONTROL_CLR_OFF_SHIFT        (24U)
/*! OFF - Turn off */
#define CCM_OBSERVE_CONTROL_CLR_OFF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_CLR_OFF_SHIFT)) & CCM_OBSERVE_CONTROL_CLR_OFF_MASK)
/*! @} */

/* The count of CCM_OBSERVE_CONTROL_CLR */
#define CCM_OBSERVE_CONTROL_CLR_COUNT            (2U)

/*! @name OBSERVE_CONTROL_TOG - Observe control */
/*! @{ */

#define CCM_OBSERVE_CONTROL_TOG_SELECT_MASK      (0x1FFU)
#define CCM_OBSERVE_CONTROL_TOG_SELECT_SHIFT     (0U)
/*! SELECT - Observe signal selector */
#define CCM_OBSERVE_CONTROL_TOG_SELECT(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_TOG_SELECT_SHIFT)) & CCM_OBSERVE_CONTROL_TOG_SELECT_MASK)

#define CCM_OBSERVE_CONTROL_TOG_RAW_MASK         (0x1000U)
#define CCM_OBSERVE_CONTROL_TOG_RAW_SHIFT        (12U)
/*! RAW - Observe raw signal */
#define CCM_OBSERVE_CONTROL_TOG_RAW(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_TOG_RAW_SHIFT)) & CCM_OBSERVE_CONTROL_TOG_RAW_MASK)

#define CCM_OBSERVE_CONTROL_TOG_INV_MASK         (0x2000U)
#define CCM_OBSERVE_CONTROL_TOG_INV_SHIFT        (13U)
#define CCM_OBSERVE_CONTROL_TOG_INV(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_TOG_INV_SHIFT)) & CCM_OBSERVE_CONTROL_TOG_INV_MASK)

#define CCM_OBSERVE_CONTROL_TOG_RESET_MASK       (0x8000U)
#define CCM_OBSERVE_CONTROL_TOG_RESET_SHIFT      (15U)
/*! RESET - Reset observe divider */
#define CCM_OBSERVE_CONTROL_TOG_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_TOG_RESET_SHIFT)) & CCM_OBSERVE_CONTROL_TOG_RESET_MASK)

#define CCM_OBSERVE_CONTROL_TOG_DIVIDE_MASK      (0xFF0000U)
#define CCM_OBSERVE_CONTROL_TOG_DIVIDE_SHIFT     (16U)
/*! DIVIDE - Division factor of the divider for observed signal */
#define CCM_OBSERVE_CONTROL_TOG_DIVIDE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_TOG_DIVIDE_SHIFT)) & CCM_OBSERVE_CONTROL_TOG_DIVIDE_MASK)

#define CCM_OBSERVE_CONTROL_TOG_OFF_MASK         (0x1000000U)
#define CCM_OBSERVE_CONTROL_TOG_OFF_SHIFT        (24U)
/*! OFF - Turn off */
#define CCM_OBSERVE_CONTROL_TOG_OFF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_CONTROL_TOG_OFF_SHIFT)) & CCM_OBSERVE_CONTROL_TOG_OFF_MASK)
/*! @} */

/* The count of CCM_OBSERVE_CONTROL_TOG */
#define CCM_OBSERVE_CONTROL_TOG_COUNT            (2U)

/*! @name OBSERVE_STATUS - Observe status */
/*! @{ */

#define CCM_OBSERVE_STATUS_SELECT_MASK           (0x1FFU)
#define CCM_OBSERVE_STATUS_SELECT_SHIFT          (0U)
/*! SELECT - Observe signal selector */
#define CCM_OBSERVE_STATUS_SELECT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_SELECT_SHIFT)) & CCM_OBSERVE_STATUS_SELECT_MASK)

#define CCM_OBSERVE_STATUS_RAW_MASK              (0x1000U)
#define CCM_OBSERVE_STATUS_RAW_SHIFT             (12U)
/*! RAW - Observe raw signal
 *  0b0..Select divided signal.
 *  0b1..Select raw signal.
 */
#define CCM_OBSERVE_STATUS_RAW(x)                (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_RAW_SHIFT)) & CCM_OBSERVE_STATUS_RAW_MASK)

#define CCM_OBSERVE_STATUS_INV_MASK              (0x2000U)
#define CCM_OBSERVE_STATUS_INV_SHIFT             (13U)
/*! INV - Invert
 *  0b0..Clock phase remain same.
 *  0b1..Invert clock phase before measurement or send to IO.
 */
#define CCM_OBSERVE_STATUS_INV(x)                (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_INV_SHIFT)) & CCM_OBSERVE_STATUS_INV_MASK)

#define CCM_OBSERVE_STATUS_RESET_MASK            (0x8000U)
#define CCM_OBSERVE_STATUS_RESET_SHIFT           (15U)
/*! RESET - Reset state
 *  0b0..Observe divider is not in reset state
 *  0b1..Observe divider is in reset state
 */
#define CCM_OBSERVE_STATUS_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_RESET_SHIFT)) & CCM_OBSERVE_STATUS_RESET_MASK)

#define CCM_OBSERVE_STATUS_DIVIDE_MASK           (0xFF0000U)
#define CCM_OBSERVE_STATUS_DIVIDE_SHIFT          (16U)
/*! DIVIDE - Divider for observe signal */
#define CCM_OBSERVE_STATUS_DIVIDE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_DIVIDE_SHIFT)) & CCM_OBSERVE_STATUS_DIVIDE_MASK)

#define CCM_OBSERVE_STATUS_OFF_MASK              (0x1000000U)
#define CCM_OBSERVE_STATUS_OFF_SHIFT             (24U)
/*! OFF - Turn off slice
 *  0b0..observe slice is on
 *  0b1..observe slice is off
 */
#define CCM_OBSERVE_STATUS_OFF(x)                (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_OFF_SHIFT)) & CCM_OBSERVE_STATUS_OFF_MASK)

#define CCM_OBSERVE_STATUS_FREQ_MEASURE_DONE_MASK (0x2000000U)
#define CCM_OBSERVE_STATUS_FREQ_MEASURE_DONE_SHIFT (25U)
/*! FREQ_MEASURE_DONE - frequency measurement done flag
 *  0b0..Frequency measurement is on-going or not started
 *  0b1..Frequency measurement is done.
 */
#define CCM_OBSERVE_STATUS_FREQ_MEASURE_DONE(x)  (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_FREQ_MEASURE_DONE_SHIFT)) & CCM_OBSERVE_STATUS_FREQ_MEASURE_DONE_MASK)

#define CCM_OBSERVE_STATUS_BUSY_MASK             (0x10000000U)
#define CCM_OBSERVE_STATUS_BUSY_SHIFT            (28U)
/*! BUSY - Busy
 *  0b0..Current observe is not busy
 *  0b1..Current observe is busy
 */
#define CCM_OBSERVE_STATUS_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_BUSY_SHIFT)) & CCM_OBSERVE_STATUS_BUSY_MASK)

#define CCM_OBSERVE_STATUS_UPDATED_FORWARD_MASK  (0x20000000U)
#define CCM_OBSERVE_STATUS_UPDATED_FORWARD_SHIFT (29U)
/*! UPDATED_FORWARD - Update Forward */
#define CCM_OBSERVE_STATUS_UPDATED_FORWARD(x)    (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_UPDATED_FORWARD_SHIFT)) & CCM_OBSERVE_STATUS_UPDATED_FORWARD_MASK)

#define CCM_OBSERVE_STATUS_CHANGING_MASK         (0x80000000U)
#define CCM_OBSERVE_STATUS_CHANGING_SHIFT        (31U)
/*! CHANGING - Busy */
#define CCM_OBSERVE_STATUS_CHANGING(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_STATUS_CHANGING_SHIFT)) & CCM_OBSERVE_STATUS_CHANGING_MASK)
/*! @} */

/* The count of CCM_OBSERVE_STATUS */
#define CCM_OBSERVE_STATUS_COUNT                 (2U)

/*! @name OBSERVE_AUTHEN - Observe access control */
/*! @{ */

#define CCM_OBSERVE_AUTHEN_TZ_USER_MASK          (0x100U)
#define CCM_OBSERVE_AUTHEN_TZ_USER_SHIFT         (8U)
/*! TZ_USER - User access permission
 *  0b0..Observe slice settings cannot be changed in user mode.
 *  0b1..Observe slice settings can be changed in user mode.
 */
#define CCM_OBSERVE_AUTHEN_TZ_USER(x)            (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TZ_USER_SHIFT)) & CCM_OBSERVE_AUTHEN_TZ_USER_MASK)

#define CCM_OBSERVE_AUTHEN_TZ_NS_MASK            (0x200U)
#define CCM_OBSERVE_AUTHEN_TZ_NS_SHIFT           (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in non-secure mode.
 *  0b1..Can be changed in non-secure mode.
 */
#define CCM_OBSERVE_AUTHEN_TZ_NS(x)              (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TZ_NS_SHIFT)) & CCM_OBSERVE_AUTHEN_TZ_NS_MASK)

#define CCM_OBSERVE_AUTHEN_LOCK_TZ_MASK          (0x800U)
#define CCM_OBSERVE_AUTHEN_LOCK_TZ_SHIFT         (11U)
/*! LOCK_TZ - Lock TrustZone setting
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_OBSERVE_AUTHEN_LOCK_TZ(x)            (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_LOCK_TZ_SHIFT)) & CCM_OBSERVE_AUTHEN_LOCK_TZ_MASK)

#define CCM_OBSERVE_AUTHEN_LOCK_LIST_MASK        (0x8000U)
#define CCM_OBSERVE_AUTHEN_LOCK_LIST_SHIFT       (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_OBSERVE_AUTHEN_LOCK_LIST(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_LOCK_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_LOCK_LIST_MASK)

#define CCM_OBSERVE_AUTHEN_WHITE_LIST_MASK       (0xFFFF0000U)
#define CCM_OBSERVE_AUTHEN_WHITE_LIST_SHIFT      (16U)
/*! WHITE_LIST - Whitelist settings
 *  0b0000000000000000..No domain can change.
 *  0b0000000000000001..Domain 0 can change.
 *  0b0000000000000010..Domain 1 can change.
 *  0b0000000000000011..Domain 0 and domain 1 can change.
 *  0b0000000000000100..Domain 2 can change.
 *  0b0000000000001111..All domain can change.
 */
#define CCM_OBSERVE_AUTHEN_WHITE_LIST(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_WHITE_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OBSERVE_AUTHEN */
#define CCM_OBSERVE_AUTHEN_COUNT                 (2U)

/*! @name OBSERVE_AUTHEN_SET - Observe access control */
/*! @{ */

#define CCM_OBSERVE_AUTHEN_SET_TZ_USER_MASK      (0x100U)
#define CCM_OBSERVE_AUTHEN_SET_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission */
#define CCM_OBSERVE_AUTHEN_SET_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_OBSERVE_AUTHEN_SET_TZ_USER_MASK)

#define CCM_OBSERVE_AUTHEN_SET_TZ_NS_MASK        (0x200U)
#define CCM_OBSERVE_AUTHEN_SET_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_OBSERVE_AUTHEN_SET_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_OBSERVE_AUTHEN_SET_TZ_NS_MASK)

#define CCM_OBSERVE_AUTHEN_SET_LOCK_TZ_MASK      (0x800U)
#define CCM_OBSERVE_AUTHEN_SET_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone setting */
#define CCM_OBSERVE_AUTHEN_SET_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_OBSERVE_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_OBSERVE_AUTHEN_SET_LOCK_LIST_MASK    (0x8000U)
#define CCM_OBSERVE_AUTHEN_SET_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_OBSERVE_AUTHEN_SET_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_OBSERVE_AUTHEN_SET_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_OBSERVE_AUTHEN_SET_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_OBSERVE_AUTHEN_SET_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OBSERVE_AUTHEN_SET */
#define CCM_OBSERVE_AUTHEN_SET_COUNT             (2U)

/*! @name OBSERVE_AUTHEN_CLR - Observe access control */
/*! @{ */

#define CCM_OBSERVE_AUTHEN_CLR_TZ_USER_MASK      (0x100U)
#define CCM_OBSERVE_AUTHEN_CLR_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission */
#define CCM_OBSERVE_AUTHEN_CLR_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_OBSERVE_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_OBSERVE_AUTHEN_CLR_TZ_NS_MASK        (0x200U)
#define CCM_OBSERVE_AUTHEN_CLR_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_OBSERVE_AUTHEN_CLR_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_OBSERVE_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_OBSERVE_AUTHEN_CLR_LOCK_TZ_MASK      (0x800U)
#define CCM_OBSERVE_AUTHEN_CLR_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone setting */
#define CCM_OBSERVE_AUTHEN_CLR_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_OBSERVE_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_OBSERVE_AUTHEN_CLR_LOCK_LIST_MASK    (0x8000U)
#define CCM_OBSERVE_AUTHEN_CLR_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_OBSERVE_AUTHEN_CLR_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_OBSERVE_AUTHEN_CLR_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_OBSERVE_AUTHEN_CLR_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_OBSERVE_AUTHEN_CLR_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OBSERVE_AUTHEN_CLR */
#define CCM_OBSERVE_AUTHEN_CLR_COUNT             (2U)

/*! @name OBSERVE_AUTHEN_TOG - Observe access control */
/*! @{ */

#define CCM_OBSERVE_AUTHEN_TOG_TZ_USER_MASK      (0x100U)
#define CCM_OBSERVE_AUTHEN_TOG_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission */
#define CCM_OBSERVE_AUTHEN_TOG_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_OBSERVE_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_OBSERVE_AUTHEN_TOG_TZ_NS_MASK        (0x200U)
#define CCM_OBSERVE_AUTHEN_TOG_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_OBSERVE_AUTHEN_TOG_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_OBSERVE_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_OBSERVE_AUTHEN_TOG_LOCK_TZ_MASK      (0x800U)
#define CCM_OBSERVE_AUTHEN_TOG_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone setting */
#define CCM_OBSERVE_AUTHEN_TOG_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_OBSERVE_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_OBSERVE_AUTHEN_TOG_LOCK_LIST_MASK    (0x8000U)
#define CCM_OBSERVE_AUTHEN_TOG_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_OBSERVE_AUTHEN_TOG_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_OBSERVE_AUTHEN_TOG_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_OBSERVE_AUTHEN_TOG_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_OBSERVE_AUTHEN_TOG_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_OBSERVE_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OBSERVE_AUTHEN_TOG */
#define CCM_OBSERVE_AUTHEN_TOG_COUNT             (2U)

/*! @name OBSERVE_FREQUENCY_CURRENT - Current frequency detected */
/*! @{ */

#define CCM_OBSERVE_FREQUENCY_CURRENT_FREQUENCY_MASK (0xFFFFFFFFU)
#define CCM_OBSERVE_FREQUENCY_CURRENT_FREQUENCY_SHIFT (0U)
/*! FREQUENCY - Frequency */
#define CCM_OBSERVE_FREQUENCY_CURRENT_FREQUENCY(x) (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_FREQUENCY_CURRENT_FREQUENCY_SHIFT)) & CCM_OBSERVE_FREQUENCY_CURRENT_FREQUENCY_MASK)
/*! @} */

/* The count of CCM_OBSERVE_FREQUENCY_CURRENT */
#define CCM_OBSERVE_FREQUENCY_CURRENT_COUNT      (2U)

/*! @name OBSERVE_FREQUENCY_MIN - Minimum frequency detected */
/*! @{ */

#define CCM_OBSERVE_FREQUENCY_MIN_FREQUENCY_MASK (0xFFFFFFFFU)
#define CCM_OBSERVE_FREQUENCY_MIN_FREQUENCY_SHIFT (0U)
/*! FREQUENCY - Frequency */
#define CCM_OBSERVE_FREQUENCY_MIN_FREQUENCY(x)   (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_FREQUENCY_MIN_FREQUENCY_SHIFT)) & CCM_OBSERVE_FREQUENCY_MIN_FREQUENCY_MASK)
/*! @} */

/* The count of CCM_OBSERVE_FREQUENCY_MIN */
#define CCM_OBSERVE_FREQUENCY_MIN_COUNT          (2U)

/*! @name OBSERVE_FREQUENCY_MAX - Maximum frequency detected */
/*! @{ */

#define CCM_OBSERVE_FREQUENCY_MAX_FREQUENCY_MASK (0xFFFFFFFFU)
#define CCM_OBSERVE_FREQUENCY_MAX_FREQUENCY_SHIFT (0U)
/*! FREQUENCY - Frequency */
#define CCM_OBSERVE_FREQUENCY_MAX_FREQUENCY(x)   (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_FREQUENCY_MAX_FREQUENCY_SHIFT)) & CCM_OBSERVE_FREQUENCY_MAX_FREQUENCY_MASK)
/*! @} */

/* The count of CCM_OBSERVE_FREQUENCY_MAX */
#define CCM_OBSERVE_FREQUENCY_MAX_COUNT          (2U)

/*! @name OBSERVE_PERIOD_CURRENT - Current period time detected */
/*! @{ */

#define CCM_OBSERVE_PERIOD_CURRENT_PERIOD_MASK   (0xFFFFFFFFU)
#define CCM_OBSERVE_PERIOD_CURRENT_PERIOD_SHIFT  (0U)
/*! PERIOD - Period time */
#define CCM_OBSERVE_PERIOD_CURRENT_PERIOD(x)     (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_PERIOD_CURRENT_PERIOD_SHIFT)) & CCM_OBSERVE_PERIOD_CURRENT_PERIOD_MASK)
/*! @} */

/* The count of CCM_OBSERVE_PERIOD_CURRENT */
#define CCM_OBSERVE_PERIOD_CURRENT_COUNT         (2U)

/*! @name OBSERVE_PERIOD_MIN - Minimum period time detected */
/*! @{ */

#define CCM_OBSERVE_PERIOD_MIN_PERIOD_MASK       (0xFFFFFFFFU)
#define CCM_OBSERVE_PERIOD_MIN_PERIOD_SHIFT      (0U)
/*! PERIOD - Period time */
#define CCM_OBSERVE_PERIOD_MIN_PERIOD(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_PERIOD_MIN_PERIOD_SHIFT)) & CCM_OBSERVE_PERIOD_MIN_PERIOD_MASK)
/*! @} */

/* The count of CCM_OBSERVE_PERIOD_MIN */
#define CCM_OBSERVE_PERIOD_MIN_COUNT             (2U)

/*! @name OBSERVE_PERIOD_MAX - Maximum period time detected */
/*! @{ */

#define CCM_OBSERVE_PERIOD_MAX_PERIOD_MASK       (0xFFFFFFFFU)
#define CCM_OBSERVE_PERIOD_MAX_PERIOD_SHIFT      (0U)
/*! PERIOD - Period time */
#define CCM_OBSERVE_PERIOD_MAX_PERIOD(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_PERIOD_MAX_PERIOD_SHIFT)) & CCM_OBSERVE_PERIOD_MAX_PERIOD_MASK)
/*! @} */

/* The count of CCM_OBSERVE_PERIOD_MAX */
#define CCM_OBSERVE_PERIOD_MAX_COUNT             (2U)

/*! @name OBSERVE_HIGH_CURRENT - Current high level time detected */
/*! @{ */

#define CCM_OBSERVE_HIGH_CURRENT_HIGH_MASK       (0xFFFFFFFFU)
#define CCM_OBSERVE_HIGH_CURRENT_HIGH_SHIFT      (0U)
/*! HIGH - High level time */
#define CCM_OBSERVE_HIGH_CURRENT_HIGH(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_HIGH_CURRENT_HIGH_SHIFT)) & CCM_OBSERVE_HIGH_CURRENT_HIGH_MASK)
/*! @} */

/* The count of CCM_OBSERVE_HIGH_CURRENT */
#define CCM_OBSERVE_HIGH_CURRENT_COUNT           (2U)

/*! @name OBSERVE_HIGH_MIN - Minimum high level time detected */
/*! @{ */

#define CCM_OBSERVE_HIGH_MIN_HIGH_MASK           (0xFFFFFFFFU)
#define CCM_OBSERVE_HIGH_MIN_HIGH_SHIFT          (0U)
/*! HIGH - High level time */
#define CCM_OBSERVE_HIGH_MIN_HIGH(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_HIGH_MIN_HIGH_SHIFT)) & CCM_OBSERVE_HIGH_MIN_HIGH_MASK)
/*! @} */

/* The count of CCM_OBSERVE_HIGH_MIN */
#define CCM_OBSERVE_HIGH_MIN_COUNT               (2U)

/*! @name OBSERVE_HIGH_MAX - Maximum high level time detected */
/*! @{ */

#define CCM_OBSERVE_HIGH_MAX_HIGH_MASK           (0xFFFFFFFFU)
#define CCM_OBSERVE_HIGH_MAX_HIGH_SHIFT          (0U)
/*! HIGH - High level time */
#define CCM_OBSERVE_HIGH_MAX_HIGH(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_HIGH_MAX_HIGH_SHIFT)) & CCM_OBSERVE_HIGH_MAX_HIGH_MASK)
/*! @} */

/* The count of CCM_OBSERVE_HIGH_MAX */
#define CCM_OBSERVE_HIGH_MAX_COUNT               (2U)

/*! @name OBSERVE_LOW_CURRENT - Current high level time detected */
/*! @{ */

#define CCM_OBSERVE_LOW_CURRENT_LOW_MASK         (0xFFFFFFFFU)
#define CCM_OBSERVE_LOW_CURRENT_LOW_SHIFT        (0U)
/*! LOW - High level time */
#define CCM_OBSERVE_LOW_CURRENT_LOW(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_LOW_CURRENT_LOW_SHIFT)) & CCM_OBSERVE_LOW_CURRENT_LOW_MASK)
/*! @} */

/* The count of CCM_OBSERVE_LOW_CURRENT */
#define CCM_OBSERVE_LOW_CURRENT_COUNT            (2U)

/*! @name OBSERVE_LOW_MIN - Minimum high level time detected */
/*! @{ */

#define CCM_OBSERVE_LOW_MIN_LOW_MASK             (0xFFFFFFFFU)
#define CCM_OBSERVE_LOW_MIN_LOW_SHIFT            (0U)
/*! LOW - High level time */
#define CCM_OBSERVE_LOW_MIN_LOW(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_LOW_MIN_LOW_SHIFT)) & CCM_OBSERVE_LOW_MIN_LOW_MASK)
/*! @} */

/* The count of CCM_OBSERVE_LOW_MIN */
#define CCM_OBSERVE_LOW_MIN_COUNT                (2U)

/*! @name OBSERVE_LOW_MAX - Maximum high level time detected */
/*! @{ */

#define CCM_OBSERVE_LOW_MAX_LOW_MASK             (0xFFFFFFFFU)
#define CCM_OBSERVE_LOW_MAX_LOW_SHIFT            (0U)
/*! LOW - High level time */
#define CCM_OBSERVE_LOW_MAX_LOW(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OBSERVE_LOW_MAX_LOW_SHIFT)) & CCM_OBSERVE_LOW_MAX_LOW_MASK)
/*! @} */

/* The count of CCM_OBSERVE_LOW_MAX */
#define CCM_OBSERVE_LOW_MAX_COUNT                (2U)

/*! @name GPR_SHARED0_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED0_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED0_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED0_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED0_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED0_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED0_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED0_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED0_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED0_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED0_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED0_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED0_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED0_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED0_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED0_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED0_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED0_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED0_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED0_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED0_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED0_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED0_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED0_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED0_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED0_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED0_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED0_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED0_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED0_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED0_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED0_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED0_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED0_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED0_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED0_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED0_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED0_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED0_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED0_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED1_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED1_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED1_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED1_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED1_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED1_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED1_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED1_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED1_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED1_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED1_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED1_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED1_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED1_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED1_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED1_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED1_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED1_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED1_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED1_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED1_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED1_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED1_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED1_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED1_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED1_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED1_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED1_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED1_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED1_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED1_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED1_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED1_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED1_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED1_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED1_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED1_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED1_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED1_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED1_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED2 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED2_m33_mask_cm7_MASK        (0x1U)
#define CCM_GPR_SHARED2_m33_mask_cm7_SHIFT       (0U)
/*! m33_mask_cm7 - m33_mask_cm7 */
#define CCM_GPR_SHARED2_m33_mask_cm7(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_cm7_SHIFT)) & CCM_GPR_SHARED2_m33_mask_cm7_MASK)

#define CCM_GPR_SHARED2_m33_mask_cm33_MASK       (0x2U)
#define CCM_GPR_SHARED2_m33_mask_cm33_SHIFT      (1U)
/*! m33_mask_cm33 - m33_mask_cm33 */
#define CCM_GPR_SHARED2_m33_mask_cm33(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_cm33_SHIFT)) & CCM_GPR_SHARED2_m33_mask_cm33_MASK)

#define CCM_GPR_SHARED2_m33_mask_edma3_MASK      (0x4U)
#define CCM_GPR_SHARED2_m33_mask_edma3_SHIFT     (2U)
/*! m33_mask_edma3 - m33_mask_edma3 */
#define CCM_GPR_SHARED2_m33_mask_edma3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_edma3_SHIFT)) & CCM_GPR_SHARED2_m33_mask_edma3_MASK)

#define CCM_GPR_SHARED2_m33_mask_edma4_MASK      (0x8U)
#define CCM_GPR_SHARED2_m33_mask_edma4_SHIFT     (3U)
/*! m33_mask_edma4 - m33_mask_edma4 */
#define CCM_GPR_SHARED2_m33_mask_edma4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_edma4_SHIFT)) & CCM_GPR_SHARED2_m33_mask_edma4_MASK)

#define CCM_GPR_SHARED2_m33_mask_netc_MASK       (0x10U)
#define CCM_GPR_SHARED2_m33_mask_netc_SHIFT      (4U)
/*! m33_mask_netc - m33_mask_netc */
#define CCM_GPR_SHARED2_m33_mask_netc(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_netc_SHIFT)) & CCM_GPR_SHARED2_m33_mask_netc_MASK)

#define CCM_GPR_SHARED2_m33_mask_sim_aon_MASK    (0x100U)
#define CCM_GPR_SHARED2_m33_mask_sim_aon_SHIFT   (8U)
/*! m33_mask_sim_aon - m33_mask_sim_aon */
#define CCM_GPR_SHARED2_m33_mask_sim_aon(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED2_m33_mask_sim_aon_MASK)

#define CCM_GPR_SHARED2_m33_mask_adc1_MASK       (0x200U)
#define CCM_GPR_SHARED2_m33_mask_adc1_SHIFT      (9U)
/*! m33_mask_adc1 - m33_mask_adc1 */
#define CCM_GPR_SHARED2_m33_mask_adc1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_adc1_SHIFT)) & CCM_GPR_SHARED2_m33_mask_adc1_MASK)

#define CCM_GPR_SHARED2_m33_mask_adc2_MASK       (0x400U)
#define CCM_GPR_SHARED2_m33_mask_adc2_SHIFT      (10U)
/*! m33_mask_adc2 - m33_mask_adc2 */
#define CCM_GPR_SHARED2_m33_mask_adc2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_adc2_SHIFT)) & CCM_GPR_SHARED2_m33_mask_adc2_MASK)

#define CCM_GPR_SHARED2_m33_mask_flexspi1_MASK   (0x800U)
#define CCM_GPR_SHARED2_m33_mask_flexspi1_SHIFT  (11U)
/*! m33_mask_flexspi1 - m33_mask_flexspi1 */
#define CCM_GPR_SHARED2_m33_mask_flexspi1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED2_m33_mask_flexspi1_MASK)

#define CCM_GPR_SHARED2_m33_mask_flexspi2_MASK   (0x1000U)
#define CCM_GPR_SHARED2_m33_mask_flexspi2_SHIFT  (12U)
/*! m33_mask_flexspi2 - m33_mask_flexspi2 */
#define CCM_GPR_SHARED2_m33_mask_flexspi2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED2_m33_mask_flexspi2_MASK)

#define CCM_GPR_SHARED2_m33_mask_trdc_MASK       (0x2000U)
#define CCM_GPR_SHARED2_m33_mask_trdc_SHIFT      (13U)
/*! m33_mask_trdc - m33_mask_trdc */
#define CCM_GPR_SHARED2_m33_mask_trdc(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_trdc_SHIFT)) & CCM_GPR_SHARED2_m33_mask_trdc_MASK)

#define CCM_GPR_SHARED2_m33_mask_semc_MASK       (0x4000U)
#define CCM_GPR_SHARED2_m33_mask_semc_SHIFT      (14U)
/*! m33_mask_semc - m33_mask_semc */
#define CCM_GPR_SHARED2_m33_mask_semc(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_semc_SHIFT)) & CCM_GPR_SHARED2_m33_mask_semc_MASK)

#define CCM_GPR_SHARED2_m33_mask_iee_MASK        (0x8000U)
#define CCM_GPR_SHARED2_m33_mask_iee_SHIFT       (15U)
/*! m33_mask_iee - m33_mask_iee */
#define CCM_GPR_SHARED2_m33_mask_iee(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_iee_SHIFT)) & CCM_GPR_SHARED2_m33_mask_iee_MASK)

#define CCM_GPR_SHARED2_m33_mask_gpio1_MASK      (0x10000U)
#define CCM_GPR_SHARED2_m33_mask_gpio1_SHIFT     (16U)
/*! m33_mask_gpio1 - m33_mask_gpio1 */
#define CCM_GPR_SHARED2_m33_mask_gpio1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_gpio1_SHIFT)) & CCM_GPR_SHARED2_m33_mask_gpio1_MASK)

#define CCM_GPR_SHARED2_m33_mask_gpio2_MASK      (0x20000U)
#define CCM_GPR_SHARED2_m33_mask_gpio2_SHIFT     (17U)
/*! m33_mask_gpio2 - m33_mask_gpio2 */
#define CCM_GPR_SHARED2_m33_mask_gpio2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_gpio2_SHIFT)) & CCM_GPR_SHARED2_m33_mask_gpio2_MASK)

#define CCM_GPR_SHARED2_m33_mask_gpio3_MASK      (0x40000U)
#define CCM_GPR_SHARED2_m33_mask_gpio3_SHIFT     (18U)
/*! m33_mask_gpio3 - m33_mask_gpio3 */
#define CCM_GPR_SHARED2_m33_mask_gpio3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_gpio3_SHIFT)) & CCM_GPR_SHARED2_m33_mask_gpio3_MASK)

#define CCM_GPR_SHARED2_m33_mask_gpio4_MASK      (0x80000U)
#define CCM_GPR_SHARED2_m33_mask_gpio4_SHIFT     (19U)
/*! m33_mask_gpio4 - m33_mask_gpio4 */
#define CCM_GPR_SHARED2_m33_mask_gpio4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_gpio4_SHIFT)) & CCM_GPR_SHARED2_m33_mask_gpio4_MASK)

#define CCM_GPR_SHARED2_m33_mask_gpio5_MASK      (0x100000U)
#define CCM_GPR_SHARED2_m33_mask_gpio5_SHIFT     (20U)
/*! m33_mask_gpio5 - m33_mask_gpio5 */
#define CCM_GPR_SHARED2_m33_mask_gpio5(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_gpio5_SHIFT)) & CCM_GPR_SHARED2_m33_mask_gpio5_MASK)

#define CCM_GPR_SHARED2_m33_mask_gpio6_MASK      (0x200000U)
#define CCM_GPR_SHARED2_m33_mask_gpio6_SHIFT     (21U)
/*! m33_mask_gpio6 - m33_mask_gpio6 */
#define CCM_GPR_SHARED2_m33_mask_gpio6(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_gpio6_SHIFT)) & CCM_GPR_SHARED2_m33_mask_gpio6_MASK)

#define CCM_GPR_SHARED2_m33_mask_flexio1_MASK    (0x400000U)
#define CCM_GPR_SHARED2_m33_mask_flexio1_SHIFT   (22U)
/*! m33_mask_flexio1 - m33_mask_flexio1 */
#define CCM_GPR_SHARED2_m33_mask_flexio1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_flexio1_SHIFT)) & CCM_GPR_SHARED2_m33_mask_flexio1_MASK)

#define CCM_GPR_SHARED2_m33_mask_flexio2_MASK    (0x800000U)
#define CCM_GPR_SHARED2_m33_mask_flexio2_SHIFT   (23U)
/*! m33_mask_flexio2 - m33_mask_flexio2 */
#define CCM_GPR_SHARED2_m33_mask_flexio2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_flexio2_SHIFT)) & CCM_GPR_SHARED2_m33_mask_flexio2_MASK)

#define CCM_GPR_SHARED2_m33_mask_lpit1_MASK      (0x1000000U)
#define CCM_GPR_SHARED2_m33_mask_lpit1_SHIFT     (24U)
/*! m33_mask_lpit1 - m33_mask_lpit1 */
#define CCM_GPR_SHARED2_m33_mask_lpit1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_lpit1_SHIFT)) & CCM_GPR_SHARED2_m33_mask_lpit1_MASK)

#define CCM_GPR_SHARED2_m33_mask_lpit2_MASK      (0x2000000U)
#define CCM_GPR_SHARED2_m33_mask_lpit2_SHIFT     (25U)
/*! m33_mask_lpit2 - m33_mask_lpit2 */
#define CCM_GPR_SHARED2_m33_mask_lpit2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_lpit2_SHIFT)) & CCM_GPR_SHARED2_m33_mask_lpit2_MASK)

#define CCM_GPR_SHARED2_m33_mask_lpit3_MASK      (0x4000000U)
#define CCM_GPR_SHARED2_m33_mask_lpit3_SHIFT     (26U)
/*! m33_mask_lpit3 - m33_mask_lpit3 */
#define CCM_GPR_SHARED2_m33_mask_lpit3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_lpit3_SHIFT)) & CCM_GPR_SHARED2_m33_mask_lpit3_MASK)

#define CCM_GPR_SHARED2_m33_mask_tpm1_MASK       (0x8000000U)
#define CCM_GPR_SHARED2_m33_mask_tpm1_SHIFT      (27U)
/*! m33_mask_tpm1 - m33_mask_tpm1 */
#define CCM_GPR_SHARED2_m33_mask_tpm1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_tpm1_SHIFT)) & CCM_GPR_SHARED2_m33_mask_tpm1_MASK)

#define CCM_GPR_SHARED2_m33_mask_tpm2_MASK       (0x10000000U)
#define CCM_GPR_SHARED2_m33_mask_tpm2_SHIFT      (28U)
/*! m33_mask_tpm2 - m33_mask_tpm2 */
#define CCM_GPR_SHARED2_m33_mask_tpm2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_tpm2_SHIFT)) & CCM_GPR_SHARED2_m33_mask_tpm2_MASK)

#define CCM_GPR_SHARED2_m33_mask_tpm3_MASK       (0x20000000U)
#define CCM_GPR_SHARED2_m33_mask_tpm3_SHIFT      (29U)
/*! m33_mask_tpm3 - m33_mask_tpm3 */
#define CCM_GPR_SHARED2_m33_mask_tpm3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_tpm3_SHIFT)) & CCM_GPR_SHARED2_m33_mask_tpm3_MASK)

#define CCM_GPR_SHARED2_m33_mask_tpm4_MASK       (0x40000000U)
#define CCM_GPR_SHARED2_m33_mask_tpm4_SHIFT      (30U)
/*! m33_mask_tpm4 - m33_mask_tpm4 */
#define CCM_GPR_SHARED2_m33_mask_tpm4(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_tpm4_SHIFT)) & CCM_GPR_SHARED2_m33_mask_tpm4_MASK)

#define CCM_GPR_SHARED2_m33_mask_tpm5_MASK       (0x80000000U)
#define CCM_GPR_SHARED2_m33_mask_tpm5_SHIFT      (31U)
/*! m33_mask_tpm5 - m33_mask_tpm5 */
#define CCM_GPR_SHARED2_m33_mask_tpm5(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_m33_mask_tpm5_SHIFT)) & CCM_GPR_SHARED2_m33_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED2_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED2_SET_m33_mask_cm7_MASK    (0x1U)
#define CCM_GPR_SHARED2_SET_m33_mask_cm7_SHIFT   (0U)
/*! m33_mask_cm7 - m33_mask_cm7 */
#define CCM_GPR_SHARED2_SET_m33_mask_cm7(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_cm7_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_cm7_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_cm33_MASK   (0x2U)
#define CCM_GPR_SHARED2_SET_m33_mask_cm33_SHIFT  (1U)
/*! m33_mask_cm33 - m33_mask_cm33 */
#define CCM_GPR_SHARED2_SET_m33_mask_cm33(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_cm33_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_cm33_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_edma3_MASK  (0x4U)
#define CCM_GPR_SHARED2_SET_m33_mask_edma3_SHIFT (2U)
/*! m33_mask_edma3 - m33_mask_edma3 */
#define CCM_GPR_SHARED2_SET_m33_mask_edma3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_edma3_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_edma3_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_edma4_MASK  (0x8U)
#define CCM_GPR_SHARED2_SET_m33_mask_edma4_SHIFT (3U)
/*! m33_mask_edma4 - m33_mask_edma4 */
#define CCM_GPR_SHARED2_SET_m33_mask_edma4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_edma4_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_edma4_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_netc_MASK   (0x10U)
#define CCM_GPR_SHARED2_SET_m33_mask_netc_SHIFT  (4U)
/*! m33_mask_netc - m33_mask_netc */
#define CCM_GPR_SHARED2_SET_m33_mask_netc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_netc_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_netc_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_sim_aon_MASK (0x100U)
#define CCM_GPR_SHARED2_SET_m33_mask_sim_aon_SHIFT (8U)
/*! m33_mask_sim_aon - m33_mask_sim_aon */
#define CCM_GPR_SHARED2_SET_m33_mask_sim_aon(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_sim_aon_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_adc1_MASK   (0x200U)
#define CCM_GPR_SHARED2_SET_m33_mask_adc1_SHIFT  (9U)
/*! m33_mask_adc1 - m33_mask_adc1 */
#define CCM_GPR_SHARED2_SET_m33_mask_adc1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_adc1_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_adc1_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_adc2_MASK   (0x400U)
#define CCM_GPR_SHARED2_SET_m33_mask_adc2_SHIFT  (10U)
/*! m33_mask_adc2 - m33_mask_adc2 */
#define CCM_GPR_SHARED2_SET_m33_mask_adc2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_adc2_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_adc2_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_flexspi1_MASK (0x800U)
#define CCM_GPR_SHARED2_SET_m33_mask_flexspi1_SHIFT (11U)
/*! m33_mask_flexspi1 - m33_mask_flexspi1 */
#define CCM_GPR_SHARED2_SET_m33_mask_flexspi1(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_flexspi1_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_flexspi2_MASK (0x1000U)
#define CCM_GPR_SHARED2_SET_m33_mask_flexspi2_SHIFT (12U)
/*! m33_mask_flexspi2 - m33_mask_flexspi2 */
#define CCM_GPR_SHARED2_SET_m33_mask_flexspi2(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_flexspi2_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_trdc_MASK   (0x2000U)
#define CCM_GPR_SHARED2_SET_m33_mask_trdc_SHIFT  (13U)
/*! m33_mask_trdc - m33_mask_trdc */
#define CCM_GPR_SHARED2_SET_m33_mask_trdc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_trdc_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_trdc_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_semc_MASK   (0x4000U)
#define CCM_GPR_SHARED2_SET_m33_mask_semc_SHIFT  (14U)
/*! m33_mask_semc - m33_mask_semc */
#define CCM_GPR_SHARED2_SET_m33_mask_semc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_semc_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_semc_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_iee_MASK    (0x8000U)
#define CCM_GPR_SHARED2_SET_m33_mask_iee_SHIFT   (15U)
/*! m33_mask_iee - m33_mask_iee */
#define CCM_GPR_SHARED2_SET_m33_mask_iee(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_iee_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_iee_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_gpio1_MASK  (0x10000U)
#define CCM_GPR_SHARED2_SET_m33_mask_gpio1_SHIFT (16U)
/*! m33_mask_gpio1 - m33_mask_gpio1 */
#define CCM_GPR_SHARED2_SET_m33_mask_gpio1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_gpio1_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_gpio1_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_gpio2_MASK  (0x20000U)
#define CCM_GPR_SHARED2_SET_m33_mask_gpio2_SHIFT (17U)
/*! m33_mask_gpio2 - m33_mask_gpio2 */
#define CCM_GPR_SHARED2_SET_m33_mask_gpio2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_gpio2_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_gpio2_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_gpio3_MASK  (0x40000U)
#define CCM_GPR_SHARED2_SET_m33_mask_gpio3_SHIFT (18U)
/*! m33_mask_gpio3 - m33_mask_gpio3 */
#define CCM_GPR_SHARED2_SET_m33_mask_gpio3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_gpio3_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_gpio3_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_gpio4_MASK  (0x80000U)
#define CCM_GPR_SHARED2_SET_m33_mask_gpio4_SHIFT (19U)
/*! m33_mask_gpio4 - m33_mask_gpio4 */
#define CCM_GPR_SHARED2_SET_m33_mask_gpio4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_gpio4_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_gpio4_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_gpio5_MASK  (0x100000U)
#define CCM_GPR_SHARED2_SET_m33_mask_gpio5_SHIFT (20U)
/*! m33_mask_gpio5 - m33_mask_gpio5 */
#define CCM_GPR_SHARED2_SET_m33_mask_gpio5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_gpio5_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_gpio5_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_gpio6_MASK  (0x200000U)
#define CCM_GPR_SHARED2_SET_m33_mask_gpio6_SHIFT (21U)
/*! m33_mask_gpio6 - m33_mask_gpio6 */
#define CCM_GPR_SHARED2_SET_m33_mask_gpio6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_gpio6_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_gpio6_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_flexio1_MASK (0x400000U)
#define CCM_GPR_SHARED2_SET_m33_mask_flexio1_SHIFT (22U)
/*! m33_mask_flexio1 - m33_mask_flexio1 */
#define CCM_GPR_SHARED2_SET_m33_mask_flexio1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_flexio1_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_flexio1_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_flexio2_MASK (0x800000U)
#define CCM_GPR_SHARED2_SET_m33_mask_flexio2_SHIFT (23U)
/*! m33_mask_flexio2 - m33_mask_flexio2 */
#define CCM_GPR_SHARED2_SET_m33_mask_flexio2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_flexio2_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_flexio2_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_lpit1_MASK  (0x1000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_lpit1_SHIFT (24U)
/*! m33_mask_lpit1 - m33_mask_lpit1 */
#define CCM_GPR_SHARED2_SET_m33_mask_lpit1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_lpit1_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_lpit1_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_lpit2_MASK  (0x2000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_lpit2_SHIFT (25U)
/*! m33_mask_lpit2 - m33_mask_lpit2 */
#define CCM_GPR_SHARED2_SET_m33_mask_lpit2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_lpit2_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_lpit2_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_lpit3_MASK  (0x4000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_lpit3_SHIFT (26U)
/*! m33_mask_lpit3 - m33_mask_lpit3 */
#define CCM_GPR_SHARED2_SET_m33_mask_lpit3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_lpit3_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_lpit3_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_tpm1_MASK   (0x8000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_tpm1_SHIFT  (27U)
/*! m33_mask_tpm1 - m33_mask_tpm1 */
#define CCM_GPR_SHARED2_SET_m33_mask_tpm1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_tpm1_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_tpm1_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_tpm2_MASK   (0x10000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_tpm2_SHIFT  (28U)
/*! m33_mask_tpm2 - m33_mask_tpm2 */
#define CCM_GPR_SHARED2_SET_m33_mask_tpm2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_tpm2_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_tpm2_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_tpm3_MASK   (0x20000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_tpm3_SHIFT  (29U)
/*! m33_mask_tpm3 - m33_mask_tpm3 */
#define CCM_GPR_SHARED2_SET_m33_mask_tpm3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_tpm3_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_tpm3_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_tpm4_MASK   (0x40000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_tpm4_SHIFT  (30U)
/*! m33_mask_tpm4 - m33_mask_tpm4 */
#define CCM_GPR_SHARED2_SET_m33_mask_tpm4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_tpm4_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_tpm4_MASK)

#define CCM_GPR_SHARED2_SET_m33_mask_tpm5_MASK   (0x80000000U)
#define CCM_GPR_SHARED2_SET_m33_mask_tpm5_SHIFT  (31U)
/*! m33_mask_tpm5 - m33_mask_tpm5 */
#define CCM_GPR_SHARED2_SET_m33_mask_tpm5(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_SET_m33_mask_tpm5_SHIFT)) & CCM_GPR_SHARED2_SET_m33_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED2_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED2_CLR_m33_mask_cm7_MASK    (0x1U)
#define CCM_GPR_SHARED2_CLR_m33_mask_cm7_SHIFT   (0U)
/*! m33_mask_cm7 - m33_mask_cm7 */
#define CCM_GPR_SHARED2_CLR_m33_mask_cm7(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_cm7_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_cm7_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_cm33_MASK   (0x2U)
#define CCM_GPR_SHARED2_CLR_m33_mask_cm33_SHIFT  (1U)
/*! m33_mask_cm33 - m33_mask_cm33 */
#define CCM_GPR_SHARED2_CLR_m33_mask_cm33(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_cm33_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_cm33_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_edma3_MASK  (0x4U)
#define CCM_GPR_SHARED2_CLR_m33_mask_edma3_SHIFT (2U)
/*! m33_mask_edma3 - m33_mask_edma3 */
#define CCM_GPR_SHARED2_CLR_m33_mask_edma3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_edma3_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_edma3_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_edma4_MASK  (0x8U)
#define CCM_GPR_SHARED2_CLR_m33_mask_edma4_SHIFT (3U)
/*! m33_mask_edma4 - m33_mask_edma4 */
#define CCM_GPR_SHARED2_CLR_m33_mask_edma4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_edma4_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_edma4_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_netc_MASK   (0x10U)
#define CCM_GPR_SHARED2_CLR_m33_mask_netc_SHIFT  (4U)
/*! m33_mask_netc - m33_mask_netc */
#define CCM_GPR_SHARED2_CLR_m33_mask_netc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_netc_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_netc_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_sim_aon_MASK (0x100U)
#define CCM_GPR_SHARED2_CLR_m33_mask_sim_aon_SHIFT (8U)
/*! m33_mask_sim_aon - m33_mask_sim_aon */
#define CCM_GPR_SHARED2_CLR_m33_mask_sim_aon(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_sim_aon_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_adc1_MASK   (0x200U)
#define CCM_GPR_SHARED2_CLR_m33_mask_adc1_SHIFT  (9U)
/*! m33_mask_adc1 - m33_mask_adc1 */
#define CCM_GPR_SHARED2_CLR_m33_mask_adc1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_adc1_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_adc1_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_adc2_MASK   (0x400U)
#define CCM_GPR_SHARED2_CLR_m33_mask_adc2_SHIFT  (10U)
/*! m33_mask_adc2 - m33_mask_adc2 */
#define CCM_GPR_SHARED2_CLR_m33_mask_adc2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_adc2_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_adc2_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_flexspi1_MASK (0x800U)
#define CCM_GPR_SHARED2_CLR_m33_mask_flexspi1_SHIFT (11U)
/*! m33_mask_flexspi1 - m33_mask_flexspi1 */
#define CCM_GPR_SHARED2_CLR_m33_mask_flexspi1(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_flexspi1_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_flexspi2_MASK (0x1000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_flexspi2_SHIFT (12U)
/*! m33_mask_flexspi2 - m33_mask_flexspi2 */
#define CCM_GPR_SHARED2_CLR_m33_mask_flexspi2(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_flexspi2_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_trdc_MASK   (0x2000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_trdc_SHIFT  (13U)
/*! m33_mask_trdc - m33_mask_trdc */
#define CCM_GPR_SHARED2_CLR_m33_mask_trdc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_trdc_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_trdc_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_semc_MASK   (0x4000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_semc_SHIFT  (14U)
/*! m33_mask_semc - m33_mask_semc */
#define CCM_GPR_SHARED2_CLR_m33_mask_semc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_semc_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_semc_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_iee_MASK    (0x8000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_iee_SHIFT   (15U)
/*! m33_mask_iee - m33_mask_iee */
#define CCM_GPR_SHARED2_CLR_m33_mask_iee(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_iee_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_iee_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_gpio1_MASK  (0x10000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio1_SHIFT (16U)
/*! m33_mask_gpio1 - m33_mask_gpio1 */
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_gpio1_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_gpio1_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_gpio2_MASK  (0x20000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio2_SHIFT (17U)
/*! m33_mask_gpio2 - m33_mask_gpio2 */
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_gpio2_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_gpio2_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_gpio3_MASK  (0x40000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio3_SHIFT (18U)
/*! m33_mask_gpio3 - m33_mask_gpio3 */
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_gpio3_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_gpio3_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_gpio4_MASK  (0x80000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio4_SHIFT (19U)
/*! m33_mask_gpio4 - m33_mask_gpio4 */
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_gpio4_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_gpio4_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_gpio5_MASK  (0x100000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio5_SHIFT (20U)
/*! m33_mask_gpio5 - m33_mask_gpio5 */
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_gpio5_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_gpio5_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_gpio6_MASK  (0x200000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio6_SHIFT (21U)
/*! m33_mask_gpio6 - m33_mask_gpio6 */
#define CCM_GPR_SHARED2_CLR_m33_mask_gpio6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_gpio6_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_gpio6_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_flexio1_MASK (0x400000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_flexio1_SHIFT (22U)
/*! m33_mask_flexio1 - m33_mask_flexio1 */
#define CCM_GPR_SHARED2_CLR_m33_mask_flexio1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_flexio1_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_flexio1_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_flexio2_MASK (0x800000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_flexio2_SHIFT (23U)
/*! m33_mask_flexio2 - m33_mask_flexio2 */
#define CCM_GPR_SHARED2_CLR_m33_mask_flexio2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_flexio2_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_flexio2_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_lpit1_MASK  (0x1000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_lpit1_SHIFT (24U)
/*! m33_mask_lpit1 - m33_mask_lpit1 */
#define CCM_GPR_SHARED2_CLR_m33_mask_lpit1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_lpit1_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_lpit1_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_lpit2_MASK  (0x2000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_lpit2_SHIFT (25U)
/*! m33_mask_lpit2 - m33_mask_lpit2 */
#define CCM_GPR_SHARED2_CLR_m33_mask_lpit2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_lpit2_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_lpit2_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_lpit3_MASK  (0x4000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_lpit3_SHIFT (26U)
/*! m33_mask_lpit3 - m33_mask_lpit3 */
#define CCM_GPR_SHARED2_CLR_m33_mask_lpit3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_lpit3_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_lpit3_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_tpm1_MASK   (0x8000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm1_SHIFT  (27U)
/*! m33_mask_tpm1 - m33_mask_tpm1 */
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_tpm1_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_tpm1_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_tpm2_MASK   (0x10000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm2_SHIFT  (28U)
/*! m33_mask_tpm2 - m33_mask_tpm2 */
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_tpm2_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_tpm2_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_tpm3_MASK   (0x20000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm3_SHIFT  (29U)
/*! m33_mask_tpm3 - m33_mask_tpm3 */
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_tpm3_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_tpm3_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_tpm4_MASK   (0x40000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm4_SHIFT  (30U)
/*! m33_mask_tpm4 - m33_mask_tpm4 */
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_tpm4_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_tpm4_MASK)

#define CCM_GPR_SHARED2_CLR_m33_mask_tpm5_MASK   (0x80000000U)
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm5_SHIFT  (31U)
/*! m33_mask_tpm5 - m33_mask_tpm5 */
#define CCM_GPR_SHARED2_CLR_m33_mask_tpm5(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_CLR_m33_mask_tpm5_SHIFT)) & CCM_GPR_SHARED2_CLR_m33_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED2_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED2_TOG_m33_mask_cm7_MASK    (0x1U)
#define CCM_GPR_SHARED2_TOG_m33_mask_cm7_SHIFT   (0U)
/*! m33_mask_cm7 - m33_mask_cm7 */
#define CCM_GPR_SHARED2_TOG_m33_mask_cm7(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_cm7_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_cm7_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_cm33_MASK   (0x2U)
#define CCM_GPR_SHARED2_TOG_m33_mask_cm33_SHIFT  (1U)
/*! m33_mask_cm33 - m33_mask_cm33 */
#define CCM_GPR_SHARED2_TOG_m33_mask_cm33(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_cm33_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_cm33_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_edma3_MASK  (0x4U)
#define CCM_GPR_SHARED2_TOG_m33_mask_edma3_SHIFT (2U)
/*! m33_mask_edma3 - m33_mask_edma3 */
#define CCM_GPR_SHARED2_TOG_m33_mask_edma3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_edma3_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_edma3_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_edma4_MASK  (0x8U)
#define CCM_GPR_SHARED2_TOG_m33_mask_edma4_SHIFT (3U)
/*! m33_mask_edma4 - m33_mask_edma4 */
#define CCM_GPR_SHARED2_TOG_m33_mask_edma4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_edma4_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_edma4_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_netc_MASK   (0x10U)
#define CCM_GPR_SHARED2_TOG_m33_mask_netc_SHIFT  (4U)
/*! m33_mask_netc - m33_mask_netc */
#define CCM_GPR_SHARED2_TOG_m33_mask_netc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_netc_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_netc_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_sim_aon_MASK (0x100U)
#define CCM_GPR_SHARED2_TOG_m33_mask_sim_aon_SHIFT (8U)
/*! m33_mask_sim_aon - m33_mask_sim_aon */
#define CCM_GPR_SHARED2_TOG_m33_mask_sim_aon(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_sim_aon_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_adc1_MASK   (0x200U)
#define CCM_GPR_SHARED2_TOG_m33_mask_adc1_SHIFT  (9U)
/*! m33_mask_adc1 - m33_mask_adc1 */
#define CCM_GPR_SHARED2_TOG_m33_mask_adc1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_adc1_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_adc1_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_adc2_MASK   (0x400U)
#define CCM_GPR_SHARED2_TOG_m33_mask_adc2_SHIFT  (10U)
/*! m33_mask_adc2 - m33_mask_adc2 */
#define CCM_GPR_SHARED2_TOG_m33_mask_adc2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_adc2_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_adc2_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_flexspi1_MASK (0x800U)
#define CCM_GPR_SHARED2_TOG_m33_mask_flexspi1_SHIFT (11U)
/*! m33_mask_flexspi1 - m33_mask_flexspi1 */
#define CCM_GPR_SHARED2_TOG_m33_mask_flexspi1(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_flexspi1_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_flexspi2_MASK (0x1000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_flexspi2_SHIFT (12U)
/*! m33_mask_flexspi2 - m33_mask_flexspi2 */
#define CCM_GPR_SHARED2_TOG_m33_mask_flexspi2(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_flexspi2_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_trdc_MASK   (0x2000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_trdc_SHIFT  (13U)
/*! m33_mask_trdc - m33_mask_trdc */
#define CCM_GPR_SHARED2_TOG_m33_mask_trdc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_trdc_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_trdc_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_semc_MASK   (0x4000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_semc_SHIFT  (14U)
/*! m33_mask_semc - m33_mask_semc */
#define CCM_GPR_SHARED2_TOG_m33_mask_semc(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_semc_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_semc_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_iee_MASK    (0x8000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_iee_SHIFT   (15U)
/*! m33_mask_iee - m33_mask_iee */
#define CCM_GPR_SHARED2_TOG_m33_mask_iee(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_iee_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_iee_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_gpio1_MASK  (0x10000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio1_SHIFT (16U)
/*! m33_mask_gpio1 - m33_mask_gpio1 */
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_gpio1_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_gpio1_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_gpio2_MASK  (0x20000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio2_SHIFT (17U)
/*! m33_mask_gpio2 - m33_mask_gpio2 */
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_gpio2_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_gpio2_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_gpio3_MASK  (0x40000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio3_SHIFT (18U)
/*! m33_mask_gpio3 - m33_mask_gpio3 */
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_gpio3_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_gpio3_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_gpio4_MASK  (0x80000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio4_SHIFT (19U)
/*! m33_mask_gpio4 - m33_mask_gpio4 */
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_gpio4_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_gpio4_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_gpio5_MASK  (0x100000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio5_SHIFT (20U)
/*! m33_mask_gpio5 - m33_mask_gpio5 */
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_gpio5_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_gpio5_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_gpio6_MASK  (0x200000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio6_SHIFT (21U)
/*! m33_mask_gpio6 - m33_mask_gpio6 */
#define CCM_GPR_SHARED2_TOG_m33_mask_gpio6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_gpio6_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_gpio6_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_flexio1_MASK (0x400000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_flexio1_SHIFT (22U)
/*! m33_mask_flexio1 - m33_mask_flexio1 */
#define CCM_GPR_SHARED2_TOG_m33_mask_flexio1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_flexio1_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_flexio1_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_flexio2_MASK (0x800000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_flexio2_SHIFT (23U)
/*! m33_mask_flexio2 - m33_mask_flexio2 */
#define CCM_GPR_SHARED2_TOG_m33_mask_flexio2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_flexio2_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_flexio2_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_lpit1_MASK  (0x1000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_lpit1_SHIFT (24U)
/*! m33_mask_lpit1 - m33_mask_lpit1 */
#define CCM_GPR_SHARED2_TOG_m33_mask_lpit1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_lpit1_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_lpit1_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_lpit2_MASK  (0x2000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_lpit2_SHIFT (25U)
/*! m33_mask_lpit2 - m33_mask_lpit2 */
#define CCM_GPR_SHARED2_TOG_m33_mask_lpit2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_lpit2_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_lpit2_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_lpit3_MASK  (0x4000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_lpit3_SHIFT (26U)
/*! m33_mask_lpit3 - m33_mask_lpit3 */
#define CCM_GPR_SHARED2_TOG_m33_mask_lpit3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_lpit3_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_lpit3_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_tpm1_MASK   (0x8000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm1_SHIFT  (27U)
/*! m33_mask_tpm1 - m33_mask_tpm1 */
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_tpm1_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_tpm1_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_tpm2_MASK   (0x10000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm2_SHIFT  (28U)
/*! m33_mask_tpm2 - m33_mask_tpm2 */
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_tpm2_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_tpm2_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_tpm3_MASK   (0x20000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm3_SHIFT  (29U)
/*! m33_mask_tpm3 - m33_mask_tpm3 */
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_tpm3_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_tpm3_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_tpm4_MASK   (0x40000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm4_SHIFT  (30U)
/*! m33_mask_tpm4 - m33_mask_tpm4 */
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_tpm4_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_tpm4_MASK)

#define CCM_GPR_SHARED2_TOG_m33_mask_tpm5_MASK   (0x80000000U)
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm5_SHIFT  (31U)
/*! m33_mask_tpm5 - m33_mask_tpm5 */
#define CCM_GPR_SHARED2_TOG_m33_mask_tpm5(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_TOG_m33_mask_tpm5_SHIFT)) & CCM_GPR_SHARED2_TOG_m33_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED2_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED2_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED2_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED2_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED2_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED2_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED2_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED2_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED2_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED2_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED2_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED2_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED2_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED2_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED2_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED2_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED2_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED2_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED2_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED2_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED2_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED2_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED2_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED2_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED2_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED2_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED2_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED2_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED2_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED2_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED2_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED2_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED2_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED2_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED2_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED2_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED2_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED2_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED2_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED2_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED3 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED3_m33_mask_tpm6_MASK       (0x1U)
#define CCM_GPR_SHARED3_m33_mask_tpm6_SHIFT      (0U)
/*! m33_mask_tpm6 - m33_mask_tpm6 */
#define CCM_GPR_SHARED3_m33_mask_tpm6(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_tpm6_SHIFT)) & CCM_GPR_SHARED3_m33_mask_tpm6_MASK)

#define CCM_GPR_SHARED3_m33_mask_gpt1_MASK       (0x2U)
#define CCM_GPR_SHARED3_m33_mask_gpt1_SHIFT      (1U)
/*! m33_mask_gpt1 - m33_mask_gpt1 */
#define CCM_GPR_SHARED3_m33_mask_gpt1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_gpt1_SHIFT)) & CCM_GPR_SHARED3_m33_mask_gpt1_MASK)

#define CCM_GPR_SHARED3_m33_mask_gpt2_MASK       (0x4U)
#define CCM_GPR_SHARED3_m33_mask_gpt2_SHIFT      (2U)
/*! m33_mask_gpt2 - m33_mask_gpt2 */
#define CCM_GPR_SHARED3_m33_mask_gpt2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_gpt2_SHIFT)) & CCM_GPR_SHARED3_m33_mask_gpt2_MASK)

#define CCM_GPR_SHARED3_m33_mask_can1_MASK       (0x8U)
#define CCM_GPR_SHARED3_m33_mask_can1_SHIFT      (3U)
/*! m33_mask_can1 - m33_mask_can1 */
#define CCM_GPR_SHARED3_m33_mask_can1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_can1_SHIFT)) & CCM_GPR_SHARED3_m33_mask_can1_MASK)

#define CCM_GPR_SHARED3_m33_mask_can2_MASK       (0x10U)
#define CCM_GPR_SHARED3_m33_mask_can2_SHIFT      (4U)
/*! m33_mask_can2 - m33_mask_can2 */
#define CCM_GPR_SHARED3_m33_mask_can2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_can2_SHIFT)) & CCM_GPR_SHARED3_m33_mask_can2_MASK)

#define CCM_GPR_SHARED3_m33_mask_can3_MASK       (0x20U)
#define CCM_GPR_SHARED3_m33_mask_can3_SHIFT      (5U)
/*! m33_mask_can3 - m33_mask_can3 */
#define CCM_GPR_SHARED3_m33_mask_can3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_can3_SHIFT)) & CCM_GPR_SHARED3_m33_mask_can3_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart1_MASK    (0x40U)
#define CCM_GPR_SHARED3_m33_mask_lpuart1_SHIFT   (6U)
/*! m33_mask_lpuart1 - m33_mask_lpuart1 */
#define CCM_GPR_SHARED3_m33_mask_lpuart1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart1_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart2_MASK    (0x80U)
#define CCM_GPR_SHARED3_m33_mask_lpuart2_SHIFT   (7U)
/*! m33_mask_lpuart2 - m33_mask_lpuart2 */
#define CCM_GPR_SHARED3_m33_mask_lpuart2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart2_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart3_MASK    (0x100U)
#define CCM_GPR_SHARED3_m33_mask_lpuart3_SHIFT   (8U)
/*! m33_mask_lpuart3 - m33_mask_lpuart3 */
#define CCM_GPR_SHARED3_m33_mask_lpuart3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart3_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart4_MASK    (0x200U)
#define CCM_GPR_SHARED3_m33_mask_lpuart4_SHIFT   (9U)
/*! m33_mask_lpuart4 - m33_mask_lpuart4 */
#define CCM_GPR_SHARED3_m33_mask_lpuart4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart4_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart5_MASK    (0x400U)
#define CCM_GPR_SHARED3_m33_mask_lpuart5_SHIFT   (10U)
/*! m33_mask_lpuart5 - m33_mask_lpuart5 */
#define CCM_GPR_SHARED3_m33_mask_lpuart5(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart5_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart6_MASK    (0x800U)
#define CCM_GPR_SHARED3_m33_mask_lpuart6_SHIFT   (11U)
/*! m33_mask_lpuart6 - m33_mask_lpuart6 */
#define CCM_GPR_SHARED3_m33_mask_lpuart6(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart6_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart7_MASK    (0x1000U)
#define CCM_GPR_SHARED3_m33_mask_lpuart7_SHIFT   (12U)
/*! m33_mask_lpuart7 - m33_mask_lpuart7 */
#define CCM_GPR_SHARED3_m33_mask_lpuart7(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart7_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart8_MASK    (0x2000U)
#define CCM_GPR_SHARED3_m33_mask_lpuart8_SHIFT   (13U)
/*! m33_mask_lpuart8 - m33_mask_lpuart8 */
#define CCM_GPR_SHARED3_m33_mask_lpuart8(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart8_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart9_MASK    (0x4000U)
#define CCM_GPR_SHARED3_m33_mask_lpuart9_SHIFT   (14U)
/*! m33_mask_lpuart9 - m33_mask_lpuart9 */
#define CCM_GPR_SHARED3_m33_mask_lpuart9(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart9_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart10_MASK   (0x8000U)
#define CCM_GPR_SHARED3_m33_mask_lpuart10_SHIFT  (15U)
/*! m33_mask_lpuart10 - m33_mask_lpuart10 */
#define CCM_GPR_SHARED3_m33_mask_lpuart10(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart10_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart11_MASK   (0x10000U)
#define CCM_GPR_SHARED3_m33_mask_lpuart11_SHIFT  (16U)
/*! m33_mask_lpuart11 - m33_mask_lpuart11 */
#define CCM_GPR_SHARED3_m33_mask_lpuart11(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart11_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpuart12_MASK   (0x20000U)
#define CCM_GPR_SHARED3_m33_mask_lpuart12_SHIFT  (17U)
/*! m33_mask_lpuart12 - m33_mask_lpuart12 */
#define CCM_GPR_SHARED3_m33_mask_lpuart12(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpuart12_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpi2c1_MASK     (0x40000U)
#define CCM_GPR_SHARED3_m33_mask_lpi2c1_SHIFT    (18U)
/*! m33_mask_lpi2c1 - m33_mask_lpi2c1 */
#define CCM_GPR_SHARED3_m33_mask_lpi2c1(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpi2c2_MASK     (0x80000U)
#define CCM_GPR_SHARED3_m33_mask_lpi2c2_SHIFT    (19U)
/*! m33_mask_lpi2c2 - m33_mask_lpi2c2 */
#define CCM_GPR_SHARED3_m33_mask_lpi2c2(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpi2c3_MASK     (0x100000U)
#define CCM_GPR_SHARED3_m33_mask_lpi2c3_SHIFT    (20U)
/*! m33_mask_lpi2c3 - m33_mask_lpi2c3 */
#define CCM_GPR_SHARED3_m33_mask_lpi2c3(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpi2c4_MASK     (0x200000U)
#define CCM_GPR_SHARED3_m33_mask_lpi2c4_SHIFT    (21U)
/*! m33_mask_lpi2c4 - m33_mask_lpi2c4 */
#define CCM_GPR_SHARED3_m33_mask_lpi2c4(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpi2c5_MASK     (0x400000U)
#define CCM_GPR_SHARED3_m33_mask_lpi2c5_SHIFT    (22U)
/*! m33_mask_lpi2c5 - m33_mask_lpi2c5 */
#define CCM_GPR_SHARED3_m33_mask_lpi2c5(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpi2c6_MASK     (0x800000U)
#define CCM_GPR_SHARED3_m33_mask_lpi2c6_SHIFT    (23U)
/*! m33_mask_lpi2c6 - m33_mask_lpi2c6 */
#define CCM_GPR_SHARED3_m33_mask_lpi2c6(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpspi1_MASK     (0x1000000U)
#define CCM_GPR_SHARED3_m33_mask_lpspi1_SHIFT    (24U)
/*! m33_mask_lpspi1 - m33_mask_lpspi1 */
#define CCM_GPR_SHARED3_m33_mask_lpspi1(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpspi1_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpspi2_MASK     (0x2000000U)
#define CCM_GPR_SHARED3_m33_mask_lpspi2_SHIFT    (25U)
/*! m33_mask_lpspi2 - m33_mask_lpspi2 */
#define CCM_GPR_SHARED3_m33_mask_lpspi2(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpspi2_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpspi3_MASK     (0x4000000U)
#define CCM_GPR_SHARED3_m33_mask_lpspi3_SHIFT    (26U)
/*! m33_mask_lpspi3 - m33_mask_lpspi3 */
#define CCM_GPR_SHARED3_m33_mask_lpspi3(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpspi3_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpspi4_MASK     (0x8000000U)
#define CCM_GPR_SHARED3_m33_mask_lpspi4_SHIFT    (27U)
/*! m33_mask_lpspi4 - m33_mask_lpspi4 */
#define CCM_GPR_SHARED3_m33_mask_lpspi4(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpspi4_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpspi5_MASK     (0x10000000U)
#define CCM_GPR_SHARED3_m33_mask_lpspi5_SHIFT    (28U)
/*! m33_mask_lpspi5 - m33_mask_lpspi5 */
#define CCM_GPR_SHARED3_m33_mask_lpspi5(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpspi5_MASK)

#define CCM_GPR_SHARED3_m33_mask_lpspi6_MASK     (0x20000000U)
#define CCM_GPR_SHARED3_m33_mask_lpspi6_SHIFT    (29U)
/*! m33_mask_lpspi6 - m33_mask_lpspi6 */
#define CCM_GPR_SHARED3_m33_mask_lpspi6(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED3_m33_mask_lpspi6_MASK)

#define CCM_GPR_SHARED3_m33_mask_sinc1_MASK      (0x40000000U)
#define CCM_GPR_SHARED3_m33_mask_sinc1_SHIFT     (30U)
/*! m33_mask_sinc1 - m33_mask_sinc1 */
#define CCM_GPR_SHARED3_m33_mask_sinc1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_sinc1_SHIFT)) & CCM_GPR_SHARED3_m33_mask_sinc1_MASK)

#define CCM_GPR_SHARED3_m33_mask_sinc2_MASK      (0x80000000U)
#define CCM_GPR_SHARED3_m33_mask_sinc2_SHIFT     (31U)
/*! m33_mask_sinc2 - m33_mask_sinc2 */
#define CCM_GPR_SHARED3_m33_mask_sinc2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_m33_mask_sinc2_SHIFT)) & CCM_GPR_SHARED3_m33_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED3_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED3_SET_m33_mask_tpm6_MASK   (0x1U)
#define CCM_GPR_SHARED3_SET_m33_mask_tpm6_SHIFT  (0U)
/*! m33_mask_tpm6 - m33_mask_tpm6 */
#define CCM_GPR_SHARED3_SET_m33_mask_tpm6(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_tpm6_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_tpm6_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_gpt1_MASK   (0x2U)
#define CCM_GPR_SHARED3_SET_m33_mask_gpt1_SHIFT  (1U)
/*! m33_mask_gpt1 - m33_mask_gpt1 */
#define CCM_GPR_SHARED3_SET_m33_mask_gpt1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_gpt1_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_gpt1_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_gpt2_MASK   (0x4U)
#define CCM_GPR_SHARED3_SET_m33_mask_gpt2_SHIFT  (2U)
/*! m33_mask_gpt2 - m33_mask_gpt2 */
#define CCM_GPR_SHARED3_SET_m33_mask_gpt2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_gpt2_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_gpt2_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_can1_MASK   (0x8U)
#define CCM_GPR_SHARED3_SET_m33_mask_can1_SHIFT  (3U)
/*! m33_mask_can1 - m33_mask_can1 */
#define CCM_GPR_SHARED3_SET_m33_mask_can1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_can1_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_can1_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_can2_MASK   (0x10U)
#define CCM_GPR_SHARED3_SET_m33_mask_can2_SHIFT  (4U)
/*! m33_mask_can2 - m33_mask_can2 */
#define CCM_GPR_SHARED3_SET_m33_mask_can2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_can2_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_can2_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_can3_MASK   (0x20U)
#define CCM_GPR_SHARED3_SET_m33_mask_can3_SHIFT  (5U)
/*! m33_mask_can3 - m33_mask_can3 */
#define CCM_GPR_SHARED3_SET_m33_mask_can3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_can3_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_can3_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart1_MASK (0x40U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart1_SHIFT (6U)
/*! m33_mask_lpuart1 - m33_mask_lpuart1 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart1_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart2_MASK (0x80U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart2_SHIFT (7U)
/*! m33_mask_lpuart2 - m33_mask_lpuart2 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart2_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart3_MASK (0x100U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart3_SHIFT (8U)
/*! m33_mask_lpuart3 - m33_mask_lpuart3 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart3(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart3_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart4_MASK (0x200U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart4_SHIFT (9U)
/*! m33_mask_lpuart4 - m33_mask_lpuart4 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart4(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart4_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart5_MASK (0x400U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart5_SHIFT (10U)
/*! m33_mask_lpuart5 - m33_mask_lpuart5 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart5(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart5_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart6_MASK (0x800U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart6_SHIFT (11U)
/*! m33_mask_lpuart6 - m33_mask_lpuart6 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart6(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart6_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart7_MASK (0x1000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart7_SHIFT (12U)
/*! m33_mask_lpuart7 - m33_mask_lpuart7 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart7(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart7_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart8_MASK (0x2000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart8_SHIFT (13U)
/*! m33_mask_lpuart8 - m33_mask_lpuart8 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart8(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart8_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart9_MASK (0x4000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart9_SHIFT (14U)
/*! m33_mask_lpuart9 - m33_mask_lpuart9 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart9(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart9_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart10_MASK (0x8000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart10_SHIFT (15U)
/*! m33_mask_lpuart10 - m33_mask_lpuart10 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart10(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart10_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart11_MASK (0x10000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart11_SHIFT (16U)
/*! m33_mask_lpuart11 - m33_mask_lpuart11 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart11(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart11_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpuart12_MASK (0x20000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart12_SHIFT (17U)
/*! m33_mask_lpuart12 - m33_mask_lpuart12 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpuart12(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpuart12_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c1_MASK (0x40000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c1_SHIFT (18U)
/*! m33_mask_lpi2c1 - m33_mask_lpi2c1 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c2_MASK (0x80000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c2_SHIFT (19U)
/*! m33_mask_lpi2c2 - m33_mask_lpi2c2 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c3_MASK (0x100000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c3_SHIFT (20U)
/*! m33_mask_lpi2c3 - m33_mask_lpi2c3 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c4_MASK (0x200000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c4_SHIFT (21U)
/*! m33_mask_lpi2c4 - m33_mask_lpi2c4 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c5_MASK (0x400000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c5_SHIFT (22U)
/*! m33_mask_lpi2c5 - m33_mask_lpi2c5 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c6_MASK (0x800000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c6_SHIFT (23U)
/*! m33_mask_lpi2c6 - m33_mask_lpi2c6 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpi2c6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpspi1_MASK (0x1000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi1_SHIFT (24U)
/*! m33_mask_lpspi1 - m33_mask_lpspi1 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpspi1_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpspi2_MASK (0x2000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi2_SHIFT (25U)
/*! m33_mask_lpspi2 - m33_mask_lpspi2 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpspi2_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpspi3_MASK (0x4000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi3_SHIFT (26U)
/*! m33_mask_lpspi3 - m33_mask_lpspi3 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpspi3_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpspi4_MASK (0x8000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi4_SHIFT (27U)
/*! m33_mask_lpspi4 - m33_mask_lpspi4 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpspi4_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpspi5_MASK (0x10000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi5_SHIFT (28U)
/*! m33_mask_lpspi5 - m33_mask_lpspi5 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpspi5_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_lpspi6_MASK (0x20000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi6_SHIFT (29U)
/*! m33_mask_lpspi6 - m33_mask_lpspi6 */
#define CCM_GPR_SHARED3_SET_m33_mask_lpspi6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_lpspi6_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_sinc1_MASK  (0x40000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_sinc1_SHIFT (30U)
/*! m33_mask_sinc1 - m33_mask_sinc1 */
#define CCM_GPR_SHARED3_SET_m33_mask_sinc1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_sinc1_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_sinc1_MASK)

#define CCM_GPR_SHARED3_SET_m33_mask_sinc2_MASK  (0x80000000U)
#define CCM_GPR_SHARED3_SET_m33_mask_sinc2_SHIFT (31U)
/*! m33_mask_sinc2 - m33_mask_sinc2 */
#define CCM_GPR_SHARED3_SET_m33_mask_sinc2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_SET_m33_mask_sinc2_SHIFT)) & CCM_GPR_SHARED3_SET_m33_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED3_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED3_CLR_m33_mask_tpm6_MASK   (0x1U)
#define CCM_GPR_SHARED3_CLR_m33_mask_tpm6_SHIFT  (0U)
/*! m33_mask_tpm6 - m33_mask_tpm6 */
#define CCM_GPR_SHARED3_CLR_m33_mask_tpm6(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_tpm6_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_tpm6_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_gpt1_MASK   (0x2U)
#define CCM_GPR_SHARED3_CLR_m33_mask_gpt1_SHIFT  (1U)
/*! m33_mask_gpt1 - m33_mask_gpt1 */
#define CCM_GPR_SHARED3_CLR_m33_mask_gpt1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_gpt1_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_gpt1_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_gpt2_MASK   (0x4U)
#define CCM_GPR_SHARED3_CLR_m33_mask_gpt2_SHIFT  (2U)
/*! m33_mask_gpt2 - m33_mask_gpt2 */
#define CCM_GPR_SHARED3_CLR_m33_mask_gpt2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_gpt2_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_gpt2_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_can1_MASK   (0x8U)
#define CCM_GPR_SHARED3_CLR_m33_mask_can1_SHIFT  (3U)
/*! m33_mask_can1 - m33_mask_can1 */
#define CCM_GPR_SHARED3_CLR_m33_mask_can1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_can1_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_can1_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_can2_MASK   (0x10U)
#define CCM_GPR_SHARED3_CLR_m33_mask_can2_SHIFT  (4U)
/*! m33_mask_can2 - m33_mask_can2 */
#define CCM_GPR_SHARED3_CLR_m33_mask_can2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_can2_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_can2_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_can3_MASK   (0x20U)
#define CCM_GPR_SHARED3_CLR_m33_mask_can3_SHIFT  (5U)
/*! m33_mask_can3 - m33_mask_can3 */
#define CCM_GPR_SHARED3_CLR_m33_mask_can3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_can3_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_can3_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart1_MASK (0x40U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart1_SHIFT (6U)
/*! m33_mask_lpuart1 - m33_mask_lpuart1 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart1_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart2_MASK (0x80U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart2_SHIFT (7U)
/*! m33_mask_lpuart2 - m33_mask_lpuart2 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart2_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart3_MASK (0x100U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart3_SHIFT (8U)
/*! m33_mask_lpuart3 - m33_mask_lpuart3 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart3(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart3_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart4_MASK (0x200U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart4_SHIFT (9U)
/*! m33_mask_lpuart4 - m33_mask_lpuart4 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart4(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart4_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart5_MASK (0x400U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart5_SHIFT (10U)
/*! m33_mask_lpuart5 - m33_mask_lpuart5 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart5(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart5_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart6_MASK (0x800U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart6_SHIFT (11U)
/*! m33_mask_lpuart6 - m33_mask_lpuart6 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart6(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart6_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart7_MASK (0x1000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart7_SHIFT (12U)
/*! m33_mask_lpuart7 - m33_mask_lpuart7 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart7(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart7_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart8_MASK (0x2000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart8_SHIFT (13U)
/*! m33_mask_lpuart8 - m33_mask_lpuart8 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart8(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart8_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart9_MASK (0x4000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart9_SHIFT (14U)
/*! m33_mask_lpuart9 - m33_mask_lpuart9 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart9(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart9_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart10_MASK (0x8000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart10_SHIFT (15U)
/*! m33_mask_lpuart10 - m33_mask_lpuart10 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart10(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart10_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart11_MASK (0x10000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart11_SHIFT (16U)
/*! m33_mask_lpuart11 - m33_mask_lpuart11 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart11(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart11_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart12_MASK (0x20000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart12_SHIFT (17U)
/*! m33_mask_lpuart12 - m33_mask_lpuart12 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpuart12(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpuart12_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c1_MASK (0x40000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c1_SHIFT (18U)
/*! m33_mask_lpi2c1 - m33_mask_lpi2c1 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c2_MASK (0x80000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c2_SHIFT (19U)
/*! m33_mask_lpi2c2 - m33_mask_lpi2c2 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c3_MASK (0x100000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c3_SHIFT (20U)
/*! m33_mask_lpi2c3 - m33_mask_lpi2c3 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c4_MASK (0x200000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c4_SHIFT (21U)
/*! m33_mask_lpi2c4 - m33_mask_lpi2c4 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c5_MASK (0x400000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c5_SHIFT (22U)
/*! m33_mask_lpi2c5 - m33_mask_lpi2c5 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c6_MASK (0x800000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c6_SHIFT (23U)
/*! m33_mask_lpi2c6 - m33_mask_lpi2c6 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpi2c6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi1_MASK (0x1000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi1_SHIFT (24U)
/*! m33_mask_lpspi1 - m33_mask_lpspi1 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpspi1_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi2_MASK (0x2000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi2_SHIFT (25U)
/*! m33_mask_lpspi2 - m33_mask_lpspi2 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpspi2_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi3_MASK (0x4000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi3_SHIFT (26U)
/*! m33_mask_lpspi3 - m33_mask_lpspi3 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpspi3_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi4_MASK (0x8000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi4_SHIFT (27U)
/*! m33_mask_lpspi4 - m33_mask_lpspi4 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpspi4_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi5_MASK (0x10000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi5_SHIFT (28U)
/*! m33_mask_lpspi5 - m33_mask_lpspi5 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpspi5_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi6_MASK (0x20000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi6_SHIFT (29U)
/*! m33_mask_lpspi6 - m33_mask_lpspi6 */
#define CCM_GPR_SHARED3_CLR_m33_mask_lpspi6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_lpspi6_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_sinc1_MASK  (0x40000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_sinc1_SHIFT (30U)
/*! m33_mask_sinc1 - m33_mask_sinc1 */
#define CCM_GPR_SHARED3_CLR_m33_mask_sinc1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_sinc1_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_sinc1_MASK)

#define CCM_GPR_SHARED3_CLR_m33_mask_sinc2_MASK  (0x80000000U)
#define CCM_GPR_SHARED3_CLR_m33_mask_sinc2_SHIFT (31U)
/*! m33_mask_sinc2 - m33_mask_sinc2 */
#define CCM_GPR_SHARED3_CLR_m33_mask_sinc2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_CLR_m33_mask_sinc2_SHIFT)) & CCM_GPR_SHARED3_CLR_m33_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED3_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED3_TOG_m33_mask_tpm6_MASK   (0x1U)
#define CCM_GPR_SHARED3_TOG_m33_mask_tpm6_SHIFT  (0U)
/*! m33_mask_tpm6 - m33_mask_tpm6 */
#define CCM_GPR_SHARED3_TOG_m33_mask_tpm6(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_tpm6_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_tpm6_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_gpt1_MASK   (0x2U)
#define CCM_GPR_SHARED3_TOG_m33_mask_gpt1_SHIFT  (1U)
/*! m33_mask_gpt1 - m33_mask_gpt1 */
#define CCM_GPR_SHARED3_TOG_m33_mask_gpt1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_gpt1_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_gpt1_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_gpt2_MASK   (0x4U)
#define CCM_GPR_SHARED3_TOG_m33_mask_gpt2_SHIFT  (2U)
/*! m33_mask_gpt2 - m33_mask_gpt2 */
#define CCM_GPR_SHARED3_TOG_m33_mask_gpt2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_gpt2_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_gpt2_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_can1_MASK   (0x8U)
#define CCM_GPR_SHARED3_TOG_m33_mask_can1_SHIFT  (3U)
/*! m33_mask_can1 - m33_mask_can1 */
#define CCM_GPR_SHARED3_TOG_m33_mask_can1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_can1_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_can1_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_can2_MASK   (0x10U)
#define CCM_GPR_SHARED3_TOG_m33_mask_can2_SHIFT  (4U)
/*! m33_mask_can2 - m33_mask_can2 */
#define CCM_GPR_SHARED3_TOG_m33_mask_can2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_can2_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_can2_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_can3_MASK   (0x20U)
#define CCM_GPR_SHARED3_TOG_m33_mask_can3_SHIFT  (5U)
/*! m33_mask_can3 - m33_mask_can3 */
#define CCM_GPR_SHARED3_TOG_m33_mask_can3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_can3_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_can3_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart1_MASK (0x40U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart1_SHIFT (6U)
/*! m33_mask_lpuart1 - m33_mask_lpuart1 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart1_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart2_MASK (0x80U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart2_SHIFT (7U)
/*! m33_mask_lpuart2 - m33_mask_lpuart2 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart2_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart3_MASK (0x100U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart3_SHIFT (8U)
/*! m33_mask_lpuart3 - m33_mask_lpuart3 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart3(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart3_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart4_MASK (0x200U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart4_SHIFT (9U)
/*! m33_mask_lpuart4 - m33_mask_lpuart4 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart4(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart4_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart5_MASK (0x400U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart5_SHIFT (10U)
/*! m33_mask_lpuart5 - m33_mask_lpuart5 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart5(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart5_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart6_MASK (0x800U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart6_SHIFT (11U)
/*! m33_mask_lpuart6 - m33_mask_lpuart6 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart6(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart6_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart7_MASK (0x1000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart7_SHIFT (12U)
/*! m33_mask_lpuart7 - m33_mask_lpuart7 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart7(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart7_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart8_MASK (0x2000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart8_SHIFT (13U)
/*! m33_mask_lpuart8 - m33_mask_lpuart8 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart8(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart8_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart9_MASK (0x4000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart9_SHIFT (14U)
/*! m33_mask_lpuart9 - m33_mask_lpuart9 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart9(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart9_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart10_MASK (0x8000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart10_SHIFT (15U)
/*! m33_mask_lpuart10 - m33_mask_lpuart10 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart10(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart10_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart11_MASK (0x10000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart11_SHIFT (16U)
/*! m33_mask_lpuart11 - m33_mask_lpuart11 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart11(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart11_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart12_MASK (0x20000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart12_SHIFT (17U)
/*! m33_mask_lpuart12 - m33_mask_lpuart12 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpuart12(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpuart12_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c1_MASK (0x40000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c1_SHIFT (18U)
/*! m33_mask_lpi2c1 - m33_mask_lpi2c1 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c2_MASK (0x80000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c2_SHIFT (19U)
/*! m33_mask_lpi2c2 - m33_mask_lpi2c2 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c3_MASK (0x100000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c3_SHIFT (20U)
/*! m33_mask_lpi2c3 - m33_mask_lpi2c3 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c4_MASK (0x200000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c4_SHIFT (21U)
/*! m33_mask_lpi2c4 - m33_mask_lpi2c4 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c5_MASK (0x400000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c5_SHIFT (22U)
/*! m33_mask_lpi2c5 - m33_mask_lpi2c5 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c6_MASK (0x800000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c6_SHIFT (23U)
/*! m33_mask_lpi2c6 - m33_mask_lpi2c6 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpi2c6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi1_MASK (0x1000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi1_SHIFT (24U)
/*! m33_mask_lpspi1 - m33_mask_lpspi1 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpspi1_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi2_MASK (0x2000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi2_SHIFT (25U)
/*! m33_mask_lpspi2 - m33_mask_lpspi2 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpspi2_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi3_MASK (0x4000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi3_SHIFT (26U)
/*! m33_mask_lpspi3 - m33_mask_lpspi3 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpspi3_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi4_MASK (0x8000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi4_SHIFT (27U)
/*! m33_mask_lpspi4 - m33_mask_lpspi4 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpspi4_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi5_MASK (0x10000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi5_SHIFT (28U)
/*! m33_mask_lpspi5 - m33_mask_lpspi5 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpspi5_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi6_MASK (0x20000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi6_SHIFT (29U)
/*! m33_mask_lpspi6 - m33_mask_lpspi6 */
#define CCM_GPR_SHARED3_TOG_m33_mask_lpspi6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_lpspi6_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_sinc1_MASK  (0x40000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_sinc1_SHIFT (30U)
/*! m33_mask_sinc1 - m33_mask_sinc1 */
#define CCM_GPR_SHARED3_TOG_m33_mask_sinc1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_sinc1_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_sinc1_MASK)

#define CCM_GPR_SHARED3_TOG_m33_mask_sinc2_MASK  (0x80000000U)
#define CCM_GPR_SHARED3_TOG_m33_mask_sinc2_SHIFT (31U)
/*! m33_mask_sinc2 - m33_mask_sinc2 */
#define CCM_GPR_SHARED3_TOG_m33_mask_sinc2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_TOG_m33_mask_sinc2_SHIFT)) & CCM_GPR_SHARED3_TOG_m33_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED3_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED3_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED3_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED3_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED3_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED3_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED3_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED3_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED3_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED3_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED3_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED3_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED3_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED3_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED3_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED3_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED3_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED3_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED3_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED3_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED3_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED3_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED3_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED3_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED3_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED3_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED3_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED3_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED3_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED3_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED3_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED3_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED3_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED3_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED3_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED3_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED3_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED3_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED3_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED3_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED3_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED3_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED3_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED3_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED3_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED3_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED3_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED3_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED3_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED3_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED3_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED3_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED3_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED3_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED4 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED4_m33_mask_sinc3_MASK      (0x1U)
#define CCM_GPR_SHARED4_m33_mask_sinc3_SHIFT     (0U)
/*! m33_mask_sinc3 - m33_mask_sinc3 */
#define CCM_GPR_SHARED4_m33_mask_sinc3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_m33_mask_sinc3_SHIFT)) & CCM_GPR_SHARED4_m33_mask_sinc3_MASK)

#define CCM_GPR_SHARED4_m33_mask_sai1_MASK       (0x2U)
#define CCM_GPR_SHARED4_m33_mask_sai1_SHIFT      (1U)
/*! m33_mask_sai1 - m33_mask_sai1 */
#define CCM_GPR_SHARED4_m33_mask_sai1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_m33_mask_sai1_SHIFT)) & CCM_GPR_SHARED4_m33_mask_sai1_MASK)

#define CCM_GPR_SHARED4_m33_mask_sai2_MASK       (0x4U)
#define CCM_GPR_SHARED4_m33_mask_sai2_SHIFT      (2U)
/*! m33_mask_sai2 - m33_mask_sai2 */
#define CCM_GPR_SHARED4_m33_mask_sai2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_m33_mask_sai2_SHIFT)) & CCM_GPR_SHARED4_m33_mask_sai2_MASK)

#define CCM_GPR_SHARED4_m33_mask_sai3_MASK       (0x8U)
#define CCM_GPR_SHARED4_m33_mask_sai3_SHIFT      (3U)
/*! m33_mask_sai3 - m33_mask_sai3 */
#define CCM_GPR_SHARED4_m33_mask_sai3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_m33_mask_sai3_SHIFT)) & CCM_GPR_SHARED4_m33_mask_sai3_MASK)

#define CCM_GPR_SHARED4_m33_mask_sai4_MASK       (0x10U)
#define CCM_GPR_SHARED4_m33_mask_sai4_SHIFT      (4U)
/*! m33_mask_sai4 - m33_mask_sai4 */
#define CCM_GPR_SHARED4_m33_mask_sai4(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_m33_mask_sai4_SHIFT)) & CCM_GPR_SHARED4_m33_mask_sai4_MASK)

#define CCM_GPR_SHARED4_m33_mask_mic_MASK        (0x20U)
#define CCM_GPR_SHARED4_m33_mask_mic_SHIFT       (5U)
/*! m33_mask_mic - m33_mask_mic */
#define CCM_GPR_SHARED4_m33_mask_mic(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_m33_mask_mic_SHIFT)) & CCM_GPR_SHARED4_m33_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED4_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED4_SET_m33_mask_sinc3_MASK  (0x1U)
#define CCM_GPR_SHARED4_SET_m33_mask_sinc3_SHIFT (0U)
/*! m33_mask_sinc3 - m33_mask_sinc3 */
#define CCM_GPR_SHARED4_SET_m33_mask_sinc3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_SET_m33_mask_sinc3_SHIFT)) & CCM_GPR_SHARED4_SET_m33_mask_sinc3_MASK)

#define CCM_GPR_SHARED4_SET_m33_mask_sai1_MASK   (0x2U)
#define CCM_GPR_SHARED4_SET_m33_mask_sai1_SHIFT  (1U)
/*! m33_mask_sai1 - m33_mask_sai1 */
#define CCM_GPR_SHARED4_SET_m33_mask_sai1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_SET_m33_mask_sai1_SHIFT)) & CCM_GPR_SHARED4_SET_m33_mask_sai1_MASK)

#define CCM_GPR_SHARED4_SET_m33_mask_sai2_MASK   (0x4U)
#define CCM_GPR_SHARED4_SET_m33_mask_sai2_SHIFT  (2U)
/*! m33_mask_sai2 - m33_mask_sai2 */
#define CCM_GPR_SHARED4_SET_m33_mask_sai2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_SET_m33_mask_sai2_SHIFT)) & CCM_GPR_SHARED4_SET_m33_mask_sai2_MASK)

#define CCM_GPR_SHARED4_SET_m33_mask_sai3_MASK   (0x8U)
#define CCM_GPR_SHARED4_SET_m33_mask_sai3_SHIFT  (3U)
/*! m33_mask_sai3 - m33_mask_sai3 */
#define CCM_GPR_SHARED4_SET_m33_mask_sai3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_SET_m33_mask_sai3_SHIFT)) & CCM_GPR_SHARED4_SET_m33_mask_sai3_MASK)

#define CCM_GPR_SHARED4_SET_m33_mask_sai4_MASK   (0x10U)
#define CCM_GPR_SHARED4_SET_m33_mask_sai4_SHIFT  (4U)
/*! m33_mask_sai4 - m33_mask_sai4 */
#define CCM_GPR_SHARED4_SET_m33_mask_sai4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_SET_m33_mask_sai4_SHIFT)) & CCM_GPR_SHARED4_SET_m33_mask_sai4_MASK)

#define CCM_GPR_SHARED4_SET_m33_mask_mic_MASK    (0x20U)
#define CCM_GPR_SHARED4_SET_m33_mask_mic_SHIFT   (5U)
/*! m33_mask_mic - m33_mask_mic */
#define CCM_GPR_SHARED4_SET_m33_mask_mic(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_SET_m33_mask_mic_SHIFT)) & CCM_GPR_SHARED4_SET_m33_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED4_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED4_CLR_m33_mask_sinc3_MASK  (0x1U)
#define CCM_GPR_SHARED4_CLR_m33_mask_sinc3_SHIFT (0U)
/*! m33_mask_sinc3 - m33_mask_sinc3 */
#define CCM_GPR_SHARED4_CLR_m33_mask_sinc3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_CLR_m33_mask_sinc3_SHIFT)) & CCM_GPR_SHARED4_CLR_m33_mask_sinc3_MASK)

#define CCM_GPR_SHARED4_CLR_m33_mask_sai1_MASK   (0x2U)
#define CCM_GPR_SHARED4_CLR_m33_mask_sai1_SHIFT  (1U)
/*! m33_mask_sai1 - m33_mask_sai1 */
#define CCM_GPR_SHARED4_CLR_m33_mask_sai1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_CLR_m33_mask_sai1_SHIFT)) & CCM_GPR_SHARED4_CLR_m33_mask_sai1_MASK)

#define CCM_GPR_SHARED4_CLR_m33_mask_sai2_MASK   (0x4U)
#define CCM_GPR_SHARED4_CLR_m33_mask_sai2_SHIFT  (2U)
/*! m33_mask_sai2 - m33_mask_sai2 */
#define CCM_GPR_SHARED4_CLR_m33_mask_sai2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_CLR_m33_mask_sai2_SHIFT)) & CCM_GPR_SHARED4_CLR_m33_mask_sai2_MASK)

#define CCM_GPR_SHARED4_CLR_m33_mask_sai3_MASK   (0x8U)
#define CCM_GPR_SHARED4_CLR_m33_mask_sai3_SHIFT  (3U)
/*! m33_mask_sai3 - m33_mask_sai3 */
#define CCM_GPR_SHARED4_CLR_m33_mask_sai3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_CLR_m33_mask_sai3_SHIFT)) & CCM_GPR_SHARED4_CLR_m33_mask_sai3_MASK)

#define CCM_GPR_SHARED4_CLR_m33_mask_sai4_MASK   (0x10U)
#define CCM_GPR_SHARED4_CLR_m33_mask_sai4_SHIFT  (4U)
/*! m33_mask_sai4 - m33_mask_sai4 */
#define CCM_GPR_SHARED4_CLR_m33_mask_sai4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_CLR_m33_mask_sai4_SHIFT)) & CCM_GPR_SHARED4_CLR_m33_mask_sai4_MASK)

#define CCM_GPR_SHARED4_CLR_m33_mask_mic_MASK    (0x20U)
#define CCM_GPR_SHARED4_CLR_m33_mask_mic_SHIFT   (5U)
/*! m33_mask_mic - m33_mask_mic */
#define CCM_GPR_SHARED4_CLR_m33_mask_mic(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_CLR_m33_mask_mic_SHIFT)) & CCM_GPR_SHARED4_CLR_m33_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED4_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED4_TOG_m33_mask_sinc3_MASK  (0x1U)
#define CCM_GPR_SHARED4_TOG_m33_mask_sinc3_SHIFT (0U)
/*! m33_mask_sinc3 - m33_mask_sinc3 */
#define CCM_GPR_SHARED4_TOG_m33_mask_sinc3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_TOG_m33_mask_sinc3_SHIFT)) & CCM_GPR_SHARED4_TOG_m33_mask_sinc3_MASK)

#define CCM_GPR_SHARED4_TOG_m33_mask_sai1_MASK   (0x2U)
#define CCM_GPR_SHARED4_TOG_m33_mask_sai1_SHIFT  (1U)
/*! m33_mask_sai1 - m33_mask_sai1 */
#define CCM_GPR_SHARED4_TOG_m33_mask_sai1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_TOG_m33_mask_sai1_SHIFT)) & CCM_GPR_SHARED4_TOG_m33_mask_sai1_MASK)

#define CCM_GPR_SHARED4_TOG_m33_mask_sai2_MASK   (0x4U)
#define CCM_GPR_SHARED4_TOG_m33_mask_sai2_SHIFT  (2U)
/*! m33_mask_sai2 - m33_mask_sai2 */
#define CCM_GPR_SHARED4_TOG_m33_mask_sai2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_TOG_m33_mask_sai2_SHIFT)) & CCM_GPR_SHARED4_TOG_m33_mask_sai2_MASK)

#define CCM_GPR_SHARED4_TOG_m33_mask_sai3_MASK   (0x8U)
#define CCM_GPR_SHARED4_TOG_m33_mask_sai3_SHIFT  (3U)
/*! m33_mask_sai3 - m33_mask_sai3 */
#define CCM_GPR_SHARED4_TOG_m33_mask_sai3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_TOG_m33_mask_sai3_SHIFT)) & CCM_GPR_SHARED4_TOG_m33_mask_sai3_MASK)

#define CCM_GPR_SHARED4_TOG_m33_mask_sai4_MASK   (0x10U)
#define CCM_GPR_SHARED4_TOG_m33_mask_sai4_SHIFT  (4U)
/*! m33_mask_sai4 - m33_mask_sai4 */
#define CCM_GPR_SHARED4_TOG_m33_mask_sai4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_TOG_m33_mask_sai4_SHIFT)) & CCM_GPR_SHARED4_TOG_m33_mask_sai4_MASK)

#define CCM_GPR_SHARED4_TOG_m33_mask_mic_MASK    (0x20U)
#define CCM_GPR_SHARED4_TOG_m33_mask_mic_SHIFT   (5U)
/*! m33_mask_mic - m33_mask_mic */
#define CCM_GPR_SHARED4_TOG_m33_mask_mic(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_TOG_m33_mask_mic_SHIFT)) & CCM_GPR_SHARED4_TOG_m33_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED4_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED4_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED4_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED4_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED4_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED4_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED4_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED4_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED4_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED4_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED4_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED4_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED4_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED4_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED4_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED4_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED4_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED4_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED4_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED4_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED4_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED4_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED4_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED4_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED4_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED4_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED4_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED4_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED4_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED4_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED4_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED4_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED4_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED4_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED4_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED4_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED4_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED4_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED4_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED4_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED4_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED4_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED4_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED4_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED4_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED4_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED4_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED4_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED4_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED4_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED4_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED4_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED4_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED4_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED5 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED5_m7_mask_cm7_MASK         (0x1U)
#define CCM_GPR_SHARED5_m7_mask_cm7_SHIFT        (0U)
/*! m7_mask_cm7 - m7_mask_cm7 */
#define CCM_GPR_SHARED5_m7_mask_cm7(x)           (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_cm7_SHIFT)) & CCM_GPR_SHARED5_m7_mask_cm7_MASK)

#define CCM_GPR_SHARED5_m7_mask_cm33_MASK        (0x2U)
#define CCM_GPR_SHARED5_m7_mask_cm33_SHIFT       (1U)
/*! m7_mask_cm33 - m7_mask_cm33 */
#define CCM_GPR_SHARED5_m7_mask_cm33(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_cm33_SHIFT)) & CCM_GPR_SHARED5_m7_mask_cm33_MASK)

#define CCM_GPR_SHARED5_m7_mask_edma3_MASK       (0x4U)
#define CCM_GPR_SHARED5_m7_mask_edma3_SHIFT      (2U)
/*! m7_mask_edma3 - m7_mask_edma3 */
#define CCM_GPR_SHARED5_m7_mask_edma3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_edma3_SHIFT)) & CCM_GPR_SHARED5_m7_mask_edma3_MASK)

#define CCM_GPR_SHARED5_m7_mask_edma4_MASK       (0x8U)
#define CCM_GPR_SHARED5_m7_mask_edma4_SHIFT      (3U)
/*! m7_mask_edma4 - m7_mask_edma4 */
#define CCM_GPR_SHARED5_m7_mask_edma4(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_edma4_SHIFT)) & CCM_GPR_SHARED5_m7_mask_edma4_MASK)

#define CCM_GPR_SHARED5_m7_mask_netc_MASK        (0x10U)
#define CCM_GPR_SHARED5_m7_mask_netc_SHIFT       (4U)
/*! m7_mask_netc - m7_mask_netc */
#define CCM_GPR_SHARED5_m7_mask_netc(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_netc_SHIFT)) & CCM_GPR_SHARED5_m7_mask_netc_MASK)

#define CCM_GPR_SHARED5_m7_mask_sim_aon_MASK     (0x100U)
#define CCM_GPR_SHARED5_m7_mask_sim_aon_SHIFT    (8U)
/*! m7_mask_sim_aon - m7_mask_sim_aon */
#define CCM_GPR_SHARED5_m7_mask_sim_aon(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED5_m7_mask_sim_aon_MASK)

#define CCM_GPR_SHARED5_m7_mask_adc1_MASK        (0x200U)
#define CCM_GPR_SHARED5_m7_mask_adc1_SHIFT       (9U)
/*! m7_mask_adc1 - m7_mask_adc1 */
#define CCM_GPR_SHARED5_m7_mask_adc1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_adc1_SHIFT)) & CCM_GPR_SHARED5_m7_mask_adc1_MASK)

#define CCM_GPR_SHARED5_m7_mask_adc2_MASK        (0x400U)
#define CCM_GPR_SHARED5_m7_mask_adc2_SHIFT       (10U)
/*! m7_mask_adc2 - m7_mask_adc2 */
#define CCM_GPR_SHARED5_m7_mask_adc2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_adc2_SHIFT)) & CCM_GPR_SHARED5_m7_mask_adc2_MASK)

#define CCM_GPR_SHARED5_m7_mask_flexspi1_MASK    (0x800U)
#define CCM_GPR_SHARED5_m7_mask_flexspi1_SHIFT   (11U)
/*! m7_mask_flexspi1 - m7_mask_flexspi1 */
#define CCM_GPR_SHARED5_m7_mask_flexspi1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED5_m7_mask_flexspi1_MASK)

#define CCM_GPR_SHARED5_m7_mask_flexspi2_MASK    (0x1000U)
#define CCM_GPR_SHARED5_m7_mask_flexspi2_SHIFT   (12U)
/*! m7_mask_flexspi2 - m7_mask_flexspi2 */
#define CCM_GPR_SHARED5_m7_mask_flexspi2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED5_m7_mask_flexspi2_MASK)

#define CCM_GPR_SHARED5_m7_mask_trdc_MASK        (0x2000U)
#define CCM_GPR_SHARED5_m7_mask_trdc_SHIFT       (13U)
/*! m7_mask_trdc - m7_mask_trdc */
#define CCM_GPR_SHARED5_m7_mask_trdc(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_trdc_SHIFT)) & CCM_GPR_SHARED5_m7_mask_trdc_MASK)

#define CCM_GPR_SHARED5_m7_mask_semc_MASK        (0x4000U)
#define CCM_GPR_SHARED5_m7_mask_semc_SHIFT       (14U)
/*! m7_mask_semc - m7_mask_semc */
#define CCM_GPR_SHARED5_m7_mask_semc(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_semc_SHIFT)) & CCM_GPR_SHARED5_m7_mask_semc_MASK)

#define CCM_GPR_SHARED5_m7_mask_iee_MASK         (0x8000U)
#define CCM_GPR_SHARED5_m7_mask_iee_SHIFT        (15U)
/*! m7_mask_iee - m7_mask_iee */
#define CCM_GPR_SHARED5_m7_mask_iee(x)           (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_iee_SHIFT)) & CCM_GPR_SHARED5_m7_mask_iee_MASK)

#define CCM_GPR_SHARED5_m7_mask_gpio1_MASK       (0x10000U)
#define CCM_GPR_SHARED5_m7_mask_gpio1_SHIFT      (16U)
/*! m7_mask_gpio1 - m7_mask_gpio1 */
#define CCM_GPR_SHARED5_m7_mask_gpio1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_gpio1_SHIFT)) & CCM_GPR_SHARED5_m7_mask_gpio1_MASK)

#define CCM_GPR_SHARED5_m7_mask_gpio2_MASK       (0x20000U)
#define CCM_GPR_SHARED5_m7_mask_gpio2_SHIFT      (17U)
/*! m7_mask_gpio2 - m7_mask_gpio2 */
#define CCM_GPR_SHARED5_m7_mask_gpio2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_gpio2_SHIFT)) & CCM_GPR_SHARED5_m7_mask_gpio2_MASK)

#define CCM_GPR_SHARED5_m7_mask_gpio3_MASK       (0x40000U)
#define CCM_GPR_SHARED5_m7_mask_gpio3_SHIFT      (18U)
/*! m7_mask_gpio3 - m7_mask_gpio3 */
#define CCM_GPR_SHARED5_m7_mask_gpio3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_gpio3_SHIFT)) & CCM_GPR_SHARED5_m7_mask_gpio3_MASK)

#define CCM_GPR_SHARED5_m7_mask_gpio4_MASK       (0x80000U)
#define CCM_GPR_SHARED5_m7_mask_gpio4_SHIFT      (19U)
/*! m7_mask_gpio4 - m7_mask_gpio4 */
#define CCM_GPR_SHARED5_m7_mask_gpio4(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_gpio4_SHIFT)) & CCM_GPR_SHARED5_m7_mask_gpio4_MASK)

#define CCM_GPR_SHARED5_m7_mask_gpio5_MASK       (0x100000U)
#define CCM_GPR_SHARED5_m7_mask_gpio5_SHIFT      (20U)
/*! m7_mask_gpio5 - m7_mask_gpio5 */
#define CCM_GPR_SHARED5_m7_mask_gpio5(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_gpio5_SHIFT)) & CCM_GPR_SHARED5_m7_mask_gpio5_MASK)

#define CCM_GPR_SHARED5_m7_mask_gpio6_MASK       (0x200000U)
#define CCM_GPR_SHARED5_m7_mask_gpio6_SHIFT      (21U)
/*! m7_mask_gpio6 - m7_mask_gpio6 */
#define CCM_GPR_SHARED5_m7_mask_gpio6(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_gpio6_SHIFT)) & CCM_GPR_SHARED5_m7_mask_gpio6_MASK)

#define CCM_GPR_SHARED5_m7_mask_flexio1_MASK     (0x400000U)
#define CCM_GPR_SHARED5_m7_mask_flexio1_SHIFT    (22U)
/*! m7_mask_flexio1 - m7_mask_flexio1 */
#define CCM_GPR_SHARED5_m7_mask_flexio1(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_flexio1_SHIFT)) & CCM_GPR_SHARED5_m7_mask_flexio1_MASK)

#define CCM_GPR_SHARED5_m7_mask_flexio2_MASK     (0x800000U)
#define CCM_GPR_SHARED5_m7_mask_flexio2_SHIFT    (23U)
/*! m7_mask_flexio2 - m7_mask_flexio2 */
#define CCM_GPR_SHARED5_m7_mask_flexio2(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_flexio2_SHIFT)) & CCM_GPR_SHARED5_m7_mask_flexio2_MASK)

#define CCM_GPR_SHARED5_m7_mask_lpit1_MASK       (0x1000000U)
#define CCM_GPR_SHARED5_m7_mask_lpit1_SHIFT      (24U)
/*! m7_mask_lpit1 - m7_mask_lpit1 */
#define CCM_GPR_SHARED5_m7_mask_lpit1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_lpit1_SHIFT)) & CCM_GPR_SHARED5_m7_mask_lpit1_MASK)

#define CCM_GPR_SHARED5_m7_mask_lpit2_MASK       (0x2000000U)
#define CCM_GPR_SHARED5_m7_mask_lpit2_SHIFT      (25U)
/*! m7_mask_lpit2 - m7_mask_lpit2 */
#define CCM_GPR_SHARED5_m7_mask_lpit2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_lpit2_SHIFT)) & CCM_GPR_SHARED5_m7_mask_lpit2_MASK)

#define CCM_GPR_SHARED5_m7_mask_lpit3_MASK       (0x4000000U)
#define CCM_GPR_SHARED5_m7_mask_lpit3_SHIFT      (26U)
/*! m7_mask_lpit3 - m7_mask_lpit3 */
#define CCM_GPR_SHARED5_m7_mask_lpit3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_lpit3_SHIFT)) & CCM_GPR_SHARED5_m7_mask_lpit3_MASK)

#define CCM_GPR_SHARED5_m7_mask_tpm1_MASK        (0x8000000U)
#define CCM_GPR_SHARED5_m7_mask_tpm1_SHIFT       (27U)
/*! m7_mask_tpm1 - m7_mask_tpm1 */
#define CCM_GPR_SHARED5_m7_mask_tpm1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_tpm1_SHIFT)) & CCM_GPR_SHARED5_m7_mask_tpm1_MASK)

#define CCM_GPR_SHARED5_m7_mask_tpm2_MASK        (0x10000000U)
#define CCM_GPR_SHARED5_m7_mask_tpm2_SHIFT       (28U)
/*! m7_mask_tpm2 - m7_mask_tpm2 */
#define CCM_GPR_SHARED5_m7_mask_tpm2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_tpm2_SHIFT)) & CCM_GPR_SHARED5_m7_mask_tpm2_MASK)

#define CCM_GPR_SHARED5_m7_mask_tpm3_MASK        (0x20000000U)
#define CCM_GPR_SHARED5_m7_mask_tpm3_SHIFT       (29U)
/*! m7_mask_tpm3 - m7_mask_tpm3 */
#define CCM_GPR_SHARED5_m7_mask_tpm3(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_tpm3_SHIFT)) & CCM_GPR_SHARED5_m7_mask_tpm3_MASK)

#define CCM_GPR_SHARED5_m7_mask_tpm4_MASK        (0x40000000U)
#define CCM_GPR_SHARED5_m7_mask_tpm4_SHIFT       (30U)
/*! m7_mask_tpm4 - m7_mask_tpm4 */
#define CCM_GPR_SHARED5_m7_mask_tpm4(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_tpm4_SHIFT)) & CCM_GPR_SHARED5_m7_mask_tpm4_MASK)

#define CCM_GPR_SHARED5_m7_mask_tpm5_MASK        (0x80000000U)
#define CCM_GPR_SHARED5_m7_mask_tpm5_SHIFT       (31U)
/*! m7_mask_tpm5 - m7_mask_tpm5 */
#define CCM_GPR_SHARED5_m7_mask_tpm5(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_m7_mask_tpm5_SHIFT)) & CCM_GPR_SHARED5_m7_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED5_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED5_SET_m7_mask_cm7_MASK     (0x1U)
#define CCM_GPR_SHARED5_SET_m7_mask_cm7_SHIFT    (0U)
/*! m7_mask_cm7 - m7_mask_cm7 */
#define CCM_GPR_SHARED5_SET_m7_mask_cm7(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_cm7_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_cm7_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_cm33_MASK    (0x2U)
#define CCM_GPR_SHARED5_SET_m7_mask_cm33_SHIFT   (1U)
/*! m7_mask_cm33 - m7_mask_cm33 */
#define CCM_GPR_SHARED5_SET_m7_mask_cm33(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_cm33_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_cm33_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_edma3_MASK   (0x4U)
#define CCM_GPR_SHARED5_SET_m7_mask_edma3_SHIFT  (2U)
/*! m7_mask_edma3 - m7_mask_edma3 */
#define CCM_GPR_SHARED5_SET_m7_mask_edma3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_edma3_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_edma3_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_edma4_MASK   (0x8U)
#define CCM_GPR_SHARED5_SET_m7_mask_edma4_SHIFT  (3U)
/*! m7_mask_edma4 - m7_mask_edma4 */
#define CCM_GPR_SHARED5_SET_m7_mask_edma4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_edma4_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_edma4_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_netc_MASK    (0x10U)
#define CCM_GPR_SHARED5_SET_m7_mask_netc_SHIFT   (4U)
/*! m7_mask_netc - m7_mask_netc */
#define CCM_GPR_SHARED5_SET_m7_mask_netc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_netc_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_netc_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_sim_aon_MASK (0x100U)
#define CCM_GPR_SHARED5_SET_m7_mask_sim_aon_SHIFT (8U)
/*! m7_mask_sim_aon - m7_mask_sim_aon */
#define CCM_GPR_SHARED5_SET_m7_mask_sim_aon(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_sim_aon_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_adc1_MASK    (0x200U)
#define CCM_GPR_SHARED5_SET_m7_mask_adc1_SHIFT   (9U)
/*! m7_mask_adc1 - m7_mask_adc1 */
#define CCM_GPR_SHARED5_SET_m7_mask_adc1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_adc1_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_adc1_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_adc2_MASK    (0x400U)
#define CCM_GPR_SHARED5_SET_m7_mask_adc2_SHIFT   (10U)
/*! m7_mask_adc2 - m7_mask_adc2 */
#define CCM_GPR_SHARED5_SET_m7_mask_adc2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_adc2_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_adc2_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_flexspi1_MASK (0x800U)
#define CCM_GPR_SHARED5_SET_m7_mask_flexspi1_SHIFT (11U)
/*! m7_mask_flexspi1 - m7_mask_flexspi1 */
#define CCM_GPR_SHARED5_SET_m7_mask_flexspi1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_flexspi1_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_flexspi2_MASK (0x1000U)
#define CCM_GPR_SHARED5_SET_m7_mask_flexspi2_SHIFT (12U)
/*! m7_mask_flexspi2 - m7_mask_flexspi2 */
#define CCM_GPR_SHARED5_SET_m7_mask_flexspi2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_flexspi2_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_trdc_MASK    (0x2000U)
#define CCM_GPR_SHARED5_SET_m7_mask_trdc_SHIFT   (13U)
/*! m7_mask_trdc - m7_mask_trdc */
#define CCM_GPR_SHARED5_SET_m7_mask_trdc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_trdc_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_trdc_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_semc_MASK    (0x4000U)
#define CCM_GPR_SHARED5_SET_m7_mask_semc_SHIFT   (14U)
/*! m7_mask_semc - m7_mask_semc */
#define CCM_GPR_SHARED5_SET_m7_mask_semc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_semc_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_semc_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_iee_MASK     (0x8000U)
#define CCM_GPR_SHARED5_SET_m7_mask_iee_SHIFT    (15U)
/*! m7_mask_iee - m7_mask_iee */
#define CCM_GPR_SHARED5_SET_m7_mask_iee(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_iee_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_iee_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_gpio1_MASK   (0x10000U)
#define CCM_GPR_SHARED5_SET_m7_mask_gpio1_SHIFT  (16U)
/*! m7_mask_gpio1 - m7_mask_gpio1 */
#define CCM_GPR_SHARED5_SET_m7_mask_gpio1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_gpio1_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_gpio1_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_gpio2_MASK   (0x20000U)
#define CCM_GPR_SHARED5_SET_m7_mask_gpio2_SHIFT  (17U)
/*! m7_mask_gpio2 - m7_mask_gpio2 */
#define CCM_GPR_SHARED5_SET_m7_mask_gpio2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_gpio2_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_gpio2_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_gpio3_MASK   (0x40000U)
#define CCM_GPR_SHARED5_SET_m7_mask_gpio3_SHIFT  (18U)
/*! m7_mask_gpio3 - m7_mask_gpio3 */
#define CCM_GPR_SHARED5_SET_m7_mask_gpio3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_gpio3_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_gpio3_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_gpio4_MASK   (0x80000U)
#define CCM_GPR_SHARED5_SET_m7_mask_gpio4_SHIFT  (19U)
/*! m7_mask_gpio4 - m7_mask_gpio4 */
#define CCM_GPR_SHARED5_SET_m7_mask_gpio4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_gpio4_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_gpio4_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_gpio5_MASK   (0x100000U)
#define CCM_GPR_SHARED5_SET_m7_mask_gpio5_SHIFT  (20U)
/*! m7_mask_gpio5 - m7_mask_gpio5 */
#define CCM_GPR_SHARED5_SET_m7_mask_gpio5(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_gpio5_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_gpio5_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_gpio6_MASK   (0x200000U)
#define CCM_GPR_SHARED5_SET_m7_mask_gpio6_SHIFT  (21U)
/*! m7_mask_gpio6 - m7_mask_gpio6 */
#define CCM_GPR_SHARED5_SET_m7_mask_gpio6(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_gpio6_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_gpio6_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_flexio1_MASK (0x400000U)
#define CCM_GPR_SHARED5_SET_m7_mask_flexio1_SHIFT (22U)
/*! m7_mask_flexio1 - m7_mask_flexio1 */
#define CCM_GPR_SHARED5_SET_m7_mask_flexio1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_flexio1_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_flexio1_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_flexio2_MASK (0x800000U)
#define CCM_GPR_SHARED5_SET_m7_mask_flexio2_SHIFT (23U)
/*! m7_mask_flexio2 - m7_mask_flexio2 */
#define CCM_GPR_SHARED5_SET_m7_mask_flexio2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_flexio2_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_flexio2_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_lpit1_MASK   (0x1000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_lpit1_SHIFT  (24U)
/*! m7_mask_lpit1 - m7_mask_lpit1 */
#define CCM_GPR_SHARED5_SET_m7_mask_lpit1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_lpit1_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_lpit1_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_lpit2_MASK   (0x2000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_lpit2_SHIFT  (25U)
/*! m7_mask_lpit2 - m7_mask_lpit2 */
#define CCM_GPR_SHARED5_SET_m7_mask_lpit2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_lpit2_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_lpit2_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_lpit3_MASK   (0x4000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_lpit3_SHIFT  (26U)
/*! m7_mask_lpit3 - m7_mask_lpit3 */
#define CCM_GPR_SHARED5_SET_m7_mask_lpit3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_lpit3_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_lpit3_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_tpm1_MASK    (0x8000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_tpm1_SHIFT   (27U)
/*! m7_mask_tpm1 - m7_mask_tpm1 */
#define CCM_GPR_SHARED5_SET_m7_mask_tpm1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_tpm1_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_tpm1_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_tpm2_MASK    (0x10000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_tpm2_SHIFT   (28U)
/*! m7_mask_tpm2 - m7_mask_tpm2 */
#define CCM_GPR_SHARED5_SET_m7_mask_tpm2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_tpm2_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_tpm2_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_tpm3_MASK    (0x20000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_tpm3_SHIFT   (29U)
/*! m7_mask_tpm3 - m7_mask_tpm3 */
#define CCM_GPR_SHARED5_SET_m7_mask_tpm3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_tpm3_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_tpm3_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_tpm4_MASK    (0x40000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_tpm4_SHIFT   (30U)
/*! m7_mask_tpm4 - m7_mask_tpm4 */
#define CCM_GPR_SHARED5_SET_m7_mask_tpm4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_tpm4_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_tpm4_MASK)

#define CCM_GPR_SHARED5_SET_m7_mask_tpm5_MASK    (0x80000000U)
#define CCM_GPR_SHARED5_SET_m7_mask_tpm5_SHIFT   (31U)
/*! m7_mask_tpm5 - m7_mask_tpm5 */
#define CCM_GPR_SHARED5_SET_m7_mask_tpm5(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_SET_m7_mask_tpm5_SHIFT)) & CCM_GPR_SHARED5_SET_m7_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED5_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED5_CLR_m7_mask_cm7_MASK     (0x1U)
#define CCM_GPR_SHARED5_CLR_m7_mask_cm7_SHIFT    (0U)
/*! m7_mask_cm7 - m7_mask_cm7 */
#define CCM_GPR_SHARED5_CLR_m7_mask_cm7(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_cm7_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_cm7_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_cm33_MASK    (0x2U)
#define CCM_GPR_SHARED5_CLR_m7_mask_cm33_SHIFT   (1U)
/*! m7_mask_cm33 - m7_mask_cm33 */
#define CCM_GPR_SHARED5_CLR_m7_mask_cm33(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_cm33_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_cm33_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_edma3_MASK   (0x4U)
#define CCM_GPR_SHARED5_CLR_m7_mask_edma3_SHIFT  (2U)
/*! m7_mask_edma3 - m7_mask_edma3 */
#define CCM_GPR_SHARED5_CLR_m7_mask_edma3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_edma3_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_edma3_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_edma4_MASK   (0x8U)
#define CCM_GPR_SHARED5_CLR_m7_mask_edma4_SHIFT  (3U)
/*! m7_mask_edma4 - m7_mask_edma4 */
#define CCM_GPR_SHARED5_CLR_m7_mask_edma4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_edma4_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_edma4_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_netc_MASK    (0x10U)
#define CCM_GPR_SHARED5_CLR_m7_mask_netc_SHIFT   (4U)
/*! m7_mask_netc - m7_mask_netc */
#define CCM_GPR_SHARED5_CLR_m7_mask_netc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_netc_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_netc_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_sim_aon_MASK (0x100U)
#define CCM_GPR_SHARED5_CLR_m7_mask_sim_aon_SHIFT (8U)
/*! m7_mask_sim_aon - m7_mask_sim_aon */
#define CCM_GPR_SHARED5_CLR_m7_mask_sim_aon(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_sim_aon_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_adc1_MASK    (0x200U)
#define CCM_GPR_SHARED5_CLR_m7_mask_adc1_SHIFT   (9U)
/*! m7_mask_adc1 - m7_mask_adc1 */
#define CCM_GPR_SHARED5_CLR_m7_mask_adc1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_adc1_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_adc1_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_adc2_MASK    (0x400U)
#define CCM_GPR_SHARED5_CLR_m7_mask_adc2_SHIFT   (10U)
/*! m7_mask_adc2 - m7_mask_adc2 */
#define CCM_GPR_SHARED5_CLR_m7_mask_adc2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_adc2_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_adc2_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_flexspi1_MASK (0x800U)
#define CCM_GPR_SHARED5_CLR_m7_mask_flexspi1_SHIFT (11U)
/*! m7_mask_flexspi1 - m7_mask_flexspi1 */
#define CCM_GPR_SHARED5_CLR_m7_mask_flexspi1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_flexspi1_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_flexspi2_MASK (0x1000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_flexspi2_SHIFT (12U)
/*! m7_mask_flexspi2 - m7_mask_flexspi2 */
#define CCM_GPR_SHARED5_CLR_m7_mask_flexspi2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_flexspi2_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_trdc_MASK    (0x2000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_trdc_SHIFT   (13U)
/*! m7_mask_trdc - m7_mask_trdc */
#define CCM_GPR_SHARED5_CLR_m7_mask_trdc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_trdc_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_trdc_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_semc_MASK    (0x4000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_semc_SHIFT   (14U)
/*! m7_mask_semc - m7_mask_semc */
#define CCM_GPR_SHARED5_CLR_m7_mask_semc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_semc_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_semc_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_iee_MASK     (0x8000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_iee_SHIFT    (15U)
/*! m7_mask_iee - m7_mask_iee */
#define CCM_GPR_SHARED5_CLR_m7_mask_iee(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_iee_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_iee_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_gpio1_MASK   (0x10000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio1_SHIFT  (16U)
/*! m7_mask_gpio1 - m7_mask_gpio1 */
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_gpio1_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_gpio1_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_gpio2_MASK   (0x20000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio2_SHIFT  (17U)
/*! m7_mask_gpio2 - m7_mask_gpio2 */
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_gpio2_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_gpio2_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_gpio3_MASK   (0x40000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio3_SHIFT  (18U)
/*! m7_mask_gpio3 - m7_mask_gpio3 */
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_gpio3_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_gpio3_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_gpio4_MASK   (0x80000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio4_SHIFT  (19U)
/*! m7_mask_gpio4 - m7_mask_gpio4 */
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_gpio4_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_gpio4_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_gpio5_MASK   (0x100000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio5_SHIFT  (20U)
/*! m7_mask_gpio5 - m7_mask_gpio5 */
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio5(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_gpio5_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_gpio5_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_gpio6_MASK   (0x200000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio6_SHIFT  (21U)
/*! m7_mask_gpio6 - m7_mask_gpio6 */
#define CCM_GPR_SHARED5_CLR_m7_mask_gpio6(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_gpio6_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_gpio6_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_flexio1_MASK (0x400000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_flexio1_SHIFT (22U)
/*! m7_mask_flexio1 - m7_mask_flexio1 */
#define CCM_GPR_SHARED5_CLR_m7_mask_flexio1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_flexio1_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_flexio1_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_flexio2_MASK (0x800000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_flexio2_SHIFT (23U)
/*! m7_mask_flexio2 - m7_mask_flexio2 */
#define CCM_GPR_SHARED5_CLR_m7_mask_flexio2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_flexio2_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_flexio2_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_lpit1_MASK   (0x1000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_lpit1_SHIFT  (24U)
/*! m7_mask_lpit1 - m7_mask_lpit1 */
#define CCM_GPR_SHARED5_CLR_m7_mask_lpit1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_lpit1_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_lpit1_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_lpit2_MASK   (0x2000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_lpit2_SHIFT  (25U)
/*! m7_mask_lpit2 - m7_mask_lpit2 */
#define CCM_GPR_SHARED5_CLR_m7_mask_lpit2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_lpit2_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_lpit2_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_lpit3_MASK   (0x4000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_lpit3_SHIFT  (26U)
/*! m7_mask_lpit3 - m7_mask_lpit3 */
#define CCM_GPR_SHARED5_CLR_m7_mask_lpit3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_lpit3_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_lpit3_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_tpm1_MASK    (0x8000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm1_SHIFT   (27U)
/*! m7_mask_tpm1 - m7_mask_tpm1 */
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_tpm1_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_tpm1_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_tpm2_MASK    (0x10000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm2_SHIFT   (28U)
/*! m7_mask_tpm2 - m7_mask_tpm2 */
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_tpm2_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_tpm2_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_tpm3_MASK    (0x20000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm3_SHIFT   (29U)
/*! m7_mask_tpm3 - m7_mask_tpm3 */
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_tpm3_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_tpm3_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_tpm4_MASK    (0x40000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm4_SHIFT   (30U)
/*! m7_mask_tpm4 - m7_mask_tpm4 */
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_tpm4_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_tpm4_MASK)

#define CCM_GPR_SHARED5_CLR_m7_mask_tpm5_MASK    (0x80000000U)
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm5_SHIFT   (31U)
/*! m7_mask_tpm5 - m7_mask_tpm5 */
#define CCM_GPR_SHARED5_CLR_m7_mask_tpm5(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_CLR_m7_mask_tpm5_SHIFT)) & CCM_GPR_SHARED5_CLR_m7_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED5_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED5_TOG_m7_mask_cm7_MASK     (0x1U)
#define CCM_GPR_SHARED5_TOG_m7_mask_cm7_SHIFT    (0U)
/*! m7_mask_cm7 - m7_mask_cm7 */
#define CCM_GPR_SHARED5_TOG_m7_mask_cm7(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_cm7_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_cm7_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_cm33_MASK    (0x2U)
#define CCM_GPR_SHARED5_TOG_m7_mask_cm33_SHIFT   (1U)
/*! m7_mask_cm33 - m7_mask_cm33 */
#define CCM_GPR_SHARED5_TOG_m7_mask_cm33(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_cm33_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_cm33_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_edma3_MASK   (0x4U)
#define CCM_GPR_SHARED5_TOG_m7_mask_edma3_SHIFT  (2U)
/*! m7_mask_edma3 - m7_mask_edma3 */
#define CCM_GPR_SHARED5_TOG_m7_mask_edma3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_edma3_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_edma3_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_edma4_MASK   (0x8U)
#define CCM_GPR_SHARED5_TOG_m7_mask_edma4_SHIFT  (3U)
/*! m7_mask_edma4 - m7_mask_edma4 */
#define CCM_GPR_SHARED5_TOG_m7_mask_edma4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_edma4_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_edma4_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_netc_MASK    (0x10U)
#define CCM_GPR_SHARED5_TOG_m7_mask_netc_SHIFT   (4U)
/*! m7_mask_netc - m7_mask_netc */
#define CCM_GPR_SHARED5_TOG_m7_mask_netc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_netc_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_netc_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_sim_aon_MASK (0x100U)
#define CCM_GPR_SHARED5_TOG_m7_mask_sim_aon_SHIFT (8U)
/*! m7_mask_sim_aon - m7_mask_sim_aon */
#define CCM_GPR_SHARED5_TOG_m7_mask_sim_aon(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_sim_aon_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_sim_aon_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_adc1_MASK    (0x200U)
#define CCM_GPR_SHARED5_TOG_m7_mask_adc1_SHIFT   (9U)
/*! m7_mask_adc1 - m7_mask_adc1 */
#define CCM_GPR_SHARED5_TOG_m7_mask_adc1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_adc1_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_adc1_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_adc2_MASK    (0x400U)
#define CCM_GPR_SHARED5_TOG_m7_mask_adc2_SHIFT   (10U)
/*! m7_mask_adc2 - m7_mask_adc2 */
#define CCM_GPR_SHARED5_TOG_m7_mask_adc2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_adc2_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_adc2_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_flexspi1_MASK (0x800U)
#define CCM_GPR_SHARED5_TOG_m7_mask_flexspi1_SHIFT (11U)
/*! m7_mask_flexspi1 - m7_mask_flexspi1 */
#define CCM_GPR_SHARED5_TOG_m7_mask_flexspi1(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_flexspi1_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_flexspi1_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_flexspi2_MASK (0x1000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_flexspi2_SHIFT (12U)
/*! m7_mask_flexspi2 - m7_mask_flexspi2 */
#define CCM_GPR_SHARED5_TOG_m7_mask_flexspi2(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_flexspi2_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_flexspi2_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_trdc_MASK    (0x2000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_trdc_SHIFT   (13U)
/*! m7_mask_trdc - m7_mask_trdc */
#define CCM_GPR_SHARED5_TOG_m7_mask_trdc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_trdc_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_trdc_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_semc_MASK    (0x4000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_semc_SHIFT   (14U)
/*! m7_mask_semc - m7_mask_semc */
#define CCM_GPR_SHARED5_TOG_m7_mask_semc(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_semc_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_semc_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_iee_MASK     (0x8000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_iee_SHIFT    (15U)
/*! m7_mask_iee - m7_mask_iee */
#define CCM_GPR_SHARED5_TOG_m7_mask_iee(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_iee_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_iee_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_gpio1_MASK   (0x10000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio1_SHIFT  (16U)
/*! m7_mask_gpio1 - m7_mask_gpio1 */
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_gpio1_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_gpio1_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_gpio2_MASK   (0x20000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio2_SHIFT  (17U)
/*! m7_mask_gpio2 - m7_mask_gpio2 */
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_gpio2_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_gpio2_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_gpio3_MASK   (0x40000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio3_SHIFT  (18U)
/*! m7_mask_gpio3 - m7_mask_gpio3 */
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_gpio3_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_gpio3_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_gpio4_MASK   (0x80000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio4_SHIFT  (19U)
/*! m7_mask_gpio4 - m7_mask_gpio4 */
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio4(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_gpio4_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_gpio4_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_gpio5_MASK   (0x100000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio5_SHIFT  (20U)
/*! m7_mask_gpio5 - m7_mask_gpio5 */
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio5(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_gpio5_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_gpio5_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_gpio6_MASK   (0x200000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio6_SHIFT  (21U)
/*! m7_mask_gpio6 - m7_mask_gpio6 */
#define CCM_GPR_SHARED5_TOG_m7_mask_gpio6(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_gpio6_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_gpio6_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_flexio1_MASK (0x400000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_flexio1_SHIFT (22U)
/*! m7_mask_flexio1 - m7_mask_flexio1 */
#define CCM_GPR_SHARED5_TOG_m7_mask_flexio1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_flexio1_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_flexio1_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_flexio2_MASK (0x800000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_flexio2_SHIFT (23U)
/*! m7_mask_flexio2 - m7_mask_flexio2 */
#define CCM_GPR_SHARED5_TOG_m7_mask_flexio2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_flexio2_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_flexio2_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_lpit1_MASK   (0x1000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_lpit1_SHIFT  (24U)
/*! m7_mask_lpit1 - m7_mask_lpit1 */
#define CCM_GPR_SHARED5_TOG_m7_mask_lpit1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_lpit1_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_lpit1_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_lpit2_MASK   (0x2000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_lpit2_SHIFT  (25U)
/*! m7_mask_lpit2 - m7_mask_lpit2 */
#define CCM_GPR_SHARED5_TOG_m7_mask_lpit2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_lpit2_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_lpit2_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_lpit3_MASK   (0x4000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_lpit3_SHIFT  (26U)
/*! m7_mask_lpit3 - m7_mask_lpit3 */
#define CCM_GPR_SHARED5_TOG_m7_mask_lpit3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_lpit3_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_lpit3_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_tpm1_MASK    (0x8000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm1_SHIFT   (27U)
/*! m7_mask_tpm1 - m7_mask_tpm1 */
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_tpm1_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_tpm1_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_tpm2_MASK    (0x10000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm2_SHIFT   (28U)
/*! m7_mask_tpm2 - m7_mask_tpm2 */
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_tpm2_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_tpm2_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_tpm3_MASK    (0x20000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm3_SHIFT   (29U)
/*! m7_mask_tpm3 - m7_mask_tpm3 */
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_tpm3_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_tpm3_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_tpm4_MASK    (0x40000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm4_SHIFT   (30U)
/*! m7_mask_tpm4 - m7_mask_tpm4 */
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_tpm4_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_tpm4_MASK)

#define CCM_GPR_SHARED5_TOG_m7_mask_tpm5_MASK    (0x80000000U)
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm5_SHIFT   (31U)
/*! m7_mask_tpm5 - m7_mask_tpm5 */
#define CCM_GPR_SHARED5_TOG_m7_mask_tpm5(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_TOG_m7_mask_tpm5_SHIFT)) & CCM_GPR_SHARED5_TOG_m7_mask_tpm5_MASK)
/*! @} */

/*! @name GPR_SHARED5_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED5_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED5_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED5_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED5_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED5_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED5_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED5_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED5_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED5_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED5_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED5_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED5_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED5_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED5_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED5_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED5_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED5_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED5_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED5_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED5_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED5_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED5_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED5_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED5_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED5_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED5_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED5_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED5_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED5_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED5_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED5_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED5_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED5_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED5_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED5_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED5_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED5_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED5_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED5_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED5_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED5_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED5_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED5_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED5_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED5_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED5_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED5_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED5_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED5_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED5_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED5_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED5_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED5_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED6 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED6_m7_mask_tpm6_MASK        (0x1U)
#define CCM_GPR_SHARED6_m7_mask_tpm6_SHIFT       (0U)
/*! m7_mask_tpm6 - m7_mask_tpm6 */
#define CCM_GPR_SHARED6_m7_mask_tpm6(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_tpm6_SHIFT)) & CCM_GPR_SHARED6_m7_mask_tpm6_MASK)

#define CCM_GPR_SHARED6_m7_mask_gpt1_MASK        (0x2U)
#define CCM_GPR_SHARED6_m7_mask_gpt1_SHIFT       (1U)
/*! m7_mask_gpt1 - m7_mask_gpt1 */
#define CCM_GPR_SHARED6_m7_mask_gpt1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_gpt1_SHIFT)) & CCM_GPR_SHARED6_m7_mask_gpt1_MASK)

#define CCM_GPR_SHARED6_m7_mask_gpt2_MASK        (0x4U)
#define CCM_GPR_SHARED6_m7_mask_gpt2_SHIFT       (2U)
/*! m7_mask_gpt2 - m7_mask_gpt2 */
#define CCM_GPR_SHARED6_m7_mask_gpt2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_gpt2_SHIFT)) & CCM_GPR_SHARED6_m7_mask_gpt2_MASK)

#define CCM_GPR_SHARED6_m7_mask_can1_MASK        (0x8U)
#define CCM_GPR_SHARED6_m7_mask_can1_SHIFT       (3U)
/*! m7_mask_can1 - m7_mask_can1 */
#define CCM_GPR_SHARED6_m7_mask_can1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_can1_SHIFT)) & CCM_GPR_SHARED6_m7_mask_can1_MASK)

#define CCM_GPR_SHARED6_m7_mask_can2_MASK        (0x10U)
#define CCM_GPR_SHARED6_m7_mask_can2_SHIFT       (4U)
/*! m7_mask_can2 - m7_mask_can2 */
#define CCM_GPR_SHARED6_m7_mask_can2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_can2_SHIFT)) & CCM_GPR_SHARED6_m7_mask_can2_MASK)

#define CCM_GPR_SHARED6_m7_mask_can3_MASK        (0x20U)
#define CCM_GPR_SHARED6_m7_mask_can3_SHIFT       (5U)
/*! m7_mask_can3 - m7_mask_can3 */
#define CCM_GPR_SHARED6_m7_mask_can3(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_can3_SHIFT)) & CCM_GPR_SHARED6_m7_mask_can3_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart1_MASK     (0x40U)
#define CCM_GPR_SHARED6_m7_mask_lpuart1_SHIFT    (6U)
/*! m7_mask_lpuart1 - m7_mask_lpuart1 */
#define CCM_GPR_SHARED6_m7_mask_lpuart1(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart1_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart2_MASK     (0x80U)
#define CCM_GPR_SHARED6_m7_mask_lpuart2_SHIFT    (7U)
/*! m7_mask_lpuart2 - m7_mask_lpuart2 */
#define CCM_GPR_SHARED6_m7_mask_lpuart2(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart2_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart3_MASK     (0x100U)
#define CCM_GPR_SHARED6_m7_mask_lpuart3_SHIFT    (8U)
/*! m7_mask_lpuart3 - m7_mask_lpuart3 */
#define CCM_GPR_SHARED6_m7_mask_lpuart3(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart3_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart4_MASK     (0x200U)
#define CCM_GPR_SHARED6_m7_mask_lpuart4_SHIFT    (9U)
/*! m7_mask_lpuart4 - m7_mask_lpuart4 */
#define CCM_GPR_SHARED6_m7_mask_lpuart4(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart4_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart5_MASK     (0x400U)
#define CCM_GPR_SHARED6_m7_mask_lpuart5_SHIFT    (10U)
/*! m7_mask_lpuart5 - m7_mask_lpuart5 */
#define CCM_GPR_SHARED6_m7_mask_lpuart5(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart5_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart6_MASK     (0x800U)
#define CCM_GPR_SHARED6_m7_mask_lpuart6_SHIFT    (11U)
/*! m7_mask_lpuart6 - m7_mask_lpuart6 */
#define CCM_GPR_SHARED6_m7_mask_lpuart6(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart6_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart7_MASK     (0x1000U)
#define CCM_GPR_SHARED6_m7_mask_lpuart7_SHIFT    (12U)
/*! m7_mask_lpuart7 - m7_mask_lpuart7 */
#define CCM_GPR_SHARED6_m7_mask_lpuart7(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart7_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart8_MASK     (0x2000U)
#define CCM_GPR_SHARED6_m7_mask_lpuart8_SHIFT    (13U)
/*! m7_mask_lpuart8 - m7_mask_lpuart8 */
#define CCM_GPR_SHARED6_m7_mask_lpuart8(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart8_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart9_MASK     (0x4000U)
#define CCM_GPR_SHARED6_m7_mask_lpuart9_SHIFT    (14U)
/*! m7_mask_lpuart9 - m7_mask_lpuart9 */
#define CCM_GPR_SHARED6_m7_mask_lpuart9(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart9_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart10_MASK    (0x8000U)
#define CCM_GPR_SHARED6_m7_mask_lpuart10_SHIFT   (15U)
/*! m7_mask_lpuart10 - m7_mask_lpuart10 */
#define CCM_GPR_SHARED6_m7_mask_lpuart10(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart10_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart11_MASK    (0x10000U)
#define CCM_GPR_SHARED6_m7_mask_lpuart11_SHIFT   (16U)
/*! m7_mask_lpuart11 - m7_mask_lpuart11 */
#define CCM_GPR_SHARED6_m7_mask_lpuart11(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart11_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpuart12_MASK    (0x20000U)
#define CCM_GPR_SHARED6_m7_mask_lpuart12_SHIFT   (17U)
/*! m7_mask_lpuart12 - m7_mask_lpuart12 */
#define CCM_GPR_SHARED6_m7_mask_lpuart12(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpuart12_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpi2c1_MASK      (0x40000U)
#define CCM_GPR_SHARED6_m7_mask_lpi2c1_SHIFT     (18U)
/*! m7_mask_lpi2c1 - m7_mask_lpi2c1 */
#define CCM_GPR_SHARED6_m7_mask_lpi2c1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpi2c2_MASK      (0x80000U)
#define CCM_GPR_SHARED6_m7_mask_lpi2c2_SHIFT     (19U)
/*! m7_mask_lpi2c2 - m7_mask_lpi2c2 */
#define CCM_GPR_SHARED6_m7_mask_lpi2c2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpi2c3_MASK      (0x100000U)
#define CCM_GPR_SHARED6_m7_mask_lpi2c3_SHIFT     (20U)
/*! m7_mask_lpi2c3 - m7_mask_lpi2c3 */
#define CCM_GPR_SHARED6_m7_mask_lpi2c3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpi2c4_MASK      (0x200000U)
#define CCM_GPR_SHARED6_m7_mask_lpi2c4_SHIFT     (21U)
/*! m7_mask_lpi2c4 - m7_mask_lpi2c4 */
#define CCM_GPR_SHARED6_m7_mask_lpi2c4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpi2c5_MASK      (0x400000U)
#define CCM_GPR_SHARED6_m7_mask_lpi2c5_SHIFT     (22U)
/*! m7_mask_lpi2c5 - m7_mask_lpi2c5 */
#define CCM_GPR_SHARED6_m7_mask_lpi2c5(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpi2c6_MASK      (0x800000U)
#define CCM_GPR_SHARED6_m7_mask_lpi2c6_SHIFT     (23U)
/*! m7_mask_lpi2c6 - m7_mask_lpi2c6 */
#define CCM_GPR_SHARED6_m7_mask_lpi2c6(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpspi1_MASK      (0x1000000U)
#define CCM_GPR_SHARED6_m7_mask_lpspi1_SHIFT     (24U)
/*! m7_mask_lpspi1 - m7_mask_lpspi1 */
#define CCM_GPR_SHARED6_m7_mask_lpspi1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpspi1_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpspi2_MASK      (0x2000000U)
#define CCM_GPR_SHARED6_m7_mask_lpspi2_SHIFT     (25U)
/*! m7_mask_lpspi2 - m7_mask_lpspi2 */
#define CCM_GPR_SHARED6_m7_mask_lpspi2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpspi2_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpspi3_MASK      (0x4000000U)
#define CCM_GPR_SHARED6_m7_mask_lpspi3_SHIFT     (26U)
/*! m7_mask_lpspi3 - m7_mask_lpspi3 */
#define CCM_GPR_SHARED6_m7_mask_lpspi3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpspi3_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpspi4_MASK      (0x8000000U)
#define CCM_GPR_SHARED6_m7_mask_lpspi4_SHIFT     (27U)
/*! m7_mask_lpspi4 - m7_mask_lpspi4 */
#define CCM_GPR_SHARED6_m7_mask_lpspi4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpspi4_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpspi5_MASK      (0x10000000U)
#define CCM_GPR_SHARED6_m7_mask_lpspi5_SHIFT     (28U)
/*! m7_mask_lpspi5 - m7_mask_lpspi5 */
#define CCM_GPR_SHARED6_m7_mask_lpspi5(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpspi5_MASK)

#define CCM_GPR_SHARED6_m7_mask_lpspi6_MASK      (0x20000000U)
#define CCM_GPR_SHARED6_m7_mask_lpspi6_SHIFT     (29U)
/*! m7_mask_lpspi6 - m7_mask_lpspi6 */
#define CCM_GPR_SHARED6_m7_mask_lpspi6(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED6_m7_mask_lpspi6_MASK)

#define CCM_GPR_SHARED6_m7_mask_sinc1_MASK       (0x40000000U)
#define CCM_GPR_SHARED6_m7_mask_sinc1_SHIFT      (30U)
/*! m7_mask_sinc1 - m7_mask_sinc1 */
#define CCM_GPR_SHARED6_m7_mask_sinc1(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_sinc1_SHIFT)) & CCM_GPR_SHARED6_m7_mask_sinc1_MASK)

#define CCM_GPR_SHARED6_m7_mask_sinc2_MASK       (0x80000000U)
#define CCM_GPR_SHARED6_m7_mask_sinc2_SHIFT      (31U)
/*! m7_mask_sinc2 - m7_mask_sinc2 */
#define CCM_GPR_SHARED6_m7_mask_sinc2(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_m7_mask_sinc2_SHIFT)) & CCM_GPR_SHARED6_m7_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED6_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED6_SET_m7_mask_tpm6_MASK    (0x1U)
#define CCM_GPR_SHARED6_SET_m7_mask_tpm6_SHIFT   (0U)
/*! m7_mask_tpm6 - m7_mask_tpm6 */
#define CCM_GPR_SHARED6_SET_m7_mask_tpm6(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_tpm6_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_tpm6_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_gpt1_MASK    (0x2U)
#define CCM_GPR_SHARED6_SET_m7_mask_gpt1_SHIFT   (1U)
/*! m7_mask_gpt1 - m7_mask_gpt1 */
#define CCM_GPR_SHARED6_SET_m7_mask_gpt1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_gpt1_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_gpt1_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_gpt2_MASK    (0x4U)
#define CCM_GPR_SHARED6_SET_m7_mask_gpt2_SHIFT   (2U)
/*! m7_mask_gpt2 - m7_mask_gpt2 */
#define CCM_GPR_SHARED6_SET_m7_mask_gpt2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_gpt2_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_gpt2_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_can1_MASK    (0x8U)
#define CCM_GPR_SHARED6_SET_m7_mask_can1_SHIFT   (3U)
/*! m7_mask_can1 - m7_mask_can1 */
#define CCM_GPR_SHARED6_SET_m7_mask_can1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_can1_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_can1_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_can2_MASK    (0x10U)
#define CCM_GPR_SHARED6_SET_m7_mask_can2_SHIFT   (4U)
/*! m7_mask_can2 - m7_mask_can2 */
#define CCM_GPR_SHARED6_SET_m7_mask_can2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_can2_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_can2_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_can3_MASK    (0x20U)
#define CCM_GPR_SHARED6_SET_m7_mask_can3_SHIFT   (5U)
/*! m7_mask_can3 - m7_mask_can3 */
#define CCM_GPR_SHARED6_SET_m7_mask_can3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_can3_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_can3_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart1_MASK (0x40U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart1_SHIFT (6U)
/*! m7_mask_lpuart1 - m7_mask_lpuart1 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart1_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart2_MASK (0x80U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart2_SHIFT (7U)
/*! m7_mask_lpuart2 - m7_mask_lpuart2 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart2_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart3_MASK (0x100U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart3_SHIFT (8U)
/*! m7_mask_lpuart3 - m7_mask_lpuart3 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart3_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart4_MASK (0x200U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart4_SHIFT (9U)
/*! m7_mask_lpuart4 - m7_mask_lpuart4 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart4_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart5_MASK (0x400U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart5_SHIFT (10U)
/*! m7_mask_lpuart5 - m7_mask_lpuart5 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart5_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart6_MASK (0x800U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart6_SHIFT (11U)
/*! m7_mask_lpuart6 - m7_mask_lpuart6 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart6_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart7_MASK (0x1000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart7_SHIFT (12U)
/*! m7_mask_lpuart7 - m7_mask_lpuart7 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart7(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart7_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart8_MASK (0x2000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart8_SHIFT (13U)
/*! m7_mask_lpuart8 - m7_mask_lpuart8 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart8(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart8_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart9_MASK (0x4000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart9_SHIFT (14U)
/*! m7_mask_lpuart9 - m7_mask_lpuart9 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart9(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart9_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart10_MASK (0x8000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart10_SHIFT (15U)
/*! m7_mask_lpuart10 - m7_mask_lpuart10 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart10(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart10_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart11_MASK (0x10000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart11_SHIFT (16U)
/*! m7_mask_lpuart11 - m7_mask_lpuart11 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart11(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart11_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpuart12_MASK (0x20000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart12_SHIFT (17U)
/*! m7_mask_lpuart12 - m7_mask_lpuart12 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpuart12(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpuart12_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c1_MASK  (0x40000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c1_SHIFT (18U)
/*! m7_mask_lpi2c1 - m7_mask_lpi2c1 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c2_MASK  (0x80000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c2_SHIFT (19U)
/*! m7_mask_lpi2c2 - m7_mask_lpi2c2 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c3_MASK  (0x100000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c3_SHIFT (20U)
/*! m7_mask_lpi2c3 - m7_mask_lpi2c3 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c4_MASK  (0x200000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c4_SHIFT (21U)
/*! m7_mask_lpi2c4 - m7_mask_lpi2c4 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c5_MASK  (0x400000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c5_SHIFT (22U)
/*! m7_mask_lpi2c5 - m7_mask_lpi2c5 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c6_MASK  (0x800000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c6_SHIFT (23U)
/*! m7_mask_lpi2c6 - m7_mask_lpi2c6 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpi2c6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpspi1_MASK  (0x1000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi1_SHIFT (24U)
/*! m7_mask_lpspi1 - m7_mask_lpspi1 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpspi1_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpspi2_MASK  (0x2000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi2_SHIFT (25U)
/*! m7_mask_lpspi2 - m7_mask_lpspi2 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpspi2_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpspi3_MASK  (0x4000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi3_SHIFT (26U)
/*! m7_mask_lpspi3 - m7_mask_lpspi3 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpspi3_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpspi4_MASK  (0x8000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi4_SHIFT (27U)
/*! m7_mask_lpspi4 - m7_mask_lpspi4 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpspi4_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpspi5_MASK  (0x10000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi5_SHIFT (28U)
/*! m7_mask_lpspi5 - m7_mask_lpspi5 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpspi5_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_lpspi6_MASK  (0x20000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi6_SHIFT (29U)
/*! m7_mask_lpspi6 - m7_mask_lpspi6 */
#define CCM_GPR_SHARED6_SET_m7_mask_lpspi6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_lpspi6_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_sinc1_MASK   (0x40000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_sinc1_SHIFT  (30U)
/*! m7_mask_sinc1 - m7_mask_sinc1 */
#define CCM_GPR_SHARED6_SET_m7_mask_sinc1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_sinc1_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_sinc1_MASK)

#define CCM_GPR_SHARED6_SET_m7_mask_sinc2_MASK   (0x80000000U)
#define CCM_GPR_SHARED6_SET_m7_mask_sinc2_SHIFT  (31U)
/*! m7_mask_sinc2 - m7_mask_sinc2 */
#define CCM_GPR_SHARED6_SET_m7_mask_sinc2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_SET_m7_mask_sinc2_SHIFT)) & CCM_GPR_SHARED6_SET_m7_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED6_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED6_CLR_m7_mask_tpm6_MASK    (0x1U)
#define CCM_GPR_SHARED6_CLR_m7_mask_tpm6_SHIFT   (0U)
/*! m7_mask_tpm6 - m7_mask_tpm6 */
#define CCM_GPR_SHARED6_CLR_m7_mask_tpm6(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_tpm6_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_tpm6_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_gpt1_MASK    (0x2U)
#define CCM_GPR_SHARED6_CLR_m7_mask_gpt1_SHIFT   (1U)
/*! m7_mask_gpt1 - m7_mask_gpt1 */
#define CCM_GPR_SHARED6_CLR_m7_mask_gpt1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_gpt1_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_gpt1_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_gpt2_MASK    (0x4U)
#define CCM_GPR_SHARED6_CLR_m7_mask_gpt2_SHIFT   (2U)
/*! m7_mask_gpt2 - m7_mask_gpt2 */
#define CCM_GPR_SHARED6_CLR_m7_mask_gpt2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_gpt2_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_gpt2_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_can1_MASK    (0x8U)
#define CCM_GPR_SHARED6_CLR_m7_mask_can1_SHIFT   (3U)
/*! m7_mask_can1 - m7_mask_can1 */
#define CCM_GPR_SHARED6_CLR_m7_mask_can1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_can1_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_can1_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_can2_MASK    (0x10U)
#define CCM_GPR_SHARED6_CLR_m7_mask_can2_SHIFT   (4U)
/*! m7_mask_can2 - m7_mask_can2 */
#define CCM_GPR_SHARED6_CLR_m7_mask_can2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_can2_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_can2_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_can3_MASK    (0x20U)
#define CCM_GPR_SHARED6_CLR_m7_mask_can3_SHIFT   (5U)
/*! m7_mask_can3 - m7_mask_can3 */
#define CCM_GPR_SHARED6_CLR_m7_mask_can3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_can3_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_can3_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart1_MASK (0x40U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart1_SHIFT (6U)
/*! m7_mask_lpuart1 - m7_mask_lpuart1 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart1_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart2_MASK (0x80U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart2_SHIFT (7U)
/*! m7_mask_lpuart2 - m7_mask_lpuart2 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart2_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart3_MASK (0x100U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart3_SHIFT (8U)
/*! m7_mask_lpuart3 - m7_mask_lpuart3 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart3_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart4_MASK (0x200U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart4_SHIFT (9U)
/*! m7_mask_lpuart4 - m7_mask_lpuart4 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart4_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart5_MASK (0x400U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart5_SHIFT (10U)
/*! m7_mask_lpuart5 - m7_mask_lpuart5 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart5_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart6_MASK (0x800U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart6_SHIFT (11U)
/*! m7_mask_lpuart6 - m7_mask_lpuart6 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart6_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart7_MASK (0x1000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart7_SHIFT (12U)
/*! m7_mask_lpuart7 - m7_mask_lpuart7 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart7(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart7_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart8_MASK (0x2000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart8_SHIFT (13U)
/*! m7_mask_lpuart8 - m7_mask_lpuart8 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart8(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart8_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart9_MASK (0x4000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart9_SHIFT (14U)
/*! m7_mask_lpuart9 - m7_mask_lpuart9 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart9(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart9_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart10_MASK (0x8000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart10_SHIFT (15U)
/*! m7_mask_lpuart10 - m7_mask_lpuart10 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart10(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart10_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart11_MASK (0x10000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart11_SHIFT (16U)
/*! m7_mask_lpuart11 - m7_mask_lpuart11 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart11(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart11_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart12_MASK (0x20000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart12_SHIFT (17U)
/*! m7_mask_lpuart12 - m7_mask_lpuart12 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpuart12(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpuart12_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c1_MASK  (0x40000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c1_SHIFT (18U)
/*! m7_mask_lpi2c1 - m7_mask_lpi2c1 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c2_MASK  (0x80000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c2_SHIFT (19U)
/*! m7_mask_lpi2c2 - m7_mask_lpi2c2 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c3_MASK  (0x100000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c3_SHIFT (20U)
/*! m7_mask_lpi2c3 - m7_mask_lpi2c3 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c4_MASK  (0x200000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c4_SHIFT (21U)
/*! m7_mask_lpi2c4 - m7_mask_lpi2c4 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c5_MASK  (0x400000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c5_SHIFT (22U)
/*! m7_mask_lpi2c5 - m7_mask_lpi2c5 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c6_MASK  (0x800000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c6_SHIFT (23U)
/*! m7_mask_lpi2c6 - m7_mask_lpi2c6 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpi2c6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi1_MASK  (0x1000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi1_SHIFT (24U)
/*! m7_mask_lpspi1 - m7_mask_lpspi1 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpspi1_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi2_MASK  (0x2000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi2_SHIFT (25U)
/*! m7_mask_lpspi2 - m7_mask_lpspi2 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpspi2_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi3_MASK  (0x4000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi3_SHIFT (26U)
/*! m7_mask_lpspi3 - m7_mask_lpspi3 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpspi3_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi4_MASK  (0x8000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi4_SHIFT (27U)
/*! m7_mask_lpspi4 - m7_mask_lpspi4 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpspi4_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi5_MASK  (0x10000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi5_SHIFT (28U)
/*! m7_mask_lpspi5 - m7_mask_lpspi5 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpspi5_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi6_MASK  (0x20000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi6_SHIFT (29U)
/*! m7_mask_lpspi6 - m7_mask_lpspi6 */
#define CCM_GPR_SHARED6_CLR_m7_mask_lpspi6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_lpspi6_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_sinc1_MASK   (0x40000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_sinc1_SHIFT  (30U)
/*! m7_mask_sinc1 - m7_mask_sinc1 */
#define CCM_GPR_SHARED6_CLR_m7_mask_sinc1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_sinc1_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_sinc1_MASK)

#define CCM_GPR_SHARED6_CLR_m7_mask_sinc2_MASK   (0x80000000U)
#define CCM_GPR_SHARED6_CLR_m7_mask_sinc2_SHIFT  (31U)
/*! m7_mask_sinc2 - m7_mask_sinc2 */
#define CCM_GPR_SHARED6_CLR_m7_mask_sinc2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_CLR_m7_mask_sinc2_SHIFT)) & CCM_GPR_SHARED6_CLR_m7_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED6_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED6_TOG_m7_mask_tpm6_MASK    (0x1U)
#define CCM_GPR_SHARED6_TOG_m7_mask_tpm6_SHIFT   (0U)
/*! m7_mask_tpm6 - m7_mask_tpm6 */
#define CCM_GPR_SHARED6_TOG_m7_mask_tpm6(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_tpm6_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_tpm6_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_gpt1_MASK    (0x2U)
#define CCM_GPR_SHARED6_TOG_m7_mask_gpt1_SHIFT   (1U)
/*! m7_mask_gpt1 - m7_mask_gpt1 */
#define CCM_GPR_SHARED6_TOG_m7_mask_gpt1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_gpt1_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_gpt1_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_gpt2_MASK    (0x4U)
#define CCM_GPR_SHARED6_TOG_m7_mask_gpt2_SHIFT   (2U)
/*! m7_mask_gpt2 - m7_mask_gpt2 */
#define CCM_GPR_SHARED6_TOG_m7_mask_gpt2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_gpt2_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_gpt2_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_can1_MASK    (0x8U)
#define CCM_GPR_SHARED6_TOG_m7_mask_can1_SHIFT   (3U)
/*! m7_mask_can1 - m7_mask_can1 */
#define CCM_GPR_SHARED6_TOG_m7_mask_can1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_can1_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_can1_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_can2_MASK    (0x10U)
#define CCM_GPR_SHARED6_TOG_m7_mask_can2_SHIFT   (4U)
/*! m7_mask_can2 - m7_mask_can2 */
#define CCM_GPR_SHARED6_TOG_m7_mask_can2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_can2_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_can2_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_can3_MASK    (0x20U)
#define CCM_GPR_SHARED6_TOG_m7_mask_can3_SHIFT   (5U)
/*! m7_mask_can3 - m7_mask_can3 */
#define CCM_GPR_SHARED6_TOG_m7_mask_can3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_can3_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_can3_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart1_MASK (0x40U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart1_SHIFT (6U)
/*! m7_mask_lpuart1 - m7_mask_lpuart1 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart1(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart1_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart1_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart2_MASK (0x80U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart2_SHIFT (7U)
/*! m7_mask_lpuart2 - m7_mask_lpuart2 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart2(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart2_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart2_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart3_MASK (0x100U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart3_SHIFT (8U)
/*! m7_mask_lpuart3 - m7_mask_lpuart3 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart3(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart3_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart3_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart4_MASK (0x200U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart4_SHIFT (9U)
/*! m7_mask_lpuart4 - m7_mask_lpuart4 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart4(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart4_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart4_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart5_MASK (0x400U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart5_SHIFT (10U)
/*! m7_mask_lpuart5 - m7_mask_lpuart5 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart5(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart5_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart5_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart6_MASK (0x800U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart6_SHIFT (11U)
/*! m7_mask_lpuart6 - m7_mask_lpuart6 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart6(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart6_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart6_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart7_MASK (0x1000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart7_SHIFT (12U)
/*! m7_mask_lpuart7 - m7_mask_lpuart7 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart7(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart7_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart7_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart8_MASK (0x2000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart8_SHIFT (13U)
/*! m7_mask_lpuart8 - m7_mask_lpuart8 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart8(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart8_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart8_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart9_MASK (0x4000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart9_SHIFT (14U)
/*! m7_mask_lpuart9 - m7_mask_lpuart9 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart9(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart9_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart9_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart10_MASK (0x8000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart10_SHIFT (15U)
/*! m7_mask_lpuart10 - m7_mask_lpuart10 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart10(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart10_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart10_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart11_MASK (0x10000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart11_SHIFT (16U)
/*! m7_mask_lpuart11 - m7_mask_lpuart11 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart11(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart11_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart11_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart12_MASK (0x20000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart12_SHIFT (17U)
/*! m7_mask_lpuart12 - m7_mask_lpuart12 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpuart12(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpuart12_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpuart12_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c1_MASK  (0x40000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c1_SHIFT (18U)
/*! m7_mask_lpi2c1 - m7_mask_lpi2c1 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpi2c1_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpi2c1_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c2_MASK  (0x80000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c2_SHIFT (19U)
/*! m7_mask_lpi2c2 - m7_mask_lpi2c2 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpi2c2_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpi2c2_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c3_MASK  (0x100000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c3_SHIFT (20U)
/*! m7_mask_lpi2c3 - m7_mask_lpi2c3 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpi2c3_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpi2c3_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c4_MASK  (0x200000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c4_SHIFT (21U)
/*! m7_mask_lpi2c4 - m7_mask_lpi2c4 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpi2c4_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpi2c4_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c5_MASK  (0x400000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c5_SHIFT (22U)
/*! m7_mask_lpi2c5 - m7_mask_lpi2c5 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpi2c5_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpi2c5_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c6_MASK  (0x800000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c6_SHIFT (23U)
/*! m7_mask_lpi2c6 - m7_mask_lpi2c6 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpi2c6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpi2c6_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpi2c6_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi1_MASK  (0x1000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi1_SHIFT (24U)
/*! m7_mask_lpspi1 - m7_mask_lpspi1 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi1(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpspi1_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpspi1_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi2_MASK  (0x2000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi2_SHIFT (25U)
/*! m7_mask_lpspi2 - m7_mask_lpspi2 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi2(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpspi2_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpspi2_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi3_MASK  (0x4000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi3_SHIFT (26U)
/*! m7_mask_lpspi3 - m7_mask_lpspi3 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi3(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpspi3_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpspi3_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi4_MASK  (0x8000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi4_SHIFT (27U)
/*! m7_mask_lpspi4 - m7_mask_lpspi4 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi4(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpspi4_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpspi4_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi5_MASK  (0x10000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi5_SHIFT (28U)
/*! m7_mask_lpspi5 - m7_mask_lpspi5 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi5(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpspi5_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpspi5_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi6_MASK  (0x20000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi6_SHIFT (29U)
/*! m7_mask_lpspi6 - m7_mask_lpspi6 */
#define CCM_GPR_SHARED6_TOG_m7_mask_lpspi6(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_lpspi6_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_lpspi6_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_sinc1_MASK   (0x40000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_sinc1_SHIFT  (30U)
/*! m7_mask_sinc1 - m7_mask_sinc1 */
#define CCM_GPR_SHARED6_TOG_m7_mask_sinc1(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_sinc1_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_sinc1_MASK)

#define CCM_GPR_SHARED6_TOG_m7_mask_sinc2_MASK   (0x80000000U)
#define CCM_GPR_SHARED6_TOG_m7_mask_sinc2_SHIFT  (31U)
/*! m7_mask_sinc2 - m7_mask_sinc2 */
#define CCM_GPR_SHARED6_TOG_m7_mask_sinc2(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_TOG_m7_mask_sinc2_SHIFT)) & CCM_GPR_SHARED6_TOG_m7_mask_sinc2_MASK)
/*! @} */

/*! @name GPR_SHARED6_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED6_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED6_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED6_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED6_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED6_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED6_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED6_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED6_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED6_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED6_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED6_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED6_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED6_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED6_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED6_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED6_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED6_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED6_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED6_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED6_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED6_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED6_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED6_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED6_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED6_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED6_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED6_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED6_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED6_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED6_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED6_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED6_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED6_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED6_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED6_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED6_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED6_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED6_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED6_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED6_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED6_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED6_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED6_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED6_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED6_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED6_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED6_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED6_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED6_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED6_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED6_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED6_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED6_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED7 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED7_m7_mask_sinc3_MASK       (0x1U)
#define CCM_GPR_SHARED7_m7_mask_sinc3_SHIFT      (0U)
/*! m7_mask_sinc3 - m7_mask_sinc3 */
#define CCM_GPR_SHARED7_m7_mask_sinc3(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_m7_mask_sinc3_SHIFT)) & CCM_GPR_SHARED7_m7_mask_sinc3_MASK)

#define CCM_GPR_SHARED7_m7_mask_sai1_MASK        (0x2U)
#define CCM_GPR_SHARED7_m7_mask_sai1_SHIFT       (1U)
/*! m7_mask_sai1 - m7_mask_sai1 */
#define CCM_GPR_SHARED7_m7_mask_sai1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_m7_mask_sai1_SHIFT)) & CCM_GPR_SHARED7_m7_mask_sai1_MASK)

#define CCM_GPR_SHARED7_m7_mask_sai2_MASK        (0x4U)
#define CCM_GPR_SHARED7_m7_mask_sai2_SHIFT       (2U)
/*! m7_mask_sai2 - m7_mask_sai2 */
#define CCM_GPR_SHARED7_m7_mask_sai2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_m7_mask_sai2_SHIFT)) & CCM_GPR_SHARED7_m7_mask_sai2_MASK)

#define CCM_GPR_SHARED7_m7_mask_sai3_MASK        (0x8U)
#define CCM_GPR_SHARED7_m7_mask_sai3_SHIFT       (3U)
/*! m7_mask_sai3 - m7_mask_sai3 */
#define CCM_GPR_SHARED7_m7_mask_sai3(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_m7_mask_sai3_SHIFT)) & CCM_GPR_SHARED7_m7_mask_sai3_MASK)

#define CCM_GPR_SHARED7_m7_mask_sai4_MASK        (0x10U)
#define CCM_GPR_SHARED7_m7_mask_sai4_SHIFT       (4U)
/*! m7_mask_sai4 - m7_mask_sai4 */
#define CCM_GPR_SHARED7_m7_mask_sai4(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_m7_mask_sai4_SHIFT)) & CCM_GPR_SHARED7_m7_mask_sai4_MASK)

#define CCM_GPR_SHARED7_m7_mask_mic_MASK         (0x20U)
#define CCM_GPR_SHARED7_m7_mask_mic_SHIFT        (5U)
/*! m7_mask_mic - m7_mask_mic */
#define CCM_GPR_SHARED7_m7_mask_mic(x)           (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_m7_mask_mic_SHIFT)) & CCM_GPR_SHARED7_m7_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED7_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED7_SET_m7_mask_sinc3_MASK   (0x1U)
#define CCM_GPR_SHARED7_SET_m7_mask_sinc3_SHIFT  (0U)
/*! m7_mask_sinc3 - m7_mask_sinc3 */
#define CCM_GPR_SHARED7_SET_m7_mask_sinc3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_SET_m7_mask_sinc3_SHIFT)) & CCM_GPR_SHARED7_SET_m7_mask_sinc3_MASK)

#define CCM_GPR_SHARED7_SET_m7_mask_sai1_MASK    (0x2U)
#define CCM_GPR_SHARED7_SET_m7_mask_sai1_SHIFT   (1U)
/*! m7_mask_sai1 - m7_mask_sai1 */
#define CCM_GPR_SHARED7_SET_m7_mask_sai1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_SET_m7_mask_sai1_SHIFT)) & CCM_GPR_SHARED7_SET_m7_mask_sai1_MASK)

#define CCM_GPR_SHARED7_SET_m7_mask_sai2_MASK    (0x4U)
#define CCM_GPR_SHARED7_SET_m7_mask_sai2_SHIFT   (2U)
/*! m7_mask_sai2 - m7_mask_sai2 */
#define CCM_GPR_SHARED7_SET_m7_mask_sai2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_SET_m7_mask_sai2_SHIFT)) & CCM_GPR_SHARED7_SET_m7_mask_sai2_MASK)

#define CCM_GPR_SHARED7_SET_m7_mask_sai3_MASK    (0x8U)
#define CCM_GPR_SHARED7_SET_m7_mask_sai3_SHIFT   (3U)
/*! m7_mask_sai3 - m7_mask_sai3 */
#define CCM_GPR_SHARED7_SET_m7_mask_sai3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_SET_m7_mask_sai3_SHIFT)) & CCM_GPR_SHARED7_SET_m7_mask_sai3_MASK)

#define CCM_GPR_SHARED7_SET_m7_mask_sai4_MASK    (0x10U)
#define CCM_GPR_SHARED7_SET_m7_mask_sai4_SHIFT   (4U)
/*! m7_mask_sai4 - m7_mask_sai4 */
#define CCM_GPR_SHARED7_SET_m7_mask_sai4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_SET_m7_mask_sai4_SHIFT)) & CCM_GPR_SHARED7_SET_m7_mask_sai4_MASK)

#define CCM_GPR_SHARED7_SET_m7_mask_mic_MASK     (0x20U)
#define CCM_GPR_SHARED7_SET_m7_mask_mic_SHIFT    (5U)
/*! m7_mask_mic - m7_mask_mic */
#define CCM_GPR_SHARED7_SET_m7_mask_mic(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_SET_m7_mask_mic_SHIFT)) & CCM_GPR_SHARED7_SET_m7_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED7_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED7_CLR_m7_mask_sinc3_MASK   (0x1U)
#define CCM_GPR_SHARED7_CLR_m7_mask_sinc3_SHIFT  (0U)
/*! m7_mask_sinc3 - m7_mask_sinc3 */
#define CCM_GPR_SHARED7_CLR_m7_mask_sinc3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_CLR_m7_mask_sinc3_SHIFT)) & CCM_GPR_SHARED7_CLR_m7_mask_sinc3_MASK)

#define CCM_GPR_SHARED7_CLR_m7_mask_sai1_MASK    (0x2U)
#define CCM_GPR_SHARED7_CLR_m7_mask_sai1_SHIFT   (1U)
/*! m7_mask_sai1 - m7_mask_sai1 */
#define CCM_GPR_SHARED7_CLR_m7_mask_sai1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_CLR_m7_mask_sai1_SHIFT)) & CCM_GPR_SHARED7_CLR_m7_mask_sai1_MASK)

#define CCM_GPR_SHARED7_CLR_m7_mask_sai2_MASK    (0x4U)
#define CCM_GPR_SHARED7_CLR_m7_mask_sai2_SHIFT   (2U)
/*! m7_mask_sai2 - m7_mask_sai2 */
#define CCM_GPR_SHARED7_CLR_m7_mask_sai2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_CLR_m7_mask_sai2_SHIFT)) & CCM_GPR_SHARED7_CLR_m7_mask_sai2_MASK)

#define CCM_GPR_SHARED7_CLR_m7_mask_sai3_MASK    (0x8U)
#define CCM_GPR_SHARED7_CLR_m7_mask_sai3_SHIFT   (3U)
/*! m7_mask_sai3 - m7_mask_sai3 */
#define CCM_GPR_SHARED7_CLR_m7_mask_sai3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_CLR_m7_mask_sai3_SHIFT)) & CCM_GPR_SHARED7_CLR_m7_mask_sai3_MASK)

#define CCM_GPR_SHARED7_CLR_m7_mask_sai4_MASK    (0x10U)
#define CCM_GPR_SHARED7_CLR_m7_mask_sai4_SHIFT   (4U)
/*! m7_mask_sai4 - m7_mask_sai4 */
#define CCM_GPR_SHARED7_CLR_m7_mask_sai4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_CLR_m7_mask_sai4_SHIFT)) & CCM_GPR_SHARED7_CLR_m7_mask_sai4_MASK)

#define CCM_GPR_SHARED7_CLR_m7_mask_mic_MASK     (0x20U)
#define CCM_GPR_SHARED7_CLR_m7_mask_mic_SHIFT    (5U)
/*! m7_mask_mic - m7_mask_mic */
#define CCM_GPR_SHARED7_CLR_m7_mask_mic(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_CLR_m7_mask_mic_SHIFT)) & CCM_GPR_SHARED7_CLR_m7_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED7_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED7_TOG_m7_mask_sinc3_MASK   (0x1U)
#define CCM_GPR_SHARED7_TOG_m7_mask_sinc3_SHIFT  (0U)
/*! m7_mask_sinc3 - m7_mask_sinc3 */
#define CCM_GPR_SHARED7_TOG_m7_mask_sinc3(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_TOG_m7_mask_sinc3_SHIFT)) & CCM_GPR_SHARED7_TOG_m7_mask_sinc3_MASK)

#define CCM_GPR_SHARED7_TOG_m7_mask_sai1_MASK    (0x2U)
#define CCM_GPR_SHARED7_TOG_m7_mask_sai1_SHIFT   (1U)
/*! m7_mask_sai1 - m7_mask_sai1 */
#define CCM_GPR_SHARED7_TOG_m7_mask_sai1(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_TOG_m7_mask_sai1_SHIFT)) & CCM_GPR_SHARED7_TOG_m7_mask_sai1_MASK)

#define CCM_GPR_SHARED7_TOG_m7_mask_sai2_MASK    (0x4U)
#define CCM_GPR_SHARED7_TOG_m7_mask_sai2_SHIFT   (2U)
/*! m7_mask_sai2 - m7_mask_sai2 */
#define CCM_GPR_SHARED7_TOG_m7_mask_sai2(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_TOG_m7_mask_sai2_SHIFT)) & CCM_GPR_SHARED7_TOG_m7_mask_sai2_MASK)

#define CCM_GPR_SHARED7_TOG_m7_mask_sai3_MASK    (0x8U)
#define CCM_GPR_SHARED7_TOG_m7_mask_sai3_SHIFT   (3U)
/*! m7_mask_sai3 - m7_mask_sai3 */
#define CCM_GPR_SHARED7_TOG_m7_mask_sai3(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_TOG_m7_mask_sai3_SHIFT)) & CCM_GPR_SHARED7_TOG_m7_mask_sai3_MASK)

#define CCM_GPR_SHARED7_TOG_m7_mask_sai4_MASK    (0x10U)
#define CCM_GPR_SHARED7_TOG_m7_mask_sai4_SHIFT   (4U)
/*! m7_mask_sai4 - m7_mask_sai4 */
#define CCM_GPR_SHARED7_TOG_m7_mask_sai4(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_TOG_m7_mask_sai4_SHIFT)) & CCM_GPR_SHARED7_TOG_m7_mask_sai4_MASK)

#define CCM_GPR_SHARED7_TOG_m7_mask_mic_MASK     (0x20U)
#define CCM_GPR_SHARED7_TOG_m7_mask_mic_SHIFT    (5U)
/*! m7_mask_mic - m7_mask_mic */
#define CCM_GPR_SHARED7_TOG_m7_mask_mic(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_TOG_m7_mask_mic_SHIFT)) & CCM_GPR_SHARED7_TOG_m7_mask_mic_MASK)
/*! @} */

/*! @name GPR_SHARED7_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED7_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED7_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED7_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED7_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED7_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED7_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED7_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED7_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED7_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED7_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED7_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED7_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED7_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED7_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED7_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED7_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED7_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED7_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED7_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED7_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED7_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED7_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED7_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED7_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED7_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED7_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED7_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED7_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED7_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED7_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED7_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED7_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED7_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED7_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED7_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED7_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED7_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED7_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED7_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED7_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED7_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED7_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED7_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED7_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED7_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED7_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED7_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED7_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED7_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED7_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED7_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED7_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED7_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED8 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED8_m33_cm7_ipg_stop_MASK    (0x1U)
#define CCM_GPR_SHARED8_m33_cm7_ipg_stop_SHIFT   (0U)
/*! m33_cm7_ipg_stop - m33_cm7_ipg_stop */
#define CCM_GPR_SHARED8_m33_cm7_ipg_stop(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_cm33_ipg_stop_MASK   (0x2U)
#define CCM_GPR_SHARED8_m33_cm33_ipg_stop_SHIFT  (1U)
/*! m33_cm33_ipg_stop - m33_cm33_ipg_stop */
#define CCM_GPR_SHARED8_m33_cm33_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_edma3_ipg_stop_MASK  (0x4U)
#define CCM_GPR_SHARED8_m33_edma3_ipg_stop_SHIFT (2U)
/*! m33_edma3_ipg_stop - m33_edma3_ipg_stop */
#define CCM_GPR_SHARED8_m33_edma3_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_edma4_ipg_stop_MASK  (0x8U)
#define CCM_GPR_SHARED8_m33_edma4_ipg_stop_SHIFT (3U)
/*! m33_edma4_ipg_stop - m33_edma4_ipg_stop */
#define CCM_GPR_SHARED8_m33_edma4_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_netc_ipg_stop_MASK   (0x10U)
#define CCM_GPR_SHARED8_m33_netc_ipg_stop_SHIFT  (4U)
/*! m33_netc_ipg_stop - m33_netc_ipg_stop */
#define CCM_GPR_SHARED8_m33_netc_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED8_m33_sim_aon_ipg_stop_SHIFT (8U)
/*! m33_sim_aon_ipg_stop - m33_sim_aon_ipg_stop */
#define CCM_GPR_SHARED8_m33_sim_aon_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_adc1_ipg_stop_MASK   (0x200U)
#define CCM_GPR_SHARED8_m33_adc1_ipg_stop_SHIFT  (9U)
/*! m33_adc1_ipg_stop - m33_adc1_ipg_stop */
#define CCM_GPR_SHARED8_m33_adc1_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_adc2_ipg_stop_MASK   (0x400U)
#define CCM_GPR_SHARED8_m33_adc2_ipg_stop_SHIFT  (10U)
/*! m33_adc2_ipg_stop - m33_adc2_ipg_stop */
#define CCM_GPR_SHARED8_m33_adc2_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED8_m33_flexspi1_ipg_stop_SHIFT (11U)
/*! m33_flexspi1_ipg_stop - m33_flexspi1_ipg_stop */
#define CCM_GPR_SHARED8_m33_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED8_m33_flexspi2_ipg_stop_SHIFT (12U)
/*! m33_flexspi2_ipg_stop - m33_flexspi2_ipg_stop */
#define CCM_GPR_SHARED8_m33_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_trdc_ipg_stop_MASK   (0x2000U)
#define CCM_GPR_SHARED8_m33_trdc_ipg_stop_SHIFT  (13U)
/*! m33_trdc_ipg_stop - m33_trdc_ipg_stop */
#define CCM_GPR_SHARED8_m33_trdc_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_semc_ipg_stop_MASK   (0x4000U)
#define CCM_GPR_SHARED8_m33_semc_ipg_stop_SHIFT  (14U)
/*! m33_semc_ipg_stop - m33_semc_ipg_stop */
#define CCM_GPR_SHARED8_m33_semc_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_iee_ipg_stop_MASK    (0x8000U)
#define CCM_GPR_SHARED8_m33_iee_ipg_stop_SHIFT   (15U)
/*! m33_iee_ipg_stop - m33_iee_ipg_stop */
#define CCM_GPR_SHARED8_m33_iee_ipg_stop(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_gpio1_ipg_stop_MASK  (0x10000U)
#define CCM_GPR_SHARED8_m33_gpio1_ipg_stop_SHIFT (16U)
/*! m33_gpio1_ipg_stop - m33_gpio1_ipg_stop */
#define CCM_GPR_SHARED8_m33_gpio1_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_gpio2_ipg_stop_MASK  (0x20000U)
#define CCM_GPR_SHARED8_m33_gpio2_ipg_stop_SHIFT (17U)
/*! m33_gpio2_ipg_stop - m33_gpio2_ipg_stop */
#define CCM_GPR_SHARED8_m33_gpio2_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_gpio3_ipg_stop_MASK  (0x40000U)
#define CCM_GPR_SHARED8_m33_gpio3_ipg_stop_SHIFT (18U)
/*! m33_gpio3_ipg_stop - m33_gpio3_ipg_stop */
#define CCM_GPR_SHARED8_m33_gpio3_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_gpio4_ipg_stop_MASK  (0x80000U)
#define CCM_GPR_SHARED8_m33_gpio4_ipg_stop_SHIFT (19U)
/*! m33_gpio4_ipg_stop - m33_gpio4_ipg_stop */
#define CCM_GPR_SHARED8_m33_gpio4_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_gpio5_ipg_stop_MASK  (0x100000U)
#define CCM_GPR_SHARED8_m33_gpio5_ipg_stop_SHIFT (20U)
/*! m33_gpio5_ipg_stop - m33_gpio5_ipg_stop */
#define CCM_GPR_SHARED8_m33_gpio5_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_gpio6_ipg_stop_MASK  (0x200000U)
#define CCM_GPR_SHARED8_m33_gpio6_ipg_stop_SHIFT (21U)
/*! m33_gpio6_ipg_stop - m33_gpio6_ipg_stop */
#define CCM_GPR_SHARED8_m33_gpio6_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED8_m33_flexio1_ipg_stop_SHIFT (22U)
/*! m33_flexio1_ipg_stop - m33_flexio1_ipg_stop */
#define CCM_GPR_SHARED8_m33_flexio1_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED8_m33_flexio2_ipg_stop_SHIFT (23U)
/*! m33_flexio2_ipg_stop - m33_flexio2_ipg_stop */
#define CCM_GPR_SHARED8_m33_flexio2_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_can1_ipg_stop_MASK   (0x1000000U)
#define CCM_GPR_SHARED8_m33_can1_ipg_stop_SHIFT  (24U)
/*! m33_can1_ipg_stop - m33_can1_ipg_stop */
#define CCM_GPR_SHARED8_m33_can1_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_can2_ipg_stop_MASK   (0x2000000U)
#define CCM_GPR_SHARED8_m33_can2_ipg_stop_SHIFT  (25U)
/*! m33_can2_ipg_stop - m33_can2_ipg_stop */
#define CCM_GPR_SHARED8_m33_can2_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_can3_ipg_stop_MASK   (0x4000000U)
#define CCM_GPR_SHARED8_m33_can3_ipg_stop_SHIFT  (26U)
/*! m33_can3_ipg_stop - m33_can3_ipg_stop */
#define CCM_GPR_SHARED8_m33_can3_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED8_m33_lpuart1_ipg_stop_SHIFT (27U)
/*! m33_lpuart1_ipg_stop - m33_lpuart1_ipg_stop */
#define CCM_GPR_SHARED8_m33_lpuart1_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED8_m33_lpuart2_ipg_stop_SHIFT (28U)
/*! m33_lpuart2_ipg_stop - m33_lpuart2_ipg_stop */
#define CCM_GPR_SHARED8_m33_lpuart2_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED8_m33_lpuart3_ipg_stop_SHIFT (29U)
/*! m33_lpuart3_ipg_stop - m33_lpuart3_ipg_stop */
#define CCM_GPR_SHARED8_m33_lpuart3_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED8_m33_lpuart4_ipg_stop_SHIFT (30U)
/*! m33_lpuart4_ipg_stop - m33_lpuart4_ipg_stop */
#define CCM_GPR_SHARED8_m33_lpuart4_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_m33_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED8_m33_lpuart5_ipg_stop_SHIFT (31U)
/*! m33_lpuart5_ipg_stop - m33_lpuart5_ipg_stop */
#define CCM_GPR_SHARED8_m33_lpuart5_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_m33_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_m33_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED8_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED8_SET_m33_cm7_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED8_SET_m33_cm7_ipg_stop_SHIFT (0U)
/*! m33_cm7_ipg_stop - m33_cm7_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_cm7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_cm33_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED8_SET_m33_cm33_ipg_stop_SHIFT (1U)
/*! m33_cm33_ipg_stop - m33_cm33_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_cm33_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_edma3_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED8_SET_m33_edma3_ipg_stop_SHIFT (2U)
/*! m33_edma3_ipg_stop - m33_edma3_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_edma3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_edma4_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED8_SET_m33_edma4_ipg_stop_SHIFT (3U)
/*! m33_edma4_ipg_stop - m33_edma4_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_edma4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_netc_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED8_SET_m33_netc_ipg_stop_SHIFT (4U)
/*! m33_netc_ipg_stop - m33_netc_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_netc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED8_SET_m33_sim_aon_ipg_stop_SHIFT (8U)
/*! m33_sim_aon_ipg_stop - m33_sim_aon_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_sim_aon_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_adc1_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED8_SET_m33_adc1_ipg_stop_SHIFT (9U)
/*! m33_adc1_ipg_stop - m33_adc1_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_adc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_adc2_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED8_SET_m33_adc2_ipg_stop_SHIFT (10U)
/*! m33_adc2_ipg_stop - m33_adc2_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_adc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED8_SET_m33_flexspi1_ipg_stop_SHIFT (11U)
/*! m33_flexspi1_ipg_stop - m33_flexspi1_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED8_SET_m33_flexspi2_ipg_stop_SHIFT (12U)
/*! m33_flexspi2_ipg_stop - m33_flexspi2_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_trdc_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED8_SET_m33_trdc_ipg_stop_SHIFT (13U)
/*! m33_trdc_ipg_stop - m33_trdc_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_trdc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_semc_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED8_SET_m33_semc_ipg_stop_SHIFT (14U)
/*! m33_semc_ipg_stop - m33_semc_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_semc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_iee_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED8_SET_m33_iee_ipg_stop_SHIFT (15U)
/*! m33_iee_ipg_stop - m33_iee_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_iee_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_gpio1_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED8_SET_m33_gpio1_ipg_stop_SHIFT (16U)
/*! m33_gpio1_ipg_stop - m33_gpio1_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_gpio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_gpio2_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED8_SET_m33_gpio2_ipg_stop_SHIFT (17U)
/*! m33_gpio2_ipg_stop - m33_gpio2_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_gpio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_gpio3_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED8_SET_m33_gpio3_ipg_stop_SHIFT (18U)
/*! m33_gpio3_ipg_stop - m33_gpio3_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_gpio3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_gpio4_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED8_SET_m33_gpio4_ipg_stop_SHIFT (19U)
/*! m33_gpio4_ipg_stop - m33_gpio4_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_gpio4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_gpio5_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED8_SET_m33_gpio5_ipg_stop_SHIFT (20U)
/*! m33_gpio5_ipg_stop - m33_gpio5_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_gpio5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_gpio6_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED8_SET_m33_gpio6_ipg_stop_SHIFT (21U)
/*! m33_gpio6_ipg_stop - m33_gpio6_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_gpio6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED8_SET_m33_flexio1_ipg_stop_SHIFT (22U)
/*! m33_flexio1_ipg_stop - m33_flexio1_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_flexio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED8_SET_m33_flexio2_ipg_stop_SHIFT (23U)
/*! m33_flexio2_ipg_stop - m33_flexio2_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_flexio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_can1_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED8_SET_m33_can1_ipg_stop_SHIFT (24U)
/*! m33_can1_ipg_stop - m33_can1_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_can1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_can2_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED8_SET_m33_can2_ipg_stop_SHIFT (25U)
/*! m33_can2_ipg_stop - m33_can2_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_can2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_can3_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED8_SET_m33_can3_ipg_stop_SHIFT (26U)
/*! m33_can3_ipg_stop - m33_can3_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_can3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED8_SET_m33_lpuart1_ipg_stop_SHIFT (27U)
/*! m33_lpuart1_ipg_stop - m33_lpuart1_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_lpuart1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED8_SET_m33_lpuart2_ipg_stop_SHIFT (28U)
/*! m33_lpuart2_ipg_stop - m33_lpuart2_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_lpuart2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED8_SET_m33_lpuart3_ipg_stop_SHIFT (29U)
/*! m33_lpuart3_ipg_stop - m33_lpuart3_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_lpuart3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED8_SET_m33_lpuart4_ipg_stop_SHIFT (30U)
/*! m33_lpuart4_ipg_stop - m33_lpuart4_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_lpuart4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_SET_m33_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED8_SET_m33_lpuart5_ipg_stop_SHIFT (31U)
/*! m33_lpuart5_ipg_stop - m33_lpuart5_ipg_stop */
#define CCM_GPR_SHARED8_SET_m33_lpuart5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_SET_m33_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_SET_m33_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED8_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED8_CLR_m33_cm7_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED8_CLR_m33_cm7_ipg_stop_SHIFT (0U)
/*! m33_cm7_ipg_stop - m33_cm7_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_cm7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_cm33_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED8_CLR_m33_cm33_ipg_stop_SHIFT (1U)
/*! m33_cm33_ipg_stop - m33_cm33_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_cm33_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_edma3_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED8_CLR_m33_edma3_ipg_stop_SHIFT (2U)
/*! m33_edma3_ipg_stop - m33_edma3_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_edma3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_edma4_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED8_CLR_m33_edma4_ipg_stop_SHIFT (3U)
/*! m33_edma4_ipg_stop - m33_edma4_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_edma4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_netc_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED8_CLR_m33_netc_ipg_stop_SHIFT (4U)
/*! m33_netc_ipg_stop - m33_netc_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_netc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED8_CLR_m33_sim_aon_ipg_stop_SHIFT (8U)
/*! m33_sim_aon_ipg_stop - m33_sim_aon_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_sim_aon_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_adc1_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED8_CLR_m33_adc1_ipg_stop_SHIFT (9U)
/*! m33_adc1_ipg_stop - m33_adc1_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_adc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_adc2_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED8_CLR_m33_adc2_ipg_stop_SHIFT (10U)
/*! m33_adc2_ipg_stop - m33_adc2_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_adc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED8_CLR_m33_flexspi1_ipg_stop_SHIFT (11U)
/*! m33_flexspi1_ipg_stop - m33_flexspi1_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED8_CLR_m33_flexspi2_ipg_stop_SHIFT (12U)
/*! m33_flexspi2_ipg_stop - m33_flexspi2_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_trdc_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED8_CLR_m33_trdc_ipg_stop_SHIFT (13U)
/*! m33_trdc_ipg_stop - m33_trdc_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_trdc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_semc_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED8_CLR_m33_semc_ipg_stop_SHIFT (14U)
/*! m33_semc_ipg_stop - m33_semc_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_semc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_iee_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED8_CLR_m33_iee_ipg_stop_SHIFT (15U)
/*! m33_iee_ipg_stop - m33_iee_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_iee_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_gpio1_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED8_CLR_m33_gpio1_ipg_stop_SHIFT (16U)
/*! m33_gpio1_ipg_stop - m33_gpio1_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_gpio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_gpio2_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED8_CLR_m33_gpio2_ipg_stop_SHIFT (17U)
/*! m33_gpio2_ipg_stop - m33_gpio2_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_gpio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_gpio3_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED8_CLR_m33_gpio3_ipg_stop_SHIFT (18U)
/*! m33_gpio3_ipg_stop - m33_gpio3_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_gpio3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_gpio4_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED8_CLR_m33_gpio4_ipg_stop_SHIFT (19U)
/*! m33_gpio4_ipg_stop - m33_gpio4_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_gpio4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_gpio5_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED8_CLR_m33_gpio5_ipg_stop_SHIFT (20U)
/*! m33_gpio5_ipg_stop - m33_gpio5_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_gpio5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_gpio6_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED8_CLR_m33_gpio6_ipg_stop_SHIFT (21U)
/*! m33_gpio6_ipg_stop - m33_gpio6_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_gpio6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED8_CLR_m33_flexio1_ipg_stop_SHIFT (22U)
/*! m33_flexio1_ipg_stop - m33_flexio1_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_flexio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED8_CLR_m33_flexio2_ipg_stop_SHIFT (23U)
/*! m33_flexio2_ipg_stop - m33_flexio2_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_flexio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_can1_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED8_CLR_m33_can1_ipg_stop_SHIFT (24U)
/*! m33_can1_ipg_stop - m33_can1_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_can1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_can2_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED8_CLR_m33_can2_ipg_stop_SHIFT (25U)
/*! m33_can2_ipg_stop - m33_can2_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_can2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_can3_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED8_CLR_m33_can3_ipg_stop_SHIFT (26U)
/*! m33_can3_ipg_stop - m33_can3_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_can3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED8_CLR_m33_lpuart1_ipg_stop_SHIFT (27U)
/*! m33_lpuart1_ipg_stop - m33_lpuart1_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_lpuart1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED8_CLR_m33_lpuart2_ipg_stop_SHIFT (28U)
/*! m33_lpuart2_ipg_stop - m33_lpuart2_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_lpuart2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED8_CLR_m33_lpuart3_ipg_stop_SHIFT (29U)
/*! m33_lpuart3_ipg_stop - m33_lpuart3_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_lpuart3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED8_CLR_m33_lpuart4_ipg_stop_SHIFT (30U)
/*! m33_lpuart4_ipg_stop - m33_lpuart4_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_lpuart4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_CLR_m33_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED8_CLR_m33_lpuart5_ipg_stop_SHIFT (31U)
/*! m33_lpuart5_ipg_stop - m33_lpuart5_ipg_stop */
#define CCM_GPR_SHARED8_CLR_m33_lpuart5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_CLR_m33_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_CLR_m33_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED8_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED8_TOG_m33_cm7_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED8_TOG_m33_cm7_ipg_stop_SHIFT (0U)
/*! m33_cm7_ipg_stop - m33_cm7_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_cm7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_cm33_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED8_TOG_m33_cm33_ipg_stop_SHIFT (1U)
/*! m33_cm33_ipg_stop - m33_cm33_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_cm33_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_edma3_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED8_TOG_m33_edma3_ipg_stop_SHIFT (2U)
/*! m33_edma3_ipg_stop - m33_edma3_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_edma3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_edma4_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED8_TOG_m33_edma4_ipg_stop_SHIFT (3U)
/*! m33_edma4_ipg_stop - m33_edma4_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_edma4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_netc_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED8_TOG_m33_netc_ipg_stop_SHIFT (4U)
/*! m33_netc_ipg_stop - m33_netc_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_netc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED8_TOG_m33_sim_aon_ipg_stop_SHIFT (8U)
/*! m33_sim_aon_ipg_stop - m33_sim_aon_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_sim_aon_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_adc1_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED8_TOG_m33_adc1_ipg_stop_SHIFT (9U)
/*! m33_adc1_ipg_stop - m33_adc1_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_adc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_adc2_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED8_TOG_m33_adc2_ipg_stop_SHIFT (10U)
/*! m33_adc2_ipg_stop - m33_adc2_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_adc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED8_TOG_m33_flexspi1_ipg_stop_SHIFT (11U)
/*! m33_flexspi1_ipg_stop - m33_flexspi1_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED8_TOG_m33_flexspi2_ipg_stop_SHIFT (12U)
/*! m33_flexspi2_ipg_stop - m33_flexspi2_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_trdc_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED8_TOG_m33_trdc_ipg_stop_SHIFT (13U)
/*! m33_trdc_ipg_stop - m33_trdc_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_trdc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_semc_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED8_TOG_m33_semc_ipg_stop_SHIFT (14U)
/*! m33_semc_ipg_stop - m33_semc_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_semc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_iee_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED8_TOG_m33_iee_ipg_stop_SHIFT (15U)
/*! m33_iee_ipg_stop - m33_iee_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_iee_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_gpio1_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED8_TOG_m33_gpio1_ipg_stop_SHIFT (16U)
/*! m33_gpio1_ipg_stop - m33_gpio1_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_gpio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_gpio2_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED8_TOG_m33_gpio2_ipg_stop_SHIFT (17U)
/*! m33_gpio2_ipg_stop - m33_gpio2_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_gpio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_gpio3_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED8_TOG_m33_gpio3_ipg_stop_SHIFT (18U)
/*! m33_gpio3_ipg_stop - m33_gpio3_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_gpio3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_gpio4_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED8_TOG_m33_gpio4_ipg_stop_SHIFT (19U)
/*! m33_gpio4_ipg_stop - m33_gpio4_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_gpio4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_gpio5_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED8_TOG_m33_gpio5_ipg_stop_SHIFT (20U)
/*! m33_gpio5_ipg_stop - m33_gpio5_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_gpio5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_gpio6_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED8_TOG_m33_gpio6_ipg_stop_SHIFT (21U)
/*! m33_gpio6_ipg_stop - m33_gpio6_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_gpio6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED8_TOG_m33_flexio1_ipg_stop_SHIFT (22U)
/*! m33_flexio1_ipg_stop - m33_flexio1_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_flexio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED8_TOG_m33_flexio2_ipg_stop_SHIFT (23U)
/*! m33_flexio2_ipg_stop - m33_flexio2_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_flexio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_can1_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED8_TOG_m33_can1_ipg_stop_SHIFT (24U)
/*! m33_can1_ipg_stop - m33_can1_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_can1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_can2_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED8_TOG_m33_can2_ipg_stop_SHIFT (25U)
/*! m33_can2_ipg_stop - m33_can2_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_can2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_can3_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED8_TOG_m33_can3_ipg_stop_SHIFT (26U)
/*! m33_can3_ipg_stop - m33_can3_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_can3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED8_TOG_m33_lpuart1_ipg_stop_SHIFT (27U)
/*! m33_lpuart1_ipg_stop - m33_lpuart1_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_lpuart1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED8_TOG_m33_lpuart2_ipg_stop_SHIFT (28U)
/*! m33_lpuart2_ipg_stop - m33_lpuart2_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_lpuart2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED8_TOG_m33_lpuart3_ipg_stop_SHIFT (29U)
/*! m33_lpuart3_ipg_stop - m33_lpuart3_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_lpuart3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED8_TOG_m33_lpuart4_ipg_stop_SHIFT (30U)
/*! m33_lpuart4_ipg_stop - m33_lpuart4_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_lpuart4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED8_TOG_m33_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED8_TOG_m33_lpuart5_ipg_stop_SHIFT (31U)
/*! m33_lpuart5_ipg_stop - m33_lpuart5_ipg_stop */
#define CCM_GPR_SHARED8_TOG_m33_lpuart5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_TOG_m33_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED8_TOG_m33_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED8_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED8_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED8_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED8_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED8_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED8_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED8_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED8_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED8_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED8_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED8_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED8_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED8_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED8_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED8_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED8_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED8_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED8_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED8_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED8_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED8_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED8_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED8_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED8_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED8_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED8_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED8_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED8_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED8_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED8_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED8_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED8_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED8_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED8_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED8_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED8_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED8_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED8_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED8_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED8_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED8_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED8_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED8_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED8_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED8_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED8_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED8_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED8_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED8_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED8_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED8_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED8_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED8_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED8_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED9 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED9_m33_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED9_m33_lpuart6_ipg_stop_SHIFT (0U)
/*! m33_lpuart6_ipg_stop - m33_lpuart6_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart6_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED9_m33_lpuart7_ipg_stop_SHIFT (1U)
/*! m33_lpuart7_ipg_stop - m33_lpuart7_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED9_m33_lpuart8_ipg_stop_SHIFT (2U)
/*! m33_lpuart8_ipg_stop - m33_lpuart8_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart8_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED9_m33_lpuart9_ipg_stop_SHIFT (3U)
/*! m33_lpuart9_ipg_stop - m33_lpuart9_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart9_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED9_m33_lpuart10_ipg_stop_SHIFT (4U)
/*! m33_lpuart10_ipg_stop - m33_lpuart10_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED9_m33_lpuart11_ipg_stop_SHIFT (5U)
/*! m33_lpuart11_ipg_stop - m33_lpuart11_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED9_m33_lpuart12_ipg_stop_SHIFT (6U)
/*! m33_lpuart12_ipg_stop - m33_lpuart12_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED9_m33_lpi2c1_ipg_stop_SHIFT (7U)
/*! m33_lpi2c1_ipg_stop - m33_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpi2c1_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED9_m33_lpi2c2_ipg_stop_SHIFT (8U)
/*! m33_lpi2c2_ipg_stop - m33_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpi2c2_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED9_m33_lpi2c3_ipg_stop_SHIFT (9U)
/*! m33_lpi2c3_ipg_stop - m33_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpi2c3_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED9_m33_lpi2c4_ipg_stop_SHIFT (10U)
/*! m33_lpi2c4_ipg_stop - m33_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpi2c4_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED9_m33_lpi2c5_ipg_stop_SHIFT (11U)
/*! m33_lpi2c5_ipg_stop - m33_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpi2c5_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED9_m33_lpi2c6_ipg_stop_SHIFT (12U)
/*! m33_lpi2c6_ipg_stop - m33_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpi2c6_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED9_m33_lpspi1_ipg_stop_SHIFT (13U)
/*! m33_lpspi1_ipg_stop - m33_lpspi1_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpspi1_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED9_m33_lpspi2_ipg_stop_SHIFT (14U)
/*! m33_lpspi2_ipg_stop - m33_lpspi2_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpspi2_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED9_m33_lpspi3_ipg_stop_SHIFT (15U)
/*! m33_lpspi3_ipg_stop - m33_lpspi3_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpspi3_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED9_m33_lpspi4_ipg_stop_SHIFT (16U)
/*! m33_lpspi4_ipg_stop - m33_lpspi4_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpspi4_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED9_m33_lpspi5_ipg_stop_SHIFT (17U)
/*! m33_lpspi5_ipg_stop - m33_lpspi5_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpspi5_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED9_m33_lpspi6_ipg_stop_SHIFT (18U)
/*! m33_lpspi6_ipg_stop - m33_lpspi6_ipg_stop */
#define CCM_GPR_SHARED9_m33_lpspi6_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sinc1_ipg_stop_MASK  (0x80000U)
#define CCM_GPR_SHARED9_m33_sinc1_ipg_stop_SHIFT (19U)
/*! m33_sinc1_ipg_stop - m33_sinc1_ipg_stop */
#define CCM_GPR_SHARED9_m33_sinc1_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sinc2_ipg_stop_MASK  (0x100000U)
#define CCM_GPR_SHARED9_m33_sinc2_ipg_stop_SHIFT (20U)
/*! m33_sinc2_ipg_stop - m33_sinc2_ipg_stop */
#define CCM_GPR_SHARED9_m33_sinc2_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sinc3_ipg_stop_MASK  (0x200000U)
#define CCM_GPR_SHARED9_m33_sinc3_ipg_stop_SHIFT (21U)
/*! m33_sinc3_ipg_stop - m33_sinc3_ipg_stop */
#define CCM_GPR_SHARED9_m33_sinc3_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sai1_ipg_stop_MASK   (0x400000U)
#define CCM_GPR_SHARED9_m33_sai1_ipg_stop_SHIFT  (22U)
/*! m33_sai1_ipg_stop - m33_sai1_ipg_stop */
#define CCM_GPR_SHARED9_m33_sai1_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sai2_ipg_stop_MASK   (0x800000U)
#define CCM_GPR_SHARED9_m33_sai2_ipg_stop_SHIFT  (23U)
/*! m33_sai2_ipg_stop - m33_sai2_ipg_stop */
#define CCM_GPR_SHARED9_m33_sai2_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sai3_ipg_stop_MASK   (0x1000000U)
#define CCM_GPR_SHARED9_m33_sai3_ipg_stop_SHIFT  (24U)
/*! m33_sai3_ipg_stop - m33_sai3_ipg_stop */
#define CCM_GPR_SHARED9_m33_sai3_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_sai4_ipg_stop_MASK   (0x2000000U)
#define CCM_GPR_SHARED9_m33_sai4_ipg_stop_SHIFT  (25U)
/*! m33_sai4_ipg_stop - m33_sai4_ipg_stop */
#define CCM_GPR_SHARED9_m33_sai4_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_m33_mic_ipg_stop_MASK    (0x4000000U)
#define CCM_GPR_SHARED9_m33_mic_ipg_stop_SHIFT   (26U)
/*! m33_mic_ipg_stop - m33_mic_ipg_stop */
#define CCM_GPR_SHARED9_m33_mic_ipg_stop(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_m33_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_m33_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED9_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED9_SET_m33_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED9_SET_m33_lpuart6_ipg_stop_SHIFT (0U)
/*! m33_lpuart6_ipg_stop - m33_lpuart6_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED9_SET_m33_lpuart7_ipg_stop_SHIFT (1U)
/*! m33_lpuart7_ipg_stop - m33_lpuart7_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart7_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED9_SET_m33_lpuart8_ipg_stop_SHIFT (2U)
/*! m33_lpuart8_ipg_stop - m33_lpuart8_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart8_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED9_SET_m33_lpuart9_ipg_stop_SHIFT (3U)
/*! m33_lpuart9_ipg_stop - m33_lpuart9_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart9_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED9_SET_m33_lpuart10_ipg_stop_SHIFT (4U)
/*! m33_lpuart10_ipg_stop - m33_lpuart10_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED9_SET_m33_lpuart11_ipg_stop_SHIFT (5U)
/*! m33_lpuart11_ipg_stop - m33_lpuart11_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED9_SET_m33_lpuart12_ipg_stop_SHIFT (6U)
/*! m33_lpuart12_ipg_stop - m33_lpuart12_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED9_SET_m33_lpi2c1_ipg_stop_SHIFT (7U)
/*! m33_lpi2c1_ipg_stop - m33_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpi2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED9_SET_m33_lpi2c2_ipg_stop_SHIFT (8U)
/*! m33_lpi2c2_ipg_stop - m33_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpi2c2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED9_SET_m33_lpi2c3_ipg_stop_SHIFT (9U)
/*! m33_lpi2c3_ipg_stop - m33_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpi2c3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED9_SET_m33_lpi2c4_ipg_stop_SHIFT (10U)
/*! m33_lpi2c4_ipg_stop - m33_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpi2c4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED9_SET_m33_lpi2c5_ipg_stop_SHIFT (11U)
/*! m33_lpi2c5_ipg_stop - m33_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpi2c5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED9_SET_m33_lpi2c6_ipg_stop_SHIFT (12U)
/*! m33_lpi2c6_ipg_stop - m33_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpi2c6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED9_SET_m33_lpspi1_ipg_stop_SHIFT (13U)
/*! m33_lpspi1_ipg_stop - m33_lpspi1_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED9_SET_m33_lpspi2_ipg_stop_SHIFT (14U)
/*! m33_lpspi2_ipg_stop - m33_lpspi2_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED9_SET_m33_lpspi3_ipg_stop_SHIFT (15U)
/*! m33_lpspi3_ipg_stop - m33_lpspi3_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED9_SET_m33_lpspi4_ipg_stop_SHIFT (16U)
/*! m33_lpspi4_ipg_stop - m33_lpspi4_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpspi4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED9_SET_m33_lpspi5_ipg_stop_SHIFT (17U)
/*! m33_lpspi5_ipg_stop - m33_lpspi5_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpspi5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED9_SET_m33_lpspi6_ipg_stop_SHIFT (18U)
/*! m33_lpspi6_ipg_stop - m33_lpspi6_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_lpspi6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sinc1_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED9_SET_m33_sinc1_ipg_stop_SHIFT (19U)
/*! m33_sinc1_ipg_stop - m33_sinc1_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sinc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sinc2_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED9_SET_m33_sinc2_ipg_stop_SHIFT (20U)
/*! m33_sinc2_ipg_stop - m33_sinc2_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sinc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sinc3_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED9_SET_m33_sinc3_ipg_stop_SHIFT (21U)
/*! m33_sinc3_ipg_stop - m33_sinc3_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sinc3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sai1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED9_SET_m33_sai1_ipg_stop_SHIFT (22U)
/*! m33_sai1_ipg_stop - m33_sai1_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sai1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sai2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED9_SET_m33_sai2_ipg_stop_SHIFT (23U)
/*! m33_sai2_ipg_stop - m33_sai2_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sai2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sai3_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED9_SET_m33_sai3_ipg_stop_SHIFT (24U)
/*! m33_sai3_ipg_stop - m33_sai3_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sai3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_sai4_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED9_SET_m33_sai4_ipg_stop_SHIFT (25U)
/*! m33_sai4_ipg_stop - m33_sai4_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_sai4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_SET_m33_mic_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED9_SET_m33_mic_ipg_stop_SHIFT (26U)
/*! m33_mic_ipg_stop - m33_mic_ipg_stop */
#define CCM_GPR_SHARED9_SET_m33_mic_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_SET_m33_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_SET_m33_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED9_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED9_CLR_m33_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart6_ipg_stop_SHIFT (0U)
/*! m33_lpuart6_ipg_stop - m33_lpuart6_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart7_ipg_stop_SHIFT (1U)
/*! m33_lpuart7_ipg_stop - m33_lpuart7_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart7_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart8_ipg_stop_SHIFT (2U)
/*! m33_lpuart8_ipg_stop - m33_lpuart8_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart8_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart9_ipg_stop_SHIFT (3U)
/*! m33_lpuart9_ipg_stop - m33_lpuart9_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart9_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart10_ipg_stop_SHIFT (4U)
/*! m33_lpuart10_ipg_stop - m33_lpuart10_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart11_ipg_stop_SHIFT (5U)
/*! m33_lpuart11_ipg_stop - m33_lpuart11_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED9_CLR_m33_lpuart12_ipg_stop_SHIFT (6U)
/*! m33_lpuart12_ipg_stop - m33_lpuart12_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED9_CLR_m33_lpi2c1_ipg_stop_SHIFT (7U)
/*! m33_lpi2c1_ipg_stop - m33_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpi2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED9_CLR_m33_lpi2c2_ipg_stop_SHIFT (8U)
/*! m33_lpi2c2_ipg_stop - m33_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpi2c2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED9_CLR_m33_lpi2c3_ipg_stop_SHIFT (9U)
/*! m33_lpi2c3_ipg_stop - m33_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpi2c3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED9_CLR_m33_lpi2c4_ipg_stop_SHIFT (10U)
/*! m33_lpi2c4_ipg_stop - m33_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpi2c4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED9_CLR_m33_lpi2c5_ipg_stop_SHIFT (11U)
/*! m33_lpi2c5_ipg_stop - m33_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpi2c5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED9_CLR_m33_lpi2c6_ipg_stop_SHIFT (12U)
/*! m33_lpi2c6_ipg_stop - m33_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpi2c6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED9_CLR_m33_lpspi1_ipg_stop_SHIFT (13U)
/*! m33_lpspi1_ipg_stop - m33_lpspi1_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED9_CLR_m33_lpspi2_ipg_stop_SHIFT (14U)
/*! m33_lpspi2_ipg_stop - m33_lpspi2_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED9_CLR_m33_lpspi3_ipg_stop_SHIFT (15U)
/*! m33_lpspi3_ipg_stop - m33_lpspi3_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED9_CLR_m33_lpspi4_ipg_stop_SHIFT (16U)
/*! m33_lpspi4_ipg_stop - m33_lpspi4_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpspi4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED9_CLR_m33_lpspi5_ipg_stop_SHIFT (17U)
/*! m33_lpspi5_ipg_stop - m33_lpspi5_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpspi5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED9_CLR_m33_lpspi6_ipg_stop_SHIFT (18U)
/*! m33_lpspi6_ipg_stop - m33_lpspi6_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_lpspi6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sinc1_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED9_CLR_m33_sinc1_ipg_stop_SHIFT (19U)
/*! m33_sinc1_ipg_stop - m33_sinc1_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sinc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sinc2_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED9_CLR_m33_sinc2_ipg_stop_SHIFT (20U)
/*! m33_sinc2_ipg_stop - m33_sinc2_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sinc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sinc3_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED9_CLR_m33_sinc3_ipg_stop_SHIFT (21U)
/*! m33_sinc3_ipg_stop - m33_sinc3_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sinc3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sai1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED9_CLR_m33_sai1_ipg_stop_SHIFT (22U)
/*! m33_sai1_ipg_stop - m33_sai1_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sai1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sai2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED9_CLR_m33_sai2_ipg_stop_SHIFT (23U)
/*! m33_sai2_ipg_stop - m33_sai2_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sai2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sai3_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED9_CLR_m33_sai3_ipg_stop_SHIFT (24U)
/*! m33_sai3_ipg_stop - m33_sai3_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sai3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_sai4_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED9_CLR_m33_sai4_ipg_stop_SHIFT (25U)
/*! m33_sai4_ipg_stop - m33_sai4_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_sai4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_CLR_m33_mic_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED9_CLR_m33_mic_ipg_stop_SHIFT (26U)
/*! m33_mic_ipg_stop - m33_mic_ipg_stop */
#define CCM_GPR_SHARED9_CLR_m33_mic_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_CLR_m33_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_CLR_m33_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED9_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED9_TOG_m33_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart6_ipg_stop_SHIFT (0U)
/*! m33_lpuart6_ipg_stop - m33_lpuart6_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart7_ipg_stop_SHIFT (1U)
/*! m33_lpuart7_ipg_stop - m33_lpuart7_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart7_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart8_ipg_stop_SHIFT (2U)
/*! m33_lpuart8_ipg_stop - m33_lpuart8_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart8_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart9_ipg_stop_SHIFT (3U)
/*! m33_lpuart9_ipg_stop - m33_lpuart9_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart9_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart10_ipg_stop_SHIFT (4U)
/*! m33_lpuart10_ipg_stop - m33_lpuart10_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart11_ipg_stop_SHIFT (5U)
/*! m33_lpuart11_ipg_stop - m33_lpuart11_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED9_TOG_m33_lpuart12_ipg_stop_SHIFT (6U)
/*! m33_lpuart12_ipg_stop - m33_lpuart12_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED9_TOG_m33_lpi2c1_ipg_stop_SHIFT (7U)
/*! m33_lpi2c1_ipg_stop - m33_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpi2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED9_TOG_m33_lpi2c2_ipg_stop_SHIFT (8U)
/*! m33_lpi2c2_ipg_stop - m33_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpi2c2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED9_TOG_m33_lpi2c3_ipg_stop_SHIFT (9U)
/*! m33_lpi2c3_ipg_stop - m33_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpi2c3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED9_TOG_m33_lpi2c4_ipg_stop_SHIFT (10U)
/*! m33_lpi2c4_ipg_stop - m33_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpi2c4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED9_TOG_m33_lpi2c5_ipg_stop_SHIFT (11U)
/*! m33_lpi2c5_ipg_stop - m33_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpi2c5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED9_TOG_m33_lpi2c6_ipg_stop_SHIFT (12U)
/*! m33_lpi2c6_ipg_stop - m33_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpi2c6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED9_TOG_m33_lpspi1_ipg_stop_SHIFT (13U)
/*! m33_lpspi1_ipg_stop - m33_lpspi1_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED9_TOG_m33_lpspi2_ipg_stop_SHIFT (14U)
/*! m33_lpspi2_ipg_stop - m33_lpspi2_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED9_TOG_m33_lpspi3_ipg_stop_SHIFT (15U)
/*! m33_lpspi3_ipg_stop - m33_lpspi3_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED9_TOG_m33_lpspi4_ipg_stop_SHIFT (16U)
/*! m33_lpspi4_ipg_stop - m33_lpspi4_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpspi4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED9_TOG_m33_lpspi5_ipg_stop_SHIFT (17U)
/*! m33_lpspi5_ipg_stop - m33_lpspi5_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpspi5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED9_TOG_m33_lpspi6_ipg_stop_SHIFT (18U)
/*! m33_lpspi6_ipg_stop - m33_lpspi6_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_lpspi6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sinc1_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED9_TOG_m33_sinc1_ipg_stop_SHIFT (19U)
/*! m33_sinc1_ipg_stop - m33_sinc1_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sinc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sinc2_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED9_TOG_m33_sinc2_ipg_stop_SHIFT (20U)
/*! m33_sinc2_ipg_stop - m33_sinc2_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sinc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sinc3_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED9_TOG_m33_sinc3_ipg_stop_SHIFT (21U)
/*! m33_sinc3_ipg_stop - m33_sinc3_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sinc3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sai1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED9_TOG_m33_sai1_ipg_stop_SHIFT (22U)
/*! m33_sai1_ipg_stop - m33_sai1_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sai1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sai2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED9_TOG_m33_sai2_ipg_stop_SHIFT (23U)
/*! m33_sai2_ipg_stop - m33_sai2_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sai2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sai3_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED9_TOG_m33_sai3_ipg_stop_SHIFT (24U)
/*! m33_sai3_ipg_stop - m33_sai3_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sai3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_sai4_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED9_TOG_m33_sai4_ipg_stop_SHIFT (25U)
/*! m33_sai4_ipg_stop - m33_sai4_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_sai4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED9_TOG_m33_mic_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED9_TOG_m33_mic_ipg_stop_SHIFT (26U)
/*! m33_mic_ipg_stop - m33_mic_ipg_stop */
#define CCM_GPR_SHARED9_TOG_m33_mic_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_TOG_m33_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED9_TOG_m33_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED9_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED9_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED9_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED9_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED9_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED9_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED9_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED9_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED9_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED9_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED9_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED9_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED9_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED9_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED9_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED9_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED9_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED9_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED9_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED9_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED9_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED9_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED9_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED9_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED9_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED9_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED9_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED9_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED9_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED9_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED9_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED9_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED9_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED9_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED9_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED9_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED9_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED9_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED9_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED9_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED9_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED9_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED9_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED9_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_SHARED9_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED9_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED9_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_SHARED9_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED9_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED9_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED9_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED9_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED9_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED9_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED10 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED10_m33_adc1_ipg_doze_MASK  (0x1U)
#define CCM_GPR_SHARED10_m33_adc1_ipg_doze_SHIFT (0U)
/*! m33_adc1_ipg_doze - m33_adc1_ipg_doze */
#define CCM_GPR_SHARED10_m33_adc1_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_adc2_ipg_doze_MASK  (0x2U)
#define CCM_GPR_SHARED10_m33_adc2_ipg_doze_SHIFT (1U)
/*! m33_adc2_ipg_doze - m33_adc2_ipg_doze */
#define CCM_GPR_SHARED10_m33_adc2_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED10_m33_flexspi1_ipg_doze_SHIFT (2U)
/*! m33_flexspi1_ipg_doze - m33_flexspi1_ipg_doze */
#define CCM_GPR_SHARED10_m33_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED10_m33_flexspi2_ipg_doze_SHIFT (3U)
/*! m33_flexspi2_ipg_doze - m33_flexspi2_ipg_doze */
#define CCM_GPR_SHARED10_m33_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED10_m33_flexio1_ipg_doze_SHIFT (4U)
/*! m33_flexio1_ipg_doze - m33_flexio1_ipg_doze */
#define CCM_GPR_SHARED10_m33_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED10_m33_flexio2_ipg_doze_SHIFT (5U)
/*! m33_flexio2_ipg_doze - m33_flexio2_ipg_doze */
#define CCM_GPR_SHARED10_m33_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED10_m33_lpit1_ipg_doze_SHIFT (6U)
/*! m33_lpit1_ipg_doze - m33_lpit1_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpit1_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED10_m33_lpit2_ipg_doze_SHIFT (7U)
/*! m33_lpit2_ipg_doze - m33_lpit2_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpit2_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED10_m33_lpit3_ipg_doze_SHIFT (8U)
/*! m33_lpit3_ipg_doze - m33_lpit3_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpit3_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_tpm1_ipg_doze_MASK  (0x200U)
#define CCM_GPR_SHARED10_m33_tpm1_ipg_doze_SHIFT (9U)
/*! m33_tpm1_ipg_doze - m33_tpm1_ipg_doze */
#define CCM_GPR_SHARED10_m33_tpm1_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_tpm2_ipg_doze_MASK  (0x400U)
#define CCM_GPR_SHARED10_m33_tpm2_ipg_doze_SHIFT (10U)
/*! m33_tpm2_ipg_doze - m33_tpm2_ipg_doze */
#define CCM_GPR_SHARED10_m33_tpm2_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_tpm3_ipg_doze_MASK  (0x800U)
#define CCM_GPR_SHARED10_m33_tpm3_ipg_doze_SHIFT (11U)
/*! m33_tpm3_ipg_doze - m33_tpm3_ipg_doze */
#define CCM_GPR_SHARED10_m33_tpm3_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_tpm4_ipg_doze_MASK  (0x1000U)
#define CCM_GPR_SHARED10_m33_tpm4_ipg_doze_SHIFT (12U)
/*! m33_tpm4_ipg_doze - m33_tpm4_ipg_doze */
#define CCM_GPR_SHARED10_m33_tpm4_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_tpm5_ipg_doze_MASK  (0x2000U)
#define CCM_GPR_SHARED10_m33_tpm5_ipg_doze_SHIFT (13U)
/*! m33_tpm5_ipg_doze - m33_tpm5_ipg_doze */
#define CCM_GPR_SHARED10_m33_tpm5_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_tpm6_ipg_doze_MASK  (0x4000U)
#define CCM_GPR_SHARED10_m33_tpm6_ipg_doze_SHIFT (14U)
/*! m33_tpm6_ipg_doze - m33_tpm6_ipg_doze */
#define CCM_GPR_SHARED10_m33_tpm6_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_gpt1_ipg_doze_MASK  (0x8000U)
#define CCM_GPR_SHARED10_m33_gpt1_ipg_doze_SHIFT (15U)
/*! m33_gpt1_ipg_doze - m33_gpt1_ipg_doze */
#define CCM_GPR_SHARED10_m33_gpt1_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_gpt2_ipg_doze_MASK  (0x10000U)
#define CCM_GPR_SHARED10_m33_gpt2_ipg_doze_SHIFT (16U)
/*! m33_gpt2_ipg_doze - m33_gpt2_ipg_doze */
#define CCM_GPR_SHARED10_m33_gpt2_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_can1_ipg_doze_MASK  (0x20000U)
#define CCM_GPR_SHARED10_m33_can1_ipg_doze_SHIFT (17U)
/*! m33_can1_ipg_doze - m33_can1_ipg_doze */
#define CCM_GPR_SHARED10_m33_can1_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_can2_ipg_doze_MASK  (0x40000U)
#define CCM_GPR_SHARED10_m33_can2_ipg_doze_SHIFT (18U)
/*! m33_can2_ipg_doze - m33_can2_ipg_doze */
#define CCM_GPR_SHARED10_m33_can2_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_can3_ipg_doze_MASK  (0x80000U)
#define CCM_GPR_SHARED10_m33_can3_ipg_doze_SHIFT (19U)
/*! m33_can3_ipg_doze - m33_can3_ipg_doze */
#define CCM_GPR_SHARED10_m33_can3_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED10_m33_lpuart1_ipg_doze_SHIFT (20U)
/*! m33_lpuart1_ipg_doze - m33_lpuart1_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED10_m33_lpuart2_ipg_doze_SHIFT (21U)
/*! m33_lpuart2_ipg_doze - m33_lpuart2_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED10_m33_lpuart3_ipg_doze_SHIFT (22U)
/*! m33_lpuart3_ipg_doze - m33_lpuart3_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED10_m33_lpuart4_ipg_doze_SHIFT (23U)
/*! m33_lpuart4_ipg_doze - m33_lpuart4_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED10_m33_lpuart5_ipg_doze_SHIFT (24U)
/*! m33_lpuart5_ipg_doze - m33_lpuart5_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED10_m33_lpuart6_ipg_doze_SHIFT (25U)
/*! m33_lpuart6_ipg_doze - m33_lpuart6_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED10_m33_lpuart7_ipg_doze_SHIFT (26U)
/*! m33_lpuart7_ipg_doze - m33_lpuart7_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED10_m33_lpuart8_ipg_doze_SHIFT (27U)
/*! m33_lpuart8_ipg_doze - m33_lpuart8_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED10_m33_lpuart9_ipg_doze_SHIFT (28U)
/*! m33_lpuart9_ipg_doze - m33_lpuart9_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED10_m33_lpuart10_ipg_doze_SHIFT (29U)
/*! m33_lpuart10_ipg_doze - m33_lpuart10_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED10_m33_lpuart11_ipg_doze_SHIFT (30U)
/*! m33_lpuart11_ipg_doze - m33_lpuart11_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED10_m33_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED10_m33_lpuart12_ipg_doze_SHIFT (31U)
/*! m33_lpuart12_ipg_doze - m33_lpuart12_ipg_doze */
#define CCM_GPR_SHARED10_m33_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_m33_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_m33_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED10_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED10_SET_m33_adc1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED10_SET_m33_adc1_ipg_doze_SHIFT (0U)
/*! m33_adc1_ipg_doze - m33_adc1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_adc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_adc2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED10_SET_m33_adc2_ipg_doze_SHIFT (1U)
/*! m33_adc2_ipg_doze - m33_adc2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_adc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED10_SET_m33_flexspi1_ipg_doze_SHIFT (2U)
/*! m33_flexspi1_ipg_doze - m33_flexspi1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED10_SET_m33_flexspi2_ipg_doze_SHIFT (3U)
/*! m33_flexspi2_ipg_doze - m33_flexspi2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED10_SET_m33_flexio1_ipg_doze_SHIFT (4U)
/*! m33_flexio1_ipg_doze - m33_flexio1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED10_SET_m33_flexio2_ipg_doze_SHIFT (5U)
/*! m33_flexio2_ipg_doze - m33_flexio2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED10_SET_m33_lpit1_ipg_doze_SHIFT (6U)
/*! m33_lpit1_ipg_doze - m33_lpit1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpit1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED10_SET_m33_lpit2_ipg_doze_SHIFT (7U)
/*! m33_lpit2_ipg_doze - m33_lpit2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpit2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED10_SET_m33_lpit3_ipg_doze_SHIFT (8U)
/*! m33_lpit3_ipg_doze - m33_lpit3_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpit3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_tpm1_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED10_SET_m33_tpm1_ipg_doze_SHIFT (9U)
/*! m33_tpm1_ipg_doze - m33_tpm1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_tpm1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_tpm2_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED10_SET_m33_tpm2_ipg_doze_SHIFT (10U)
/*! m33_tpm2_ipg_doze - m33_tpm2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_tpm2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_tpm3_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED10_SET_m33_tpm3_ipg_doze_SHIFT (11U)
/*! m33_tpm3_ipg_doze - m33_tpm3_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_tpm3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_tpm4_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED10_SET_m33_tpm4_ipg_doze_SHIFT (12U)
/*! m33_tpm4_ipg_doze - m33_tpm4_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_tpm4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_tpm5_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED10_SET_m33_tpm5_ipg_doze_SHIFT (13U)
/*! m33_tpm5_ipg_doze - m33_tpm5_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_tpm5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_tpm6_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED10_SET_m33_tpm6_ipg_doze_SHIFT (14U)
/*! m33_tpm6_ipg_doze - m33_tpm6_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_tpm6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_gpt1_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED10_SET_m33_gpt1_ipg_doze_SHIFT (15U)
/*! m33_gpt1_ipg_doze - m33_gpt1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_gpt1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_gpt2_ipg_doze_MASK (0x10000U)
#define CCM_GPR_SHARED10_SET_m33_gpt2_ipg_doze_SHIFT (16U)
/*! m33_gpt2_ipg_doze - m33_gpt2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_gpt2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_can1_ipg_doze_MASK (0x20000U)
#define CCM_GPR_SHARED10_SET_m33_can1_ipg_doze_SHIFT (17U)
/*! m33_can1_ipg_doze - m33_can1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_can1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_can2_ipg_doze_MASK (0x40000U)
#define CCM_GPR_SHARED10_SET_m33_can2_ipg_doze_SHIFT (18U)
/*! m33_can2_ipg_doze - m33_can2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_can2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_can3_ipg_doze_MASK (0x80000U)
#define CCM_GPR_SHARED10_SET_m33_can3_ipg_doze_SHIFT (19U)
/*! m33_can3_ipg_doze - m33_can3_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_can3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart1_ipg_doze_SHIFT (20U)
/*! m33_lpuart1_ipg_doze - m33_lpuart1_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart2_ipg_doze_SHIFT (21U)
/*! m33_lpuart2_ipg_doze - m33_lpuart2_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart3_ipg_doze_SHIFT (22U)
/*! m33_lpuart3_ipg_doze - m33_lpuart3_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart4_ipg_doze_SHIFT (23U)
/*! m33_lpuart4_ipg_doze - m33_lpuart4_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart5_ipg_doze_SHIFT (24U)
/*! m33_lpuart5_ipg_doze - m33_lpuart5_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart6_ipg_doze_SHIFT (25U)
/*! m33_lpuart6_ipg_doze - m33_lpuart6_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart7_ipg_doze_SHIFT (26U)
/*! m33_lpuart7_ipg_doze - m33_lpuart7_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart8_ipg_doze_SHIFT (27U)
/*! m33_lpuart8_ipg_doze - m33_lpuart8_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart9_ipg_doze_SHIFT (28U)
/*! m33_lpuart9_ipg_doze - m33_lpuart9_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart10_ipg_doze_SHIFT (29U)
/*! m33_lpuart10_ipg_doze - m33_lpuart10_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart11_ipg_doze_SHIFT (30U)
/*! m33_lpuart11_ipg_doze - m33_lpuart11_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED10_SET_m33_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED10_SET_m33_lpuart12_ipg_doze_SHIFT (31U)
/*! m33_lpuart12_ipg_doze - m33_lpuart12_ipg_doze */
#define CCM_GPR_SHARED10_SET_m33_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_SET_m33_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_SET_m33_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED10_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED10_CLR_m33_adc1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED10_CLR_m33_adc1_ipg_doze_SHIFT (0U)
/*! m33_adc1_ipg_doze - m33_adc1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_adc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_adc2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED10_CLR_m33_adc2_ipg_doze_SHIFT (1U)
/*! m33_adc2_ipg_doze - m33_adc2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_adc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED10_CLR_m33_flexspi1_ipg_doze_SHIFT (2U)
/*! m33_flexspi1_ipg_doze - m33_flexspi1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED10_CLR_m33_flexspi2_ipg_doze_SHIFT (3U)
/*! m33_flexspi2_ipg_doze - m33_flexspi2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED10_CLR_m33_flexio1_ipg_doze_SHIFT (4U)
/*! m33_flexio1_ipg_doze - m33_flexio1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED10_CLR_m33_flexio2_ipg_doze_SHIFT (5U)
/*! m33_flexio2_ipg_doze - m33_flexio2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED10_CLR_m33_lpit1_ipg_doze_SHIFT (6U)
/*! m33_lpit1_ipg_doze - m33_lpit1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpit1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED10_CLR_m33_lpit2_ipg_doze_SHIFT (7U)
/*! m33_lpit2_ipg_doze - m33_lpit2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpit2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED10_CLR_m33_lpit3_ipg_doze_SHIFT (8U)
/*! m33_lpit3_ipg_doze - m33_lpit3_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpit3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_tpm1_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED10_CLR_m33_tpm1_ipg_doze_SHIFT (9U)
/*! m33_tpm1_ipg_doze - m33_tpm1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_tpm1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_tpm2_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED10_CLR_m33_tpm2_ipg_doze_SHIFT (10U)
/*! m33_tpm2_ipg_doze - m33_tpm2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_tpm2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_tpm3_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED10_CLR_m33_tpm3_ipg_doze_SHIFT (11U)
/*! m33_tpm3_ipg_doze - m33_tpm3_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_tpm3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_tpm4_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED10_CLR_m33_tpm4_ipg_doze_SHIFT (12U)
/*! m33_tpm4_ipg_doze - m33_tpm4_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_tpm4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_tpm5_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED10_CLR_m33_tpm5_ipg_doze_SHIFT (13U)
/*! m33_tpm5_ipg_doze - m33_tpm5_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_tpm5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_tpm6_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED10_CLR_m33_tpm6_ipg_doze_SHIFT (14U)
/*! m33_tpm6_ipg_doze - m33_tpm6_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_tpm6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_gpt1_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED10_CLR_m33_gpt1_ipg_doze_SHIFT (15U)
/*! m33_gpt1_ipg_doze - m33_gpt1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_gpt1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_gpt2_ipg_doze_MASK (0x10000U)
#define CCM_GPR_SHARED10_CLR_m33_gpt2_ipg_doze_SHIFT (16U)
/*! m33_gpt2_ipg_doze - m33_gpt2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_gpt2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_can1_ipg_doze_MASK (0x20000U)
#define CCM_GPR_SHARED10_CLR_m33_can1_ipg_doze_SHIFT (17U)
/*! m33_can1_ipg_doze - m33_can1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_can1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_can2_ipg_doze_MASK (0x40000U)
#define CCM_GPR_SHARED10_CLR_m33_can2_ipg_doze_SHIFT (18U)
/*! m33_can2_ipg_doze - m33_can2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_can2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_can3_ipg_doze_MASK (0x80000U)
#define CCM_GPR_SHARED10_CLR_m33_can3_ipg_doze_SHIFT (19U)
/*! m33_can3_ipg_doze - m33_can3_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_can3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart1_ipg_doze_SHIFT (20U)
/*! m33_lpuart1_ipg_doze - m33_lpuart1_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart2_ipg_doze_SHIFT (21U)
/*! m33_lpuart2_ipg_doze - m33_lpuart2_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart3_ipg_doze_SHIFT (22U)
/*! m33_lpuart3_ipg_doze - m33_lpuart3_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart4_ipg_doze_SHIFT (23U)
/*! m33_lpuart4_ipg_doze - m33_lpuart4_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart5_ipg_doze_SHIFT (24U)
/*! m33_lpuart5_ipg_doze - m33_lpuart5_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart6_ipg_doze_SHIFT (25U)
/*! m33_lpuart6_ipg_doze - m33_lpuart6_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart7_ipg_doze_SHIFT (26U)
/*! m33_lpuart7_ipg_doze - m33_lpuart7_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart8_ipg_doze_SHIFT (27U)
/*! m33_lpuart8_ipg_doze - m33_lpuart8_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart9_ipg_doze_SHIFT (28U)
/*! m33_lpuart9_ipg_doze - m33_lpuart9_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart10_ipg_doze_SHIFT (29U)
/*! m33_lpuart10_ipg_doze - m33_lpuart10_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart11_ipg_doze_SHIFT (30U)
/*! m33_lpuart11_ipg_doze - m33_lpuart11_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED10_CLR_m33_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED10_CLR_m33_lpuart12_ipg_doze_SHIFT (31U)
/*! m33_lpuart12_ipg_doze - m33_lpuart12_ipg_doze */
#define CCM_GPR_SHARED10_CLR_m33_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_CLR_m33_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_CLR_m33_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED10_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED10_TOG_m33_adc1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED10_TOG_m33_adc1_ipg_doze_SHIFT (0U)
/*! m33_adc1_ipg_doze - m33_adc1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_adc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_adc2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED10_TOG_m33_adc2_ipg_doze_SHIFT (1U)
/*! m33_adc2_ipg_doze - m33_adc2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_adc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED10_TOG_m33_flexspi1_ipg_doze_SHIFT (2U)
/*! m33_flexspi1_ipg_doze - m33_flexspi1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED10_TOG_m33_flexspi2_ipg_doze_SHIFT (3U)
/*! m33_flexspi2_ipg_doze - m33_flexspi2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED10_TOG_m33_flexio1_ipg_doze_SHIFT (4U)
/*! m33_flexio1_ipg_doze - m33_flexio1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED10_TOG_m33_flexio2_ipg_doze_SHIFT (5U)
/*! m33_flexio2_ipg_doze - m33_flexio2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED10_TOG_m33_lpit1_ipg_doze_SHIFT (6U)
/*! m33_lpit1_ipg_doze - m33_lpit1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpit1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED10_TOG_m33_lpit2_ipg_doze_SHIFT (7U)
/*! m33_lpit2_ipg_doze - m33_lpit2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpit2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED10_TOG_m33_lpit3_ipg_doze_SHIFT (8U)
/*! m33_lpit3_ipg_doze - m33_lpit3_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpit3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_tpm1_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED10_TOG_m33_tpm1_ipg_doze_SHIFT (9U)
/*! m33_tpm1_ipg_doze - m33_tpm1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_tpm1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_tpm2_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED10_TOG_m33_tpm2_ipg_doze_SHIFT (10U)
/*! m33_tpm2_ipg_doze - m33_tpm2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_tpm2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_tpm3_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED10_TOG_m33_tpm3_ipg_doze_SHIFT (11U)
/*! m33_tpm3_ipg_doze - m33_tpm3_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_tpm3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_tpm4_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED10_TOG_m33_tpm4_ipg_doze_SHIFT (12U)
/*! m33_tpm4_ipg_doze - m33_tpm4_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_tpm4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_tpm5_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED10_TOG_m33_tpm5_ipg_doze_SHIFT (13U)
/*! m33_tpm5_ipg_doze - m33_tpm5_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_tpm5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_tpm6_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED10_TOG_m33_tpm6_ipg_doze_SHIFT (14U)
/*! m33_tpm6_ipg_doze - m33_tpm6_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_tpm6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_gpt1_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED10_TOG_m33_gpt1_ipg_doze_SHIFT (15U)
/*! m33_gpt1_ipg_doze - m33_gpt1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_gpt1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_gpt2_ipg_doze_MASK (0x10000U)
#define CCM_GPR_SHARED10_TOG_m33_gpt2_ipg_doze_SHIFT (16U)
/*! m33_gpt2_ipg_doze - m33_gpt2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_gpt2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_can1_ipg_doze_MASK (0x20000U)
#define CCM_GPR_SHARED10_TOG_m33_can1_ipg_doze_SHIFT (17U)
/*! m33_can1_ipg_doze - m33_can1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_can1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_can2_ipg_doze_MASK (0x40000U)
#define CCM_GPR_SHARED10_TOG_m33_can2_ipg_doze_SHIFT (18U)
/*! m33_can2_ipg_doze - m33_can2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_can2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_can3_ipg_doze_MASK (0x80000U)
#define CCM_GPR_SHARED10_TOG_m33_can3_ipg_doze_SHIFT (19U)
/*! m33_can3_ipg_doze - m33_can3_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_can3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart1_ipg_doze_SHIFT (20U)
/*! m33_lpuart1_ipg_doze - m33_lpuart1_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart2_ipg_doze_SHIFT (21U)
/*! m33_lpuart2_ipg_doze - m33_lpuart2_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart3_ipg_doze_SHIFT (22U)
/*! m33_lpuart3_ipg_doze - m33_lpuart3_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart4_ipg_doze_SHIFT (23U)
/*! m33_lpuart4_ipg_doze - m33_lpuart4_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart5_ipg_doze_SHIFT (24U)
/*! m33_lpuart5_ipg_doze - m33_lpuart5_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart6_ipg_doze_SHIFT (25U)
/*! m33_lpuart6_ipg_doze - m33_lpuart6_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart7_ipg_doze_SHIFT (26U)
/*! m33_lpuart7_ipg_doze - m33_lpuart7_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart8_ipg_doze_SHIFT (27U)
/*! m33_lpuart8_ipg_doze - m33_lpuart8_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart9_ipg_doze_SHIFT (28U)
/*! m33_lpuart9_ipg_doze - m33_lpuart9_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart10_ipg_doze_SHIFT (29U)
/*! m33_lpuart10_ipg_doze - m33_lpuart10_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart11_ipg_doze_SHIFT (30U)
/*! m33_lpuart11_ipg_doze - m33_lpuart11_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED10_TOG_m33_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED10_TOG_m33_lpuart12_ipg_doze_SHIFT (31U)
/*! m33_lpuart12_ipg_doze - m33_lpuart12_ipg_doze */
#define CCM_GPR_SHARED10_TOG_m33_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_TOG_m33_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED10_TOG_m33_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED10_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED10_AUTHEN_TZ_USER_MASK     (0x100U)
#define CCM_GPR_SHARED10_AUTHEN_TZ_USER_SHIFT    (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED10_AUTHEN_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED10_AUTHEN_TZ_NS_MASK       (0x200U)
#define CCM_GPR_SHARED10_AUTHEN_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED10_AUTHEN_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED10_AUTHEN_LOCK_TZ_MASK     (0x800U)
#define CCM_GPR_SHARED10_AUTHEN_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED10_AUTHEN_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED10_AUTHEN_LOCK_LIST_MASK   (0x8000U)
#define CCM_GPR_SHARED10_AUTHEN_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED10_AUTHEN_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED10_AUTHEN_WHITE_LIST_MASK  (0xFFFF0000U)
#define CCM_GPR_SHARED10_AUTHEN_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED10_AUTHEN_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED10_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED10_AUTHEN_SET_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED10_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED10_AUTHEN_SET_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED10_AUTHEN_SET_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED10_AUTHEN_SET_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED10_AUTHEN_SET_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED10_AUTHEN_SET_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED10_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED10_AUTHEN_SET_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED10_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED10_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED10_AUTHEN_SET_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED10_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED10_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED10_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED10_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED10_AUTHEN_CLR_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED10_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED10_AUTHEN_CLR_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED10_AUTHEN_CLR_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED10_AUTHEN_CLR_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED10_AUTHEN_CLR_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED10_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED10_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED10_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED10_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED10_AUTHEN_TOG_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED10_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED10_AUTHEN_TOG_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED10_AUTHEN_TOG_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED10_AUTHEN_TOG_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED10_AUTHEN_TOG_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED10_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED10_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED10_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED10_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED10_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED11 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED11_m33_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED11_m33_lpi2c1_ipg_doze_SHIFT (0U)
/*! m33_lpi2c1_ipg_doze - m33_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpi2c1_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED11_m33_lpi2c2_ipg_doze_SHIFT (1U)
/*! m33_lpi2c2_ipg_doze - m33_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpi2c2_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED11_m33_lpi2c3_ipg_doze_SHIFT (2U)
/*! m33_lpi2c3_ipg_doze - m33_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpi2c3_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED11_m33_lpi2c4_ipg_doze_SHIFT (3U)
/*! m33_lpi2c4_ipg_doze - m33_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpi2c4_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED11_m33_lpi2c5_ipg_doze_SHIFT (4U)
/*! m33_lpi2c5_ipg_doze - m33_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpi2c5_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED11_m33_lpi2c6_ipg_doze_SHIFT (5U)
/*! m33_lpi2c6_ipg_doze - m33_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpi2c6_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED11_m33_lpspi1_ipg_doze_SHIFT (6U)
/*! m33_lpspi1_ipg_doze - m33_lpspi1_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpspi1_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED11_m33_lpspi2_ipg_doze_SHIFT (7U)
/*! m33_lpspi2_ipg_doze - m33_lpspi2_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpspi2_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED11_m33_lpspi3_ipg_doze_SHIFT (8U)
/*! m33_lpspi3_ipg_doze - m33_lpspi3_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpspi3_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED11_m33_lpspi4_ipg_doze_SHIFT (9U)
/*! m33_lpspi4_ipg_doze - m33_lpspi4_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpspi4_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED11_m33_lpspi5_ipg_doze_SHIFT (10U)
/*! m33_lpspi5_ipg_doze - m33_lpspi5_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpspi5_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED11_m33_lpspi6_ipg_doze_SHIFT (11U)
/*! m33_lpspi6_ipg_doze - m33_lpspi6_ipg_doze */
#define CCM_GPR_SHARED11_m33_lpspi6_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED11_m33_sinc1_ipg_doze_SHIFT (12U)
/*! m33_sinc1_ipg_doze - m33_sinc1_ipg_doze */
#define CCM_GPR_SHARED11_m33_sinc1_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED11_m33_sinc2_ipg_doze_SHIFT (13U)
/*! m33_sinc2_ipg_doze - m33_sinc2_ipg_doze */
#define CCM_GPR_SHARED11_m33_sinc2_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED11_m33_sinc3_ipg_doze_SHIFT (14U)
/*! m33_sinc3_ipg_doze - m33_sinc3_ipg_doze */
#define CCM_GPR_SHARED11_m33_sinc3_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_m33_mic_ipg_doze_MASK   (0x8000U)
#define CCM_GPR_SHARED11_m33_mic_ipg_doze_SHIFT  (15U)
/*! m33_mic_ipg_doze - m33_mic_ipg_doze */
#define CCM_GPR_SHARED11_m33_mic_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_m33_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_m33_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED11_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED11_SET_m33_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED11_SET_m33_lpi2c1_ipg_doze_SHIFT (0U)
/*! m33_lpi2c1_ipg_doze - m33_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpi2c1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED11_SET_m33_lpi2c2_ipg_doze_SHIFT (1U)
/*! m33_lpi2c2_ipg_doze - m33_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpi2c2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED11_SET_m33_lpi2c3_ipg_doze_SHIFT (2U)
/*! m33_lpi2c3_ipg_doze - m33_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpi2c3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED11_SET_m33_lpi2c4_ipg_doze_SHIFT (3U)
/*! m33_lpi2c4_ipg_doze - m33_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpi2c4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED11_SET_m33_lpi2c5_ipg_doze_SHIFT (4U)
/*! m33_lpi2c5_ipg_doze - m33_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpi2c5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED11_SET_m33_lpi2c6_ipg_doze_SHIFT (5U)
/*! m33_lpi2c6_ipg_doze - m33_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpi2c6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED11_SET_m33_lpspi1_ipg_doze_SHIFT (6U)
/*! m33_lpspi1_ipg_doze - m33_lpspi1_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED11_SET_m33_lpspi2_ipg_doze_SHIFT (7U)
/*! m33_lpspi2_ipg_doze - m33_lpspi2_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED11_SET_m33_lpspi3_ipg_doze_SHIFT (8U)
/*! m33_lpspi3_ipg_doze - m33_lpspi3_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpspi3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED11_SET_m33_lpspi4_ipg_doze_SHIFT (9U)
/*! m33_lpspi4_ipg_doze - m33_lpspi4_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpspi4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED11_SET_m33_lpspi5_ipg_doze_SHIFT (10U)
/*! m33_lpspi5_ipg_doze - m33_lpspi5_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpspi5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED11_SET_m33_lpspi6_ipg_doze_SHIFT (11U)
/*! m33_lpspi6_ipg_doze - m33_lpspi6_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_lpspi6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED11_SET_m33_sinc1_ipg_doze_SHIFT (12U)
/*! m33_sinc1_ipg_doze - m33_sinc1_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_sinc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED11_SET_m33_sinc2_ipg_doze_SHIFT (13U)
/*! m33_sinc2_ipg_doze - m33_sinc2_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_sinc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED11_SET_m33_sinc3_ipg_doze_SHIFT (14U)
/*! m33_sinc3_ipg_doze - m33_sinc3_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_sinc3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_SET_m33_mic_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED11_SET_m33_mic_ipg_doze_SHIFT (15U)
/*! m33_mic_ipg_doze - m33_mic_ipg_doze */
#define CCM_GPR_SHARED11_SET_m33_mic_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_SET_m33_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_SET_m33_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED11_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED11_CLR_m33_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED11_CLR_m33_lpi2c1_ipg_doze_SHIFT (0U)
/*! m33_lpi2c1_ipg_doze - m33_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpi2c1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED11_CLR_m33_lpi2c2_ipg_doze_SHIFT (1U)
/*! m33_lpi2c2_ipg_doze - m33_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpi2c2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED11_CLR_m33_lpi2c3_ipg_doze_SHIFT (2U)
/*! m33_lpi2c3_ipg_doze - m33_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpi2c3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED11_CLR_m33_lpi2c4_ipg_doze_SHIFT (3U)
/*! m33_lpi2c4_ipg_doze - m33_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpi2c4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED11_CLR_m33_lpi2c5_ipg_doze_SHIFT (4U)
/*! m33_lpi2c5_ipg_doze - m33_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpi2c5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED11_CLR_m33_lpi2c6_ipg_doze_SHIFT (5U)
/*! m33_lpi2c6_ipg_doze - m33_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpi2c6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED11_CLR_m33_lpspi1_ipg_doze_SHIFT (6U)
/*! m33_lpspi1_ipg_doze - m33_lpspi1_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED11_CLR_m33_lpspi2_ipg_doze_SHIFT (7U)
/*! m33_lpspi2_ipg_doze - m33_lpspi2_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED11_CLR_m33_lpspi3_ipg_doze_SHIFT (8U)
/*! m33_lpspi3_ipg_doze - m33_lpspi3_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpspi3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED11_CLR_m33_lpspi4_ipg_doze_SHIFT (9U)
/*! m33_lpspi4_ipg_doze - m33_lpspi4_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpspi4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED11_CLR_m33_lpspi5_ipg_doze_SHIFT (10U)
/*! m33_lpspi5_ipg_doze - m33_lpspi5_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpspi5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED11_CLR_m33_lpspi6_ipg_doze_SHIFT (11U)
/*! m33_lpspi6_ipg_doze - m33_lpspi6_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_lpspi6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED11_CLR_m33_sinc1_ipg_doze_SHIFT (12U)
/*! m33_sinc1_ipg_doze - m33_sinc1_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_sinc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED11_CLR_m33_sinc2_ipg_doze_SHIFT (13U)
/*! m33_sinc2_ipg_doze - m33_sinc2_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_sinc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED11_CLR_m33_sinc3_ipg_doze_SHIFT (14U)
/*! m33_sinc3_ipg_doze - m33_sinc3_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_sinc3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_CLR_m33_mic_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED11_CLR_m33_mic_ipg_doze_SHIFT (15U)
/*! m33_mic_ipg_doze - m33_mic_ipg_doze */
#define CCM_GPR_SHARED11_CLR_m33_mic_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_CLR_m33_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_CLR_m33_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED11_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED11_TOG_m33_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED11_TOG_m33_lpi2c1_ipg_doze_SHIFT (0U)
/*! m33_lpi2c1_ipg_doze - m33_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpi2c1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED11_TOG_m33_lpi2c2_ipg_doze_SHIFT (1U)
/*! m33_lpi2c2_ipg_doze - m33_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpi2c2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED11_TOG_m33_lpi2c3_ipg_doze_SHIFT (2U)
/*! m33_lpi2c3_ipg_doze - m33_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpi2c3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED11_TOG_m33_lpi2c4_ipg_doze_SHIFT (3U)
/*! m33_lpi2c4_ipg_doze - m33_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpi2c4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED11_TOG_m33_lpi2c5_ipg_doze_SHIFT (4U)
/*! m33_lpi2c5_ipg_doze - m33_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpi2c5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED11_TOG_m33_lpi2c6_ipg_doze_SHIFT (5U)
/*! m33_lpi2c6_ipg_doze - m33_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpi2c6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED11_TOG_m33_lpspi1_ipg_doze_SHIFT (6U)
/*! m33_lpspi1_ipg_doze - m33_lpspi1_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED11_TOG_m33_lpspi2_ipg_doze_SHIFT (7U)
/*! m33_lpspi2_ipg_doze - m33_lpspi2_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED11_TOG_m33_lpspi3_ipg_doze_SHIFT (8U)
/*! m33_lpspi3_ipg_doze - m33_lpspi3_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpspi3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED11_TOG_m33_lpspi4_ipg_doze_SHIFT (9U)
/*! m33_lpspi4_ipg_doze - m33_lpspi4_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpspi4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED11_TOG_m33_lpspi5_ipg_doze_SHIFT (10U)
/*! m33_lpspi5_ipg_doze - m33_lpspi5_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpspi5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED11_TOG_m33_lpspi6_ipg_doze_SHIFT (11U)
/*! m33_lpspi6_ipg_doze - m33_lpspi6_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_lpspi6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED11_TOG_m33_sinc1_ipg_doze_SHIFT (12U)
/*! m33_sinc1_ipg_doze - m33_sinc1_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_sinc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED11_TOG_m33_sinc2_ipg_doze_SHIFT (13U)
/*! m33_sinc2_ipg_doze - m33_sinc2_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_sinc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED11_TOG_m33_sinc3_ipg_doze_SHIFT (14U)
/*! m33_sinc3_ipg_doze - m33_sinc3_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_sinc3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED11_TOG_m33_mic_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED11_TOG_m33_mic_ipg_doze_SHIFT (15U)
/*! m33_mic_ipg_doze - m33_mic_ipg_doze */
#define CCM_GPR_SHARED11_TOG_m33_mic_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_TOG_m33_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED11_TOG_m33_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED11_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED11_AUTHEN_TZ_USER_MASK     (0x100U)
#define CCM_GPR_SHARED11_AUTHEN_TZ_USER_SHIFT    (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED11_AUTHEN_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED11_AUTHEN_TZ_NS_MASK       (0x200U)
#define CCM_GPR_SHARED11_AUTHEN_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED11_AUTHEN_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED11_AUTHEN_LOCK_TZ_MASK     (0x800U)
#define CCM_GPR_SHARED11_AUTHEN_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED11_AUTHEN_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED11_AUTHEN_LOCK_LIST_MASK   (0x8000U)
#define CCM_GPR_SHARED11_AUTHEN_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED11_AUTHEN_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED11_AUTHEN_WHITE_LIST_MASK  (0xFFFF0000U)
#define CCM_GPR_SHARED11_AUTHEN_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED11_AUTHEN_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED11_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED11_AUTHEN_SET_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED11_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED11_AUTHEN_SET_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED11_AUTHEN_SET_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED11_AUTHEN_SET_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED11_AUTHEN_SET_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED11_AUTHEN_SET_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED11_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED11_AUTHEN_SET_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED11_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED11_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED11_AUTHEN_SET_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED11_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED11_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED11_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED11_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED11_AUTHEN_CLR_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED11_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED11_AUTHEN_CLR_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED11_AUTHEN_CLR_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED11_AUTHEN_CLR_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED11_AUTHEN_CLR_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED11_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED11_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED11_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED11_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED11_AUTHEN_TOG_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED11_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED11_AUTHEN_TOG_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED11_AUTHEN_TOG_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED11_AUTHEN_TOG_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED11_AUTHEN_TOG_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED11_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED11_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED11_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED11_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED11_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED12 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED12_m7_cm7_ipg_stop_MASK    (0x1U)
#define CCM_GPR_SHARED12_m7_cm7_ipg_stop_SHIFT   (0U)
/*! m7_cm7_ipg_stop - m7_cm7_ipg_stop */
#define CCM_GPR_SHARED12_m7_cm7_ipg_stop(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_cm33_ipg_stop_MASK   (0x2U)
#define CCM_GPR_SHARED12_m7_cm33_ipg_stop_SHIFT  (1U)
/*! m7_cm33_ipg_stop - m7_cm33_ipg_stop */
#define CCM_GPR_SHARED12_m7_cm33_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_edma3_ipg_stop_MASK  (0x4U)
#define CCM_GPR_SHARED12_m7_edma3_ipg_stop_SHIFT (2U)
/*! m7_edma3_ipg_stop - m7_edma3_ipg_stop */
#define CCM_GPR_SHARED12_m7_edma3_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_edma4_ipg_stop_MASK  (0x8U)
#define CCM_GPR_SHARED12_m7_edma4_ipg_stop_SHIFT (3U)
/*! m7_edma4_ipg_stop - m7_edma4_ipg_stop */
#define CCM_GPR_SHARED12_m7_edma4_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_netc_ipg_stop_MASK   (0x10U)
#define CCM_GPR_SHARED12_m7_netc_ipg_stop_SHIFT  (4U)
/*! m7_netc_ipg_stop - m7_netc_ipg_stop */
#define CCM_GPR_SHARED12_m7_netc_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED12_m7_sim_aon_ipg_stop_SHIFT (8U)
/*! m7_sim_aon_ipg_stop - m7_sim_aon_ipg_stop */
#define CCM_GPR_SHARED12_m7_sim_aon_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_adc1_ipg_stop_MASK   (0x200U)
#define CCM_GPR_SHARED12_m7_adc1_ipg_stop_SHIFT  (9U)
/*! m7_adc1_ipg_stop - m7_adc1_ipg_stop */
#define CCM_GPR_SHARED12_m7_adc1_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_adc2_ipg_stop_MASK   (0x400U)
#define CCM_GPR_SHARED12_m7_adc2_ipg_stop_SHIFT  (10U)
/*! m7_adc2_ipg_stop - m7_adc2_ipg_stop */
#define CCM_GPR_SHARED12_m7_adc2_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED12_m7_flexspi1_ipg_stop_SHIFT (11U)
/*! m7_flexspi1_ipg_stop - m7_flexspi1_ipg_stop */
#define CCM_GPR_SHARED12_m7_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED12_m7_flexspi2_ipg_stop_SHIFT (12U)
/*! m7_flexspi2_ipg_stop - m7_flexspi2_ipg_stop */
#define CCM_GPR_SHARED12_m7_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_trdc_ipg_stop_MASK   (0x2000U)
#define CCM_GPR_SHARED12_m7_trdc_ipg_stop_SHIFT  (13U)
/*! m7_trdc_ipg_stop - m7_trdc_ipg_stop */
#define CCM_GPR_SHARED12_m7_trdc_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_semc_ipg_stop_MASK   (0x4000U)
#define CCM_GPR_SHARED12_m7_semc_ipg_stop_SHIFT  (14U)
/*! m7_semc_ipg_stop - m7_semc_ipg_stop */
#define CCM_GPR_SHARED12_m7_semc_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_iee_ipg_stop_MASK    (0x8000U)
#define CCM_GPR_SHARED12_m7_iee_ipg_stop_SHIFT   (15U)
/*! m7_iee_ipg_stop - m7_iee_ipg_stop */
#define CCM_GPR_SHARED12_m7_iee_ipg_stop(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_gpio1_ipg_stop_MASK  (0x10000U)
#define CCM_GPR_SHARED12_m7_gpio1_ipg_stop_SHIFT (16U)
/*! m7_gpio1_ipg_stop - m7_gpio1_ipg_stop */
#define CCM_GPR_SHARED12_m7_gpio1_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_gpio2_ipg_stop_MASK  (0x20000U)
#define CCM_GPR_SHARED12_m7_gpio2_ipg_stop_SHIFT (17U)
/*! m7_gpio2_ipg_stop - m7_gpio2_ipg_stop */
#define CCM_GPR_SHARED12_m7_gpio2_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_gpio3_ipg_stop_MASK  (0x40000U)
#define CCM_GPR_SHARED12_m7_gpio3_ipg_stop_SHIFT (18U)
/*! m7_gpio3_ipg_stop - m7_gpio3_ipg_stop */
#define CCM_GPR_SHARED12_m7_gpio3_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_gpio4_ipg_stop_MASK  (0x80000U)
#define CCM_GPR_SHARED12_m7_gpio4_ipg_stop_SHIFT (19U)
/*! m7_gpio4_ipg_stop - m7_gpio4_ipg_stop */
#define CCM_GPR_SHARED12_m7_gpio4_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_gpio5_ipg_stop_MASK  (0x100000U)
#define CCM_GPR_SHARED12_m7_gpio5_ipg_stop_SHIFT (20U)
/*! m7_gpio5_ipg_stop - m7_gpio5_ipg_stop */
#define CCM_GPR_SHARED12_m7_gpio5_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_gpio6_ipg_stop_MASK  (0x200000U)
#define CCM_GPR_SHARED12_m7_gpio6_ipg_stop_SHIFT (21U)
/*! m7_gpio6_ipg_stop - m7_gpio6_ipg_stop */
#define CCM_GPR_SHARED12_m7_gpio6_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED12_m7_flexio1_ipg_stop_SHIFT (22U)
/*! m7_flexio1_ipg_stop - m7_flexio1_ipg_stop */
#define CCM_GPR_SHARED12_m7_flexio1_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED12_m7_flexio2_ipg_stop_SHIFT (23U)
/*! m7_flexio2_ipg_stop - m7_flexio2_ipg_stop */
#define CCM_GPR_SHARED12_m7_flexio2_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_can1_ipg_stop_MASK   (0x1000000U)
#define CCM_GPR_SHARED12_m7_can1_ipg_stop_SHIFT  (24U)
/*! m7_can1_ipg_stop - m7_can1_ipg_stop */
#define CCM_GPR_SHARED12_m7_can1_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_can2_ipg_stop_MASK   (0x2000000U)
#define CCM_GPR_SHARED12_m7_can2_ipg_stop_SHIFT  (25U)
/*! m7_can2_ipg_stop - m7_can2_ipg_stop */
#define CCM_GPR_SHARED12_m7_can2_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_can3_ipg_stop_MASK   (0x4000000U)
#define CCM_GPR_SHARED12_m7_can3_ipg_stop_SHIFT  (26U)
/*! m7_can3_ipg_stop - m7_can3_ipg_stop */
#define CCM_GPR_SHARED12_m7_can3_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED12_m7_lpuart1_ipg_stop_SHIFT (27U)
/*! m7_lpuart1_ipg_stop - m7_lpuart1_ipg_stop */
#define CCM_GPR_SHARED12_m7_lpuart1_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED12_m7_lpuart2_ipg_stop_SHIFT (28U)
/*! m7_lpuart2_ipg_stop - m7_lpuart2_ipg_stop */
#define CCM_GPR_SHARED12_m7_lpuart2_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED12_m7_lpuart3_ipg_stop_SHIFT (29U)
/*! m7_lpuart3_ipg_stop - m7_lpuart3_ipg_stop */
#define CCM_GPR_SHARED12_m7_lpuart3_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED12_m7_lpuart4_ipg_stop_SHIFT (30U)
/*! m7_lpuart4_ipg_stop - m7_lpuart4_ipg_stop */
#define CCM_GPR_SHARED12_m7_lpuart4_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_m7_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED12_m7_lpuart5_ipg_stop_SHIFT (31U)
/*! m7_lpuart5_ipg_stop - m7_lpuart5_ipg_stop */
#define CCM_GPR_SHARED12_m7_lpuart5_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_m7_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_m7_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED12_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED12_SET_m7_cm7_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED12_SET_m7_cm7_ipg_stop_SHIFT (0U)
/*! m7_cm7_ipg_stop - m7_cm7_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_cm7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_cm33_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED12_SET_m7_cm33_ipg_stop_SHIFT (1U)
/*! m7_cm33_ipg_stop - m7_cm33_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_cm33_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_edma3_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED12_SET_m7_edma3_ipg_stop_SHIFT (2U)
/*! m7_edma3_ipg_stop - m7_edma3_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_edma3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_edma4_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED12_SET_m7_edma4_ipg_stop_SHIFT (3U)
/*! m7_edma4_ipg_stop - m7_edma4_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_edma4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_netc_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED12_SET_m7_netc_ipg_stop_SHIFT (4U)
/*! m7_netc_ipg_stop - m7_netc_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_netc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED12_SET_m7_sim_aon_ipg_stop_SHIFT (8U)
/*! m7_sim_aon_ipg_stop - m7_sim_aon_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_sim_aon_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_adc1_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED12_SET_m7_adc1_ipg_stop_SHIFT (9U)
/*! m7_adc1_ipg_stop - m7_adc1_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_adc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_adc2_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED12_SET_m7_adc2_ipg_stop_SHIFT (10U)
/*! m7_adc2_ipg_stop - m7_adc2_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_adc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED12_SET_m7_flexspi1_ipg_stop_SHIFT (11U)
/*! m7_flexspi1_ipg_stop - m7_flexspi1_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED12_SET_m7_flexspi2_ipg_stop_SHIFT (12U)
/*! m7_flexspi2_ipg_stop - m7_flexspi2_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_trdc_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED12_SET_m7_trdc_ipg_stop_SHIFT (13U)
/*! m7_trdc_ipg_stop - m7_trdc_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_trdc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_semc_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED12_SET_m7_semc_ipg_stop_SHIFT (14U)
/*! m7_semc_ipg_stop - m7_semc_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_semc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_iee_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED12_SET_m7_iee_ipg_stop_SHIFT (15U)
/*! m7_iee_ipg_stop - m7_iee_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_iee_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_gpio1_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED12_SET_m7_gpio1_ipg_stop_SHIFT (16U)
/*! m7_gpio1_ipg_stop - m7_gpio1_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_gpio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_gpio2_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED12_SET_m7_gpio2_ipg_stop_SHIFT (17U)
/*! m7_gpio2_ipg_stop - m7_gpio2_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_gpio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_gpio3_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED12_SET_m7_gpio3_ipg_stop_SHIFT (18U)
/*! m7_gpio3_ipg_stop - m7_gpio3_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_gpio3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_gpio4_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED12_SET_m7_gpio4_ipg_stop_SHIFT (19U)
/*! m7_gpio4_ipg_stop - m7_gpio4_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_gpio4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_gpio5_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED12_SET_m7_gpio5_ipg_stop_SHIFT (20U)
/*! m7_gpio5_ipg_stop - m7_gpio5_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_gpio5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_gpio6_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED12_SET_m7_gpio6_ipg_stop_SHIFT (21U)
/*! m7_gpio6_ipg_stop - m7_gpio6_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_gpio6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED12_SET_m7_flexio1_ipg_stop_SHIFT (22U)
/*! m7_flexio1_ipg_stop - m7_flexio1_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_flexio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED12_SET_m7_flexio2_ipg_stop_SHIFT (23U)
/*! m7_flexio2_ipg_stop - m7_flexio2_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_flexio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_can1_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED12_SET_m7_can1_ipg_stop_SHIFT (24U)
/*! m7_can1_ipg_stop - m7_can1_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_can1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_can2_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED12_SET_m7_can2_ipg_stop_SHIFT (25U)
/*! m7_can2_ipg_stop - m7_can2_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_can2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_can3_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED12_SET_m7_can3_ipg_stop_SHIFT (26U)
/*! m7_can3_ipg_stop - m7_can3_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_can3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED12_SET_m7_lpuart1_ipg_stop_SHIFT (27U)
/*! m7_lpuart1_ipg_stop - m7_lpuart1_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_lpuart1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED12_SET_m7_lpuart2_ipg_stop_SHIFT (28U)
/*! m7_lpuart2_ipg_stop - m7_lpuart2_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_lpuart2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED12_SET_m7_lpuart3_ipg_stop_SHIFT (29U)
/*! m7_lpuart3_ipg_stop - m7_lpuart3_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_lpuart3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED12_SET_m7_lpuart4_ipg_stop_SHIFT (30U)
/*! m7_lpuart4_ipg_stop - m7_lpuart4_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_lpuart4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_SET_m7_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED12_SET_m7_lpuart5_ipg_stop_SHIFT (31U)
/*! m7_lpuart5_ipg_stop - m7_lpuart5_ipg_stop */
#define CCM_GPR_SHARED12_SET_m7_lpuart5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_SET_m7_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_SET_m7_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED12_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED12_CLR_m7_cm7_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED12_CLR_m7_cm7_ipg_stop_SHIFT (0U)
/*! m7_cm7_ipg_stop - m7_cm7_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_cm7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_cm33_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED12_CLR_m7_cm33_ipg_stop_SHIFT (1U)
/*! m7_cm33_ipg_stop - m7_cm33_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_cm33_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_edma3_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED12_CLR_m7_edma3_ipg_stop_SHIFT (2U)
/*! m7_edma3_ipg_stop - m7_edma3_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_edma3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_edma4_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED12_CLR_m7_edma4_ipg_stop_SHIFT (3U)
/*! m7_edma4_ipg_stop - m7_edma4_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_edma4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_netc_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED12_CLR_m7_netc_ipg_stop_SHIFT (4U)
/*! m7_netc_ipg_stop - m7_netc_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_netc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED12_CLR_m7_sim_aon_ipg_stop_SHIFT (8U)
/*! m7_sim_aon_ipg_stop - m7_sim_aon_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_sim_aon_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_adc1_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED12_CLR_m7_adc1_ipg_stop_SHIFT (9U)
/*! m7_adc1_ipg_stop - m7_adc1_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_adc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_adc2_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED12_CLR_m7_adc2_ipg_stop_SHIFT (10U)
/*! m7_adc2_ipg_stop - m7_adc2_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_adc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED12_CLR_m7_flexspi1_ipg_stop_SHIFT (11U)
/*! m7_flexspi1_ipg_stop - m7_flexspi1_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED12_CLR_m7_flexspi2_ipg_stop_SHIFT (12U)
/*! m7_flexspi2_ipg_stop - m7_flexspi2_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_trdc_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED12_CLR_m7_trdc_ipg_stop_SHIFT (13U)
/*! m7_trdc_ipg_stop - m7_trdc_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_trdc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_semc_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED12_CLR_m7_semc_ipg_stop_SHIFT (14U)
/*! m7_semc_ipg_stop - m7_semc_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_semc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_iee_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED12_CLR_m7_iee_ipg_stop_SHIFT (15U)
/*! m7_iee_ipg_stop - m7_iee_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_iee_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_gpio1_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED12_CLR_m7_gpio1_ipg_stop_SHIFT (16U)
/*! m7_gpio1_ipg_stop - m7_gpio1_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_gpio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_gpio2_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED12_CLR_m7_gpio2_ipg_stop_SHIFT (17U)
/*! m7_gpio2_ipg_stop - m7_gpio2_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_gpio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_gpio3_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED12_CLR_m7_gpio3_ipg_stop_SHIFT (18U)
/*! m7_gpio3_ipg_stop - m7_gpio3_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_gpio3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_gpio4_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED12_CLR_m7_gpio4_ipg_stop_SHIFT (19U)
/*! m7_gpio4_ipg_stop - m7_gpio4_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_gpio4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_gpio5_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED12_CLR_m7_gpio5_ipg_stop_SHIFT (20U)
/*! m7_gpio5_ipg_stop - m7_gpio5_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_gpio5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_gpio6_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED12_CLR_m7_gpio6_ipg_stop_SHIFT (21U)
/*! m7_gpio6_ipg_stop - m7_gpio6_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_gpio6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED12_CLR_m7_flexio1_ipg_stop_SHIFT (22U)
/*! m7_flexio1_ipg_stop - m7_flexio1_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_flexio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED12_CLR_m7_flexio2_ipg_stop_SHIFT (23U)
/*! m7_flexio2_ipg_stop - m7_flexio2_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_flexio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_can1_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED12_CLR_m7_can1_ipg_stop_SHIFT (24U)
/*! m7_can1_ipg_stop - m7_can1_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_can1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_can2_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED12_CLR_m7_can2_ipg_stop_SHIFT (25U)
/*! m7_can2_ipg_stop - m7_can2_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_can2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_can3_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED12_CLR_m7_can3_ipg_stop_SHIFT (26U)
/*! m7_can3_ipg_stop - m7_can3_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_can3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED12_CLR_m7_lpuart1_ipg_stop_SHIFT (27U)
/*! m7_lpuart1_ipg_stop - m7_lpuart1_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_lpuart1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED12_CLR_m7_lpuart2_ipg_stop_SHIFT (28U)
/*! m7_lpuart2_ipg_stop - m7_lpuart2_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_lpuart2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED12_CLR_m7_lpuart3_ipg_stop_SHIFT (29U)
/*! m7_lpuart3_ipg_stop - m7_lpuart3_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_lpuart3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED12_CLR_m7_lpuart4_ipg_stop_SHIFT (30U)
/*! m7_lpuart4_ipg_stop - m7_lpuart4_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_lpuart4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_CLR_m7_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED12_CLR_m7_lpuart5_ipg_stop_SHIFT (31U)
/*! m7_lpuart5_ipg_stop - m7_lpuart5_ipg_stop */
#define CCM_GPR_SHARED12_CLR_m7_lpuart5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_CLR_m7_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_CLR_m7_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED12_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED12_TOG_m7_cm7_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED12_TOG_m7_cm7_ipg_stop_SHIFT (0U)
/*! m7_cm7_ipg_stop - m7_cm7_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_cm7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_cm7_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_cm7_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_cm33_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED12_TOG_m7_cm33_ipg_stop_SHIFT (1U)
/*! m7_cm33_ipg_stop - m7_cm33_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_cm33_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_cm33_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_cm33_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_edma3_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED12_TOG_m7_edma3_ipg_stop_SHIFT (2U)
/*! m7_edma3_ipg_stop - m7_edma3_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_edma3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_edma3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_edma3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_edma4_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED12_TOG_m7_edma4_ipg_stop_SHIFT (3U)
/*! m7_edma4_ipg_stop - m7_edma4_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_edma4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_edma4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_edma4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_netc_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED12_TOG_m7_netc_ipg_stop_SHIFT (4U)
/*! m7_netc_ipg_stop - m7_netc_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_netc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_netc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_netc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_sim_aon_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED12_TOG_m7_sim_aon_ipg_stop_SHIFT (8U)
/*! m7_sim_aon_ipg_stop - m7_sim_aon_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_sim_aon_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_sim_aon_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_sim_aon_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_adc1_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED12_TOG_m7_adc1_ipg_stop_SHIFT (9U)
/*! m7_adc1_ipg_stop - m7_adc1_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_adc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_adc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_adc1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_adc2_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED12_TOG_m7_adc2_ipg_stop_SHIFT (10U)
/*! m7_adc2_ipg_stop - m7_adc2_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_adc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_adc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_adc2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_flexspi1_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED12_TOG_m7_flexspi1_ipg_stop_SHIFT (11U)
/*! m7_flexspi1_ipg_stop - m7_flexspi1_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_flexspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_flexspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_flexspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_flexspi2_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED12_TOG_m7_flexspi2_ipg_stop_SHIFT (12U)
/*! m7_flexspi2_ipg_stop - m7_flexspi2_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_flexspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_flexspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_flexspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_trdc_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED12_TOG_m7_trdc_ipg_stop_SHIFT (13U)
/*! m7_trdc_ipg_stop - m7_trdc_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_trdc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_trdc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_trdc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_semc_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED12_TOG_m7_semc_ipg_stop_SHIFT (14U)
/*! m7_semc_ipg_stop - m7_semc_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_semc_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_semc_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_semc_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_iee_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED12_TOG_m7_iee_ipg_stop_SHIFT (15U)
/*! m7_iee_ipg_stop - m7_iee_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_iee_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_iee_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_iee_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_gpio1_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED12_TOG_m7_gpio1_ipg_stop_SHIFT (16U)
/*! m7_gpio1_ipg_stop - m7_gpio1_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_gpio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_gpio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_gpio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_gpio2_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED12_TOG_m7_gpio2_ipg_stop_SHIFT (17U)
/*! m7_gpio2_ipg_stop - m7_gpio2_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_gpio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_gpio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_gpio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_gpio3_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED12_TOG_m7_gpio3_ipg_stop_SHIFT (18U)
/*! m7_gpio3_ipg_stop - m7_gpio3_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_gpio3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_gpio3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_gpio3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_gpio4_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED12_TOG_m7_gpio4_ipg_stop_SHIFT (19U)
/*! m7_gpio4_ipg_stop - m7_gpio4_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_gpio4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_gpio4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_gpio4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_gpio5_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED12_TOG_m7_gpio5_ipg_stop_SHIFT (20U)
/*! m7_gpio5_ipg_stop - m7_gpio5_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_gpio5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_gpio5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_gpio5_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_gpio6_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED12_TOG_m7_gpio6_ipg_stop_SHIFT (21U)
/*! m7_gpio6_ipg_stop - m7_gpio6_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_gpio6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_gpio6_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_gpio6_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_flexio1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED12_TOG_m7_flexio1_ipg_stop_SHIFT (22U)
/*! m7_flexio1_ipg_stop - m7_flexio1_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_flexio1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_flexio1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_flexio1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_flexio2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED12_TOG_m7_flexio2_ipg_stop_SHIFT (23U)
/*! m7_flexio2_ipg_stop - m7_flexio2_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_flexio2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_flexio2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_flexio2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_can1_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED12_TOG_m7_can1_ipg_stop_SHIFT (24U)
/*! m7_can1_ipg_stop - m7_can1_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_can1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_can1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_can1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_can2_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED12_TOG_m7_can2_ipg_stop_SHIFT (25U)
/*! m7_can2_ipg_stop - m7_can2_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_can2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_can2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_can2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_can3_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED12_TOG_m7_can3_ipg_stop_SHIFT (26U)
/*! m7_can3_ipg_stop - m7_can3_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_can3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_can3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_can3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_lpuart1_ipg_stop_MASK (0x8000000U)
#define CCM_GPR_SHARED12_TOG_m7_lpuart1_ipg_stop_SHIFT (27U)
/*! m7_lpuart1_ipg_stop - m7_lpuart1_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_lpuart1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_lpuart1_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_lpuart1_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_lpuart2_ipg_stop_MASK (0x10000000U)
#define CCM_GPR_SHARED12_TOG_m7_lpuart2_ipg_stop_SHIFT (28U)
/*! m7_lpuart2_ipg_stop - m7_lpuart2_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_lpuart2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_lpuart2_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_lpuart2_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_lpuart3_ipg_stop_MASK (0x20000000U)
#define CCM_GPR_SHARED12_TOG_m7_lpuart3_ipg_stop_SHIFT (29U)
/*! m7_lpuart3_ipg_stop - m7_lpuart3_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_lpuart3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_lpuart3_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_lpuart3_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_lpuart4_ipg_stop_MASK (0x40000000U)
#define CCM_GPR_SHARED12_TOG_m7_lpuart4_ipg_stop_SHIFT (30U)
/*! m7_lpuart4_ipg_stop - m7_lpuart4_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_lpuart4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_lpuart4_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_lpuart4_ipg_stop_MASK)

#define CCM_GPR_SHARED12_TOG_m7_lpuart5_ipg_stop_MASK (0x80000000U)
#define CCM_GPR_SHARED12_TOG_m7_lpuart5_ipg_stop_SHIFT (31U)
/*! m7_lpuart5_ipg_stop - m7_lpuart5_ipg_stop */
#define CCM_GPR_SHARED12_TOG_m7_lpuart5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_TOG_m7_lpuart5_ipg_stop_SHIFT)) & CCM_GPR_SHARED12_TOG_m7_lpuart5_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED12_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED12_AUTHEN_TZ_USER_MASK     (0x100U)
#define CCM_GPR_SHARED12_AUTHEN_TZ_USER_SHIFT    (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED12_AUTHEN_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED12_AUTHEN_TZ_NS_MASK       (0x200U)
#define CCM_GPR_SHARED12_AUTHEN_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED12_AUTHEN_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED12_AUTHEN_LOCK_TZ_MASK     (0x800U)
#define CCM_GPR_SHARED12_AUTHEN_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED12_AUTHEN_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED12_AUTHEN_LOCK_LIST_MASK   (0x8000U)
#define CCM_GPR_SHARED12_AUTHEN_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED12_AUTHEN_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED12_AUTHEN_WHITE_LIST_MASK  (0xFFFF0000U)
#define CCM_GPR_SHARED12_AUTHEN_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED12_AUTHEN_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED12_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED12_AUTHEN_SET_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED12_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED12_AUTHEN_SET_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED12_AUTHEN_SET_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED12_AUTHEN_SET_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED12_AUTHEN_SET_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED12_AUTHEN_SET_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED12_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED12_AUTHEN_SET_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED12_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED12_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED12_AUTHEN_SET_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED12_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED12_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED12_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED12_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED12_AUTHEN_CLR_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED12_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED12_AUTHEN_CLR_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED12_AUTHEN_CLR_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED12_AUTHEN_CLR_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED12_AUTHEN_CLR_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED12_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED12_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED12_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED12_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED12_AUTHEN_TOG_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED12_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED12_AUTHEN_TOG_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED12_AUTHEN_TOG_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED12_AUTHEN_TOG_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED12_AUTHEN_TOG_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED12_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED12_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED12_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED12_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED12_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED13 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED13_m7_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED13_m7_lpuart6_ipg_stop_SHIFT (0U)
/*! m7_lpuart6_ipg_stop - m7_lpuart6_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart6_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED13_m7_lpuart7_ipg_stop_SHIFT (1U)
/*! m7_lpuart7_ipg_stop - m7_lpuart7_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart7_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED13_m7_lpuart8_ipg_stop_SHIFT (2U)
/*! m7_lpuart8_ipg_stop - m7_lpuart8_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart8_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED13_m7_lpuart9_ipg_stop_SHIFT (3U)
/*! m7_lpuart9_ipg_stop - m7_lpuart9_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart9_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED13_m7_lpuart10_ipg_stop_SHIFT (4U)
/*! m7_lpuart10_ipg_stop - m7_lpuart10_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED13_m7_lpuart11_ipg_stop_SHIFT (5U)
/*! m7_lpuart11_ipg_stop - m7_lpuart11_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED13_m7_lpuart12_ipg_stop_SHIFT (6U)
/*! m7_lpuart12_ipg_stop - m7_lpuart12_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED13_m7_lpi2c1_ipg_stop_SHIFT (7U)
/*! m7_lpi2c1_ipg_stop - m7_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpi2c1_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED13_m7_lpi2c2_ipg_stop_SHIFT (8U)
/*! m7_lpi2c2_ipg_stop - m7_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpi2c2_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED13_m7_lpi2c3_ipg_stop_SHIFT (9U)
/*! m7_lpi2c3_ipg_stop - m7_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpi2c3_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED13_m7_lpi2c4_ipg_stop_SHIFT (10U)
/*! m7_lpi2c4_ipg_stop - m7_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpi2c4_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED13_m7_lpi2c5_ipg_stop_SHIFT (11U)
/*! m7_lpi2c5_ipg_stop - m7_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpi2c5_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED13_m7_lpi2c6_ipg_stop_SHIFT (12U)
/*! m7_lpi2c6_ipg_stop - m7_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpi2c6_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED13_m7_lpspi1_ipg_stop_SHIFT (13U)
/*! m7_lpspi1_ipg_stop - m7_lpspi1_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpspi1_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED13_m7_lpspi2_ipg_stop_SHIFT (14U)
/*! m7_lpspi2_ipg_stop - m7_lpspi2_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpspi2_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED13_m7_lpspi3_ipg_stop_SHIFT (15U)
/*! m7_lpspi3_ipg_stop - m7_lpspi3_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpspi3_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED13_m7_lpspi4_ipg_stop_SHIFT (16U)
/*! m7_lpspi4_ipg_stop - m7_lpspi4_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpspi4_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED13_m7_lpspi5_ipg_stop_SHIFT (17U)
/*! m7_lpspi5_ipg_stop - m7_lpspi5_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpspi5_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED13_m7_lpspi6_ipg_stop_SHIFT (18U)
/*! m7_lpspi6_ipg_stop - m7_lpspi6_ipg_stop */
#define CCM_GPR_SHARED13_m7_lpspi6_ipg_stop(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sinc1_ipg_stop_MASK  (0x80000U)
#define CCM_GPR_SHARED13_m7_sinc1_ipg_stop_SHIFT (19U)
/*! m7_sinc1_ipg_stop - m7_sinc1_ipg_stop */
#define CCM_GPR_SHARED13_m7_sinc1_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sinc2_ipg_stop_MASK  (0x100000U)
#define CCM_GPR_SHARED13_m7_sinc2_ipg_stop_SHIFT (20U)
/*! m7_sinc2_ipg_stop - m7_sinc2_ipg_stop */
#define CCM_GPR_SHARED13_m7_sinc2_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sinc3_ipg_stop_MASK  (0x200000U)
#define CCM_GPR_SHARED13_m7_sinc3_ipg_stop_SHIFT (21U)
/*! m7_sinc3_ipg_stop - m7_sinc3_ipg_stop */
#define CCM_GPR_SHARED13_m7_sinc3_ipg_stop(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sai1_ipg_stop_MASK   (0x400000U)
#define CCM_GPR_SHARED13_m7_sai1_ipg_stop_SHIFT  (22U)
/*! m7_sai1_ipg_stop - m7_sai1_ipg_stop */
#define CCM_GPR_SHARED13_m7_sai1_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sai2_ipg_stop_MASK   (0x800000U)
#define CCM_GPR_SHARED13_m7_sai2_ipg_stop_SHIFT  (23U)
/*! m7_sai2_ipg_stop - m7_sai2_ipg_stop */
#define CCM_GPR_SHARED13_m7_sai2_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sai3_ipg_stop_MASK   (0x1000000U)
#define CCM_GPR_SHARED13_m7_sai3_ipg_stop_SHIFT  (24U)
/*! m7_sai3_ipg_stop - m7_sai3_ipg_stop */
#define CCM_GPR_SHARED13_m7_sai3_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_sai4_ipg_stop_MASK   (0x2000000U)
#define CCM_GPR_SHARED13_m7_sai4_ipg_stop_SHIFT  (25U)
/*! m7_sai4_ipg_stop - m7_sai4_ipg_stop */
#define CCM_GPR_SHARED13_m7_sai4_ipg_stop(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_m7_mic_ipg_stop_MASK    (0x4000000U)
#define CCM_GPR_SHARED13_m7_mic_ipg_stop_SHIFT   (26U)
/*! m7_mic_ipg_stop - m7_mic_ipg_stop */
#define CCM_GPR_SHARED13_m7_mic_ipg_stop(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_m7_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_m7_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED13_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED13_SET_m7_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED13_SET_m7_lpuart6_ipg_stop_SHIFT (0U)
/*! m7_lpuart6_ipg_stop - m7_lpuart6_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED13_SET_m7_lpuart7_ipg_stop_SHIFT (1U)
/*! m7_lpuart7_ipg_stop - m7_lpuart7_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart7_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED13_SET_m7_lpuart8_ipg_stop_SHIFT (2U)
/*! m7_lpuart8_ipg_stop - m7_lpuart8_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart8_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED13_SET_m7_lpuart9_ipg_stop_SHIFT (3U)
/*! m7_lpuart9_ipg_stop - m7_lpuart9_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart9_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED13_SET_m7_lpuart10_ipg_stop_SHIFT (4U)
/*! m7_lpuart10_ipg_stop - m7_lpuart10_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED13_SET_m7_lpuart11_ipg_stop_SHIFT (5U)
/*! m7_lpuart11_ipg_stop - m7_lpuart11_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED13_SET_m7_lpuart12_ipg_stop_SHIFT (6U)
/*! m7_lpuart12_ipg_stop - m7_lpuart12_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED13_SET_m7_lpi2c1_ipg_stop_SHIFT (7U)
/*! m7_lpi2c1_ipg_stop - m7_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpi2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED13_SET_m7_lpi2c2_ipg_stop_SHIFT (8U)
/*! m7_lpi2c2_ipg_stop - m7_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpi2c2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED13_SET_m7_lpi2c3_ipg_stop_SHIFT (9U)
/*! m7_lpi2c3_ipg_stop - m7_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpi2c3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED13_SET_m7_lpi2c4_ipg_stop_SHIFT (10U)
/*! m7_lpi2c4_ipg_stop - m7_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpi2c4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED13_SET_m7_lpi2c5_ipg_stop_SHIFT (11U)
/*! m7_lpi2c5_ipg_stop - m7_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpi2c5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED13_SET_m7_lpi2c6_ipg_stop_SHIFT (12U)
/*! m7_lpi2c6_ipg_stop - m7_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpi2c6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED13_SET_m7_lpspi1_ipg_stop_SHIFT (13U)
/*! m7_lpspi1_ipg_stop - m7_lpspi1_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED13_SET_m7_lpspi2_ipg_stop_SHIFT (14U)
/*! m7_lpspi2_ipg_stop - m7_lpspi2_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED13_SET_m7_lpspi3_ipg_stop_SHIFT (15U)
/*! m7_lpspi3_ipg_stop - m7_lpspi3_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED13_SET_m7_lpspi4_ipg_stop_SHIFT (16U)
/*! m7_lpspi4_ipg_stop - m7_lpspi4_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpspi4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED13_SET_m7_lpspi5_ipg_stop_SHIFT (17U)
/*! m7_lpspi5_ipg_stop - m7_lpspi5_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpspi5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED13_SET_m7_lpspi6_ipg_stop_SHIFT (18U)
/*! m7_lpspi6_ipg_stop - m7_lpspi6_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_lpspi6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sinc1_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED13_SET_m7_sinc1_ipg_stop_SHIFT (19U)
/*! m7_sinc1_ipg_stop - m7_sinc1_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sinc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sinc2_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED13_SET_m7_sinc2_ipg_stop_SHIFT (20U)
/*! m7_sinc2_ipg_stop - m7_sinc2_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sinc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sinc3_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED13_SET_m7_sinc3_ipg_stop_SHIFT (21U)
/*! m7_sinc3_ipg_stop - m7_sinc3_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sinc3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sai1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED13_SET_m7_sai1_ipg_stop_SHIFT (22U)
/*! m7_sai1_ipg_stop - m7_sai1_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sai1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sai2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED13_SET_m7_sai2_ipg_stop_SHIFT (23U)
/*! m7_sai2_ipg_stop - m7_sai2_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sai2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sai3_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED13_SET_m7_sai3_ipg_stop_SHIFT (24U)
/*! m7_sai3_ipg_stop - m7_sai3_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sai3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_sai4_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED13_SET_m7_sai4_ipg_stop_SHIFT (25U)
/*! m7_sai4_ipg_stop - m7_sai4_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_sai4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_SET_m7_mic_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED13_SET_m7_mic_ipg_stop_SHIFT (26U)
/*! m7_mic_ipg_stop - m7_mic_ipg_stop */
#define CCM_GPR_SHARED13_SET_m7_mic_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_SET_m7_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_SET_m7_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED13_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED13_CLR_m7_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart6_ipg_stop_SHIFT (0U)
/*! m7_lpuart6_ipg_stop - m7_lpuart6_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart7_ipg_stop_SHIFT (1U)
/*! m7_lpuart7_ipg_stop - m7_lpuart7_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart7_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart8_ipg_stop_SHIFT (2U)
/*! m7_lpuart8_ipg_stop - m7_lpuart8_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart8_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart9_ipg_stop_SHIFT (3U)
/*! m7_lpuart9_ipg_stop - m7_lpuart9_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart9_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart10_ipg_stop_SHIFT (4U)
/*! m7_lpuart10_ipg_stop - m7_lpuart10_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart11_ipg_stop_SHIFT (5U)
/*! m7_lpuart11_ipg_stop - m7_lpuart11_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED13_CLR_m7_lpuart12_ipg_stop_SHIFT (6U)
/*! m7_lpuart12_ipg_stop - m7_lpuart12_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED13_CLR_m7_lpi2c1_ipg_stop_SHIFT (7U)
/*! m7_lpi2c1_ipg_stop - m7_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpi2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED13_CLR_m7_lpi2c2_ipg_stop_SHIFT (8U)
/*! m7_lpi2c2_ipg_stop - m7_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpi2c2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED13_CLR_m7_lpi2c3_ipg_stop_SHIFT (9U)
/*! m7_lpi2c3_ipg_stop - m7_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpi2c3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED13_CLR_m7_lpi2c4_ipg_stop_SHIFT (10U)
/*! m7_lpi2c4_ipg_stop - m7_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpi2c4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED13_CLR_m7_lpi2c5_ipg_stop_SHIFT (11U)
/*! m7_lpi2c5_ipg_stop - m7_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpi2c5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED13_CLR_m7_lpi2c6_ipg_stop_SHIFT (12U)
/*! m7_lpi2c6_ipg_stop - m7_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpi2c6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED13_CLR_m7_lpspi1_ipg_stop_SHIFT (13U)
/*! m7_lpspi1_ipg_stop - m7_lpspi1_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED13_CLR_m7_lpspi2_ipg_stop_SHIFT (14U)
/*! m7_lpspi2_ipg_stop - m7_lpspi2_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED13_CLR_m7_lpspi3_ipg_stop_SHIFT (15U)
/*! m7_lpspi3_ipg_stop - m7_lpspi3_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED13_CLR_m7_lpspi4_ipg_stop_SHIFT (16U)
/*! m7_lpspi4_ipg_stop - m7_lpspi4_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpspi4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED13_CLR_m7_lpspi5_ipg_stop_SHIFT (17U)
/*! m7_lpspi5_ipg_stop - m7_lpspi5_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpspi5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED13_CLR_m7_lpspi6_ipg_stop_SHIFT (18U)
/*! m7_lpspi6_ipg_stop - m7_lpspi6_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_lpspi6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sinc1_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED13_CLR_m7_sinc1_ipg_stop_SHIFT (19U)
/*! m7_sinc1_ipg_stop - m7_sinc1_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sinc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sinc2_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED13_CLR_m7_sinc2_ipg_stop_SHIFT (20U)
/*! m7_sinc2_ipg_stop - m7_sinc2_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sinc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sinc3_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED13_CLR_m7_sinc3_ipg_stop_SHIFT (21U)
/*! m7_sinc3_ipg_stop - m7_sinc3_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sinc3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sai1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED13_CLR_m7_sai1_ipg_stop_SHIFT (22U)
/*! m7_sai1_ipg_stop - m7_sai1_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sai1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sai2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED13_CLR_m7_sai2_ipg_stop_SHIFT (23U)
/*! m7_sai2_ipg_stop - m7_sai2_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sai2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sai3_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED13_CLR_m7_sai3_ipg_stop_SHIFT (24U)
/*! m7_sai3_ipg_stop - m7_sai3_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sai3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_sai4_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED13_CLR_m7_sai4_ipg_stop_SHIFT (25U)
/*! m7_sai4_ipg_stop - m7_sai4_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_sai4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_CLR_m7_mic_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED13_CLR_m7_mic_ipg_stop_SHIFT (26U)
/*! m7_mic_ipg_stop - m7_mic_ipg_stop */
#define CCM_GPR_SHARED13_CLR_m7_mic_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_CLR_m7_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_CLR_m7_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED13_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED13_TOG_m7_lpuart6_ipg_stop_MASK (0x1U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart6_ipg_stop_SHIFT (0U)
/*! m7_lpuart6_ipg_stop - m7_lpuart6_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpuart7_ipg_stop_MASK (0x2U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart7_ipg_stop_SHIFT (1U)
/*! m7_lpuart7_ipg_stop - m7_lpuart7_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart7_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart7_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart7_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpuart8_ipg_stop_MASK (0x4U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart8_ipg_stop_SHIFT (2U)
/*! m7_lpuart8_ipg_stop - m7_lpuart8_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart8_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart8_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart8_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpuart9_ipg_stop_MASK (0x8U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart9_ipg_stop_SHIFT (3U)
/*! m7_lpuart9_ipg_stop - m7_lpuart9_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart9_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart9_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart9_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpuart10_ipg_stop_MASK (0x10U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart10_ipg_stop_SHIFT (4U)
/*! m7_lpuart10_ipg_stop - m7_lpuart10_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart10_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart10_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart10_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpuart11_ipg_stop_MASK (0x20U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart11_ipg_stop_SHIFT (5U)
/*! m7_lpuart11_ipg_stop - m7_lpuart11_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart11_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart11_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart11_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpuart12_ipg_stop_MASK (0x40U)
#define CCM_GPR_SHARED13_TOG_m7_lpuart12_ipg_stop_SHIFT (6U)
/*! m7_lpuart12_ipg_stop - m7_lpuart12_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpuart12_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpuart12_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpuart12_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpi2c1_ipg_stop_MASK (0x80U)
#define CCM_GPR_SHARED13_TOG_m7_lpi2c1_ipg_stop_SHIFT (7U)
/*! m7_lpi2c1_ipg_stop - m7_lpi2c1_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpi2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpi2c1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpi2c1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpi2c2_ipg_stop_MASK (0x100U)
#define CCM_GPR_SHARED13_TOG_m7_lpi2c2_ipg_stop_SHIFT (8U)
/*! m7_lpi2c2_ipg_stop - m7_lpi2c2_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpi2c2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpi2c2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpi2c2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpi2c3_ipg_stop_MASK (0x200U)
#define CCM_GPR_SHARED13_TOG_m7_lpi2c3_ipg_stop_SHIFT (9U)
/*! m7_lpi2c3_ipg_stop - m7_lpi2c3_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpi2c3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpi2c3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpi2c3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpi2c4_ipg_stop_MASK (0x400U)
#define CCM_GPR_SHARED13_TOG_m7_lpi2c4_ipg_stop_SHIFT (10U)
/*! m7_lpi2c4_ipg_stop - m7_lpi2c4_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpi2c4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpi2c4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpi2c4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpi2c5_ipg_stop_MASK (0x800U)
#define CCM_GPR_SHARED13_TOG_m7_lpi2c5_ipg_stop_SHIFT (11U)
/*! m7_lpi2c5_ipg_stop - m7_lpi2c5_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpi2c5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpi2c5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpi2c5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpi2c6_ipg_stop_MASK (0x1000U)
#define CCM_GPR_SHARED13_TOG_m7_lpi2c6_ipg_stop_SHIFT (12U)
/*! m7_lpi2c6_ipg_stop - m7_lpi2c6_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpi2c6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpi2c6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpi2c6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpspi1_ipg_stop_MASK (0x2000U)
#define CCM_GPR_SHARED13_TOG_m7_lpspi1_ipg_stop_SHIFT (13U)
/*! m7_lpspi1_ipg_stop - m7_lpspi1_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpspi1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpspi1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpspi2_ipg_stop_MASK (0x4000U)
#define CCM_GPR_SHARED13_TOG_m7_lpspi2_ipg_stop_SHIFT (14U)
/*! m7_lpspi2_ipg_stop - m7_lpspi2_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpspi2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpspi2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpspi3_ipg_stop_MASK (0x8000U)
#define CCM_GPR_SHARED13_TOG_m7_lpspi3_ipg_stop_SHIFT (15U)
/*! m7_lpspi3_ipg_stop - m7_lpspi3_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpspi3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpspi3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpspi4_ipg_stop_MASK (0x10000U)
#define CCM_GPR_SHARED13_TOG_m7_lpspi4_ipg_stop_SHIFT (16U)
/*! m7_lpspi4_ipg_stop - m7_lpspi4_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpspi4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpspi4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpspi4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpspi5_ipg_stop_MASK (0x20000U)
#define CCM_GPR_SHARED13_TOG_m7_lpspi5_ipg_stop_SHIFT (17U)
/*! m7_lpspi5_ipg_stop - m7_lpspi5_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpspi5_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpspi5_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpspi5_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_lpspi6_ipg_stop_MASK (0x40000U)
#define CCM_GPR_SHARED13_TOG_m7_lpspi6_ipg_stop_SHIFT (18U)
/*! m7_lpspi6_ipg_stop - m7_lpspi6_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_lpspi6_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_lpspi6_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_lpspi6_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sinc1_ipg_stop_MASK (0x80000U)
#define CCM_GPR_SHARED13_TOG_m7_sinc1_ipg_stop_SHIFT (19U)
/*! m7_sinc1_ipg_stop - m7_sinc1_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sinc1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sinc1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sinc1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sinc2_ipg_stop_MASK (0x100000U)
#define CCM_GPR_SHARED13_TOG_m7_sinc2_ipg_stop_SHIFT (20U)
/*! m7_sinc2_ipg_stop - m7_sinc2_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sinc2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sinc2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sinc2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sinc3_ipg_stop_MASK (0x200000U)
#define CCM_GPR_SHARED13_TOG_m7_sinc3_ipg_stop_SHIFT (21U)
/*! m7_sinc3_ipg_stop - m7_sinc3_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sinc3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sinc3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sinc3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sai1_ipg_stop_MASK (0x400000U)
#define CCM_GPR_SHARED13_TOG_m7_sai1_ipg_stop_SHIFT (22U)
/*! m7_sai1_ipg_stop - m7_sai1_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sai1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sai1_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sai1_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sai2_ipg_stop_MASK (0x800000U)
#define CCM_GPR_SHARED13_TOG_m7_sai2_ipg_stop_SHIFT (23U)
/*! m7_sai2_ipg_stop - m7_sai2_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sai2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sai2_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sai2_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sai3_ipg_stop_MASK (0x1000000U)
#define CCM_GPR_SHARED13_TOG_m7_sai3_ipg_stop_SHIFT (24U)
/*! m7_sai3_ipg_stop - m7_sai3_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sai3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sai3_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sai3_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_sai4_ipg_stop_MASK (0x2000000U)
#define CCM_GPR_SHARED13_TOG_m7_sai4_ipg_stop_SHIFT (25U)
/*! m7_sai4_ipg_stop - m7_sai4_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_sai4_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_sai4_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_sai4_ipg_stop_MASK)

#define CCM_GPR_SHARED13_TOG_m7_mic_ipg_stop_MASK (0x4000000U)
#define CCM_GPR_SHARED13_TOG_m7_mic_ipg_stop_SHIFT (26U)
/*! m7_mic_ipg_stop - m7_mic_ipg_stop */
#define CCM_GPR_SHARED13_TOG_m7_mic_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_TOG_m7_mic_ipg_stop_SHIFT)) & CCM_GPR_SHARED13_TOG_m7_mic_ipg_stop_MASK)
/*! @} */

/*! @name GPR_SHARED13_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED13_AUTHEN_TZ_USER_MASK     (0x100U)
#define CCM_GPR_SHARED13_AUTHEN_TZ_USER_SHIFT    (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED13_AUTHEN_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED13_AUTHEN_TZ_NS_MASK       (0x200U)
#define CCM_GPR_SHARED13_AUTHEN_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED13_AUTHEN_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED13_AUTHEN_LOCK_TZ_MASK     (0x800U)
#define CCM_GPR_SHARED13_AUTHEN_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED13_AUTHEN_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED13_AUTHEN_LOCK_LIST_MASK   (0x8000U)
#define CCM_GPR_SHARED13_AUTHEN_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED13_AUTHEN_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED13_AUTHEN_WHITE_LIST_MASK  (0xFFFF0000U)
#define CCM_GPR_SHARED13_AUTHEN_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED13_AUTHEN_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED13_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED13_AUTHEN_SET_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED13_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED13_AUTHEN_SET_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED13_AUTHEN_SET_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED13_AUTHEN_SET_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED13_AUTHEN_SET_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED13_AUTHEN_SET_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED13_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED13_AUTHEN_SET_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED13_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED13_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED13_AUTHEN_SET_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED13_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED13_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED13_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED13_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED13_AUTHEN_CLR_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED13_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED13_AUTHEN_CLR_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED13_AUTHEN_CLR_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED13_AUTHEN_CLR_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED13_AUTHEN_CLR_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED13_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED13_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED13_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED13_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED13_AUTHEN_TOG_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED13_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED13_AUTHEN_TOG_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED13_AUTHEN_TOG_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED13_AUTHEN_TOG_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED13_AUTHEN_TOG_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED13_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED13_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED13_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED13_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED13_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED14 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED14_m7_adc1_ipg_doze_MASK   (0x1U)
#define CCM_GPR_SHARED14_m7_adc1_ipg_doze_SHIFT  (0U)
/*! m7_adc1_ipg_doze - m7_adc1_ipg_doze */
#define CCM_GPR_SHARED14_m7_adc1_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_adc2_ipg_doze_MASK   (0x2U)
#define CCM_GPR_SHARED14_m7_adc2_ipg_doze_SHIFT  (1U)
/*! m7_adc2_ipg_doze - m7_adc2_ipg_doze */
#define CCM_GPR_SHARED14_m7_adc2_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED14_m7_flexspi1_ipg_doze_SHIFT (2U)
/*! m7_flexspi1_ipg_doze - m7_flexspi1_ipg_doze */
#define CCM_GPR_SHARED14_m7_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED14_m7_flexspi2_ipg_doze_SHIFT (3U)
/*! m7_flexspi2_ipg_doze - m7_flexspi2_ipg_doze */
#define CCM_GPR_SHARED14_m7_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED14_m7_flexio1_ipg_doze_SHIFT (4U)
/*! m7_flexio1_ipg_doze - m7_flexio1_ipg_doze */
#define CCM_GPR_SHARED14_m7_flexio1_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED14_m7_flexio2_ipg_doze_SHIFT (5U)
/*! m7_flexio2_ipg_doze - m7_flexio2_ipg_doze */
#define CCM_GPR_SHARED14_m7_flexio2_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpit1_ipg_doze_MASK  (0x40U)
#define CCM_GPR_SHARED14_m7_lpit1_ipg_doze_SHIFT (6U)
/*! m7_lpit1_ipg_doze - m7_lpit1_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpit1_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpit2_ipg_doze_MASK  (0x80U)
#define CCM_GPR_SHARED14_m7_lpit2_ipg_doze_SHIFT (7U)
/*! m7_lpit2_ipg_doze - m7_lpit2_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpit2_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpit3_ipg_doze_MASK  (0x100U)
#define CCM_GPR_SHARED14_m7_lpit3_ipg_doze_SHIFT (8U)
/*! m7_lpit3_ipg_doze - m7_lpit3_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpit3_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_tpm1_ipg_doze_MASK   (0x200U)
#define CCM_GPR_SHARED14_m7_tpm1_ipg_doze_SHIFT  (9U)
/*! m7_tpm1_ipg_doze - m7_tpm1_ipg_doze */
#define CCM_GPR_SHARED14_m7_tpm1_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_tpm2_ipg_doze_MASK   (0x400U)
#define CCM_GPR_SHARED14_m7_tpm2_ipg_doze_SHIFT  (10U)
/*! m7_tpm2_ipg_doze - m7_tpm2_ipg_doze */
#define CCM_GPR_SHARED14_m7_tpm2_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_tpm3_ipg_doze_MASK   (0x800U)
#define CCM_GPR_SHARED14_m7_tpm3_ipg_doze_SHIFT  (11U)
/*! m7_tpm3_ipg_doze - m7_tpm3_ipg_doze */
#define CCM_GPR_SHARED14_m7_tpm3_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_tpm4_ipg_doze_MASK   (0x1000U)
#define CCM_GPR_SHARED14_m7_tpm4_ipg_doze_SHIFT  (12U)
/*! m7_tpm4_ipg_doze - m7_tpm4_ipg_doze */
#define CCM_GPR_SHARED14_m7_tpm4_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_tpm5_ipg_doze_MASK   (0x2000U)
#define CCM_GPR_SHARED14_m7_tpm5_ipg_doze_SHIFT  (13U)
/*! m7_tpm5_ipg_doze - m7_tpm5_ipg_doze */
#define CCM_GPR_SHARED14_m7_tpm5_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_tpm6_ipg_doze_MASK   (0x4000U)
#define CCM_GPR_SHARED14_m7_tpm6_ipg_doze_SHIFT  (14U)
/*! m7_tpm6_ipg_doze - m7_tpm6_ipg_doze */
#define CCM_GPR_SHARED14_m7_tpm6_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_gpt1_ipg_doze_MASK   (0x8000U)
#define CCM_GPR_SHARED14_m7_gpt1_ipg_doze_SHIFT  (15U)
/*! m7_gpt1_ipg_doze - m7_gpt1_ipg_doze */
#define CCM_GPR_SHARED14_m7_gpt1_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_gpt2_ipg_doze_MASK   (0x10000U)
#define CCM_GPR_SHARED14_m7_gpt2_ipg_doze_SHIFT  (16U)
/*! m7_gpt2_ipg_doze - m7_gpt2_ipg_doze */
#define CCM_GPR_SHARED14_m7_gpt2_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_can1_ipg_doze_MASK   (0x20000U)
#define CCM_GPR_SHARED14_m7_can1_ipg_doze_SHIFT  (17U)
/*! m7_can1_ipg_doze - m7_can1_ipg_doze */
#define CCM_GPR_SHARED14_m7_can1_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_can2_ipg_doze_MASK   (0x40000U)
#define CCM_GPR_SHARED14_m7_can2_ipg_doze_SHIFT  (18U)
/*! m7_can2_ipg_doze - m7_can2_ipg_doze */
#define CCM_GPR_SHARED14_m7_can2_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_can3_ipg_doze_MASK   (0x80000U)
#define CCM_GPR_SHARED14_m7_can3_ipg_doze_SHIFT  (19U)
/*! m7_can3_ipg_doze - m7_can3_ipg_doze */
#define CCM_GPR_SHARED14_m7_can3_ipg_doze(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED14_m7_lpuart1_ipg_doze_SHIFT (20U)
/*! m7_lpuart1_ipg_doze - m7_lpuart1_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart1_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED14_m7_lpuart2_ipg_doze_SHIFT (21U)
/*! m7_lpuart2_ipg_doze - m7_lpuart2_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart2_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED14_m7_lpuart3_ipg_doze_SHIFT (22U)
/*! m7_lpuart3_ipg_doze - m7_lpuart3_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart3_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED14_m7_lpuart4_ipg_doze_SHIFT (23U)
/*! m7_lpuart4_ipg_doze - m7_lpuart4_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart4_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED14_m7_lpuart5_ipg_doze_SHIFT (24U)
/*! m7_lpuart5_ipg_doze - m7_lpuart5_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart5_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED14_m7_lpuart6_ipg_doze_SHIFT (25U)
/*! m7_lpuart6_ipg_doze - m7_lpuart6_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart6_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED14_m7_lpuart7_ipg_doze_SHIFT (26U)
/*! m7_lpuart7_ipg_doze - m7_lpuart7_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart7_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED14_m7_lpuart8_ipg_doze_SHIFT (27U)
/*! m7_lpuart8_ipg_doze - m7_lpuart8_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart8_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED14_m7_lpuart9_ipg_doze_SHIFT (28U)
/*! m7_lpuart9_ipg_doze - m7_lpuart9_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart9_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED14_m7_lpuart10_ipg_doze_SHIFT (29U)
/*! m7_lpuart10_ipg_doze - m7_lpuart10_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED14_m7_lpuart11_ipg_doze_SHIFT (30U)
/*! m7_lpuart11_ipg_doze - m7_lpuart11_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED14_m7_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED14_m7_lpuart12_ipg_doze_SHIFT (31U)
/*! m7_lpuart12_ipg_doze - m7_lpuart12_ipg_doze */
#define CCM_GPR_SHARED14_m7_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_m7_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_m7_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED14_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED14_SET_m7_adc1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED14_SET_m7_adc1_ipg_doze_SHIFT (0U)
/*! m7_adc1_ipg_doze - m7_adc1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_adc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_adc2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED14_SET_m7_adc2_ipg_doze_SHIFT (1U)
/*! m7_adc2_ipg_doze - m7_adc2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_adc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED14_SET_m7_flexspi1_ipg_doze_SHIFT (2U)
/*! m7_flexspi1_ipg_doze - m7_flexspi1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED14_SET_m7_flexspi2_ipg_doze_SHIFT (3U)
/*! m7_flexspi2_ipg_doze - m7_flexspi2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED14_SET_m7_flexio1_ipg_doze_SHIFT (4U)
/*! m7_flexio1_ipg_doze - m7_flexio1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED14_SET_m7_flexio2_ipg_doze_SHIFT (5U)
/*! m7_flexio2_ipg_doze - m7_flexio2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED14_SET_m7_lpit1_ipg_doze_SHIFT (6U)
/*! m7_lpit1_ipg_doze - m7_lpit1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpit1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED14_SET_m7_lpit2_ipg_doze_SHIFT (7U)
/*! m7_lpit2_ipg_doze - m7_lpit2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpit2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED14_SET_m7_lpit3_ipg_doze_SHIFT (8U)
/*! m7_lpit3_ipg_doze - m7_lpit3_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpit3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_tpm1_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED14_SET_m7_tpm1_ipg_doze_SHIFT (9U)
/*! m7_tpm1_ipg_doze - m7_tpm1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_tpm1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_tpm2_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED14_SET_m7_tpm2_ipg_doze_SHIFT (10U)
/*! m7_tpm2_ipg_doze - m7_tpm2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_tpm2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_tpm3_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED14_SET_m7_tpm3_ipg_doze_SHIFT (11U)
/*! m7_tpm3_ipg_doze - m7_tpm3_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_tpm3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_tpm4_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED14_SET_m7_tpm4_ipg_doze_SHIFT (12U)
/*! m7_tpm4_ipg_doze - m7_tpm4_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_tpm4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_tpm5_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED14_SET_m7_tpm5_ipg_doze_SHIFT (13U)
/*! m7_tpm5_ipg_doze - m7_tpm5_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_tpm5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_tpm6_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED14_SET_m7_tpm6_ipg_doze_SHIFT (14U)
/*! m7_tpm6_ipg_doze - m7_tpm6_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_tpm6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_gpt1_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED14_SET_m7_gpt1_ipg_doze_SHIFT (15U)
/*! m7_gpt1_ipg_doze - m7_gpt1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_gpt1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_gpt2_ipg_doze_MASK (0x10000U)
#define CCM_GPR_SHARED14_SET_m7_gpt2_ipg_doze_SHIFT (16U)
/*! m7_gpt2_ipg_doze - m7_gpt2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_gpt2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_can1_ipg_doze_MASK (0x20000U)
#define CCM_GPR_SHARED14_SET_m7_can1_ipg_doze_SHIFT (17U)
/*! m7_can1_ipg_doze - m7_can1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_can1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_can2_ipg_doze_MASK (0x40000U)
#define CCM_GPR_SHARED14_SET_m7_can2_ipg_doze_SHIFT (18U)
/*! m7_can2_ipg_doze - m7_can2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_can2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_can3_ipg_doze_MASK (0x80000U)
#define CCM_GPR_SHARED14_SET_m7_can3_ipg_doze_SHIFT (19U)
/*! m7_can3_ipg_doze - m7_can3_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_can3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart1_ipg_doze_SHIFT (20U)
/*! m7_lpuart1_ipg_doze - m7_lpuart1_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart2_ipg_doze_SHIFT (21U)
/*! m7_lpuart2_ipg_doze - m7_lpuart2_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart3_ipg_doze_SHIFT (22U)
/*! m7_lpuart3_ipg_doze - m7_lpuart3_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart4_ipg_doze_SHIFT (23U)
/*! m7_lpuart4_ipg_doze - m7_lpuart4_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart5_ipg_doze_SHIFT (24U)
/*! m7_lpuart5_ipg_doze - m7_lpuart5_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart6_ipg_doze_SHIFT (25U)
/*! m7_lpuart6_ipg_doze - m7_lpuart6_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart7_ipg_doze_SHIFT (26U)
/*! m7_lpuart7_ipg_doze - m7_lpuart7_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart8_ipg_doze_SHIFT (27U)
/*! m7_lpuart8_ipg_doze - m7_lpuart8_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart9_ipg_doze_SHIFT (28U)
/*! m7_lpuart9_ipg_doze - m7_lpuart9_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart10_ipg_doze_SHIFT (29U)
/*! m7_lpuart10_ipg_doze - m7_lpuart10_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart11_ipg_doze_SHIFT (30U)
/*! m7_lpuart11_ipg_doze - m7_lpuart11_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED14_SET_m7_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED14_SET_m7_lpuart12_ipg_doze_SHIFT (31U)
/*! m7_lpuart12_ipg_doze - m7_lpuart12_ipg_doze */
#define CCM_GPR_SHARED14_SET_m7_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_SET_m7_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_SET_m7_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED14_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED14_CLR_m7_adc1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED14_CLR_m7_adc1_ipg_doze_SHIFT (0U)
/*! m7_adc1_ipg_doze - m7_adc1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_adc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_adc2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED14_CLR_m7_adc2_ipg_doze_SHIFT (1U)
/*! m7_adc2_ipg_doze - m7_adc2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_adc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED14_CLR_m7_flexspi1_ipg_doze_SHIFT (2U)
/*! m7_flexspi1_ipg_doze - m7_flexspi1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED14_CLR_m7_flexspi2_ipg_doze_SHIFT (3U)
/*! m7_flexspi2_ipg_doze - m7_flexspi2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED14_CLR_m7_flexio1_ipg_doze_SHIFT (4U)
/*! m7_flexio1_ipg_doze - m7_flexio1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED14_CLR_m7_flexio2_ipg_doze_SHIFT (5U)
/*! m7_flexio2_ipg_doze - m7_flexio2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED14_CLR_m7_lpit1_ipg_doze_SHIFT (6U)
/*! m7_lpit1_ipg_doze - m7_lpit1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpit1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED14_CLR_m7_lpit2_ipg_doze_SHIFT (7U)
/*! m7_lpit2_ipg_doze - m7_lpit2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpit2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED14_CLR_m7_lpit3_ipg_doze_SHIFT (8U)
/*! m7_lpit3_ipg_doze - m7_lpit3_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpit3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_tpm1_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED14_CLR_m7_tpm1_ipg_doze_SHIFT (9U)
/*! m7_tpm1_ipg_doze - m7_tpm1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_tpm1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_tpm2_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED14_CLR_m7_tpm2_ipg_doze_SHIFT (10U)
/*! m7_tpm2_ipg_doze - m7_tpm2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_tpm2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_tpm3_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED14_CLR_m7_tpm3_ipg_doze_SHIFT (11U)
/*! m7_tpm3_ipg_doze - m7_tpm3_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_tpm3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_tpm4_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED14_CLR_m7_tpm4_ipg_doze_SHIFT (12U)
/*! m7_tpm4_ipg_doze - m7_tpm4_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_tpm4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_tpm5_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED14_CLR_m7_tpm5_ipg_doze_SHIFT (13U)
/*! m7_tpm5_ipg_doze - m7_tpm5_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_tpm5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_tpm6_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED14_CLR_m7_tpm6_ipg_doze_SHIFT (14U)
/*! m7_tpm6_ipg_doze - m7_tpm6_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_tpm6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_gpt1_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED14_CLR_m7_gpt1_ipg_doze_SHIFT (15U)
/*! m7_gpt1_ipg_doze - m7_gpt1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_gpt1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_gpt2_ipg_doze_MASK (0x10000U)
#define CCM_GPR_SHARED14_CLR_m7_gpt2_ipg_doze_SHIFT (16U)
/*! m7_gpt2_ipg_doze - m7_gpt2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_gpt2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_can1_ipg_doze_MASK (0x20000U)
#define CCM_GPR_SHARED14_CLR_m7_can1_ipg_doze_SHIFT (17U)
/*! m7_can1_ipg_doze - m7_can1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_can1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_can2_ipg_doze_MASK (0x40000U)
#define CCM_GPR_SHARED14_CLR_m7_can2_ipg_doze_SHIFT (18U)
/*! m7_can2_ipg_doze - m7_can2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_can2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_can3_ipg_doze_MASK (0x80000U)
#define CCM_GPR_SHARED14_CLR_m7_can3_ipg_doze_SHIFT (19U)
/*! m7_can3_ipg_doze - m7_can3_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_can3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart1_ipg_doze_SHIFT (20U)
/*! m7_lpuart1_ipg_doze - m7_lpuart1_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart2_ipg_doze_SHIFT (21U)
/*! m7_lpuart2_ipg_doze - m7_lpuart2_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart3_ipg_doze_SHIFT (22U)
/*! m7_lpuart3_ipg_doze - m7_lpuart3_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart4_ipg_doze_SHIFT (23U)
/*! m7_lpuart4_ipg_doze - m7_lpuart4_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart5_ipg_doze_SHIFT (24U)
/*! m7_lpuart5_ipg_doze - m7_lpuart5_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart6_ipg_doze_SHIFT (25U)
/*! m7_lpuart6_ipg_doze - m7_lpuart6_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart7_ipg_doze_SHIFT (26U)
/*! m7_lpuart7_ipg_doze - m7_lpuart7_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart8_ipg_doze_SHIFT (27U)
/*! m7_lpuart8_ipg_doze - m7_lpuart8_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart9_ipg_doze_SHIFT (28U)
/*! m7_lpuart9_ipg_doze - m7_lpuart9_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart10_ipg_doze_SHIFT (29U)
/*! m7_lpuart10_ipg_doze - m7_lpuart10_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart11_ipg_doze_SHIFT (30U)
/*! m7_lpuart11_ipg_doze - m7_lpuart11_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED14_CLR_m7_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED14_CLR_m7_lpuart12_ipg_doze_SHIFT (31U)
/*! m7_lpuart12_ipg_doze - m7_lpuart12_ipg_doze */
#define CCM_GPR_SHARED14_CLR_m7_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_CLR_m7_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_CLR_m7_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED14_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED14_TOG_m7_adc1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED14_TOG_m7_adc1_ipg_doze_SHIFT (0U)
/*! m7_adc1_ipg_doze - m7_adc1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_adc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_adc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_adc1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_adc2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED14_TOG_m7_adc2_ipg_doze_SHIFT (1U)
/*! m7_adc2_ipg_doze - m7_adc2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_adc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_adc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_adc2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_flexspi1_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED14_TOG_m7_flexspi1_ipg_doze_SHIFT (2U)
/*! m7_flexspi1_ipg_doze - m7_flexspi1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_flexspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_flexspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_flexspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_flexspi2_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED14_TOG_m7_flexspi2_ipg_doze_SHIFT (3U)
/*! m7_flexspi2_ipg_doze - m7_flexspi2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_flexspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_flexspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_flexspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_flexio1_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED14_TOG_m7_flexio1_ipg_doze_SHIFT (4U)
/*! m7_flexio1_ipg_doze - m7_flexio1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_flexio1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_flexio1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_flexio1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_flexio2_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED14_TOG_m7_flexio2_ipg_doze_SHIFT (5U)
/*! m7_flexio2_ipg_doze - m7_flexio2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_flexio2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_flexio2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_flexio2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpit1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED14_TOG_m7_lpit1_ipg_doze_SHIFT (6U)
/*! m7_lpit1_ipg_doze - m7_lpit1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpit1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpit1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpit1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpit2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED14_TOG_m7_lpit2_ipg_doze_SHIFT (7U)
/*! m7_lpit2_ipg_doze - m7_lpit2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpit2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpit2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpit2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpit3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED14_TOG_m7_lpit3_ipg_doze_SHIFT (8U)
/*! m7_lpit3_ipg_doze - m7_lpit3_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpit3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpit3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpit3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_tpm1_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED14_TOG_m7_tpm1_ipg_doze_SHIFT (9U)
/*! m7_tpm1_ipg_doze - m7_tpm1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_tpm1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_tpm1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_tpm1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_tpm2_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED14_TOG_m7_tpm2_ipg_doze_SHIFT (10U)
/*! m7_tpm2_ipg_doze - m7_tpm2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_tpm2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_tpm2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_tpm2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_tpm3_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED14_TOG_m7_tpm3_ipg_doze_SHIFT (11U)
/*! m7_tpm3_ipg_doze - m7_tpm3_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_tpm3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_tpm3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_tpm3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_tpm4_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED14_TOG_m7_tpm4_ipg_doze_SHIFT (12U)
/*! m7_tpm4_ipg_doze - m7_tpm4_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_tpm4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_tpm4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_tpm4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_tpm5_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED14_TOG_m7_tpm5_ipg_doze_SHIFT (13U)
/*! m7_tpm5_ipg_doze - m7_tpm5_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_tpm5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_tpm5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_tpm5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_tpm6_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED14_TOG_m7_tpm6_ipg_doze_SHIFT (14U)
/*! m7_tpm6_ipg_doze - m7_tpm6_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_tpm6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_tpm6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_tpm6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_gpt1_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED14_TOG_m7_gpt1_ipg_doze_SHIFT (15U)
/*! m7_gpt1_ipg_doze - m7_gpt1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_gpt1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_gpt1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_gpt1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_gpt2_ipg_doze_MASK (0x10000U)
#define CCM_GPR_SHARED14_TOG_m7_gpt2_ipg_doze_SHIFT (16U)
/*! m7_gpt2_ipg_doze - m7_gpt2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_gpt2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_gpt2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_gpt2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_can1_ipg_doze_MASK (0x20000U)
#define CCM_GPR_SHARED14_TOG_m7_can1_ipg_doze_SHIFT (17U)
/*! m7_can1_ipg_doze - m7_can1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_can1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_can1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_can1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_can2_ipg_doze_MASK (0x40000U)
#define CCM_GPR_SHARED14_TOG_m7_can2_ipg_doze_SHIFT (18U)
/*! m7_can2_ipg_doze - m7_can2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_can2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_can2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_can2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_can3_ipg_doze_MASK (0x80000U)
#define CCM_GPR_SHARED14_TOG_m7_can3_ipg_doze_SHIFT (19U)
/*! m7_can3_ipg_doze - m7_can3_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_can3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_can3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_can3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart1_ipg_doze_MASK (0x100000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart1_ipg_doze_SHIFT (20U)
/*! m7_lpuart1_ipg_doze - m7_lpuart1_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart1_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart1_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart2_ipg_doze_MASK (0x200000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart2_ipg_doze_SHIFT (21U)
/*! m7_lpuart2_ipg_doze - m7_lpuart2_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart2_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart2_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart3_ipg_doze_MASK (0x400000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart3_ipg_doze_SHIFT (22U)
/*! m7_lpuart3_ipg_doze - m7_lpuart3_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart3_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart3_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart4_ipg_doze_MASK (0x800000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart4_ipg_doze_SHIFT (23U)
/*! m7_lpuart4_ipg_doze - m7_lpuart4_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart4_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart4_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart5_ipg_doze_MASK (0x1000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart5_ipg_doze_SHIFT (24U)
/*! m7_lpuart5_ipg_doze - m7_lpuart5_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart5_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart5_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart6_ipg_doze_MASK (0x2000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart6_ipg_doze_SHIFT (25U)
/*! m7_lpuart6_ipg_doze - m7_lpuart6_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart6_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart6_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart7_ipg_doze_MASK (0x4000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart7_ipg_doze_SHIFT (26U)
/*! m7_lpuart7_ipg_doze - m7_lpuart7_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart7_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart7_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart7_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart8_ipg_doze_MASK (0x8000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart8_ipg_doze_SHIFT (27U)
/*! m7_lpuart8_ipg_doze - m7_lpuart8_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart8_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart8_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart8_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart9_ipg_doze_MASK (0x10000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart9_ipg_doze_SHIFT (28U)
/*! m7_lpuart9_ipg_doze - m7_lpuart9_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart9_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart9_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart9_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart10_ipg_doze_MASK (0x20000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart10_ipg_doze_SHIFT (29U)
/*! m7_lpuart10_ipg_doze - m7_lpuart10_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart10_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart10_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart10_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart11_ipg_doze_MASK (0x40000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart11_ipg_doze_SHIFT (30U)
/*! m7_lpuart11_ipg_doze - m7_lpuart11_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart11_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart11_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart11_ipg_doze_MASK)

#define CCM_GPR_SHARED14_TOG_m7_lpuart12_ipg_doze_MASK (0x80000000U)
#define CCM_GPR_SHARED14_TOG_m7_lpuart12_ipg_doze_SHIFT (31U)
/*! m7_lpuart12_ipg_doze - m7_lpuart12_ipg_doze */
#define CCM_GPR_SHARED14_TOG_m7_lpuart12_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_TOG_m7_lpuart12_ipg_doze_SHIFT)) & CCM_GPR_SHARED14_TOG_m7_lpuart12_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED14_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED14_AUTHEN_TZ_USER_MASK     (0x100U)
#define CCM_GPR_SHARED14_AUTHEN_TZ_USER_SHIFT    (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED14_AUTHEN_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED14_AUTHEN_TZ_NS_MASK       (0x200U)
#define CCM_GPR_SHARED14_AUTHEN_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED14_AUTHEN_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED14_AUTHEN_LOCK_TZ_MASK     (0x800U)
#define CCM_GPR_SHARED14_AUTHEN_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED14_AUTHEN_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED14_AUTHEN_LOCK_LIST_MASK   (0x8000U)
#define CCM_GPR_SHARED14_AUTHEN_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED14_AUTHEN_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED14_AUTHEN_WHITE_LIST_MASK  (0xFFFF0000U)
#define CCM_GPR_SHARED14_AUTHEN_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED14_AUTHEN_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED14_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED14_AUTHEN_SET_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED14_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED14_AUTHEN_SET_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED14_AUTHEN_SET_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED14_AUTHEN_SET_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED14_AUTHEN_SET_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED14_AUTHEN_SET_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED14_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED14_AUTHEN_SET_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED14_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED14_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED14_AUTHEN_SET_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED14_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED14_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED14_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED14_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED14_AUTHEN_CLR_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED14_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED14_AUTHEN_CLR_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED14_AUTHEN_CLR_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED14_AUTHEN_CLR_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED14_AUTHEN_CLR_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED14_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED14_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED14_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED14_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED14_AUTHEN_TOG_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED14_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED14_AUTHEN_TOG_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED14_AUTHEN_TOG_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED14_AUTHEN_TOG_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED14_AUTHEN_TOG_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED14_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED14_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED14_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED14_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED14_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED15 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED15_m7_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED15_m7_lpi2c1_ipg_doze_SHIFT (0U)
/*! m7_lpi2c1_ipg_doze - m7_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpi2c1_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED15_m7_lpi2c2_ipg_doze_SHIFT (1U)
/*! m7_lpi2c2_ipg_doze - m7_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpi2c2_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED15_m7_lpi2c3_ipg_doze_SHIFT (2U)
/*! m7_lpi2c3_ipg_doze - m7_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpi2c3_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED15_m7_lpi2c4_ipg_doze_SHIFT (3U)
/*! m7_lpi2c4_ipg_doze - m7_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpi2c4_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED15_m7_lpi2c5_ipg_doze_SHIFT (4U)
/*! m7_lpi2c5_ipg_doze - m7_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpi2c5_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED15_m7_lpi2c6_ipg_doze_SHIFT (5U)
/*! m7_lpi2c6_ipg_doze - m7_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpi2c6_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED15_m7_lpspi1_ipg_doze_SHIFT (6U)
/*! m7_lpspi1_ipg_doze - m7_lpspi1_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpspi1_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED15_m7_lpspi2_ipg_doze_SHIFT (7U)
/*! m7_lpspi2_ipg_doze - m7_lpspi2_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpspi2_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED15_m7_lpspi3_ipg_doze_SHIFT (8U)
/*! m7_lpspi3_ipg_doze - m7_lpspi3_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpspi3_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED15_m7_lpspi4_ipg_doze_SHIFT (9U)
/*! m7_lpspi4_ipg_doze - m7_lpspi4_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpspi4_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED15_m7_lpspi5_ipg_doze_SHIFT (10U)
/*! m7_lpspi5_ipg_doze - m7_lpspi5_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpspi5_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED15_m7_lpspi6_ipg_doze_SHIFT (11U)
/*! m7_lpspi6_ipg_doze - m7_lpspi6_ipg_doze */
#define CCM_GPR_SHARED15_m7_lpspi6_ipg_doze(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_sinc1_ipg_doze_MASK  (0x1000U)
#define CCM_GPR_SHARED15_m7_sinc1_ipg_doze_SHIFT (12U)
/*! m7_sinc1_ipg_doze - m7_sinc1_ipg_doze */
#define CCM_GPR_SHARED15_m7_sinc1_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_sinc2_ipg_doze_MASK  (0x2000U)
#define CCM_GPR_SHARED15_m7_sinc2_ipg_doze_SHIFT (13U)
/*! m7_sinc2_ipg_doze - m7_sinc2_ipg_doze */
#define CCM_GPR_SHARED15_m7_sinc2_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_sinc3_ipg_doze_MASK  (0x4000U)
#define CCM_GPR_SHARED15_m7_sinc3_ipg_doze_SHIFT (14U)
/*! m7_sinc3_ipg_doze - m7_sinc3_ipg_doze */
#define CCM_GPR_SHARED15_m7_sinc3_ipg_doze(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_m7_mic_ipg_doze_MASK    (0x8000U)
#define CCM_GPR_SHARED15_m7_mic_ipg_doze_SHIFT   (15U)
/*! m7_mic_ipg_doze - m7_mic_ipg_doze */
#define CCM_GPR_SHARED15_m7_mic_ipg_doze(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_m7_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_m7_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED15_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED15_SET_m7_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED15_SET_m7_lpi2c1_ipg_doze_SHIFT (0U)
/*! m7_lpi2c1_ipg_doze - m7_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpi2c1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED15_SET_m7_lpi2c2_ipg_doze_SHIFT (1U)
/*! m7_lpi2c2_ipg_doze - m7_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpi2c2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED15_SET_m7_lpi2c3_ipg_doze_SHIFT (2U)
/*! m7_lpi2c3_ipg_doze - m7_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpi2c3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED15_SET_m7_lpi2c4_ipg_doze_SHIFT (3U)
/*! m7_lpi2c4_ipg_doze - m7_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpi2c4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED15_SET_m7_lpi2c5_ipg_doze_SHIFT (4U)
/*! m7_lpi2c5_ipg_doze - m7_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpi2c5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED15_SET_m7_lpi2c6_ipg_doze_SHIFT (5U)
/*! m7_lpi2c6_ipg_doze - m7_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpi2c6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED15_SET_m7_lpspi1_ipg_doze_SHIFT (6U)
/*! m7_lpspi1_ipg_doze - m7_lpspi1_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED15_SET_m7_lpspi2_ipg_doze_SHIFT (7U)
/*! m7_lpspi2_ipg_doze - m7_lpspi2_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED15_SET_m7_lpspi3_ipg_doze_SHIFT (8U)
/*! m7_lpspi3_ipg_doze - m7_lpspi3_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpspi3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED15_SET_m7_lpspi4_ipg_doze_SHIFT (9U)
/*! m7_lpspi4_ipg_doze - m7_lpspi4_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpspi4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED15_SET_m7_lpspi5_ipg_doze_SHIFT (10U)
/*! m7_lpspi5_ipg_doze - m7_lpspi5_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpspi5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED15_SET_m7_lpspi6_ipg_doze_SHIFT (11U)
/*! m7_lpspi6_ipg_doze - m7_lpspi6_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_lpspi6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED15_SET_m7_sinc1_ipg_doze_SHIFT (12U)
/*! m7_sinc1_ipg_doze - m7_sinc1_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_sinc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED15_SET_m7_sinc2_ipg_doze_SHIFT (13U)
/*! m7_sinc2_ipg_doze - m7_sinc2_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_sinc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED15_SET_m7_sinc3_ipg_doze_SHIFT (14U)
/*! m7_sinc3_ipg_doze - m7_sinc3_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_sinc3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_SET_m7_mic_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED15_SET_m7_mic_ipg_doze_SHIFT (15U)
/*! m7_mic_ipg_doze - m7_mic_ipg_doze */
#define CCM_GPR_SHARED15_SET_m7_mic_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_SET_m7_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_SET_m7_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED15_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED15_CLR_m7_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED15_CLR_m7_lpi2c1_ipg_doze_SHIFT (0U)
/*! m7_lpi2c1_ipg_doze - m7_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpi2c1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED15_CLR_m7_lpi2c2_ipg_doze_SHIFT (1U)
/*! m7_lpi2c2_ipg_doze - m7_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpi2c2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED15_CLR_m7_lpi2c3_ipg_doze_SHIFT (2U)
/*! m7_lpi2c3_ipg_doze - m7_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpi2c3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED15_CLR_m7_lpi2c4_ipg_doze_SHIFT (3U)
/*! m7_lpi2c4_ipg_doze - m7_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpi2c4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED15_CLR_m7_lpi2c5_ipg_doze_SHIFT (4U)
/*! m7_lpi2c5_ipg_doze - m7_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpi2c5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED15_CLR_m7_lpi2c6_ipg_doze_SHIFT (5U)
/*! m7_lpi2c6_ipg_doze - m7_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpi2c6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED15_CLR_m7_lpspi1_ipg_doze_SHIFT (6U)
/*! m7_lpspi1_ipg_doze - m7_lpspi1_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED15_CLR_m7_lpspi2_ipg_doze_SHIFT (7U)
/*! m7_lpspi2_ipg_doze - m7_lpspi2_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED15_CLR_m7_lpspi3_ipg_doze_SHIFT (8U)
/*! m7_lpspi3_ipg_doze - m7_lpspi3_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpspi3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED15_CLR_m7_lpspi4_ipg_doze_SHIFT (9U)
/*! m7_lpspi4_ipg_doze - m7_lpspi4_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpspi4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED15_CLR_m7_lpspi5_ipg_doze_SHIFT (10U)
/*! m7_lpspi5_ipg_doze - m7_lpspi5_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpspi5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED15_CLR_m7_lpspi6_ipg_doze_SHIFT (11U)
/*! m7_lpspi6_ipg_doze - m7_lpspi6_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_lpspi6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED15_CLR_m7_sinc1_ipg_doze_SHIFT (12U)
/*! m7_sinc1_ipg_doze - m7_sinc1_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_sinc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED15_CLR_m7_sinc2_ipg_doze_SHIFT (13U)
/*! m7_sinc2_ipg_doze - m7_sinc2_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_sinc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED15_CLR_m7_sinc3_ipg_doze_SHIFT (14U)
/*! m7_sinc3_ipg_doze - m7_sinc3_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_sinc3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_CLR_m7_mic_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED15_CLR_m7_mic_ipg_doze_SHIFT (15U)
/*! m7_mic_ipg_doze - m7_mic_ipg_doze */
#define CCM_GPR_SHARED15_CLR_m7_mic_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_CLR_m7_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_CLR_m7_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED15_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED15_TOG_m7_lpi2c1_ipg_doze_MASK (0x1U)
#define CCM_GPR_SHARED15_TOG_m7_lpi2c1_ipg_doze_SHIFT (0U)
/*! m7_lpi2c1_ipg_doze - m7_lpi2c1_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpi2c1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpi2c1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpi2c1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpi2c2_ipg_doze_MASK (0x2U)
#define CCM_GPR_SHARED15_TOG_m7_lpi2c2_ipg_doze_SHIFT (1U)
/*! m7_lpi2c2_ipg_doze - m7_lpi2c2_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpi2c2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpi2c2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpi2c2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpi2c3_ipg_doze_MASK (0x4U)
#define CCM_GPR_SHARED15_TOG_m7_lpi2c3_ipg_doze_SHIFT (2U)
/*! m7_lpi2c3_ipg_doze - m7_lpi2c3_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpi2c3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpi2c3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpi2c3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpi2c4_ipg_doze_MASK (0x8U)
#define CCM_GPR_SHARED15_TOG_m7_lpi2c4_ipg_doze_SHIFT (3U)
/*! m7_lpi2c4_ipg_doze - m7_lpi2c4_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpi2c4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpi2c4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpi2c4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpi2c5_ipg_doze_MASK (0x10U)
#define CCM_GPR_SHARED15_TOG_m7_lpi2c5_ipg_doze_SHIFT (4U)
/*! m7_lpi2c5_ipg_doze - m7_lpi2c5_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpi2c5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpi2c5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpi2c5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpi2c6_ipg_doze_MASK (0x20U)
#define CCM_GPR_SHARED15_TOG_m7_lpi2c6_ipg_doze_SHIFT (5U)
/*! m7_lpi2c6_ipg_doze - m7_lpi2c6_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpi2c6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpi2c6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpi2c6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpspi1_ipg_doze_MASK (0x40U)
#define CCM_GPR_SHARED15_TOG_m7_lpspi1_ipg_doze_SHIFT (6U)
/*! m7_lpspi1_ipg_doze - m7_lpspi1_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpspi1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpspi1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpspi1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpspi2_ipg_doze_MASK (0x80U)
#define CCM_GPR_SHARED15_TOG_m7_lpspi2_ipg_doze_SHIFT (7U)
/*! m7_lpspi2_ipg_doze - m7_lpspi2_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpspi2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpspi2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpspi2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpspi3_ipg_doze_MASK (0x100U)
#define CCM_GPR_SHARED15_TOG_m7_lpspi3_ipg_doze_SHIFT (8U)
/*! m7_lpspi3_ipg_doze - m7_lpspi3_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpspi3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpspi3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpspi3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpspi4_ipg_doze_MASK (0x200U)
#define CCM_GPR_SHARED15_TOG_m7_lpspi4_ipg_doze_SHIFT (9U)
/*! m7_lpspi4_ipg_doze - m7_lpspi4_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpspi4_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpspi4_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpspi4_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpspi5_ipg_doze_MASK (0x400U)
#define CCM_GPR_SHARED15_TOG_m7_lpspi5_ipg_doze_SHIFT (10U)
/*! m7_lpspi5_ipg_doze - m7_lpspi5_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpspi5_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpspi5_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpspi5_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_lpspi6_ipg_doze_MASK (0x800U)
#define CCM_GPR_SHARED15_TOG_m7_lpspi6_ipg_doze_SHIFT (11U)
/*! m7_lpspi6_ipg_doze - m7_lpspi6_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_lpspi6_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_lpspi6_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_lpspi6_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_sinc1_ipg_doze_MASK (0x1000U)
#define CCM_GPR_SHARED15_TOG_m7_sinc1_ipg_doze_SHIFT (12U)
/*! m7_sinc1_ipg_doze - m7_sinc1_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_sinc1_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_sinc1_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_sinc1_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_sinc2_ipg_doze_MASK (0x2000U)
#define CCM_GPR_SHARED15_TOG_m7_sinc2_ipg_doze_SHIFT (13U)
/*! m7_sinc2_ipg_doze - m7_sinc2_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_sinc2_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_sinc2_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_sinc2_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_sinc3_ipg_doze_MASK (0x4000U)
#define CCM_GPR_SHARED15_TOG_m7_sinc3_ipg_doze_SHIFT (14U)
/*! m7_sinc3_ipg_doze - m7_sinc3_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_sinc3_ipg_doze(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_sinc3_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_sinc3_ipg_doze_MASK)

#define CCM_GPR_SHARED15_TOG_m7_mic_ipg_doze_MASK (0x8000U)
#define CCM_GPR_SHARED15_TOG_m7_mic_ipg_doze_SHIFT (15U)
/*! m7_mic_ipg_doze - m7_mic_ipg_doze */
#define CCM_GPR_SHARED15_TOG_m7_mic_ipg_doze(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_TOG_m7_mic_ipg_doze_SHIFT)) & CCM_GPR_SHARED15_TOG_m7_mic_ipg_doze_MASK)
/*! @} */

/*! @name GPR_SHARED15_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED15_AUTHEN_TZ_USER_MASK     (0x100U)
#define CCM_GPR_SHARED15_AUTHEN_TZ_USER_SHIFT    (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 */
#define CCM_GPR_SHARED15_AUTHEN_TZ_USER(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED15_AUTHEN_TZ_NS_MASK       (0x200U)
#define CCM_GPR_SHARED15_AUTHEN_TZ_NS_SHIFT      (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED15_AUTHEN_TZ_NS(x)         (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED15_AUTHEN_LOCK_TZ_MASK     (0x800U)
#define CCM_GPR_SHARED15_AUTHEN_LOCK_TZ_SHIFT    (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_SHARED15_AUTHEN_LOCK_TZ(x)       (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED15_AUTHEN_LOCK_LIST_MASK   (0x8000U)
#define CCM_GPR_SHARED15_AUTHEN_LOCK_LIST_SHIFT  (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_SHARED15_AUTHEN_LOCK_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED15_AUTHEN_WHITE_LIST_MASK  (0xFFFF0000U)
#define CCM_GPR_SHARED15_AUTHEN_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED15_AUTHEN_WHITE_LIST(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED15_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED15_AUTHEN_SET_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED15_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED15_AUTHEN_SET_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_SHARED15_AUTHEN_SET_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED15_AUTHEN_SET_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED15_AUTHEN_SET_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_SHARED15_AUTHEN_SET_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED15_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED15_AUTHEN_SET_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_SHARED15_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED15_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED15_AUTHEN_SET_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_SHARED15_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED15_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED15_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED15_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED15_AUTHEN_CLR_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED15_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED15_AUTHEN_CLR_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_SHARED15_AUTHEN_CLR_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED15_AUTHEN_CLR_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED15_AUTHEN_CLR_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_SHARED15_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED15_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED15_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED15_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED15_AUTHEN_TOG_TZ_USER_MASK (0x100U)
#define CCM_GPR_SHARED15_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_SHARED15_AUTHEN_TOG_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_SHARED15_AUTHEN_TOG_TZ_NS_MASK   (0x200U)
#define CCM_GPR_SHARED15_AUTHEN_TOG_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_SHARED15_AUTHEN_TOG_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_TZ_MASK (0x800U)
#define CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_SHARED15_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_SHARED15_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_SHARED15_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED15_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED15_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED_STATUS - General purpose status register for CM33..General purpose status register for CM7 */
/*! @{ */

#define CCM_GPR_SHARED_STATUS_GPR_STATUS_MASK    (0xFFFFFFFFU)
#define CCM_GPR_SHARED_STATUS_GPR_STATUS_SHIFT   (0U)
/*! GPR_STATUS - Acknowledge indicators for low power handshake */
#define CCM_GPR_SHARED_STATUS_GPR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_STATUS_GPR_STATUS_SHIFT)) & CCM_GPR_SHARED_STATUS_GPR_STATUS_MASK)
/*! @} */

/*! @name GPR_PRIVATE - General purpose register */
/*! @{ */

#define CCM_GPR_PRIVATE_GPR_MASK                 (0xFFFFFFFFU)
#define CCM_GPR_PRIVATE_GPR_SHIFT                (0U)
/*! GPR - GP register */
#define CCM_GPR_PRIVATE_GPR(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_GPR_SHIFT)) & CCM_GPR_PRIVATE_GPR_MASK)
/*! @} */

/*! @name GPR_PRIVATE_SET - General purpose register */
/*! @{ */

#define CCM_GPR_PRIVATE_SET_GPR_MASK             (0xFFFFFFFFU)
#define CCM_GPR_PRIVATE_SET_GPR_SHIFT            (0U)
/*! GPR - GP register */
#define CCM_GPR_PRIVATE_SET_GPR(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_SET_GPR_SHIFT)) & CCM_GPR_PRIVATE_SET_GPR_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_SET */
#define CCM_GPR_PRIVATE_SET_COUNT                (4U)

/*! @name GPR_PRIVATE_CLR - General purpose register */
/*! @{ */

#define CCM_GPR_PRIVATE_CLR_GPR_MASK             (0xFFFFFFFFU)
#define CCM_GPR_PRIVATE_CLR_GPR_SHIFT            (0U)
/*! GPR - GP register */
#define CCM_GPR_PRIVATE_CLR_GPR(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_CLR_GPR_SHIFT)) & CCM_GPR_PRIVATE_CLR_GPR_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_CLR */
#define CCM_GPR_PRIVATE_CLR_COUNT                (4U)

/*! @name GPR_PRIVATE_TOG - General purpose register */
/*! @{ */

#define CCM_GPR_PRIVATE_TOG_GPR_MASK             (0xFFFFFFFFU)
#define CCM_GPR_PRIVATE_TOG_GPR_SHIFT            (0U)
/*! GPR - GP register */
#define CCM_GPR_PRIVATE_TOG_GPR(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_TOG_GPR_SHIFT)) & CCM_GPR_PRIVATE_TOG_GPR_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_TOG */
#define CCM_GPR_PRIVATE_TOG_COUNT                (4U)

/*! @name GPR_PRIVATE_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_PRIVATE_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_PRIVATE_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b0..Registers of private GPR cannot be changed in user mode.
 *  0b1..Registers of private GPR can be changed in user mode.
 */
#define CCM_GPR_PRIVATE_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_PRIVATE_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_PRIVATE_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_PRIVATE_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_GPR_PRIVATE_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_PRIVATE_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_GPR_PRIVATE_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_PRIVATE_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_PRIVATE_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_AUTHEN */
#define CCM_GPR_PRIVATE_AUTHEN_COUNT             (4U)

/*! @name GPR_PRIVATE_AUTHEN_SET - GPR access control */
/*! @{ */

#define CCM_GPR_PRIVATE_AUTHEN_SET_TZ_USER_MASK  (0x100U)
#define CCM_GPR_PRIVATE_AUTHEN_SET_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_PRIVATE_AUTHEN_SET_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_SET_TZ_USER_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_SET_TZ_USER_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_SET_TZ_NS_MASK    (0x200U)
#define CCM_GPR_PRIVATE_AUTHEN_SET_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_PRIVATE_AUTHEN_SET_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_SET_TZ_NS_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_SET_TZ_NS_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_TZ_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_TZ_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_SET_LOCK_LIST_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_SET_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_PRIVATE_AUTHEN_SET_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_PRIVATE_AUTHEN_SET_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_SET_WHITE_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_SET_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_AUTHEN_SET */
#define CCM_GPR_PRIVATE_AUTHEN_SET_COUNT         (4U)

/*! @name GPR_PRIVATE_AUTHEN_CLR - GPR access control */
/*! @{ */

#define CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_USER_MASK  (0x100U)
#define CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_USER_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_USER_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_NS_MASK    (0x200U)
#define CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_NS_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_CLR_TZ_NS_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_TZ_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_TZ_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_CLR_LOCK_LIST_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_CLR_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_PRIVATE_AUTHEN_CLR_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_PRIVATE_AUTHEN_CLR_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_CLR_WHITE_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_CLR_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_AUTHEN_CLR */
#define CCM_GPR_PRIVATE_AUTHEN_CLR_COUNT         (4U)

/*! @name GPR_PRIVATE_AUTHEN_TOG - GPR access control */
/*! @{ */

#define CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_USER_MASK  (0x100U)
#define CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_USER_SHIFT (8U)
/*! TZ_USER - User access permission */
#define CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_USER(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_USER_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_USER_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_NS_MASK    (0x200U)
#define CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_NS_SHIFT   (9U)
/*! TZ_NS - Non-secure access permission */
#define CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_NS(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_NS_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TOG_TZ_NS_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_TZ_MASK  (0x800U)
#define CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TrustZone settings */
#define CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_TZ(x)    (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_TZ_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_TZ_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_LIST_MASK (0x8000U)
#define CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - Lock white list */
#define CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_LIST(x)  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TOG_LOCK_LIST_MASK)

#define CCM_GPR_PRIVATE_AUTHEN_TOG_WHITE_LIST_MASK (0xFFFF0000U)
#define CCM_GPR_PRIVATE_AUTHEN_TOG_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Whitelist settings */
#define CCM_GPR_PRIVATE_AUTHEN_TOG_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_AUTHEN_TOG_WHITE_LIST_SHIFT)) & CCM_GPR_PRIVATE_AUTHEN_TOG_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_GPR_PRIVATE_AUTHEN_TOG */
#define CCM_GPR_PRIVATE_AUTHEN_TOG_COUNT         (4U)

/*! @name OSCPLL_DIRECT - Clock source direct control */
/*! @{ */

#define CCM_OSCPLL_DIRECT_ON_MASK                (0x1U)
#define CCM_OSCPLL_DIRECT_ON_SHIFT               (0U)
/*! ON - Turn on clock source
 *  0b0..Clock source is OFF.
 *  0b1..Clock source is ON.
 */
#define CCM_OSCPLL_DIRECT_ON(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_DIRECT_ON_SHIFT)) & CCM_OSCPLL_DIRECT_ON_MASK)
/*! @} */

/* The count of CCM_OSCPLL_DIRECT */
#define CCM_OSCPLL_DIRECT_COUNT                  (25U)

/*! @name OSCPLL_LPM0 - Clock source low power mode setting */
/*! @{ */

#define CCM_OSCPLL_LPM0_LPM_SETTING_D0_MASK      (0x7U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D0_SHIFT     (0U)
/*! LPM_SETTING_D0 - Clock Source LPM in DOMAIN0
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D0(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D0_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D0_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D1_MASK      (0x70U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D1_SHIFT     (4U)
/*! LPM_SETTING_D1 - Clock Source LPM in DOMAIN1
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D1_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D1_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D2_MASK      (0x700U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D2_SHIFT     (8U)
/*! LPM_SETTING_D2 - Clock Source LPM in DOMAIN2
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D2_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D2_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D3_MASK      (0x7000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D3_SHIFT     (12U)
/*! LPM_SETTING_D3 - Clock Source LPM in DOMAIN3
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D3_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D3_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D4_MASK      (0x70000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D4_SHIFT     (16U)
/*! LPM_SETTING_D4 - Clock Source LPM in DOMAIN4
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D4_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D4_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D5_MASK      (0x700000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D5_SHIFT     (20U)
/*! LPM_SETTING_D5 - Clock Source LPM in DOMAIN5
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D5(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D5_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D5_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D6_MASK      (0x7000000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D6_SHIFT     (24U)
/*! LPM_SETTING_D6 - Clock Source LPM in DOMAIN6
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D6(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D6_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D6_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D7_MASK      (0x70000000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D7_SHIFT     (28U)
/*! LPM_SETTING_D7 - Clock Source LPM in DOMAIN7
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D7(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D7_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D7_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM0 */
#define CCM_OSCPLL_LPM0_COUNT                    (25U)

/*! @name OSCPLL_LPM1 - clock source low power mode setting */
/*! @{ */

#define CCM_OSCPLL_LPM1_LPM_SETTING_D8_MASK      (0x7U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D8_SHIFT     (0U)
/*! LPM_SETTING_D8 - Clock Source LPM in DOMAIN8
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D8(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D8_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D8_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D9_MASK      (0x70U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D9_SHIFT     (4U)
/*! LPM_SETTING_D9 - Clock Source LPM in DOMAIN9
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D9(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D9_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D9_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D10_MASK     (0x700U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D10_SHIFT    (8U)
/*! LPM_SETTING_D10 - Clock Source LPM in DOMAIN10
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D10(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D10_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D10_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D11_MASK     (0x7000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D11_SHIFT    (12U)
/*! LPM_SETTING_D11 - Clock Source LPM in DOMAIN11
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D11(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D11_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D11_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D12_MASK     (0x70000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D12_SHIFT    (16U)
/*! LPM_SETTING_D12 - Clock Source LPM in DOMAIN12
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D12(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D12_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D12_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D13_MASK     (0x700000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D13_SHIFT    (20U)
/*! LPM_SETTING_D13 - Clock Source LPM in DOMAIN13
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D13(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D13_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D13_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D14_MASK     (0x7000000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D14_SHIFT    (24U)
/*! LPM_SETTING_D14 - Clock Source LPM in DOMAIN14
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D14(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D14_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D14_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D15_MASK     (0x70000000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D15_SHIFT    (28U)
/*! LPM_SETTING_D15 - Clock Source LPM in DOMAIN15
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D15(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D15_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D15_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM1 */
#define CCM_OSCPLL_LPM1_COUNT                    (25U)

/*! @name OSCPLL_LPM_CUR - LPM setting of current CPU domain */
/*! @{ */

#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_MASK  (0x7U)
#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_SHIFT (0U)
/*! LPM_SETTING_CUR - LPM settings value for current CPU domain that is reading this register.
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR(x)    (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_SHIFT)) & CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_CUR */
#define CCM_OSCPLL_LPM_CUR_COUNT                 (25U)

/*! @name OSCPLL_STATUS0 - Clock source working status */
/*! @{ */

#define CCM_OSCPLL_STATUS0_ON_MASK               (0x1U)
#define CCM_OSCPLL_STATUS0_ON_SHIFT              (0U)
/*! ON - Clock source current state
 *  0b0..Clock source is OFF.
 *  0b1..Clock source is ON.
 */
#define CCM_OSCPLL_STATUS0_ON(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_ON_SHIFT)) & CCM_OSCPLL_STATUS0_ON_MASK)

#define CCM_OSCPLL_STATUS0_STATUS_EARLY_MASK     (0x10U)
#define CCM_OSCPLL_STATUS0_STATUS_EARLY_SHIFT    (4U)
/*! STATUS_EARLY - Clock source active
 *  0b0..Clock source is not active
 *  0b1..Clock source is active
 */
#define CCM_OSCPLL_STATUS0_STATUS_EARLY(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_STATUS_EARLY_SHIFT)) & CCM_OSCPLL_STATUS0_STATUS_EARLY_MASK)

#define CCM_OSCPLL_STATUS0_STATUS_LATE_MASK      (0x20U)
#define CCM_OSCPLL_STATUS0_STATUS_LATE_SHIFT     (5U)
/*! STATUS_LATE - Clock source ready
 *  0b0..Clock source is not ready to use
 *  0b1..Clock source is ready to use
 */
#define CCM_OSCPLL_STATUS0_STATUS_LATE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_STATUS_LATE_SHIFT)) & CCM_OSCPLL_STATUS0_STATUS_LATE_MASK)

#define CCM_OSCPLL_STATUS0_IN_USE_MASK           (0x1000U)
#define CCM_OSCPLL_STATUS0_IN_USE_SHIFT          (12U)
/*! IN_USE - This Clock Source is being used or not.
 *  0b0..Clock Source is not being used.
 *  0b1..Clock Source is being used.
 */
#define CCM_OSCPLL_STATUS0_IN_USE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_IN_USE_SHIFT)) & CCM_OSCPLL_STATUS0_IN_USE_MASK)
/*! @} */

/* The count of CCM_OSCPLL_STATUS0 */
#define CCM_OSCPLL_STATUS0_COUNT                 (25U)

/*! @name OSCPLL_STATUS1 - Clock source domain status */
/*! @{ */

#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_MASK    (0xFFFFU)
#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_SHIFT   (0U)
/*! DOMAIN_ACTIVE - Domain active */
#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_SHIFT)) & CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_MASK)

#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_MASK    (0xFFFF0000U)
#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_SHIFT   (16U)
/*! DOMAIN_ENABLE - Domain enable */
#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_SHIFT)) & CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_MASK)
/*! @} */

/* The count of CCM_OSCPLL_STATUS1 */
#define CCM_OSCPLL_STATUS1_COUNT                 (25U)

/*! @name OSCPLL_AUTHEN - Clock Source access control */
/*! @{ */

#define CCM_OSCPLL_AUTHEN_CPULPM_MODE_MASK       (0x4U)
#define CCM_OSCPLL_AUTHEN_CPULPM_MODE_SHIFT      (2U)
/*! CPULPM_MODE - CPULPM mode enable
 *  0b0..Disable CPULPM mode.
 *  0b1..Enable CPULPM mode.
 */
#define CCM_OSCPLL_AUTHEN_CPULPM_MODE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_CPULPM_MODE_SHIFT)) & CCM_OSCPLL_AUTHEN_CPULPM_MODE_MASK)

#define CCM_OSCPLL_AUTHEN_AUTO_CTRL_MASK         (0x8U)
#define CCM_OSCPLL_AUTHEN_AUTO_CTRL_SHIFT        (3U)
/*! AUTO_CTRL - Auto mode enable
 *  0b0..Disable Auto mode
 *  0b1..Enable Auto mode
 */
#define CCM_OSCPLL_AUTHEN_AUTO_CTRL(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_AUTO_CTRL_SHIFT)) & CCM_OSCPLL_AUTHEN_AUTO_CTRL_MASK)

#define CCM_OSCPLL_AUTHEN_TZ_USER_MASK           (0x100U)
#define CCM_OSCPLL_AUTHEN_TZ_USER_SHIFT          (8U)
/*! TZ_USER - User access permission
 *  0b0..Clock Source settings cannot be changed in user mode.
 *  0b1..Clock Source settings can be changed in user mode.
 */
#define CCM_OSCPLL_AUTHEN_TZ_USER(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_TZ_USER_SHIFT)) & CCM_OSCPLL_AUTHEN_TZ_USER_MASK)

#define CCM_OSCPLL_AUTHEN_TZ_NS_MASK             (0x200U)
#define CCM_OSCPLL_AUTHEN_TZ_NS_SHIFT            (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_OSCPLL_AUTHEN_TZ_NS(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_TZ_NS_SHIFT)) & CCM_OSCPLL_AUTHEN_TZ_NS_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_TZ_MASK           (0x800U)
#define CCM_OSCPLL_AUTHEN_LOCK_TZ_SHIFT          (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_TZ(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_TZ_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_TZ_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_LIST_MASK         (0x8000U)
#define CCM_OSCPLL_AUTHEN_LOCK_LIST_SHIFT        (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_LIST(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_LIST_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_LIST_MASK)

#define CCM_OSCPLL_AUTHEN_WHITE_LIST_MASK        (0xFFFF0000U)
#define CCM_OSCPLL_AUTHEN_WHITE_LIST_SHIFT       (16U)
/*! WHITE_LIST - Whitelist */
#define CCM_OSCPLL_AUTHEN_WHITE_LIST(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_WHITE_LIST_SHIFT)) & CCM_OSCPLL_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OSCPLL_AUTHEN */
#define CCM_OSCPLL_AUTHEN_COUNT                  (25U)

/*! @name LPCG_DIRECT - LPCG direct control */
/*! @{ */

#define CCM_LPCG_DIRECT_ON_MASK                  (0x1U)
#define CCM_LPCG_DIRECT_ON_SHIFT                 (0U)
/*! ON - Turn on LPCG
 *  0b0..LPCG is OFF.
 *  0b1..LPCG is ON.
 */
#define CCM_LPCG_DIRECT_ON(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_DIRECT_ON_SHIFT)) & CCM_LPCG_DIRECT_ON_MASK)

#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK (0x4U)
#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_SHIFT (2U)
/*! CLKOFF_ACK_TIMEOUT_EN - Clock off handshake timeout enable
 *  0b0..disable
 *  0b1..enable
 */
#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_SHIFT)) & CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK)
/*! @} */

/* The count of CCM_LPCG_DIRECT */
#define CCM_LPCG_DIRECT_COUNT                    (149U)

/*! @name LPCG_LPM0 - Clock source low power mode setting */
/*! @{ */

#define CCM_LPCG_LPM0_LPM_SETTING_D0_MASK        (0x7U)
#define CCM_LPCG_LPM0_LPM_SETTING_D0_SHIFT       (0U)
/*! LPM_SETTING_D0 - Clock Source LPM in DOMAIN0
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D0(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D0_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D0_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D1_MASK        (0x70U)
#define CCM_LPCG_LPM0_LPM_SETTING_D1_SHIFT       (4U)
/*! LPM_SETTING_D1 - Clock Source LPM in DOMAIN1
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D1_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D1_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D2_MASK        (0x700U)
#define CCM_LPCG_LPM0_LPM_SETTING_D2_SHIFT       (8U)
/*! LPM_SETTING_D2 - Clock Source LPM in DOMAIN2
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D2_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D2_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D3_MASK        (0x7000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D3_SHIFT       (12U)
/*! LPM_SETTING_D3 - Clock Source LPM in DOMAIN3
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D3(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D3_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D3_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D4_MASK        (0x70000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D4_SHIFT       (16U)
/*! LPM_SETTING_D4 - Clock Source LPM in DOMAIN4
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D4(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D4_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D4_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D5_MASK        (0x700000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D5_SHIFT       (20U)
/*! LPM_SETTING_D5 - Clock Source LPM in DOMAIN5
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D5(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D5_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D5_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D6_MASK        (0x7000000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D6_SHIFT       (24U)
/*! LPM_SETTING_D6 - Clock Source LPM in DOMAIN6
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D6(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D6_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D6_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D7_MASK        (0x70000000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D7_SHIFT       (28U)
/*! LPM_SETTING_D7 - Clock Source LPM in DOMAIN7
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D7(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D7_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D7_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM0 */
#define CCM_LPCG_LPM0_COUNT                      (149U)

/*! @name LPCG_LPM1 - clock source low power mode setting */
/*! @{ */

#define CCM_LPCG_LPM1_LPM_SETTING_D8_MASK        (0x7U)
#define CCM_LPCG_LPM1_LPM_SETTING_D8_SHIFT       (0U)
/*! LPM_SETTING_D8 - Clock Source LPM in DOMAIN8
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D8(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D8_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D8_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D9_MASK        (0x70U)
#define CCM_LPCG_LPM1_LPM_SETTING_D9_SHIFT       (4U)
/*! LPM_SETTING_D9 - Clock Source LPM in DOMAIN9
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D9(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D9_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D9_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D10_MASK       (0x700U)
#define CCM_LPCG_LPM1_LPM_SETTING_D10_SHIFT      (8U)
/*! LPM_SETTING_D10 - Clock Source LPM in DOMAIN10
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D10(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D10_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D10_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D11_MASK       (0x7000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D11_SHIFT      (12U)
/*! LPM_SETTING_D11 - Clock Source LPM in DOMAIN11
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D11(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D11_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D11_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D12_MASK       (0x70000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D12_SHIFT      (16U)
/*! LPM_SETTING_D12 - Clock Source LPM in DOMAIN12
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D12(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D12_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D12_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D13_MASK       (0x700000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D13_SHIFT      (20U)
/*! LPM_SETTING_D13 - Clock Source LPM in DOMAIN13
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D13(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D13_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D13_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D14_MASK       (0x7000000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D14_SHIFT      (24U)
/*! LPM_SETTING_D14 - Clock Source LPM in DOMAIN14
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D14(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D14_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D14_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D15_MASK       (0x70000000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D15_SHIFT      (28U)
/*! LPM_SETTING_D15 - Clock Source LPM in DOMAIN15
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D15(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D15_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D15_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM1 */
#define CCM_LPCG_LPM1_COUNT                      (149U)

/*! @name LPCG_LPM_CUR - LPM setting of current CPU domain */
/*! @{ */

#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_MASK    (0x7U)
#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_SHIFT   (0U)
/*! LPM_SETTING_CUR - LPM settings value for current CPU domain that is reading this register.
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR(x)      (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_SHIFT)) & CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_CUR */
#define CCM_LPCG_LPM_CUR_COUNT                   (149U)

/*! @name LPCG_STATUS0 - LPCG working status */
/*! @{ */

#define CCM_LPCG_STATUS0_ON_MASK                 (0x1U)
#define CCM_LPCG_STATUS0_ON_SHIFT                (0U)
/*! ON - LPCG work status
 *  0b0..LPCG is OFF.
 *  0b1..LPCG is ON.
 */
#define CCM_LPCG_STATUS0_ON(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS0_ON_SHIFT)) & CCM_LPCG_STATUS0_ON_MASK)
/*! @} */

/* The count of CCM_LPCG_STATUS0 */
#define CCM_LPCG_STATUS0_COUNT                   (149U)

/*! @name LPCG_STATUS1 - LPCG domain status */
/*! @{ */

#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE_MASK      (0xFFFFU)
#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE_SHIFT     (0U)
/*! DOMAIN_ACTIVE - Domain active */
#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS1_DOMAIN_ACTIVE_SHIFT)) & CCM_LPCG_STATUS1_DOMAIN_ACTIVE_MASK)

#define CCM_LPCG_STATUS1_DOMAIN_ENABLE_MASK      (0xFFFF0000U)
#define CCM_LPCG_STATUS1_DOMAIN_ENABLE_SHIFT     (16U)
/*! DOMAIN_ENABLE - Domain enable */
#define CCM_LPCG_STATUS1_DOMAIN_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS1_DOMAIN_ENABLE_SHIFT)) & CCM_LPCG_STATUS1_DOMAIN_ENABLE_MASK)
/*! @} */

/* The count of CCM_LPCG_STATUS1 */
#define CCM_LPCG_STATUS1_COUNT                   (149U)

/*! @name LPCG_AUTHEN - LPCG access control */
/*! @{ */

#define CCM_LPCG_AUTHEN_CPULPM_MODE_MASK         (0x4U)
#define CCM_LPCG_AUTHEN_CPULPM_MODE_SHIFT        (2U)
/*! CPULPM_MODE - CPULPM mode enable
 *  0b0..Disable CPULPM mode, this LPCG is in Direct Control mode.
 *  0b1..Enable CPULPM mode, this LPCG is in CPULPM mode.
 */
#define CCM_LPCG_AUTHEN_CPULPM_MODE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_CPULPM_MODE_SHIFT)) & CCM_LPCG_AUTHEN_CPULPM_MODE_MASK)

#define CCM_LPCG_AUTHEN_ACK_MODE_MASK            (0x10U)
#define CCM_LPCG_AUTHEN_ACK_MODE_SHIFT           (4U)
/*! ACK_MODE - CPULPM mode enable
 *  0b0..Disable ACK mode.
 *  0b1..Enable ACK mode.
 */
#define CCM_LPCG_AUTHEN_ACK_MODE(x)              (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_ACK_MODE_SHIFT)) & CCM_LPCG_AUTHEN_ACK_MODE_MASK)

#define CCM_LPCG_AUTHEN_TZ_USER_MASK             (0x100U)
#define CCM_LPCG_AUTHEN_TZ_USER_SHIFT            (8U)
/*! TZ_USER - User access permission
 *  0b0..LPCG settings cannot be changed in user mode.
 *  0b1..LPCG settings can be changed in user mode.
 */
#define CCM_LPCG_AUTHEN_TZ_USER(x)               (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_TZ_USER_SHIFT)) & CCM_LPCG_AUTHEN_TZ_USER_MASK)

#define CCM_LPCG_AUTHEN_TZ_NS_MASK               (0x200U)
#define CCM_LPCG_AUTHEN_TZ_NS_SHIFT              (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_LPCG_AUTHEN_TZ_NS(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_TZ_NS_SHIFT)) & CCM_LPCG_AUTHEN_TZ_NS_MASK)

#define CCM_LPCG_AUTHEN_LOCK_TZ_MASK             (0x800U)
#define CCM_LPCG_AUTHEN_LOCK_TZ_SHIFT            (11U)
/*! LOCK_TZ - Lock TrustZone settings
 *  0b0..TrustZone settings is not locked.
 *  0b1..TrustZone settings is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_TZ(x)               (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_TZ_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_TZ_MASK)

#define CCM_LPCG_AUTHEN_LOCK_LIST_MASK           (0x8000U)
#define CCM_LPCG_AUTHEN_LOCK_LIST_SHIFT          (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..Whitelist is not locked.
 *  0b1..Whitelist is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_LIST_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_LIST_MASK)

#define CCM_LPCG_AUTHEN_WHITE_LIST_MASK          (0xFFFF0000U)
#define CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT         (16U)
/*! WHITE_LIST - Whitelist */
#define CCM_LPCG_AUTHEN_WHITE_LIST(x)            (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT)) & CCM_LPCG_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_LPCG_AUTHEN */
#define CCM_LPCG_AUTHEN_COUNT                    (149U)


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM_H_ */

