#include <gtest/gtest.h>

#include <pkg/pkg.h>

TEST( TemplateTest, Test1 )
{
	EXPECT_EQ( getFibonacci( 5 ), 5 );
}
