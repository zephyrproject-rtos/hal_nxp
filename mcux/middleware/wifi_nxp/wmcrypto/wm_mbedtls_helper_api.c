/** @file wm_mbedtls_helper_api.c
 *
 *  @brief This file provides helper APIs to use mbedtls on marvell platform
 *
 *  Copyright 2008-2020 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_debug_console.h"
#include <mbedtls/x509_crt.h>
#include "mbedtls/timing.h"

#include "wm_mbedtls_net.h"
#include "wm_mbedtls_mem.h"
//#include "wm_mbedtls_threading.h"
#include "wm_mbedtls_entropy.h"
#include "wm_mbedtls_helper_api.h"
//#include "wm_timing_alt.h"
#include <mbedtls/debug.h>
#include <wm_os.h>

#ifdef MBEDTLS_DEBUG_C
#include <string.h>
#endif /* MBEDTLS_DEBUG_C */

static bool wm_mbedtls_lib_inited;

int wm_mbedtls_lib_init()
{
    int ret = 0;
    if (wm_mbedtls_lib_inited)
        return 0;

    // wmtime_init();
    wm_mbedtls_set_mem_alloc();

    if ((ret = wm_mbedtls_entropy_ctr_drbg_setup()) != 0)
        return ret;

    wm_mbedtls_lib_inited = 1;
    return 0;
}

bool is_wm_mbedtls_lib_init()
{
    return wm_mbedtls_lib_inited;
}

mbedtls_x509_crt *wm_mbedtls_parse_cert(const unsigned char *cert_buf, size_t cert_buf_len)
{
    if (!wm_mbedtls_lib_inited)
        wm_mbedtls_lib_init();

    if (!cert_buf)
    {
        wm_mbedtls_e("Cannot parse NULL cert buffer");
        return NULL;
    }

    int ret                = 0;
    mbedtls_x509_crt *cert = NULL;

    cert = (mbedtls_x509_crt *)os_mem_alloc(sizeof(mbedtls_x509_crt));
    if (!cert)
        return NULL;

    mbedtls_x509_crt_init(cert);

    ret = mbedtls_x509_crt_parse(cert, cert_buf, cert_buf_len);

    if (ret < 0)
    {
        wm_mbedtls_e(
            "mbedtls_x509_crt_parse failed, "
            "ret = -0x%02X",
            -ret);
        os_mem_free(cert);
        return NULL;
    }
    return cert;
}

void wm_mbedtls_free_cert(mbedtls_x509_crt *cert)
{
    if (!cert)
        return;

    mbedtls_x509_crt_free(cert);
    os_mem_free(cert);
    return;
}

mbedtls_pk_context *wm_mbedtls_parse_key(const unsigned char *key_buf,
                                         size_t key_len,
                                         const unsigned char *pwd,
                                         size_t pwd_len)
{
    if (!wm_mbedtls_lib_inited)
        wm_mbedtls_lib_init();

    if (!key_buf)
    {
        wm_mbedtls_e("Cannot parse NULL key buffer");
        return NULL;
    }

    int ret                 = 0;
    mbedtls_pk_context *key = NULL;

    key = (mbedtls_pk_context *)os_mem_alloc(sizeof(mbedtls_pk_context));
    if (!key)
        return NULL;

    mbedtls_pk_init(key);

    ret = mbedtls_pk_parse_key(key, key_buf, key_len, pwd, pwd_len);

    if (ret != 0)
    {
        wm_mbedtls_e(
            "mbedtls_pk_parse_key failed, "
            "ret = -0x%02X",
            -ret);
        os_mem_free(key);
        return NULL;
    }
    return key;
}

void wm_mbedtls_free_key(mbedtls_pk_context *key)
{
    if (!key)
        return;

    mbedtls_pk_free(key);
    os_mem_free(key);
    return;
}

static const mbedtls_x509_crt_profile wm_mbedtls_x509_crt_profile_default = {
    /* Hashes from RIPEMD160 and above */
    MBEDTLS_X509_ID_FLAG(MBEDTLS_MD_RIPEMD160) | MBEDTLS_X509_ID_FLAG(MBEDTLS_MD_SHA224) |
        MBEDTLS_X509_ID_FLAG(MBEDTLS_MD_SHA256) | MBEDTLS_X509_ID_FLAG(MBEDTLS_MD_SHA384) |
        MBEDTLS_X509_ID_FLAG(MBEDTLS_MD_SHA512),
    0xFFFFFFF, /* Any PK alg    */
    0xFFFFFFF, /* Any curve     */
    2048,
};

