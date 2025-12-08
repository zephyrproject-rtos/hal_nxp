/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_HEADERWRAPPER_S32K5_H
#define ADC_SAR_IP_HEADERWRAPPER_S32K5_H

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
#define ADC_SAR_IP_VENDOR_ID_HEADERWRAPPER_S32K5                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32K5       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32K5       9
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32K5    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32K5               0
#define ADC_SAR_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32K5               8
#define ADC_SAR_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32K5               0

/*==================================================================================================
*                             DEFINITIONS
==================================================================================================*/

/* ----------------------------------------------------------------------------
   -- SARADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */
typedef struct {
  __IO uint32_t MCR;                               /**< Main Configuration, offset: 0x0 */
  __IO uint32_t MSR;                                /**< Main Status, offset: 0x4 */
  __IO uint32_t CALBISTREG;                           /**< Control and Calibration Status, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __IO uint32_t ISR;                                /**< Interrupt Status, offset: 0x10 */
  __IO uint32_t CEOCF0;                            /**< Channel End of Conversion Flag for Type 0, offset: 0x14 */
  __IO uint32_t CEOCF1;                            /**< Channel End of Conversion Flag for Type 1, offset: 0x18 */
  __IO uint32_t CEOCF2;                            /**< Channel End of Conversion Flag for Type 2, offset: 0x1C */
  __IO uint32_t IMR;                                /**< Interrupt Mask, offset: 0x20 */
  __IO uint32_t CIM0;                              /**< EOC Interrupt Enable for Type 0, offset: 0x24 */
  __IO uint32_t CIM1;                              /**< EOC Interrupt Enable for Type 1, offset: 0x28 */
  __IO uint32_t CIM2;                              /**< EOC Interrupt Enable for Type 2, offset: 0x2C */
  __IO uint32_t WTISR;                              /**< Analog Watchdog Threshold Interrupt Status, offset: 0x30 */
  __IO uint32_t WTIMR;                              /**< Analog Watchdog Threshold Interrupt Mask, offset: 0x34 */
  uint8_t RESERVED_1[8];
  __IO uint32_t DMAE;                              /**< Direct Memory Access Configuration, offset: 0x40 */
  __IO uint32_t DMA0;                              /**< DMA Request Enable for Type 0, offset: 0x44 */
  __IO uint32_t DMA1;                              /**< DMA Request Enable for Type 1, offset: 0x48 */
  __IO uint32_t DMA2;                              /**< DMA Request Enable for Type 2, offset: 0x4C */
  uint8_t RESERVED_2[16];
  __IO uint32_t THRHLREG[SARADC_THRHLN_COUNT];     /**< Analog Watchdog Threshold Values, array offset: 0x60, array step: 0x4 */
  uint8_t RESERVED_3[48];
  __IO uint32_t SMPLTSEL;                          /**< Sample Time Select, offset: 0xA0 */
  __IO uint32_t NCM0;                              /**< Normal Conversion Mask for Type 0, offset: 0xA4 */
  __IO uint32_t NCM1;                              /**< Normal Conversion Mask for Type 1, offset: 0xA8 */
  __IO uint32_t NCM2;                              /**< Normal Conversion Mask for Type 2, offset: 0xAC */
  uint8_t RESERVED_4[4];
  __IO uint32_t JCM0;                              /**< Injected Conversion Mask for Type 0, offset: 0xB4 */
  __IO uint32_t JCM1;                              /**< Injected Conversion Mask for Type 1, offset: 0xB8 */
  __IO uint32_t JCM2;                              /**< Injected Conversion Mask for Type 2, offset: 0xBC */
  uint8_t RESERVED_5[4];
  __IO uint32_t DSD;                               /**< Delay Start of Data Conversion, offset: 0xC4 */
  __IO uint32_t PDEDR;                             /**< Power Up Delay, offset: 0xC8 */
  uint8_t RESERVED_6[52];
  __I  uint32_t CD0_P[SARADC_CD0_P_COUNT];         /**< Type 0 Input n Conversion Data, array offset: 0x100, array step: 0x4 */
  __I  uint32_t CD0_M[SARADC_CD0_M_COUNT];         /**< Type 0 Input n Conversion Data, array offset: 0x140, array step: 0x4 */
  __I  uint32_t CD1_P[SARADC_CD1_P_COUNT];         /**< Type 1 Input n Conversion Data, array offset: 0x180, array step: 0x4 */
  uint8_t RESERVED_7[20];
  __I  uint32_t CD1_M[SARADC_CD1_M_COUNT];         /**< Type 1 Input n Conversion Data, array offset: 0x1C0, array step: 0x4 */
  uint8_t RESERVED_8[20];
  __I  uint32_t CD2_P[SARADC_CD2_P_COUNT];         /**< Type 2 input n Conversion Data, array offset: 0x200, array step: 0x4 */
  __I  uint32_t CD2_M[SARADC_CD2_M_COUNT];         /**< Type 2 input n Conversion Data, array offset: 0x240, array step: 0x4 */
  uint8_t RESERVED_9[48];
  __IO uint32_t CWSEL_0_0;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2B0 */
  __IO uint32_t CWSEL_0_1;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2B4 */
  __IO uint32_t CWSEL_0_2;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2B8 */
  __IO uint32_t CWSEL_0_3;                         /**< Channel Analog Watchdog Select for Type 0, offset: 0x2BC */
  __IO uint32_t CWSEL_1_0;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2C0 */
  __IO uint32_t CWSEL_1_1;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2C4 */
  __IO uint32_t CWSEL_1_2;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2C8 */
  __IO uint32_t CWSEL_1_3;                         /**< Channel Analog Watchdog Select for Type 1, offset: 0x2CC */
  __IO uint32_t CWSEL_2_0;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2D0 */
  __IO uint32_t CWSEL_2_1;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2D4 */
  __IO uint32_t CWSEL_2_2;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2D8 */
  __IO uint32_t CWSEL_2_3;                         /**< Channel Analog Watchdog Select for Type 2, offset: 0x2DC */
  __IO uint32_t CWEN0;                             /**< Channel Watchdog Enable for Type 0, offset: 0x2E0 */
  __IO uint32_t CWEN1;                             /**< Channel Watchdog Enable for Type 1, offset: 0x2E4 */
  __IO uint32_t CWEN2;                             /**< Channel Watchdog Enable for Type 2, offset: 0x2E8 */
  uint8_t RESERVED_10[4];
  __IO uint32_t AWOR0;                             /**< Analog Watchdog Out of Range for Type 0, offset: 0x2F0 */
  __IO uint32_t AWOR1;                             /**< Analog Watchdog Out of Range for Type 1, offset: 0x2F4 */
  __IO uint32_t AWOR2;                             /**< Analog Watchdog Out of Range for Type 2, offset: 0x2F8 */
  uint8_t RESERVED_11[68];
  __IO uint32_t STCR1;                              /**< Self-Test Configuration 1, offset: 0x340 */
  __IO uint32_t STCR2;                              /**< Self-Test Configuration 2, offset: 0x344 */
  uint8_t RESERVED_12[4];
  __IO uint32_t STBR;                              /**< Self-Test Baud Rate, offset: 0x34C */
  __IO uint32_t STS1_P;                            /**< Self-Test Status 1 for P-SARADC, offset: 0x350 */
  __IO uint32_t STS1_M;                            /**< Self-Test Status 1 for M-SARADC, offset: 0x354 */
  __I  uint32_t STS2_P;                            /**< Self-Test Status 2 for P-SARADC, offset: 0x358 */
  __I  uint32_t STS2_M;                            /**< Self-Test Status 2 for M-SARADC, offset: 0x35C */
  __I  uint32_t STS3_P;                            /**< Self-Test Status 3 for P-SARADC, offset: 0x360 */
  __I  uint32_t STS3_M;                            /**< Self-Test Status 3 for M-SARADC, offset: 0x364 */
  __I  uint32_t STS4_P;                            /**< Self-Test Status 4 for P-SARADC, offset: 0x368 */
  __I  uint32_t STS4_M;                            /**< Self-Test Status 4 for M-SARADC, offset: 0x36C */
  __I  uint32_t STD1_P;                            /**< Self-Test Conversion Data 1 for P-SARADC, offset: 0x370 */
  __I  uint32_t STD1_M;                            /**< Self-Test Conversion Data 1 for M-SARADC, offset: 0x374 */
  __I  uint32_t STD2_P;                            /**< Self-Test Conversion Data 2 for P-SARADC, offset: 0x378 */
  __I  uint32_t STD2_M;                            /**< Self-Test Conversion Data 2 for M-SARADC, offset: 0x37C */
  __IO uint32_t STAWVBG;                           /**< Self Test Analog Watchdog Threshold for Bandgap Supply, offset: 0x380 */
  __IO uint32_t STAWVDDI;                          /**< Self Test Analog Watchdog Threshold for VDD (Integer Part), offset: 0x384 */
  __IO uint32_t STAWVDDF;                          /**< Self Test Analog Watchdog Threshold for VDD (Fractional Part), offset: 0x388 */
  __IO uint32_t STAWVRHL;                          /**< Self Test Analog Watchdog Threshold for Reference High Supply, offset: 0x38C */
  __IO uint32_t STAWOFS;                           /**< Self Test Analog Watchdog Threshold for Offset, offset: 0x390 */
  __IO uint32_t STAWCAPM;                          /**< Self Test Analog Watchdog Threshold for MSB Capacitor, offset: 0x394 */
  __IO uint32_t STAWCAPI;                          /**< Self Test Analog Watchdog Threshold for ISB Capacitor, offset: 0x398 */
  __IO uint32_t STAWCAPL;                          /**< Self Test Analog Watchdog Threshold for LSB Capacitor, offset: 0x39C */
  uint8_t RESERVED_13[8];
  __IO uint32_t GCC_P;                             /**< Gain Calibration Control for P-SARADC Converter, offset: 0x3A8 */
  __IO uint32_t GCC_M;                             /**< Gain Calibration Control for M-SARADC SARADC Converter, offset: 0x3AC */
  __IO uint32_t GCR_P;                             /**< Gain Calculation Result for P-SARADC Converter, offset: 0x3B0 */
  __IO uint32_t GCR_M;                             /**< Gain Calculation Result for M-SARADC Converter, offset: 0x3B4 */
  uint8_t RESERVED_14[268];
  __I  uint32_t CALSTSP0;                          /**< Calibration Fail Status 0 for P-SARADC, offset: 0x4C4 */
  __I  uint32_t CALSTSP1;                          /**< Calibration Fail Status 1 for P-SARADC, offset: 0x4C8 */
  __I  uint32_t CALSTSM0;                          /**< Calibration Fail Status 0 for M-SARADC, offset: 0x4CC */
  __I  uint32_t CALSTSM1;                          /**< Calibration Fail Status 1 for M-SARADC, offset: 0x4D0 */
} ADC_Type, *ADC_MemMapPtr;


