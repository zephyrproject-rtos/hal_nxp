/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSCP_H
#define FSL_SSCP_H

#include <stddef.h>
#include "fsl_sscp_commands.h"

/*!
@defgroup sscp Security Subsystem Communication Protocol (SSCP)

    # SSCP protocol description

    SSCP is very simple remote procedure call protocol.
    Function parameters are described by one or multiple SSCP operation descriptor(s).
    One parameter descriptor describes up to 7 function parameters as contexts, buffers, values or aggregates.
    Multiple parameter descriptors can be linked by the aggregate parameter type (kSSCP_ParamType_Aggregate).

    Function arguments are described as a buffer (address and size), a value (a tuple of two words),
    a context (pointer and type id) or an aggregate.
    If the parameter is the aggregate (kSSCP_ParamType_Aggregate type), then it will contain a pointer to another
    sscp_operation_t. This allows to link additional sscp_operation_t.

    The protocol allows for remote calling by a copy of all arguments (including buffer contents),
    that is, to remote call to a sub-system having no physical access to Host CPU memory.
    If a sub-system has access to Host CPU memory, the SSCP transport implementation can decide to transfer
    only the buffer descriptor (pointer and size) without physically transmitting the buffer content,
    as the buffer content can be accessed by the sub-system when the remote function executes.
    The same holds for the context descriptor (pointer and type id). The actual SSCP implementation
    can transfer only pointer to a sub-system, if the sub-system has access to the memory, where the context data
    structure is located, and if it has an application level knowledge of the context data structure
    layout (either based on the command id or the context type id).

    Byte length (for void* and uintptr_t) and endianess is inherited from the host CPU.

    # SSCP operation descriptors

    A remote function is invoked by transmitting a command id (unique identifier to specify a remote function),
    followed by SSCP operation descriptors ::sscp_operation_t. There is always one descriptor and optionally
    it can link another descriptor, if the number of ::sscp_operation_t params is not sufficient
    to described all function parameters. In the example below, the last params[n-1] on the left side is an aggregate
    that links secondary descriptor.

    @code
    command
    paramTypes
    params[0]
    ...
    params[n-1] ------------- paramTypes
                              params[0]
                              ...
                              params[n-1]
    @endcode

    where n = 1, 2, ..., 7.

    These operation descriptors serve as an input to ::sscp_invoke_command() function.
    The serialization to the communication system is implementation specific.
    For example, implementations may decide to transfer only pointers and values (without payloads),
    because security sub-system has access to memory, so it can read and write payloads on its own during function
    execution. Other implementations may need to serialize everything to a communication bus.

    This implementation specific data transfer is implemented by an invoke() function.
    During implementation specific initialization of the SSCP transfer, sscp_<Implementation>_init() function,
    a pointer to implementation specific invoke() function is stored in the sscp_<Implementation>_context_t.

    @code
      sscp_mu_init(ctx, invoke = sscp_mu_invoke_command)
      ...
      ctx->invoke()
      ...
      ctx->invoke()
      ...
      sscp_deinit(ctx)
    @endcode

    # Example for SSCP protocol implementation with ELEMU

    The ::sscp_invoke_command() implementation for the ELEMU (Sentinel), ::sscp_mu_invoke_command(),
    builds up the serial message as follows:

      word 0 | word 1    | word 2      | word 3      | ... | word (n*2 + 1)
      -------|-----------|-------------|-------------|-----|---------------
      CMD    |paramTypes | params[0].a | params[0].b | ... | params[n-1].b

    where the n value is CMD specific and it is present in the CMD word.
    Passing this message through ELEMU to the ELE sub-system is done by simply moving the 16 words into ELEMU Tx A
    registers.

    # Example with the SSS API

    @code
      sss_status_t sss_aead_one_go(sss_aead_t *context,
                                   const uint8_t *srcData,
                                   uint8_t *destData,
                                   size_t size,
                                   uint8_t *nonce,
                                   size_t nonceLen,
                                   const uint8_t *aad,
                                   size_t aadLen,
                                   uint8_t *tag,
                                   size_t tagLen);

      uint32_t cmd = kSSCP_CMD_SSS_AeadOneGo(n=6);

      sscp_operation_t op = (0);
      sscp_status_t status = kStatus_SSCP_Fail;
      uint32_t ret = 0;

      if (context->mode == Encrypt)
      {
          op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_MemrefOutput,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_MemrefOutput,
                                            kSSCP_ParamType_None);
      }
      else
      {
          op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_MemrefOutput,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_MemrefInput,
                                            kSSCP_ParamType_None);
      }

      ... context is an aggregate data type ...
      ... implementation specific sscp_operation_t to serialize the context data ...
      op.params[0].context.ptr = context;
      op.params[0].context.type = kSSCP_ParamContextType_SSS_Aead;

      ... function parameters ...
      op.params[1].memref.buffer = srcData;
      op.params[1].memref.size = size;

      op.params[2].memref.buffer = destData;
      op.params[2].memref.size = size;

      op.params[3].memref.buffer = nonce;
      op.params[3].memref.size = nonceLen;

      op.params[4].memref.buffer = aad;
      op.params[4].memref.size = aadLen;

      op.params[5].memref.buffer = tag;
      op.params[5].memref.size = tagLen;

      ... Serialize to the link ...
      status = context->session->sscp->invoke(context->sscpSession, cmd, &op, &ret);
      if (status != kStatus_SSCP_Success)
      {
          return kStatus_SSS_Fail;
      }

      return (sss_status_t)ret;

    @endcode

    # Example with the TEE Client API

      @code
      TEEC_Result TEEC_InvokeCommand(TEEC_Session *sessionTEEC,
                                     uint32_t commandID,
                                     TEEC_Operation *operation,
                                     uint32_t *returnOrigin);


      uint32_t cmd = kSSCP_CMD_TEEC_InvokeCommand;

      sscp_operation_t op = {0};
      sscp_status_t status = kStatus_SSCP_Fail;
      uint32_t ret = 0;

      op.paramTypes = SSCP_OP_SET_PARAM(kSSCP_ParamType_ContextReference,
                                        kSSCP_ParamType_ValueInput,
                                        kSSCP_ParamType_ContextReference,
                                        kSSCP_ParamType_MemrefOutput,
                                        kSSCP_ParamType_None,
                                        kSSCP_ParamType_None,
                                        kSSCP_ParamType_None);

      op.params[0].context.ptr = sessionTEEC;
      op.params[0].context.type = kSSCP_ParamContextType_TEEC_Session;

      op.params[1].value.a = commandID;
      op.params[1].value.b = 0;

      op.params[2].context.ptr = operation;
      op.params[2].context.type = kSSCP_ParamContextType_TEEC_Operation;

      op.params[3].memref.buffer = returnOrigin;
      op.params[3].memref.size = sizeof(*returnOrigin);

      @endcode
 */

