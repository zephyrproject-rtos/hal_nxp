# USB host CDC example

The MCUXpresso SDK debug console can be based on The MCUXpresso SDK UART, LPUART, or LPSCI driver. Because different platforms may use different drivers, the CDC has a wrapper code. The files, which call the corresponding driver API according to the debug console use UART, LPUART, or LPSCI. The utility uses the BOARD\_DEBUG\_UART\_TYPE toidentify the UART type. To use a different UART instance, use the corresponding UART instance wrapper file.

The MCUXpresso SDK debug console only enables send. The Host CDC example needs the receive function. Therefore, configuration MACROs need to be defined in the board.h file. The debug console and the Host CDC share the same configuration. This is an example:

```
#define BOARD_DEBUG_UART_TYPE       kSerialPort_Uart
#define BOARD_DEBUG_UART_BASEADDR   (uint32_t)UART1
#define BOARD_DEBUG_UART_CLKSRC     kCLOCK_CoreSysClk
#define BOARD_DEBUG_UART_BAUDRATE   115200

```

Update MACROs according to board design. For example, the default UART instance on the board is LPUART1, the type of default UART instance on one specific platform is LPUART, and the LPUART clock source is the external clock. In this case, change the above MACROs as follows:

```
#define BOARD_DEBUG_UART_TYPE **kSerialPort\_Uart**
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) **LPUART1**
#define BOARD_DEBUG_UART_CLKSRC **kCLOCK\_Osc0ErClk**
#define BOARD_DEBUG_UART_BAUDRATE 115200

```

**Parent topic:**[Porting examples](../topics/porting_examples.md)

