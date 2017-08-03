#include "Vector2.h"
using namespace std;


Vector2 Vector2::operator +(const Vector2 &v) const
        {
          return Vector2(this->x + v.x, this->y + v.y);
        }

Vector2 Vector2::operator +=( double d)
        {

          this->x+=d;
          this->y+=d;
          return *this;
        }
Vector2 operator *( const Vector2 &v, double d)
        {
          Vector2 one(v.getX()*d, v.getY()*d);
          return one;
        }

Vector2 operator *( double d, const Vector2 &v)
        {
          Vector2 one(d*v.getX(), d*v.getY());
          return one;
        }

Vector2 Vector2::operator *=( double d)
        {

          this->x*=d;
          this->y*=d;
          return *this;
        }
Vector2 Vector2::operator -(const Vector2 &v) const
        {
            return Vector2(this->x - v.x, this->y - v.y);
        }
Vector2 Vector2::operator -=( double d)
        {

          this->x-=d;
          this->y-=d;
          return *this;
        }
Vector2 Vector2::operator /( double d) const
        {
          if(d==0)
                return *this;

          return Vector2(this->x / d, this->y / d);

        }
Vector2  Vector2::operator /=( double d)
        {

          if(d==0)
                return *this;

          this->x/=d;
          this->y/=d;
          return *this;
        }
Vector2 & Vector2::operator =(const Vector2 &v)
        {
           if(&v != this)
           {
           x=v.x;
           y=v.y;
           }
           return *this;
        }
bool Vector2::operator ==(const Vector2 &v) const
        {
            if((this->x == v.x)&& (this->y == v.y))
               return true;
            else
              return false;
        }
