#include "main.h"

void example2()
{
	std::cout << "----- Example 2 -----" << std::endl;
	MyUnion myUnion;

	// Lambda functions are super cool!
	auto dump = [&myUnion]() {
		std::cout << "myInt: " << myUnion.myInt << std::endl;
		std::cout << "myChar: " << myUnion.myChar << std::endl;
		std::cout << std::endl;
	};

	myUnion.myInt = 64;
	std::cout << "`myUnion.myInt = 64;`" << std::endl;
	dump();

	myUnion.myChar = ' ';
	std::cout << "`myUnion.myChar = ' ';`" << std::endl;
	dump();

	myUnion.myInt = 96;
	std::cout << "`myUnion.myInt = 96;`" << std::endl;
	dump();

	myUnion.myChar = '@';
	std::cout << "`myUnion.myChar = '@';`" << std::endl;
	dump();

	myUnion.myInt = 100;
	std::cout << "`myUnion.myInt = 100;`" << std::endl;
	dump();

	myUnion.myChar = '%';
	std::cout << "`myUnion.myChar = '%';`" << std::endl;
	dump();

	std::cin.get();
}