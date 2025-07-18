#####################################################################
##     Processor:           MC56F84462VLH
##     Compiler:            CodeWarrior C/C++ for DSP M56800E
##     Reference manual:    Manual version TBD
##     Version:             rev. 0.1, 2021-03-01
##     Build:               b230724
##
##     Abstract:
##         Linker file for the CodeWarrior C/C++ for DSP M56800E
##
##     Copyright 2016 Freescale Semiconductor, Inc.
##     Copyright 2016-2023 NXP
##     SPDX-License-Identifier: BSD-3-Clause
##
##     http:                 www.nxp.com
##     mail:                 support@nxp.com
##
#####################################################################

#####################################################################
##
##  Notes:
##  1. Address and size(length) below are both in unit of WORD(16 bits).
##
##  2. Source codes(reside in Flash) that need to run in RAM can be put into "codesInRam.text" section.
##
##  3. When compiler does NOT support __has_feature(FE_POINTER_MODIFIERS)
##     - .p_NVM here is just used as placeholder, employ the last flash sector by default.
##     - In SDM, if the .p_NVM allocation address in p space is > 64K, data defined in .p_NVM causes linker error.
##     - To use .p_NVM in SDM, it is application's responsibility to allocate proper flash sector(< 64K) to .p_NVM section.
##       One possible .p_NVM usage: locate the .p_NVM from second sector of flash, and assign later flash space for user code,
##       codesInRam.text and .data, depends on real application, and there may be some flash space wasted.
##
##  4. In SDM .x_FlashData could be used only when compiler supports __has_feature(FE_POINTER_MODIFIERS)
##
##  5. In SDM .p_FlexNVM and .x_FlexRAM could be used only when compiler supports __has_feature(FE_POINTER_MODIFIERS)
##
##    ***************************************************************
##              Program_space allocation
##              -------------
##    0x0:
##              vector table
##    0xDD:
##              -------------
##              -------------
##    0x200:
##              flash config field
##    0x207:
##              -------------
##              -------------
##    0x208:
##            > Codes running in Flash
##            > Flash data, namely, ".xflash.data" section
##            > Codes running in RAM, namely, "codesInRam.text" section
##            > Global variables with initial values, namely, ".data" section
##    0xFBFF:
##              -------------
##              -------------
##    0xFC00:
##            > nvm.data section
##    0xFFFF:
##              -------------
##              -------------
##    0x60000:
##            > RAM code, namely, "codesInRam.text" section
##    0x62FFF:
##              -------------
##              -------------
##    0x68000:
##            > flexnvm.text section
##            > flexnvm.data section
##    0x6BFFF:
##              -------------
##    ***************************************************************
##
##              Data_space allocation
##              -------------
##    0x0:
##            > Codes running in RAM, namely, "codesInRam.text" section
##            > .data section
##            > .bss section
##            > none_init.data section
##            > Heap
##            > Stack
##    0x2FFF:
##              -------------
##              -------------
##    0x1E000:
##            > flexram.data section
##    0x1E3FF:
##              -------------
##              -------------
##    0x20000:
##            > Flash data, namely, ".xflash.data" section
##    0x2FFFF:
##              -------------
#####################################################################

FLASH_PARTITION {
  # name : ORIGIN_P = addr, ORIGIN_X = addr, LENGTH = size [> filename]
  FlashImage   : ORIGIN_P = 0x0,     ORIGIN_X = 0x20000, LENGTH = 0x10000 > FlashImage.bin
  # FlashPart1 : ORIGIN_P = 0x0,     ORIGIN_X = 0x20000, LENGTH = 0x10000
  FlashImage   : ORIGIN_P = 0x68000, ORIGIN_X = 0x8000,  LENGTH = 0x4000  > FlexNVMImage.bin
  # FlashPart1 : ORIGIN_P = 0x68000, ORIGIN_X = 0x8000,  LENGTH = 0x4000
}

