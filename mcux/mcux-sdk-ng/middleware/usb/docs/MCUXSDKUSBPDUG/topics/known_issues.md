# Known issues

Five issues were found during the Ellisys compliance test as shown below.

-   Hardware: Ellisys EX350
-   Software: Ellisys USB Explorer 350 Examiner 3.1.8098

**Issue 1: TD 4.3.1 Sink Connect Source**

**Issue 2: TD 4.3.2 Sink Connect DRP**

**Issue 3: TD 4.3.3 Sink Connect Try.SRC DRP**

**Issue 4: TD 4.3.4 TD 4.3.4 Sink Connect Try.SNK DRP**

**Issue 5: COMMON.CHECK.PD.10**

For issues 1-4, these items will fail when using the consumer\_provider and displayport\_dock VIF file. The om13790host and om13790dock have these failures and om13588 does not have these failures. The reason for these failures is that Ellisys EX350 will pull up a 5 V pulse with a fast rising edge on CC lines before starting testing these items, which triggers NX20P0407 OVP protection. NX20P0407 is USB Type C CC and SBU Protection IC. To pass these test items, solder a 100pF capacitor between CC lines and ground at the connector to slow down the fast rising edge as a workaround. We are working with Ellisys to eliminate this 5 V pulse.

For issue 5, this item fails because of the conflict between PD 3.0 and PD 3.1. The current Ellisys EX350 Examiner does the compliance test based on the PD 3.1 although the vendor info specifies the PD 3.0. The data size of the related message is different for PD 3.0 and PD 3.1. For details, see the specifications.

