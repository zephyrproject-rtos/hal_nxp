/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_HWACCESS_H
#define EMIOS_PWM_IP_HWACCESS_H

/**
*   @file       Emios_Pwm_Ip_HwAccess.h
*   @implements Emios_Pwm_Ip_HwAccess.h_Artifact
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Emios_Pwm_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_HWACCESS_VENDOR_ID                    43
#define EMIOS_PWM_IP_HWACCESS_MODULE_ID                    121
#define EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_HWACCESS_SW_MAJOR_VERSION             3
#define EMIOS_PWM_IP_HWACCESS_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_HWACCESS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_HwAccess.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same vendor */
#if (EMIOS_PWM_IP_HWACCESS_VENDOR_ID != EMIOS_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_HwAccess.h and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_HwAccess.h and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same software version */
#if ((EMIOS_PWM_IP_HWACCESS_SW_MAJOR_VERSION != EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_HWACCESS_SW_MINOR_VERSION != EMIOS_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_HWACCESS_SW_PATCH_VERSION != EMIOS_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_HwAccess.h and Emios_Pwm_Ip_Cfg.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*!
* @brief Emios PWM Channel modes
*/
typedef enum
{
    /** @brief Output Pulse Width and Frequency Modulation Buffered.*/
    EMIOS_PWM_IP_HW_MODE_OPWFMB   = 0x00U,
    /** @brief Center Aligned Output Pulse Width Modulation Buffered */
    EMIOS_PWM_IP_HW_MODE_OPWMCB   = 0x01U,
    /** @brief Output Pulse Width Modulation Buffered. */
    EMIOS_PWM_IP_HW_MODE_OPWMB    = 0x02U,
    /** @brief Output Pulse-Width Modulation with Trigger */
    EMIOS_PWM_IP_HW_MODE_OPWMT    = 0x03U,
    /** @brief Double Action Output Compare */
    EMIOS_PWM_IP_HW_MODE_DAOC     = 0x04U,
    /** @brief Center Aligned Output Pulse Width Modulation  */
    EMIOS_PWM_IP_HW_MODE_OPWMC    = 0x05U,
    /** @brief Output Pulse Width Modulation. */
    EMIOS_PWM_IP_HW_MODE_OPWM     = 0x06U,
    /** @brief Output Pulse Width and Frequency Modulation.*/
    EMIOS_PWM_IP_HW_MODE_OPWFM    = 0x07U
} Emios_Pwm_Ip_PwmType;

/*!
* @brief Emios PWM master bus modes
*/
typedef enum
{
    EMIOS_PWM_IP_MC_UP_COUNTER_START = 16u,
    EMIOS_PWM_IP_MC_UP_COUNTER_END   = 18u,
    EMIOS_PWM_IP_MC_UP_DOWN_COUNTER  = 20u,
    EMIOS_PWM_IP_MCB_UP_COUNTER      = 80u,
    EMIOS_PWM_IP_MCB_UP_DOWN_COUNTER = 84u,
    EMIOS_PWM_IP_NODEFINE_COUNTER    = 0u
} Emios_Pwm_Ip_MasterBusModeType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
/*-----------------------MCR Register----------------------------*/
/*!
 * brief Get MCR Freeze enable bit
 * param[in] Base     The Emios base address pointer
 */
static inline boolean Emios_Pwm_Ip_GetDebugMode(const Emios_Pwm_Ip_HwAddrType *const Base)
{
    return (((Base->MCR & eMIOS_MCR_FRZ_MASK) >> eMIOS_MCR_FRZ_SHIFT) == 0U)? FALSE : TRUE;
}

/*-----------------------OUDIS Register----------------------------*/
/*!
 * brief Set OUDIS Channel n enable bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 */
static inline void Emios_Pwm_Ip_SetOutputUpdate(Emios_Pwm_Ip_HwAddrType *const Base,
                                                 uint8 Channel,
                                                 boolean Value)
{
    Base->OUDIS = Base->OUDIS | (eMIOS_OUDIS_OU0((Value == TRUE) ? 0x00U : 0x01U) << Channel);
}

/*!
 * brief Get OUDIS Channel n enable bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 */
static inline boolean Emios_Pwm_Ip_GetOutputUpdate(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                   uint8 Channel)
{
    return (((Base->OUDIS & (uint32)((uint32)eMIOS_OUDIS_OU0_MASK << (uint32)Channel)) >> Channel) == 0U) ? TRUE : FALSE;
}

