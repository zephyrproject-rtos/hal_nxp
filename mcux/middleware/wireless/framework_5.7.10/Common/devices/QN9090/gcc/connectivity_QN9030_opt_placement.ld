/*
** ###################################################################
**     Processors:          QN9030
**
**     Compiler:            GNU C Compiler
**     Reference manual:    QN9030 Series Reference Manual
**
**     Abstract:
**         Linker file for the GNU C Compiler
**
**     Copyright  2019 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/


/******************* Map of QN9030 FLASH ***********************************


             0x000a_0000    m_flash_end
    - - - +---------------+ - - - - - - - -
          |   _ _ _ _ _   |
          | Flash config  |
   8.5k   |   - - - - -   |
          |               |
          |  RESERVED     |  0x9de00
    - - - +---------------+ - - - - - - - -
          |               |
          |     NOT       |
          |  AVAILABLE    |
          |               | 0x50000
    - - - +---------------+ - - - - - - - -
          |               | NV_STORAGE_START_ADDRESS
   31.5k  |               |
          |   NVM_region  |
          |               |
          |               | NV_STORAGE_END_ADDRESS
    - - - +---------------+ - - - - - - - -
          |               | INT_STORAGE_START
          |               |
          |               |
   MAX    | OTAP Internal |
   144k   |   Storage*    |
          |               |
          |               |
          |               |
          |               | INT_STORAGE_END (Must be aligned on a 8K to support the OTA remap mechanism)
    - - - +---------------+ - - - - - - - -
          |               | m_text_end
          |               |
          |               |
    MAX   |  Application  |
    144k  |               |
          |               |
          |               | m_text_start
    - - - +---------------+ - - - - - - - -
             0x0000_0000

 * - This section is optional for application that does not support OTA (gUseInternalStorageLink_d not defined or equal to 0).
In this case the application (m_text_end) could be up to NV_STORAGE_END_ADDRESS-1 and its MAX size will be 600k
 *****************************************************************************/

/* Entry Point */
ENTRY(ResetISR)

INCLUDE qn9030_map.ld


/****************************************************
 *******         User Defines                 *******
 ****************************************************/
UseNVMLink              = DEFINED(gUseNVMLink_d)            ? gUseNVMLink_d             : 0;
NVMSectorCountLink      = DEFINED(gNVMSectorCountLink_d)    ? gNVMSectorCountLink_d     : ( DEFINED(gUseNVMLink_d) ? gUseNVMLink_d*63 : 0 ); 
ram_vector_table        = DEFINED(__ram_vector_table__)     ? __ram_vector_table__      : 0;
UseInternalStorageLink  = DEFINED(gUseInternalStorageLink_d)? gUseInternalStorageLink_d : 0;

m_app_size  = DEFINED(__app_stated_size__) ? __app_stated_size__ : 0x48000;
m_app_start = DEFINED(__app_load_address__) ? __app_load_address__ : 0x0;

m_app_end                 = m_app_start + m_app_size - 1;


HEAP_SIZE               = DEFINED(__heap_size__)            ? __heap_size__             : 0;
STACK_SIZE              = DEFINED(__stack_size__)           ? __stack_size__            : ( DEFINED(__special_stack_size__) ? __special_stack_size__ : (0x1000 - 32));
vector_table_size       = 0x120;

/****************************************************
 ******          Flash regions sizes           ******
 ****************************************************/
NV_STORAGE_SIZE         = NVMSectorCountLink * m_sector_size;
NV_STORAGE_MAX_SECTORS  = NVMSectorCountLink;
NV_STORAGE_SECTOR_SIZE = m_sector_size;

m_int_start_addr        = m_app_end + 1;

/****************************************************
 ******        Flash Regions, low to high      ******
 ****************************************************/
m_text_start            = m_app_start;



/****************************************************
 *****        Flash Regions, high to low       ******
 ****************************************************/
NV_STORAGE_START_ADDRESS = m_update_page_address - 1;
NV_STORAGE_END_ADDRESS  = NV_STORAGE_START_ADDRESS - NV_STORAGE_SIZE + 1;
INT_STORAGE_START       = NV_STORAGE_END_ADDRESS - 1;
INT_STORAGE_END         = (UseInternalStorageLink) ? m_int_start_addr : INT_STORAGE_START;
INT_STORAGE_SIZE        = INT_STORAGE_START - INT_STORAGE_END;
m_text_end              = INT_STORAGE_END - 1;

/* Other Defines */
m_text_size             = m_text_end + 1 - m_text_start ;

