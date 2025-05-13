/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_HEADERWRAPPER_S32XX_AE_H
#define ADC_SAR_IP_HEADERWRAPPER_S32XX_AE_H

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
#define ADC_SAR_IP_VENDOR_ID_HEADERWRAPPER_S32XX_AE                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32XX_AE       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32XX_AE       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32XX_AE    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32XX_AE               2
#define ADC_SAR_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32XX_AE               0
#define ADC_SAR_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32XX_AE               1

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/

#define ADC_SAR_IP_NUM_GROUP_CHAN             (2U)
#define ADC_SAR_IP_CDR_COUNT                  (39U)
#define ADC_SAR_IP_INSTANCE_COUNT             (ADC_INSTANCE_COUNT + SAR_ADC_AE_INSTANCE_COUNT)
#define ADC_SAR_IP_THRHLR_COUNT               (8U)
#define ADC_SAR_AE_IP_THRHLR_COUNT            (16U)
#define ADC_SAR_IP_CWSELR_COUNT               (2U)
#define ADC_SAR_AE_IP_CWSELR_COUNT            (3U)

#define ADC_SAR_IP_MAX_RESOLUTION             (12U)
#define ADC_SAR_IP_HAS_THRHLR_ARRAY           (0U)
#define ADC_SAR_IP_HAS_CWSELR_UNROLLED        (1U)
#define ADC_SAR_IP_CALIBRATION_USES_MCR       (1U)

#define ADC_SAR_IP_PRESAMPLE_DVDD_EVAL        (0U)
#define ADC_SAR_IP_PRESAMPLE_AVDD_EVAL        (1U)
#define ADC_SAR_IP_PRESAMPLE_VREFL_EVAL       (2U)
#define ADC_SAR_IP_PRESAMPLE_VREFH_EVAL       (3U)

#define ADC_SAR_IP_HAS_CWSELR0                (1U)
#define ADC_SAR_IP_HAS_CWSELR1                (0U)
#define ADC_SAR_IP_HAS_CWSELR2                (0U)
#define ADC_SAR_IP_HAS_CWSELR3                (0U)
#define ADC_SAR_IP_HAS_CWSELR4                (1U)
#define ADC_SAR_IP_HAS_CWSELR5                (0U)
#define ADC_SAR_IP_HAS_CWSELR6                (0U)
#define ADC_SAR_IP_HAS_CWSELR7                (0U)
#define ADC_SAR_IP_HAS_CWSELR8                (0U)
#define ADC_SAR_IP_HAS_CWSELR9                (0U)
#define ADC_SAR_IP_HAS_CWSELR10               (0U)
#define ADC_SAR_IP_HAS_CWSELR11               (0U)

#define ADC_SAR_IP_HAS_ADCLKSEL               (1U)

#define ADC_SAR_IP_MSR_ADCSTATUS_POWER_DOWN   (1U)
#define ADC_SAR_IP_MSR_ADCSTATUS_IDLE         (0U)

#define ADC_SAR_IP_BAD_ACCESS_PROT_FEATURE   (1U)
#define ADC_SAR_IP_BAD_ACCESS_PROT_CHANNEL   (1U)
#define ADC_SAR_IP_HAS_CTU_TRIGGER_MODE      (1U)
#define ADC_SAR_IP_HAS_CTU                   (1U)
#define ADC_SAR_IP_HAS_CLKSEL_EXTENDED       (0U)
#define ADC_SAR_IP_W1C_ABORT                 (0U)
#define ADC_SAR_IP_HAS_TEMPSENSE_CHN         (0U)
#define ADC_SAR_IP_SELFTEST_FULL_CLK         (1U)

#define ADC_SAR_IP_HAS_SELFTEST_STCR1                    (1U)
#define ADC_SAR_IP_HAS_SELFTEST_STCR3                    (1U)
#define ADC_SAR_IP_HAS_BANDGAP_STATUS                    (0U)
#define ADC_SAR_IP_HAS_SELFTEST_USE_CH32                 (0U)

#define ADC_SAR_IP_ABORTCHAIN_WORKAROUND                 (1U)

                                     /* 31-28   3-0  63-60  35-32 95-92  67-64
                                         \_/    \_/   \_/    \_/   \_/    \_/
                                          |......|     |......|     |......| */
#define ADC_SAR_IP_CHN_AVAIL_BITMAP   {{0x000000FFU, 0x00000079U}, /* 0 */ \
                                       {0x000000FFU, 0x00000079U}, /* 1 */ \
                                       {0x00FFFFFFU, 0x00000000U}, /* 2 (ADC_AE_0_0) */ \
                                       {0x00001FFFU, 0x00000000U}, /* 3 (ADC_AE_1_0) */ \
                                       {0x00001FFFU, 0x00000000U}, /* 4 (ADC_AE_1_1) */ \
                                       {0x00001FFFU, 0x00000000U}, /* 5 (ADC_AE_2_0) */ \
                                       {0x00001FFFU, 0x00000000U}, /* 6 (ADC_AE_2_1) */ \
                                      }
                                     /* Adc Channels are divided into 2 Groups. */
                                     /* This array shows max number of channels of each group. */
                                     /* There are some registers that relate to this one: CEOCFR, CIMR, DMAR, PSR, NCMR, JCMR,... */
                                     /* Should be same with ADC_CDRx_COUNT in header file (from Base) */
