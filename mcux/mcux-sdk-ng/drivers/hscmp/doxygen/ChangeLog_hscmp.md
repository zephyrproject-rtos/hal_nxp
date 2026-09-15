# HSCMP

## [2.1.0]

- New Features:
  - Added Round Robin mode support: new `hscmp_roundrobin_config_t` structures,
    `HSCMP_SetRoundRobinConfig()`, `HSCMP_SetRoundRobinPresetState()`,
    `HSCMP_GetRoundRobinLastResult()`, `HSCMP_GetRoundRobinChannelFlags()`, and
    `HSCMP_ClearRoundRobinChannelFlags()` APIs.
  - Added full window mode configuration: new `hscmp_window_config_t` structure and
    `HSCMP_SetWindowConfig()` API covering WINDOW_INV, WINDOW_CLS, EVT_SEL, COUTA_OWEN, COUTA_OW.
  - Added `HSCMP_SetDACValue()` API to dynamically update the DAC output voltage at runtime
    without reconfiguring the full DAC settings.
  - Added `enableDac` field to `hscmp_dac_config_t` to control DCR.DAC_EN explicitly.
  - Added `enableDacLink` field to `hscmp_config_t` to control CCR0.LINKEN (CMP-to-DAC link).
  - Added `enableOffset` field to `hscmp_config_t` to control CCR2.OFFSET (asymmetric hysteresis).
  - Added `enableComparator` field to `hscmp_config_t` to enable the HSCMP module optionally.
  - Added `enableDacOutput` field to `hscmp_dac_config_t` to control DCR.DACOE (DAC output pin enable).
  - Added `kHSCMP_RoundRobinEventFlag` status flag and `kHSCMP_RoundRobinInterruptEnable` interrupt mask.
  - Added `hscmp_window_event_select_t` enum for window close event selection.
  - Added `_hscmp_roundrobin_channel_mask` enum for per-channel bitmask constants shared across
    channel-enable, preset-state, last-result, and channel-flag APIs.
  - Added `hscmp_input_t` enum and `HSCMP_SetInputMux()` API to configure CCR2.INPSEL and
    CCR2.INMSEL, selecting between the internal DAC output (IN0) and the analog 8-to-1 mux (IN1)
    for the Plus and Minus comparator input ports independently.
  - Added `hscmp_func_clock_t` enum and `funcClockSel` field in `hscmp_config_t` to configure
    CCR1.FUNC_CLK_SEL (functional clock source).
  - Added `enableDacStopMode` field in `hscmp_dac_config_t` to configure DCR.DAC_STOP_EN (allow DAC_EN to
    enable the DAC in stop mode).
  - Added `hscmp_roundrobin_trig_sel_t` enum and `triggerSelect` field in `hscmp_roundrobin_config_t`
    to configure RRCR0.RR_TRG_SEL (external/internal trigger).
  - Added `hscmp_roundrobin_clk_sel_t` enum and `rrClockSel` field in `hscmp_roundrobin_config_t`
    to configure RRCR0.RR_CLK_SEL (round-robin clock source).
  - Added `sampleCount` field in `hscmp_roundrobin_config_t` to configure RRCR0.RR_SAMPLE_CNT
    (number of samples for one channel).
  - Added `sampleThreshold` field in `hscmp_roundrobin_config_t` to configure RRCR0.RR_SAMPLE_THRESHOLD.

## [2.0.4]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.0.3]

- Bug Fixes:
  - Fixed the violation of MISRA-2012 rule 17.7.

## [2.0.2]

- Bug Fixes:
  - The current API LPCMP_ClearStatusFlags has to check w1c bits.

## [2.0.1]

- Added control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
