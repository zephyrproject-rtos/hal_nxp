/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_CONFIG_H_
#define _FWK_CONFIG_H_

#include "fwk_platform_definitions.h"

/*********************************************************************
 *        General
 *********************************************************************/

/* This platform has an NBU domain */
#define gPlatformHasNbu_d 1

/* Defines the calibration duration of the ADC, it will block the task during this time in milisec before trigger the
 * ADC on a channel*/
#define gSensorsAdcCalibrationDurationInMs_c 4U

/*
 * KW45/K32W148 CM33 core has the DSP extension (__DSP_PRESENT), which allows the use of the NXP UltraFast EC P256
 * library. The flags may be set to 0 if this library is not required. It mainly makes sense for Matter SPAKE2P
 * procedures and for BLE point validation.
 */
#define gSecLibUseDspExtension_d 1

/*********************************************************************
 *        HW parameters enablement and placement
 *********************************************************************/

#if !defined(gPlatformUseHwParameter_d)
#define gPlatformUseHwParameter_d 1
#endif
/*
 * gHwParamsProdDataMainFlashMode_c HWParameters PROD_DATA remain at top of main flash,
 * where the linker script defines PROD_DATA_BASE_ADDR.
 * When transiting from MainFlashMode to IfrMode, an interim mode MainFlash2IfrMode is used to
 * enable the transfer of HWParameters from the main flash to the IFR.
 * After this has been applied the size of the PROD_DATA reserved space in the linker script
 * will be made 0 in order to gain a sector.
 * These modes are used to configure gHwParamsProdDataPlacement_c
 */
#define gHwParamsProdDataMainFlashMode_c     0
#define gHwParamsProdDataMainFlash2IfrMode_c 1
#define gHwParamsProdDataIfrMode_c           2

/*
 * Place Application FactoryData in same sector as ProdData.
 * HWParameters and App Factory Data being colocated has an implication on the life cycle of information stored in the
 * sector.
 */
#ifndef gHwParamsAppFactoryDataExtension_d
#define gHwParamsAppFactoryDataExtension_d 0
#endif

/*
 * To be defined as 1 if NV_WriteHWParameters is liable to be invoked after Application Factory Data were written,
 * and you intend not to have to preprogram them. Default to 0, assuming that this can happne in the context of
 * a factory reset. Not needed if gHwParamsAppFactoryDataExtension_d is not set.
 */
#if (gHwParamsAppFactoryDataExtension_d != 0)
#ifndef gHwParamsAppFactoryDataPreserveOnHwParamUpdate_d
#define gHwParamsAppFactoryDataPreserveOnHwParamUpdate_d 0
#endif
#else
#define gHwParamsAppFactoryDataPreserveOnHwParamUpdate_d 0
#endif
/*
 * Define gHwParamsProdDataPlacement_c as :
 *   - gHwParamsProdDataMainFlash_c if you mean to remain backward compatible.
 *   - gHwParamsProdDataMainFlash2IfrMode_c if you wish to conserve previous
 *     HWParameter setting (MAC addresses, xtal trimming data) during migration phase.
 *   - gHwParamsProdDataIfrMode_c for new devices or once gHwParamsProdDataMainFlash2IfrMode_c
 *     mode has populated the IFR with legacy values. -> after this phase update linker script to remove
 *     flash space reserved for PROD_DATA.
 */
#ifndef gHwParamsProdDataPlacement_c
//#define gHwParamsProdDataPlacement_c gHwParamsProdDataMainFlashMode_c
//#define gHwParamsProdDataPlacement_c gHwParamsProdDataMainFlash2IfrMode_c
#define gHwParamsProdDataPlacement_c gHwParamsProdDataIfrMode_c
#endif

#if (gHwParamsProdDataPlacement_c == gHwParamsProdDataMainFlashMode_c)
#define PROD_DATA_FLASH_ADDR (MAIN_FLASH_PROD_DATA_ADDR + PROD_DATA_OFFSET)
#define USER_DATA_SECTOR     PROD_DATA_FLASH_ADDR
#else
/*
 * IFR_RSVD_SZ may be undefined or set to 0 if no reserved space is required.
 * However keep it as 0x600 during the internal development phase.
 */
#define IFR_RSVD_SZ 0x600

#if (defined IFR_RSVD_SZ) && (IFR_RSVD_SZ > 0)
#define PROD_DATA_FLASH_ADDR (IFR_USER_ADDR + IFR_RSVD_SZ + PROD_DATA_OFFSET)
#else
#define PROD_DATA_FLASH_ADDR (IFR_USER_ADDR + PROD_DATA_OFFSET)
#endif
#define USER_DATA_SECTOR PROD_DATA_FLASH_ADDR
#endif

#ifdef gHwParamsAppFactoryDataExtension_d
#define APP_FACTORY_DATA_FLASH_ADDR (PROD_DATA_FLASH_ADDR + APP_FACTORY_DATA_OFFSET)
#endif

/*********************************************************************
 *        Reset Method
 * Define the alternative method from warm reset to use for Device reset
 *   when calling PLATFORM_ResetCpu()
 *********************************************************************/
#define gUseResetByNvicReset_c     1
#define gUseResetByLvdForce_c      2
#define gUseResetByDeepPowerDown_c 3

