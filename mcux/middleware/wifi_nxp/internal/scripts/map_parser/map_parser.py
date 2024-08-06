#!/usr/bin/python
# -*- coding: UTF-8 -*-

from posixpath import split
import sys
import os
import datetime
import json
import re
try:
    import pandas as pd
except ModuleNotFoundError:
    print("NOTE: no module named 'pandas', but you can ignore it.")
    print("If you installed pandas: \n"
          "  get output files: xxx.txt, xxx.xlsx \n"
          "No pandas installed: \n"
          "  get output files: xxx.txt\n")

class Logger(object):
    def __init__(self, file_path: str = "./log.txt"):
        self.terminal = sys.stdout
        self.log = open(file_path, "a", encoding="utf-8")

    def write(self, message):
        self.terminal.write(message)
        self.log.write(message)

    def flush(self):
        pass

class Config(object):
    def __init__(self, file_name):
        self.file_name = file_name
        with open(self.file_name,'r',encoding='UTF-8') as file:
            self.conf = json.load(file)

    def load(self, name):
        self.conf_tu = tuple(self.conf.get(name))
        return self.conf_tu

    def val(self, name):
        self.conf_val = self.conf.get(name)
        return self.conf_val

# class map
class Map(object):
    """ Count the size of the .text/.data/.bss ... segment in the .map file. """

    def __init__(self, file_name):
        self.file_name = file_name
        self.output_path = ''
        self.file_string = ''
        self.fill_size = 0

        # "*fill*" numbers
        self.no_i = 0

    def StartMap(self, args):
        "Map parsing starts"

        for i in range(len(args)):
            # args = [sram, flash]
            args_dict = args[i]
            type = args_dict.get("type")
            self.section = args_dict.get("section")
            self.component = args_dict.get("component")
            self.component_path = args_dict.get("component_path")

            if type == "sram":
                self.ram_func_section = args_dict.get("ram_func_section")
                self.ram_func_file = args_dict.get("ram_func_file")
                self.sram_symbol = args_dict.get("sram_symbol")
                self.ram_func_symbol = args_dict.get("ram_func_symbol")

                self.ram_func = []
                self.list_sets_ram_func = []
                self.component_symbol_dict_ram_func = {}

                self.ram_func_ble_lib = ["libethermind_ble_lc3_ndsp_common.a", "libethermind_ble_lc3_ndsp_decoder.a", "libethermind_ble_lc3_ndsp_encoder.a"]
            elif type == "flash":
                self.flash_symbol = args_dict.get("flash_symbol")
                self.fw_image_size = 0

            # section symbol
            self.section_symbol_dict = {}
            self.section_symbol_start_list = []
            self.section_symbol_end_list = []
            # breakdown component
            self.component_symbol_dict = {}

            self.list_sets = []
            self.is_heap_stack = []

            # start process...
            self.process(type)

    def process(self, type):

        self.section_symbol(type)
        # create a list set to store each component results
        self.component_symbol(type)
        # load .map file, parsing .map
        self.load_file(type)
        # get output path
        self.get_outpath(type)
        # print each component
        self.show_size(type)

        # print("Saving file...")
        print("Output path: %s \r" % self.output_path)

        for index in range(len(self.component)):
            self.save_txt(self.component[index], self.component_symbol_dict.get(
                self.component[index]))
            try:
                self.save_xls(self.component[index], self.component_symbol_dict.get(
                    self.component[index]))
            except NameError:
                print("[Error]: can not save xls file!")
                # print("- %-20s" % (self.component[index] + ".txt"))
            else:
                pass
                # print("- %-20s" % (self.component[index] + ".txt"),
                #       " %s\r" % (self.component[index] + ".xlsx"))

        if type == "sram":
            self.save_txt("ram_func", self.ram_func)
            try:
                self.save_xls("ram_func", self.ram_func)
            except NameError:
                print("[Error]: can not save xls file!")
                # print("- %-20s" % ("ram_func.txt"))
            else:
                pass
                # print("- %-20s" % ("ram_func.txt"),
                #       " %s\r" % ("ram_func.xlsx"))
        print("\n<<<< RUN SUCCESS!\r\n")


    def section_symbol(self, type):
        "section symbol"

        if len(self.section) <= 0:
            print("[Error]: section tuple is empty!")

        self.section_symbol_start_list = []
        self.section_symbol_end_list = []

        if type == "sram":
            # sram check region
            self.section_symbol_start_list.append(self.sram_symbol[0])
            self.section_symbol_end_list.append(self.sram_symbol[1])
            self.section_symbol_start_list.append(self.ram_func_symbol[0])
            self.section_symbol_end_list.append(self.ram_func_symbol[1])

            if ".heap" in self.section:
                self.is_heap_stack.append(".heap")
            if ".stack" in self.section:
                self.is_heap_stack.append(".stack")
        elif type == "flash":
            # flash check region
            self.section_symbol_start_list.append(self.flash_symbol[0])
            self.section_symbol_end_list.append(self.flash_symbol[1])
        else:
            print("[Error]: invalid section type!")


    def component_symbol(self, type):
        if len(self.component) <= 0:
            print("[Error]: component list is empty!")

        # create a list and set the size according to the components
        self.list_sets = [[] for _ in range(len(self.component))]
        # create dict, e.g. {"wifi driver", []}
        self.component_symbol_dict = dict(zip(self.component, self.list_sets))

        if type == "sram":
            # same as component
            self.list_sets_ram_func = [[] for _ in range(len(self.component))]
            # ram function, {"ram func", []}
            self.component_symbol_dict_ram_func = dict(
                zip(self.component, self.list_sets_ram_func))


    def load_file(self, type):
        "load .map file"

        self.fill_size = 0
        count = 0
        flag_find = 0

        with open(self.file_name, mode='r', encoding='utf-8') as file:
            print(">>>> loading file: %s\n" % (self.file_name))
            for line in file:
                count += 1
                # remove leading and trailing spaces, and split string with spaces
                curLine = line.strip().split()
                # if current line is NULL
                if curLine == []:
                    continue

                if type == "sram":
                    # sram usage
                    if (len(curLine) > 1) and (curLine[1] in self.section_symbol_start_list):
                        # section start flag
                        flag_find = flag_find + 1
                        continue
                    elif (len(curLine) > 1) and (curLine[1] in self.section_symbol_end_list):
                        # section end flag
                        flag_find = flag_find - 1
                        continue
                    elif curLine[0] in self.is_heap_stack:
                        if (self.hex2dec(curLine[1]) == 0) or (curLine[2] == "0x30000"):
                            # .heap section
                            # .heap address = 0x000000
                            continue
                        if (curLine[0] == '.heap') and (curLine[3] == 'load'):
                            # ucheap exists in coex app, confirm "load" to avoid double calculation
                            # find .heap, store it to the "other" component
                            self.component_symbol_dict.get("other").append(curLine[0:4])
                        elif curLine[0] == '.stack':
                            # find .stack, store it to the "other" component
                            self.component_symbol_dict.get("other").append(curLine[0:4])
                        continue
                    elif (curLine[0] == ".wlan_data") and (len(curLine) <= 4):
                        # Redfinch is not specified in the linker file to be placed in .data,
                        # so it cannot be calculated within the flag interval.
                        self.line_storage(file, curLine, type)
                        continue
                    elif flag_find == 0:
                        continue

                    if (curLine[0] == "*fill*"):
                        # find "*fill*" string
                        self.no_i += 1
                        # calculate size
                        if self.hex2dec(curLine[2]) < 1024:
                            # fix bug: .heap and .stack fill size
                            self.fill_size += self.hex2dec(curLine[2])
                            # print("type: %s, no. %d, %s"% (type, self.no_i, curLine))
                        else:
                            # print("[drop] type: %s, no. %d, %s"% (type, self.no_i, curLine))
                            pass

                    if ((curLine[0].startswith(self.section)) or curLine[0].startswith(self.ram_func_section)) and (len(curLine) <= 4):
                        self.line_storage(file, curLine, type)

                    if (curLine[0].endswith('.__stub')):
                      #  .text.OSA_InterruptDisable.__stub
                      #     0x20019320      0x528 linker stubs
                      self.line_storage(file, curLine, type)
                else:
                    # flash usage
                    if (len(curLine) > 1) and (curLine[1] in self.section_symbol_start_list):
                        # section start flag
                        flag_find = flag_find + 1
                        continue
                    elif (len(curLine) > 1) and (curLine[1] in self.section_symbol_end_list):
                        # section end flag
                        flag_find = flag_find - 1
                        continue
                    elif flag_find == 0:
                        continue

                    if ((curLine[0] == "*fill*")):
                        # find "*fill*" string
                        self.no_i += 1
                        # print("type: %s, no. %d, %s"% (type, self.no_i, curLine))
                        self.fill_size += self.hex2dec(curLine[2])

                    if (curLine[0].startswith(self.section)) and (len(curLine) <= 4):
                        self.line_storage(file, curLine, type)

                    if (curLine[0].endswith('.__stub')):
                      self.line_storage(file, curLine, type)

                if (len(curLine) >= 2) and ((curLine[1] == "__StackTop") or (curLine[1] == "__etext")):
                    # end parsing
                    return

        # print("Total parsing: %d lines\n" % (count))


    def line_storage(self, file, curLine, type):
        "store one line to component list sets, first check"

        if len(curLine) < 4:
            # Sometimes the length of curLine is too long,
            # the map file will split it into two lines.
            # e.g.    .text.ap_handle_timer
            #               0x000000003007b114      0x3d4 CMakeFiles/wifi_wpa_supplicant_cm7...
            nextLine = file.readline().strip().split()
            if nextLine[0][0:2] == "0x":
                # concat two lines
                curLine.extend(nextLine)
            else:
              # error case:
              # .text.tcp_rst   0x600726f8       0x38
              #   .text.tcp_rst  0x600726f8       0x38 CMakeFiles/wifi_cli.elf.dir/Bitbucket/Firecrest/mcu-sdk-2.0/middleware/lwip/src/core/tcp_out.c.obj
              #                   0x600726f8                tcp_rst
              if nextLine[0] == curLine[0]:
                self.line_storage(file, nextLine, type)
        if (curLine[0].endswith('.__stub')):
          self.split_to_each_component(
              self.component, self.component_path, self.component_symbol_dict, curLine)
        # check the length of current line
        if (len(curLine) != 4) or (self.hex2dec(curLine[1]) == 0):
            #Address: 0x000000
            return
        if (type == "sram") and (curLine[0].startswith(self.ram_func_section)):
            # sram, ram_func section
            if (curLine[3].endswith(self.ram_func_file)) or (re.search(r'libethermind_ble_lc3_ndsp_*.a', curLine[3], re.M|re.I)): #any(field in curLine[3] for filed in self.ram_func_ble_lib)
                self.ram_func.append(curLine[0:4])
                self.split_to_each_component(
                    self.component, self.component_path, self.component_symbol_dict_ram_func, curLine)

        if (type == "flash") and (curLine[0] == ".rodata.wlan_fw_bin"):
            self.fw_image_size = self.fw_image_size + self.hex2dec(curLine[2])

        self.split_to_each_component(
            self.component, self.component_path, self.component_symbol_dict, curLine)


    def split_to_each_component(self, component, component_path, component_symbol_dict, curLine):
        "sub-string matched"

        for i in range(len(component_path)):
            flag_other = False # flag for 'other' component, no matched component
            try:
                if component_path[i] in curLine[3]:
                    # e.g. component_path = "middleware/wifidriver"
                    component_symbol_dict.get(component[i]).append(curLine[0:4])
                    flag_other = True
                    break
            except IndexError:
                print(curLine)
                break
        if flag_other == False:
            # 'other' component
            component_symbol_dict.get(component[-1]).append(curLine[0:4])

    def get_file_string(self):
        self.file_string = os.path.basename(self.file_name).split(".")[0]
        # print(self.file_string)

    def hex2dec(self, hex_val):
        dec_val = int(hex_val, 16)
        return dec_val

    def count_size(self, lists):
        total_size = 0
        for item_l in lists:
            total_size += self.hex2dec(item_l[2])
        return total_size

    def show_size(self, type):
        component_symbol_size = []
        total_size = 0
        total_size_qacode = 0

        print("========= Total Size: %s ========\r" % type)
        print("  %-15s\t%s\t\t%s\t%s" %
                  ("component", "size", "ram_func size", "size(w/o qacode)"))

        for i in range(len(self.component)):
            temp_size = self.count_size(
                self.component_symbol_dict.get(self.component[i]))

            if self.component[i] == "other":
                temp_size += self.fill_size

            if type == "sram":
                ram_func_size = self.count_size(
                    self.component_symbol_dict_ram_func.get(self.component[i]))
                print("- %-15s\t%.1fk\t\t%.1fk\t\t%.1fk" %
                    (self.component[i], temp_size/1024.0, ram_func_size/1024.0, (temp_size-ram_func_size)/1024.0))
            else:
                print("- %-15s\t%.1fk" %
                    (self.component[i], temp_size/1024.0))

            component_symbol_size.append(temp_size)
            total_size += temp_size


        if type == "sram":
            total_size_qacode += self.count_size(self.ram_func)
            print("- %-15s\t\t\t\t\t%.1fk"%
                  ("ram function", total_size_qacode/1024.0))
        elif type == "flash":
            print("- %-15s\t%.1fk" %
                    ("FW image", self.fw_image_size/1024.0))

        print("\r--------- fill size: %.1fk (%d)-------\r" % ((self.fill_size)/1024.0, self.fill_size))
        print("\r\n===== End: size: %.1fk (%d)=====\r\n" %
            ((total_size + self.fill_size)/1024.0, total_size))


    def get_outpath(self, type):
        self.get_file_string()

        invocation_time = datetime.datetime.now()
        self.output_path = os.getcwd() + '\\output\\' + self.file_string + '\\' + \
            f"{invocation_time.strftime('%Y-%m-%d-%H-%M-%S')}" + \
            "_" + type + '\\'

        if not os.path.exists(self.output_path):
            try:
                os.makedirs(self.output_path)
            except FileNotFoundError:
                self.output_path = os.getcwd() + '/output/' + self.file_string + '/' + \
                    f"{invocation_time.strftime('%Y-%m-%d-%H-%M-%S')}" + \
                    "_" + type + '/'
                os.makedirs(self.output_path)
            # print(self.output_path)

        log_file = self.output_path + 'optimization.txt'
        sys.stdout = Logger(log_file)

    def save_txt(self, file_name, lists):
        file_name += ".txt"
        out_file = self.output_path + file_name
        with open(out_file, 'w') as file:
            for l in lists:
                file.write(str(l) + '\n')

    def save_xls(self, file_name, lists):
        file_name += ".xlsx"
        out_file = self.output_path + file_name
        # convert list to dataframe
        df = pd.DataFrame(
            lists, columns=['Section', 'Address', 'Size', 'Object'])
        # save as excel
        df.to_excel(out_file, index=False)


