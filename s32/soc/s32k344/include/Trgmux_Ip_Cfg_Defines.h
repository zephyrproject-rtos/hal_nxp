/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef TRGMUX_IP_CFG_DEFINES_H_
#define TRGMUX_IP_CFG_DEFINES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "BasicTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_CFG_DEFINES_VENDOR_ID                    43
#define TRGMUX_IP_CFG_DEFINES_MODULE_ID                    255
#define TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION             3
#define TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Trgmux_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*===============================================================================================
					DEFINES AND MACROS
===============================================================================================*/
/*-----------------------------------------------/
/  TRGMUX IP SUPPORT                             /
/-----------------------------------------------*/

#define TRGMUX_IP_IS_AVAILABLE                   STD_ON

#define TRGMUX_IP_MULTICORE_IS_AVAILABLE         STD_OFF
/*-----------------------------------------------/
/  TRGMUX INSTANCE NUMBER                        /
/-----------------------------------------------*/
#define TRGMUX_IP_NOF_INSTANCE                   ((uint32)1U)

#define TRGMUX_IP_NOF_CFG_LOGIC_TRIGGERS         ((uint32)4U)
/*-----------------------------------------------/
/  TRGMUX IP USER MODE SUPPORT                    /
/-----------------------------------------------*/
#define TRGMUX_IP_USER_MODE_SUPPORT_IS_AVAILABLE STD_OFF
/*-----------------------------------------------/
/  TRGMUX IP DEV ERROR DETECT SUPPORT            /
/-----------------------------------------------*/
#define TRGMUX_IP_DEV_ERROR_DETECT               STD_OFF

/*-----------------------------------------------/
/  TRGMUX HARDWARE INSTANCE                      /
/-----------------------------------------------*/
#define TRGMUX_IP_HW_INST_0                      ((uint8)0U)
#define TRGMUX_IP_HW_INST_1                      ((uint8)1U)

