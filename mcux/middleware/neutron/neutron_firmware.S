/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Embed the Neutron firmware ELF as a byte array so it can be passed to the
 * Neutron driver via neutronCustomPrepare(). On RT2660 the firmware is no
 * longer a link-time library; the driver references the binary through the
 * _binary_NeutronFirmware_elf_start / _end symbols produced here.
 *
 * The path to the firmware ELF is provided by the build system through the
 * NEUTRON_FIRMWARE_ELF preprocessor define.
 */

	.section .rodata, "a", %progbits
	.align 16
	.global _binary_NeutronFirmware_elf_start
	.global _binary_NeutronFirmware_elf_end

_binary_NeutronFirmware_elf_start:
	.incbin NEUTRON_FIRMWARE_ELF
_binary_NeutronFirmware_elf_end:
