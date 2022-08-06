/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_SPECIFIC_H
#define CLOCK_IP_SPECIFIC_H

/**
*   @file    Clock_Ip_Specific.h
*   @version    0.8.0
*
*   @brief   CLOCK IP specific header file.
*   @details CLOCK IP specific header file.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Clock_Ip_Cfg_Defines.h"
#include "Mcal.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SPECIFIC_VENDOR_ID                       43
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION        4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION                0
#define CLOCK_IP_SPECIFIC_SW_MINOR_VERSION                8
#define CLOCK_IP_SPECIFIC_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file have same versions */
#if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_CFG_DEFINES_VENDOR_ID)
    #error "Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Specific.h file and Mcal.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define CLOCK_IP_DIVIDER_CALLBACKS_COUNT                                               4U
#define CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE                                       1U
#define CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE_WITH_TRIGGER                          2U
#define CLOCK_IP_PLLDIG_PLL0DIV_DE_DIV_OUTPUT                                          3U

#define CLOCK_IP_DIVIDERTRIGGER_CALLBACKS_COUNT                                        2U
#define CLOCK_IP_CGM_X_DIV_TRIG_CTRL_TCTL_HHEN_UPD_STAT                                1U

#define CLOCK_IP_XOSC_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_FXOSC_OSCON_BYP_EOCV_GM_SEL                                           1U

#define CLOCK_IP_IRCOSC_CALLBACKS_COUNT                                                1U

#define CLOCK_IP_GATE_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_CONTROL_ENABLE_GPR_PCTL                                         1U

#define CLOCK_IP_FRACTIONAL_DIVIDER_CALLBACKS_COUNT                                    2U
#define CLOCK_IP_DFS_MFI_MFN                                                           1U
#define CLOCK_IP_NUMBER_OF_HARDWARE_DFS                                                12U

#define CLOCK_IP_PLL_CALLBACKS_COUNT                                                   3U
#define CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE           1U
#define CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN                                             2U
#define CLOCK_IP_NUMBER_OF_HARDWARE_PLL                                                3U

#define CLOCK_IP_SELECTOR_CALLBACKS_COUNT                                              2U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP                                             1U

#define CLOCK_IP_PCFS_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS                                        1U

#define CLOCK_IP_CMU_CALLBACKS_COUNT                                                   2U
#define CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF                                        1U

#define CLOCK_IP_ALL_CALLBACKS_COUNT                                                   8U

#define CLOCK_IP_TRIGGER_VALUE               0xFFFFFFFFU              /* Trigger value. */

#define DFS_PORTSR_PORTSTAT_MASK                  (DFS_PORTSR_PORTSTAT5_MASK | DFS_PORTSR_PORTSTAT4_MASK | DFS_PORTSR_PORTSTAT3_MASK | DFS_PORTSR_PORTSTAT2_MASK | DFS_PORTSR_PORTSTAT1_MASK | DFS_PORTSR_PORTSTAT0_MASK)
#define DFS_PORTSR_PORTSTAT_SHIFT                 (DFS_PORTSR_PORTSTAT0_SHIFT)

#define MC_ME_AE_TRANSITION_IS_ON_GOING            MC_ME_AE_GS_S_MTRANS_MASK

#define CLOCK_IP_MC_CGM_MUX_MUX_DIV_COUNT                  11u
#define CLOCK_IP_MC_CGM_PCFS_COUNT                         64u
#define CLOCK_IP_PERIPHERALS_NO                            64u

#define CLOCK_IP_MC_CGM_INSTANCES_COUNT      10U
#define CLOCK_IP_MC_CGM_MUXS_COUNT           15U
#define CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE   1U
#define CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE    3U
#define CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE    2U
#define CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE    27U
#define CLOCK_IP_PERIPHERAL_GROUPS_COUNT     7U
#define CLOCK_IP_CMU_INFO_SIZE               28U
#define CLOCK_IP_GATE_INFO_SIZE              80U
#define CLOCK_IP_EXTENSIONS_SIZE             133U