/*!
 * brief Get OUDIS register
 * param[in] Base  The Emios Base address pointer
 */
static inline uint32 Emios_Pwm_Ip_GetOutputUpdateInstance(const Emios_Pwm_Ip_HwAddrType *const Base)
{
    return (Base->OUDIS);
}

/*-----------------------UCDIS Register----------------------------*/
/*!
 * brief Set UCDIS Channel n enable bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 */
static inline void Emios_Pwm_Ip_SetChannelEnable(Emios_Pwm_Ip_HwAddrType *const Base,
                                                 uint8 Channel,
                                                 boolean Value)
{
    Base->UCDIS = Base->UCDIS | (eMIOS_UCDIS_UCDIS0((Value == TRUE) ? 0x00U : 0x01U) << Channel);
}

/*!
 * brief Get UCDIS Channel n enable bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 */
static inline boolean Emios_Pwm_Ip_GetChannelEnable(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                    uint8 Channel)
{
    return (((Base->UCDIS & (uint32)((uint32)eMIOS_UCDIS_UCDIS0_MASK << (uint32)Channel)) >> Channel) == 0U) ? TRUE : FALSE;
}

/*-----------------------UC register A-----------------------------*/
/*!
 * brief Set A register's Value, maximum Value is 0xFFFFFF
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 */
static inline void Emios_Pwm_Ip_SetUCRegA(Emios_Pwm_Ip_HwAddrType *const Base,
                                          uint8 Channel,
                                          Emios_Pwm_Ip_PeriodType Value)
{
    Base->CH.UC[Channel].A = eMIOS_A_A(Value);
}

/*!
 * brief Get A register's Value
 * param[in] Base       The Emios Base address pointer
 * param[in] Channel    The Channel id for the given instance
 * return Value of Unified Channels A register
 */
static inline Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetUCRegA(const Emios_Pwm_Ip_HwAddrType *const Base,
                                            uint8 Channel)
{
    return (Emios_Pwm_Ip_PeriodType)((Base->CH.UC[Channel].A & eMIOS_A_A_MASK) >> eMIOS_A_A_SHIFT);
}

/*-----------------------UC register B-----------------------------*/
/*!
 * brief Set B register's Value, maximum Value is 0xFFFFFF
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 */
static inline void Emios_Pwm_Ip_SetUCRegB(Emios_Pwm_Ip_HwAddrType *const Base,
                                          uint8 Channel,
                                          Emios_Pwm_Ip_PeriodType Value)
{
    Base->CH.UC[Channel].B = eMIOS_B_B(Value);
}

/*!
 * brief Get B register's Value
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Unified Channels B register
 */
static inline Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetUCRegB(const Emios_Pwm_Ip_HwAddrType *const Base,
                                            uint8 Channel)
{
    return (Emios_Pwm_Ip_PeriodType)((Base->CH.UC[Channel].B & eMIOS_B_B_MASK) >> eMIOS_B_B_SHIFT);
}

/*-----------------------UC register CNT-----------------------------*/
/*!
 * brief Get CNT register's Value
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * return Value of Unified Channels CNT register
 */
static inline Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetInternalCounterValue(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                          uint8 Channel)
{
    return (Emios_Pwm_Ip_PeriodType)((Base->CH.UC[Channel].CNT & eMIOS_CNT_C_MASK) >> eMIOS_CNT_C_SHIFT);
}

/*----------------------------UC register C bit fields--------------------------*/
/*!
 * brief Set Freeze Enable bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 *            - 0      Normal operation
 *            - 1      Freeze UC registers values
 */
static inline void Emios_Pwm_Ip_SetFreezeEnable(Emios_Pwm_Ip_HwAddrType *const Base,
                                                uint8 Channel,
                                                boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_FREN_MASK)) | eMIOS_C_FREN(ValueConvert);
}

/*!
 * brief Set Output Disable bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 */
static inline void Emios_Pwm_Ip_SetOutDisable(Emios_Pwm_Ip_HwAddrType *const Base,
                                              uint8 Channel,
                                              boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_ODIS_MASK)) | eMIOS_C_ODIS(ValueConvert);
}

