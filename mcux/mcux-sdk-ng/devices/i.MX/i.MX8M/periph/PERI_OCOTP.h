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
**         CMSIS Peripheral Access Layer for OCOTP
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
 * @file PERI_OCOTP.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCOTP
 *
 * CMSIS Peripheral Access Layer for OCOTP
 */

#if !defined(PERI_OCOTP_H_)
#define PERI_OCOTP_H_                            /**< Symbol preventing repeated inclusion */

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
   -- OCOTP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Peripheral_Access_Layer OCOTP Peripheral Access Layer
 * @{
 */

/** OCOTP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< OTP Controller Control Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< OTP Controller Control Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< OTP Controller Control Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< OTP Controller Control Register, offset: 0xC */
  __IO uint32_t TIMING;                            /**< OTP Controller Timing Register, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DATA;                              /**< OTP Controller Write Data Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t READ_CTRL;                         /**< OTP Controller Write Data Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t READ_FUSE_DATA;                    /**< OTP Controller Read Data Register, offset: 0x40 */
       uint8_t RESERVED_3[12];
  __IO uint32_t SW_STICKY;                         /**< Sticky bit Register, offset: 0x50 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCS;                               /**< Software Controllable Signals Register, offset: 0x60 */
  __IO uint32_t SCS_SET;                           /**< Software Controllable Signals Register, offset: 0x64 */
  __IO uint32_t SCS_CLR;                           /**< Software Controllable Signals Register, offset: 0x68 */
  __IO uint32_t SCS_TOG;                           /**< Software Controllable Signals Register, offset: 0x6C */
       uint8_t RESERVED_5[32];
  __I  uint32_t VERSION;                           /**< OTP Controller Version Register, offset: 0x90 */
       uint8_t RESERVED_6[876];
  __I  uint32_t LOCK;                              /**< Value of OTP Bank0 Word0 (Lock controls), offset: 0x400 */
       uint8_t RESERVED_7[12];
  __IO uint32_t TESTER0;                           /**< Value of OTP Bank0 Word1 (Tester Info.), offset: 0x410 */
       uint8_t RESERVED_8[12];
  __IO uint32_t TESTER1;                           /**< Value of OTP Bank0 Word2 (tester Info.), offset: 0x420 */
       uint8_t RESERVED_9[12];
  __IO uint32_t TESTER2;                           /**< Value of OTP Bank0 Word3 (Tester Info.), offset: 0x430 */
       uint8_t RESERVED_10[12];
  __IO uint32_t TESTER3;                           /**< Value of OTP Bank1 Word0 (Tester Info.), offset: 0x440 */
       uint8_t RESERVED_11[12];
  __IO uint32_t TESTER4;                           /**< Value of OTP Bank1 Word1 (Tester Info.), offset: 0x450 */
       uint8_t RESERVED_12[12];
  __IO uint32_t TESTER5;                           /**< Value of OTP Bank1 Word2 (Tester Info.), offset: 0x460 */
       uint8_t RESERVED_13[12];
  __IO uint32_t BOOT_CFG0;                         /**< Value of OTP Bank1 Word3 (Boot Configuration Info.), offset: 0x470 */
       uint8_t RESERVED_14[12];
  __IO uint32_t BOOT_CFG1;                         /**< Value of OTP Bank2 Word0 (Boot Configuration Info.), offset: 0x480 */
       uint8_t RESERVED_15[12];
  __IO uint32_t BOOT_CFG2;                         /**< Value of OTP Bank2 Word1 (Boot Configuration Info.), offset: 0x490 */
       uint8_t RESERVED_16[12];
  __IO uint32_t BOOT_CFG3;                         /**< Value of OTP Bank2 Word2 (Boot Configuration Info.), offset: 0x4A0 */
       uint8_t RESERVED_17[12];
  __IO uint32_t BOOT_CFG4;                         /**< Value of OTP Bank2 Word3 (BOOT Configuration Info.), offset: 0x4B0 */
       uint8_t RESERVED_18[12];
  __IO uint32_t MEM_TRIM0;                         /**< Value of OTP Bank3 Word0 (Memory Related Info.), offset: 0x4C0 */
       uint8_t RESERVED_19[12];
  __IO uint32_t MEM_TRIM1;                         /**< Value of OTP Bank3 Word1 (Memory Related Info.), offset: 0x4D0 */
       uint8_t RESERVED_20[12];
  __IO uint32_t ANA0;                              /**< Value of OTP Bank3 Word2 (Analog Info.), offset: 0x4E0 */
       uint8_t RESERVED_21[12];
  __IO uint32_t ANA1;                              /**< Value of OTP Bank3 Word3 (Analog Info.), offset: 0x4F0 */
       uint8_t RESERVED_22[140];
  __IO uint32_t SRK0;                              /**< Shadow Register for OTP Bank6 Word0 (SRK Hash), offset: 0x580 */
       uint8_t RESERVED_23[12];
  __IO uint32_t SRK1;                              /**< Shadow Register for OTP Bank6 Word1 (SRK Hash), offset: 0x590 */
       uint8_t RESERVED_24[12];
  __IO uint32_t SRK2;                              /**< Shadow Register for OTP Bank6 Word2 (SRK Hash), offset: 0x5A0 */
       uint8_t RESERVED_25[12];
  __IO uint32_t SRK3;                              /**< Shadow Register for OTP Bank6 Word3 (SRK Hash), offset: 0x5B0 */
       uint8_t RESERVED_26[12];
  __IO uint32_t SRK4;                              /**< Shadow Register for OTP Bank7 Word0 (SRK Hash), offset: 0x5C0 */
       uint8_t RESERVED_27[12];
  __IO uint32_t SRK5;                              /**< Shadow Register for OTP Bank7 Word1 (SRK Hash), offset: 0x5D0 */
       uint8_t RESERVED_28[12];
  __IO uint32_t SRK6;                              /**< Shadow Register for OTP Bank7 Word2 (SRK Hash), offset: 0x5E0 */
       uint8_t RESERVED_29[12];
  __IO uint32_t SRK7;                              /**< Shadow Register for OTP Bank7 Word3 (SRK Hash), offset: 0x5F0 */
       uint8_t RESERVED_30[12];
  __IO uint32_t SJC_RESP0;                         /**< Value of OTP Bank8 Word0 (Secure JTAG Response Field), offset: 0x600 */
       uint8_t RESERVED_31[12];
  __IO uint32_t SJC_RESP1;                         /**< Value of OTP Bank8 Word1 (Secure JTAG Response Field), offset: 0x610 */
       uint8_t RESERVED_32[12];
  __IO uint32_t USB_ID;                            /**< Value of OTP Bank8 Word2 (USB ID info), offset: 0x620 */
       uint8_t RESERVED_33[12];
  __IO uint32_t FIELD_RETURN;                      /**< Value of OTP Bank5 Word6 (Field Return), offset: 0x630 */
       uint8_t RESERVED_34[12];
  __IO uint32_t MAC_ADDR0;                         /**< Value of OTP Bank9 Word0 (MAC Address), offset: 0x640 */
       uint8_t RESERVED_35[12];
  __IO uint32_t MAC_ADDR1;                         /**< Value of OTP Bank9 Word1 (MAC Address), offset: 0x650 */
       uint8_t RESERVED_36[12];
  __IO uint32_t MAC_ADDR2;                         /**< Value of OTP Bank9 Word2 (MAC Address), offset: 0x660 */
       uint8_t RESERVED_37[12];
  __IO uint32_t SRK_REVOKE;                        /**< Value of OTP Bank9 Word3 (SRK Revoke), offset: 0x670 */
       uint8_t RESERVED_38[12];
  __IO uint32_t MAU_KEY0;                          /**< Shadow Register for OTP Bank10 Word0 (MAU Key), offset: 0x680 */
       uint8_t RESERVED_39[12];
  __IO uint32_t MAU_KEY1;                          /**< Shadow Register for OTP Bank10 Word1 (MAU Key), offset: 0x690 */
       uint8_t RESERVED_40[12];
  __IO uint32_t MAU_KEY2;                          /**< Shadow Register for OTP Bank10 Word2 (MAU Key), offset: 0x6A0 */
       uint8_t RESERVED_41[12];
  __IO uint32_t MAU_KEY3;                          /**< Shadow Register for OTP Bank10 Word3 (MAU Key), offset: 0x6B0 */
       uint8_t RESERVED_42[12];
  __IO uint32_t MAU_KEY4;                          /**< Shadow Register for OTP Bank11 Word0 (MAU Key), offset: 0x6C0 */
       uint8_t RESERVED_43[12];
  __IO uint32_t MAU_KEY5;                          /**< Shadow Register for OTP Bank11 Word1 (MAU Key), offset: 0x6D0 */
       uint8_t RESERVED_44[12];
  __IO uint32_t MAU_KEY6;                          /**< Shadow Register for OTP Bank11 Word2 (MAU Key), offset: 0x6E0 */
       uint8_t RESERVED_45[12];
  __IO uint32_t MAU_KEY7;                          /**< Shadow Register for OTP Bank11 Word3 (MAU Key), offset: 0x6F0 */
       uint8_t RESERVED_46[140];
  __IO uint32_t GP10;                              /**< Value of OTP Bank14 Word0 (), offset: 0x780 */
       uint8_t RESERVED_47[12];
  __IO uint32_t GP11;                              /**< Value of OTP Bank14 Word1 (), offset: 0x790 */
       uint8_t RESERVED_48[12];
  __IO uint32_t GP20;                              /**< Value of OTP Bank14 Word2 (), offset: 0x7A0 */
       uint8_t RESERVED_49[12];
  __IO uint32_t GP21;                              /**< Value of OTP Bank14 Word3 (), offset: 0x7B0 */
       uint8_t RESERVED_50[12];
  __IO uint32_t GP_CRC0;                           /**< Value of OTP Bank15 Word0 (CRC Key), offset: 0x7C0 */
       uint8_t RESERVED_51[12];
  __IO uint32_t GP_CRC1;                           /**< Value of OTP Bank15 Word1 (CRC Key), offset: 0x7D0 */
       uint8_t RESERVED_52[12];
  __IO uint32_t GP_CRC2;                           /**< Value of OTP Bank15 Word2 (CRC Key), offset: 0x7E0 */
       uint8_t RESERVED_53[12];
  __IO uint32_t GROUP_MASK;                        /**< Value of OTP Bank15 Word3 (CRC Key), offset: 0x7F0 */
       uint8_t RESERVED_54[12];
  __IO uint32_t HDMI_FW_SRK0;                      /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x800 */
       uint8_t RESERVED_55[12];
  __IO uint32_t HDMI_FW_SRK1;                      /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0x810 */
       uint8_t RESERVED_56[12];
  __IO uint32_t HDMI_FW_SRK2;                      /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x820 */
       uint8_t RESERVED_57[12];
  __IO uint32_t HDMI_FW_SRK3;                      /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x830 */
       uint8_t RESERVED_58[12];
  __IO uint32_t HDMI_FW_SRK4;                      /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x840 */
       uint8_t RESERVED_59[12];
  __IO uint32_t HDMI_FW_SRK5;                      /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x850 */
       uint8_t RESERVED_60[12];
  __IO uint32_t HDMI_FW_SRK6;                      /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x860 */
       uint8_t RESERVED_61[12];
  __IO uint32_t HDMI_FW_SRK7;                      /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x870 */
       uint8_t RESERVED_62[12];
  __IO uint32_t HDMI_KMEK0;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x880 */
       uint8_t RESERVED_63[12];
  __IO uint32_t HDMI_KMEK1;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x890 */
       uint8_t RESERVED_64[12];
  __IO uint32_t HDMI_KMEK2;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x8A0 */
       uint8_t RESERVED_65[12];
  __IO uint32_t HDMI_KMEK3;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x8B0 */
       uint8_t RESERVED_66[76];
  __IO uint32_t HDCP_TX_CONS0;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x900 */
       uint8_t RESERVED_67[12];
  __IO uint32_t HDCP_TX_CONS1;                     /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0x910 */
       uint8_t RESERVED_68[12];
  __IO uint32_t HDCP_TX_CONS2;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x920 */
       uint8_t RESERVED_69[12];
  __IO uint32_t HDCP_TX_CONS3;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x930 */
       uint8_t RESERVED_70[12];
  __IO uint32_t HDCP_TX_CERT0;                     /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x940 */
       uint8_t RESERVED_71[12];
  __IO uint32_t HDCP_TX_CERT1;                     /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x950 */
       uint8_t RESERVED_72[12];
  __IO uint32_t HDCP_TX_CERT2;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x960 */
       uint8_t RESERVED_73[12];
  __IO uint32_t HDCP_TX_CERT3;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x970 */
       uint8_t RESERVED_74[12];
  __IO uint32_t HDCP_TX_CERT4;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x980 */
       uint8_t RESERVED_75[12];
  __IO uint32_t HDCP_TX_CERT5;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x990 */
       uint8_t RESERVED_76[12];
  __IO uint32_t HDCP_TX_CERT6;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x9A0 */
       uint8_t RESERVED_77[12];
  __IO uint32_t HDCP_TX_CERT7;                     /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x9B0 */
       uint8_t RESERVED_78[12];
  __IO uint32_t HDCP_TX_CERT8;                     /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x9C0 */
       uint8_t RESERVED_79[12];
  __IO uint32_t HDCP_TX_CERT9;                     /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x9D0 */
       uint8_t RESERVED_80[12];
  __IO uint32_t HDCP_TX_CERT10;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x9E0 */
       uint8_t RESERVED_81[12];
  __IO uint32_t HDCP_TX_CERT11;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x9F0 */
       uint8_t RESERVED_82[12];
  __IO uint32_t HDCP_TX_CERT12;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA00 */
       uint8_t RESERVED_83[12];
  __IO uint32_t HDCP_TX_CERT13;                    /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0xA10 */
       uint8_t RESERVED_84[12];
  __IO uint32_t HDCP_TX_CERT14;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA20 */
       uint8_t RESERVED_85[12];
  __IO uint32_t HDCP_TX_CERT15;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA30 */
       uint8_t RESERVED_86[12];
  __IO uint32_t HDCP_TX_CERT16;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xA40 */
       uint8_t RESERVED_87[12];
  __IO uint32_t HDCP_TX_CERT17;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xA50 */
       uint8_t RESERVED_88[12];
  __IO uint32_t HDCP_TX_CERT18;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA60 */
       uint8_t RESERVED_89[12];
  __IO uint32_t HDCP_TX_CERT19;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA70 */
       uint8_t RESERVED_90[12];
  __IO uint32_t HDCP_TX_CERT20;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA80 */
       uint8_t RESERVED_91[12];
  __IO uint32_t HDCP_TX_CERT21;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xA90 */
       uint8_t RESERVED_92[12];
  __IO uint32_t HDCP_TX_CERT22;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xAA0 */
       uint8_t RESERVED_93[12];
  __IO uint32_t HDCP_TX_CERT23;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xAB0 */
       uint8_t RESERVED_94[12];
  __IO uint32_t HDCP_TX_CERT24;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xAC0 */
       uint8_t RESERVED_95[12];
  __IO uint32_t HDCP_TX_CERT25;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xAD0 */
       uint8_t RESERVED_96[12];
  __IO uint32_t HDCP_TX_CERT26;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xAE0 */
       uint8_t RESERVED_97[12];
  __IO uint32_t HDCP_TX_CERT27;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xAF0 */
       uint8_t RESERVED_98[12];
  __IO uint32_t HDCP_TX_CERT28;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB00 */
       uint8_t RESERVED_99[12];
  __IO uint32_t HDCP_TX_CERT29;                    /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0xB10 */
       uint8_t RESERVED_100[12];
  __IO uint32_t HDCP_TX_CERT30;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB20 */
       uint8_t RESERVED_101[12];
  __IO uint32_t HDCP_TX_CERT31;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB30 */
       uint8_t RESERVED_102[12];
  __IO uint32_t HDCP_TX_CERT32;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xB40 */
       uint8_t RESERVED_103[12];
  __IO uint32_t HDCP_TX_CERT33;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xB50 */
       uint8_t RESERVED_104[12];
  __IO uint32_t HDCP_TX_CERT34;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB60 */
       uint8_t RESERVED_105[12];
  __IO uint32_t HDCP_TX_CERT35;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB70 */
       uint8_t RESERVED_106[12];
  __IO uint32_t HDCP_TX_CERT36;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB80 */
       uint8_t RESERVED_107[12];
  __IO uint32_t HDCP_TX_CERT37;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xB90 */
       uint8_t RESERVED_108[12];
  __IO uint32_t HDCP_TX_CERT38;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xBA0 */
       uint8_t RESERVED_109[12];
  __IO uint32_t HDCP_TX_CERT39;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xBB0 */
       uint8_t RESERVED_110[12];
  __IO uint32_t HDCP_TX_CERT40;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xBC0 */
       uint8_t RESERVED_111[12];
  __IO uint32_t HDCP_TX_CERT41;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xBD0 */
       uint8_t RESERVED_112[12];
  __IO uint32_t HDCP_TX_CERT42;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xBE0 */
       uint8_t RESERVED_113[12];
  __IO uint32_t HDCP_TX_CERT43;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xBF0 */
       uint8_t RESERVED_114[12];
  __IO uint32_t HDCP_TX_CERT44;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC00 */
       uint8_t RESERVED_115[12];
  __IO uint32_t HDCP_TX_CERT45;                    /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0xC10 */
       uint8_t RESERVED_116[12];
  __IO uint32_t HDCP_TX_CERT46;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC20 */
       uint8_t RESERVED_117[12];
  __IO uint32_t HDCP_TX_CERT47;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC30 */
       uint8_t RESERVED_118[12];
  __IO uint32_t HDCP_TX_CERT48;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xC40 */
       uint8_t RESERVED_119[12];
  __IO uint32_t HDCP_TX_CERT49;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xC50 */
       uint8_t RESERVED_120[12];
  __IO uint32_t HDCP_TX_CERT50;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC60 */
       uint8_t RESERVED_121[12];
  __IO uint32_t HDCP_TX_CERT51;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC70 */
       uint8_t RESERVED_122[12];
  __IO uint32_t HDCP_TX_CERT52;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC80 */
       uint8_t RESERVED_123[12];
  __IO uint32_t HDCP_TX_CERT53;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xC90 */
       uint8_t RESERVED_124[12];
  __IO uint32_t HDCP_TX_CERT54;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xCA0 */
       uint8_t RESERVED_125[12];
  __IO uint32_t HDCP_TX_CERT55;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xCB0 */
       uint8_t RESERVED_126[12];
  __IO uint32_t HDCP_TX_CERT56;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xCC0 */
       uint8_t RESERVED_127[12];
  __IO uint32_t HDCP_TX_CERT57;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xCD0 */
       uint8_t RESERVED_128[12];
  __IO uint32_t HDCP_TX_CERT58;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xCE0 */
       uint8_t RESERVED_129[12];
  __IO uint32_t HDCP_TX_CERT59;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xCF0 */
       uint8_t RESERVED_130[12];
  __IO uint32_t HDCP_TX_CERT60;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD00 */
       uint8_t RESERVED_131[12];
  __IO uint32_t HDCP_TX_CERT61;                    /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0xD10 */
       uint8_t RESERVED_132[12];
  __IO uint32_t HDCP_TX_CERT62;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD20 */
       uint8_t RESERVED_133[12];
  __IO uint32_t HDCP_TX_CERT63;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD30 */
       uint8_t RESERVED_134[12];
  __IO uint32_t HDCP_TX_CERT64;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xD40 */
       uint8_t RESERVED_135[12];
  __IO uint32_t HDCP_TX_CERT65;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xD50 */
       uint8_t RESERVED_136[12];
  __IO uint32_t HDCP_TX_CERT66;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD60 */
       uint8_t RESERVED_137[12];
  __IO uint32_t HDCP_TX_CERT67;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD70 */
       uint8_t RESERVED_138[12];
  __IO uint32_t HDCP_TX_CERT68;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD80 */
       uint8_t RESERVED_139[12];
  __IO uint32_t HDCP_TX_CERT69;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xD90 */
       uint8_t RESERVED_140[12];
  __IO uint32_t HDCP_TX_CERT70;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xDA0 */
       uint8_t RESERVED_141[12];
  __IO uint32_t HDCP_TX_CERT71;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xDB0 */
       uint8_t RESERVED_142[12];
  __IO uint32_t HDCP_TX_CERT72;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xDC0 */
       uint8_t RESERVED_143[12];
  __IO uint32_t HDCP_TX_CERT73;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xDD0 */
       uint8_t RESERVED_144[12];
  __IO uint32_t HDCP_TX_CERT74;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xDE0 */
       uint8_t RESERVED_145[12];
  __IO uint32_t HDCP_TX_CERT75;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xDF0 */
       uint8_t RESERVED_146[12];
  __IO uint32_t HDCP_TX_CERT76;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE00 */
       uint8_t RESERVED_147[12];
  __IO uint32_t HDCP_TX_CERT77;                    /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0xE10 */
       uint8_t RESERVED_148[12];
  __IO uint32_t HDCP_TX_CERT78;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE20 */
       uint8_t RESERVED_149[12];
  __IO uint32_t HDCP_TX_CERT79;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE30 */
       uint8_t RESERVED_150[12];
  __IO uint32_t HDCP_TX_CERT80;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xE40 */
       uint8_t RESERVED_151[12];
  __IO uint32_t HDCP_TX_CERT81;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xE50 */
       uint8_t RESERVED_152[12];
  __IO uint32_t HDCP_TX_CERT82;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE60 */
       uint8_t RESERVED_153[12];
  __IO uint32_t HDCP_TX_CERT83;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE70 */
       uint8_t RESERVED_154[12];
  __IO uint32_t HDCP_TX_CERT84;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE80 */
       uint8_t RESERVED_155[12];
  __IO uint32_t HDCP_TX_CERT85;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xE90 */
       uint8_t RESERVED_156[12];
  __IO uint32_t HDCP_TX_CERT86;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xEA0 */
       uint8_t RESERVED_157[12];
  __IO uint32_t HDCP_TX_CERT87;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xEB0 */
       uint8_t RESERVED_158[12];
  __IO uint32_t HDCP_TX_CERT88;                    /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xEC0 */
       uint8_t RESERVED_159[12];
  __IO uint32_t HDCP_TX_CERT89;                    /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xED0 */
       uint8_t RESERVED_160[12];
  __IO uint32_t HDCP_TX_CERT90;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xEE0 */
       uint8_t RESERVED_161[12];
  __IO uint32_t HDCP_TX_CERT91;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xEF0 */
       uint8_t RESERVED_162[12];
  __IO uint32_t HDCP_TX_CERT92;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF00 */
       uint8_t RESERVED_163[12];
  __IO uint32_t HDCP_TX_CERT93;                    /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0xF10 */
       uint8_t RESERVED_164[12];
  __IO uint32_t HDCP_TX_CERT94;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF20 */
       uint8_t RESERVED_165[12];
  __IO uint32_t HDCP_TX_CERT95;                    /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF30 */
       uint8_t RESERVED_166[12];
  __IO uint32_t HDCP_KEY0;                         /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xF40 */
       uint8_t RESERVED_167[12];
  __IO uint32_t HDCP_KEY1;                         /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xF50 */
       uint8_t RESERVED_168[12];
  __IO uint32_t HDCP_KEY2;                         /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF60 */
       uint8_t RESERVED_169[12];
  __IO uint32_t HDCP_KEY3;                         /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF70 */
       uint8_t RESERVED_170[12];
  __IO uint32_t HDCP_KEY4;                         /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF80 */
       uint8_t RESERVED_171[12];
  __IO uint32_t HDCP_KEY5;                         /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xF90 */
       uint8_t RESERVED_172[12];
  __IO uint32_t HDCP_KEY6;                         /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xFA0 */
       uint8_t RESERVED_173[12];
  __IO uint32_t HDCP_KEY7;                         /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xFB0 */
       uint8_t RESERVED_174[12];
  __IO uint32_t HDCP_KEY8;                         /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0xFC0 */
       uint8_t RESERVED_175[12];
  __IO uint32_t HDCP_KEY9;                         /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0xFD0 */
       uint8_t RESERVED_176[12];
  __IO uint32_t HDCP_KEY10;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xFE0 */
       uint8_t RESERVED_177[12];
  __IO uint32_t HDCP_KEY11;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0xFF0 */
       uint8_t RESERVED_178[12];
  __IO uint32_t HDCP_KEY12;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1000 */
       uint8_t RESERVED_179[12];
  __IO uint32_t HDCP_KEY13;                        /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0x1010 */
       uint8_t RESERVED_180[12];
  __IO uint32_t HDCP_KEY14;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1020 */
       uint8_t RESERVED_181[12];
  __IO uint32_t HDCP_KEY15;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1030 */
       uint8_t RESERVED_182[12];
  __IO uint32_t HDCP_KEY16;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x1040 */
       uint8_t RESERVED_183[12];
  __IO uint32_t HDCP_KEY17;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x1050 */
       uint8_t RESERVED_184[12];
  __IO uint32_t HDCP_KEY18;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1060 */
       uint8_t RESERVED_185[12];
  __IO uint32_t HDCP_KEY19;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1070 */
       uint8_t RESERVED_186[12];
  __IO uint32_t HDCP_KEY20;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1080 */
       uint8_t RESERVED_187[12];
  __IO uint32_t HDCP_KEY21;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1090 */
       uint8_t RESERVED_188[12];
  __IO uint32_t HDCP_KEY22;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x10A0 */
       uint8_t RESERVED_189[12];
  __IO uint32_t HDCP_KEY23;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x10B0 */
       uint8_t RESERVED_190[12];
  __IO uint32_t HDCP_KEY24;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x10C0 */
       uint8_t RESERVED_191[12];
  __IO uint32_t HDCP_KEY25;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x10D0 */
       uint8_t RESERVED_192[12];
  __IO uint32_t HDCP_KEY26;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x10E0 */
       uint8_t RESERVED_193[12];
  __IO uint32_t HDCP_KEY27;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x10F0 */
       uint8_t RESERVED_194[12];
  __IO uint32_t HDCP_KEY28;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1100 */
       uint8_t RESERVED_195[12];
  __IO uint32_t HDCP_KEY29;                        /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0x1110 */
       uint8_t RESERVED_196[12];
  __IO uint32_t HDCP_KEY30;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1120 */
       uint8_t RESERVED_197[12];
  __IO uint32_t HDCP_KEY31;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1130 */
       uint8_t RESERVED_198[12];
  __IO uint32_t HDCP_KEY32;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x1140 */
       uint8_t RESERVED_199[12];
  __IO uint32_t HDCP_KEY33;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x1150 */
       uint8_t RESERVED_200[12];
  __IO uint32_t HDCP_KEY34;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1160 */
       uint8_t RESERVED_201[12];
  __IO uint32_t HDCP_KEY35;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1170 */
       uint8_t RESERVED_202[12];
  __IO uint32_t HDCP_KEY36;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1180 */
       uint8_t RESERVED_203[12];
  __IO uint32_t HDCP_KEY37;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1190 */
       uint8_t RESERVED_204[12];
  __IO uint32_t HDCP_KEY38;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x11A0 */
       uint8_t RESERVED_205[12];
  __IO uint32_t HDCP_KEY39;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x11B0 */
       uint8_t RESERVED_206[12];
  __IO uint32_t HDCP_KEY40;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x11C0 */
       uint8_t RESERVED_207[12];
  __IO uint32_t HDCP_KEY41;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x11D0 */
       uint8_t RESERVED_208[12];
  __IO uint32_t HDCP_KEY42;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x11E0 */
       uint8_t RESERVED_209[12];
  __IO uint32_t HDCP_KEY43;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x11F0 */
       uint8_t RESERVED_210[12];
  __IO uint32_t HDCP_KEY44;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1200 */
       uint8_t RESERVED_211[12];
  __IO uint32_t HDCP_KEY45;                        /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0x1210 */
       uint8_t RESERVED_212[12];
  __IO uint32_t HDCP_KEY46;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1220 */
       uint8_t RESERVED_213[12];
  __IO uint32_t HDCP_KEY47;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1230 */
       uint8_t RESERVED_214[12];
  __IO uint32_t HDCP_KEY48;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x1240 */
       uint8_t RESERVED_215[12];
  __IO uint32_t HDCP_KEY49;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x1250 */
       uint8_t RESERVED_216[12];
  __IO uint32_t HDCP_KEY50;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1260 */
       uint8_t RESERVED_217[12];
  __IO uint32_t HDCP_KEY51;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1270 */
       uint8_t RESERVED_218[12];
  __IO uint32_t HDCP_KEY52;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1280 */
       uint8_t RESERVED_219[12];
  __IO uint32_t HDCP_KEY53;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1290 */
       uint8_t RESERVED_220[12];
  __IO uint32_t HDCP_KEY54;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x12A0 */
       uint8_t RESERVED_221[12];
  __IO uint32_t HDCP_KEY55;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x12B0 */
       uint8_t RESERVED_222[12];
  __IO uint32_t HDCP_KEY56;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x12C0 */
       uint8_t RESERVED_223[12];
  __IO uint32_t HDCP_KEY57;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x12D0 */
       uint8_t RESERVED_224[12];
  __IO uint32_t HDCP_KEY58;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x12E0 */
       uint8_t RESERVED_225[12];
  __IO uint32_t HDCP_KEY59;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x12F0 */
       uint8_t RESERVED_226[12];
  __IO uint32_t HDCP_KEY60;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1300 */
       uint8_t RESERVED_227[12];
  __IO uint32_t HDCP_KEY61;                        /**< Value of OTP Bank16 Word1 (HDCP Key), offset: 0x1310 */
       uint8_t RESERVED_228[12];
  __IO uint32_t HDCP_KEY62;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1320 */
       uint8_t RESERVED_229[12];
  __IO uint32_t HDCP_KEY63;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1330 */
       uint8_t RESERVED_230[12];
  __IO uint32_t HDCP_KEY64;                        /**< Value of OTP Bank17 Word0 (HDCP Key), offset: 0x1340 */
       uint8_t RESERVED_231[12];
  __IO uint32_t HDCP_KEY65;                        /**< Value of OTP Bank17 Word1 (HDCP Key), offset: 0x1350 */
       uint8_t RESERVED_232[12];
  __IO uint32_t HDCP_KEY66;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1360 */
       uint8_t RESERVED_233[12];
  __IO uint32_t HDCP_KEY67;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1370 */
       uint8_t RESERVED_234[12];
  __IO uint32_t HDCP_KEY68;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1380 */
       uint8_t RESERVED_235[12];
  __IO uint32_t HDCP_KEY69;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x1390 */
       uint8_t RESERVED_236[12];
  __IO uint32_t HDCP_KEY70;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x13A0 */
       uint8_t RESERVED_237[12];
  __IO uint32_t HDCP_KEY71;                        /**< Value of OTP Bank16 Word0 (HDCP Key), offset: 0x13B0 */
} OCOTP_Type;

/* ----------------------------------------------------------------------------
   -- OCOTP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Register_Masks OCOTP Register Masks
 * @{
 */

/*! @name CTRL - OTP Controller Control Register */
/*! @{ */

#define OCOTP_CTRL_ADDR_MASK                     (0xFFU)
#define OCOTP_CTRL_ADDR_SHIFT                    (0U)
#define OCOTP_CTRL_ADDR(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_ADDR_SHIFT)) & OCOTP_CTRL_ADDR_MASK)

#define OCOTP_CTRL_BUSY_MASK                     (0x100U)
#define OCOTP_CTRL_BUSY_SHIFT                    (8U)
#define OCOTP_CTRL_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_BUSY_SHIFT)) & OCOTP_CTRL_BUSY_MASK)

#define OCOTP_CTRL_ERROR_MASK                    (0x200U)
#define OCOTP_CTRL_ERROR_SHIFT                   (9U)
#define OCOTP_CTRL_ERROR(x)                      (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_ERROR_SHIFT)) & OCOTP_CTRL_ERROR_MASK)

#define OCOTP_CTRL_RELOAD_SHADOWS_MASK           (0x400U)
#define OCOTP_CTRL_RELOAD_SHADOWS_SHIFT          (10U)
#define OCOTP_CTRL_RELOAD_SHADOWS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_WR_UNLOCK_MASK                (0xFFFF0000U)
#define OCOTP_CTRL_WR_UNLOCK_SHIFT               (16U)
#define OCOTP_CTRL_WR_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_WR_UNLOCK_MASK)
/*! @} */

