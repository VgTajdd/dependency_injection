// ========================================================================= //
// Copyright (c) 2022 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// test.cpp                                                                  //
// ========================================================================= //

#include <gtest/gtest.h>

#include "pkg/pkg.h"
#include "pkg/DIContainer.h"

#include "ServicesInterfaces.h"
#include "ServicesImplementations.h"
#include "ClientClass.h"

TEST( TemplateTest, Test1 )
{
	EXPECT_EQ( getFibonacci( 5 ), 5 );
}

TEST( TemplateTest, Test2 )
{
	DIContainer container;
	container.registerService<IPowerOfTwoGenerator, PowerOfTwoGenerator>();
	const auto& service{ container.getService<IPowerOfTwoGenerator>() };

	EXPECT_EQ( service->value(), 2 );
}

TEST( TemplateTest, Test3 )
{
	DIContainer container;
	container.registerService<IPowerOfThreeGenerator, PowerOfThreeGenerator, int>( 2 );
	const auto& service{ container.getService<IPowerOfThreeGenerator>() };

	EXPECT_EQ( service->value(), 9 );
}

TEST( TemplateTest, Test4 )
{
	DIContainer container;
	container.registerService<IPowerOfTwoGenerator, PowerOfTwoGenerator>();
	container.registerService<IPowerOfThreeGenerator, PowerOfThreeGenerator, int>( 2 );

	ClientClass client;
	const auto result{ client.evaluate( container ) };

	EXPECT_EQ( result, 11 );
}