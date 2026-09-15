/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NPU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_NPU.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for NPU
 *
 * CMSIS Peripheral Access Layer for NPU
 */

#if !defined(PERI_NPU_H_)
#define PERI_NPU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- NPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_Peripheral_Access_Layer NPU Peripheral Access Layer
 * @{
 */

/** NPU - Size of Registers Arrays */
#define NPU_MBOX_COUNT                            8u
#define NPU_V2P_DATA_COUNT                        16u
#define NPU_V2P_WEIGHTS_COUNT                     16u
#define NPU_V2P_RESULTS_COUNT                     16u

/** NPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t RESETCTRL;                         /**< Reset and Control, offset: 0x0 */
  __IO uint32_t STATUSERR;                         /**< Zen-V Status and Error, offset: 0x4 */
  __IO uint32_t INTENA;                            /**< Interrupt Enable For SoC, offset: 0x8 */
  __IO uint32_t INTCLR;                            /**< Interrupt Clear For SoC, offset: 0xC */
  __IO uint32_t CYCLOW;                            /**< Cycle Counter, offset: 0x10 */
  __IO uint32_t CYCHIGH;                           /**< Cycle Counter, offset: 0x14 */
  __IO uint32_t DDRLATENT;                         /**< DDR Latency Performance Counter, offset: 0x18 */
  __IO uint32_t DDRSPREAD;                         /**< DDR Data Read Spread Performance Counter, offset: 0x1C */
  __IO uint32_t DDRRCNTS;                          /**< DDR Read Performance Counter, offset: 0x20 */
  __IO uint32_t DDRWWORDS;                         /**< DDR Write Performance Counter, offset: 0x24 */
  __IO uint32_t DDRRWORDS;                         /**< DDR Read Word Performance Counter, offset: 0x28 */
  __IO uint32_t DDRSTALL;                          /**< DDR Stall Performance Counter, offset: 0x2C */
  __IO uint32_t NSTALL;                            /**< Neutron Stall Performance Counter, offset: 0x30 */
  __IO uint32_t NACT;                              /**< Neutron active performance counter, offset: 0x34 */
       uint8_t RESERVED_0[24];
  __IO uint32_t EVTRCCFG;                          /**< Optional Event Trace configure/control, offset: 0x50 */
  __IO uint32_t EVTRCDATA;                         /**< Optional Event Trace Software submission, offset: 0x54 */
       uint8_t RESERVED_1[8];
  __IO uint32_t ZVIV2P0;                           /**< Zen-V Code Virtual to Physical, offset: 0x60 */
  __IO uint32_t ZVIV2P1;                           /**< Zen-V Code Virtual to Physical, offset: 0x64 */
  __IO uint32_t ZVIV2P2;                           /**< Zen-V Code Virtual to Physical, offset: 0x68 */
  __IO uint32_t ZVIV2P3;                           /**< Zen-V Code Virtual to Physical, offset: 0x6C */
       uint8_t RESERVED_2[16];
  __IO uint32_t TTCTRL;                            /**< TCM-to-TCM Control, offset: 0x80 */
  __IO uint32_t TTSADDR;                           /**< TCM-to-TCM Source Address, offset: 0x84 */
  __IO uint32_t TTDADDR;                           /**< TCM-to-TCM Destination Address, offset: 0x88 */
  __IO uint32_t TTCTRL2;                           /**< TCM-to-TCM Control 2, offset: 0x8C */
  __IO uint32_t CONFIG;                            /**< Configuration, offset: 0x90 */
  __I  uint32_t STATUS;                            /**< Data mover status, offset: 0x94 */
  __IO uint32_t DFORDER;                           /**< Data Fetch Order Manager, offset: 0x98 */
  __IO uint32_t DPORDER;                           /**< Data Push Order Manager, offset: 0x9C */
  __IO uint32_t DCTRL0_FETCH;                      /**< Fetch Control, offset: 0xA0 */
  __IO uint32_t DCTRL1_FETCH;                      /**< Fetch Control, offset: 0xA4 */
  __IO uint32_t DCTRL2_PUSH;                       /**< Push Control, offset: 0xA8 */
  __IO uint32_t DCTRL3_PUSH;                       /**< Push Control, offset: 0xAC */
  __IO uint32_t DSADDR0;                           /**< Fetch Source Address, offset: 0xB0 */
  __IO uint32_t DSADDR1;                           /**< Fetch Source Address, offset: 0xB4 */
  __IO uint32_t DSADDR2;                           /**< Push Source Address, offset: 0xB8 */
  __IO uint32_t DSADDR3;                           /**< Push Source Address, offset: 0xBC */
  __IO uint32_t DDADDR0;                           /**< Fetch Destination Address, offset: 0xC0 */
  __IO uint32_t DDADDR1;                           /**< Fetch Destination Address, offset: 0xC4 */
  __IO uint32_t DDADDR2;                           /**< Push Destination Address, offset: 0xC8 */
  __IO uint32_t DDADDR3;                           /**< Push Destination Address, offset: 0xCC */
  __IO uint32_t DCTRL2_0;                          /**< Fetch Second Control, offset: 0xD0 */
  __IO uint32_t DCTRL2_1;                          /**< Fetch Second Control, offset: 0xD4 */
  __IO uint32_t DCTRL2_2;                          /**< Push pack Second Control, offset: 0xD8 */
  __IO uint32_t DCTRL2_3;                          /**< Push pack Second Control, offset: 0xDC */
  __IO uint32_t WCTRL;                             /**< Weight Fetch Control, offset: 0xE0 */
  __IO uint32_t WSADDR;                            /**< Weight Fetch Source Address, offset: 0xE4 */
  __IO uint32_t WDADDR;                            /**< Weight Fetch Destination Address, offset: 0xE8 */
       uint8_t RESERVED_3[4];
  __IO uint32_t DCTRL3_0;                          /**< Fetch Unpack Third Control, offset: 0xF0 */
  __IO uint32_t DCTRL3_1;                          /**< Fetch Unpack Third Control, offset: 0xF4 */
  __IO uint32_t DCTRL3_2;                          /**< Push pack Third Control, offset: 0xF8 */
  __IO uint32_t DCTRL3_3;                          /**< Push pack Third Control, offset: 0xFC */
  __IO uint32_t WCTRL2_0;                          /**< Weight Fetch Second Control, offset: 0x100 */
  __IO uint32_t WCTRL3_0;                          /**< Weight Fetch Unpack Third Control, offset: 0x104 */
  __IO uint32_t WPEND1;                            /**< Fetch Pend/Ready set 1, offset: 0x108 */
       uint8_t RESERVED_4[244];
  union {                                          /* offset: 0x200 */
    __IO uint32_t APPCTRL_SOC;                       /**< Application Control, offset: 0x200 */
    __IO uint32_t APPCTRL_ZV;                        /**< Application Control, offset: 0x200 */
  };
  __IO uint32_t APPSTATUS;                         /**< Application Status, offset: 0x204 */
  __IO uint32_t BASEDDRL;                          /**< Base physical address in DDR, offset: 0x208 */
  __IO uint32_t BASEDDRH;                          /**< Base physical address in DDR, offset: 0x20C */
  __IO uint32_t INPUT;                             /**< Offset of Input image from DDR Base, offset: 0x210 */
  __IO uint32_t INPUT2;                            /**< Offset of Input image from DDR Base, offset: 0x214 */
  __IO uint32_t OUTPUT;                            /**< Offset of Output results from DDR Base, offset: 0x218 */
  __IO uint32_t OUTPUT2;                           /**< Offset of Output results from DDR Base, offset: 0x21C */
  __IO uint32_t CODEOFF;                           /**< Offset of Zen-V code from BASEDDRn, offset: 0x220 */
  __IO uint32_t DATAOFF;                           /**< Offset of Zen-V data from BASEDDRn, offset: 0x224 */
       uint8_t RESERVED_5[8];
  __IO uint32_t RINGCTRL;                          /**< Ring buffer control by Zen-V, offset: 0x230 */
       uint8_t RESERVED_6[4];
  __IO uint32_t TAIL;                              /**< Tail of ring buffer written by Zen-V, offset: 0x238 */
  __IO uint32_t HEAD;                              /**< Head of ring buffer written by SoC, offset: 0x23C */
  __IO uint32_t MBOX[NPU_MBOX_COUNT];              /**< Mailboxes For SoC/Zen-V Communications, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_7[32];
  __IO uint32_t BASEINOUTL;                        /**< Base physical address for Input/Output fetch/push, offset: 0x280 */
  __IO uint32_t BASEINOUTH;                        /**< Base physical address for Spill fetch/push, offset: 0x284 */
  __IO uint32_t BASESPILLL;                        /**< Base physical address for Spill fetch/push, offset: 0x288 */
  __IO uint32_t BASESPILLH;                        /**< Base physical address for Spill fetch/push, offset: 0x28C */
       uint8_t RESERVED_8[112];
  __IO uint32_t DECOMPCTRL;                        /**< Control For Weight Decompressor, offset: 0x300 */
  __IO uint32_t DECOMPSTAT;                        /**< Weight Decompressor Status, offset: 0x304 */
  __IO uint32_t GROUP_BASE;                        /**< DDR offset from base for Weight Decompressor, offset: 0x308 */
       uint8_t RESERVED_9[4];
  __IO uint32_t GROUP_LEN;                         /**< Weight Decompressor Group Length, offset: 0x310 */
       uint8_t RESERVED_10[44];
#pragma push_macro("CRYPTO")
#undef CRYPTO
  __IO uint32_t CRYPTO;                            /**< Cryptographic Protection Control, offset: 0x340 */
#pragma pop_macro("CRYPTO")
  __IO uint32_t PRIVDDRL;                          /**< Physical address in DDR of model when secure, offset: 0x344 */
  __IO uint32_t PRIVDDRH;                          /**< Physical address in DDR of model when secure, offset: 0x348 */
  __IO uint32_t SESSIONIV;                         /**< Unique IV for Protected models, offset: 0x34C */
  __IO uint32_t INFCOUNT;                          /**< Inference count, offset: 0x350 */
  __IO uint32_t FLAYERNUM;                         /**< Layer number for Fetch, offset: 0x354 */
  __IO uint32_t PLAYERNUM;                         /**< Layer number for Push, offset: 0x358 */
       uint8_t RESERVED_11[4];
  __IO uint32_t AXIOPT;                            /**< Boot SoC setting for AXI optimization, offset: 0x360 */
       uint8_t RESERVED_12[156];
  __IO uint32_t V2P_DATA[NPU_V2P_DATA_COUNT];      /**< Virtual to Physical registers, array offset: 0x400, array step: 0x4 */
  __IO uint32_t V2P_WEIGHTS[NPU_V2P_WEIGHTS_COUNT]; /**< Virtual to Physical registers, array offset: 0x440, array step: 0x4 */
  __IO uint32_t V2P_RESULTS[NPU_V2P_RESULTS_COUNT]; /**< Virtual to Physical registers, array offset: 0x480, array step: 0x4 */
       uint8_t RESERVED_13[48];
  __IO uint32_t LISTEN;                            /**< Listener Mode Enable, offset: 0x4F0 */
} NPU_Type;

/* ----------------------------------------------------------------------------
   -- NPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_Register_Masks NPU Register Masks
 * @{
 */

/*! @name RESETCTRL - Reset and Control */
/*! @{ */

#define NPU_RESETCTRL_ZVRUN_MASK                 (0x1U)
#define NPU_RESETCTRL_ZVRUN_SHIFT                (0U)
/*! ZVRUN - ZVRUN
 *  0b0..If Zen-V is held in reset
 *  0b1..If running
 */
#define NPU_RESETCTRL_ZVRUN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_ZVRUN_SHIFT)) & NPU_RESETCTRL_ZVRUN_MASK)

#define NPU_RESETCTRL_OCMCNT_MASK                (0xEU)
#define NPU_RESETCTRL_OCMCNT_SHIFT               (1U)
/*! OCMCNT - OCMCNT */
#define NPU_RESETCTRL_OCMCNT(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_OCMCNT_SHIFT)) & NPU_RESETCTRL_OCMCNT_MASK)

#define NPU_RESETCTRL_NRUN_MASK                  (0xF0U)
#define NPU_RESETCTRL_NRUN_SHIFT                 (4U)
/*! NRUN - NRUN */
#define NPU_RESETCTRL_NRUN(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_NRUN_SHIFT)) & NPU_RESETCTRL_NRUN_MASK)

#define NPU_RESETCTRL_MEMENA_MASK                (0xF00U)
#define NPU_RESETCTRL_MEMENA_SHIFT               (8U)
/*! MEMENA - MEMENA */
#define NPU_RESETCTRL_MEMENA(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_MEMENA_SHIFT)) & NPU_RESETCTRL_MEMENA_MASK)

#define NPU_RESETCTRL_ZMEMFREE_MASK              (0x1000U)
#define NPU_RESETCTRL_ZMEMFREE_SHIFT             (12U)
/*! ZMEMFREE - ZMEMFREE
 *  0b0..If 0, the ITCM and DTCM will be unavailable when Zen-V is (when Zen-V in reset or halted).
 *  0b1..If 1, the ITCM and DTCM will be available regardless of Zen-V core state. This should be used when the
 *       memories are to be updated while Zen-V is off.
 */
#define NPU_RESETCTRL_ZMEMFREE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_ZMEMFREE_SHIFT)) & NPU_RESETCTRL_ZMEMFREE_MASK)

#define NPU_RESETCTRL_DMRESET_MASK               (0x8000U)
#define NPU_RESETCTRL_DMRESET_SHIFT              (15U)
/*! DMRESET - DataMover Reset Control
 *  0b0..DataMover out-of-reset
 *  0b1..DataMover kept in reset
 */
#define NPU_RESETCTRL_DMRESET(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_DMRESET_SHIFT)) & NPU_RESETCTRL_DMRESET_MASK)

#define NPU_RESETCTRL_NGANGDIS_MASK              (0xF0000U)
#define NPU_RESETCTRL_NGANGDIS_SHIFT             (16U)
/*! NGANGDIS - NGANGDIS */
#define NPU_RESETCTRL_NGANGDIS(x)                (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_NGANGDIS_SHIFT)) & NPU_RESETCTRL_NGANGDIS_MASK)

#define NPU_RESETCTRL_ITCM_INIT_MASK             (0x1000000U)
#define NPU_RESETCTRL_ITCM_INIT_SHIFT            (24U)
/*! ITCM_INIT - Initialization of ITCM memory. Initialization can only be run once.
 *  0b0..Write: No action. Read: ITCM memory is not initialized.
 *  0b1..Write: Initialize ITCM. Read: ITCM memory is initialized.
 */
#define NPU_RESETCTRL_ITCM_INIT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_ITCM_INIT_SHIFT)) & NPU_RESETCTRL_ITCM_INIT_MASK)

#define NPU_RESETCTRL_DTCM_INIT_MASK             (0x2000000U)
#define NPU_RESETCTRL_DTCM_INIT_SHIFT            (25U)
/*! DTCM_INIT - Initialization of DTCM memory. Initialization can only be run once.
 *  0b0..Write: No action. Read: DTCM memory is not initialized.
 *  0b1..Write: Initialize DTCM. Read: DTCM memory is initialized.
 */
#define NPU_RESETCTRL_DTCM_INIT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_DTCM_INIT_SHIFT)) & NPU_RESETCTRL_DTCM_INIT_MASK)

#define NPU_RESETCTRL_NTCM_INIT_MASK             (0x4000000U)
#define NPU_RESETCTRL_NTCM_INIT_SHIFT            (26U)
/*! NTCM_INIT - Initialization of NTCM memory. Initialization can only be run once.
 *  0b0..Write: No action. Read: NTCM memory is not initialized.
 *  0b1..Write: Initialize NTCM. Read: NTCM memory is initialized.
 */
#define NPU_RESETCTRL_NTCM_INIT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_NTCM_INIT_SHIFT)) & NPU_RESETCTRL_NTCM_INIT_MASK)

#define NPU_RESETCTRL_VTCM_INIT_MASK             (0x8000000U)
#define NPU_RESETCTRL_VTCM_INIT_SHIFT            (27U)
/*! VTCM_INIT - Initialization of VTCM memory. Initialization can only be run once.
 *  0b0..Write: No action. Read: VTCM memory is not initialized.
 *  0b1..Write: Initialize VTCM. Read: VTCM memory is initialized.
 */
#define NPU_RESETCTRL_VTCM_INIT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_VTCM_INIT_SHIFT)) & NPU_RESETCTRL_VTCM_INIT_MASK)

#define NPU_RESETCTRL_OCMEN_MASK                 (0x40000000U)
#define NPU_RESETCTRL_OCMEN_SHIFT                (30U)
/*! OCMEN - OCM enable
 *  0b0..OCMCNT bit field determines the number of zones used as OCMs. AXI_S access to other zones are blocked and error terminated.
 *  0b1..OCMCNT bit field determines the number of zones used as OCMs. Other zones are accessible via AXI_S. None
 *       OCM zone accesses using result V2P configuration for read and data V2P configuration for write.
 */
#define NPU_RESETCTRL_OCMEN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_OCMEN_SHIFT)) & NPU_RESETCTRL_OCMEN_MASK)

#define NPU_RESETCTRL_ZVCLKEN_MASK               (0x80000000U)
#define NPU_RESETCTRL_ZVCLKEN_SHIFT              (31U)
/*! ZVCLKEN - Zen-V's clock enable
 *  0b0..If 0, then ZVRUN bit field determines the gating state of Zen-V's clock.
 *  0b1..If 1, the Zen-V clock is ungated.
 */
