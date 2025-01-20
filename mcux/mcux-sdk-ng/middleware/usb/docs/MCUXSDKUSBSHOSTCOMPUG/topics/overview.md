# Overview

This document describes steps to implement a host that supports multiple devices based on the MCUXpresso SDK USB stack.

The USB Stack provides one host demo that supports HID mouse + HID keyboard. A user may need a host to meet its requirements, such as the ability to support different class devices like supporting an HID and an MSD device simultaneously. This document provides a step-by-step guide to create a customizable host that supports multiple devices.