/*! @name CTRL_SET - OTP Controller Control Register */
/*! @{ */

#define OCOTP_CTRL_SET_ADDR_MASK                 (0xFFU)
#define OCOTP_CTRL_SET_ADDR_SHIFT                (0U)
#define OCOTP_CTRL_SET_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_ADDR_SHIFT)) & OCOTP_CTRL_SET_ADDR_MASK)

#define OCOTP_CTRL_SET_BUSY_MASK                 (0x100U)
#define OCOTP_CTRL_SET_BUSY_SHIFT                (8U)
#define OCOTP_CTRL_SET_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_BUSY_SHIFT)) & OCOTP_CTRL_SET_BUSY_MASK)

#define OCOTP_CTRL_SET_ERROR_MASK                (0x200U)
#define OCOTP_CTRL_SET_ERROR_SHIFT               (9U)
#define OCOTP_CTRL_SET_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_ERROR_SHIFT)) & OCOTP_CTRL_SET_ERROR_MASK)

#define OCOTP_CTRL_SET_RELOAD_SHADOWS_MASK       (0x400U)
#define OCOTP_CTRL_SET_RELOAD_SHADOWS_SHIFT      (10U)
#define OCOTP_CTRL_SET_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_SET_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_SET_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_CTRL_SET_WR_UNLOCK_SHIFT           (16U)
#define OCOTP_CTRL_SET_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_SET_WR_UNLOCK_MASK)
/*! @} */

