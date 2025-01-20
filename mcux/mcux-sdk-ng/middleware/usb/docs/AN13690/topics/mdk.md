# MDK

1.  **Create an RT1170 M4/RT1180 M7 project**
    1.  For RT1170, copy the *cm4* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_hid\_mouse/bm/cm4* to the folder where the example must be enabled.

        In this case, copy the *cm4* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_hid\_mouse/bm/cm4* to the *bm* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm*.

        For RT1180, copy the *cm7*folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_hid\_mouse/bm/cm7* to the folder where the example must be enabled.

        In this case, copy the *cm7* folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_hid\_mouse/bm/cm7* to the *bm* folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_msc\_disk/bm*.

    2.  For RT1170, open the *mdk* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm4/mdk*.

        For RT1180, open the *mdk* folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_msc\_disk/bm/cm7/mdk*.

    3.  For RT1170, change the filename *dev\_hid\_mouse\_bm\_cm4* to *dev\_msc\_disk\_bm\_cm4* respectively.

        |![](../images/image13.png)

|

        For RT1180, change the filename *dev\_hid\_mouse\_bm\_cm7* to *dev\_msc\_disk\_bm\_cm7* respectively.

    4.  For RT1170, open the *dev\_msc\_disk\_bm\_cm4.uvmpw*, *dev\_msc\_disk\_bm\_cm4.uvoptx, and* *dev\_msc\_disk\_bm\_cm4.uvprojx* files with a text editor, such as notepad, notepad++, sublime or Visual studio code.

        For RT1180, open the *dev\_msc\_disk\_bm\_cm4.uvmpw*, *dev\_msc\_disk\_bm\_cm7.uvoptx, and* *dev\_msc\_disk\_bm\_cm7.uvprojx* files with a text editor, such as notepad, notepad++, sublime or Visual studio code.

    5.  For RT1170, search and replace all `dev_hid_mouse_bm_cm4` with `dev_msc_disk_bm_cm4`, and then save the files.

        |![](../images/image14.png)

|

        For RT1180, search and replace all `dev_hid_mouse_bm_cm7` with `dev_msc_disk_bm_cm7`, and then save the files.

2.  **Rearrange source files**

    1.  For RT1170, open the *cm4* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm4*, and delete all files with the `.c` and `.h` extension.

        For RT1180, open the *cm7* folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_msc\_disk/bm/cm7*, and delete all files with the `.c` and `.h` extension.

    2.  For RT1170, copy files with the `.c` and `.h` extension in the *cm7* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm7* to the *cm4* folder under *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm4*.

        |![](../images/image4.png)

|

    For RT1180, copy files with the `.c` and `.h` extension in the *cm33* folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_msc\_disk/bm/cm33* to the *cm7* folder under *<install\_dir\>/boards/evkmimxrt1180/usb\_examples/usb\_device\_msc\_disk/bm/cm7*.

3.  **Rearrange project files**

    **Note:** The following steps are described for RT1170. However, these steps are also applicable for RT1180.

    1.  Open `dev_msc_disk_bm_cm7` and `dev_msc_disk_bm_cm4` MDK project respectively. The two workspaces are respectively located in *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm7/mdk* and *<install\_dir\>/boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm4/ mdk*.
    2.  Compare the whole project directory, delete groups that are in the `cm4` project but not `cm7`. In the `cm4` project, add groups that are in the `cm7` project but not `cm4`.
    3.  Compare the two groups with the same name. Delete files that are in the `cm4` project but not `cm7`. Add files that are in the `cm7` project but not `cm4`.
    In this case,

    -   Delete the groups framed in the red box in the `cm4` project and add the directories framed in the green box to the `cm4` project.

        |![](../images/image15.png)

|

    -   For the `source` group, delete the files in the *source* group in the `cm4` project and add files under *<install\_dir\>boards/evkmimxrt1170/usb\_examples/usb\_device\_msc\_disk/bm/cm4* with the same name as in `cm7` project.

        |![](../images/image16.png)

|

    -   For the `board` group, add *sdmmc\_config* source files to the *board* group in the `cm4` project.

        |![](../images/image17.png)

|

    -   For the `drivers` group, delete `fsl_pit` source files in the `cm4` project and add `fsl_usdhc` source files to the `cm4` project.
4.  **Adjust project settings**

    **Note:** The following steps are described for RT1170. However, these steps are also applicable for RT1180.

    1.  Compare the macro in the project settings by clicking **Option** -\> **C/C++**. Add a macro that is in the `cm7` project but not `cm4`.

        In this case, add the *SD\_ENABLED* macro to the `cm4` project.

        |![](../images/image19.png)

|

    2.  Change the include paths in the project settings, by clicking **Option** \> **C/C++**, according to the changes of project files.

        In this case, delete the paths framed in the red box and add the paths framed in the green box.

        |![](../images/image20.png)

|


With all above steps done, the RT1170 M7 project successfully changes to an M4 project and the M4 example USB project is available for downloading and debugging. The RT1180 M33 project successfully changes to an M7 project and the M7 example USB project is downloading and debugging.

