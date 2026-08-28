/*--------------------------------------------------------------------------*/
/* Copyright 2022-2024 NXP                                                  */
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

/** @file  mcuxClBuffer.h
 *  @brief Top-level include file for the @ref mcuxClBuffer component
 *
 *  This includes headers for all of the functionality provided by the @ref mcuxClBuffer component.
 *
 *  @defgroup mcuxClBuffer mcuxClBuffer
 *  @brief Buffer component
 *
 * */

#ifndef MCUXCLBUFFER_H_
#define MCUXCLBUFFER_H_

#include <mcuxClCore_Platform.h>

#include <mcuxClBuffer_Constants.h>

/* Include the actual implementation of the flow protection mechanism. */
#include <mcuxClBuffer_Impl.h>

/**
 * \defgroup clBufInit Buffer initialization functionality
 * \brief Buffer initialization functionality.
 * \ingroup mcuxClBuffer
 *
 * Two sets of default buffer initializations are provided, each with
 * read-only (RO, for mcuxCl_InputBuffer_t) and read-write (RW, for mcuxCl_Buffer_t)
 * variants:
 *  - Plain: basic CPU copy operations (aligned when possible)
 *  - DMA: utilizing DMA peripherals
 *
 * \note The DMA variants will be mapped to plain for buffer implementations
 * that do not support DMA operations.
 *
 * Additionally a custom initializer is provided as well as some aliases
 * that can be used as shorthand notation.
 */

/**
 * \def MCUXCLBUFFER_INIT
 * \brief Initialize an input/output buffer (mcuxCl_Buffer_t).
 * \api
 * \ingroup clBufInit
 *
 * This macro is an alias for \p MCUXCLBUFFER_INIT_RW.
 *
 * \see MCUXCLBUFFER_INIT_RW
 *
 * \param name the name to be used for the buffer variable
 * \param info pointer to a data structure that holds relevant information for the handler
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT(name, info, ptr, size) \
  MCUXCLBUFFER_INIT_RW(name, info, ptr, size)

/**
 * \def MCUXCLBUFFER_INIT_RO
 * \brief Initialize an input buffer (mcuxCl_InputBuffer_t) with plain CPU handling.
 * \api
 * \ingroup clBufInit
 *
 * This macro can be used to initialize an input buffer that will be handled
 * using plain CPU operations.
 *
 * \param name the name to be used for the buffer variable
 * \param info pointer to a data structure that holds relevant information for the handler
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT_RO(name, info, ptr, size) \
  MCUXCLBUFFER_INIT_PLAIN_RO_IMPL(name, info, ptr, size)

/**
 * \def MCUXCLBUFFER_INIT_RW
 * \brief Initialize an input/output buffer (mcuxCl_Buffer_t) with plain CPU handling.
 * \api
 * \ingroup clBufInit
 *
 * This macro can be used to initialize an input/output buffer that will be
 * handled using plain CPU operations.
 *
 * \param name the name to be used for the buffer variable
 * \param info pointer to a data structure that holds relevant information for the handler
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT_RW(name, info, ptr, size) \
  MCUXCLBUFFER_INIT_PLAIN_RW_IMPL(name, info, ptr, size)

/**
 * \def MCUXCLBUFFER_INIT_DMA_RO
 * \brief Initialize an input buffer (mcuxCl_InputBuffer_t) with DMA handling.
 * \api
 * \ingroup clBufInit
 *
 * This macro can be used to initialize an input buffer that will be handled
 * using DMA operations.
 *
 * \note DMA operations are only supported for object-oriented buffer implementations.
 *
 * \param name the name to be used for the buffer variable
 * \param info pointer to a data structure that holds relevant information for the handler
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT_DMA_RO(name, info, ptr, size) \
  MCUXCLBUFFER_INIT_DMA_RO_IMPL(name, info, ptr, size)

/**
 * \def MCUXCLBUFFER_INIT_DMA_RW
 * \brief Initialize an input/output buffer (mcuxCl_Buffer_t) with DMA handling.
 * \api
 * \ingroup clBufInit
 *
 * This macro can be used to initialize an input/output buffer that will be
 * handled using DMA operations.
 *
 * \note DMA operations are only supported for object-oriented buffer implementations.
 *
 * \param name the name to be used for the buffer variable
 * \param info pointer to a data structure that holds relevant information for the handler
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT_DMA_RW(name, info, ptr, size) \
  MCUXCLBUFFER_INIT_DMA_RW_IMPL(name, info, ptr, size)

/**
 * \def MCUXCLBUFFER_INIT_DMA
 * \brief Initialize an input/output buffer (mcuxCl_Buffer_t) with DMA handling.
 * \api
 * \ingroup clBufInit
 *
 * This macro is an alias for \p MCUXCLBUFFER_INIT_RW.
 *
 * \see MCUXCLBUFFER_INIT_RW
 *
 * \param name the name to be used for the buffer variable
 * \param info pointer to a data structure that holds relevant information for the handler
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT_DMA(name, info, ptr, size) \
  MCUXCLBUFFER_INIT_DMA_RW(name, info, ptr, size)

/**
 * \def MCUXCLBUFFER_INIT_CUSTOM
 * \brief Initialize an input/output buffer with custom handler
 * \api
 * \ingroup clBufInit
 *
 * This macro can be used to initialize an input/output buffer with a custom
 * handler.
 *
 * \note Custom handlers are only supported for object-oriented buffer
 * implementations.
 *
 * \param name    the name to be used for the buffer variable
 * \param handler the callback function that will handle the buffer operations
 * \param info    pointer to a data structure that holds relevant information for the handler
 * \param spec    specification of the buffer properties
 * \param ptr     pointer to the memory location of the buffer
 * \param size    size of the buffer - RFU
 */
