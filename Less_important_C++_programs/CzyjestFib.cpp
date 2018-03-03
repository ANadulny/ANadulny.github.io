#include <iostream>
using namespace std;

const int N = 47; // F[0], F[1], ..., F[N-1]
int F[N];

void przygFib()
{
  // przygotowanie tablicy F[]
  F[0] = 0; F[1] = 1;
  for(int i=2; i<N; i++)
    F[i] = F[i-1] + F[i-2];
}

bool czyjestFib(int k)
{
  for(int i=0; i<N; i++)
    if(F[i] == k) return true;
  return false;
}

int main()
{
  przygFib();
  int k;
  cout << "k = "; cin >> k;
  if(czyjestFib(k)) cout << "TAK" << endl;
  else cout << "NIE" << endl;
  cin.ignore();
  cin.get();
}
