//==============================================================================
//
// Title:		StringTool.h
// Purpose:		A short description of the interface.
//
// Created on:	2013/04/01 at 0:42:07 by aaa.
// Copyright:	aaaa. All Rights Reserved.
//
//==============================================================================

#ifndef __StringTool_H__
#define __StringTool_H__

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

typedef struct type_String
{
	char* Text;
	
} type_String;

typedef struct type_String *String;

String String_Create(char* text);
String String_Delete(String string);

int String_Length(String string);

String String_TrimFront(String string, int trimCharNum);
String String_TrimBack(String string, int trimCharNum);
String String_Sub(String string, int startIdx, int endIdx);
String String_Join(String string1, String string2);

int String_FindChar(String string, char key);
int String_FindChars(String string, char* text);
int String_FindString(String string, String key);

void String_Print(String string);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __StringTool_H__ */