/*!
 * @addtogroup sscp
 * @{
 */

/*! @brief Maximum number of parameters to be supported in one sscp_operation_t */
#define SSCP_OPERATION_PARAM_COUNT   (7u)
#define SSCP_OPERATION_RESULTS_COUNT (2u)

/*! @brief Default SSCP context is a pointer to memory. */
#ifndef SSCP_MAX_CONTEXT_SIZE
#define SSCP_MAX_CONTEXT_SIZE (sizeof(void *))
#endif

/*! @brief Set parameter types for the SSCP operation. Each param type is encoded into 4-bits bit field. */
#define SSCP_OP_SET_PARAM(p0, p1, p2, p3, p4, p5, p6)                                                   \
    (((uint32_t)(p0)&0xFu) << 0) | (((uint32_t)(p1)&0xFu) << 4) | (((uint32_t)(p2)&0xFu) << 8) |        \
        (((uint32_t)(p3)&0xFu) << 12) | (((uint32_t)(p4)&0xFu) << 16) | (((uint32_t)(p5)&0xFu) << 20) | \
        (((uint32_t)(p6)&0xFu) << 24)

/*! @brief Set parameter types for the SSCP operation. Each param type is encoded into 4-bits bit field. */
#define SSCP_OP_SET_RESULT(p0) (((uint32_t)(p0)&0xFu) << 0)

