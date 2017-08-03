#define BOOST_TEST_MODULE PROI_task2
#include <boost/test/unit_test.hpp>
#include "vector.h"


BOOST_AUTO_TEST_SUITE(VectorTests)

BOOST_AUTO_TEST_CASE(constructed_Vector_GetLength)
{
    vector <> v;
    BOOST_CHECK_EQUAL(v.GetLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_GetMaxLegth)
{
    vector <> v;
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_float_GetLength)
{
    vector <float> v;
    BOOST_CHECK_EQUAL(v.GetLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_float_GetMaxLegth)
{
    vector <float> v;
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_int_GetLength)
{
    vector <int> v;
    BOOST_CHECK_EQUAL(v.GetLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_int_GetMaxLegth)
{
    vector <int> v;
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_GetLength)
{
    vector <char> v;
    BOOST_CHECK_EQUAL(v.GetLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_GetMaxLegth)
{
    vector <char> v;
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 0);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_with_elements_GetLength)
{
    vector <> v(4, 'z');
    BOOST_CHECK_EQUAL(v.GetLength(), 4);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_with_elements_GetMaxLength)
{
    vector <> v(4, 'z');
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_with_elements_GetElement)
{
    vector <> v(4, 'z');
    BOOST_CHECK_EQUAL(v.GetElement(0), 'z');
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_with_elements_GetLength)
{
    vector <> v(4, 'z');
    BOOST_CHECK_EQUAL(v.GetLength(), 4);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_with_elements_GetMaxLength)
{
    vector <> v(4, 'z');
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_with_elements_GetElement)
{
    vector <char> v(4, 'z');
    BOOST_CHECK_EQUAL(v.GetElement(0), 'z');
}

BOOST_AUTO_TEST_CASE(constructed_Vector_copy_with_elements)
{
    vector <> w(4, 'z');
    vector <> v(w);

    BOOST_CHECK_EQUAL(v.GetLength(), 4);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
    BOOST_CHECK_EQUAL(v.GetElement(0), 122);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_int_copy_with_elements)
{
    vector <int> w(4, 'z');
    vector <int> v(w);

    BOOST_CHECK_EQUAL(v.GetLength(), 4);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
    BOOST_CHECK_EQUAL(v.GetElement(0), 122);
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_copy_with_elements)
{
    vector <char> w(4, 'z');
    vector <char> v(w);

    BOOST_CHECK_EQUAL(v.GetLength(), 4);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
    BOOST_CHECK_EQUAL(v.GetElement(0), 'z');
}

BOOST_AUTO_TEST_CASE(constructed_Vector_char_to_char_copy_with_elements)
{
    vector <char> w(4, 'z');
    vector <char> v=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 4);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
    BOOST_CHECK_EQUAL(v.GetElement(0), 'z');
}

BOOST_AUTO_TEST_CASE(Vector_function_clear)
{
    vector <char> v(4, 'z');
    v.clear();

    BOOST_CHECK_EQUAL(v.GetLength(), 0);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 0);
}

BOOST_AUTO_TEST_CASE(Vector_function_pop_back)
{
    vector <> v(8, 'a');
    v.pop_back(2);

    BOOST_CHECK_EQUAL(v.GetLength(), 6);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(6), 97);
}

BOOST_AUTO_TEST_CASE(Vector_function_pop_back_for_char)
{
    vector <char> v(8, 'a');
    v.pop_back(2);

    BOOST_CHECK_EQUAL(v.GetLength(), 6);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(7), 0);
}

