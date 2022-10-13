#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>

using namespace std;

string boolString(bool value) {
	return value ? "TRUE" : "FALSE";
}

struct Option {
		int toBe;
		char r;
};

Option options[] = {
		{
				1,
				'I'
		},
		{
				10,
				'X'
		},
		{
				0,
				'H'
		},
		{
				100,
				'C'
		},
		{
				5,
				'V'
		},
		{
			500,
			'D'
		}
};

void printGreen(const char test, const string& result) {
	cout << termcolor::green << "TEST " << "\"" << test << "\"" << " PASSED! RESULT: " << result;
}

void printRed(const char test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << "\"" << test << "\"" << " FAILED! EXPECTED: \"" << expected << "\" INSTEAD OF \"" << result << "\"!";
}

void test() {
	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		int result = roman(option.r);

		cout << endl;

		if (result == option.toBe) {
			printGreen(option.r, to_string(result));
		} else {
			printRed(option.r, to_string(option.toBe), to_string(result));
		}

		cout << endl;
	}
}