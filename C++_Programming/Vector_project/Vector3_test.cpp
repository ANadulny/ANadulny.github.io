#define BOOST_TEST_MODULE PROI_task2
#include <boost/test/unit_test.hpp>
#include "Vector3.h"

BOOST_AUTO_TEST_SUITE(Vector3Tests)
BOOST_AUTO_TEST_CASE(constructed_Vector3_X)  //double getX() { return x;}
{
    const Vector3 v;
    BOOST_CHECK_EQUAL(v.getX(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector3_Y) //double getY() { return y;}
{
    const Vector3 v;
    BOOST_CHECK_EQUAL(v.getY(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector3_Z) //double getZ() { return z;}
{
    const Vector3 v;
    BOOST_CHECK_EQUAL(v.getZ(), 0);
}

BOOST_AUTO_TEST_CASE(vector3_comparing)  //bool Vector3::operator ==(const Vector3 &v)
{
	const Vector3 v(2.1, 2), w(2.1,2);
    BOOST_CHECK( v == w );
}

BOOST_AUTO_TEST_CASE( vector3_plus )  //Vector3 Vector3::operator +(const Vector3 &v)
{
	const Vector3 v(2.1, 2), w(1, 2), z(3.1, 4);
    BOOST_CHECK( (v+w) == z );
}

BOOST_AUTO_TEST_CASE( vector3_minus )  //Vector3 Vector3::operator -(const Vector3 &v)
{
	const Vector3 v(2.1,2), w(1,2), z(1.1, 0);
    BOOST_CHECK( (v-w) == z);
}

BOOST_AUTO_TEST_CASE( vector3_plus1 )  //Vector3 & Vector3::operator +=(const Vector3 &v)
{
	Vector3 v(2.1,2);
	const Vector3 w(7.1,7,5);
	double d=5;
    BOOST_CHECK( (v+=d) == w );
}

BOOST_AUTO_TEST_CASE( vector3_minus1 )  //Vector3 & Vector3::operator -=(const Vector3 &v)
{
	Vector3 v(2.1,2,2);
	const Vector3 w(1.1, 1,1);
	double d=1;
    BOOST_CHECK( (v-=d) == w );
}

BOOST_AUTO_TEST_CASE( vector3_multiplication )  //Vector3 Vector3::operator *( double d, const Vector3 &v)
{
	const Vector3 v(2.1,2), w(4.2,4);
	double d=2;
    BOOST_CHECK( (d*v) == w );
}

BOOST_AUTO_TEST_CASE( vector3_multiplication1 )  //Vector3 Vector3::operator *( const Vector3 &v ,double d)
{
	const Vector3 v(2.1,2), w(4.2,4);
	double d=2;
    BOOST_CHECK( (v*d) == w );
}

BOOST_AUTO_TEST_CASE( vector3_multiplication_return )  //Vector3 Vector3::operator *=(const  d)
{
	Vector3 v(2.1,2), w(4.2,4);
	double d=2;
    BOOST_CHECK( (v*=d) == w );
}

BOOST_AUTO_TEST_CASE( vector3_division )  //Vector3 Vector3::operator /(const  d)
{
	const Vector3 v(2.1,2), w(4.2,4);
	double d=0.5;
    BOOST_CHECK( (v/d) == w );
}

BOOST_AUTO_TEST_CASE( vector3_division1 )  //Vector3 Vector3::operator /=(const double &d)
{
	Vector3 v(2.1,2);
	const Vector3 w(4.2,4);
	double d=0.5;
    BOOST_CHECK( (v/=d) == w );
}

BOOST_AUTO_TEST_CASE( vector3_compare )  ////Vector3 & Vector2::operator =(const Vector3 &v)
{
    Vector3 v;
    const Vector3 w(4.2,4), z(4.2, 4);
    v=w;
    BOOST_CHECK( v == z );
}
BOOST_AUTO_TEST_SUITE_END()
