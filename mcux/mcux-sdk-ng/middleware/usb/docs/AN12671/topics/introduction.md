# Introduction

MCU boots from M4 core, by default. However, it can be configured to boot from M0+ core. To do so, bit field BOOT\_CORE in FTFE\_FOPT register must be set to 0 \(register value - 0xFFFFFFBF\).

Follow the steps below to access \(program, read, erase\) the FTFE\_FOPT register using J-Link commander:

![](../images/image1jpeg.jpg)

1.  Connect J12 on board to PC using USB cable.
2.  Connect J7 on board to PC using Jlink.
3.  Open Jlink command. Once the following instructions are input, new configuration will become active after power-on-reset.

    *FTFE\_FOPT value should be 0xFFFFFFFF before.*

    ```
    w1 0x40023007 0x43 // FCCOB0: CMD_PROGRAM_ONCE (IFR)
    w1 0x40023006 0x84 // FCCOB1: IFR Index of the FOPT
    w1 0x40023005 0x00 // FCCOB2: Not used
    w1 0x40023004 0x00 // FCCOB3: Not used
    w1 0x4002300B 0xFF // FCCOB4: Record byte 0 value --> FOPT (Bit31:Bit24)
    w1 0x4002300A 0xFF // FCCOB5: Record byte 1 value --> FOPT (Bit23:Bit16)
    w1 0x40023009 0xFF // FCCOB6: Record byte 2 value --> FOPT (Bit15:Bit8)
    w1 0x40023008 0xBF // FCCOB7: Record byte 3 value --> FOPT (Bit7:Bit0)
    w1 0x40023000 0x80 // Trigger operation
    ```

4.  Additional information is available on webpage [https://wiki.segger.com/K32W\#Boot\_ROM](https://wiki.segger.com/K32W). For download issue, see the “Getting Started with MCUXpresso SDK for K32W0X2S.pdf”.

    K32 has M4 and M0+ cores. USB example can run on both cores. The USB example in the release package runs on M4 core. However, this example project can be migrated from M4 to M0p core. M4 and M0p USB project use same source files with different project setting. Use the following steps to change M4 project to M0P project with IAR, MDK, and GCC compilers. Other compilers have similar way to migrate project from M4 to M0p.


