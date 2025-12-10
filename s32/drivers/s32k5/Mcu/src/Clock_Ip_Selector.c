/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Selector.c
*   @version    0.8.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
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

#include "Clock_Ip_Private.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SELECTOR_VENDOR_ID_C                      43
#define CLOCK_IP_SELECTOR_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_SELECTOR_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_SELECTOR_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_SELECTOR_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_SELECTOR_SW_MINOR_VERSION_C               8
#define CLOCK_IP_SELECTOR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Selector.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_SELECTOR_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Selector.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Selector.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_SELECTOR_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SELECTOR_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SELECTOR_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Selector.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Selector.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_SELECTOR_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SELECTOR_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_SELECTOR_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Selector.c and Clock_Ip_Private.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
#define CLOCK_IP_RUN_MODE     ((uint32)0x00000001U)
#endif
#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
#define CLOCK_IP_HSRUN_MODE   ((uint32)0x00000080U)
#endif
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static Clock_Ip_NameType Clock_Ip_SelectorName = RESERVED_CLK;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"
#ifdef CLOCK_IP_RTC_RTCC_CLKSELECT
void Clock_Ip_SetRtcRtccClksel_TrustedCall(Clock_Ip_NameType Source);
#endif


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_CallbackSelectorEmptyName(Clock_Ip_NameType PllName);
static void Clock_Ip_CallbackSelectorEmpty1(void);
static Clock_Ip_NameType Clock_Ip_CallbackSelectorEmpty2(void);
static ClockLLD_StatusReturnType Clock_Ip_CallbackSelectorEmpty3(void);
static void Clock_Ip_CallbackSelectorEmpty4(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_CallbackSelectorEmpty5(Clock_Ip_NameType Source);
static uint32 Clock_Ip_CallbackSelectorEmpty6(Clock_Ip_NameType (*SelectorEntries)[]);
static uint32 Clock_Ip_CallbackSelectorEmpty7(Clock_Ip_NameType (*DividerChildren)[]);

#ifdef CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP
static void Clock_Ip_SetNameCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType SelectorName);
static void Clock_Ip_ResetCgmXCscCssClkSwSwtrigSwip(void);
static void Clock_Ip_SetOptionalParameterCgmXCscCssClkSwSwtrigSwip(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType Source);
static void Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwip(void);
static void Clock_Ip_SwitchCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType Source);
static uint32 Clock_Ip_GetSelectorEntriesCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType (*SelectorEntries)[]);
static uint32 Clock_Ip_GetDividerChildrenCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType (*DividerChildren)[]);
static Clock_Ip_NameType Clock_Ip_GetSourceCgmXCscCssClkSwSwtrigSwip(void);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCgmXCscCssClkSwSwtrigSwip(void);
static void Clock_Ip_Set_Optimized_CgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType Source);
static void Clock_Ip_Wait_Optimized_CgmXCscCssClkSwSwtrigSwip(void);
#endif
#ifdef CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP_RMP_SW
static void Clock_Ip_SetNameCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType SelectorName);
static void Clock_Ip_ResetCgmXCscCssClkSwSwtrigSwipRmpSw(void);
static void Clock_Ip_SetOptionalParameterCgmXCscCssClkSwSwtrigSwipRmpSw(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value);
static void Clock_Ip_SetCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType Source);
static void Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwipRmpSw(void);
static void Clock_Ip_SwitchCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType Source);
static uint32 Clock_Ip_GetSelectorEntriesCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType (*SelectorEntries)[]);
static uint32 Clock_Ip_GetDividerChildrenCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType (*DividerChildren)[]);
static Clock_Ip_NameType Clock_Ip_GetSourceCgmXCscCssClkSwSwtrigSwipRmpSw(void);
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCgmXCscCssClkSwSwtrigSwipRmpSw(void);
static void Clock_Ip_Set_Optimized_CgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType Source);
static void Clock_Ip_Wait_Optimized_CgmXCscCssClkSwSwtrigSwipRmpSw(void);
#endif
#ifdef CLOCK_IP_RTC_RTCC_CLKSELECT
static void Clock_Ip_SetRtcRtccClksel(Clock_Ip_NameType Source);
#endif
/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_CallbackSelectorEmptyName(Clock_Ip_NameType SelectorName)
{
    (void)SelectorName;
    /* No implementation */
}
static void Clock_Ip_CallbackSelectorEmpty1(void)
{
    /* No implementation */
}
static Clock_Ip_NameType Clock_Ip_CallbackSelectorEmpty2(void)
{
    /* No implementation */
    return gated_clk;
}
static ClockLLD_StatusReturnType Clock_Ip_CallbackSelectorEmpty3(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static void Clock_Ip_CallbackSelectorEmpty4(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_CallbackSelectorEmpty5(Clock_Ip_NameType Source)
{
    (void)Source;
    /* No implementation */
}
static uint32 Clock_Ip_CallbackSelectorEmpty6(Clock_Ip_NameType (*SelectorEntries)[])
{
    (void)SelectorEntries;
    return 0U;
}
static uint32 Clock_Ip_CallbackSelectorEmpty7(Clock_Ip_NameType (*DividerChildren)[])
{
    (void)DividerChildren;
    return 0U;
}

#ifdef CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_STEP_DURATION_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_STEP_DURATION_VALUE 0U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE 1U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE 2U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE 3U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE 4U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS
    #define CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS 5U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS
    #define CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS 6U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE 7U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_RETURN
    #define CLOCK_IP_SET_SELECTOR_001_RETURN 8U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS
    #define CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS 0U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS
    #define CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS 1U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS
    #define CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS 2U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_RETURN
    #define CLOCK_IP_WAIT_SELECTOR_001_RETURN 3U
#endif
static void Clock_Ip_SetNameCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType SelectorName)
{
    Clock_Ip_SelectorName = SelectorName;
}
static void Clock_Ip_ResetCgmXCscCssClkSwSwtrigSwip(void)
{
    uint32 SelectorEntry;
    uint32 SelectorMask;
    uint32 RegValue;

    Clock_Ip_HwSelectorType *HwAddr;

    SelectorEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    SelectorMask       =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelMask;
    HwAddr             =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;

    RegValue = HwAddr->SetSelectorValue;
    RegValue &= ~SelectorMask;
    RegValue |= CLOCK_IP_MC_CGM_MUX_CSC_SAFE_SW_MASK;
    HwAddr->SetSelectorValue = RegValue;
}
static void Clock_Ip_SetOptionalParameterCgmXCscCssClkSwSwtrigSwip(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_SetCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType Source)
{
    uint32 SelectorEntry;
    uint32 SelectorMask;
    uint32 SelectorShift;
    uint32 SelectorValue;    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    uint32 RegValue;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Clock_Ip_HwSelectorType *HwAddr;


    SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[Source];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    SelectorEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    SelectorMask       =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelMask;
    SelectorShift      =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelShift;
    HwAddr             =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;

    if (SelectorValue != ((HwAddr->GetSelectorValue & SelectorMask) >> SelectorShift))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS == (HwAddr->GetSelectorValue & CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK)) && (FALSE == TimeoutOccurred));

        if (FALSE == TimeoutOccurred)
        {
            RegValue = HwAddr->SetSelectorValue;
            RegValue &= ~SelectorMask;
            RegValue |= (SelectorValue << SelectorShift) & SelectorMask;
            RegValue |= (CLOCK_IP_MC_CGM_MUX_CSC_CLK_SW_MASK);  /* Clock switch operation is requested */
            HwAddr->SetSelectorValue = RegValue;

        }
        else
        {

            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_SelectorName);
        }
    }
}
static void Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwip(void)
{


    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    uint32 SelectorEntry            =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    Clock_Ip_HwSelectorType *HwAddr =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;


    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    /* Wait for acknowledge to be cleared. */
    do
    {
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while ((CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS == (HwAddr->GetSelectorValue & CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK)) && (FALSE == TimeoutOccurred) );

    if (FALSE == TimeoutOccurred)
    {
        /* Check the switch status. */
        if (CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED != ((HwAddr->GetSelectorValue & CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_MASK) >> CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SHIFT))
        {
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_CLOCK_MUX_SWITCH_ERROR, Clock_Ip_SelectorName);
        }
    }
    else
    {
        /* Report timeout error */
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_SelectorName);
    }
}
static void Clock_Ip_SwitchCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType Source)
{
    Clock_Ip_SetCgmXCscCssClkSwSwtrigSwip(Source);

    Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwip();
}
static uint32 Clock_Ip_GetSelectorEntriesCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType (*SelectorEntries)[])
{
    uint32 SelectorEntriesNo = 0U;

    switch (Clock_Ip_SelectorName)
    {
#if defined(CLOCK_IP_HAS_CAN_PE_CLK)
        case CAN_PE_CLK:
        {
            (*SelectorEntries)[0] = PLTDIV1_CLK;
            (*SelectorEntries)[1] = PLL0_DFS3_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            (*SelectorEntries)[3] = SAFE_CLK;

            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH_TS_CLK)
        case ETH_TS_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = FXOSC_CLK;
            (*SelectorEntries)[2] = SAFE_CLK;
            (*SelectorEntries)[3] = ts_1588_clk;
            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH0_RX_CLK)
        case ETH0_RX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            (*SelectorEntries)[3] = eth0_mii_rx_ext_clk;
            (*SelectorEntries)[4] = eth0_rgmii_rx_ext_clk;
            SelectorEntriesNo = 5U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH0_TX_CLK)
        case ETH0_TX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = eth0_rmii_ref_ext_clk;
            (*SelectorEntries)[4] = eth0_mii_tx_ext_clk;
            (*SelectorEntries)[5] = eth0_rgmii_tx_ext_clk;
            SelectorEntriesNo = 6U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH1_RX_CLK)
        case ETH1_RX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            (*SelectorEntries)[3] = eth1_mii_rx_ext_clk;
            (*SelectorEntries)[4] = eth1_rgmii_rx_ext_clk;
            SelectorEntriesNo = 5U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH1_TX_CLK)
        case ETH1_TX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = eth1_rmii_ref_ext_clk;
            (*SelectorEntries)[4] = eth1_mii_tx_ext_clk;
            (*SelectorEntries)[5] = eth1_rgmii_tx_ext_clk;
            SelectorEntriesNo = 6U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH2_RX_CLK)
        case ETH2_RX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            (*SelectorEntries)[3] = eth2_mii_rx_ext_clk;
            (*SelectorEntries)[4] = eth2_rgmii_rx_ext_clk;
            SelectorEntriesNo = 5U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH2_TX_CLK)
        case ETH2_TX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = eth2_rmii_ref_ext_clk;
            (*SelectorEntries)[4] = eth2_mii_tx_ext_clk;
            (*SelectorEntries)[5] = eth2_rgmii_tx_ext_clk;
            SelectorEntriesNo = 6U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH3_RX_CLK)
        case ETH3_RX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            (*SelectorEntries)[3] = eth1_rgmii_rx_ext_clk;
            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH3_TX_CLK)
        case ETH3_TX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = eth1_rgmii_rx_ext_clk;
            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH4_RX_CLK)
        case ETH4_RX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            (*SelectorEntries)[3] = eth1_rgmii_rx_ext_clk;
            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH4_TX_CLK)
        case ETH4_TX_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = eth1_rgmii_rx_ext_clk;
            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK)
        case PERI_HIGH_SPEED_REST_USDHC_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS2_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = FXOSC_CLK;

            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK)
        case PERI_HIGH_SPEED_REST_XSPI_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS1_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;
            (*SelectorEntries)[3] = FXOSC_CLK;

            SelectorEntriesNo = 4U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_TRACE_CLK)
        case PERI_HIGH_SPEED_TRACE_CLK:
        {
            (*SelectorEntries)[0] = PLTDIV1_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FXOSC_CLK;
            SelectorEntriesNo = 3U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PHY_ETH_CLK)
        case PHY_ETH_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = PLTDIV1_CLK;
            SelectorEntriesNo = 3U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_SERDES_AUX_CLK)
        case SERDES_AUX_CLK:
        {
            (*SelectorEntries)[1] = FIRCDIV2_CLK;
            (*SelectorEntries)[0] = SAFE_CLK;

            SelectorEntriesNo = 2U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_SERDES_REF_CLK)
        case SERDES_REF_CLK:
        {
            (*SelectorEntries)[0] = PLL0_DFS0_CLK;
            (*SelectorEntries)[1] = SAFE_CLK;
            (*SelectorEntries)[2] = FIRCDIV2_CLK;

            SelectorEntriesNo = 3U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }

    return SelectorEntriesNo;
}
static uint32 Clock_Ip_GetDividerChildrenCgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType (*DividerChildren)[])
{
    uint32 DividerChildrenNo = 0U;

    switch (Clock_Ip_SelectorName)
    {
#if defined(CLOCK_IP_HAS_CAN_PE_CLK)
        case CAN_PE_CLK:
        {
            (*DividerChildren)[0] = CAN_PE_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH_TS_CLK)
        case ETH_TS_CLK:
        {
            (*DividerChildren)[0] = ETH_TS_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH0_RX_CLK)
        case ETH0_RX_CLK:
        {
            (*DividerChildren)[0] = ETH0_RX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH0_TX_CLK)
        case ETH0_TX_CLK:
        {
            (*DividerChildren)[0] = ETH0_TX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH1_RX_CLK)
        case ETH1_RX_CLK:
        {
            (*DividerChildren)[0] = ETH1_RX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH1_TX_CLK)
        case ETH1_TX_CLK:
        {
            (*DividerChildren)[0] = ETH1_TX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH2_RX_CLK)
        case ETH2_RX_CLK:
        {
            (*DividerChildren)[0] = ETH2_RX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH2_TX_CLK)
        case ETH2_TX_CLK:
        {
            (*DividerChildren)[0] = ETH2_TX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH3_RX_CLK)
        case ETH3_RX_CLK:
        {
            (*DividerChildren)[0] = ETH3_RX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH3_TX_CLK)
        case ETH3_TX_CLK:
        {
            (*DividerChildren)[0] = ETH3_TX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH4_RX_CLK)
        case ETH4_RX_CLK:
        {
            (*DividerChildren)[0] = ETH4_RX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_ETH4_TX_CLK)
        case ETH4_TX_CLK:
        {
            (*DividerChildren)[0] = ETH4_TX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK)
        case PERI_HIGH_SPEED_REST_USDHC_CLK:
        {
            (*DividerChildren)[0] = PERI_HIGH_SPEED_REST_USDHC_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK)
        case PERI_HIGH_SPEED_REST_XSPI_CLK:
        {
            (*DividerChildren)[0] = PERI_HIGH_SPEED_REST_XSPI_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_TRACE_CLK)
        case PERI_HIGH_SPEED_TRACE_CLK:
        {
            (*DividerChildren)[0] = PERI_HIGH_SPEED_TRACE_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_PHY_ETH_CLK)
        case PHY_ETH_CLK:
        {
            (*DividerChildren)[0] = PHY_ETH_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_SERDES_AUX_CLK)
        case SERDES_AUX_CLK:
        {
            (*DividerChildren)[0] = SERDES_AUX_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
#if defined(CLOCK_IP_HAS_SERDES_REF_CLK)
        case SERDES_REF_CLK:
        {
            (*DividerChildren)[0] = SERDES_REF_CLK;
            DividerChildrenNo = 1U;
        }
        break;
#endif
        default:
        {
            /* Invalid pll name */
        }
    }

    return DividerChildrenNo;

}
static Clock_Ip_NameType Clock_Ip_GetSourceCgmXCscCssClkSwSwtrigSwip(void)
{
    /* No implementation */
    return gated_clk;
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCgmXCscCssClkSwSwtrigSwip(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static void Clock_Ip_Set_Optimized_CgmXCscCssClkSwSwtrigSwip(Clock_Ip_NameType Source)
{
    uint32 SelectorEntry;
    uint32 SelectorMask;
    uint32 SelectorShift;
    uint32 SelectorValue;    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    Clock_Ip_HwSelectorType *HwAddr;


    SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[Source];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    SelectorEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    SelectorMask       =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelMask;
    SelectorShift      =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelShift;
    HwAddr             =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;


    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
-------------->     CHECK: Selector is already set to value from configuration.           /\
-------------->      - Yes, go to end                                                    /  \
-------------->      - No, continue to configure selector.                              /    \    Yes
-------------->                                                                        /      \____________________________________
-------------->     Check hardware state:                                              \      /                                    ||
-------------->     CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                              \    /                                     ||
-------------->     Offset in diagram state machine:                                     \  /                                      ||
-------------->     CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                        \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
                CHECK: Previous selector configuration is in progress.                    \/                                       ||
                 - Yes, wait for selector to complete.                                    /\                                       ||
                 - No, continue to configure selector.                                   /  \                                      ||
                                                                                        /    \                                     ||
                Check hardware state:                                                  /      \_________________                   ||
                CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS              \      /               ||                   ||
                Offset in diagram state machine:                                        \    /                ||                   ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
                CHECK: Timeout for previous selector configuration which is still in progress.               /  \                  ||
                 - Yes, go to end                                                         ||                /    \    Yes          ||
                 - No, continue to configure selector.                                    ||               /      \_________       ||
                                                                                          ||               \      /       ||       ||
                Check hardware state:                                                     ||                \    /        ||       ||
                CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS            || No              \  /         ||       ||
                Offset in diagram state machine:                                          ||                  \/          ||       ||
                CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
                WRITE: Configure selector.                                      |                    |        ||          ||       ||
                                                                                |                    |/_______||          ||       ||
                Update hardware state:                                          |                    |\                   ||       ||
                CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                          |                    |                    ||       ||
                Offset in diagram state machine:                                |---------------------                    ||       ||
                CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                              ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE */
    /* Do not configure mux if it is already set to the selector value from configuration. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       /* Register access: check a bitfield from register */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE,                            /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS - CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        SelectorMask,                                                                /* Register mask. */
        SelectorValue << SelectorShift,                                              /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwip_TYPE,                                  /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                       /* Check hardware state */
    );

    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
                CHECK: Selector is already set to value from configuration.               /\
                 - Yes, go to end                                                        /  \
                 - No, continue to configure selector.                                  /    \    Yes
                                                                                       /      \____________________________________
                Check hardware state:                                                  \      /                                    ||
                CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                  \    /                                     ||
                Offset in diagram state machine:                                         \  /                                      ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                            \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
-------------->     CHECK: Previous selector configuration is in progress.                \/                                       ||
-------------->      - Yes, wait for selector to complete.                                /\                                       ||
-------------->      - No, continue to configure selector.                               /  \                                      ||
-------------->                                                                         /    \                                     ||
-------------->     Check hardware state:                                              /      \_________________                   ||
-------------->     CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS          \      /               ||                   ||
-------------->     Offset in diagram state machine:                                    \    /                ||                   ||
-------------->     CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS          \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
                CHECK: Timeout for previous selector configuration which is still in progress.               /  \                  ||
                 - Yes, go to end                                                         ||                /    \    Yes          ||
                 - No, continue to configure selector.                                    ||               /      \_________       ||
                                                                                          ||               \      /       ||       ||
                Check hardware state:                                                     ||                \    /        ||       ||
                CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS            || No              \  /         ||       ||
                Offset in diagram state machine:                                          ||                  \/          ||       ||
                CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
                WRITE: Configure selector.                                      |                    |        ||          ||       ||
                                                                                |                    |/_______||          ||       ||
                Update hardware state:                                          |                    |\                   ||       ||
                CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                          |                    |                    ||       ||
                Offset in diagram state machine:                                |---------------------                    ||       ||
                CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                              ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS */
    /* Check CLK_SW is cleared */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       /* Register access: check a bitfield from register */
        CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS - CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE - CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS,                           /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwip_TYPE,                                  /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                          /* Check hardware state */
    );


    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
                CHECK: Selector is already set to value from configuration.               /\
                 - Yes, go to end                                                        /  \
                 - No, continue to configure selector.                                  /    \    Yes
                                                                                       /      \____________________________________
                Check hardware state:                                                  \      /                                    ||
                CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                  \    /                                     ||
                Offset in diagram state machine:                                         \  /                                      ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                            \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
                CHECK: Previous selector configuration is in progress.                    \/                                       ||
                 - Yes, wait for selector to complete.                                    /\                                       ||
                 - No, continue to configure selector.                                   /  \                                      ||
                                                                                        /    \                                     ||
                Check hardware state:                                                  /      \_________________                   ||
                CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS              \      /               ||                   ||
                Offset in diagram state machine:                                        \    /                ||                   ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
-------------->     CHECK: Timeout for previous selector configuration which is still in progress.           /  \                  ||
-------------->      - Yes, go to end                                                     ||                /    \    Yes          ||
-------------->      - No, continue to configure selector.                                ||               /      \_________       ||
-------------->                                                                           ||               \      /       ||       ||
-------------->     Check hardware state:                                                 ||                \    /        ||       ||
-------------->     CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS        || No              \  /         ||       ||
-------------->     Offset in diagram state machine:                                      ||                  \/          ||       ||
-------------->     CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
                WRITE: Configure selector.                                      |                    |        ||          ||       ||
                                                                                |                    |/_______||          ||       ||
                Update hardware state:                                          |                    |\                   ||       ||
                CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                          |                    |                    ||       ||
                Offset in diagram state machine:                                |---------------------                    ||       ||
                CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                              ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS */
    /* Wait for CLK_SW to auto-clear */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_TIMEOUT,                         /* Register access: check a bitfield from register */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS,              /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE - CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS,  /* The second branch offset */
        REGISTER_ACCESS__TIMEOUT_EVENT,                                              /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwip_TYPE,                                  /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               /* Check hardware state */
    );

    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
                CHECK: Selector is already set to value from configuration.               /\
                 - Yes, go to end                                                        /  \
                 - No, continue to configure selector.                                  /    \    Yes
                                                                                       /      \____________________________________
                Check hardware state:                                                  \      /                                    ||
                CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                  \    /                                     ||
                Offset in diagram state machine:                                         \  /                                      ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                            \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
                CHECK: Previous selector configuration is in progress.                    \/                                       ||
                 - Yes, wait for selector to complete.                                    /\                                       ||
                 - No, continue to configure selector.                                   /  \                                      ||
                                                                                        /    \                                     ||
                Check hardware state:                                                  /      \_________________                   ||
                CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS              \      /               ||                   ||
                Offset in diagram state machine:                                        \    /                ||                   ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
                CHECK: Timeout for previous selector configuration which is still in progress.               /  \                  ||
                 - Yes, go to end                                                         ||                /    \    Yes          ||
                 - No, continue to configure selector.                                    ||               /      \_________       ||
                                                                                          ||               \      /       ||       ||
                Check hardware state:                                                     ||                \    /        ||       ||
                CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS            || No              \  /         ||       ||
                Offset in diagram state machine:                                          ||                  \/          ||       ||
                CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
-------------->     WRITE: Configure selector.                                  |                    |        ||          ||       ||
-------------->                                                                 |                    |/_______||          ||       ||
-------------->     Update hardware state:                                      |                    |\                   ||       ||
-------------->     CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                      |                    |                    ||       ||
-------------->     Offset in diagram state machine:                            |---------------------                    ||       ||
-------------->     CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                          ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* All the PCFS commands should be atomic in nature (i.e. a single register write should provide a complete PCFS sequence
     * to be executed, that is ramp-down, clock switch, and ramp-up. It is necessary to set both RAMPUP and RAMPDOWN bits
     * together even if you want to trigger either RAMPUP or RAMPDOWN process, otherwise the PCFS effect will not manifest. */

    /* CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE */
    /* Set selector value. */
    RegisterAccess
    (
        REGISTER_ACCESS__READ_MODIFY_WRITE,                                          /* Register access: read modify write */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        &HwAddr->SetSelectorValue,                                                   /* Register address. */
        NULL_PTR,                                                                    /* Register address read-only. */
        (SelectorMask),                                                              /* Register mask. */
        ((SelectorValue << SelectorShift) | CLOCK_IP_MC_CGM_MUX_CSC_CLK_SW_MASK),    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwip_TYPE,                                  /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                                       /* Update hardware state */
    );
    /* CLOCK_IP_SET_SELECTOR_001_RETURN */

}
static void Clock_Ip_Wait_Optimized_CgmXCscCssClkSwSwtrigSwip(void)
{
    uint32 SelectorEntry            =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    Clock_Ip_HwSelectorType *HwAddr =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;


    /*
                                                                                          ____________
                                                                                         /            \
                                                                                        |    START     |
                                                                                         \____________/
                                                                                               ||
                                                                                               ||
                                                                                               ||  No
-------------->     CHECK: Selector configuration is in progress.                              \/
-------------->      - Yes, wait for selector to complete.                                     /\
-------------->      - No, continue to further checkings.                                     /  \
-------------->                                                                              /    \        Yes
-------------->     Check hardware state:                                                   /      \__________
-------------->     CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               \      /        ||
-------------->     Offset in diagram state machine:                                         \    /         ||
-------------->     CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /          ||
                                                                                               \/           ||
                                                                                               ||           \/
                                                                                               ||           /\
                    CHECK: Timeout for selector configuration which is still in progress.      ||          /  \
                     - Yes, go to end                                                          ||         /    \   Yes
                     - No, continue to further checkings.                                      ||        /      \______
                                                                                               ||        \      /    ||
                    Check hardware state:                                                      ||         \    /     ||
                    CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS             || No       \  /      ||
                    Offset in diagram state machine:                                           ||           \/       ||
                    CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||          //  No    ||
                                                                                               ||         //         ||
                                                                                               ||        //          ||
                                                                                               ||       //           ||
                                                                                               ||      //            ||
                                                                                               ||     //             ||
                                                                                               ||    //              ||
                                                                                               ||   //               ||
                                                                                               ||  //                ||
                                                                                               || //                 ||
                                                                                               ||//                  ||
                                                                                               |//                   ||
                                                                                               ||  No                ||
                    CHECK: Clock switch status.                                                \/                    ||
                     - Yes, switch after request succeeded.                                    /\                    ||
                     - No, go to end.                                                         /  \                   ||
                                                                                             /    \        Yes       ||
                    Check hardware state:                                                   /      \__________       ||
                    CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                     \      /          ||     ||
                    Offset in diagram state machine:                                         \    /           ||     ||
                    CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /            ||     ||
                                                                                               \/             ||     ||
                                                                                               || No          /|     /|
                                                                                               ||            //     //
                                                                                          _____\/_____      //     //
                                                                                         /            \    //     //
                                                                                        |      END     |/_//_____//
                                                                                         \____________/ \
    */



    /* CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS */
    /* Wait for acknowledge to be cleared. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       /* Register access: check a bitfield from register */
        CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS - CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS, /* The first branch offset */
        CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS - CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS,                          /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_WAIT_TYPE,                                                          /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwip_TYPE,                                 /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                          /* Check hardware state */
    );


    /*
                                                                                          ____________
                                                                                         /            \
                                                                                        |    START     |
                                                                                         \____________/
                                                                                               ||
                                                                                               ||
                                                                                               ||  No
                    CHECK: Selector configuration is in progress.                              \/
                     - Yes, wait for selector to complete.                                     /\
                     - No, continue to further checkings.                                     /  \
                                                                                             /    \        Yes
                    Check hardware state:                                                   /      \__________
                    CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               \      /        ||
                    Offset in diagram state machine:                                         \    /         ||
                    CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /          ||
                                                                                               \/           ||
                                                                                               ||           \/
                                                                                               ||           /\
-------------->     CHECK: Timeout for selector configuration which is still in progress.      ||          /  \
-------------->      - Yes, go to end                                                          ||         /    \   Yes
-------------->      - No, continue to further checkings.                                      ||        /      \______
-------------->                                                                                ||        \      /    ||
-------------->     Check hardware state:                                                      ||         \    /     ||
-------------->     CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS             || No       \  /      ||
-------------->     Offset in diagram state machine:                                           ||           \/       ||
-------------->     CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||          //  No    ||
                                                                                               ||         //         ||
                                                                                               ||        //          ||
                                                                                               ||       //           ||
                                                                                               ||      //            ||
                                                                                               ||     //             ||
                                                                                               ||    //              ||
                                                                                               ||   //               ||
                                                                                               ||  //                ||
                                                                                               || //                 ||
                                                                                               ||//                  ||
                                                                                               |//                   ||
                                                                                               ||  No                ||
                    CHECK: Clock switch status.                                                \/                    ||
                     - Yes, switch after request succeeded.                                    /\                    ||
                     - No, go to end.                                                         /  \                   ||
                                                                                             /    \        Yes       ||
                    Check hardware state:                                                   /      \__________       ||
                    CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                     \      /          ||     ||
                    Offset in diagram state machine:                                         \    /           ||     ||
                    CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /            ||     ||
                                                                                               \/             ||     ||
                                                                                               || No          /|     /|
                                                                                               ||            //     //
                                                                                          _____\/_____      //     //
                                                                                         /            \    //     //
                                                                                        |      END     |/_//_____//
                                                                                         \____________/ \
    */


    /* CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS */
    /* Check the switch status. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_TIMEOUT,                         /* Register access: check a bitfield from register */
        CLOCK_IP_WAIT_SELECTOR_001_RETURN - CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS,              /* The first branch offset */
        CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS - CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS, /* The second branch offset */
        REGISTER_ACCESS__TIMEOUT_EVENT,                                              /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_WAIT_TYPE,                                                          /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwip_TYPE,                                 /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               /* Check hardware state */
    );


    /*
                                                                                            ____________
                                                                                           /            \
                                                                                          |    START     |
                                                                                           \____________/
                                                                                                 ||
                                                                                                 ||
                                                                                                 ||  No
-------------->     CHECK: Selector configuration is in progress.                                \/
-------------->      - Yes, wait for selector to complete.                                       /\
-------------->      - No, continue to further checkings.                                       /  \
-------------->                                                                                /    \        Yes
-------------->     Check hardware state:                                                     /      \__________
-------------->     CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS                 \      /        ||
-------------->     Offset in diagram state machine:                                           \    /         ||
-------------->     CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                \  /          ||
                                                                                                 \/           ||
                                                                                                 ||           \/
                                                                                                 ||           /\
                      CHECK: Timeout for selector configuration which is still in progress.      ||          /  \
                       - Yes, go to end                                                          ||         /    \   Yes
                       - No, continue to further checkings.                                      ||        /      \______
                                                                                                 ||        \      /    ||
                      Check hardware state:                                                      ||         \    /     ||
                      CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS             || No       \  /      ||
                      Offset in diagram state machine:                                           ||           \/       ||
                      CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||          //  No    ||
                                                                                                 ||         //         ||
                                                                                                 ||        //          ||
                                                                                                 ||       //           ||
                                                                                                 ||      //            ||
                                                                                                 ||     //             ||
                                                                                                 ||    //              ||
                                                                                                 ||   //               ||
                                                                                                 ||  //                ||
                                                                                                 || //                 ||
                                                                                                 ||//                  ||
                                                                                                 |//                   ||
                                                                                                 ||  No                ||
                      CHECK: Clock switch status.                                                \/                    ||
                      - Yes, switch after request succeeded.                                     /\                    ||
                      - No, go to end.                                                          /  \                   ||
                                                                                               /    \        Yes       ||
                      Check hardware state:                                                   /      \__________       ||
                      CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                     \      /          ||     ||
                      Offset in diagram state machine:                                         \    /           ||     ||
                      CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /            ||     ||
                                                                                                 \/             ||     ||
                                                                                                 || No          /|     /|
                                                                                                 ||            //     //
                                                                                            _____\/_____      //     //
                                                                                           /            \    //     //
                                                                                          |      END     |/_//_____//
                                                                                           \____________/ \
    */




    /* CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS */
    /* Check the switch status. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_NOT_REGISTER_VALUE__WITH_EVENT,                       /* Register access: check a bitfield from register */
        CLOCK_IP_WAIT_SELECTOR_001_RETURN - CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS, /* The first branch offset */
        CLOCK_IP_WAIT_SELECTOR_001_RETURN - CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS, /* The second branch offset */
        REGISTER_ACCESS__MUX_SWITCH_ERROR_EVENT,                                     /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_MASK,                                          /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED,                                     /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_WAIT_TYPE,                                                          /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwip_TYPE,                                 /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_STATUS                                  /* Check hardware state */
    );
}
#endif
#ifdef CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP_RMP_SW
#define CLOCK_IP_A_MAX_SIZE 4U                                  /* Size of pcfs rates */
#define CLOCK_IP_DYNAMIC_IDD_CHANGE 2360U                       /* microA per MHz - maximum current consumtion per 1 MHz frequency variation, this setting is dependent on device */
#define CLOCK_IP_MAXIMUM_ALLOWABLE_IDD_CHANGE 50U               /* mA/microsec - dependent on power supply */
#define CLOCK_IP_STEP_DURATION_MICROSECONDS 1U                  /* microsec - PCS step duration in microseconds */
#define CLOCK_IP_CONVERT_MICROSECONDS_TO_SECONDS                1000000U
#define CLOCK_IP_CONVERT_MHZ_TO_HZ                              1000000U
#define CLOCK_IP_MULTIPLY_AmaxBrut_BY_1000                      1000U
#define CLOCK_IP_MULTIPLY_dynamicIDDchange_BY_1000              1000U
#define CLOCK_IP_CONSTANT_2048000                               (1024U * 2000U)
#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    #define CLOCK_IP_MAX_REGISTER_VALUE                         (uint32)0xFFFFFFFFU
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_STEP_DURATION_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_STEP_DURATION_VALUE 0U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE 1U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE 2U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE 3U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE 4U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS
    #define CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS 5U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS
    #define CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS 6U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE
    #define CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE 7U
