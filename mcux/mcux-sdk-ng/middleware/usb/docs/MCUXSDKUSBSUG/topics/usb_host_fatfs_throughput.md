# USB host FatFs throughput

The following test is based on usb\_host\_msd\_fatfs, bm, IAR, release target.

| |Test device - Sandisk extreme USB3.0 64G SDCZ80 - 64G|
|--|-----------------------------------------------------|
|**Controller**|**Write speed**|**Read speed**|
|RT1050 EHCI|~32163 KB/s|~38509 KB/s|
|K28FA KHCI|~913 KB/s|~932 KB/s|
|LPCXpresso54628 IP3516|~22034 KB/s|~22489 KB/s|
|LPCXpresso54628 OHCI|~860 KB/s|~970 KB/s|

