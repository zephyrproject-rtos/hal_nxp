/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_PM_BOARD_H_
#define _FSL_PM_BOARD_H_

#include "fsl_common.h"

#include "fsl_pm_config.h"

/*!
 * @addtogroup PM Framework: Power Manager Framework
 * @brief This section includes Power Mode macros, System Constraints macros, and Wakeup source macros.
 * @{
 */

/*!
 * @name Power Mode Definition
 * @{
 */

/* Power Mode Index */
#define PM_LP_STATE_SLEEP                (0U)
#define PM_LP_STATE_DEEP_SLEEP           (1U)
#define PM_LP_STATE_DEEP_POWER_DOWN      (2U)
#define PM_LP_STATE_FULL_DEEP_POWER_DOWN (3U)
#define PM_LP_STATE_NO_CONSTRAINT        (0xFFU)

/* @} */

/* Temporary workaround as enumeration for PORCORE is missing in fsl_power header file. Will be removed once supported. */
#define kPDRUNCFG_LP_PORCORE (pd_bit_t)(MAKE_PD_BITS(PDRCFG0, 8U))

/* Helper macros */
#define PM_RESC_MASK(resc_masks, resc) (resc_masks->rescMask[resc / 32L] >> (resc % 32L)) & 1U
#define PM_RESC_GROUP(resc_groups, resc) (resc_groups->groupSlice[resc / 8] >> (4 * (resc % 8))) & 0xFU

/*!
 * @name System basic resource constraints definitions.
 * @{
 */

/*! @brief Available constraints for resources
 *
 *  The constraints below are grouped together in 3 groups
 */

