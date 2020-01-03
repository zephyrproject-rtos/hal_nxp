/*
 * Copyright 2014, NXP
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MAILBOX_H_
#define _FSL_MAILBOX_H_

#include "fsl_common.h"

/*!
 * @addtogroup mailbox
 * @{
 */

/*! @file */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.mailbox"
#endif

/*! @name Driver version */
/*@{*/
/*! @brief MAILBOX driver version 2.1.0. */
#define FSL_MAILBOX_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*@}*/

/*!
 * @brief CPU ID.
 */
#if (defined(LPC55S69_cm33_core0_SERIES) || defined(LPC55S69_cm33_core1_SERIES))
typedef enum _mailbox_cpu_id
{
    kMAILBOX_CM33_Core1 = 0,
    kMAILBOX_CM33_Core0
} mailbox_cpu_id_t;
#elif (defined(CPU_NXH2004J640UK48))
typedef enum _mailbox_cpu_id
{
    kMAILBOX_CM0Plus_Core0 = 0,
    kMAILBOX_CM0Plus_Core1
} mailbox_cpu_id_t;

typedef enum _mailbox_sw_irq_id
{
    kMAILBOX_CM0Plus_Sw_Irq0 = 2,
    kMAILBOX_CM0Plus_Sw_Irq1,
    kMAILBOX_CM0Plus_Sw_Irq2,
    kMAILBOX_CM0Plus_Sw_Irq3
} mailbox_sw_irq_id_t;