#define NPU_RESETCTRL_ZVCLKEN(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_RESETCTRL_ZVCLKEN_SHIFT)) & NPU_RESETCTRL_ZVCLKEN_MASK)
/*! @} */

/*! @name STATUSERR - Zen-V Status and Error */
/*! @{ */

#define NPU_STATUSERR_ZVHALT_MASK                (0x1U)
#define NPU_STATUSERR_ZVHALT_SHIFT               (0U)
/*! ZVHALT - Zen-V core HALT */
#define NPU_STATUSERR_ZVHALT(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_ZVHALT_SHIFT)) & NPU_STATUSERR_ZVHALT_MASK)

#define NPU_STATUSERR_ZVFAULT_MASK               (0x2U)
#define NPU_STATUSERR_ZVFAULT_SHIFT              (1U)
/*! ZVFAULT - Zen-V core fault */
#define NPU_STATUSERR_ZVFAULT(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_ZVFAULT_SHIFT)) & NPU_STATUSERR_ZVFAULT_MASK)

#define NPU_STATUSERR_NRAERR_MASK                (0x10U)
#define NPU_STATUSERR_NRAERR_SHIFT               (4U)
/*! NRAERR - NRAERR */
#define NPU_STATUSERR_NRAERR(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_NRAERR_SHIFT)) & NPU_STATUSERR_NRAERR_MASK)

#define NPU_STATUSERR_NWAERR_MASK                (0x20U)
#define NPU_STATUSERR_NWAERR_SHIFT               (5U)
/*! NWAERR - NWAERR */
#define NPU_STATUSERR_NWAERR(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_NWAERR_SHIFT)) & NPU_STATUSERR_NWAERR_MASK)

#define NPU_STATUSERR_NDAERR_MASK                (0x40U)
#define NPU_STATUSERR_NDAERR_SHIFT               (6U)
/*! NDAERR - NDAERR */
#define NPU_STATUSERR_NDAERR(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_NDAERR_SHIFT)) & NPU_STATUSERR_NDAERR_MASK)

#define NPU_STATUSERR_REQCONT_MASK               (0x100U)
#define NPU_STATUSERR_REQCONT_SHIFT              (8U)
/*! REQCONT - REQCONT */
#define NPU_STATUSERR_REQCONT(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_REQCONT_SHIFT)) & NPU_STATUSERR_REQCONT_MASK)

#define NPU_STATUSERR_REQCONTID_MASK             (0x1FE00U)
#define NPU_STATUSERR_REQCONTID_SHIFT            (9U)
/*! REQCONTID - REQCONTID */
#define NPU_STATUSERR_REQCONTID(x)               (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_REQCONTID_SHIFT)) & NPU_STATUSERR_REQCONTID_MASK)

#define NPU_STATUSERR_OCMECCCORR_MASK            (0xFF00000U)
#define NPU_STATUSERR_OCMECCCORR_SHIFT           (20U)
/*! OCMECCCORR - OCMECCCORR */
#define NPU_STATUSERR_OCMECCCORR(x)              (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_OCMECCCORR_SHIFT)) & NPU_STATUSERR_OCMECCCORR_MASK)

#define NPU_STATUSERR_OCMECCFATAL_MASK           (0x10000000U)
#define NPU_STATUSERR_OCMECCFATAL_SHIFT          (28U)
/*! OCMECCFATAL - OCMECCFATAL */
#define NPU_STATUSERR_OCMECCFATAL(x)             (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_OCMECCFATAL_SHIFT)) & NPU_STATUSERR_OCMECCFATAL_MASK)

#define NPU_STATUSERR_INFDONE_CLR_MASK           (0x40000000U)
#define NPU_STATUSERR_INFDONE_CLR_SHIFT          (30U)
/*! INFDONE_CLR - Interrupt on clear Inference Done */
#define NPU_STATUSERR_INFDONE_CLR(x)             (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_INFDONE_CLR_SHIFT)) & NPU_STATUSERR_INFDONE_CLR_MASK)

#define NPU_STATUSERR_MBOXINT_MASK               (0x80000000U)
#define NPU_STATUSERR_MBOXINT_SHIFT              (31U)
/*! MBOXINT - Message Box Interrupt */
#define NPU_STATUSERR_MBOXINT(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_STATUSERR_MBOXINT_SHIFT)) & NPU_STATUSERR_MBOXINT_MASK)
/*! @} */

/*! @name INTENA - Interrupt Enable For SoC */
/*! @{ */

#define NPU_INTENA_ZVHALT_MASK                   (0x1U)
#define NPU_INTENA_ZVHALT_SHIFT                  (0U)
/*! ZVHALT - Zen-V Halt */
#define NPU_INTENA_ZVHALT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_ZVHALT_SHIFT)) & NPU_INTENA_ZVHALT_MASK)

#define NPU_INTENA_INFDONE_MASK                  (0x2U)
#define NPU_INTENA_INFDONE_SHIFT                 (1U)
/*! INFDONE - Inference Done */
#define NPU_INTENA_INFDONE(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_INFDONE_SHIFT)) & NPU_INTENA_INFDONE_MASK)

#define NPU_INTENA_MBOX_MASK                     (0x4U)
#define NPU_INTENA_MBOX_SHIFT                    (2U)
/*! MBOX - Mailbox */
#define NPU_INTENA_MBOX(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_MBOX_SHIFT)) & NPU_INTENA_MBOX_MASK)

#define NPU_INTENA_SHUTDOWN_MASK                 (0x80U)
#define NPU_INTENA_SHUTDOWN_SHIFT                (7U)
/*! SHUTDOWN - Shutdown */
#define NPU_INTENA_SHUTDOWN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_SHUTDOWN_SHIFT)) & NPU_INTENA_SHUTDOWN_MASK)

#define NPU_INTENA_AERR_MASK                     (0x10000U)
#define NPU_INTENA_AERR_SHIFT                    (16U)
/*! AERR - AERR */
#define NPU_INTENA_AERR(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_AERR_SHIFT)) & NPU_INTENA_AERR_MASK)

#define NPU_INTENA_REQCONT_MASK                  (0x20000U)
#define NPU_INTENA_REQCONT_SHIFT                 (17U)
/*! REQCONT - REQCONT */
#define NPU_INTENA_REQCONT(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_REQCONT_SHIFT)) & NPU_INTENA_REQCONT_MASK)

#define NPU_INTENA_OCMECCSAT_MASK                (0x40000U)
#define NPU_INTENA_OCMECCSAT_SHIFT               (18U)
/*! OCMECCSAT - OCMECCSAT */
#define NPU_INTENA_OCMECCSAT(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_OCMECCSAT_SHIFT)) & NPU_INTENA_OCMECCSAT_MASK)

#define NPU_INTENA_OCMECCFATAL_MASK              (0x80000U)
#define NPU_INTENA_OCMECCFATAL_SHIFT             (19U)
/*! OCMECCFATAL - OCMECCFATAL */
#define NPU_INTENA_OCMECCFATAL(x)                (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_OCMECCFATAL_SHIFT)) & NPU_INTENA_OCMECCFATAL_MASK)

#define NPU_INTENA_ZVFAULT_MASK                  (0x100000U)
#define NPU_INTENA_ZVFAULT_SHIFT                 (20U)
/*! ZVFAULT - ZVFAULT */
#define NPU_INTENA_ZVFAULT(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INTENA_ZVFAULT_SHIFT)) & NPU_INTENA_ZVFAULT_MASK)
/*! @} */

/*! @name INTCLR - Interrupt Clear For SoC */
/*! @{ */

#define NPU_INTCLR_ZVHALT_MASK                   (0x1U)
#define NPU_INTCLR_ZVHALT_SHIFT                  (0U)
/*! ZVHALT - ZVHALT */
#define NPU_INTCLR_ZVHALT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_ZVHALT_SHIFT)) & NPU_INTCLR_ZVHALT_MASK)

#define NPU_INTCLR_INFDONE_MASK                  (0x2U)
#define NPU_INTCLR_INFDONE_SHIFT                 (1U)
/*! INFDONE - Inference Done */
#define NPU_INTCLR_INFDONE(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_INFDONE_SHIFT)) & NPU_INTCLR_INFDONE_MASK)

#define NPU_INTCLR_MBOX_MASK                     (0x4U)
#define NPU_INTCLR_MBOX_SHIFT                    (2U)
/*! MBOX - Mailbox */
#define NPU_INTCLR_MBOX(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_MBOX_SHIFT)) & NPU_INTCLR_MBOX_MASK)

#define NPU_INTCLR_SHUTDOWN_MASK                 (0x80U)
#define NPU_INTCLR_SHUTDOWN_SHIFT                (7U)
/*! SHUTDOWN - SHUTDOWN */
#define NPU_INTCLR_SHUTDOWN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_SHUTDOWN_SHIFT)) & NPU_INTCLR_SHUTDOWN_MASK)

#define NPU_INTCLR_AERR_MASK                     (0x10000U)
#define NPU_INTCLR_AERR_SHIFT                    (16U)
/*! AERR - AERR */
#define NPU_INTCLR_AERR(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_AERR_SHIFT)) & NPU_INTCLR_AERR_MASK)

#define NPU_INTCLR_REQCONT_MASK                  (0x20000U)
#define NPU_INTCLR_REQCONT_SHIFT                 (17U)
/*! REQCONT - REQCONT */
#define NPU_INTCLR_REQCONT(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_REQCONT_SHIFT)) & NPU_INTCLR_REQCONT_MASK)

#define NPU_INTCLR_OCMECCSAT_MASK                (0x40000U)
#define NPU_INTCLR_OCMECCSAT_SHIFT               (18U)
/*! OCMECCSAT - OCMECCSAT */
#define NPU_INTCLR_OCMECCSAT(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_OCMECCSAT_SHIFT)) & NPU_INTCLR_OCMECCSAT_MASK)

#define NPU_INTCLR_OCMECCFATAL_MASK              (0x80000U)
#define NPU_INTCLR_OCMECCFATAL_SHIFT             (19U)
/*! OCMECCFATAL - OCMECCFATAL */
#define NPU_INTCLR_OCMECCFATAL(x)                (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_OCMECCFATAL_SHIFT)) & NPU_INTCLR_OCMECCFATAL_MASK)

#define NPU_INTCLR_ZVFAULT_MASK                  (0x100000U)
#define NPU_INTCLR_ZVFAULT_SHIFT                 (20U)
/*! ZVFAULT - ZVFAULT */
#define NPU_INTCLR_ZVFAULT(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INTCLR_ZVFAULT_SHIFT)) & NPU_INTCLR_ZVFAULT_MASK)
/*! @} */

/*! @name CYCLOW - Cycle Counter */
/*! @{ */

#define NPU_CYCLOW_CNT_LOW_MASK                  (0xFFFFFFFFU)
#define NPU_CYCLOW_CNT_LOW_SHIFT                 (0U)
/*! CNT_LOW - CNT_LOW */
#define NPU_CYCLOW_CNT_LOW(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CYCLOW_CNT_LOW_SHIFT)) & NPU_CYCLOW_CNT_LOW_MASK)
/*! @} */

/*! @name CYCHIGH - Cycle Counter */
/*! @{ */

#define NPU_CYCHIGH_CNT_HIGH_MASK                (0xFFFFFFFFU)
#define NPU_CYCHIGH_CNT_HIGH_SHIFT               (0U)
/*! CNT_HIGH - CNT_HIGH */
#define NPU_CYCHIGH_CNT_HIGH(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_CYCHIGH_CNT_HIGH_SHIFT)) & NPU_CYCHIGH_CNT_HIGH_MASK)
/*! @} */

/*! @name DDRLATENT - DDR Latency Performance Counter */
/*! @{ */

#define NPU_DDRLATENT_CNT_MASK                   (0xFFFFFFFFU)
#define NPU_DDRLATENT_CNT_SHIFT                  (0U)
/*! CNT - CNT */
#define NPU_DDRLATENT_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DDRLATENT_CNT_SHIFT)) & NPU_DDRLATENT_CNT_MASK)
/*! @} */

/*! @name DDRSPREAD - DDR Data Read Spread Performance Counter */
/*! @{ */

#define NPU_DDRSPREAD_CNT_MASK                   (0xFFFFFFFFU)
#define NPU_DDRSPREAD_CNT_SHIFT                  (0U)
/*! CNT - CNT */
#define NPU_DDRSPREAD_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DDRSPREAD_CNT_SHIFT)) & NPU_DDRSPREAD_CNT_MASK)
/*! @} */

/*! @name DDRRCNTS - DDR Read Performance Counter */
/*! @{ */

#define NPU_DDRRCNTS_CNT_DDRR_MASK               (0xFFFFFFFFU)
#define NPU_DDRRCNTS_CNT_DDRR_SHIFT              (0U)
/*! CNT_DDRR - CNT_DDRR */
#define NPU_DDRRCNTS_CNT_DDRR(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_DDRRCNTS_CNT_DDRR_SHIFT)) & NPU_DDRRCNTS_CNT_DDRR_MASK)
/*! @} */

/*! @name DDRWWORDS - DDR Write Performance Counter */
/*! @{ */

#define NPU_DDRWWORDS_CNT_MASK                   (0xFFFFFFFFU)
#define NPU_DDRWWORDS_CNT_SHIFT                  (0U)
/*! CNT - Count */
#define NPU_DDRWWORDS_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DDRWWORDS_CNT_SHIFT)) & NPU_DDRWWORDS_CNT_MASK)
/*! @} */

/*! @name DDRRWORDS - DDR Read Word Performance Counter */
/*! @{ */

#define NPU_DDRRWORDS_CNT_MASK                   (0xFFFFFFFFU)
#define NPU_DDRRWORDS_CNT_SHIFT                  (0U)
/*! CNT - CNT */
#define NPU_DDRRWORDS_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DDRRWORDS_CNT_SHIFT)) & NPU_DDRRWORDS_CNT_MASK)
/*! @} */

/*! @name DDRSTALL - DDR Stall Performance Counter */
/*! @{ */

#define NPU_DDRSTALL_REQSTALLS_MASK              (0xFFFFU)
#define NPU_DDRSTALL_REQSTALLS_SHIFT             (0U)
/*! REQSTALLS - REQSTALLS */
#define NPU_DDRSTALL_REQSTALLS(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DDRSTALL_REQSTALLS_SHIFT)) & NPU_DDRSTALL_REQSTALLS_MASK)

#define NPU_DDRSTALL_WSTALLS_MASK                (0xFFFF0000U)
#define NPU_DDRSTALL_WSTALLS_SHIFT               (16U)
/*! WSTALLS - WSTALLS */
#define NPU_DDRSTALL_WSTALLS(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_DDRSTALL_WSTALLS_SHIFT)) & NPU_DDRSTALL_WSTALLS_MASK)
/*! @} */

/*! @name NSTALL - Neutron Stall Performance Counter */
/*! @{ */

#define NPU_NSTALL_DSTALLS_MASK                  (0xFFFFU)
#define NPU_NSTALL_DSTALLS_SHIFT                 (0U)
/*! DSTALLS - DSTALLS */
#define NPU_NSTALL_DSTALLS(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_NSTALL_DSTALLS_SHIFT)) & NPU_NSTALL_DSTALLS_MASK)

#define NPU_NSTALL_WSTALLS_MASK                  (0xFFFF0000U)
#define NPU_NSTALL_WSTALLS_SHIFT                 (16U)
/*! WSTALLS - WSTALLS */
#define NPU_NSTALL_WSTALLS(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_NSTALL_WSTALLS_SHIFT)) & NPU_NSTALL_WSTALLS_MASK)
/*! @} */

/*! @name NACT - Neutron active performance counter */
/*! @{ */

#define NPU_NACT_CNT_MASK                        (0xFFFFFFFFU)
#define NPU_NACT_CNT_SHIFT                       (0U)
/*! CNT - CNT */
#define NPU_NACT_CNT(x)                          (((uint32_t)(((uint32_t)(x)) << NPU_NACT_CNT_SHIFT)) & NPU_NACT_CNT_MASK)
/*! @} */

/*! @name EVTRCCFG - Optional Event Trace configure/control */
/*! @{ */

#define NPU_EVTRCCFG_ENABLE_MASK                 (0x1U)
#define NPU_EVTRCCFG_ENABLE_SHIFT                (0U)
/*! ENABLE - Enable */
#define NPU_EVTRCCFG_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCCFG_ENABLE_SHIFT)) & NPU_EVTRCCFG_ENABLE_MASK)

#define NPU_EVTRCCFG_DIV_MASK                    (0xCU)
#define NPU_EVTRCCFG_DIV_SHIFT                   (2U)
/*! DIV - Divider
 *  0b00..Cycle is one count. No divider
 *  0b01..Divide by 4
 *  0b10..Divide by 16
 *  0b11..Divide by 64
 */
#define NPU_EVTRCCFG_DIV(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCCFG_DIV_SHIFT)) & NPU_EVTRCCFG_DIV_MASK)

#define NPU_EVTRCCFG_TSTAMP_MASK                 (0xFF0U)
#define NPU_EVTRCCFG_TSTAMP_SHIFT                (4U)
/*! TSTAMP - Time stamp */
#define NPU_EVTRCCFG_TSTAMP(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCCFG_TSTAMP_SHIFT)) & NPU_EVTRCCFG_TSTAMP_MASK)

#define NPU_EVTRCCFG_RW_MASK                     (0xF000U)
#define NPU_EVTRCCFG_RW_SHIFT                    (12U)
/*! RW - Read Write */
#define NPU_EVTRCCFG_RW(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCCFG_RW_SHIFT)) & NPU_EVTRCCFG_RW_MASK)

