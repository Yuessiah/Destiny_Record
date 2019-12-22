#include<bits/stdc++.h>
using namespace std;

long long N;

int main()
{
  scanf("%lld", &N);

  if(N&1) {
    puts("0");
    return 0;
  }

  long long ans = N/10; N /= 10;
  while(N) ans += N/5, N /= 5;
  printf("%lld\n", ans);

  return 0;
}
