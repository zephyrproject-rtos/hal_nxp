/*
 * Copyright (c) 2014, Mentor Graphics Corporation
 * Copyright (c) 2015 Xilinx, Inc.
 * Copyright (c) 2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * Copyright 2021 ACRIOS Systems s.r.o.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "rpmsg_lite.h"
#include "rpmsg_queue.h"

int32_t rpmsg_queue_rx_cb(void *payload, uint32_t payload_len, uint32_t src, void *priv)
{
    rpmsg_queue_rx_cb_data_t msg;

    RL_ASSERT(priv != RL_NULL);

    msg.data = payload;
    msg.len  = payload_len;
    msg.src  = src;

    /* if message is successfully added into queue then hold rpmsg buffer */
    if (0 != env_put_queue(priv, &msg, 0))
    {
        /* hold the rx buffer */
        return RL_HOLD;
    }

    return RL_RELEASE;
}

#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
rpmsg_queue_handle rpmsg_queue_create(struct rpmsg_lite_instance *rpmsg_lite_dev,
                                      uint8_t *queue_storage,
                                      rpmsg_static_queue_ctxt *queue_ctxt)
#else
rpmsg_queue_handle rpmsg_queue_create(struct rpmsg_lite_instance *rpmsg_lite_dev)
#endif
{
    int32_t status;
    void *q = RL_NULL;

    if (rpmsg_lite_dev == RL_NULL)
    {
        return RL_NULL;
    }

    /* create message queue for channel default endpoint */
#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
    if ((queue_storage == RL_NULL) || (queue_ctxt == RL_NULL))
    {
        return RL_NULL;
    }
    status = env_create_queue(&q, 2 * (int32_t)(rpmsg_lite_dev->rvq->vq_nentries),
                              (int32_t)sizeof(rpmsg_queue_rx_cb_data_t), queue_storage, queue_ctxt);
#else
    status = env_create_queue(&q, 2 * (int32_t)(rpmsg_lite_dev->rvq->vq_nentries),
                              (int32_t)sizeof(rpmsg_queue_rx_cb_data_t));
#endif
    if ((status != 0) || (q == RL_NULL))
    {
        return RL_NULL;
    }

    return ((rpmsg_queue_handle)q);
}

int32_t rpmsg_queue_destroy(struct rpmsg_lite_instance *rpmsg_lite_dev, rpmsg_queue_handle q)
{
    if (rpmsg_lite_dev == RL_NULL)
    {
        return RL_ERR_PARAM;
    }

    if (q == RL_NULL)
    {
        return RL_ERR_PARAM;
    }
    env_delete_queue((void *)q);
    return RL_SUCCESS;
}

int32_t rpmsg_queue_recv(struct rpmsg_lite_instance *rpmsg_lite_dev,
                         rpmsg_queue_handle q,
                         uint32_t *src,
                         char *data,
                         uint32_t maxlen,
                         uint32_t *len,
                         uintptr_t timeout)
{
    rpmsg_queue_rx_cb_data_t msg = {0};
    int32_t retval               = RL_SUCCESS;

    if (rpmsg_lite_dev == RL_NULL)
    {
        return RL_ERR_PARAM;
    }
    if (q == RL_NULL)
    {
        return RL_ERR_PARAM;
    }
    if (data == RL_NULL)
    {
        return RL_ERR_PARAM;
    }

    /* Get an element out of the message queue for the selected endpoint */
    if (0 != env_get_queue((void *)q, &msg, timeout))
    {
        if (src != RL_NULL)
        {
            *src = msg.src;
        }
        if (len != RL_NULL)
        {
            *len = msg.len;
        }

        if (maxlen >= msg.len)
        {
            env_memcpy(data, msg.data, msg.len);
        }
        else
        {
            retval = RL_ERR_BUFF_SIZE;
        }

        /* Release used buffer. */
        return ((RL_SUCCESS == rpmsg_lite_release_rx_buffer(rpmsg_lite_dev, msg.data)) ? retval : RL_ERR_PARAM);
    }
    else
    {
        return RL_ERR_NO_BUFF; /* failed */
    }
}

int32_t rpmsg_queue_recv_nocopy(struct rpmsg_lite_instance *rpmsg_lite_dev,
                                rpmsg_queue_handle q,
                                uint32_t *src,
                                char **data,
                                uint32_t *len,
                                uintptr_t timeout)
{
    rpmsg_queue_rx_cb_data_t msg = {0};

    if (rpmsg_lite_dev == RL_NULL)
    {
        return RL_ERR_PARAM;
    }
    if (data == RL_NULL)
    {
        return RL_ERR_PARAM;
    }
    if (q == RL_NULL)
    {
        return RL_ERR_PARAM;
    }

    /* Get an element out of the message queue for the selected endpoint */
    if (0 != env_get_queue((void *)q, &msg, timeout))
    {
        if (src != RL_NULL)
        {
            *src = msg.src;
        }
        if (len != RL_NULL)
        {
            *len = msg.len;
        }

        *data = msg.data;

        return RL_SUCCESS; /* success */
    }

    return RL_ERR_NO_BUFF; /* failed */
}

int32_t rpmsg_queue_nocopy_free(struct rpmsg_lite_instance *rpmsg_lite_dev, void *data)
{
    if (rpmsg_lite_dev == RL_NULL)
    {
        return RL_ERR_PARAM;
    }
    if (data == RL_NULL)
    {
        return RL_ERR_PARAM;
    }

    /* Release used buffer. */
    return ((RL_SUCCESS == rpmsg_lite_release_rx_buffer(rpmsg_lite_dev, data)) ? RL_SUCCESS : RL_ERR_PARAM);
}

int32_t rpmsg_queue_get_current_size(rpmsg_queue_handle q)
{
    if (q == RL_NULL)
    {
        return RL_ERR_PARAM;
    }

    /* Return actual queue size. */
    return env_get_current_queue_size((void *)q);
}
