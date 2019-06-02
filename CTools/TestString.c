#include "TestString.h"

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

static void testString_Init1(void)
{
	String string = String_Create("aaa");

	PCU_ASSERT_NOT_EQUAL(NULL, string);
	PCU_ASSERT_STRING_EQUAL("aaa", string->Text);

	string = String_Delete(string);
	PCU_ASSERT_EQUAL(NULL, string);
}

static void testString_Init2(void)
{
	String string = String_Create("ccc");

	PCU_ASSERT_NOT_EQUAL(NULL, string);
	PCU_ASSERT_STRING_EQUAL("ccc", string->Text);

	string = String_Delete(string);
	PCU_ASSERT_EQUAL(NULL, string);
}

static void testString_Init3(void)
{
	String string = String_Create("");

	PCU_ASSERT_NOT_EQUAL(NULL, string);
	PCU_ASSERT_STRING_EQUAL("", string->Text);

	string = String_Delete(string);
	PCU_ASSERT_EQUAL(NULL, string);
}

static void testString_Init4(void)
{
	String string = String_Create("‚ ‚¢‚¤");

	PCU_ASSERT_NOT_EQUAL(NULL, string);
	PCU_ASSERT_STRING_EQUAL("‚ ‚¢‚¤", string->Text);

	string = String_Delete(string);
	PCU_ASSERT_EQUAL(NULL, string);
}

static void testString_Length(void)
{
	String string = String_Create("test");

	PCU_ASSERT_EQUAL(4, String_Length(string));
	
	String_Delete(string);
}

static void testString_TrimBack(void)
{
	String string = String_Create("test2");
	string = String_TrimBack(string, 1);

	PCU_ASSERT_STRING_EQUAL("test", string->Text);
	
	String_Delete(string);
}

static void testString_TrimBack_TooIndex(void)
{
	String string = String_Create("Hello");
	string = String_TrimBack(string, 6);

	PCU_ASSERT_STRING_EQUAL("Hello", string->Text);
	
	String_Delete(string);
}

static void testString_TrimFront(void)
{
	String string = String_Create("Hello World");
	string = String_TrimFront(string, 6);

	PCU_ASSERT_STRING_EQUAL("World", string->Text);
	
	String_Delete(string);
}

static void testString_TrimFront_TooIndex(void)
{
	String string = String_Create("Hello World");
	string = String_TrimFront(string, 12);

	PCU_ASSERT_STRING_EQUAL("Hello World", string->Text);
	
	String_Delete(string);
}

static void testString_SubString1(void)
{
	String string = String_Create("Welcome to Japan");

	string = String_Sub(string, 9, 10);

	PCU_ASSERT_STRING_EQUAL("to", string->Text);
	
	String_Delete(string);
}

static void testString_SubString2(void)
{
	String string = String_Create("Welcome to Japan");

	string = String_Sub(string, 0, 7);

	PCU_ASSERT_STRING_EQUAL("Welcome", string->Text);
	
	String_Delete(string);
}

static void testString_SubString3(void)
{
	String string = String_Create("Welcome to Japan");

	string = String_Sub(string, 12, String_Length(string));

	PCU_ASSERT_STRING_EQUAL("Japan", string->Text);
	
	String_Delete(string);
}

static void testString_SubString4(void)
{
	String string = String_Create("Welcome to Japan");

	string = String_Sub(string, 8, 11);

	PCU_ASSERT_STRING_EQUAL(" to ", string->Text);
	
	String_Delete(string);
}

static void testString_FindChar1(void)
{
	String string = String_Create("0123456789");

	int idx = String_FindChar(string, '5');

	PCU_ASSERT_EQUAL(5, idx);
	
	String_Delete(string);
}

static void testString_FindChar2(void)
{
	String string = String_Create("0123456789");

	int idx = String_FindChar(string, '4');

	PCU_ASSERT_EQUAL(4, idx);
	
	String_Delete(string);
}

static void testString_FindChar3_NG(void)
{
	String string = String_Create("0123456789");

	int idx = String_FindChar(string, 'a');

	PCU_ASSERT_EQUAL(-1, idx);
	
	String_Delete(string);
}

