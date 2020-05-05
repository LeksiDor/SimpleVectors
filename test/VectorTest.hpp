#include "catchhelpers.hpp"


TEST_CASE( "Vector", "[Vec2]" )
{
	SECTION( "Add" )
	{
		Vec2 a( 1, 2 );
		Vec2 b( 3, 4 );
		Vec2 c = a + b;
		Vec2 ref( 4, 6 );
		CheckVec2( c, ref );
	}
}