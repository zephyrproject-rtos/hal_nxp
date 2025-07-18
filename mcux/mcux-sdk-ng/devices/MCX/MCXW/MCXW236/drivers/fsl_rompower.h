/*
 * Copyright 2017,2020 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_POWER_H_
#define _FSL_POWER_H_

#include "fsl_common.h"

/** @defgroup rom_power ROM Power Driver
 * @ingroup power
 * @{
 */

/*******************
 * EXPORTED MACROS  *
 ********************/

/** @brief    Low Power main structure */
typedef struct
{                              /*     */
    __IO uint32_t CFG;         /*!< Low Power Mode Configuration, and miscallenous options  */
    __IO uint32_t PDCTRL0;     /*!< Power Down control : controls power of various modules
                                   in the different Low power modes, including ROM */
    __IO uint32_t SRAMRETCTRL; /*!< Power Down control : controls power SRAM instances
                                      in the different Low power modes */
    __IO uint32_t CPURETCTRL;  /*!< CPU0 retention control : controls CPU retention parameters in POWER DOWN modes */
    __IO uint64_t VOLTAGE;     /*!< Voltage control in Low Power Modes */
    __IO uint64_t WAKEUPSRC;   /*!< Wake up sources control for sleepcon */
    __IO uint64_t WAKEUPINT;   /*!< Wake up sources control for ARM */
    __IO uint32_t HWWAKE;      /*!< Interrupt that can postpone power down modes
                                  in case an interrupt is pending when the processor request deepsleep */
    __IO uint32_t WAKEUPIOSRC; /*!< Wake up I/O sources in DEEP POWER DOWN mode */
    __IO uint32_t TIMERCFG;    /*!< Wake up timers configuration */
    __IO uint32_t TIMERCOUNT;  /*!< Wake up Timer count*/
    __IO uint32_t POWERCYCLE;  /*!< Cancels entry in Low Power mode if set with 0xDEADABBA (might be used by some
                                  interrupt handlers)*/
} LPC_LOWPOWER_T;

/*   */
#define LOWPOWER_POWERCYCLE_CANCELLED 0xDEADABBA /*!<    */

/* Low Power modes  */
#define LOWPOWER_CFG_LPMODE_INDEX       0
#define LOWPOWER_CFG_LPMODE_MASK        (0x3UL << LOWPOWER_CFG_LPMODE_INDEX)
#define LOWPOWER_CFG_SELCLOCK_INDEX     2
#define LOWPOWER_CFG_SELCLOCK_MASK      (0x1UL << LOWPOWER_CFG_SELCLOCK_INDEX)
#define LOWPOWER_CFG_SELMEMSUPPLY_INDEX 3
#define LOWPOWER_CFG_SELMEMSUPPLY_MASK  (0x1UL << LOWPOWER_CFG_SELMEMSUPPLY_INDEX)

#define LOWPOWER_CFG_LPMODE_ACTIVE        0 /*!< ACTIVE mode */
#define LOWPOWER_CFG_LPMODE_DEEPSLEEP     1 /*!< DEEP SLEEP mode */
#define LOWPOWER_CFG_LPMODE_POWERDOWN     2 /*!< POWER DOWN mode */
#define LOWPOWER_CFG_LPMODE_DEEPPOWERDOWN 3 /*!< DEEP POWER DOWN mode */
#define LOWPOWER_CFG_LPMODE_SLEEP         4 /*!< SLEEP mode */

#define LOWPOWER_CFG_SELCLOCK_1MHZ 0 /*!< The 1 MHz clock is used during the configuration of the PMC */
#define LOWPOWER_CFG_SELCLOCK_12MHZ                          \
    1 /*!< The 12 MHz clock is used during the configuration \
        of the PMC (to speed up PMC configuration process)*/

#define LOWPOWER_CFG_SELMEMSUPPLY_LDOMEM                       \
    0 /*!< In DEEP SLEEP power mode, the Memories are supplied \
        by the LDO_MEM */
#define LOWPOWER_CFG_SELMEMSUPPLY_LDODEEPSLEEP                 \
    1 /*!< In DEEP SLEEP power mode, the Memories are supplied \
        by the LDO_DEEP_SLEEP (or DCDC)  */