/*! @name CTRL_CLR - OTP Controller Control Register */
/*! @{ */

#define OCOTP_CTRL_CLR_ADDR_MASK                 (0xFFU)
#define OCOTP_CTRL_CLR_ADDR_SHIFT                (0U)
#define OCOTP_CTRL_CLR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_ADDR_SHIFT)) & OCOTP_CTRL_CLR_ADDR_MASK)

#define OCOTP_CTRL_CLR_BUSY_MASK                 (0x100U)
#define OCOTP_CTRL_CLR_BUSY_SHIFT                (8U)
#define OCOTP_CTRL_CLR_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_BUSY_SHIFT)) & OCOTP_CTRL_CLR_BUSY_MASK)

#define OCOTP_CTRL_CLR_ERROR_MASK                (0x200U)
#define OCOTP_CTRL_CLR_ERROR_SHIFT               (9U)
#define OCOTP_CTRL_CLR_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_ERROR_SHIFT)) & OCOTP_CTRL_CLR_ERROR_MASK)

#define OCOTP_CTRL_CLR_RELOAD_SHADOWS_MASK       (0x400U)
#define OCOTP_CTRL_CLR_RELOAD_SHADOWS_SHIFT      (10U)
#define OCOTP_CTRL_CLR_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_CLR_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_CLR_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_CTRL_CLR_WR_UNLOCK_SHIFT           (16U)
#define OCOTP_CTRL_CLR_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_CLR_WR_UNLOCK_MASK)
/*! @} */

/*! @name CTRL_TOG - OTP Controller Control Register */
/*! @{ */

#define OCOTP_CTRL_TOG_ADDR_MASK                 (0xFFU)
#define OCOTP_CTRL_TOG_ADDR_SHIFT                (0U)
#define OCOTP_CTRL_TOG_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_ADDR_SHIFT)) & OCOTP_CTRL_TOG_ADDR_MASK)

#define OCOTP_CTRL_TOG_BUSY_MASK                 (0x100U)
#define OCOTP_CTRL_TOG_BUSY_SHIFT                (8U)
#define OCOTP_CTRL_TOG_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_BUSY_SHIFT)) & OCOTP_CTRL_TOG_BUSY_MASK)

#define OCOTP_CTRL_TOG_ERROR_MASK                (0x200U)
#define OCOTP_CTRL_TOG_ERROR_SHIFT               (9U)
#define OCOTP_CTRL_TOG_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_ERROR_SHIFT)) & OCOTP_CTRL_TOG_ERROR_MASK)

#define OCOTP_CTRL_TOG_RELOAD_SHADOWS_MASK       (0x400U)
#define OCOTP_CTRL_TOG_RELOAD_SHADOWS_SHIFT      (10U)
#define OCOTP_CTRL_TOG_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_TOG_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_TOG_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_CTRL_TOG_WR_UNLOCK_SHIFT           (16U)
#define OCOTP_CTRL_TOG_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_TOG_WR_UNLOCK_MASK)
/*! @} */

/*! @name TIMING - OTP Controller Timing Register */
/*! @{ */

#define OCOTP_TIMING_STROBE_PROG_MASK            (0xFFFU)
#define OCOTP_TIMING_STROBE_PROG_SHIFT           (0U)
#define OCOTP_TIMING_STROBE_PROG(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_STROBE_PROG_SHIFT)) & OCOTP_TIMING_STROBE_PROG_MASK)

#define OCOTP_TIMING_RELAX_MASK                  (0xF000U)
#define OCOTP_TIMING_RELAX_SHIFT                 (12U)
#define OCOTP_TIMING_RELAX(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_RELAX_SHIFT)) & OCOTP_TIMING_RELAX_MASK)

#define OCOTP_TIMING_STROBE_READ_MASK            (0x3F0000U)
#define OCOTP_TIMING_STROBE_READ_SHIFT           (16U)
#define OCOTP_TIMING_STROBE_READ(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_STROBE_READ_SHIFT)) & OCOTP_TIMING_STROBE_READ_MASK)

#define OCOTP_TIMING_WAIT_MASK                   (0xFC00000U)
#define OCOTP_TIMING_WAIT_SHIFT                  (22U)
#define OCOTP_TIMING_WAIT(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_WAIT_SHIFT)) & OCOTP_TIMING_WAIT_MASK)

#define OCOTP_TIMING_RSRVD0_MASK                 (0xF0000000U)
#define OCOTP_TIMING_RSRVD0_SHIFT                (28U)
#define OCOTP_TIMING_RSRVD0(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_RSRVD0_SHIFT)) & OCOTP_TIMING_RSRVD0_MASK)
/*! @} */

/*! @name DATA - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_DATA_DATA_MASK                     (0xFFFFFFFFU)
#define OCOTP_DATA_DATA_SHIFT                    (0U)
#define OCOTP_DATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DATA_DATA_SHIFT)) & OCOTP_DATA_DATA_MASK)
/*! @} */

/*! @name READ_CTRL - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_READ_CTRL_READ_FUSE_MASK           (0x1U)
#define OCOTP_READ_CTRL_READ_FUSE_SHIFT          (0U)
#define OCOTP_READ_CTRL_READ_FUSE(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_READ_CTRL_READ_FUSE_SHIFT)) & OCOTP_READ_CTRL_READ_FUSE_MASK)

#define OCOTP_READ_CTRL_RSVD0_MASK               (0xFFFFFFFEU)
#define OCOTP_READ_CTRL_RSVD0_SHIFT              (1U)
#define OCOTP_READ_CTRL_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_READ_CTRL_RSVD0_SHIFT)) & OCOTP_READ_CTRL_RSVD0_MASK)
/*! @} */

/*! @name READ_FUSE_DATA - OTP Controller Read Data Register */
/*! @{ */

#define OCOTP_READ_FUSE_DATA_DATA_MASK           (0xFFFFFFFFU)
#define OCOTP_READ_FUSE_DATA_DATA_SHIFT          (0U)
#define OCOTP_READ_FUSE_DATA_DATA(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_READ_FUSE_DATA_DATA_SHIFT)) & OCOTP_READ_FUSE_DATA_DATA_MASK)
/*! @} */

/*! @name SW_STICKY - Sticky bit Register */
/*! @{ */

#define OCOTP_SW_STICKY_RSVD0_MASK               (0x1U)
#define OCOTP_SW_STICKY_RSVD0_SHIFT              (0U)
#define OCOTP_SW_STICKY_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_RSVD0_SHIFT)) & OCOTP_SW_STICKY_RSVD0_MASK)

#define OCOTP_SW_STICKY_SRK_REVOKE_LOCK_MASK     (0x2U)
#define OCOTP_SW_STICKY_SRK_REVOKE_LOCK_SHIFT    (1U)
#define OCOTP_SW_STICKY_SRK_REVOKE_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_SRK_REVOKE_LOCK_SHIFT)) & OCOTP_SW_STICKY_SRK_REVOKE_LOCK_MASK)

#define OCOTP_SW_STICKY_FIELD_RETURN_LOCK_MASK   (0x4U)
#define OCOTP_SW_STICKY_FIELD_RETURN_LOCK_SHIFT  (2U)
#define OCOTP_SW_STICKY_FIELD_RETURN_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_FIELD_RETURN_LOCK_SHIFT)) & OCOTP_SW_STICKY_FIELD_RETURN_LOCK_MASK)

#define OCOTP_SW_STICKY_BLOCK_ROM_PART_MASK      (0x8U)
#define OCOTP_SW_STICKY_BLOCK_ROM_PART_SHIFT     (3U)
#define OCOTP_SW_STICKY_BLOCK_ROM_PART(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_BLOCK_ROM_PART_SHIFT)) & OCOTP_SW_STICKY_BLOCK_ROM_PART_MASK)

#define OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE_MASK  (0x10U)
#define OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE_SHIFT (4U)
#define OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE_SHIFT)) & OCOTP_SW_STICKY_JTAG_BLOCK_RELEASE_MASK)

#define OCOTP_SW_STICKY_DISABLE_READ_GROUP_MASK_MASK (0x20U)
#define OCOTP_SW_STICKY_DISABLE_READ_GROUP_MASK_SHIFT (5U)
#define OCOTP_SW_STICKY_DISABLE_READ_GROUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_DISABLE_READ_GROUP_MASK_SHIFT)) & OCOTP_SW_STICKY_DISABLE_READ_GROUP_MASK_MASK)

#define OCOTP_SW_STICKY_DISABLE_READ_HDMI_FW_SRK_MASK (0x40U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDMI_FW_SRK_SHIFT (6U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDMI_FW_SRK(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_DISABLE_READ_HDMI_FW_SRK_SHIFT)) & OCOTP_SW_STICKY_DISABLE_READ_HDMI_FW_SRK_MASK)

#define OCOTP_SW_STICKY_DISABLE_READ_HDMI_KMEK_MASK (0x80U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDMI_KMEK_SHIFT (7U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDMI_KMEK(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_DISABLE_READ_HDMI_KMEK_SHIFT)) & OCOTP_SW_STICKY_DISABLE_READ_HDMI_KMEK_MASK)

#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_GLOBAL_CONSTANT_MASK (0x100U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_GLOBAL_CONSTANT_SHIFT (8U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_GLOBAL_CONSTANT(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_GLOBAL_CONSTANT_SHIFT)) & OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_GLOBAL_CONSTANT_MASK)

#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_CERT_MASK (0x200U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_CERT_SHIFT (9U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_CERT(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_CERT_SHIFT)) & OCOTP_SW_STICKY_DISABLE_READ_HDCP_TX_CERT_MASK)

#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_DEVICE_KEY_MASK (0x400U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_DEVICE_KEY_SHIFT (10U)
#define OCOTP_SW_STICKY_DISABLE_READ_HDCP_DEVICE_KEY(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_DISABLE_READ_HDCP_DEVICE_KEY_SHIFT)) & OCOTP_SW_STICKY_DISABLE_READ_HDCP_DEVICE_KEY_MASK)

#define OCOTP_SW_STICKY_RSVD1_MASK               (0xFFFFF800U)
#define OCOTP_SW_STICKY_RSVD1_SHIFT              (11U)
#define OCOTP_SW_STICKY_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_RSVD1_SHIFT)) & OCOTP_SW_STICKY_RSVD1_MASK)
/*! @} */

