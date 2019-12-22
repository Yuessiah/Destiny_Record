#include<bits/stdc++.h>
using namespace std;

int n, a;

int main()
{
  scanf("%d", &n);

  long long cnt[2] = {}, sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[i&1] += a&1;
    sum += a/2;
  }

  printf("%lld\n", sum += min(cnt[0], cnt[1]));

  return 0;
}
