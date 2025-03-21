# USB device audio speaker example

USB device audio speaker example needs the I2C, SAI, and DMA driver support.

The instance of SAI \(I2S\) and I2C are defined in the app.h file in the example directory as follows:

```
#define DEMO_SAI I2S0
#define DEMO_I2C I2C0
#define DEMO_SAI_CLKSRC kCLOCK_CoreSysClk
```

Update the MACROs according to board design. For example, the I2S instance on the board is I2S2. In this case, change the above MACROs as follows:

```
#define DEMO_SAI I2S2
#define DEMO_I2C I2C2
#define DEMO_SAI_CLKSRC kCLOCK_CoreSysClk
```

**Parent topic:**[Porting examples](../topics/porting_examples.md)

