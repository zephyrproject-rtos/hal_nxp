# Copyright (c) 2021, Linaro Limited.
# Copyright (c) 2022, NXP
#
# SPDX-License-Identifier: Apache-2.0

"""
Implements a configuration file parser for kinetis MCUs, which can generate
pinctrl definitions for Zephyr
"""

import xml.etree.ElementTree as ET
import re
import os
import collections
import logging

# layout/index of pins tuple
PIN = collections.namedtuple('PIN', ['PERIPH', 'NAME_PART', 'SIGNAL', 'PORT',
                                     'PIN', 'CH', 'MUX_FUNC'])

NAMESPACES = {'mex': 'http://mcuxpresso.nxp.com/XSD/mex_configuration_10'}

class MUXOption:
    """
    Internal class representing a mux option on the SOC
    """
    def __init__(self, connection):
        """
        Initializes a mux option
        @param connection XML connection option from signal_configuration.xml
        """
        self._name = connection.attrib.get('name_part')
        logging.debug("\t\t %s", self._name)
        if self._name is None:
            self._name = ''
            return
        # Get MUX settings
        self._port = None
        for periph in connection.iter('peripheral_signal_ref'):
            self._periph = periph.attrib.get('peripheral')
            self._signal = periph.attrib.get('signal')
            self._channel = periph.attrib.get('channel')
        for assign in connection.iter('assign'):
            reg = assign.attrib.get('register')
            val = assign.attrib.get('bit_field_value')
            logging.debug('\t\t\t [ASSIGN] %s %s', reg, val)
            # Only process PCR registers
            match = re.match(r'PORT([A-Z])_PCR(\d+)', reg)
            if match:
                # For muxes like PTC5, do not append peripheral name
                if re.match(r'PT[A-Z]\d+', self._name) is None:
                    self._name += f"_PT{match.group(1)}{match.group(2)}"
                self._port = match.group(1)
                self._pin = int(match.group(2))
                self._mux = int(val, 16)
        if self._port is None:
            # Not a valid port mapping. Clear name
            self._name = ''

    def __repr__(self):
        """
        String representation of object
        """
        return "MUXOption(%s)" % (self._name)

    def get_name(self):
        """
        Get mux option name
        """
        return self._name

    def get_mux_name(self):
        """
        Get name of the mux option, without pin name
        """
        if self._channel:
            return f"{self._periph}_{self._signal}, {self._channel}"
        return f"{self._periph}_{self._signal}"

    def get_port(self):
        """
        Get mux port
        """
        return self._port

    def get_signal(self):
        """
        Get mux signal name
        """
        return self._signal

    def get_pin(self):
        """
        Get mux pin
        """
        return self._pin

    def get_mux(self):
        """
        Get mux register write value
        """
        return self._mux

    def get_periph(self):
        """
        Get peripheral name
        """
        return self._periph

    def get_channel(self):
        """
        Get channel number
        """
        return self._channel

    def __hash__(self):
        """
        Override hash method to return pin name as hash
        """
        return hash(self._name)

    def __eq__(self, obj):
        """
        Like the hash method, we override the eq method to return true if two
        objects have the same pin name
        """
        return isinstance(obj, SignalPin) and self._name == obj._name

    def __lt__(self, obj):
        """
        Compare objects based on name
        """
        if not isinstance(obj, SignalPin):
            return True
        return self._name < obj._name


