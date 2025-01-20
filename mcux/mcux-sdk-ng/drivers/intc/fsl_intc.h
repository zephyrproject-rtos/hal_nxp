/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_INTC_H_
#define FSL_INTC_H_

#include "fsl_common.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.intc"
#endif

/*!
 * @defgroup intc INTC: Interrupt Controller Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief INTC driver version. */
#define FSL_INTC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup intc_driver_log The Driver Change Log
 * @ingroup intc
 * @{
 * The current INTC driver version is 2.0.1
 *
 * - 2.0.1
 *   - Improvements
 *     - Added doxygen comments.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction
 ******************************************************************************/
/*!
 * @defgroup intc_intro INTC Peripheral and Driver Overview
 * @ingroup intc
 * @brief Content including 1) peripheral features; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features
 * ====================
 * The Interrupt Controller (INTC) module arbitrates among the various interrupt requests(IRQs).
 *
 *  + The module supports unique interrupt vectors and programmable interrupt priority.
 *    - It signals to the DSC core when an interrupt of sufficient priority exists and to what address to jump to
 *      service this interrupt.
 *
 *  + Programmable priority levels for each IRQ.
 *
 *  + Two programmable fast interrupts.
 *    - Fast Interrupts vector directly to a service routine based on values in the Fast Interrupt Vector Address
 *      registers without having to go to a jump table first.
 *
 * How this driver is designed to make this peripheral work
 * ==========================================================
 * This driver provide multiple functions to configure the INTC module. The APIs can be classified in 3 API groups:
 *
 *  + Normal Interrupt Interfaces
 *    - The APIs in this function group can be used to enable/disable IRQ with priority and configure interrupt
 *      vector base address. Normal interrupt handling concatenates the vector base address (VBA) and the vector number
 *      to determine the vector address.
 *
 *  + Fast Interrupt Interfaces
 *    - The APIs in this function group can be used to configure two programmable fast interrupts.
 *
 *  + Interrupt Status Interfaces
 *    - The APIs in this function group can be used to check whether an IRQ is pending, get the latest responded
 *      IRQ's vector number and get which interrupt priority level allow the servicing of an IRQ with higher
 *      priority than the current exception.
 *
 *  How to use this driver
 *  =======================
 * Before go to the details of using INTC driver, some background knowledge of SDK vector table should be established.
 * SDK defines vector table in xxxx_Vectors.c, taking MC56F83xxx_Vectors.c as an example to describe the vector table
 * and weak ISR entry implementation:
 * Vector table _vect is defined as a function, all ISR entries in the table are defined as two words instruction,
 * "JMP/JSR" followed by weak ISR entries, there are two kinds of weak ISR entries:
 * - Single weak function, most of ISR entries are single weak ISR. These weak ISR entries are defined to call the
 * default_interrupt() function, when user enable the related vector, just simply define a strong ISR entry to overwrite
 * the weak definition. Take COP interrupt as an example. COP interrupt will jump to ivINT_COP_INT as defined in vector
 * table. The implementation of single weak ivINT_COP_INT show as below:
 *    @code
      #pragma interrupt alignsp saveall
      __attribute__((weak)) void ivINT_COP_INT(void);
      __attribute__((weak)) void ivINT_COP_INT(void)
      {
          default_interrupt();
      }
      #pragma interrupt off
      @endcode
 * User should implement the ISR entry in their application to specify their own interrupt routine, such as below:
 *    @code
      #pragma interrupt alignsp saveall
      void ivINT_COP_INT(void)
      {
          COP_Refresh(DEMO_COP_BASE);
          copIsrFlag = true;
          copRefreshCount++;
      }
      #pragma interrupt off
      @endcode
 * Then COP interrupt will jump to the strong implementation in application.
 *
 * - Double weak function. This is special design architecture to ease user to directly use interrupt/DMA driven
 * transactional layer SDK driver, such layer of API integrated in bus drivers such as QSCI/QSPI/I2C/DMA. When
 * interrupt happens, will firstly call the first level ISR entry defined in vector table, which is defined as an
 * weak ISR entry and call to another weak function, alias second level weak ISR, the naming of such ISR ends
 * with "_DriverIRQHandler" and already have a strong implementation in specified SDK driver. Take DMA0 interrupt
 * as an example, when interrupt happens, weak ISR entry ivINT_DMA0 is jumped, and the definition of the weak ISR
 * is show below:
 *    @code
      __attribute__((weak)) static void DMA0_DriverIRQHandler(void)
      {
          default_interrupt();
      }

      #pragma interrupt alignsp saveall
      __attribute__((weak)) void ivINT_DMA0(void);
      __attribute__((weak)) void ivINT_DMA0(void)
      {
          DMA0_DriverIRQHandler();
      }
      #pragma interrupt off
      @endcode
 * The weak ISR entry ivINT_DMA0 call function DMA0_DriverIRQHandler, which also defined as a weak function, and the
 * function default also call to default_interrupt(). In SDK DMA driver, there's definition of DMA0_DriverIRQHandler
 * and it's strong definition, then when application integrate DMA driver and DMA0 interrupt happens, the
 * DMA0_DriverIRQHandler() defined in SDK DMA driver will be executed in interrupt routine. This way allows user to
 * use driver pre-defined IRQ routine to do complete transfer, also leave the possibility for user to define their own
 * ISR entry for DMA0. He could use the previous way as re-write single-weak ISR entry, implement first level weak
 * ISR entry ivINT_DMA0.
 *
 * INTC driver provides settings of vector table address, IRQ priority, fast interrupt handle and interrupt status.
 *
 *  + For vector table base address setting, call @ref INTC_SetVectorBaseAddress function, you could refer to vector
 *    table definition in xxxx_Vectors.c.
 *
 *  + To enable IRQ with priority or disable IRQ, invoke @ref INTC_SetIRQPriorityNum() function. Refer to SOC header
 *    file to use the IRQn_Type structure. Please note a none-zero priority number for different IP may means
 *    different priority level, check the RM INTC chapter for more details.
 *
 *  + For fast interrupts, @ref INTC_SetIRQPriorityNum() function can used to set the priority of the interrupt as
 *    level 2, then invoke the corresponding API in Fast Interrupt Interfaces, such as
 *    @ref INTC_SetFastIRQVectorHandler0 to set the fast IRQ handler.
 *
 *  + If needed, the APIs in Interrupt Status Interfaces can be used. Invoke INTC_GetPendingIRQ() to check whether an
 *    IRQ is pending. Get the latest responded IRQ's vector number can use INTC_GetLatestRespondedVectorNumber()
 *    function. To get which interrupt priority level is permitted, INTC_GetIRQPermittedPriorityLevel() can be invoked.
 *
 *  + Note: IRQ number and vector number are different. IRQ number is an IP enumerator in INTC IPRx register.
 *          Vector number is an IP enumerator in vector table.
 *
 *  Typical Use Case
 *  ================
 *  + Normal interrupt Handling: Use normal interrupts when a significant amount of code is needed to serve the
 *    interrupt.
 *    Follow below steps to realize normal interrupt:
 *    1. Setup interrupt priority in INTC module. call @ref INTC_SetIRQPriorityNum to do the setting.
 *    2. Enable interrupt in the peripheral module.
 *    3. Define strong implementation of ISR entry for the definition in vector table.
 *     Use \#pragma interrupt xxxxx for the ISR. This is to tell the compiler to store necessary registers before the
 *     execution of ISR, and return with RTI instruction.
 *  + \#pragma interrupt saveall is the safest way to define an ISR. It saves all the registers no matter what. Use it
 *    when:
 *       - There is library function invoking in the ISR.
 *       - There are too many function nesting invoking in the ISR, you don't want to identify them all.
 *    @code
        #pragma interrupt saveall
        void isrFunc(void)
        {
            // There is library or many function nesting called in the ISR, use saveall to save all the registers.
        }
        #pragma interrupt off
      @endcode
 *  + Use \#pragma interrupt on when there isn't any other function invoking in the ISR.
 *    @code
        #pragma interrupt on
        void isrFunc(void)
        {
            // No function invoking in the ISR. Compiler saves the registers used in this ISR only.
        }
        #pragma interrupt off
      @endcode
 *  + Use \#pragma interrupt on when there is function invoking in the ISR, and use \#pragma interrupt called
 *    for the invoked functions in the ISR.
 *    @code
        #pragma interrupt on
        void isrFunc(void)
        {
            func1();

        }
        #pragma interrupt off

        #pragma interrupt called
        void func1(void)
        {
            // No function invoking in this function
        }
        #pragma interrupt off
      @endcode
 *
 *    Simple sample code for normal interrupt setup
 *    @code
        // ISR entry
        #pragma interrupt on
        void CMPA_IRQHandler()
        {
            isInterrupted = true;
        }
        #pragma interrupt off
        INTC_SetIRQPriorityNum(CMPA_IRQn, 3); // Set CMPA_IRQn to priority level 2
      @endcode
 *
 *  + Fast Interrupt Handling: Fast interrupts are intended for use with interrupts that do not require a large
 *    amount of code to service, suggested uses for fast interrupts are:
 *      - Data move operations
 *      - Repetitive interrupt source with minimal ISR code

 *    Steps:
 *          1. Set the priority of the interrupt as level 2, call @ref INTC_SetIRQPriorityNum to do the setting.
 *          2. Use \#pragma interrupt fast for fast interrupt ISR.
               + It is preferred that there should be no function invoking in this ISR.
               + There shouldn't be library function invoking in this ISR.
               + If there is function invoking (not lib function) in this ISR, use \#pragma interrupt called for
               the invoked function.
 *          3. Call @ref INTC_SetFastIRQVectorHandler0 or @ref INTC_SetFastIRQVectorHandler1 to configure the
 *             vector number and ISR entry for the specified fast interrupt.
 *
 *    Simple sample code for fast interrupt setup
 *    @code
           #pragma interrupt fast
           void IRQ_HANDLER()
           {
               isInterrupted = true;
           }
           #pragma interrupt off

           INTC_SetIRQPriorityNum(CMPA_IRQn, 3); //Set CMPA_IRQn interrupt priority to priority level 2.
      @endcode
 * @}
 */

/*! @brief Macro to disable the IRQ. */
#define INTC_DisableIRQ(x) INTC_SetIRQPriorityLevel(x, 0U)
/*! @brief Helper Macro function to extract IRQ pending register index comparing to INTC_IRQP0. */
#define INTC_PEND_REG_INDEX(x) ((((uint16_t)(x)) - 1U) >> 4U)
/*! @brief Helper Macro function to extract pending IRQs bit index. */
#define INTC_PEND_BIT_INDEX(x) ((((uint16_t)(x)) - 1U) & 0x0FU)
/*! @brief Helper Macro function to extract IRQ priority register index comparing to INTC_IRP0. */
#define INTC_TYPE_REG_INDEX(x) (((uint8_t)(x)) >> 3U)
/*! @brief Helper Macro function to extract IRQs priority bit index. */
#define INTC_TYPE_BIT_INDEX(x) ((((uint8_t)(x)) & 0x7U) << 1U)

/*! @brief The handle of the fast irq handler function
 *
 *  Normally this function should be guarded by:
 *  \#pragma interrupt fast and \#pragma interrupt off.
 */
typedef void (*fast_irq_handler)(void);

/*!
 * @name Normal Interrupt Interfaces
 * @{
 */

/*!
 * @brief Disable IRQ or Enable IRQ with priority.
 *
 * There are similar function in fsl_common:
 * - EnableIRQWithPriority,
 * - DisableIRQ,
 * - EnableIRQ,
 * - IRQ_SetPriority.
 *
 * This function is faster and simpler than those in fsl_common.
 * Generally, this function and IRQ functions in fsl_common are either-or, don't use them together for same IRQn type,
 * but feasible that different IRQn type use them simultaneously, for example:
 * It is OK OCCS_IRQn use INTC_SetIRQPriorityLevel, and ADC12_CC1_IRQn use EnableIRQWithPriority.
 * It is NOT OK that OCCS_IRQn use INTC_SetIRQPriorityLevel and EnableIRQWithPriority simultaneously.
 *
 * @param eIrq            The IRQ number.
 * @param u8PriorityNum   IRQ interrupt priority number.
 * - 0:  disable IRQ.
 * - 1-3: enable IRQ and set its priority, 3 is the highest priority for this IRQ and 1 is the lowest priority.
 * @note Please note a none-zero priority number does directly map to priority level, simple summary is as below,
 * you could check RM INTC chapter for more details.
 * - Some IPs have priority level 1~3, maps priority number 1 to priority 1, 2 to priority 2, 3 to priority 3.
 * - Some IPs have priority level 0~2, maps priority number 1 to priority 0, 2 to priority 1, 3 to priority 2.
 */
static inline void INTC_SetIRQPriorityNum(IRQn_Type eIrq, uint8_t u8PriorityNum)
{
    uint16_t u16IntcCtrl;

    assert(((uint8_t)eIrq) < NUMBER_OF_INT_IRQ);
    assert(u8PriorityNum < 4U);

    /* Disable global interrupt for atomic change. */
    u16IntcCtrl = INTC->CTRL;
    INTC->CTRL  = u16IntcCtrl | INTC_CTRL_INT_DIS_MASK;

    ((volatile uint16_t *)&(INTC->IPR0))[INTC_TYPE_REG_INDEX((uint8_t)eIrq)] =
        (((volatile uint16_t *)&(INTC->IPR0))[INTC_TYPE_REG_INDEX((uint8_t)eIrq)] &
         (~(3U << INTC_TYPE_BIT_INDEX((uint8_t)eIrq)))) |
        (((uint16_t)u8PriorityNum) << INTC_TYPE_BIT_INDEX((uint8_t)eIrq));

    INTC->CTRL = u16IntcCtrl;
}

/*!
 * @brief Set the base address vector table. The value in INTC_VBA is used as the upper
 *        13 bits of the interrupt vector VAB[20:0].
 *
 * @param u32VectorBaseAddr Vector table base address. The address requires 256 words (512 bytes) aligned.
 * Take the vector table in MC56F83xxx_Vectors.c as example for how to implement this table.
 *
 */
static inline void INTC_SetVectorBaseAddress(uint32_t u32VectorBaseAddr)
{
    INTC->VBA = ((uint32_t)u32VectorBaseAddr) >> 8U;
}
/*! @} */

/*!
 * @name Fast Interrupt Interfaces
 * @{
 */

/*!
 * @brief Set the IRQ handler for fast IRQ0. The INTC takes the vector address from the appropriate
 *        FIVAL0 and FIVAH0 registers, instead of generating an address that is an offset from the
 *        vector base address (VBA).
 *
 * @param eVector   The vector number.
 * @param pfHandler Pointer to the fast IRQ handler function, see @ref fast_irq_handler definition for more info.
 */
static inline void INTC_SetFastIRQVectorHandler0(vector_type_t eVector, fast_irq_handler pfHandler)
{
    INTC->FIM0   = (uint16_t)eVector;
    INTC->FIVAL0 = ((uint32_t)pfHandler) & 0xFFFFU; /* FIVALxx requires WORD address, and pfHandler is WORD address */
    INTC->FIVAH0 = (((uint32_t)pfHandler) >> 16U);
}

/*!
 * @brief Set the IRQ handler for fast IRQ1. The INTC takes the vector address from the appropriate
 *        FIVAL1 and FIVAH1 registers, instead of generating an address that is an offset from the
 *        vector base address (VBA).
 *
 * @param eVector The eVector number.
 * @param pfHandler Pointer to the fast IRQ handler function, see @ ref fast_irq_handler definition for more info.
 */
static inline void INTC_SetFastIRQVectorHandler1(vector_type_t eVector, fast_irq_handler pfHandler)
{
    INTC->FIM1   = (uint16_t)eVector;
    INTC->FIVAL1 = ((uint32_t)pfHandler) & 0xFFFFU; /* FIVALxx requires WORD address, and pfHandler is WORD address */
    INTC->FIVAH1 = (((uint32_t)pfHandler) >> 16U);
}
/*! @} */

/*!
 * @name Interrupt Status Interfaces
 * @{
 */

/*!
 * @brief Get IRQ permitted priority levels. Interrupt exceptions may be nested to allow the
 *        servicing of an IRQ with higher priority than the current exception.
 *
 * The return value indicate the priority level needed for a new IRQ to interrupt the current interrupt being sent to
 * the Core.
 * @retval 0 Required nested exception priority levels are 0, 1, 2, or 3.
 * @retval 1 Required nested exception priority levels are 1, 2, or 3.
 * @retval 2 Required nested exception priority levels are 2 or 3.
 * @retval 3 Required nested exception priority level is 3.
 */
static inline uint8_t INTC_GetIRQPermittedPriorityLevel(void)
{
    return (INTC->CTRL & INTC_CTRL_IPIC_MASK) >> INTC_CTRL_IPIC_SHIFT;
}

/*!
 * @brief Check if IRQ is pending for execution. Before the ISR is entered, IRQ is pending. After
 *        the ISR is entered, the IRQ is not pending.
 *
 * @param eVector The IRQ vector number.
 *
 * @retval True if interrupt is pending, otherwise return false.
 */
static inline bool INTC_GetPendingIRQ(vector_type_t eVector)
{
    assert(eVector <= kCOP_RESET_VECTORn);

    if (0U ==
        (((volatile uint16_t *)&(INTC->IRQP0))[INTC_PEND_REG_INDEX(eVector)] & (1U << INTC_PEND_BIT_INDEX(eVector))))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @brief Get the latest responded IRQ's vector number. It shows the Vector Address Bus
 *        used at the time the last IRQ was taken.
 * @note Return value of the function call could be different according to where the function call is invoked.
 * - when called in normal ISR handler, it returns current ISR's vector number defined in vector_type_t.
 * - when called in fast IRQ handler, it returns the lower address bits of the jump address.
 * - when called in none ISR handler code, it returns previous responded IRQ vector
 * number defined in vector_type_t or fast IRQ low address bits.
 *
 * @return The latest vector number.
 */
static inline uint16_t INTC_GetLatestRespondedVectorNumber(void)
{
    return (INTC->CTRL & INTC_CTRL_VAB_MASK) >> INTC_CTRL_VAB_SHIFT;
}
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_INTC_H_*/
