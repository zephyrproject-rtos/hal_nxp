# IRQSTEER

## [2.1.0]

- New Features
  - Add IRQSTEER_GetInstIdxByIRQ() API to find instance index by IRQ number.
    Supports multiple IRQSTEER instances with different interrupt counts.
  - Add irqStartOff field to irqsteer_info_t for per-instance IRQ offset.
- Improvements
  - Fix inputIdx calculation to use per-instance irqStartOff offset.

## [2.0.1]

- Improvement
  - Initialize irqsteer defaultly, so users don't need to call api
    IRQSTEER_Init to intialize irqsteer.

## [2.0.0]

- Initial version.