#define NPU_EVTRCCFG_START_MASK                  (0xFF0000U)
#define NPU_EVTRCCFG_START_SHIFT                 (16U)
/*! START - Start trace event
 *  0b00000001..Neutron
 *  0b00000010..Data fetch by Data Mover
 *  0b00000100..Data push by Data Mover
 *  0b00001000..Weight fetch by Data Mover
 */
#define NPU_EVTRCCFG_START(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCCFG_START_SHIFT)) & NPU_EVTRCCFG_START_MASK)

#define NPU_EVTRCCFG_END_MASK                    (0xF000000U)
#define NPU_EVTRCCFG_END_SHIFT                   (24U)
/*! END - End trace event */
#define NPU_EVTRCCFG_END(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCCFG_END_SHIFT)) & NPU_EVTRCCFG_END_MASK)
/*! @} */

/*! @name EVTRCDATA - Optional Event Trace Software submission */
/*! @{ */

#define NPU_EVTRCDATA_PUSH_MASK                  (0x1U)
#define NPU_EVTRCDATA_PUSH_SHIFT                 (0U)
/*! PUSH - Push */
#define NPU_EVTRCDATA_PUSH(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCDATA_PUSH_SHIFT)) & NPU_EVTRCDATA_PUSH_MASK)

#define NPU_EVTRCDATA_TYPE_MASK                  (0x70U)
#define NPU_EVTRCDATA_TYPE_SHIFT                 (4U)
/*! TYPE - Type
 *  0b000..Software Event only with no data or timestamp
 *  0b001..Software Event with 1 byte relative timestamp
 *  0b010..Software Event with 2 byte relative timestamp
 *  0b011..Software Event with absolute timestamp
 *  0b100..Software Event with 2 bytes of DATA
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define NPU_EVTRCDATA_TYPE(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCDATA_TYPE_SHIFT)) & NPU_EVTRCDATA_TYPE_MASK)

#define NPU_EVTRCDATA_DATA_MASK                  (0xFFFF0000U)
#define NPU_EVTRCDATA_DATA_SHIFT                 (16U)
/*! DATA - Optional data */
#define NPU_EVTRCDATA_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_EVTRCDATA_DATA_SHIFT)) & NPU_EVTRCDATA_DATA_MASK)
/*! @} */

/*! @name ZVIV2P0 - Zen-V Code Virtual to Physical */
/*! @{ */

#define NPU_ZVIV2P0_ERROR_MASK                   (0x1U)
#define NPU_ZVIV2P0_ERROR_SHIFT                  (0U)
/*! ERROR - ERROR */
#define NPU_ZVIV2P0_ERROR(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_ERROR_SHIFT)) & NPU_ZVIV2P0_ERROR_MASK)

#define NPU_ZVIV2P0_DATA1_MASK                   (0x2U)
#define NPU_ZVIV2P0_DATA1_SHIFT                  (1U)
/*! DATA1 - DATA1 */
#define NPU_ZVIV2P0_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_DATA1_SHIFT)) & NPU_ZVIV2P0_DATA1_MASK)

#define NPU_ZVIV2P0_DATA2_MASK                   (0x4U)
#define NPU_ZVIV2P0_DATA2_SHIFT                  (2U)
/*! DATA2 - DATA2 */
#define NPU_ZVIV2P0_DATA2(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_DATA2_SHIFT)) & NPU_ZVIV2P0_DATA2_MASK)

#define NPU_ZVIV2P0_DATA3_MASK                   (0x8U)
#define NPU_ZVIV2P0_DATA3_SHIFT                  (3U)
/*! DATA3 - DATA3 */
#define NPU_ZVIV2P0_DATA3(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_DATA3_SHIFT)) & NPU_ZVIV2P0_DATA3_MASK)

#define NPU_ZVIV2P0_MATCH1_MASK                  (0xFF00U)
#define NPU_ZVIV2P0_MATCH1_SHIFT                 (8U)
/*! MATCH1 - MATCH1 */
#define NPU_ZVIV2P0_MATCH1(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_MATCH1_SHIFT)) & NPU_ZVIV2P0_MATCH1_MASK)

#define NPU_ZVIV2P0_MATCH2_MASK                  (0xFF0000U)
#define NPU_ZVIV2P0_MATCH2_SHIFT                 (16U)
/*! MATCH2 - MATCH2 */
#define NPU_ZVIV2P0_MATCH2(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_MATCH2_SHIFT)) & NPU_ZVIV2P0_MATCH2_MASK)

#define NPU_ZVIV2P0_MATCH3_MASK                  (0xFF000000U)
#define NPU_ZVIV2P0_MATCH3_SHIFT                 (24U)
/*! MATCH3 - MATCH2 */
#define NPU_ZVIV2P0_MATCH3(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P0_MATCH3_SHIFT)) & NPU_ZVIV2P0_MATCH3_MASK)
/*! @} */

/*! @name ZVIV2P1 - Zen-V Code Virtual to Physical */
/*! @{ */

#define NPU_ZVIV2P1_MATCH0_MASK                  (0xFFU)
#define NPU_ZVIV2P1_MATCH0_SHIFT                 (0U)
/*! MATCH0 - MATCH0 */
#define NPU_ZVIV2P1_MATCH0(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P1_MATCH0_SHIFT)) & NPU_ZVIV2P1_MATCH0_MASK)

#define NPU_ZVIV2P1_MATCH1_MASK                  (0xFF00U)
#define NPU_ZVIV2P1_MATCH1_SHIFT                 (8U)
/*! MATCH1 - MATCH1 */
#define NPU_ZVIV2P1_MATCH1(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P1_MATCH1_SHIFT)) & NPU_ZVIV2P1_MATCH1_MASK)

#define NPU_ZVIV2P1_MATCH2_MASK                  (0xFF0000U)
#define NPU_ZVIV2P1_MATCH2_SHIFT                 (16U)
/*! MATCH2 - MATCH2 */
#define NPU_ZVIV2P1_MATCH2(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P1_MATCH2_SHIFT)) & NPU_ZVIV2P1_MATCH2_MASK)

#define NPU_ZVIV2P1_MATCH3_MASK                  (0xFF000000U)
#define NPU_ZVIV2P1_MATCH3_SHIFT                 (24U)
/*! MATCH3 - MATCH3 */
#define NPU_ZVIV2P1_MATCH3(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P1_MATCH3_SHIFT)) & NPU_ZVIV2P1_MATCH3_MASK)
/*! @} */

/*! @name ZVIV2P2 - Zen-V Code Virtual to Physical */
/*! @{ */

#define NPU_ZVIV2P2_MATCH0_MASK                  (0xFFU)
#define NPU_ZVIV2P2_MATCH0_SHIFT                 (0U)
/*! MATCH0 - MATCH0 */
#define NPU_ZVIV2P2_MATCH0(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P2_MATCH0_SHIFT)) & NPU_ZVIV2P2_MATCH0_MASK)

#define NPU_ZVIV2P2_MATCH1_MASK                  (0xFF00U)
#define NPU_ZVIV2P2_MATCH1_SHIFT                 (8U)
/*! MATCH1 - MATCH1 */
#define NPU_ZVIV2P2_MATCH1(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P2_MATCH1_SHIFT)) & NPU_ZVIV2P2_MATCH1_MASK)

#define NPU_ZVIV2P2_MATCH2_MASK                  (0xFF0000U)
#define NPU_ZVIV2P2_MATCH2_SHIFT                 (16U)
/*! MATCH2 - MATCH2 */
#define NPU_ZVIV2P2_MATCH2(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P2_MATCH2_SHIFT)) & NPU_ZVIV2P2_MATCH2_MASK)

#define NPU_ZVIV2P2_MATCH3_MASK                  (0xFF000000U)
#define NPU_ZVIV2P2_MATCH3_SHIFT                 (24U)
/*! MATCH3 - MATCH3 */
#define NPU_ZVIV2P2_MATCH3(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P2_MATCH3_SHIFT)) & NPU_ZVIV2P2_MATCH3_MASK)
/*! @} */

/*! @name ZVIV2P3 - Zen-V Code Virtual to Physical */
/*! @{ */

#define NPU_ZVIV2P3_MATCH0_MASK                  (0xFFU)
#define NPU_ZVIV2P3_MATCH0_SHIFT                 (0U)
/*! MATCH0 - MATCH0 */
#define NPU_ZVIV2P3_MATCH0(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P3_MATCH0_SHIFT)) & NPU_ZVIV2P3_MATCH0_MASK)

#define NPU_ZVIV2P3_MATCH1_MASK                  (0xFF00U)
#define NPU_ZVIV2P3_MATCH1_SHIFT                 (8U)
/*! MATCH1 - MATCH1 */
#define NPU_ZVIV2P3_MATCH1(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P3_MATCH1_SHIFT)) & NPU_ZVIV2P3_MATCH1_MASK)

#define NPU_ZVIV2P3_MATCH2_MASK                  (0xFF0000U)
#define NPU_ZVIV2P3_MATCH2_SHIFT                 (16U)
/*! MATCH2 - MATCH2 */
#define NPU_ZVIV2P3_MATCH2(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P3_MATCH2_SHIFT)) & NPU_ZVIV2P3_MATCH2_MASK)

#define NPU_ZVIV2P3_MATCH3_MASK                  (0xFF000000U)
#define NPU_ZVIV2P3_MATCH3_SHIFT                 (24U)
/*! MATCH3 - MATCH3 */
#define NPU_ZVIV2P3_MATCH3(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ZVIV2P3_MATCH3_SHIFT)) & NPU_ZVIV2P3_MATCH3_MASK)
/*! @} */

/*! @name TTCTRL - TCM-to-TCM Control */
/*! @{ */

#define NPU_TTCTRL_STRIDE_MASK                   (0xFFU)
#define NPU_TTCTRL_STRIDE_SHIFT                  (0U)
/*! STRIDE - Stride */
#define NPU_TTCTRL_STRIDE(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_TTCTRL_STRIDE_SHIFT)) & NPU_TTCTRL_STRIDE_MASK)

#define NPU_TTCTRL_SIZE_MASK                     (0x3FFF00U)
#define NPU_TTCTRL_SIZE_SHIFT                    (8U)
/*! SIZE - Size */
#define NPU_TTCTRL_SIZE(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_TTCTRL_SIZE_SHIFT)) & NPU_TTCTRL_SIZE_MASK)

#define NPU_TTCTRL_ITER_MASK                     (0xFFC00000U)
#define NPU_TTCTRL_ITER_SHIFT                    (22U)
/*! ITER - Iterations */
#define NPU_TTCTRL_ITER(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_TTCTRL_ITER_SHIFT)) & NPU_TTCTRL_ITER_MASK)
/*! @} */

/*! @name TTSADDR - TCM-to-TCM Source Address */
/*! @{ */

#define NPU_TTSADDR_ADDR_MASK                    (0xFFFFFFFFU)
#define NPU_TTSADDR_ADDR_SHIFT                   (0U)
/*! ADDR - Address */
#define NPU_TTSADDR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_TTSADDR_ADDR_SHIFT)) & NPU_TTSADDR_ADDR_MASK)
/*! @} */

/*! @name TTDADDR - TCM-to-TCM Destination Address */
/*! @{ */

#define NPU_TTDADDR_ADDR_MASK                    (0xFFFFFFFFU)
#define NPU_TTDADDR_ADDR_SHIFT                   (0U)
/*! ADDR - Address */
#define NPU_TTDADDR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_TTDADDR_ADDR_SHIFT)) & NPU_TTDADDR_ADDR_MASK)
/*! @} */

/*! @name TTCTRL2 - TCM-to-TCM Control 2 */
/*! @{ */

#define NPU_TTCTRL2_DSTLEN_MASK                  (0x7FFFFU)
#define NPU_TTCTRL2_DSTLEN_SHIFT                 (0U)
/*! DSTLEN - Destination Length */
#define NPU_TTCTRL2_DSTLEN(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_TTCTRL2_DSTLEN_SHIFT)) & NPU_TTCTRL2_DSTLEN_MASK)

#define NPU_TTCTRL2_MODE_MASK                    (0xC00000U)
#define NPU_TTCTRL2_MODE_SHIFT                   (22U)
/*! MODE - Mode
 *  0b00..Normal slice (src_stride)
 *  0b01..Destination stride (using {pad,src_stride})
 *  0b10..Inject padding (using src_stride)
 */
#define NPU_TTCTRL2_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_TTCTRL2_MODE_SHIFT)) & NPU_TTCTRL2_MODE_MASK)

#define NPU_TTCTRL2_PAD_MASK                     (0xFF000000U)
#define NPU_TTCTRL2_PAD_SHIFT                    (24U)
/*! PAD - Pad */
#define NPU_TTCTRL2_PAD(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_TTCTRL2_PAD_SHIFT)) & NPU_TTCTRL2_PAD_MASK)
/*! @} */

/*! @name CONFIG - Configuration */
/*! @{ */

#define NPU_CONFIG_TTINTENA_MASK                 (0x1U)
#define NPU_CONFIG_TTINTENA_SHIFT                (0U)
/*! TTINTENA - Enable TCM-to-TCM Channel Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_TTINTENA(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_TTINTENA_SHIFT)) & NPU_CONFIG_TTINTENA_MASK)

#define NPU_CONFIG_FINTENA_MASK                  (0x2U)
#define NPU_CONFIG_FINTENA_SHIFT                 (1U)
/*! FINTENA - Enable Fetch Channel Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_FINTENA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_FINTENA_SHIFT)) & NPU_CONFIG_FINTENA_MASK)

#define NPU_CONFIG_PINTENA_MASK                  (0x4U)
#define NPU_CONFIG_PINTENA_SHIFT                 (2U)
/*! PINTENA - Enable Push Channel Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_PINTENA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_PINTENA_SHIFT)) & NPU_CONFIG_PINTENA_MASK)

#define NPU_CONFIG_WINTENA_MASK                  (0x8U)
#define NPU_CONFIG_WINTENA_SHIFT                 (3U)
/*! WINTENA - Enable Weight Channel Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_WINTENA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_WINTENA_SHIFT)) & NPU_CONFIG_WINTENA_MASK)

#define NPU_CONFIG_ERRENA_MASK                   (0x10U)
#define NPU_CONFIG_ERRENA_SHIFT                  (4U)
/*! ERRENA - Enable Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_ERRENA(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_ERRENA_SHIFT)) & NPU_CONFIG_ERRENA_MASK)

#define NPU_CONFIG_RELEASE_MASK                  (0x80U)
#define NPU_CONFIG_RELEASE_SHIFT                 (7U)
/*! RELEASE - Zen-V Release
 *  0b0..No action
 *  0b1..Release from reset
 */
#define NPU_CONFIG_RELEASE(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_RELEASE_SHIFT)) & NPU_CONFIG_RELEASE_MASK)

#define NPU_CONFIG_TTINT_MASK                    (0x100U)
#define NPU_CONFIG_TTINT_SHIFT                   (8U)
/*! TTINT - TCM-to-TCM Channel Interrupt Status
 *  0b0..No effect
 *  0b0..No interrupt generated
 *  0b1..Clear
 *  0b1..Interrupt generated
 */
#define NPU_CONFIG_TTINT(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_TTINT_SHIFT)) & NPU_CONFIG_TTINT_MASK)

#define NPU_CONFIG_FINT_MASK                     (0x200U)
#define NPU_CONFIG_FINT_SHIFT                    (9U)
/*! FINT - Fetch Channel Interrupt Status
 *  0b0..No effect
 *  0b0..No interrupt generated
 *  0b1..Clear
 *  0b1..Interrupt generated
 */
#define NPU_CONFIG_FINT(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_FINT_SHIFT)) & NPU_CONFIG_FINT_MASK)

#define NPU_CONFIG_PINT_MASK                     (0x400U)
#define NPU_CONFIG_PINT_SHIFT                    (10U)
/*! PINT - Push Channel Interrupt Status
 *  0b0..No effect
 *  0b0..No interrupt generated
 *  0b1..Clear
 *  0b1..Interrupt generated
 */
#define NPU_CONFIG_PINT(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_PINT_SHIFT)) & NPU_CONFIG_PINT_MASK)

#define NPU_CONFIG_WINT_MASK                     (0x800U)
#define NPU_CONFIG_WINT_SHIFT                    (11U)
/*! WINT - Data Mover Weight Channel Interrupt
 *  0b0..No effect
 *  0b0..No interrupt generated
 *  0b1..Clear
 *  0b1..Interrupt generated
 */
#define NPU_CONFIG_WINT(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_WINT_SHIFT)) & NPU_CONFIG_WINT_MASK)

#define NPU_CONFIG_EINT_MASK                     (0x1000U)
#define NPU_CONFIG_EINT_SHIFT                    (12U)
/*! EINT - Data Mover Error Interrupt
 *  0b0..No effect
 *  0b0..No interrupt generated
 *  0b1..Clear
 *  0b1..Interrupt generated
 */
#define NPU_CONFIG_EINT(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_EINT_SHIFT)) & NPU_CONFIG_EINT_MASK)

#define NPU_CONFIG_TTWFIENA_MASK                 (0x10000U)
#define NPU_CONFIG_TTWFIENA_SHIFT                (16U)
/*! TTWFIENA - TCM-to-TCM Chanel Exit Wait For Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_TTWFIENA(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_TTWFIENA_SHIFT)) & NPU_CONFIG_TTWFIENA_MASK)

#define NPU_CONFIG_FWFIENA_MASK                  (0x20000U)
#define NPU_CONFIG_FWFIENA_SHIFT                 (17U)
/*! FWFIENA - Fetch Channel Wait For Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_FWFIENA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_FWFIENA_SHIFT)) & NPU_CONFIG_FWFIENA_MASK)

#define NPU_CONFIG_PWFIENA_MASK                  (0x40000U)
#define NPU_CONFIG_PWFIENA_SHIFT                 (18U)
/*! PWFIENA - Push Channel Wait For Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_PWFIENA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_PWFIENA_SHIFT)) & NPU_CONFIG_PWFIENA_MASK)

#define NPU_CONFIG_WWFIENA_MASK                  (0x80000U)
#define NPU_CONFIG_WWFIENA_SHIFT                 (19U)
/*! WWFIENA - Weight Channel Wait For Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_CONFIG_WWFIENA(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_WWFIENA_SHIFT)) & NPU_CONFIG_WWFIENA_MASK)
/*! @} */