MEMORY {
  .x_Peripherals (RW): ORIGIN = 0xC000,  LENGTH = 0x0              # I/O registers area for on-chip peripherals

  .p_Interrupts (RWX): ORIGIN = 0x0,     LENGTH = 0xDE             # Interrupt Vector Table
  .p_FCF        (RWX): ORIGIN = 0x200,   LENGTH = 0x8              # Flash Configuration Area

  .p_Code       (RWX): ORIGIN = 0x208,   LENGTH = 0x10000 - 0x208 - 0x400  # XIP(excute in place) code resides in flash
  .x_FlashData   (RX): ORIGIN = AFTER(.p_Code) + 0x20000, LENGTH = 0  # Flash data stored in flash but accessed from x space

  .p_RamCode     (RX): ORIGIN = 0x60000, LENGTH = 0x3000           # RAM mapped into p space, code resides in flash and runs in RAM

  .p_RamData     (RX): ORIGIN = AFTER(.p_RamCode) - 0x60000, LENGTH = 0x3000 + 0x60000 - AFTER(.p_RamCode)  # .data section
  .x_Data        (RW): ORIGIN = AFTER(.p_RamCode) - 0x60000, LENGTH = 0x3000 + 0x60000 - AFTER(.p_RamCode)  # bss, heap, stack ...

  .p_NVM        (RWX): ORIGIN = 0x10000 - 0x400, LENGTH = 0x400    # Use flash last sector as NVM, stored and accessed in p space

  .p_FlexNVM    (RWX): ORIGIN = 0x68000, LENGTH = 0x4000           # FlexNVM in p space
  .x_FlexRAM     (RW): ORIGIN = 0x1E000, LENGTH = 0x400            # FlexRAM in x space
}

KEEP_SECTION { interrupt_vectors.text }
KEEP_SECTION { reserved_FCF.text }
KEEP_SECTION { codesInRam.text }