#define ADC_SAR_IP_NUM_GROUP_CHAN           (3U)
#define ADC_SAR_IP_CDR_COUNT                (96U)
#define ADC_SAR_IP_INSTANCE_COUNT           (ADC_INSTANCE_COUNT)
#define ADC_INSTANCE_COUNT                  (SARADC_INSTANCE_COUNT)
#define ADC_SAR_IP_THRHLR_COUNT             (SARADC_THRHLN_COUNT)
#define ADC_SAR_IP_MAX_RESOLUTION           (16U)
#define ADC_SAR_IP_RESULT_RESOLUTION        (16U) /* Resolution of the result written by the ADC module */
#define ADC_SAR_IP_HAS_THRHLR_ARRAY         (1U)
#define ADC_SAR_IP_CALIBRATION_USES_MCR     (0U)
#define ADC_SAR_IP_PRESAMPLE_VREFL_EVAL     (0U)
#define ADC_SAR_IP_PRESAMPLE_VREFH_EVAL     (0U)
#define ADC_SAR_IP_HAS_ADCLKSEL             (1U)
#define ADC_SAR_IP_HAS_ADCLKDIV             (1U)
#define ADC_SAR_IP_MSR_ADCSTATUS_POWER_DOWN (1U)
#define ADC_SAR_IP_MSR_ADCSTATUS_IDLE       (0U)
#define ADC_SAR_IP_BAD_ACCESS_PROT_FEATURE  (1U)
#define ADC_SAR_IP_BAD_ACCESS_PROT_CHANNEL  (1U)
#define ADC_SAR_IP_HAS_CTU_TRIGGER_MODE     (1U)
#define ADC_SAR_IP_HAS_CTU                  (1U)
#define ADC_SAR_IP_HAS_CLKSEL_EXTENDED      (1U)
#define ADC_SAR_IP_W1C_ABORT                (1U)
#define ADC_SAR_IP_HAS_TEMPSENSE_CHN        (1U)
#define ADC_SAR_IP_SELFTEST_FULL_CLK        (1U)
#define ADC_SAR_IP_HAS_SELFTEST_STCR1       (1U)
#define ADC_SAR_IP_HAS_SELFTEST_STCR3       (0U)
#define ADC_SAR_IP_HAS_BANDGAP_STATUS       (0U)
#define ADC_SAR_IP_HAS_SELFTEST_USE_CH32    (0U)
#define ADC_SAR_IP_ABORTCHAIN_WORKAROUND    (0U)