class SignalPin:
    """
    Internal class representing a signal on the SOC
    """
    def __init__(self, pin):
        """
        Initializes a SignalPin object
        @param pin: pin XML object from signal_configuration.xml
        """
        # Kinetis pin names are formatted as [PT[Port][Pin]]
        pin_regex = re.search(r'PT([A-Z])(\d+)', pin.attrib['name'])
        if pin_regex is None:
            logging.debug('Could not match pin name %s', pin.attrib['name'])
            self._name = ''
            return
        self._name = pin.attrib['name']
        self._port = pin_regex.group(1)
        self._pin = pin_regex.group(2)
        self._properties = self._get_pin_properties(pin.find('functional_properties'))
        self._mux_options = {}
        for connections in pin.findall('connections'):
            mux_opt = MUXOption(connections)
            # Only append mux options with a valid name
            if mux_opt.get_name() != '':
                self._mux_options[mux_opt.get_mux_name()] = mux_opt

    def __repr__(self):
        """
        String representation of object
        """
        return "SignalPin(%s)" % (self._name)

    def __hash__(self):
        """
        Override hash method to return pin name as hash
        """
        return hash(self._name)

    def __eq__(self, obj):
        """
        Like the hash method, we override the eq method to return true if two
        objects have the same pin name
        """
        return isinstance(obj, SignalPin) and self._name == obj._name

    def __lt__(self, obj):
        """
        Compare objects based on name
        """
        if not isinstance(obj, SignalPin):
            return True
        return self._name < obj._name

    def get_name(self):
        """
        Get name of pin
        """
        return self._name

    def get_port(self):
        """
        Get PORT this signal is defined for
        """
        return self._port

    def get_pin(self):
        """
        Get pin this signal is defined for
        """
        return self._pin

    def get_mux_connection(self, signal):
        """
        Gets an MUXOption object for the relevant signal name
        @param signal: Signal name on pin to get mux option for
        """
        if signal in self._mux_options:
            return self._mux_options[signal]
        return None

    def get_mux_options(self):
        """
        Gets all unique settings for IOMUX on the specific pin
        """
        return set(self._mux_options.values())

    def get_pin_properties(self):
        """
        Gets array of pin property names
        """
        return self._properties.keys()

    def get_pin_property_default(self, prop):
        """
        Gets name of default pin property
        @param prop: name of pin property
        """
        return self._properties[prop]['default']

    def get_pin_defaults(self):
        """
        Gets mapping of all pin property names to default value names
        """
        pin_defaults = {}
        for prop in self.get_pin_properties():
            pin_default = self.get_pin_property_default(prop)
            pin_defaults[prop] = pin_default
        return pin_defaults

    def get_pin_property_value(self, prop, selection):
        """
        Gets bit value for pin property
        @param prop: name of pin property
        @param selection: name of option selected for property
        """
        return self._properties[prop][selection]

    def _get_pin_properties(self, props):
        """
        Builds dictionary with all pin properties
        @param props: pin function_properties XML object in signal_configuration.xml
        """
        prop_mapping = {}
        for prop in props.findall('functional_property'):
            prop_id = prop.attrib['id']
            if not 'default' in prop.attrib:
                # No default property. Skip
                continue
            prop_mapping[prop_id] = {}
            prop_mapping[prop_id]['default'] = prop.attrib['default']
            for state in prop.findall('state'):
                reg_assign = state.find('configuration/assign')
                if reg_assign:
                    bit_value = int(reg_assign.attrib['bit_field_value'], 0)
                else:
                    # Assume writing zero to register will select default
                    bit_value = 0
                prop_mapping[prop_id][state.attrib['id']] = bit_value
        return prop_mapping

