/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef LINFLEXD_UART_IP_HWACCESS_H
#define LINFLEXD_UART_IP_HWACCESS_H

/**
*   @file
*   @internal
*   @defgroup linflexd_ip Linflexd IPL
*   @addtogroup  linflexd_ip Linflexd  IPL
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
#include "OsIf.h"
#include "Linflexd_Uart_Ip_Defines.h"
#include "SchM_Uart.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_HWACCESS_VENDOR_ID                    43
#define LINFLEXD_UART_IP_HWACCESS_MODULE_ID                    255
#define LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define LINFLEXD_UART_IP_HWACCESS_SW_MAJOR_VERSION             2
#define LINFLEXD_UART_IP_HWACCESS_SW_MINOR_VERSION             0
#define LINFLEXD_UART_IP_HWACCESS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip_Defines.h */
#if (LINFLEXD_UART_IP_HWACCESS_VENDOR_ID != LINFLEXD_UART_IP_DEFINES_VENDOR_ID)
    #error "Linflexd_Uart_Ip_HwAccess.h and Linflexd_Uart_Ip_Defines.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_HwAccess.h and Linflexd_Uart_Ip_Defines.h are different"
#endif
#if ((LINFLEXD_UART_IP_HWACCESS_SW_MAJOR_VERSION != LINFLEXD_UART_IP_DEFINES_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_SW_MINOR_VERSION != LINFLEXD_UART_IP_DEFINES_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_HWACCESS_SW_PATCH_VERSION != LINFLEXD_UART_IP_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_HwAccess.h and Linflexd_Uart_Ip_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if ((LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
        #error "Linflexd_Uart_Ip_HwAccess.h and Std_Types.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
    )
        #error "Linflexd_Uart_Ip_HwAccess.h and OsIf.h are different"
    #endif

    /* Check if current file and SchM_Uart.h header file are of the same Autosar version */
    #if ((LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != SCHM_UART_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_UART_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != SCHM_UART_AR_RELEASE_MINOR_VERSION) \
    )
        #error "Linflexd_Uart_Ip_HwAccess.h and SchM_Uart.h are different"
    #endif
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DEFAULT_OSR              16U

#define LINFLEXD_BAUDRATE_FRACTION_WIDTH  LINFLEXD_LINFBRR_FBR_WIDTH

#ifdef CPU_BYTE_ORDER
    #if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
        #define PARTITION_LITTLE_ENDIAN
    #endif
#endif

#ifdef PARTITION_LITTLE_ENDIAN
    #define SWAP_BYTES_UINT16(x) ((((x) >> 8U) & 0xFFU) | (((x) << 8U) & 0xFF00U))
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @internal
 *@brief Word length in UART mode.
 *
 *implements     Linflexd_Uart_Ip_WordLengthType_enum
 */
typedef enum
{
    LINFLEXD_UART_IP_7_BITS     = 0U,
    LINFLEXD_UART_IP_8_BITS     = 1U,
    LINFLEXD_UART_IP_15_BITS    = 2U,
    LINFLEXD_UART_IP_16_BITS    = 3U,
#ifdef LINFLEXD_UART_IP_ENABLE_UPSTREAM_FRAME_SUPPORT
#if (STD_ON == LINFLEXD_UART_IP_ENABLE_UPSTREAM_FRAME_SUPPORT)
    LINFLEXD_UART_IP_12_BITS    = 4U
#endif /*(STD_ON == LINFLEXD_UART_IP_ENABLE_UPSTREAM_FRAME_SUPPORT)*/
#endif /* LINFLEXD_UART_IP_ENABLE_UPSTREAM_FRAME_SUPPORT */
} Linflexd_Uart_Ip_WordLengthType;

/**
 * @internal
 * @brief Number of stop bits.
 *
 *
 */
typedef enum
{
    LINFLEXD_UART_IP_ONE_STOP_BIT = 0U,
    LINFLEXD_UART_IP_TWO_STOP_BIT = 1U
} Linflexd_Uart_Ip_StopBitsCountType;

/**
 * @internal
 * @brief Parity type.
 *
 *implements     Linflexd_Uart_Ip_ParityType_enum
 */