#if (ADC_SAR_IP_INSTANCE_COUNT == 3U)
                                      /* 31-28   3-0  63-60  35-32 95-92  67-64
                                          \_/    \_/   \_/    \_/   \_/    \_/
                                           |......|     |......|     |......| */
#define ADC_SAR_IP_CHN_AVAIL_BITMAP    {{0xFFFFFFFFU, 0x07490749U, 0xFFFFFFFFU}, /* 0 */ \
                                        {0xFFFFFFFFU, 0x0F490F49U, 0xFFFFFFFFU}, /* 1 */ \
                                        {0xFFFFFFFFU, 0x075D075DU, 0xFFFFFFFFU}, /* 2 */ \
                                       }

                                      /* Adc Channels are divided into 3 Groups. */
                                      /* This array shows max number of channels of each group. */
                                      /* There are some registers that relate to this one: CEOCFR, CIMR, DMAR, PSR, NCMR, JCMR,... */
                                      /* Should be same with ADC_CDRx_COUNT in header file (from Base) */
#define ADC_SAR_IP_MAX_CHN_COUNT       {{32U, 22U, 32U}, /* Adc HW Unit 0 */ \
                                        {32U, 24U, 32U}, /* Adc HW Unit 1 */ \
                                        {32U, 22U, 32U},  /* Adc HW Unit 2 */ \
                                       }

                                       /* Number of group channels of each unit */
                                       /* Unit 0 / 1 / 2 */
