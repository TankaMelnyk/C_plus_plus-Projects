#include <conio.h>

#include "Application.h"
#include "UiTester.h"

void main()
{
	setlocale(LC_ALL, "russian");

	Application pro;
    pro.RunProgramm();

	UiTester tester;
//	tester.runTests();

	_getch();
}