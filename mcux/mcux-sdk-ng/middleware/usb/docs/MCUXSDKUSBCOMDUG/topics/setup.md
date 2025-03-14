# Setup

Before developing the composite device, the user needs to:

1.  Decide how many classes are included in this composite device.
2.  Decide which types of classes are included in this composite device. For example, HID + AUDIO, HID + HID, and so on.
3.  Prepare the device descriptor depending on the use case. In particular, the IAD should be used for AUDIO/VIDEO class. For more information, see [www.usb.org/developers/docs/whitepapers/iadclasscode\_r10.pdf](http://www.usb.org/developers/docs/whitepapers/iadclasscode_r10.pdf).
4.  Ensure that the functionality of the single function device code is valid.


```{include} ../topics/design_steps.md
:heading-offset: 1
```

