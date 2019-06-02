//==============================================================================
//
// Title:		StringTool.c
// Purpose:		A short description of the implementation.
//
// Created on:	2013/04/01 at 0:42:07 by aaa.
// Copyright:	aaaa. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include "cvidef.h"

#include "StringTool.h"

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

String String_Create(char *value)
{
	String string = (String)calloc(1, sizeof(type_String));
	int len = strlen(value);
	
	string->Text = calloc(len + 1, sizeof(char));
	strcpy(string->Text, value);
	
	return string;
}

String String_Delete(String string)
{
	free(string);
	string = NULL;
	
	return string;
}

int String_Length(String string)
{
	return strlen(string->Text);
}

String String_TrimFront(String string, int trimCharNum)
{
	String newString = String_Create(string->Text);
	int len = String_Length(newString);
	
	if(len < trimCharNum)
	{
		return newString;
	}
	
	strcpy(newString->Text, &newString->Text[trimCharNum]);
	
	return newString;
}

String String_TrimBack(String string, int trimCharNum)
{
	String newString = String_Create(string->Text);
	int len = String_Length(newString);
	
	if(len < trimCharNum)
	{
		return newString;
	}
	
	newString->Text[len - trimCharNum] = '\0';
	
	return newString;
}

String String_Sub(String string, int startIdx, int endIdx)
{
	String newString = String_Create(string->Text);
	int len = String_Length(newString);
	
	newString = String_TrimBack(newString, len - endIdx);
	if(startIdx > 0)
	{
		newString = String_TrimFront(newString, startIdx - 1);
	}
	
	return newString;
}

String String_Join(String string1, String string2)
{
	char* joinChar;
	
	joinChar = calloc(String_Length(string1) + String_Length(string2) + 1, sizeof(char));
	sprintf(joinChar, "%s%s", string1->Text, string2->Text);
	String joinString = String_Create(joinChar);
	
	return joinString;
}

int String_FindChar(String string, char key)
{
	int len = String_Length(string);
	
	for(int idx = 0; idx < len; idx++)
	{
		if(string->Text[idx] == key)
		{
			return idx;
		}
	}
	
	return -1;
}

int String_FindChars(String string, char* text)
{
	char* find = strstr(string->Text, text);
	
	if(find == NULL)
	{
		return -1;
	}
	
	return find - string->Text;
}

int String_FindString(String string, String key)
{
	return String_FindChars(string, key->Text);
}

void String_Print(String string)
{
	printf("%s : (%d)", string->Text, String_Length(string));
}
