# LPC Pin Control Generation Scripts

These scripts aid in the generation of pin control data for LPC platforms, as
well as the RT600 and RT500 series.
The following scripts are provided:

| Script               | Functionality                |
| -------------------- | ---------------------------- |
| `lpc_gen_dts.py`     | Generates pin control dtsi files for boards |
| `lpc_gen_headers.py` | Generates pin control dtsi files defining SOC pinmux settings
| `lpc_cfg_utils.py`   | support library              |

## Requirements

All scripts here utilize files and data sources provided with [MCUXpresso Config
tools v12](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-config-tools-pins-clocks-peripherals:MCUXpresso-Config-Tools).
No other version of MCUXpresso Config tools is supported.
MCUXpresso config tools data sources must be provided to this tool, see below
for documentation on how to download data sources.

## Data Sources
In order to generate board or SOC level pin control definitions, the following
steps must be taken to ensure the MCUXpresso config tools downloads the relevant
data:
 - Create a new configuration in MCUXpresso config tools, targeting your SOC's EVK
 - If board pin control generation is desired, save this configuration with
   appropriate pin settings in each functional group

Data sources will be stored in `C:\ProgramData\NXP\mcu_data_v12` on Windows machines after they are downloaded for a given processor.

## Board Pin Control Generation

To generate pin control files for a board, first generate a board settings file,
also known as a MEX file for the specific board. Populate board level
functional groups with pin control groups. Then, run the following command:

`python ./pinctrl/lpc/lpc_gen_dts.py --cfg-tool-root ${data_source_root} ${path_to_mex_file}`

Replacing `${data_source_root}` and `${path_to_mex_file}` with the paths to
your MCUXpresso config tools data source, and board settings file respectively.

## SOC Pin Control Definition Generation

To generate pin control definitions for a new SOC not presently supported by
Zephyr, first create an empty board settings file (also known as a MEX file) for
the EVK corresponding to your SOC. This will prompt the configuration tools
to download the data sources for your SOC. Now, run the following command:

`python ./pinctrl/lpc/lpc_gen_headers.py ${data_source_root}/${soc_folder}`

Replacing `${data_source_root}` and `${soc_folder}` with the paths to
your MCUXpresso config tools data source, full name of your SOC (as used by
MCUXpresso), respectively.
