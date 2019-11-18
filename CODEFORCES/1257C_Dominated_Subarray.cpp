#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int T, n, a[maxn];

int main()
{
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);

    map<int, vector<int> > pos;
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]].push_back(i);
    }

    int mi = n+1; // minimun
    for(auto [k, v]: pos)
      for(int i = 0; i < v.size()-1; i++) {
        int len = v[i+1] - v[i] + 1;
        if(len >= 2) mi = min(mi, len);
      }

    printf("%d\n", (mi==n+1)? -1 : mi);
  }

  return 0;
}