/*!
 * brief Set Output Disable select Value
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 */
static inline void Emios_Pwm_Ip_SetOutDisableSource(Emios_Pwm_Ip_HwAddrType *const Base,
                                                    uint8 Channel,
                                                    Emios_Pwm_Ip_OutDisableSourceType Value)
{
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_ODISSL_MASK)) | eMIOS_C_ODISSL(Value);
}

/*!
 * brief Set Prescaler Enable bit.
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 *            - 0     Prescaler disabled (no clock)
 *            - 1     Prescaler enabled
 */
static inline void Emios_Pwm_Ip_SetPrescalerEnable(Emios_Pwm_Ip_HwAddrType *const Base,
                                                   uint8 Channel,
                                                   boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_UCPREN_MASK)) | eMIOS_C_UCPREN(ValueConvert);
}

/* Bitfiled UCPRE is not used. Instead the Value is controled using UCEXTPRE from C2 */

/*!
 * brief Set Direct Memory Access bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 *            - 0      Flag/overrun assigned to Interrupt request.
 *            - 1      Flag/overrun assigned to DMA request.
 */
static inline void Emios_Pwm_Ip_SetDMARequest(Emios_Pwm_Ip_HwAddrType *const Base,
                                              uint8 Channel,
                                              boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_DMA_MASK)) | eMIOS_C_DMA(ValueConvert);
}

/*!
 * brief Get Direct Memory Access bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * return Value of Direct Memory Access state in Unified Channels Control register
 *          - 0      Flag/overrun assigned to Interrupt request.
 *          - 1      Flag/overrun assigned to DMA request.
 */
static inline boolean Emios_Pwm_Ip_GetDMARequest(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                 uint8 Channel)
{
    return (((Base->CH.UC[Channel].C & eMIOS_C_DMA_MASK) >> eMIOS_C_DMA_SHIFT) == 0U)? FALSE : TRUE;
}

/*!
 * brief Set FLAG Enable bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 *            - 0      Disable (FLAG does not generate an interrupt request)
 *            - 1      Enable (FLAG generates an interrupt request)
 */
static inline void Emios_Pwm_Ip_SetInterruptRequest(Emios_Pwm_Ip_HwAddrType *const Base,
                                                    uint8 Channel,
                                                    boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_FEN_MASK)) | eMIOS_C_FEN(ValueConvert);
}

/*!
 * brief Get FLAG Enable bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of FLAG Enable bit
 *            - 0 Disable (FLAG does not generate an interrupt request)
 *            - 1 Enable (FLAG generates an interrupt request)
 */
static inline boolean Emios_Pwm_Ip_GetInterruptRequest(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                       uint8 Channel)
{
    return (((Base->CH.UC[Channel].C & eMIOS_C_FEN_MASK) >> eMIOS_C_FEN_SHIFT) == 0U)? FALSE : TRUE;
}

/*!
 * brief Force Match A bit
 * param[in] Base      The Emios Base address pointer
 * param[in] Channel   The Channel id for the given instance
 * param[in] Value     The Value to set
 *            - 0      Has no effect.
 *            - 1      Force a match at comparator A
 */
static inline void Emios_Pwm_Ip_SetForceMatchA(Emios_Pwm_Ip_HwAddrType *const Base,
                                               uint8 Channel,
                                               boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_FORCMA_MASK)) | eMIOS_C_FORCMA(ValueConvert);
}

/*!
 * brief Force Match B bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 *            - 0     Has no effect.
 *            - 1     Force a match at comparator B
 */
static inline void Emios_Pwm_Ip_SetForceMatchB(Emios_Pwm_Ip_HwAddrType *const Base,
                                               uint8 Channel,
                                               boolean Value)
{
    uint8 ValueConvert = (Value == FALSE)? 0U : 1U;
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_FORCMB_MASK)) | eMIOS_C_FORCMB(ValueConvert);
}

/*!
 * brief Set Bus Select bits.
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 */
static inline void Emios_Pwm_Ip_SetCounterBus(Emios_Pwm_Ip_HwAddrType *const Base,
                                              uint8 Channel,
                                              Emios_Pwm_Ip_CounterBusSourceType Value)
{
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_BSL_MASK)) | eMIOS_C_BSL(Value);
}

/*!
 * brief Get Bus Select Value
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Bus Select in Unified Channels Control register
 */
