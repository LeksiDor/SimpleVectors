#include "catch.hpp"
#include "SimpleVectors.h"
#include "SimpleMatrices.h"


void CheckVec2( const Vec2& v, const Vec2& ref )
{
	for ( int i = 0; i < 2; ++i )
		REQUIRE( v[i] == Approx(ref[i]) );
}


void CheckVec3( const Vec3& v, const Vec3& ref )
{
	for ( int i = 0; i < 3; ++i )
		REQUIRE( v[i] == Approx(ref[i]) );
}


void CheckVec4( const Vec4& v, const Vec4& ref )
{
	for ( int i = 0; i < 4; ++i )
		REQUIRE( v[i] == Approx(ref[i]) );
}


void CheckMat22( const Mat22& m, const Mat22& ref )
{
	for ( int i = 0; i < 4; ++i )
		REQUIRE( m.data[i] == Approx(ref.data[i]) );
}


void CheckMat33( const Mat33& m, const Mat33& ref )
{
	for ( int i = 0; i < 9; ++i )
		REQUIRE( m.data[i] == Approx(ref.data[i]) );
}


void CheckMat44( const Mat44& m, const Mat44& ref )
{
	for ( int i = 0; i < 16; ++i )
		REQUIRE( m.data[i] == Approx(ref.data[i]) );
}