/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2022 NXP
* All rights reserved.
*
* \file
*
* This is the header file for the linked lists part of the Utils package.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _FWK_GENERIC_LIST_H_
#define _FWK_GENERIC_LIST_H_

#if defined(gMemManagerLight) && (gMemManagerLight != 0)
#include "fsl_component_generic_list.h"

#define listHandle           list_handle_t
#define listElementHandle_t  list_element_handle_t
#define list_t               list_handle_t
#define gListOk_c            kLIST_Ok
#define gListDuplicate_c     kLIST_DuplicateError
#define gListFull_c          kLIST_Full
#define gListEmpty_c         kLIST_Empty
#define gListOrphanElement_c kLIST_OrphanElement
#define gListNotSupport_c    kLIST_NotSupport

#define ListGetList          LIST_GetList
#define ListAddHead          LIST_AddHead
#define ListAddTail          LIST_AddTail

#define ListRemoveHead       LIST_RemoveHead
#define ListGetHead          LIST_GetHead
#define ListGetNext          LIST_GetNext
#define ListGetPrev          LIST_GetPrev
#define ListRemoveElement    LIST_RemoveElement
#define ListAddPrevElement   LIST_AddPrevElement
#define ListGetSize          LIST_GetSize
#define ListGetAvailable     LIST_GetAvailableSize

#else
/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

#include "EmbeddedTypes.h"



/*! *********************************************************************************
*************************************************************************************
* Public macro definitions
*************************************************************************************
********************************************************************************** */

/*! *********************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
********************************************************************************** */
typedef enum 
{
  gListOk_c = 0,
  gListFull_c,
  gListEmpty_c,
  gListOrphanElement_c
}listStatus_t;

typedef struct list_tag
{
  struct listElement_tag *head;
  struct listElement_tag *tail;
  uint16_t size;
  uint16_t max;
}list_t, *listHandle_t;

typedef struct listElement_tag
{
  struct listElement_tag *next;
  struct listElement_tag *prev;
  struct list_tag *list;
}listElement_t, *listElementHandle_t;

/*! *********************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
********************************************************************************** */
#ifdef __cplusplus
extern "C" {
#endif

void ListInit(listHandle_t list, uint32_t max);
listHandle_t ListGetList(listElementHandle_t element);
listStatus_t ListAddHead(listHandle_t list, listElementHandle_t element);
listStatus_t ListAddTail(listHandle_t list, listElementHandle_t element);
listElementHandle_t ListRemoveHead(listHandle_t list);
listElementHandle_t ListGetHead(listHandle_t list);
listElementHandle_t ListGetNext(listElementHandle_t element);
listElementHandle_t ListGetPrev(listElementHandle_t element);
listStatus_t ListRemoveElement(listElementHandle_t element);
listStatus_t ListAddPrevElement(listElementHandle_t element, listElementHandle_t newElement);
uint32_t ListGetSize(listHandle_t list);
uint32_t ListGetAvailable(listHandle_t list);
listStatus_t ListTest(void);

#ifdef __cplusplus
}
#endif
/*! *********************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
********************************************************************************** */
#ifdef DEBUG_ASSERT
#define LIST_ASSERT(condition) if(!(condition))while(1);
#else
#define LIST_ASSERT(condition) (void)(condition);
#endif
#endif /* gMemManagerLight */
#endif /*_GENERIC_LIST_H_*/