/*! @name STATUS - Data mover status */
/*! @{ */

#define NPU_STATUS_TTERRD_MASK                   (0x1U)
#define NPU_STATUS_TTERRD_SHIFT                  (0U)
/*! TTERRD - TCM-to-TCM Channel Error: Destination
 *  0b0..No error
 *  0b1..Error
 */
#define NPU_STATUS_TTERRD(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_TTERRD_SHIFT)) & NPU_STATUS_TTERRD_MASK)

#define NPU_STATUS_TTERRS_MASK                   (0x2U)
#define NPU_STATUS_TTERRS_SHIFT                  (1U)
/*! TTERRS - TCM-to-TCM Channel Error: Source
 *  0b0..No error
 *  0b1..Error
 */
#define NPU_STATUS_TTERRS(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_TTERRS_SHIFT)) & NPU_STATUS_TTERRS_MASK)

#define NPU_STATUS_DERRD_MASK                    (0xF0U)
#define NPU_STATUS_DERRD_SHIFT                   (4U)
/*! DERRD - Data Channel Error: Destination */
#define NPU_STATUS_DERRD(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_DERRD_SHIFT)) & NPU_STATUS_DERRD_MASK)

#define NPU_STATUS_DERRS_MASK                    (0xF00U)
#define NPU_STATUS_DERRS_SHIFT                   (8U)
/*! DERRS - Data Channel Error Source */
#define NPU_STATUS_DERRS(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_DERRS_SHIFT)) & NPU_STATUS_DERRS_MASK)

#define NPU_STATUS_WERRD_MASK                    (0x1000U)
#define NPU_STATUS_WERRD_SHIFT                   (12U)
/*! WERRD - Weight Channel Error: Destination
 *  0b0..No error
 *  0b1..Error
 */
#define NPU_STATUS_WERRD(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_WERRD_SHIFT)) & NPU_STATUS_WERRD_MASK)

#define NPU_STATUS_WERRS_MASK                    (0x2000U)
#define NPU_STATUS_WERRS_SHIFT                   (13U)
/*! WERRS - Weight Channel Error: Source
 *  0b0..No error
 *  0b1..Error
 */
#define NPU_STATUS_WERRS(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_WERRS_SHIFT)) & NPU_STATUS_WERRS_MASK)

#define NPU_STATUS_XERR_MASK                     (0x8000U)
#define NPU_STATUS_XERR_SHIFT                    (15U)
/*! XERR - DxORDER Register Error
 *  0b0..No error
 *  0b1..Error
 */
#define NPU_STATUS_XERR(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_XERR_SHIFT)) & NPU_STATUS_XERR_MASK)

#define NPU_STATUS_LRDSTALL_MASK                 (0x10000U)
#define NPU_STATUS_LRDSTALL_SHIFT                (16U)
/*! LRDSTALL - Local Read Stall
 *  0b0..No read stall
 *  0b1..Read stall
 */
#define NPU_STATUS_LRDSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_LRDSTALL_SHIFT)) & NPU_STATUS_LRDSTALL_MASK)

#define NPU_STATUS_LWRSTALL_MASK                 (0x20000U)
#define NPU_STATUS_LWRSTALL_SHIFT                (17U)
/*! LWRSTALL - Local Write Stall
 *  0b0..No write stall
 *  0b1..Write stall
 */
#define NPU_STATUS_LWRSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_LWRSTALL_SHIFT)) & NPU_STATUS_LWRSTALL_MASK)

#define NPU_STATUS_XRDSTALL_MASK                 (0x40000U)
#define NPU_STATUS_XRDSTALL_SHIFT                (18U)
/*! XRDSTALL - AXI Read Stall
 *  0b0..No AXI read stall
 *  0b1..AXI read stall
 */
#define NPU_STATUS_XRDSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_XRDSTALL_SHIFT)) & NPU_STATUS_XRDSTALL_MASK)

#define NPU_STATUS_XWRSTALL_MASK                 (0x80000U)
#define NPU_STATUS_XWRSTALL_SHIFT                (19U)
/*! XWRSTALL - AXI Write Stall
 *  0b0..No AXI write stall
 *  0b1..AXI write stall
 */
#define NPU_STATUS_XWRSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_XWRSTALL_SHIFT)) & NPU_STATUS_XWRSTALL_MASK)

#define NPU_STATUS_DECOMPERR_MASK                (0x100000U)
#define NPU_STATUS_DECOMPERR_SHIFT               (20U)
/*! DECOMPERR - Decompressor Error
 *  0b0..No error
 *  0b1..Error
 */
#define NPU_STATUS_DECOMPERR(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_DECOMPERR_SHIFT)) & NPU_STATUS_DECOMPERR_MASK)
/*! @} */

/*! @name DFORDER - Data Fetch Order Manager */
/*! @{ */

#define NPU_DFORDER_INDEX_MASK                   (0x3U)
#define NPU_DFORDER_INDEX_SHIFT                  (0U)
/*! INDEX - Index */
#define NPU_DFORDER_INDEX(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_INDEX_SHIFT)) & NPU_DFORDER_INDEX_MASK)

#define NPU_DFORDER_STALL_MASK                   (0x4U)
#define NPU_DFORDER_STALL_SHIFT                  (2U)
/*! STALL - Stall
 *  0b0..No stall
 *  0b1..Stall
 */
#define NPU_DFORDER_STALL(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_STALL_SHIFT)) & NPU_DFORDER_STALL_MASK)

#define NPU_DFORDER_LIST0_MASK                   (0x70U)
#define NPU_DFORDER_LIST0_SHIFT                  (4U)
/*! LIST0 - List 0
 *  0b0xx..List entry is completed
 *  0b100..Fetch channel 0 is pending or running
 *  0b101..Fetch channel 1 is pending or running
 *  0b110..Weight channel is pending or running
 *  0b111..Reserved
 */
#define NPU_DFORDER_LIST0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_LIST0_SHIFT)) & NPU_DFORDER_LIST0_MASK)

#define NPU_DFORDER_LIST1_MASK                   (0x700U)
#define NPU_DFORDER_LIST1_SHIFT                  (8U)
/*! LIST1 - List 1
 *  0b0xx..List entry is completed
 *  0b100..Fetch channel 0 is pending or running
 *  0b101..Fetch channel 1 is pending or running
 *  0b110..Weight channel is pending or running
 *  0b111..Reserved
 */
#define NPU_DFORDER_LIST1(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_LIST1_SHIFT)) & NPU_DFORDER_LIST1_MASK)

#define NPU_DFORDER_LIST2_MASK                   (0x7000U)
#define NPU_DFORDER_LIST2_SHIFT                  (12U)
/*! LIST2 - List 2
 *  0b0xx..List entry is completed
 *  0b100..Fetch channel 0 is pending or running
 *  0b101..Fetch channel 1 is pending or running
 *  0b110..Weight channel is pending or running
 *  0b111..Reserved
 */
#define NPU_DFORDER_LIST2(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_LIST2_SHIFT)) & NPU_DFORDER_LIST2_MASK)

#define NPU_DFORDER_LIST3_MASK                   (0x70000U)
#define NPU_DFORDER_LIST3_SHIFT                  (16U)
/*! LIST3 - List 3
 *  0b0xx..List entry is completed
 *  0b100..Fetch channel 0 is pending or running
 *  0b101..Fetch channel 1 is pending or running
 *  0b110..Weight channel is pending or running
 *  0b111..Reserved
 */
#define NPU_DFORDER_LIST3(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_LIST3_SHIFT)) & NPU_DFORDER_LIST3_MASK)

#define NPU_DFORDER_ADD_MASK                     (0x7000000U)
#define NPU_DFORDER_ADD_SHIFT                    (24U)
/*! ADD - ADD
 *  0b0xx..Write DFORDER[INDEX], DFORDER[STALL], DFORDER[LIST0], DFORDER[LIST1], DFORDER[LIST2], and DFORDER[LIST3]
 *  0b100..Add fetch channel 0
 *  0b101..Add fetch channel 1
 *  0b110..Add weight channel
 *  0b111..Reserved
 */
#define NPU_DFORDER_ADD(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_DFORDER_ADD_SHIFT)) & NPU_DFORDER_ADD_MASK)
/*! @} */

/*! @name DPORDER - Data Push Order Manager */
/*! @{ */

#define NPU_DPORDER_INDEX_MASK                   (0x3U)
#define NPU_DPORDER_INDEX_SHIFT                  (0U)
/*! INDEX - Index */
#define NPU_DPORDER_INDEX(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_INDEX_SHIFT)) & NPU_DPORDER_INDEX_MASK)

#define NPU_DPORDER_STALL_MASK                   (0x4U)
#define NPU_DPORDER_STALL_SHIFT                  (2U)
/*! STALL - Stall
 *  0b0..No stall
 *  0b1..Stall
 */
#define NPU_DPORDER_STALL(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_STALL_SHIFT)) & NPU_DPORDER_STALL_MASK)

#define NPU_DPORDER_LIST0_MASK                   (0x70U)
#define NPU_DPORDER_LIST0_SHIFT                  (4U)
/*! LIST0 - List 0
 *  0b00x..List entry is completed
 *  0b100..Push channel 0 is pending or running
 *  0b101..Push channel 1 is pending or running
 *  0b11x..Reserved
 */
#define NPU_DPORDER_LIST0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_LIST0_SHIFT)) & NPU_DPORDER_LIST0_MASK)

#define NPU_DPORDER_LIST1_MASK                   (0x700U)
#define NPU_DPORDER_LIST1_SHIFT                  (8U)
/*! LIST1 - List 1
 *  0b00x..List entry is completed
 *  0b100..Push channel 0 is pending or running
 *  0b101..Push channel 1 is pending or running
 *  0b11x..Reserved
 */
#define NPU_DPORDER_LIST1(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_LIST1_SHIFT)) & NPU_DPORDER_LIST1_MASK)

#define NPU_DPORDER_LIST2_MASK                   (0x7000U)
#define NPU_DPORDER_LIST2_SHIFT                  (12U)
/*! LIST2 - List 2
 *  0b00x..List entry is completed
 *  0b100..Push channel 0 is pending or running
 *  0b101..Push channel 1 is pending or running
 *  0b11x..Reserved
 */
#define NPU_DPORDER_LIST2(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_LIST2_SHIFT)) & NPU_DPORDER_LIST2_MASK)

#define NPU_DPORDER_LIST3_MASK                   (0x70000U)
#define NPU_DPORDER_LIST3_SHIFT                  (16U)
/*! LIST3 - List 3
 *  0b00x..List entry is completed
 *  0b100..Push channel 0 is pending or running
 *  0b101..Push channel 1 is pending or running
 *  0b11x..Reserved
 */
#define NPU_DPORDER_LIST3(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_LIST3_SHIFT)) & NPU_DPORDER_LIST3_MASK)

#define NPU_DPORDER_ADD_MASK                     (0x7000000U)
#define NPU_DPORDER_ADD_SHIFT                    (24U)
/*! ADD - ADD
 *  0b0xx..Write DPORDER[INDEX], DPORDER[STALL], DPORDER[LIST0], DPORDER[LIST1], DPORDER[LIST2], and DPORDER[LIST3]
 *  0b100..Add push channel 0
 *  0b101..Add push channel 1
 *  0b11x..Reserved
 */
#define NPU_DPORDER_ADD(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_DPORDER_ADD_SHIFT)) & NPU_DPORDER_ADD_MASK)
/*! @} */

/*! @name DCTRL0_FETCH - Fetch Control */
/*! @{ */

#define NPU_DCTRL0_FETCH_MODE_MASK               (0x3U)
#define NPU_DCTRL0_FETCH_MODE_SHIFT              (0U)
/*! MODE - Mode
 *  0b00..Write: Clears all DCTRL0_FETCH bits. Read: Fetch is completed.
 *  0b01..Activate Fetch
 *  0b10..Activate Fetch unpack
 *  0b11..Clears all DCTRL0_FETCH bits.
 */
#define NPU_DCTRL0_FETCH_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL0_FETCH_MODE_SHIFT)) & NPU_DCTRL0_FETCH_MODE_MASK)

#define NPU_DCTRL0_FETCH_SRCEQDST_MASK           (0x4U)
#define NPU_DCTRL0_FETCH_SRCEQDST_SHIFT          (2U)
/*! SRCEQDST - SRCEQDST */
#define NPU_DCTRL0_FETCH_SRCEQDST(x)             (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL0_FETCH_SRCEQDST_SHIFT)) & NPU_DCTRL0_FETCH_SRCEQDST_MASK)

#define NPU_DCTRL0_FETCH_PADINSERT_MASK          (0x8U)
#define NPU_DCTRL0_FETCH_PADINSERT_SHIFT         (3U)
/*! PADINSERT - Pad Insert */
#define NPU_DCTRL0_FETCH_PADINSERT(x)            (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL0_FETCH_PADINSERT_SHIFT)) & NPU_DCTRL0_FETCH_PADINSERT_MASK)

#define NPU_DCTRL0_FETCH_DESTLEN_MASK            (0xFFFF0U)
#define NPU_DCTRL0_FETCH_DESTLEN_SHIFT           (4U)
/*! DESTLEN - Destination Length */
#define NPU_DCTRL0_FETCH_DESTLEN(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL0_FETCH_DESTLEN_SHIFT)) & NPU_DCTRL0_FETCH_DESTLEN_MASK)

#define NPU_DCTRL0_FETCH_PADCNT_MASK             (0xF00000U)
#define NPU_DCTRL0_FETCH_PADCNT_SHIFT            (20U)
/*! PADCNT - Pad Count */
#define NPU_DCTRL0_FETCH_PADCNT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL0_FETCH_PADCNT_SHIFT)) & NPU_DCTRL0_FETCH_PADCNT_MASK)

#define NPU_DCTRL0_FETCH_PADBYTE_MASK            (0xFF000000U)
#define NPU_DCTRL0_FETCH_PADBYTE_SHIFT           (24U)
/*! PADBYTE - Pad Byte */
#define NPU_DCTRL0_FETCH_PADBYTE(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL0_FETCH_PADBYTE_SHIFT)) & NPU_DCTRL0_FETCH_PADBYTE_MASK)
/*! @} */

/*! @name DCTRL1_FETCH - Fetch Control */
/*! @{ */

#define NPU_DCTRL1_FETCH_MODE_MASK               (0x3U)
#define NPU_DCTRL1_FETCH_MODE_SHIFT              (0U)
/*! MODE - Mode
 *  0b00..Write: Clears all DCTRL1_FETCH bits. Read: Fetch is completed.
 *  0b01..Activate Fetch
 *  0b10..Activate Fetch unpack
 *  0b11..Clears all DCTRL1_FETCH bits.
 */
#define NPU_DCTRL1_FETCH_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL1_FETCH_MODE_SHIFT)) & NPU_DCTRL1_FETCH_MODE_MASK)

#define NPU_DCTRL1_FETCH_SRCEQDST_MASK           (0x4U)
#define NPU_DCTRL1_FETCH_SRCEQDST_SHIFT          (2U)
/*! SRCEQDST - SRCEQDST */
#define NPU_DCTRL1_FETCH_SRCEQDST(x)             (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL1_FETCH_SRCEQDST_SHIFT)) & NPU_DCTRL1_FETCH_SRCEQDST_MASK)

#define NPU_DCTRL1_FETCH_PADINSERT_MASK          (0x8U)
#define NPU_DCTRL1_FETCH_PADINSERT_SHIFT         (3U)
/*! PADINSERT - Pad Insert */
#define NPU_DCTRL1_FETCH_PADINSERT(x)            (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL1_FETCH_PADINSERT_SHIFT)) & NPU_DCTRL1_FETCH_PADINSERT_MASK)

#define NPU_DCTRL1_FETCH_DESTLEN_MASK            (0xFFFF0U)
#define NPU_DCTRL1_FETCH_DESTLEN_SHIFT           (4U)
/*! DESTLEN - Destination Length */
#define NPU_DCTRL1_FETCH_DESTLEN(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL1_FETCH_DESTLEN_SHIFT)) & NPU_DCTRL1_FETCH_DESTLEN_MASK)

#define NPU_DCTRL1_FETCH_PADCNT_MASK             (0xF00000U)
#define NPU_DCTRL1_FETCH_PADCNT_SHIFT            (20U)
/*! PADCNT - Pad Count */
#define NPU_DCTRL1_FETCH_PADCNT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL1_FETCH_PADCNT_SHIFT)) & NPU_DCTRL1_FETCH_PADCNT_MASK)

#define NPU_DCTRL1_FETCH_PADBYTE_MASK            (0xFF000000U)
#define NPU_DCTRL1_FETCH_PADBYTE_SHIFT           (24U)
/*! PADBYTE - Pad Byte */
#define NPU_DCTRL1_FETCH_PADBYTE(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL1_FETCH_PADBYTE_SHIFT)) & NPU_DCTRL1_FETCH_PADBYTE_MASK)
/*! @} */

/*! @name DCTRL2_PUSH - Push Control */
/*! @{ */

