/*! *********************************************************************************
* Copyright 2022-2024 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef __PHY_TIME_H__
#define __PHY_TIME_H__

#define BM_ZLL_IRQSTS_TMRxMSK (ZLL_IRQSTS_TMR1MSK_MASK | \
                               ZLL_IRQSTS_TMR2MSK_MASK | \
                               ZLL_IRQSTS_TMR3MSK_MASK | \
                               ZLL_IRQSTS_TMR4MSK_MASK )

#define TMR_REG_EN_1            (ZLL_PHY_CTRL_TMR1CMP_EN_MASK)
#define TMR_REG_EN_2            (ZLL_PHY_CTRL_TMR2CMP_EN_MASK | ZLL_PHY_CTRL_TMRTRIGEN_MASK)
#define TMR_REG_EN_3            (ZLL_PHY_CTRL_TMR3CMP_EN_MASK | ZLL_PHY_CTRL_TC3TMOUT_MASK)
#define TMR_REG_EN_4            (ZLL_PHY_CTRL_TMR4CMP_EN_MASK)

#define TMR_REG_SET_1           (ZLL->T1CMP)
#define TMR_REG_SET_2           (ZLL->T2CMP)
#define TMR_REG_SET_3           (ZLL->T3CMP)
#define TMR_REG_SET_4           (ZLL->T4CMP)

#define TMR_REG_EN(__tmr__)     TMR_REG_EN_ ## __tmr__
#define TMR_REG_SET(__tmr__)    TMR_REG_SET_ ## __tmr__
#define TMR_REG_MSK(__tmr__)    ZLL_IRQSTS_TMR ## __tmr__ ## MSK_MASK
#define TMR_REG_IRQ(__tmr__)    ZLL_IRQSTS_TMR ## __tmr__ ## IRQ_MASK

#define ENABLE_TMR(__tmr__)             ZLL->PHY_CTRL |= (TMR_REG_EN(__tmr__))
#define DISABLE_TMR(__tmr__)            ZLL->PHY_CTRL &= ~(TMR_REG_EN(__tmr__))
#define SET_TMR(__tmr__, __time__)      TMR_REG_SET(__tmr__) = __time__

#define CLEAR_TMR_IRQ(__tmr__)  do {                \
    uint32_t irq_sts;                               \
                                                    \
    irq_sts  = ZLL->IRQSTS & BM_ZLL_IRQSTS_TMRxMSK; \
    irq_sts |= (TMR_REG_IRQ(__tmr__));              \
    ZLL->IRQSTS = irq_sts;                          \
} while(0)

#define UNMASK_AND_CLEAR_TMR_IRQ(__tmr__)  do {     \
    uint32_t irq_sts;                               \
                                                    \
    irq_sts  = ZLL->IRQSTS & BM_ZLL_IRQSTS_TMRxMSK; \
    irq_sts &= ~(TMR_REG_MSK(__tmr__));             \
    irq_sts |= (TMR_REG_IRQ(__tmr__));              \
    ZLL->IRQSTS = irq_sts;                          \
} while(0)

#define MASK_TMR_IRQ(__tmr__)  do {                             \
    uint32_t irq_sts;                                           \
                                                                \
    irq_sts  = ZLL->IRQSTS & BM_ZLL_IRQSTS_TMRxMSK;             \
    irq_sts |= (TMR_REG_MSK(__tmr__) | TMR_REG_IRQ(__tmr__));   \
    ZLL->IRQSTS = irq_sts;                                      \
} while(0)

#define TMR_SET(__tmr__, __time__) do {                \
    OSA_InterruptDisable();                            \
                                                       \
    DISABLE_TMR(__tmr__);                              \
    SET_TMR(__tmr__, __time__);                        \
    CLEAR_TMR_IRQ(__tmr__);                            \
    ENABLE_TMR(__tmr__);                               \
                                                       \
    OSA_InterruptEnable();                             \
} while(0)

#define TMR_UNMASK_AND_SET(__tmr__, __time__) do {     \
    OSA_InterruptDisable();                            \
                                                       \
    DISABLE_TMR(__tmr__);                              \
    SET_TMR(__tmr__, __time__);                        \
    UNMASK_AND_CLEAR_TMR_IRQ(__tmr__);                 \
    ENABLE_TMR(__tmr__);                               \
                                                       \
    OSA_InterruptEnable();                             \
} while(0)

#define TMR_CLEAR(__tmr__) do {    \
    OSA_InterruptDisable();        \
                                   \
    DISABLE_TMR(__tmr__);          \
    MASK_TMR_IRQ(__tmr__);         \
                                   \
    OSA_InterruptEnable();         \
} while(0)

#define PhyTimeDisableEventTrigger() 		TMR_CLEAR(2)
#define PhyTimeSetEventTrigger(__time__)    TMR_UNMASK_AND_SET(2, __time__)

#define PhyTimeDisableEventTimeout()        TMR_CLEAR(3)
#define PhyTimeSetEventTimeout(__time__)    TMR_SET(3, __time__)

#define PhyTimeDisableWaitTimeout()         TMR_CLEAR(1)
#define PhyTimeSetWaitTimeout(__time__)     TMR_UNMASK_AND_SET(1, __time__)

#endif /* __PHY_TIME_H__ */
