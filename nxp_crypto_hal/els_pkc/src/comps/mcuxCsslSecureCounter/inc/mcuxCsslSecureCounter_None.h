/*--------------------------------------------------------------------------*/
/* Copyright 2020-2024 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

/**
 * \file  mcuxCsslSecureCounter_None.h
 * \brief Implementation that disables the CSSL secure counter mechanism.
 */

#ifndef MCUXCSSLSECURECOUNTER_NONE_H_
#define MCUXCSSLSECURECOUNTER_NONE_H_

/**
 * \addtogroup mcuxCsslIMPL MCUX CSSL -- Implementations
 *
 * \defgroup mcuxCsslSecureCounter_None Secure Counter: Disabled
 * \brief Disable the secure counter mechanism.
 * \ingroup mcuxCsslIMPL
 */


/**
 * \defgroup scNoneCore Secure counter core functionality
 * \brief Secure counter handling core functionality.
 * \ingroup mcuxCsslSecureCounter_None
 *
 * \todo Extend this description of the core functionality.
 */

/****************************************************************************/
/* Constants                                                                */
/****************************************************************************/

/**
 * \def MCUX_CSSL_SC_CHECK_PASSED_IMPL
 * \brief Positive comparison result value.
 * \ingroup scNoneCore
 */
#define MCUX_CSSL_SC_CHECK_PASSED_IMPL (0xA5A5A5A5u)

/**
 * \def MCUX_CSSL_SC_CHECK_FAILED_IMPL
 * \brief Negative comparison result value.
 * \ingroup scNoneCore
 */
#define MCUX_CSSL_SC_CHECK_FAILED_IMPL (~ MCUX_CSSL_SC_CHECK_PASSED_IMPL)

/**
 * \def MCUX_CSSL_SC_COUNTER_TYPE_IMPL
 * \brief Data type used for the secure counter.
 * \ingroup scNoneCore
 */
#define MCUX_CSSL_SC_COUNTER_TYPE_IMPL \
  uint32_t

/**
 * \def MCUX_CSSL_SC_VALUE_TYPE_IMPL
 * \brief Data type used for the secure counter values.
 * \ingroup scNoneCore
 */
#define MCUX_CSSL_SC_VALUE_TYPE_IMPL \
  static const uint32_t

/**
 * \def MCUX_CSSL_SC_BALANCING_VALUE_TYPE_IMPL
 * \brief Data type used for properly casting the secure counter balancing values.
 * \ingroup scNoneCore
 */
#define MCUX_CSSL_SC_BALANCING_VALUE_TYPE_IMPL \
  uint32_t

/****************************************************************************/
/* Initialization                                                           */
/****************************************************************************/

/**
 * \def MCUX_CSSL_SC_ALLOC_IMPL
 * \brief Allocation operation implementation for the secure counter.
 * \ingroup scNoneCore
 */
#define MCUX_CSSL_SC_ALLOC_IMPL() \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_INIT_IMPL
 * \brief Initialization operation implementation for the secure counter.
 * \ingroup scNoneCore
 *
 * \param value Value with which the secure counter must be initialized.
 */
#define MCUX_CSSL_SC_INIT_IMPL(value) \
  /* intentionally empty */

/****************************************************************************/
/* Check                                                                    */
/****************************************************************************/

/**
 * \def MCUX_CSSL_SC_CHECK_IMPL
 * \brief Comparison operation implementation for the secure counter.
 * \ingroup scNoneCore
 *
 * \param reference Reference value to compare the secure counter value against (unused).
 * \return          Always #MCUX_CSSL_SC_CHECK_PASSED.
 */
#define MCUX_CSSL_SC_CHECK_IMPL(reference) \
  (MCUX_CSSL_SC_CHECK_PASSED_IMPL)

/****************************************************************************/
/* Counter increment                                                        */
/****************************************************************************/
/**
 * \defgroup scNoneInc Secure counter increment
 * \brief Support for incrementing the secure counter.
 * \ingroup mcuxCsslSecureCounter_None
 */

/**
 * \def MCUX_CSSL_SC_ADD_IMPL
 * \brief Increment the secure counter with \p value.
 * \ingroup scNoneInc
 *
 * \see MCUX_CSSL_SC_SUB_IMPL
 *
 * \param value Value with which the secure counter must be incremented.
 */
