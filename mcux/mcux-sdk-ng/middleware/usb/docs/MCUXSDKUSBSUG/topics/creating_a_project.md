# Creating a project

Perform the following steps to create a project.

-   Create a new application directory under `<install_dir>/boards/<board>/usb_examples/usb_host_<class>_<application>` to locate the application source files and header files. For example, `<install_dir>/boards/<board>/usb_examples/usb_host_hid_mouse`.
-   Copy the following files from the similar existing applications to the application directory that is created in step 1.

    app.c

    usb\_host\_config.h

    The app.c file contains the common initialization code for USB host and the usb\_host\_config.h file contains the configuration MACROs for the USB host.

-   Copy the bm directory from the similar existing application directory to the new application directory. Remove the unused project directory from the bm directory. Modify the project directory name to the new application project name. For example, `to create toolchain-IAR, board-frdmk64 class-hid related application` , create the new application `hid_test` based on a similar existing application `hid_mouse`.

    Copy `<install_dir>/boards/frdmk64f/usb_examples/usb_host_hid_mouse/bm`

    to `<install_dir>/boards/frdmk64f/usb_examples/usb_host_hid_test/bm`

-   Modify the project file name to the new application project file name, for example, from `host_hid_mouse_bm.ewp` to `host_hid_test_bm.ewp` . Globally replace the existing name to the new project name by editing the project files. The `host_hid_test_bm.ewp` file includes the new application project setting.

-   Create a new source file to implement the main application function, application task function, and the callback function. The name of this file is similar to the new application name, such as `host_mouse.c` and `host_keyboard.c`.


The following sections describe the steps to modify application files created in the steps above to match the new application.

**Parent topic:**[How to develop a new host application](../topics/how_to_develop_a_new_host_application.md)

