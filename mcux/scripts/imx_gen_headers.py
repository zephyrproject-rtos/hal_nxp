#!/usr/bin/env python3

"""
Wrapper around imx_cfg_utils.py to provide arguments to module
"""
import argparse
import datetime
import pathlib
import sys
from errno import ENOTDIR, EINVAL

import imx_cfg_utils


HELPSTR = """
Processes NXP iMX.RT signal configuration files

Given a processor folder, generates the SOC level pinctrl DTSI defintions
required for Zephyr. Only supports iMX.RT parts.

This tool is intended to be used with the configuration data downloaded
from NXP's website. One way to extract this config data is to use the
MCUXpresso configuration tool to download processor defintions, locate
those defintions on the disk. Alternatively, individual processor config
data packs can be downloaded from the MCUXpresso SDK builder tool. Either way,
the path to the 'processors' directory must be provided as the 'cfg-tool-root'
parameter.
"""


parser = argparse.ArgumentParser(description=HELPSTR,
        formatter_class=argparse.RawDescriptionHelpFormatter)
parser.add_argument('processor_root', metavar = 'PROC_ROOT',
                    type=str,
                    help='folder with processor signal configuration files')
parser.add_argument('--copyright', action='store_true',
                    help='Enable default NXP copyright')
parser.add_argument('--soc-output', metavar = 'BOARD_OUT', type=str,
                    help='Output path for soc level dtsi files')

args = parser.parse_args()

if not args.soc_output:
    args.soc_output = "."
elif not pathlib.Path(args.soc_output).is_dir():
    print('SOC output path must be a directory')
    sys.exit(ENOTDIR)

# Attempt to locate the signal XML files we will generate from
proc_root = pathlib.Path(args.processor_root) / 'ksdk2_0'
if not proc_root.exists():
    print(f"Error: Path {args.processor_root} provided for processor root is invalid")
    sys.exit(EINVAL)
# Iterate through all processor package signal.xml files
for package_root in proc_root.iterdir():
    signal_path = package_root / 'signal_configuration.xml'
    # Check if this is a processor package folder
    if signal_path.exists():
        # Generate SOC DTSI file
        if args.copyright:
            # Add default copyright
            COPYRIGHT = (f"Copyright (c) {datetime.datetime.today().year}, NXP\n"
            f" * SPDX-License-Identifier: Apache-2.0")
        else:
            COPYRIGHT = ""
        util = imx_cfg_utils.NXPSdkUtil(str(package_root), copyright_header= COPYRIGHT)
        out_path = f"{args.soc_output.rstrip('/')}/{util.get_part_num().lower()}-pinctrl.dtsi"
        util.write_pinctrl_defs(out_path)
        print(f"Wrote SOC DTSI file to {out_path}")
 