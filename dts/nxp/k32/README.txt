How to generate qn9090-pinctrl.h

1. Generate SDK for qn9090DK6 at https://mcuxpresso.nxp.com/en/dashboard
2. Download MCUXPresso Config Tools (select v13) as .zip
3. Apply patch to mcux/scripts/pinctrl/gen_soc_headers.py :
------------------------------------------
--- a/mcux/scripts/pinctrl/gen_soc_headers.py
+++ b/mcux/scripts/pinctrl/gen_soc_headers.py
@@ -72,6 +72,9 @@ def processor_to_controller(processor_name):
     if "LPC55" in processor_name:
         # LPC config tools
         return 'IOCON'
+    if "QN90" in processor_name:
+        # LPC config tools
+        return 'IOCON'
     if "MK" in processor_name:
         # Kinetis config tools
         return 'PORT'
------------------------------------------

4. Run script
------------------------------------------
python3 gen_soc_headers.py <PATH>/SDK_2.6.12_QN9090DK6_ConfigTools_data.zip
------------------------------------------

5. Two headers are generated: QN9090HN-pinctrl.h and QN9090THN-pinctrl.h - they seem to be identical
6. Copy header to hal_nxp/dts/nxp/k32
------------------------------------------
mv QN9090HN-pinctrl.h ../../../dts/nxp/k32/qn9090-pinctrl.h
------------------------------------------