class PinGroup:
    """
    Internal class representing pin group
    """
    def __init__(self, function, signal_map):
        """
        Creates a pin group
        @param function: function xml structure from MEX configuration file
        @param signal_map: Signal mapping, maps signal names to signal pins
        """
        self._name = function.attrib.get('name')
        pins = function.find('mex:pins', NAMESPACES)
        description = function.find('mex:description', NAMESPACES)
        if description is not None and description.text is not None:
            self._description = description.text
        else:
            self._description = ""
        # Build dictionary mapping pin properties to pins. This allows us to
        # group pins based on shared configuration
        self._pin_groups = collections.defaultdict(lambda: [])
        for pin in pins:
            # find signal defintion for this pin
            signal_name = pin.attrib.get('pin_signal')
            signal = signal_map[signal_name]
            if not signal:
                logging.warning('Signal name %s not present in mapping', signal_name)
                # No way to find mux option
                continue
            # Get mux option for this signal
            mux_option = f"{pin.attrib.get('peripheral')}_{pin.attrib.get('signal')}"
            mux = signal.get_mux_connection(mux_option)
            if mux is None:
                logging.warning('Signal name %s has no mux', mux_option)
                # Do not add pinmux option to group
                continue
            # Get pin defaults for this pin
            defaults = signal.get_pin_defaults()
            # Get pin overrides
            features = pin.find('mex:pin_features', NAMESPACES)
            pin_overrides = {}
            if features is not None:
                for feature in pin.find('mex:pin_features', NAMESPACES):
                    pin_overrides[feature.attrib.get('name')] = feature.attrib.get('value')
            pin_props = self._props_to_dts(pin_overrides, defaults)
            self._pin_groups[pin_props].append(mux)

    def __repr__(self):
        """
        Get string representation of the object
        """
        return "PinGroup(%s)" % (self._name)
    
    def __eq__(self, obj):
        """
        return true if two objects have the same pin group name
        """
        return isinstance(obj, PinGroup) and self._name == obj._name

    def __lt__(self, obj):
        """
        Compare objects based on name
        """
        if not isinstance(obj, PinGroup):
            return True
        return self._name < obj._name

    def get_pin_props(self):
        """
        Get all unique pin properties
        """
        return self._pin_groups.keys()

    def get_pins(self, props):
        """
        Get all pins with a provided set of properties
        @param props: property set
        """
        return self._pin_groups[props]
    
    def get_description(self):
        """
        Get description of the pin group, if present. If no description present,
        description will be ""
        """
        return self._description

    def get_name(self):
        """
        Get pin group name
        """
        return self._name

    def _props_to_dts(self, props, defaults):
        """
        Remap dictionary of property names from NXP defined values to
        Zephyr ones
        @param props: Dictionary of NXP property names and values
        @param defaults: Dictionary of NXP property names and default pin values
        @return array of strings suitable for writing to DTS
        """
        zephyr_props = []
        prop_mapping = {
            'fast': 'fast',
            'slow': 'slow',
            'low': 'low',
            'high': 'high',
        }
        # Lambda to convert property names to zephyr formatted strings
        sanitize = lambda x: "\"" + prop_mapping[x] + "\"" if (x in prop_mapping) else ""
        # Lambda to get property value or fallback on default
        prop_val = lambda x: props[x] if x in props else defaults[x]
        # Check pin defaults and overrides to see if the pin will have a pull
        pull_enable = prop_val('pull_enable') == 'enable'
        # For each property, append the provided override or the default
        zephyr_props.append(f"drive-strength = {sanitize(prop_val('drive_strength'))}")
        if prop_val('open_drain') == 'enable':
            zephyr_props.append('drive-open-drain')
        if pull_enable:
            # If pull is enabled, select pull up or pull down
            if prop_val('pull_select') == 'up':
                zephyr_props.append('bias-pull-up')
            else:
                zephyr_props.append('bias-pull-down')
        zephyr_props.append(f"slew-rate = {sanitize(prop_val('slew_rate'))}")
        if prop_val('passive_filter') == 'enable':
            zephyr_props.append("nxp,passive-filter")
        return tuple(zephyr_props)