#define ADC_SAR_IP_MAX_GROUP_COUNT     { 3U, 3U, 3U }

                                      /* Bit0: DSDR is available
                                         Bit1: PSCR is available
                                         Bit2: CTU is available
                                         Bit3: CTU trigger mode is available */
#define ADC_SAR_IP_FEAT_AVAIL_BITMAP    {0x0000000CU, /* Adc HW Unit 0 */ \
                                         0x0000000CU, /* Adc HW Unit 1 */ \
                                         0x0000000CU, /* Adc HW Unit 2 */ \
                                        }
#else
#error "Unknown platform!"
#endif /* (ADC_SAR_IP_INSTANCE_COUNT > 3U) */

#define REG_ACCESS(reg, index)          (*(volatile uint32*)(&(((&(reg))[(index)]))))
#define REG_READ(reg, index)            (*(volatile const uint32*)(&(((&(reg))[(index)]))))

#define CEOCFR(base, regIndex)          REG_ACCESS((base)->CEOCF0, (regIndex))
#define CIMR(base, regIndex)            REG_ACCESS((base)->CIM0, (regIndex))
#define DMAR(base, regIndex)            REG_ACCESS((base)->DMA0, (regIndex))
#define NCMR(base, regIndex)            REG_ACCESS((base)->NCM0, (regIndex))
#define JCMR(base, regIndex)            REG_ACCESS((base)->JCM0, (regIndex))
#define THRHLR(base, regIndex)          REG_ACCESS((base)->THRHLREG[0U], (regIndex))
#define CWSELR(base, regIndex)          REG_ACCESS((base)->CWSEL_0_0, (regIndex))
#define CWENR(base, regIndex)           REG_ACCESS((base)->CWEN0, (regIndex))
#define AWORR(base, regIndex)           REG_ACCESS((base)->AWOR0, (regIndex))
#define CDR(base, chanIndex)            REG_READ((base)->CD0_P[0U], (chanIndex))
#define ADC_CWSELR_WSEL_CH0_MASK        SARADC_CWSEL_0_0_WSEL_T00_0_MASK
#define ADC_CWSELR_WSEL_CH0(x)          SARADC_CWSEL_0_0_WSEL_T00_0(x)
#define ADC_CWSELR_WSEL_CH1_SHIFT       SARADC_CWSEL_0_0_WSEL_T00_1_SHIFT
#define IP_LPE_ADC                      ((ADC_Type *)IP_LPE_SARADC_BASE)
#define IP_ADC_0                        ((ADC_Type *)IP_SARADC_0_BASE)
#define IP_ADC_1                        ((ADC_Type *)IP_SARADC_1_BASE)
#define IP_ADC_BASE_PTRS                { IP_ADC_0, IP_ADC_1, IP_LPE_ADC }

