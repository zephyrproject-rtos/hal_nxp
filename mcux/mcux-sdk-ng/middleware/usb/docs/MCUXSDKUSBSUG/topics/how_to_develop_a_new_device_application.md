# How to develop a new device application

Perform these steps to develop a new device application:

1.  Create a new application directory under `<install_dir>/boards/<board>/usb_examples/usb_device_<class>_<application>`to locate the application source files and header files. For example, `<install_dir>/boards/<board>/usb_examples/usb_device_hid_test.`
2.  Copy the following files from the similar existing applications to the application directory that is created in Step 1.

    ```
    usb_device_descriptor.c
    usb_device_descriptor.h
    ```

    The `usb_device_descriptor.c` and `usb_device_descriptor.h` files contain the USB descriptors that are dependent on the application and the class driver.

3.  Copy the bm directory from the similar existing application directory to the new application directory. Remove the unused project directory from the bm directory. Modify the project directory name to the new application project name. For example, to create `toolchain-IAR, board-frdmk64 class-hid related application`, create the new application `hid_test` based on a similar existing application `hid_mouse.`

    Change `<install_dir>/boards/<board>/usb_examples/usb_device_hid_mouse` to `<install_dir>/boards/<board>/usb_examples/usb_device_hid_test`

4.  Modify the project file name to the new application project file name, for example, from `dev_hid_mouse_bm.ewp` to `dev_hid_test_bm.ewp`. Globally replace the existing name to the new project name by editing the project files. The `dev_hid_test_bm.ewp` file includes the new application project setting.
5.  Create a new source file to implement the main application functions and callback functions. The name of this file is similar to the new application name, such as `mouse.c` and `keyboard.c`.

The following sections describe the steps to change application files created in the steps above to match the new application.


```{include} ../topics/changing_the_usb_device_descriptorc_file.md
:heading-offset: 3
```

```{include} ../topics/changing_the_usb_device_descriptorh_file.md
:heading-offset: 3
```

```{include} ../topics/changing_the_application_file.md
:heading-offset: 3
```

**Parent topic:**[Developing a new USB device application](../topics/developing_a_new_usb_device_application.md)

