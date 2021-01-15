#include "main.h"

void example1()
{
	std::cout << "----- Example 1 -----" << std::endl;
	MyUnion myUnion;

	myUnion.myInt = 64;
	std::cout << "`myUnion.myInt = 64;`" << std::endl;

	std::cout << "myInt: " << myUnion.myInt << std::endl;
	std::cout << "myChar: " << myUnion.myChar << std::endl;
	std::cout << std::endl;

	myUnion.myChar = ' ';
	std::cout << "`myUnion.myChar = ' ';`" << std::endl;

	std::cout << "myInt: " << myUnion.myInt << std::endl;
	std::cout << "myChar: " << myUnion.myChar << std::endl;
	std::cout << std::endl;

	myUnion.myInt = 96;
	std::cout << "`myUnion.myInt = 96;`" << std::endl;

	std::cout << "myInt: " << myUnion.myInt << std::endl;
	std::cout << "myChar: " << myUnion.myChar << std::endl;
	std::cout << std::endl;

	myUnion.myChar = '@';
	std::cout << "`myUnion.myChar = '@';`" << std::endl;

	std::cout << "myInt: " << myUnion.myInt << std::endl;
	std::cout << "myChar: " << myUnion.myChar << std::endl;
	std::cout << std::endl;

	myUnion.myInt = 100;
	std::cout << "`myUnion.myInt = 100;`" << std::endl;

	std::cout << "myInt: " << myUnion.myInt << std::endl;
	std::cout << "myChar: " << myUnion.myChar << std::endl;
	std::cout << std::endl;

	myUnion.myChar = '%';
	std::cout << "`myUnion.myChar = '%';`" << std::endl;

	std::cout << "myInt: " << myUnion.myInt << std::endl;
	std::cout << "myChar: " << myUnion.myChar << std::endl;
	std::cout << std::endl;

	std::cin.get();
}