SECTIONS {
  .Interrupt :
  {
    F_vector_addr = .;
    * (interrupt_vectors.text)  # interrupt vectors
    F_vector_vba_addr = (F_vector_addr >> 4);
  } > .p_Interrupts

  .FCF :
  {
    F_FCF_addr = .;
    * (reserved_FCF.text) #Flash Configuration Field
  } > .p_FCF

  .Code :
  {
    _code_start_addr =.;

    # .text sections
    * (.text)

    * (startup.text)
    * (fp_engine.text)
    * (ll_engine.text)
    * (user.text)
    * (rtlib.text)
    * (.data.pmem)

    * (.const.data.pmem)
    . = ALIGN(2);
    _code_end_addr = .;

  } > .p_Code

  .FlashData : AT(_code_end_addr)
  {
    _xflash_start_addr = .;
    * (.xflash.data)
    . = ALIGN(2);
    _xflash_end_addr = .;
    _xflash_size = _xflash_end_addr - _xflash_start_addr;

    # save address where for the ram code storage in flash
    _RamCode_storage_start_addr = _code_end_addr + _xflash_size;

  } > .x_FlashData

  .RamCode : AT(_RamCode_storage_start_addr)
  {
    # the RamCode sections flashed to pROM

    # save RamCode start address so we can copy it later to xRAM
    _RamCode_start_addr = .;

    # Write 2 WORD here as placeholder to make sure no function, data and variables are placed at x space address 0
    WRITEH(0x5A);
    WRITEH(0xA5);

    #  OBJECT(ARTDIVREC_S16, "runtime 56800E lmm.lib") # this is an example for how to allocate functions in library to RAM
    #  * (rtlib.text) # suggest to put rtlib function into RAM if ISR performance needs to be improved

    * (codesInRam.text)

    # save RamCode end address and size
    . = ALIGN(2);
    _RamCode_end_addr = .;
    _RamCode_size = _RamCode_end_addr - _RamCode_start_addr;

    # save address where for the ram data storage in flash
    _RamData_storage_start_addr = _RamCode_storage_start_addr + _RamCode_size;
  } > .p_RamCode

  .RamData : AT(_RamData_storage_start_addr)
  {
    # the RamData sections flashed to pROM

    # save RamData start address so we can copy it later to xRAM
    _RamData_start_addr = .;

    # .data sections
    * (.const.data.char)  # used if "Emit Separate Char Data Section" enabled
    * (.const.data)
    * (fp_state.data)
    * (rtlib.data)
    * (.data.char)        # used if "Emit Separate Char Data Section" enabled
    * (.data)

    # save RamData end and size
    . = ALIGN(2);
    _RamData_end_addr = .;
    _RamData_size = _RamData_end_addr - _RamData_start_addr;
  } > .p_RamData

  .NVM :
  {
    F_NVM_start_addr = .;

    * (nvm.data)
    . = ALIGN(4);

    F_NVM_end_addr = .;
  } > .p_NVM

  .FlexNVM :
  {
    # Note:
    #   - If FlexNVM is configured as EEPROM, ORIGIN and LENGTH of .p_FlexNVM also need to adjust accordingly.
    #   - Code and data put into .p_FlexNVM access speed are limited, due to there is no cache for FlexNVM.

    F_FlexNVM_code_start_addr = .;
    * (flexnvm.text)
    . = ALIGN(4);
    F_FlexNVM_code_end_addr = .;

    F_FlexNVM_data_start_addr = .;
    * (flexnvm.data)
    . = ALIGN(4);
    F_FlexNVM_data_end_addr = .;

  } > .p_FlexNVM

  .FlexRAM :
  {
    # Note:
    #   - FlexRAM is not available if FlexNVM is configured as EEPROM.
    #   - Variables put into .x_FlexRAM are not initiated at startup phase.
    #   - none_init.data is put into .x_Data segment by default, it is OK to put none_init.data into
    #     .x_FlexRAM segment if FlexNVM is not configured as EEPROM.

    F_FlexRAM_data_start_addr = .;
    # * (none_init.data)
    * (flexram.data)
    F_FlexRAM_data_end_addr = .;

  } > .x_FlexRAM

  .Data :
  {
    # save space for the RamData copy
    . = _RamData_end_addr;

    _Data_start_addr = .;

    # library .bss sections
    * (rtlib.bss.lo)
    * (rtlib.bss)
    . = ALIGN(4);

    # application .bss sections
    _Data_bss_start_addr = .;
    * (.bss.char)         # used if "Emit Separate Char Data Section" enabled
    * (.bss)
    . = ALIGN(2);         # used to ensure proper functionality of the zeroBSS hardware loop utility
    _Data_bss_end_addr   = .;
    _Data_bss_size = _Data_bss_end_addr - _Data_bss_start_addr;

    # none init data
    * (none_init.data)

    /* Setup the HEAP address */
    . = ALIGN(4);
    _Data_heap_start_addr  = .;
    _Data_heap_size        = 0x0;
    _Data_heap_end_addr    = _Data_heap_start_addr + _Data_heap_size;
    . = _Data_heap_end_addr;

    /* Setup the STACK address */
    . = ALIGN(2);
    _Data_stack_start_addr = .;
    _Data_stack_size       = 0x300;
    _Data_stack_end_addr   = _Data_stack_start_addr + _Data_stack_size;
    . = _Data_stack_end_addr;

    /* EXPORT HEAP, STACK, BSS to runtime and MSL libraries */
    F_heap_addr   = _Data_heap_start_addr;
    F_heap_end    = _Data_heap_end_addr;
    F_Lstack_addr = _Data_stack_start_addr;
    F_start_bss   = _Data_bss_start_addr;
    F_end_bss     = _Data_bss_end_addr;

    /* startup Finit_56800_ uses these globals */
    F_Xbss_start_addr  = _Data_bss_start_addr;
    F_Xbss_length      = _Data_bss_size;

    F_Ldata_size       = _RamData_size;
    F_Ldata_RAM_addr   = _RamData_start_addr;
    F_Ldata_ROM_addr   = _RamData_storage_start_addr;

    F_Livt_size        = _RamCode_size;
    F_Livt_RAM_addr    = _RamCode_start_addr;
    F_Livt_ROM_addr    = _RamCode_storage_start_addr;

    F_xROM_to_xRAM     = 0x0000;
    F_pROM_to_xRAM     = 0x0001;  # Enable loading data initial value to corresponding variables before entering main function
    F_pROM_to_pRAM     = 0x0001;  # Enable loading codes that residing in flash but running in RAM to RAM before entering main function

    _Data_end_addr = .;
  } > .x_Data
}
