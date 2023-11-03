/*
** ###################################################################
**     Processors:          QN9030
**
**     Compiler:            GNU C Compiler
**     Reference manual:    QN9030 Series Reference Manual
**
**     Abstract:
**         Linker file definitions to be included by linker scripts
**         using QN9030 chip.
**         Contain memory mapping constants.   
**
**     Copyright  2022 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*** Internal flash memory characteristics ***/
m_flash_start   = 0x00000000;
m_flash_end     = 0x0004FFFF;
m_flash_size    = 0x00050000;
m_sector_size   = 512;

m_update_page_address = 0x9de00;
m_config_page_address = 0x9fc00;   /* CONFIG page of page N-2  */


BOOT_SCRATCH_DATA_SZ = 0x400;
/*
 * stack size for the boot rom during warm boot and application
 * 256 is sufficient (pwrm_test) but keep it large to 1024
 */
BOOT_RESUME_STACK_SIZE = 0x400;


  __base_RAM_Bank0 = 0x04000000;             /* RAM0 Bank0 */
  __size_RAM_Bank0 = 0x00004000;             /* 16kB */
  __top_RAM_Bank0  = __base_RAM_Bank0 + __size_RAM_Bank0;

  __base_RAM_Bank1 = 0x04004000;             /* RAM0 Bank1 */
  __size_RAM_Bank1 = 0x00004000;             /* 16kB */
  __top_RAM_Bank1  = __base_RAM_Bank1 + __size_RAM_Bank1;

  __base_RAM_Bank2 = 0x04008000;             /* RAM0 Bank2 */
  __size_RAM_Bank2 = 0x00004000;             /* 16kB */
  __top_RAM_Bank1  = __base_RAM_Bank2 + __size_RAM_Bank2;

  __base_RAM_Bank3 = 0x0400c000;             /* RAM0 Bank3 */
  __size_RAM_Bank3 = 0x00004000;             /* 16kB */
  __top_RAM_Bank3  = __base_RAM_Bank3 + __size_RAM_Bank3;

  __base_RAM_Bank4 = 0x04010000;             /* RAM0 Bank4 */
  __size_RAM_Bank4 = 0x00002000;             /* 8kB */
  __top_RAM_Bank4  = __base_RAM_Bank4 + __size_RAM_Bank4;

  __base_RAM_Bank5 = 0x04012000;             /* RAM0 Bank5 */
  __size_RAM_Bank5 = 0x00002000;             /* 8kB */
  __top_RAM_Bank5  = __base_RAM_Bank5 + __size_RAM_Bank5;

  __base_RAM_Bank6 = 0x04014000;             /* RAM0 Bank6 */
  __size_RAM_Bank6 = 0x00001000;             /* 4kB */
  __top_RAM_Bank6  = __base_RAM_Bank6 + __size_RAM_Bank6;

  __base_RAM_Bank7 = 0x04015000;             /* RAM0 Bank7 */
  __size_RAM_Bank7 = 0x00001000;             /* 4kB */
  /*
   * the 32 top bytes of the RAM0/Bank7 are used for WarmBoot.
   * These impose that the Bank7 remain under retention.
   */
  __BootInterfaceSz       = 32;
  __top_RAM_Bank7  = __base_RAM_Bank7 + __size_RAM_Bank7 -__BootInterfaceSz ;



  /* Define a symbol for the top of each memory region */
  __base_Flash320       = 0x0;            /* Flash640 */
  __size_Flash320       = 0x50000;        /* 320K bytes */
  __top_Flash320        = __base_Flash320 + __size_Flash320; 
  
  __base_Flash          = __base_Flash320;
  __size_Flash          = __size_Flash320;
  __top_Flash           = __top_Flash320;
  /* RAM0 bank : [0x04000000..0x04000400] trampled at Warm boot
   * Likewise we choose to place the Boot Resume stack contiguous to this area in 
   * [0x04000400..0x04000800].
   * so that we have a 2kB region that can be unretained and be used as a scratch area.
   * Ideally to minimize retained memory one should concentrate in Bank0 all data not
   * requiring retention.
   */
  __base_unretainedRAM0 = __base_RAM_Bank0;
  __size_unretainedRAM0 = BOOT_SCRATCH_DATA_SZ + BOOT_RESUME_STACK_SIZE;
  __top_unretainedRAM0  = __base_unretainedRAM0 + __size_unretainedRAM0; /* start of normal use RAM0 */

  /* The remainder of Bank0 is usable it is up to the papplication designer to decide
   * to retain Bank0 or not. If so the default below allow for maximum RAM capacity, gaining 14kB
   * but requiring to retain Bank0 at the expense of power ~420nA.
   */
  __base_RAM0           = __top_unretainedRAM0;      /* RAM0 */
  __size_RAM0           = __top_RAM_Bank7 - __top_unretainedRAM0;      /* RAM0 */
  /* __base_RAM will be set to __base_RAM0 if the approach favours capacity and
   * otherwise the Stack of the startup task will be placed in a way such that the top of the stack 
   * that require retention be in Bank1 while the */ 
  __base_RAM            = __base_RAM0; 
  __size_RAM            = __size_RAM0;
  __top_RAM             = __top_RAM_Bank7;