INT_STORAGE_SECTOR_SIZE = m_sector_size;
M_VECTOR_RAM_SIZE       = DEFINED(__ram_vector_table__) ? vector_table_size : 0x0;

/* StartupStack retained stack fluctuates
 * depending on whether the build is release of debug.
 * Can be adjusted to x0100 in Release mode*/
__StartupStackRetained  = 0x200;
__StackTop              = __base_RAM_Bank1 + __StartupStackRetained;
__size_of_ram           = __top_RAM - __StartupTaskTop;   

PROVIDE(_vStackTop = __StackTop );
__StackBottom = _vStackTop - STACK_SIZE; /* only the top 256 bytes of the startup_task are retained */
/* Specify the memory areas */
MEMORY
{
  /* Define each memory region */
  /* Internal Flash */
  Flash320        (RX)   : ORIGIN = m_app_start,       LENGTH = m_text_size

  /* SRAM */  
  BANK0          (rwx)   : ORIGIN = __base_RAM_Bank0,  LENGTH = __size_RAM_Bank0
  BANK1          (rwx)   : ORIGIN = __base_RAM_Bank1,  LENGTH = __size_RAM_Bank1
  BANK2          (rwx)   : ORIGIN = __base_RAM_Bank2,  LENGTH = __size_RAM_Bank2
  BANK3          (rwx)   : ORIGIN = __base_RAM_Bank3,  LENGTH = __size_RAM_Bank3
  BANK4          (rwx)   : ORIGIN = __base_RAM_Bank4,  LENGTH = __size_RAM_Bank4
  BANK5          (rwx)   : ORIGIN = __base_RAM_Bank5,  LENGTH = __size_RAM_Bank5
  BANK6          (rwx)   : ORIGIN = __base_RAM_Bank6,  LENGTH = __size_RAM_Bank6
  BANK7          (rwx)   : ORIGIN = __base_RAM_Bank7,  LENGTH = __size_RAM_Bank7

  SCRATCH_RAM    (rwx)   : ORIGIN = __base_RAM_Bank0,  LENGTH = __StackBottom - __base_RAM_Bank0 /* 2K bytes (alias SCRATCH_RAM) */
 
  RAM0           (rwx)   : ORIGIN = __StackTop,  LENGTH = __size_of_ram /* 87K bytes (alias RAM) */

}