#if !defined(gPlatResetMethod_c)
#if defined(FPGA_TARGET) && (FPGA_TARGET == 1)
#define gPlatResetMethod_c gUseResetByNvicReset_c
#else
#define gPlatResetMethod_c gUseResetByDeepPowerDown_c
#endif
#endif

/*********************************************************************
 *   Flash check for ECC error after IFR OT_CFG programming.
 *
 *  Defaults to 1 to avoid bus fault in case of error
 *  Temporarily leave as 0 to before full OTA testing is done.
 *********************************************************************/
#ifndef gOtaCheckEccFaults_d
#define gOtaCheckEccFaults_d 1
#endif

/*********************************************************************
 *   NVS Sector size is necessarily a multiple of physical flash sector size.
 *
 *  Defaults to 1 because 8kB is already pretty large. cannot exceed 8 sectors.
 *
 *********************************************************************/
#ifndef gPlatNvsSectorSize_c
#define gPlatNvsSectorSize_c (PLATFORM_INTFLASH_SECTOR_SIZE * 1u)
#endif

/*********************************************************************
 *        RNG source of entropy
 *********************************************************************/

/* On wireless_mcu platform the only source of entropy disponible is the S200 */
#ifndef gRngUseSecureSubSystem_d
#define gRngUseSecureSubSystem_d 1
#endif

/*********************************************************************
 *        SecLib
 *********************************************************************/
/* If SecLib.c is used, prevent from using LTC HW as this module is located on NBU side and is used exclusively
 by Ble controller and 15.4 MAC/Phy code */
#undef FSL_FEATURE_SOC_LTC_COUNT

/*********************************************************************
 *        NBU debuggability
 *********************************************************************/
/* Enable NBU access to GPIO PORT D - This allows easier debugging when an issue is reported with a specific main core
 * binary.
 * \warning: Disabling this compile macro can impair the debug capability of the NBU for a specific main core binary.
 * \warning: This part of code can generate bus fault when trustzone is enabled (code executed in non secure mode).
 *      Reason is that TRDC_IDAU_CR can not be read. In this case, user shall disable this compile macro when running
 *      in non secure mode.
 * */
#if !defined(gPlatformNbuDebugGpioDAccessEnabled_d)
#define gPlatformNbuDebugGpioDAccessEnabled_d 1
#endif

/*********************************************************************
 *        PLATFORM
 *********************************************************************/
/* Enable ICS RX processing in the system workqueue thread
 * If enabled, the ICS will use the system workqueue to process its received data. This allows to reduce the time spent
 * in the ISR and reduces impact on system activities.
 * Note: the system workqueue requires a dedicated thread, so enabling this feature will consume a bit of RAM for the
 * thread stack (this can be configured).
 */
#ifndef gPlatformIcsUseWorkqueueRxProcessing_d
#define gPlatformIcsUseWorkqueueRxProcessing_d 0
#endif

/* Address which can trigger a dummy interrupt on NBU. Used in PLATFORM_RemoteActiveReq() to ensure code is executed on
 * NBU when trying to access to its power domain. In some corner cases NBU could become irresponsive if the NBU power domain was woken up without executing any code on the core  */
#define gPlatformNbuWakeUpInterruptAddr 0x48949410U

/*! Enable/Disable shutdown of ECC RAM banks during low power period like Deep Sleep or Power Down
 *  Shutting down ECC RAM banks allows to save about 1uA
 *  The RAM banks can be selectively reinitialized by calling MEM_ReinitRamBank API
 *  The MemoryManagerLight will call this API when allocating a new block in the heap
 *  Defining this flag to 0 will make the system shutdown only the non-ecc banks */
#ifndef gPlatformShutdownEccRamInLowPower
#define gPlatformShutdownEccRamInLowPower 1
#endif

#if defined(gPlatformShutdownEccRamInLowPower) && (gPlatformShutdownEccRamInLowPower > 0)
/* In this configuration, all RAM banks can be shutdown during low power if not used
 * The ECC RAM banks can be selectively reinitialized with MEM_ReinitRamBank API
 * This API is also used by the Memory Manager Light */
#define PLATFORM_SELECT_RAM_RET_START_IDX 0U
#define PLATFORM_SELECT_RAM_RET_END_IDX   7U
#else
/* STCM3 and STCM4 only are non-ECC RAM banks
 * NOTE: the following values should be aligned with PLATFORM_BANK_IS_ECC definition
 */
#define PLATFORM_SELECT_RAM_RET_START_IDX 5U
#define PLATFORM_SELECT_RAM_RET_END_IDX   6U
#endif /* gPlatformShutdownEccRamInLowPower */

/* Allow verification of FRO6M frequency validity: in some extremely rare situations FRO6M was observed oscillating at 2
 * MHz instead of 6MHz.
 * Defining gPlatformEnableFro6MCalLowpower_d as 1 enables an assessment of its value at each wake up by comparing TSTMR tick against core clock.
 * This FRO6M assessment is performed in parallel of other wake up operations but causes the wake up procedure to last at least 6 usec.
 */
#ifndef gPlatformEnableFro6MCalLowpower_d
#define gPlatformEnableFro6MCalLowpower_d 1
#endif

#endif /* _FWK_CONFIG_H_ */