typedef enum _resc_name
{
    /* Peripherals and RAMs that do not have separate retention bit */
    kResc_MAIN_CLK       = 0,   /*!< Main Clock */
    kResc_VDDCOREREG_HP     ,   /*!< VDDCORE Regulator */
    kResc_PMCREF_HP         ,   /*!< PMC Reference */
    kResc_HVD1V8            ,   /*!< 1.8V High-Voltage Detect */
    kResc_PORCORE_HP        ,   /*!< VDDCORE Power-On Reset monitor */
    kResc_LVDCORE_HP        ,   /*!< VDDCORE Low-Voltage Detect */
    kResc_HVDCORE           ,   /*!< VDDCORE High-Voltage Detect */
    kResc_SYSXTAL           ,   /*!< System crystal oscillator */
    kResc_LPOSC             ,   /*!< Low-Power Oscillator */
    kResc_FRO               ,   /*!< Free-Running Oscillator */
    kResc_SYSPLLLDO         ,   /*!< LDO for System PLL */
    kResc_SYSPLLANA         ,   /*!< Analog for System PLL */
    kResc_AUDIOPLLLDO       ,   /*!< LDO for Audio PLL */
    kResc_AUDIOPLLANA       ,   /*!< Analog for Audio PLL */
    kResc_ADC_ACTIVE        ,   /*!< ADC Powered */
    kResc_ADC_TEMP          ,   /*!< ADC Temperature sensor */
    kResc_PMC_TEMP          ,   /*!< PMC Temperature sensor */
    kResc_ACMP              ,   /*!< Analog Comparator */
    kResc_SRAM_PQ           ,   /*!< PowerQuad SRAM */
    kResc_SRAM_CASPER       ,   /*!< CASPER SRAM */
    kResc_DSP               ,   /*!< DSP */
    kResc_MIPIDSI           ,   /*!< MIPI-DSI */
    kResc_OTP               ,   /*!< OTP */
    kResc_ROM               ,   /*!< ROM */

    /* dedicated peripheral SRAMs that have 2 bits each in PDSLEEPCFG1 */
    kResc_SRAM_FLEXSPI0     ,   /*!< FlexSPI0 SRAM */
    kResc_SRAM_FLEXSPI1     ,   /*!< FlexSPI1 SRAM */
    kResc_SRAM_USB          ,   /*!< USB SRAM */
    kResc_SRAM_USDHC0       ,   /*!< uSDHC0 SRAM */
    kResc_SRAM_USDHC1       ,   /*!< uSDHC1 SRAM */
    kResc_SRAM_GPU          ,   /*!< GPU SRAM */
    kResc_SRAM_SMARTDMA     ,   /*!< SmartDMA SRAM */
    kResc_SRAM_MIPIDSI      ,   /*!< MIPI-DSI SRAM */
    kResc_SRAM_LCDIF        ,   /*!< LCD Interface SRAM */

    /* System SRAMs that have bits in both PDSLEEPCFG2 & 3 */
    kResc_SRAM0_32KB        ,   /*!< SRAM partition0 */
    kResc_SRAM1_32KB        ,   /*!< SRAM partition1 */
    kResc_SRAM2_32KB        ,   /*!< SRAM partition2 */
    kResc_SRAM3_32KB        ,   /*!< SRAM partition3 */
    kResc_SRAM4_32KB        ,   /*!< SRAM partition4 */
    kResc_SRAM5_32KB        ,   /*!< SRAM partition5 */
    kResc_SRAM6_32KB        ,   /*!< SRAM partition6 */
    kResc_SRAM7_32KB        ,   /*!< SRAM partition7 */
    kResc_SRAM8_64KB        ,   /*!< SRAM partition8 */
    kResc_SRAM9_64KB        ,   /*!< SRAM partition9 */
    kResc_SRAM10_64KB       ,   /*!< SRAM partition10 */
    kResc_SRAM11_64KB       ,   /*!< SRAM partition11 */
    kResc_SRAM12_128KB      ,   /*!< SRAM partition12 */
    kResc_SRAM13_128KB      ,   /*!< SRAM partition13 */
    kResc_SRAM14_128KB      ,   /*!< SRAM partition14 */
    kResc_SRAM15_128KB      ,   /*!< SRAM partition15 */
    kResc_SRAM16_256KB      ,   /*!< SRAM partition16 */
    kResc_SRAM17_256KB      ,   /*!< SRAM partition17 */
    kResc_SRAM18_256KB      ,   /*!< SRAM partition18 */
    kResc_SRAM19_256KB      ,   /*!< SRAM partition19 */
    kResc_SRAM20_256KB      ,   /*!< SRAM partition20 */
    kResc_SRAM21_256KB      ,   /*!< SRAM partition21 */
    kResc_SRAM22_256KB      ,   /*!< SRAM partition22 */
    kResc_SRAM23_256KB      ,   /*!< SRAM partition23 */
    kResc_SRAM24_256KB      ,   /*!< SRAM partition24 */
    kResc_SRAM25_256KB      ,   /*!< SRAM partition25 */
    kResc_SRAM26_256KB      ,   /*!< SRAM partition26 */
    kResc_SRAM27_256KB      ,   /*!< SRAM partition27 */
    kResc_SRAM28_256KB      ,   /*!< SRAM partition28 */
    kResc_SRAM29_256KB      ,   /*!< SRAM partition29 */
    kResc_SRAM30_256KB      ,   /*!< SRAM partition30 */
    kResc_SRAM31_256KB      ,   /*!< SRAM partition31 */

    kResc_MaxNum            ,   /*!< Maximum number of supported constraints */
} resc_name_t;

/* Macros for Resource Constraint Group Types */
#define RESC_GROUP_PRAMS_START          kResc_SRAM_FLEXSPI0
#define RESC_GROUP_PRAMS_END            kResc_SRAM_LCDIF
#define RESC_GROUP_PRAMS_SIZE           RESC_GROUP_PRAMS_END - RESC_GROUP_PRAMS_START + 1

#define RESC_GROUP_SRAMS_START          kResc_SRAM0_32KB
#define RESC_GROUP_SRAMS_END            kResc_SRAM31_256KB
#define RESC_GROUP_SRAMS_SIZE           RESC_GROUP_SRAMS_END - RESC_GROUP_SRAMS_START + 1

#define RESC_GROUP_PERIPHERALS_START    kResc_MAIN_CLK
#define RESC_GROUP_PERIPHERALS_END      kResc_ROM
#define RESC_GROUP_PERIPHERALS_SIZE     RESC_GROUP_PERIPHERALS_END - RESC_GROUP_PERIPHERALS_START + 1

/*!
 * @brief Structure for peripheral SRAM resources, or bits in PDSLEEPCFG
 *
 */
typedef struct _enabled_resources_prams
{
    uint32_t apd_mask; /*!< PDSLEEPCFG1 mask for Array PD */
    uint32_t ppd_mask; /*!< PDSLEEPCFG1 mask for Periphery PD */
} enabled_resources_prams_t;

