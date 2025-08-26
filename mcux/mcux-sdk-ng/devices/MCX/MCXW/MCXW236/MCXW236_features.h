/*
** ###################################################################
**     Version:             rev. 1.0, 2022-03-08
**     Build:               b250603
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**
** ###################################################################
*/

#ifndef _MCXW236_FEATURES_H_
#define _MCXW236_FEATURES_H_

/* SOC module features */

/* @brief CASPER availability on the SoC. */
#define FSL_FEATURE_SOC_CASPER_COUNT (1)
/* @brief CDOG availability on the SoC. */
#define FSL_FEATURE_SOC_CDOG_COUNT (1)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief CTIMER availability on the SoC. */
#define FSL_FEATURE_SOC_CTIMER_COUNT (5)
/* @brief DMA availability on the SoC. */
#define FSL_FEATURE_SOC_DMA_COUNT (2)
/* @brief FLEXCOMM availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCOMM_COUNT (3)
/* @brief GINT availability on the SoC. */
#define FSL_FEATURE_SOC_GINT_COUNT (1)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (1)
/* @brief SECGPIO availability on the SoC. */
#define FSL_FEATURE_SOC_SECGPIO_COUNT (1)
/* @brief HASHCRYPT availability on the SoC. */
#define FSL_FEATURE_SOC_HASHCRYPT_COUNT (1)
/* @brief I2C availability on the SoC. */
#define FSL_FEATURE_SOC_I2C_COUNT (3)
/* @brief INPUTMUX availability on the SoC. */
#define FSL_FEATURE_SOC_INPUTMUX_COUNT (1)
/* @brief IOCON availability on the SoC. */
#define FSL_FEATURE_SOC_IOCON_COUNT (1)
/* @brief MPU availability on the SoC. */
#define FSL_FEATURE_SOC_MPU_COUNT (1)
/* @brief MRT availability on the SoC. */
#define FSL_FEATURE_SOC_MRT_COUNT (1)
/* @brief OSTIMER availability on the SoC. */
#define FSL_FEATURE_SOC_OSTIMER_COUNT (1)
/* @brief PINT availability on the SoC. */
#define FSL_FEATURE_SOC_PINT_COUNT (1)
/* @brief SECPINT availability on the SoC. */
#define FSL_FEATURE_SOC_SECPINT_COUNT (1)
/* @brief PMC availability on the SoC. */
#define FSL_FEATURE_SOC_PMC_COUNT (1)
/* @brief PUF availability on the SoC. */
#define FSL_FEATURE_SOC_PUF_COUNT (1)
/* @brief PUF_SRAM_CTRL availability on the SoC. */
#define FSL_FEATURE_SOC_PUF_SRAM_CTRL_COUNT (1)
/* @brief ROMC availability on the SoC. */
#define FSL_FEATURE_SOC_ROMC_COUNT (1)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief SCT availability on the SoC. */
#define FSL_FEATURE_SOC_SCT_COUNT (1)
/* @brief SPI availability on the SoC. */
#define FSL_FEATURE_SOC_SPI_COUNT (3)
/* @brief SPIFI availability on the SoC. */
#define FSL_FEATURE_SOC_SPIFI_COUNT (1)
/* @brief SYSCON availability on the SoC. */
#define FSL_FEATURE_SOC_SYSCON_COUNT (1)
/* @brief SYSCTL1 availability on the SoC. */
#define FSL_FEATURE_SOC_SYSCTL1_COUNT (1)
/* @brief TRNG availability on the SoC. */
#define FSL_FEATURE_SOC_TRNG_COUNT (1)
/* @brief USART availability on the SoC. */
#define FSL_FEATURE_SOC_USART_COUNT (3)
/* @brief UTICK availability on the SoC. */
#define FSL_FEATURE_SOC_UTICK_COUNT (1)
/* @brief WWDT availability on the SoC. */
#define FSL_FEATURE_SOC_WWDT_COUNT (1)

/* ANALOGCTRL module features */

/* @brief Has PLL_USB_OUT_BIT_FIELD bitfile in XO32M_CTRL reigster. */
#define FSL_FEATURE_ANACTRL_HAS_NO_ENABLE_PLL_USB_OUT_BIT_FIELD (1)
/* @brief Has XO32M_ADC_CLK_MODE bitfile in DUMMY_CTRL reigster. */
#define FSL_FEATURE_ANACTRL_HAS_XO32M_ADC_CLK_MODE_BIF_FIELD (0)
/* @brief Has auxiliary bias(register AUX_BIAS). */
#define FSL_FEATURE_ANACTRL_HAS_AUX_BIAS_REG (0)
/* @brief ANACTRL interrupt control BOD1. */
#define FSL_FEATURE_ANACTRL_CONTROL_BOD1_INT (1)
/* @brief ANACTRL interrupt control BOD2. */
#define FSL_FEATURE_ANACTRL_CONTROL_BOD2_INT (1)
/* @brief BOD_DCDC_INT_CTRL reigster has BODCORE bit field. */
#define FSL_FEATURE_ANACTRL_HAS_BODCORE_BIT_FIELD (0)
/* @brief ANACTRL has XO32M_CTRL reigster. */
#define FSL_FEATURE_ANACTRL_HAS_XO32M_CTRL (0)
/* @brief FRO192M_CTRL reigster has 96MHz clock control. */
#define FSL_FEATURE_ANACTRL_HAS_96MHZCLK_CONTROL (0)

