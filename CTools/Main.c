#include <ansi_c.h>
#include "PCUnit.h"
#include "Main.h"

PCU_Suite *TestIList_Suite(void);
PCU_Suite *TestString_Suite(void);
PCU_Suite *TestStringList_Suite(void);

int main(void)
{
	const PCU_SuiteMethod suites[] = {
		TestIList_Suite,
		TestString_Suite,
		TestStringList_Suite,
	};
	
	PCU_set_putchar(putchar);
	PCU_set_getchar(getchar);
	
	PCU_enable_color();
	//PCU_set_verbose(1);

	PCU_console_run(suites, sizeof suites / sizeof suites[0]);
}
