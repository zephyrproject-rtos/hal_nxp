Command for driver wrapper generation:

python <SDK_root>/middleware/mbedtls/tf-psa-crypto/scripts/generate_driver_wrappers.py                                   \
--template-dir <SDK_root>/components/psa_crypto_driver/generated_files_tf_psa_crypto/scripts/data_files/driver_templates \
--json-dir <SDK_root>/components/psa_crypto_driver/generated_files_tf_psa_crypto/scripts/data_files/driver_jsons         \
<SDK_root>/components/psa_crypto_driver/generated_files_tf_psa_crypto