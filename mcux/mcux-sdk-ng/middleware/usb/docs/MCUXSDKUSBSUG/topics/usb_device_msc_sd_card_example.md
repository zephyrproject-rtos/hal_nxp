# USB device MSC SD card example

USB device MSC SD card example needs SDHC driver support and SD card support. The example works only if the platform supports both SD card and the SDHC. To enable this example using the same code, the following MACROs are defined in the board.h file:

```
#define BOARD_SDHC_BASEADDR             SDHC
#define BOARD_SDHC_CLKSRC               kCLOCK_CoreSysClk
#define BOARD_SDHC_CD_GPIO_BASE         GPIOB
#define BOARD_SDHC_CD_GPIO_PIN          20U
#define BOARD_SDHC_CD_PORT_BASE         PORTB
#define BOARD_SDHC_CD_PORT_IRQ          PORTB_IRQn
#define BOARD_SDHC_CD_PORT_IRQ_HANDLER  PORTB_IRQHandler

```

Update the MACROs according to the board design. For example, the SD card detection GPIO on the board is PORTD\_1. In this case, change the above MACROs as follows:

```
#define BOARD_SDHC_BASEADDR             SDHC
#define BOARD_SDHC_CLKSRC               kCLOCK_CoreSysClk
#define BOARD_SDHC_CD_GPIO_BASE         **GPIOD**
#define BOARD_SDHC_CD_GPIO_PIN          **1U**
#define BOARD_SDHC_CD_PORT_BASE         **PORTD**
#define BOARD_SDHC_CD_PORT_IRQ          **PORTD\_IRQn**
#define BOARD_SDHC_CD_PORT_IRQ_HANDLER  **PORTD\_IRQHandler**

```

**Parent topic:**[Porting examples](../topics/porting_examples.md)