#endif
#ifndef CLOCK_IP_SET_SELECTOR_001_RETURN
    #define CLOCK_IP_SET_SELECTOR_001_RETURN 8U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS
    #define CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS 0U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS
    #define CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS 1U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS
    #define CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS 2U
#endif
#ifndef CLOCK_IP_WAIT_SELECTOR_001_RETURN
    #define CLOCK_IP_WAIT_SELECTOR_001_RETURN 3U
#endif
static void Clock_Ip_SetNameCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType SelectorName)
{
    Clock_Ip_SelectorName = SelectorName;
}
static void Clock_Ip_ResetCgmXCscCssClkSwSwtrigSwipRmpSw(void)
{
    uint32 SelectorEntry;
    uint32 SelectorMask;
    uint32 RegValue;

    Clock_Ip_HwSelectorType *HwAddr;

    SelectorEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    SelectorMask       =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelMask;
    HwAddr             =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;

    RegValue = HwAddr->SetSelectorValue;
    RegValue &= ~SelectorMask;
    RegValue |= CLOCK_IP_MC_CGM_MUX_CSC_SAFE_SW_MASK;
    HwAddr->SetSelectorValue = RegValue;
}
static void Clock_Ip_SetOptionalParameterCgmXCscCssClkSwSwtrigSwipRmpSw(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value)
{
    (void)ParamId;
    (void)Value;
    /* No implementation */
}
static void Clock_Ip_SetCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType Source)
{
    uint32 Instance;
    uint32 SelectorEntry;
    uint32 SelectorMask;
    uint32 SelectorShift;
    uint32 SelectorValue;    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    uint32 RegValue;
    uint32 Index;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    uint64 Finput = 0U;
    uint64 Fsafe = 0U;
    uint64 AmaxBrut;
    uint64 Rate = 0U;

    uint64 Var1;
    uint64 Var2;
    uint64 Var3;
    uint64 K;

    uint32 Sdur;
    uint32 DivcInit;
    uint32 DivcRate;
    uint32 DivStartValue;
    uint32 DivEndValue;

    uint32 AMax[CLOCK_IP_A_MAX_SIZE] = {5U,10U,150U,200U};
    uint32 PcfsRate[CLOCK_IP_A_MAX_SIZE] = {12U,48U,112U,184U};

    Clock_Ip_HwSelectorType *HwAddr;
    Clock_Ip_HwPcfsType (*HwPcfsArray)[];


    Finput = ((*Clock_Ip_pxConfig->ConfiguredFrequencies)[Clock_Ip_FreqIds[Source]].ConfiguredFrequencyValue);
#if defined(CLOCK_IP_HAS_FIRC_CLK)
    Fsafe = ((*Clock_Ip_pxConfig->ConfiguredFrequencies)[Clock_Ip_FreqIds[FIRC_CLK]].ConfiguredFrequencyValue);
#endif

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT(Finput != 0U);
    CLOCK_IP_DEV_ASSERT(Fsafe != 0U);
#endif

    /* Calculate PcfsRate = AmaxBrut = fchg/Finput */
    AmaxBrut = ((uint64)CLOCK_IP_MAXIMUM_ALLOWABLE_IDD_CHANGE * CLOCK_IP_CONVERT_MHZ_TO_HZ * CLOCK_IP_MULTIPLY_dynamicIDDchange_BY_1000 * CLOCK_IP_MULTIPLY_AmaxBrut_BY_1000 / (Finput * CLOCK_IP_DYNAMIC_IDD_CHANGE));
#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT(AmaxBrut >= AMax[0]);
#endif


    for (Index = 0U; Index < CLOCK_IP_A_MAX_SIZE; Index++)
    {
        if (AMax[Index] < AmaxBrut)
        {
            Rate = PcfsRate[Index];
        }
    }

    /* Calculate K by using formula k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Finput/fsafe)) / Rate))) */
    Var1 = 256U + ((CLOCK_IP_CONSTANT_2048000 * Finput) / (Fsafe * Rate)) - (CLOCK_IP_CONSTANT_2048000 / Rate);
    Var2 = 1UL << 30U;   /* The second-to-top bit is set: use 1u << 14 for uint16 type; use 1uL<<30 for uint32 type  */
    Var3 = 0U;

    /* Implement sqrt from K formula by using a square-root computing in embedded C */

    /* "one" starts at the highest power of four <= than the argument */
    while (Var2 > Var1)
    {
        Var2 = Var2 >> 2;
    }
    /* Implement sqrt from K formula by using a square-root computing in embedded C */

    while (Var2 != 0U)
    {
        if (Var1 >= (Var3 + Var2))
        {
            Var1 = Var1 - (Var3 + Var2);
            Var3 = Var3 + (Var2 << 1U);
        }

        Var3 = Var3 >> 1U;
        Var2 = Var2 >> 2U;
    }

    K = (64U + 127U + (Var3 << 2U)) >> 7U;   /* Calculated K from k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Fi/Fsafe)) / Rate))) */

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT((CLOCK_IP_STEP_DURATION_MICROSECONDS * Fsafe)       < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for Sdur */
    CLOCK_IP_DEV_ASSERT((Rate * K)                           < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivcInit */
    CLOCK_IP_DEV_ASSERT((Rate)                               < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivcRate */
    CLOCK_IP_DEV_ASSERT((999U + ((Rate * K * (K+1U)) >> 1U)) < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivStartValue */
    CLOCK_IP_DEV_ASSERT(((Finput * 1000U / Fsafe) - 1U)      < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivEndValue */
#endif

    Sdur = (uint32)(CLOCK_IP_STEP_DURATION_MICROSECONDS * Fsafe / CLOCK_IP_CONVERT_MICROSECONDS_TO_SECONDS);
    DivcInit = (uint32)(Rate * K);
    DivcRate = (uint32)(Rate);
    DivStartValue = (uint32)(999U + ((Rate * K * (K+1U)) >> 1U));
    DivEndValue = (uint32)((Finput * 1000U / Fsafe) - 1U);

    SelectorValue      = Clock_Ip_au16SelectorEntryHardwareValue[Source];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    SelectorEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    SelectorMask       =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelMask;
    SelectorShift      =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelShift;
    HwAddr             =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;
    HwPcfsArray        =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].PcfsAddress;
    Instance           =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Instance;


        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS == (HwAddr->GetSelectorValue & CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK)) && (FALSE == TimeoutOccurred));

        if (FALSE == TimeoutOccurred)
        {
            RegValue = ((HwAddr->GetSelectorValue & SelectorMask) >> SelectorShift);
            if (SelectorValue != RegValue)
            {
                /* Configure pcfs registers */
                *Clock_Ip_SwitchDuration[Instance] = MC_CGM_PCFS_SDUR_SDUR(Sdur);   /* Switch step duration */
                (*HwPcfsArray)[SelectorValue - 1U].DividerChange = MC_CGM_PCFS_DIVC_RATE(DivcRate) | MC_CGM_PCFS_DIVC_INIT(DivcInit);
                (*HwPcfsArray)[SelectorValue - 1U].DividerEnd = MC_CGM_PCFS_DIVE_DIVE(DivEndValue);
                (*HwPcfsArray)[SelectorValue - 1U].DividerStart = MC_CGM_PCFS_DIVS_DIVS(DivStartValue);

                RegValue = HwAddr->SetSelectorValue;
                RegValue &= ~SelectorMask;
                RegValue |= (SelectorValue << SelectorShift) & SelectorMask;
                RegValue |= (CLOCK_IP_MC_CGM_MUX_CSC_CLK_SW_MASK);  /* Clock switch operation is requested */
                RegValue |= (CLOCK_IP_MC_CGM_MUX_CSC_RMP_SW_MASK);  /* Ramp up/down operation is requested (progressive clock frequency switch) */
                HwAddr->SetSelectorValue = RegValue;
            }
        }
        else
        {

            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_SelectorName);
        }
    }
static void Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwipRmpSw(void)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    uint32 SelectorEntry            =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    Clock_Ip_HwSelectorType *HwAddr =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;

    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    /* Wait for acknowledge to be cleared. */
    do
    {
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while ((CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS == (HwAddr->GetSelectorValue & CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK)) && (FALSE == TimeoutOccurred) );

    if (FALSE == TimeoutOccurred)
    {
        /* Check the switch status. */
        if (CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED != ((HwAddr->GetSelectorValue & CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_MASK) >> CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SHIFT))
        {
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_CLOCK_MUX_SWITCH_ERROR, Clock_Ip_SelectorName);
        }
    }
    else
    {
        /* Report timeout error */
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Clock_Ip_SelectorName);
    }
}
static void Clock_Ip_SwitchCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType Source)
{
    (void)Source;
    /* No implementation */
}
static uint32 Clock_Ip_GetSelectorEntriesCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType (*SelectorEntries)[])
{
    (void)SelectorEntries;
    return 0U;
}
static uint32 Clock_Ip_GetDividerChildrenCgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType (*DividerChildren)[])
{
    (void)DividerChildren;
    return 0U;
}
static Clock_Ip_NameType Clock_Ip_GetSourceCgmXCscCssClkSwSwtrigSwipRmpSw(void)
{
    /* No implementation */
    return gated_clk;
}
static ClockLLD_StatusReturnType Clock_Ip_GetStatusCgmXCscCssClkSwSwtrigSwipRmpSw(void)
{
    /* No implementation */
    return CLOCK_LLD_STATUS_SUCCESS;
}
static void Clock_Ip_Set_Optimized_CgmXCscCssClkSwSwtrigSwipRmpSw(Clock_Ip_NameType Source)
{
    uint32 Instance;
    uint32 SelectorEntry;
    uint32 SelectorMask;
    uint32 SelectorShift;
    uint32 SelectorValue;    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */
    uint32 Index;

    uint64 Finput = 0U;
    uint64 Fsafe = 0U;
    uint64 AmaxBrut;
    uint64 Rate = 0U;

    uint64 Var1;
    uint64 Var2;
    uint64 Var3;
    uint64 K;

    uint32 Sdur;
    uint32 DivcInit;
    uint32 DivcRate;
    uint32 DivStartValue;
    uint32 DivEndValue;

    uint32 AMax[CLOCK_IP_A_MAX_SIZE] = {5U,10U,150U,200U};
    uint32 PcfsRate[CLOCK_IP_A_MAX_SIZE] = {12U,48U,112U,184U};

    Clock_Ip_HwSelectorType *HwAddr;
    Clock_Ip_HwPcfsType (*HwPcfsArray)[];


    Finput = ((*Clock_Ip_pxConfig->ConfiguredFrequencies)[Clock_Ip_FreqIds[Source]].ConfiguredFrequencyValue);
#if defined(CLOCK_IP_HAS_FIRC_CLK)
    Fsafe = ((*Clock_Ip_pxConfig->ConfiguredFrequencies)[Clock_Ip_FreqIds[FIRC_CLK]].ConfiguredFrequencyValue);
#endif

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT(Finput != 0U);
    CLOCK_IP_DEV_ASSERT(Fsafe != 0U);
#endif

    /* Calculate PcfsRate = AmaxBrut = fchg/Finput */
    AmaxBrut = ((uint64)CLOCK_IP_MAXIMUM_ALLOWABLE_IDD_CHANGE * CLOCK_IP_CONVERT_MHZ_TO_HZ * CLOCK_IP_MULTIPLY_dynamicIDDchange_BY_1000 * CLOCK_IP_MULTIPLY_AmaxBrut_BY_1000 / (Finput * CLOCK_IP_DYNAMIC_IDD_CHANGE));
#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT(AmaxBrut >= AMax[0]);
#endif


    for (Index = 0U; Index < CLOCK_IP_A_MAX_SIZE; Index++)
    {
        if (AMax[Index] < AmaxBrut)
        {
            Rate = PcfsRate[Index];
        }
    }

    /* Calculate K by using formula k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Finput/fsafe)) / Rate))) */
    Var1 = 256U + ((CLOCK_IP_CONSTANT_2048000 * Finput) / (Fsafe * Rate)) - (CLOCK_IP_CONSTANT_2048000 / Rate);
    Var2 = 1UL << 30U;   /* The second-to-top bit is set: use 1u << 14 for uint16 type; use 1uL<<30 for uint32 type  */
    Var3 = 0U;

    /* Implement sqrt from K formula by using a square-root computing in embedded C */

    /* "one" starts at the highest power of four <= than the argument */
    while (Var2 > Var1)
    {
        Var2 = Var2 >> 2;
    }
    /* Implement sqrt from K formula by using a square-root computing in embedded C */

    while (Var2 != 0U)
    {
        if (Var1 >= (Var3 + Var2))
        {
            Var1 = Var1 - (Var3 + Var2);
            Var3 = Var3 + (Var2 << 1U);
        }

        Var3 = Var3 >> 1U;
        Var2 = Var2 >> 2U;
    }

    K = (64U + 127U + (Var3 << 2U)) >> 7U;   /* Calculated K from k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Fi/Fsafe)) / Rate))) */

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT((CLOCK_IP_STEP_DURATION_MICROSECONDS * Fsafe)       < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for Sdur */
    CLOCK_IP_DEV_ASSERT((Rate * K)                           < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivcInit */
    CLOCK_IP_DEV_ASSERT((Rate)                               < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivcRate */
    CLOCK_IP_DEV_ASSERT((999U + ((Rate * K * (K+1U)) >> 1U)) < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivStartValue */
    CLOCK_IP_DEV_ASSERT(((Finput * 1000U / Fsafe) - 1U)      < CLOCK_IP_MAX_REGISTER_VALUE); /* Overflow check for DivEndValue */
#endif

    Sdur = (uint32)(CLOCK_IP_STEP_DURATION_MICROSECONDS * Fsafe / CLOCK_IP_CONVERT_MICROSECONDS_TO_SECONDS);
    DivcInit = (uint32)(Rate * K);
    DivcRate = (uint32)(Rate);
    DivStartValue = (uint32)(999U + ((Rate * K * (K+1U)) >> 1U));
    DivEndValue = (uint32)((Finput * 1000U / Fsafe) - 1U);

    SelectorValue      = Clock_Ip_au16SelectorEntryHardwareValue[Source];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    SelectorEntry      =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    SelectorMask       =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelMask;
    SelectorShift      =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].SelShift;
    HwAddr             =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;
    HwPcfsArray        =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].PcfsAddress;
    Instance           =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Instance;

    RegisterAccess
    (
        REGISTER_ACCESS__WRITE,                                                      /* Register access: read modify write */
        CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_STEP_DURATION_VALUE, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_STEP_DURATION_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        &(*Clock_Ip_SwitchDuration[Instance]),                                       /* Register address. */
        NULL_PTR,                                                                    /* Register address read-only. */
        MC_CGM_PCFS_SDUR_SDUR_MASK,                                                  /* Register mask. */
        MC_CGM_PCFS_SDUR_SDUR(Sdur),                                                 /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_WRITE_PCFS_STEP_DURATION_VALUE                             /* Update hardware state */
    );

    RegisterAccess
    (
        REGISTER_ACCESS__WRITE,                                                      /* Register access: read modify write */
        CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_CHANGE_RATE_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        &(*HwPcfsArray)[SelectorValue - 1U].DividerChange,                           /* Register address. */
        NULL_PTR,                                                                    /* Register address read-only. */
        MC_CGM_PCFS_DIVC_RATE_MASK | MC_CGM_PCFS_DIVC_INIT_MASK,                     /* Register mask. */
        MC_CGM_PCFS_DIVC_RATE(DivcRate) | MC_CGM_PCFS_DIVC_INIT(DivcInit),           /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_WRITE_PCFS_CHANGE_RATE_VALUE                               /* Update hardware state */
    );

    RegisterAccess
    (
        REGISTER_ACCESS__WRITE,                                                      /* Register access: read modify write */
        CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_START_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        &(*HwPcfsArray)[SelectorValue - 1U].DividerStart,                            /* Register address. */
        NULL_PTR,                                                                    /* Register address read-only. */
        MC_CGM_PCFS_DIVS_DIVS_MASK,                                                  /* Register mask. */
        MC_CGM_PCFS_DIVS_DIVS(DivStartValue),                                         /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_WRITE_PCFS_DIVIDER_START_VALUE                               /* Update hardware state */
    );


    RegisterAccess
    (
        REGISTER_ACCESS__WRITE,                                                      /* Register access: read modify write */
        CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE - CLOCK_IP_SET_SELECTOR_001_WRITE_PCFS_DIVIDER_END_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        &(*HwPcfsArray)[SelectorValue - 1U].DividerEnd,                              /* Register address. */
        NULL_PTR,                                                                    /* Register address read-only. */
        MC_CGM_PCFS_DIVE_DIVE_MASK,                                                  /* Register mask. */
        MC_CGM_PCFS_DIVE_DIVE(DivEndValue),                                          /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_WRITE_PCFS_DIVIDER_END_VALUE                               /* Update hardware state */
    );



    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
-------------->     CHECK: Selector is already set to value from configuration.           /\
-------------->      - Yes, go to end                                                    /  \
-------------->      - No, continue to configure selector.                              /    \    Yes
-------------->                                                                        /      \____________________________________
-------------->     Check hardware state:                                              \      /                                    ||
-------------->     CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                              \    /                                     ||
-------------->     Offset in diagram state machine:                                     \  /                                      ||
-------------->     CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                        \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
                CHECK: Previous selector configuration is in progress.                    \/                                       ||
                 - Yes, wait for selector to complete.                                    /\                                       ||
                 - No, continue to configure selector.                                   /  \                                      ||
                                                                                        /    \                                     ||
                Check hardware state:                                                  /      \_________________                   ||
                CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS              \      /               ||                   ||
                Offset in diagram state machine:                                        \    /                ||                   ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
                CHECK: Timeout for previous selector configuration which is still in progress.               /  \                  ||
                 - Yes, go to end                                                         ||                /    \    Yes          ||
                 - No, continue to configure selector.                                    ||               /      \_________       ||
                                                                                          ||               \      /       ||       ||
                Check hardware state:                                                     ||                \    /        ||       ||
                CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS            || No              \  /         ||       ||
                Offset in diagram state machine:                                          ||                  \/          ||       ||
                CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
                WRITE: Configure selector.                                      |                    |        ||          ||       ||
                                                                                |                    |/_______||          ||       ||
                Update hardware state:                                          |                    |\                   ||       ||
                CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                          |                    |                    ||       ||
                Offset in diagram state machine:                                |---------------------                    ||       ||
                CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                              ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE */
    /* Do not configure mux if it is already set to the selector value from configuration. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       /* Register access: check a bitfield from register */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE,                            /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS - CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        SelectorMask,                                                                /* Register mask. */
        SelectorValue << SelectorShift,                                              /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                       /* Check hardware state */
    );

    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
                CHECK: Selector is already set to value from configuration.               /\
                 - Yes, go to end                                                        /  \
                 - No, continue to configure selector.                                  /    \    Yes
                                                                                       /      \____________________________________
                Check hardware state:                                                  \      /                                    ||
                CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                  \    /                                     ||
                Offset in diagram state machine:                                         \  /                                      ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                            \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
-------------->     CHECK: Previous selector configuration is in progress.                \/                                       ||
-------------->      - Yes, wait for selector to complete.                                /\                                       ||
-------------->      - No, continue to configure selector.                               /  \                                      ||
-------------->                                                                         /    \                                     ||
-------------->     Check hardware state:                                              /      \_________________                   ||
-------------->     CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS          \      /               ||                   ||
-------------->     Offset in diagram state machine:                                    \    /                ||                   ||
-------------->     CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS          \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
                CHECK: Timeout for previous selector configuration which is still in progress.               /  \                  ||
                 - Yes, go to end                                                         ||                /    \    Yes          ||
                 - No, continue to configure selector.                                    ||               /      \_________       ||
                                                                                          ||               \      /       ||       ||
                Check hardware state:                                                     ||                \    /        ||       ||
                CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS            || No              \  /         ||       ||
                Offset in diagram state machine:                                          ||                  \/          ||       ||
                CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
                WRITE: Configure selector.                                      |                    |        ||          ||       ||
                                                                                |                    |/_______||          ||       ||
                Update hardware state:                                          |                    |\                   ||       ||
                CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                          |                    |                    ||       ||
                Offset in diagram state machine:                                |---------------------                    ||       ||
                CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                              ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS */
    /* Check CLK_SW is cleared */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       /* Register access: check a bitfield from register */
        CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS - CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE - CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS,                           /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                          /* Check hardware state */
    );


    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
                CHECK: Selector is already set to value from configuration.               /\
                 - Yes, go to end                                                        /  \
                 - No, continue to configure selector.                                  /    \    Yes
                                                                                       /      \____________________________________
                Check hardware state:                                                  \      /                                    ||
                CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                  \    /                                     ||
                Offset in diagram state machine:                                         \  /                                      ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                            \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
                CHECK: Previous selector configuration is in progress.                    \/                                       ||
                 - Yes, wait for selector to complete.                                    /\                                       ||
                 - No, continue to configure selector.                                   /  \                                      ||
                                                                                        /    \                                     ||
                Check hardware state:                                                  /      \_________________                   ||
                CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS              \      /               ||                   ||
                Offset in diagram state machine:                                        \    /                ||                   ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
-------------->     CHECK: Timeout for previous selector configuration which is still in progress.           /  \                  ||
-------------->      - Yes, go to end                                                     ||                /    \    Yes          ||
-------------->      - No, continue to configure selector.                                ||               /      \_________       ||
-------------->                                                                           ||               \      /       ||       ||
-------------->     Check hardware state:                                                 ||                \    /        ||       ||
-------------->     CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS        || No              \  /         ||       ||
-------------->     Offset in diagram state machine:                                      ||                  \/          ||       ||
-------------->     CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
                WRITE: Configure selector.                                      |                    |        ||          ||       ||
                                                                                |                    |/_______||          ||       ||
                Update hardware state:                                          |                    |\                   ||       ||
                CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                          |                    |                    ||       ||
                Offset in diagram state machine:                                |---------------------                    ||       ||
                CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                              ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS */
    /* Wait for CLK_SW to auto-clear */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_TIMEOUT,                         /* Register access: check a bitfield from register */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS,              /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE - CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS,  /* The second branch offset */
        REGISTER_ACCESS__TIMEOUT_EVENT,                                              /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               /* Check hardware state */
    );

    /*
                                                                                     ____________
                                                                                    /            \
                                                                                   |    START     |
                                                                                    \____________/
                                                                                          ||
                                                                                          \/
                CHECK: Selector is already set to value from configuration.               /\
                 - Yes, go to end                                                        /  \
                 - No, continue to configure selector.                                  /    \    Yes
                                                                                       /      \____________________________________
                Check hardware state:                                                  \      /                                    ||
                CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE                                  \    /                                     ||
                Offset in diagram state machine:                                         \  /                                      ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_SELECTOR_VALUE                            \/                                       ||
                                                                                          ||                                       ||
                                                                                          ||                                       ||
                                                                                          ||  No                                   ||
                CHECK: Previous selector configuration is in progress.                    \/                                       ||
                 - Yes, wait for selector to complete.                                    /\                                       ||
                 - No, continue to configure selector.                                   /  \                                      ||
                                                                                        /    \                                     ||
                Check hardware state:                                                  /      \_________________                   ||
                CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS              \      /               ||                   ||
                Offset in diagram state machine:                                        \    /                ||                   ||
                CLOCK_IP_SET_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /                 ||                   ||
                                                                                          \/                  ||  Yes              ||
                                                                                          ||                  \/                   ||
                                                                                          ||                  /\                   ||
                CHECK: Timeout for previous selector configuration which is still in progress.               /  \                  ||
                 - Yes, go to end                                                         ||                /    \    Yes          ||
                 - No, continue to configure selector.                                    ||               /      \_________       ||
                                                                                          ||               \      /       ||       ||
                Check hardware state:                                                     ||                \    /        ||       ||
                CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS            || No              \  /         ||       ||
                Offset in diagram state machine:                                          ||                  \/          ||       ||
                CLOCK_IP_SET_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||                  ||  No      ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          ||                  ||          ||       ||
                                                                                          \/                  ||          ||       ||
                                                                                ---------------------|        ||          ||       ||
-------------->     WRITE: Configure selector.                                  |                    |        ||          ||       ||
-------------->                                                                 |                    |/_______||          ||       ||
-------------->     Update hardware state:                                      |                    |\                   ||       ||
-------------->     CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                      |                    |                    ||       ||
-------------->     Offset in diagram state machine:                            |---------------------                    ||       ||
-------------->     CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE                          ||                              ||       ||
                                                                                          ||                              ||       ||
                                                                                     _____\/_____                         ||       ||
                                                                                    /            \                        ||       ||
                                                                                   |      END     |/______________________||       ||
                                                                                    \____________/ \                               ||
                                                                                          /\                                       ||
                                                                                          ||_______________________________________||
    */

    /* All the PCFS commands should be atomic in nature (i.e. a single register write should provide a complete PCFS sequence
     * to be executed, that is ramp-down, clock switch, and ramp-up. It is necessary to set both RAMPUP and RAMPDOWN bits
     * together even if you want to trigger either RAMPUP or RAMPDOWN process, otherwise the PCFS effect will not manifest. */

    /* CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE */
    /* Set selector value. */
    RegisterAccess
    (
        REGISTER_ACCESS__READ_MODIFY_WRITE,                                          /* Register access: read modify write */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE, /* The first branch offset */
        CLOCK_IP_SET_SELECTOR_001_RETURN - CLOCK_IP_SET_SELECTOR_001_SET_SELECTOR_VALUE, /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* No event to be reported */
        &HwAddr->SetSelectorValue,                                                   /* Register address. */
        NULL_PTR,                                                                    /* Register address read-only. */
        (SelectorMask),                                                              /* Register mask. */
        ((SelectorValue << SelectorShift) | CLOCK_IP_MC_CGM_MUX_CSC_CLK_SW_MASK | CLOCK_IP_MC_CGM_MUX_CSC_RMP_SW_MASK),    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_SET_TYPE,                                                           /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                             /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE                                       /* Update hardware state */
    );
    /* CLOCK_IP_SET_SELECTOR_001_RETURN */

}
static void Clock_Ip_Wait_Optimized_CgmXCscCssClkSwSwtrigSwipRmpSw(void)
{
    uint32 SelectorEntry            =  Clock_Ip_au16ClockFeatures[Clock_Ip_SelectorName][CLOCK_LLD_SELECTOR_ENTRY];
    Clock_Ip_HwSelectorType *HwAddr =  Clock_Ip_axSelectorsDividersTable[SelectorEntry].Address;


    /*
                                                                                          ____________
                                                                                         /            \
                                                                                        |    START     |
                                                                                         \____________/
                                                                                               ||
                                                                                               ||
                                                                                               ||  No
-------------->     CHECK: Selector configuration is in progress.                              \/
-------------->      - Yes, wait for selector to complete.                                     /\
-------------->      - No, continue to further checkings.                                     /  \
-------------->                                                                              /    \        Yes
-------------->     Check hardware state:                                                   /      \__________
-------------->     CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               \      /        ||
-------------->     Offset in diagram state machine:                                         \    /         ||
-------------->     CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /          ||
                                                                                               \/           ||
                                                                                               ||           \/
                                                                                               ||           /\
                    CHECK: Timeout for selector configuration which is still in progress.      ||          /  \
                     - Yes, go to end                                                          ||         /    \   Yes
                     - No, continue to further checkings.                                      ||        /      \______
                                                                                               ||        \      /    ||
                    Check hardware state:                                                      ||         \    /     ||
                    CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS             || No       \  /      ||
                    Offset in diagram state machine:                                           ||           \/       ||
                    CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||          //  No    ||
                                                                                               ||         //         ||
                                                                                               ||        //          ||
                                                                                               ||       //           ||
                                                                                               ||      //            ||
                                                                                               ||     //             ||
                                                                                               ||    //              ||
                                                                                               ||   //               ||
                                                                                               ||  //                ||
                                                                                               || //                 ||
                                                                                               ||//                  ||
                                                                                               |//                   ||
                                                                                               ||  No                ||
                    CHECK: Clock switch status.                                                \/                    ||
                     - Yes, switch after request succeeded.                                    /\                    ||
                     - No, go to end.                                                         /  \                   ||
                                                                                             /    \        Yes       ||
                    Check hardware state:                                                   /      \__________       ||
                    CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                     \      /          ||     ||
                    Offset in diagram state machine:                                         \    /           ||     ||
                    CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /            ||     ||
                                                                                               \/             ||     ||
                                                                                               || No          /|     /|
                                                                                               ||            //     //
                                                                                          _____\/_____      //     //
                                                                                         /            \    //     //
                                                                                        |      END     |/_//_____//
                                                                                         \____________/ \
    */



    /* CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS */
    /* Wait for acknowledge to be cleared. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE,                                       /* Register access: check a bitfield from register */
        CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS - CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS, /* The first branch offset */
        CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS - CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS,                          /* The second branch offset */
        REGISTER_ACCESS__NO_EVENT,                                                   /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_WAIT_TYPE,                                                          /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                            /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                          /* Check hardware state */
    );


    /*
                                                                                          ____________
                                                                                         /            \
                                                                                        |    START     |
                                                                                         \____________/
                                                                                               ||
                                                                                               ||
                                                                                               ||  No
                    CHECK: Selector configuration is in progress.                              \/
                     - Yes, wait for selector to complete.                                     /\
                     - No, continue to further checkings.                                     /  \
                                                                                             /    \        Yes
                    Check hardware state:                                                   /      \__________
                    CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               \      /        ||
                    Offset in diagram state machine:                                         \    /         ||
                    CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /          ||
                                                                                               \/           ||
                                                                                               ||           \/
                                                                                               ||           /\
-------------->     CHECK: Timeout for selector configuration which is still in progress.      ||          /  \
-------------->      - Yes, go to end                                                          ||         /    \   Yes
-------------->      - No, continue to further checkings.                                      ||        /      \______
-------------->                                                                                ||        \      /    ||
-------------->     Check hardware state:                                                      ||         \    /     ||
-------------->     CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS             || No       \  /      ||
-------------->     Offset in diagram state machine:                                           ||           \/       ||
-------------->     CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||          //  No    ||
                                                                                               ||         //         ||
                                                                                               ||        //          ||
                                                                                               ||       //           ||
                                                                                               ||      //            ||
                                                                                               ||     //             ||
                                                                                               ||    //              ||
                                                                                               ||   //               ||
                                                                                               ||  //                ||
                                                                                               || //                 ||
                                                                                               ||//                  ||
                                                                                               |//                   ||
                                                                                               ||  No                ||
                    CHECK: Clock switch status.                                                \/                    ||
                     - Yes, switch after request succeeded.                                    /\                    ||
                     - No, go to end.                                                         /  \                   ||
                                                                                             /    \        Yes       ||
                    Check hardware state:                                                   /      \__________       ||
                    CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                     \      /          ||     ||
                    Offset in diagram state machine:                                         \    /           ||     ||
                    CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /            ||     ||
                                                                                               \/             ||     ||
                                                                                               || No          /|     /|
                                                                                               ||            //     //
                                                                                          _____\/_____      //     //
                                                                                         /            \    //     //
                                                                                        |      END     |/_//_____//
                                                                                         \____________/ \
    */


    /* CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS */
    /* Check the switch status. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_TIMEOUT,                         /* Register access: check a bitfield from register */
        CLOCK_IP_WAIT_SELECTOR_001_RETURN - CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS,              /* The first branch offset */
        CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS - CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS, /* The second branch offset */
        REGISTER_ACCESS__TIMEOUT_EVENT,                                              /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_MASK,                                           /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWIP_IN_PROGRESS,                                    /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_WAIT_TYPE,                                                          /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                            /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS               /* Check hardware state */
    );


    /*
                                                                                            ____________
                                                                                           /            \
                                                                                          |    START     |
                                                                                           \____________/
                                                                                                 ||
                                                                                                 ||
                                                                                                 ||  No
-------------->     CHECK: Selector configuration is in progress.                                \/
-------------->      - Yes, wait for selector to complete.                                       /\
-------------->      - No, continue to further checkings.                                       /  \
-------------->                                                                                /    \        Yes
-------------->     Check hardware state:                                                     /      \__________
-------------->     CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_STILL_IN_PROGRESS                 \      /        ||
-------------->     Offset in diagram state machine:                                           \    /         ||
-------------->     CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                \  /          ||
                                                                                                 \/           ||
                                                                                                 ||           \/
                                                                                                 ||           /\
                      CHECK: Timeout for selector configuration which is still in progress.      ||          /  \
                       - Yes, go to end                                                          ||         /    \   Yes
                       - No, continue to further checkings.                                      ||        /      \______
                                                                                                 ||        \      /    ||
                      Check hardware state:                                                      ||         \    /     ||
                      CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS             || No       \  /      ||
                      Offset in diagram state machine:                                           ||           \/       ||
                      CLOCK_IP_WAIT_SELECTOR_001_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS    ||          //  No    ||
                                                                                                 ||         //         ||
                                                                                                 ||        //          ||
                                                                                                 ||       //           ||
                                                                                                 ||      //            ||
                                                                                                 ||     //             ||
                                                                                                 ||    //              ||
                                                                                                 ||   //               ||
                                                                                                 ||  //                ||
                                                                                                 || //                 ||
                                                                                                 ||//                  ||
                                                                                                 |//                   ||
                                                                                                 ||  No                ||
                      CHECK: Clock switch status.                                                \/                    ||
                      - Yes, switch after request succeeded.                                     /\                    ||
                      - No, go to end.                                                          /  \                   ||
                                                                                               /    \        Yes       ||
                      Check hardware state:                                                   /      \__________       ||
                      CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS                     \      /          ||     ||
                      Offset in diagram state machine:                                         \    /           ||     ||
                      CLOCK_IP_WAIT_SELECTOR_001_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS              \  /            ||     ||
                                                                                                 \/             ||     ||
                                                                                                 || No          /|     /|
                                                                                                 ||            //     //
                                                                                            _____\/_____      //     //
                                                                                           /            \    //     //
                                                                                          |      END     |/_//_____//
                                                                                           \____________/ \
    */




    /* CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS */
    /* Check the switch status. */
    RegisterAccess
    (
        REGISTER_ACCESS__CHECK_NOT_REGISTER_VALUE__WITH_EVENT,                       /* Register access: check a bitfield from register */
        CLOCK_IP_WAIT_SELECTOR_001_RETURN - CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS, /* The first branch offset */
        CLOCK_IP_WAIT_SELECTOR_001_RETURN - CLOCK_IP_WAIT_SELECTOR_001_CHECK_SWITCH_STATUS, /* The second branch offset */
        REGISTER_ACCESS__MUX_SWITCH_ERROR_EVENT,                                     /* Timeout event to be reported */
        NULL_PTR,                                                                    /* Register address. */
        &HwAddr->GetSelectorValue,                                                   /* Register address read-only. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_MASK,                                          /* Register mask. */
        CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED,                                     /* Register value. */
        Clock_Ip_SelectorName,                                                       /* Clock Name by which selector identified. */
        CLOCK_IP_SELECTOR_TYPE,                                                      /* Type of the resource. */
        CLOCK_IP_WAIT_TYPE,                                                          /* Operation type, service routine type. */
        0U,                                                                          /* Index of the buffer. */
        CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE,                            /* Name of the function/service routine where register is accessed. */
        CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_STATUS                                  /* Check hardware state */
    );
}
#endif
#ifdef CLOCK_IP_RTC_RTCC_CLKSELECT
static void Clock_Ip_SetRtcRtccClksel(Clock_Ip_NameType Source)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_SetRtcRtccClksel_TrustedCall,(Source));
  #else
    Clock_Ip_SetRtcRtccClksel_TrustedCall(Source);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