typedef enum
{
    LINFLEXD_UART_IP_PARITY_EVEN    = 0U,
    LINFLEXD_UART_IP_PARITY_ODD     = 1U,
    LINFLEXD_UART_IP_PARITY_ZERO    = 2U,
    LINFLEXD_UART_IP_PARITY_ONE     = 3U
} Linflexd_Uart_Ip_ParityType;


/**
  * * @internal
  * @brief LINFLEXD mode: UART/LIN.

  */
typedef enum
{
    LINFLEXD_LIN_MODE   = 0U,
    LINFLEXD_UART_MODE  = 1U
} Linflexd_Uart_Ip_ModeType;


/**
 * @internal
 * @brief UART Mode: FIFO/BUFFER.
 */
typedef enum
{
    LINFLEXD_UART_RXTX_BUFFER_MODE  = 0U,
    LINFLEXD_UART_RXTX_FIFO_MODE    = 1U
} Linflexd_Uart_Ip_RxTxModeType;

/**
 * @internal
 * @brief LINFLEXD state.
*/
typedef enum
{
    LINFLEXD_STATE_SLEEP_MODE       = 0U,
    LINFLEXD_STATE_INIT_MODE        = 1U,
    LINFLEXD_STATE_IDLE_MODE        = 2U,
    LINFLEXD_STATE_DATA_RX_TX       = 8U
} Linflexd_Uart_Ip_StateType;

/**
 * @internal
 * @brief UART Status flags.
 * @details These identifiers provide both mask and shift for status bits in UARTSR register.
 */
typedef enum
{
    LINFLEXD_UART_NOISE_FLAG                   = LINFLEXD_UARTSR_NF_MASK,
    LINFLEXD_UART_DATA_TRANSMITTED_FLAG        = LINFLEXD_UARTSR_DTFTFF_MASK,
    LINFLEXD_UART_DATA_RECEPTION_COMPLETE_FLAG = LINFLEXD_UARTSR_DRFRFE_MASK,
    LINFLEXD_UART_WAKEUP_FLAG                  = LINFLEXD_UARTSR_WUF_MASK,
    LINFLEXD_UART_BUFFER_OVERRUN_FLAG          = LINFLEXD_UARTSR_BOF_MASK,
    LINFLEXD_UART_FRAME_ERROR_FLAG             = LINFLEXD_UARTSR_FEF_MASK,
    LINFLEXD_UART_MESSAGE_BUFFER_FULL_FLAG     = LINFLEXD_UARTSR_RMB_MASK,
    LINFLEXD_UART_PARITY_ERROR_FLAG            = LINFLEXD_UARTSR_PE_MASK,
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    LINFLEXD_UART_TIMEOUT_INTERRUPT_FLAG       = LINFLEXD_UARTSR_TO_MASK
#endif
} Linflexd_Uart_Ip_StatusFlagType;

/**
 * @internal
 * @brief LINFLEXD interrupts.
 * @details These identifiers provide both mask and shift for the interrupt enable bits in LINIER register.
 */
typedef enum
{
    LINFLEXD_DATA_TRANSMITTED_INT        = LINFLEXD_LINIER_DTIE_MASK,
    LINFLEXD_DATA_RECEPTION_COMPLETE_INT = LINFLEXD_LINIER_DRIE_MASK,
    LINFLEXD_BUFFER_OVERRUN_INT          = LINFLEXD_LINIER_BOIE_MASK,
    LINFLEXD_FRAME_ERROR_INT             = LINFLEXD_LINIER_FEIE_MASK,
    LINFLEXD_WAKEUP_INT                  = LINFLEXD_LINIER_WUIE_MASK,
#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
    LINFLEXD_TIMEOUT_INT                 = LINFLEXD_LINIER_TOIE_MASK
#endif
} Linflexd_Uart_Ip_InterruptType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

/**
 * @internal
 * @brief Requests LINFLEXD module to enter init mode.
 *
 * This function enters initialization mode.
 *
 * @param Base LINFLEXD Base pointer.
 */