static inline Emios_Pwm_Ip_CounterBusSourceType Emios_Pwm_Ip_GetCounterBus(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                                           uint8 Channel)
{
    Emios_Pwm_Ip_CounterBusSourceType CounterBus;
    switch((Base->CH.UC[Channel].C & eMIOS_C_BSL_MASK) >> eMIOS_C_BSL_SHIFT)
    {
        case 0x00U:
            CounterBus = EMIOS_PWM_IP_BUS_A;
            break;
        case 0x01U:
            CounterBus = EMIOS_PWM_IP_BUS_BCDE;
            break;
        case 0x02U:
            CounterBus = EMIOS_PWM_IP_BUS_F;
            break;
        default:
            CounterBus = EMIOS_PWM_IP_BUS_INTERNAL;
            break;
    }
    return CounterBus;
}

/*!
 * brief Get the timebase channel
 * param[in] Channel The channel id for the given instance
 * param[in] Value   Bus Select in Unified Channels Control register
 * return  Timebase channel.
 */
static inline uint8 Emios_Pwm_Ip_GetTimebaseChannel(uint8 Channel,
                                                    Emios_Pwm_Ip_CounterBusSourceType Value)
{
    uint8 TimbaseChannel;
    switch(Value)
    {
        case EMIOS_PWM_IP_BUS_A:
            TimbaseChannel = (uint8)EMIOS_PWM_IP_COUNTER_BUS_A;
            break;
        case EMIOS_PWM_IP_BUS_F:
            TimbaseChannel = (uint8)EMIOS_PWM_IP_COUNTER_BUS_F;
            break;
        case EMIOS_PWM_IP_BUS_BCDE:
            TimbaseChannel = Channel & (uint8)EMIOS_PWM_IP_COUNTER_BUS_BCDE;
            break;
        default:
            TimbaseChannel = (uint8)0xFFU;
            break;
    }
    (void)Channel;
    
    return TimbaseChannel;
}

/*!
 * brief Set Edge Polarity bit.
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 */
static inline void Emios_Pwm_Ip_SetEdgePolarity(Emios_Pwm_Ip_HwAddrType *const Base,
                                                uint8 Channel,
                                                Emios_Pwm_Ip_PolarityType Value)
{
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_EDPOL_MASK)) | eMIOS_C_EDPOL(Value);
}

/*!
 * brief Get Edge Polarity bit.
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Edge Polarity bit in Unified Channels Control register
 */
static inline Emios_Pwm_Ip_PolarityType Emios_Pwm_Ip_GetEdgePolarity(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                                     uint8 Channel)
{
    return (((Base->CH.UC[Channel].C & eMIOS_C_EDPOL_MASK) >> eMIOS_C_EDPOL_SHIFT) == 0U)? (Emios_Pwm_Ip_PolarityType)EMIOS_PWM_IP_ACTIVE_LOW : (Emios_Pwm_Ip_PolarityType)EMIOS_PWM_IP_ACTIVE_HIGH;
}

/*!
 * brief Set mode of operation of the Unified Channel
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Mode     The mode to set
 */
static inline void Emios_Pwm_Ip_SetPwmMode(Emios_Pwm_Ip_HwAddrType *const Base,
                                           uint8 Channel,
                                           Emios_Pwm_Ip_PwmModeType Mode)
{
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_MODE_MASK)) | eMIOS_C_MODE(Mode);
}

/*!
 * brief Set mode and Edge Polarity bit of operation of the Unified Channel at the same time to avoid spike pulse
 * param[in] Base    The Emios Base address pointer
 * param[in] Channel The Channel id for the given instance
 * param[in] Mode    The mode to set
 * param[in] Pol     The Edge polarity to set
 * return    void
 */
static inline void Emios_Pwm_Ip_SetPwmModePol(Emios_Pwm_Ip_HwAddrType *const Base,
                                           uint8 Channel,
                                           Emios_Pwm_Ip_PwmModeType Mode,
                                           Emios_Pwm_Ip_PolarityType Pol)
{
    Base->CH.UC[Channel].C = (Base->CH.UC[Channel].C & ~(eMIOS_C_MODE_MASK) & ~(eMIOS_C_EDPOL_MASK)) | eMIOS_C_MODE(Mode) | eMIOS_C_EDPOL(Pol);
}

