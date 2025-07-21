/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_PM_BOARD_H_
#define _FSL_PM_BOARD_H_

/** Calculates the uint32 array size for storing a bitmask of x bits */
#define BITMASK_SIZE(x) (((x - 1) / 32) + 1)

/** Calculates the offset in the bitmask array for the given bit position */
#define BITMASK_OFFSET(x) ((uint32_t)(x / 32))

/** Sets the bit in the given bitmask array */
#define BITMASK_SET(arr, x) ((arr)[(x) / 32] |= (1 << ((x) % 32)))

/** Sets the bit in the given bitmask array */
#define BITMASK_CLEAR(arr, x) ((arr)[(x) / 32] &= ~(1 << ((x) % 32)))

/** Checks whether a bit is set */
#define BITMASK_ISSET(arr, x) ((arr)[(x) / 32] & (1 << ((x) % 32)))

typedef enum
{
    kResource_Dcdc,
    kResource_Bod1,
    kResource_Bod2,
    kResource_Fro192m,
    kResource_Fro32k,
    kResource_Xtal32k,
    kResource_Fro1m,
    kResource_Trng,
    kResource_DcdcBypass,
    kResource_BleWup,
    kResource_Hfdsm,
    kResource_WakeupSys,
    kResource_WakeupDma0,
    kResource_WakeupGint0,
    kResource_WakeupPinInt0,
    kResource_WakeupPinInt1,
    kResource_WakeupPinInt2,
    kResource_WakeupPinInt3,
    kResource_WakeupUtick,
    kResource_WakeupMrt,
    kResource_WakeupCtimer0,
    kResource_WakeupCtimer1,
    kResource_WakeupSct,
    kResource_WakeupCtimer3,
    kResource_WakeupFlexcomm0,
    kResource_WakeupFlexcomm1,
    kResource_WakeupFlexcomm2,
    kResource_WakeupBleLl,
    kResource_WakeupBleSlpTmr,
    kResource_WakeupWdt,
    kResource_WakeupBod1,
    kResource_WakeupBod2,
    kResource_WakeupRtc,
    kResource_WakeupWakeDslp,
    kResource_WakeupPinInt4,
    kResource_WakeupPinInt5,
    kResource_WakeupPinInt6,
    kResource_WakeupPinInt7,
    kResource_WakeupCtimer2,
    kResource_WakeupCtimer4,
    kResource_WakeupOsEvent,
    kResource_WakeupSpifi,
    kResource_WakeupSecGpioInt0Irq0,
    kResource_WakeupSecGpioInt0Irq1,
    kResource_WakeupPlu,
    kResource_WakeupSecVio,
    kResource_WakeupTrng,
    kResource_WakeupDma1,
    kResource_WakeupWakePad,
    kResource_Count
} board_resource_t;

typedef uint32_t pm_board_resource_mask_t[BITMASK_SIZE(kResource_Count)];

/**
 * Initializes the board specific power manager component
 */
void PMBOARD_Init(void);

#endif /* _FSL_PM_BOARD_H_ */