#ifdef MBEDTLS_DEBUG_C
static void (*g_f_dbg)(void *, int, const char *, int, const char *);

#ifdef __ICCARM__
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif /* __ICCARM__ */

/*
 * This function will return basename of filename i.e.
 * it will return a pointer to basename in the filename after ignoring '/'.
 *
 * e.g. for filename "abc/xyx/some_name.c", this function will return
 * pointer to basename i.e. "some_name.c"
 */
static char *get_basename(char *file_name)
{
    char *p = strrchr(file_name, PATH_SEPARATOR);
    return p ? ++p : file_name;
}

static void wm_mbedtls_f_dbg(void *ctx, int level, const char *file, int line, const char *str)
{
    wm_mbedtls_d("%s:%04d: |%d| %s", get_basename((char *)file), line, level, str);
}

void wm_mbedtls_set_debug_cb(mbedtls_ssl_config *conf,
                             int threshold,
                             void (*f_dbg)(void *, int, const char *, int, const char *))
{
    if (!conf)
    {
        wm_mbedtls_e("Invalid SSL configuration context");
        return;
    }

    if (!f_dbg && !g_f_dbg)
    {
        /**
         * If 'NULL' dbg function and 'g_f_dbg' has not been set yet,
         * then set 'g_f_dbg' pointing to global dbg function,
         * and set it in conf.
         */
        g_f_dbg = wm_mbedtls_f_dbg;
        mbedtls_ssl_conf_dbg(conf, g_f_dbg, NULL);
    }
    else if (!f_dbg && g_f_dbg)
    {
        /**
         * If 'NULL' dbg function and already set 'g_f_dbg',
         * we will not override it.
         */
        wm_mbedtls_e("Cannot override dbg function");
        return;
    }
    else if (f_dbg)
    {
        /**
         * If valid dbg function then set it in conf.
         */
        mbedtls_ssl_conf_dbg(conf, f_dbg, NULL);
    }
    mbedtls_debug_set_threshold(threshold);
}
#endif /* MBEDTLS_DEBUG_C */

mbedtls_ssl_config *wm_mbedtls_ssl_config_new(wm_mbedtls_cert_t *cert, int endpoint, int authmode)
{
    if (!wm_mbedtls_lib_inited)
        wm_mbedtls_lib_init();

    mbedtls_ssl_config *conf           = NULL;
    mbedtls_ctr_drbg_context *ctr_drbg = NULL;

    conf = (mbedtls_ssl_config *)os_mem_alloc(sizeof(mbedtls_ssl_config));
    if (!conf)
        return NULL;

    mbedtls_ssl_config_init(conf);

    /* Set endpoint, transport, and default settings */
    mbedtls_ssl_config_defaults(conf, endpoint, MBEDTLS_SSL_TRANSPORT_STREAM, MBEDTLS_SSL_PRESET_DEFAULT);

#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
    /*
     * For values < 512, we disable the exchange of max
     * fragment length extension, leaving handling of success/failure to
     * the application layer. This allows maximum flexiblity by allowing
     * all values between 1 to 16384.
     */
    if (MBEDTLS_SSL_MAX_CONTENT_LEN == 16384 || MBEDTLS_SSL_MAX_CONTENT_LEN < 512)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_NONE);
    else if (MBEDTLS_SSL_MAX_CONTENT_LEN >= 4096)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_4096);
    else if (MBEDTLS_SSL_MAX_CONTENT_LEN >= 2048)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_2048);
    else if (MBEDTLS_SSL_MAX_CONTENT_LEN >= 1024)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_1024);
    else if (MBEDTLS_SSL_MAX_CONTENT_LEN >= 512)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_512);
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */

    mbedtls_ssl_conf_cert_profile(conf, &wm_mbedtls_x509_crt_profile_default);

    /* Set authentication mode */
    mbedtls_ssl_conf_authmode(conf, authmode);

    if (cert)
    {
        /* Set ca_chain */
        if (cert->ca_chain)
            mbedtls_ssl_conf_ca_chain(conf, cert->ca_chain, NULL);

        /* Set own_cert and own_key */
        if ((cert->own_cert) && (cert->own_key))
            mbedtls_ssl_conf_own_cert(conf, cert->own_cert, cert->own_key);
    }

    /* Get ctr_drbg context */
    ctr_drbg = wm_mbedtls_get_ctr_drbg_ctx();

    /* Set ctr_drbg context */
    if (ctr_drbg)
        mbedtls_ssl_conf_rng(conf, mbedtls_ctr_drbg_random, ctr_drbg);
    return conf;
}

