# Step-by-step guide for MCUXpresso IDE

1.  Prepare a compressed release package, such as SDK\_2.0\_FRDM-K64F.zip.
2.  Open MCUXpresso IDE and drag and drop the MCUXpresso SDK \(zip file/folder\) into the "Installed SDKs". The MCUXpresso SDK should install.

    |![](../images/fig_12.jpg "Installed SDK")

|

3.  To select an example, select the “Import SDK example\(s\)” button. Click the “Next” button after selecting the available board.

    |![](../images/import_project_button.jpg "Import project button")

|

    |![](../images/select_boards.jpg "Select boards")

|

4.  To import one example, click the “Finish” button after selecting the available example.

    |![](../images/import_project.jpg "Import project")

|

5.  After importing, the window should look like the below figure.

    |![](../images/usb_project_workspace_fig16.jpg "The USB projects workspace")

|

6.  Choose the appropriate build target, “Debug” or “Release”, by left-clicking the build configuration icon as show in the below figure.

    |![](../images/manage_build_config_button.jpg "Manage build configuration button")

|

7.  If the project build does not begin after selecting the desired target, left-click the build icon to start the build.

    |![](../images/build_project_button.jpg "Build project button")

|

8.  To check debugger configurations, click the down arrow next to the green debug button and select “Debug Configurations”.

    |![](../images/config_debug_button.jpg "Configure debug button")

|

9.  After verifying the debugger configurations are correct, click the “Debug” button.

    |![](../images/mcux_debug_config.jpg "MCUXpresso IDE debug configurations")

|

10. The application is downloaded to the target and automatically runs to main\(\):
11. Run the code by clicking the “Resume” button to start the application:

    |![](../images/resume_button.jpg "Resume button")

|

12. See the example-specific document for more test information.

**Parent topic:**[Compiling or running the USB stack and examples](../topics/compiling_or_running_the_usb_stack_and_examples.md)