#define NPU_DCTRL2_PUSH_MODE_MASK                (0x3U)
#define NPU_DCTRL2_PUSH_MODE_SHIFT               (0U)
/*! MODE - Mode
 *  0b00..Write: Clears all DCTRL2_PUSH bits. Read: Push is completed.
 *  0b01..Activate Push
 *  0b10..Activate Push pack
 *  0b11..Clears all DCTRL2_PUSH bits.
 */
#define NPU_DCTRL2_PUSH_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_PUSH_MODE_SHIFT)) & NPU_DCTRL2_PUSH_MODE_MASK)

#define NPU_DCTRL2_PUSH_SRCEQDST_MASK            (0x4U)
#define NPU_DCTRL2_PUSH_SRCEQDST_SHIFT           (2U)
/*! SRCEQDST - SRCEQDST */
#define NPU_DCTRL2_PUSH_SRCEQDST(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_PUSH_SRCEQDST_SHIFT)) & NPU_DCTRL2_PUSH_SRCEQDST_MASK)

#define NPU_DCTRL2_PUSH_PADINSERT_MASK           (0x8U)
#define NPU_DCTRL2_PUSH_PADINSERT_SHIFT          (3U)
/*! PADINSERT - Pad Insert */
#define NPU_DCTRL2_PUSH_PADINSERT(x)             (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_PUSH_PADINSERT_SHIFT)) & NPU_DCTRL2_PUSH_PADINSERT_MASK)

#define NPU_DCTRL2_PUSH_DESTLEN_MASK             (0xFFFF0U)
#define NPU_DCTRL2_PUSH_DESTLEN_SHIFT            (4U)
/*! DESTLEN - Destination Length */
#define NPU_DCTRL2_PUSH_DESTLEN(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_PUSH_DESTLEN_SHIFT)) & NPU_DCTRL2_PUSH_DESTLEN_MASK)

#define NPU_DCTRL2_PUSH_PADCNT_MASK              (0xF00000U)
#define NPU_DCTRL2_PUSH_PADCNT_SHIFT             (20U)
/*! PADCNT - Pad Count */
#define NPU_DCTRL2_PUSH_PADCNT(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_PUSH_PADCNT_SHIFT)) & NPU_DCTRL2_PUSH_PADCNT_MASK)

#define NPU_DCTRL2_PUSH_PADBYTE_MASK             (0xFF000000U)
#define NPU_DCTRL2_PUSH_PADBYTE_SHIFT            (24U)
/*! PADBYTE - Pad Byte */
#define NPU_DCTRL2_PUSH_PADBYTE(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_PUSH_PADBYTE_SHIFT)) & NPU_DCTRL2_PUSH_PADBYTE_MASK)
/*! @} */

/*! @name DCTRL3_PUSH - Push Control */
/*! @{ */

#define NPU_DCTRL3_PUSH_MODE_MASK                (0x3U)
#define NPU_DCTRL3_PUSH_MODE_SHIFT               (0U)
/*! MODE - Mode
 *  0b00..Write: Clears all DCTRL3_PUSH bits. Read: Push is completed.
 *  0b01..Activate Push
 *  0b10..Activate Push pack
 *  0b11..Clears all DCTRL3_PUSH bits.
 */
#define NPU_DCTRL3_PUSH_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_PUSH_MODE_SHIFT)) & NPU_DCTRL3_PUSH_MODE_MASK)

#define NPU_DCTRL3_PUSH_SRCEQDST_MASK            (0x4U)
#define NPU_DCTRL3_PUSH_SRCEQDST_SHIFT           (2U)
/*! SRCEQDST - SRCEQDST */
#define NPU_DCTRL3_PUSH_SRCEQDST(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_PUSH_SRCEQDST_SHIFT)) & NPU_DCTRL3_PUSH_SRCEQDST_MASK)

#define NPU_DCTRL3_PUSH_PADINSERT_MASK           (0x8U)
#define NPU_DCTRL3_PUSH_PADINSERT_SHIFT          (3U)
/*! PADINSERT - Pad Insert */
#define NPU_DCTRL3_PUSH_PADINSERT(x)             (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_PUSH_PADINSERT_SHIFT)) & NPU_DCTRL3_PUSH_PADINSERT_MASK)

#define NPU_DCTRL3_PUSH_DESTLEN_MASK             (0xFFFF0U)
#define NPU_DCTRL3_PUSH_DESTLEN_SHIFT            (4U)
/*! DESTLEN - Destination Length */
#define NPU_DCTRL3_PUSH_DESTLEN(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_PUSH_DESTLEN_SHIFT)) & NPU_DCTRL3_PUSH_DESTLEN_MASK)

#define NPU_DCTRL3_PUSH_PADCNT_MASK              (0xF00000U)
#define NPU_DCTRL3_PUSH_PADCNT_SHIFT             (20U)
/*! PADCNT - Pad Count */
#define NPU_DCTRL3_PUSH_PADCNT(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_PUSH_PADCNT_SHIFT)) & NPU_DCTRL3_PUSH_PADCNT_MASK)

#define NPU_DCTRL3_PUSH_PADBYTE_MASK             (0xFF000000U)
#define NPU_DCTRL3_PUSH_PADBYTE_SHIFT            (24U)
/*! PADBYTE - Pad Byte */
#define NPU_DCTRL3_PUSH_PADBYTE(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_PUSH_PADBYTE_SHIFT)) & NPU_DCTRL3_PUSH_PADBYTE_MASK)
/*! @} */

/*! @name DSADDR0 - Fetch Source Address */
/*! @{ */

#define NPU_DSADDR0_DSADDR0_MASK                 (0xFFFFFFFFU)
#define NPU_DSADDR0_DSADDR0_SHIFT                (0U)
/*! DSADDR0 - DSADDR0 */
#define NPU_DSADDR0_DSADDR0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DSADDR0_DSADDR0_SHIFT)) & NPU_DSADDR0_DSADDR0_MASK)
/*! @} */

/*! @name DSADDR1 - Fetch Source Address */
/*! @{ */

#define NPU_DSADDR1_DSADDR1_MASK                 (0xFFFFFFFFU)
#define NPU_DSADDR1_DSADDR1_SHIFT                (0U)
/*! DSADDR1 - DSADDR1 */
#define NPU_DSADDR1_DSADDR1(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DSADDR1_DSADDR1_SHIFT)) & NPU_DSADDR1_DSADDR1_MASK)
/*! @} */

/*! @name DSADDR2 - Push Source Address */
/*! @{ */

#define NPU_DSADDR2_DSADDR2_MASK                 (0xFFFFFFFFU)
#define NPU_DSADDR2_DSADDR2_SHIFT                (0U)
/*! DSADDR2 - DSADDR2 */
#define NPU_DSADDR2_DSADDR2(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DSADDR2_DSADDR2_SHIFT)) & NPU_DSADDR2_DSADDR2_MASK)
/*! @} */

/*! @name DSADDR3 - Push Source Address */
/*! @{ */

#define NPU_DSADDR3_DSADDR3_MASK                 (0xFFFFFFFFU)
#define NPU_DSADDR3_DSADDR3_SHIFT                (0U)
/*! DSADDR3 - DSADDR3 */
#define NPU_DSADDR3_DSADDR3(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DSADDR3_DSADDR3_SHIFT)) & NPU_DSADDR3_DSADDR3_MASK)
/*! @} */

/*! @name DDADDR0 - Fetch Destination Address */
/*! @{ */

#define NPU_DDADDR0_DDADDR0_MASK                 (0xFFFFFFFFU)
#define NPU_DDADDR0_DDADDR0_SHIFT                (0U)
/*! DDADDR0 - DDADDR0 */
#define NPU_DDADDR0_DDADDR0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DDADDR0_DDADDR0_SHIFT)) & NPU_DDADDR0_DDADDR0_MASK)
/*! @} */

/*! @name DDADDR1 - Fetch Destination Address */
/*! @{ */

#define NPU_DDADDR1_DDADDR1_MASK                 (0xFFFFFFFFU)
#define NPU_DDADDR1_DDADDR1_SHIFT                (0U)
/*! DDADDR1 - DDADDR1 */
#define NPU_DDADDR1_DDADDR1(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DDADDR1_DDADDR1_SHIFT)) & NPU_DDADDR1_DDADDR1_MASK)
/*! @} */

/*! @name DDADDR2 - Push Destination Address */
/*! @{ */

#define NPU_DDADDR2_DDADDR2_MASK                 (0xFFFFFFFFU)
#define NPU_DDADDR2_DDADDR2_SHIFT                (0U)
/*! DDADDR2 - DDADDR2 */
#define NPU_DDADDR2_DDADDR2(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DDADDR2_DDADDR2_SHIFT)) & NPU_DDADDR2_DDADDR2_MASK)
/*! @} */

/*! @name DDADDR3 - Push Destination Address */
/*! @{ */

#define NPU_DDADDR3_DDADDR3_MASK                 (0xFFFFFFFFU)
#define NPU_DDADDR3_DDADDR3_SHIFT                (0U)
/*! DDADDR3 - DDADDR3 */
#define NPU_DDADDR3_DDADDR3(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DDADDR3_DDADDR3_SHIFT)) & NPU_DDADDR3_DDADDR3_MASK)
/*! @} */

/*! @name DCTRL2_0 - Fetch Second Control */
/*! @{ */

#define NPU_DCTRL2_0_SRCLEN_MASK                 (0x3FFFU)
#define NPU_DCTRL2_0_SRCLEN_SHIFT                (0U)
/*! SRCLEN - SRCLEN */
#define NPU_DCTRL2_0_SRCLEN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_0_SRCLEN_SHIFT)) & NPU_DCTRL2_0_SRCLEN_MASK)

#define NPU_DCTRL2_0_SBIT_MASK                   (0x10000U)
#define NPU_DCTRL2_0_SBIT_SHIFT                  (16U)
/*! SBIT - SBIT */
#define NPU_DCTRL2_0_SBIT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_0_SBIT_SHIFT)) & NPU_DCTRL2_0_SBIT_MASK)

#define NPU_DCTRL2_0_ITER_MASK                   (0xFFF00000U)
#define NPU_DCTRL2_0_ITER_SHIFT                  (20U)
/*! ITER - ITER */
#define NPU_DCTRL2_0_ITER(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_0_ITER_SHIFT)) & NPU_DCTRL2_0_ITER_MASK)
/*! @} */

/*! @name DCTRL2_1 - Fetch Second Control */
/*! @{ */

#define NPU_DCTRL2_1_SRCLEN1_MASK                (0x3FFFU)
#define NPU_DCTRL2_1_SRCLEN1_SHIFT               (0U)
/*! SRCLEN1 - SRCLEN1 */
#define NPU_DCTRL2_1_SRCLEN1(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_1_SRCLEN1_SHIFT)) & NPU_DCTRL2_1_SRCLEN1_MASK)

#define NPU_DCTRL2_1_SBIT_MASK                   (0x10000U)
#define NPU_DCTRL2_1_SBIT_SHIFT                  (16U)
/*! SBIT - SBIT */
#define NPU_DCTRL2_1_SBIT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_1_SBIT_SHIFT)) & NPU_DCTRL2_1_SBIT_MASK)

#define NPU_DCTRL2_1_ITER1_MASK                  (0xFFF00000U)
#define NPU_DCTRL2_1_ITER1_SHIFT                 (20U)
/*! ITER1 - ITER1 */
#define NPU_DCTRL2_1_ITER1(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_1_ITER1_SHIFT)) & NPU_DCTRL2_1_ITER1_MASK)
/*! @} */

/*! @name DCTRL2_2 - Push pack Second Control */
/*! @{ */

#define NPU_DCTRL2_2_SRCLEN2_MASK                (0x3FFFU)
#define NPU_DCTRL2_2_SRCLEN2_SHIFT               (0U)
/*! SRCLEN2 - SRCLEN2 */
#define NPU_DCTRL2_2_SRCLEN2(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_2_SRCLEN2_SHIFT)) & NPU_DCTRL2_2_SRCLEN2_MASK)

#define NPU_DCTRL2_2_SBIT_MASK                   (0x10000U)
#define NPU_DCTRL2_2_SBIT_SHIFT                  (16U)
/*! SBIT - SBIT */
#define NPU_DCTRL2_2_SBIT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_2_SBIT_SHIFT)) & NPU_DCTRL2_2_SBIT_MASK)

#define NPU_DCTRL2_2_ITER2_MASK                  (0xFFF00000U)
#define NPU_DCTRL2_2_ITER2_SHIFT                 (20U)
/*! ITER2 - ITER2 */
#define NPU_DCTRL2_2_ITER2(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_2_ITER2_SHIFT)) & NPU_DCTRL2_2_ITER2_MASK)
/*! @} */

/*! @name DCTRL2_3 - Push pack Second Control */
/*! @{ */

#define NPU_DCTRL2_3_SRCLEN3_MASK                (0x3FFFU)
#define NPU_DCTRL2_3_SRCLEN3_SHIFT               (0U)
/*! SRCLEN3 - SRCLEN3 */
#define NPU_DCTRL2_3_SRCLEN3(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_3_SRCLEN3_SHIFT)) & NPU_DCTRL2_3_SRCLEN3_MASK)

#define NPU_DCTRL2_3_SBIT_MASK                   (0x10000U)
#define NPU_DCTRL2_3_SBIT_SHIFT                  (16U)
/*! SBIT - SBIT */
#define NPU_DCTRL2_3_SBIT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_3_SBIT_SHIFT)) & NPU_DCTRL2_3_SBIT_MASK)

#define NPU_DCTRL2_3_ITER3_MASK                  (0xFFF00000U)
#define NPU_DCTRL2_3_ITER3_SHIFT                 (20U)
/*! ITER3 - ITER3 */
#define NPU_DCTRL2_3_ITER3(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL2_3_ITER3_SHIFT)) & NPU_DCTRL2_3_ITER3_MASK)
/*! @} */

/*! @name WCTRL - Weight Fetch Control */
/*! @{ */

#define NPU_WCTRL_MODE_MASK                      (0x3U)
#define NPU_WCTRL_MODE_SHIFT                     (0U)
/*! MODE - Mode
 *  0b00..Write: Clears all WCTRL bits. Read: Weight Fetch is completed.
 *  0b01..Activate Weight Fetch
 *  0b10..Activate Weight Fetch unpack
 *  0b11..Clears all WPENDx and WCTRL bits.
 */
#define NPU_WCTRL_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL_MODE_SHIFT)) & NPU_WCTRL_MODE_MASK)

#define NPU_WCTRL_SRCEQDST_MASK                  (0x4U)
#define NPU_WCTRL_SRCEQDST_SHIFT                 (2U)
/*! SRCEQDST - SRCEQDST */
#define NPU_WCTRL_SRCEQDST(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL_SRCEQDST_SHIFT)) & NPU_WCTRL_SRCEQDST_MASK)

#define NPU_WCTRL_PADINSERT_MASK                 (0x8U)
#define NPU_WCTRL_PADINSERT_SHIFT                (3U)
/*! PADINSERT - Weight fetch unpack stride length selector
 *  0b0..Stride length is defined by WCTRL2_0.SBIT
 *  0b1..Stride length is 256kB
 */
#define NPU_WCTRL_PADINSERT(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL_PADINSERT_SHIFT)) & NPU_WCTRL_PADINSERT_MASK)

#define NPU_WCTRL_LEN_MASK                       (0xFFFF0U)
#define NPU_WCTRL_LEN_SHIFT                      (4U)
/*! LEN - LEN */
#define NPU_WCTRL_LEN(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL_LEN_SHIFT)) & NPU_WCTRL_LEN_MASK)

#define NPU_WCTRL_PADCNT_MASK                    (0xF00000U)
#define NPU_WCTRL_PADCNT_SHIFT                   (20U)
/*! PADCNT - Pad Count */
#define NPU_WCTRL_PADCNT(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL_PADCNT_SHIFT)) & NPU_WCTRL_PADCNT_MASK)

#define NPU_WCTRL_PADBYTE_MASK                   (0xFF000000U)
#define NPU_WCTRL_PADBYTE_SHIFT                  (24U)
/*! PADBYTE - Pad Byte */
#define NPU_WCTRL_PADBYTE(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL_PADBYTE_SHIFT)) & NPU_WCTRL_PADBYTE_MASK)
/*! @} */

/*! @name WSADDR - Weight Fetch Source Address */
/*! @{ */

#define NPU_WSADDR_ADDR_MASK                     (0xFFFFFFF0U)
#define NPU_WSADDR_ADDR_SHIFT                    (4U)
/*! ADDR - ADDR */
#define NPU_WSADDR_ADDR(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_WSADDR_ADDR_SHIFT)) & NPU_WSADDR_ADDR_MASK)
/*! @} */

/*! @name WDADDR - Weight Fetch Destination Address */
/*! @{ */

#define NPU_WDADDR_ADDR_MASK                     (0xFFFFFFF0U)
#define NPU_WDADDR_ADDR_SHIFT                    (4U)
/*! ADDR - ADDR */
#define NPU_WDADDR_ADDR(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_WDADDR_ADDR_SHIFT)) & NPU_WDADDR_ADDR_MASK)
/*! @} */

/*! @name DCTRL3_0 - Fetch Unpack Third Control */
/*! @{ */

#define NPU_DCTRL3_0_SRCSTRIDE_MASK              (0xFFFFU)
#define NPU_DCTRL3_0_SRCSTRIDE_SHIFT             (0U)
/*! SRCSTRIDE - SRCSTRIDE */
#define NPU_DCTRL3_0_SRCSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_0_SRCSTRIDE_SHIFT)) & NPU_DCTRL3_0_SRCSTRIDE_MASK)

