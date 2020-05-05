#include "catch.hpp"

#include "SimpleMatrices.h"

TEST_CASE( "Matrix", "[Mat22]" )
{
	SECTION( "Add" )
	{
		Mat22 A( 1, 2, 3, 4 );
		Mat22 B( 5, 6, 7, 8 );
		Mat22 C = A + B;
		Mat22 ref( 6, 8, 10, 12 );
		CheckMat22( C, ref );
	}
}