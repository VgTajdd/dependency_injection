// ========================================================================= //
// Copyright (c) 2022 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// source.cpp                                                                //
// ========================================================================= //

#include "pkg/pkg.h"

int main( int, char** )
{
	printHelloWorld();
	printNumber( getFibonacci( 5 ) );
	return 0;
}