/*!
 * @brief Structure for other peripheral resources, or bit in PDSLEEPCFG
 *
 */
typedef struct _enabled_resources_peripherals
{
    uint8_t  group; /*!< Group for this enabled resource */
    uint32_t mask;  /*!< Mask in group for this enabled resource */
} enabled_resources_peripherals_t;


/* Constraints used by application. */
#define PM_RESC_MAIN_CLK_ON         PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_MAIN_CLK)
#define PM_RESC_VDDCOREREG_HP       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_VDDCOREREG_HP)
#define PM_RESC_PMCREF_HP           PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_PMCREF_HP)
#define PM_RESC_HVD1V8_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_HVD1V8)
#define PM_RESC_PORCORE_HP          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_PORCORE_HP)
#define PM_RESC_LVDCORE_HP          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_LVDCORE_HP)
#define PM_RESC_HVDCORE_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_HVDCORE)
#define PM_RESC_SYSXTAL_ON          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_SYSXTAL)
#define PM_RESC_LPOSC_ON            PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_LPOSC)
#define PM_RESC_FRO_192M96M_ON      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_FRO)
#define PM_RESC_SYSPLLLDO_ON        PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_SYSPLLLDO)
#define PM_RESC_SYSPLLANA_ON        PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_SYSPLLANA)
#define PM_RESC_AUDIOPLLLDO_ON      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_AUDIOPLLLDO)
#define PM_RESC_AUDIOPLLANA_ON      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_AUDIOPLLANA)
#define PM_RESC_ADC_TEMP_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_ADC_TEMP)
#define PM_RESC_PMC_TEMP_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_PMC_TEMP)
#define PM_RESC_ACMP_ACTIVE         PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_ACMP)
#define PM_RESC_PQ_SRAM_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_SRAM_PQ)
#define PM_RESC_CASPER_SRAM_ACTIVE  PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_SRAM_CASPER)
#define PM_RESC_DSP_ACTIVE          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_SRAM_DSP)
#define PM_RESC_MIPIDSI_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_MIPIDSI)
#define PM_RESC_OTP_ACTIVE          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_OTP)
#define PM_RESC_ROM_ACTIVE          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_ROM)

/* Note, to keep the ADC active in Sleep and Deep Sleep modes, the application must ensure the
 * ADC CTRL[DOZEN] bit is clear.  The fsl_lpadc driver configures this bit with the
 * LPADC_Init() API.
 */
#define PM_RESC_ADC_ACTIVE          PM_ENCODE_RESC(PM_RESOURCE_FULL_ON, kResc_ADC_ACTIVE)

#define PM_RESC_FLEXSPI0_SRAM_ACTIVE    PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_FLEXSPI0)
#define PM_RESC_FLEXSPI0_SRAM_RETENTION PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_FLEXSPI0)

#define PM_RESC_FLEXSPI1_SRAM_ACTIVE    PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_FLEXSPI1)
#define PM_RESC_FLEXSPI1_SRAM_RETENTION PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_FLEXSPI1)

#define PM_RESC_USB_SRAM_ACTIVE         PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_USB)
#define PM_RESC_USB_SRAM_RETENTION      PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_USB)

#define PM_RESC_USDHC0_SRAM_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_USDHC0)
#define PM_RESC_USDHC0_SRAM_RETENTION   PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_USDHC0)

#define PM_RESC_USDHC1_SRAM_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_USDHC1)
#define PM_RESC_USDHC1_SRAM_RETENTION   PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_USDHC1)

#define PM_RESC_GPU_SRAM_ACTIVE         PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_GPU)
#define PM_RESC_GPU_SRAM_RETENTION      PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_GPU)

#define PM_RESC_SMARTDMA_SRAM_ACTIVE    PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_SMARTDMA)
#define PM_RESC_SMARTDMA_SRAM_RETENTION PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_SMARTDMA)

#define PM_RESC_MIPIDSI_SRAM_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_MIPIDSI)
#define PM_RESC_MIPIDSI_SRAM_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_MIPIDSI)

#define PM_RESC_LCDIF_SRAM_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM_LCDIF)
#define PM_RESC_LCDIF_SRAM_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM_LCDIF)

#define PM_RESC_SRAM0_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM0_32KB)
#define PM_RESC_SRAM0_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM0_32KB)

