#include<bits/stdc++.h>
using namespace std;

int q;
long long int n, m, k;

int main()
{
  scanf("%d", &q);

  while(q--) {
    scanf("%lld%lld%lld", &n, &m, &k);

    long long int diagonal = min(n, m);
    k -= min(n, m);
    long long int target = abs(m-n) - (abs(m-n)&1);
    k -= abs(m-n);

    if(k < 0) { puts("-1"); continue; }

    long long int remain = k;
    if(!(abs(m-n)&1) && (k&1)) remain -= 2;

    printf("%lld\n", diagonal + target + remain);
  }

  return 0;
}