#define NPU_DCTRL3_0_DSTSTRIDE_MASK              (0xFFFF0000U)
#define NPU_DCTRL3_0_DSTSTRIDE_SHIFT             (16U)
/*! DSTSTRIDE - DSTSTRIDE */
#define NPU_DCTRL3_0_DSTSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_0_DSTSTRIDE_SHIFT)) & NPU_DCTRL3_0_DSTSTRIDE_MASK)
/*! @} */

/*! @name DCTRL3_1 - Fetch Unpack Third Control */
/*! @{ */

#define NPU_DCTRL3_1_SRCSTRIDE_MASK              (0xFFFFU)
#define NPU_DCTRL3_1_SRCSTRIDE_SHIFT             (0U)
/*! SRCSTRIDE - SRCSTRIDE */
#define NPU_DCTRL3_1_SRCSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_1_SRCSTRIDE_SHIFT)) & NPU_DCTRL3_1_SRCSTRIDE_MASK)

#define NPU_DCTRL3_1_DSTSTRIDE_MASK              (0xFFFF0000U)
#define NPU_DCTRL3_1_DSTSTRIDE_SHIFT             (16U)
/*! DSTSTRIDE - DSTSTRIDE */
#define NPU_DCTRL3_1_DSTSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_1_DSTSTRIDE_SHIFT)) & NPU_DCTRL3_1_DSTSTRIDE_MASK)
/*! @} */

/*! @name DCTRL3_2 - Push pack Third Control */
/*! @{ */

#define NPU_DCTRL3_2_SRCSTRIDE_MASK              (0xFFFFU)
#define NPU_DCTRL3_2_SRCSTRIDE_SHIFT             (0U)
/*! SRCSTRIDE - SRCSTRIDE */
#define NPU_DCTRL3_2_SRCSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_2_SRCSTRIDE_SHIFT)) & NPU_DCTRL3_2_SRCSTRIDE_MASK)

#define NPU_DCTRL3_2_DSTSTRIDE_MASK              (0xFFFF0000U)
#define NPU_DCTRL3_2_DSTSTRIDE_SHIFT             (16U)
/*! DSTSTRIDE - DSTSTRIDE */
#define NPU_DCTRL3_2_DSTSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_2_DSTSTRIDE_SHIFT)) & NPU_DCTRL3_2_DSTSTRIDE_MASK)
/*! @} */

/*! @name DCTRL3_3 - Push pack Third Control */
/*! @{ */

#define NPU_DCTRL3_3_SRCSTRIDE_MASK              (0xFFFFU)
#define NPU_DCTRL3_3_SRCSTRIDE_SHIFT             (0U)
/*! SRCSTRIDE - SRCSTRIDE */
#define NPU_DCTRL3_3_SRCSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_3_SRCSTRIDE_SHIFT)) & NPU_DCTRL3_3_SRCSTRIDE_MASK)

#define NPU_DCTRL3_3_DSTSTRIDE_MASK              (0xFFFF0000U)
#define NPU_DCTRL3_3_DSTSTRIDE_SHIFT             (16U)
/*! DSTSTRIDE - DSTSTRIDE */
#define NPU_DCTRL3_3_DSTSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DCTRL3_3_DSTSTRIDE_SHIFT)) & NPU_DCTRL3_3_DSTSTRIDE_MASK)
/*! @} */

/*! @name WCTRL2_0 - Weight Fetch Second Control */
/*! @{ */

#define NPU_WCTRL2_0_SRCLEN_MASK                 (0x3FFFU)
#define NPU_WCTRL2_0_SRCLEN_SHIFT                (0U)
/*! SRCLEN - SRCLEN */
#define NPU_WCTRL2_0_SRCLEN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL2_0_SRCLEN_SHIFT)) & NPU_WCTRL2_0_SRCLEN_MASK)

#define NPU_WCTRL2_0_SBIT_MASK                   (0x10000U)
#define NPU_WCTRL2_0_SBIT_SHIFT                  (16U)
/*! SBIT - SBIT */
#define NPU_WCTRL2_0_SBIT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL2_0_SBIT_SHIFT)) & NPU_WCTRL2_0_SBIT_MASK)

#define NPU_WCTRL2_0_ITER_MASK                   (0xFFF00000U)
#define NPU_WCTRL2_0_ITER_SHIFT                  (20U)
/*! ITER - ITER */
#define NPU_WCTRL2_0_ITER(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL2_0_ITER_SHIFT)) & NPU_WCTRL2_0_ITER_MASK)
/*! @} */

/*! @name WCTRL3_0 - Weight Fetch Unpack Third Control */
/*! @{ */

#define NPU_WCTRL3_0_SRCSTRIDE_MASK              (0xFFFFU)
#define NPU_WCTRL3_0_SRCSTRIDE_SHIFT             (0U)
/*! SRCSTRIDE - SRCSTRIDE */
#define NPU_WCTRL3_0_SRCSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL3_0_SRCSTRIDE_SHIFT)) & NPU_WCTRL3_0_SRCSTRIDE_MASK)

#define NPU_WCTRL3_0_DSTSTRIDE_MASK              (0xFFFF0000U)
#define NPU_WCTRL3_0_DSTSTRIDE_SHIFT             (16U)
/*! DSTSTRIDE - DSTSTRIDE */
#define NPU_WCTRL3_0_DSTSTRIDE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_WCTRL3_0_DSTSTRIDE_SHIFT)) & NPU_WCTRL3_0_DSTSTRIDE_MASK)
/*! @} */

/*! @name WPEND1 - Fetch Pend/Ready set 1 */
/*! @{ */

#define NPU_WPEND1_WPEND1_ZONE0_MASK             (0xFFFFU)
#define NPU_WPEND1_WPEND1_ZONE0_SHIFT            (0U)
/*! WPEND1_ZONE0 - WPEND1_ZONE0 */
#define NPU_WPEND1_WPEND1_ZONE0(x)               (((uint32_t)(((uint32_t)(x)) << NPU_WPEND1_WPEND1_ZONE0_SHIFT)) & NPU_WPEND1_WPEND1_ZONE0_MASK)
/*! @} */

/*! @name APPCTRL_SOC - Application Control */
/*! @{ */

#define NPU_APPCTRL_SOC_INFCONT_MASK             (0x1U)
#define NPU_APPCTRL_SOC_INFCONT_SHIFT            (0U)
/*! INFCONT - INFCONT */
#define NPU_APPCTRL_SOC_INFCONT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_INFCONT_SHIFT)) & NPU_APPCTRL_SOC_INFCONT_MASK)

#define NPU_APPCTRL_SOC_INFHALT_MASK             (0x2U)
#define NPU_APPCTRL_SOC_INFHALT_SHIFT            (1U)
/*! INFHALT - INFHALT */
#define NPU_APPCTRL_SOC_INFHALT(x)               (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_INFHALT_SHIFT)) & NPU_APPCTRL_SOC_INFHALT_MASK)

#define NPU_APPCTRL_SOC_SYS_SHUTDOWN_MASK        (0x4U)
#define NPU_APPCTRL_SOC_SYS_SHUTDOWN_SHIFT       (2U)
/*! SYS_SHUTDOWN - SYS_SHUTDOWN */
#define NPU_APPCTRL_SOC_SYS_SHUTDOWN(x)          (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_SYS_SHUTDOWN_SHIFT)) & NPU_APPCTRL_SOC_SYS_SHUTDOWN_MASK)

#define NPU_APPCTRL_SOC_IMGPONG_MASK             (0x10U)
#define NPU_APPCTRL_SOC_IMGPONG_SHIFT            (4U)
/*! IMGPONG - IMGPONG */
#define NPU_APPCTRL_SOC_IMGPONG(x)               (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_IMGPONG_SHIFT)) & NPU_APPCTRL_SOC_IMGPONG_MASK)

#define NPU_APPCTRL_SOC_RESDONE_MASK             (0x20U)
#define NPU_APPCTRL_SOC_RESDONE_SHIFT            (5U)
/*! RESDONE - RESDONE */
#define NPU_APPCTRL_SOC_RESDONE(x)               (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_RESDONE_SHIFT)) & NPU_APPCTRL_SOC_RESDONE_MASK)

#define NPU_APPCTRL_SOC_RINGSTALL_MASK           (0x100U)
#define NPU_APPCTRL_SOC_RINGSTALL_SHIFT          (8U)
/*! RINGSTALL - RINGSTALL */
#define NPU_APPCTRL_SOC_RINGSTALL(x)             (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_RINGSTALL_SHIFT)) & NPU_APPCTRL_SOC_RINGSTALL_MASK)

#define NPU_APPCTRL_SOC_INTDONEENA2_MASK         (0x200U)
#define NPU_APPCTRL_SOC_INTDONEENA2_SHIFT        (9U)
/*! INTDONEENA2 - INTDONEENA */
#define NPU_APPCTRL_SOC_INTDONEENA2(x)           (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_INTDONEENA2_SHIFT)) & NPU_APPCTRL_SOC_INTDONEENA2_MASK)

#define NPU_APPCTRL_SOC_INTMBOXENA2_MASK         (0x400U)
#define NPU_APPCTRL_SOC_INTMBOXENA2_SHIFT        (10U)
/*! INTMBOXENA2 - INTMBOXENA */
#define NPU_APPCTRL_SOC_INTMBOXENA2(x)           (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_INTMBOXENA2_SHIFT)) & NPU_APPCTRL_SOC_INTMBOXENA2_MASK)

#define NPU_APPCTRL_SOC_MBZVWR_MASK              (0xFF0000U)
#define NPU_APPCTRL_SOC_MBZVWR_SHIFT             (16U)
/*! MBZVWR - MBZVWR */
#define NPU_APPCTRL_SOC_MBZVWR(x)                (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_MBZVWR_SHIFT)) & NPU_APPCTRL_SOC_MBZVWR_MASK)

#define NPU_APPCTRL_SOC_MBSOCWR_MASK             (0xFF000000U)
#define NPU_APPCTRL_SOC_MBSOCWR_SHIFT            (24U)
/*! MBSOCWR - MBSOCWR */
#define NPU_APPCTRL_SOC_MBSOCWR(x)               (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_SOC_MBSOCWR_SHIFT)) & NPU_APPCTRL_SOC_MBSOCWR_MASK)
/*! @} */

/*! @name APPCTRL_ZV - Application Control */
/*! @{ */

#define NPU_APPCTRL_ZV_INFCONT_MASK              (0x1U)
#define NPU_APPCTRL_ZV_INFCONT_SHIFT             (0U)
/*! INFCONT - INFCONT */
#define NPU_APPCTRL_ZV_INFCONT(x)                (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_INFCONT_SHIFT)) & NPU_APPCTRL_ZV_INFCONT_MASK)

#define NPU_APPCTRL_ZV_INFHALT_MASK              (0x2U)
#define NPU_APPCTRL_ZV_INFHALT_SHIFT             (1U)
/*! INFHALT - INFHALT */
#define NPU_APPCTRL_ZV_INFHALT(x)                (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_INFHALT_SHIFT)) & NPU_APPCTRL_ZV_INFHALT_MASK)

#define NPU_APPCTRL_ZV_SYS_SHUTDOWN_MASK         (0x4U)
#define NPU_APPCTRL_ZV_SYS_SHUTDOWN_SHIFT        (2U)
/*! SYS_SHUTDOWN - SYS_SHUTDOWN */
#define NPU_APPCTRL_ZV_SYS_SHUTDOWN(x)           (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_SYS_SHUTDOWN_SHIFT)) & NPU_APPCTRL_ZV_SYS_SHUTDOWN_MASK)

#define NPU_APPCTRL_ZV_IMGPONG_MASK              (0x10U)
#define NPU_APPCTRL_ZV_IMGPONG_SHIFT             (4U)
/*! IMGPONG - IMGPONG */
#define NPU_APPCTRL_ZV_IMGPONG(x)                (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_IMGPONG_SHIFT)) & NPU_APPCTRL_ZV_IMGPONG_MASK)

#define NPU_APPCTRL_ZV_RESDONE_MASK              (0x20U)
#define NPU_APPCTRL_ZV_RESDONE_SHIFT             (5U)
/*! RESDONE - RESDONE */
#define NPU_APPCTRL_ZV_RESDONE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_RESDONE_SHIFT)) & NPU_APPCTRL_ZV_RESDONE_MASK)

#define NPU_APPCTRL_ZV_RINGSTALL_MASK            (0x100U)
#define NPU_APPCTRL_ZV_RINGSTALL_SHIFT           (8U)
/*! RINGSTALL - RINGSTALL */
#define NPU_APPCTRL_ZV_RINGSTALL(x)              (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_RINGSTALL_SHIFT)) & NPU_APPCTRL_ZV_RINGSTALL_MASK)

#define NPU_APPCTRL_ZV_INTDONEENA1_MASK          (0x200U)
#define NPU_APPCTRL_ZV_INTDONEENA1_SHIFT         (9U)
/*! INTDONEENA1 - INTDONEENA */
#define NPU_APPCTRL_ZV_INTDONEENA1(x)            (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_INTDONEENA1_SHIFT)) & NPU_APPCTRL_ZV_INTDONEENA1_MASK)

#define NPU_APPCTRL_ZV_INTMBOXENA1_MASK          (0x400U)
#define NPU_APPCTRL_ZV_INTMBOXENA1_SHIFT         (10U)
/*! INTMBOXENA1 - INTMBOXENA */
#define NPU_APPCTRL_ZV_INTMBOXENA1(x)            (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_INTMBOXENA1_SHIFT)) & NPU_APPCTRL_ZV_INTMBOXENA1_MASK)

#define NPU_APPCTRL_ZV_MBZVWR_MASK               (0xFF0000U)
#define NPU_APPCTRL_ZV_MBZVWR_SHIFT              (16U)
/*! MBZVWR - MBZVWR */
#define NPU_APPCTRL_ZV_MBZVWR(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_MBZVWR_SHIFT)) & NPU_APPCTRL_ZV_MBZVWR_MASK)

#define NPU_APPCTRL_ZV_MBSOCWR_MASK              (0xFF000000U)
#define NPU_APPCTRL_ZV_MBSOCWR_SHIFT             (24U)
/*! MBSOCWR - MBSOCWR */
#define NPU_APPCTRL_ZV_MBSOCWR(x)                (((uint32_t)(((uint32_t)(x)) << NPU_APPCTRL_ZV_MBSOCWR_SHIFT)) & NPU_APPCTRL_ZV_MBSOCWR_MASK)
/*! @} */

/*! @name APPSTATUS - Application Status */
/*! @{ */

#define NPU_APPSTATUS_INFDONE_MASK               (0x1U)
#define NPU_APPSTATUS_INFDONE_SHIFT              (0U)
/*! INFDONE - Inference Done */
#define NPU_APPSTATUS_INFDONE(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_APPSTATUS_INFDONE_SHIFT)) & NPU_APPSTATUS_INFDONE_MASK)

#define NPU_APPSTATUS_INFHALTED_MASK             (0x2U)
#define NPU_APPSTATUS_INFHALTED_SHIFT            (1U)
/*! INFHALTED - INFHALTED */
#define NPU_APPSTATUS_INFHALTED(x)               (((uint32_t)(((uint32_t)(x)) << NPU_APPSTATUS_INFHALTED_SHIFT)) & NPU_APPSTATUS_INFHALTED_MASK)

#define NPU_APPSTATUS_INFBUFFHALF_MASK           (0x4U)
#define NPU_APPSTATUS_INFBUFFHALF_SHIFT          (2U)
/*! INFBUFFHALF - INFBUFFHALF */
#define NPU_APPSTATUS_INFBUFFHALF(x)             (((uint32_t)(((uint32_t)(x)) << NPU_APPSTATUS_INFBUFFHALF_SHIFT)) & NPU_APPSTATUS_INFBUFFHALF_MASK)

#define NPU_APPSTATUS_INFOUTHALF_MASK            (0x8U)
#define NPU_APPSTATUS_INFOUTHALF_SHIFT           (3U)
/*! INFOUTHALF - INFOUTHALF */
#define NPU_APPSTATUS_INFOUTHALF(x)              (((uint32_t)(((uint32_t)(x)) << NPU_APPSTATUS_INFOUTHALF_SHIFT)) & NPU_APPSTATUS_INFOUTHALF_MASK)

#define NPU_APPSTATUS_MBOX_MASK                  (0x10U)
#define NPU_APPSTATUS_MBOX_SHIFT                 (4U)
/*! MBOX - Mailbox */
#define NPU_APPSTATUS_MBOX(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_APPSTATUS_MBOX_SHIFT)) & NPU_APPSTATUS_MBOX_MASK)

#define NPU_APPSTATUS_FAULTCAUSE_MASK            (0x3F0000U)
#define NPU_APPSTATUS_FAULTCAUSE_SHIFT           (16U)
/*! FAULTCAUSE - Fault case */
#define NPU_APPSTATUS_FAULTCAUSE(x)              (((uint32_t)(((uint32_t)(x)) << NPU_APPSTATUS_FAULTCAUSE_SHIFT)) & NPU_APPSTATUS_FAULTCAUSE_MASK)
/*! @} */

/*! @name BASEDDRL - Base physical address in DDR */
/*! @{ */

#define NPU_BASEDDRL_SPLITPRIV_MASK              (0x1U)
#define NPU_BASEDDRL_SPLITPRIV_SHIFT             (0U)
/*! SPLITPRIV - SPLITPRIV */
#define NPU_BASEDDRL_SPLITPRIV(x)                (((uint32_t)(((uint32_t)(x)) << NPU_BASEDDRL_SPLITPRIV_SHIFT)) & NPU_BASEDDRL_SPLITPRIV_MASK)

#define NPU_BASEDDRL_LIMITMB_MASK                (0x1FF00U)
#define NPU_BASEDDRL_LIMITMB_SHIFT               (8U)
/*! LIMITMB - LIMITMB */
#define NPU_BASEDDRL_LIMITMB(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEDDRL_LIMITMB_SHIFT)) & NPU_BASEDDRL_LIMITMB_MASK)

