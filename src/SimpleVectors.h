#ifndef SIMPLEVECTORS_H
#define SIMPLEVECTORS_H

#ifdef SIMPLEVECTORS_INT_IS_LONG
typedef long int Int;
#else // SIMPLEVECTORS_INT_IS_LONG
typedef int Int;
#endif // SIMPLEVECTORS_INT_IS_LONG

#ifdef SIMPLEVECTORS_REAL_IS_DOUBLE
typedef double Real;
#else // SIMPLEVECTORS_REAL_IS_DOUBLE
typedef float Real;
#endif // SIMPLEVECTORS_REAL_IS_DOUBLE

#include <cassert>
#include <cmath>

template <size_t DIM, typename T> struct vec;

typedef vec<2,Real> Vec2;
typedef vec<3,Real> Vec3;
typedef vec<4,Real> Vec4;

typedef vec<2,Int> Vec2i;
typedef vec<3,Int> Vec3i;
typedef vec<4,Int> Vec4i;


template <size_t DIM, typename T> struct vec
{
	vec() { for (size_t i=DIM; i--; data_[i] = T()); }
	vec<DIM,T>& operator = ( const vec<DIM,T> &v ) { for( size_t i = DIM; i--; this->data_[i] = v[i] ); }
	T& operator[](const size_t i)       { assert(i<DIM); return data_[i]; }
	const T& operator[](const size_t i) const { assert(i<DIM); return data_[i]; }
	template<typename U> vec<DIM,U> toType() const { vec<DIM,U> result; for( size_t i = DIM; i--; result[i] = (U)data_[i] ); return result; }
private:
	T data_[DIM];
};


template <typename T> struct vec<2,T>
{
	vec() noexcept : x(T()), y(T()) {}
	vec( const T &X, const T &Y ) noexcept : x(X), y(Y) {}
	vec<2,T>& operator = (const vec<2,T> &v) { x=v.x; y=v.y; return *this; }
	T& operator[](const size_t i)       { assert(i<2); return i<=0 ? x : y; }
	const T& operator[](const size_t i) const { assert(i<2); return i<=0 ? x : y; }
	template<typename U> vec<2,U> toType() const { return vec<2,U>(x,y); }
	T norm() const { return std::sqrt(x*x+y*y); }
	vec<2,T>& normalize() { *this = (*this)/norm(); return *this; }
	vec<2,T> normalized() const { return (*this)/norm(); }
	T x,y;
};


template <typename T> struct vec<3,T>
{
	vec() noexcept : x(T()), y(T()), z(T()) {}
	vec( const T &X, const T &Y, const T &Z ) noexcept : x(X), y(Y), z(Z) {}
	vec( const vec<2,T>& XY, const T& Z = (T)0 ) noexcept : x(XY.x), y(XY.y), z(Z) {}
	vec<3,T>& operator = (const vec<3,T> &v) { x=v.x; y=v.y; z=v.z; return *this; }
	T& operator[](const size_t i)       { assert(i<3); return i<=0 ? x : (1==i ? y : z); }
	const T& operator[](const size_t i) const { assert(i<3); return i<=0 ? x : (1==i ? y : z); }
	template<typename U> vec<3,U> const toType() { return vec<3,U>(x,y,z); }
	T norm() const { return std::sqrt(x*x+y*y+z*z); }
	vec<3,T>& normalize() { *this = (*this)/norm(); return *this; }
	vec<3,T> normalized() const { return (*this)/norm(); }
	union
	{
		struct { T x; T y; T z; };
		struct { vec<2,T> xy; T z; };
		struct { T x; vec<2,T> yz; };
	};
};


