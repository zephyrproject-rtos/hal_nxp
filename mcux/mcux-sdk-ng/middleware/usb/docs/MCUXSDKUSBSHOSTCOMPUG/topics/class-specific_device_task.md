# Class-specific device task

The main function needs to schedule every supported device’s task. If the host only supports CDC devices, the class-specific task in the main function is as follows:

```
int main(void)
{
BOARD_InitHardware();
APP_init();
while (1)
{
USB_HostTaskFn(g_hostHandle);
/* cdc class task */
USB_HosCdcTask(&g_cdc);
/* here add the new device’s task */
}
}
```

**Parent topic:**[Detailed steps](../topics/detailed_steps.md)