#define NPU_BASEDDRL_BASEDDRL_MASK               (0xFFF00000U)
#define NPU_BASEDDRL_BASEDDRL_SHIFT              (20U)
/*! BASEDDRL - BASEDDRL */
#define NPU_BASEDDRL_BASEDDRL(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEDDRL_BASEDDRL_SHIFT)) & NPU_BASEDDRL_BASEDDRL_MASK)
/*! @} */

/*! @name BASEDDRH - Base physical address in DDR */
/*! @{ */

#define NPU_BASEDDRH_BASEDDRH_1_MASK             (0x1FFFFU)
#define NPU_BASEDDRH_BASEDDRH_1_SHIFT            (0U)
/*! BASEDDRH_1 - BASEDDRH */
#define NPU_BASEDDRH_BASEDDRH_1(x)               (((uint32_t)(((uint32_t)(x)) << NPU_BASEDDRH_BASEDDRH_1_SHIFT)) & NPU_BASEDDRH_BASEDDRH_1_MASK)
/*! @} */

/*! @name INPUT - Offset of Input image from DDR Base */
/*! @{ */

#define NPU_INPUT_INPUT_MASK                     (0x3FFFFF0U)
#define NPU_INPUT_INPUT_SHIFT                    (4U)
/*! INPUT - INPUT */
#define NPU_INPUT_INPUT(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_INPUT_INPUT_SHIFT)) & NPU_INPUT_INPUT_MASK)
/*! @} */

/*! @name INPUT2 - Offset of Input image from DDR Base */
/*! @{ */

#define NPU_INPUT2_INPUT2_MASK                   (0x3FFFFF0U)
#define NPU_INPUT2_INPUT2_SHIFT                  (4U)
/*! INPUT2 - INPUT2 */
#define NPU_INPUT2_INPUT2(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_INPUT2_INPUT2_SHIFT)) & NPU_INPUT2_INPUT2_MASK)
/*! @} */

/*! @name OUTPUT - Offset of Output results from DDR Base */
/*! @{ */

#define NPU_OUTPUT_OUTPUT_MASK                   (0x3FFFFF0U)
#define NPU_OUTPUT_OUTPUT_SHIFT                  (4U)
/*! OUTPUT - OUTPUT */
#define NPU_OUTPUT_OUTPUT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_OUTPUT_OUTPUT_SHIFT)) & NPU_OUTPUT_OUTPUT_MASK)
/*! @} */

/*! @name OUTPUT2 - Offset of Output results from DDR Base */
/*! @{ */

#define NPU_OUTPUT2_OUTPUT2_MASK                 (0x3FFFFF0U)
#define NPU_OUTPUT2_OUTPUT2_SHIFT                (4U)
/*! OUTPUT2 - OUTPUT2 */
#define NPU_OUTPUT2_OUTPUT2(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_OUTPUT2_OUTPUT2_SHIFT)) & NPU_OUTPUT2_OUTPUT2_MASK)
/*! @} */

/*! @name CODEOFF - Offset of Zen-V code from BASEDDRn */
/*! @{ */

#define NPU_CODEOFF_CODEOFF_MASK                 (0x7FFFFF0U)
#define NPU_CODEOFF_CODEOFF_SHIFT                (4U)
/*! CODEOFF - CODEOFF */
#define NPU_CODEOFF_CODEOFF(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_CODEOFF_CODEOFF_SHIFT)) & NPU_CODEOFF_CODEOFF_MASK)
/*! @} */

/*! @name DATAOFF - Offset of Zen-V data from BASEDDRn */
/*! @{ */

#define NPU_DATAOFF_DATAOFF_MASK                 (0x7FFFFF0U)
#define NPU_DATAOFF_DATAOFF_SHIFT                (4U)
/*! DATAOFF - DATAOFF */
#define NPU_DATAOFF_DATAOFF(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DATAOFF_DATAOFF_SHIFT)) & NPU_DATAOFF_DATAOFF_MASK)
/*! @} */

/*! @name RINGCTRL - Ring buffer control by Zen-V */
/*! @{ */

#define NPU_RINGCTRL_RINGSZ_MASK                 (0xFFU)
#define NPU_RINGCTRL_RINGSZ_SHIFT                (0U)
/*! RINGSZ - RINGSZ */
#define NPU_RINGCTRL_RINGSZ(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_RINGCTRL_RINGSZ_SHIFT)) & NPU_RINGCTRL_RINGSZ_MASK)

#define NPU_RINGCTRL_RINGADDR_MASK               (0x3F00U)
#define NPU_RINGCTRL_RINGADDR_SHIFT              (8U)
/*! RINGADDR - RINGADDR */
#define NPU_RINGCTRL_RINGADDR(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_RINGCTRL_RINGADDR_SHIFT)) & NPU_RINGCTRL_RINGADDR_MASK)
/*! @} */

/*! @name TAIL - Tail of ring buffer written by Zen-V */
/*! @{ */

#define NPU_TAIL_TAIL_MASK                       (0xFFFFU)
#define NPU_TAIL_TAIL_SHIFT                      (0U)
/*! TAIL - TAIL */
#define NPU_TAIL_TAIL(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_TAIL_TAIL_SHIFT)) & NPU_TAIL_TAIL_MASK)
/*! @} */

/*! @name HEAD - Head of ring buffer written by SoC */
/*! @{ */

#define NPU_HEAD_HEAD_MASK                       (0xFFFFU)
#define NPU_HEAD_HEAD_SHIFT                      (0U)
/*! HEAD - HEAD */
#define NPU_HEAD_HEAD(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_HEAD_HEAD_SHIFT)) & NPU_HEAD_HEAD_MASK)
/*! @} */

/*! @name MBOX - Mailboxes For SoC/Zen-V Communications */
/*! @{ */

#define NPU_MBOX_MBOX_MASK                       (0xFFFFFFFFU)
#define NPU_MBOX_MBOX_SHIFT                      (0U)
/*! MBOX - Mailbox */
#define NPU_MBOX_MBOX(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_MBOX_MBOX_SHIFT)) & NPU_MBOX_MBOX_MASK)
/*! @} */

/*! @name BASEINOUTL - Base physical address for Input/Output fetch/push */
/*! @{ */

#define NPU_BASEINOUTL_LIMITMB_MASK              (0x1FF00U)
#define NPU_BASEINOUTL_LIMITMB_SHIFT             (8U)
/*! LIMITMB - LIMITMB */
#define NPU_BASEINOUTL_LIMITMB(x)                (((uint32_t)(((uint32_t)(x)) << NPU_BASEINOUTL_LIMITMB_SHIFT)) & NPU_BASEINOUTL_LIMITMB_MASK)

#define NPU_BASEINOUTL_BASEINOUTL_MASK           (0xFFF00000U)
#define NPU_BASEINOUTL_BASEINOUTL_SHIFT          (20U)
/*! BASEINOUTL - BASESPILLL */
#define NPU_BASEINOUTL_BASEINOUTL(x)             (((uint32_t)(((uint32_t)(x)) << NPU_BASEINOUTL_BASEINOUTL_SHIFT)) & NPU_BASEINOUTL_BASEINOUTL_MASK)
/*! @} */

/*! @name BASEINOUTH - Base physical address for Spill fetch/push */
/*! @{ */

#define NPU_BASEINOUTH_BASEINOUTH_1_MASK         (0x1FFFFU)
#define NPU_BASEINOUTH_BASEINOUTH_1_SHIFT        (0U)
/*! BASEINOUTH_1 - BASEINOUTH */
#define NPU_BASEINOUTH_BASEINOUTH_1(x)           (((uint32_t)(((uint32_t)(x)) << NPU_BASEINOUTH_BASEINOUTH_1_SHIFT)) & NPU_BASEINOUTH_BASEINOUTH_1_MASK)
/*! @} */

/*! @name BASESPILLL - Base physical address for Spill fetch/push */
/*! @{ */

#define NPU_BASESPILLL_SPLITPRIV_MASK            (0x1U)
#define NPU_BASESPILLL_SPLITPRIV_SHIFT           (0U)
/*! SPLITPRIV - SPLITPRIV */
#define NPU_BASESPILLL_SPLITPRIV(x)              (((uint32_t)(((uint32_t)(x)) << NPU_BASESPILLL_SPLITPRIV_SHIFT)) & NPU_BASESPILLL_SPLITPRIV_MASK)

#define NPU_BASESPILLL_LIMITMB_MASK              (0x1FF00U)
#define NPU_BASESPILLL_LIMITMB_SHIFT             (8U)
/*! LIMITMB - LIMITMB */
#define NPU_BASESPILLL_LIMITMB(x)                (((uint32_t)(((uint32_t)(x)) << NPU_BASESPILLL_LIMITMB_SHIFT)) & NPU_BASESPILLL_LIMITMB_MASK)

#define NPU_BASESPILLL_BASESPILLL_MASK           (0xFFF00000U)
#define NPU_BASESPILLL_BASESPILLL_SHIFT          (20U)
/*! BASESPILLL - BASESPILLL */
#define NPU_BASESPILLL_BASESPILLL(x)             (((uint32_t)(((uint32_t)(x)) << NPU_BASESPILLL_BASESPILLL_SHIFT)) & NPU_BASESPILLL_BASESPILLL_MASK)
/*! @} */

/*! @name BASESPILLH - Base physical address for Spill fetch/push */
/*! @{ */

#define NPU_BASESPILLH_BASESPILLH_MASK           (0x1FFFFU)
#define NPU_BASESPILLH_BASESPILLH_SHIFT          (0U)
/*! BASESPILLH - BASESPILLH */
#define NPU_BASESPILLH_BASESPILLH(x)             (((uint32_t)(((uint32_t)(x)) << NPU_BASESPILLH_BASESPILLH_SHIFT)) & NPU_BASESPILLH_BASESPILLH_MASK)
/*! @} */

/*! @name DECOMPCTRL - Control For Weight Decompressor */
/*! @{ */

#define NPU_DECOMPCTRL_ENABLE_MASK               (0x1U)
#define NPU_DECOMPCTRL_ENABLE_SHIFT              (0U)
/*! ENABLE - Enable */
#define NPU_DECOMPCTRL_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPCTRL_ENABLE_SHIFT)) & NPU_DECOMPCTRL_ENABLE_MASK)

#define NPU_DECOMPCTRL_BYPASS_MASK               (0x2U)
#define NPU_DECOMPCTRL_BYPASS_SHIFT              (1U)
/*! BYPASS - Bypass */
#define NPU_DECOMPCTRL_BYPASS(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPCTRL_BYPASS_SHIFT)) & NPU_DECOMPCTRL_BYPASS_MASK)

#define NPU_DECOMPCTRL_NEW_META_MASK             (0x30U)
#define NPU_DECOMPCTRL_NEW_META_SHIFT            (4U)
/*! NEW_META - NEW_META */
#define NPU_DECOMPCTRL_NEW_META(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPCTRL_NEW_META_SHIFT)) & NPU_DECOMPCTRL_NEW_META_MASK)

#define NPU_DECOMPCTRL_NEW_GROUP_MASK            (0x100U)
#define NPU_DECOMPCTRL_NEW_GROUP_SHIFT           (8U)
/*! NEW_GROUP - NEW_GROUP */
#define NPU_DECOMPCTRL_NEW_GROUP(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPCTRL_NEW_GROUP_SHIFT)) & NPU_DECOMPCTRL_NEW_GROUP_MASK)

#define NPU_DECOMPCTRL_SKIP_LEN_MASK             (0xFFF00000U)
#define NPU_DECOMPCTRL_SKIP_LEN_SHIFT            (20U)
/*! SKIP_LEN - Skip Length */
#define NPU_DECOMPCTRL_SKIP_LEN(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPCTRL_SKIP_LEN_SHIFT)) & NPU_DECOMPCTRL_SKIP_LEN_MASK)
/*! @} */

/*! @name DECOMPSTAT - Weight Decompressor Status */
/*! @{ */

#define NPU_DECOMPSTAT_DONE_MASK                 (0x1U)
#define NPU_DECOMPSTAT_DONE_SHIFT                (0U)
/*! DONE - DONE */
#define NPU_DECOMPSTAT_DONE(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPSTAT_DONE_SHIFT)) & NPU_DECOMPSTAT_DONE_MASK)

#define NPU_DECOMPSTAT_ACTIVE_MASK               (0x2U)
#define NPU_DECOMPSTAT_ACTIVE_SHIFT              (1U)
/*! ACTIVE - ACTIVE */
#define NPU_DECOMPSTAT_ACTIVE(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPSTAT_ACTIVE_SHIFT)) & NPU_DECOMPSTAT_ACTIVE_MASK)

#define NPU_DECOMPSTAT_ERR_DECOMP_MASK           (0x4U)
#define NPU_DECOMPSTAT_ERR_DECOMP_SHIFT          (2U)
/*! ERR_DECOMP - ERR_DECOMP */
#define NPU_DECOMPSTAT_ERR_DECOMP(x)             (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPSTAT_ERR_DECOMP_SHIFT)) & NPU_DECOMPSTAT_ERR_DECOMP_MASK)

#define NPU_DECOMPSTAT_ERR_BUS_MASK              (0x8U)
#define NPU_DECOMPSTAT_ERR_BUS_SHIFT             (3U)
/*! ERR_BUS - ERR_BUS */
#define NPU_DECOMPSTAT_ERR_BUS(x)                (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPSTAT_ERR_BUS_SHIFT)) & NPU_DECOMPSTAT_ERR_BUS_MASK)

#define NPU_DECOMPSTAT_ERR_OVER_MASK             (0x10U)
#define NPU_DECOMPSTAT_ERR_OVER_SHIFT            (4U)
/*! ERR_OVER - ERR_OVER */
#define NPU_DECOMPSTAT_ERR_OVER(x)               (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPSTAT_ERR_OVER_SHIFT)) & NPU_DECOMPSTAT_ERR_OVER_MASK)

#define NPU_DECOMPSTAT_ERR_UNDER_MASK            (0x20U)
#define NPU_DECOMPSTAT_ERR_UNDER_SHIFT           (5U)
/*! ERR_UNDER - ERR_UNDER */
#define NPU_DECOMPSTAT_ERR_UNDER(x)              (((uint32_t)(((uint32_t)(x)) << NPU_DECOMPSTAT_ERR_UNDER_SHIFT)) & NPU_DECOMPSTAT_ERR_UNDER_MASK)
/*! @} */

/*! @name GROUP_BASE - DDR offset from base for Weight Decompressor */
/*! @{ */

#define NPU_GROUP_BASE_OFFSET_MASK               (0x7FFFFFF0U)
#define NPU_GROUP_BASE_OFFSET_SHIFT              (4U)
/*! OFFSET - OFFSET */
#define NPU_GROUP_BASE_OFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_GROUP_BASE_OFFSET_SHIFT)) & NPU_GROUP_BASE_OFFSET_MASK)
/*! @} */

/*! @name GROUP_LEN - Weight Decompressor Group Length */
/*! @{ */

#define NPU_GROUP_LEN_LEN_MASK                   (0x3FFF0U)
#define NPU_GROUP_LEN_LEN_SHIFT                  (4U)
/*! LEN - LEN */
#define NPU_GROUP_LEN_LEN(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_GROUP_LEN_LEN_SHIFT)) & NPU_GROUP_LEN_LEN_MASK)
/*! @} */

/*! @name CRYPTO - Cryptographic Protection Control */
/*! @{ */

#define NPU_CRYPTO_CRYPTOLOCK_MASK               (0x1U)
#define NPU_CRYPTO_CRYPTOLOCK_SHIFT              (0U)
/*! CRYPTOLOCK - CRYPTOLOCK
 *  0b0..Access to ITCM, DTCM, and NTCM is allowed.
 *  0b1..Access to ITCM, DTCM, and NTCM is prohibited.
 */
#define NPU_CRYPTO_CRYPTOLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_CRYPTO_CRYPTOLOCK_SHIFT)) & NPU_CRYPTO_CRYPTOLOCK_MASK)

#define NPU_CRYPTO_DBGLOCK_MASK                  (0x2U)
#define NPU_CRYPTO_DBGLOCK_SHIFT                 (1U)
/*! DBGLOCK - DBGLOCK */
#define NPU_CRYPTO_DBGLOCK(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CRYPTO_DBGLOCK_SHIFT)) & NPU_CRYPTO_DBGLOCK_MASK)

#define NPU_CRYPTO_PCLOCK_MASK                   (0x4U)
#define NPU_CRYPTO_PCLOCK_SHIFT                  (2U)
/*! PCLOCK - PCLOCK */
#define NPU_CRYPTO_PCLOCK(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_CRYPTO_PCLOCK_SHIFT)) & NPU_CRYPTO_PCLOCK_MASK)

#define NPU_CRYPTO_CRYPTOMODEL_MASK              (0x100U)
#define NPU_CRYPTO_CRYPTOMODEL_SHIFT             (8U)
/*! CRYPTOMODEL - CRYPTOMODEL */
#define NPU_CRYPTO_CRYPTOMODEL(x)                (((uint32_t)(((uint32_t)(x)) << NPU_CRYPTO_CRYPTOMODEL_SHIFT)) & NPU_CRYPTO_CRYPTOMODEL_MASK)

#define NPU_CRYPTO_ZERORAM_MASK                  (0x200U)
#define NPU_CRYPTO_ZERORAM_SHIFT                 (9U)
/*! ZERORAM - ZERORAM */
#define NPU_CRYPTO_ZERORAM(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CRYPTO_ZERORAM_SHIFT)) & NPU_CRYPTO_ZERORAM_MASK)
/*! @} */