/*! @name SCS - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_HAB_JDE_MASK                   (0x1U)
#define OCOTP_SCS_HAB_JDE_SHIFT                  (0U)
#define OCOTP_SCS_HAB_JDE(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_HAB_JDE_SHIFT)) & OCOTP_SCS_HAB_JDE_MASK)

#define OCOTP_SCS_SPARE_MASK                     (0x7FFFFFFEU)
#define OCOTP_SCS_SPARE_SHIFT                    (1U)
#define OCOTP_SCS_SPARE(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SPARE_SHIFT)) & OCOTP_SCS_SPARE_MASK)

#define OCOTP_SCS_LOCK_MASK                      (0x80000000U)
#define OCOTP_SCS_LOCK_SHIFT                     (31U)
#define OCOTP_SCS_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_LOCK_SHIFT)) & OCOTP_SCS_LOCK_MASK)
/*! @} */

/*! @name SCS_SET - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_SET_HAB_JDE_MASK               (0x1U)
#define OCOTP_SCS_SET_HAB_JDE_SHIFT              (0U)
#define OCOTP_SCS_SET_HAB_JDE(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SET_HAB_JDE_SHIFT)) & OCOTP_SCS_SET_HAB_JDE_MASK)

#define OCOTP_SCS_SET_SPARE_MASK                 (0x7FFFFFFEU)
#define OCOTP_SCS_SET_SPARE_SHIFT                (1U)
#define OCOTP_SCS_SET_SPARE(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SET_SPARE_SHIFT)) & OCOTP_SCS_SET_SPARE_MASK)

#define OCOTP_SCS_SET_LOCK_MASK                  (0x80000000U)
#define OCOTP_SCS_SET_LOCK_SHIFT                 (31U)
#define OCOTP_SCS_SET_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SET_LOCK_SHIFT)) & OCOTP_SCS_SET_LOCK_MASK)
/*! @} */

/*! @name SCS_CLR - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_CLR_HAB_JDE_MASK               (0x1U)
#define OCOTP_SCS_CLR_HAB_JDE_SHIFT              (0U)
#define OCOTP_SCS_CLR_HAB_JDE(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_CLR_HAB_JDE_SHIFT)) & OCOTP_SCS_CLR_HAB_JDE_MASK)

#define OCOTP_SCS_CLR_SPARE_MASK                 (0x7FFFFFFEU)
#define OCOTP_SCS_CLR_SPARE_SHIFT                (1U)
#define OCOTP_SCS_CLR_SPARE(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_CLR_SPARE_SHIFT)) & OCOTP_SCS_CLR_SPARE_MASK)

#define OCOTP_SCS_CLR_LOCK_MASK                  (0x80000000U)
#define OCOTP_SCS_CLR_LOCK_SHIFT                 (31U)
#define OCOTP_SCS_CLR_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_CLR_LOCK_SHIFT)) & OCOTP_SCS_CLR_LOCK_MASK)
/*! @} */

/*! @name SCS_TOG - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_TOG_HAB_JDE_MASK               (0x1U)
#define OCOTP_SCS_TOG_HAB_JDE_SHIFT              (0U)
#define OCOTP_SCS_TOG_HAB_JDE(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_TOG_HAB_JDE_SHIFT)) & OCOTP_SCS_TOG_HAB_JDE_MASK)

#define OCOTP_SCS_TOG_SPARE_MASK                 (0x7FFFFFFEU)
#define OCOTP_SCS_TOG_SPARE_SHIFT                (1U)
#define OCOTP_SCS_TOG_SPARE(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_TOG_SPARE_SHIFT)) & OCOTP_SCS_TOG_SPARE_MASK)

#define OCOTP_SCS_TOG_LOCK_MASK                  (0x80000000U)
#define OCOTP_SCS_TOG_LOCK_SHIFT                 (31U)
#define OCOTP_SCS_TOG_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_TOG_LOCK_SHIFT)) & OCOTP_SCS_TOG_LOCK_MASK)
/*! @} */

/*! @name VERSION - OTP Controller Version Register */
/*! @{ */

#define OCOTP_VERSION_STEP_MASK                  (0xFFFFU)
#define OCOTP_VERSION_STEP_SHIFT                 (0U)
#define OCOTP_VERSION_STEP(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_STEP_SHIFT)) & OCOTP_VERSION_STEP_MASK)

#define OCOTP_VERSION_MINOR_MASK                 (0xFF0000U)
#define OCOTP_VERSION_MINOR_SHIFT                (16U)
#define OCOTP_VERSION_MINOR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_MINOR_SHIFT)) & OCOTP_VERSION_MINOR_MASK)

#define OCOTP_VERSION_MAJOR_MASK                 (0xFF000000U)
#define OCOTP_VERSION_MAJOR_SHIFT                (24U)
#define OCOTP_VERSION_MAJOR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_MAJOR_SHIFT)) & OCOTP_VERSION_MAJOR_MASK)
/*! @} */

/*! @name LOCK - Value of OTP Bank0 Word0 (Lock controls) */
/*! @{ */

#define OCOTP_LOCK_TESTER_MASK                   (0x3U)
#define OCOTP_LOCK_TESTER_SHIFT                  (0U)
#define OCOTP_LOCK_TESTER(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_TESTER_SHIFT)) & OCOTP_LOCK_TESTER_MASK)

#define OCOTP_LOCK_BOOT_CFG_MASK                 (0xCU)
#define OCOTP_LOCK_BOOT_CFG_SHIFT                (2U)
#define OCOTP_LOCK_BOOT_CFG(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_BOOT_CFG_SHIFT)) & OCOTP_LOCK_BOOT_CFG_MASK)

#define OCOTP_LOCK_MEM_TRIM_MASK                 (0x30U)
#define OCOTP_LOCK_MEM_TRIM_SHIFT                (4U)
#define OCOTP_LOCK_MEM_TRIM(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_MEM_TRIM_SHIFT)) & OCOTP_LOCK_MEM_TRIM_MASK)

#define OCOTP_LOCK_ANALOG_MASK                   (0xC0U)
#define OCOTP_LOCK_ANALOG_SHIFT                  (6U)
#define OCOTP_LOCK_ANALOG(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_ANALOG_SHIFT)) & OCOTP_LOCK_ANALOG_MASK)

#define OCOTP_LOCK_OTPMK_MASK                    (0x100U)
#define OCOTP_LOCK_OTPMK_SHIFT                   (8U)
#define OCOTP_LOCK_OTPMK(x)                      (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_OTPMK_SHIFT)) & OCOTP_LOCK_OTPMK_MASK)

#define OCOTP_LOCK_SRK_MASK                      (0x200U)
#define OCOTP_LOCK_SRK_SHIFT                     (9U)
#define OCOTP_LOCK_SRK(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_SRK_SHIFT)) & OCOTP_LOCK_SRK_MASK)

#define OCOTP_LOCK_SJC_RESP_MASK                 (0x400U)
#define OCOTP_LOCK_SJC_RESP_SHIFT                (10U)
#define OCOTP_LOCK_SJC_RESP(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_SJC_RESP_SHIFT)) & OCOTP_LOCK_SJC_RESP_MASK)

#define OCOTP_LOCK_GROUP_MASK_MASK               (0x800U)
#define OCOTP_LOCK_GROUP_MASK_SHIFT              (11U)
#define OCOTP_LOCK_GROUP_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GROUP_MASK_SHIFT)) & OCOTP_LOCK_GROUP_MASK_MASK)

#define OCOTP_LOCK_USB_ID_MASK                   (0x3000U)
#define OCOTP_LOCK_USB_ID_SHIFT                  (12U)
#define OCOTP_LOCK_USB_ID(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_USB_ID_SHIFT)) & OCOTP_LOCK_USB_ID_MASK)

#define OCOTP_LOCK_MAC_ADDR_MASK                 (0xC000U)
#define OCOTP_LOCK_MAC_ADDR_SHIFT                (14U)
#define OCOTP_LOCK_MAC_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_MAC_ADDR_SHIFT)) & OCOTP_LOCK_MAC_ADDR_MASK)

#define OCOTP_LOCK_MAU_KEY_MASK                  (0x10000U)
#define OCOTP_LOCK_MAU_KEY_SHIFT                 (16U)
#define OCOTP_LOCK_MAU_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_MAU_KEY_SHIFT)) & OCOTP_LOCK_MAU_KEY_MASK)

#define OCOTP_LOCK_ROM_PATCH_MASK                (0x20000U)
#define OCOTP_LOCK_ROM_PATCH_SHIFT               (17U)
#define OCOTP_LOCK_ROM_PATCH(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_ROM_PATCH_SHIFT)) & OCOTP_LOCK_ROM_PATCH_MASK)

#define OCOTP_LOCK_GP_CRC_MASK                   (0xC0000U)
#define OCOTP_LOCK_GP_CRC_SHIFT                  (18U)
#define OCOTP_LOCK_GP_CRC(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GP_CRC_SHIFT)) & OCOTP_LOCK_GP_CRC_MASK)

#define OCOTP_LOCK_GP1_MASK                      (0x300000U)
#define OCOTP_LOCK_GP1_SHIFT                     (20U)
#define OCOTP_LOCK_GP1(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GP1_SHIFT)) & OCOTP_LOCK_GP1_MASK)

#define OCOTP_LOCK_GP2_MASK                      (0xC00000U)
#define OCOTP_LOCK_GP2_SHIFT                     (22U)
#define OCOTP_LOCK_GP2(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GP2_SHIFT)) & OCOTP_LOCK_GP2_MASK)

#define OCOTP_LOCK_HDMI_KEY_MASK                 (0x3000000U)
#define OCOTP_LOCK_HDMI_KEY_SHIFT                (24U)
#define OCOTP_LOCK_HDMI_KEY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_HDMI_KEY_SHIFT)) & OCOTP_LOCK_HDMI_KEY_MASK)

#define OCOTP_LOCK_HDMI_CRC_MASK                 (0xC000000U)
#define OCOTP_LOCK_HDMI_CRC_SHIFT                (26U)
#define OCOTP_LOCK_HDMI_CRC(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_HDMI_CRC_SHIFT)) & OCOTP_LOCK_HDMI_CRC_MASK)

#define OCOTP_LOCK_HDCP_KEY_MASK                 (0x30000000U)
#define OCOTP_LOCK_HDCP_KEY_SHIFT                (28U)
#define OCOTP_LOCK_HDCP_KEY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_HDCP_KEY_SHIFT)) & OCOTP_LOCK_HDCP_KEY_MASK)

#define OCOTP_LOCK_HDCP_CRC_MASK                 (0xC0000000U)
#define OCOTP_LOCK_HDCP_CRC_SHIFT                (30U)
#define OCOTP_LOCK_HDCP_CRC(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_HDCP_CRC_SHIFT)) & OCOTP_LOCK_HDCP_CRC_MASK)
/*! @} */

/*! @name TESTER0 - Value of OTP Bank0 Word1 (Tester Info.) */
/*! @{ */

#define OCOTP_TESTER0_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_TESTER0_BITS_SHIFT                 (0U)
#define OCOTP_TESTER0_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TESTER0_BITS_SHIFT)) & OCOTP_TESTER0_BITS_MASK)
/*! @} */

/*! @name TESTER1 - Value of OTP Bank0 Word2 (tester Info.) */
/*! @{ */

#define OCOTP_TESTER1_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_TESTER1_BITS_SHIFT                 (0U)
#define OCOTP_TESTER1_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TESTER1_BITS_SHIFT)) & OCOTP_TESTER1_BITS_MASK)
/*! @} */

/*! @name TESTER2 - Value of OTP Bank0 Word3 (Tester Info.) */
/*! @{ */