/*-----------------------------------------------/
/  TRGMUX HARDWARE TRIGGER INPUT                 /
/-----------------------------------------------*/
#define TRGMUX_IP_INPUT_LOGIC0_VSS               ((uint8)0U)
#define TRGMUX_IP_INPUT_LOGIC1_VDD               ((uint8)1U)
#define TRGMUX_IP_INPUT_ADC0_EOC                 ((uint8)2U)
#define TRGMUX_IP_INPUT_ADC1_EOC                 ((uint8)3U)
#define TRGMUX_IP_INPUT_ADC2_EOC                 ((uint8)4U)
#define TRGMUX_IP_INPUT_CMP0_COUT                ((uint8)5U)
#define TRGMUX_IP_INPUT_CMP1_COUT                ((uint8)6U)
#define TRGMUX_IP_INPUT_CMP2_COUT                ((uint8)7U)
#define TRGMUX_IP_INPUT_EDMA_CH0                 ((uint8)8U)
#define TRGMUX_IP_INPUT_EDMA_CH1                 ((uint8)9U)
#define TRGMUX_IP_INPUT_EDMA_CH16                ((uint8)10U)
#define TRGMUX_IP_INPUT_EDMA_CH17                ((uint8)11U)
#define TRGMUX_IP_INPUT_EMIOS0_RELOAD_OUT_CH23   ((uint8)12U)
#define TRGMUX_IP_INPUT_EMIOS0_RELOAD_OUT_CH22   ((uint8)13U)
#define TRGMUX_IP_INPUT_EMIOS0_RELOAD_OUT_CH8    ((uint8)14U)
#define TRGMUX_IP_INPUT_EMIOS0_RELOAD_OUT_CH0    ((uint8)15U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH0           ((uint8)16U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH1           ((uint8)17U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH2           ((uint8)18U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH3           ((uint8)19U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH4           ((uint8)20U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH5           ((uint8)21U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH6           ((uint8)22U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH7           ((uint8)23U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH8           ((uint8)24U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH9           ((uint8)25U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH10          ((uint8)26U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH11          ((uint8)27U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH12          ((uint8)28U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH13          ((uint8)29U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH14          ((uint8)30U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH15          ((uint8)31U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH22          ((uint8)32U)
#define TRGMUX_IP_INPUT_EMIOS0_IPP_CH23          ((uint8)33U)
#define TRGMUX_IP_INPUT_EMIOS1_RELOAD_OUT_CH23   ((uint8)34U)
#define TRGMUX_IP_INPUT_EMIOS1_RELOAD_OUT_CH22   ((uint8)35U)
#define TRGMUX_IP_INPUT_EMIOS1_RELOAD_OUT_CH8    ((uint8)36U)
#define TRGMUX_IP_INPUT_EMIOS1_RELOAD_OUT_CH0    ((uint8)37U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH0           ((uint8)38U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH1           ((uint8)39U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH2           ((uint8)40U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH3           ((uint8)41U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH4           ((uint8)42U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH5           ((uint8)43U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH6           ((uint8)44U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH7           ((uint8)45U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH8           ((uint8)46U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH9           ((uint8)47U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH10          ((uint8)48U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH11          ((uint8)49U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH12          ((uint8)50U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH13          ((uint8)51U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH14          ((uint8)52U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH15          ((uint8)53U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH22          ((uint8)54U)
#define TRGMUX_IP_INPUT_EMIOS1_IPP_CH23          ((uint8)55U)
#define TRGMUX_IP_INPUT_FLEXIO_EXT_OUTPUT_TRIG_0 ((uint8)56U)
#define TRGMUX_IP_INPUT_FLEXIO_EXT_OUTPUT_TRIG_1 ((uint8)57U)
#define TRGMUX_IP_INPUT_FLEXIO_EXT_OUTPUT_TRIG_2 ((uint8)58U)
#define TRGMUX_IP_INPUT_FLEXIO_EXT_OUTPUT_TRIG_3 ((uint8)59U)
#define TRGMUX_IP_INPUT_SIUL2_IN0                ((uint8)60U)
#define TRGMUX_IP_INPUT_SIUL2_IN1                ((uint8)61U)
#define TRGMUX_IP_INPUT_SIUL2_IN2                ((uint8)62U)
#define TRGMUX_IP_INPUT_SIUL2_IN3                ((uint8)63U)
#define TRGMUX_IP_INPUT_SIUL2_IN4                ((uint8)64U)
#define TRGMUX_IP_INPUT_SIUL2_IN5                ((uint8)65U)
#define TRGMUX_IP_INPUT_SIUL2_IN6                ((uint8)66U)
#define TRGMUX_IP_INPUT_SIUL2_IN7                ((uint8)67U)
#define TRGMUX_IP_INPUT_SIUL2_IN8                ((uint8)68U)
#define TRGMUX_IP_INPUT_SIUL2_IN9                ((uint8)69U)
#define TRGMUX_IP_INPUT_SIUL2_IN10               ((uint8)70U)
#define TRGMUX_IP_INPUT_SIUL2_IN11               ((uint8)71U)
#define TRGMUX_IP_INPUT_SIUL2_IN12               ((uint8)72U)
#define TRGMUX_IP_INPUT_SIUL2_IN13               ((uint8)73U)
#define TRGMUX_IP_INPUT_SIUL2_IN14               ((uint8)74U)
#define TRGMUX_IP_INPUT_SIUL2_IN15               ((uint8)75U)
#define TRGMUX_IP_INPUT_LPI2C0_MASTER            ((uint8)76U)
#define TRGMUX_IP_INPUT_LPI2C0_SLAVE             ((uint8)77U)
#define TRGMUX_IP_INPUT_LPSPI0_END               ((uint8)78U)
#define TRGMUX_IP_INPUT_LPSPI0_RECEIVE           ((uint8)79U)
#define TRGMUX_IP_INPUT_LPSPI1_END               ((uint8)80U)
#define TRGMUX_IP_INPUT_LPSPI1_RECEIVE           ((uint8)81U)
#define TRGMUX_IP_INPUT_LPSPI2_END               ((uint8)82U)
#define TRGMUX_IP_INPUT_LPSPI2_RECEIVE           ((uint8)83U)
#define TRGMUX_IP_INPUT_LPUART0_TX               ((uint8)84U)
#define TRGMUX_IP_INPUT_LPUART0_RX               ((uint8)85U)
#define TRGMUX_IP_INPUT_LPUART0_RX_IDLE          ((uint8)86U)
#define TRGMUX_IP_INPUT_LPUART1_TX               ((uint8)87U)
#define TRGMUX_IP_INPUT_LPUART1_RX               ((uint8)88U)
#define TRGMUX_IP_INPUT_LPUART1_RX_IDLE          ((uint8)89U)
#define TRGMUX_IP_INPUT_LPUART2_TX               ((uint8)90U)
#define TRGMUX_IP_INPUT_LPUART2_RX               ((uint8)91U)
#define TRGMUX_IP_INPUT_LPUART2_RX_IDLE          ((uint8)92U)
#define TRGMUX_IP_INPUT_LCU0_LC0_OUT_I0          ((uint8)93U)
#define TRGMUX_IP_INPUT_LCU0_LC0_OUT_I1          ((uint8)94U)
#define TRGMUX_IP_INPUT_LCU0_LC0_OUT_I2          ((uint8)95U)
#define TRGMUX_IP_INPUT_LCU0_LC0_OUT_I3          ((uint8)96U)
#define TRGMUX_IP_INPUT_LCU0_LC1_OUT_I0          ((uint8)97U)
#define TRGMUX_IP_INPUT_LCU0_LC1_OUT_I1          ((uint8)98U)
#define TRGMUX_IP_INPUT_LCU0_LC1_OUT_I2          ((uint8)99U)
#define TRGMUX_IP_INPUT_LCU0_LC1_OUT_I3          ((uint8)100U)
#define TRGMUX_IP_INPUT_LCU0_LC2_OUT_I0          ((uint8)101U)
#define TRGMUX_IP_INPUT_LCU0_LC2_OUT_I1          ((uint8)102U)
#define TRGMUX_IP_INPUT_LCU0_LC2_OUT_I2          ((uint8)103U)
#define TRGMUX_IP_INPUT_LCU0_LC2_OUT_I3          ((uint8)104U)
#define TRGMUX_IP_INPUT_LCU1_LC0_OUT_I0          ((uint8)105U)
#define TRGMUX_IP_INPUT_LCU1_LC0_OUT_I1          ((uint8)106U)
#define TRGMUX_IP_INPUT_LCU1_LC0_OUT_I2          ((uint8)107U)
#define TRGMUX_IP_INPUT_LCU1_LC0_OUT_I3          ((uint8)108U)
#define TRGMUX_IP_INPUT_LCU1_LC1_OUT_I0          ((uint8)109U)
#define TRGMUX_IP_INPUT_LCU1_LC1_OUT_I1          ((uint8)110U)
#define TRGMUX_IP_INPUT_LCU1_LC1_OUT_I2          ((uint8)111U)
#define TRGMUX_IP_INPUT_LCU1_LC1_OUT_I3          ((uint8)112U)
#define TRGMUX_IP_INPUT_LCU1_LC2_OUT_I0          ((uint8)113U)
#define TRGMUX_IP_INPUT_LCU1_LC2_OUT_I1          ((uint8)114U)
#define TRGMUX_IP_INPUT_LCU1_LC2_OUT_I2          ((uint8)115U)
#define TRGMUX_IP_INPUT_LCU1_LC2_OUT_I3          ((uint8)116U)
#define TRGMUX_IP_INPUT_PIT0_CH0                 ((uint8)117U)
#define TRGMUX_IP_INPUT_PIT0_CH1                 ((uint8)118U)
#define TRGMUX_IP_INPUT_PIT0_CH2                 ((uint8)119U)
#define TRGMUX_IP_INPUT_PIT0_CH3                 ((uint8)120U)
#define TRGMUX_IP_INPUT_PIT0_CH4                 ((uint8)121U)
#define TRGMUX_IP_INPUT_PIT1_CH0                 ((uint8)122U)
#define TRGMUX_IP_INPUT_PIT1_CH1                 ((uint8)123U)
#define TRGMUX_IP_INPUT_PIT1_CH2                 ((uint8)124U)
#define TRGMUX_IP_INPUT_PIT1_CH3                 ((uint8)125U)
#define TRGMUX_IP_INPUT_CM7_0_TXEV               ((uint8)126U)
#define TRGMUX_IP_INPUT_CM7_1_TXEV               ((uint8)127U)
#define TRGMUX_IP_INPUT_CM7_2_TXEV               ((uint8)127U)


