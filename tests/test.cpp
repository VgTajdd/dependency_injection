#include <gtest/gtest.h>

#include <pkg/pkg.h>

TEST( TemplateTest, Test1 )
{
	EXPECT_EQ( getFibonacci( 5 ), 5 );
}

TEST( TemplateTest, Test2 )
{
	RegisterService<IPowerOfTwoGenerator, PowerOfTwoGenerator>();
	const auto& service{ GetService<IPowerOfTwoGenerator>() };

	EXPECT_EQ( service->value(), 2 );
}

TEST( TemplateTest, Test3 )
{
	RegisterService<IPowerOfThreeGenerator, PowerOfThreeGenerator, int>( 2 );
	const auto& service{ GetService<IPowerOfThreeGenerator>() };

	EXPECT_EQ( service->value(), 9 );
}