template <typename T> struct vec<4,T>
{
	vec() noexcept : x(T()), y(T()), z(T()), w(T()) {}
	vec( const T& X, const T& Y, const T& Z, const T& W ) noexcept : x(X), y(Y), z(Z), w(W) {}
	vec( const vec<2,T>& XY, const T& Z, const T& W ) noexcept : x(XY.x), y(XY.y), z(Z), w(W) {}
	vec( const vec<2,T>& XY, const vec<2,T>& ZW ) noexcept : x(XY.x), y(XY.y), z(ZW.x), w(ZW.y) {}
	vec( const vec<3,T>& XYZ, const T& W = (T)0 ) noexcept : x(XYZ.x), y(XYZ.y), z(XYZ.z), w(W) {}
	vec<4,T>& operator = (const vec<4,T> &v) { x=v.x; y=v.y; z=v.z; w=v.w; return *this; }
	T& operator[](const size_t i)       { assert(i<4); return i<=0 ? x : (1==i ? y : (2==i ? z : w)); }
	const T& operator[](const size_t i) const { assert(i<4); return i<=0 ? x : (1==i ? y : (2==i ? z : w)); }
	template<typename U> vec<4,U> toType() const { return vec<4,U>(x,y,z,w); }
	T norm() const { return std::sqrt(x*x+y*y+z*z+w*w); }
	vec<4,T>& normalize() { *this = (*this)/norm(); return *this; }
	vec<4,T> normalized() const { return (*this)/norm(); }
	union
	{
		struct { T x; T y; T z; T w; };
		struct { vec<2,T> xy; vec<2,T> zw; };
		struct { vec<3,T> xyz; T w; };
		struct { T x; vec<3,T> yzw; };
	};
};


template<size_t DIM,typename T> T dot( const vec<DIM,T>& lhs, const vec<DIM,T>& rhs )
{
	T ret = T();
	for (size_t i=DIM; i--; ret+=lhs[i]*rhs[i]);
	return ret;
}


template<size_t DIM,typename T>vec<DIM,T> operator + ( vec<DIM,T> lhs, const vec<DIM,T> &rhs )
{
	for (size_t i=DIM; i--; lhs[i]+=rhs[i]);
	return lhs;
}


template<size_t DIM,typename T>vec<DIM,T> operator - ( vec<DIM,T> lhs, const vec<DIM,T>& rhs)
{
	for (size_t i=DIM; i--; lhs[i]-=rhs[i]);
	return lhs;
}


template<size_t DIM,typename T> bool operator == ( const vec<DIM,T>& lhs, const vec<DIM,T>& rhs)
{
	for ( size_t i = 0; i < DIM; ++i )
	{
		if ( lhs[i] != rhs[i] )
			return false;
	}
	return true;
}


template<size_t DIM,typename T,typename U> vec<DIM,T> operator * ( const vec<DIM,T>& lhs, const U& rhs )
{
	vec<DIM,T> ret;
	for (size_t i=DIM; i--; ret[i]=lhs[i]*rhs);
	return ret;
}


template<size_t DIM,typename T,typename U> vec<DIM,T> operator * ( const U& lhs, const vec<DIM,T>& rhs )
{
	vec<DIM,T> ret;
	for (size_t i=DIM; i--; ret[i]=rhs[i]*lhs);
	return ret;
}


template<size_t DIM,typename T> vec<DIM,T> operator * ( const vec<DIM,T>& lhs, const vec<DIM,T>& rhs )
{
	vec<DIM,T> ret;
	for (size_t i=DIM; i--; ret[i]=lhs[i]*rhs[i]);
	return ret;
}


template<size_t DIM,typename T,typename U> vec<DIM,T> operator / ( const vec<DIM,T>& lhs, const U& rhs )
{
	vec<DIM,T> ret;
	for (size_t i=DIM; i--; ret[i]=lhs[i]/rhs);
	return ret;
}


template<size_t DIM,typename T> vec<DIM,T> operator / ( const vec<DIM,T>& lhs, const vec<DIM,T>& rhs )
{
	vec<DIM,T> ret;
	for (size_t i=DIM; i--; ret[i]=lhs[i]/rhs[i]);
	return ret;
}


template<size_t DIM,typename T> vec<DIM,T> operator - ( const vec<DIM,T> &lhs )
{
	return lhs*T(-1);
}


template <typename T> T dot( const vec<3,T>& v1, const vec<3,T>& v2 )
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}


template <typename T> vec<3,T> cross( const vec<3,T>& v1, const vec<3,T>& v2 )
{
	return vec<3,T>(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}


#endif // SIMPLEVECTORS_H