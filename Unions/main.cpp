#include "main.h"

// In contrasting unions and structs, observe that when I change one member of a
// union, the other member of the union is changed as well. This behavior holds
// true for when there are more than two members as well. Also observe that the
// same is not true for structs, where changing one member does not change the
// other member(s) of the struct.

// The reason for this is that the compiler treats each of the union members as
// typed aliases for the same block of memory (which will be large enough to
// accommodate the largest member of the union). Meanwhile, the compiler treats
// each of the struct members as different locations in memory entirely.

// The result is that when we have the following union and struct:
union BigUnion
{
	int myInt;          // 4 bytes
	char myChar;        // 1 byte
	float myFloat;      // 4 bytes
	int* myIntPointer; // 4 bytes on x86 and 8 bytes on x64
};
struct BigStruct
{
	int myInt;          // 4 bytes
	char myChar;        // 1 byte
	float myFloat;      // 4 bytes
	int* myIntPointer; // 4 bytes on x86 and 8 bytes on x64
};

// The size of a BigUnion variable will be at least 4 bytes on x86 and 8 bytes
// on x64 (the exact size depending on the compiler)...
BigUnion bigUnion;
const int bigUnionSize = sizeof(bigUnion); // For me: x86 = 4 and x64 = 8
// and the size of a BigStruct variable will be at least 13 bytes on x86 and 17
// bytes on x64 (the exact size depending on the compiler). Note that the size
// will likely be larger due to padding and other compiler speed optimizations.
BigStruct bigStruct;
const int bigStructSize = sizeof(BigStruct); // For me: x86 = 16 and x64 = 24

// In memory, this is likely what is happening for x86 on my computer:

/* bigUnion

	 4 bytes is the
 /--largest type --\
+----+----+----+----+
| b0 | b1 | b2 | b3 |  <---------+
+----+----+----+----+            |
																 |
All the values get packed        |
together into those four bytes --+

*/

/* bigStruct

	 4 bytes is the      1 byte for char     4 bytes is the      4 bytes is the
 /--integer type --\ /-3 bytes padding-\ /---float type ---\ /--pointer type --\
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
| b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7 | b8 | b9 | bA | bB | bC | bD | bE | bF |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+

*/

int main(void)
{
	example4();
	contrast4();

	return 0;
}