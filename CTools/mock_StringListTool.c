#include "mock_StringListTool.h"
#include "PCUnit/PCUnit.h"

struct mock_StringListTool_t {
	StringList_Create_Callback StringList_Create_funcptr;
	String_Split_Callback String_Split_funcptr;
	StringList_GetItem_Callback StringList_GetItem_funcptr;
	StringList_GetString_Callback StringList_GetString_funcptr;
	int StringList_Create_expected_num_calls;
	int String_Split_expected_num_calls;
	int StringList_GetItem_expected_num_calls;
	int StringList_GetString_expected_num_calls;
	int StringList_Create_actual_num_calls;
	int String_Split_actual_num_calls;
	int StringList_GetItem_actual_num_calls;
	int StringList_GetString_actual_num_calls;
	const StringList_Create_Expectation *StringList_Create_expectations;
	const String_Split_Expectation *String_Split_expectations;
	const StringList_GetItem_Expectation *StringList_GetItem_expectations;
	const StringList_GetString_Expectation *StringList_GetString_expectations;
	const char *StringList_Create_file;
	const char *String_Split_file;
	const char *StringList_GetItem_file;
	const char *StringList_GetString_file;
	unsigned int StringList_Create_line;
	unsigned int String_Split_line;
	unsigned int StringList_GetItem_line;
	unsigned int StringList_GetString_line;
};
static struct mock_StringListTool_t mock_StringListTool;

void mock_StringListTool_init(void)
{
	char *p = (char *) &mock_StringListTool;
	size_t i;
	for (i = 0; i < sizeof mock_StringListTool; i++) {
		*(p++) = 0;
	}
}

#ifdef _MSC_VER
#define LINE_FORMAT	"(%u) "
#else
#define LINE_FORMAT	":%u"
#endif

void mock_StringListTool_verify_aux(const char *file, unsigned int line)
{
	if (PCU_test_has_failed()) {
		return;
	}
	if (mock_StringListTool.StringList_Create_expectations || (mock_StringListTool.StringList_Create_funcptr && mock_StringListTool.StringList_Create_expected_num_calls >= 0)) {
		if (mock_StringListTool.StringList_Create_expected_num_calls != mock_StringListTool.StringList_Create_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_Create(), but was %d", file, line, mock_StringListTool.StringList_Create_expected_num_calls, mock_StringListTool.StringList_Create_actual_num_calls));
			return;
		}
	}
	if (mock_StringListTool.String_Split_expectations || (mock_StringListTool.String_Split_funcptr && mock_StringListTool.String_Split_expected_num_calls >= 0)) {
		if (mock_StringListTool.String_Split_expected_num_calls != mock_StringListTool.String_Split_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of String_Split(), but was %d", file, line, mock_StringListTool.String_Split_expected_num_calls, mock_StringListTool.String_Split_actual_num_calls));
			return;
		}
	}
	if (mock_StringListTool.StringList_GetItem_expectations || (mock_StringListTool.StringList_GetItem_funcptr && mock_StringListTool.StringList_GetItem_expected_num_calls >= 0)) {
		if (mock_StringListTool.StringList_GetItem_expected_num_calls != mock_StringListTool.StringList_GetItem_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_GetItem(), but was %d", file, line, mock_StringListTool.StringList_GetItem_expected_num_calls, mock_StringListTool.StringList_GetItem_actual_num_calls));
			return;
		}
	}
	if (mock_StringListTool.StringList_GetString_expectations || (mock_StringListTool.StringList_GetString_funcptr && mock_StringListTool.StringList_GetString_expected_num_calls >= 0)) {
		if (mock_StringListTool.StringList_GetString_expected_num_calls != mock_StringListTool.StringList_GetString_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_GetString(), but was %d", file, line, mock_StringListTool.StringList_GetString_expected_num_calls, mock_StringListTool.StringList_GetString_actual_num_calls));
			return;
		}
	}
}


