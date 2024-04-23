/*
 *  Copyright 2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <wm_os.h>
#include <wm_net.h>

#include "telnet_server.h"
#include "cli.h"

#ifndef SOCK_SERVER_PORT
#define SOCK_SERVER_PORT 23
#endif

#ifdef CONFIG_WIFI_SMOKE_TESTS

volatile int clientfd = 0;
char token[1000];

#define WPA_DEBUG_MAX_LINE_LENGTH 256
char buffer[WPA_DEBUG_MAX_LINE_LENGTH];

void sm_printf(const char *str, ...)
{
    va_list ap;

    memset(buffer, 0, WPA_DEBUG_MAX_LINE_LENGTH);

    va_start(ap, str);
    vsnprintf(buffer, sizeof(buffer), str, ap);
#if SDK_DEBUGCONSOLE == DEBUGCONSOLE_REDIRECT_TO_SDK /* Select printf, scanf, putchar, getchar of SDK version. */
    DbgConsole_Printf("%s", buffer);
#endif

    if (clientfd != 0)
    {
        lwip_send(clientfd, buffer, sizeof(buffer), 0);
    }
    va_end(ap);
}

void NewClient(void *pvParameters);
void SocketTelnetServer(void *pvParameters)
{
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    err_t err;

    /* Parameters are not used - suppress compiler error. */
    LWIP_UNUSED_ARG(pvParameters);

    /* First call to socket() function */
    sockfd = lwip_socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        // erro
        while (1)
        {
            vTaskDelay(1000);
        }
    }

    /* Initialize socket structure */
    /* set up address to connect to */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_len         = sizeof(serv_addr);
    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_port        = PP_HTONS(SOCK_SERVER_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    /* Now bind the host address using bind() call.*/
    if (lwip_bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        // erro
        lwip_close(sockfd);
        while (1)
        {
            vTaskDelay(1000);
        }
    }

    /* Now start listening for the clients, here
     * process will go in sleep mode and will wait
     * for the incoming connection
     */
    if (lwip_listen(sockfd, 5) != 0)
    {
        lwip_close(sockfd);
        while (1)
        {
            vTaskDelay(1000);
        }
    }

    clilen = sizeof(cli_addr);
    while (1)
    {
        newsockfd = lwip_accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);

        if (newsockfd > 0)
        {
            if (sys_thread_new("NewClient", NewClient, (void *)&newsockfd, 2048, 1) == NULL)
            {
                lwip_close(newsockfd);
            }
        }
    }
}

extern int handle_input(char *handle_inbuf);
extern void print_bad_command(char *cmd_string);

void NewClient(void *pvParameters)
{
    char buffer[256];
    int i, nbytes;
    clientfd                     = *((int *)pvParameters);
    int cInputIndex              = 0;
    BaseType_t xMoreDataToFollow = pdFALSE;
    static char pcOutputString[MAX_OUTPUT_LENGTH],
        pcInputString[MAX_INPUT_LENGTH]; // The input and output buffers are declared static to keep them off the stack.
    int ret;

    // Welcome message
    lwip_send(clientfd, "RTOS Telnet Server:\r\n\r\n~$ ", sizeof("\r\n\tRTOS Telnet Server:\r\n\r\n~$ "), 0);

    do
    {
        nbytes = lwip_recv(clientfd, buffer, sizeof(buffer), 0);

        if (nbytes > 0)
        { // no error

            for (i = 0; i < nbytes; i++)
            {
                if (buffer[i] == '\r') // Enter pressed
                {
                    do
                    {
                        memset(pcOutputString, 0, MAX_OUTPUT_LENGTH);

                        if (!strcmp(pcInputString, "exit"))
                        {
                            nbytes = 0; // forced stop
                            lwip_close(clientfd);
                            clientfd = 0;
                            vTaskDelete(NULL);
                        }
                        else
                        {
                            ret = handle_input(pcInputString);

                            if (ret == 0)
                            {
                                lwip_send(clientfd, pcOutputString, sizeof(pcOutputString), 0);
                            }

                            else if (ret == 1)
                            {
                                print_bad_command(pcInputString);
                            }
                            else if (ret == 2)
                            {
                                (void)PRINTF("syntax error\r\n");
                            }
                            else
                            { /* Do Nothing */
                            }

                            // If the command "exit" was entered, its output is "^]"
                            //							if (!strcmp(pcOutputString, "^]"))
                            //							{
                            //								nbytes = 0; // forced stop
                            //							}
                        }

                        if (xMoreDataToFollow == pdFALSE)
                        {
                            lwip_send(clientfd, "~$ ", sizeof("~$ "), 0);
                        }

                    } while (xMoreDataToFollow != pdFALSE);

                    cInputIndex = 0;
                    memset(pcInputString, 0x00, MAX_INPUT_LENGTH);
                }
                else
                {
                    if (buffer[i] == '\n')
                    {
                        /* Ignore . */
                    }
                    else if (buffer[i] == '\b')
                    {
                        if (cInputIndex > 0)
                        {
                            cInputIndex--;
                            pcInputString[cInputIndex] = '\0';
                        }

                        // UARTPutString(UART0_BASE, &buffer[i]);
                        lwip_send(clientfd, &buffer[i], sizeof(buffer[i]), 0);
                    }
                    else
                    {
                        if (cInputIndex < MAX_INPUT_LENGTH)
                        {
                            pcInputString[cInputIndex] = buffer[i];
                            cInputIndex++;
                        }
                    }
                }
            }
        }

    } while (nbytes > 0);

    lwip_close(clientfd);
    clientfd = 0;
    vTaskDelete(NULL);
}
#endif
