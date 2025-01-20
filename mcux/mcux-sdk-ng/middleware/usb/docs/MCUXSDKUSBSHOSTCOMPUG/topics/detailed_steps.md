# Detailed steps

Before developing the host that supports multiple devices, the user needs to determine:

1.  How many classes this host needs to support.
2.  How many subclasses for every class. For example, the HID class may include HID mouse and HID keyboard.

The code change for the host that supports HID mouse and HID keyboard is similar to that of the host supporting CDC virtual com and HID mouse.


```{include} ../topics/host_event_handle_function.md
:heading-offset: 1
```

```{include} ../topics/class-specific_device_task.md
:heading-offset: 1
```

