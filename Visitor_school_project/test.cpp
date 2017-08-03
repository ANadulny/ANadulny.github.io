
#define BOOST_TEST_MODULE PROI_task3
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <vector>
#include "Visitor.cpp"
#include "Interface.h"
#include "Tests.h"
using namespace std;
BOOST_AUTO_TEST_SUITE(VisitorTests)

BOOST_AUTO_TEST_CASE(SharpTurnRight)
{
	BOOST_CHECK(TestSharpTurnRight() == 1);
}

BOOST_AUTO_TEST_CASE(SharpTurnLeft)
{
    BOOST_CHECK(TestSharpTurnLeft() == 1);
}

BOOST_AUTO_TEST_CASE(GoStraightOn)
{
    BOOST_CHECK(TestGoStraightOn() == 1);
}

BOOST_AUTO_TEST_CASE(TurnLeft)
{
    BOOST_CHECK(TestTurnLeft() == 1);
}

BOOST_AUTO_TEST_CASE(TurnRight)
{
    BOOST_CHECK(TestTurnRight() == 1);
}

BOOST_AUTO_TEST_CASE(Rondo)
{
    BOOST_CHECK(TestRondo() == 1);
}

BOOST_AUTO_TEST_CASE(CrossroadsGoStraightOn)
{
   BOOST_CHECK(TestCrossroadsGoStraightOn() == 1);
}

BOOST_AUTO_TEST_CASE(CrossroadsTurnRight)
{
    BOOST_CHECK(TestCrossroadsTurnRight() == 1);
}

BOOST_AUTO_TEST_CASE(CrossroadsTurnLeft)
{
   BOOST_CHECK(TestCrossroadsTurnLeft() == 1);
}

BOOST_AUTO_TEST_CASE(TurnBack)
{
    BOOST_CHECK(TestTurnBack() == 1);
}

BOOST_AUTO_TEST_CASE(RondoExitFirst)
{
   BOOST_CHECK(TestRondoExitFirst() == 1);
}

BOOST_AUTO_TEST_CASE(RondoExitFourth)
{
    BOOST_CHECK(TestRondoExitFourth() == 1);
}

BOOST_AUTO_TEST_CASE(GoStraightOnFourKm)
{
    BOOST_CHECK(TestGoStraightOnFourKm() == 1);
}

BOOST_AUTO_TEST_CASE(GoStraightOnTwentyKm)
{
    BOOST_CHECK(TestGoStraightOnTwentyKm() == 1);
}

BOOST_AUTO_TEST_CASE(GoStraightOnKm)
{
    BOOST_CHECK(TestGoStraightOnKm() == 1);
}

BOOST_AUTO_TEST_CASE(NumberOfTurnLeft)
{
    BOOST_CHECK(TestNumberOfTurnLeft() == 1);
}

BOOST_AUTO_TEST_CASE(NumberOfTurnLeftWithZero)
{
    BOOST_CHECK(TestNumberOfTurnLeftWithZero() == 1);
}

BOOST_AUTO_TEST_CASE(RemoveOne)
{
    BOOST_CHECK(TestRemoveOne() == 1);
}

BOOST_AUTO_TEST_CASE(RemoveAll)
{
    BOOST_CHECK(TestRemoveAll() == 1);
}


BOOST_AUTO_TEST_SUITE_END()
