/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MED_HDR10
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MED_HDR10.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MED_HDR10
 *
 * CMSIS Peripheral Access Layer for MED_HDR10
 */

#if !defined(PERI_MED_HDR10_H_)
#define PERI_MED_HDR10_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- MED_HDR10 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MED_HDR10_Peripheral_Access_Layer MED_HDR10 Peripheral Access Layer
 * @{
 */

/** MED_HDR10 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIPE1_A0_LUT;                      /**< A0 component Look-Up-Table. (LUT), offset: 0x0 */
       uint8_t RESERVED_0[4092];
  __IO uint32_t PIPE1_A1_LUT;                      /**< A1 component Look-Up-Table. (LUT), offset: 0x1000 */
       uint8_t RESERVED_1[4092];
  __IO uint32_t PIPE1_A2_LUT;                      /**< A2 component Look-Up-Table. (LUT), offset: 0x2000 */
       uint8_t RESERVED_2[4092];
  __IO uint32_t HDR_PIPE1_CSCA_CONTROL_REG;        /**< Pipe1 Colorspace Converter A control., offset: 0x3000 */
  __IO uint32_t HDR_PIPE1_CSCA_H00;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,0) matrix coefficient, offset: 0x3004 */
  __IO uint32_t HDR_PIPE1_CSCA_H10;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,0) matrix coefficient, offset: 0x3008 */
  __IO uint32_t HDR_PIPE1_CSCA_H20;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,0) matrix coefficient, offset: 0x300C */
  __IO uint32_t HDR_PIPE1_CSCA_H01;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,1) matrix coefficient, offset: 0x3010 */
  __IO uint32_t HDR_PIPE1_CSCA_H11;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,1) matrix coefficient, offset: 0x3014 */
  __IO uint32_t HDR_PIPE1_CSCA_H21;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,1) matrix coefficient, offset: 0x3018 */
  __IO uint32_t HDR_PIPE1_CSCA_H02;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,2) matrix coefficient, offset: 0x301C */
  __IO uint32_t HDR_PIPE1_CSCA_H12;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,2) matrix coefficient, offset: 0x3020 */
  __IO uint32_t HDR_PIPE1_CSCA_H22;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,2) matrix coefficient, offset: 0x3024 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_0;               /**< Pipe1 Colorspace Converter A (CSCA) component 0 pre-offset, offset: 0x3028 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_1;               /**< Pipe1 Colorspace Converter A (CSCA) component 1 pre-offset, offset: 0x302C */
  __IO uint32_t HDR_PIPE1_CSCA_IO_2;               /**< Pipe1 Colorspace Converter A (CSCA) component 2 pre-offset, offset: 0x3030 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_MIN_0;           /**< Pipe1 Colorspace Converter A (CSCA) component 0 clip min., offset: 0x3034 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_MIN_1;           /**< Pipe1 Colorspace Converter A (CSCA) component 1 clip min., offset: 0x3038 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_MIN_2;           /**< Pipe1 Colorspace Converter A (CSCA) component 2 clip min., offset: 0x303C */
  __IO uint32_t HDR_PIPE1_CSCA_IO_MAX_0;           /**< Pipe1 Colorspace Converter A (CSCA) component 0 clip max value., offset: 0x3040 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_MAX_1;           /**< Pipe1 Colorspace Converter A (CSCA) component 1 clip max value., offset: 0x3044 */
  __IO uint32_t HDR_PIPE1_CSCA_IO_MAX_2;           /**< Pipe1 Colorspace Converter A (CSCA) component 2 clip max value., offset: 0x3048 */
  __IO uint32_t HDR_PIPE1_CSCA_NORM;               /**< Pipe1 Colorspace Converter A (CSCA) normalization factor, offset: 0x304C */
  __IO uint32_t HDR_PIPE1_CSCA_OO_0;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 0, offset: 0x3050 */
  __IO uint32_t HDR_PIPE1_CSCA_OO_1;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 1, offset: 0x3054 */
  __IO uint32_t HDR_PIPE1_CSCA_OO_2;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 2, offset: 0x3058 */
  __IO uint32_t HDR_PIPE1_CSCA_OMIN_0;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 0, offset: 0x305C */
  __IO uint32_t HDR_PIPE1_CSCA_OMIN_1;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 1, offset: 0x3060 */
  __IO uint32_t HDR_PIPE1_CSCA_OMIN_2;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 2, offset: 0x3064 */
  __IO uint32_t HDR_PIPE1_CSCA_OMAX_0;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 0, offset: 0x3068 */
  __IO uint32_t HDR_PIPE1_CSCA_OMAX_1;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 1, offset: 0x306C */
  __IO uint32_t HDR_PIPE1_CSCA_OMAX_2;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 2, offset: 0x3070 */
       uint32_t HDR_PIPE1_ENTRY_29;                /**< PIPE1: NOT USED, offset: 0x3074 */
       uint8_t RESERVED_3[8];
  __IO uint32_t HDR_PIPE1_LUT_CONTROL_REG;         /**< Pipe1 LUT control register, offset: 0x3080 */
       uint8_t RESERVED_4[1916];
  __IO uint32_t HDR_PIPE1_CSCB_CONTROL_REG;        /**< Pipe1 Colorspace Converter B control., offset: 0x3800 */
  __IO uint32_t HDR_PIPE1_CSCB_H00;                /**< Pipe1 Colorspace Converter A (CSCB) h(0,0) matrix coefficient, offset: 0x3804 */
  __IO uint32_t HDR_PIPE1_CSCB_H10;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,0) matrix coefficient, offset: 0x3808 */
  __IO uint32_t HDR_PIPE1_CSCB_H20;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,0) matrix coefficient, offset: 0x380C */
  __IO uint32_t HDR_PIPE1_CSCB_H01;                /**< Pipe1 Colorspace Converter B (CSCB) h(0,1) matrix coefficient, offset: 0x3810 */
  __IO uint32_t HDR_PIPE1_CSCB_H11;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,1) matrix coefficient, offset: 0x3814 */
  __IO uint32_t HDR_PIPE1_CSCB_H21;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,1) matrix coefficient, offset: 0x3818 */
  __IO uint32_t HDR_PIPE1_CSCB_H02;                /**< Pipe1 Colorspace Converter B (CSCB) h(0,2) matrix coefficient, offset: 0x381C */
  __IO uint32_t HDR_PIPE1_CSCB_H12;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,2) matrix coefficient, offset: 0x3820 */
  __IO uint32_t HDR_PIPE1_CSCB_H22;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,2) matrix coefficient, offset: 0x3824 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_0;               /**< Pipe1 Colorspace Converter B (CSCB) component 0 pre-offset, offset: 0x3828 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_1;               /**< Pipe1 Colorspace Converter B (CSCB) component 1 pre-offset, offset: 0x382C */
  __IO uint32_t HDR_PIPE1_CSCB_IO_2;               /**< Pipe1 Colorspace Converter B (CSCB) component 2 pre-offset, offset: 0x3830 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_MIN_0;           /**< Pipe1 Colorspace Converter B (CSCB) component 0 clip min., offset: 0x3834 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_MIN_1;           /**< Pipe1 Colorspace Converter B (CSCB) component 1 clip min., offset: 0x3838 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_MIN_2;           /**< Pipe1 Colorspace Converter B (CSCB) component 2 clip min., offset: 0x383C */
  __IO uint32_t HDR_PIPE1_CSCB_IO_MAX_0;           /**< Pipe1 Colorspace Converter B (CSCB) component 0 clip max value., offset: 0x3840 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_MAX_1;           /**< Pipe1 Colorspace Converter B (CSCB) component 1 clip max value., offset: 0x3844 */
  __IO uint32_t HDR_PIPE1_CSCB_IO_MAX_2;           /**< Pipe1 Colorspace Converter B (CSCB) component 2 clip max value., offset: 0x3848 */
  __IO uint32_t HDR_PIPE1_CSCB_NORM;               /**< Pipe1 Colorspace Converter B (CSCB) normalization factor, offset: 0x384C */
  __IO uint32_t HDR_PIPE1_CSCB_OO_0;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 0, offset: 0x3850 */
  __IO uint32_t HDR_PIPE1_CSCB_OO_1;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 1, offset: 0x3854 */
  __IO uint32_t HDR_PIPE1_CSCB_OO_2;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 2, offset: 0x3858 */
  __IO uint32_t HDR_PIPE1_CSCB_OMIN_0;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 0, offset: 0x385C */
  __IO uint32_t HDR_PIPE1_CSCB_OMIN_1;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 1, offset: 0x3860 */
  __IO uint32_t HDR_PIPE1_CSCB_OMIN_2;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 2, offset: 0x3864 */
  __IO uint32_t HDR_PIPE1_CSCB_OMAX_0;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 0, offset: 0x3868 */
  __IO uint32_t HDR_PIPE1_CSCB_OMAX_1;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 1, offset: 0x386C */
  __IO uint32_t HDR_PIPE1_CSCB_OMAX_2;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 2, offset: 0x3870 */
  __IO uint32_t HDR_PIPE1_FL2FX;                   /**< Pipe1 floating point to fixed point control, offset: 0x3874 */
       uint32_t HDR_PIPE1_ENTRY_30;                /**< PIPE1: NOT USED, offset: 0x3878 */
       uint8_t RESERVED_5[1924];
  __IO uint32_t PIPE2_A0_LUT;                      /**< A0 component Look-Up-Table. (LUT), offset: 0x4000 */
       uint8_t RESERVED_6[4092];
  __IO uint32_t PIPE2_A1_LUT;                      /**< A1 component Look-Up-Table. (LUT), offset: 0x5000 */
       uint8_t RESERVED_7[4092];
  __IO uint32_t PIPE2_A2_LUT;                      /**< A2 component Look-Up-Table. (LUT), offset: 0x6000 */
       uint8_t RESERVED_8[4092];
  __IO uint32_t HDR_PIPE2_CSCA_CONTROL_REG;        /**< Pipe1 Colorspace Converter A control., offset: 0x7000 */
  __IO uint32_t HDR_PIPE2_CSCA_H00;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,0) matrix coefficient, offset: 0x7004 */
  __IO uint32_t HDR_PIPE2_CSCA_H10;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,0) matrix coefficient, offset: 0x7008 */
  __IO uint32_t HDR_PIPE2_CSCA_H20;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,0) matrix coefficient, offset: 0x700C */
  __IO uint32_t HDR_PIPE2_CSCA_H01;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,1) matrix coefficient, offset: 0x7010 */
  __IO uint32_t HDR_PIPE2_CSCA_H11;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,1) matrix coefficient, offset: 0x7014 */
  __IO uint32_t HDR_PIPE2_CSCA_H21;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,1) matrix coefficient, offset: 0x7018 */
  __IO uint32_t HDR_PIPE2_CSCA_H02;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,2) matrix coefficient, offset: 0x701C */
  __IO uint32_t HDR_PIPE2_CSCA_H12;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,2) matrix coefficient, offset: 0x7020 */
  __IO uint32_t HDR_PIPE2_CSCA_H22;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,2) matrix coefficient, offset: 0x7024 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_0;               /**< Pipe1 Colorspace Converter A (CSCA) component 0 pre-offset, offset: 0x7028 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_1;               /**< Pipe1 Colorspace Converter A (CSCA) component 1 pre-offset, offset: 0x702C */
  __IO uint32_t HDR_PIPE2_CSCA_IO_2;               /**< Pipe1 Colorspace Converter A (CSCA) component 2 pre-offset, offset: 0x7030 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_MIN_0;           /**< Pipe1 Colorspace Converter A (CSCA) component 0 clip min., offset: 0x7034 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_MIN_1;           /**< Pipe1 Colorspace Converter A (CSCA) component 1 clip min., offset: 0x7038 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_MIN_2;           /**< Pipe1 Colorspace Converter A (CSCA) component 2 clip min., offset: 0x703C */
  __IO uint32_t HDR_PIPE2_CSCA_IO_MAX_0;           /**< Pipe1 Colorspace Converter A (CSCA) component 0 clip max value., offset: 0x7040 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_MAX_1;           /**< Pipe1 Colorspace Converter A (CSCA) component 1 clip max value., offset: 0x7044 */
  __IO uint32_t HDR_PIPE2_CSCA_IO_MAX_2;           /**< Pipe1 Colorspace Converter A (CSCA) component 2 clip max value., offset: 0x7048 */
  __IO uint32_t HDR_PIPE2_CSCA_NORM;               /**< Pipe1 Colorspace Converter A (CSCA) normalization factor, offset: 0x704C */
  __IO uint32_t HDR_PIPE2_CSCA_OO_0;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 0, offset: 0x7050 */
  __IO uint32_t HDR_PIPE2_CSCA_OO_1;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 1, offset: 0x7054 */
  __IO uint32_t HDR_PIPE2_CSCA_OO_2;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 2, offset: 0x7058 */
  __IO uint32_t HDR_PIPE2_CSCA_OMIN_0;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 0, offset: 0x705C */
  __IO uint32_t HDR_PIPE2_CSCA_OMIN_1;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 1, offset: 0x7060 */
  __IO uint32_t HDR_PIPE2_CSCA_OMIN_2;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 2, offset: 0x7064 */
  __IO uint32_t HDR_PIPE2_CSCA_OMAX_0;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 0, offset: 0x7068 */
  __IO uint32_t HDR_PIPE2_CSCA_OMAX_1;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 1, offset: 0x706C */
  __IO uint32_t HDR_PIPE2_CSCA_OMAX_2;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 2, offset: 0x7070 */
       uint32_t HDR_PIPE2_ENTRY_29;                /**< PIPE2: NOT USED, offset: 0x7074 */
       uint8_t RESERVED_9[8];
  __IO uint32_t HDR_PIPE2_LUT_CONTROL_REG;         /**< Pipe1 LUT control register, offset: 0x7080 */
       uint8_t RESERVED_10[1916];
  __IO uint32_t HDR_PIPE2_CSCB_CONTROL_REG;        /**< Pipe1 Colorspace Converter B control., offset: 0x7800 */
  __IO uint32_t HDR_PIPE2_CSCB_H00;                /**< Pipe1 Colorspace Converter A (CSCB) h(0,0) matrix coefficient, offset: 0x7804 */
  __IO uint32_t HDR_PIPE2_CSCB_H10;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,0) matrix coefficient, offset: 0x7808 */
  __IO uint32_t HDR_PIPE2_CSCB_H20;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,0) matrix coefficient, offset: 0x780C */
  __IO uint32_t HDR_PIPE2_CSCB_H01;                /**< Pipe1 Colorspace Converter B (CSCB) h(0,1) matrix coefficient, offset: 0x7810 */
  __IO uint32_t HDR_PIPE2_CSCB_H11;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,1) matrix coefficient, offset: 0x7814 */
  __IO uint32_t HDR_PIPE2_CSCB_H21;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,1) matrix coefficient, offset: 0x7818 */
  __IO uint32_t HDR_PIPE2_CSCB_H02;                /**< Pipe1 Colorspace Converter B (CSCB) h(0,2) matrix coefficient, offset: 0x781C */
  __IO uint32_t HDR_PIPE2_CSCB_H12;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,2) matrix coefficient, offset: 0x7820 */
  __IO uint32_t HDR_PIPE2_CSCB_H22;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,2) matrix coefficient, offset: 0x7824 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_0;               /**< Pipe1 Colorspace Converter B (CSCB) component 0 pre-offset, offset: 0x7828 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_1;               /**< Pipe1 Colorspace Converter B (CSCB) component 1 pre-offset, offset: 0x782C */
  __IO uint32_t HDR_PIPE2_CSCB_IO_2;               /**< Pipe1 Colorspace Converter B (CSCB) component 2 pre-offset, offset: 0x7830 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_MIN_0;           /**< Pipe1 Colorspace Converter B (CSCB) component 0 clip min., offset: 0x7834 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_MIN_1;           /**< Pipe1 Colorspace Converter B (CSCB) component 1 clip min., offset: 0x7838 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_MIN_2;           /**< Pipe1 Colorspace Converter B (CSCB) component 2 clip min., offset: 0x783C */
  __IO uint32_t HDR_PIPE2_CSCB_IO_MAX_0;           /**< Pipe1 Colorspace Converter B (CSCB) component 0 clip max value., offset: 0x7840 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_MAX_1;           /**< Pipe1 Colorspace Converter B (CSCB) component 1 clip max value., offset: 0x7844 */
  __IO uint32_t HDR_PIPE2_CSCB_IO_MAX_2;           /**< Pipe1 Colorspace Converter B (CSCB) component 2 clip max value., offset: 0x7848 */
  __IO uint32_t HDR_PIPE2_CSCB_NORM;               /**< Pipe1 Colorspace Converter B (CSCB) normalization factor, offset: 0x784C */
  __IO uint32_t HDR_PIPE2_CSCB_OO_0;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 0, offset: 0x7850 */
  __IO uint32_t HDR_PIPE2_CSCB_OO_1;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 1, offset: 0x7854 */
  __IO uint32_t HDR_PIPE2_CSCB_OO_2;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 2, offset: 0x7858 */
  __IO uint32_t HDR_PIPE2_CSCB_OMIN_0;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 0, offset: 0x785C */
  __IO uint32_t HDR_PIPE2_CSCB_OMIN_1;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 1, offset: 0x7860 */
  __IO uint32_t HDR_PIPE2_CSCB_OMIN_2;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 2, offset: 0x7864 */
  __IO uint32_t HDR_PIPE2_CSCB_OMAX_0;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 0, offset: 0x7868 */
  __IO uint32_t HDR_PIPE2_CSCB_OMAX_1;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 1, offset: 0x786C */
  __IO uint32_t HDR_PIPE2_CSCB_OMAX_2;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 2, offset: 0x7870 */
  __IO uint32_t HDR_PIPE2_FL2FX;                   /**< Pipe1 floating point to fixed point control, offset: 0x7874 */
       uint32_t HDR_PIPE2_ENTRY_30;                /**< PIPE2: NOT USED, offset: 0x7878 */
       uint8_t RESERVED_11[1924];
  __IO uint32_t PIPE3_A0_LUT;                      /**< A0 component Look-Up-Table. (LUT), offset: 0x8000 */
       uint8_t RESERVED_12[4092];
  __IO uint32_t PIPE3_A1_LUT;                      /**< A1 component Look-Up-Table. (LUT), offset: 0x9000 */
       uint8_t RESERVED_13[4092];
  __IO uint32_t PIPE3_A2_LUT;                      /**< A2 component Look-Up-Table. (LUT), offset: 0xA000 */
       uint8_t RESERVED_14[4092];
  __IO uint32_t HDR_PIPE3_CSCA_CONTROL_REG;        /**< Pipe1 Colorspace Converter A control., offset: 0xB000 */
  __IO uint32_t HDR_PIPE3_CSCA_H00;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,0) matrix coefficient, offset: 0xB004 */
  __IO uint32_t HDR_PIPE3_CSCA_H10;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,0) matrix coefficient, offset: 0xB008 */
  __IO uint32_t HDR_PIPE3_CSCA_H20;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,0) matrix coefficient, offset: 0xB00C */
  __IO uint32_t HDR_PIPE3_CSCA_H01;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,1) matrix coefficient, offset: 0xB010 */
  __IO uint32_t HDR_PIPE3_CSCA_H11;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,1) matrix coefficient, offset: 0xB014 */
  __IO uint32_t HDR_PIPE3_CSCA_H21;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,1) matrix coefficient, offset: 0xB018 */
  __IO uint32_t HDR_PIPE3_CSCA_H02;                /**< Pipe1 Colorspace Converter A (CSCA) h(0,2) matrix coefficient, offset: 0xB01C */
  __IO uint32_t HDR_PIPE3_CSCA_H12;                /**< Pipe1 Colorspace Converter A (CSCA) h(1,2) matrix coefficient, offset: 0xB020 */
  __IO uint32_t HDR_PIPE3_CSCA_H22;                /**< Pipe1 Colorspace Converter A (CSCA) h(2,2) matrix coefficient, offset: 0xB024 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_0;               /**< Pipe1 Colorspace Converter A (CSCA) component 0 pre-offset, offset: 0xB028 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_1;               /**< Pipe1 Colorspace Converter A (CSCA) component 1 pre-offset, offset: 0xB02C */
  __IO uint32_t HDR_PIPE3_CSCA_IO_2;               /**< Pipe1 Colorspace Converter A (CSCA) component 2 pre-offset, offset: 0xB030 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_MIN_0;           /**< Pipe1 Colorspace Converter A (CSCA) component 0 clip min., offset: 0xB034 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_MIN_1;           /**< Pipe1 Colorspace Converter A (CSCA) component 1 clip min., offset: 0xB038 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_MIN_2;           /**< Pipe1 Colorspace Converter A (CSCA) component 2 clip min., offset: 0xB03C */
  __IO uint32_t HDR_PIPE3_CSCA_IO_MAX_0;           /**< Pipe1 Colorspace Converter A (CSCA) component 0 clip max value., offset: 0xB040 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_MAX_1;           /**< Pipe1 Colorspace Converter A (CSCA) component 1 clip max value., offset: 0xB044 */
  __IO uint32_t HDR_PIPE3_CSCA_IO_MAX_2;           /**< Pipe1 Colorspace Converter A (CSCA) component 2 clip max value., offset: 0xB048 */
  __IO uint32_t HDR_PIPE3_CSCA_NORM;               /**< Pipe1 Colorspace Converter A (CSCA) normalization factor, offset: 0xB04C */
  __IO uint32_t HDR_PIPE3_CSCA_OO_0;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 0, offset: 0xB050 */
  __IO uint32_t HDR_PIPE3_CSCA_OO_1;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 1, offset: 0xB054 */
  __IO uint32_t HDR_PIPE3_CSCA_OO_2;               /**< Pipe1 Colorspace Converter A (CSCA): Post offset component 2, offset: 0xB058 */
  __IO uint32_t HDR_PIPE3_CSCA_OMIN_0;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 0, offset: 0xB05C */
  __IO uint32_t HDR_PIPE3_CSCA_OMIN_1;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 1, offset: 0xB060 */
  __IO uint32_t HDR_PIPE3_CSCA_OMIN_2;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 2, offset: 0xB064 */
  __IO uint32_t HDR_PIPE3_CSCA_OMAX_0;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 0, offset: 0xB068 */
  __IO uint32_t HDR_PIPE3_CSCA_OMAX_1;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 1, offset: 0xB06C */
  __IO uint32_t HDR_PIPE3_CSCA_OMAX_2;             /**< Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 2, offset: 0xB070 */
       uint32_t HDR_PIPE3_ENTRY_29;                /**< PIPE3: NOT USED, offset: 0xB074 */
       uint8_t RESERVED_15[8];
  __IO uint32_t HDR_PIPE3_LUT_CONTROL_REG;         /**< Pipe1 LUT control register, offset: 0xB080 */
       uint8_t RESERVED_16[1916];
  __IO uint32_t HDR_PIPE3_CSCB_CONTROL_REG;        /**< Pipe1 Colorspace Converter B control., offset: 0xB800 */
  __IO uint32_t HDR_PIPE3_CSCB_H00;                /**< Pipe1 Colorspace Converter A (CSCB) h(0,0) matrix coefficient, offset: 0xB804 */
  __IO uint32_t HDR_PIPE3_CSCB_H10;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,0) matrix coefficient, offset: 0xB808 */
  __IO uint32_t HDR_PIPE3_CSCB_H20;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,0) matrix coefficient, offset: 0xB80C */
  __IO uint32_t HDR_PIPE3_CSCB_H01;                /**< Pipe1 Colorspace Converter B (CSCB) h(0,1) matrix coefficient, offset: 0xB810 */
  __IO uint32_t HDR_PIPE3_CSCB_H11;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,1) matrix coefficient, offset: 0xB814 */
  __IO uint32_t HDR_PIPE3_CSCB_H21;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,1) matrix coefficient, offset: 0xB818 */
  __IO uint32_t HDR_PIPE3_CSCB_H02;                /**< Pipe1 Colorspace Converter B (CSCB) h(0,2) matrix coefficient, offset: 0xB81C */
  __IO uint32_t HDR_PIPE3_CSCB_H12;                /**< Pipe1 Colorspace Converter B (CSCB) h(1,2) matrix coefficient, offset: 0xB820 */
  __IO uint32_t HDR_PIPE3_CSCB_H22;                /**< Pipe1 Colorspace Converter B (CSCB) h(2,2) matrix coefficient, offset: 0xB824 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_0;               /**< Pipe1 Colorspace Converter B (CSCB) component 0 pre-offset, offset: 0xB828 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_1;               /**< Pipe1 Colorspace Converter B (CSCB) component 1 pre-offset, offset: 0xB82C */
  __IO uint32_t HDR_PIPE3_CSCB_IO_2;               /**< Pipe1 Colorspace Converter B (CSCB) component 2 pre-offset, offset: 0xB830 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_MIN_0;           /**< Pipe1 Colorspace Converter B (CSCB) component 0 clip min., offset: 0xB834 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_MIN_1;           /**< Pipe1 Colorspace Converter B (CSCB) component 1 clip min., offset: 0xB838 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_MIN_2;           /**< Pipe1 Colorspace Converter B (CSCB) component 2 clip min., offset: 0xB83C */
  __IO uint32_t HDR_PIPE3_CSCB_IO_MAX_0;           /**< Pipe1 Colorspace Converter B (CSCB) component 0 clip max value., offset: 0xB840 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_MAX_1;           /**< Pipe1 Colorspace Converter B (CSCB) component 1 clip max value., offset: 0xB844 */
  __IO uint32_t HDR_PIPE3_CSCB_IO_MAX_2;           /**< Pipe1 Colorspace Converter B (CSCB) component 2 clip max value., offset: 0xB848 */
  __IO uint32_t HDR_PIPE3_CSCB_NORM;               /**< Pipe1 Colorspace Converter B (CSCB) normalization factor, offset: 0xB84C */
  __IO uint32_t HDR_PIPE3_CSCB_OO_0;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 0, offset: 0xB850 */
  __IO uint32_t HDR_PIPE3_CSCB_OO_1;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 1, offset: 0xB854 */
  __IO uint32_t HDR_PIPE3_CSCB_OO_2;               /**< Pipe1 Colorspace Converter B (CSCB): Post offset component 2, offset: 0xB858 */
  __IO uint32_t HDR_PIPE3_CSCB_OMIN_0;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 0, offset: 0xB85C */
  __IO uint32_t HDR_PIPE3_CSCB_OMIN_1;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 1, offset: 0xB860 */
  __IO uint32_t HDR_PIPE3_CSCB_OMIN_2;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 2, offset: 0xB864 */
  __IO uint32_t HDR_PIPE3_CSCB_OMAX_0;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 0, offset: 0xB868 */
  __IO uint32_t HDR_PIPE3_CSCB_OMAX_1;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 1, offset: 0xB86C */
  __IO uint32_t HDR_PIPE3_CSCB_OMAX_2;             /**< Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 2, offset: 0xB870 */
  __IO uint32_t HDR_PIPE3_FL2FX;                   /**< Pipe1 floating point to fixed point control, offset: 0xB874 */
       uint32_t HDR_PIPE3_ENTRY_30;                /**< PIPE3: NOT USED, offset: 0xB878 */
       uint8_t RESERVED_17[1924];
  __IO uint32_t OPIPE_A0_TABLE;                    /**< A0 component Linear-to-Non-linear conversion table, offset: 0xC000 */
       uint8_t RESERVED_18[4092];
  __IO uint32_t OPIPE_A1_TABLE;                    /**< A1 component Linear-to-Non-linear conversion table, offset: 0xD000 */
       uint8_t RESERVED_19[4092];
  __IO uint32_t OPIPE_A2_TABLE;                    /**< A2 component Linear-to-Non-linear conversion table, offset: 0xE000 */
       uint8_t RESERVED_20[4092];
  __IO uint32_t HDR_OPIPE_CSC_CONTROL_REG;         /**< HDR output stage Colorspace Converter (CSCO) control., offset: 0xF000 */
  __IO uint32_t HDR_OPIPE_CSC_H00;                 /**< Pipe1 Colorspace Converter (CSC) h(0,0) matrix coefficient, offset: 0xF004 */
  __IO uint32_t HDR_OPIPE_CSC_H10;                 /**< Pipe1 Colorspace Converter (CSC) h(1,0) matrix coefficient, offset: 0xF008 */
  __IO uint32_t HDR_OPIPE_CSC_H20;                 /**< HDR OUTPUT Colorspace Converter (CSCO) h(2,0) matrix coefficient, offset: 0xF00C */
  __IO uint32_t HDR_OPIPE_CSC_H01;                 /**< HDR OUTPUT pipe Colorspace Converter (CSCO) h(0,1) matrix coefficient, offset: 0xF010 */
  __IO uint32_t HDR_OPIPE_CSC_H11;                 /**< HDR OUTPUT pipe Colorspace Converter (CSCO) h(1,1) matrix coefficient, offset: 0xF014 */
  __IO uint32_t HDR_OPIPE_CSC_H21;                 /**< HDR_output pipe Colorspace Converter (CSCO) h(2,1) matrix coefficient, offset: 0xF018 */
  __IO uint32_t HDR_OPIPE_CSC_H02;                 /**< HDR OUTPUT pipe Colorspace Converter (CSCO) h(0,2) matrix coefficient, offset: 0xF01C */
  __IO uint32_t HDR_OPIPE_CSC_H12;                 /**< HDR OUPUT pipe Colorspace Converter (CSCO) h(1,2) matrix coefficient, offset: 0xF020 */
  __IO uint32_t HDR_;                              /**< HDR OUPUT pipe Colorspace Converter (CSCO) h(2,2) matrix coefficient, offset: 0xF024 */
  __IO uint32_t HDR_OPIPE_CSC_IO_0;                /**< HDR OUTPUT pipe Colorspace Converter (CSCO) component 0 pre-offset, offset: 0xF028 */
  __IO uint32_t HDR_OPIPE_CSC_IO_1;                /**< HDR OUPTUT pipe Colorspace Converter (CSCO) component 1 pre-offset, offset: 0xF02C */
  __IO uint32_t HDR_OPIPE_CSC_IO_2;                /**< HDR OUPUT pipe: Colorspace Converter (CSCO) component 2 pre-offset, offset: 0xF030 */
  __IO uint32_t HDR_OPIPE_CSC_MIN_0;               /**< HDR OUPTU pipe Colorspace Converter (CSCO) component 0 clip min., offset: 0xF034 */
  __IO uint32_t HDR_OPIPE_CSC_MIN_1;               /**< HDR OUPUT pipe Colorspace Converter (CSCO) component 1 clip min., offset: 0xF038 */
  __IO uint32_t HDR_OPIPE_CSC_MIN_2;               /**< HDR OUPTU pipe Colorspace Converter (CSCO) component 2 clip min., offset: 0xF03C */
  __IO uint32_t HDR_OPIPE_CSC_MAX_0;               /**< HDR OUPTUT pipe Colorspace Converter O (CSC) component 0 clip max value., offset: 0xF040 */
  __IO uint32_t HDR_OPIPE_CSC_MAX_1;               /**< HDR OUTPUT pipe Colorspace Converter (CSCO) component 1 clip max value., offset: 0xF044 */
  __IO uint32_t HDR_OPIPE_CSC_MAX_2;               /**< HDR OUTPUT pipe Colorspace Converter (CSCO) component 2 clip max value., offset: 0xF048 */
  __IO uint32_t HDR_OPIPE_CSC_NORM;                /**< HDR OUPUT pipe Colorspace Converter (CSCO) normalization factor, offset: 0xF04C */
  __IO uint32_t HDR_OPIPE_CSC_OO_0;                /**< HDR OUPTUT pipe Colorspace Converter (CSC): Post offset component 0, offset: 0xF050 */
  __IO uint32_t HDR_OPIPE_CSC_OO_1;                /**< HDR OUTPUT pipe Colorspace Converter (CSC): Post offset component 1, offset: 0xF054 */
  __IO uint32_t HDR_OPIPE_CSC_OO_2;                /**< HDR OUPTUT pipe Colorspace Converter (CSC): Post offset component 2, offset: 0xF058 */
  __IO uint32_t HDR_OPIPE_CSC_OMIN_0;              /**< HDR OUTPUT pipe Colorspace Converter (CSC): Post offset min clip value for component 0, offset: 0xF05C */
  __IO uint32_t HDR_OPIPE_CSC_OMIN_1;              /**< HDR OUTPUT pipe Colorspace Converter (CSC): Post offset min clip value for component 1, offset: 0xF060 */
  __IO uint32_t HDR_OPIPE_CSC_OMIN_2;              /**< HDR OUTPUT pipe Colorspace Converter (CSC): Post offset min clip value for component 2, offset: 0xF064 */
  __IO uint32_t HDR_OPIPE_CSC_OMAX_0;              /**< HDR OUPTUT pipe Colorspace Converter (CSC): Post offset max clip value for component 0, offset: 0xF068 */
  __IO uint32_t HDR_OPIPE_CSC_OMAX_1;              /**< HDR OUTPUT pipe Colorspace Converter (CSC): Post offset max clip value for component 1, offset: 0xF06C */
  __IO uint32_t HDR_OPIPE_CSC_OMAX_2;              /**< HDR OUTPUT pipe Colorspace Converter (CSC): Post offset max clip value for component 2, offset: 0xF070 */
       uint8_t RESERVED_21[2048];
  __IO uint32_t HDR_OPIPE_2NL_CONTROL_REG;         /**< HDR OUTPUT -TO NON LINEAR pipeline control, offset: 0xF874 */
} MED_HDR10_Type;