StringList StringList_Create(void)
{
	StringList ret;
	if (mock_StringListTool.StringList_Create_expectations) {
		const StringList_Create_Expectation *e;
		if (mock_StringListTool.StringList_Create_expected_num_calls <= mock_StringListTool.StringList_Create_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_Create(), but was more", mock_StringListTool.StringList_Create_file, mock_StringListTool.StringList_Create_line, mock_StringListTool.StringList_Create_expected_num_calls));
		}
		e = mock_StringListTool.StringList_Create_expectations + mock_StringListTool.StringList_Create_actual_num_calls;
		ret = e->retval;
	}
	if (mock_StringListTool.StringList_Create_funcptr) {
		if (mock_StringListTool.StringList_Create_expected_num_calls >= 0) {
			if (mock_StringListTool.StringList_Create_expected_num_calls <= mock_StringListTool.StringList_Create_actual_num_calls) {
				PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_Create(), but was more", mock_StringListTool.StringList_Create_file, mock_StringListTool.StringList_Create_line, mock_StringListTool.StringList_Create_expected_num_calls));
			}
		}
		ret = mock_StringListTool.StringList_Create_funcptr();
	}
	if (!mock_StringListTool.StringList_Create_expectations && !mock_StringListTool.StringList_Create_funcptr) {
		PCU_FAIL("Call StringList_Create_expect() or StringList_Create_set_callback()");
	}
	mock_StringListTool.StringList_Create_actual_num_calls++;
	return ret;
}

void StringList_Create_expect_aux(const StringList_Create_Expectation *expectations, int num, const char *file, unsigned int line)
{
	mock_StringListTool.StringList_Create_expectations = expectations;
	mock_StringListTool.StringList_Create_expected_num_calls = num;
	mock_StringListTool.StringList_Create_file = file;
	mock_StringListTool.StringList_Create_line = line;
}

void StringList_Create_set_callback_aux(StringList_Create_Callback callback, int expected_num_calls, const char *file, unsigned int line)
{
	mock_StringListTool.StringList_Create_funcptr = callback;
	if (!mock_StringListTool.StringList_Create_expectations) {
		mock_StringListTool.StringList_Create_expected_num_calls = expected_num_calls;
		mock_StringListTool.StringList_Create_file = file;
		mock_StringListTool.StringList_Create_line = line;
	}
}

int StringList_Create_num_calls(void)
{
	return mock_StringListTool.StringList_Create_actual_num_calls;
}

StringList String_Split(String string, char token)
{
	StringList ret;
	if (mock_StringListTool.String_Split_expectations) {
		const String_Split_Expectation *e;
		if (mock_StringListTool.String_Split_expected_num_calls <= mock_StringListTool.String_Split_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of String_Split(), but was more", mock_StringListTool.String_Split_file, mock_StringListTool.String_Split_line, mock_StringListTool.String_Split_expected_num_calls));
		}
		e = mock_StringListTool.String_Split_expectations + mock_StringListTool.String_Split_actual_num_calls;
		if (!e->ignored.string) {
			PCU_ASSERT_MEMORY_EQUAL_MESSAGE(&e->expected.string, &string, sizeof(string), 1, PCU_format("%s" LINE_FORMAT ": call #%d: Parameter 'string' of String_Split() is unexpected value", mock_StringListTool.String_Split_file, mock_StringListTool.String_Split_line, mock_StringListTool.String_Split_actual_num_calls + 1));
		}
		if (!e->ignored.token) {
			PCU_ASSERT_EQUAL_MESSAGE(e->expected.token, token, PCU_format("%s" LINE_FORMAT ": call #%d: Parameter 'token' of String_Split() is unexpected value", mock_StringListTool.String_Split_file, mock_StringListTool.String_Split_line, mock_StringListTool.String_Split_actual_num_calls + 1));
		}
		ret = e->retval;
	}
	if (mock_StringListTool.String_Split_funcptr) {
		if (mock_StringListTool.String_Split_expected_num_calls >= 0) {
			if (mock_StringListTool.String_Split_expected_num_calls <= mock_StringListTool.String_Split_actual_num_calls) {
				PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of String_Split(), but was more", mock_StringListTool.String_Split_file, mock_StringListTool.String_Split_line, mock_StringListTool.String_Split_expected_num_calls));
			}
		}
		ret = mock_StringListTool.String_Split_funcptr(string, token);
	}
	if (!mock_StringListTool.String_Split_expectations && !mock_StringListTool.String_Split_funcptr) {
		PCU_FAIL("Call String_Split_expect() or String_Split_set_callback()");
	}
	mock_StringListTool.String_Split_actual_num_calls++;
	return ret;
}

