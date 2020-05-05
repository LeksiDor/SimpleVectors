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
	for ( int i = 0; i < 2; ++i )
		for ( int j = 0; j < 2; ++j )
			REQUIRE( m(i,j) == Approx(ref(i,j)) );
}


void CheckMat33( const Mat33& m, const Mat33& ref )
{
	for ( int i = 0; i < 3; ++i )
		for ( int j = 0; j < 3; ++j )
			REQUIRE( m(i,j) == Approx(ref(i,j)) );
}


void CheckMat44( const Mat44& m, const Mat44& ref )
{
	for ( int i = 0; i < 4; ++i )
		for ( int j = 0; j < 4; ++j )
			REQUIRE( m(i,j) == Approx(ref(i,j)) );
}