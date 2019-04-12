#include<bits/stdc++.h>
using namespace std;

int n, a;
map<int, int> cnt;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[a]++;
  }

  vector<int> c;
  for(auto &it: cnt) c.push_back(it.second);
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());

  int fir = c[0], ans = 0;
  for(int i = 0; i < c.size(); i++) {
    ans = max(ans, fir * ((1<<(i+1)) - 1));
    if(i != c.size()-1) fir = min(fir/2, c[i+1]);
  }

  printf("%d\n", ans);

  return 0;
}