#define ADC_SAR_IP_MAX_CHN_COUNT      {{8U, 8U},  /* 0 */ \
                                       {8U, 8U},  /* 1 */ \
                                       {24U, 0U},  /* 2 (ADC_AE_0_0) */ \
                                       {13U, 0U}, /* 3 (ADC_AE_1_0) */ \
                                       {13U, 0U}, /* 4 (ADC_AE_1_1) */ \
                                       {13U, 0U}, /* 5 (ADC_AE_2_0) */ \
                                       {13U, 0U}, /* 6 (ADC_AE_2_1) */ \
                                      }
                                     /* Number of group channels of each unit */
                                     /* Unit 0 / 1 / 2 (ADC_AE_0_0)/ 3 (ADC_AE_1_0)/ 4 (ADC_AE_1_1)/ 5 (ADC_AE_2_0)/ 6 (ADC_AE_2_1) */
#define ADC_SAR_IP_MAX_GROUP_COUNT    { 2U, 2U, 1U, 1U, 1U, 1U, 1U }
                                     /* Bit0: DSDR is available
                                        Bit1: PSCR is available
                                        Bit2: CTU is available
                                        Bit3: CTU trigger mode is available */
#define ADC_SAR_IP_FEAT_AVAIL_BITMAP   {0x0000000EU, /* 0 */ \
                                        0x0000000EU, /* 1 */ \
                                        0x00000002U, /* 2 (ADC_AE_0_0) */ \
                                        0x0000000EU, /* 3 (ADC_AE_1_0) */ \
                                        0x0000000EU, /* 4 (ADC_AE_1_1) */ \
                                        0x0000000EU, /* 5 (ADC_AE_2_0) */ \
                                        0x0000000EU, /* 6 (ADC_AE_2_1) */ \
                                       }

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
#define CWSELR(base, regIndex)      REG_ACCESS((base)->CWSELR, (regIndex))
#define CWENR(base, regIndex)       REG_ACCESS((base)->CWENR0, (regIndex))
#define AWORR(base, regIndex)       REG_ACCESS((base)->AWORR0, (regIndex))
#define CDR(base, chanIndex)        REG_READ((base)->PCDR[0U], (chanIndex))
#define CDR_AE(base, chanIndex)     REG_READ((base)->CDR[0U], (chanIndex))

/* MCR */
#define ADC_MCR_ADCLKSEL_MASK       ADC_MCR_ADCLKSE_MASK
#define ADC_MCR_ADCLKSEL(x)         ADC_MCR_ADCLKSE(x)

/* CTR */
#define ADC_CTR_INPSAMP(x)          ADC_CTR0_INPSAMP(x)

/* NCMR */
#define ADC_NCMR_CH0(x)             ADC_NCMR0_CH0(x)

/* CDR */
#define ADC_CDR_CDATA_MASK          ADC_PCDR_CDATA_MASK
#define ADC_CDR_CDATA_SHIFT         ADC_PCDR_CDATA_SHIFT
#define ADC_CDR_RESULT_MASK         ADC_PCDR_RESULT_MASK
#define ADC_CDR_RESULT(x)           ADC_PCDR_RESULT(x)
#define ADC_CDR_OVERW_MASK          ADC_PCDR_OVERW_MASK
#define ADC_CDR_OVERW_SHIFT         ADC_PCDR_OVERW_SHIFT
#define ADC_CDR_VALID_MASK          ADC_PCDR_VALID_MASK

/* USROFSGN - Offset and Gain User */
#define ADC_USER_OFFSET_GAIN_REG     USROFSGN
#define ADC_USER_OFFSET(x)           ADC_USROFSGN_OFFSUSER(x)
#define ADC_USER_GAIN(x)             ADC_USROFSGN_GAINUSER(x)

#define ADC_AE_USER_OFFSET_GAIN_REG  OFSGNUSR
#define ADC_AE_USER_OFFSET(x)        SAR_ADC_AE_OFSGNUSR_OFFSET_USER(x)
#define ADC_AE_USER_GAIN(x)          SAR_ADC_AE_OFSGNUSR_GAIN_USER(x)

/*! @name CALBISTREG - Control And Calibration Status */
/*! @{ */

#define ADC_SAR_IP_CALBISTREG_TEST_EN_MASK       SAR_ADC_AE_CALBISTREG_TEST_EN_MASK
#define ADC_SAR_IP_CALBISTREG_TEST_EN(x)         SAR_ADC_AE_CALBISTREG_TEST_EN(x)
#define ADC_SAR_IP_CALBISTREG_TEST_FAIL_MASK     SAR_ADC_AE_CALBISTREG_TEST_FAIL_MASK
#define ADC_SAR_IP_CALBISTREG_AVG_EN_MASK        SAR_ADC_AE_CALBISTREG_AVG_EN_MASK
#define ADC_SAR_IP_CALBISTREG_AVG_EN(x)          SAR_ADC_AE_CALBISTREG_AVG_EN(x)
#define ADC_SAR_IP_CALBISTREG_NR_SMPL_MASK       SAR_ADC_AE_CALBISTREG_NR_SMPL_MASK
#define ADC_SAR_IP_CALBISTREG_NR_SMPL(x)         SAR_ADC_AE_CALBISTREG_NR_SMPL(x)
#define ADC_SAR_IP_CALBISTREG_C_T_BUSY_MASK      SAR_ADC_AE_CALBISTREG_C_T_BUSY_MASK
#define ADC_SAR_IP_CALBISTREG_TSAMP_MASK         SAR_ADC_AE_CALBISTREG_TSAMP_MASK

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_HEADERWRAPPER_S32XX_H */
