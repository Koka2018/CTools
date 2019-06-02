//==============================================================================
//
// Title:		StringListTool.h
// Purpose:		A short description of the interface.
//
// Created on:	2013/04/01 at 4:14:11 by aaa.
// Copyright:	aaaa. All Rights Reserved.
//
//==============================================================================

#ifndef __StringListTool_H__
#define __StringListTool_H__

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

typedef struct type_StringList
{
	IList Pre;
	IList Next;
	String String;
	
} type_StringList;

typedef struct type_StringList *StringList;

StringList StringList_Create(void);
StringList String_Split(String string, char token);
StringList StringList_GetItem(StringList stringList, int idx);
String StringList_GetString(StringList stringList, int idx);

String StringList_ToString(StringList stringList);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __StringListTool_H__ */
