#include "TestCase.h"

#include <iostream>
#include <string>


#ifdef _MSC_VER
#	define	WIN32_LEAN_AND_MEAN
#	include <Windows.h>
#endif

using namespace std;
int TestCase::_totalCount = 0;
int TestCase::_totalPassing = 0;

void __SetColor(int fore, int background = 0)
{
#ifdef _MSC_VER
	static HANDLE hstdout = 0;
	if (hstdout == 0)
	{
		hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	WORD color = fore | (background << 4);
	SetConsoleTextAttribute(hstdout, color);
#endif
}

void __WritePassFail(bool isPassing)
{
	cout << "    ";

	if (isPassing)
	{
		__SetColor(2);
		cout << "\033[1;32mPass:\033[0m";
	}
	else
	{
		__SetColor(0, 4);
		cout << "\033[1;31mFail:\033[0m";
	}

	__SetColor(7);
	cout << " ";
}

TestCase::TestCase(const char *msg) :
	_isPassing(true)
{
	_totalCount++;
	__SetColor(0xF);
	cout << msg << endl;
	__SetColor(7);
}

TestCase::~TestCase()
{
	if (_isPassing)
	{
		_totalPassing++;
		__SetColor(0xF, 0x2);
		cout << "  \033[1;42mPASS\033[0m  ";
	}
	else
	{
		__SetColor(0xE, 0x4);
		cout << "  \033[1;41mFAILED\033[0m  ";
	}
	__SetColor(7);

	cout << endl << endl << endl;
}

void TestCase::LogResult(bool passed, const char *msg)
{
	__WritePassFail(passed);

	cout << msg << endl;

	if (!passed)
		_isPassing = false;
}

void TestCase::Assert(bool condition, const char *msg)
{
	__WritePassFail(condition);

	cout << "ASSERT: " << msg << endl;

	if (!condition)
		_isPassing = false;
}


void TestCase::AssertEquals(bool expected, bool actual, const char *msg)
{
	__WritePassFail(expected == actual);

	if (expected == actual)
		cout << msg << "  \033[1;36mExpected=\"" << expected << "\"\033[0m  \033[1;32mActual=\"" << actual << "\"\033[0m" << endl;
	else
	{
		_isPassing = false;
		cout << msg << "  \033[1;36mExpected=\"" << expected << "\"\033[0m \033[1;31mActual=\"" << actual << "\"\033[0m" << endl;
	}
}


void TestCase::AssertEquals(int expected, int actual, const char *msg)
{
	__WritePassFail(expected == actual);

	if (expected == actual)
		cout << msg << "  \033[1;36mExpected=\"" << expected << "\"\033[0m  \033[1;32mActual=\"" << actual << "\"\033[0m" << endl;
	else
	{
		_isPassing = false;
		cout << msg << "  \033[1;36mExpected=\"" << expected << "\"\033[0m \033[1;31mActual=\"" << actual << "\"\033[0m" << endl;
	}
}


void TestCase::AssertEquals(const string& expected, const string& actual, const char *msg)
{
	bool success = expected == actual;
	__WritePassFail(success);

	if (success)
		cout << msg << "  \033[1;36mExpected=\"" << expected << "\"\033[0m  \033[1;32mActual=\"" << actual << "\"\033[0m" << endl;
	else
	{
		_isPassing = false;
		cout << msg << "  \033[1;36mExpected=\"" << expected << "\"\033[0m \033[1;31mActual=\"" << actual << "\"\033[0m" << endl;
	}
}


void TestCase::LogException(std::exception ex)
{
	string msg = "EXCEPTION: ";
	msg += ex.what();

	LogResult(false, msg.c_str());
}


void TestCase::PrintBanner(const char* msg)
{
	__SetColor(0xF);
	cout << "*******************************************************************************" << endl;
	cout << "   ";

	for (int i = 0; msg[i] != 0; i++)
	{
		cout << msg[i];
		cout << " ";
	}

	cout << endl << "*******************************************************************************" << endl << endl;
	__SetColor(7);
}


void TestCase::PrintSummary()
{
	int percentage = (int)((double)_totalPassing / (double)_totalCount * 100);

	cout << "TOTALS" << endl;
	cout << "    \033[1;32mPassing:     \033[0m" << _totalPassing << endl;
	cout << "    \033[1;31mFailing:     \033[0m" << _totalCount - _totalPassing << endl;
	cout << "    Total tests: " << _totalCount << endl;
	cout << endl;
	cout << "Your grade: " << 20.0 + (double)percentage * 0.80 << "%";

	cout << endl;
	cout << "Press [Enter] to continue...";
	std::cin.get();
}

bool TestCase::IsPassing()
{
	return _isPassing;
}