/*! @name PRIVDDRL - Physical address in DDR of model when secure */
/*! @{ */

#define NPU_PRIVDDRL_SPLITPRIV_MASK              (0x1U)
#define NPU_PRIVDDRL_SPLITPRIV_SHIFT             (0U)
/*! SPLITPRIV - SPLITPRIV */
#define NPU_PRIVDDRL_SPLITPRIV(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PRIVDDRL_SPLITPRIV_SHIFT)) & NPU_PRIVDDRL_SPLITPRIV_MASK)

#define NPU_PRIVDDRL_LIMITMB_MASK                (0x1FF00U)
#define NPU_PRIVDDRL_LIMITMB_SHIFT               (8U)
/*! LIMITMB - LIMITMB */
#define NPU_PRIVDDRL_LIMITMB(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_PRIVDDRL_LIMITMB_SHIFT)) & NPU_PRIVDDRL_LIMITMB_MASK)

#define NPU_PRIVDDRL_PRIVDDRL_MASK               (0xFFF00000U)
#define NPU_PRIVDDRL_PRIVDDRL_SHIFT              (20U)
/*! PRIVDDRL - PRIVDDRL */
#define NPU_PRIVDDRL_PRIVDDRL(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_PRIVDDRL_PRIVDDRL_SHIFT)) & NPU_PRIVDDRL_PRIVDDRL_MASK)
/*! @} */

/*! @name PRIVDDRH - Physical address in DDR of model when secure */
/*! @{ */

#define NPU_PRIVDDRH_BASEDDRH1_MASK              (0x1FFFFU)
#define NPU_PRIVDDRH_BASEDDRH1_SHIFT             (0U)
/*! BASEDDRH1 - BASEDDRH */
#define NPU_PRIVDDRH_BASEDDRH1(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PRIVDDRH_BASEDDRH1_SHIFT)) & NPU_PRIVDDRH_BASEDDRH1_MASK)

#define NPU_PRIVDDRH_BASEDDRH2_MASK              (0x20000U)
#define NPU_PRIVDDRH_BASEDDRH2_SHIFT             (17U)
/*! BASEDDRH2 - BASEDDRH */
#define NPU_PRIVDDRH_BASEDDRH2(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PRIVDDRH_BASEDDRH2_SHIFT)) & NPU_PRIVDDRH_BASEDDRH2_MASK)
/*! @} */

/*! @name SESSIONIV - Unique IV for Protected models */
/*! @{ */

#define NPU_SESSIONIV_NONCE_MASK                 (0xFFFFFFFFU)
#define NPU_SESSIONIV_NONCE_SHIFT                (0U)
/*! NONCE - NONCE */
#define NPU_SESSIONIV_NONCE(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_SESSIONIV_NONCE_SHIFT)) & NPU_SESSIONIV_NONCE_MASK)
/*! @} */

/*! @name INFCOUNT - Inference count */
/*! @{ */

#define NPU_INFCOUNT_COUNT_MASK                  (0xFFFFFFFFU)
#define NPU_INFCOUNT_COUNT_SHIFT                 (0U)
/*! COUNT - COUNT */
#define NPU_INFCOUNT_COUNT(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_INFCOUNT_COUNT_SHIFT)) & NPU_INFCOUNT_COUNT_MASK)
/*! @} */

/*! @name FLAYERNUM - Layer number for Fetch */
/*! @{ */

#define NPU_FLAYERNUM_NUM_MASK                   (0xFFFFU)
#define NPU_FLAYERNUM_NUM_SHIFT                  (0U)
/*! NUM - NUM */
#define NPU_FLAYERNUM_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_FLAYERNUM_NUM_SHIFT)) & NPU_FLAYERNUM_NUM_MASK)
/*! @} */

/*! @name PLAYERNUM - Layer number for Push */
/*! @{ */

#define NPU_PLAYERNUM_NUM_MASK                   (0xFFFFU)
#define NPU_PLAYERNUM_NUM_SHIFT                  (0U)
/*! NUM - NUM */
#define NPU_PLAYERNUM_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_PLAYERNUM_NUM_SHIFT)) & NPU_PLAYERNUM_NUM_MASK)
/*! @} */

/*! @name AXIOPT - Boot SoC setting for AXI optimization */
/*! @{ */

#define NPU_AXIOPT_ARLEN_MASK                    (0xFFU)
#define NPU_AXIOPT_ARLEN_SHIFT                   (0U)
/*! ARLEN - ARLEN */
#define NPU_AXIOPT_ARLEN(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_AXIOPT_ARLEN_SHIFT)) & NPU_AXIOPT_ARLEN_MASK)

#define NPU_AXIOPT_AWLEN_MASK                    (0xFF00U)
#define NPU_AXIOPT_AWLEN_SHIFT                   (8U)
/*! AWLEN - AWLEN */
#define NPU_AXIOPT_AWLEN(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_AXIOPT_AWLEN_SHIFT)) & NPU_AXIOPT_AWLEN_MASK)

#define NPU_AXIOPT_ARTRIG_MASK                   (0xFF0000U)
#define NPU_AXIOPT_ARTRIG_SHIFT                  (16U)
/*! ARTRIG - ARTRIG */
#define NPU_AXIOPT_ARTRIG(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_AXIOPT_ARTRIG_SHIFT)) & NPU_AXIOPT_ARTRIG_MASK)

#define NPU_AXIOPT_USEOT_MASK                    (0x1000000U)
#define NPU_AXIOPT_USEOT_SHIFT                   (24U)
/*! USEOT - Use Out Standing */
#define NPU_AXIOPT_USEOT(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_AXIOPT_USEOT_SHIFT)) & NPU_AXIOPT_USEOT_MASK)

#define NPU_AXIOPT_RRDCNT_MASK                   (0xF0000000U)
#define NPU_AXIOPT_RRDCNT_SHIFT                  (28U)
/*! RRDCNT - ARTRIG */
#define NPU_AXIOPT_RRDCNT(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_AXIOPT_RRDCNT_SHIFT)) & NPU_AXIOPT_RRDCNT_MASK)
/*! @} */

/*! @name V2P_DATA - Virtual to Physical registers */
/*! @{ */

#define NPU_V2P_DATA_D_VMAP0_MASK                (0x3FU)
#define NPU_V2P_DATA_D_VMAP0_SHIFT               (0U)
/*! D_VMAP0 - VMAP0 */
#define NPU_V2P_DATA_D_VMAP0(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_VMAP0_SHIFT)) & NPU_V2P_DATA_D_VMAP0_MASK)

#define NPU_V2P_DATA_D_WRUPD0_MASK               (0x80U)
#define NPU_V2P_DATA_D_WRUPD0_SHIFT              (7U)
/*! D_WRUPD0 - WRUPD0 */
#define NPU_V2P_DATA_D_WRUPD0(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_WRUPD0_SHIFT)) & NPU_V2P_DATA_D_WRUPD0_MASK)

#define NPU_V2P_DATA_D_VMAP1_MASK                (0x3F00U)
#define NPU_V2P_DATA_D_VMAP1_SHIFT               (8U)
/*! D_VMAP1 - VMAP1 */
#define NPU_V2P_DATA_D_VMAP1(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_VMAP1_SHIFT)) & NPU_V2P_DATA_D_VMAP1_MASK)

#define NPU_V2P_DATA_D_WRUPD1_MASK               (0x8000U)
#define NPU_V2P_DATA_D_WRUPD1_SHIFT              (15U)
/*! D_WRUPD1 - WRUPD1 */
#define NPU_V2P_DATA_D_WRUPD1(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_WRUPD1_SHIFT)) & NPU_V2P_DATA_D_WRUPD1_MASK)

#define NPU_V2P_DATA_D_VMAP2_MASK                (0x3F0000U)
#define NPU_V2P_DATA_D_VMAP2_SHIFT               (16U)
/*! D_VMAP2 - VMAP2 */
#define NPU_V2P_DATA_D_VMAP2(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_VMAP2_SHIFT)) & NPU_V2P_DATA_D_VMAP2_MASK)

#define NPU_V2P_DATA_D_WRUP2_MASK                (0x800000U)
#define NPU_V2P_DATA_D_WRUP2_SHIFT               (23U)
/*! D_WRUP2 - WRUP2 */
#define NPU_V2P_DATA_D_WRUP2(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_WRUP2_SHIFT)) & NPU_V2P_DATA_D_WRUP2_MASK)

#define NPU_V2P_DATA_D_VMAP3_MASK                (0x3F000000U)
#define NPU_V2P_DATA_D_VMAP3_SHIFT               (24U)
/*! D_VMAP3 - VMAP3 */
#define NPU_V2P_DATA_D_VMAP3(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_VMAP3_SHIFT)) & NPU_V2P_DATA_D_VMAP3_MASK)

#define NPU_V2P_DATA_D_WRUPD3_MASK               (0x80000000U)
#define NPU_V2P_DATA_D_WRUPD3_SHIFT              (31U)
/*! D_WRUPD3 - WRUPD3 */
#define NPU_V2P_DATA_D_WRUPD3(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_V2P_DATA_D_WRUPD3_SHIFT)) & NPU_V2P_DATA_D_WRUPD3_MASK)
/*! @} */

/*! @name V2P_WEIGHTS - Virtual to Physical registers */
/*! @{ */

#define NPU_V2P_WEIGHTS_W_VMAP0_MASK             (0x3FU)
#define NPU_V2P_WEIGHTS_W_VMAP0_SHIFT            (0U)
/*! W_VMAP0 - VMAP0 */
#define NPU_V2P_WEIGHTS_W_VMAP0(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_VMAP0_SHIFT)) & NPU_V2P_WEIGHTS_W_VMAP0_MASK)

#define NPU_V2P_WEIGHTS_W_WRUPD0_MASK            (0x80U)
#define NPU_V2P_WEIGHTS_W_WRUPD0_SHIFT           (7U)
/*! W_WRUPD0 - WRUPD0 */
#define NPU_V2P_WEIGHTS_W_WRUPD0(x)              (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_WRUPD0_SHIFT)) & NPU_V2P_WEIGHTS_W_WRUPD0_MASK)

#define NPU_V2P_WEIGHTS_W_VMAP1_MASK             (0x3F00U)
#define NPU_V2P_WEIGHTS_W_VMAP1_SHIFT            (8U)
/*! W_VMAP1 - VMAP1 */
#define NPU_V2P_WEIGHTS_W_VMAP1(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_VMAP1_SHIFT)) & NPU_V2P_WEIGHTS_W_VMAP1_MASK)

#define NPU_V2P_WEIGHTS_W_WRUPD1_MASK            (0x8000U)
#define NPU_V2P_WEIGHTS_W_WRUPD1_SHIFT           (15U)
/*! W_WRUPD1 - WRUPD1 */
#define NPU_V2P_WEIGHTS_W_WRUPD1(x)              (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_WRUPD1_SHIFT)) & NPU_V2P_WEIGHTS_W_WRUPD1_MASK)

#define NPU_V2P_WEIGHTS_W_VMAP2_MASK             (0x3F0000U)
#define NPU_V2P_WEIGHTS_W_VMAP2_SHIFT            (16U)
/*! W_VMAP2 - VMAP2 */
#define NPU_V2P_WEIGHTS_W_VMAP2(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_VMAP2_SHIFT)) & NPU_V2P_WEIGHTS_W_VMAP2_MASK)

#define NPU_V2P_WEIGHTS_W_WRUP2_MASK             (0x800000U)
#define NPU_V2P_WEIGHTS_W_WRUP2_SHIFT            (23U)
/*! W_WRUP2 - WRUP2 */
#define NPU_V2P_WEIGHTS_W_WRUP2(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_WRUP2_SHIFT)) & NPU_V2P_WEIGHTS_W_WRUP2_MASK)

#define NPU_V2P_WEIGHTS_W_VMAP3_MASK             (0x3F000000U)
#define NPU_V2P_WEIGHTS_W_VMAP3_SHIFT            (24U)
/*! W_VMAP3 - VMAP3 */
#define NPU_V2P_WEIGHTS_W_VMAP3(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_VMAP3_SHIFT)) & NPU_V2P_WEIGHTS_W_VMAP3_MASK)

#define NPU_V2P_WEIGHTS_W_WRUPD3_MASK            (0x80000000U)
#define NPU_V2P_WEIGHTS_W_WRUPD3_SHIFT           (31U)
/*! W_WRUPD3 - WRUPD3 */
#define NPU_V2P_WEIGHTS_W_WRUPD3(x)              (((uint32_t)(((uint32_t)(x)) << NPU_V2P_WEIGHTS_W_WRUPD3_SHIFT)) & NPU_V2P_WEIGHTS_W_WRUPD3_MASK)
/*! @} */

/*! @name V2P_RESULTS - Virtual to Physical registers */
/*! @{ */

#define NPU_V2P_RESULTS_R_VMAP0_MASK             (0x3FU)
#define NPU_V2P_RESULTS_R_VMAP0_SHIFT            (0U)
/*! R_VMAP0 - VMAP0 */
#define NPU_V2P_RESULTS_R_VMAP0(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_VMAP0_SHIFT)) & NPU_V2P_RESULTS_R_VMAP0_MASK)

#define NPU_V2P_RESULTS_R_WRUPD0_MASK            (0x80U)
#define NPU_V2P_RESULTS_R_WRUPD0_SHIFT           (7U)
/*! R_WRUPD0 - WRUPD0 */
#define NPU_V2P_RESULTS_R_WRUPD0(x)              (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_WRUPD0_SHIFT)) & NPU_V2P_RESULTS_R_WRUPD0_MASK)

#define NPU_V2P_RESULTS_R_VMAP1_MASK             (0x3F00U)
#define NPU_V2P_RESULTS_R_VMAP1_SHIFT            (8U)
/*! R_VMAP1 - VMAP1 */
#define NPU_V2P_RESULTS_R_VMAP1(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_VMAP1_SHIFT)) & NPU_V2P_RESULTS_R_VMAP1_MASK)

#define NPU_V2P_RESULTS_R_WRUPD1_MASK            (0x8000U)
#define NPU_V2P_RESULTS_R_WRUPD1_SHIFT           (15U)
/*! R_WRUPD1 - WRUPD1 */
#define NPU_V2P_RESULTS_R_WRUPD1(x)              (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_WRUPD1_SHIFT)) & NPU_V2P_RESULTS_R_WRUPD1_MASK)

#define NPU_V2P_RESULTS_R_VMAP2_MASK             (0x3F0000U)
#define NPU_V2P_RESULTS_R_VMAP2_SHIFT            (16U)
/*! R_VMAP2 - VMAP2 */
#define NPU_V2P_RESULTS_R_VMAP2(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_VMAP2_SHIFT)) & NPU_V2P_RESULTS_R_VMAP2_MASK)

#define NPU_V2P_RESULTS_R_WRUP2_MASK             (0x800000U)
#define NPU_V2P_RESULTS_R_WRUP2_SHIFT            (23U)
/*! R_WRUP2 - WRUP2 */
#define NPU_V2P_RESULTS_R_WRUP2(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_WRUP2_SHIFT)) & NPU_V2P_RESULTS_R_WRUP2_MASK)

#define NPU_V2P_RESULTS_R_VMAP3_MASK             (0x3F000000U)
#define NPU_V2P_RESULTS_R_VMAP3_SHIFT            (24U)
/*! R_VMAP3 - VMAP3 */
#define NPU_V2P_RESULTS_R_VMAP3(x)               (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_VMAP3_SHIFT)) & NPU_V2P_RESULTS_R_VMAP3_MASK)

#define NPU_V2P_RESULTS_R_WRUPD3_MASK            (0x80000000U)
#define NPU_V2P_RESULTS_R_WRUPD3_SHIFT           (31U)
/*! R_WRUPD3 - WRUPD3 */
#define NPU_V2P_RESULTS_R_WRUPD3(x)              (((uint32_t)(((uint32_t)(x)) << NPU_V2P_RESULTS_R_WRUPD3_SHIFT)) & NPU_V2P_RESULTS_R_WRUPD3_MASK)
/*! @} */

/*! @name LISTEN - Listener Mode Enable */
/*! @{ */

#define NPU_LISTEN_MODE_MASK                     (0x3U)
#define NPU_LISTEN_MODE_SHIFT                    (0U)
/*! MODE - Mode
 *  0b00..None. No listener mode
 *  0b01..Data listening
 *  0b10..Weight listening
 */
#define NPU_LISTEN_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_LISTEN_MODE_SHIFT)) & NPU_LISTEN_MODE_MASK)

#define NPU_LISTEN_LISTENER1_MASK                (0x20U)
#define NPU_LISTEN_LISTENER1_SHIFT               (5U)
/*! LISTENER1 - Listener 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_LISTEN_LISTENER1(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_LISTEN_LISTENER1_SHIFT)) & NPU_LISTEN_LISTENER1_MASK)

#define NPU_LISTEN_LISTENER2_MASK                (0x40U)
#define NPU_LISTEN_LISTENER2_SHIFT               (6U)
/*! LISTENER2 - Listener 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_LISTEN_LISTENER2(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_LISTEN_LISTENER2_SHIFT)) & NPU_LISTEN_LISTENER2_MASK)

#define NPU_LISTEN_LISTENER3_MASK                (0x80U)
#define NPU_LISTEN_LISTENER3_SHIFT               (7U)
/*! LISTENER3 - Listener 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_LISTEN_LISTENER3(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_LISTEN_LISTENER3_SHIFT)) & NPU_LISTEN_LISTENER3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NPU_Register_Masks */


/*!
 * @}
 */ /* end of group NPU_Peripheral_Access_Layer */


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


#endif  /* PERI_NPU_H_ */

