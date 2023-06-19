/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_HEADERWRAPPER_S32K3_H
#define ADC_SAR_IP_HEADERWRAPPER_S32K3_H

/**
*   @file
*
*   @addtogroup adc_sar_ip Adc Sar IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/* Important Note: This file cannot be used independently.
*  It depends on platform header files to be included before including it */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_HEADERWRAPPER_S32K3                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32K3       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32K3       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32K3    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32K3               3
#define ADC_SAR_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32K3               0
#define ADC_SAR_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32K3               0

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/

#define ADC_SAR_IP_NUM_GROUP_CHAN           (3U)
#define ADC_SAR_IP_CDR_COUNT                (96U)
#define ADC_SAR_IP_INSTANCE_COUNT           ADC_INSTANCE_COUNT
#define ADC_SAR_IP_THRHLR_COUNT             ADC_THRHLR_COUNT
#define ADC_SAR_IP_CWSELR_COUNT             (3U)
#define ADC_SAR_IP_MAX_RESOLUTION           (14U)
#define ADC_SAR_IP_RESULT_RESOLUTION        (15U) /* Resolution of the result written by the ADC module */
#define ADC_SAR_IP_HAS_THRHLR_ARRAY         (1U)
#define ADC_SAR_IP_HAS_CWSELR_UNROLLED      (0U)
#define ADC_SAR_IP_CALIBRATION_USES_MCR     (0U)

#define ADC_SAR_IP_PRESAMPLE_VREFL_EVAL     (0U)
#define ADC_SAR_IP_PRESAMPLE_VREFH_EVAL     (1U)

#define ADC_SAR_IP_HAS_ADCLKSEL               (1U)
#define ADC_SAR_IP_MSR_ADCSTATUS_POWER_DOWN   (1U)
#define ADC_SAR_IP_MSR_ADCSTATUS_IDLE         (0U)

#define FEATURE_ADC_BAD_ACCESS_PROT_FEATURE   (1U)
#define FEATURE_ADC_BAD_ACCESS_PROT_CHANNEL   (1U)
#define FEATURE_ADC_HAS_CTU_TRIGGER_MODE      (1U)
#define FEATURE_ADC_HAS_CTU                   (1U)
#define FEATURE_ADC_HAS_CLKSEL_EXTENDED       (1U)
#define FEATURE_ADC_SAR_W1C_ABORT             (1U)
#define FEATURE_ADC_HAS_TEMPSENSE_CHN         (1U)
#define FEATURE_ADC_SELFTEST_FULL_CLK         (0U)

#define FEATURE_ADC_HAS_SELFTEST_STCR1                    (1U)
#define FEATURE_ADC_HAS_SELFTEST_STCR3                    (1U)
#define FEATURE_ADC_HAS_BANDGAP_STATUS                    (0U)
#define FEATURE_ADC_HAS_SELFTEST_USE_CH32                 (0U)

#define FEATURE_ADC_ABORTCHAIN_WORKAROUND                 (0U)

#if (ADC_SAR_IP_INSTANCE_COUNT > 3U)
                                      /* 31-28   3-0  63-60  35-32 95-92  67-64
                                          \_/    \_/   \_/    \_/   \_/    \_/
                                           |......|     |......|     |......| */
#define FEATURE_ADC_CHN_AVAIL_BITMAP   {{0x000000FFU, 0x004FFFFFU, 0xFFFFFFFFU}, /* 0 */ \
                                        {0x000000FFU, 0x004FFFFFU, 0xFFFFFFFFU}, /* 1 */ \
                                        {0x000000FFU, 0x000FFFFFU, 0x00000000U}, /* 2 */ \
                                        {0x000000FFU, 0x000F000FU, 0x00000000U}, /* 3 */ \
                                        {0x000000FFU, 0x000F000FU, 0x00000000U}, /* 4 */ \
                                        {0x000000FFU, 0x000F000FU, 0x00000000U}, /* 5 */ \
                                        {0x000000FFU, 0x000F000FU, 0x00000000U}, /* 6 */ \
                                       }
                                      /* Adc Channels are divided into 3 Groups. */
                                      /* This array shows max number of channels of each group. */
                                      /* There are some registers that relate to this one: CEOCFR, CIMR, DMAR, PSR, NCMR, JCMR,... */
                                      /* Should be same with ADC_CDRx_COUNT in header file (from Base) */
