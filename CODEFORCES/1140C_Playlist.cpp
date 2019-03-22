#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
int const INF = 1e6;

int n, k, t, b;

priority_queue<pair<int, int> > songs;
priority_queue<int, vector<int>, greater<int> > T; // times

int main()
{
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i++) {
    scanf("%d%d", &t, &b);
    songs.push({b, t});
  }

  Int pls = 0, len = 0; // pls := pleasure
  while(!songs.empty()) {
    tie(b, t) = songs.top(); songs.pop();

    len += t;
    pls = max(pls, b*len);

    T.push(t);
    if(T.size() == k) len -= T.top(), T.pop();
  }

  printf("%lld\n", pls);

  return 0;
}
