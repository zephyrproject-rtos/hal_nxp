# Introduction

RT1170 works with M7 and M4, on which all USB examples can run. However, all USB examples in the release package are enabled on M7. Only example `host_hid_mouse` and `dev_hid_mouse` are enabled on M4. As for RT1180 works with M7 and M33, all USB examples in the release package are enabled on M33. Only example host\_hid\_mouse and dev\_hid\_mouse are enabled on M7. Since USB projects on both cores share demo source files but with different project settings, examples can be migrated.

This document describes how to migrate USB examples from M7 to M4 or from M33 to M7 with different toolchains. There are four main steps required:

1.  Create an RT1170 M4/RT1180 M7 project.
2.  Rearrange source files.
3.  Rearrange project files.
4.  Adjust project settings.

This document takes the `dev_msc_disk_bm` as an example to show how to enable USB examples on M4 core of RT1170 or on M7 core of RT1180 with IAR, MDK, ARMGCC, and MCUXpresso IDE.

