#include <stdio.h>
#include <math.h>
double a; double b; double c; double d; double e; double f; double g;
double F( double x)
{
    return a*pow(x, b)+c*pow(x, d)+e*pow(x,f)+g;
}

 double z; double y; int n;

 double pole( double z, double y, int n)
{
     double dx = (y-z)/n; //szerokoœæ jednego prostok¹ta
     double s = 0;
    int i;
    for (i=1; i<=n; i++)
    {
        s = s + fabs( F(z+dx*i)); //fabs() funkcja dajaca modu³ z jakieœ liczby
        if(i%(n/10)==0) printf("%lf \n", s*dx);
    }
    return s*dx;
}

int main(void)
{
     printf("podaj liczby dla a\n");
      scanf("%lf", &a);
     printf("podaj liczby dla b\n");
      scanf("%lf", &b);
     printf("podaj liczby dla c\n");
      scanf("%lf", &c);
     printf("podaj liczby dla d\n");
      scanf("%lf", &d);
     printf("podaj liczby dla e\n");
      scanf("%lf", &e);
     printf("podaj liczby dla f\n");
      scanf("%lf", &f);
     printf("podaj liczby dla g\n");
      scanf("%lf", &g);

     printf("Podaj przedzial calkowania [z,y] \n");
     poczatek:
    scanf("%lf %lf", &z, &y);
      if(z>y)  // Nie dzia³a dla wariantu gdy z i y s¹ ujemne np z=-6, y=-9
      {
       printf("Bledny przedzial podales\nPodaj dane jeszcze raz\n");
       goto poczatek;
      }
   else
    {
    printf("Podaj podzial przedzialu calkowania (liczbe prostokatow)\n");
     poczatek1:
     scanf("%d", &n);
     if(n<10)
     {
     printf("Bledny dane podales\nPodaj n jeszcze raz\n");
       goto poczatek1;
     }
     printf("Pole = %lf", pole(z, y, n));
    }

  return 0;
}
