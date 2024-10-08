Multicore SDK
=============

This is the top level Multicore SDK directory. This directory contains source code
for NXP's multicore support.


Prerequisites
-------------

There are several packages required to build multicore source code.

erpcgen prerequisites:
  - flex
  - bison
  - boost

Documentation
-------------

Multicore SDK documents can be found in the top level MCUXpressoSDK doc directory:
    "MCUXSDK_ROOT/docs/MULTICORE".

Directory Structure
-------------------

(Not all MCUXpresso SDK packages contain the whole set of these folders)

erpc - Embedded Remote Procedure Call. An infrastructure to abstract multicore
communication to fully user-definable sets of function calls. A host tool,
erpcgen, is provided to generate code to implement the multicore communication
layer for the defined function calls. Erpcgen is built for Linux, Windows, and
OS X.

mcmgr - Multicore Manager. Provides control of second core startup and shutdown.

rdmgr - Resource Domain Manager. Configures the XRDC periphal, which controls
access rights to peripherals and memory blocks.

remoteproc - General source code used for remote cores (from the Linux perspective)
to allow easy remote core applications deployment/start/debug via the remoteproc 
Linux framework.

rpmsg_lite - Remote Processor Messaging Lite software component is a lightweight
implementation of the RPMsg protocol. Compared to the OpenAMP implementation,
the RPMsg-Lite offers a code size reduction, API simplification and improved
modularity.

tools - Folder contains tools and utilities for multicore like prebuilt 
versions of erpcgen and erpcsniffer.
