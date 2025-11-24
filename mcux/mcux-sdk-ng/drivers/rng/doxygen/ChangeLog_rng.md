# RNG

## [2.1.0]

- Renamed function RNG_GetRandomData() to RNG_GetRandomDataWord(). Added function RNG_GetRandomData() which discarding next 32 words after reading RNG register which results into better entropy, as is recommended in UM.
- API is aligned with other RNG driver, having similar functionality as other RNG/TRNG drivers.

## [2.0.0]

- Initial version.
