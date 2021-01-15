#pragma once

#include <iostream>
#include <ostream>

// These examples illustrate how unions work at their most basic level
void example1();
void example2();
void example3();
void example4();

union MyUnion
{
	int myInt;
	char myChar;
};

// These examples are counter examples contrasting unions with structs
void contrast1();
void contrast2();
void contrast3();
void contrast4();

struct MyStruct
{
	int myInt;
	char myChar;
};

// Only the ______4() functions are used, since the lower functions are only
// there to demonstrate how I contructed the macros and lambda functions

// See "main.cpp" for more
