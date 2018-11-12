#include<bits/stdc++.h>
using namespace std;

long double n;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%Lf", &n);

    if(n == 1 || n == 2 || n == 3) {
      puts("N");
      continue;
    }

    if(n == 0) {
      puts("Y 0.000000000 0.000000000");
      continue;
    }

    long double a = (sqrt(n*n - 4*n) + n) / 2;
    printf("Y %.9Lf %.9Lf\n", a, n-a);
  }

  return 0;
}