/* CPU Retention Control*/
#define LOWPOWER_CPURETCTRL_ENA_INDEX           0
#define LOWPOWER_CPURETCTRL_ENA_MASK            (0x1UL << LOWPOWER_CPURETCTRL_ENA_INDEX)
#define LOWPOWER_CPURETCTRL_MEMBASE_INDEX       1
#define LOWPOWER_CPURETCTRL_MEMBASE_MASK        (0x1FFF << LOWPOWER_CPURETCTRL_MEMBASE_INDEX)
#define LOWPOWER_CPURETCTRL_RETDATALENGTH_INDEX 14
#define LOWPOWER_CPURETCTRL_RETDATALENGTH_MASK  (0x3FFUL << LOWPOWER_CPURETCTRL_RETDATALENGTH_INDEX)

#define LOWPOWER_CPURETCTRL_ENA_DISABLE 0 /*!< In POWER DOWN mode, CPU Retention is disabled */
#define LOWPOWER_CPURETCTRL_ENA_ENABLE  1 /*!< In POWER DOWN mode, CPU Retention is enabled  */

/**
 * @brief Analog components power modes control during low power modes
 */
/*!< Shut down DCDC Converter during low power modes                       */
#define LOWPOWER_PDCTRL0_PDEN_DCDC (1UL << 0)
/*!< Shut down Analog references during low power modes                    */
#define LOWPOWER_PDCTRL0_PDEN_BIAS (1UL << 1)
/*!< Shut down Core logic Brown Out Detector during low power modes        */
#define LOWPOWER_PDCTRL0_PDEN_BODCORE (1UL << 2)
/*!< Shut down Battery Brown Out Detector during low power modes           */
#define LOWPOWER_PDCTRL0_PDEN_BODVBAT (1UL << 3)
/*!< Shut down 1 MHz Free Running Oscillator during low power modes        */
#define LOWPOWER_PDCTRL0_PDEN_FRO1M (1UL << 4)
/*!< Shut down 192 MHz Free Running Oscillator during low power modes      */
#define LOWPOWER_PDCTRL0_PDEN_FRO192M (1UL << 5)
/*!< Shut down 32 KHz Running Oscillator during low power modes            */
#define LOWPOWER_PDCTRL0_PDEN_FRO32K (1UL << 6)
/*!< Shut down 32 KHz chrystal Oscillator during low power modes           */
#define LOWPOWER_PDCTRL0_PDEN_XTAL32K (1UL << 7)
/*!< Shut down 32 MHz chrystal Oscillator during low power modes           */
#define LOWPOWER_PDCTRL0_PDEN_XTAL32M (1UL << 8)
/*!< Shut down PLL0 (System) during low power modes                        */
#define LOWPOWER_PDCTRL0_PDEN_PLLSYS (1UL << 9)
/*!< Shut down PLL1 (USB Full Speed) during low power modes                */
#define LOWPOWER_PDCTRL0_PDEN_PLLUSB (1UL << 10)
/*!< Shut down USB Full Speed Phy during low power modes                   */
#define LOWPOWER_PDCTRL0_PDEN_USBFSPHY (1UL << 11)
/*!< Shut down USB High Speed Phy  during low power modes                  */
#define LOWPOWER_PDCTRL0_PDEN_USBHSPHY (1UL << 12)
/*!< Shut down Analog Comparator during low power modes                    */
#define LOWPOWER_PDCTRL0_PDEN_COMP (1UL << 13)
/*!< Shut down Temperature Sensor during low power modes                   */
#define LOWPOWER_PDCTRL0_PDEN_TEMPSENS (1UL << 14)
/*!< Shut down General Purpose ADC during low power modes                  */
#define LOWPOWER_PDCTRL0_PDEN_GPADC (1UL << 15)
/*!< Shut down Memories LDO during low power modes                         */
#define LOWPOWER_PDCTRL0_PDEN_LDOMEM (1UL << 16)
/*!< Shut down Deep Sleep LDO during low power modes                       */
#define LOWPOWER_PDCTRL0_PDEN_LDODEEPSLEEP (1UL << 17)
/*!< Shut down USB High Speed LDO during low power modes                   */
#define LOWPOWER_PDCTRL0_PDEN_LDOUSBHS (1UL << 18)
/*!< Shut down General purpose ADC LDO during low power modes              */
#define LOWPOWER_PDCTRL0_PDEN_LDOGPADC (1UL << 19)
/*!< Shut down Chrystal 32 MHz LDO during low power modes                  */
#define LOWPOWER_PDCTRL0_PDEN_LDOXO32M (1UL << 20)
/*!< Shut down Flash NV LDO during low power modes                         */
#define LOWPOWER_PDCTRL0_PDEN_LDOFLASHNV (1UL << 21)
/*!< Shut down Random Number Generators sources during low power modes     */
#define LOWPOWER_PDCTRL0_PDEN_RNG (1UL << 22)
/*!< Shut down PLL0 Spread Spectrum Clock generator during low power modes */
#define LOWPOWER_PDCTRL0_PDEN_PLLSYS_SSCG (1UL << 23)
/*!< Shut down ROM during low power modes                                  */
#define LOWPOWER_PDCTRL0_PDEN_ROM (1UL << 24)