/* MC Register Configuration Macros */
#define ADC_MCR_PWDN(x)                 SARADC_MC_PWDN(x)
#define ADC_MCR_ADCLKSEL_MASK           SARADC_MC_ADCLKSEL_MASK
#define ADC_MCR_ADCLKSEL(x)             SARADC_MC_ADCLKSEL(x)
#define ADC_MCR_ADCLKDIV_MASK           SARADC_MC_ADCLKDIV_MASK
#define ADC_MCR_ADCLKDIV(x)             SARADC_MC_ADCLKDIV(x)
#define ADC_MCR_ACKO_MASK               SARADC_MC_ACKO_MASK
#define ADC_MCR_ABORT(x)                SARADC_MC_STOP(x)
#define ADC_MCR_ABORTCHAIN(x)           SARADC_MC_STOPCHN(x)
#define ADC_MCR_AVGS_MASK               SARADC_MC_AVGS_MASK
#define ADC_MCR_AVGS(x)                 SARADC_MC_AVGS(x)
#define ADC_MCR_AVGEN(x)                SARADC_MC_AVGEN(x)
#define ADC_MCR_AVGEN_MASK              SARADC_MC_AVGEN_MASK
#define ADC_MCR_CTYPE_MASK              SARADC_MC_CTYPE_MASK
#define ADC_MCR_CTU_MODE_MASK           SARADC_MC_CTUMODE_MASK
#define ADC_MCR_CTU_MODE(x)             SARADC_MC_CTUMODE(x)
#define ADC_MCR_CTUEN_MASK              SARADC_MC_CTUEN_MASK
#define ADC_MCR_CTUEN(x)                SARADC_MC_CTUEN(x)
#define ADC_MCR_JSTART(x)               SARADC_MC_JSTART(x)
#define ADC_MCR_JEDGE_MASK              SARADC_MC_JEDGE_MASK
#define ADC_MCR_JTRGEN_MASK             SARADC_MC_JTRGEN_MASK
#define ADC_MCR_NSTART(x)               SARADC_MC_NSTART(x)
#define ADC_MCR_XSTRTEN_MASK            SARADC_MC_XSTRTEN_MASK
#define ADC_MCR_EDGE(x)                 SARADC_MC_EDGE(x)
#define ADC_MCR_EDGE_MASK               SARADC_MC_EDGE_MASK
#define ADC_MCR_TRGEN_MASK              SARADC_MC_TRGEN_MASK
#define ADC_MCR_MODE_MASK               SARADC_MC_MODE_MASK
#define ADC_MCR_MODE(x)                 SARADC_MC_MODE(x)
#define ADC_MCR_WLSIDE_MASK             SARADC_MC_WLSIDE_MASK
#define ADC_MCR_WLSIDE(x)               SARADC_MC_WLSIDE(x)
#define ADC_MCR_OWREN_MASK              SARADC_MC_OWREN_MASK

