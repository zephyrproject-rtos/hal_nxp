# CE

## [2.3.3]

- Improvements
  - Updated the type of the variables and the parameters from int to int32_t

## [2.3.2]

- Bug Fixes
  - Fixed FFT size error check for F32

## [2.3.1]

- Improvements
  - Updated the API CE_CmdInitBuffer, type of the parameter statusbuffer is updated from uint32_t to int
  - Fixed MISRA 17.7 violation
  - Added API descriptions in CE driver C code

## [2.3.0]

- New Features
  - Enabled Matrix add for Q15 and Q31 data types
  - Enabled Chol Decomp for CF32 Matrices
- Improvements
  - Optimized EVD scratch usage to be proportional to EVD size (and not based on MAXSIZE)
  - Add a simple check for log2N min and max sizes in transform API
  - Remove unsupported API CE_MatrixInv_F32, CE_MatrixInvSymm_F32 and CE_MatrixInv_CF32

## [2.2.3]

- Improvements
  - Added timeout for while loop in CE_CmdLaunchBlocking().

## [2.2.2]

- Improvements
  - New memory map ("cmd_buffer" and "status_buffer" in the API CE_CmdInitBuffer needs to be mapped to 0x20029000 and 0x20029400, respectively)
  - 0x20020000 : 0x20027FFF => ZV Program Memory
    0x20028000 : 0x20028FFF => ZV Stack
    0x20029000 : 0x20029617 => Reserved for ZV Driver
    0x20029618 : 0x20037FFF => ZV Data RAM

## [2.2.1]

- Improvements
  - Fixed MISRA issue 7.2, 17.7, 10.4 and 10.3.

## [2.2.0]

- Bug Fixes
  - Fix the issue that eigenvectors are NaNs with triangular or square input Hermitian.

## [2.1.1]

- Improvements
  - Add checking its value before casting N from unsigned int to int.
  - Update the types of the buffer_base_ptr, next_buffer_ptr and status_buffer_ptr
    variables in the ce_cmdbuffer_t structure.

## [2.1.0]

- New Features
  - Added ZV->CM33 interrupt for non-blocking mode and updated matrix multiply
    function to handle small matrices.

## [2.0.1]

- Bug Fixes
  - Add the conditional compiling flags KW47_core0_SERIES and MCXW72_core0_SERIES
    to fix the CE driver compiling issues in Core1.

## [2.0.0]

- Initial version.
