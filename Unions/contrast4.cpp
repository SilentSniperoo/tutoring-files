#include "main.h"

void contrast4()
{
	std::cout << "----- Example 4 -----" << std::endl;
	MyStruct myStruct;

	// Lambda functions are super cool!
	auto dump = [&myStruct](const char * firstLine) {
		std::cout << "'" << firstLine << "'" << std::endl;
		std::cout << "myInt: " << myStruct.myInt << std::endl;
		std::cout << "myChar: " << myStruct.myChar << std::endl;
		std::cout << std::endl;
	};

	// Macros are also super cool!
#define DO_AND_DUMP(x) x dump(#x)

	DO_AND_DUMP(myStruct.myInt = 64;);
	DO_AND_DUMP(myStruct.myChar = ' ';);
	DO_AND_DUMP(myStruct.myInt = 96;);
	DO_AND_DUMP(myStruct.myChar = '@';);
	DO_AND_DUMP(myStruct.myInt = 100;);
	DO_AND_DUMP(myStruct.myChar = '%';);

	std::cin.get();
}