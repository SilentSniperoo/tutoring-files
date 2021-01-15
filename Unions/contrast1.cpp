#include "main.h"

void contrast1()
{
	std::cout << "----- Example 1 -----" << std::endl;
	MyStruct myStruct;

	myStruct.myInt = 64;
	std::cout << "`myStruct.myInt = 64;`" << std::endl;

	std::cout << "myInt: " << myStruct.myInt << std::endl;
	//std::cout << "myChar: " << myStruct.myChar << std::endl; // Not initialized
	std::cout << std::endl;

	myStruct.myChar = ' ';
	std::cout << "`myStruct.myChar = ' ';`" << std::endl;

	std::cout << "myInt: " << myStruct.myInt << std::endl;
	std::cout << "myChar: " << myStruct.myChar << std::endl;
	std::cout << std::endl;

	myStruct.myInt = 96;
	std::cout << "`myStruct.myInt = 96;`" << std::endl;

	std::cout << "myInt: " << myStruct.myInt << std::endl;
	std::cout << "myChar: " << myStruct.myChar << std::endl;
	std::cout << std::endl;

	myStruct.myChar = '@';
	std::cout << "`myStruct.myChar = '@';`" << std::endl;

	std::cout << "myInt: " << myStruct.myInt << std::endl;
	std::cout << "myChar: " << myStruct.myChar << std::endl;
	std::cout << std::endl;

	myStruct.myInt = 100;
	std::cout << "`myStruct.myInt = 100;`" << std::endl;

	std::cout << "myInt: " << myStruct.myInt << std::endl;
	std::cout << "myChar: " << myStruct.myChar << std::endl;
	std::cout << std::endl;

	myStruct.myChar = '%';
	std::cout << "`myStruct.myChar = '%';`" << std::endl;

	std::cout << "myInt: " << myStruct.myInt << std::endl;
	std::cout << "myChar: " << myStruct.myChar << std::endl;
	std::cout << std::endl;

	std::cin.get();
}