#define OCOTP_TESTER2_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_TESTER2_BITS_SHIFT                 (0U)
#define OCOTP_TESTER2_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TESTER2_BITS_SHIFT)) & OCOTP_TESTER2_BITS_MASK)
/*! @} */

/*! @name TESTER3 - Value of OTP Bank1 Word0 (Tester Info.) */
/*! @{ */

#define OCOTP_TESTER3_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_TESTER3_BITS_SHIFT                 (0U)
#define OCOTP_TESTER3_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TESTER3_BITS_SHIFT)) & OCOTP_TESTER3_BITS_MASK)
/*! @} */

/*! @name TESTER4 - Value of OTP Bank1 Word1 (Tester Info.) */
/*! @{ */

#define OCOTP_TESTER4_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_TESTER4_BITS_SHIFT                 (0U)
#define OCOTP_TESTER4_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TESTER4_BITS_SHIFT)) & OCOTP_TESTER4_BITS_MASK)
/*! @} */

/*! @name TESTER5 - Value of OTP Bank1 Word2 (Tester Info.) */
/*! @{ */

#define OCOTP_TESTER5_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_TESTER5_BITS_SHIFT                 (0U)
#define OCOTP_TESTER5_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TESTER5_BITS_SHIFT)) & OCOTP_TESTER5_BITS_MASK)
/*! @} */

/*! @name BOOT_CFG0 - Value of OTP Bank1 Word3 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_BOOT_CFG0_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_BOOT_CFG0_BITS_SHIFT               (0U)
#define OCOTP_BOOT_CFG0_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_BOOT_CFG0_BITS_SHIFT)) & OCOTP_BOOT_CFG0_BITS_MASK)
/*! @} */

/*! @name BOOT_CFG1 - Value of OTP Bank2 Word0 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_BOOT_CFG1_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_BOOT_CFG1_BITS_SHIFT               (0U)
#define OCOTP_BOOT_CFG1_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_BOOT_CFG1_BITS_SHIFT)) & OCOTP_BOOT_CFG1_BITS_MASK)
/*! @} */

/*! @name BOOT_CFG2 - Value of OTP Bank2 Word1 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_BOOT_CFG2_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_BOOT_CFG2_BITS_SHIFT               (0U)
#define OCOTP_BOOT_CFG2_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_BOOT_CFG2_BITS_SHIFT)) & OCOTP_BOOT_CFG2_BITS_MASK)
/*! @} */

/*! @name BOOT_CFG3 - Value of OTP Bank2 Word2 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_BOOT_CFG3_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_BOOT_CFG3_BITS_SHIFT               (0U)
#define OCOTP_BOOT_CFG3_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_BOOT_CFG3_BITS_SHIFT)) & OCOTP_BOOT_CFG3_BITS_MASK)
/*! @} */

/*! @name BOOT_CFG4 - Value of OTP Bank2 Word3 (BOOT Configuration Info.) */
/*! @{ */

#define OCOTP_BOOT_CFG4_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_BOOT_CFG4_BITS_SHIFT               (0U)
#define OCOTP_BOOT_CFG4_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_BOOT_CFG4_BITS_SHIFT)) & OCOTP_BOOT_CFG4_BITS_MASK)
/*! @} */

/*! @name MEM_TRIM0 - Value of OTP Bank3 Word0 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM_TRIM0_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_MEM_TRIM0_BITS_SHIFT               (0U)
#define OCOTP_MEM_TRIM0_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM_TRIM0_BITS_SHIFT)) & OCOTP_MEM_TRIM0_BITS_MASK)
/*! @} */

/*! @name MEM_TRIM1 - Value of OTP Bank3 Word1 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM_TRIM1_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_MEM_TRIM1_BITS_SHIFT               (0U)
#define OCOTP_MEM_TRIM1_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM_TRIM1_BITS_SHIFT)) & OCOTP_MEM_TRIM1_BITS_MASK)
/*! @} */

/*! @name ANA0 - Value of OTP Bank3 Word2 (Analog Info.) */
/*! @{ */

#define OCOTP_ANA0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_ANA0_BITS_SHIFT                    (0U)
#define OCOTP_ANA0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_ANA0_BITS_SHIFT)) & OCOTP_ANA0_BITS_MASK)
/*! @} */

/*! @name ANA1 - Value of OTP Bank3 Word3 (Analog Info.) */
/*! @{ */

#define OCOTP_ANA1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_ANA1_BITS_SHIFT                    (0U)
#define OCOTP_ANA1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_ANA1_BITS_SHIFT)) & OCOTP_ANA1_BITS_MASK)
/*! @} */

/*! @name SRK0 - Shadow Register for OTP Bank6 Word0 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK0_BITS_SHIFT                    (0U)
#define OCOTP_SRK0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK0_BITS_SHIFT)) & OCOTP_SRK0_BITS_MASK)
/*! @} */

/*! @name SRK1 - Shadow Register for OTP Bank6 Word1 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK1_BITS_SHIFT                    (0U)
#define OCOTP_SRK1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK1_BITS_SHIFT)) & OCOTP_SRK1_BITS_MASK)
/*! @} */

/*! @name SRK2 - Shadow Register for OTP Bank6 Word2 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK2_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK2_BITS_SHIFT                    (0U)
#define OCOTP_SRK2_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK2_BITS_SHIFT)) & OCOTP_SRK2_BITS_MASK)
/*! @} */

/*! @name SRK3 - Shadow Register for OTP Bank6 Word3 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK3_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK3_BITS_SHIFT                    (0U)
#define OCOTP_SRK3_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK3_BITS_SHIFT)) & OCOTP_SRK3_BITS_MASK)
/*! @} */

/*! @name SRK4 - Shadow Register for OTP Bank7 Word0 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK4_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK4_BITS_SHIFT                    (0U)
#define OCOTP_SRK4_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK4_BITS_SHIFT)) & OCOTP_SRK4_BITS_MASK)
/*! @} */

/*! @name SRK5 - Shadow Register for OTP Bank7 Word1 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK5_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK5_BITS_SHIFT                    (0U)
#define OCOTP_SRK5_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK5_BITS_SHIFT)) & OCOTP_SRK5_BITS_MASK)
/*! @} */

/*! @name SRK6 - Shadow Register for OTP Bank7 Word2 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK6_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK6_BITS_SHIFT                    (0U)
#define OCOTP_SRK6_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK6_BITS_SHIFT)) & OCOTP_SRK6_BITS_MASK)
/*! @} */

/*! @name SRK7 - Shadow Register for OTP Bank7 Word3 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK7_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK7_BITS_SHIFT                    (0U)
#define OCOTP_SRK7_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK7_BITS_SHIFT)) & OCOTP_SRK7_BITS_MASK)
/*! @} */

/*! @name SJC_RESP0 - Value of OTP Bank8 Word0 (Secure JTAG Response Field) */
/*! @{ */

#define OCOTP_SJC_RESP0_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_SJC_RESP0_BITS_SHIFT               (0U)
#define OCOTP_SJC_RESP0_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_SJC_RESP0_BITS_SHIFT)) & OCOTP_SJC_RESP0_BITS_MASK)
/*! @} */

/*! @name SJC_RESP1 - Value of OTP Bank8 Word1 (Secure JTAG Response Field) */
/*! @{ */

#define OCOTP_SJC_RESP1_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_SJC_RESP1_BITS_SHIFT               (0U)
#define OCOTP_SJC_RESP1_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_SJC_RESP1_BITS_SHIFT)) & OCOTP_SJC_RESP1_BITS_MASK)
/*! @} */

/*! @name USB_ID - Value of OTP Bank8 Word2 (USB ID info) */
/*! @{ */

#define OCOTP_USB_ID_BITS_MASK                   (0xFFFFFFFFU)
#define OCOTP_USB_ID_BITS_SHIFT                  (0U)
#define OCOTP_USB_ID_BITS(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_USB_ID_BITS_SHIFT)) & OCOTP_USB_ID_BITS_MASK)
/*! @} */

/*! @name FIELD_RETURN - Value of OTP Bank5 Word6 (Field Return) */
/*! @{ */

#define OCOTP_FIELD_RETURN_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_FIELD_RETURN_BITS_SHIFT            (0U)
#define OCOTP_FIELD_RETURN_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_FIELD_RETURN_BITS_SHIFT)) & OCOTP_FIELD_RETURN_BITS_MASK)
/*! @} */

/*! @name MAC_ADDR0 - Value of OTP Bank9 Word0 (MAC Address) */
/*! @{ */

#define OCOTP_MAC_ADDR0_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_MAC_ADDR0_BITS_SHIFT               (0U)
#define OCOTP_MAC_ADDR0_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_MAC_ADDR0_BITS_SHIFT)) & OCOTP_MAC_ADDR0_BITS_MASK)
/*! @} */

/*! @name MAC_ADDR1 - Value of OTP Bank9 Word1 (MAC Address) */
/*! @{ */

#define OCOTP_MAC_ADDR1_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_MAC_ADDR1_BITS_SHIFT               (0U)
#define OCOTP_MAC_ADDR1_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_MAC_ADDR1_BITS_SHIFT)) & OCOTP_MAC_ADDR1_BITS_MASK)
/*! @} */

/*! @name MAC_ADDR2 - Value of OTP Bank9 Word2 (MAC Address) */
/*! @{ */

#define OCOTP_MAC_ADDR2_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_MAC_ADDR2_BITS_SHIFT               (0U)
#define OCOTP_MAC_ADDR2_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_MAC_ADDR2_BITS_SHIFT)) & OCOTP_MAC_ADDR2_BITS_MASK)
/*! @} */

/*! @name SRK_REVOKE - Value of OTP Bank9 Word3 (SRK Revoke) */
/*! @{ */

#define OCOTP_SRK_REVOKE_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_SRK_REVOKE_BITS_SHIFT              (0U)
#define OCOTP_SRK_REVOKE_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK_REVOKE_BITS_SHIFT)) & OCOTP_SRK_REVOKE_BITS_MASK)
/*! @} */

/*! @name MAU_KEY0 - Shadow Register for OTP Bank10 Word0 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY0_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY0_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY0_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY0_BITS_SHIFT)) & OCOTP_MAU_KEY0_BITS_MASK)
/*! @} */

/*! @name MAU_KEY1 - Shadow Register for OTP Bank10 Word1 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY1_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY1_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY1_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY1_BITS_SHIFT)) & OCOTP_MAU_KEY1_BITS_MASK)
/*! @} */

/*! @name MAU_KEY2 - Shadow Register for OTP Bank10 Word2 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY2_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY2_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY2_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY2_BITS_SHIFT)) & OCOTP_MAU_KEY2_BITS_MASK)
/*! @} */

/*! @name MAU_KEY3 - Shadow Register for OTP Bank10 Word3 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY3_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY3_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY3_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY3_BITS_SHIFT)) & OCOTP_MAU_KEY3_BITS_MASK)
/*! @} */

/*! @name MAU_KEY4 - Shadow Register for OTP Bank11 Word0 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY4_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY4_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY4_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY4_BITS_SHIFT)) & OCOTP_MAU_KEY4_BITS_MASK)
/*! @} */

