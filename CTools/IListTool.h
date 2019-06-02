//==============================================================================
//
// Title:		IList.h
// Purpose:		A short description of the interface.
//
// Created on:	2013/04/01 at 1:23:31 by aaa.
// Copyright:	aaaa. All Rights Reserved.
//
//==============================================================================

#ifndef __IList_H__
#define __IList_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

typedef struct type_IList *IList;

typedef struct type_IList
{
	IList Pre;
	IList Next;
} type_IList;

IList IList_Create(void);
IList IList_Delete(IList list);
void IList_Clear(IList list);

int IList_Count(IList list);
int IList_GetIndex(IList list, IList item);
IList IList_GetItem(IList list, int idx);

IList IList_Add(IList list, IList item);
IList IList_Remove(IList list, IList item);

String IList_ToString(IList list);

#ifdef __UNIT_TEST__

extern void IList_SetPre(IList me, IList pre);
extern void IList_SetNext(IList me, IList next);

#endif


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __IList_H__ */