#else
typedef enum _mailbox_cpu_id
{
    kMAILBOX_CM0Plus = 0,
    kMAILBOX_CM4
} mailbox_cpu_id_t;
#endif
/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @name MAILBOX initialization
 * @{
 */

/*!
 * @brief Initializes the MAILBOX module.
 *
 * This function enables the MAILBOX clock only.
 *
 * @param base MAILBOX peripheral base address.
 */
static inline void MAILBOX_Init(MAILBOX_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(kCLOCK_Mailbox);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
#if !(defined(FSL_FEATURE_MAILBOX_HAS_NO_RESET) && FSL_FEATURE_MAILBOX_HAS_NO_RESET)
    /* Reset the MAILBOX module */
    RESET_PeripheralReset(kMAILBOX_RST_SHIFT_RSTn);
#endif
}

/*!
 * @brief De-initializes the MAILBOX module.
 *
 * This function disables the MAILBOX clock only.
 *
 * @param base MAILBOX peripheral base address.
 */
static inline void MAILBOX_Deinit(MAILBOX_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(kCLOCK_Mailbox);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/* @} */

/*!
 * @brief Set data value in the mailbox based on the CPU ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param cpu_id CPU id, kMAILBOX_CM0Plus or kMAILBOX_CM4 for LPC5410x and LPC5411x devices,
 *               kMAILBOX_CM33_Core0 or kMAILBOX_CM33_Core1 for LPC55S69 devices.
 * @param mboxData Data to send in the mailbox.
 *
 * @note Sets a data value to send via the MAILBOX to the other core.
 */
static inline void MAILBOX_SetValue(MAILBOX_Type *base, mailbox_cpu_id_t cpu_id, uint32_t mboxData)
{
#if (defined(LPC55S69_cm33_core0_SERIES) || defined(LPC55S69_cm33_core1_SERIES))
    assert((cpu_id == kMAILBOX_CM33_Core0) || (cpu_id == kMAILBOX_CM33_Core1));
#elif (defined(CPU_NXH2004J640UK48))
    assert((cpu_id == kMAILBOX_CM0Plus_Core0) || (cpu_id == kMAILBOX_CM0Plus_Core1));
#else
    assert((cpu_id == kMAILBOX_CM0Plus) || (cpu_id == kMAILBOX_CM4));
#endif
    base->MBOXIRQ[cpu_id].IRQ = mboxData;
}

/*!
 * @brief Get data in the mailbox based on the CPU ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param cpu_id CPU id, kMAILBOX_CM0Plus or kMAILBOX_CM4 for LPC5410x and LPC5411x devices,
 *               kMAILBOX_CM33_Core0 or kMAILBOX_CM33_Core1 for LPC55S69 devices.
 *
 * @return Current mailbox data.
 */
static inline uint32_t MAILBOX_GetValue(MAILBOX_Type *base, mailbox_cpu_id_t cpu_id)
{
#if (defined(LPC55S69_cm33_core0_SERIES) || defined(LPC55S69_cm33_core1_SERIES))
    assert((cpu_id == kMAILBOX_CM33_Core0) || (cpu_id == kMAILBOX_CM33_Core1));
#elif (defined(CPU_NXH2004J640UK48))
    assert((cpu_id == kMAILBOX_CM0Plus_Core0) || (cpu_id == kMAILBOX_CM0Plus_Core1));
#else
    assert((cpu_id == kMAILBOX_CM0Plus) || (cpu_id == kMAILBOX_CM4));
#endif
    return base->MBOXIRQ[cpu_id].IRQ;
}

/*!
 * @brief Set data bits in the mailbox based on the CPU ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param cpu_id CPU id, kMAILBOX_CM0Plus or kMAILBOX_CM4 for LPC5410x and LPC5411x devices,
 *               kMAILBOX_CM33_Core0 or kMAILBOX_CM33_Core1 for LPC55S69 devices.
 * @param mboxSetBits Data bits to set in the mailbox.
 *
 * @note Sets data bits to send via the MAILBOX to the other core. A value of 0 will
 * do nothing. Only sets bits selected with a 1 in it's bit position.
 */
static inline void MAILBOX_SetValueBits(MAILBOX_Type *base, mailbox_cpu_id_t cpu_id, uint32_t mboxSetBits)
{
#if (defined(LPC55S69_cm33_core0_SERIES) || defined(LPC55S69_cm33_core1_SERIES))
    assert((cpu_id == kMAILBOX_CM33_Core0) || (cpu_id == kMAILBOX_CM33_Core1));
#elif (defined(CPU_NXH2004J640UK48))
    assert((cpu_id == kMAILBOX_CM0Plus_Core0) || (cpu_id == kMAILBOX_CM0Plus_Core1));
#else
    assert((cpu_id == kMAILBOX_CM0Plus) || (cpu_id == kMAILBOX_CM4));
#endif
    base->MBOXIRQ[cpu_id].IRQSET = mboxSetBits;
}

/*!
 * @brief Clear data bits in the mailbox based on the CPU ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param cpu_id CPU id, kMAILBOX_CM0Plus or kMAILBOX_CM4 for LPC5410x and LPC5411x devices,
 *               kMAILBOX_CM33_Core0 or kMAILBOX_CM33_Core1 for LPC55S69 devices.
 * @param mboxClrBits Data bits to clear in the mailbox.
 *
 * @note Clear data bits to send via the MAILBOX to the other core. A value of 0 will
 * do nothing. Only clears bits selected with a 1 in it's bit position.
 */
static inline void MAILBOX_ClearValueBits(MAILBOX_Type *base, mailbox_cpu_id_t cpu_id, uint32_t mboxClrBits)
{
#if (defined(LPC55S69_cm33_core0_SERIES) || defined(LPC55S69_cm33_core1_SERIES))
    assert((cpu_id == kMAILBOX_CM33_Core0) || (cpu_id == kMAILBOX_CM33_Core1));
#elif (defined(CPU_NXH2004J640UK48))
    assert((cpu_id == kMAILBOX_CM0Plus_Core0) || (cpu_id == kMAILBOX_CM0Plus_Core1));
#else
    assert((cpu_id == kMAILBOX_CM0Plus) || (cpu_id == kMAILBOX_CM4));
#endif
    base->MBOXIRQ[cpu_id].IRQCLR = mboxClrBits;
}

/*!
 * @brief Get MUTEX state and lock mutex
 *
 * @param base MAILBOX peripheral base address.
 *
 * @return See note
 *
 * @note Returns '1' if the mutex was taken or '0' if another resources has the
 * mutex locked. Once a mutex is taken, it can be returned with the MAILBOX_SetMutex()
 * function.
 */
static inline uint32_t MAILBOX_GetMutex(MAILBOX_Type *base)
{
    return (base->MUTEX & MAILBOX_MUTEX_EX_MASK);
}

/*!
 * @brief Set MUTEX state
 *
 * @param base MAILBOX peripheral base address.
 *
 * @note Sets mutex state to '1' and allows other resources to get the mutex.
 */
static inline void MAILBOX_SetMutex(MAILBOX_Type *base)
{
    base->MUTEX = MAILBOX_MUTEX_EX_MASK;
}

#if (defined(CPU_NXH2004J640UK48))

/*!
 * @brief Set data value in the SW mailbox based on the SW Mailbox ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param sw_irq_id SW Mailbox Index for NXH2004 devices
 * @param mboxData Data to send in the mailbox.
 *
 */
static inline void MAILBOX_SW_SetValue(MAILBOX_Type *base, mailbox_sw_irq_id_t sw_irq_id, uint32_t mboxData)
{
    assert((sw_irq_id >= kMAILBOX_CM0Plus_Sw_Irq0) && (sw_irq_id <= kMAILBOX_CM0Plus_Sw_Irq3));
    base->MBOXIRQ[sw_irq_id].IRQ = mboxData;
}

/*!
 * @brief Get data in the SW mailbox based on the SW Mailbox ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param sw_irq_id, SW Mailbox index for NXH2004 devies.
 *
 * @return Current mailbox data.
 */
static inline uint32_t MAILBOX_SW_GetValue(MAILBOX_Type *base, mailbox_sw_irq_id_t sw_irq_id)
{
    assert((sw_irq_id >= kMAILBOX_CM0Plus_Sw_Irq0) && (sw_irq_id <= kMAILBOX_CM0Plus_Sw_Irq3));
    return base->MBOXIRQ[sw_irq_id].IRQ;
}

/*!
 * @brief Set data bits in the SW mailbox based on the SW Mailbox Index.
 *
 * @param base MAILBOX peripheral base address.
 * @param sw_irq_id SW Mailbox Index for NXH2004 devices
 * @param mboxSetBits Data bits to set in the mailbox.
 *
 * @note Sets data bits to send via the MAILBOX. A value of 0 will
 * do nothing. Only sets bits selected with a 1 in it's bit position.
 */
static inline void MAILBOX_SW_SetValueBits(MAILBOX_Type *base, mailbox_sw_irq_id_t sw_irq_id, uint32_t mboxSetBits)
{
    assert((sw_irq_id >= kMAILBOX_CM0Plus_Sw_Irq0) && (sw_irq_id <= kMAILBOX_CM0Plus_Sw_Irq3));
    base->MBOXIRQ[sw_irq_id].IRQSET = mboxSetBits;
}

/*!
 * @brief Clear data bits in the SW mailbox based on the SW Mailbox ID.
 *
 * @param base MAILBOX peripheral base address.
 * @param sw_irq_id, Index to SW Mailbox for NXH2004 devices.
 * @param mboxClrBits Data bits to clear in the SW mailbox.
 *
 * @note Clear data bits to send via the MAILBOX. A value of 0 will do
 * nothing. Only clears bits selected with a 1 in it's bit position.
 */
static inline void MAILBOX_SW_ClearValueBits(MAILBOX_Type *base, mailbox_sw_irq_id_t sw_irq_id, uint32_t mboxClrBits)
{
    assert((sw_irq_id >= kMAILBOX_CM0Plus_Sw_Irq0) && (sw_irq_id <= kMAILBOX_CM0Plus_Sw_Irq3));
    base->MBOXIRQ[sw_irq_id].IRQCLR = mboxClrBits;
}

#endif /*CPU_NXH2004J640UK48*/

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/*@}*/

#endif /* _FSL_MAILBOX_H_ */