#endif


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CLOCK_IP_RTC_RTCC_CLKSELECT
void Clock_Ip_SetRtcRtccClksel_TrustedCall(Clock_Ip_NameType Source)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryRtcHardwareValue[Source];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */
    /* CLKSEL may only be updated when CNTEN is 0. */
    if (0U == ((IP_LPE_RTC->RTCC & RTC_RTCC_CNTEN_MASK) >> RTC_RTCC_CNTEN_SHIFT))
    {
        RegValue = IP_LPE_RTC->RTCC;
        RegValue &= ~RTC_RTCC_CLKSEL_MASK;
        RegValue |= RTC_RTCC_CLKSEL(SelectorValue);
        IP_LPE_RTC->RTCC = RegValue;
    }
    else
    {
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_CLOCK_MUX_SWITCH_ERROR, RR_RTC_CLK);
    }
}
#endif
/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_SelectorCallbackType Clock_Ip_axSelectorCallbacks[CLOCK_IP_SELECTOR_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackSelectorEmptyName,                     /* SetName */
        &Clock_Ip_CallbackSelectorEmpty1,                        /* Reset */
        &Clock_Ip_CallbackSelectorEmpty4,                        /* SetOptionalParameter */
        &Clock_Ip_CallbackSelectorEmpty5,                        /* Set */
        &Clock_Ip_CallbackSelectorEmpty1,                        /* Wait */
        &Clock_Ip_CallbackSelectorEmpty5,                        /* Switch */
        &Clock_Ip_CallbackSelectorEmpty6,                        /* GetSelectorEntries */
        &Clock_Ip_CallbackSelectorEmpty7,                        /* GetDividerChildren */
        &Clock_Ip_CallbackSelectorEmpty2,                        /* GetSources */
        &Clock_Ip_CallbackSelectorEmpty3,                        /* GetStatus */
        &Clock_Ip_CallbackSelectorEmpty5,                        /* Set_Optimized */
        &Clock_Ip_CallbackSelectorEmpty1,                        /* Wait_Optimized */
    },