void String_Split_expect_aux(const String_Split_Expectation *expectations, int num, const char *file, unsigned int line)
{
	mock_StringListTool.String_Split_expectations = expectations;
	mock_StringListTool.String_Split_expected_num_calls = num;
	mock_StringListTool.String_Split_file = file;
	mock_StringListTool.String_Split_line = line;
}

void String_Split_set_callback_aux(String_Split_Callback callback, int expected_num_calls, const char *file, unsigned int line)
{
	mock_StringListTool.String_Split_funcptr = callback;
	if (!mock_StringListTool.String_Split_expectations) {
		mock_StringListTool.String_Split_expected_num_calls = expected_num_calls;
		mock_StringListTool.String_Split_file = file;
		mock_StringListTool.String_Split_line = line;
	}
}

int String_Split_num_calls(void)
{
	return mock_StringListTool.String_Split_actual_num_calls;
}

StringList StringList_GetItem(StringList stringList, int idx)
{
	StringList ret;
	if (mock_StringListTool.StringList_GetItem_expectations) {
		const StringList_GetItem_Expectation *e;
		if (mock_StringListTool.StringList_GetItem_expected_num_calls <= mock_StringListTool.StringList_GetItem_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_GetItem(), but was more", mock_StringListTool.StringList_GetItem_file, mock_StringListTool.StringList_GetItem_line, mock_StringListTool.StringList_GetItem_expected_num_calls));
		}
		e = mock_StringListTool.StringList_GetItem_expectations + mock_StringListTool.StringList_GetItem_actual_num_calls;
		if (!e->ignored.stringList) {
			PCU_ASSERT_MEMORY_EQUAL_MESSAGE(&e->expected.stringList, &stringList, sizeof(stringList), 1, PCU_format("%s" LINE_FORMAT ": call #%d: Parameter 'stringList' of StringList_GetItem() is unexpected value", mock_StringListTool.StringList_GetItem_file, mock_StringListTool.StringList_GetItem_line, mock_StringListTool.StringList_GetItem_actual_num_calls + 1));
		}
		if (!e->ignored.idx) {
			PCU_ASSERT_EQUAL_MESSAGE(e->expected.idx, idx, PCU_format("%s" LINE_FORMAT ": call #%d: Parameter 'idx' of StringList_GetItem() is unexpected value", mock_StringListTool.StringList_GetItem_file, mock_StringListTool.StringList_GetItem_line, mock_StringListTool.StringList_GetItem_actual_num_calls + 1));
		}
		ret = e->retval;
	}
	if (mock_StringListTool.StringList_GetItem_funcptr) {
		if (mock_StringListTool.StringList_GetItem_expected_num_calls >= 0) {
			if (mock_StringListTool.StringList_GetItem_expected_num_calls <= mock_StringListTool.StringList_GetItem_actual_num_calls) {
				PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_GetItem(), but was more", mock_StringListTool.StringList_GetItem_file, mock_StringListTool.StringList_GetItem_line, mock_StringListTool.StringList_GetItem_expected_num_calls));
			}
		}
		ret = mock_StringListTool.StringList_GetItem_funcptr(stringList, idx);
	}
	if (!mock_StringListTool.StringList_GetItem_expectations && !mock_StringListTool.StringList_GetItem_funcptr) {
		PCU_FAIL("Call StringList_GetItem_expect() or StringList_GetItem_set_callback()");
	}
	mock_StringListTool.StringList_GetItem_actual_num_calls++;
	return ret;
}

void StringList_GetItem_expect_aux(const StringList_GetItem_Expectation *expectations, int num, const char *file, unsigned int line)
{
	mock_StringListTool.StringList_GetItem_expectations = expectations;
	mock_StringListTool.StringList_GetItem_expected_num_calls = num;
	mock_StringListTool.StringList_GetItem_file = file;
	mock_StringListTool.StringList_GetItem_line = line;
}

