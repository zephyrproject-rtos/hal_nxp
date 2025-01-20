# PD compliance test

Ellisys test environment

-   Hardware: Ellisys EX350
-   Software: Ellisys USB Explorer 350 Examiner 3.1.8098

The usb\_pd example supports the PD3.0 compliance test. The usb\_pd\_alt\_mode\_dp\_host example supports DisplayPort host alternate mode compliance test. The usb\_pd\_alt\_mode\_dp\_dock example supports DisplayPort dock alternate mode compliance test.

The tested target for PD3.0 compliance test is usb\_pd\_freertos flexspi\_nor\_release target of IAR toolchain on the MIMXRT1064-EVK board.

The tested target for DisplayPort host alternate mode compliance test is usb\_pd\_alt\_mode\_dp\_host\_freertos flexspi\_nor\_release target of IAR toolchain on the MIMXRT1064-EVK board.

The tested target for DisplayPort dock alternate mode compliance test is usb\_pd\_alt\_mode\_dp\_dock\_freertos release target of IAR toolchain on the LPCXpresso55S69 board.

The test reports are in *boards/middleware/usb/pd/compliance\_test\_report*.

To do a compliance test, the following configurations need be enabled in the usb\_pd\_config.h file.

PD\_CONFIG\_COMPLIANCE\_TEST\_ENABLE, PD\_CONFIG\_TRY\_SNK\_SUPPORT and PD\_CONFIG\_TRY\_SRC\_SUPPORT.

For the usb\_pd example, five configurations are verified and passed: correspondingly, one dedicated MACRO and one VIF file are needed to enable each of them. The MACROs are defined in the pd\_board\_config.h and the VIF files are in *boards/<board\>/usb\_examples/usb\_pd/<bm or freertos\>/VIF*:

-   Dual-role port

    PD\_COMPLIANCE\_TEST\_DRP needs to be enabled in pd\_board\_config.h and the file drp.txt is the dedicated VIF file for this test.

-   Dual-role port with Try.SNK

    PD\_COMPLIANCE\_TEST\_DRP\_TRY\_SNK needs to be enabled in pd\_board\_config.h and the file drp\_try\_snk.txt is the dedicated VIF file for this test.

-   Dual-role port with Try.SRC

    PD\_COMPLIANCE\_TEST\_DRP\_TRY\_SRC needs to be enabled in pd\_board\_config.h and the file drp\_try\_src.txt is the dedicated VIF file for this test.

-   Consumer/Provider port

    PD\_COMPLIANCE\_TEST\_CONSUMER\_PROVIDER needs to be enabled in pd\_board\_config.h and the file consumer\_provider.txt is the dedicated VIF file for this test.

-   Provider/Consumer port

    PD\_COMPLIANCE\_TEST\_PROVIDER\_CONSUMER needs to be enabled in pd\_board\_config.h and the file provider\_consumer.txt is the dedicated VIF file for this test.


**Note:** Only one macro can be enabled at a time for these five configurations.

For the usb\_pd\_alt\_mode\_dp\_host and usb\_pd\_alt\_mode\_dp\_dock example, the MACROs are defined in the pd\_board\_config.h and do not need to be modified. The corresponding VIF file is in boards/<board\>/usb\_examples/ usb\_pd\_alt\_mode\_dp\_host /<bm or freertos\>/VIF and boards/<board\>/usb\_examples/ usb\_pd\_alt\_mode\_dp\_dock /<bm or freertos\>/VIF