#ifdef CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP
    {
        &Clock_Ip_SetNameCgmXCscCssClkSwSwtrigSwip,                            /* SetName */
        &Clock_Ip_ResetCgmXCscCssClkSwSwtrigSwip,                              /* Reset */
        &Clock_Ip_SetOptionalParameterCgmXCscCssClkSwSwtrigSwip,               /* SetOptionalParameter */
        &Clock_Ip_SetCgmXCscCssClkSwSwtrigSwip,                                /* Set */
        &Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwip,                               /* Wait */
        &Clock_Ip_SwitchCgmXCscCssClkSwSwtrigSwip,                             /* Switch */
        &Clock_Ip_GetSelectorEntriesCgmXCscCssClkSwSwtrigSwip,                 /* GetSelectorEntries */
        &Clock_Ip_GetDividerChildrenCgmXCscCssClkSwSwtrigSwip,                 /* GetDividerChildren */
        &Clock_Ip_GetSourceCgmXCscCssClkSwSwtrigSwip,                          /* GetSources */
        &Clock_Ip_GetStatusCgmXCscCssClkSwSwtrigSwip,                          /* GetStatus */
        &Clock_Ip_Set_Optimized_CgmXCscCssClkSwSwtrigSwip,                     /* Set_Optimized */
        &Clock_Ip_Wait_Optimized_CgmXCscCssClkSwSwtrigSwip,                    /* Wait_Optimized */
    },