/*! @brief Decode i-th parameter as 4-bit unsigned integer. */
#define SSCP_OP_GET_PARAM(i, paramTypes) ((((uint32_t)(paramTypes)) >> (i)*4u) & 0xFu)

/*! @brief Compile time sizeof() check */
#if 0
#define SSCP_BUILD_ASSURE(condition, msg) extern int(msg)[1 - 2 * (!(condition))] __attribute__((unused))
#else
#define SSCP_BUILD_ASSURE(condition, msg)
#endif

/**
 * @brief Definitions with return values from SSCP functions
 */
typedef uint32_t sscp_status_t;
#define kStatus_SSCP_Success      ((sscp_status_t)0x10203040u)
#define kStatus_SSCP_Fail         ((sscp_status_t)0x40302010u)
#define kStatus_SSCP_ResourceBusy ((sscp_status_t)0x40302020u)

typedef struct sscp_context sscp_context_t;

/**
 * @brief SSCP operation descriptor
 *
 */
typedef struct sscp_operation sscp_operation_t;

/*! @brief Typedef for a function that sends a command and associated parameters to security sub-system
 *
 *  The commandID and operation content is serialized and sent over to the selected security sub-system.
 *  This is implementation specific function.
 *  The function can invoke both blocking and non-blocking secure functions in the selected security sub-system.
 *
 * @param context Initialized SSCP context
 * @param commandID Command - an id of a remote secure function to be invoked
 * @param op Description of function arguments as a sequence of buffers, values, context references and aggregates
 * @param ret Return code of the remote secure function (application layer return value)
 *
 * @returns Status of the operation
 * @retval kStatus_SSCP_Success A blocking command has completed or a non-blocking command has been accepted.
 * @retval kStatus_SSCP_Fail Operation failure, for example hardware fail.
 * @retval kStatus_SSCP_InvalidArgument One of the arguments is invalid for the function to execute.
 */
typedef sscp_status_t (*fn_sscp_invoke_command_t)(sscp_context_t *context,
                                                  sscp_command_t commandID,
                                                  sscp_operation_t *op,
                                                  uint32_t *ret);

/**
 * struct _sscp_context - SSCP context struct
 *
 * This data type is used to keep context of the SSCP link.
 * It has one mandatory member - pointer to invoke() function.
 * Otherwise it is completely implementation specific.
 *
 * @param invoke Pointer to implementation specific invoke() function
 * @param context Container for the implementation specific data.
 */
struct sscp_context
{
    fn_sscp_invoke_command_t invoke;
    /*sscp_status_t (*sscp_invoke_command)(sscp_context_t *context, uint32_t commandID, sscp_operation_t *op);*/

    /*! Implementation specific part */
    struct
    {
        uint8_t data[SSCP_MAX_CONTEXT_SIZE];
    } context;
};

/**
 * struct _sscp_memref - Buffer
 *
 * This data type is used to describe a function argument as a buffer.
 *
 * @param buffer Memory address
 * @param size Length of the buffer in bytes
 */
typedef struct
{
    uintptr_t buffer;
    size_t size;
} sscp_memref_t;

/**
 * struct sscp_value_t - Small raw data
 *
 * This data type is used to describe a function argument as a tuple of two 32-bit values.
 *
 * @param a First 32-bit data value.
 * @param b Second 32-bit data value.
 */
typedef struct
{
    uint32_t a;
    uint32_t b;
} sscp_value_t;

/**
 * @brief SSCP descriptor for an aggregate
 *
 * This data type is used to link additional SSCP operation.
 *
 * @param op Pointer to sscp_operation_t.
 */
typedef struct
{
    sscp_operation_t *op;
} sscp_aggregate_operation_t;

/**
 * @brief SSCP descriptor for a context struct
 *
 * This data type is used pass context struct to SSCP by reference
 *
 * @param ptr Pointer to a data structure
 * @param type 32-bit identifier specifying context struct type
 */
typedef struct
{
    void *ptr;
    uint32_t type;
} sscp_context_reference_t;

/**
 * @brief Data structure representing a function argument.
 *
 * Either the client uses a shared memory reference, or a small raw
 * data container.
 *
 * @param value Small raw data container
 * @param memref Memory reference
 * @param aggregate Reference to another SSCP descriptor
 * @param context Pointer to a data struct to be passed to SSCP by reference
 */