#define FEATURE_ADC_MAX_CHN_COUNT      {{8U, 26U, 32U}, /* Adc HW Unit 0 */ \
                                        {8U, 26U, 32U}, /* Adc HW Unit 1 */ \
                                        {8U, 26U, 0U},  /* Adc HW Unit 2 */ \
                                        {8U, 26U, 0U},  /* Adc HW Unit 3 */ \
                                        {8U, 26U, 0U},  /* Adc HW Unit 4 */ \
                                        {8U, 26U, 0U},  /* Adc HW Unit 5 */ \
                                        {8U, 26U, 0U},  /* Adc HW Unit 6 */ \
                                       }
                                       /* Number of group channels of each unit */
                                       /* Unit 0 / 1 / 2 / 3 / 4 / 5 / 6 */
#define FEATURE_ADC_MAX_GROUP_COUNT    { 3U, 3U, 2U, 2U, 2U, 2U, 2U }
                                      /* Bit0: DSDR is available
                                         Bit1: PSCR is available
                                         Bit2: CTU is available */
#define FEATURE_ADC_FEAT_AVAIL_BITMAP   {0x00000007U, /* Adc HW Unit 0 */ \
                                         0x00000007U, /* Adc HW Unit 1 */ \
                                         0x00000006U, /* Adc HW Unit 2 */ \
                                         0x00000006U, /* Adc HW Unit 3 */ \
                                         0x00000006U, /* Adc HW Unit 4 */ \
                                         0x00000006U, /* Adc HW Unit 5 */ \
                                         0x00000006U, /* Adc HW Unit 6 */ \
                                        }
#elif (ADC_SAR_IP_INSTANCE_COUNT == 3U)
                                      /* 31-28   3-0  63-60  35-32 95-92  67-64
                                          \_/    \_/   \_/    \_/   \_/    \_/
                                           |......|     |......|     |......| */
#define FEATURE_ADC_CHN_AVAIL_BITMAP   {{0x000000FFU, 0x00C7FFFFU, 0xFFFFFFFFU}, /* 0 */ \
                                        {0x000000FFU, 0x00C3FFFFU, 0xFFFFFFFFU}, /* 1 */ \
                                        {0x000000FFU, 0x00C3FFFFU, 0x00000000U}, /* 2 */ \
                                       }
                                      /* Adc Channels are divided into 3 Groups. */
                                      /* This array shows max number of channels of each group. */
                                      /* There are some registers that relate to this one: CEOCFR, CIMR, DMAR, PSR, NCMR, JCMR,... */
                                      /* Should be same with ADC_CDRx_COUNT in header file (from Base) */
#define FEATURE_ADC_MAX_CHN_COUNT      {{8U, 24U, 32U}, /* Adc HW Unit 0 */ \
                                        {8U, 24U, 32U}, /* Adc HW Unit 1 */ \
                                        {8U, 24U, 0U},  /* Adc HW Unit 2 */ \
                                       }
                                       /* Number of group channels of each unit */
                                       /* Unit 0 / 1 / 2 */
#define FEATURE_ADC_MAX_GROUP_COUNT    { 3U, 3U, 2U }
                                      /* Bit0: DSDR is available
                                         Bit1: PSCR is available
                                         Bit2: CTU is available */
#define FEATURE_ADC_FEAT_AVAIL_BITMAP   {0x00000007U, /* Adc HW Unit 0 */ \
                                         0x00000007U, /* Adc HW Unit 1 */ \
                                         0x00000006U, /* Adc HW Unit 2 */ \
                                        }
#elif (ADC_SAR_IP_INSTANCE_COUNT == 2U)
                                      /* 31-28   3-0  63-60  35-32 95-92  67-64
                                          \_/    \_/   \_/    \_/   \_/    \_/
                                           |......|     |......|     |......| */
