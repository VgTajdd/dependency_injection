// ========================================================================= //
// Copyright (c) 2022 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// source.cpp                                                                //
// ========================================================================= //

#include "pkg/pkg.h"
#include "pkg/DIContainer.h"

#include "ServicesInterfaces.h"
#include "ServicesImplementations.h"
#include "ClientClass.h"

int main( int, char** )
{
	printHelloWorld();
	printNumber( getFibonacci( 5 ) );

	DIContainer container;
	container.registerService<IPowerOfTwoGenerator, PowerOfTwoGenerator>();
	const auto& service{ container.getService<IPowerOfTwoGenerator>() };
	std::cout << service->value() << std::endl;

	return 0;
}
