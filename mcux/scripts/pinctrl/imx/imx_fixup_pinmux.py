#!/usr/bin/env python3

import argparse
import tempfile
import re
import os

HELPSTR = """
Fix generated pinctrl defintions
Generated RT11xx pinctrl definitions will be incorrect, because the signal
configuration XML file itself is not correct. Fix them using fsl_iomuxc
definitions.
"""


parser = argparse.ArgumentParser(description=HELPSTR,
        formatter_class=argparse.RawDescriptionHelpFormatter)
parser.add_argument('iomuxc_file', metavar = 'IOMUXC',
                    type=str,
                    help='iomuxc file to use as ground truth')
parser.add_argument('pinctrl_file', metavar = 'pinctrl',
                    type=str,
                    help='pinctrl file to check against iomuxc file')
parser.add_argument('--check', action='store_true',
                    help='do not edit pinctrl file, just check for errors')

args = parser.parse_args()

try:
    iomux_file = open(args.iomuxc_file, 'r', encoding='utf8')
except IOError:
    print(f"Could not open {args.iomuxc_file}")
try:
    pinctrl_file = open(args.pinctrl_file, 'r+', encoding='utf8')
except IOError:
    print(f"Could not open {args.pinctrl_file}")

iomuxc_re = re.compile(r'#define (IOMUXC_[\w_]+)\s+([0x]*[\dA-F]+)[U]*, ([0x]*[\dA-F]+)[U]*,'
    r' ([0x]*[\dA-F]+)[U]*, ([0x]*[\dA-F]+)[U]*, ([0x]*[\dA-F]+)[U]*\n')

pinctrl_line1_re = re.compile(r'\t/omit-if-no-ref/ [\w_]+: ([\w_]+) {\n')
pinctrl_line2_re = re.compile(r'\t\tpinmux = <(0x[\da-f]+) '
    r'(\d+) (0x[\da-f]+) (\d+) (0x[\da-f]+)>;')

ground_truth = {}
while True:
    line = iomux_file.readline()
    if line == '':
        break
    match = iomuxc_re.match(line)
    if match:
        mux_reg = int(match.group(2), 0)
        mux = int(match.group(3), 0)
        daisy_reg = int(match.group(4), 0)
        daisy = int(match.group(5), 0)
        cfg_reg = int(match.group(6), 0)
        if (mux_reg, mux, cfg_reg) in ground_truth:
            raise RuntimeError("Duplicate mux_reg and mux value pairings")
        ground_truth[(mux_reg, mux)] = (match.group(1), daisy_reg, daisy, cfg_reg)

if not args.check:
    tmp = tempfile.TemporaryFile(mode='r+')
while True:
    line = pinctrl_file.readline()
    if line == '':
        break
    if not args.check:
        if line == '&iomuxc {\n':
            # Write a comment before dts defintions
            tmp.write('/*\n'
                f' * NOTE: file fixup performed by {os.path.basename(__file__)}\n'
                " * to correct missing daisy register values\n"
                ' */\n\n')
        # Write back untouched line
        tmp.write(line)
    match = pinctrl_line1_re.match(line)
    if match:
        line = pinctrl_file.readline()
        match2 = pinctrl_line2_re.match(line)
        if match2:
            mux_reg = int(match2.group(1), 0)
            mux = int(match2.group(2), 0)
            daisy_reg = int(match2.group(3), 0)
            daisy = int(match2.group(4), 0)
            cfg_reg = int(match2.group(5), 0)
            name = match.group(1)
            errors = False
            if (mux_reg, mux) in ground_truth:
                mux_truth = ground_truth[(mux_reg, mux)]
                # Get the MUX daisy values
                if mux_truth[1] != daisy_reg:
                    print(f"Bad daisy reg on {name}")
                    errors = True
                if mux_truth[2] != daisy:
                    print(f"Bad daisy value on {name}")
                    errors = True
                if mux_truth[3] != cfg_reg:
                    print(f"Bad cfg value on {name}")
                    errors = True
                if (not args.check) and (errors):
                    # Fix up file
                    new_line = (f"\t\tpinmux = <0x{mux_reg:x} {mux} "
                        f"0x{mux_truth[1]:x} {mux_truth[2]} 0x{mux_truth[3]:x}>;\n")
                    tmp.write(new_line)
                elif not args.check:
                    # Write back untouched line
                    tmp.write(line)
            else:
                print("WARNING: Mux name %s not preset in ground truth" % (name))
                if not args.check:
                    # Write back untouched line
                    tmp.write(line)
if not args.check:
    # Commit operation by writing temp file to real file
    tmp.seek(0)
    pinctrl_file.seek(0)
    while True:
        tmpline = tmp.readline()
        if tmpline == '':
            break
        pinctrl_file.write(tmpline)

iomux_file.close()
pinctrl_file.close()
if not args.check:
    tmp.close()
