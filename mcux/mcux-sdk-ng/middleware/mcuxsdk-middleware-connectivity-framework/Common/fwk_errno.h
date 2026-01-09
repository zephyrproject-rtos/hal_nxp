/*!
 * Copyright 2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_errno.h
 * \brief this header aims to map std and posix errno to all toolchains used with the connectivity framework.
 *
 */

#ifndef _FWK_ERRNO_H_
#define _FWK_ERRNO_H_

/* C99 only requires to define EDOM, EILSEQ and ERANGE, so only those 3 are guaranteed to be defined by any toolchain
 * GCC defines the POSIX codes, so no need to define them here for this toolchain */
#include <errno.h>

#if defined(__IAR_SYSTEMS_ICC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION)

/* IAR and MDK toolchains don't define POSIX error codes, so we re-define those we need */

#ifndef ENOMEM
#define ENOMEM 12 /* Not enough space */
#endif

#ifndef ENODEV
#define ENODEV 19 /* No such device */
#endif

#ifndef EINVAL
#define EINVAL 22 /* Invalid argument */
#endif

#endif /* defined(__IAR_SYSTEMS_ICC__) || defined(__CC_ARM) || defined(__ARMCC_VERSION) */

#endif /* _FWK_ERRNO_H_ */