if __name__ == "__main__":
    # NOTE Info
    print("[NOTE]: only support to .map files generated by arm-gcc!")
    print("Please choose a board:")
    print(" 1 - Redfinch")
    print(" 2 - Firecrest")
    print(" 3 - IW416")
    print(" 4 - Matter")
    board_type = input("Enter number:")
    print("Choice: ", board_type)

    print("Do you want the size of wifi to be more granular? [y/n]")
    breakdown_mode = input("Enter char:")
    print("Choice: ", breakdown_mode)

    # Supported linker files:
    # - MIMXRT1176xxxxx_cm7_flexspi_nor.ld
    # - MIMXRT1062xxxxx_flexspi_nor.ld
    # - RW610_flash.ld

    map_conf = Config("map_conf.json")

    if int(board_type) >= 1 and int(board_type) <=3:
        if breakdown_mode == 'y':
            # Parts that need to be broken down
            component = map_conf.load("component_y")
            component_path = map_conf.load("component_path_y")
        else:
            # wifi, ble, ot
            component = map_conf.load("component_n")
            component_path = map_conf.load("component_path_n")
        ram_func_file = map_conf.load("ram_func_file")
    elif board_type == '4':
        # wifi, ble, ot, matter
        component = map_conf.load("component_matter")
        component_path = map_conf.load("component_path_matter")
        ram_func_file = map_conf.load("ram_func_file_matter")
    else:
        print("Error: invalid board!")

    # SRAM dict
    args_dict_sram = {
        'type': "sram",
        # sram section (start: __DATA_ROM, end: __StackTop)
        'section': map_conf.load("section_sram"),
        'component': component,
        'component_path' : component_path,
        # qacode/ram_function
        'ram_func_section': map_conf.load("ram_func_section"),
        'ram_func_file':  ram_func_file,
        # m_data/ram_func symbol
        "sram_symbol": ["__DATA_ROM", "__StackTop"],
        "ram_func_symbol": ["__ram_function_start__", "__ram_function_end__"]
    }

    # FLASH dict
    section_flash_conf = map_conf.load("section_flash")
    # if int(board_type) == 1:
    #     section_flash_conf = section_flash_conf + (".flash_conf", )

    args_dict_flash = {
        "type": "flash",
        # flash section (start: __FLASH_BASE, end: __etext)
        'section': section_flash_conf,
        'component': component,
        'component_path' : component_path,
        # m_text symbol
        "flash_symbol": ["__FLASH_BASE", "__etext"]
    }

    input_args = [args_dict_sram, args_dict_flash]

    # Parsing
    try:
        if (map_conf.val("default_map")):
            file_name = map_conf.val("default_map")
        else:
            file_name = str(sys.argv[1])
    except IndexError:
        print("Failed: need to specify a map file!\r\n")
        print("Usage:\r")
        print("      python map_parser.py <map file>\r\n")
        sys.exit(1)
    else:
        map = Map(file_name)
        map.StartMap(input_args)
        if (map_conf.val("exit") == 0):
            os.system("pause")
