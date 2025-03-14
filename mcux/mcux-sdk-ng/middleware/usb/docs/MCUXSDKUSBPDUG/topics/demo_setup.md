# Demo setup

The `usb_pd` demo is described in this section. For information about `usb_pd_battery`, `usb_pd_source_charger`, and `usb_pd_alt_mode_dp_host`, see the *readme* file in the corresponding demos' directory.

The LPCXpresso54114 and USB-PD/Type C shield board om13588 is used as the example.

In this demo, several functionalities are demonstrated: Power Role Swap, Request 5 V or higher voltage, Hard Reset, and so on. There are two ways to control the demo, using the button or user menu. Due to the limitation of number of hardware buttons, additional functionalities are provided via user menu. The follow table indicates the way it is used on different boards:

||Power request software|Power change software|
|::|:--------------------:|:-------------------:|
|**FRDM-K22F**|SW2|SW3|
|**FRDM-K64F**|SW2|SW3|
|**FRDM-KL27Z**|SW1|SW3|
|**FRDM-KL28Z**|user menu|user menu|
|**FRDM-KL32L2A4S**|user menu|user menu|
|**IMXRT1050-EVKB**|user menu|user menu|
|**LPCXpresso54018**|SW4|SW5|
|**LPCXpresso54114**|SW1|SW2|
|**LPCXpresso54608**|SW4|SW5|
|**LPCXpresso55S16**|user menu|user menu|
|**LPCXpresso55S28**|user menu|user menu|
|**LPCXpresso55S69**|user menu|user menu|
|**MIMXRT685-EVK**|user menu|user menu|
|**MIMXRT1015-EVK**|user menu|user menu|
|**MIMXRT1020-EVK**|user menu|user menu|
|**MIMXRT1050-EVK**|user menu|user menu|
|**MIMXRT1060-EVK**|user menu|user menu|
|**MIMXRT1064-EVK**|user menu|user menu|
|**MC56F83000-EVK**|user menu|user menu|
|**MIMXRT1170-EVK**|user menu|user menu|
|**MIMXRT1060-EVKB**|user menu|user menu|
|**MIMXRT1160-EVK**|user menu|user menu|
|**MIMXRT595-EVK**|user menu|user menu|
|**LPCXpresso55S36**|user menu|user menu|
|**MIMXRT685-AUD-EVK**|user menu|user menu|

**Note:** For some boards there are no switches to use. So, this demo uses menus to implement the same functionality as a switch. The menus correspond to the switches as follows and can be obtained by inputting **0** in the debug console.

|**Switch**|**Menu item**|
|Short press **Power request switch**|Request 5 V|
|Long press **Power request switch**|Request high voltage|
|Short press **Power change switch**|Power role swap|
|Long press **Power change switch**|Hard reset|

**Note:** The VBus test point is **J5** of the USB-PD/Type C Shield board.


```{include} ../topics/setup_hardware_boards.md
:heading-offset: 1
```

```{include} ../topics/request_from_original_sink_role.md
:heading-offset: 1
```

```{include} ../topics/power_swap_from_sink_role.md
:heading-offset: 1
```

```{include} ../topics/request_from_original_source_role.md
:heading-offset: 1
```

```{include} ../topics/power_swap_from_source_role.md
:heading-offset: 1
```

```{include} ../topics/hard_reset_test.md
:heading-offset: 1
```

```{include} ../topics/test_other_commands.md
:heading-offset: 1
```

