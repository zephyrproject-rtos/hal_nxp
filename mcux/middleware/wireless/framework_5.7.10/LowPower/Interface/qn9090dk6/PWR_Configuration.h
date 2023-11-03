/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2020 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _PWR_CONFIGURATION_H_
#define _PWR_CONFIGURATION_H_

/*****************************************************************************
 *                               INCLUDED HEADERS                            *
 *---------------------------------------------------------------------------*
 * Add to this section all the headers that this module needs to include.    *
 * Note that it is not a good practice to include header files into header   *
 * files, so use this section only if there is no other better solution.     *
 *---------------------------------------------------------------------------*
 *****************************************************************************/
#include "TimersManager.h"

/************************************************************************************
 *************************************************************************************
 * Module configuration constants
 *************************************************************************************
 ************************************************************************************/

/*-----------------------------------------------------------------------------
 * To enable/disable all of the code in this PWR/PWRLib files.
 *   TRUE =  1: Use Lowpower functions (Normal)
 *   FALSE = 0: Don't use Lowpower - only WFI. Will cut variables and code out. But
 *              functions still exist. Useful for debugging and test purposes
 */
#ifndef cPWR_UsePowerDownMode
#define cPWR_UsePowerDownMode            FALSE
#endif

#ifndef cPWR_FullPowerDownMode
#define cPWR_FullPowerDownMode           FALSE
#endif

#ifndef cPWR_EnableDeepSleepMode_4
#define cPWR_EnableDeepSleepMode_4     	 FALSE
#endif

#ifndef gAppDeepSleepMode_c
#define gAppDeepSleepMode_c    1
#endif

/* ------------------------------------------------------------------------------------------------------*/
/* Mode                                     | Osc | RAM | AO LDO | TMR | PWRM mapping                    */
/*-------------------------------------------------------------------------------------------------------*/
/* 1 cPWR_ClockGating                       | On  | On  | Build  | On  | E_AHI_SLEEP_OSCON_RAMON         */
/* 2 cPWR_DeepSleep_RamOffOsc32kOn          | On  | Off | Build  | On  | E_AHI_SLEEP_OSCON_RAMOFF        */
/* 3 cPWR_PowerDown_RamRet                  | On  | On  | Reduce | On  |                                 */
/* 4 cPWR_DeepSleep_RamOffOsc32kOff         | Off | Off | Reduce | NA  |                                 */
/* 5 cPWR_DeepSleep_RamOnOsc32kOff          | Off | On  | Reduce | NA  | E_AHI_SLEEP_OSCOFF_RAMON        */
/* 6 cPWR_DeepSleep_RamOffOsc32kOff2        | Off | Off | Reduce | NA  | E_AHI_SLEEP_OSCOFF_RAMOFF       */
/* 7 cPWR_DeepSleep_RamOffOsc32kOnTimersOff | On  | Off | Reduce | Off | E_AHI_SLEEP_OSCON_RAMOFF_TMROFF */

/* Mode 4 and Mode 6 are identical except that mode 4 may be compiled using cPWR_EnableDeepSleepMode_4 */
/* Mode 2 and 7 are similar except that timer wake sources are stopped in mode 7 */
/* Mode 7 allows DIO retention while keeping the Osc32k */

#define cPWR_NoClockGating                      0u
#define cPWR_ClockGating                        1u
#define cPWR_DeepSleep_RamOffOsc32kOn           2u
#define cPWR_PowerDown_RamRet                   3u
#define cPWR_DeepSleep_RamOffOsc32kOff          4u
#define cPWR_DeepSleep_RamOnOsc32kOff           5u
#define cPWR_DeepSleep_RamOffOsc32kOff2         6u
#define cPWR_DeepSleep_RamOffOsc32kOnTimersOff  7u


#ifndef gPWR_LpOscOptim
/* gPWR_LpOscOptim must be 0 to wait for the BLE Osc before going into LowPower.
 * Otherwise, the LinkLayer may wakeup the device directly after going into LowPower*/
#define gPWR_LpOscOptim                        0
#endif

#ifndef gPWR_Xtal32MDeactMode
#define gPWR_Xtal32MDeactMode                  1
#endif

#ifndef gPWR_Xtal32MSwitchOffEarlier
#define gPWR_Xtal32MSwitchOffEarlier           0
#endif


#if cPWR_UsePowerDownMode
  #if cPWR_FullPowerDownMode
  #define cPWR_DeepSleepMode                     cPWR_PowerDown_RamRet
  #else
  #define cPWR_DeepSleepMode                     cPWR_ClockGating
  #endif
#else
  #define cPWR_DeepSleepMode                     cPWR_NoClockGating
#endif

#ifndef gSupportBle
/* BLE features (checks BLE status, uses BLE timers) */
#define gSupportBle (1)
#endif

/*  Check the calibration results either at the end of the SW wakeup sequence or before going to lowpower
    FRO32K calibration is always started on device wake up if gClkRecalFro32K is set to 1. The calibration results can be
    retrieved
      1 : at sofware wakeup  sequence completion, However the calibration duration (defined by FRO32K_CAL_SCALE) shall be
          smaller and the accuracy of the measurement will be lower.
      0 : When going to low power after active period. This allows a larger calibration duration, increasing the accuracy of the measurement
 */
#ifndef PWR_FRO32K_CAL_WAKEUP_END
#define PWR_FRO32K_CAL_WAKEUP_END         0
#endif

/* Number of times the wakeup Reason is checked before proceeding on powerdown exit */
#ifndef PWR_WakeupReasonWaitingLoop
#define PWR_WakeupReasonWaitingLoop  1
#endif

#ifndef gPWR_BleLL_EarlyEnterDsm
#if !defined(DUAL_MODE_APP) && (defined(gSupportBle) && (gSupportBle == 1))
#define gPWR_BleLL_EarlyEnterDsm     1
#else
#define gPWR_BleLL_EarlyEnterDsm     0
#endif
#endif

#ifndef gPWR_LpEntryStructOptim
#define gPWR_LpEntryStructOptim      1
#endif

#if 1
#define gPWR_ForceWakeTimer0_WakeupSrc  1
#define gPWR_ForceWakeTimer1_WakeupSrc  1
#define gPWR_ForceRtc_WakeupSrc         1

#else
/* flags may not be set in this file */
#if ((gTimestamp_Enabled_d == 1) && (gTimestampUseWtimer_c == 0)) || (gLoggingActive_d == 1)
/* No need for WakeTimer 0 wakeup source for Timestamping */
//#define gPWR_ForceWakeTimer0_WakeupSrc  1
#endif

#if ( /*(gTimestamp_Enabled_d == 1) && (gTimestampUseWtimer_c == 1)) ||*/ (mAppUseTickLessMode_c ==1)  )
#define gPWR_ForceWakeTimer1_WakeupSrc  1
#endif

#if (gTMR_Enabled_d == 1)
#define gPWR_ForceRtc_WakeupSrc         1
#endif
#endif

#endif /* _PWR_CONFIGURATION_H_ */

