#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 100;

int N, M, X[maxn];
vector<int> seg;

int main()
{
  scanf("%d%d", &N, &M);

  for(int i = 0; i < M; i++) scanf("%d", &X[i]);
  sort(X, X+M);

  for(int i = 0; i < M-1; i++) seg.push_back(X[i+1]-X[i]);
  sort(seg.begin(), seg.end());

  int sum = 0;
  for(int i = 0; i < (M-1) - (N-1); i++) sum += seg[i];

  printf("%d\n", sum);

  return 0;
}