/* CASPER module features */

/* @brief Base address of the CASPER dedicated RAM */
#define FSL_FEATURE_CASPER_RAM_BASE_ADDRESS (0x04000000)
/* @brief HW interleaving of the CASPER dedicated RAM */
#define FSL_FEATURE_CASPER_RAM_HW_INTERLEAVE (1)
/* @brief CASPER dedicated RAM offset */
#define FSL_FEATURE_CASPER_RAM_OFFSET (0xC)

/* CDOG module features */

/* @brief SOC has no reset driver. */
#define FSL_FEATURE_CDOG_HAS_NO_RESET (0)
/* @brief CDOG Load default configurations during init function */
#define FSL_FEATURE_CDOG_NEED_LOAD_DEFAULT_CONF (0)

/* CTIMER module features */

/* @brief CTIMER has no capture channel. */
#define FSL_FEATURE_CTIMER_HAS_NO_INPUT_CAPTURE (0)
/* @brief CTIMER has no capture 2 interrupt. */
#define FSL_FEATURE_CTIMER_HAS_NO_IR_CR2INT (0)
/* @brief CTIMER capture 3 interrupt. */
#define FSL_FEATURE_CTIMER_HAS_IR_CR3INT (1)
/* @brief Has CTIMER CCR_CAP2 (register bits CCR[CAP2RE][CAP2FE][CAP2I]. */
#define FSL_FEATURE_CTIMER_HAS_NO_CCR_CAP2 (0)
/* @brief Has CTIMER CCR_CAP3 (register bits CCR[CAP3RE][CAP3FE][CAP3I]). */
#define FSL_FEATURE_CTIMER_HAS_CCR_CAP3 (1)
/* @brief CTIMER Has register MSR */
#define FSL_FEATURE_CTIMER_HAS_MSR (1)

/* DMA module features */

/* @brief Number of channels */
#define FSL_FEATURE_DMA_NUMBER_OF_CHANNELS (23)
/* @brief Align size of DMA descriptor */
#define FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZE (512)
/* @brief DMA head link descriptor table align size */
#define FSL_FEATURE_DMA_LINK_DESCRIPTOR_ALIGN_SIZE (16U)

/* FLEXCOMM module features */

/* @brief FLEXCOMM0 USART INDEX 0 */
#define FSL_FEATURE_FLEXCOMM0_USART_INDEX  (0)
/* @brief FLEXCOMM0 SPI INDEX 0 */
#define FSL_FEATURE_FLEXCOMM0_SPI_INDEX  (0)
/* @brief FLEXCOMM0 I2C INDEX 0 */
#define FSL_FEATURE_FLEXCOMM0_I2C_INDEX  (0)
/* @brief FLEXCOMM1 USART INDEX 1 */
#define FSL_FEATURE_FLEXCOMM1_USART_INDEX  (1)
/* @brief FLEXCOMM1 SPI INDEX 1 */
#define FSL_FEATURE_FLEXCOMM1_SPI_INDEX  (1)
/* @brief FLEXCOMM1 I2C INDEX 1 */
#define FSL_FEATURE_FLEXCOMM1_I2C_INDEX  (1)
/* @brief FLEXCOMM2 USART INDEX 2 */
#define FSL_FEATURE_FLEXCOMM2_USART_INDEX  (2)
/* @brief FLEXCOMM2 SPI INDEX 2 */
#define FSL_FEATURE_FLEXCOMM2_SPI_INDEX  (2)
/* @brief FLEXCOMM2 I2C INDEX 2 */
#define FSL_FEATURE_FLEXCOMM2_I2C_INDEX  (2)

/* HASHCRYPT module features */

/* @brief the address of alias offset */
#define FSL_FEATURE_HASHCRYPT_ALIAS_OFFSET (0x00000000)
/* @brief hashcrypt has reload feature */
#define FSL_FEATURE_HASHCRYPT_HAS_RELOAD_FEATURE (1)

/* INPUTMUX module features */

/* @brief Inputmux has DMA Request Enable */
#define FSL_FEATURE_INPUTMUX_HAS_SIGNAL_ENA (0)
/* @brief Inputmux has channel mux control */
#define FSL_FEATURE_INPUTMUX_HAS_CHANNEL_MUX (0)

/* IOCON module features */

/* @brief Func bit field width */
#define FSL_FEATURE_IOCON_FUNC_FIELD_WIDTH (4)

/* MRT module features */

/* @brief number of channels. */
#define FSL_FEATURE_MRT_NUMBER_OF_CHANNELS  (4)

/* PINT module features */

/* @brief Number of connected outputs */
#define FSL_FEATURE_PINT_NUMBER_OF_CONNECTED_OUTPUTS (8)

/* PLU module features */

