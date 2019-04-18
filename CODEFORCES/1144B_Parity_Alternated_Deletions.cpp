#include<bits/stdc++.h>
using namespace std;

int const maxn = 2000 + 10;

int n, a;
vector<int> P[2];

int main()
{
  scanf("%d", &n);

  int sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    P[a&1].push_back(a);
    sum += a;
  }

  sort(P[0].begin(), P[0].end());
  sort(P[1].begin(), P[1].end());
  reverse(P[0].begin(), P[0].end());
  reverse(P[1].begin(), P[1].end());

  for(int i = 0;; i++) {
    if(i < P[0].size() && i < P[1].size()) sum -= P[0][i] + P[1][i];
    else if(i < P[0].size()) { sum -= P[0][i]; break; }
    else if(i < P[1].size()) { sum -= P[1][i]; break; }
    else break;
  }

  printf("%d\n", sum);

  return 0;
}