#define FEATURE_ADC_CHN_AVAIL_BITMAP   {{0x000000FFU, 0x00C7FFFFU, 0xFFFFFFFFU}, /* 0 */ \
                                        {0x000000FFU, 0x00C3FFFFU, 0xFFFFFFFFU}, /* 1 */ \
                                       }
                                      /* Adc Channels are divided into 3 Groups. */
                                      /* This array shows max number of channels of each group. */
                                      /* There are some registers that relate to this one: CEOCFR, CIMR, DMAR, PSR, NCMR, JCMR,... */
                                      /* Should be same with ADC_CDRx_COUNT in header file (from Base) */
#define FEATURE_ADC_MAX_CHN_COUNT      {{8U, 24U, 32U}, /* Adc HW Unit 0 */ \
                                        {8U, 24U, 32U}, /* Adc HW Unit 1 */ \
                                       }
                                       /* Number of group channels of each unit */
                                       /* Unit 0 / 1 */
#define FEATURE_ADC_MAX_GROUP_COUNT    { 3U, 3U }
                                      /* Bit0: DSDR is available
                                         Bit1: PSCR is available
                                         Bit2: CTU is available
                                         Bit3: CTU trigger mode is available */
#define FEATURE_ADC_FEAT_AVAIL_BITMAP   {0x0000000FU, /* Adc HW Unit 0 */ \
                                         0x0000000FU, /* Adc HW Unit 1 */ \
                                        }
#else
#error "Unknown platform!"
#endif /* (ADC_SAR_IP_INSTANCE_COUNT > 3U) */

/* Register access defines */
#define REG_ACCESS(reg, index)      (*(volatile uint32*)(&(((&(reg))[(index)]))))
#define REG_READ(reg, index)        (*(volatile const uint32*)(&(((&(reg))[(index)]))))

#define CEOCFR(base, regIndex)      REG_ACCESS((base)->CEOCFR0, (regIndex))
#define CIMR(base, regIndex)        REG_ACCESS((base)->CIMR0, (regIndex))
#define DMAR(base, regIndex)        REG_ACCESS((base)->DMAR0, (regIndex))
#define PSR(base, regIndex)         REG_ACCESS((base)->PSR0, (regIndex))
#define CTR(base, regIndex)         REG_ACCESS((base)->CTR0, (regIndex))
#define NCMR(base, regIndex)        REG_ACCESS((base)->NCMR0, (regIndex))
#define JCMR(base, regIndex)        REG_ACCESS((base)->JCMR0, (regIndex))
#define CWSELR(base, regIndex)      REG_ACCESS((base)->CWSELRPI[0U], (regIndex))
#define CWENR(base, regIndex)       REG_ACCESS((base)->CWENR0, (regIndex))
#define AWORR(base, regIndex)       REG_ACCESS((base)->AWORR0, (regIndex))
#define CDR(base, chanIndex)        REG_READ((base)->PCDR[0U], (chanIndex))

/* MCR */
#define ADC_MCR_CTU_MODE_MASK       ADC_MCR_BCTU_MODE_MASK
#define ADC_MCR_CTU_MODE(x)         ADC_MCR_BCTU_MODE(x)
#define ADC_MCR_CTUEN_MASK          ADC_MCR_BCTUEN_MASK
#define ADC_MCR_CTUEN(x)            ADC_MCR_BCTUEN(x)

/* MSR */
#define ADC_MSR_CTUSTART_MASK       ADC_MSR_BCTUSTART_MASK

/* ISR */
#define ADC_ISR_EOCTU_MASK          ADC_ISR_EOBCTU_MASK
#define ADC_ISR_EOCTU(x)            ADC_ISR_EOBCTU(x)

/* IMR */
#define ADC_IMR_MSKEOCTU_MASK       ADC_IMR_MSKEOBCTU_MASK
#define ADC_IMR_MSKEOCTU(x)         ADC_IMR_MSKEOBCTU(x)

/* CTR */
#define ADC_CTR_INPSAMP(x)          ADC_CTR0_INPSAMP(x)

/* NCMR */
#define ADC_NCMR_CH0(x)             ADC_NCMR0_CH0(x)