#define MC_CGM_MUX_DC_DE_MASK                MC_CGM_MUX_0_DC_0_DE_MASK
#define MC_CGM_MUX_DC_DE_SHIFT               MC_CGM_MUX_0_DC_0_DE_SHIFT
#define MC_CGM_MUX_CSC_SAFE_SW_MASK          MC_CGM_MUX_0_CSS_SAFE_SW_MASK
#define MC_CGM_MUX_CSC_CLK_SW_MASK           MC_CGM_MUX_0_CSC_CLK_SW_MASK
#define MC_CGM_MUX_CSC_RAMPUP_MASK           MC_CGM_MUX_0_CSC_RAMPUP_MASK
#define MC_CGM_MUX_CSC_RAMPDOWN_MASK         MC_CGM_MUX_0_CSC_RAMPDOWN_MASK
#define MC_CGM_MUX_CSS_SWIP_MASK             MC_CGM_MUX_0_CSS_SWIP_MASK
#define MC_CGM_MUX_CSS_SWIP_IN_PROGRESS      MC_CGM_MUX_CSS_SWIP_MASK
#define MC_CGM_MUX_CSS_SWTRG_MASK            MC_CGM_MUX_0_CSS_SWTRG_MASK
#define MC_CGM_MUX_CSS_SWTRG_SHIFT           MC_CGM_MUX_0_CSS_SWTRG_SHIFT
#define CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED       1U
#define MC_CGM_MUX_CSS_CLK_SW_MASK           MC_CGM_MUX_0_CSS_CLK_SW_MASK
#define CLOCK_IP_MC_CGM_MUX_CSS_CLK_SW_NOT_REQUESTED  0U

/* Some macro did not available in S32ZSE, define it as 0 value to avoid build fail, will be remove after */ 
#define MC_CGM_MUX_CSC_CG_MASK               0U
#define MC_CGM_MUX_CSC_FCG_MASK              0U
#define MC_CGM_MUX_CSS_CS_MASK               0U
#define MC_CGM_MUX_CSS_CS_TRANSPARENT        0U

#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_PENDING MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_MUX_DIV_TRIG_CTRL_TCTL_MASK   MC_CGM_MUX_7_DIV_TRIG_CTRL_TCTL_MASK
#define MC_CGM_MUX_DIV_TRIG_TRIGGER(x)       MC_CGM_MUX_7_DIV_TRIG_CTRL_TCTL(x)
#define MC_CGM_MUX_DIV_TRIG_CTRL_COMMON_TRIGGER_DIVIDER_UPDATE   MC_CGM_MUX_DIV_TRIG_CTRL_TCTL_MASK


#define MC_CGM_PCFS_DIVC_INIT(x)             MC_CGM_PCFS_DIVC12_INIT(x)
#define MC_CGM_PCFS_DIVC_RATE(x)             MC_CGM_PCFS_DIVC12_RATE(x)
#define MC_CGM_PCFS_DIVE_DIVE(x)             MC_CGM_PCFS_DIVE12_DIVE(x)
#define MC_CGM_PCFS_DIVS_DIVS(x)             MC_CGM_PCFS_DIVS12_DIVS(x)

#define CLOCK_IP_CMU_FREQUENCY_CHECK_ENABLED          CMU_FC_GCR_FCE_MASK
#define CLOCK_IP_CMU_FREQUENCY_CHECK_STOPPED          0U
#define CLOCK_IP_CMU_ISR_MASK                         3U

#define GPR_PCTL_MASK                        GPR3_PCTL_EDMACEPCTL_PCTL_MASK

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct {
  uint32 CSC;                                      /**< Clock Mux Select Control Register */
  const  uint32 CSS;                               /**< Clock Mux Select Status Register */
  uint32 Divider[CLOCK_IP_MC_CGM_MUX_MUX_DIV_COUNT];        /**< Clock Divider Control Register */
  uint32 MUX_DIV_TRIG_CTRL;                        /**< Clock Divider trigger Control Register */
  uint32 MUX_DIV_TRIG;                             /**< Clock Divider trigger Register */
  const  uint32 MUX_DIV_UPD_STAT;                  /**< Clock Divider Update Status Register */

}volatile Clock_Ip_CgmMuxType;

