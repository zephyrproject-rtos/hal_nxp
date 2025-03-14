# USB cache-related MACROs definitions

There are few MACROs in the USB stack to define USB data attributes.

-   USB\_STACK\_USE\_DEDICATED\_RAM

    The following values are used to configure the USB stack to use dedicated RAM or not.

    1. USB\_STACK\_DEDICATED\_RAM\_TYPE\_BDT\_GLOBAL - The USB device global variables \(controller data and device stack data\) are put into the USB-dedicated RAM.

    2. USB\_STACK\_DEDICATED\_RAM\_TYPE\_BDT - The USB device controller global variables \(BDT data\) are put into the USB-dedicated RAM.

    3. 0 - There is no USB-dedicated RAM.

-   USB\_DEVICE\_CONFIG\_BUFFER\_PROPERTY\_CACHEABLE

    The following values are used to configure the device stack cache to be enabled or not.

    0: disabled

    1: enable

    This macro is not supported in the Cortex-M7 platforms.

-   USB\_HOST\_CONFIG\_BUFFER\_PROPERTY\_CACHEABLE

    The following values are used to configure host stack cache to be enabled or not.

    0: disable

    1: enable

    This macro is not supported in the Cortex-M7 platforms.


Based on the above MACROs, the following cache-related MACROs are defined in the USB stack.

||USB\_DEVICE\_CONFIG\_BUFFER\_PROPERTY\_CACHEABLE \|\|

 USB\_HOST\_CONFIG\_BUFFER\_PROPERTY\_CACHEABLE is true

|USB\_DEVICE\_CONFIG\_BUFFER\_PROPERTY\_CACHEABLE \|\|

 USB\_HOST\_CONFIG\_BUFFER\_PROPERTY\_CACHEABLE is false

|
|USB\_STACK\_USE\_DEDICATED\_RAM’s Value| |DATA\_SECTION\_IS\_CACHEABLE is true|DATA\_SECTION\_IS\_CACHEABLE is false|
|USB\_STACK\_DEDICATED\_RAM\_TYPE\_BDT\_GLOBAL||USB\_GLOBAL|dedicated ram, stack use only|
|USB\_BDT|dedicated ram, stack use only|
|USB\_CONTROLLER\_DATA|NonCachable, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|cachable ram and alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|cachable ram and alignment|

||USB\_GLOBAL|dedicated ram, stack use only|
|USB\_BDT|dedicated ram, stack use only|
|USB\_CONTROLLER\_DATA|NonCachable, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|noncachable ram and alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|noncachable ram and alignment|

||USB\_GLOBAL|dedicated ram, stack use only|
|USB\_BDT|dedicated ram, stack use only|
|USB\_CONTROLLER\_DATA|dedicated ram, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|alignment|

|
|USB\_STACK\_DEDICATED\_RAM\_TYPE\_BDT||USB\_GLOBAL|cachable ram and alignment, stack use only|
|USB\_BDT|dedicated ram, stack use only|
|USB\_CONTROLLER\_DATA|NonCachable, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|cachable ram and alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|cachable ram and alignment|

||USB\_GLOBAL|NonCachable, stack use only|
|USB\_BDT|dedicated ram, stack use only|
|USB\_CONTROLLER\_DATA|NonCachable, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|NonCachable and alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|NonCachable and alignment|

||USB\_GLOBAL|NULL, stack use only|
|USB\_BDT|dedicated ram, stack use only|
|USB\_CONTROLLER\_DATA|NULL, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|alignment|

|
|0||USB\_GLOBAL|cachable ram and alignment, stack use only|
|USB\_BDT|NonCachable, stack use only|
|USB\_CONTROLLER\_DATA|NonCachable, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|cachable ram and alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|cachable ram and alignment|

||USB\_GLOBAL|NonCachable, stack use only|
|USB\_BDT|NonCachable, stack use only|
|USB\_CONTROLLER\_DATA|NonCachable, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|NonCachable and alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|NonCachable and alignment|

||USB\_GLOBAL|NULL, stack use only|
|USB\_BDT|NULL, stack use only|
|USB\_CONTROLLER\_DATA|NULL, stack use only|
|USB\_DMA\_NONINIT\_DATA\_ALIGN\(n\)|alignment|
|USB\_DMA\_INIT\_DATA\_ALIGN\(n\)|alignment|

|

**Note:** “NULL” means that the MACRO is empty and has no influence.

There are four assistant MACROs:

|USB\_DATA\_ALIGN\_SIZE|Used in USB stack and application, defines the default align size for USB data.|
|USB\_DATA\_ALIGN\_SIZE\_MULTIPLE\(n\)|Used in USB stack and application, calculates the value that is multiple of the data align size.|
|USB\_DMA\_DATA\_NONCACHEABLE|Used in USB stack and application, puts data in the noncacheable region if the cache is enabled.|
|USB\_GLOBAL\_DEDICATED\_RAM|Used in USB stack and application, puts data in the dedicated RAM if dedicated RAM is enabled.|

**Parent topic:**[USB stack configuration](../topics/usb_stack_configuration.md)

