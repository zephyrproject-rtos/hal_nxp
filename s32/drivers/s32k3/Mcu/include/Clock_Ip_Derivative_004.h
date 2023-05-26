/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_DERIVATIVE_004_H
#define CLOCK_IP_DERIVATIVE_004_H

/**
*   @file       Clock_Ip_Derivative_004.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
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

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_DERIVATIVE_004_VENDOR_ID                       43
#define CLOCK_IP_DERIVATIVE_004_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_DERIVATIVE_004_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_DERIVATIVE_004_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_DERIVATIVE_004_SW_MAJOR_VERSION                3
#define CLOCK_IP_DERIVATIVE_004_SW_MINOR_VERSION                0
#define CLOCK_IP_DERIVATIVE_004_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


#define CLOCK_IP_DIVIDER_CALLBACKS_COUNT                                               4U
#define CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE                                       1U
#define CLOCK_IP_PLL_PLL0DIV_DE_DIV_OUTPUT                                             2U
#define CLOCK_IP_PLL_PLLDV_ODIV2_OUTPUT                                                3U

#define CLOCK_IP_DIVIDERTRIGGER_CALLBACKS_COUNT                                        2U
#define CLOCK_IP_CGM_X_DIV_TRIG_CTRL_TCTL_HHEN_UPD_STAT                                1U

#define CLOCK_IP_XOSC_CALLBACKS_COUNT                                                  3U
#define CLOCK_IP_FXOSC_OSCON_BYP_EOCV_GM_SEL                                           1U
#define CLOCK_IP_SXOSC_OSCON_EOCV                                                      2U

#define CLOCK_IP_IRCOSC_CALLBACKS_COUNT                                                4U
#define CLOCK_IP_FIRC_STDBY_ENABLE                                                     1U
#define CLOCK_IP_SIRC_STDBY_ENABLE                                                     2U
#define CLOCK_IP_FIRC_DIV_SEL_HSEb_CONFIG_REG_GPR                                      3U

#define CLOCK_IP_GATE_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST                                   1U

#define CLOCK_IP_FRACTIONAL_DIVIDER_CALLBACKS_COUNT                                     1U

#define CLOCK_IP_PLL_CALLBACKS_COUNT                                                   2U
#define CLOCK_IP_PLL_RDIV_MFI_MFN_ODIV2_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE        1U

#define CLOCK_IP_SELECTOR_CALLBACKS_COUNT                                              5U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP                                             1U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP                             2U
#define CLOCK_IP_CGM_X_CSC_CSS_CS_GRIP                                                 3U
#define CLOCK_IP_RTC_RTCC_CLKSELECT                                                    4U

#define CLOCK_IP_PCFS_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS                                        1U

#define CLOCK_IP_CMU_CALLBACKS_COUNT                                                   2U
#define CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF                                        1U

#define CLOCK_IP_CMU_INSTANCES_NO                                                      4U

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef CLOCK_IP_DERIVATIVE_004_H */