static inline void Linflexd_Uart_Ip_EnterInitMode(LINFLEXD_Type *Base)
{
    uint32 RegValTemp;

    RegValTemp = Base->LINCR1;
    RegValTemp &= ~(LINFLEXD_LINCR1_SLEEP_MASK);
    RegValTemp |= LINFLEXD_LINCR1_INIT(1UL);
    Base->LINCR1 = RegValTemp;
}

/**
 * @internal
 * @brief Requests LINFLEXD module to enter normal mode.
 *
 * This function enters normal mode. *
 *
 * @param Base LINFLEXD Base pointer.
 */
static inline void Linflexd_Uart_Ip_EnterNormalMode(LINFLEXD_Type *Base)
{
    uint32 RegValTemp;

    RegValTemp = Base->LINCR1;
    RegValTemp &= ~(LINFLEXD_LINCR1_SLEEP_MASK);
    RegValTemp &= ~(LINFLEXD_LINCR1_INIT_MASK);
    Base->LINCR1 = RegValTemp;
}

/**
 * @internal
 * @brief Sets the LINFLEXD mode.
 *
 * This function sets LIN or UART mode, Based on the parameter received.
 *
 * @param Base LINFLEXD Base pointer.
 * @param mode LINFLEXD mode - UART/LIN.
 */
static inline void Linflexd_Uart_Ip_SetMode(LINFLEXD_Type *Base, Linflexd_Uart_Ip_ModeType Mode)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_UART_MASK);
    RegValTemp |= LINFLEXD_UARTCR_UART((uint32)Mode);
    Base->UARTCR = RegValTemp;
}

#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
/**
 * @internal
 * @brief Enable Monitor Idle State for UART module
 *
 * This function to enable monitor idle state of the reception line.
 *
 * @param Base LINFLEXD Base pointer.
 * @param mode Enable enable/disable monitor idle state of the reception line.
 */
static inline void Linflexd_Uart_Ip_EnableMonitorIdleState(LINFLEXD_Type *Base, boolean Enable)
{
    Base->UARTCR |= LINFLEXD_UARTCR_MIS(Enable);
}
#endif

#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
/**
 * @internal
 * @brief Enable Timer Reset for UART module Disable Timeout in UART mode
 * Note: Disable Timeout causes only the Timer to restart which enables Timeout again.
 *       Timer reset means it resets and starts counting again and the Timeout is enabled.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Enable enable/disable timeout in UART mode.
 */
static inline void Linflexd_Uart_Ip_EnableTimerReset(LINFLEXD_Type *Base, boolean Enable)
{
    Base->UARTCR |= LINFLEXD_UARTCR_DTU_PCETX(Enable);
}
#endif

/**
 * @internal
 * @brief Returns the current LINFLEXD state.
 *
 * This function returns the state of the LINFLEXD instance. The possible states are:
 *    - Sleep mode
 *    - Init mode
 *    - Idle mode
 *    - Sync Break Reception/Transmission
 *    - Sync Delimiter Reception/Transmission
 *    - Sync Field Reception/Transmission
 *    - Identifier Field Reception/Transmission
 *    - Header Reception/Transmission
 *    - Data Reception/Transmission
 *    - Checksum Reception/Transmission
 *
 * @param Base LINFLEXD Base pointer.
 * @return LINFLEXD mode - UART/LIN.
 */
static inline Linflexd_Uart_Ip_StateType Linflexd_Uart_Ip_GetLinState(const LINFLEXD_Type * Base)
{
    uint8 State = (uint8)((Base->LINSR & LINFLEXD_LINSR_LINS_MASK) >> LINFLEXD_LINSR_LINS_SHIFT);
    return (Linflexd_Uart_Ip_StateType)State;
}

/**
 * @internal
 * @brief Sets the word length.
 *
 * This function sets the word length in UART mode.
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Length UART mode word length.
 */
static inline void Linflexd_Uart_Ip_SetUartWordLength(LINFLEXD_Type *Base, Linflexd_Uart_Ip_WordLengthType Length)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_WL0_MASK);
    RegValTemp |= LINFLEXD_UARTCR_WL0((uint32)Length & 1U);
    RegValTemp &= ~(LINFLEXD_UARTCR_WL1_MASK);
    RegValTemp |= LINFLEXD_UARTCR_WL1(((uint32)Length >> 1U) & 1U);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Enables/disables parity bit.
 *
 * This function enables or disables the parity bit from UART bytes.
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param enable true - enable parity queuing/checking, false - disable parity queuing/checking.
 */