typedef union
{
    sscp_value_t value;
    sscp_memref_t memref;
    sscp_aggregate_operation_t aggregate;
    sscp_context_reference_t context;
} sscp_parameter_t;

/**
 * @brief Data structure describing function arguments.
 * Function argument are described as a sequence of buffers, values, context references and aggregates.
 * It serves as an input to ::sscp_invoke_command(), an implementation specific serialization function.
 *
 * @param   paramTypes  Type of data passed.
 * @param   params      Array of parameters of type sscp_parameter_t.
 *
 */
struct sscp_operation
{
    uint32_t paramTypes;
    sscp_parameter_t params[SSCP_OPERATION_PARAM_COUNT];
    uint32_t resultTypes;
    uint32_t resultCount;
    sscp_parameter_t result[SSCP_OPERATION_RESULTS_COUNT];
};

/**
 * @brief Enum with SSCP operation parameters.
 */
typedef uint32_t sscp_param_types_t;
#define kSSCP_ParamType_None      ((sscp_param_types_t)0x0u) /*! Parameter not in use */
#define kSSCP_ParamType_Aggregate ((sscp_param_types_t)0x1u) /*! Link to another ::sscp_operation_t */
#define kSSCP_ParamType_ContextReference \
    ((sscp_param_types_t)0x2u)                               /*! Reference to a context structure - pointer and type */
#define kSSCP_ParamType_MemrefInputNoSize                                                                      \
    ((sscp_param_types_t)0x3u) /*! Reference to a memory buffer - input to remote function or service, no size \
                                  specified */
#define kSSCP_ParamType_MemrefOutputNoSize                                                                      \
    ((sscp_param_types_t)0x4u) /*! Reference to a memory buffer - output by remote function or service, no size \
                                  specified.*/
#define kSSCP_ParamType_MemrefInput \
    ((sscp_param_types_t)0x5u) /*! Reference to a memory buffer - input to remote function or service */
#define kSSCP_ParamType_MemrefOutput                                                                           \
    ((sscp_param_types_t)0x6u) /*! Reference to a memory buffer - output by remote function or service.        \
                                  Implementations shall update the size member of the ::sscp_memref_t with the \
                                  actual number of bytes written. */
#define kSSCP_ParamType_MemrefInOut                                                                                  \
    ((sscp_param_types_t)0x7u) /*! Reference to a memory buffer - input to and ouput from remote function or service \
                                */
#define kSSCP_ParamType_ValueInputTuple \
    ((sscp_param_types_t)0x8u) /*! Tuple of two 32-bit integers  - input to remote function or service */
#define kSSCP_ParamType_ValueOutputTuple \
    ((sscp_param_types_t)0x9u) /*! Tuple of two 32-bit integers - output by remote function or service */
#define kSSCP_ParamType_ValueInputSingle \
    ((sscp_param_types_t)0xau) /*! One 32-bit integers  - input to remote function or service */
#define kSSCP_ParamType_ValueOutputSingle \
    ((sscp_param_types_t)0xbu) /*! One 32-bit integers - output by remote function or service */

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*! @brief Sends a command and associated parameters to security sub-system
 *
 *  The commandID and operation content is serialized and sent over to the selected security sub-system.
 *  This is implementation specific function.
 *  The function can invoke both blocking and non-blocking secure functions in the selected security sub-system.
 *
 * @param context Initialized SSCP context
 * @param commandID Command - an id of a remote secure function to be invoked
 * @param op Description of function arguments as a sequence of buffers and values
 * @param ret Return code of the remote secure function (application layer return value)
 *
 * @returns Status of the operation
 * @retval kStatus_SSCP_Success A blocking command has completed or a non-blocking command has been accepted.
 * @retval kStatus_SSCP_Fail Operation failure, for example hardware fail.
 * @retval kStatus_SSCP_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sscp_status_t sscp_invoke_command(sscp_context_t *context, uint32_t commandID, sscp_operation_t *op, uint32_t *ret);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */ /* end of sscp */

#endif /* FSL_SSCP_H */