/*! @name MAU_KEY5 - Shadow Register for OTP Bank11 Word1 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY5_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY5_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY5_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY5_BITS_SHIFT)) & OCOTP_MAU_KEY5_BITS_MASK)
/*! @} */

/*! @name MAU_KEY6 - Shadow Register for OTP Bank11 Word2 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY6_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY6_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY6_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY6_BITS_SHIFT)) & OCOTP_MAU_KEY6_BITS_MASK)
/*! @} */

/*! @name MAU_KEY7 - Shadow Register for OTP Bank11 Word3 (MAU Key) */
/*! @{ */

#define OCOTP_MAU_KEY7_BITS_MASK                 (0xFFFFFFFFU)
#define OCOTP_MAU_KEY7_BITS_SHIFT                (0U)
#define OCOTP_MAU_KEY7_BITS(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_MAU_KEY7_BITS_SHIFT)) & OCOTP_MAU_KEY7_BITS_MASK)
/*! @} */

/*! @name GP10 - Value of OTP Bank14 Word0 () */
/*! @{ */

#define OCOTP_GP10_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_GP10_BITS_SHIFT                    (0U)
#define OCOTP_GP10_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_GP10_BITS_SHIFT)) & OCOTP_GP10_BITS_MASK)
/*! @} */

/*! @name GP11 - Value of OTP Bank14 Word1 () */
/*! @{ */

#define OCOTP_GP11_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_GP11_BITS_SHIFT                    (0U)
#define OCOTP_GP11_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_GP11_BITS_SHIFT)) & OCOTP_GP11_BITS_MASK)
/*! @} */

/*! @name GP20 - Value of OTP Bank14 Word2 () */
/*! @{ */

#define OCOTP_GP20_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_GP20_BITS_SHIFT                    (0U)
#define OCOTP_GP20_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_GP20_BITS_SHIFT)) & OCOTP_GP20_BITS_MASK)
/*! @} */

/*! @name GP21 - Value of OTP Bank14 Word3 () */
/*! @{ */

#define OCOTP_GP21_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_GP21_BITS_SHIFT                    (0U)
#define OCOTP_GP21_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_GP21_BITS_SHIFT)) & OCOTP_GP21_BITS_MASK)
/*! @} */

/*! @name GP_CRC0 - Value of OTP Bank15 Word0 (CRC Key) */
/*! @{ */

#define OCOTP_GP_CRC0_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_GP_CRC0_BITS_SHIFT                 (0U)
#define OCOTP_GP_CRC0_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_GP_CRC0_BITS_SHIFT)) & OCOTP_GP_CRC0_BITS_MASK)
/*! @} */

/*! @name GP_CRC1 - Value of OTP Bank15 Word1 (CRC Key) */
/*! @{ */

#define OCOTP_GP_CRC1_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_GP_CRC1_BITS_SHIFT                 (0U)
#define OCOTP_GP_CRC1_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_GP_CRC1_BITS_SHIFT)) & OCOTP_GP_CRC1_BITS_MASK)
/*! @} */

/*! @name GP_CRC2 - Value of OTP Bank15 Word2 (CRC Key) */
/*! @{ */

#define OCOTP_GP_CRC2_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_GP_CRC2_BITS_SHIFT                 (0U)
#define OCOTP_GP_CRC2_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_GP_CRC2_BITS_SHIFT)) & OCOTP_GP_CRC2_BITS_MASK)
/*! @} */

/*! @name GROUP_MASK - Value of OTP Bank15 Word3 (CRC Key) */
/*! @{ */

#define OCOTP_GROUP_MASK_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_GROUP_MASK_BITS_SHIFT              (0U)
#define OCOTP_GROUP_MASK_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_GROUP_MASK_BITS_SHIFT)) & OCOTP_GROUP_MASK_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK0 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK0_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK0_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK0_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK0_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK0_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK1 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK1_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK1_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK1_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK1_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK1_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK2 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK2_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK2_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK2_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK2_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK2_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK3 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK3_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK3_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK3_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK3_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK3_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK4 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK4_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK4_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK4_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK4_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK4_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK5 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK5_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK5_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK5_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK5_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK5_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK6 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK6_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK6_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK6_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK6_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK6_BITS_MASK)
/*! @} */

/*! @name HDMI_FW_SRK7 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_FW_SRK7_BITS_MASK             (0xFFFFFFFFU)
#define OCOTP_HDMI_FW_SRK7_BITS_SHIFT            (0U)
#define OCOTP_HDMI_FW_SRK7_BITS(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_FW_SRK7_BITS_SHIFT)) & OCOTP_HDMI_FW_SRK7_BITS_MASK)
/*! @} */

/*! @name HDMI_KMEK0 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_KMEK0_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDMI_KMEK0_BITS_SHIFT              (0U)
#define OCOTP_HDMI_KMEK0_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_KMEK0_BITS_SHIFT)) & OCOTP_HDMI_KMEK0_BITS_MASK)
/*! @} */

/*! @name HDMI_KMEK1 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_KMEK1_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDMI_KMEK1_BITS_SHIFT              (0U)
#define OCOTP_HDMI_KMEK1_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_KMEK1_BITS_SHIFT)) & OCOTP_HDMI_KMEK1_BITS_MASK)
/*! @} */

/*! @name HDMI_KMEK2 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_KMEK2_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDMI_KMEK2_BITS_SHIFT              (0U)
#define OCOTP_HDMI_KMEK2_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_KMEK2_BITS_SHIFT)) & OCOTP_HDMI_KMEK2_BITS_MASK)
/*! @} */

/*! @name HDMI_KMEK3 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDMI_KMEK3_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDMI_KMEK3_BITS_SHIFT              (0U)
#define OCOTP_HDMI_KMEK3_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDMI_KMEK3_BITS_SHIFT)) & OCOTP_HDMI_KMEK3_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CONS0 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CONS0_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CONS0_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CONS0_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CONS0_BITS_SHIFT)) & OCOTP_HDCP_TX_CONS0_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CONS1 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CONS1_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CONS1_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CONS1_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CONS1_BITS_SHIFT)) & OCOTP_HDCP_TX_CONS1_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CONS2 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CONS2_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CONS2_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CONS2_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CONS2_BITS_SHIFT)) & OCOTP_HDCP_TX_CONS2_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CONS3 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CONS3_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CONS3_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CONS3_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CONS3_BITS_SHIFT)) & OCOTP_HDCP_TX_CONS3_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT0 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT0_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT0_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT0_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT0_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT0_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT1 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT1_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT1_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT1_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT1_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT1_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT2 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT2_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT2_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT2_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT2_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT2_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT3 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT3_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT3_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT3_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT3_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT3_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT4 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT4_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT4_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT4_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT4_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT4_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT5 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT5_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT5_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT5_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT5_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT5_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT6 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT6_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT6_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT6_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT6_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT6_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT7 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT7_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT7_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT7_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT7_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT7_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT8 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT8_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT8_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT8_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT8_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT8_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT9 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT9_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT9_BITS_SHIFT           (0U)
#define OCOTP_HDCP_TX_CERT9_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT9_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT9_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT10 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT10_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT10_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT10_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT10_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT10_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT11 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT11_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT11_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT11_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT11_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT11_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT12 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT12_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT12_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT12_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT12_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT12_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT13 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT13_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT13_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT13_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT13_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT13_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT14 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT14_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT14_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT14_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT14_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT14_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT15 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT15_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT15_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT15_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT15_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT15_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT16 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT16_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT16_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT16_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT16_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT16_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT17 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT17_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT17_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT17_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT17_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT17_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT18 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT18_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT18_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT18_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT18_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT18_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT19 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT19_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT19_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT19_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT19_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT19_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT20 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT20_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT20_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT20_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT20_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT20_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT21 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT21_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT21_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT21_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT21_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT21_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT22 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT22_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT22_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT22_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT22_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT22_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT23 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT23_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT23_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT23_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT23_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT23_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT24 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT24_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT24_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT24_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT24_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT24_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT25 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT25_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT25_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT25_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT25_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT25_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT26 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT26_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT26_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT26_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT26_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT26_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT27 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT27_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT27_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT27_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT27_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT27_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT28 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT28_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT28_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT28_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT28_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT28_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT29 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT29_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT29_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT29_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT29_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT29_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT30 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT30_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT30_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT30_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT30_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT30_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT31 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT31_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT31_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT31_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT31_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT31_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT32 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT32_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT32_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT32_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT32_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT32_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT33 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT33_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT33_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT33_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT33_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT33_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT34 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT34_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT34_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT34_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT34_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT34_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT35 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT35_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT35_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT35_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT35_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT35_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT36 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT36_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT36_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT36_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT36_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT36_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT37 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT37_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT37_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT37_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT37_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT37_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT38 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT38_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT38_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT38_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT38_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT38_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT39 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT39_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT39_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT39_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT39_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT39_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT40 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT40_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT40_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT40_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT40_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT40_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT41 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT41_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT41_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT41_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT41_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT41_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT42 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT42_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT42_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT42_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT42_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT42_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT43 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT43_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT43_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT43_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT43_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT43_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT44 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT44_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT44_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT44_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT44_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT44_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT45 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT45_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT45_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT45_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT45_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT45_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT46 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT46_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT46_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT46_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT46_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT46_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT47 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT47_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT47_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT47_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT47_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT47_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT48 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT48_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT48_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT48_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT48_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT48_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT49 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT49_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT49_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT49_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT49_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT49_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT50 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT50_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT50_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT50_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT50_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT50_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT51 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT51_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT51_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT51_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT51_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT51_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT52 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT52_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT52_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT52_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT52_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT52_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT53 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT53_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT53_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT53_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT53_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT53_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT54 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT54_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT54_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT54_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT54_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT54_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT55 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT55_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT55_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT55_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT55_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT55_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT56 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT56_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT56_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT56_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT56_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT56_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT57 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT57_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT57_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT57_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT57_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT57_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT58 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT58_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT58_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT58_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT58_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT58_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT59 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT59_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT59_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT59_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT59_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT59_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT60 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT60_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT60_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT60_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT60_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT60_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT61 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT61_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT61_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT61_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT61_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT61_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT62 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT62_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT62_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT62_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT62_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT62_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT63 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT63_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT63_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT63_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT63_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT63_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT64 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT64_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT64_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT64_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT64_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT64_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT65 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT65_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT65_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT65_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT65_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT65_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT66 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT66_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT66_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT66_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT66_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT66_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT67 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT67_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT67_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT67_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT67_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT67_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT68 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT68_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT68_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT68_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT68_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT68_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT69 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT69_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT69_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT69_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT69_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT69_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT70 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT70_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT70_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT70_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT70_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT70_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT71 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT71_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT71_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT71_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT71_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT71_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT72 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT72_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT72_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT72_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT72_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT72_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT73 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT73_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT73_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT73_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT73_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT73_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT74 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT74_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT74_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT74_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT74_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT74_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT75 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT75_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT75_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT75_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT75_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT75_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT76 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT76_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT76_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT76_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT76_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT76_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT77 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT77_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT77_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT77_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT77_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT77_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT78 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT78_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT78_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT78_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT78_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT78_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT79 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT79_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT79_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT79_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT79_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT79_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT80 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT80_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT80_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT80_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT80_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT80_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT81 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT81_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT81_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT81_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT81_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT81_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT82 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT82_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT82_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT82_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT82_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT82_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT83 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT83_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT83_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT83_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT83_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT83_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT84 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT84_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT84_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT84_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT84_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT84_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT85 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT85_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT85_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT85_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT85_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT85_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT86 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT86_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT86_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT86_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT86_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT86_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT87 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT87_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT87_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT87_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT87_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT87_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT88 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT88_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT88_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT88_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT88_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT88_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT89 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT89_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT89_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT89_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT89_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT89_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT90 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT90_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT90_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT90_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT90_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT90_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT91 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT91_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT91_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT91_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT91_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT91_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT92 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT92_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT92_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT92_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT92_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT92_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT93 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT93_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT93_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT93_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT93_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT93_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT94 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT94_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT94_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT94_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT94_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT94_BITS_MASK)
/*! @} */

