# TSI_V6

## [2.1.1]

- Bug Fixes
  - Fixed CERT INT31-C violations: use ternary expression for bool-to-uint32_t conversion in TSI_CONFIG_S_SEN and TSI_CONFIG_S_NOISE macros.
  - Fixed build failure on platforms with TSI channel count <= 32 where the driver unconditionally accessed SELF_SEL_63_32/SELF_SEL_69_64 and the matching SHIELD/MUTUAL_TX/MUTUAL_RX registers that do not exist.

## [2.1.0]

- New Features
  - Add 70 channel support for TSI module.
  - Add TSI DPD mode support.
  - Add API TSI_EnableOutOfRangeDmaTransferOnly enable DMA transfer only when out of range.
- Bug Fixes
  - Fixed incorrectly using the ALL_FLAGS_MASK when modifying the GENCS register issue

## [2.0.1]

- New Features
  - The tsi_shield_t typedef has been extended to cover 4 bits shielding bit-field. 

## [2.0.0]

- Initial version.
