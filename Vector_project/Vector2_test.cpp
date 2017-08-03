#define BOOST_TEST_MODULE PROI_task1
#include <boost/test/unit_test.hpp>
#include "Vector2.h"


BOOST_AUTO_TEST_SUITE(Vector2Tests)
BOOST_AUTO_TEST_CASE(constructed_Vector2_X)  //double getX() { return x;}
{
    const Vector2 v;
    BOOST_CHECK_EQUAL(v.getX(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector2_Y) //double getY() { return y;}
{
    const Vector2 v;
    BOOST_CHECK_EQUAL(v.getY(), 0);
}

BOOST_AUTO_TEST_CASE(vector2_comparing)  //bool Vector2::operator ==(const Vector2 &v)
{
	const Vector2 v(2.1, 2), w(2.1,2);
    BOOST_CHECK( v == w );
}

BOOST_AUTO_TEST_CASE( vector2_plus )  //Vector2 Vector2::operator +(const Vector2 &v)
{
	const Vector2 v(2.1, 2), w(1, 2), z(3.1, 4);
    BOOST_CHECK( (v+w) == z );
}

BOOST_AUTO_TEST_CASE( vector2_minus )  //Vector2 Vector2::operator -(const Vector2 &v)
{
	const Vector2 v(2.1,2), w(1,2), z(1.1, 0);
    BOOST_CHECK( (v-w) == z);
}

BOOST_AUTO_TEST_CASE( vector2_plus1 )  //Vector2 & Vector2::operator +=(const Vector2 &v)
{
	Vector2 v(2.1,2);
	const Vector2 w(7.1,7);
	double d=5;
    BOOST_CHECK( (v+=d) == w );
}

BOOST_AUTO_TEST_CASE( vector2_minus1 )  //Vector2 & Vector2::operator -=(const Vector2 &v)
{
	Vector2 v(2.1,2);
	const Vector2 w(1.1, 1);
	double d=1;
    BOOST_CHECK( (v-=d) == w );
}

BOOST_AUTO_TEST_CASE( vector2_multiplication )  //Vector2 Vector2::operator *( double d, const Vector2 &v)
{
	const Vector2 v(2.1,2), w(4.2,4);
	double d=2;
    BOOST_CHECK( (d*v) == w );
}

BOOST_AUTO_TEST_CASE( vector2_multiplication1 )  //Vector2 Vector2::operator *( const Vector2 &v ,double d)
{
	const Vector2 v(2.1,2), w(4.2,4);
	double d=2;
    BOOST_CHECK( (v*d) == w );
}

BOOST_AUTO_TEST_CASE( vector2_multiplication_return )  //Vector2 Vector2::operator *=( double d)
{
	Vector2 v(2.1,2);
	const Vector2 w(4.2,4);
	double d=2;
    BOOST_CHECK( (v*=d) == w );
}

BOOST_AUTO_TEST_CASE( vector2_division )  //Vector2 Vector2::operator /( double d)
{
	const Vector2 v(2.1,2), w(4.2,4);
	double d=0.5;
    BOOST_CHECK( (v/d) == w );
}

BOOST_AUTO_TEST_CASE( vector2_division1 )  //Vector2 Vector2::operator /=( double d)
{
	Vector2 v(2.1,2);
	const Vector2 w(4.2,4);
	double d=0.5;
    BOOST_CHECK( (v/=d) == w );
}

BOOST_AUTO_TEST_CASE( vector2_compare )  ////Vector2 & Vector2::operator =(const Vector2 &v)
{
    Vector2 v;
    const Vector2 w(4.2,4), z(4.2, 4);
    v=w;
    BOOST_CHECK( v == z );
}
BOOST_AUTO_TEST_SUITE_END()

