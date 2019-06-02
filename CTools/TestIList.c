#define __UNIT_TEST__

#include "StringTool.h"
#include "TestIList.h"

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

static void testIList_Init1(void)
{
	IList list = IList_Create();
	
	PCU_ASSERT_NOT_EQUAL(NULL, list);
	PCU_ASSERT_EQUAL(NULL, list->Pre);
	PCU_ASSERT_EQUAL(NULL, list->Next);
	PCU_ASSERT_EQUAL(1, IList_Count(list));
	
	list = IList_Delete(list);
	
	PCU_ASSERT_EQUAL(NULL, list);
}

static void testIList_SetPre1(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	
	IList_SetPre(item1, item2);
	
	PCU_ASSERT_EQUAL(item1->Pre, item2);
	PCU_ASSERT_EQUAL(item2->Next, item1);
	PCU_ASSERT_EQUAL(1, IList_Count(item1));
	PCU_ASSERT_EQUAL(2, IList_Count(item2));
	
	item1 = IList_Delete(item1);
	item2 = IList_Delete(item2);
}

static void testIList_SetNext1(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	
	IList_SetNext(item1, item2);
	
	PCU_ASSERT_EQUAL(item1->Next, item2);
	PCU_ASSERT_EQUAL(item2->Pre, item1);
	PCU_ASSERT_EQUAL(2, IList_Count(item1));
	PCU_ASSERT_EQUAL(1, IList_Count(item2));
	
	item1 = IList_Delete(item1);
	item2 = IList_Delete(item2);
}

static void testIList_Add(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	IList item3 = IList_Create();
	
	IList_Add(item1, item2);
	IList_Add(item1, item3);
	
	PCU_ASSERT_EQUAL(item1->Next,	item2);
	PCU_ASSERT_EQUAL(item1->Pre, 	NULL);
	
	PCU_ASSERT_EQUAL(item2->Next,	item3);
	PCU_ASSERT_EQUAL(item2->Pre, 	item1);
	
	PCU_ASSERT_EQUAL(item3->Next,	NULL);
	PCU_ASSERT_EQUAL(item3->Pre, 	item2);
	
	PCU_ASSERT_EQUAL(3, IList_Count(item1));
	PCU_ASSERT_EQUAL(2, IList_Count(item2));
	PCU_ASSERT_EQUAL(1, IList_Count(item3));
	
	item1 = IList_Delete(item1);
	item2 = IList_Delete(item2);
	item3 = IList_Delete(item3);
}

static void testIList_Remove(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	IList item3 = IList_Create();
	
	IList_Add(item1, item2);
	IList_Add(item1, item3);
	
	PCU_ASSERT_EQUAL(3, IList_Count(item1));
	
	item2 = IList_Remove(item1, item2);
	
	PCU_ASSERT_EQUAL(2, IList_Count(item1));
	PCU_ASSERT_EQUAL(1, IList_Count(item3));
	
	PCU_ASSERT_EQUAL(item1->Next,	item3);
	PCU_ASSERT_EQUAL(item1->Pre, 	NULL);
	
	PCU_ASSERT_EQUAL(item3->Next,	NULL);
	PCU_ASSERT_EQUAL(item3->Pre, 	item1);
	
	
	item1 = IList_Delete(item1);
	item3 = IList_Delete(item3);
}

static void testIList_Clear(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	IList item3 = IList_Create();
	
	IList_Add(item1, item2);
	IList_Add(item1, item3);
	
	PCU_ASSERT_EQUAL(3, IList_Count(item1));
	
	IList_Clear(item2);
	
	PCU_ASSERT_EQUAL(1, IList_Count(item1));
	PCU_ASSERT_NOT_EQUAL(NULL, item1);
	PCU_ASSERT_EQUAL(NULL, item1->Next);
}

static void testIList_GetIndex(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	IList item3 = IList_Create();
	
	IList_Add(item1, item2);
	IList_Add(item1, item3);
	
	PCU_ASSERT_EQUAL(0, IList_GetIndex(item1, item1));
	PCU_ASSERT_EQUAL(1, IList_GetIndex(item1, item2));
	PCU_ASSERT_EQUAL(2, IList_GetIndex(item1, item3));
	
	PCU_ASSERT_EQUAL(-1, IList_GetIndex(item2, item1));
	PCU_ASSERT_EQUAL(0, IList_GetIndex(item2, item2));
	PCU_ASSERT_EQUAL(1, IList_GetIndex(item2, item3));
	
	PCU_ASSERT_EQUAL(-1, IList_GetIndex(item3, item1));
	PCU_ASSERT_EQUAL(-1, IList_GetIndex(item3, item2));
	PCU_ASSERT_EQUAL(0, IList_GetIndex(item3, item3));
	
	IList_Clear(item1);
}

static void testIList_GetItem(void)
{
	IList item1 = IList_Create();
	IList item2 = IList_Create();
	IList item3 = IList_Create();
	
	IList_Add(item1, item2);
	IList_Add(item1, item3);
	
	PCU_ASSERT_EQUAL(item1, IList_GetItem(item1, 0));
	PCU_ASSERT_EQUAL(item2, IList_GetItem(item1, 1));
	PCU_ASSERT_EQUAL(item3, IList_GetItem(item1, 2));
	PCU_ASSERT_EQUAL(NULL, IList_GetItem(item1, 3));
	
	IList_Clear(item1);
}

PCU_Suite *TestIList_Suite(void)
{

	static PCU_Test tests[] = {
		PCU_TEST(testIList_Init1),
		PCU_TEST(testIList_SetPre1),
		PCU_TEST(testIList_SetNext1),
		PCU_TEST(testIList_Add),
		PCU_TEST(testIList_Remove),
		PCU_TEST(testIList_Clear),
		PCU_TEST(testIList_GetIndex),
		PCU_TEST(testIList_GetItem),

	};
	static PCU_Suite suite = { "TestIList_Suite", tests, sizeof tests / sizeof tests[0], setup, teardown, initialize, cleanup };
	return &suite;
}
