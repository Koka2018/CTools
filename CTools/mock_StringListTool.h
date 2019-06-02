#ifndef MOCK_STRINGLISTTOOL_H_INCLUDED
#define MOCK_STRINGLISTTOOL_H_INCLUDED

#include "StringListTool.h"

void mock_StringListTool_init(void);
#define mock_StringListTool_verify()	mock_StringListTool_verify_aux(__FILE__, __LINE__)
void mock_StringListTool_verify_aux(const char *file, unsigned int line);


typedef struct {
	StringList retval;
} StringList_Create_Expectation;
typedef StringList (*StringList_Create_Callback)(void);
#define StringList_Create_expect(expectations, num)	StringList_Create_expect_aux(expectations, num, __FILE__, __LINE__)
void StringList_Create_expect_aux(const StringList_Create_Expectation *expectations, int num, const char *file, unsigned int line);
#define StringList_Create_set_callback(callback, expected_num_calls)	StringList_Create_set_callback_aux(callback, expected_num_calls, __FILE__, __LINE__)
void StringList_Create_set_callback_aux(StringList_Create_Callback callback, int expected_num_calls, const char *file, unsigned int line);
int StringList_Create_num_calls(void);

typedef struct {
	StringList retval;
	struct {
		String string;
		char token;
	} expected;
	struct {
		unsigned int string:1;
		unsigned int token:1;
	} ignored;
} String_Split_Expectation;
typedef StringList (*String_Split_Callback)(String string, char token);
#define String_Split_expect(expectations, num)	String_Split_expect_aux(expectations, num, __FILE__, __LINE__)
void String_Split_expect_aux(const String_Split_Expectation *expectations, int num, const char *file, unsigned int line);
#define String_Split_set_callback(callback, expected_num_calls)	String_Split_set_callback_aux(callback, expected_num_calls, __FILE__, __LINE__)
void String_Split_set_callback_aux(String_Split_Callback callback, int expected_num_calls, const char *file, unsigned int line);
int String_Split_num_calls(void);

typedef struct {
	StringList retval;
	struct {
		StringList stringList;
		int idx;
	} expected;
	struct {
		unsigned int stringList:1;
		unsigned int idx:1;
	} ignored;
} StringList_GetItem_Expectation;
typedef StringList (*StringList_GetItem_Callback)(StringList stringList, int idx);
#define StringList_GetItem_expect(expectations, num)	StringList_GetItem_expect_aux(expectations, num, __FILE__, __LINE__)
void StringList_GetItem_expect_aux(const StringList_GetItem_Expectation *expectations, int num, const char *file, unsigned int line);
#define StringList_GetItem_set_callback(callback, expected_num_calls)	StringList_GetItem_set_callback_aux(callback, expected_num_calls, __FILE__, __LINE__)
void StringList_GetItem_set_callback_aux(StringList_GetItem_Callback callback, int expected_num_calls, const char *file, unsigned int line);
int StringList_GetItem_num_calls(void);

typedef struct {
	String retval;
	struct {
		StringList stringList;
		int idx;
	} expected;
	struct {
		unsigned int stringList:1;
		unsigned int idx:1;
	} ignored;
} StringList_GetString_Expectation;
typedef String (*StringList_GetString_Callback)(StringList stringList, int idx);
#define StringList_GetString_expect(expectations, num)	StringList_GetString_expect_aux(expectations, num, __FILE__, __LINE__)
void StringList_GetString_expect_aux(const StringList_GetString_Expectation *expectations, int num, const char *file, unsigned int line);
#define StringList_GetString_set_callback(callback, expected_num_calls)	StringList_GetString_set_callback_aux(callback, expected_num_calls, __FILE__, __LINE__)
void StringList_GetString_set_callback_aux(StringList_GetString_Callback callback, int expected_num_calls, const char *file, unsigned int line);
int StringList_GetString_num_calls(void);

#endif /* MOCK_STRINGLISTTOOL_H_INCLUDED */