static inline void Linflexd_Uart_Ip_SetParityControl(LINFLEXD_Type *Base, boolean Enable)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_PCE_MASK);
    RegValTemp |= LINFLEXD_UARTCR_PCE(Enable ? 1UL : 0UL);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets parity type.
 *
 * This function sets the type of parity to be used for UART bytes. Available options are:
 *    - odd
 *    - even
 *    - always 0
 *    - always 1
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param ParityType the type of parity.
 */
static inline void Linflexd_Uart_Ip_SetParityType(LINFLEXD_Type *Base, Linflexd_Uart_Ip_ParityType ParityType)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_PC0_MASK);
    RegValTemp |= LINFLEXD_UARTCR_PC0((uint32)ParityType & 1U);
    RegValTemp &= ~(LINFLEXD_UARTCR_PC1_MASK);
    RegValTemp |= LINFLEXD_UARTCR_PC1(((uint32)ParityType >> 1U) & 1U);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets the transmission mode (FIFO/Buffer).
 *
 * This function sets the transmission mode (FIFO/Buffer).
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param mode tx mode: FIFO/Buffer.
 */
static inline void Linflexd_Uart_Ip_SetTxMode(LINFLEXD_Type *Base, Linflexd_Uart_Ip_RxTxModeType Mode)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_TFBM_MASK);
    RegValTemp |= LINFLEXD_UARTCR_TFBM((uint32)Mode);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets the reception mode (FIFO/Buffer).
 *
 * This function sets the reception mode (FIFO/Buffer).
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param mode rx mode: FIFO/Buffer.
 */
static inline void Linflexd_Uart_Ip_SetRxMode(LINFLEXD_Type *Base, Linflexd_Uart_Ip_RxTxModeType Mode)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_RFBM_MASK);
    RegValTemp |= LINFLEXD_UARTCR_RFBM((uint32)Mode);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets the reception data field length/FIFO depth.
 *
 * This function sets either the reception data field length or the number of bytes in the Rx FIFO, according to
 * the current reception mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Length data field length/FIFO depth.
 */
static inline void Linflexd_Uart_Ip_SetRxDataFieldLength(LINFLEXD_Type *Base, uint8 Length)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_RDFL_RFC_MASK);
    RegValTemp |= LINFLEXD_UARTCR_RDFL_RFC(Length);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets the transmission data field length/FIFO depth.
 *
 * This function sets either the transmission data field length or the number of bytes in the Tx FIFO, according to
 * the current transmission mode.
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Length data field length/FIFO depth.
 */
static inline void Linflexd_Uart_Ip_SetTxDataFieldLength(LINFLEXD_Type *Base, uint8 Length)
{
    uint32 RegValTemp;

    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_TDFL_TFC_MASK);
    RegValTemp |= LINFLEXD_UARTCR_TDFL_TFC(Length);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets the number of stop bits for Rx.
 *
 * This function sets the number of stop bits for received bytes.
 *
 * @param Base LINFLEXD Base pointer.
 * @param StopBitsCount number of stop bits.
 */
static inline void Linflexd_Uart_Ip_SetRxStopBitsCount(LINFLEXD_Type *Base, Linflexd_Uart_Ip_StopBitsCountType StopBitsCount)
{
    uint32 RegValTemp;
    RegValTemp = Base->UARTCR;
    RegValTemp &= ~(LINFLEXD_UARTCR_SBUR_MASK);
    RegValTemp |= LINFLEXD_UARTCR_SBUR(StopBitsCount);
    Base->UARTCR = RegValTemp;
}

/**
 * @internal
 * @brief Sets fractional baud rate.
 *
 * This function configures the bits that decide the fractional part of the LIN Baud Rate.
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Fbr fractional baud rate.
 */
static inline void Linflexd_Uart_Ip_SetFractionalBaudRate(LINFLEXD_Type *Base, uint8 Fbr)
{
    Base->LINFBRR = LINFLEXD_LINFBRR_FBR(Fbr);
}

