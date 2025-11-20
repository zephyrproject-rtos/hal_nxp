# ANACTRL

## [2.4.0]

- Improvements
  - Added some interrupt flags for devices containing BOD1 and BOD2 interrupt controls.
  - Added a control macro to enable/disable the 32MHz Crystal oscillator code in current driver.
  - Added a feature macro for bit field ENA_96MHZCLK in FRO192M_CTRL.
  - Added a feature macro for bit field BODCORE_INT_ENABLE in BOD_DCDC_INT_CTRL.

## [2.3.1]

- Bug Fixes
  - Added casts to prevent overflow caused by capturing large target clock.

## [2.3.0]

- Improvements
  - Added AUX_BIAS control APIs.

## [2.2.0]

- Improvements
  - Added some macros to separate the scenes that some bit fields are reserved for some devices.
  - Optimized the comments.
  - Optimized the code implementation inside some functions.

## [2.1.2]

- Bug Fixes
  - Fixed MISRA C-2012 rule 10.3 and rule 17.7.

## [2.1.1]

- Bug Fixes
  - Removed AnalogTestBus configuration to align with new header.

## [2.1.0]

- Improvements
  - Updates for LPC55xx A1.
    - Removed the control of bitfield FRO192M_CTRL_ENA_48MHZCLK, XO32M_CTRL_ACBUF_PASS_ENABLE.
    - Removed status bits in ANACTRL_STATUS: PMU_ID OSC_ID FINAL_TEST_DONE_VECT.
    - Removed API ANACTRL_EnableAdcVBATDivider() and APIs which operate the RingOSC registers.
    - Removed the configurations of 32 MHz Crystal oscillator voltage source supply control register.
    - Added API ANACTRL_ClearInterrupts().

## [2.0.0]

- Initial version.