/*! @name HDCP_TX_CERT95 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_TX_CERT95_BITS_MASK           (0xFFFFFFFFU)
#define OCOTP_HDCP_TX_CERT95_BITS_SHIFT          (0U)
#define OCOTP_HDCP_TX_CERT95_BITS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_TX_CERT95_BITS_SHIFT)) & OCOTP_HDCP_TX_CERT95_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY0 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY0_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY0_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY0_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY0_BITS_SHIFT)) & OCOTP_HDCP_KEY0_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY1 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY1_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY1_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY1_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY1_BITS_SHIFT)) & OCOTP_HDCP_KEY1_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY2 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY2_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY2_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY2_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY2_BITS_SHIFT)) & OCOTP_HDCP_KEY2_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY3 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY3_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY3_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY3_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY3_BITS_SHIFT)) & OCOTP_HDCP_KEY3_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY4 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY4_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY4_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY4_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY4_BITS_SHIFT)) & OCOTP_HDCP_KEY4_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY5 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY5_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY5_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY5_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY5_BITS_SHIFT)) & OCOTP_HDCP_KEY5_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY6 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY6_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY6_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY6_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY6_BITS_SHIFT)) & OCOTP_HDCP_KEY6_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY7 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY7_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY7_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY7_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY7_BITS_SHIFT)) & OCOTP_HDCP_KEY7_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY8 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY8_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY8_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY8_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY8_BITS_SHIFT)) & OCOTP_HDCP_KEY8_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY9 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY9_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY9_BITS_SHIFT               (0U)
#define OCOTP_HDCP_KEY9_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY9_BITS_SHIFT)) & OCOTP_HDCP_KEY9_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY10 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY10_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY10_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY10_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY10_BITS_SHIFT)) & OCOTP_HDCP_KEY10_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY11 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY11_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY11_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY11_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY11_BITS_SHIFT)) & OCOTP_HDCP_KEY11_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY12 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY12_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY12_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY12_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY12_BITS_SHIFT)) & OCOTP_HDCP_KEY12_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY13 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY13_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY13_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY13_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY13_BITS_SHIFT)) & OCOTP_HDCP_KEY13_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY14 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY14_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY14_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY14_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY14_BITS_SHIFT)) & OCOTP_HDCP_KEY14_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY15 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY15_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY15_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY15_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY15_BITS_SHIFT)) & OCOTP_HDCP_KEY15_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY16 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY16_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY16_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY16_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY16_BITS_SHIFT)) & OCOTP_HDCP_KEY16_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY17 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY17_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY17_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY17_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY17_BITS_SHIFT)) & OCOTP_HDCP_KEY17_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY18 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY18_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY18_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY18_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY18_BITS_SHIFT)) & OCOTP_HDCP_KEY18_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY19 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY19_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY19_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY19_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY19_BITS_SHIFT)) & OCOTP_HDCP_KEY19_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY20 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY20_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY20_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY20_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY20_BITS_SHIFT)) & OCOTP_HDCP_KEY20_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY21 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY21_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY21_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY21_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY21_BITS_SHIFT)) & OCOTP_HDCP_KEY21_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY22 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY22_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY22_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY22_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY22_BITS_SHIFT)) & OCOTP_HDCP_KEY22_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY23 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY23_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY23_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY23_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY23_BITS_SHIFT)) & OCOTP_HDCP_KEY23_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY24 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY24_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY24_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY24_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY24_BITS_SHIFT)) & OCOTP_HDCP_KEY24_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY25 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY25_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY25_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY25_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY25_BITS_SHIFT)) & OCOTP_HDCP_KEY25_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY26 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY26_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY26_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY26_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY26_BITS_SHIFT)) & OCOTP_HDCP_KEY26_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY27 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY27_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY27_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY27_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY27_BITS_SHIFT)) & OCOTP_HDCP_KEY27_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY28 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY28_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY28_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY28_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY28_BITS_SHIFT)) & OCOTP_HDCP_KEY28_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY29 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY29_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY29_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY29_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY29_BITS_SHIFT)) & OCOTP_HDCP_KEY29_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY30 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY30_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY30_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY30_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY30_BITS_SHIFT)) & OCOTP_HDCP_KEY30_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY31 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY31_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY31_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY31_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY31_BITS_SHIFT)) & OCOTP_HDCP_KEY31_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY32 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY32_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY32_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY32_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY32_BITS_SHIFT)) & OCOTP_HDCP_KEY32_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY33 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY33_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY33_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY33_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY33_BITS_SHIFT)) & OCOTP_HDCP_KEY33_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY34 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY34_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY34_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY34_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY34_BITS_SHIFT)) & OCOTP_HDCP_KEY34_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY35 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY35_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY35_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY35_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY35_BITS_SHIFT)) & OCOTP_HDCP_KEY35_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY36 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY36_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY36_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY36_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY36_BITS_SHIFT)) & OCOTP_HDCP_KEY36_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY37 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY37_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY37_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY37_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY37_BITS_SHIFT)) & OCOTP_HDCP_KEY37_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY38 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY38_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY38_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY38_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY38_BITS_SHIFT)) & OCOTP_HDCP_KEY38_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY39 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY39_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY39_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY39_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY39_BITS_SHIFT)) & OCOTP_HDCP_KEY39_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY40 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY40_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY40_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY40_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY40_BITS_SHIFT)) & OCOTP_HDCP_KEY40_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY41 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY41_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY41_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY41_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY41_BITS_SHIFT)) & OCOTP_HDCP_KEY41_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY42 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY42_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY42_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY42_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY42_BITS_SHIFT)) & OCOTP_HDCP_KEY42_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY43 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY43_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY43_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY43_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY43_BITS_SHIFT)) & OCOTP_HDCP_KEY43_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY44 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY44_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY44_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY44_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY44_BITS_SHIFT)) & OCOTP_HDCP_KEY44_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY45 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY45_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY45_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY45_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY45_BITS_SHIFT)) & OCOTP_HDCP_KEY45_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY46 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY46_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY46_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY46_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY46_BITS_SHIFT)) & OCOTP_HDCP_KEY46_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY47 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY47_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY47_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY47_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY47_BITS_SHIFT)) & OCOTP_HDCP_KEY47_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY48 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY48_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY48_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY48_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY48_BITS_SHIFT)) & OCOTP_HDCP_KEY48_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY49 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY49_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY49_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY49_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY49_BITS_SHIFT)) & OCOTP_HDCP_KEY49_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY50 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY50_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY50_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY50_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY50_BITS_SHIFT)) & OCOTP_HDCP_KEY50_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY51 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY51_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY51_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY51_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY51_BITS_SHIFT)) & OCOTP_HDCP_KEY51_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY52 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY52_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY52_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY52_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY52_BITS_SHIFT)) & OCOTP_HDCP_KEY52_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY53 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY53_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY53_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY53_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY53_BITS_SHIFT)) & OCOTP_HDCP_KEY53_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY54 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY54_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY54_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY54_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY54_BITS_SHIFT)) & OCOTP_HDCP_KEY54_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY55 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY55_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY55_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY55_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY55_BITS_SHIFT)) & OCOTP_HDCP_KEY55_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY56 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY56_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY56_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY56_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY56_BITS_SHIFT)) & OCOTP_HDCP_KEY56_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY57 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY57_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY57_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY57_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY57_BITS_SHIFT)) & OCOTP_HDCP_KEY57_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY58 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY58_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY58_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY58_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY58_BITS_SHIFT)) & OCOTP_HDCP_KEY58_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY59 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY59_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY59_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY59_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY59_BITS_SHIFT)) & OCOTP_HDCP_KEY59_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY60 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY60_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY60_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY60_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY60_BITS_SHIFT)) & OCOTP_HDCP_KEY60_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY61 - Value of OTP Bank16 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY61_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY61_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY61_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY61_BITS_SHIFT)) & OCOTP_HDCP_KEY61_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY62 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY62_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY62_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY62_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY62_BITS_SHIFT)) & OCOTP_HDCP_KEY62_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY63 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY63_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY63_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY63_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY63_BITS_SHIFT)) & OCOTP_HDCP_KEY63_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY64 - Value of OTP Bank17 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY64_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY64_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY64_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY64_BITS_SHIFT)) & OCOTP_HDCP_KEY64_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY65 - Value of OTP Bank17 Word1 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY65_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY65_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY65_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY65_BITS_SHIFT)) & OCOTP_HDCP_KEY65_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY66 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY66_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY66_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY66_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY66_BITS_SHIFT)) & OCOTP_HDCP_KEY66_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY67 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY67_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY67_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY67_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY67_BITS_SHIFT)) & OCOTP_HDCP_KEY67_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY68 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY68_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY68_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY68_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY68_BITS_SHIFT)) & OCOTP_HDCP_KEY68_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY69 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY69_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY69_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY69_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY69_BITS_SHIFT)) & OCOTP_HDCP_KEY69_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY70 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY70_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY70_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY70_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY70_BITS_SHIFT)) & OCOTP_HDCP_KEY70_BITS_MASK)
/*! @} */

/*! @name HDCP_KEY71 - Value of OTP Bank16 Word0 (HDCP Key) */
/*! @{ */

#define OCOTP_HDCP_KEY71_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_HDCP_KEY71_BITS_SHIFT              (0U)
#define OCOTP_HDCP_KEY71_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_HDCP_KEY71_BITS_SHIFT)) & OCOTP_HDCP_KEY71_BITS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCOTP_Register_Masks */


/*!
 * @}
 */ /* end of group OCOTP_Peripheral_Access_Layer */


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


#endif  /* PERI_OCOTP_H_ */

