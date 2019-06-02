//==============================================================================
//
// Title:		IList.c
// Purpose:		A short description of the implementation.
//
// Created on:	2013/04/01 at 1:23:31 by aaa.
// Copyright:	aaaa. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include "cvidef.h"
#include "StringTool.h"

#include "IListTool.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

IList IList_Create(void)
{
	IList list = (IList)calloc(1, sizeof(type_IList));
	
	return list;
}

IList IList_Delete(IList list)
{
	free(list);
	list = NULL;

	return list;
}

void IList_Clear(IList list)
{
	int cnt = IList_Count(list);
	
	while(cnt > 0)
	{
		cnt--;
		IList item = IList_GetItem(list, cnt);
		if(item->Pre != NULL)
		{
			item->Pre->Next = NULL;
		}
		free(item);
		item = NULL;
	}
}

void IList_SetPre(IList me, IList pre);
void IList_SetPre(IList me, IList pre)
{
	me->Pre = pre;
	pre->Next = me;
}

void IList_SetNext(IList me, IList next);
void IList_SetNext(IList me, IList next)
{
	me->Next = next;
	next->Pre = me;
}

int IList_Count(IList list)
{
	int cnt = 1;
	IList tgtItem = list;
	
	while(tgtItem->Next != NULL)
	{
		tgtItem = tgtItem->Next;
		cnt++;
	}
	
	return cnt;
}

int IList_GetIndex(IList list, IList item)
{
	int idx = 0;
	IList tgtItem = list;
	
	do
	{
		if(memcmp(tgtItem, item, sizeof(tgtItem)) == 0)
		{
			return idx;
		}
		tgtItem = tgtItem->Next;
		idx++;
	}while(tgtItem != NULL);
	
	return -1;
}

IList IList_GetItem(IList list, int idx)
{
	IList tgtItem = list;

	if(idx > IList_Count(list))
	{
		return NULL;
	}
	
	for(int cnt = 0; cnt < idx; cnt++)
	{
		tgtItem = tgtItem->Next;
		if(tgtItem == NULL)
		{
			return NULL;
		}
	}
	
	return tgtItem;
}

IList IList_Add(IList list, IList item)
{
	int lastIdx = IList_Count(list) - 1;
	
	if(lastIdx == -1)
	{
		return list;
	}
	
	IList_SetNext(IList_GetItem(list, lastIdx), item);
	
	return list;
}

IList IList_Remove(IList list, IList item)
{
	if(item->Pre != NULL)
	{
		item->Pre->Next = item->Next;
	}
		
	if(item->Next != NULL)
	{
		item->Next->Pre = item->Pre;
	}
	
	IList_Delete(item);
	
	return list;
}

String IList_ToString(IList list)
{
	char msg[BUFSIZ] = "";
	
	sprintf(msg, "%x - %x - %x",
				 list->Pre == NULL ? 0 : list->Pre,
				 list == NULL ? 0 : list,
				 list->Next == NULL ? 0 : list->Next);
	return String_Create(msg);
}