SECTIONS
{
    /* MAIN TEXT SECTION */
    .m_interrupts : ALIGN(4)
    {
        _flash_start = ABSOLUTE(.);
        _flash_beg = ABSOLUTE(.);

        FILL(0xff)
        __vectors_start__ = ABSOLUTE(.) ;
        __VECTOR_TABLE = .;
        KEEP(*(.isr_vector))
        FILL(0xff)
        . = ALIGN (0x10);
    } > Flash320

    /* MAIN TEXT SECTION */
    .data_bss : ALIGN(10)
    {
        /* Global Section Table */
        __section_table_start = .;
        __data_section_table = .;
        LONG(LOADADDR(.data));
        LONG(    ADDR(.data));
        LONG(  SIZEOF(.data));
        __data_section_table_end = .;
        __bss_section_table = .;
        LONG(    ADDR(.bss));
        LONG(  SIZEOF(.bss));
        __bss_section_table_end = .;
        __section_table_end = . ;
        /* End of Global Section Table */
        FILL(0xff)
        . = ALIGN (0x10);
    } > Flash320

    .ro_nonce : ALIGN(0x10)
    {
        _FlsNonceStart = ABSOLUTE(.);
        *(.ro_nonce) /* nonce value is 16 bytes.*/
        FILL(0xff)
        . = ALIGN (0x10);
    } > Flash320

    .ro_ota_header : ALIGN(0x10)
    {
        _enc_start = ABSOLUTE(.);
        _enc_offset = (_enc_start & 0x0000000F);
        _FlsOtaHeader = ABSOLUTE(.);
        *(.ro_ota_header) /* Ota Header 69 bytes*/
        FILL(0xff)
        . = ALIGN (0x10);
    } > Flash320

    .ro_se_lnkKey (ALIGN((. - _enc_offset), 16) + _enc_offset):
    {
        _FlsLinkKey = ABSOLUTE(.);
        *(.ro_se_lnkKey)  /* Link Key 16 bytes*/
        FILL(0xff)
        . = ALIGN (0x10);
    } > Flash320

    .filler :
    {
        BYTE(0xff)
        FILL(0xff);
        . = ALIGN(0x40);
    } > Flash320

    .text : ALIGN(0x40)
    {
        FILL(0xff)

       *(.after_vectors*)
       *(.text*)
        *(.rodata .rodata.* .constdata .constdata.*)
        . = ALIGN(4);
    } > Flash320

    .NVM_TABLE :
    {
      . = ALIGN(4);
      PROVIDE(__start_NVM_TABLE = .);
      KEEP(*(.NVM_TABLE));
      PROVIDE(__stop_NVM_TABLE = .);
      . = ALIGN(4);
    } > Flash320

    .VERSION_TAGS :
    {
        . = ALIGN(4);
        PROVIDE(__start_VERSION_TAGS = .);
        KEEP(*(.VERSION_TAGS));
        PROVIDE(__stop_VERSION_TAGS = .);
        . = ALIGN(4);
    } > Flash320

    /*
     * for exception handling/unwind - some Newlib functions (in common
     * with C++ and STDC++) use this.
     */
    .ARM.extab : ALIGN(4)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > Flash320
    __exidx_start = .;

    .ARM.exidx : ALIGN(4)
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > Flash320
    __exidx_end = .;

    _etext = .;

    .interrupts_ram :
    {
        . = ALIGN(4);
        __VECTOR_RAM__ = .;
        __interrupts_ram_start__ = .;   /* Create a global symbol at data start */
        *(.m_interrupts_ram)            /* This is a user defined section */
        . += M_VECTOR_RAM_SIZE;
        . = ALIGN(4);
        __interrupts_ram_end__ = .;     /* Define a global symbol at data end */
    } > RAM0
    .scratch_area (NOLOAD): ALIGN(4)
    {
       __scratch_area_start__ = .;
       . = ALIGN(4) ;
       . += 0x400;
       _boot_resume_stack = .;
       . += BOOT_RESUME_STACK_SIZE;
       _end_boot_resume_stack = .;
       __scratch_area_top__ = .;

       /* Between 0x04000800 and __StackLimit we have available space to be used for unretained
        * data preferably. Hint may be used for communication buffers. Unfortunately not possible
        * for BLE exchange memory
        */
    } > SCRATCH_RAM

    /* Main DATA section (RAM0) */
    .data : ALIGN(4)
    {
       FILL(0xff)
       _data = . ;
       *(vtable)
       *(.ramfunc*)
       *(.data*)
       . = ALIGN(4) ;
       _edata = . ;
    } > RAM0 AT>Flash320

    __VECTOR_RAM = __VECTOR_RAM__;
    __RAM_VECTOR_TABLE_SIZE_BYTES = DEFINED(__ram_vector_table__) ? (__interrupts_ram_end__ - __interrupts_ram_start__) : 0x0;

    /* MAIN BSS SECTION */
    .bss : ALIGN(4)
    {
        _bss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4) ;
        _ebss = .;

        PROVIDE(end = .);
    } > RAM0

    .ll_exchange_mem (NOLOAD): ALIGN(4)
    {
        __ll_exchange_mem_start__ = .;
        . = ALIGN(4) ;
        *(.ll.exchange_mem*);
        __ll_exchange_mem_top__ = .;
    } > BANK7

    /* DEFAULT NOINIT SECTION */
    .noinit (NOLOAD): ALIGN(4)
    {
        _noinit = .;
        *(.noinit*)
        . = ALIGN(4) ;
        _end_noinit = .;
    } > RAM0

    /* For now, Heap does not need to ne retained as configuration is baremetal
       and no allocator is implemented. Used only ponctually by stdio (sprintf) */
    PROVIDE(_pvHeapStart = DEFINED(__user_heap_base) ? __user_heap_base : .);
    PROVIDE(_pvHeapLimit = _pvHeapStart + (HEAP_SIZE));
    /* end of firmware RAM to be retained in power down mode only if MemManagerLight unused */
    _end_fw_retention = .;

	/* MemManagerLight heap : top can reach up to top of Bank6 but retained area may
	 * recede lower than Bank frontiers allowing to avoid retention of Banks  */
    .heap (NOLOAD): ALIGN(4)
    {
        __HEAP_start__ = .;
        *(.heap*)
        . = ALIGN(4) ;
    } > RAM0
    __HEAP_end__ = __top_RAM_Bank6; /* top of Heap in RAM0 */

  
    PROVIDE(_scratch_buf_start = __scratch_area_start__);
    PROVIDE(_scratch_buf_end = __scratch_area_top__);
}
ASSERT(__ll_exchange_mem_top__ < __top_RAM_Bank7, "LL echange memory too big to fit into bank7");
ASSERT(m_app_size % 8192 == 0, "Stated size must be a multiple of 8k")

GROUP(libcr_nohost.a libcr_c.a libcr_eabihelpers.a)