#define MCUXCLBUFFER_INIT_CUSTOM(name, handler, info, spec, ptr, size) \
  MCUXCLBUFFER_INIT_CUSTOM_IMPL(name, handler, info, spec, ptr, size)

/**
 * \defgroup clBufUpdate Buffer manipulation functionality
 * \brief Input/output buffer manipulation functionality.
 * \ingroup mcuxClBuffer
 */

/**
 * \def MCUXCLBUFFER_UPDATE
 * \brief Update the buffer pointer with the given offset.
 * \api
 * \ingroup clBufUpdate
 *
 * \warning When used inside of a function, MCUXCLBUFFER_UPDATE may have side effects outside of the function call.
 * Therefore, updating a buffer that is passed as function parameter should be avoided.
 * Instead, MCUXCLBUFFER_UPDATE should be used on temporary buffers that have been initialized within a function, or derived from another buffer.
 *
 * \param name   the name of the buffer variable to update.
 * \param offset the amount of bytes that the buffer pointer should be moved.
 */
#define MCUXCLBUFFER_UPDATE(name, offset) \
  MCUXCLBUFFER_UPDATE_IMPL(name, offset)

/**
 * \def MCUXCLBUFFER_DERIVE_RO
 * \brief Derive a new input buffer object from an existing one (updated with the given offset).
 * \api
 * \ingroup clBufUpdate
 *
 * \param name     the name of the buffer variable to create.
 * \param original the name of the buffer variable that will be cloned.
 * \param offset   the amount of bytes that the buffer pointer should be moved.
 */
#define MCUXCLBUFFER_DERIVE_RO(name, original, offset) \
  MCUXCLBUFFER_DERIVE_RO_IMPL(name, original, offset)

/**
 * \def MCUXCLBUFFER_DERIVE_RW
 * \brief Derive a new input/output buffer object from an existing one (updated with the given offset).
 * \api
 * \ingroup clBufUpdate
 *
 * \param name     the name of the buffer variable to create.
 * \param original the name of the buffer variable that will be cloned.
 * \param offset   the amount of bytes that the buffer pointer should be moved.
 */
#define MCUXCLBUFFER_DERIVE_RW(name, original, offset) \
  MCUXCLBUFFER_DERIVE_RW_IMPL(name, original, offset)

/**
 * \def MCUXCLBUFFER_SET
 * \brief Update the buffer pointer the a new memory location.
 * \api
 * \ingroup clBufUpdate
 *
 * \param name the name of the buffer variable to update
 * \param ptr  pointer to the memory location of the buffer
 * \param size size of the buffer - RFU
 */
#define MCUXCLBUFFER_SET(name, ptr, size) \
  MCUXCLBUFFER_SET_IMPL(name, ptr, size)

/**
 * \def MCUXCLBUFFER_GET
 * \brief Get the pointer of the buffer
 * \api
 * \ingroup clBufUpdate
 *
 * \param name the name of the buffer variable
 */
#define MCUXCLBUFFER_GET(name) \
  MCUXCLBUFFER_GET_IMPL(name)

/**
 * \def MCUXCLBUFFER_IS_NULL
 * \brief Check the buffer and its pointer against NULL
 * \api
 * \ingroup clBufUpdate
 *
 * \param name the name of the buffer variable
 */
#define MCUXCLBUFFER_IS_NULL(name) \
  MCUXCLBUFFER_IS_NULL_IMPL(name)


#endif /* MCUXCLBUFFER_H_ */
