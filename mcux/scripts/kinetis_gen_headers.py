#!/usr/bin/env python3
#
# Copyright (c) 2022, NXP
#
# SPDX-License-Identifier: Apache-2.0

"""
Wrapper around kinetis_signal2dts.py to provide arguments
"""

import datetime
import argparse
from errno import EINVAL, ENOTDIR
import pathlib
import sys

import kinetis_cfg_utils

HELPSTR = """
Processes NXP Kinetis signal configuration files and outputs kinetis pinctrl
headers. Only supports Kinetis parts.
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

parser.add_argument('--processor-root', metavar = 'PROC_ROOT', type=str,
                    help='Path to root of processor directory with package defintions')
parser.add_argument('--copyright', action='store_true',
                    help='Enable default NXP copyright')
parser.add_argument('--soc-output', metavar = 'SOC_OUT', type=str,
                    help='Output folder for soc level header files')

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
for directory in proc_root.iterdir():
    signal_path = directory / 'signal_configuration.xml'
    if signal_path.exists():
        if args.copyright:
            # Add default copyright
            copyright_txt = (f"Copyright (c) {datetime.datetime.today().year}, NXP\n"
            f" * SPDX-License-Identifier: Apache-2.0")
            util = kinetis_cfg_utils.NXPSdkUtil(str(signal_path), copyright_header= copyright_txt)
        else:
            util = kinetis_cfg_utils.NXPSdkUtil(str(signal_path))
        out_path = f"{args.soc_output}/{util.get_part_num().upper()}-pinctrl.h"
        util.write_pinctrl_defs(out_path)
        print(f"Wrote pinctrl header defs to {out_path}")