/*-----------------------------------------------/
/  TRGMUX HARDWARE TRIGGER OUTPUT                /
/-----------------------------------------------*/
#define TRGMUX_IP_OUTPUT_ADC12_0_EXTRG_NORMAL_CONV            ((uint8)0U)
#define TRGMUX_IP_OUTPUT_ADC12_0_EXTRG_INJECTED_CONV          ((uint8)1U)
#define TRGMUX_IP_OUTPUT_ADC12_0_EXTRG_SYNC_START_PULSE       ((uint8)2U)
#define TRGMUX_IP_OUTPUT_ADC12_1_EXTRG_NORMAL_CONV            ((uint8)4U)
#define TRGMUX_IP_OUTPUT_ADC12_1_EXTRG_INJECTED_CONV          ((uint8)5U)
#define TRGMUX_IP_OUTPUT_ADC12_1_EXTRG_SYNC_START_PULSE       ((uint8)6U)
#define TRGMUX_IP_OUTPUT_ADC12_2_EXTRG_NORMAL_CONV            ((uint8)8U)
#define TRGMUX_IP_OUTPUT_ADC12_2_EXTRG_INJECTED_CONV          ((uint8)9U)
#define TRGMUX_IP_OUTPUT_ADC12_2_EXTRG_SYNC_START_PULSE       ((uint8)10U)
#define TRGMUX_IP_OUTPUT_LPCMP_0_SAMPLE_WINDOW                ((uint8)12U)
#define TRGMUX_IP_OUTPUT_LPCMP_1_SAMPLE_WINDOW                ((uint8)16U)
#define TRGMUX_IP_OUTPUT_LPCMP_2_SAMPLE_WINDOW                ((uint8)20U)
#define TRGMUX_IP_OUTPUT_BCTU_TRG23                           ((uint8)24U)
#define TRGMUX_IP_OUTPUT_BCTU_TRG47                           ((uint8)25U)
#define TRGMUX_IP_OUTPUT_BCTU_TRG71                           ((uint8)26U)
#define TRGMUX_IP_OUTPUT_EMIOS012_ODIS0                       ((uint8)28U)
#define TRGMUX_IP_OUTPUT_EMIOS012_ODIS1                       ((uint8)29U)
#define TRGMUX_IP_OUTPUT_EMIOS012_ODIS2                       ((uint8)30U)
#define TRGMUX_IP_OUTPUT_EMIOS012_ODIS3                       ((uint8)31U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH1_4_IPP_IND_CH1             ((uint8)32U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH1_4_IPP_IND_CH2             ((uint8)33U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH1_4_IPP_IND_CH3             ((uint8)34U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH1_4_IPP_IND_CH4             ((uint8)35U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH5_9_IPP_IND_CH5             ((uint8)36U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH5_9_IPP_IND_CH6             ((uint8)37U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH5_9_IPP_IND_CH7             ((uint8)38U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH5_9_IPP_IND_CH9             ((uint8)39U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH10_13_IPP_IND_CH10          ((uint8)40U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH10_13_IPP_IND_CH11          ((uint8)41U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH10_13_IPP_IND_CH12          ((uint8)42U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH10_13_IPP_IND_CH13          ((uint8)43U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH14_15_IPP_IND_CH14          ((uint8)44U)
#define TRGMUX_IP_OUTPUT_EMIOS0_CH14_15_IPP_IND_CH15          ((uint8)45U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH1_4_IPP_IND_CH1             ((uint8)48U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH1_4_IPP_IND_CH2             ((uint8)49U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH1_4_IPP_IND_CH3             ((uint8)50U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH1_4_IPP_IND_CH4             ((uint8)51U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH5_9_IPP_IND_CH5             ((uint8)52U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH5_9_IPP_IND_CH6             ((uint8)53U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH5_9_IPP_IND_CH7             ((uint8)54U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH5_9_IPP_IND_CH9             ((uint8)55U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH10_13_IPP_IND_CH10          ((uint8)56U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH10_13_IPP_IND_CH11          ((uint8)57U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH10_13_IPP_IND_CH12          ((uint8)58U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH10_13_IPP_IND_CH13          ((uint8)59U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH14_15_IPP_IND_CH14          ((uint8)60U)
#define TRGMUX_IP_OUTPUT_EMIOS1_CH14_15_IPP_IND_CH15          ((uint8)61U)
#define TRGMUX_IP_OUTPUT_FLEXIO_EXT_IN_TRG0                   ((uint8)64U)
#define TRGMUX_IP_OUTPUT_FLEXIO_EXT_IN_TRG1                   ((uint8)65U)
#define TRGMUX_IP_OUTPUT_FLEXIO_EXT_IN_TRG2                   ((uint8)66U)
#define TRGMUX_IP_OUTPUT_FLEXIO_EXT_IN_TRG3                   ((uint8)67U)
#define TRGMUX_IP_OUTPUT_SIUL2_0_3_OUT0                       ((uint8)68U)
#define TRGMUX_IP_OUTPUT_SIUL2_0_3_OUT1                       ((uint8)69U)
#define TRGMUX_IP_OUTPUT_SIUL2_0_3_OUT2                       ((uint8)70U)
#define TRGMUX_IP_OUTPUT_SIUL2_0_3_OUT3                       ((uint8)71U)
#define TRGMUX_IP_OUTPUT_SIUL2_4_7_OUT4                       ((uint8)72U)
#define TRGMUX_IP_OUTPUT_SIUL2_4_7_OUT5                       ((uint8)73U)
#define TRGMUX_IP_OUTPUT_SIUL2_4_7_OUT6                       ((uint8)74U)
#define TRGMUX_IP_OUTPUT_SIUL2_4_7_OUT7                       ((uint8)75U)
#define TRGMUX_IP_OUTPUT_SIUL2_8_11_OUT8                      ((uint8)76U)
#define TRGMUX_IP_OUTPUT_SIUL2_8_11_OUT9                      ((uint8)77U)
#define TRGMUX_IP_OUTPUT_SIUL2_8_11_OUT10                     ((uint8)78U)
#define TRGMUX_IP_OUTPUT_SIUL2_8_11_OUT11                     ((uint8)79U)
#define TRGMUX_IP_OUTPUT_SIUL2_12_15_OUT12                    ((uint8)80U)
#define TRGMUX_IP_OUTPUT_SIUL2_12_15_OUT13                    ((uint8)81U)
#define TRGMUX_IP_OUTPUT_SIUL2_12_15_OUT14                    ((uint8)82U)
#define TRGMUX_IP_OUTPUT_SIUL2_12_15_OUT15                    ((uint8)83U)
#define TRGMUX_IP_OUTPUT_LPI2C0                               ((uint8)84U)
#define TRGMUX_IP_OUTPUT_LPSPI0                               ((uint8)88U)
#define TRGMUX_IP_OUTPUT_LPSPI1                               ((uint8)92U)
#define TRGMUX_IP_OUTPUT_LPSPI2                               ((uint8)96U)
#define TRGMUX_IP_OUTPUT_LPUART0                              ((uint8)100U)
#define TRGMUX_IP_OUTPUT_LPUART1                              ((uint8)104U)
#define TRGMUX_IP_OUTPUT_LPUART2                              ((uint8)108U)
#define TRGMUX_IP_OUTPUT_LPUART3                              ((uint8)112U)
#define TRGMUX_IP_OUTPUT_LCU0_SYNC0                           ((uint8)116U)
#define TRGMUX_IP_OUTPUT_LCU0_SYNC1                           ((uint8)117U)
#define TRGMUX_IP_OUTPUT_LCU0_FORCE0                          ((uint8)120U)
#define TRGMUX_IP_OUTPUT_LCU0_FORCE1                          ((uint8)121U)
#define TRGMUX_IP_OUTPUT_LCU0_FORCE2                          ((uint8)122U)
#define TRGMUX_IP_OUTPUT_LCU0_0_INP_I0                        ((uint8)124U)
#define TRGMUX_IP_OUTPUT_LCU0_0_INP_I1                        ((uint8)125U)
#define TRGMUX_IP_OUTPUT_LCU0_0_INP_I2                        ((uint8)126U)
#define TRGMUX_IP_OUTPUT_LCU0_0_INP_I3                        ((uint8)127U)
#define TRGMUX_IP_OUTPUT_LCU0_1_INP_I4                        ((uint8)128U)
#define TRGMUX_IP_OUTPUT_LCU0_1_INP_I5                        ((uint8)129U)
#define TRGMUX_IP_OUTPUT_LCU0_1_INP_I6                        ((uint8)130U)
#define TRGMUX_IP_OUTPUT_LCU0_1_INP_I7                        ((uint8)131U)
#define TRGMUX_IP_OUTPUT_LCU0_2_INP_I8                        ((uint8)132U)
#define TRGMUX_IP_OUTPUT_LCU0_2_INP_I9                        ((uint8)133U)
#define TRGMUX_IP_OUTPUT_LCU0_2_INP_I10                       ((uint8)134U)
#define TRGMUX_IP_OUTPUT_LCU0_2_INP_I11                       ((uint8)135U)
#define TRGMUX_IP_OUTPUT_LCU1_SYNC0                           ((uint8)136U)
#define TRGMUX_IP_OUTPUT_LCU1_SYNC1                           ((uint8)137U)
#define TRGMUX_IP_OUTPUT_LCU1_FORCE0                          ((uint8)140U)
#define TRGMUX_IP_OUTPUT_LCU1_FORCE1                          ((uint8)141U)
#define TRGMUX_IP_OUTPUT_LCU1_FORCE2                          ((uint8)142U)
#define TRGMUX_IP_OUTPUT_LCU1_0_INP_I0                        ((uint8)144U)
#define TRGMUX_IP_OUTPUT_LCU1_0_INP_I1                        ((uint8)145U)
#define TRGMUX_IP_OUTPUT_LCU1_0_INP_I2                        ((uint8)146U)
#define TRGMUX_IP_OUTPUT_LCU1_0_INP_I3                        ((uint8)147U)
#define TRGMUX_IP_OUTPUT_LCU1_1_INP_I4                        ((uint8)148U)
#define TRGMUX_IP_OUTPUT_LCU1_1_INP_I5                        ((uint8)149U)
#define TRGMUX_IP_OUTPUT_LCU1_1_INP_I6                        ((uint8)150U)
#define TRGMUX_IP_OUTPUT_LCU1_1_INP_I7                        ((uint8)151U)
#define TRGMUX_IP_OUTPUT_LCU1_2_INP_I8                        ((uint8)152U)
#define TRGMUX_IP_OUTPUT_LCU1_2_INP_I9                        ((uint8)153U)
#define TRGMUX_IP_OUTPUT_LCU1_2_INP_I10                       ((uint8)154U)
#define TRGMUX_IP_OUTPUT_LCU1_2_INP_I11                       ((uint8)155U)
#define TRGMUX_IP_OUTPUT_CM7_0_RXEV                           ((uint8)156U)
#define TRGMUX_IP_OUTPUT_CM7_1_RXEV                           ((uint8)157U)
#define TRGMUX_IP_OUTPUT_CM7_2_RXEV                           ((uint8)158U)

#endif  /* #ifndef TRGMUX_IP_CFG_DEFINES_H */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
