#include "catch.hpp"

#include "SimpleVectors.h"

TEST_CASE( "Vector", "[Vec2]" )
{
	SECTION( "Add" )
	{
		Vec2 a( 1, 2 );
		Vec2 b( 3, 4 );
		Vec2 c = a + b;

		REQUIRE( c.x == Approx(4) );
		REQUIRE( c.y == Approx(6) );
	}
}