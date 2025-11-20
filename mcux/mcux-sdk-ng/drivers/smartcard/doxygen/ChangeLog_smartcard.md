# SMARTCARD

## [2.3.0]

- New features:
  - Added support for USIM

## [2.2.2]

- Bug fix:
  - Fixed MISRA C-2012 rule 10.4.

## [2.2.1]

- Bug fix:
  - Fixed IAR warnings Pa082 in smartcard_emvsim
  - Fixed MISRA issues
  - Fixed rules 10.1, 10.3, 10.4, 10.6, 10.7, 10.8, 14.4, 16.1, 16.3, 16.4, 17.7

## [2.2.0]

- New features:
  - Updated to use RX/TX FIFO

## [2.1.2]

- Provided time delay function which works in microseconds.
- Bug fix:
  - Changed event to semaphore in RTOS driver (KPSDK-11634).
  - Added check if de-initialized variables are not null iSMARTCARD_RTOS_Deinit() (KPSDK-8788).
  - Changed deactivation sequence iSMARTCARD_PHY_TDA8035_Deactivate() to properly stop the clockPOSCR-35).
  - Fixed timing issue with VSEL0/1 signals in smartcard TDA803driver (KPSDK-10160)

## [2.1.1]

- New features:
  - Added default phy interface selection into smartcard RTOS drivers (KPSDK-9063).
  - Replaced smartcard_phy_ncn8025 driver by smartcard_phy_tda8035.
- Bug fix:
  - Fixed protocol timers activation sequences in smartcard_emvsim and smartcard_phy_tda8035 drivers during emvl1 pre-certification tests (KPSDK-9170, KPSDK-9556).

## [2.1.0]

- Initial version.