#define MCUX_CSSL_SC_ADD_IMPL(value) \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_ADD_ON_CALL_IMPL
 * \brief Increment the secure counter with \p value in case of function call.
 * \ingroup scNoneInc
 *
 * \see MCUX_CSSL_SC_ADD_IMPL
 *
 * \param value Value with which the secure counter must be incremented.
 */
#define MCUX_CSSL_SC_ADD_ON_CALL_IMPL(value) \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_ADD_0X1_IMPL
 * \brief Increment the secure counter with 0x1.
 * \ingroup scNoneInc
 *
 * \see MCUX_CSSL_SC_ADD_IMPL
 */
#define MCUX_CSSL_SC_ADD_0X1_IMPL() \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_ADD_0X10_IMPL
 * \brief Increment the secure counter with 0x10.
 * \ingroup scNoneInc
 *
 * \see MCUX_CSSL_SC_ADD_IMPL
 */
#define MCUX_CSSL_SC_ADD_0X10_IMPL() \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_ADD_0X100_IMPL
 * \brief Increment the secure counter with 0x100.
 * \ingroup scNoneInc
 *
 * \see MCUX_CSSL_SC_ADD_IMPL
 */
#define MCUX_CSSL_SC_ADD_0X100_IMPL() \
  /* intentionally empty */

/****************************************************************************/
/* Counter decrement                                                        */
/****************************************************************************/
/**
 * \defgroup scNoneDec Secure counter decrement
 * \brief Support for decrementing the secure counter.
 * \ingroup mcuxCsslSecureCounter_None
 */

/**
 * \def MCUX_CSSL_SC_SUB_IMPL
 * \brief Decrement the secure counter with \p value.
 * \ingroup scNoneDec
 *
 * \see MCUX_CSSL_SC_ADD_IMPL
 *
 * \param value Value with which the secure counter must be decremented.
 */
#define MCUX_CSSL_SC_SUB_IMPL(value) \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_SUB_0X1_IMPL
 * \brief Decrement the secure counter with 0x1.
 * \ingroup scNoneDec
 *
 * \see MCUX_CSSL_SC_SUB_IMPL
 */
#define MCUX_CSSL_SC_SUB_0X1_IMPL() \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_SUB_0X10_IMPL
 * \brief Decrement the secure counter with 0x10.
 * \ingroup scNoneDec
 *
 * \see MCUX_CSSL_SC_SUB_IMPL
 */
#define MCUX_CSSL_SC_SUB_0X10_IMPL() \
  /* intentionally empty */

/**
 * \def MCUX_CSSL_SC_SUB_0X100_IMPL
 * \brief Decrement the secure counter with 0x100.
 * \ingroup scNoneDec
 *
 * \see MCUX_CSSL_SC_SUB_IMPL
 */
#define MCUX_CSSL_SC_SUB_0X100_IMPL() \
  /* intentionally empty */

/****************************************************************************/
/* Direct access (optional)                                                 */
/****************************************************************************/
/**
 * \defgroup scNoneDirect Secure counter direct access
 * \brief Support for directly accessing the secure counter.
 * \ingroup mcuxCsslSecureCounter_None
 *
 * \warning Access to the secure counter is generally restricted, and generic
 * access might not be allowed.
 */

/**
 * \def MCUX_CSSL_SC_VALUE_IMPL
 * \brief Access operation for the current secure counter value.
 * \ingroup scNoneDirect
 *
 * \warning Access to the secure counter is generally restricted, and generic
 * access might not be allowed. For portable code it is best to only rely on
 * the check operation to verify the secure counter value.
 *
 * \return The current value of the secure counter.
 */
#define MCUX_CSSL_SC_VALUE_IMPL() \
  1/0 /* not supported */

/**
 * \def MCUX_CSSL_SC_ASSIGN_IMPL
 * \brief Assignment operation for the secure counter.
 * \ingroup scNoneDirect
 *
 * \warning Access to the secure counter is generally restricted, and generic
 * assignment might not be allowed. For portable code it is best to only rely
 * on the initialization, increment and decrement operations to change the
 * secure counter value.
 *
 * \param value Value that needs to be assigned to the secure counter.
 */
#define MCUX_CSSL_SC_ASSIGN_IMPL(value) \
  /* intentionally empty */


#endif /* MCUXCSSLSECURECOUNTER_NONE_H_ */