BOOST_AUTO_TEST_CASE(Vector_function_pop_back_for_int)
{
    vector <int> v(8, 'a');
    v.pop_back(3);

    BOOST_CHECK_EQUAL(v.GetLength(), 5);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(6), 0);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back)
{
    vector <> v(8, 'a');
    v.push_back(2);

    BOOST_CHECK_EQUAL(v.GetLength(), 9);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 2);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_char)
{
    vector <char> v(8, 'a');
    v.push_back('n');

    BOOST_CHECK_EQUAL(v.GetLength(), 9);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 'n');
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_int)
{
    vector <int> v(8, 'a');
    v.push_back(3);

    BOOST_CHECK_EQUAL(v.GetLength(), 9);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 3);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_elements)
{
    vector <> v(8, 'a');
    v.push_back(2, 2);

    BOOST_CHECK_EQUAL(v.GetLength(), 10);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 2);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_char_elements)
{
    vector <char> v(8, 'a');
    v.push_back(3, 'n');

    BOOST_CHECK_EQUAL(v.GetLength(), 11);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 'n');
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_int_elements)
{
    vector <int> v(8, 'a');
    v.push_back(4, 3);

    BOOST_CHECK_EQUAL(v.GetLength(), 12);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 3);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_allocate_elements)
{
    vector <> v(4, 21);
    v.push_back(5, 2);

    BOOST_CHECK_EQUAL(v.GetLength(), 9);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 2);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_char_allocate_elements)
{
    vector <char> v(4, 'a');
    v.push_back(5, 'n');

    BOOST_CHECK_EQUAL(v.GetLength(), 9);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 'n');
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_int_allocate_elements)
{
    vector <int> v(4, 7);
    v.push_back(5, 3);

    BOOST_CHECK_EQUAL(v.GetLength(), 9);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(8), 3);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_resize)
{
    vector <> v(4, 6);
    v.resize(32, 2);

    BOOST_CHECK_EQUAL(v.GetLength(), 32);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 64);
    BOOST_CHECK_EQUAL(v.GetElement(8), 2);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_char_resize)
{
    vector <char> v(4, 'a');
    v.resize(32, 'c');

    BOOST_CHECK_EQUAL(v.GetLength(), 32);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 64);
    BOOST_CHECK_EQUAL(v.GetElement(8), 'c');
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_for_int_resize)
{
    vector <int> v(4, 7);
    v.resize(2);

    BOOST_CHECK_EQUAL(v.GetLength(), 2);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 8);
    BOOST_CHECK_EQUAL(v.GetElement(3), 0);
}

BOOST_AUTO_TEST_CASE(Vector_function_is_empty)
{
    vector <> v;
    BOOST_CHECK_EQUAL(v.is_empty(), true); //albo 1

}

BOOST_AUTO_TEST_CASE(Vector_function_equal)
{
    vector <char> w(8, 121);
    vector <char> v=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 8);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 'y');
}

BOOST_AUTO_TEST_CASE(Vector_function_equal_double_to_double)
{
    vector <double> w(8, 'a');
    vector <double> v=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 8);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 97);
}


BOOST_AUTO_TEST_CASE(Vector_function_equal_int_to_int)
{
    vector <int> w(8, 9);
    vector <int> v=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 8);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 9);
}

BOOST_AUTO_TEST_CASE(Vector_function_equal_char_to_char)
{
    vector <char> w(8, 'n');
    vector <char> v=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 8);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 'n');
}

BOOST_AUTO_TEST_CASE(Vector_function_addition)
{
    vector <char> w(8, 'n');
    vector <char> v(2, 'a');
    v+=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 10);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 'n');
}

BOOST_AUTO_TEST_CASE(Vector_function_addition_double)
{
    vector <double> w(8, 5);
    vector <double> v(2, 4);
    v+=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 10);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 5);
}

BOOST_AUTO_TEST_CASE(Vector_function_addition_double_to_char)
{
    vector <double> w(8, 'c');
    vector <char> v(2, 'b');
    v+=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 10);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 'c');
}

BOOST_AUTO_TEST_CASE(Vector_function_addition_char_to_double)
{
    vector <char> w(8, 'b');
    vector <double> v(2, 5);
    v+=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 10);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 16);
    BOOST_CHECK_EQUAL(v.GetElement(3), 98);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_constructor_int)
{
    vector <int> v;
    v.push_back(5);

    BOOST_CHECK_EQUAL(v.GetLength(), 1);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 10);
    BOOST_CHECK_EQUAL(v.GetElement(0), 5);
}

BOOST_AUTO_TEST_CASE(Vector_function_push_back_constructor_char)
{
    vector <char> v;
    v.push_back('a');

    BOOST_CHECK_EQUAL(v.GetLength(), 1);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 10);
    BOOST_CHECK_EQUAL(v.GetElement(0), 'a');

}

BOOST_AUTO_TEST_CASE(Vector_function_addition_double_to_constructor)
{
    vector <double> w(8, 'b');
    vector <double> v;
    v+=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 8);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 10);
    BOOST_CHECK_EQUAL(v.GetElement(0), 98);
}

BOOST_AUTO_TEST_CASE(Vector_function_addition_char_to_constructor)
{
    vector <char> w(8, 'b');
    vector <double> v;
    v+=w;

    BOOST_CHECK_EQUAL(v.GetLength(), 8);
    BOOST_CHECK_EQUAL(v.GetMaxLength(), 10);
    BOOST_CHECK_EQUAL(v.GetElement(0), 'b');
}

BOOST_AUTO_TEST_SUITE_END()