/* ----------------------------------------------------------------------------
   -- MED_HDR10 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MED_HDR10_Register_Masks MED_HDR10 Register Masks
 * @{
 */

/*! @name PIPE1_A0_LUT - A0 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE1_A0_LUT_PIPE1_A0_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE1_A0_LUT_PIPE1_A0_LUT_SHIFT (0U)
#define MED_HDR10_PIPE1_A0_LUT_PIPE1_A0_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE1_A0_LUT_PIPE1_A0_LUT_SHIFT)) & MED_HDR10_PIPE1_A0_LUT_PIPE1_A0_LUT_MASK)
/*! @} */

/*! @name PIPE1_A1_LUT - A1 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE1_A1_LUT_PIPE1_A1_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE1_A1_LUT_PIPE1_A1_LUT_SHIFT (0U)
#define MED_HDR10_PIPE1_A1_LUT_PIPE1_A1_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE1_A1_LUT_PIPE1_A1_LUT_SHIFT)) & MED_HDR10_PIPE1_A1_LUT_PIPE1_A1_LUT_MASK)
/*! @} */

/*! @name PIPE1_A2_LUT - A2 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE1_A2_LUT_PIPE1_A2_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE1_A2_LUT_PIPE1_A2_LUT_SHIFT (0U)
#define MED_HDR10_PIPE1_A2_LUT_PIPE1_A2_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE1_A2_LUT_PIPE1_A2_LUT_SHIFT)) & MED_HDR10_PIPE1_A2_LUT_PIPE1_A2_LUT_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_CONTROL_REG - Pipe1 Colorspace Converter A control. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H00 - Pipe1 Colorspace Converter A (CSCA) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H00_H00_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H00_H00_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H00_H00(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H00_H00_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H00_H00_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H10 - Pipe1 Colorspace Converter A (CSCA) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H10_H10_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H10_H10_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H10_H10(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H10_H10_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H10_H10_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H20 - Pipe1 Colorspace Converter A (CSCA) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H20_H20_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H20_H20_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H20_H20(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H20_H20_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H20_H20_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H01 - Pipe1 Colorspace Converter A (CSCA) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H01_H01_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H01_H01_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H01_H01(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H01_H01_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H01_H01_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H11 - Pipe1 Colorspace Converter A (CSCA) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H11_H11_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H11_H11_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H11_H11(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H11_H11_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H11_H11_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H21 - Pipe1 Colorspace Converter A (CSCA) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H21_H21_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H21_H21_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H21_H21(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H21_H21_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H21_H21_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H02 - Pipe1 Colorspace Converter A (CSCA) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H02_H02_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H02_H02_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H02_H02(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H02_H02_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H02_H02_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H12 - Pipe1 Colorspace Converter A (CSCA) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H12_H12_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H12_H12_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H12_H12(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H12_H12_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H12_H12_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_H22 - Pipe1 Colorspace Converter A (CSCA) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_H22_H22_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_H22_H22_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_H22_H22(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_H22_H22_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_H22_H22_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_0 - Pipe1 Colorspace Converter A (CSCA) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_1 - Pipe1 Colorspace Converter A (CSCA) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_2 - Pipe1 Colorspace Converter A (CSCA) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_MIN_0 - Pipe1 Colorspace Converter A (CSCA) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_MIN_1 - Pipe1 Colorspace Converter A (CSCA) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_MIN_2 - Pipe1 Colorspace Converter A (CSCA) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_MAX_0 - Pipe1 Colorspace Converter A (CSCA) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_MAX_1 - Pipe1 Colorspace Converter A (CSCA) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_IO_MAX_2 - Pipe1 Colorspace Converter A (CSCA) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_IO_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_NORM - Pipe1 Colorspace Converter A (CSCA) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_NORM_CSCA_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_PIPE1_CSCA_NORM_CSCA_NORM_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_NORM_CSCA_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_NORM_CSCA_NORM_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_NORM_CSCA_NORM_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OO_0 - Pipe1 Colorspace Converter A (CSCA): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OO_0_CSCA_OO_0_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OO_0_CSCA_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OO_0_CSCA_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OO_0_CSCA_OO_0_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OO_0_CSCA_OO_0_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OO_1 - Pipe1 Colorspace Converter A (CSCA): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OO_1_CSCA_OO_1_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OO_1_CSCA_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OO_1_CSCA_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OO_1_CSCA_OO_1_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OO_1_CSCA_OO_1_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OO_2 - Pipe1 Colorspace Converter A (CSCA): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OO_2_CSCA_OO_2_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OO_2_CSCA_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OO_2_CSCA_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OO_2_CSCA_OO_2_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OO_2_CSCA_OO_2_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OMIN_0 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_0_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OMIN_1 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_1_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OMIN_2 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_2_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OMAX_0 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_0_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OMAX_1 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCA_OMAX_2 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_2_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCA_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCA_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCA_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_LUT_CONTROL_REG - Pipe1 LUT control register */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE1_LUT_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_CONTROL_REG - Pipe1 Colorspace Converter B control. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H00 - Pipe1 Colorspace Converter A (CSCB) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H00_H00_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H00_H00_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H00_H00(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H00_H00_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H00_H00_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H10 - Pipe1 Colorspace Converter B (CSCB) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H10_H10_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H10_H10_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H10_H10(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H10_H10_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H10_H10_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H20 - Pipe1 Colorspace Converter B (CSCB) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H20_H20_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H20_H20_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H20_H20(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H20_H20_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H20_H20_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H01 - Pipe1 Colorspace Converter B (CSCB) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H01_H01_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H01_H01_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H01_H01(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H01_H01_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H01_H01_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H11 - Pipe1 Colorspace Converter B (CSCB) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H11_H11_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H11_H11_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H11_H11(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H11_H11_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H11_H11_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H21 - Pipe1 Colorspace Converter B (CSCB) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H21_H21_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H21_H21_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H21_H21(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H21_H21_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H21_H21_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H02 - Pipe1 Colorspace Converter B (CSCB) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H02_H02_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H02_H02_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H02_H02(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H02_H02_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H02_H02_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H12 - Pipe1 Colorspace Converter B (CSCB) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H12_H12_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H12_H12_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H12_H12(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H12_H12_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H12_H12_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_H22 - Pipe1 Colorspace Converter B (CSCB) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_H22_H22_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_H22_H22_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_H22_H22(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_H22_H22_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_H22_H22_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_0 - Pipe1 Colorspace Converter B (CSCB) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_1 - Pipe1 Colorspace Converter B (CSCB) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_2 - Pipe1 Colorspace Converter B (CSCB) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_MIN_0 - Pipe1 Colorspace Converter B (CSCB) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_MIN_1 - Pipe1 Colorspace Converter B (CSCB) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_MIN_2 - Pipe1 Colorspace Converter B (CSCB) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_MAX_0 - Pipe1 Colorspace Converter B (CSCB) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_MAX_1 - Pipe1 Colorspace Converter B (CSCB) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_IO_MAX_2 - Pipe1 Colorspace Converter B (CSCB) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_IO_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_NORM - Pipe1 Colorspace Converter B (CSCB) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_NORM_CSCB_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_PIPE1_CSCB_NORM_CSCB_NORM_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_NORM_CSCB_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_NORM_CSCB_NORM_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_NORM_CSCB_NORM_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OO_0 - Pipe1 Colorspace Converter B (CSCB): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OO_0_CSCB_OO_0_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OO_0_CSCB_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OO_0_CSCB_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OO_0_CSCB_OO_0_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OO_0_CSCB_OO_0_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OO_1 - Pipe1 Colorspace Converter B (CSCB): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OO_1_CSCB_OO_1_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OO_1_CSCB_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OO_1_CSCB_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OO_1_CSCB_OO_1_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OO_1_CSCB_OO_1_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OO_2 - Pipe1 Colorspace Converter B (CSCB): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OO_2_CSCB_OO_2_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OO_2_CSCB_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OO_2_CSCB_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OO_2_CSCB_OO_2_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OO_2_CSCB_OO_2_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OMIN_0 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_0_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OMIN_1 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_1_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OMIN_2 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_2_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OMAX_0 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_0_POST_OFF_MAX_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OMAX_1 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_CSCB_OMAX_2 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_2_POST_OFF_MAX_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE1_CSCB_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_CSCB_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE1_CSCB_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE1_FL2FX - Pipe1 floating point to fixed point control */
/*! @{ */

#define MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_MASK    (0x1U)
#define MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE1_FL2FX_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE1_FL2FX_ENABLE_FOR_ALL_PELS_MASK)
/*! @} */

/*! @name PIPE2_A0_LUT - A0 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE2_A0_LUT_PIPE2_A0_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE2_A0_LUT_PIPE2_A0_LUT_SHIFT (0U)
#define MED_HDR10_PIPE2_A0_LUT_PIPE2_A0_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE2_A0_LUT_PIPE2_A0_LUT_SHIFT)) & MED_HDR10_PIPE2_A0_LUT_PIPE2_A0_LUT_MASK)
/*! @} */

/*! @name PIPE2_A1_LUT - A1 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE2_A1_LUT_PIPE2_A1_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE2_A1_LUT_PIPE2_A1_LUT_SHIFT (0U)
#define MED_HDR10_PIPE2_A1_LUT_PIPE2_A1_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE2_A1_LUT_PIPE2_A1_LUT_SHIFT)) & MED_HDR10_PIPE2_A1_LUT_PIPE2_A1_LUT_MASK)
/*! @} */

/*! @name PIPE2_A2_LUT - A2 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE2_A2_LUT_PIPE2_A2_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE2_A2_LUT_PIPE2_A2_LUT_SHIFT (0U)
#define MED_HDR10_PIPE2_A2_LUT_PIPE2_A2_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE2_A2_LUT_PIPE2_A2_LUT_SHIFT)) & MED_HDR10_PIPE2_A2_LUT_PIPE2_A2_LUT_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_CONTROL_REG - Pipe1 Colorspace Converter A control. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H00 - Pipe1 Colorspace Converter A (CSCA) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H00_H00_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H00_H00_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H00_H00(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H00_H00_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H00_H00_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H10 - Pipe1 Colorspace Converter A (CSCA) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H10_H10_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H10_H10_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H10_H10(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H10_H10_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H10_H10_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H20 - Pipe1 Colorspace Converter A (CSCA) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H20_H20_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H20_H20_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H20_H20(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H20_H20_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H20_H20_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H01 - Pipe1 Colorspace Converter A (CSCA) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H01_H01_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H01_H01_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H01_H01(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H01_H01_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H01_H01_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H11 - Pipe1 Colorspace Converter A (CSCA) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H11_H11_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H11_H11_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H11_H11(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H11_H11_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H11_H11_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H21 - Pipe1 Colorspace Converter A (CSCA) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H21_H21_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H21_H21_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H21_H21(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H21_H21_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H21_H21_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H02 - Pipe1 Colorspace Converter A (CSCA) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H02_H02_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H02_H02_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H02_H02(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H02_H02_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H02_H02_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H12 - Pipe1 Colorspace Converter A (CSCA) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H12_H12_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H12_H12_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H12_H12(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H12_H12_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H12_H12_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_H22 - Pipe1 Colorspace Converter A (CSCA) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_H22_H22_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_H22_H22_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_H22_H22(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_H22_H22_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_H22_H22_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_0 - Pipe1 Colorspace Converter A (CSCA) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_1 - Pipe1 Colorspace Converter A (CSCA) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_2 - Pipe1 Colorspace Converter A (CSCA) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_MIN_0 - Pipe1 Colorspace Converter A (CSCA) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_MIN_1 - Pipe1 Colorspace Converter A (CSCA) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_MIN_2 - Pipe1 Colorspace Converter A (CSCA) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_MAX_0 - Pipe1 Colorspace Converter A (CSCA) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_MAX_1 - Pipe1 Colorspace Converter A (CSCA) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_IO_MAX_2 - Pipe1 Colorspace Converter A (CSCA) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_IO_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_NORM - Pipe1 Colorspace Converter A (CSCA) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_NORM_CSCA_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_PIPE2_CSCA_NORM_CSCA_NORM_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_NORM_CSCA_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_NORM_CSCA_NORM_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_NORM_CSCA_NORM_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OO_0 - Pipe1 Colorspace Converter A (CSCA): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OO_0_CSCA_OO_0_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OO_0_CSCA_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OO_0_CSCA_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OO_0_CSCA_OO_0_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OO_0_CSCA_OO_0_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OO_1 - Pipe1 Colorspace Converter A (CSCA): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OO_1_CSCA_OO_1_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OO_1_CSCA_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OO_1_CSCA_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OO_1_CSCA_OO_1_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OO_1_CSCA_OO_1_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OO_2 - Pipe1 Colorspace Converter A (CSCA): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OO_2_CSCA_OO_2_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OO_2_CSCA_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OO_2_CSCA_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OO_2_CSCA_OO_2_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OO_2_CSCA_OO_2_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OMIN_0 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_0_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OMIN_1 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_1_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OMIN_2 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_2_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OMAX_0 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_0_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OMAX_1 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCA_OMAX_2 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_2_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCA_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCA_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCA_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_LUT_CONTROL_REG - Pipe1 LUT control register */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE2_LUT_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_CONTROL_REG - Pipe1 Colorspace Converter B control. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H00 - Pipe1 Colorspace Converter A (CSCB) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H00_H00_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H00_H00_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H00_H00(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H00_H00_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H00_H00_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H10 - Pipe1 Colorspace Converter B (CSCB) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H10_H10_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H10_H10_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H10_H10(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H10_H10_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H10_H10_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H20 - Pipe1 Colorspace Converter B (CSCB) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H20_H20_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H20_H20_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H20_H20(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H20_H20_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H20_H20_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H01 - Pipe1 Colorspace Converter B (CSCB) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H01_H01_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H01_H01_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H01_H01(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H01_H01_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H01_H01_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H11 - Pipe1 Colorspace Converter B (CSCB) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H11_H11_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H11_H11_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H11_H11(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H11_H11_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H11_H11_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H21 - Pipe1 Colorspace Converter B (CSCB) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H21_H21_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H21_H21_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H21_H21(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H21_H21_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H21_H21_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H02 - Pipe1 Colorspace Converter B (CSCB) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H02_H02_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H02_H02_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H02_H02(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H02_H02_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H02_H02_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H12 - Pipe1 Colorspace Converter B (CSCB) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H12_H12_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H12_H12_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H12_H12(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H12_H12_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H12_H12_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_H22 - Pipe1 Colorspace Converter B (CSCB) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_H22_H22_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_H22_H22_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_H22_H22(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_H22_H22_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_H22_H22_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_0 - Pipe1 Colorspace Converter B (CSCB) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_1 - Pipe1 Colorspace Converter B (CSCB) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_2 - Pipe1 Colorspace Converter B (CSCB) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_MIN_0 - Pipe1 Colorspace Converter B (CSCB) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_MIN_1 - Pipe1 Colorspace Converter B (CSCB) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_MIN_2 - Pipe1 Colorspace Converter B (CSCB) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_MAX_0 - Pipe1 Colorspace Converter B (CSCB) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_MAX_1 - Pipe1 Colorspace Converter B (CSCB) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_IO_MAX_2 - Pipe1 Colorspace Converter B (CSCB) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_IO_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_NORM - Pipe1 Colorspace Converter B (CSCB) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_NORM_CSCB_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_PIPE2_CSCB_NORM_CSCB_NORM_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_NORM_CSCB_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_NORM_CSCB_NORM_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_NORM_CSCB_NORM_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OO_0 - Pipe1 Colorspace Converter B (CSCB): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OO_0_CSCB_OO_0_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OO_0_CSCB_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OO_0_CSCB_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OO_0_CSCB_OO_0_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OO_0_CSCB_OO_0_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OO_1 - Pipe1 Colorspace Converter B (CSCB): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OO_1_CSCB_OO_1_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OO_1_CSCB_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OO_1_CSCB_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OO_1_CSCB_OO_1_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OO_1_CSCB_OO_1_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OO_2 - Pipe1 Colorspace Converter B (CSCB): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OO_2_CSCB_OO_2_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OO_2_CSCB_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OO_2_CSCB_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OO_2_CSCB_OO_2_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OO_2_CSCB_OO_2_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OMIN_0 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_0_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OMIN_1 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_1_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OMIN_2 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_2_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OMAX_0 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_0_POST_OFF_MAX_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OMAX_1 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_CSCB_OMAX_2 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_2_POST_OFF_MAX_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE2_CSCB_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_CSCB_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE2_CSCB_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE2_FL2FX - Pipe1 floating point to fixed point control */
/*! @{ */

#define MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_MASK    (0x1U)
#define MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE2_FL2FX_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE2_FL2FX_ENABLE_FOR_ALL_PELS_MASK)
/*! @} */

/*! @name PIPE3_A0_LUT - A0 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE3_A0_LUT_PIPE3_A0_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE3_A0_LUT_PIPE3_A0_LUT_SHIFT (0U)
#define MED_HDR10_PIPE3_A0_LUT_PIPE3_A0_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE3_A0_LUT_PIPE3_A0_LUT_SHIFT)) & MED_HDR10_PIPE3_A0_LUT_PIPE3_A0_LUT_MASK)
/*! @} */

/*! @name PIPE3_A1_LUT - A1 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE3_A1_LUT_PIPE3_A1_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE3_A1_LUT_PIPE3_A1_LUT_SHIFT (0U)
#define MED_HDR10_PIPE3_A1_LUT_PIPE3_A1_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE3_A1_LUT_PIPE3_A1_LUT_SHIFT)) & MED_HDR10_PIPE3_A1_LUT_PIPE3_A1_LUT_MASK)
/*! @} */

/*! @name PIPE3_A2_LUT - A2 component Look-Up-Table. (LUT) */
/*! @{ */

#define MED_HDR10_PIPE3_A2_LUT_PIPE3_A2_LUT_MASK (0x3FFFU)
#define MED_HDR10_PIPE3_A2_LUT_PIPE3_A2_LUT_SHIFT (0U)
#define MED_HDR10_PIPE3_A2_LUT_PIPE3_A2_LUT(x)   (((uint32_t)(((uint32_t)(x)) << MED_HDR10_PIPE3_A2_LUT_PIPE3_A2_LUT_SHIFT)) & MED_HDR10_PIPE3_A2_LUT_PIPE3_A2_LUT_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_CONTROL_REG - Pipe1 Colorspace Converter A control. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H00 - Pipe1 Colorspace Converter A (CSCA) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H00_H00_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H00_H00_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H00_H00(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H00_H00_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H00_H00_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H10 - Pipe1 Colorspace Converter A (CSCA) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H10_H10_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H10_H10_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H10_H10(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H10_H10_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H10_H10_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H20 - Pipe1 Colorspace Converter A (CSCA) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H20_H20_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H20_H20_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H20_H20(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H20_H20_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H20_H20_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H01 - Pipe1 Colorspace Converter A (CSCA) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H01_H01_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H01_H01_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H01_H01(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H01_H01_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H01_H01_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H11 - Pipe1 Colorspace Converter A (CSCA) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H11_H11_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H11_H11_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H11_H11(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H11_H11_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H11_H11_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H21 - Pipe1 Colorspace Converter A (CSCA) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H21_H21_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H21_H21_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H21_H21(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H21_H21_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H21_H21_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H02 - Pipe1 Colorspace Converter A (CSCA) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H02_H02_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H02_H02_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H02_H02(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H02_H02_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H02_H02_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H12 - Pipe1 Colorspace Converter A (CSCA) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H12_H12_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H12_H12_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H12_H12(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H12_H12_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H12_H12_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_H22 - Pipe1 Colorspace Converter A (CSCA) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_H22_H22_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_H22_H22_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_H22_H22(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_H22_H22_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_H22_H22_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_0 - Pipe1 Colorspace Converter A (CSCA) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_1 - Pipe1 Colorspace Converter A (CSCA) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_2 - Pipe1 Colorspace Converter A (CSCA) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_MIN_0 - Pipe1 Colorspace Converter A (CSCA) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_MIN_1 - Pipe1 Colorspace Converter A (CSCA) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_MIN_2 - Pipe1 Colorspace Converter A (CSCA) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_MAX_0 - Pipe1 Colorspace Converter A (CSCA) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_MAX_1 - Pipe1 Colorspace Converter A (CSCA) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_IO_MAX_2 - Pipe1 Colorspace Converter A (CSCA) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_IO_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_NORM - Pipe1 Colorspace Converter A (CSCA) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_NORM_CSCA_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_PIPE3_CSCA_NORM_CSCA_NORM_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_NORM_CSCA_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_NORM_CSCA_NORM_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_NORM_CSCA_NORM_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OO_0 - Pipe1 Colorspace Converter A (CSCA): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OO_0_CSCA_OO_0_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OO_0_CSCA_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OO_0_CSCA_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OO_0_CSCA_OO_0_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OO_0_CSCA_OO_0_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OO_1 - Pipe1 Colorspace Converter A (CSCA): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OO_1_CSCA_OO_1_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OO_1_CSCA_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OO_1_CSCA_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OO_1_CSCA_OO_1_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OO_1_CSCA_OO_1_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OO_2 - Pipe1 Colorspace Converter A (CSCA): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OO_2_CSCA_OO_2_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OO_2_CSCA_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OO_2_CSCA_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OO_2_CSCA_OO_2_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OO_2_CSCA_OO_2_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OMIN_0 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_0_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OMIN_1 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_1_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OMIN_2 - Pipe1 Colorspace Converter A (CSCA): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_2_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OMAX_0 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_0_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OMAX_1 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCA_OMAX_2 - Pipe1 Colorspace Converter A (CSCA): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_2_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCA_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCA_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCA_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_LUT_CONTROL_REG - Pipe1 LUT control register */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE3_LUT_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_CONTROL_REG - Pipe1 Colorspace Converter B control. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H00 - Pipe1 Colorspace Converter A (CSCB) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H00_H00_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H00_H00_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H00_H00(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H00_H00_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H00_H00_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H10 - Pipe1 Colorspace Converter B (CSCB) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H10_H10_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H10_H10_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H10_H10(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H10_H10_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H10_H10_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H20 - Pipe1 Colorspace Converter B (CSCB) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H20_H20_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H20_H20_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H20_H20(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H20_H20_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H20_H20_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H01 - Pipe1 Colorspace Converter B (CSCB) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H01_H01_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H01_H01_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H01_H01(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H01_H01_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H01_H01_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H11 - Pipe1 Colorspace Converter B (CSCB) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H11_H11_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H11_H11_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H11_H11(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H11_H11_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H11_H11_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H21 - Pipe1 Colorspace Converter B (CSCB) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H21_H21_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H21_H21_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H21_H21(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H21_H21_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H21_H21_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H02 - Pipe1 Colorspace Converter B (CSCB) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H02_H02_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H02_H02_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H02_H02(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H02_H02_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H02_H02_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H12 - Pipe1 Colorspace Converter B (CSCB) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H12_H12_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H12_H12_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H12_H12(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H12_H12_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H12_H12_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_H22 - Pipe1 Colorspace Converter B (CSCB) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_H22_H22_MASK    (0xFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_H22_H22_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_H22_H22(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_H22_H22_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_H22_H22_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_0 - Pipe1 Colorspace Converter B (CSCB) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_1 - Pipe1 Colorspace Converter B (CSCB) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_2 - Pipe1 Colorspace Converter B (CSCB) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_MIN_0 - Pipe1 Colorspace Converter B (CSCB) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_MIN_1 - Pipe1 Colorspace Converter B (CSCB) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_MIN_2 - Pipe1 Colorspace Converter B (CSCB) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_MAX_0 - Pipe1 Colorspace Converter B (CSCB) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_MAX_1 - Pipe1 Colorspace Converter B (CSCB) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_IO_MAX_2 - Pipe1 Colorspace Converter B (CSCB) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_IO_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_NORM - Pipe1 Colorspace Converter B (CSCB) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_NORM_CSCB_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_PIPE3_CSCB_NORM_CSCB_NORM_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_NORM_CSCB_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_NORM_CSCB_NORM_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_NORM_CSCB_NORM_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OO_0 - Pipe1 Colorspace Converter B (CSCB): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OO_0_CSCB_OO_0_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OO_0_CSCB_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OO_0_CSCB_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OO_0_CSCB_OO_0_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OO_0_CSCB_OO_0_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OO_1 - Pipe1 Colorspace Converter B (CSCB): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OO_1_CSCB_OO_1_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OO_1_CSCB_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OO_1_CSCB_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OO_1_CSCB_OO_1_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OO_1_CSCB_OO_1_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OO_2 - Pipe1 Colorspace Converter B (CSCB): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OO_2_CSCB_OO_2_MASK (0x1FFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OO_2_CSCB_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OO_2_CSCB_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OO_2_CSCB_OO_2_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OO_2_CSCB_OO_2_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OMIN_0 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_0_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OMIN_1 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_1_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OMIN_2 - Pipe1 Colorspace Converter B (CSCB): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_2_POST_OFF_MIN_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OMAX_0 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_0_POST_OFF_MAX_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OMAX_1 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_CSCB_OMAX_2 - Pipe1 Colorspace Converter B (CSCB): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_2_POST_OFF_MAX_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_PIPE3_CSCB_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_CSCB_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_PIPE3_CSCB_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_PIPE3_FL2FX - Pipe1 floating point to fixed point control */
/*! @{ */

#define MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_MASK    (0x1U)
#define MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_SHIFT   (0U)
#define MED_HDR10_HDR_PIPE3_FL2FX_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_SHIFT)) & MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_MASK)

#define MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_PIPE3_FL2FX_ENABLE_FOR_ALL_PELS_MASK)
/*! @} */

/*! @name OPIPE_A0_TABLE - A0 component Linear-to-Non-linear conversion table */
/*! @{ */

#define MED_HDR10_OPIPE_A0_TABLE_OPIPE_A0_TABLE_MASK (0x3FFFU)
#define MED_HDR10_OPIPE_A0_TABLE_OPIPE_A0_TABLE_SHIFT (0U)
#define MED_HDR10_OPIPE_A0_TABLE_OPIPE_A0_TABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_OPIPE_A0_TABLE_OPIPE_A0_TABLE_SHIFT)) & MED_HDR10_OPIPE_A0_TABLE_OPIPE_A0_TABLE_MASK)
/*! @} */

/*! @name OPIPE_A1_TABLE - A1 component Linear-to-Non-linear conversion table */
/*! @{ */

#define MED_HDR10_OPIPE_A1_TABLE_OPIPE_A1_TABLE_MASK (0x3FFFU)
#define MED_HDR10_OPIPE_A1_TABLE_OPIPE_A1_TABLE_SHIFT (0U)
#define MED_HDR10_OPIPE_A1_TABLE_OPIPE_A1_TABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_OPIPE_A1_TABLE_OPIPE_A1_TABLE_SHIFT)) & MED_HDR10_OPIPE_A1_TABLE_OPIPE_A1_TABLE_MASK)
/*! @} */

/*! @name OPIPE_A2_TABLE - A2 component Linear-to-Non-linear conversion table */
/*! @{ */

#define MED_HDR10_OPIPE_A2_TABLE_OPIPE_A2_TABLE_MASK (0x3FFFU)
#define MED_HDR10_OPIPE_A2_TABLE_OPIPE_A2_TABLE_SHIFT (0U)
#define MED_HDR10_OPIPE_A2_TABLE_OPIPE_A2_TABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_OPIPE_A2_TABLE_OPIPE_A2_TABLE_SHIFT)) & MED_HDR10_OPIPE_A2_TABLE_OPIPE_A2_TABLE_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_CONTROL_REG - HDR output stage Colorspace Converter (CSCO) control. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_MASK (0x1U)
#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_MASK)

#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK (0x2U)
#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT (1U)
#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_BYPASS_MASK (0x8000U)
#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_BYPASS_SHIFT (15U)
#define MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_BYPASS_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_CONTROL_REG_BYPASS_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H00 - Pipe1 Colorspace Converter (CSC) h(0,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H00_H00_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H00_H00_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H00_H00(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H00_H00_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H00_H00_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H10 - Pipe1 Colorspace Converter (CSC) h(1,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H10_H10_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H10_H10_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H10_H10(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H10_H10_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H10_H10_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H20 - HDR OUTPUT Colorspace Converter (CSCO) h(2,0) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H20_H20_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H20_H20_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H20_H20(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H20_H20_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H20_H20_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H01 - HDR OUTPUT pipe Colorspace Converter (CSCO) h(0,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H01_H01_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H01_H01_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H01_H01(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H01_H01_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H01_H01_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H11 - HDR OUTPUT pipe Colorspace Converter (CSCO) h(1,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H11_H11_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H11_H11_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H11_H11(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H11_H11_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H11_H11_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H21 - HDR_output pipe Colorspace Converter (CSCO) h(2,1) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H21_H21_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H21_H21_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H21_H21(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H21_H21_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H21_H21_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H02 - HDR OUTPUT pipe Colorspace Converter (CSCO) h(0,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H02_H02_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H02_H02_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H02_H02(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H02_H02_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H02_H02_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_H12 - HDR OUPUT pipe Colorspace Converter (CSCO) h(1,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_H12_H12_MASK     (0xFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_H12_H12_SHIFT    (0U)
#define MED_HDR10_HDR_OPIPE_CSC_H12_H12(x)       (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_H12_H12_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_H12_H12_MASK)
/*! @} */

/*! @name HDR_ - HDR OUPUT pipe Colorspace Converter (CSCO) h(2,2) matrix coefficient */
/*! @{ */

#define MED_HDR10_HDR__H22_MASK                  (0xFFFFU)
#define MED_HDR10_HDR__H22_SHIFT                 (0U)
#define MED_HDR10_HDR__H22(x)                    (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR__H22_SHIFT)) & MED_HDR10_HDR__H22_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_IO_0 - HDR OUTPUT pipe Colorspace Converter (CSCO) component 0 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_IO_0_COMPO_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_IO_0_COMPO_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_IO_0_COMPO_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_IO_0_COMPO_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_IO_0_COMPO_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_IO_1 - HDR OUPTUT pipe Colorspace Converter (CSCO) component 1 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_IO_1_COMP1_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_IO_1_COMP1_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_IO_1_COMP1_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_IO_1_COMP1_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_IO_1_COMP1_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_IO_2 - HDR OUPUT pipe: Colorspace Converter (CSCO) component 2 pre-offset */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_IO_2_COMP2_PRE_OFFSET_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_IO_2_COMP2_PRE_OFFSET_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_IO_2_COMP2_PRE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_IO_2_COMP2_PRE_OFFSET_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_IO_2_COMP2_PRE_OFFSET_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_MIN_0 - HDR OUPTU pipe Colorspace Converter (CSCO) component 0 clip min. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_MIN_0_COMP0_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_MIN_0_COMP0_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_MIN_0_COMP0_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_MIN_0_COMP0_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_MIN_0_COMP0_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_MIN_1 - HDR OUPUT pipe Colorspace Converter (CSCO) component 1 clip min. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_MIN_1_COMP1_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_MIN_1_COMP1_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_MIN_1_COMP1_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_MIN_1_COMP1_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_MIN_1_COMP1_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_MIN_2 - HDR OUPTU pipe Colorspace Converter (CSCO) component 2 clip min. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_MIN_2_COMP2_CLIP_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_MIN_2_COMP2_CLIP_MIN_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_MIN_2_COMP2_CLIP_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_MIN_2_COMP2_CLIP_MIN_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_MIN_2_COMP2_CLIP_MIN_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_MAX_0 - HDR OUPTUT pipe Colorspace Converter O (CSC) component 0 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_MAX_0_COMP0_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_MAX_0_COMP0_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_MAX_0_COMP0_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_MAX_0_COMP0_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_MAX_0_COMP0_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_MAX_1 - HDR OUTPUT pipe Colorspace Converter (CSCO) component 1 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_MAX_1_COMP1_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_MAX_1_COMP1_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_MAX_1_COMP1_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_MAX_1_COMP1_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_MAX_1_COMP1_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_MAX_2 - HDR OUTPUT pipe Colorspace Converter (CSCO) component 2 clip max value. */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_MAX_2_COMP2_CLIP_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_MAX_2_COMP2_CLIP_MAX_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_MAX_2_COMP2_CLIP_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_MAX_2_COMP2_CLIP_MAX_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_MAX_2_COMP2_CLIP_MAX_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_NORM - HDR OUPUT pipe Colorspace Converter (CSCO) normalization factor */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_NORM_CSC_NORM_MASK (0x1FU)
#define MED_HDR10_HDR_OPIPE_CSC_NORM_CSC_NORM_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_NORM_CSC_NORM(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_NORM_CSC_NORM_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_NORM_CSC_NORM_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OO_0 - HDR OUPTUT pipe Colorspace Converter (CSC): Post offset component 0 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OO_0_CSC_OO_0_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_OO_0_CSC_OO_0_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OO_0_CSC_OO_0(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OO_0_CSC_OO_0_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OO_0_CSC_OO_0_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OO_1 - HDR OUTPUT pipe Colorspace Converter (CSC): Post offset component 1 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OO_1_CSC_OO_1_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_OO_1_CSC_OO_1_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OO_1_CSC_OO_1(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OO_1_CSC_OO_1_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OO_1_CSC_OO_1_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OO_2 - HDR OUPTUT pipe Colorspace Converter (CSC): Post offset component 2 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OO_2_CSC_OO_2_MASK (0xFFFFFFFU)
#define MED_HDR10_HDR_OPIPE_CSC_OO_2_CSC_OO_2_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OO_2_CSC_OO_2(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OO_2_CSC_OO_2_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OO_2_CSC_OO_2_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OMIN_0 - HDR OUTPUT pipe Colorspace Converter (CSC): Post offset min clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OMIN_0_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_OMIN_0_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OMIN_0_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OMIN_0_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OMIN_0_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OMIN_1 - HDR OUTPUT pipe Colorspace Converter (CSC): Post offset min clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OMIN_1_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_OMIN_1_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OMIN_1_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OMIN_1_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OMIN_1_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OMIN_2 - HDR OUTPUT pipe Colorspace Converter (CSC): Post offset min clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OMIN_2_POST_OFF_MIN_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_OMIN_2_POST_OFF_MIN_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OMIN_2_POST_OFF_MIN(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OMIN_2_POST_OFF_MIN_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OMIN_2_POST_OFF_MIN_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OMAX_0 - HDR OUPTUT pipe Colorspace Converter (CSC): Post offset max clip value for component 0 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OMAX_0_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_OMAX_0_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OMAX_0_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OMAX_0_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OMAX_0_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OMAX_1 - HDR OUTPUT pipe Colorspace Converter (CSC): Post offset max clip value for component 1 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OMAX_1_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_OMAX_1_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OMAX_1_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OMAX_1_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OMAX_1_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_OPIPE_CSC_OMAX_2 - HDR OUTPUT pipe Colorspace Converter (CSC): Post offset max clip value for component 2 */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_CSC_OMAX_2_POST_OFF_MAX_MASK (0x3FFU)
#define MED_HDR10_HDR_OPIPE_CSC_OMAX_2_POST_OFF_MAX_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_CSC_OMAX_2_POST_OFF_MAX(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_CSC_OMAX_2_POST_OFF_MAX_SHIFT)) & MED_HDR10_HDR_OPIPE_CSC_OMAX_2_POST_OFF_MAX_MASK)
/*! @} */

/*! @name HDR_OPIPE_2NL_CONTROL_REG - HDR OUTPUT -TO NON LINEAR pipeline control */
/*! @{ */

#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_PASS_THRU_MASK (0x1U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_PASS_THRU_SHIFT (0U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_PASS_THRU(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_PASS_THRU_SHIFT)) & MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_PASS_THRU_MASK)

#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_DISABLE_FIXED_TO_FLOAT_MASK (0x2U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_DISABLE_FIXED_TO_FLOAT_SHIFT (1U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_DISABLE_FIXED_TO_FLOAT(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_DISABLE_FIXED_TO_FLOAT_SHIFT)) & MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_DISABLE_FIXED_TO_FLOAT_MASK)

#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_LTNL_ENABLE_FOR_ALL_PELS_MASK (0x4U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_LTNL_ENABLE_FOR_ALL_PELS_SHIFT (2U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_LTNL_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_LTNL_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_LTNL_ENABLE_FOR_ALL_PELS_MASK)

#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_FIX2FLT_ENABLE_FOR_ALL_PELS_MASK (0x8U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_FIX2FLT_ENABLE_FOR_ALL_PELS_SHIFT (3U)
#define MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_FIX2FLT_ENABLE_FOR_ALL_PELS(x) (((uint32_t)(((uint32_t)(x)) << MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_FIX2FLT_ENABLE_FOR_ALL_PELS_SHIFT)) & MED_HDR10_HDR_OPIPE_2NL_CONTROL_REG_FIX2FLT_ENABLE_FOR_ALL_PELS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MED_HDR10_Register_Masks */


/*!
 * @}
 */ /* end of group MED_HDR10_Peripheral_Access_Layer */


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


#endif  /* PERI_MED_HDR10_H_ */