class NXPSdkUtil:
    """
    Class for kinetis configuration file parser
    """
    def __init__(self, signal_file, copyright_header = "", log_level = logging.ERROR):
        """
        Initialize SDK utilities.
        Providing a signal file will enable this class to parse MEX files,
        and generate output DTS
        @param signal_file: path to signal_configuration.xml file
        @param copyright_header: copyright string to add to any generated file header
        @param log_level: log level for SDK utility
        """
        # Load the signal XML data

        self._logger = logging.getLogger('')
        self._logger.setLevel(log_level)
        self._parse_signal_xml(signal_file)
        self._copyright = copyright_header
        logging.info("Loaded %d configurable pin defs", len(self._pins))

    def _parse_signal_xml(self, signal_fn):
        """
        Parses signal XML configuration file. Builds a list of pins, which can
        be used to generate soc level DTSI file.
        @param signal_fn: signal_configuration.xml file to parse
        """
        self._pins = {}
        try:
            signal_tree = ET.parse(signal_fn)
        except ET.ParseError:
            logging.error("Could not parse provided signal file: %s", signal_fn)
            return

        signal_root = signal_tree.getroot()

        self._part_num = signal_root.find("./part_information/part_number").get('id')

        logging.info("Loaded XML for %s", self._part_num)

        periphs_node = signal_root.find("peripherals")
        periphs = []
        for pin in periphs_node:
            pin_id = pin.attrib.get("id")
            name = pin.attrib.get("name")

            if pin_id != name:
                logging.warning("id and name don't match")

            periphs.append(pin_id)

        pins_node = signal_root.find("pins")
        for pin in pins_node:
            signal = SignalPin(pin)
            # Only add valid signal pins to list
            if signal.get_name() != '':
                self._pins[signal.get_name()] = signal

    def _write_pins(self, which_port, pins, file):
        """
        Writes all pin mux nodes for a specific pin port to soc pinctrl dtsi
        file.
        @param which_port: pin port to define
        @param pins: list of pin mux options to write
        @param file: output file to write to
        """
        port_pins = list(filter(lambda p: (p.get_port().lower() == which_port), pins))

        if (len(port_pins)) == 0:
            return

        port_pins.sort(key=lambda p: (p.get_pin(), p.get_mux()))

        seen_nodes = []


        for pin_data in port_pins:
            label = pin_data.get_name()
            port = pin_data.get_port()
            pin = pin_data.get_pin()
            mux = pin_data.get_mux()

            if label in seen_nodes:
                continue
            seen_nodes.append(label)

            file.write(f"#define {label} KINETIS_MUX('{port}',{pin},{mux}) /* PT{port}{pin} */\n")

    def get_part_num(self):
        """
        Return the part number this class is instantiated for
        """
        return self._part_num

    def write_pinctrl_defs(self, outputfile):
        """
        Writes all pin mux options into pinctrl DTSI file. Board level pin groups
        can include this pinctrl dtsi file to access pin control defintions.
        @param outputfile: file to write output pinctrl defs to
        """
        # Create list of all pin mux options
        pinmux_opts = []
        for pin in self._pins.values():
            pinmux_opts.extend(pin.get_mux_options())
        pcr_pins = list(filter(lambda p: (p.get_periph() not in ["FB", "EZPORT"]), pinmux_opts))
        file_header = ("/*\n"
            f" * NOTE: Autogenerated file by {os.path.basename(__file__)}\n"
            f" * for {self._part_num}/signal_configuration.xml\n"
            " *\n"
            f" * {self._copyright}\n"
            " */\n"
            "\n")
        
        # Notes on the below macro:
        # Port values range from 'A'-'E', so we store them with 4 bits,
        # with port A being 0, B=1,...
        # Pin values range from 0-31, so we give 6 bits for future expansion
        # Mux values range from 0-8, so we give 3 bits
        # shift the port and pin values to the MSBs of the mux value, so they
        # don't conflict with pin configuration settings
        # Store the mux value at the offset it will actually be written to the
        # configuration register
        mux_macro = ("#define KINETIS_MUX(port, pin, mux)\t\t\\\n"
                "\t(((((port) - 'A') & 0xF) << 28) |\t\\\n"
                "\t(((pin) & 0x3F) << 22) |\t\t\\\n"
                "\t(((mux) & 0x7) << 8))\n\n")
        with open(outputfile, "w", encoding="utf8") as file:
            file.write(file_header)
            # ifdef guard
            file.write(f"#ifndef _ZEPHYR_DTS_BINDING_{self._part_num.upper()}_\n")
            file.write(f"#define _ZEPHYR_DTS_BINDING_{self._part_num.upper()}_\n\n")
            # Write macro to make port name
            file.write(mux_macro)
            self._write_pins('a', pcr_pins, file)
            self._write_pins('b', pcr_pins, file)
            self._write_pins('c', pcr_pins, file)
            self._write_pins('d', pcr_pins, file)
            self._write_pins('e', pcr_pins, file)
            file.write("#endif\n")

    def _parse_mex_cfg(self, mexfile):
        """
        Parses mex configuration into pin groups.
        @param mexfile: mex configuration file to parse
        @return parsed pin groups
        """
        pin_groups = {}
        try:
            mex_xml = ET.parse(mexfile)
            for function in mex_xml.findall(
                'mex:tools/mex:pins/mex:functions_list/mex:function', NAMESPACES):
                group = PinGroup(function, self._pins)
                pin_groups[group.get_name()] = group
            return pin_groups
        except ET.ParseError:
            logging.error("Could not parse mex file %s", mex_xml)
            return None

    def write_pinctrl_groups(self, mexfile, outputfile):
        """
        Write pinctrl groups to disk as a parsed DTS file. Intended for use
        with the output of @ref write_pinctrl_defs
        @param mexfile: mex file to parse
        @param outputfile: DTS pinctrl file to write pin groups to
        """
        file_header = ("/*\n"
            f" * NOTE: Autogenerated file by {os.path.basename(__file__)}\n"
            f" * for {self._part_num}/signal_configuration.xml\n"
            " *\n"
            f" * {self._copyright}\n"
            " */\n"
            "\n")
        pin_groups = self._parse_mex_cfg(mexfile)
        with open(outputfile, "w", encoding="utf8") as file:
            file.write(file_header)
            file.write(f"\n#include <nxp/kinetis/{get_package_name(mexfile)}-pinctrl.h>\n\n")
            file.write("&pinctrl {\n")
            # Write pin groups back out to disk
            for group in sorted(pin_groups.values()):
                pin_props = group.get_pin_props()
                if len(pin_props) == 0:
                    # Do not write to disk
                    continue
                logging.info("Writing pin group %s to disk", group.get_name())
                # Write description as comment if group has one
                if group.get_description() != "":
                    file.write(f"\t/* {group.get_description()} */\n")
                file.write(f"\t{group.get_name().lower()}: {group.get_name().lower()} {{\n")
                idx = 0
                for pin_prop in sorted(pin_props):
                    group_str = f"\t\tgroup{idx} {{\n"
                    # Write all pin names
                    group_str += "\t\t\tpinmux = "
                    for pin in group.get_pins(pin_prop):
                        group_str += f"<{pin.get_name()}>,\n\t\t\t\t"
                    # Strip out last 3 tabs and close pin name list
                    group_str = re.sub(r',\n\t\t\t\t$', ';\n', group_str)
                    idx += 1
                    # Write all pin props
                    for prop in pin_prop:
                        group_str += f"\t\t\t{prop};\n"
                    group_str += "\t\t};\n"
                    file.write(group_str)
                file.write("\t};\n\n")
            file.write("};\n")

