/****************************************************************************
 *
 * Copyright (c) 2014 Wi-Fi Alliance
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE
 * USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *****************************************************************************/

#ifndef __WFA_PORTALL_H__
#define __WFA_PORTALL_H__

#include <stdio.h>
#include <wlan.h>
#include <wifi.h>
#include <osa.h>
#include <wm_net.h>
#include <wm_utils.h>

/* The fixed definition for the device interface name */
/* For different OSes or your platforms, you may not  */
/* need to use fixed definition                       */
#define WFA_STAUT_IF "ml1"

/* the path to store EAP certificates. This is used   */
/* for Linux-like OS for wpa_supplicant               */
#define CERTIFICATES_PATH "/etc/wpa_supplicant"

static inline void panic(const char *msg)
{
    PRINTF("%s\r\n", msg);
    while (1)
    {
        OSA_TimeDelay(100);
    }
}

/** Wait until a condition becomes true */
#define wASSERT(cond)                                                  \
    do                                                                 \
    {                                                                  \
        if (!(cond))                                                   \
        {                                                              \
            PRINTM(WFA_ERR, "ASSERT: %s: %i\r\n", __func__, __LINE__); \
            panic("Assert failed: Panic!");                            \
        }                                                              \
    } while (0)

static inline int gettimeofday2(struct timeval *tv, void *tz)
{
    uint32_t sec, usec;
    uint32_t msecs = os_get_timestamp();

    sec = msecs / 1000;

    usec = (msecs % 1000) * 1000;

    tv->tv_sec  = sec;
    tv->tv_usec = usec;

    return 0;
}

#define wSTRNCPY(dstr, sstr, len) strncpy(dstr, sstr, len)

#define wSTRCPY(dstr, sstr) strcpy(dstr, sstr)

#define wSTRNCPY(dstr, sstr, len) strncpy(dstr, sstr, len)

#define wSTRNCMP(str1, str2, size) strncmp(str1, str2, size)

#define wSTRLEN(str) strlen(str)

#define wSOCKET(family, type, protocol) socket(family, type, protocol)

#define wSELECT(maxfdn, rsockSet, wsockSet, exceptSet, timer) select(maxfdn, rsockSet, wsockSet, exceptSet, timer)

#define wSETSOCKOPT(sock, level, optname, optval, optlen) setsockopt(sock, level, optname, optval, optlen)

#define wBIND(sock, sockaddr, sizeaddr) bind(sock, sockaddr, sizeaddr)

#define wLISTEN(sock, maxnumpending) listen(sock, maxnumpending)

#define wBZERO(ap, memsize) memset(ap, 0, memsize)

#define wCONNECT(sock, peeraddr, sizeaddr) connect(sock, peeraddr, sizeaddr)

#define wACCEPT(sock, addr, sizeaddr) accept(sock, addr, sizeaddr)

#define wSEND(sock, buf, len, flag) send(sock, buf, len, flag)

#define wSENDTO(sock, buf, len, flag, toaddr, sizeaddr) sendto(sock, buf, len, flag, toaddr, sizeaddr)

#define wRECV(sock, buf, len, flag) recv(sock, buf, len, flag)

#define wRECVFROM(sock, buf, len, flag, fromaddr, sizeaddr) recvfrom(sock, buf, len, flag, fromaddr, sizeaddr)

#define wFCNTL(fd, cmd, args) fcntl(fd, cmd, args)

#define wSYSTEM(cmd) system(cmd)

#define wSPRINTF(buf, format...) sprintf(buf, ##format)

#define wIOCTL(fd, cmd, intf) ioctl(fd, cmd, intf)

#define wMALLOC(size) OSA_MemoryAllocate(size)

#define wMEMCPY(dp, sp, size) memcpy(dp, sp, size)

#define wMEMSET(memp, val, size) memset(memp, val, size)

#define wFREE(memp) OSA_MemoryFree(memp);

#define wGETTIMEOFDAY(tmval, zone) gettimeofday2(tmval, zone)

#define wSETTIMEOFDAY(tmval, zone) settimeofday(tmval, zone)

#define wSIGNAL(signum, sighandler) signal(signum, sighandler)

#define wALARM(duration) // alarm(duration)

#define wCLOSE(fd) close(fd);

#define wUSLEEP(usecs) usleep(usecs)

#define wSLEEP(secs) sleep(secs)

#define wEXIT(num) exit(num)

#define wATOI(c) atoi(c)

#define wSHUTDOWN(fd, type) shutdown(fd, type)

#define wGETSOFD(sockfd, proto, tosval, ptosval, psize) getsockopt(sockfd, proto, tosval, ptosval, psize)

#define wPT_ATTR_INIT(ptattr) pthread_attr_init(ptattr)

#define wPT_ATTR_SETSCH(ptattr, policy) pthread_attr_setschedpolicy(ptattr, policy)

#define wPT_ATTR_SETSCHPARAM(ptattr, param) pthread_attr_setschedparam(ptattr, param)

#define wPT_MUTEX_LOCK(lock) pthread_mutex_lock(lock)

#define wPT_MUTEX_UNLOCK(lock) pthread_mutex_unlock(lock)

#define wFFLUSH(out) fflush(out)

#define wPT_COND_SIGNAL(signal) pthread_cond_signal(signal)

#define wPT_COND_WAIT(pcond, pmlock) pthread_cond_wait(pcond, pmlock)

#define wPT_MUTEX_INIT(pmlock, initval) pthread_mutex_init(pmlock, initval)

#define wPT_COND_INIT(pcond, initval) pthread_cond_init(pcond, initval)

#define wPT_CREATE(t, ptattr, func, pdata) pthread_create(t, ptattr, func, pdata)

typedef struct _memblock
{
    int id;
    int size; /* number of blocks 512 byte/block */
    void *mem;
} wfaMemBlk_t;

#endif /* __WFA_PORTALL_H__ */
