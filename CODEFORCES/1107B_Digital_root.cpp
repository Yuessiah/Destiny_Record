#include<bits/stdc++.h>
using namespace std;

long long int k;
int x;

int main()
{
  int n;
  scanf("%d", &n);

  while(n--) {
    scanf("%lld%d", &k, &x);
    printf("%lld\n", (k-1)*9 + x);
  }

  return 0;
}