void StringList_GetItem_set_callback_aux(StringList_GetItem_Callback callback, int expected_num_calls, const char *file, unsigned int line)
{
	mock_StringListTool.StringList_GetItem_funcptr = callback;
	if (!mock_StringListTool.StringList_GetItem_expectations) {
		mock_StringListTool.StringList_GetItem_expected_num_calls = expected_num_calls;
		mock_StringListTool.StringList_GetItem_file = file;
		mock_StringListTool.StringList_GetItem_line = line;
	}
}

int StringList_GetItem_num_calls(void)
{
	return mock_StringListTool.StringList_GetItem_actual_num_calls;
}

String StringList_GetString(StringList stringList, int idx)
{
	String ret;
	if (mock_StringListTool.StringList_GetString_expectations) {
		const StringList_GetString_Expectation *e;
		if (mock_StringListTool.StringList_GetString_expected_num_calls <= mock_StringListTool.StringList_GetString_actual_num_calls) {
			PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_GetString(), but was more", mock_StringListTool.StringList_GetString_file, mock_StringListTool.StringList_GetString_line, mock_StringListTool.StringList_GetString_expected_num_calls));
		}
		e = mock_StringListTool.StringList_GetString_expectations + mock_StringListTool.StringList_GetString_actual_num_calls;
		if (!e->ignored.stringList) {
			PCU_ASSERT_MEMORY_EQUAL_MESSAGE(&e->expected.stringList, &stringList, sizeof(stringList), 1, PCU_format("%s" LINE_FORMAT ": call #%d: Parameter 'stringList' of StringList_GetString() is unexpected value", mock_StringListTool.StringList_GetString_file, mock_StringListTool.StringList_GetString_line, mock_StringListTool.StringList_GetString_actual_num_calls + 1));
		}
		if (!e->ignored.idx) {
			PCU_ASSERT_EQUAL_MESSAGE(e->expected.idx, idx, PCU_format("%s" LINE_FORMAT ": call #%d: Parameter 'idx' of StringList_GetString() is unexpected value", mock_StringListTool.StringList_GetString_file, mock_StringListTool.StringList_GetString_line, mock_StringListTool.StringList_GetString_actual_num_calls + 1));
		}
		ret = e->retval;
	}
	if (mock_StringListTool.StringList_GetString_funcptr) {
		if (mock_StringListTool.StringList_GetString_expected_num_calls >= 0) {
			if (mock_StringListTool.StringList_GetString_expected_num_calls <= mock_StringListTool.StringList_GetString_actual_num_calls) {
				PCU_FAIL(PCU_format("%s" LINE_FORMAT ": Expected %d calls of StringList_GetString(), but was more", mock_StringListTool.StringList_GetString_file, mock_StringListTool.StringList_GetString_line, mock_StringListTool.StringList_GetString_expected_num_calls));
			}
		}
		ret = mock_StringListTool.StringList_GetString_funcptr(stringList, idx);
	}
	if (!mock_StringListTool.StringList_GetString_expectations && !mock_StringListTool.StringList_GetString_funcptr) {
		PCU_FAIL("Call StringList_GetString_expect() or StringList_GetString_set_callback()");
	}
	mock_StringListTool.StringList_GetString_actual_num_calls++;
	return ret;
}

void StringList_GetString_expect_aux(const StringList_GetString_Expectation *expectations, int num, const char *file, unsigned int line)
{
	mock_StringListTool.StringList_GetString_expectations = expectations;
	mock_StringListTool.StringList_GetString_expected_num_calls = num;
	mock_StringListTool.StringList_GetString_file = file;
	mock_StringListTool.StringList_GetString_line = line;
}

void StringList_GetString_set_callback_aux(StringList_GetString_Callback callback, int expected_num_calls, const char *file, unsigned int line)
{
	mock_StringListTool.StringList_GetString_funcptr = callback;
	if (!mock_StringListTool.StringList_GetString_expectations) {
		mock_StringListTool.StringList_GetString_expected_num_calls = expected_num_calls;
		mock_StringListTool.StringList_GetString_file = file;
		mock_StringListTool.StringList_GetString_line = line;
	}
}

int StringList_GetString_num_calls(void)
{
	return mock_StringListTool.StringList_GetString_actual_num_calls;
}