/*!
 * brief Get mode of operation of the Unified Channel
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Mode selection in Unified Channels Control register
 */
static inline Emios_Pwm_Ip_MasterBusModeType Emios_Pwm_Ip_GetChannelPwmMode( const Emios_Pwm_Ip_HwAddrType *const Base,
                                                                             uint8 Channel)
{
    Emios_Pwm_Ip_MasterBusModeType MasterBusMode;
    switch ((Base->CH.UC[Channel].C & eMIOS_C_MODE_MASK) >> eMIOS_C_MODE_SHIFT)
    {
        case 16U:
            MasterBusMode = EMIOS_PWM_IP_MC_UP_COUNTER_START;
            break;
        case 18U:
            MasterBusMode = EMIOS_PWM_IP_MC_UP_COUNTER_END;
            break;
        case 20U:
            MasterBusMode = EMIOS_PWM_IP_MC_UP_DOWN_COUNTER;
            break;
        case 80U:
            MasterBusMode = EMIOS_PWM_IP_MCB_UP_COUNTER;
            break;
        case 84U:
            MasterBusMode = EMIOS_PWM_IP_MCB_UP_DOWN_COUNTER;
            break;
        default:
            MasterBusMode = EMIOS_PWM_IP_NODEFINE_COUNTER;
            break;    
    }
    return MasterBusMode;
}

/*----------------------UC register S bit field-----------------------------*/
/*!
 * brief Write 1 to clear overrun bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 */
static inline void Emios_Pwm_Ip_ClearOverRunFlag(Emios_Pwm_Ip_HwAddrType *const Base,
                                                 uint8 Channel)
{
    /* OVR bit, OVFL bit & FLAG bit can be cleared when write 1 to them */
    Base->CH.UC[Channel].S = (Base->CH.UC[Channel].S & ~((eMIOS_S_FLAG_MASK & eMIOS_S_OVFL_MASK) & eMIOS_S_OVR_MASK)) | eMIOS_S_OVR(1UL);
}

/*!
 * brief Get overrun bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Overrun bit in Unified Channels Control register
 * The OVR bit indicates that FLAG generation occurred when the FLAG bit was already set .
 * The OVR bit can be cleared either by clearing the FLAG bit or by writing a 1 to the OVR bit.
 *         - 0 Overrun has not occurred
 *         - 1 Overrun has occurred
 */
static inline boolean Emios_Pwm_Ip_GetOverRunFlag(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                  uint8 Channel)
{
    return (((Base->CH.UC[Channel].S & eMIOS_S_OVR_MASK) >> eMIOS_S_OVR_SHIFT) == 0U)? FALSE : TRUE;
}

/*!
 * brief Write 1 to clear the overflow bit.
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 */
static inline void Emios_Pwm_Ip_ClearOverFlowFlag(Emios_Pwm_Ip_HwAddrType *const Base,
                                                  uint8 Channel)
{
    /* OVR bit, OVFL bit & FLAG bit can be cleared when write 1 to them */
    Base->CH.UC[Channel].S = (Base->CH.UC[Channel].S & ~((eMIOS_S_FLAG_MASK & eMIOS_S_OVFL_MASK) & eMIOS_S_OVR_MASK)) | eMIOS_S_OVFL(1UL);
}

/*!
 * brief Get Overflow bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Overflow bit in Unified Channels Control register
 * The OVFL bit indicates that an overflow has occurred in the internal counter.
 * The OVFL bit must be cleared by software writing a 1 to it.
 *         - 0 No overflow
 *         - 1 An overflow had occurred
 */
static inline boolean Emios_Pwm_Ip_GetOverFlowFlag(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                   uint8 Channel)
{
    return (((Base->CH.UC[Channel].S & eMIOS_S_OVFL_MASK) >> eMIOS_S_OVFL_SHIFT) == 0U)? FALSE : TRUE;
}

/*!
 * brief Get Unified Channel Output pin bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of Unified Channel Output pin bit in Unified Channels Control register
 */
static inline boolean Emios_Pwm_Ip_GetOutputPinState(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                     uint8 Channel)
{
    return (((Base->CH.UC[Channel].S & eMIOS_S_UCOUT_MASK) >> eMIOS_S_UCOUT_SHIFT) == 0U)? FALSE : TRUE;
}

/*!
 * brief Write 1 to clear the FLAG bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 */
