#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  long long sum = 0;
  for(int i = 3; i <= n; i++) sum += i*(i-1);
  printf("%lld\n", sum);

  return 0;
}