/**
 * @internal
 * @brief Sets integer baud rate.
 *
 * This function configures the bits that decide the integer part of the LIN Baud Rate.
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Ibr integer baud rate.
 */
static inline void Linflexd_Uart_Ip_SetIntegerBaudRate(LINFLEXD_Type *Base, uint32 Ibr)
{
    Base->LINIBRR = LINFLEXD_LINIBRR_IBR(Ibr);
}

/**
 * @internal
 * @brief Sets the number of stop bits for Tx.
 *
 * This function sets the number of stop bits for transmitted bytes.
 * Should be called only when the module is in init mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param DefaultOffset - true - use the memory map defined in the header file to access the register;
 *                      - false - use custom memory map to access the register.
 * @param StopBitsCount number of stop bits.
 */
static inline void Linflexd_Uart_Ip_SetTxStopBitsCount(LINFLEXD_Type *Base, Linflexd_Uart_Ip_StopBitsCountType StopBitsCount, boolean DefaultOffset)
{
    uint32 RegValTemp;

#if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
    if (!DefaultOffset)
    {
        RegValTemp = ((LINFLEXD_0IFCR_Type *)Base)->GCR;
        RegValTemp &= ~(LINFLEXD_GCR_STOP_MASK);
        RegValTemp |= LINFLEXD_GCR_STOP(StopBitsCount);
        ((LINFLEXD_0IFCR_Type *)Base)->GCR = RegValTemp;
    }
    else
    {
        RegValTemp = Base->GCR;
        RegValTemp &= ~(LINFLEXD_GCR_STOP_MASK);
        RegValTemp |= LINFLEXD_GCR_STOP(StopBitsCount);
        Base->GCR = RegValTemp;
    }
#else
    (void)DefaultOffset;
    RegValTemp = Base->GCR;
    RegValTemp &= ~(LINFLEXD_GCR_STOP_MASK);
    RegValTemp |= LINFLEXD_GCR_STOP(StopBitsCount);
    Base->GCR = RegValTemp;
#endif
}

/**
 * @internal
 * @brief Clears an UART interrupt flag.
 *
 * This function clears the UART status flag received as parameter.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Flag UART status flag.
 */
static inline void Linflexd_Uart_Ip_ClearStatusFlag(LINFLEXD_Type * Base, Linflexd_Uart_Ip_StatusFlagType Flag)
{
    Base->UARTSR = (uint32)Flag;
}

/**
 * @internal
 * @brief Returns an UART interrupt flag.
 *
 * This function returns the value of the UART status flag received as parameter.
 *
 * @param Base LINFLEXD Base pointer.
 * @return true - UART status flag set, false - UART status flag reset.
 */
static inline boolean Linflexd_Uart_Ip_GetStatusFlag(const LINFLEXD_Type * Base, Linflexd_Uart_Ip_StatusFlagType Flag)
{
    return ((Base->UARTSR & (uint32)Flag) != 0U);
}

#if defined (LINFLEXD_UART_IP_ORED_INT_LINES)
/**
 * @internal
 * @brief Returns the state of an UART interrupt.
 *
 * This function returns whether the UART Event will trigger an interrupt.
 *
 * @param Base LINFLEXD Base pointer.
 * @param IntSrc UART interrupt source.
 * @return true - interrupt enabled, false - interrupt disabled.
 */
static inline boolean Linflexd_Uart_Ip_IsInterruptEnabled(const LINFLEXD_Type * Base, Linflexd_Uart_Ip_InterruptType IntSrc)
{
    return ((Base->LINIER & (uint32)IntSrc) != 0U);
}
#endif

/**
 * @internal
 * @brief Sets the first byte of the tx data buffer.
 *
 * This function writes one byte to the tx data buffer.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Data data byte.
 */
static inline void Linflexd_Uart_Ip_SetTxDataBuffer1Byte(LINFLEXD_Type * Base, uint8 Data)
{
    Base->BDRL = LINFLEXD_BDRL_DATA0(Data);
}

/**
 * @internal
 * @brief Sets the first half-word of the tx data buffer.
 *
 * This function writes two bytes to the tx data buffer.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Data data half-word.
 */