#if defined(MBEDTLS_SSL_BUFFER_SIZES)
/* RFC 6066 section 4, see also mfl_code_to_length in ssl_tls.c
 * NONE must be zero so that memset()ing structure to zero works */
#define MBEDTLS_SSL_MAX_FRAG_LEN_NONE    0 /*!< don't use this extension   */
#define MBEDTLS_SSL_MAX_FRAG_LEN_512     1 /*!< MaxFragmentLength 2^9      */
#define MBEDTLS_SSL_MAX_FRAG_LEN_1024    2 /*!< MaxFragmentLength 2^10     */
#define MBEDTLS_SSL_MAX_FRAG_LEN_2048    3 /*!< MaxFragmentLength 2^11     */
#define MBEDTLS_SSL_MAX_FRAG_LEN_4096    4 /*!< MaxFragmentLength 2^12     */
#define MBEDTLS_SSL_MAX_FRAG_LEN_INVALID 5 /*!< first invalid value        */

int mbedtls_ssl_conf_buffsizes(mbedtls_ssl_config *conf, size_t in_buf_len, size_t out_buf_len)
{
    if (in_buf_len > 16384 || out_buf_len > 16384)
        return (MBEDTLS_ERR_SSL_BAD_INPUT_DATA);

    if (in_buf_len == 0)
        in_buf_len = MBEDTLS_SSL_MAX_CONTENT_LEN;

    if (out_buf_len == 0)
        out_buf_len = MBEDTLS_SSL_MAX_CONTENT_LEN;
/*
    conf->in_buf_len = in_buf_len;
    conf->out_buf_len = out_buf_len;
*/
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
    /*
     * For values < 512, we disable the exchange of max
     * fragment length extension, leaving handling of success/failure to
     * the application layer. This allows maximum flexiblity by allowing
     * all values between 1 to 16384.
     */
    if (out_buf_len == 16384 || out_buf_len < 512)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_NONE);
    else if (out_buf_len >= 4096)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_4096);
    else if (out_buf_len >= 2048)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_2048);
    else if (out_buf_len >= 1024)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_1024);
    else if (out_buf_len >= 512)
        mbedtls_ssl_conf_max_frag_len(conf, MBEDTLS_SSL_MAX_FRAG_LEN_512);
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */

    return (0);
}
#endif

int wm_mbedtls_ssl_conf_buffsizes(mbedtls_ssl_config *conf, size_t in_buf_len, size_t out_buf_len)
{
#if defined(MBEDTLS_SSL_BUFFER_SIZES)
    return mbedtls_ssl_conf_buffsizes(conf, in_buf_len, out_buf_len);
#else
    return -1;
#endif
}

void wm_mbedtls_ssl_config_free(mbedtls_ssl_config *conf)
{
    if (!conf)
        return;

    mbedtls_ssl_config_free(conf);
    os_mem_free(conf);
    return;
}

/*
 * Perform the SSL connection
 */
int wm_mbedtls_ssl_connect(mbedtls_ssl_context *ssl)
{
    if (!ssl)
    {
        wm_mbedtls_e("Invalid SSL context");
        return -1;
    }

    int ret = 0;

    while ((ret = mbedtls_ssl_handshake(ssl)) != 0)
    {
        if ((ret != MBEDTLS_ERR_SSL_WANT_READ) && (ret != MBEDTLS_ERR_SSL_WANT_WRITE))
        {
            wm_mbedtls_e(
                "mbedtls_ssl_handshake failed, "
                "ret = -0x%02X",
                -ret);
            break;
        }
    }

#if defined(MBEDTLS_X509_CRT_PARSE_C)
    uint32_t flags;
    if ((flags = mbedtls_ssl_get_verify_result(ssl)) != 0)
    {
        char vrfy_buf[512];

        mbedtls_x509_crt_verify_info(vrfy_buf, sizeof(vrfy_buf), "==> ", flags);

        wm_mbedtls_e("--------------------------------------");
        wm_mbedtls_e(
            "Verification results for flags 0x%02X "
            "are:",
            flags);
        wm_mbedtls_e("%s", vrfy_buf);
        wm_mbedtls_e("--------------------------------------");
    }
#endif /* MBEDTLS_X509_CRT_PARSE_C */

    return ret;
}

