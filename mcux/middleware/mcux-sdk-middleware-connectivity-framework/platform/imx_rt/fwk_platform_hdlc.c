/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fwk_platform_hdlc.h"
#include "fsl_component_serial_manager.h"
#include "board.h"
#include "fwk_platform_coex.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#ifndef SPINEL_UART_INSTANCE
#define SPINEL_UART_INSTANCE 3
#endif
#ifndef SPINEL_ENABLE_RX_RTS
#define SPINEL_ENABLE_RX_RTS 1
#endif
#ifndef SPINEL_ENABLE_TX_RTS
#define SPINEL_ENABLE_TX_RTS 1
#endif

#ifndef SPINEL_UART_BAUD_RATE
#define SPINEL_UART_BAUD_RATE 1000000
#endif

#ifndef SPINEL_UART_CLOCK_RATE
#define SPINEL_UART_CLOCK_RATE BOARD_BT_UART_CLK_FREQ
#endif

#define SPINEL_HDLC_MALLOC pvPortMalloc
#define SPINEL_HDLC_FREE   vPortFree

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

enum
{
    /* Ring buffer size should be >= to the RCP max TX buffer size value which is 2048 */
    kMaxRingBufferSize = 2048,
};

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static SERIAL_MANAGER_HANDLE_DEFINE(otTransceiverSerialHandle);
static SERIAL_MANAGER_READ_HANDLE_DEFINE(otTransceiverSerialReadHandle);

static uint8_t s_ringBuffer[kMaxRingBufferSize];

static platform_hdlc_rx_callback_t hdlcRxCallback;
static void *                      callbackParam = NULL;

