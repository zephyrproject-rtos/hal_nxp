/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OCOTP_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OCOTP_CTRL.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCOTP_CTRL
 *
 * CMSIS Peripheral Access Layer for OCOTP_CTRL
 */

#if !defined(PERI_OCOTP_CTRL_H_)
#define PERI_OCOTP_CTRL_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- OCOTP_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_CTRL_Peripheral_Access_Layer OCOTP_CTRL Peripheral Access Layer
 * @{
 */

/** OCOTP_CTRL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< OTP Controller Control Register, offset: 0x0 */
    __IO uint32_t SET;                               /**< OTP Controller Control Register, offset: 0x4 */
    __IO uint32_t CLR;                               /**< OTP Controller Control Register, offset: 0x8 */
    __IO uint32_t TOG;                               /**< OTP Controller Control Register, offset: 0xC */
  } HW_OCOTP_CTRL;
  __IO uint32_t HW_OCOTP_PDN;                      /**< OTP Controller PDN Register, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t HW_OCOTP_DATA;                     /**< OTP Controller Write Data Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t HW_OCOTP_READ_CTRL;                /**< OTP Controller Read Control Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __I  uint32_t HW_OCOTP_READ_FUSE_DATA;           /**< OTP Controller Read Fuse Data Register, offset: 0x40 */
       uint8_t RESERVED_3[12];
  __IO uint32_t HW_OCOTP_SW_STICKY;                /**< OTP Controller Sticky Bit Register, offset: 0x50 */
       uint8_t RESERVED_4[12];
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< OTP Controller Software Controllable Signals Register, offset: 0x60 */
    __IO uint32_t SET;                               /**< OTP Controller Software Controllable Signals Register, offset: 0x64 */
    __IO uint32_t CLR;                               /**< OTP Controller Software Controllable Signals Register, offset: 0x68 */
    __IO uint32_t TOG;                               /**< OTP Controller Software Controllable Signals Register, offset: 0x6C */
  } HW_OCOTP_SCS;
       uint8_t RESERVED_5[32];
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< OTP Controller Output Status Register, offset: 0x90 */
    __IO uint32_t SET;                               /**< OTP Controller Output Status Register, offset: 0x94 */
    __IO uint32_t CLR;                               /**< OTP Controller Output Status Register, offset: 0x98 */
    __IO uint32_t TOG;                               /**< OTP Controller Output Status Register, offset: 0x9C */
  } HW_OCOTP_OUT_STATUS;
  __I  uint32_t HW_OCOTP_STARTWORD;                /**< OTP Controller Output Startword Register, offset: 0xA0 */
       uint8_t RESERVED_6[12];
  __I  uint32_t HW_OCOTP_VERSION;                  /**< OTP Controller Version Register, offset: 0xB0 */
       uint8_t RESERVED_7[972];
  __I  uint32_t HW_OCOTP_LOCK0;                    /**< OTP Controller Lock Control Register 0, offset: 0x480 */
       uint8_t RESERVED_8[12];
  __I  uint32_t HW_OCOTP_LOCK1;                    /**< OTP Controller Lock Control Register 1, offset: 0x490 */
       uint8_t RESERVED_9[12];
  __I  uint32_t HW_OCOTP_LOCK2;                    /**< OTP Controller Lock Control Register 2, offset: 0x4A0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t HW_OCOTP_CFG0;                     /**< Value of OTP Bank1 Word3 (ID Info.), offset: 0x4B0 */
       uint8_t RESERVED_11[12];
  __IO uint32_t HW_OCOTP_CFG1;                     /**< Value of OTP Bank1 Word4 (ID Info.), offset: 0x4C0 */
       uint8_t RESERVED_12[12];
  __IO uint32_t HW_OCOTP_CFG2;                     /**< Value of OTP Bank1 Word5 (ID Info.), offset: 0x4D0 */
       uint8_t RESERVED_13[12];
  __IO uint32_t HW_OCOTP_CFG3;                     /**< Value of OTP Bank1 Word6 (ID Info.), offset: 0x4E0 */
       uint8_t RESERVED_14[12];
  __IO uint32_t HW_OCOTP_CFG4;                     /**< Value of OTP Bank1 Word7 (ID Info.), offset: 0x4F0 */
       uint8_t RESERVED_15[12];
  __IO uint32_t HW_OCOTP_BOOT0;                    /**< Value of OTP Bank2 Word0 (Boot Configuration Info.), offset: 0x500 */
       uint8_t RESERVED_16[44];
  __IO uint32_t HW_OCOTP_BOOT3;                    /**< OTP Controller Boot Configuration Register 3, offset: 0x530 */
       uint8_t RESERVED_17[12];
  __IO uint32_t HW_OCOTP_BOOT4;                    /**< OTP Controller Boot Configuration Register 4, offset: 0x540 */
       uint8_t RESERVED_18[12];
  __IO uint32_t HW_OCOTP_BOOT5;                    /**< OTP Controller Boot Configuration Register 5, offset: 0x550 */
       uint8_t RESERVED_19[12];
  __IO uint32_t HW_OCOTP_BOOT6;                    /**< OTP Controller Boot Configuration Register 6, offset: 0x560 */
       uint8_t RESERVED_20[12];
  __IO uint32_t HW_OCOTP_BOOT7;                    /**< OTP Controller Boot Configuration Register 7, offset: 0x570 */
       uint8_t RESERVED_21[92];
  __IO uint32_t HW_OCOTP_ANA1;                     /**< Value of OTP Bank3 Word5 (Memory Related Info.), offset: 0x5D0 */
       uint8_t RESERVED_22[12];
  __IO uint32_t HW_OCOTP_ANA2;                     /**< OTP Controller Analog Register 2, offset: 0x5E0 */
       uint8_t RESERVED_23[12];
  __IO uint32_t HW_OCOTP_ANA3;                     /**< OTP Controller Analog Register 3, offset: 0x5F0 */
       uint8_t RESERVED_24[668];
  __IO uint32_t HW_OCOTP_PAD_MISC1;                /**< Value of OTP Bank9 Word1, offset: 0x890 */
       uint8_t RESERVED_25[28];
  __IO uint32_t HW_OCOTP_PAD_MISC3;                /**< Value of OTP Bank9 Word3, offset: 0x8B0 */
       uint8_t RESERVED_26[1868];
  __IO uint32_t HW_OCOTP_GP60;                     /**< Value of OTP Bank24 Word0 (GP6), offset: 0x1000 */
       uint8_t RESERVED_27[12];
  __IO uint32_t HW_OCOTP_GP61;                     /**< Value of OTP Bank24 Word1 (GP6), offset: 0x1010 */
       uint8_t RESERVED_28[12];
  __IO uint32_t HW_OCOTP_GP62;                     /**< Value of OTP Bank24 Word2 (GP6), offset: 0x1020 */
       uint8_t RESERVED_29[12];
  __IO uint32_t HW_OCOTP_GP63;                     /**< Value of OTP Bank24 Word3 (GP6), offset: 0x1030 */
       uint8_t RESERVED_30[12];
  __IO uint32_t HW_OCOTP_GP64;                     /**< Value of OTP Bank24 Word4 (GP6), offset: 0x1040 */
       uint8_t RESERVED_31[12];
  __IO uint32_t HW_OCOTP_GP65;                     /**< Value of OTP Bank24 Word5 (GP6), offset: 0x1050 */
       uint8_t RESERVED_32[12];
  __IO uint32_t HW_OCOTP_GP66;                     /**< Value of OTP Bank24 Word6 (GP6), offset: 0x1060 */
       uint8_t RESERVED_33[12];
  __IO uint32_t HW_OCOTP_GP67;                     /**< Value of OTP Bank24 Word7 (GP6), offset: 0x1070 */
       uint8_t RESERVED_34[12];
  __IO uint32_t HW_OCOTP_GP70;                     /**< Value of OTP Bank25 Word0 (GP7), offset: 0x1080 */
       uint8_t RESERVED_35[12];
  __IO uint32_t HW_OCOTP_GP71;                     /**< Value of OTP Bank25 Word1 (GP7), offset: 0x1090 */
       uint8_t RESERVED_36[12];
  __IO uint32_t HW_OCOTP_GP72;                     /**< Value of OTP Bank25 Word2 (GP7), offset: 0x10A0 */
       uint8_t RESERVED_37[12];
  __IO uint32_t HW_OCOTP_GP73;                     /**< Value of OTP Bank25 Word3 (GP7), offset: 0x10B0 */
       uint8_t RESERVED_38[12];
  __IO uint32_t HW_OCOTP_GP74;                     /**< Value of OTP Bank25 Word4 (GP7), offset: 0x10C0 */
       uint8_t RESERVED_39[12];
  __IO uint32_t HW_OCOTP_GP75;                     /**< Value of OTP Bank25 Word5 (GP7), offset: 0x10D0 */
       uint8_t RESERVED_40[12];
  __IO uint32_t HW_OCOTP_GP76;                     /**< Value of OTP Bank25 Word6 (GP7), offset: 0x10E0 */
       uint8_t RESERVED_41[12];
  __IO uint32_t HW_OCOTP_GP77;                     /**< Value of OTP Bank25 Word7 (GP7), offset: 0x10F0 */
       uint8_t RESERVED_42[12];
  __IO uint32_t HW_OCOTP_GP80;                     /**< Value of OTP Bank26 Word0 (GP8), offset: 0x1100 */
       uint8_t RESERVED_43[12];
  __IO uint32_t HW_OCOTP_GP81;                     /**< Value of OTP Bank26 Word1 (GP8), offset: 0x1110 */
       uint8_t RESERVED_44[12];
  __IO uint32_t HW_OCOTP_GP82;                     /**< Value of OTP Bank26 Word2 (GP8), offset: 0x1120 */
       uint8_t RESERVED_45[12];
  __IO uint32_t HW_OCOTP_GP83;                     /**< Value of OTP Bank26 Word3 (GP8), offset: 0x1130 */
       uint8_t RESERVED_46[12];
  __IO uint32_t HW_OCOTP_GP84;                     /**< Value of OTP Bank26 Word4 (GP8), offset: 0x1140 */
       uint8_t RESERVED_47[12];
  __IO uint32_t HW_OCOTP_GP85;                     /**< Value of OTP Bank26 Word5 (GP8), offset: 0x1150 */
       uint8_t RESERVED_48[12];
  __IO uint32_t HW_OCOTP_GP86;                     /**< Value of OTP Bank26 Word6 (GP8), offset: 0x1160 */
       uint8_t RESERVED_49[12];
  __IO uint32_t HW_OCOTP_GP87;                     /**< Value of OTP Bank26 Word7 (GP8), offset: 0x1170 */
       uint8_t RESERVED_50[12];
  __IO uint32_t HW_OCOTP_GP90;                     /**< Value of OTP Bank27 Word0 (GP9), offset: 0x1180 */
       uint8_t RESERVED_51[12];
  __IO uint32_t HW_OCOTP_GP91;                     /**< Value of OTP Bank27 Word1 (GP9), offset: 0x1190 */
       uint8_t RESERVED_52[12];
  __IO uint32_t HW_OCOTP_GP92;                     /**< Value of OTP Bank27 Word2 (GP9), offset: 0x11A0 */
       uint8_t RESERVED_53[12];
  __IO uint32_t HW_OCOTP_GP93;                     /**< Value of OTP Bank27 Word3 (GP9), offset: 0x11B0 */
       uint8_t RESERVED_54[12];
  __IO uint32_t HW_OCOTP_GP94;                     /**< Value of OTP Bank27 Word4 (GP9), offset: 0x11C0 */
       uint8_t RESERVED_55[12];
  __IO uint32_t HW_OCOTP_GP95;                     /**< Value of OTP Bank27 Word5 (GP9), offset: 0x11D0 */
       uint8_t RESERVED_56[12];
  __IO uint32_t HW_OCOTP_GP96;                     /**< Value of OTP Bank27 Word6 (GP9), offset: 0x11E0 */
       uint8_t RESERVED_57[12];
  __IO uint32_t HW_OCOTP_GP97;                     /**< Value of OTP Bank27 Word7 (GP9), offset: 0x11F0 */
       uint8_t RESERVED_58[124];
  __IO uint32_t HW_OCOTP_GP107;                    /**< Value of OTP Bank28 Word7, offset: 0x1270 */
       uint8_t RESERVED_59[12];
  __IO uint32_t HW_OCOTP_OTFAD_KEY0;               /**< OTP Controller OTFAD Key Register 0, offset: 0x1280 */
       uint8_t RESERVED_60[12];
  __IO uint32_t HW_OCOTP_OTFAD_KEY1;               /**< OTP Controller OTFAD Key Register 1, offset: 0x1290 */
       uint8_t RESERVED_61[12];
  __IO uint32_t HW_OCOTP_OTFAD_KEY2;               /**< OTP Controller OTFAD Key Register 2, offset: 0x12A0 */
       uint8_t RESERVED_62[12];
  __IO uint32_t HW_OCOTP_OTFAD_KEY3;               /**< OTP Controller OTFAD Key Register 3, offset: 0x12B0 */
       uint8_t RESERVED_63[12];
  __IO uint32_t HW_OCOTP_OTFAD_CFG0;               /**< OTP Controller OTFAD Configuration Register 0, offset: 0x12C0 */
       uint8_t RESERVED_64[12];
  __IO uint32_t HW_OCOTP_OTFAD_CFG1;               /**< OTP Controller OTFAD Configuration Register 1, offset: 0x12D0 */
       uint8_t RESERVED_65[12];
  __IO uint32_t HW_OCOTP_OTFAD_CFG2;               /**< OTP Controller OTFAD Configuration Register 2, offset: 0x12E0 */
       uint8_t RESERVED_66[12];
  __IO uint32_t HW_OCOTP_OTFAD_CFG3;               /**< OTP Controller OTFAD Configuration Register 3, offset: 0x12F0 */
} OCOTP_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- OCOTP_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_CTRL_Register_Masks OCOTP_CTRL Register Masks
 * @{
 */

/*! @name HW_OCOTP_CTRL - OTP Controller Control Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_CTRL_ADDR_MASK       (0xFFU)
#define OCOTP_CTRL_HW_OCOTP_CTRL_ADDR_SHIFT      (0U)
/*! ADDR - ADDRESS */
#define OCOTP_CTRL_HW_OCOTP_CTRL_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_ADDR_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_ADDR_MASK)

#define OCOTP_CTRL_HW_OCOTP_CTRL_BUSY_MASK       (0x100U)
#define OCOTP_CTRL_HW_OCOTP_CTRL_BUSY_SHIFT      (8U)
/*! BUSY - BUSY */
#define OCOTP_CTRL_HW_OCOTP_CTRL_BUSY(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_BUSY_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_BUSY_MASK)

#define OCOTP_CTRL_HW_OCOTP_CTRL_ERROR_MASK      (0x200U)
#define OCOTP_CTRL_HW_OCOTP_CTRL_ERROR_SHIFT     (9U)
/*! ERROR - ERROR */
#define OCOTP_CTRL_HW_OCOTP_CTRL_ERROR(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_ERROR_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_ERROR_MASK)

#define OCOTP_CTRL_HW_OCOTP_CTRL_RELOAD_SHADOWS_MASK (0x400U)
#define OCOTP_CTRL_HW_OCOTP_CTRL_RELOAD_SHADOWS_SHIFT (10U)
/*! RELOAD_SHADOWS - RELOAD_SHADOWS */
#define OCOTP_CTRL_HW_OCOTP_CTRL_RELOAD_SHADOWS(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_HW_OCOTP_CTRL_SUPPADD_MASK    (0x2000U)
#define OCOTP_CTRL_HW_OCOTP_CTRL_SUPPADD_SHIFT   (13U)
/*! SUPPADD - Supplementary Address */
#define OCOTP_CTRL_HW_OCOTP_CTRL_SUPPADD(x)      (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_SUPPADD_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_SUPPADD_MASK)

#define OCOTP_CTRL_HW_OCOTP_CTRL_WORDLOCK_MASK   (0x4000U)
#define OCOTP_CTRL_HW_OCOTP_CTRL_WORDLOCK_SHIFT  (14U)
/*! WORDLOCK - WORDLOCK */
#define OCOTP_CTRL_HW_OCOTP_CTRL_WORDLOCK(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_WORDLOCK_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_WORDLOCK_MASK)

#define OCOTP_CTRL_HW_OCOTP_CTRL_WR_UNLOCK_MASK  (0xFFFF0000U)
#define OCOTP_CTRL_HW_OCOTP_CTRL_WR_UNLOCK_SHIFT (16U)
/*! WR_UNLOCK - Write Unlock
 *  0b0000000000000000..OTP write accesses are locked.
 *  0b0011111001110111..OPT write access is unlocked.
 */
#define OCOTP_CTRL_HW_OCOTP_CTRL_WR_UNLOCK(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CTRL_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CTRL_WR_UNLOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_PDN - OTP Controller PDN Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_PDN_PDN_MASK         (0x1U)
#define OCOTP_CTRL_HW_OCOTP_PDN_PDN_SHIFT        (0U)
/*! PDN - PDN */
#define OCOTP_CTRL_HW_OCOTP_PDN_PDN(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_PDN_PDN_SHIFT)) & OCOTP_CTRL_HW_OCOTP_PDN_PDN_MASK)
/*! @} */

/*! @name HW_OCOTP_DATA - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_DATA_DATA_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_DATA_DATA_SHIFT      (0U)
/*! DATA - DATA */
#define OCOTP_CTRL_HW_OCOTP_DATA_DATA(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_DATA_DATA_SHIFT)) & OCOTP_CTRL_HW_OCOTP_DATA_DATA_MASK)
/*! @} */

/*! @name HW_OCOTP_READ_CTRL - OTP Controller Read Control Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_READ_CTRL_READ_FUSE_MASK (0x1U)
#define OCOTP_CTRL_HW_OCOTP_READ_CTRL_READ_FUSE_SHIFT (0U)
/*! READ_FUSE - READ_FUSE */
#define OCOTP_CTRL_HW_OCOTP_READ_CTRL_READ_FUSE(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_READ_CTRL_READ_FUSE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_READ_CTRL_READ_FUSE_MASK)
/*! @} */

/*! @name HW_OCOTP_READ_FUSE_DATA - OTP Controller Read Fuse Data Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_READ_FUSE_DATA_DATA_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_READ_FUSE_DATA_DATA_SHIFT (0U)
/*! DATA - DATA */
#define OCOTP_CTRL_HW_OCOTP_READ_FUSE_DATA_DATA(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_READ_FUSE_DATA_DATA_SHIFT)) & OCOTP_CTRL_HW_OCOTP_READ_FUSE_DATA_DATA_MASK)
/*! @} */

/*! @name HW_OCOTP_SW_STICKY - OTP Controller Sticky Bit Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK_MASK (0x4U)
#define OCOTP_CTRL_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK_SHIFT (2U)
/*! FIELD_RETURN_LOCK - FIELD_RETURN_LOCK */
#define OCOTP_CTRL_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SW_STICKY_FIELD_RETURN_LOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_SCS - OTP Controller Software Controllable Signals Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_SCS_HAB_JDE_MASK     (0x1U)
#define OCOTP_CTRL_HW_OCOTP_SCS_HAB_JDE_SHIFT    (0U)
/*! HAB_JDE - HAB_JDE
 *  0b0..JTAG debugging is not enabled by the HAB (it may still be enabled by other mechanisms).
 *  0b1..JTAG debugging is enabled by the HAB (though this signal may be gated off).
 */
#define OCOTP_CTRL_HW_OCOTP_SCS_HAB_JDE(x)       (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SCS_HAB_JDE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SCS_HAB_JDE_MASK)

#define OCOTP_CTRL_HW_OCOTP_SCS_SPARE_MASK       (0x7FFFFFFEU)
#define OCOTP_CTRL_HW_OCOTP_SCS_SPARE_SHIFT      (1U)
/*! SPARE - SPARE */
#define OCOTP_CTRL_HW_OCOTP_SCS_SPARE(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SCS_SPARE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SCS_SPARE_MASK)

#define OCOTP_CTRL_HW_OCOTP_SCS_LOCK_MASK        (0x80000000U)
#define OCOTP_CTRL_HW_OCOTP_SCS_LOCK_SHIFT       (31U)
/*! LOCK - LOCK */
#define OCOTP_CTRL_HW_OCOTP_SCS_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SCS_LOCK_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SCS_LOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_OUT_STATUS - OTP Controller Output Status Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DOUT_40_32_MASK (0x1FFU)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DOUT_40_32_SHIFT (0U)
/*! DOUT_40_32 - DOUT_40_32 */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DOUT_40_32(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DOUT_40_32_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DOUT_40_32_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_MASK  (0x200U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_SHIFT (9U)
/*! SEC - SEC */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_MASK  (0x400U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_SHIFT (10U)
/*! DED - DED */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_LOCKED_MASK (0x800U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_LOCKED_SHIFT (11U)
/*! LOCKED - LOCKED */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_LOCKED_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_LOCKED_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PROGFAIL_MASK (0x1000U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PROGFAIL_SHIFT (12U)
/*! PROGFAIL - PROGFAIL */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PROGFAIL(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PROGFAIL_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PROGFAIL_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_ACK_MASK  (0x2000U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_ACK_SHIFT (13U)
/*! ACK - ACK */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_ACK(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_ACK_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_ACK_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PWOK_MASK (0x4000U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PWOK_SHIFT (14U)
/*! PWOK - PWOK */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PWOK(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PWOK_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_PWOK_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_FLAGSTATE_MASK (0x78000U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_FLAGSTATE_SHIFT (15U)
/*! FLAGSTATE - FLAGSTATE */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_FLAGSTATE(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_FLAGSTATE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_FLAGSTATE_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_RELOAD_MASK (0x80000U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_RELOAD_SHIFT (19U)
/*! SEC_RELOAD - SEC_RELOAD */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_RELOAD(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_RELOAD_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_SEC_RELOAD_MASK)

#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_RELOAD_MASK (0x100000U)
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_RELOAD_SHIFT (20U)
/*! DED_RELOAD - DED_RELOAD */
#define OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_RELOAD(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_RELOAD_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OUT_STATUS_DED_RELOAD_MASK)
/*! @} */

/*! @name HW_OCOTP_STARTWORD - OTP Controller Output Startword Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_STARTWORD_STARTWORD_MASK (0xFFFFU)
#define OCOTP_CTRL_HW_OCOTP_STARTWORD_STARTWORD_SHIFT (0U)
/*! STARTWORD - STARTWORD */
#define OCOTP_CTRL_HW_OCOTP_STARTWORD_STARTWORD(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_STARTWORD_STARTWORD_SHIFT)) & OCOTP_CTRL_HW_OCOTP_STARTWORD_STARTWORD_MASK)
/*! @} */

/*! @name HW_OCOTP_VERSION - OTP Controller Version Register */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_VERSION_STEP_MASK    (0xFFFFU)
#define OCOTP_CTRL_HW_OCOTP_VERSION_STEP_SHIFT   (0U)
/*! STEP - STEP */
#define OCOTP_CTRL_HW_OCOTP_VERSION_STEP(x)      (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_VERSION_STEP_SHIFT)) & OCOTP_CTRL_HW_OCOTP_VERSION_STEP_MASK)

#define OCOTP_CTRL_HW_OCOTP_VERSION_MINOR_MASK   (0xFF0000U)
#define OCOTP_CTRL_HW_OCOTP_VERSION_MINOR_SHIFT  (16U)
/*! MINOR - MINOR */
#define OCOTP_CTRL_HW_OCOTP_VERSION_MINOR(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_VERSION_MINOR_SHIFT)) & OCOTP_CTRL_HW_OCOTP_VERSION_MINOR_MASK)

#define OCOTP_CTRL_HW_OCOTP_VERSION_MAJOR_MASK   (0xFF000000U)
#define OCOTP_CTRL_HW_OCOTP_VERSION_MAJOR_SHIFT  (24U)
/*! MAJOR - MAJOR */
#define OCOTP_CTRL_HW_OCOTP_VERSION_MAJOR(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_VERSION_MAJOR_SHIFT)) & OCOTP_CTRL_HW_OCOTP_VERSION_MAJOR_MASK)
/*! @} */

/*! @name HW_OCOTP_LOCK0 - OTP Controller Lock Control Register 0 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_LOCK0_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_LOCK0_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_LOCK0_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_LOCK0_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_LOCK0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_LOCK1 - OTP Controller Lock Control Register 1 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_LOCK1_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_LOCK1_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_LOCK1_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_LOCK1_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_LOCK1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_LOCK2 - OTP Controller Lock Control Register 2 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_LOCK2_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_LOCK2_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_LOCK2_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_LOCK2_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_LOCK2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_CFG0 - Value of OTP Bank1 Word3 (ID Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_CFG0_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_CFG0_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_CFG0_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CFG0_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CFG0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_CFG1 - Value of OTP Bank1 Word4 (ID Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_CFG1_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_CFG1_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_CFG1_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CFG1_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CFG1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_CFG2 - Value of OTP Bank1 Word5 (ID Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_CFG2_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_CFG2_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_CFG2_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CFG2_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CFG2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_CFG3 - Value of OTP Bank1 Word6 (ID Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_CFG3_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_CFG3_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_CFG3_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CFG3_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CFG3_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_CFG4 - Value of OTP Bank1 Word7 (ID Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_CFG4_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_CFG4_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_CFG4_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_CFG4_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_CFG4_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT0 - Value of OTP Bank2 Word0 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_BOOT0_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_BOOT0_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_BOOT0_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_BOOT0_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_BOOT0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT3 - OTP Controller Boot Configuration Register 3 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_BOOT3_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_BOOT3_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_BOOT3_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_BOOT3_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_BOOT3_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT4 - OTP Controller Boot Configuration Register 4 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_BOOT4_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_BOOT4_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_BOOT4_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_BOOT4_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_BOOT4_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT5 - OTP Controller Boot Configuration Register 5 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_BOOT5_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_BOOT5_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_BOOT5_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_BOOT5_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_BOOT5_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT6 - OTP Controller Boot Configuration Register 6 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_BOOT6_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_BOOT6_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_BOOT6_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_BOOT6_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_BOOT6_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT7 - OTP Controller Boot Configuration Register 7 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_BOOT7_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_BOOT7_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_BOOT7_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_BOOT7_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_BOOT7_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_ANA1 - Value of OTP Bank3 Word5 (Memory Related Info.) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_ANA1_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_ANA1_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_ANA1_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_ANA1_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_ANA1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_ANA2 - OTP Controller Analog Register 2 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_ANA2_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_ANA2_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_ANA2_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_ANA2_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_ANA2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_ANA3 - OTP Controller Analog Register 3 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_ANA3_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_ANA3_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_ANA3_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_ANA3_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_ANA3_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_PAD_MISC1 - Value of OTP Bank9 Word1 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_PAD_MISC1_BITS_MASK  (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_PAD_MISC1_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_PAD_MISC1_BITS(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_PAD_MISC1_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_PAD_MISC1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_PAD_MISC3 - Value of OTP Bank9 Word3 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_PAD_MISC3_BITS_MASK  (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_PAD_MISC3_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_PAD_MISC3_BITS(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_PAD_MISC3_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_PAD_MISC3_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP60 - Value of OTP Bank24 Word0 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP60_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP60_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP60_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP60_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP60_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP61 - Value of OTP Bank24 Word1 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP61_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP61_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP61_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP61_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP61_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP62 - Value of OTP Bank24 Word2 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP62_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP62_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP62_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP62_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP62_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP63 - Value of OTP Bank24 Word3 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP63_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP63_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP63_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP63_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP63_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP64 - Value of OTP Bank24 Word4 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP64_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP64_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP64_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP64_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP64_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP65 - Value of OTP Bank24 Word5 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP65_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP65_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP65_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP65_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP65_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP66 - Value of OTP Bank24 Word6 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP66_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP66_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP66_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP66_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP66_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP67 - Value of OTP Bank24 Word7 (GP6) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP67_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP67_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP67_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP67_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP67_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP70 - Value of OTP Bank25 Word0 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP70_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP70_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP70_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP70_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP70_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP71 - Value of OTP Bank25 Word1 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP71_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP71_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP71_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP71_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP71_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP72 - Value of OTP Bank25 Word2 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP72_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP72_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP72_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP72_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP72_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP73 - Value of OTP Bank25 Word3 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP73_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP73_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP73_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP73_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP73_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP74 - Value of OTP Bank25 Word4 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP74_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP74_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP74_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP74_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP74_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP75 - Value of OTP Bank25 Word5 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP75_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP75_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP75_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP75_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP75_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP76 - Value of OTP Bank25 Word6 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP76_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP76_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP76_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP76_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP76_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP77 - Value of OTP Bank25 Word7 (GP7) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP77_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP77_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP77_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP77_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP77_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP80 - Value of OTP Bank26 Word0 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP80_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP80_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP80_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP80_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP80_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP81 - Value of OTP Bank26 Word1 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP81_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP81_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP81_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP81_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP81_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP82 - Value of OTP Bank26 Word2 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP82_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP82_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP82_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP82_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP82_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP83 - Value of OTP Bank26 Word3 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP83_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP83_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP83_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP83_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP83_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP84 - Value of OTP Bank26 Word4 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP84_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP84_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP84_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP84_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP84_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP85 - Value of OTP Bank26 Word5 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP85_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP85_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP85_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP85_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP85_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP86 - Value of OTP Bank26 Word6 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP86_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP86_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP86_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP86_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP86_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP87 - Value of OTP Bank26 Word7 (GP8) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP87_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP87_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP87_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP87_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP87_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP90 - Value of OTP Bank27 Word0 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP90_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP90_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP90_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP90_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP90_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP91 - Value of OTP Bank27 Word1 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP91_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP91_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP91_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP91_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP91_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP92 - Value of OTP Bank27 Word2 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP92_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP92_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP92_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP92_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP92_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP93 - Value of OTP Bank27 Word3 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP93_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP93_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP93_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP93_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP93_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP94 - Value of OTP Bank27 Word4 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP94_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP94_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP94_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP94_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP94_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP95 - Value of OTP Bank27 Word5 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP95_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP95_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP95_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP95_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP95_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP96 - Value of OTP Bank27 Word6 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP96_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP96_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP96_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP96_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP96_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP97 - Value of OTP Bank27 Word7 (GP9) */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP97_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP97_BITS_SHIFT      (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP97_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP97_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP97_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP107 - Value of OTP Bank28 Word7 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_GP107_BITS_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_GP107_BITS_SHIFT     (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_GP107_BITS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_GP107_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_GP107_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY0 - OTP Controller OTFAD Key Register 0 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY1 - OTP Controller OTFAD Key Register 1 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY2 - OTP Controller OTFAD Key Register 2 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY3 - OTP Controller OTFAD Key Register 3 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_CFG0 - OTP Controller OTFAD Configuration Register 0 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG0_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG0_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG0_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_CFG0_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_CFG0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_CFG1 - OTP Controller OTFAD Configuration Register 1 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG1_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG1_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG1_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_CFG1_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_CFG1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_CFG2 - OTP Controller OTFAD Configuration Register 2 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG2_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG2_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG2_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_CFG2_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_CFG2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_CFG3 - OTP Controller OTFAD Configuration Register 3 */
/*! @{ */

#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG3_BITS_MASK (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG3_BITS_SHIFT (0U)
/*! BITS - BITS */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_CFG3_BITS(x)   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_CFG3_BITS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_CFG3_BITS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCOTP_CTRL_Register_Masks */

/* Backward compatibility */
/*! @name HW_OCOTP_OTFAD_KEY_BLOB_EN - OTP Controller OTFAD Key Blob Enable */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_BLOB_EN_MASK      (0x20U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_BLOB_EN_SHIFT     (5U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_BLOB_EN(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_BLOB_EN_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_BLOB_EN_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY_SCRAMBLE_EN - OTP Controller OTFAD Key Scramble Enable */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_SCRAMBLE_EN_MASK      (0x80U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_SCRAMBLE_EN_SHIFT     (7U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_SCRAMBLE_EN(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_SCRAMBLE_EN_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY_SCRAMBLE_EN_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY0_SCRAMBLE - OTP Controller OTFAD Key Scramble 0 Align */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_SCRAMBLE_MASK      (0x300U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_SCRAMBLE_SHIFT     (8U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_SCRAMBLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_SCRAMBLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY0_SCRAMBLE_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY1_SCRAMBLE - OTP Controller OTFAD Key Scramble 1 Align */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_SCRAMBLE_MASK      (0xC00U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_SCRAMBLE_SHIFT     (10U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_SCRAMBLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_SCRAMBLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY1_SCRAMBLE_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY2_SCRAMBLE - OTP Controller OTFAD Key Scramble 2 Align */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_SCRAMBLE_MASK      (0x3000U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_SCRAMBLE_SHIFT     (12U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_SCRAMBLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_SCRAMBLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY2_SCRAMBLE_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_KEY3_SCRAMBLE - OTP Controller OTFAD Key Scramble 3 Align */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_SCRAMBLE_MASK      (0xC000U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_SCRAMBLE_SHIFT     (14U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_SCRAMBLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_SCRAMBLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_KEY3_SCRAMBLE_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_RESTRICT_OTFAD_IPS - OTP Controller OTFAD Restrict OTFAD IPS */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_RESTRICT_OTFAD_IPS_MASK      (0x10000U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_RESTRICT_OTFAD_IPS_SHIFT     (16U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_RESTRICT_OTFAD_IPS(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_RESTRICT_OTFAD_IPS_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_RESTRICT_OTFAD_IPS_MASK)
/*! @} */

/*! @name HW_OCOTP_FORCE_INTERNAL_BT - OTP Controller Force Internal Boot */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_FORCE_INTERNAL_BT_MASK      (0x1U)
#define OCOTP_CTRL_HW_OCOTP_FORCE_INTERNAL_BT_SHIFT     (0U)
#define OCOTP_CTRL_HW_OCOTP_FORCE_INTERNAL_BT(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_FORCE_INTERNAL_BT_SHIFT)) & OCOTP_CTRL_HW_OCOTP_FORCE_INTERNAL_BT_MASK)
/*! @} */

/*! @name HW_OCOTP_SDP_DISABLE - OTP Controller SDP Disable */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_SDP_DISABLE_MASK      (0x2U)
#define OCOTP_CTRL_HW_OCOTP_SDP_DISABLE_SHIFT     (1U)
#define OCOTP_CTRL_HW_OCOTP_SDP_DISABLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SDP_DISABLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SDP_DISABLE_MASK)
/*! @} */

/*! @name HW_OCOTP_SDP_READ_DISABLE - OTP Controller SDP Read Disable */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_SDP_READ_DISABLE_MASK      (0x4U)
#define OCOTP_CTRL_HW_OCOTP_SDP_READ_DISABLE_SHIFT     (2U)
#define OCOTP_CTRL_HW_OCOTP_SDP_READ_DISABLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SDP_READ_DISABLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SDP_READ_DISABLE_MASK)
/*! @} */

/*! @name HW_OCOTP_SEC_CONFIG1 - OTP Controller SEC CONFIG[1] */
/*! @{ */
#define SEC_CONFIG_OPEN                           0U
#define SEC_CONFIG_CLOSED                         1U
#define OCOTP_CTRL_HW_OCOTP_SEC_CONFIG1_MASK      (0x80000000U)
#define OCOTP_CTRL_HW_OCOTP_SEC_CONFIG1_SHIFT     (31U)
#define OCOTP_CTRL_HW_OCOTP_SEC_CONFIG1(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_SEC_CONFIG1_SHIFT)) & OCOTP_CTRL_HW_OCOTP_SEC_CONFIG1_MASK)
/*! @} */

/*! @name HW_OCOTP_OTFAD_OTFAD_KEY_SCRAMBLE - OTP Controller OTFAD OTFAD Key Scramble */
/*! @{ */
#define OCOTP_CTRL_HW_OCOTP_OTFAD_OTFAD_KEY_SCRAMBLE_MASK      (0xFFFFFFFFU)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_OTFAD_KEY_SCRAMBLE_SHIFT     (0U)
#define OCOTP_CTRL_HW_OCOTP_OTFAD_OTFAD_KEY_SCRAMBLE(x)        (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_HW_OCOTP_OTFAD_OTFAD_KEY_SCRAMBLE_SHIFT)) & OCOTP_CTRL_HW_OCOTP_OTFAD_OTFAD_KEY_SCRAMBLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCOTP_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_OCOTP_CTRL_H_ */

