#include<bits/stdc++.h>
using namespace std;

int a, sum;
bitset<500> dp;

int main()
{
  sum = 0;
  dp[0] = true;

  for(int i = 0; i < 4; i++) {
    scanf("%d", &a);
    sum += a;
    dp |= dp << a;
  }

  puts(((sum&1) || !dp[sum/2])? "NO" : "YES");

  return 0;
}
