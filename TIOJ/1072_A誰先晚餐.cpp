#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e4 + 10;

int N, C[maxn], E[maxn];

int main()
{
  while(scanf("%d", &N) && N) {
    vector<int> idx;
    for(int i = 0; i < N; i++) {
      scanf("%d%d", &C[i], &E[i]);
      idx.push_back(i);
    }

    sort(idx.begin(), idx.end(), [&](int x, int y) { return E[x] > E[y]; });

    int cook = 0, time = 0;
    for(int i: idx) {
      cook += C[i];
      time = max(time, cook + E[i]);
    }

    printf("%d\n", time);
  }

  return 0;
}
