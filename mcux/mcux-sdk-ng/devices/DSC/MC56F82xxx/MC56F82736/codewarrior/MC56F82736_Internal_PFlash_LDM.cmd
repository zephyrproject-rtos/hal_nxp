#####################################################################
##     Processor:           MC56F82736VLF
##     Compiler:            CodeWarrior C/C++ for DSP M56800E
##     Reference manual:    Manual version TBD
##     Version:             rev. 0.1, 2021-01-28
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
##  3. .p_NVM uses the last flash sector by default.
##
##  4. To use .x_FlashData memory segment, since MC56F82xxx flash mapping address in x space is 0x4000-0xBFFF(word address).
##     - LDM is supported by default when data allocation only range in x space address 0x4000-0x7FFF.
##     - When data allocation range in range in x space address 0x8000-0xBFFF(word address), LDM is supported by uncheck
##       below setting in Codewarrior project properties:
##       Project Properties -> C/C++ Build -> Settings -> Tool Settings -> DSC Compiler -> Processor -> Globals Live Lower Memory
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
##    0x5DFF:
##              -------------
##              -------------
##    0x5E00:
##            > nvm.data section
##    0x5FFF:
##              -------------
##              -------------
##    0xF000:
##            > RAM code, namely, "codesInRam.text" section
##    0xFFFF:
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
##    0xFFF:
##              -------------
##              -------------
##    0x4000:
##            > Flash data, namely, ".xflash.data" section
##    0x9FFF:
##              -------------
#####################################################################

FLASH_PARTITION {
  # name : ORIGIN_P = addr, ORIGIN_X = addr, LENGTH = size [> filename]
  FlashImage   : ORIGIN_P = 0x0, ORIGIN_X = 0x4000, LENGTH = 0x6000 > FlashImage.bin
  # FlashPart1 : ORIGIN_P = 0x0, ORIGIN_X = 0x4000, LENGTH = 0x6000
}

MEMORY {
  .x_Peripherals (RW): ORIGIN = 0xC000,  LENGTH = 0x0              # I/O registers area for on-chip peripherals

  .p_Interrupts (RWX): ORIGIN = 0x0,     LENGTH = 0xDE             # Interrupt Vector Table
  .p_FCF        (RWX): ORIGIN = 0x200,   LENGTH = 0x8              # Flash Configuration Area

  .p_Code       (RWX): ORIGIN = 0x208,   LENGTH = 0x6000 - 0x208 - 0x200  # XIP(excute in place) code resides in flash
  .x_FlashData   (RX): ORIGIN = AFTER(.p_Code) + 0x4000, LENGTH = 0  # Flash data stored in flash but accessed from x space

  .p_RamCode     (RX): ORIGIN = 0xF000, LENGTH = 0x1000           # RAM mapped into p space, code resides in flash and runs in RAM

  .p_RamData     (RX): ORIGIN = AFTER(.p_RamCode) - 0xF000, LENGTH = 0x1000 + 0xF000 - AFTER(.p_RamCode)  # .data section
  .x_Data        (RW): ORIGIN = AFTER(.p_RamCode) - 0xF000, LENGTH = 0x1000 + 0xF000 - AFTER(.p_RamCode)  # bss, heap, stack ...

  .p_NVM        (RWX): ORIGIN = 0x6000 - 0x200, LENGTH = 0x200    # Use flash last sector as NVM, stored and accessed in p space
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
    _Data_stack_size       = 0x200;
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
