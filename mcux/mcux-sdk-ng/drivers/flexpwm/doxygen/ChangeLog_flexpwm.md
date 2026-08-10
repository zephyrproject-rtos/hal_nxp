# FlexPWM

## [2.0.0]

- Initial version of FlexPWM driver which is refactored from PWM driver (fsl_pwm.c/h).
- Improvements
  - Decomposed monolithic initialization into 11 dedicated configuration functions following single responsibility principle.
    - `FLEXPWM_ConfigSubmodule` for counter and reload configuration.
    - `FLEXPWM_ConfigPWM` for PWM output configuration.
    - `FLEXPWM_ConfigPWMChannelX` for PWM_X channel configuration.
    - `FLEXPWM_ConfigFaultProtection` for fault protection settings.
    - `FLEXPWM_ConfigInputCapture` for input capture configuration.
    - `FLEXPWM_ConfigOutputTrigger` for output trigger configuration.
    - `FLEXPWM_ConfigDMAControl` for DMA control settings.
    - And other specialized configuration functions.
  - Added inline register access APIs for zero-overhead direct control.
    - `FLEXPWM_SetVAL0` through `FLEXPWM_SetVAL5` compile to single-instruction register writes.
  - Reorganized data structures into hierarchical configuration for better clarity.
    - `flexpwm_submodule_config_t` for submodule-level settings.
    - `flexpwm_pwm_config_t` for PWM signal parameters.
    - `flexpwm_fault_protection_config_t` for fault protection.
  - Added atomic multi-submodule control using bitmask-based operations.
    - `FLEXPWM_EnableSubmoduleCounter` supports simultaneous start of multiple submodules.
    - Eliminates race conditions in multi-channel scenarios.
  - Improved fault protection configuration with dedicated structures and APIs.
  - Updated naming convention from `PWM_*` to `FLEXPWM_*` to align with peripheral name.
  - Removed implicit side effects from initialization functions for more predictable behavior.