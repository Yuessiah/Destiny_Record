#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a, cnt[maxn];

int main()
{
  scanf("%d", &n);

  vector<int> inc, dec;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[a]++;

    if(cnt[a] == 3) { puts("NO"); return 0; }
    if(cnt[a] == 2) inc.push_back(a);
    if(cnt[a] == 1) dec.push_back(a);
  }

  puts("YES");
  sort(inc.begin(), inc.end());
  sort(dec.begin(), dec.end());
  reverse(dec.begin(), dec.end());

  printf("%d\n", inc.size());
  for(auto &it: inc) printf("%d ", it);
  putchar('\n');

  printf("%d\n", dec.size());
  for(auto &it: dec) printf("%d ", it);
  putchar('\n');


  return 0;
}