#endif
#ifdef CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP_RMP_SW
    {
        &Clock_Ip_SetNameCgmXCscCssClkSwSwtrigSwipRmpSw,                            /* SetName */
        &Clock_Ip_ResetCgmXCscCssClkSwSwtrigSwipRmpSw,                              /* Reset */
        &Clock_Ip_SetOptionalParameterCgmXCscCssClkSwSwtrigSwipRmpSw,               /* SetOptionalParameter */
        &Clock_Ip_SetCgmXCscCssClkSwSwtrigSwipRmpSw,                                /* Set */
        &Clock_Ip_WaitCgmXCscCssClkSwSwtrigSwipRmpSw,                               /* Wait */
        &Clock_Ip_SwitchCgmXCscCssClkSwSwtrigSwipRmpSw,                             /* Switch */
        &Clock_Ip_GetSelectorEntriesCgmXCscCssClkSwSwtrigSwipRmpSw,                 /* GetSelectorEntries */
        &Clock_Ip_GetDividerChildrenCgmXCscCssClkSwSwtrigSwipRmpSw,                 /* GetDividerChildren */
        &Clock_Ip_GetSourceCgmXCscCssClkSwSwtrigSwipRmpSw,                          /* GetSources */
        &Clock_Ip_GetStatusCgmXCscCssClkSwSwtrigSwipRmpSw,                          /* GetStatus */
        &Clock_Ip_Set_Optimized_CgmXCscCssClkSwSwtrigSwipRmpSw,                     /* Set_Optimized */
        &Clock_Ip_Wait_Optimized_CgmXCscCssClkSwSwtrigSwipRmpSw,                    /* Wait_Optimized */
    },
#endif
#ifdef CLOCK_IP_RTC_RTCC_CLKSELECT
    {
        &Clock_Ip_CallbackSelectorEmptyName,                     /* SetName */
        &Clock_Ip_CallbackSelectorEmpty1,                        /* Reset */
        &Clock_Ip_CallbackSelectorEmpty4,                        /* SetOptionalParameter */
        &Clock_Ip_SetRtcRtccClksel,                              /* Set */
        &Clock_Ip_CallbackSelectorEmpty1,                        /* Wait */
        &Clock_Ip_CallbackSelectorEmpty5,                        /* Switch */
        &Clock_Ip_CallbackSelectorEmpty6,                        /* GetSelectorEntries */
        &Clock_Ip_CallbackSelectorEmpty7,                        /* GetDividerChildren */
        &Clock_Ip_CallbackSelectorEmpty2,                        /* GetSources */
        &Clock_Ip_CallbackSelectorEmpty3,                        /* GetStatus */
        &Clock_Ip_CallbackSelectorEmpty5,                        /* Set_Optimized */
        &Clock_Ip_CallbackSelectorEmpty1,                        /* Wait_Optimized */
    },
#endif
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

