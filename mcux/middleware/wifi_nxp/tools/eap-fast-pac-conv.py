#!/usr/bin/python
#
# This file provides the support for EAP FAST pac binary data creation
# using pac file
#
# Copyright 2023-2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

import os
import sys
import argparse

continue_loop = True
pac_file = None
out_file = None

def main():

    parser = argparse.ArgumentParser(description='EAP FAST PAC convertor')
    parser.add_argument('--pac',
                        help='summary file for writing status updates')
    parser.add_argument('--out',
                        help='success file for writing success update')
    args = parser.parse_args()

    if args.pac:
        global pac_file
        pac_file = args.pac

    if args.out:
        global out_file
        out_file = args.out

    h = open(out_file, "w")
    h.write("const unsigned char pac_data[] = {\n")

    count = 0
    eap_fast_pac_magic=[" 0x6a,", " 0xe4,", " 0x92,", " 0x0c,\n"]
    h.writelines(eap_fast_pac_magic)
    count += 4

    eap_fast_pac_ver=[" 0x00,", " 0x00,\n"]
    h.writelines(eap_fast_pac_ver)
    count += 2

    idx = 0
    f=open(pac_file)
    for line in f:
        x = line.find("PAC-Type")
        if x != -1:
            pt = 0
            pk = 0
            po = 0
            pi = 0
            l = line.rsplit("=")
            h.write(" 0x00, ")
            h2 = "0x{:02x}".format(int(l[1].rstrip(), 16))
            h.write(h2+", \n")
            count += 2
            pt = 1
            idx += 1
        x = line.find("PAC-Key")
        if x != -1:
            l = line.rsplit("=")
            data = l[1]
            for x in range(0, len(data) - 1, 2):
                h2 = "0x{:02x}".format(int(data[x:x+2], 16))
                h.write(" "+h2+", ")
                count += 1
            h.write("\n")
            pk = 1
        x = line.find("PAC-Opaque")
        if x != -1:
            l = line.rsplit("=")
            data = l[1]
            h1 = hex(int((len(data) - 1)/2))
            h.write(" 0x00, "+h1+",\n")
            count += 2
            for x in range(0, len(data) -1, 2):
                h2 = "0x{:02x}".format(int(data[x:x+2], 16))
                h.write(" "+h2+", ")
                count += 1
            h.write("\n")
            po = 1
        x = line.find("PAC-Info")
        if x != -1:
            l = line.rsplit("=")
            data = l[1]
            h1 = hex(int((len(data) - 1)/2))
            h.write(" 0x00, "+h1+",\n")
            count += 2
            for x in range(0, len(data) -1, 2):
                h2 = "0x{:02x}".format(int(data[x:x+2], 16))
                h.write(" "+h2+", ")
                count += 1
            h.write("\n")
            pi = 1

        x = line.find("END")
        if x != -1:
            if pt == 0:
                sys.stderr.write('Entry '+str(idx)+': PAC-Type is not provided\n')
                quit()
            if pk == 0:
                sys.stderr.write('Entry '+str(idx)+': PAC-Key is not provided\n')
                quit()
            if po == 0:
                sys.stderr.write('Entry '+str(idx)+': PAC-Opaque is not provided\n')
                quit()
            if pi == 0:
                sys.stderr.write('Entry '+str(idx)+': PAC-Info is not provided\n')
                quit()

    h.write("};\n")
    h.write("\n")

    h.write("unsigned int pac_data_len = "+str(count)+";")
    f.close()
        
    raise SystemExit

if __name__ == '__main__':
    main()