static inline void Emios_Pwm_Ip_ClearFlagEvent(Emios_Pwm_Ip_HwAddrType *const Base,
                                               uint8 Channel)
{
    /* OVR bit, OVFL bit & FLAG bit can be cleared when write 1 to them */
    Base->CH.UC[Channel].S = (Base->CH.UC[Channel].S & ~((eMIOS_S_FLAG_MASK & eMIOS_S_OVFL_MASK) & eMIOS_S_OVR_MASK)) | eMIOS_S_FLAG(1UL);
}

/*!
 * brief Get FLAG bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of FLAG bit in Unified Channels Control register
 * The FLAG bit indicates that a match event has occurred in the Channel.
 * The FLAG bit must be cleared by software writing a 1 to it.
 *         - 0 No flag event
 *         - 1 A flag eventhad occurred
 */
static inline boolean Emios_Pwm_Ip_GetOverFlagEvent(const Emios_Pwm_Ip_HwAddrType *const Base,
                                                    uint8 Channel)
{
    return (((Base->CH.UC[Channel].S & eMIOS_S_FLAG_MASK) >> eMIOS_S_FLAG_SHIFT) == 0U)? FALSE : TRUE;
}

/*-----------------------UC register ALTA-----------------------------*/
/*!
 * brief Set A2 Channel registers Value
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 */
static inline void Emios_Pwm_Ip_SetTrigger(Emios_Pwm_Ip_HwAddrType *const Base,
                                           uint8 Channel,
                                           Emios_Pwm_Ip_PeriodType Value)
{
    Base->CH.UC[Channel].ALTA = (Base->CH.UC[Channel].ALTA & ~(eMIOS_ALTA_ALTA_MASK)) | eMIOS_ALTA_ALTA(Value);
}

/*!
 * brief Get A2 Channel registers Value
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * return Value of A2 Channel registers in Unified Channels Control register
 */
static inline Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetTrigger(const Emios_Pwm_Ip_HwAddrType *const Base,
                                             uint8 Channel)
{
    return (Emios_Pwm_Ip_PeriodType)((Base->CH.UC[Channel].ALTA & eMIOS_ALTA_ALTA_MASK) >> eMIOS_ALTA_ALTA_SHIFT);
}

/*------------------UC register C2 --------------------------*/
/*!
 * brief Set Extended Prescaler bits
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 */
#ifdef EMIOS_PWM_IP_PRESCALER_14BIT
static inline void Emios_Pwm_Ip_SetExtendedPrescaler(Emios_Pwm_Ip_HwAddrType *const Base,
                                                     uint8 Channel,
                                                     uint16 Value)
{
    uint32 ClockDividerValue = (uint32)Value - 1U;
    /* Set Extended Prescaler bits */
    Base->CH.UC[Channel].C2 = (Base->CH.UC[Channel].C2 & ~(eMIOS_C2_UCEXTPRE_MASK)) | eMIOS_C2_UCEXTPRE(ClockDividerValue);
}
#else
/*!
 * brief Set Extended Prescaler bits
 */    
static inline void Emios_Pwm_Ip_SetExtendedPrescaler(Emios_Pwm_Ip_HwAddrType *const Base,
                                                     uint8 Channel,
                                                     Emios_Pwm_Ip_InternalClkPsType Value)
{
    Base->CH.UC[Channel].C2 = (Base->CH.UC[Channel].C2 & ~(eMIOS_C2_UCEXTPRE_MASK)) | eMIOS_C2_UCEXTPRE(Value);
}
#endif

/*!
 * brief Set Prescaler Clock select bit
 * param[in] Base     The Emios Base address pointer
 * param[in] Channel  The Channel id for the given instance
 * param[in] Value    The Value to set
 *         - 0        Prescaled Clock
 *         - 1        eMIOS module clock
 */
static inline void Emios_Pwm_Ip_SetPrescalerSource(Emios_Pwm_Ip_HwAddrType *const Base,
                                                   uint8 Channel,
                                                   Emios_Pwm_Ip_InternalPsSrcType Value)
{
    Base->CH.UC[Channel].C2 = (Base->CH.UC[Channel].C2 & ~(eMIOS_C2_UCPRECLK_MASK)) | eMIOS_C2_UCPRECLK(Value);
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_HWACCESS_H */
