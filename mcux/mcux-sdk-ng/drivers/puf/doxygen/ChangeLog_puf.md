# PUF

## [2.2.0]

- Add support for kPUF_KeySlot4.
- Add new PUF_ClearKey() function, that clears a desired PUF internal HW key register.

## [2.1.6]

- Changed wait time in PUF_Init(), when initialization fails it will try PUF_Powercycle() with shorter time. If this shorter time will also fail, initialization will be tried with worst case time as before.

## [2.1.5]

- Use common SDK delay in puf_wait_usec().

## [2.1.4]

- Replace register uint32_t ticksCount with volatile uint32_t ticksCount in puf_wait_usec() to prevent optimization out delay loop.

## [2.1.3]

- Fix MISRA C-2012 issue.

## [2.1.2]

- Update: Add automatic big to little endian swap for user
  (pre-shared) keys destinated to secret hardware bus (PUF key index 0).

## [2.1.1]

- Fix ARMGCC build warning .

## [2.1.0]

- Align driver with PUF SRAM controller registers on LPCXpresso55s16.
- Update initizalition logic .

## [2.0.3]

- Fix MISRA C-2012 issue.

## [2.0.2]

- New feature:
  - Add PUF configuration structure and support for PUF SRAM controller.
- Improvements:
  - Remove magic constants.

## [2.0.1]

- Bug Fixes:
  - Fixed puf_wait_usec function optimization issue.

## [2.0.0]

- Initial version.