#define PM_RESC_SRAM1_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM1_32KB)
#define PM_RESC_SRAM1_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM1_32KB)

#define PM_RESC_SRAM2_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM2_32KB)
#define PM_RESC_SRAM2_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM2_32KB)

#define PM_RESC_SRAM3_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM3_32KB)
#define PM_RESC_SRAM3_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM3_32KB)

#define PM_RESC_SRAM4_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM4_32KB)
#define PM_RESC_SRAM4_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM4_32KB)

#define PM_RESC_SRAM5_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM5_32KB)
#define PM_RESC_SRAM5_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM5_32KB)

#define PM_RESC_SRAM6_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM6_32KB)
#define PM_RESC_SRAM6_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM6_32KB)

#define PM_RESC_SRAM7_32KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM7_32KB)
#define PM_RESC_SRAM7_32KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM7_32KB)

#define PM_RESC_SRAM8_64KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM8_64KB)
#define PM_RESC_SRAM8_64KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM8_64KB)

#define PM_RESC_SRAM9_64KB_ACTIVE       PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM9_64KB)
#define PM_RESC_SRAM9_64KB_RETENTION    PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM9_64KB)

#define PM_RESC_SRAM10_64KB_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM10_64KB)
#define PM_RESC_SRAM10_64KB_RETENTION   PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM10_64KB)

#define PM_RESC_SRAM11_64KB_ACTIVE      PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM11_64KB)
#define PM_RESC_SRAM11_64KB_RETENTION   PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM11_64KB)

#define PM_RESC_SRAM12_128KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM12_128KB)
#define PM_RESC_SRAM12_128KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM12_128KB)

#define PM_RESC_SRAM13_128KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM13_128KB)
#define PM_RESC_SRAM13_128KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM13_128KB)

#define PM_RESC_SRAM14_128KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM14_128KB)
#define PM_RESC_SRAM14_128KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM14_128KB)

#define PM_RESC_SRAM15_128KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM15_128KB)
#define PM_RESC_SRAM15_128KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM15_128KB)

#define PM_RESC_SRAM16_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM16_256KB)
#define PM_RESC_SRAM16_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM16_256KB)

#define PM_RESC_SRAM17_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM17_256KB)
#define PM_RESC_SRAM17_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM17_256KB)

#define PM_RESC_SRAM18_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM18_256KB)
#define PM_RESC_SRAM18_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM18_256KB)

#define PM_RESC_SRAM19_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM19_256KB)
#define PM_RESC_SRAM19_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM19_256KB)

#define PM_RESC_SRAM20_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM20_256KB)
#define PM_RESC_SRAM20_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM20_256KB)

#define PM_RESC_SRAM21_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM21_256KB)
#define PM_RESC_SRAM21_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM21_256KB)

#define PM_RESC_SRAM22_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM22_256KB)
#define PM_RESC_SRAM22_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM22_256KB)

#define PM_RESC_SRAM23_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM23_256KB)
#define PM_RESC_SRAM23_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM23_256KB)

#define PM_RESC_SRAM24_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM24_256KB)
#define PM_RESC_SRAM24_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM24_256KB)

#define PM_RESC_SRAM25_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM25_256KB)
#define PM_RESC_SRAM25_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM25_256KB)

#define PM_RESC_SRAM26_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM26_256KB)
#define PM_RESC_SRAM26_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM26_256KB)

#define PM_RESC_SRAM27_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM27_256KB)
#define PM_RESC_SRAM27_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM27_256KB)

#define PM_RESC_SRAM28_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM28_256KB)
#define PM_RESC_SRAM28_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM28_256KB)

#define PM_RESC_SRAM29_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM29_256KB)
#define PM_RESC_SRAM29_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM29_256KB)

#define PM_RESC_SRAM30_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM30_256KB)
#define PM_RESC_SRAM30_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM30_256KB)

#define PM_RESC_SRAM31_256KB_ACTIVE     PM_ENCODE_RESC(PM_RESOURCE_FULL_ON,      kResc_SRAM31_256KB)
#define PM_RESC_SRAM31_256KB_RETENTION  PM_ENCODE_RESC(PM_RESOURCE_PARTABLE_ON1, kResc_SRAM31_256KB)

#if FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER

#endif

#endif /* _FSL_PM_BOARD_H_ */