/* MS Register Configuration Macros */
#define ADC_MSR_ADCSTATUS_MASK          SARADC_MS_ADCSTS_MASK
#define ADC_MSR_ADCSTATUS_SHIFT         SARADC_MS_ADCSTS_SHIFT
#define ADC_MSR_ADCSTATUS(x)            SARADC_MS_ADCSTS(x)
#define ADC_MSR_ACKO_MASK               SARADC_MS_ACKO_MASK
#define ADC_MSR_CTUSTART_MASK           SARADC_MS_CTUSTART_MASK
#define ADC_MSR_SELF_TEST_S_MASK        SARADC_MS_SELF_TST_MASK
#define ADC_MSR_JSTART_MASK             SARADC_MS_JSTART_MASK
#define ADC_MSR_JABORT_MASK             SARADC_MS_JSTOP_MASK
#define ADC_MSR_NSTART_MASK             SARADC_MS_NSTART_MASK
#define ADC_MSR_CALFAIL_MASK            SARADC_MS_CALFAIL_MASK
#define ADC_MSR_CALBUSY_MASK            SARADC_MS_CALBUSY_MASK
#define ADC_MSR_CAP_DONE_MASK           SARADC_MS_CAP_DONE_MASK
#define ADC_MSR_CALIBRTD_MASK           SARADC_MS_OFS_DONE_MASK

/* IS Register Configuration Macros for Interrupt Status */
#define ADC_ISR_ECH_MASK                SARADC_IS_ECH_MASK
#define ADC_ISR_ECH(x)                  SARADC_IS_ECH(x)
#define ADC_ISR_EOC_MASK                SARADC_IS_EOC_MASK
#define ADC_ISR_EOC(x)                  SARADC_IS_EOC(x)
#define ADC_ISR_JECH_MASK               SARADC_IS_JECH_MASK
#define ADC_ISR_JECH(x)                 SARADC_IS_JECH(x)
#define ADC_ISR_JEOC_MASK               SARADC_IS_JEOC_MASK
#define ADC_ISR_JEOC(x)                 SARADC_IS_JEOC(x)
#define ADC_ISR_EOCTU_MASK              SARADC_IS_EOBCTU_MASK
#define ADC_ISR_EOCTU(x)                SARADC_IS_EOBCTU(x)

/* IM Register Configuration Macros for Interrupt Mask */
#define ADC_IMR_MSKECH_MASK             SARADC_IM_MSKECH_MASK
#define ADC_IMR_MSKECH(x)               SARADC_IM_MSKECH(x)
#define ADC_IMR_MSKEOC_MASK             SARADC_IM_MSKEOC_MASK
#define ADC_IMR_MSKEOC(x)               SARADC_IM_MSKEOC(x)
#define ADC_IMR_MSKJECH_MASK            SARADC_IM_MSKJECH_MASK
#define ADC_IMR_MSKJECH(x)              SARADC_IM_MSKJECH(x)
#define ADC_IMR_MSKJEOC_MASK			SARADC_IM_MSKJEOC_MASK
#define ADC_IMR_MSKJEOC(x)              SARADC_IM_MSKJEOC(x)
#define ADC_IMR_MSKEOCTU_MASK           SARADC_IM_MSKEOBCTU_MASK
#define ADC_IMR_MSKEOCTU(x)             SARADC_IM_MSKEOBCTU(x)

