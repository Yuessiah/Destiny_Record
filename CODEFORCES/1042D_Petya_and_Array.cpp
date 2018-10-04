#include<bits/stdc++.h>
using namespace std;

typedef long long int Int;
const int maxn = 2e5 + 5;

int n, BIT[2*maxn];
Int t, pre[maxn];
map<Int, int> mp;

void add(Int p) {
  for(; p < 2*maxn; p+=p&-p) BIT[p]++;
}

int get(Int p) {
  int sum = 0;
  for(; p > 0; p-=p&-p) sum += BIT[p];

  return sum;
}

int main()
{
  scanf("%d%lld", &n, &t);

  int a;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a);
    pre[i] = pre[i-1] + a;
    mp[pre[i]] = mp[pre[i] - t] = 0; //construct key with dummy value.
  }

  mp[0] = 0;
  int c = 1;
  for(auto &it: mp) it.second = c++;

  Int ans = 0;
  add(mp[0]);
  for(int i = 1; i <= n; i++) { //i := current maximum or index of pre
    ans += i - get(mp[pre[i] - t]);
    add(mp[pre[i]]);
  }

  printf("%lld\n", ans);

  return 0;
}
