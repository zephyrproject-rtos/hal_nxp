/** @file wm_mbedtls_net.c
 *
 *  @brief This file ports mbedtls net related APIs
 *
 *  Copyright 2008-2020 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <lwip/sockets.h>
#include <wmerrno.h>
#include <wm_mbedtls_debug.h>

#include <mbedtls/ssl.h>

#include "wm_mbedtls_net.h"

/* Read at most 'len' characters */
static int wm_mbedtls_net_recv(void *ctx, unsigned char *buf, size_t len)
{
    int ret;
    int fd = (int)ctx;

    if (fd < 0)
        return MBEDTLS_ERR_NET_INVALID_CONTEXT;

    ret = (int)read(fd, buf, len);

    if (ret < 0)
    {
        if (lwip_fcntl(fd, F_GETFL, 0) != 0)
            return MBEDTLS_ERR_SSL_WANT_READ;

        if (errno == EPIPE || errno == ECONNRESET)
            return MBEDTLS_ERR_NET_CONN_RESET;

        if (errno == EINTR)
            return MBEDTLS_ERR_SSL_WANT_READ;

        return MBEDTLS_ERR_NET_RECV_FAILED;
    }

    return ret;
}

/*
 * Read at most 'len' characters, blocking for at most 'timeout' ms
 */
static int wm_mbedtls_net_recv_timeout(void *ctx, unsigned char *buf, size_t len, uint32_t timeout)
{
    int ret;
    int fd = (int)ctx;

    if (fd < 0)
        return MBEDTLS_ERR_NET_INVALID_CONTEXT;

    /*------------------------------------------------------------
     * Get previous timeout on socket before receive.
     * This value will be used to restore timeout on socket.
     */
#if LWIP_SO_SNDRCVTIMEO_NONSTANDARD
    uint32_t previous_timeout = 0;
    socklen_t timeout_len 	= sizeof(previous_timeout);
    uint32_t timo = timeout;
    socklen_t timo_len	= sizeof(timo);
#else
    struct timeval previous_timeout = {0, 0};
    socklen_t timeout_len	= sizeof(previous_timeout);
    struct timeval timo = {timeout / 1000, (timeout % 1000) * 1000};
    socklen_t timo_len	= sizeof(timo);
#endif

    if (WM_SUCCESS != getsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &previous_timeout, &timeout_len))
    {
        wm_mbedtls_e("Failed to get previous socket timeout");
        return -WM_FAIL;
    }

    /*------------------------------------------------------------
     * Set timeout on socket before receive
     */
    if (WM_SUCCESS != setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &timo, timo_len))
    {
        wm_mbedtls_e(
            "Failed to set socket "
            "timeout: %d",
            timeout);
        return -WM_FAIL;
    }
    /*------------------------------------------------------------
     */
    /* This call will not block */
    ret = wm_mbedtls_net_recv(ctx, buf, len);

    /*------------------------------------------------------------
     * Restore previous timeout on socket
     */
    if (WM_SUCCESS != setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &previous_timeout, timeout_len))
    {
        wm_mbedtls_e(
            "Failed to restore previous socket "
            "timeout: %d",
            previous_timeout);
        return -WM_FAIL;
    }
    /*------------------------------------------------------------
     */
    return ret;
}

/*
 * Write at most 'len' characters
 */
static int wm_mbedtls_net_send(void *ctx, const unsigned char *buf, size_t len)
{
    int ret;
    int fd = (int)ctx;

    if (fd < 0)
        return MBEDTLS_ERR_NET_INVALID_CONTEXT;

    ret = (int)write(fd, buf, len);

    if (ret < 0)
    {
        if (lwip_fcntl(fd, F_GETFL, 0) != 0)
            return MBEDTLS_ERR_SSL_WANT_WRITE;

        if (errno == EPIPE || errno == ECONNRESET)
            return MBEDTLS_ERR_NET_CONN_RESET;

        if (errno == EINTR)
            return MBEDTLS_ERR_SSL_WANT_WRITE;

        return MBEDTLS_ERR_NET_SEND_FAILED;
    }
    return ret;
}

void wm_mbedtls_set_fd(mbedtls_ssl_context *ssl, int fd)
{
    /* Set:
     *
     * socket file descriptor
     * 'send', 'read', 'recv timeout' functions of lwip network stack
     */
    mbedtls_ssl_set_bio(ssl, (void *)fd, (mbedtls_ssl_send_t *)wm_mbedtls_net_send,
                        (mbedtls_ssl_recv_t *)wm_mbedtls_net_recv,
                        (mbedtls_ssl_recv_timeout_t *)wm_mbedtls_net_recv_timeout);
}