static inline void Linflexd_Uart_Ip_SetTxDataBuffer2Bytes(LINFLEXD_Type * Base, uint16 Data)
{
    uint32 Mask;
    uint16 DataTemp;
#ifdef PARTITION_LITTLE_ENDIAN
    DataTemp = SWAP_BYTES_UINT16(Data);
#else
    DataTemp = Data;
#endif
    Mask = LINFLEXD_BDRL_DATA0_MASK | LINFLEXD_BDRL_DATA1_MASK;
    Base->BDRL = ((uint32)DataTemp & Mask);
}

/**
 * @brief Gets the first byte of the rx data buffer.
 *
 * This function retrieves one byte from the rx data buffer.
 *
 * @param Base LINFLEXD Base pointer.
 * @return data byte.
 */
static inline uint8 Linflexd_Uart_Ip_GetRxDataBuffer1Byte(const LINFLEXD_Type * Base)
{
    return (uint8)((Base->BDRM & LINFLEXD_BDRM_DATA4_MASK) >> LINFLEXD_BDRM_DATA4_SHIFT);
}

/**
 * @internal
 * @brief Gets the first half-word of the rx data buffer.
 *
 * This function retrieves two bytes from the rx data buffer.
 *
 * @param Base LINFLEXD Base pointer.
 * @return data half-word.
 */
static inline uint16 Linflexd_Uart_Ip_GetRxDataBuffer2Bytes(const LINFLEXD_Type * Base)
{
    uint16 Data;
    uint32 Mask = LINFLEXD_BDRM_DATA4_MASK | LINFLEXD_BDRM_DATA5_MASK;
    Data = (uint16)(Base->BDRM & Mask);
#ifdef PARTITION_LITTLE_ENDIAN
    Data = SWAP_BYTES_UINT16(Data);
#endif
    return Data;
}

/**
 * @internal
 * @brief DMA Tx channel enable.
 *
 * This function configures the bit that decide the DMA Tx channel enable or disable.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Enable Set Dma Tx Enable/disable.
 */
static inline void Linflexd_Uart_Ip_SetDmaTxEnable(LINFLEXD_Type *Base, boolean Enable)
{
    Base->DMATXE = LINFLEXD_DMATXE_DTE0(Enable ? 1UL : 0UL);
}

/**
 * @brief DMA Rx channel enable.
 *
 * This function configures the bit that decide the DMA Rx channel enable or disable.
 *
 * @param Base LINFLEXD Base pointer.
 * @param Enable Set Dma Rx enable/disable.
 */
static inline void Linflexd_Uart_Ip_SetDmaRxEnable(LINFLEXD_Type *Base, boolean Enable)
{
    Base->DMARXE = LINFLEXD_DMARXE_DRE0(Enable ? 1UL : 0UL);
}

#if (LINFLEXD_UART_IP_ENABLE_TIMEOUT_INTERRUPT == STD_ON)
/**
 * @brief Configures the preset value of the timeout register in UART mode.
 *
 * @param Base LINFLEXD Base pointer.
 * @param PresetValue Preset value of the timeout register.
 */
static inline void Linflexd_Uart_Ip_SetPresetValue(LINFLEXD_Type *Base, uint16 PresetValue)
{
    Base->UARTPTO = LINFLEXD_UARTPTO_PTO(PresetValue);
}
#endif

/**
 * @brief   : Prepare for timeout checking
 * @internal
 * @return  : None
 */
static inline void Linflexd_Uart_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter)
{
    *StartTimeOut    = OsIf_GetCounter(OsifCounter);
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, OsifCounter);
}

/**
 * @brief   : Checks for timeout condition
 * @internal
 * @return  TRUE     Timeout occurs
 *          FALSE    Timeout does not occur
 */
static inline boolean Linflexd_Uart_Ip_CheckTimeout(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter)
{
    uint32 CurrentElapsedTicks = OsIf_GetElapsed(StartTime, OsifCounter);
    *ElapsedTicks += CurrentElapsedTicks;
    boolean IsTimeout = FALSE;

    if (*ElapsedTicks >= TimeoutTicks)
    {
        IsTimeout = TRUE;
    }
    else
    {
        IsTimeout = FALSE;
    }
    return IsTimeout;
}

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_HWACCESS_H */
