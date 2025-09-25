;/*
; * Copyright 2020,2025 NXP
; *
; * All rights reserved.
; *
; * SPDX-License-Identifier: BSD-3-Clause
; */

#if defined(__CC_ARM)

        AREA core1_code, DATA, READONLY, PREINIT_ARRAY, ALIGN=3
        EXPORT core1_image_start
        EXPORT core1_image_end
core1_image_start
        INCBIN core1_image.bin
core1_image_end
#if CONFIG_UTILITY_INCBIN_NS == 1
        AREA core1_ns_code, DATA, READONLY, PREINIT_ARRAY, ALIGN=3
        EXPORT core1_ns_image_start
        EXPORT core1_ns_image_end
core1_ns_image_start
        INCBIN core1_ns_image.bin
core1_ns_image_end
#endif /* CONFIG_UTILITY_INCBIN_NS == 1 */
        END

#elif defined(__GNUC__) || defined(__ARMCC_VERSION)

        .section .core1_code, "ax" @progbits @preinit_array
        .global core1_image_start
        .type core1_image_start, %object
        .align 4
core1_image_start:
        .incbin "core1_image.bin"
        .global core1_image_end
        .type core1_image_end, %object
core1_image_end:
        .global core1_image_size
        .type core1_image_size, %object
        .align 4
core1_image_size:
        .int  core1_image_end - core1_image_start
#if CONFIG_UTILITY_INCBIN_NS == 1
        .section .core1_ns_code, "ax" @progbits @preinit_array
        .global core1_ns_image_start
        .type core1_ns_image_start, %object
        .align 4
core1_ns_image_start:
        .incbin "core1_ns_image.bin"
        .global core1_ns_image_end
        .type core1_ns_image_end, %object
core1_ns_image_end:
        .global core1_ns_image_size
        .type core1_ns_image_size, %object
        .align 4
core1_ns_image_size:
        .int  core1_ns_image_end - core1_ns_image_start
#endif /* CONFIG_UTILITY_INCBIN_NS == 1 */
        .end

#endif