"""
Utility functions used to get details about board/processor from MEX file
"""

def get_board_name(mexfile):
    """
    Extracts board name from a mex file
    @param mexfile: mex file to parse for board name
    """
    try:
        config_tree = ET.parse(mexfile)
        return config_tree.getroot().find('mex:common/mex:board',
            NAMESPACES).text
    except ET.ParseError:
        print(f"Malformed XML tree {mexfile}")
        return None
    except IOError:
        print(f"File {mexfile} could not be opened")
        return None

def get_processor_name(mexfile):
    """
    Extracts processor name from a mex file
    @param mexfile: mex file to parse for processor name
    """
    try:
        config_tree = ET.parse(mexfile)
        return config_tree.getroot().find('mex:common/mex:processor',
            NAMESPACES).text
    except ET.ParseError:
        print(f"Malformed XML tree {mexfile}")
        return None
    except IOError:
        print(f"File {mexfile} could not be opened")
        return None

def get_package_name(mexfile):
    """
    Extracts package name from a mex file
    @param mexfile: mex file to parse for package name
    """
    try:
        config_tree = ET.parse(mexfile)
        return config_tree.getroot().find('mex:common/mex:package',
            NAMESPACES).text
    except ET.ParseError:
        print(f"Malformed XML tree {mexfile}")
        return None
    except IOError:
        print(f"File {mexfile} could not be opened")
        return None
