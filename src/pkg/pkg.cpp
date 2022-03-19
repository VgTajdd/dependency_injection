// ========================================================================= //
// Copyright (c) 2022 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// pkg.cpp                                                                   //
// ========================================================================= //

#include "pkg/pkg.h"

#include <iostream>

void printHelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void printNumber( int number )
{
	std::cout << number << std::endl;
}

int getFibonacci( int n )
{
	if ( n == 0 )
	{
		return 0;
	}
	else if ( n == 1 )
	{
		return 1;
	}
	else
	{
		return getFibonacci( n - 1 ) + getFibonacci( n - 2 );
	}
}