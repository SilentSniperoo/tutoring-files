#include "main.h"

void contrast2()
{
	std::cout << "----- Example 2 -----" << std::endl;
	MyStruct myStruct;

	// Lambda functions are super cool!
	auto dump = [&myStruct]() {
		std::cout << "myInt: " << myStruct.myInt << std::endl;
		std::cout << "myChar: " << myStruct.myChar << std::endl;
		std::cout << std::endl;
	};

	myStruct.myInt = 64;
	std::cout << "`myStruct.myInt = 64;`" << std::endl;
	dump();

	myStruct.myChar = ' ';
	std::cout << "`myStruct.myChar = ' ';`" << std::endl;
	dump();

	myStruct.myInt = 96;
	std::cout << "`myStruct.myInt = 96;`" << std::endl;
	dump();

	myStruct.myChar = '@';
	std::cout << "`myStruct.myChar = '@';`" << std::endl;
	dump();

	myStruct.myInt = 100;
	std::cout << "`myStruct.myInt = 100;`" << std::endl;
	dump();

	myStruct.myChar = '%';
	std::cout << "`myStruct.myChar = '%';`" << std::endl;
	dump();

	std::cin.get();
}