#include<bits/stdc++.h>
using namespace std;

int const maxn = 1002;

int n, w, s[maxn];

bool check(int bound) {
  int sum = 0, cnt = 0;

  for(int i = 0; i < n; i++) {
    sum += s[i];
    if(sum > bound) sum = s[i], cnt++;
  }

  return cnt <= w;
}

int main()
{
  while(scanf("%d%d", &n, &w) && (n || w)) {
    for(int i = 0; i < n; i++) scanf("%d", &s[i]);

    int l = *max_element(s, s+n), r = maxn*maxn;
    while(l != r) {
      int m = (l+r)/2;
      if(check(m)) r = m;
      else l = m+1;
    }

    printf("%d\n", l);
  }

  return 0;
}
