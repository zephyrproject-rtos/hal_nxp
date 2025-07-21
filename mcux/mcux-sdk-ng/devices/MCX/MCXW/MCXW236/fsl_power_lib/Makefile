# Compiler
CLANG_ROOT_DIR ?= $(if $(ARMCLANG_DIR),$(ARMCLANG_DIR),/armclang-6.23/bin)

CC    		:= $(CLANG_ROOT_DIR)/armclang
AR    		:= $(CLANG_ROOT_DIR)/armar
ARFLAGS = -rcs

# Includes
INCL_DIR += ../../../../../examples_int/_devices/MCXW236/ \
			../../../../../examples_int/_devices/MCXW236/periph4/ \
			../../../../../drivers/common \
			../../../../../drivers/lpc_gpio \
			../drivers \
			../../../../../arch/arm/CMSIS/Core/Include \
			../../../../../middleware/wireless/snps_ll_private/firmware/shrd_utils/inc \
			../../../../../middleware/wireless/snps_ll_private/firmware/shrd_utils/inc/_40nm_reg_files \
			../../../../../middleware/wireless/snps_ll_private/firmware/shrd_utils/src/porting/nhs \
			../../../../../middleware/wireless/snps_ll_private/firmware/ble_controller/inc \
			../../../../../components/debug_console \
			../../../../../components/serial_manager \
			../../../../../components/uart \

# Compiler flags
CFLAGS = -xc -std=c99 --target=arm-arm-none-eabi -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c \
		 -fno-rtti -mno-unaligned-access -Werror -funsigned-char -fshort-enums -Os -ffunction-sections \
		 -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion \
		 -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command \
		 -Wno-documentation -Wno-license-management -Wno-parentheses-equality -Wno-reserved-identifier \
		 -DMCXW23 -DCPU_MCXW236BIHNAR -DSERIAL_PORT_TYPE_UART=1
CFLAGS += $(addprefix -I, $(INCL_DIR))
CFLAGS_SECURE = $(CFLAGS) -mcmse


# Output library name
LIB_DIR = ../arm
LIBNAME = $(LIB_DIR)/libpower.a
LIBNAME_SECURE = $(LIB_DIR)/libpower_s.a

# Source files and object files
SOURCES = fsl_power_lib.c fsl_system_lib.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_SECURE = $(SOURCES:.c=_secure.o)

# Default target
all: $(LIBNAME) $(LIBNAME_SECURE)

# Rule to create the static library
$(LIBNAME): $(OBJECTS)
	$(AR) $(ARFLAGS)  $@ $^
	rm -f $(OBJECTS)

$(LIBNAME_SECURE): $(OBJECTS_SECURE)
	$(AR) $(ARFLAGS)  $@ $^
	rm -f $(OBJECTS_SECURE)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Compile source files for secure build
%_secure.o: %.c
	$(CC) $(CFLAGS_SECURE) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(OBJECTS_SECURE)

# Phony targets
.PHONY: all clean