#if (defined(HAL_UART_DMA_ENABLE) && (HAL_UART_DMA_ENABLE > 0U))
static serial_port_uart_dma_config_t uartConfig = {
#else
static serial_port_uart_config_t uartConfig = {
#endif
    .baudRate        = SPINEL_UART_BAUD_RATE,
    .parityMode      = kSerialManager_UartParityDisabled,
    .stopBitCount    = kSerialManager_UartOneStopBit,
    .enableRx        = 1,
    .enableTx        = 1,
    .enableRxRTS     = SPINEL_ENABLE_RX_RTS,
    .enableTxCTS     = SPINEL_ENABLE_TX_RTS,
    .instance        = SPINEL_UART_INSTANCE,
    .txFifoWatermark = 0,
    .rxFifoWatermark = 0,
};

static const serial_manager_config_t serialManagerConfig = {
    .ringBuffer     = &s_ringBuffer[0],
    .ringBufferSize = sizeof(s_ringBuffer),
    .type           = kSerialPort_Uart,
    .blockType      = kSerialManager_NonBlocking,
    .portConfig     = (serial_port_uart_config_t *)&uartConfig,
};

static bool hdlcUartInitialized = false;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

int         PLATFORM_InitHdlcUart(void);
static int  PLATFORM_TerminateHdlcUart(void);
static void PLATFORM_HdlcSerialManagerTxCallback(void *                             pData,
                                                 serial_manager_callback_message_t *message,
                                                 serial_manager_status_t            status);
static void PLATFORM_HdlcSerialManagerRxCallback(void *                             pData,
                                                 serial_manager_callback_message_t *message,
                                                 serial_manager_status_t            status);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitHdlcInterface(platform_hdlc_rx_callback_t callback, void *param)
{
    int ret = 0;

    hdlcRxCallback = callback;
    callbackParam  = param;

    do
    {
        /* Init controllers
         *  The hdlc interface will be initialized at the end of the controller initialization
         *  and before doing a reset.
         */
        if (PLATFORM_InitControllers(conn802_15_4_c) != 0)
        {
            ret = -1;
            break;
        }
        if (PLATFORM_InitHdlcUart() != 0)
        {
            ret = -1;
            break;
        }
    } while (false);

    if (ret < 0)
    {
        hdlcRxCallback = NULL;
        callbackParam  = NULL;
    }

    return ret;
}

int PLATFORM_TerminateHdlcInterface(void)
{
    int ret = 0;

    hdlcRxCallback = NULL;
    callbackParam  = NULL;

    if (PLATFORM_TerminateHdlcUart() != 0)
    {
        ret = -1;
    }

    return ret;
}

int PLATFORM_SendHdlcMessage(uint8_t *msg, uint32_t len)
{
    serial_manager_status_t serialManagerStatus;
    uint8_t *               pWriteHandleAndFrame = NULL;
    uint8_t *               pNewFrameBuffer      = NULL;
    int                     ret                  = 0;

    /* Disable IRQs to prevent concurrent accesses to class fields or
     * serial manager global variables that could be accessed in the
     * Write function
     */
    OSA_InterruptDisable();

    do
    {
        pWriteHandleAndFrame = (uint8_t *)SPINEL_HDLC_MALLOC(SERIAL_MANAGER_WRITE_HANDLE_SIZE + len);
        if (pWriteHandleAndFrame == NULL)
        {
            ret = -1;
            break;
        }

        pNewFrameBuffer = pWriteHandleAndFrame + SERIAL_MANAGER_WRITE_HANDLE_SIZE;
        memcpy(pNewFrameBuffer, msg, len);

        serialManagerStatus = SerialManager_OpenWriteHandle((serial_handle_t)otTransceiverSerialHandle,
                                                            (serial_write_handle_t)pWriteHandleAndFrame);
        if (serialManagerStatus != kStatus_SerialManager_Success)
        {
            ret = -2;
            break;
        }

        serialManagerStatus = SerialManager_InstallTxCallback(
            (serial_write_handle_t)pWriteHandleAndFrame, PLATFORM_HdlcSerialManagerTxCallback, pWriteHandleAndFrame);
        if (serialManagerStatus != kStatus_SerialManager_Success)
        {
            ret = -3;
            break;
        }

        serialManagerStatus =
            SerialManager_WriteNonBlocking((serial_write_handle_t)pWriteHandleAndFrame, pNewFrameBuffer, len);
        if (serialManagerStatus != kStatus_SerialManager_Success)
        {
            ret = -4;
            break;
        }
    } while (false);

    if (ret != 0)
    {
        SPINEL_HDLC_FREE(pWriteHandleAndFrame);
    }

    OSA_InterruptEnable();

    return ret;
}

int PLATFORM_InitHdlcUart(void)
{
    serial_manager_status_t status;
    int                     ret = 0;

    /*
     * Make sure to disable interrupts while initializating the serial manager interface
     * Some issues could happen a UART IRQ is fired during serial manager initialization
     */
    OSA_InterruptDisable();
    do
    {
        if (hdlcUartInitialized)
            break;
        /* Retrieve the UART clock rate at runtime as it can depend on clock config */
        uartConfig.clockRate = SPINEL_UART_CLOCK_RATE;

        status = SerialManager_Init((serial_handle_t)otTransceiverSerialHandle, &serialManagerConfig);
        if (status != kStatus_SerialManager_Success)
        {
            ret = -1;
            break;
        }

        status = SerialManager_OpenReadHandle((serial_handle_t)otTransceiverSerialHandle,
                                              (serial_read_handle_t)otTransceiverSerialReadHandle);
        if (status != kStatus_SerialManager_Success)
        {
            ret = -2;
            break;
        }

        status = SerialManager_InstallRxCallback((serial_read_handle_t)otTransceiverSerialReadHandle,
                                                 PLATFORM_HdlcSerialManagerRxCallback, NULL);
        if (status != kStatus_SerialManager_Success)
        {
            ret = -3;
            break;
        }
        hdlcUartInitialized = true;
    } while (false);
    OSA_InterruptEnable();
    assert(status == kStatus_SerialManager_Success);

    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_TerminateHdlcUart(void)
{
    serial_manager_status_t status;
    int                     ret = 0;

    do
    {
        if (!hdlcUartInitialized)
            break;
        status = SerialManager_CloseReadHandle((serial_read_handle_t)otTransceiverSerialReadHandle);
        if (status != kStatus_SerialManager_Success)
        {
            ret = -1;
            break;
        }

        status = SerialManager_Deinit((serial_handle_t)otTransceiverSerialHandle);
        if (status != kStatus_SerialManager_Success)
        {
            ret = -2;
            break;
        }
        hdlcUartInitialized = false;
    } while (false);

    return ret;
}

static void PLATFORM_HdlcSerialManagerTxCallback(void *                             pData,
                                                 serial_manager_callback_message_t *message,
                                                 serial_manager_status_t            status)
{
    OSA_InterruptDisable();
    /* Close the write handle */
    SerialManager_CloseWriteHandle((serial_write_handle_t)pData);
    OSA_InterruptEnable();
    /* Free the buffer */
    SPINEL_HDLC_FREE(pData);
}

static void PLATFORM_HdlcSerialManagerRxCallback(void *                             param,
                                                 serial_manager_callback_message_t *message,
                                                 serial_manager_status_t            status)
{
    uint8_t                 mUartRxBuffer[256];
    uint32_t                bytesRead = 0U;
    serial_manager_status_t smStatus;

    do
    {
        OSA_InterruptDisable();
        smStatus = SerialManager_TryRead((serial_read_handle_t)otTransceiverSerialReadHandle, mUartRxBuffer,
                                         sizeof(mUartRxBuffer), &bytesRead);
        OSA_InterruptEnable();

        if ((hdlcRxCallback != NULL) && (bytesRead > 0U) && (smStatus == kStatus_SerialManager_Success))
        {
            hdlcRxCallback(mUartRxBuffer, bytesRead, callbackParam);
        }
    } while (bytesRead != 0U);
}