static void testString_FindChars1(void)
{
	String string = String_Create("0123456789");

	int idx = String_FindChars(string, "234");

	PCU_ASSERT_EQUAL(2, idx);
	
	String_Delete(string);
}

static void testString_FindChars2(void)
{
	String string = String_Create("9876543210");

	int idx = String_FindChars(string, "210");

	PCU_ASSERT_EQUAL(7, idx);
	
	String_Delete(string);
}

static void testString_FindChars3_NG(void)
{
	String string = String_Create("0123456789");

	int idx = String_FindChars(string, "abc");

	PCU_ASSERT_EQUAL(-1, idx);
	
	String_Delete(string);
}

static void testString_FindChars4(void)
{
	String string = String_Create("9876543210");

	int idx = String_FindChars(string, "98");

	PCU_ASSERT_EQUAL(0, idx);
	
	String_Delete(string);
}

static void testString_FindChars5(void)
{
	String string = String_Create("9876543210");

	int idx = String_FindChars(string, "0");

	PCU_ASSERT_EQUAL(9, idx);
	
	String_Delete(string);
}

static void testString_FindChars6(void)
{
	String string = String_Create("‚ ‚¢‚¤‚¦‚¨");

	int idx = String_FindChars(string, "‚¢‚¤");

	PCU_ASSERT_EQUAL(2, idx);
	
	String_Delete(string);
}

static void testString_FindChars7(void)
{
	String string = String_Create("0123‚ ‚¢‚¤!##$");

	int idx = String_FindChars(string, "##");

	PCU_ASSERT_EQUAL(11, idx);
	
	String_Delete(string);
}

static void testString_FindString1(void)
{
	String string = String_Create("0123456789");
	String keyString = String_Create("456");

	int idx = String_FindString(string, keyString);

	PCU_ASSERT_EQUAL(4, idx);
	
	String_Delete(string);
}

static void testString_FindString2(void)
{
	String string = String_Create("‚ ‚¢‚¤‚¦‚¨");
	String keyString = String_Create("‚¤");

	int idx = String_FindString(string, keyString);

	PCU_ASSERT_EQUAL(4, idx);
	
	String_Delete(string);
}

static void testString_Join1(void)
{
	String string1 = String_Create("0123");
	String string2 = String_Create("abcd");

	String joinString = String_Join(string1, string2);

	PCU_ASSERT_EQUAL(8, String_Length(joinString));
	PCU_ASSERT_STRING_EQUAL("0123abcd", joinString->Text);
	
	//String_Print(joinString);
	
	String_Delete(string1);
	String_Delete(string2);
	String_Delete(joinString);
}

PCU_Suite *TestString_Suite(void)
{

	static PCU_Test tests[] = {
		PCU_TEST(testString_Init1),
		PCU_TEST(testString_Init2),
		PCU_TEST(testString_Init3),
		PCU_TEST(testString_Init4),
		PCU_TEST(testString_Length),
		PCU_TEST(testString_TrimBack),
		PCU_TEST(testString_TrimBack_TooIndex),
		PCU_TEST(testString_TrimFront),
		PCU_TEST(testString_TrimFront_TooIndex),
		PCU_TEST(testString_SubString1),
		PCU_TEST(testString_SubString2),
		PCU_TEST(testString_SubString3),
		PCU_TEST(testString_SubString4),
		PCU_TEST(testString_FindChar1),
		PCU_TEST(testString_FindChar2),
		PCU_TEST(testString_FindChar3_NG),
		PCU_TEST(testString_FindChars1),
		PCU_TEST(testString_FindChars2),
		PCU_TEST(testString_FindChars3_NG),
		PCU_TEST(testString_FindChars4),
		PCU_TEST(testString_FindChars5),
		PCU_TEST(testString_FindChars6),
		PCU_TEST(testString_FindChars7),
		PCU_TEST(testString_FindString1),
		PCU_TEST(testString_FindString2),
		PCU_TEST(testString_Join1),
	};
	static PCU_Suite suite = { "TestString_Suite", tests, sizeof tests / sizeof tests[0], setup, teardown, initialize, cleanup };
	return &suite;
}