mbedtls_ssl_context *wm_mbedtls_ssl_new(mbedtls_ssl_config *conf, int fd, const char *hostname)
{
    if (!wm_mbedtls_lib_inited)
        wm_mbedtls_lib_init();

    if (!conf)
    {
        wm_mbedtls_e(
            "Cannot proceed to setup with "
            "NULL SSL configuration context");
        return NULL;
    }

    int ret                  = 0;
    mbedtls_ssl_context *ssl = NULL;

    ssl = (mbedtls_ssl_context *)os_mem_alloc(sizeof(mbedtls_ssl_context));
    if (!ssl)
        return NULL;

    mbedtls_ssl_init(ssl);

    /* Setup conf */
    ret = mbedtls_ssl_setup(ssl, conf);
    if (ret != 0)
    {
        wm_mbedtls_e(
            "mbedtls_ssl_setup failed, "
            "ret = -0x%02X",
            -ret);
        return NULL;
    }

    /* Set hostname */
    if (hostname)
        mbedtls_ssl_set_hostname(ssl, hostname);

    /* Set fd and register lwip write, read functions */
    wm_mbedtls_set_fd(ssl, fd);

#if defined(MBEDTLS_TIMING_C)
    mbedtls_timing_delay_context *timer = NULL;

    timer = (mbedtls_timing_delay_context *)os_mem_alloc(sizeof(mbedtls_timing_delay_context));
    if (!timer)
        return NULL;

    /* Set timing callbacks */
    mbedtls_ssl_set_timer_cb(ssl, timer, mbedtls_timing_set_delay, mbedtls_timing_get_delay);
#endif /* MBEDTLS_TIMING_C */
    return ssl;
}

void wm_mbedtls_ssl_free(mbedtls_ssl_context *ssl)
{
    if (!ssl)
        return;

#if defined(MBEDTLS_TIMING_C)
    if (ssl->p_timer)
    {
        os_mem_free(ssl->p_timer);
        ssl->p_timer = NULL;
    }
#endif /* MBEDTLS_TIMING_C */

    mbedtls_ssl_free(ssl);
    os_mem_free(ssl);
    return;
}

int wm_mbedtls_ssl_read(mbedtls_ssl_context *ssl, unsigned char *buf, size_t len)
{
    int ret = 0;

    /* Actual datalen read may be less than len bytes. So, we can't force
     * a 'for' loop like in wm_mbedtls_ssl_write() below. */
    do
        ret = mbedtls_ssl_read(ssl, buf, len);
    while (ret == MBEDTLS_ERR_SSL_WANT_READ || ret == MBEDTLS_ERR_SSL_WANT_WRITE);

    if (ret < 0)
    {
        wm_mbedtls_d("mbedtls_ssl_read failed, ret = -0x%02X", -ret);
    }

    return ret;
}

int wm_mbedtls_ssl_write(mbedtls_ssl_context *ssl, const unsigned char *buf, size_t len)
{
    int ret = 0, written;

    /* Exact len bytes must be written during writes. Otherwise, it is
     * an error. */
    for (written = 0; written < len; written += ret)
    {
        do
            ret = mbedtls_ssl_write(ssl, buf + written, len - written);
        while (ret == MBEDTLS_ERR_SSL_WANT_READ || ret == MBEDTLS_ERR_SSL_WANT_WRITE);

        if (ret <= 0)
        {
            wm_mbedtls_d("mbedtls_ssl_write failed, ret = -0x%02X", -ret);
            return ret;
        }
    }

    return written;
}

void wm_mbedtls_reset_read_timer(mbedtls_ssl_context *ssl)
{
    /*-----------------------------------------------------
     * Reset internal MBEDTLS timer
     */
    if (!ssl || !(ssl->f_set_timer))
        return;

    ssl->f_set_timer(ssl->p_timer, 0, 0);
}

void wm_mbedtls_set_read_timeout(mbedtls_ssl_context *ssl, uint32_t timeout)
{
    if (!ssl)
        return;
    /*-----------------------------------------------------
     * Set read_timeout to desired value
     */
    mbedtls_ssl_conf_read_timeout((struct mbedtls_ssl_config *)ssl->conf, timeout);
}
