# PSA Key Location
The PSA specification defines multiple key locations (of type `key_location_t`)
that specify the high-level behavior of the key. The default key location
supported by all drivers is the the *Primary Local Storage*.

Other key locations may be supported by specific hardware accelerated ports.
See the [Port Layers](#port-layers) section.

**NOTE: Currently, the PSA reference implementation does not expose**
**vendor-defined key locations. To expose NXP-defined key locations,**
**please include the `mcux_psa_defines.h` header that is contained in the**
**`middleware/mbedtls3x/port/` folder.**

**Properly exposing vendor-defined key locations through the regular**
**inclusion of `psa/crypto.h` is a work in progress.**

## Primary Local Storage (`PSA_KEY_LOCATION_LOCAL_STORAGE`)
This storage location is defined by PSA as `PSA_KEY_LOCATION_LOCAL_STORAGE` and
is assigned the value of `0`. Keys that are assigned this location are
transparent, so readable in plain text.

## Other Key Locations (`PSA_KEY_LOCATION_xxx`)
Some drivers may define additional, driver-specific, locations that implement
additional ways of handling opaque key material. Such driver-specific key
locations will be documented in their respective port layer readmes.

# Port Layers
Below is a list of supported port layers with links to their respective readmes.

* [ELE_S200](ele_s200/ele_s200_readme.md)
* CAAM (to be added)
* Casper / Hashcrypt (to be added)
* DCP (to be added)
* ELA_CSEC (to be added)
* [ELE_HSEB](ele_hseb/ele_hseb_readme.md)
* ELE_S4XX (to be added)
* SGI (to be added)
* ELS_PKC (to be added)