/**
 * @brief SRAM instances retention control during low power modes
 */
/*!< Enable SRAMX_0 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAMX0 (1UL << 0)
/*!< Enable SRAMX_1 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAMX1 (1UL << 1)
/*!< Enable SRAMX_2 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAMX2 (1UL << 2)
/*!< Enable SRAMX_3 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAMX3 (1UL << 3)
/*!< Enable SRAM0_0 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM00 (1UL << 4)
/*!< Enable SRAM0_1 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM01 (1UL << 5)
/*!< Enable SRAM1_0 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM10 (1UL << 6)
/*!< Enable SRAM2_0 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM20 (1UL << 7)
/*!< Enable SRAM3_0 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM30 (1UL << 8)
/*!< Enable SRAM3_1 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM31 (1UL << 9)
/*!< Enable SRAM4_0 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM40 (1UL << 10)
/*!< Enable SRAM4_1 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM41 (1UL << 11)
/*!< Enable SRAM4_2 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM42 (1UL << 12)
/*!< Enable SRAM4_3 retention when entering in Low power modes       */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM43 (1UL << 13)
/*!< Enable SRAM USB HS retention when entering in Low power modes   */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM_USB_HS (1UL << 14)
/*!< Enable SRAM PUFF retention when entering in Low power modes     */
#define LOWPOWER_SRAMRETCTRL_RETEN_RAM_PUF (1UL << 15)

/**
 * @brief LDO Voltage control in Low Power Modes
 */
#define LOWPOWER_VOLTAGE_LDO_PMU_INDEX        0
#define LOWPOWER_VOLTAGE_LDO_MEM_INDEX        5
#define LOWPOWER_VOLTAGE_LDO_DEEP_SLEEP_INDEX 10
#define LOWPOWER_VOLTAGE_LDO_PMU_BOOST_INDEX  19
#define LOWPOWER_VOLTAGE_LDO_MEM_BOOST_INDEX  24
#define LOWPOWER_VOLTAGE_DCDC_INDEX           29

#define LOWPOWER_VOLTAGE_LDO_PMU_MASK        (0x1FULL << LOWPOWER_VOLTAGE_LDO_PMU_INDEX)
#define LOWPOWER_VOLTAGE_LDO_MEM_MASK        (0x1FULL << LOWPOWER_VOLTAGE_LDO_MEM_INDEX)
#define LOWPOWER_VOLTAGE_LDO_DEEP_SLEEP_MASK (0x7ULL << LOWPOWER_VOLTAGE_LDO_DEEP_SLEEP_INDEX)
#define LOWPOWER_VOLTAGE_LDO_PMU_BOOST_MASK  (0x1FULL << LOWPOWER_VOLTAGE_LDO_PMU_BOOST_INDEX)
#define LOWPOWER_VOLTAGE_LDO_MEM_BOOST_MASK  (0x1FULL << LOWPOWER_VOLTAGE_LDO_MEM_BOOST_INDEX)
#define LOWPOWER_VOLTAGE_DCDC_MASK           (0x7ULL << LOWPOWER_VOLTAGE_DCDC_INDEX)

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief    Shut off the Flash and execute the _WFI(), then power up the Flash after wake-up event
 * @param    None
 * @return    Nothing
 */
void CHIPLOWPOWER_PowerCycleCpuAndFlash(void);

/**
 * @brief    Configure and enters in low power mode
 * @param    p_lowpower_cfg: pointer to a structure that contains all low power mode parameters
 * @return   Nothing
 */
void CHIPLOWPOWER_SetLowPowerMode(LPC_LOWPOWER_T *p_lowpower_cfg);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _FSL_POWER_H_ */
