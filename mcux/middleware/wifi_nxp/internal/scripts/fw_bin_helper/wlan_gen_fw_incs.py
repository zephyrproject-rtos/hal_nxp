# import OS module

import os
import argparse
import codecs
import gzip
import io

base_path = os.getcwd()

src_path = base_path + "/wifi_bt_firmware/fw_bins"

dest_path = base_path + "/wifi_bt_firmware"

def get_nice_string(list_or_iterator):
    return ", ".join( "0x" + str(x) for x in list_or_iterator)

def make_hex(chunk, outfp):
    hexdata = codecs.encode(chunk, 'hex').decode("utf-8")
    hexlist = map(''.join, zip(*[iter(hexdata)]*2))
    outfp.write(get_nice_string(hexlist) + ',')

for d in os.listdir(src_path):

    for f in os.listdir(src_path+"/"+d):

        if '.bin' in f:

            # Prints only text file present in My Folder

            print("Convert: "+src_path+"/"+d+"/"+f+" => "+dest_path+"/"+d+"/"+f+".inc")

            outfp = open(dest_path+"/"+d+"/"+f+".inc", "w")

            with open(src_path+"/"+d+"/"+f, "rb") as fp:
                for chunk in iter(lambda: fp.read(8), b''):
                    make_hex(chunk, outfp)

