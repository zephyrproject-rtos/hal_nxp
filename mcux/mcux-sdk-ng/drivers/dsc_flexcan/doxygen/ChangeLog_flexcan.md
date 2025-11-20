# FLEXCAN

## [2.1.2]

- Bug Fixes
- Fixed the violation of MISRA-2012 rule : 10.1, 14.3, 17.7.

## [2.1.1]

- Bug Fixes
- Fixed the violation of MISRA-2012 rule.
- Fixed CBT SEG2 potential overflow issue.

## [2.1.0]

- Improvement
- Add bEnableTimingCalc member in flexcan_config_t structure to make users can choose to use their desired timing
  values or use auto calculate timing values to initialize FLEXCAN module.
- Update FLEXCAN_CalculateImprovedTimingValues/FLEXCAN_FDCalculateImprovedTimingValues APIs to improvement the
  bit timing calculate.
- Add FLEXCAN_CalculateImprovedTimingValuesWithCBT API.
- Move TDC config operations to FLEXCAN_SetFDTimingConfig API.
- Add FLEXCAN_SetBaudRate/FLEXCAN_SetFDBaudRate APIs to enable auto update CAN bit timing configuration base on
  baud rate parameter.
- Update FLEXCAN_WriteFDTxMb to make it can send both CAN FD frame and classic frame.

## [2.0.2]

- Bug Fixes
- Fixed build error by adding macro isolation to all CAN FD codes.

## [2.0.1]

- Bug Fixes
- Fixed build warnings.

## [2.0.0]

- Initial version.
