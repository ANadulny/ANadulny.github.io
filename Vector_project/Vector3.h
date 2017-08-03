#include <iostream>
#include<string>
#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3;

Vector3 operator *( const Vector3 &v, double d);
Vector3 operator *( double d, const Vector3 &v);

class Vector3
{
       double x;
       double y;
       double z;

    public:
        double getX() const { return x;}
        double getY() const { return y;}
        double getZ() const { return z;}


        Vector3(double xx=0,double yy=0,double zz=0) :x(xx), y(yy) , z(zz) {}
        bool operator ==(const Vector3 &v) const;
        Vector3 operator +(const Vector3 &v) const;
        Vector3 operator +=(double d);
        Vector3 operator *=( double d);
        Vector3 operator -(const Vector3 &v)const;
        Vector3 operator -=(double d);
        Vector3 operator /(double d)const;
        Vector3  operator /=(double d);
        Vector3 & operator =(const Vector3 &v);

};

#endif // VECTOR3_H

