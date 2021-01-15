#include "main.h"

void contrast3()
{
	std::cout << "----- Example 3 -----" << std::endl;
	MyStruct myStruct;

	// Lambda functions are super cool!
	auto dump = [&myStruct](const char * firstLine) {
		std::cout << "'" << firstLine << "'" << std::endl;
		std::cout << "myInt: " << myStruct.myInt << std::endl;
		std::cout << "myChar: " << myStruct.myChar << std::endl;
		std::cout << std::endl;
	};

	myStruct.myInt = 64;
	dump("`myStruct.myInt = '64';`");

	myStruct.myChar = ' ';
	dump("`myStruct.myChar = ' ';`");

	myStruct.myInt = 96;
	dump("`myStruct.myInt = 96;`");

	myStruct.myChar = '@';
	dump("`myStruct.myChar = '@';`");

	myStruct.myInt = 100;
	dump("`myStruct.myInt = 100;`");

	myStruct.myChar = '%';
	dump("`myStruct.myChar = '%';`");

	std::cin.get();
}