/* CDR */
#if defined(ADC_PCDR_CDATA_MASK)
#define ADC_CDR_CDATA_MASK          ADC_PCDR_CDATA_MASK
#define ADC_CDR_CDATA_SHIFT         ADC_PCDR_CDATA_SHIFT
#define ADC_CDR_RESULT_MASK         ADC_PCDR_RESULT_MASK
#define ADC_CDR_RESULT(x)           ADC_PCDR_RESULT(x)
#define ADC_CDR_OVERW_MASK          ADC_PCDR_OVERW_MASK
#define ADC_CDR_OVERW_SHIFT         ADC_PCDR_OVERW_SHIFT
#define ADC_CDR_VALID_MASK          ADC_PCDR_VALID_MASK
#elif defined(ADC_PCDR0_CDATA_MASK)
#define ADC_CDR_CDATA_MASK          ADC_PCDR0_CDATA_MASK
#define ADC_CDR_CDATA_SHIFT         ADC_PCDR0_CDATA_SHIFT
#define ADC_CDR_RESULT_MASK         ADC_PCDR0_RESULT_MASK
#define ADC_CDR_RESULT(x)           ADC_PCDR0_RESULT(x)
#define ADC_CDR_OVERW_MASK          ADC_PCDR0_OVERW_MASK
#define ADC_CDR_OVERW_SHIFT         ADC_PCDR0_OVERW_SHIFT
#define ADC_CDR_VALID_MASK          ADC_PCDR0_VALID_MASK
#else
#error "Unknown platform!"
#endif /* defined(ADC_PCDR_CDATA_MASK) */

/* CWSELR */
#define ADC_CWSELR_WSEL_CH0_MASK    ADC_CWSELRPI_WSEL_SI0_0_MASK
#define ADC_CWSELR_WSEL_CH0(x)      ADC_CWSELRPI_WSEL_SI0_0(x)
#define ADC_CWSELR_WSEL_CH1_SHIFT   ADC_CWSELRPI_WSEL_SI0_1_SHIFT

/* USROFSGN - Offset and Gain User */
#define ADC_USER_OFFSET_GAIN_REG     OFSGNUSR
#define ADC_USER_OFFSET(x)           ADC_OFSGNUSR_OFFSET_USER(x)
#define ADC_USER_GAIN(x)             ADC_OFSGNUSR_GAIN_USER(x)

/* Tempsense module */
#define ADC_SAR_IP_TEMPSENSE_CHANNEL           (49U)
#define ADC_SAR_IP_TEMPSENSE_RESOLUTION        (12U)
#define ADC_SAR_IP_TEMPSENSE_RESOLUTION_12B    (4096U)
#define ADC_SAR_IP_TEMPSENSE_SIGN_MASK         (0x8000U)
#define ADC_SAR_IP_TEMPSENSE_INTEGER_MASK      (0x7FF0U)
#define ADC_SAR_IP_TEMPSENSE_INTEGER_SHIFT     (4U)
#define ADC_SAR_IP_TEMPSENSE_DECIMAL_MASK      (0xFU)
#define ADC_SAR_IP_TEMPSENSE_MULTIPLIER        (100U)

/*! @name CALBISTREG - Control And Calibration Status */
/*! @{ */

#define ADC_SAR_IP_CALBISTREG_TEST_EN_MASK       ADC_CALBISTREG_TEST_EN_MASK
#define ADC_SAR_IP_CALBISTREG_TEST_EN(x)         ADC_CALBISTREG_TEST_EN(x)
#define ADC_SAR_IP_CALBISTREG_TEST_FAIL_MASK     ADC_CALBISTREG_TEST_FAIL_MASK
#define ADC_SAR_IP_CALBISTREG_AVG_EN_MASK        ADC_CALBISTREG_AVG_EN_MASK
#define ADC_SAR_IP_CALBISTREG_AVG_EN(x)          ADC_CALBISTREG_AVG_EN(x)
#define ADC_SAR_IP_CALBISTREG_NR_SMPL_MASK       ADC_CALBISTREG_NR_SMPL_MASK
#define ADC_SAR_IP_CALBISTREG_NR_SMPL(x)         ADC_CALBISTREG_NR_SMPL(x)
#define ADC_SAR_IP_CALBISTREG_C_T_BUSY_MASK      ADC_CALBISTREG_C_T_BUSY_MASK
#define ADC_SAR_IP_CALBISTREG_TSAMP_MASK         ADC_CALBISTREG_TSAMP_MASK

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_HEADERWRAPPER_S32K3_H */
