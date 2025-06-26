# Main function task

Add the USB\_HostMsdTask function into the main function. The modified code should look like this:

```
int main(void)
{
    gpio_pin_config_t pinConfig;
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    /* enable usb host vbus */
    pinConfig.pinDirection = kGPIO_DigitalOutput;
    pinConfig.outputLogic = 1U;
    GPIO_PinInit(PTD, 8U, &pinConfig);
    APP_init();
    while (1)
    {
        USB_HostTaskFn(g_HostHandle);
        /* cdc class task */
        USB_HosCdcTask(&g_cdc);
        /* msd class task */
        USB_HostMsdTask(&g_MsdCommandInstance);
    }
}
```

**Parent topic:**[Host MSD command + CDC virtual com example](../topics/host_msd_command__cdc_virtual_com_example.md)