/* DMAE Register Configuration Macros for DMA Enable */
#define ADC_DMAE_DMAEN_MASK             SARADC_DMAE_DMAEN_MASK
#define ADC_DMAE_DMAEN(x)               SARADC_DMAE_DMAEN(x)
#define ADC_DMAE_DCLR_MASK              SARADC_DMAE_DCLR_MASK
#define ADC_DMAE_DCLR(x)                SARADC_DMAE_DCLR(x)

/* NCMR */
#define ADC_NCMR_CH0(x)                 SARADC_NCM0_CH0(x)

/* THRHLR Register Configuration Macros for Threshold High/Low */
#define ADC_THRHLR_THRL(x)              SARADC_THRHL_THRL(x)
#define ADC_THRHLR_THRH(x)              SARADC_THRHL_THRH(x)

/* PD Register Configuration Macros for Power Down */
#define ADC_PDEDR_PDED(x)               SARADC_PUDLY_PUED(x)

/* CD Register Configuration Macros for Channel Delay */
#define ADC_CDR_RESULT_NORMAL_TRIGGER       0x01U
#define ADC_CDR_RESULT_INJECTED_TRIGGER     0x02U
#define ADC_CDR_RESULT_CTU_TRIGGER          0x03U

#define ADC_CDR_CDATA_MASK              SARADC_CD0_P_CDATA_MASK
#define ADC_CDR_CDATA_SHIFT             SARADC_CD0_P_CDATA_SHIFT
#define ADC_CDR_RESULT_MASK             SARADC_CD0_P_RESULT_MASK
#define ADC_CDR_RESULT(x)               SARADC_CD0_P_RESULT(x)
#define ADC_CDR_OVERW_MASK              SARADC_CD0_P_OVERW_MASK
#define ADC_CDR_OVERW_SHIFT             SARADC_CD0_P_OVERW_SHIFT
#define ADC_CDR_VALID_MASK              SARADC_CD0_P_VALID_MASK

/* CALBIST Register Configuration Macros for Calibration and Built-In Self-Test */
#define ADC_SAR_IP_CALBISTREG_NR_SMPL_MASK       SARADC_CALBIST_CAL_AVGS_MASK
#define ADC_SAR_IP_CALBISTREG_NR_SMPL(x)         SARADC_CALBIST_CAL_AVGS(x)
#define ADC_SAR_IP_CALBISTREG_AVG_EN_MASK        SARADC_CALBIST_CALAVGEN_MASK
#define ADC_SAR_IP_CALBISTREG_AVG_EN(x)          SARADC_CALBIST_CALAVGEN(x)
#define ADC_SAR_IP_CALBISTREG_CST_LONG_MASK      SARADC_CALBIST_CST_LONG_MASK
#define ADC_SAR_IP_CALBISTREG_TEST_CAP_EN_MASK   SARADC_CALBIST_CAP_REQ_MASK
#define ADC_SAR_IP_CALBISTREG_TEST_CAP_EN(x)     SARADC_CALBIST_CAP_REQ(x)
#define ADC_SAR_IP_CALBISTREG_TEST_EN_MASK       SARADC_CALBIST_OFS_REQ_MASK
#define ADC_SAR_IP_CALBISTREG_TEST_EN(x)         SARADC_CALBIST_OFS_REQ(x)

/* STCR */
#define ADC_STCR2_EN(x)                          SARADC_STC2_ST_EN(x)
#define ADC_STCR2_ALG(x)                         SARADC_STC2_ALG(x)
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_HEADERWRAPPER_S32K5_H */
