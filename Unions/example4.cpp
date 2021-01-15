#include "main.h"

void example4()
{
	std::cout << "----- Example 4 -----" << std::endl;
	MyUnion myUnion;

	// Lambda functions are super cool!
	auto dump = [&myUnion](const char * firstLine) {
		std::cout << "'" << firstLine << "'" << std::endl;
		std::cout << "myInt: " << myUnion.myInt << std::endl;
		std::cout << "myChar: " << myUnion.myChar << std::endl;
		std::cout << std::endl;
	};

	// Macros are also super cool!
#define DO_AND_DUMP(x) x dump(#x)

	DO_AND_DUMP(myUnion.myInt = 64;);
	DO_AND_DUMP(myUnion.myChar = ' ';);
	DO_AND_DUMP(myUnion.myInt = 96;);
	DO_AND_DUMP(myUnion.myChar = '@';);
	DO_AND_DUMP(myUnion.myInt = 100;);
	DO_AND_DUMP(myUnion.myChar = '%';);

	std::cin.get();
}