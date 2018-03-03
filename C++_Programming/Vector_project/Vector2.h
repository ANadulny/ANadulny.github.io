#ifndef VECTOR2_H
#define VECTOR2_H
#include <iostream>
#include<string>

class Vector2;

Vector2 operator *( const Vector2 &v, double d);
Vector2 operator *( double d, const Vector2 &v);

class Vector2
{
       double x;
       double y;

    public:
        double getX()const { return x;}
        double getY()const { return y;}

        Vector2(double xx=0,double yy=0) :x(xx), y(yy) {}
        bool operator ==(const Vector2 &v)const;
        Vector2 operator +(const Vector2 &v)const;
        Vector2 operator +=( double d);
        Vector2 operator *=( double d);
        Vector2 operator -(const Vector2 &v)const;
        Vector2 operator -=( double d);
        Vector2 operator /( double d)const;
        Vector2 operator /=( double d);
        Vector2 & operator =(const Vector2 &v);

};


#endif // VECTOR2_H
