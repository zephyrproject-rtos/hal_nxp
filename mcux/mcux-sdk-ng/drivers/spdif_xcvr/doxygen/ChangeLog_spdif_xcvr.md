# SPDIF XCVR Driver

## [1.0.1]

- Improvements
	- Added `SPDIF_CopyRxChannelStatusToTx()` and enabled TX channel status by default to support the shared interrupt transfer example.
	- Updated the public SPDIF API layer to use `SPDIF_Type` while mapping the implementation directly onto the RT2660 `AUDIO_XCVR` register interface.

## [1.0.0]

- Initial version.
