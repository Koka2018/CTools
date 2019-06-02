#include "StringTool.h"
#include "IListTool.h"

#include "TestStringList.h"

static int initialize(void)
{
	return 0;
}

static int cleanup(void)
{
	return 0;
}

static int setup(void)
{
	return 0;
}

static int teardown(void)
{
	return 0;
}

static void testStringList_Split(void)
{
	String input = String_Create(",123,456,7,89,");
	
	StringList sp_input = String_Split(input, ',');
	
	PCU_ASSERT_EQUAL(6, IList_Count((IList)sp_input));

	PCU_ASSERT_STRING_EQUAL("", StringList_GetString(sp_input, 0)->Text);
	PCU_ASSERT_STRING_EQUAL("123", StringList_GetString(sp_input, 1)->Text);
	PCU_ASSERT_STRING_EQUAL("456", StringList_GetString(sp_input, 2)->Text);
	PCU_ASSERT_STRING_EQUAL("7", StringList_GetString(sp_input, 3)->Text);
	PCU_ASSERT_STRING_EQUAL("89", StringList_GetString(sp_input, 4)->Text);
	PCU_ASSERT_STRING_EQUAL("", StringList_GetString(sp_input, 5)->Text);
	
	//String string = StringList_ToString(sp_input);
	//printf("%s", string->Text);
	//String_Delete(string);
}

PCU_Suite *TestStringList_Suite(void)
{

	static PCU_Test tests[] = {
		PCU_TEST(testStringList_Split),
	};
	static PCU_Suite suite = { "TestStringList_Suite", tests, sizeof tests / sizeof tests[0], setup, teardown, initialize, cleanup };
	return &suite;
}
