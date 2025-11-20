# SHA

## [2.3.2]

- Add -O2 optimization for GCC to sha_process_message_data_master(), because without it the function hangs under some conditions.

## [2.3.1]

- Modified sha_process_message_data_master() to ensure that MEMCTRL will be written within 64 cycles of writing last word to INDATA as is mentioned in errata, even with different optimization levels.

## [2.3.0]

- Modified SHA_Update to use blocking version of AHB Master mode when its available on chip. Added SHA_UpdateNonBlocking() function which uses nonblocking AHB Master mode.
- Fixed incorrect calculation of SHA when calling SHA_Update multiple times when is CPU used to load data.
- Added Reset into SHA_ClkInit and SHA_ClkDeinit function.

## [2.2.2]

- Modified SHA_Finish function. While using pseudo DMA with maximum optimization, compiler optimize out condition.
  Which caused block in this function and did not check flag, which has been set in interrupt.

## [2.2.1]

- MISRA C-2012 issue fix.

## [2.2.0]

- Support MEMADDR pseudo DMA for loading input data in SHA_Update function (LPCXpresso54018 and LPCXpresso54628).

## [2.1.1]

- MISRA C-2012 issue fixed: rule 10.3, 10.4, 11.9, 14.4, 16.4 and 17.7.

## [2.1.0]

- Updated "sha_ldm_stm_16_words" "sha_one_block" API to match QN9090. QN9090 has no ALIAS register.
- Added "SHA_ClkInit" "SHA_ClkInit"

## [2.0.0]

- Initial version.
