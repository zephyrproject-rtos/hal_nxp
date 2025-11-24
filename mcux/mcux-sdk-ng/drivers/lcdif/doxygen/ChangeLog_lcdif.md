# LCDIF

## [2.3.1]

- Bug Fixes
  - Fixed CERT-C violations.
  - Fixed wrong frame buffer configuration for overlay layers.

## [2.3.0]

- New Features
  - Supported layer decompress mode for DC8000.

## [2.2.0]

- New Features
  - Supported new layers and configurations for DC8000.
  - Added new APIs and configurations to support DBI interface.
- Bug Fixes
  - Update align calculation method, the old one can only be used when the
    align bytes' low bits are all zeros.

## [2.1.2]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.1]

- Improvements
  - Added memory address conversion to support buffers which could only be
    accessed using alias address by non-core masters.
- Bug Fixes
  - Fix MISRA-C 2012 issues.

## [2.1.0]

- Bug Fixes
  - Corrected the frame buffer pixel format name.

## [2.0.0]

- Initial version.
