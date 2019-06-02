//==============================================================================
//
// Title:		StringListTool.c
// Purpose:		A short description of the implementation.
//
// Created on:	2013/04/01 at 4:14:11 by aaa.
// Copyright:	aaaa. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include "cvidef.h"
#include "StringTool.h"
#include "IListTool.h"

#include "StringListTool.h"

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

StringList StringList_Create(void)
{
	StringList stringList = (StringList)calloc(1, sizeof(type_StringList));
	stringList->String = String_Create("");
	
	return stringList;
}

StringList StringList_Delete(StringList stringList)
{
	String_Delete(stringList->String);
	
	return stringList;
}

StringList String_Split(String string, char token)
{
	StringList stringList = NULL;
	String workString = String_Create(string->Text);
	
	int idx = 0;
	do
	{
		idx = String_FindChar(workString, token);
		if(idx >= 0)
		{
			String leftString = String_Sub(workString, 0, idx);
			workString = String_Sub(workString, idx + 2, String_Length(workString));
			
			if(stringList == NULL)
			{
				stringList = StringList_Create();
				stringList->String = leftString;
			}
			else
			{
				StringList newStringList = StringList_Create();
				newStringList->String = leftString;
				stringList = (StringList)IList_Add((IList)stringList, (IList)newStringList);
			}
		}
	}while(idx >= 0);
	
	{
		StringList newStringList = StringList_Create();
		newStringList->String = workString;
		stringList = (StringList)IList_Add((IList)stringList, (IList)newStringList);
	}
	
	return stringList;
}

StringList StringList_GetItem(StringList stringList, int idx)
{
	return (StringList)IList_GetItem((IList)stringList, idx);
}

String StringList_GetString(StringList stringList, int idx)
{
	return ((StringList)IList_GetItem((IList)stringList, idx))->String;
}

String StringList_ToString(StringList stringList)
{
	char msg[BUFSIZ] = "";
	char strSpace[BUFSIZ] = "";
	int num = IList_Count((IList)stringList);
	
	for(int i = 0; i < num; i++)
	{
		StringList item = StringList_GetItem(stringList, i);
		strcat(msg, strSpace);
		strcat(msg, " - ");
		strcat(msg, item->String->Text);
		strcat(msg, "\n");
		
		strcat(strSpace, " ");
	}
	
	return String_Create(msg);
}
