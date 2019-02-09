#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

Int K, A, B;

int main()
{
  scanf("%lld%lld%lld", &K, &A, &B);

  Int bis = 1;
  if(K >= A-1) bis = A, K -= A-1;
  else bis += K, K = 0;

  printf("%lld\n", max(bis + (K/2)*(B-A) + (K&1), bis + K));

  return 0;
}
