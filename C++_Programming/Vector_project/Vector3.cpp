#include "Vector3.h"
using namespace std;


Vector3 Vector3::operator +(const Vector3 &v) const
//Vector3 Vector3::operator +(Vector3 v) const
        {
        //return v += *this;
          return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
        }

Vector3 Vector3::operator +=( double d)
        {

          this->x+=d;
          this->y+=d;
          this->z+=d;
          return *this;
        }

Vector3 operator *( const Vector3 &v, double d)
        {
          Vector3 one(v.getX()*d, v.getY()*d, v.getZ()*d);
          return one;
        }

Vector3 operator *( double d, const Vector3 &v)
        {
          Vector3 one(d*v.getX(), d*v.getY(),d*v.getZ());
          return one;
        }

Vector3 Vector3::operator *=( double d)
        {

          this->x*=d;
          this->y*=d;
          this->z*=d;
          return *this;
        }
Vector3 Vector3::operator -(const Vector3 &v) const
        {
            return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
        }
Vector3 Vector3::operator -=( double d)
        {

          this->x-=d;
          this->y-=d;
          this->z-=d;
          return *this;
        }
Vector3 Vector3::operator /( double d) const
        {
          if(d==0)
             return *this;

          return Vector3(this->x / d, this->y / d, this->z / d);
        }
Vector3  Vector3::operator /=( double d)
        {

          if(d==0)
             return *this;

          this->x/=d;
          this->y/=d;
          this->z/=d;
          return *this;
        }
Vector3 & Vector3::operator =(const Vector3 &v)
        {
           if(&v != this)
           {
           x=v.x;
           y=v.y;
           z=v.z;
           }
           return *this;
        }
bool Vector3::operator ==(const Vector3 &v) const
        {
            if((this->x == v.x)&& (this->y == v.y)&& (this->z == v.z))
               return true;
            else
              return false;
        }

