# ADC_ETC

## [2.3.2]

- Improvements
  - Corrected that FSL_FEATURE_ADC_ETC_HAS_NO_TSC1_TRIG should be used instead
    of FSL_FEATURE_ADC_ETC_HAS_NO_TSC0_TRIG in some places.
  - For ADC_ETC without TSC trigger source, CTRL [bit 30] shall be cleared explicitly.

## [2.3.1]

- Improvements
  - Change ADC_ETC default DMA Mode to kADC_ETC_TrigDMAWithPulsedSignal.
    Generally speaking, DMA transfer requests should only be cleared by DMA ACK,
    and the CPU should not clear the request source.
    If some users use option kADC_ETC_TrigDMAWithLatchedSignal, changing the mode to
    kADC_ETC_TrigDMAWithPulsedSignal also meet their requirements.

## [2.3.0]

- Improvements
  - Added blocking way to implement SW trigger.

## [2.2.1]

- Improvements
  - Moditied macro  "ADC_ETC_DONE2_ERR_IRQ_TRIG0_DONE2_MASK" to "ADC_ETC_DONE2_3_ERR_IRQ_TRIG0_DONE2_MASK" based
    on the updates of header file.

## [2.2.0]

- Improvements
  - Defined two macros to support some devices that do not equipped with
    TSC trigger.

## [2.1.1]

- Bug Fixes
  - Fixed the violation of MISRA-2012 rule.

## [2.1.0]

- New Features
  - Supported independent IRQ enable bit in ADC-ETC chain configuration registers.
  - Supported trigger n DONE3 interrupt operations.
- Bug Fixes
  - Fixed the violation of MISRA-2012 rules:
    - Rule 10.1 10.3 10.7 15.5 16.1 16.3 16.4 17.7

## [2.0.1]

- New Features
  - Added a control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