/* @brief Has WAKEINT_CTRL register. */
#define FSL_FEATURE_PLU_HAS_WAKEINT_CTRL_REG (1)

/* PMC module features */

/* @brief UTICK does not support PD configure. */
#define FSL_FEATURE_UTICK_HAS_NO_PDCFG (1)
/* @brief WDT OSC does not support PD configure. */
#define FSL_FEATURE_WWDT_HAS_NO_PDCFG (1)

/* POWERLIB module features */

/* @brief Powerlib API is different with other LPC series devices. */
#define FSL_FEATURE_POWERLIB_EXTEND (1)

/* PUF module features */

/* @brief Number of PUF key slots available on device. */
#define FSL_FEATURE_PUF_HAS_KEYSLOTS (5)
/* @brief the shift status value */
#define FSL_FEATURE_PUF_HAS_SHIFT_STATUS (1)
/* @brief PUF has dedicated SRAM control */
#define FSL_FEATURE_PUF_HAS_SRAM_CTRL (1)
/* @brief Puf Activation Code Address. */
#define FSL_FEATURE_PUF_ACTIVATION_CODE_ADDRESS (1079304)
/* @brief Puf Activation Code Size. */
#define FSL_FEATURE_PUF_ACTIVATION_CODE_SIZE (1192)
/* @brief PUF has key reset. */
#define FSL_FEATURE_PUF_HAS_KEYRESET (1)

/* RTC module features */

/* @brief Has SUBSEC Register (register SUBSEC) */
#define FSL_FEATURE_RTC_HAS_SUBSEC (1)

/* SCT module features */

/* @brief Number of events */
#define FSL_FEATURE_SCT_NUMBER_OF_EVENTS (16)
/* @brief Number of states */
#define FSL_FEATURE_SCT_NUMBER_OF_STATES (32)
/* @brief Number of match capture */
#define FSL_FEATURE_SCT_NUMBER_OF_MATCH_CAPTURE (16)
/* @brief Number of outputs */
#define FSL_FEATURE_SCT_NUMBER_OF_OUTPUTS (10)

/* SECPINT module features */

/* @brief Number of connected outputs */
#define FSL_FEATURE_SECPINT_NUMBER_OF_CONNECTED_OUTPUTS (2)

/* SPI module features */

/* @brief SSEL pin count. */
#define FSL_FEATURE_SPI_SSEL_COUNT (2)

/* SPIFI module features */

/* @brief SPIFI start address */
#define FSL_FEATURE_SPIFI_START_ADDR (0x28000000)
/* @brief SPIFI end address */
#define FSL_FEATURE_SPIFI_END_ADDR (0x2FFFFFFF)

/* SYSCON module features */

/* @brief Flash phrase size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_PHRASE_SIZE_BYTES (16)
#define FSL_FEATURE_FLASH_PHRASE_SIZE_BYTES        FSL_FEATURE_SYSCON_FLASH_PHRASE_SIZE_BYTES
/* @brief Flash page size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_PAGE_SIZE_BYTES (128)
#define FSL_FEATURE_FLASH_PAGE_SIZE_BYTES        FSL_FEATURE_SYSCON_FLASH_PAGE_SIZE_BYTES
/* @brief Flash sector size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES (8192)
#define FSL_FEATURE_FLASH_SECTOR_SIZE_BYTES        FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES
#define FSL_FEATURE_FLASH_PFLASH_SECTOR_SIZE       FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE        (FSL_FEATURE_SYSCON_FLASH_SECTOR_SIZE_BYTES * 56)
/* @brief Flash size in bytes */
#define FSL_FEATURE_SYSCON_FLASH_SIZE_BYTES (1040384)
/* @brief Has Power Down mode */
#define FSL_FEATURE_SYSCON_HAS_POWERDOWN_MODE (1)
/* @brief CCM_ANALOG availability on the SoC.  */
#define FSL_FEATURE_SOC_CCM_ANALOG_COUNT (1)
/* @brief Starter register discontinuous. */
#define FSL_FEATURE_SYSCON_STARTER_DISCONTINUOUS (1)

/* SYSCTL1 module features */

/* @brief SYSCTRL has Code Gray feature. */
#define FSL_FEATURE_SYSCTRL_HAS_CODE_GRAY (1)

/* SysTick module features */

/* @brief Systick has external reference clock. */
#define FSL_FEATURE_SYSTICK_HAS_EXT_REF (0)
/* @brief Systick external reference clock is core clock divided by this value. */
#define FSL_FEATURE_SYSTICK_EXT_REF_CORE_DIV (0)

/* TRNG module features */

/* @brief TRNG has no TRNG_ACC bitfield. */
#define FSL_FEATURE_TRNG_HAS_NO_TRNG_ACC (0)

/* WWDT module features */

/* @brief Has no RESET register. */
#define FSL_FEATURE_WWDT_HAS_NO_RESET (1)
/* @brief WWDT does not support oscillator lock. */
#define FSL_FEATURE_WWDT_HAS_NO_OSCILLATOR_LOCK (1)

#endif /* _MCXW236_FEATURES_H_ */

