#include "main.h"

void example3()
{
	std::cout << "----- Example 3 -----" << std::endl;
	MyUnion myUnion;

	// Lambda functions are super cool!
	auto dump = [&myUnion](const char * firstLine) {
		std::cout << "'" << firstLine << "'" << std::endl;
		std::cout << "myInt: " << myUnion.myInt << std::endl;
		std::cout << "myChar: " << myUnion.myChar << std::endl;
		std::cout << std::endl;
	};

	myUnion.myInt = 64;
	dump("`myUnion.myInt = '64';`");

	myUnion.myChar = ' ';
	dump("`myUnion.myChar = ' ';`");

	myUnion.myInt = 96;
	dump("`myUnion.myInt = 96;`");

	myUnion.myChar = '@';
	dump("`myUnion.myChar = '@';`");

	myUnion.myInt = 100;
	dump("`myUnion.myInt = 100;`");

	myUnion.myChar = '%';
	dump("`myUnion.myChar = '%';`");

	std::cin.get();
}