typedef struct {

    uint32 PCFS_SDUR;                           /**< PCFS Step Duration, offset: 0x0 */
    struct {                                    /* offset: 0x4, array step: 0xC */
      uint32 DIVC;                              /**< PCFS Divider Change 12 Register, array offset: 0x4, array step: 0xC */
      uint32 DIVE;                              /**< PCFS Divider End 12 Register, array offset: 0x8, array step: 0xC */
      uint32 DIVS;                              /**< PCFS Divider Start 12 Register, array offset: 0xC, array step: 0xC */
    } PCFS[CLOCK_IP_MC_CGM_PCFS_COUNT];

}Clock_Ip_CgmPcfsType;

typedef struct {
    volatile uint32 PCTL[CLOCK_IP_PERIPHERALS_NO];
}Clock_Ip_GprClockControlEnable_Type;

/** MC_ME_AE - Register Layout Typedef */
typedef struct {
    uint32_t POWER_MODE_CONFIG[3u];                           /**< Power Mode Configuration, offset: 0x28, 0x2C and 0x30 */
}volatile Clock_Ip_SystemClockType;


/** XOSC - Register Layout Typedef */
typedef struct {
    uint32 CTRL;                        /**< XOSC Control Register, offset: 0x0 */
    const  uint32 STAT;                        /**< Oscillator Status Register, offset: 0x4 */
}volatile Clock_Ip_ExtOSCType;

/** CMU - Register Layout Typedef */
typedef struct {
    uint32 GCR;                               /**< Global Configuration Register, offset: 0x0 */
    uint32 RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
    uint32 HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
    uint32 LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
    volatile uint32 SR;                       /**< Status Register, offset: 0x10 */
    uint32 IER;                               /**< Interrupt Enable Register, offset: 0x14 */

}Clock_Ip_ClockMonitorType;

typedef struct{

    Clock_Ip_NameType Name;       /* Name of the clock that can be monitored/supports cmu (clock monitor) */
    Clock_Ip_NameType Reference;  /* Name of the reference clock */
    Clock_Ip_NameType Bus;        /* Name of the bus clock */

    Clock_Ip_ClockMonitorType* CmuInstance;

}Clock_Ip_CmuInfoType;

typedef struct
{
    uint8 GroupIndex;
    uint8 GateIndex;

}Clock_Ip_GateInfoType;

typedef struct
{
    uint32 SelectorValueMask;
    uint32 SelectorValueShift;
    uint32 DividerValueMask;
    uint32 DividerValueShift;

}Clock_Ip_ClockExtensionType;

typedef struct
{
    PLLDIG_Type* PllInstance;
    uint8 DivsNo;

}Clock_Ip_PllType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

extern Clock_Ip_CgmMuxType* const Clock_Ip_apxCgm[CLOCK_IP_MC_CGM_INSTANCES_COUNT][CLOCK_IP_MC_CGM_MUXS_COUNT];
extern volatile Clock_Ip_CgmPcfsType* const Clock_Ip_apxCgmPcfs[CLOCK_IP_MC_CGM_INSTANCES_COUNT];
extern Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_PllType const Clock_Ip_apxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE];
extern DFS_Type* const Clock_Ip_apxDfs[CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_ClockMonitorType * const Clock_Ip_apxCmu[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_NameType const Clock_Ip_aeCmuNames[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE];

extern Clock_Ip_GprClockControlEnable_Type* const Clock_Ip_apxGprClockControlEnable[CLOCK_IP_PERIPHERAL_GROUPS_COUNT];

extern const Clock_Ip_CmuInfoType Clock_Ip_axCmuInfo[CLOCK_IP_CMU_INFO_SIZE];

extern const Clock_Ip_GateInfoType Clock_Ip_axGateInfo[CLOCK_IP_GATE_INFO_SIZE];

extern const Clock_Ip_ClockExtensionType Clock_Ip_axFeatureExtensions[CLOCK_IP_EXTENSIONS_SIZE];

#if defined(CLOCK_IP_HAS_SYSTEM_CLK)
extern Clock_Ip_SystemClockType* const Clock_Ip_apxSystemClock;
#endif



/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_16
#include "Mcu_MemMap.h"

extern const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_FEATURE_PRODUCERS_NO];
extern const uint16 Clock_Ip_au16SelectorEntryAeHardwareValue[];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16
#include "Mcu_MemMap.h"



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
void Clock_Ip_SpecificSetUserAccessAllowed(void);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
void Clock_Ip_McMeEnterKey(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CLOCK_IP_SPECIFIC_H */

