#include "pkg/pkg.h"

int main( int, char** )
{
	printHelloWorld();
	printNumber( getFibonacci( 5 ) );
	return 0;
}
